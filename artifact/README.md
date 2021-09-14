# Introduction

This artifact accompanies "Verifying Solidity Smart Contracts Via Communication Abstraction in SmartACE".
It contains an installation of all tools user in the paper, the smart contracts verified, and a script to automate each experiment.
The artifact is able to replicate all claims made in Table 2 of the paper.
They are as follows:
1. Properties O1 through to A2 can be verified with both user-provided and synthesized interference invariants.
2. All faults can be detected using each of BMC, fuzzing, and symbolic execution.
3. EAch reported time reflects the real verification/refutation time.
As stated in the paper, all experiments were performed on an `Intel(R) Core i7(R) CPU @ 1.8GHz 8-core` machine with 16GB of RAM running `Ubuntu 20.04`.

# Structure of Artifact

The artifact is built upon the VMCAI 2022 Virtual Machine and uses Docker to encapsulate experimental setup.
The Docker image used in this evaluation is `verify-openzeppelin` and is built from: https://github.com/contract-ace/verify-openzeppelin/.
For more details on Docker, visit: https://www.docker.com/.

The `verify-openzeppelin` image includes installations of SmartACE (`/home/usea/smartace`), Klee (`/home/usea/klee/`), Scribble (`/home/usea/.nvm/versions/node/v10.24.1/bin/`), and SeaHorn (`/home/usea/seahorn/`).
The annotated smart contracts from the `Ownable`, `RefundEscrow`, and `Auction` case studies are found in `/home/usea/verify/contracts/ownable/`, `/home/usea/verify/contracts/escrow/`, and `/home/usea/verify/auction/`, respectively.
Faults for a given case study are found within the `./faults/` subdirectory.
A script to run each experiment is given by `/home/usea/verify/scripts/evaluate.sh`.
An explanation of the script can be found in `/home/usea/verify/README.md`.

# Evaluating the Artifact

To evaluate the artifact, first enter the Docker container.
This is done by executing `docker run -it verify-openzeppelin /bin/bash`.
This will open a new terminal within the Docker container through which each experiment is performed.

The `/home/usea/verify/scripts/evaluate.sh` is used to run each experiment.
The expected usage is `/home/usea/verify/scripts/evaluate.sh ${PROP} ${EXPR}` where `${PROP}` is the property and `${EXPR}` is the experiment.
Possible values for `${PROP}` include: `o1`, `o2`, `o3`, `r1`, `r2`, `r3`, `r4`, `r5`, `a1, `a2.
Possible values for `${EXPR}` include:
- `man`: Verification with manually provided interference invariants (interference invariants are provided by the script when necessary);
- `auto`: Verification with synthesized interference invariants.
- `bmc5`: BMC with 5 users;
- `bmc500`: BMC with 500 users;
- `fuz5` Greybox fuzzing with 5 users;
- `fuz500`: Greybox fuzzing with 500 users;
- `sym5`: Symbolic execution with 5 users;
- `sym500`: Symbolic execution with 500 users.

## Evaluation for Testing Phase

A tester will want to ensure that the Docker container workers, and that each choice of property or experiment is supported.
Certain combinations of property and experiment are very slow to validate (see Table 2 in main paper).
We suggest the following sequence of commands as a starting point for testers:
- `docker run -it verify-openzeppelin /bin/bash`
- `/home/usea/verify/scripts/evaluate.sh o3 man`
- `/home/usea/verify/scripts/evaluate.sh o3 auto`
- `/home/usea/verify/scripts/evaluate.sh o3 bmc5`
- `/home/usea/verify/scripts/evaluate.sh o3 bmc500`
- `/home/usea/verify/scripts/evaluate.sh o3 fuz5`
- `/home/usea/verify/scripts/evaluate.sh o3 fuz500`
- `/home/usea/verify/scripts/evaluate.sh o3 sym5`
- `/home/usea/verify/scripts/evaluate.sh o3 sym500`
- `/home/usea/verify/scripts/evaluate.sh o1 man`
- `/home/usea/verify/scripts/evaluate.sh o2 man`
- `/home/usea/verify/scripts/evaluate.sh o3 man`
- `/home/usea/verify/scripts/evaluate.sh r1 man`
- `/home/usea/verify/scripts/evaluate.sh r2 man`
- `/home/usea/verify/scripts/evaluate.sh r3 man`
- `/home/usea/verify/scripts/evaluate.sh r4 man`
- `/home/usea/verify/scripts/evaluate.sh r5 man`
- `/home/usea/verify/scripts/evaluate.sh a1 man`
- `/home/usea/verify/scripts/evaluate.sh a2 man`
Each command is likely successful if a timing result with real greater than 2s is logged to the terminal.
For details on how to interpret each output, see the next section.

## Evaluation for Assessment Phase

This section describes how an accessor should interpret the output for each command.

If verification (`man` or `auto`) is successful, then the accessor should identify a line `unsat` in the output.
The line `unsat` indicates that there does not exist a counterexample to the property.
The final 3 lines will provide timing data for verification.

If BMC (`bmc5` or `bmc500`) is successful, then the accessor should identify a line `sat` in the output.
The line `sat` indicates that a counterexample was discovered.
The final 3 lines will provide timing data for verification.

If greybox fuzzing is successful, then the accessor should identify a line `SUMMARY: libFuzzer: deadly signal`.
This indicates that an assertion was violated.
The final 3 lines will provide timing data for verification.

If symbolic execution is successful, then the accessor should identify a line `KLEE: ERROR: libverify/verify_klee.c:48: ASSERTION FAIL: _cond`.
This indicates that an assertion was violated.
The final 3 lines will provide timing data for verification.
Note that for failed evaluations, the resource limit was reached within 2 hours.