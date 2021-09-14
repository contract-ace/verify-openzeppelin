# Verify OpenZeppelin

This repository contains the annotated smart contracts verified in the case study of *Verifying Solidity Smart Contracts Via Communication Abstraction in SmartACE*.
The repository verifies `Ownable` and `RefundEscrow` from the [OpenZeppelin library](https://github.com/OpenZeppelin/openzeppelin-contracts).
In addition, a simple open-bid auction is verified to study the unique challenges posed in auction verification.
The auction contract is *not* from OpenZeppelin as OpenZeppelin [does not provide auction implementations](https://github.com/OpenZeppelin/openzeppelin-contracts/issues/458).

# Case Study Design

This case study verifies properties of three smart contracts.

For each smart contract, the following methodology is used:
1. Specifications are extracted from the contract's documentation.
2. The specifications are formalized using [Scribble](https://docs.scribble.codes).
3. The smart contract is transformed into an LLVM-based model using [SmartACE](https://github.com/contract-ace/smartace).
4. The LLVM-based model is verified through [PCMC](https://arxiv.org/abs/2107.08583/) in [SeaHorn](http://seahorn.github.io).

To validate each specification:
1. A fault is injected into the smart contract.
2. The fault is identified using each of SeaHorn (bounded model checking), [libFuzzer](https://llvm.org/docs/LibFuzzer.html) (greybox fuzzing), and [KLEE](https://klee.github.io/) (symbolic execution).

To evaluate the effectiveness of SmartACE, all smart contracts are instantiated with 5 and 500 users to compare the time until bugs are detected.

# Instructions to Reproduce

Each case study requires an installation of `clang-10`, SeaHorn, Klee, SmartACE, Scribble, and `python3`.
A preconfigured environment is available as a Docker image.
If this is your first time using Docker, start by installing the client for [Ubuntu](https://docs.docker.com/installation/ubuntulinux/), [OS X](https://docs.docker.com/installation/mac/), or [Windows](https://docs.docker.com/installation/windows/).
Alternatively, the Docker image can be built manually by following the directions in `docker/`.
To enter the Docker environment, run `docker run -it --rm verify-openzeppelin /bin/bash`.

The commands for each experiment can be found in `experiments/README.md`.
The rest of this section describes in detail how to perform each experiment.

The first step in each experiment is to convert contract annotations into assertions using `Scribble`.
Note that the script `./scripts/postprocessing_scribble.py` is used to automate the integration between `SmartACE` and `Scribble`.
To generate the contract with assertions, run the following commands where `${DIR}` is one of (`auction`, `escrow`, `ownable`) and `${FILE}` is the annotated contract:
```
cd /home/usea/verify/contracts/${DIR}
mkdir -p eval
scribble ${FILE} --output-mode flat --output eval/scribble.sol
cd eval
python /home/usea/verify/scripts/postprocess_scribble.py scribble.sol scribble.clean.sol
```

The second step applies SmartACE to verify the contract.
This step depends on the mode of analysis being applied.
Instructions are given for each analyzer.

## Instructions for BMC

To apply BMC, first convert the annotated contract into an LLVM-based model, and configure the project.
To do this, run the following commands where `${NUM_USERS}` is the number of users and `${CONTRACT}` is the name of the contract (i.e., `Ownable`, `RefundEscrow`, `TimedMgr`, or `Auction`):
```
solc scribble.clean.sol --aux-users=${NUM_USERS} --bundle=${CONTRACT} \
                        --concrete --c-model --output-dir=bmc
cd bmc
mkdir build
cd build
cmake ..
```

To apply BMC with a bound of 5 iterations, run the following command:
```
time make bmc
```
Otherwise, run:
```
time make verify_concrete
```
Note that the expected output should contain `SAT` to indicate that a bug has been detected.

## Instructions for Fuzzing

To apply greybox fuzzing, run the following comamnds where `${NUM_USERS}` is the number of users and `${CONTRACT}` is the name of the contract (i.e., `Ownable`, `RefundEscrow`, `TimedMgr`, or `Auction`):
```
solc scribble.clean.sol --aux-users=${NUM_USERS} --bundle=${CONTRACT} \
                        --concrete --c-model --output-dir=fuz
cd fuz
mkdir build
cd build
CC=clang-10 CXX=clang++-10 cmake -DFUZZ_RUNS=-1 ..
time make fuzz
```

## Instructions for Symbolic Execution

To apply symbolic execution, run the following commands, run the following comamnds where `${NUM_USERS}` is the number of users and `${CONTRACT}` is the name of the contract (i.e., `Ownable`, `RefundEscrow`, `TimedMgr`, or `Auction`):
```
solc scribble.clean.sol --aux-users=${NUM_USERS} --bundle=${CONTRACT} \
                        --concrete --c-model --output-dir=symbex
cd symbex
mkdir build
cd build
CC=clang-10 CXX=clang++-10 cmake -DKLEE_MAX_TIME=900s ..
time make symbex
```

## Instructions for PCMC without Synthesis

For property `R5` and `A2`, all transient users *must* be concrete, otherwise, they may be abstracted.
For `R5` and `A2`, run:
```
solc scribble.clean.sol --bundle=${CONTRACT} --invar-rule=checked --invar-type=rolebased \
                        --c-model --output-dir=pcmc
```
Otherwise, run:
```
solc scribble.clean.sol --bundle=${CONTRACT} --invar-rule=checked --c-model --output-dir=pcmc
```
Regardless of the property, continue by running:
```
cd pcmc
mkdir build
cd build
cmake ..
time make verify
```
Note that the expected output should contain `UNSAT` to indicate that a bug has not been detected.

Note that to verify `A1`, an interference invariant must be provided manually.
This can be done by replacing `eval/pcmc/cmodel.c` with `/home/usea/verify/res/cmodel.c`.

## Instructions for PCMC with Synthesis

For property `R5` and `A2`, all transient users *must* be concrete, otherwise, they may be abstracted.
For `R5` and `A2`, run:
```
solc scribble.clean.sol --bundle=${CONTRACT} --invar-rule=checked --invar-stateful=on \
                        --invar-type=rolebased --invar-infer=on --c-model --output-dir=synth
```
Otherwise, run:
```
solc scribble.clean.sol --bundle=${CONTRACT} --invar-rule=checked --invar-stateful=on  \
                        --invar-infer=on --c-model --output-dir=synth
```
Regardless of the property, continue by running:
```
cd synth
mkdir build
cd build
cmake ..
time make verify
```
Note that the expected output should contain `UNSAT` to indicate that a bug has not been detected.

# Publication(s)

Under review.

