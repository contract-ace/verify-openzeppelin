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
scribble o1.sol --output-mode flat --output eval_o1/scribble.sol
cd eval_o1
python /home/usea/verify/scripts/postprocess_scribble.py scribble.sol scribble.clean.sol
solc scribble.clean.sol --aux-users=5 --bundle=Ownable \
                        --concrete --c-model --output-dir=bmc
cd bmc
mkdir build
cd build
cmake build ..
time make verify_concrete
```

### Property: O2

```
cd /home/usea/verify/contracts/ownable/faults/
mkdir -p eval_o2
scribble o2.sol --output-mode flat --output eval_o2/scribble.sol
cd eval_o2
python /home/usea/verify/scripts/postprocess_scribble.py scribble.sol scribble.clean.sol
solc scribble.clean.sol --aux-users=5 --bundle=Ownable \
                        --concrete --c-model --output-dir=bmc
cd bmc
mkdir build
cd build
cmake build ..
time make verify_concrete
```

### Property: O3

```
cd /home/usea/verify/contracts/ownable/faults/
mkdir -p eval_o3
scribble o3.sol --output-mode flat --output eval_o3/scribble.sol
cd eval_o3
python /home/usea/verify/scripts/postprocess_scribble.py scribble.sol scribble.clean.sol
solc scribble.clean.sol --aux-users=5 --bundle=Ownable \
                        --concrete --c-model --output-dir=bmc
cd bmc
mkdir build
cd build
cmake build ..
time make verify_concrete
```

### Property: R1

```
cd /home/usea/verify/contracts/escrow/faults/
mkdir -p eval_r1
scribble r1.sol --output-mode flat --output eval_r1/scribble.sol
cd eval_r1
python /home/usea/verify/scripts/postprocess_scribble.py scribble.sol scribble.clean.sol
solc scribble.clean.sol --aux-users=5 --bundle=RefundEscrow \
                        --concrete --c-model --output-dir=bmc
cd bmc
mkdir build
cd build
cmake build ..
time make verify_concrete
```

### Property: R2

```
cd /home/usea/verify/contracts/escrow/faults/
mkdir -p eval_r2
scribble r2.sol --output-mode flat --output eval_r2/scribble.sol
cd eval_r2
python /home/usea/verify/scripts/postprocess_scribble.py scribble.sol scribble.clean.sol
solc scribble.clean.sol --aux-users=5 --bundle=RefundEscrow \
                        --concrete --c-model --output-dir=bmc
cd bmc
mkdir build
cd build
cmake build ..
time make verify_concrete
```

### Property: R3

```
cd /home/usea/verify/contracts/escrow/faults/
mkdir -p eval_r3
scribble r3.sol --output-mode flat --output eval_r3/scribble.sol
cd eval_r3
python /home/usea/verify/scripts/postprocess_scribble.py scribble.sol scribble.clean.sol
solc scribble.clean.sol --aux-users=5 --bundle=RefundEscrow \
                        --concrete --c-model --output-dir=bmc
cd bmc
mkdir build
cd build
cmake build ..
time make verify_concrete
```

### Property: R4

```
cd /home/usea/verify/contracts/escrow/faults/
mkdir -p eval_r4
scribble r4.sol --output-mode flat --output eval_r4/scribble.sol
cd eval_r4
python /home/usea/verify/scripts/postprocess_scribble.py scribble.sol scribble.clean.sol
solc scribble.clean.sol --aux-users=5 --bundle=RefundEscrow \
                        --concrete --c-model --output-dir=bmc
cd bmc
mkdir build
cd build
cmake build ..
time make verify_concrete
```

### Property: R5

```
cd /home/usea/verify/contracts/escrow/faults/
mkdir -p eval_r5
scribble r5.sol --output-mode flat --output eval_r5/scribble.sol
cd eval_r5
python /home/usea/verify/scripts/postprocess_scribble.py scribble.sol scribble.clean.sol
solc scribble.clean.sol --aux-users=5 --bundle=RefundEscrow \
                        --concrete --c-model --output-dir=bmc
cd bmc
mkdir build
cd build
cmake build ..
time make verify_concrete
```

### Property: A1

```
cd /home/usea/verify/contracts/auction/faults/
mkdir -p eval_a1
scribble a1.sol --output-mode flat --output eval_a1/scribble.sol
cd eval_a1
python /home/usea/verify/scripts/postprocess_scribble.py scribble.sol scribble.clean.sol
solc scribble.clean.sol --aux-users=5 --bundle=Auction \
                        --concrete --c-model --output-dir=bmc
cd bmc
mkdir build
cd build
cmake build ..
time make verify_concrete
```

### Property: A2

```
cd /home/usea/verify/contracts/auction/faults/
mkdir -p eval_a2
scribble a2.sol --output-mode flat --output eval_a2/scribble.sol
cd eval_a2
python /home/usea/verify/scripts/postprocess_scribble.py scribble.sol scribble.clean.sol
solc scribble.clean.sol --aux-users=5 --bundle=Auction \
                        --concrete --c-model --output-dir=bmc
cd bmc
mkdir build
cd build
cmake build ..
time make verify_concrete
```

## Bounded Model Checking (500 Users)

### Property: O1

```
cd /home/usea/verify/contracts/ownable/faults/
mkdir -p eval_o1
scribble o1.sol --output-mode flat --output eval_o1/scribble.sol
cd eval_o1
python /home/usea/verify/scripts/postprocess_scribble.py scribble.sol scribble.clean.sol
solc scribble.clean.sol --aux-users=500 --bundle=Ownable \
                        --concrete --c-model --output-dir=bmc
cd bmc
mkdir build
cd build
cmake build ..
time make verify_concrete
```

### Property: O2

```
cd /home/usea/verify/contracts/ownable/faults/
mkdir -p eval_o2
scribble o2.sol --output-mode flat --output eval_o2/scribble.sol
cd eval_o2
python /home/usea/verify/scripts/postprocess_scribble.py scribble.sol scribble.clean.sol
solc scribble.clean.sol --aux-users=500 --bundle=Ownable \
                        --concrete --c-model --output-dir=bmc
cd bmc
mkdir build
cd build
cmake build ..
time make verify_concrete
```

### Property: O3

```
cd /home/usea/verify/contracts/ownable/faults/
mkdir -p eval_o3
scribble o3.sol --output-mode flat --output eval_o3/scribble.sol
cd eval_o3
python /home/usea/verify/scripts/postprocess_scribble.py scribble.sol scribble.clean.sol
solc scribble.clean.sol --aux-users=500 --bundle=Ownable \
                        --concrete --c-model --output-dir=bmc
cd bmc
mkdir build
cd build
cmake build ..
time make verify_concrete
```

### Property: R1

```
cd /home/usea/verify/contracts/escrow/faults/
mkdir -p eval_r1
scribble r1.sol --output-mode flat --output eval_r1/scribble.sol
cd eval_r1
python /home/usea/verify/scripts/postprocess_scribble.py scribble.sol scribble.clean.sol
solc scribble.clean.sol --aux-users=500 --bundle=RefundEscrow \
                        --concrete --c-model --output-dir=bmc
cd bmc
mkdir build
cd build
cmake build ..
time make verify_concrete
```

### Property: R2

```
cd /home/usea/verify/contracts/escrow/faults/
mkdir -p eval_r2
scribble r2.sol --output-mode flat --output eval_r2/scribble.sol
cd eval_r2
python /home/usea/verify/scripts/postprocess_scribble.py scribble.sol scribble.clean.sol
solc scribble.clean.sol --aux-users=500 --bundle=RefundEscrow \
                        --concrete --c-model --output-dir=bmc
cd bmc
mkdir build
cd build
cmake build ..
time make verify_concrete
```

### Property: R3

```
cd /home/usea/verify/contracts/escrow/faults/
mkdir -p eval_r3
scribble r3.sol --output-mode flat --output eval_r3/scribble.sol
cd eval_r3
python /home/usea/verify/scripts/postprocess_scribble.py scribble.sol scribble.clean.sol
solc scribble.clean.sol --aux-users=500 --bundle=RefundEscrow \
                        --concrete --c-model --output-dir=bmc
cd bmc
mkdir build
cd build
cmake build ..
time make verify_concrete
```

### Property: R4

```
cd /home/usea/verify/contracts/escrow/faults/
mkdir -p eval_r4
scribble r4.sol --output-mode flat --output eval_r4/scribble.sol
cd eval_r4
python /home/usea/verify/scripts/postprocess_scribble.py scribble.sol scribble.clean.sol
solc scribble.clean.sol --aux-users=500 --bundle=RefundEscrow \
                        --concrete --c-model --output-dir=bmc
cd bmc
mkdir build
cd build
cmake build ..
time make verify_concrete
```

### Property: R5

```
cd /home/usea/verify/contracts/escrow/faults/
mkdir -p eval_r5
scribble r5.sol --output-mode flat --output eval_r5/scribble.sol
cd eval_r5
python /home/usea/verify/scripts/postprocess_scribble.py scribble.sol scribble.clean.sol
solc scribble.clean.sol --aux-users=500 --bundle=RefundEscrow \
                        --concrete --c-model --output-dir=bmc
cd bmc
mkdir build
cd build
cmake build ..
time make bmc
```

### Property: A1

```
cd /home/usea/verify/contracts/auction/faults/
mkdir -p eval_a1
scribble a1.sol --output-mode flat --output eval_a1/scribble.sol
cd eval_a1
python /home/usea/verify/scripts/postprocess_scribble.py scribble.sol scribble.clean.sol
solc scribble.clean.sol --aux-users=500 --bundle=Auction \
                        --concrete --c-model --output-dir=bmc
cd bmc
mkdir build
cd build
cmake build ..
time make verify_concrete
```

### Property: A2

```
cd /home/usea/verify/contracts/auction/faults/
mkdir -p eval_a2
scribble a2.sol --output-mode flat --output eval_a2/scribble.sol
cd eval_a2
python /home/usea/verify/scripts/postprocess_scribble.py scribble.sol scribble.clean.sol
solc scribble.clean.sol --aux-users=500 --bundle=Auction \
                        --concrete --c-model --output-dir=bmc
cd bmc
mkdir build
cd build
cmake build ..
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

## Symbolic Execution (500 Users)

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
