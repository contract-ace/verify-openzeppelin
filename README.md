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

# Publication(s)

Under review.

