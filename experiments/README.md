# Experiments

## Verification (Manual)

### Property: O1

...

### Property: O2

...

### Property: O3

...

### Property: R1

...

### Property: R2

...

### Property: R3

...

### Property: R4

...

### Property: R5

...

### Property: A1

...

### Property: A2

...

## Verification (Automatic)

### Property: O1

...

### Property: O2

...

### Property: O3

...

### Property: R1

...

### Property: R2

...

### Property: R3

...

### Property: R4

...

### Property: R5

...

### Property: A1

...

### Property: A2

...

## Bounded Model Checking (5 Users)

### Property: O1

```
cd /home/usea/verify/contracts/ownable/faults/
mkdir -p eval_o1
rm -f eval_o1/scribble.sol eval_o1/scribble.clean.sol
scribble o1.sol --output-mode flat --output eval_o1/scribble.sol
cd eval_o1
python /home/usea/verify/scripts/postprocess_scribble.py scribble.sol scribble.clean.sol
solc scribble.clean.sol --aux-users=5 --bundle=Ownable \
                        --concrete --c-model --output-dir=bmc
cd bmc
mkdir build
cd build
cmake ..
time make verify_concrete
```

### Property: O2

```
cd /home/usea/verify/contracts/ownable/faults/
mkdir -p eval_o2
rm -f eval_o2/scribble.sol eval_o2/scribble.clean.sol
scribble o2.sol --output-mode flat --output eval_o2/scribble.sol
cd eval_o2
python /home/usea/verify/scripts/postprocess_scribble.py scribble.sol scribble.clean.sol
solc scribble.clean.sol --aux-users=5 --bundle=Ownable \
                        --concrete --c-model --output-dir=bmc
cd bmc
mkdir build
cd build
cmake ..
time make verify_concrete
```

### Property: O3

```
cd /home/usea/verify/contracts/ownable/faults/
mkdir -p eval_o3
rm -f eval_o3/scribble.sol eval_o3/scribble.clean.sol
scribble o3.sol --output-mode flat --output eval_o3/scribble.sol
cd eval_o3
python /home/usea/verify/scripts/postprocess_scribble.py scribble.sol scribble.clean.sol
solc scribble.clean.sol --aux-users=5 --bundle=Ownable \
                        --concrete --c-model --output-dir=bmc
cd bmc
mkdir build
cd build
cmake ..
time make verify_concrete
```

### Property: R1

```
cd /home/usea/verify/contracts/escrow/faults/
mkdir -p eval_r1
rm -f eval_r1/scribble.sol eveval_r1al_o2/scribble.clean.sol
scribble r1.sol --output-mode flat --output eval_r1/scribble.sol
cd eval_r1
python /home/usea/verify/scripts/postprocess_scribble.py scribble.sol scribble.clean.sol
solc scribble.clean.sol --aux-users=5 --bundle=RefundEscrow \
                        --concrete --c-model --output-dir=bmc
cd bmc
mkdir build
cd build
cmake ..
time make verify_concrete
```

### Property: R2

```
cd /home/usea/verify/contracts/escrow/faults/
mkdir -p eval_r2
rm -f eval_r2/scribble.sol eval_r2/scribble.clean.sol
scribble r2.sol --output-mode flat --output eval_r2/scribble.sol
cd eval_r2
python /home/usea/verify/scripts/postprocess_scribble.py scribble.sol scribble.clean.sol
solc scribble.clean.sol --aux-users=5 --bundle=RefundEscrow \
                        --concrete --c-model --output-dir=bmc
cd bmc
mkdir build
cd build
cmake ..
time make verify_concrete
```

### Property: R3

```
cd /home/usea/verify/contracts/escrow/faults/
mkdir -p eval_r3
rm -f eval_r3/scribble.sol eval_r3/scribble.clean.sol
scribble r3.sol --output-mode flat --output eval_r3/scribble.sol
cd eval_r3
python /home/usea/verify/scripts/postprocess_scribble.py scribble.sol scribble.clean.sol
solc scribble.clean.sol --aux-users=5 --bundle=RefundEscrow \
                        --concrete --c-model --output-dir=bmc
cd bmc
mkdir build
cd build
cmake ..
time make verify_concrete
```

### Property: R4

```
cd /home/usea/verify/contracts/escrow/faults/
mkdir -p eval_r4
rm -f eval_r4/scribble.sol eval_r4/scribble.clean.sol
scribble r4.sol --output-mode flat --output eval_r4/scribble.sol
cd eval_r4
python /home/usea/verify/scripts/postprocess_scribble.py scribble.sol scribble.clean.sol
solc scribble.clean.sol --aux-users=5 --bundle=RefundEscrow \
                        --concrete --c-model --output-dir=bmc
cd bmc
mkdir build
cd build
cmake ..
time make verify_concrete
```

### Property: R5

```
cd /home/usea/verify/contracts/escrow/faults/
mkdir -p eval_r5
rm -f eval_r5/scribble.sol eval_r5/scribble.clean.sol
scribble r5.sol --output-mode flat --output eval_r5/scribble.sol
cd eval_r5
python /home/usea/verify/scripts/postprocess_scribble.py scribble.sol scribble.clean.sol
solc scribble.clean.sol --aux-users=5 --bundle=RefundEscrow \
                        --concrete --c-model --output-dir=bmc
cd bmc
mkdir build
cd build
cmake ..
time make verify_concrete
```

### Property: A1

```
cd /home/usea/verify/contracts/auction/faults/
mkdir -p eval_a1
rm -f eval_a1/scribble.sol eval_a1/scribble.clean.sol
scribble a1.sol --output-mode flat --output eval_a1/scribble.sol
cd eval_a1
python /home/usea/verify/scripts/postprocess_scribble.py scribble.sol scribble.clean.sol
solc scribble.clean.sol --aux-users=5 --bundle=TimedMgr \
                        --concrete --c-model --output-dir=bmc
cd bmc
mkdir build
cd build
cmake ..
time make verify_concrete
```

### Property: A2

```
cd /home/usea/verify/contracts/auction/faults/
mkdir -p eval_a2
rm -f eval_a2/scribble.sol eval_a2/scribble.clean.sol
scribble a2.sol --output-mode flat --output eval_a2/scribble.sol
cd eval_a2
python /home/usea/verify/scripts/postprocess_scribble.py scribble.sol scribble.clean.sol
solc scribble.clean.sol --aux-users=5 --bundle=Auction \
                        --concrete --c-model --output-dir=bmc
cd bmc
mkdir build
cd build
cmake ..
time make verify_concrete
```

## Bounded Model Checking (500 Users)

### Property: O1

```
cd /home/usea/verify/contracts/ownable/faults/
mkdir -p eval_o1
rm -f eval_o1/scribble.sol eval_o1/scribble.clean.sol
scribble o1.sol --output-mode flat --output eval_o1/scribble.sol
cd eval_o1
python /home/usea/verify/scripts/postprocess_scribble.py scribble.sol scribble.clean.sol
solc scribble.clean.sol --aux-users=500 --bundle=Ownable \
                        --concrete --c-model --output-dir=bmc_lg
cd bmc_lg
mkdir build
cd build
cmake ..
time make verify_concrete
```

### Property: O2

```
cd /home/usea/verify/contracts/ownable/faults/
mkdir -p eval_o2
rm -f eval_o2/scribble.sol eval_o2/scribble.clean.sol
scribble o2.sol --output-mode flat --output eval_o2/scribble.sol
cd eval_o2
python /home/usea/verify/scripts/postprocess_scribble.py scribble.sol scribble.clean.sol
solc scribble.clean.sol --aux-users=500 --bundle=Ownable \
                        --concrete --c-model --output-dir=bmc_lg
cd bmc_lg
mkdir build
cd build
cmake ..
time make verify_concrete
```

### Property: O3

```
cd /home/usea/verify/contracts/ownable/faults/
mkdir -p eval_o3
rm -f eval_o3/scribble.sol eval_o3/scribble.clean.sol
scribble o3.sol --output-mode flat --output eval_o3/scribble.sol
cd eval_o3
python /home/usea/verify/scripts/postprocess_scribble.py scribble.sol scribble.clean.sol
solc scribble.clean.sol --aux-users=500 --bundle=Ownable \
                        --concrete --c-model --output-dir=bmc_lg
cd bmc_lg
mkdir build
cd build
cmake ..
time make verify_concrete
```

### Property: R1

```
cd /home/usea/verify/contracts/escrow/faults/
mkdir -p eval_r1
rm -f eval_r1/scribble.sol eval_r1/scribble.clean.sol
scribble r1.sol --output-mode flat --output eval_r1/scribble.sol
cd eval_r1
python /home/usea/verify/scripts/postprocess_scribble.py scribble.sol scribble.clean.sol
solc scribble.clean.sol --aux-users=500 --bundle=RefundEscrow \
                        --concrete --c-model --output-dir=bmc_lg
cd bmc_lg
mkdir build
cd build
cmake ..
time make verify_concrete
```

### Property: R2

```
cd /home/usea/verify/contracts/escrow/faults/
mkdir -p eval_r2
rm -f eval_r2/scribble.sol eval_r2/scribble.clean.sol
scribble r2.sol --output-mode flat --output eval_r2/scribble.sol
cd eval_r2
python /home/usea/verify/scripts/postprocess_scribble.py scribble.sol scribble.clean.sol
solc scribble.clean.sol --aux-users=500 --bundle=RefundEscrow \
                        --concrete --c-model --output-dir=bmc_lg
cd bmc_lg
mkdir build
cd build
cmake ..
time make verify_concrete
```

### Property: R3

```
cd /home/usea/verify/contracts/escrow/faults/
mkdir -p eval_r3
rm -f eval_r3/scribble.sol eval_r3/scribble.clean.sol
scribble r3.sol --output-mode flat --output eval_r3/scribble.sol
cd eval_r3
python /home/usea/verify/scripts/postprocess_scribble.py scribble.sol scribble.clean.sol
solc scribble.clean.sol --aux-users=500 --bundle=RefundEscrow \
                        --concrete --c-model --output-dir=bmc_lg
cd bmc_lg
mkdir build
cd build
cmake ..
time make verify_concrete
```

### Property: R4

```
cd /home/usea/verify/contracts/escrow/faults/
mkdir -p eval_r4
rm -f eval_r4/scribble.sol eval_r4/scribble.clean.sol
scribble r4.sol --output-mode flat --output eval_r4/scribble.sol
cd eval_r4
python /home/usea/verify/scripts/postprocess_scribble.py scribble.sol scribble.clean.sol
solc scribble.clean.sol --aux-users=500 --bundle=RefundEscrow \
                        --concrete --c-model --output-dir=bmc_lg
cd bmc_lg
mkdir build
cd build
cmake ..
time make verify_concrete
```

### Property: R5

```
cd /home/usea/verify/contracts/escrow/faults/
mkdir -p eval_r5
rm -f eval_r5/scribble.sol eval_r5/scribble.clean.sol
scribble r5.sol --output-mode flat --output eval_r5/scribble.sol
cd eval_r5
python /home/usea/verify/scripts/postprocess_scribble.py scribble.sol scribble.clean.sol
solc scribble.clean.sol --aux-users=500 --bundle=RefundEscrow \
                        --concrete --c-model --output-dir=bmc_lg
cd bmc_lg
mkdir build
cd build
cmake ..
time make bmc
```

### Property: A1

```
cd /home/usea/verify/contracts/auction/faults/
mkdir -p eval_a1
rm -f eval_a1/scribble.sol eval_a1/scribble.clean.sol
scribble a1.sol --output-mode flat --output eval_a1/scribble.sol
cd eval_a1
python /home/usea/verify/scripts/postprocess_scribble.py scribble.sol scribble.clean.sol
solc scribble.clean.sol --aux-users=500 --bundle=TimedMgr \
                        --concrete --c-model --output-dir=bmc_lg
cd bmc_lg
mkdir build
cd build
cmake ..
time make verify_concrete
```

### Property: A2

```
cd /home/usea/verify/contracts/auction/faults/
mkdir -p eval_a2
rm -f eval_a2/scribble.sol eval_a2/scribble.clean.sol
scribble a2.sol --output-mode flat --output eval_a2/scribble.sol
cd eval_a2
python /home/usea/verify/scripts/postprocess_scribble.py scribble.sol scribble.clean.sol
solc scribble.clean.sol --aux-users=500 --bundle=Auction \
                        --concrete --c-model --output-dir=bmc_lg
cd bmc_lg
mkdir build
cd build
cmake ..
time make verify_concrete
```

## Greybox Fuzzing (5 Users)

### Property: O1

...

### Property: O2

...

### Property: O3

...

### Property: R1

...

### Property: R2

...

### Property: R3

...

### Property: R4

...

### Property: R5

...

### Property: A1

...

### Property: A2

...

## Greybox Fuzzing (500 Users)

### Property: O1

...

### Property: O2

...

### Property: O3

...

### Property: R1

...

### Property: R2

...

### Property: R3

...

### Property: R4

...

### Property: R5

...

### Property: A1

...

### Property: A2

...

## Symbolic Execution (5 Users)

### Property: O1

```
cd /home/usea/verify/contracts/ownable/faults/
mkdir -p eval_o1
rm -f eval_o1/scribble.sol eval_o1/scribble.clean.sol
scribble o1.sol --output-mode flat --output eval_o1/scribble.sol
cd eval_o1
python /home/usea/verify/scripts/postprocess_scribble.py scribble.sol scribble.clean.sol
solc scribble.clean.sol --aux-users=5 --bundle=Ownable \
                        --concrete --c-model --output-dir=symb
cd symb
mkdir build
cd build
CC=clang-10 CXX=clang++-10 cmake ..
time make symbex
```

### Property: O2

```
cd /home/usea/verify/contracts/ownable/faults/
mkdir -p eval_o2
rm -f eval_o2/scribble.sol eval_o2/scribble.clean.sol
scribble o2.sol --output-mode flat --output eval_o2/scribble.sol
cd eval_o2
python /home/usea/verify/scripts/postprocess_scribble.py scribble.sol scribble.clean.sol
solc scribble.clean.sol --aux-users=5 --bundle=Ownable \
                        --concrete --c-model --output-dir=symb
cd symb
mkdir build
cd build
CC=clang-10 CXX=clang++-10 cmake ..
time make symbex
```

### Property: O3

```
cd /home/usea/verify/contracts/ownable/faults/
mkdir -p eval_o3
rm -f eval_o3/scribble.sol eval_o3/scribble.clean.sol
scribble o3.sol --output-mode flat --output eval_o3/scribble.sol
cd eval_o3
python /home/usea/verify/scripts/postprocess_scribble.py scribble.sol scribble.clean.sol
solc scribble.clean.sol --aux-users=5 --bundle=Ownable \
                        --concrete --c-model --output-dir=symb
cd symb
mkdir build
cd build
CC=clang-10 CXX=clang++-10 cmake ..
time make symbex
```

### Property: R1

```
cd /home/usea/verify/contracts/escrow/faults/
mkdir -p eval_r1
rm -f eval_r1/scribble.sol eval_r1/scribble.clean.sol
scribble r1.sol --output-mode flat --output eval_r1/scribble.sol
cd eval_r1
python /home/usea/verify/scripts/postprocess_scribble.py scribble.sol scribble.clean.sol
solc scribble.clean.sol --aux-users=5 --bundle=RefundEscrow \
                        --concrete --c-model --output-dir=symb
cd symb
mkdir build
cd build
CC=clang-10 CXX=clang++-10 cmake ..
time make symbex
```

### Property: R2

```
cd /home/usea/verify/contracts/escrow/faults/
mkdir -p eval_r2
rm -f eval_r2/scribble.sol eval_r2/scribble.clean.sol
scribble r2.sol --output-mode flat --output eval_r2/scribble.sol
cd eval_r2
python /home/usea/verify/scripts/postprocess_scribble.py scribble.sol scribble.clean.sol
solc scribble.clean.sol --aux-users=5 --bundle=RefundEscrow \
                        --concrete --c-model --output-dir=symb
cd symb
mkdir build
cd build
CC=clang-10 CXX=clang++-10 cmake ..
time make symbex
```

### Property: R3

```
cd /home/usea/verify/contracts/escrow/faults/
mkdir -p eval_r3
rm -f eval_r3/scribble.sol eval_r3/scribble.clean.sol
scribble r3.sol --output-mode flat --output eval_r3/scribble.sol
cd eval_r3
python /home/usea/verify/scripts/postprocess_scribble.py scribble.sol scribble.clean.sol
solc scribble.clean.sol --aux-users=5 --bundle=RefundEscrow \
                        --concrete --c-model --output-dir=symb
cd symb
mkdir build
cd build
CC=clang-10 CXX=clang++-10 cmake ..
time make symbex
```

### Property: R4

```
cd /home/usea/verify/contracts/escrow/faults/
mkdir -p eval_r4
rm -f eval_r4/scribble.sol eval_r4/scribble.clean.sol
scribble r4.sol --output-mode flat --output eval_r4/scribble.sol
cd eval_r4
python /home/usea/verify/scripts/postprocess_scribble.py scribble.sol scribble.clean.sol
solc scribble.clean.sol --aux-users=5 --bundle=RefundEscrow \
                        --concrete --c-model --output-dir=symb
cd symb
mkdir build
cd build
CC=clang-10 CXX=clang++-10 cmake ..
time make symbex
```

### Property: R5

```
cd /home/usea/verify/contracts/escrow/faults/
mkdir -p eval_r5
rm -f eval_r5/scribble.sol eval_r5/scribble.clean.sol
scribble r5.sol --output-mode flat --output eval_r5/scribble.sol
cd eval_r5
python /home/usea/verify/scripts/postprocess_scribble.py scribble.sol scribble.clean.sol
solc scribble.clean.sol --aux-users=5 --bundle=RefundEscrow \
                        --concrete --c-model --output-dir=symb
cd symb
mkdir build
cd build
CC=clang-10 CXX=clang++-10 cmake ..
time make symbex
```

### Property: A1

```
cd /home/usea/verify/contracts/auction/faults/
mkdir -p eval_a1
rm -f eval_a1/scribble.sol eval_a1/scribble.clean.sol
scribble a1.sol --output-mode flat --output eval_a1/scribble.sol
cd eval_a1
python /home/usea/verify/scripts/postprocess_scribble.py scribble.sol scribble.clean.sol
solc scribble.clean.sol --aux-users=5 --bundle=TimedMgr \
                        --concrete --c-model --output-dir=symb
cd symb
mkdir build
cd build
CC=clang-10 CXX=clang++-10 cmake ..
time make symbex
```

### Property: A2

```
cd /home/usea/verify/contracts/auction/faults/
mkdir -p eval_a2
rm -f eval_a2/scribble.sol eval_a2/scribble.clean.sol
scribble a2.sol --output-mode flat --output eval_a2/scribble.sol
cd eval_a2
python /home/usea/verify/scripts/postprocess_scribble.py scribble.sol scribble.clean.sol
solc scribble.clean.sol --aux-users=5 --bundle=Auction \
                        --concrete --c-model --output-dir=symb
cd symb
mkdir build
cd build
CC=clang-10 CXX=clang++-10 cmake ..
time make symbex
```

## Symbolic Execution (500 Users)

### Property: O1

```
cd /home/usea/verify/contracts/ownable/faults/
mkdir -p eval_o1
rm -f eval_o1/scribble.sol eval_o1/scribble.clean.sol
scribble o1.sol --output-mode flat --output eval_o1/scribble.sol
cd eval_o1
python /home/usea/verify/scripts/postprocess_scribble.py scribble.sol scribble.clean.sol
solc scribble.clean.sol --aux-users=500 --bundle=Ownable \
                        --concrete --c-model --output-dir=symb_lg
cd symb_lg
mkdir build
cd build
CC=clang-10 CXX=clang++-10 cmake ..
time make symbex
```

### Property: O2

```
cd /home/usea/verify/contracts/ownable/faults/
mkdir -p eval_o2
rm -f eval_o2/scribble.sol eval_o2/scribble.clean.sol
scribble o2.sol --output-mode flat --output eval_o2/scribble.sol
cd eval_o2
python /home/usea/verify/scripts/postprocess_scribble.py scribble.sol scribble.clean.sol
solc scribble.clean.sol --aux-users=500 --bundle=Ownable \
                        --concrete --c-model --output-dir=symb_lg
cd symb_lg
mkdir build
cd build
CC=clang-10 CXX=clang++-10 cmake ..
time make symbex
```

### Property: O3

```
cd /home/usea/verify/contracts/ownable/faults/
mkdir -p eval_o3
rm -f eval_o3/scribble.sol eval_o3/scribble.clean.sol
scribble o3.sol --output-mode flat --output eval_o3/scribble.sol
cd eval_o3
python /home/usea/verify/scripts/postprocess_scribble.py scribble.sol scribble.clean.sol
solc scribble.clean.sol --aux-users=500 --bundle=Ownable \
                        --concrete --c-model --output-dir=symb_lg
cd symb_lg
mkdir build
cd build
CC=clang-10 CXX=clang++-10 cmake ..
time make symbex
```

### Property: R1

```
cd /home/usea/verify/contracts/escrow/faults/
mkdir -p eval_r1
rm -f eval_r1/scribble.sol eval_r1/scribble.clean.sol
scribble r1.sol --output-mode flat --output eval_r1/scribble.sol
cd eval_r1
python /home/usea/verify/scripts/postprocess_scribble.py scribble.sol scribble.clean.sol
solc scribble.clean.sol --aux-users=500 --bundle=RefundEscrow \
                        --concrete --c-model --output-dir=symb_lg
cd symb_lg
mkdir build
cd build
CC=clang-10 CXX=clang++-10 cmake ..
time make symbex
```

### Property: R2

```
cd /home/usea/verify/contracts/escrow/faults/
mkdir -p eval_r2
rm -f eval_r2/scribble.sol eval_r2/scribble.clean.sol
scribble r2.sol --output-mode flat --output eval_r2/scribble.sol
cd eval_r2
python /home/usea/verify/scripts/postprocess_scribble.py scribble.sol scribble.clean.sol
solc scribble.clean.sol --aux-users=500 --bundle=RefundEscrow \
                        --concrete --c-model --output-dir=symb_lg
cd symb_lg
mkdir build
cd build
CC=clang-10 CXX=clang++-10 cmake ..
time make symbex
```

### Property: R3

```
cd /home/usea/verify/contracts/escrow/faults/
mkdir -p eval_r3
rm -f eval_r3/scribble.sol eval_r3/scribble.clean.sol
scribble r3.sol --output-mode flat --output eval_r3/scribble.sol
cd eval_r3
python /home/usea/verify/scripts/postprocess_scribble.py scribble.sol scribble.clean.sol
solc scribble.clean.sol --aux-users=500 --bundle=RefundEscrow \
                        --concrete --c-model --output-dir=symb_lg
cd symb_lg
mkdir build
cd build
CC=clang-10 CXX=clang++-10 cmake ..
time make symbex
```

### Property: R4

```
cd /home/usea/verify/contracts/escrow/faults/
mkdir -p eval_r4
rm -f eval_r4/scribble.sol eval_r4/scribble.clean.sol
scribble r4.sol --output-mode flat --output eval_r4/scribble.sol
cd eval_r4
python /home/usea/verify/scripts/postprocess_scribble.py scribble.sol scribble.clean.sol
solc scribble.clean.sol --aux-users=500 --bundle=RefundEscrow \
                        --concrete --c-model --output-dir=symb_lg
cd symb_lg
mkdir build
cd build
CC=clang-10 CXX=clang++-10 cmake ..
time make symbex
```

### Property: R5

```
cd /home/usea/verify/contracts/escrow/faults/
mkdir -p eval_r5
rm -f eval_r5/scribble.sol eval_r5/scribble.clean.sol
scribble r5.sol --output-mode flat --output eval_r5/scribble.sol
cd eval_r5
python /home/usea/verify/scripts/postprocess_scribble.py scribble.sol scribble.clean.sol
solc scribble.clean.sol --aux-users=500 --bundle=RefundEscrow \
                        --concrete --c-model --output-dir=symb_lg
cd symb_lg
mkdir build
cd build
CC=clang-10 CXX=clang++-10 cmake ..
time make symbex
```

### Property: A1

```
cd /home/usea/verify/contracts/auction/faults/
mkdir -p eval_a1
rm -f eval_a1/scribble.sol eval_a1/scribble.clean.sol
scribble a1.sol --output-mode flat --output eval_a1/scribble.sol
cd eval_a1
python /home/usea/verify/scripts/postprocess_scribble.py scribble.sol scribble.clean.sol
solc scribble.clean.sol --aux-users=500 --bundle=TimedMgr \
                        --concrete --c-model --output-dir=symb_lg
cd symb_lg
mkdir build
cd build
CC=clang-10 CXX=clang++-10 cmake ..
time make symbex
```

### Property: A2

```
cd /home/usea/verify/contracts/auction/faults/
mkdir -p eval_a2
rm -f eval_a2/scribble.sol eval_a2/scribble.clean.sol
scribble a2.sol --output-mode flat --output eval_a2/scribble.sol
cd eval_a2
python /home/usea/verify/scripts/postprocess_scribble.py scribble.sol scribble.clean.sol
solc scribble.clean.sol --aux-users=500 --bundle=Auction \
                        --concrete --c-model --output-dir=symb_lg
cd symb_lg
mkdir build
cd build
CC=clang-10 CXX=clang++-10 cmake ..
time make symbex
```
