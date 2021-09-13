#!/bin/bash

# Usage: evaluate.sh prop expr
#
# This script executes experiment `expr` for property `prop`.
# The script must be executed from within the Docker container.
# The value of `prop` must be one of: o1, o2, o3, r1, r2, r3, r4, r5, a1, a2
# The value of `expr` must be one of: man, auto, bmc5, bmc500, fuz5, fuz500, sym5, sym500

# Must specify a property.
if [ $# -ne 2 ]; then
    echo "Expected usage: evaluate.sh prop expr"
    exit 1
fi

# Identifies directory and contract.
ROOT=""
CTRT=""
if [[ "$1" =~ ^(o1|o2|o3)$ ]]; then
    ROOT="/home/usea/verify/contracts/ownable"
    CTRT="Ownable"
elif [[ "$1" =~ ^(r1|r2|r3|r4|r5)$ ]]; then
    ROOT="/home/usea/verify/contracts/escrow"
    CTRT="RefundEscrow"
elif [[ "$1" == "a1" ]]; then
    ROOT="/home/usea/verify/contracts/auction"
    CTRT="TimedMgr"
elif [[ "$1" == "a2" ]]; then
    ROOT="/home/usea/verify/contracts/auction"
    CTRT="Auction"
else
    echo "Property must be one of: o1, o2, o3, r1, r2, r3, r4, r5, a1, a2."
    exit 1
fi
if [[ "$2" =~ ^(bmc5|bmc500|fuz5|fuz500|sym5|sym500) ]]; then
    ROOT="${ROOT}/faults"
fi

# Generates contract with assertions.
SOL_FN="$1.sol"
EVAL_DIR="${ROOT}/eval_$1"
cd ${ROOT}
rm -rf ${EVAL_DIR}
mkdir ${EVAL_DIR}
scribble ${SOL_FN} --output-mode flat --output ${EVAL_DIR}/scribble.sol
cd ${EVAL_DIR}
python /home/usea/verify/scripts/postprocess_scribble.py scribble.sol scribble.clean.sol

# Determines experiment.
if [[ "$2" == "man" ]]; then
    # Run Manual Verification.
    if [[ "$1" =~ ^(r5|a2)$ ]]; then
        solc scribble.clean.sol --bundle=${CTRT} --invar-rule=checked --invar-type=rolebased --c-model --output-dir=pcmc
    else
        solc scribble.clean.sol --bundle=${CTRT} --invar-rule=checked --c-model --output-dir=pcmc
    fi
    cd pcmc
    mkdir build
    cd build
    cmake ..
    time make verify
elif [[ "$2" == "auto" ]]; then
    # Run Automatic Verification.
    if [[ "$1" =~ ^(r5|a2)$ ]]; then
        solc scribble.clean.sol --bundle=${CTRT} --invar-rule=checked --invar-type=rolebased --invar-stateful=on --invar-infer=on --c-model --output-dir=synth
    else
        solc scribble.clean.sol --bundle=${CTRT} --invar-rule=checked --invar-stateful=on --invar-infer=on --c-model --output-dir=synth
    fi
    cd synth
    mkdir build
    cd build
    cmake ..
    if [[ "$1" == "a1" ]]; then
        cp /home/usea/verify/res/cmodel.c /home/usea/verify/contracts/auction/eval_a1/synth/cmodel.c
    fi
    time make verify
elif [[ "$2" == "bmc5" ]]; then
    # Run BMC (5).
    solc scribble.clean.sol --aux-users=5 --bundle=${CTRT} --concrete --c-model --output-dir=bmc
    cd bmc
    mkdir build
    cd build
    cmake ..
    time make verify_concrete
elif [[ "$2" == "bmc500" ]]; then
    # Run BMC (500).
    solc scribble.clean.sol --aux-users=500 --bundle=${CTRT} --concrete --c-model --output-dir=bmc-lg
    cd bmc-lg
    mkdir build
    cd build
    cmake ..
    if [[ "$1" == "r5" ]]; then
        time make bmc
    else
        time make verify_concrete
    fi
elif [[ "$2" == "fuz5" ]]; then
    # Run FUZ (5).
    solc scribble.clean.sol --aux-users=5 --bundle=${CTRT} --concrete --c-model --output-dir=fuz
    cd fuz
    mkdir build
    cd build
    CC=clang-10 CXX=clang++-10 cmake -DFUZZ_RUNS=-1 ..
    time make fuzz
elif [[ "$2" == "fuz500" ]]; then
    # Run FUZ (500).
    solc scribble.clean.sol --aux-users=500 --bundle=${CTRT} --concrete --c-model --output-dir=fuz-lg
    cd fuz-lg
    mkdir build
    cd build
    CC=clang-10 CXX=clang++-10 cmake -DFUZZ_RUNS=-1 ..
    time make fuzz
elif [[ "$2" == "sym5" ]]; then
    # Run Symbolic Execution (5).
    solc scribble.clean.sol --aux-users=5 --bundle=${CTRT} --concrete --c-model --output-dir=symbex
    cd symbex
    mkdir build
    cd build
    CC=clang-10 CXX=clang++-10 cmake -DKLEE_MAX_TIME=900s ..
    time make symbex
    time make fuzz
elif [[ "$2" == "sym500" ]]; then
    # Run Symbolic Execution (500).
    solc scribble.clean.sol --aux-users=500 --bundle=${CTRT} --concrete --c-model --output-dir=symbex
    cd symbex
    mkdir build
    cd build
    CC=clang-10 CXX=clang++-10 cmake -DKLEE_MAX_TIME=900s ..
    time make symbex
else
    echo "Experiment must be one of: auto, man, bmc5, bmc500, fuz5, fuz500, bmc5, bmc500"
    exit 1
fi
