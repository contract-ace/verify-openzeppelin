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

The case study environment is available as a Docker container.
For details to build the Docker environment, see `./docker/README.md`.
To enter the Docker environment, run `docker run -it verify-openzeppelin /bin/bash`.

The first step in each evaluation is to generate a contract with assertions using `Scribble`.
Note that the script `./scripts/postprocessing_scribble.py` to automate the integration between `SmartACE` and `Scribble`.
To generate the contract with assertions, run the following commands where `${STUDY}` is the case study directory and `${SOLFILE}` is the annotated contract:
```
cd verify/contracts/${STUDY}
mkdir -p eval
scribble ${SOLFILE} --output-mode flat --output eval/scribble.sol
cd eval
python /home/usea/verify/scripts/postprocess_scribble.py scribble.sol scribble.clean.sol
```

The second step applies `SmartACE` to verify the contract.
This step depends on the mode of analysis being applied.
Instructions are given for each analyzer.

## Instructions for BMC

To apply BMC, run the following comamnds, where `${NUM_USERS}` is the number of users and `${CONTRACT}` is the name of the contract (i.e., `Ownable`, `RefundEscrow`, or `Auction`):
```
solc scribble.clean.sol --aux-users=${NUM_USERS} --bundle=${CONTRACT} --concrete --c-model --output-dir=bmc
cd bmc
mkdir build
cd build
cmake build ..
make verify_concrete # Use 'make bmc' instead of 'make verify_concrete' to bound analysis to 5 transactions.
```

## Instructions for Fuzzing

To apply greybox fuzzing, run the following comamnds where `${NUM_USERS}` is the number of users and `${CONTRACT}` is the name of the contract (i.e., `Ownable`, `RefundEscrow`, or `Auction):
```
solc scribble.clean.sol --aux-users=${NUM_USERS} --bundle=${CONTRACT} --concrete --c-model --output-dir=fuz
cd fuz
mkdir build
cd build
CC=clang-10 CXX=clang++-10 cmake -DFUZZ_RUNS=-1 ..
make fuzz
```

## Instructions for Symbolic Execution

To apply symbolic execution, run the following commands, run the following comamnds where `${NUM_USERS}` is the number of users and `${CONTRACT}` is the name of the contract (i.e., `Ownable`, `RefundEscrow`, or `Auction).
```
solc scribble.clean.sol --aux-users=${NUM_USERS} --bundle=${CONTRACT} --concrete --c-model --output-dir=symbex
cd symbex
mkdir build
cd build
CC=clang-10 CXX=clang++-10 cmake -DKLEE_MAX_TIME=900s ..
make symbex
```

## Instructions for PCMC without Synthesis

To do: add instructions.

## Instructions for PCMC with Synthesis

To do: add instructions.

# Publication(s)

Under review.

