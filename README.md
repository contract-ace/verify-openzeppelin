# Verify OpenZeppelin

This repository contains the annotated smart contracts verified in the case study of *Verifying Solidity Smart Contracts Via Communication Abstraction in SmartACE*.
The repository verifies `Ownable` and `RefundEscrow` from [OpenZeppelin library](https://github.com/OpenZeppelin/openzeppelin-contracts/).
In addition, a simple open-bid auction is verified to study the unique challenges posed in auction verification.
The auction contract is *not* from OpenZeppelin as OpenZeppelin [does not provide auction implementations](https://github.com/OpenZeppelin/openzeppelin-contracts/issues/458).

# Case Study Design

This case study verifies three smart contracts.
For each smart contract, the following methodology is used:
- Specifications are extracted from the smart contract's documentation.
- The specifications are formalized using [Scribble](https://docs.scribble.codes/l).
- The smart contract is transformed into an LLVM-based model using [SmartACE](https://github.com/contract-ace/smartace/).
- The LLVM-based model is verified through [PCMC](https://arxiv.org/abs/2107.08583/) in [SeaHorn](http://seahorn.github.io/).
To validate each specification:
- A fault is injected into the smart contract.
- The fault is identified using each of SeaHorn (bounded model checking), [libFuzzer](https://llvm.org/docs/LibFuzzer.html) (greybox fuzzing), and [KLEE](https://klee.github.io/) (symbolic execution).
To evaluate the effectiveness of SmartACE at finding bugs, the smart contract is instantiated with 5 and 500 users, with the results compared.

# Publication(s)

Under review.

