# Experiments

## Verification (Manual)

### Property: O1

```
cd /home/usea/verify/contracts/ownable/
mkdir -p eval_o1
rm -f eval_o1/scribble.sol eval_o1/scribble.clean.sol
scribble o1.sol --output-mode flat --output eval_o1/scribble.sol
cd eval_o1
python /home/usea/verify/scripts/postprocess_scribble.py scribble.sol scribble.clean.sol
solc scribble.clean.sol --bundle=Ownable --invar-rule=checked --c-model --output-dir=pcmc
cd pcmc
mkdir build
cd build
cmake ..
time make verify
```

### Property: O2

```
cd /home/usea/verify/contracts/ownable/
mkdir -p eval_o2
rm -f eval_o2/scribble.sol eval_o2/scribble.clean.sol
scribble o2.sol --output-mode flat --output eval_o2/scribble.sol
cd eval_o2
python /home/usea/verify/scripts/postprocess_scribble.py scribble.sol scribble.clean.sol
solc scribble.clean.sol --bundle=Ownable --invar-rule=checked --c-model --output-dir=pcmc
cd pcmc
mkdir build
cd build
cmake ..
time make verify
```

### Property: O3

```
cd /home/usea/verify/contracts/ownable/
mkdir -p eval_o3
rm -f eval_o3/scribble.sol eval_o3/scribble.clean.sol
scribble o3.sol --output-mode flat --output eval_o3/scribble.sol
cd eval_o3
python /home/usea/verify/scripts/postprocess_scribble.py scribble.sol scribble.clean.sol
solc scribble.clean.sol --bundle=Ownable --invar-rule=checked --c-model --output-dir=pcmc
cd pcmc
mkdir build
cd build
cmake ..
time make verify
```

### Property: R1

```
cd /home/usea/verify/contracts/escrow/
mkdir -p eval_r1
rm -f eval_r1/scribble.sol eval_r1/scribble.clean.sol
scribble r1.sol --output-mode flat --output eval_r1/scribble.sol
cd eval_r1
python /home/usea/verify/scripts/postprocess_scribble.py scribble.sol scribble.clean.sol
solc scribble.clean.sol --bundle=RefundEscrow --invar-rule=checked --c-model --output-dir=pcmc
cd pcmc
mkdir build
cd build
cmake ..
time make verify
```

### Property: R2

```
cd /home/usea/verify/contracts/escrow/
mkdir -p eval_r2
rm -f eval_r2/scribble.sol eval_r2/scribble.clean.sol
scribble r2.sol --output-mode flat --output eval_r2/scribble.sol
cd eval_r2
python /home/usea/verify/scripts/postprocess_scribble.py scribble.sol scribble.clean.sol
solc scribble.clean.sol --bundle=RefundEscrow --invar-rule=checked --c-model --output-dir=pcmc
cd pcmc
mkdir build
cd build
cmake ..
time make verify
```

### Property: R3

```
cd /home/usea/verify/contracts/escrow/
mkdir -p eval_r3
rm -f eval_r3/scribble.sol eval_r3/scribble.clean.sol
scribble r3.sol --output-mode flat --output eval_r3/scribble.sol
cd eval_r3
python /home/usea/verify/scripts/postprocess_scribble.py scribble.sol scribble.clean.sol
solc scribble.clean.sol --bundle=RefundEscrow --invar-rule=checked --c-model --output-dir=pcmc
cd pcmc
mkdir build
cd build
cmake ..
time make verify
```

### Property: R4

```
cd /home/usea/verify/contracts/escrow/
mkdir -p eval_r4
rm -f eval_r4/scribble.sol eval_r4/scribble.clean.sol
scribble r4.sol --output-mode flat --output eval_r4/scribble.sol
cd eval_r4
python /home/usea/verify/scripts/postprocess_scribble.py scribble.sol scribble.clean.sol
solc scribble.clean.sol --bundle=RefundEscrow --invar-rule=checked --c-model --output-dir=pcmc
cd pcmc
mkdir build
cd build
cmake ..
time make verify
```

### Property: R5

```
cd /home/usea/verify/contracts/escrow/
mkdir -p eval_r5
rm -f eval_r5/scribble.sol eval_r5/scribble.clean.sol
scribble r5.sol --output-mode flat --output eval_r5/scribble.sol
cd eval_r5
python /home/usea/verify/scripts/postprocess_scribble.py scribble.sol scribble.clean.sol
solc scribble.clean.sol --bundle=RefundEscrow --invar-rule=checked --invar-type=rolebased \
                        --c-model --output-dir=pcmc
cd pcmc
mkdir build
cd build
cmake ..
time make verify
```

### Property: A1

```
cd /home/usea/verify/contracts/auction/
mkdir -p eval_a1
rm -f eval_a1/scribble.sol eval_a1/scribble.clean.sol
scribble a1.sol --output-mode flat --output eval_a1/scribble.sol
cd eval_a1
python /home/usea/verify/scripts/postprocess_scribble.py scribble.sol scribble.clean.sol
solc scribble.clean.sol --bundle=TimedMgr --invar-rule=checked --c-model --output-dir=pcmc
cd pcmc
mkdir build
cd build
cmake ..
cp /home/usea/verify/res/cmodel.c /home/usea/verify/contracts/auction/eval_a1/pcmc/cmodel.c
time make verify
```

### Property: A2

```
cd /home/usea/verify/contracts/auction/
mkdir -p eval_a1
rm -f eval_a1/scribble.sol eval_a1/scribble.clean.sol
scribble a1.sol --output-mode flat --output eval_a1/scribble.sol
cd eval_a1
python /home/usea/verify/scripts/postprocess_scribble.py scribble.sol scribble.clean.sol
solc scribble.clean.sol --bundle=Auction --invar-rule=checked --c-model --output-dir=pcmc
cd pcmc
mkdir build
cd build
cmake ..
time make verify
```

## Verification (Automatic)

### Property: O1

```
cd /home/usea/verify/contracts/ownable/
mkdir -p eval_o1
rm -f eval_o1/scribble.sol eval_o1/scribble.clean.sol
scribble o1.sol --output-mode flat --output eval_o1/scribble.sol
cd eval_o1
python /home/usea/verify/scripts/postprocess_scribble.py scribble.sol scribble.clean.sol
solc scribble.clean.sol --bundle=Ownable --invar-rule=checked --invar-stateful=on \
                        --invar-infer=on --c-model --output-dir=synth
cd synth
mkdir build
cd build
cmake ..
time make verify
```

### Property: O2

```
cd /home/usea/verify/contracts/ownable/
mkdir -p eval_o2
rm -f eval_o2/scribble.sol eval_o2/scribble.clean.sol
scribble o2.sol --output-mode flat --output eval_o2/scribble.sol
cd eval_o2
python /home/usea/verify/scripts/postprocess_scribble.py scribble.sol scribble.clean.sol
solc scribble.clean.sol --bundle=Ownable --invar-rule=checked --invar-stateful=on \
                        --invar-infer=on --c-model --output-dir=synth
cd synth
mkdir build
cd build
cmake ..
time make verify
```

### Property: O3

```
cd /home/usea/verify/contracts/ownable/
mkdir -p eval_o3
rm -f eval_o3/scribble.sol eval_o3/scribble.clean.sol
scribble o3.sol --output-mode flat --output eval_o3/scribble.sol
cd eval_o3
python /home/usea/verify/scripts/postprocess_scribble.py scribble.sol scribble.clean.sol
solc scribble.clean.sol --bundle=Ownable --invar-rule=checked --c-model --output-dir=synth
solc scribble.clean.sol --bundle=Ownable --invar-rule=checked --invar-stateful=on \
                        --invar-infer=on --c-model --output-dir=synth
cd synth
mkdir build
cd build
cmake ..
time make verify
```

### Property: R1

```
cd /home/usea/verify/contracts/escrow/
mkdir -p eval_r1
rm -f eval_r1/scribble.sol eval_r1/scribble.clean.sol
scribble r1.sol --output-mode flat --output eval_r1/scribble.sol
cd eval_r1
python /home/usea/verify/scripts/postprocess_scribble.py scribble.sol scribble.clean.sol
solc scribble.clean.sol --bundle=RefundEscrow --invar-rule=checked --invar-stateful=on \
                        --invar-infer=on --c-model --output-dir=synth
cd synth
mkdir build
cd build
cmake ..
time make verify
```

### Property: R2

```
cd /home/usea/verify/contracts/escrow/
mkdir -p eval_r2
rm -f eval_r2/scribble.sol eval_r2/scribble.clean.sol
scribble r2.sol --output-mode flat --output eval_r2/scribble.sol
cd eval_r2
python /home/usea/verify/scripts/postprocess_scribble.py scribble.sol scribble.clean.sol
solc scribble.clean.sol --bundle=RefundEscrow --invar-rule=checked --invar-stateful=on \
                        --invar-infer=on --c-model --output-dir=synth
cd synth
mkdir build
cd build
cmake ..
time make verify
```

### Property: R3

```
cd /home/usea/verify/contracts/escrow/
mkdir -p eval_r3
rm -f eval_r3/scribble.sol eval_r3/scribble.clean.sol
scribble r3.sol --output-mode flat --output eval_r3/scribble.sol
cd eval_r3
python /home/usea/verify/scripts/postprocess_scribble.py scribble.sol scribble.clean.sol
solc scribble.clean.sol --bundle=RefundEscrow --invar-rule=checked --invar-stateful=on \
                        --invar-infer=on --c-model --output-dir=synth
cd synth
mkdir build
cd build
cmake ..
time make verify
```

### Property: R4

```
cd /home/usea/verify/contracts/escrow/
mkdir -p eval_r4
rm -f eval_r4/scribble.sol eval_r4/scribble.clean.sol
scribble r4.sol --output-mode flat --output eval_r4/scribble.sol
cd eval_r4
python /home/usea/verify/scripts/postprocess_scribble.py scribble.sol scribble.clean.sol
solc scribble.clean.sol --bundle=RefundEscrow --invar-rule=checked --invar-stateful=on \
                        --invar-infer=on --c-model --output-dir=synth
cd synth
mkdir build
cd build
cmake ..
time make verify
```

### Property: R5

```
cd /home/usea/verify/contracts/escrow/
mkdir -p eval_r5
rm -f eval_r5/scribble.sol eval_r5/scribble.clean.sol
scribble r5.sol --output-mode flat --output eval_r5/scribble.sol
cd eval_r5
python /home/usea/verify/scripts/postprocess_scribble.py scribble.sol scribble.clean.sol
solc scribble.clean.sol --bundle=RefundEscrow --invar-rule=checked --invar-stateful=on \
                        --invar-type=rolebased --invar-infer=on --c-model --output-dir=synth
cd synth
mkdir build
cd build
cmake ..
time make verify
```

### Property: A1

```
cd /home/usea/verify/contracts/auction/
mkdir -p eval_a1
rm -f eval_a1/scribble.sol eval_a1/scribble.clean.sol
scribble a1.sol --output-mode flat --output eval_a1/scribble.sol
cd eval_a1
python /home/usea/verify/scripts/postprocess_scribble.py scribble.sol scribble.clean.sol
solc scribble.clean.sol --bundle=TimedMgr --invar-rule=checked --invar-stateful=on \
                        --invar-infer=on --c-model --output-dir=synth
cd synth
mkdir build
cd build
cmake ..
cp /home/usea/verify/res/cmodel.c /home/usea/verify/contracts/auction/eval_a1/synth/cmodel.c
time make verify
```

### Property: A2

```
cd /home/usea/verify/contracts/auction/
mkdir -p eval_a1
rm -f eval_a1/scribble.sol eval_a1/scribble.clean.sol
scribble a1.sol --output-mode flat --output eval_a1/scribble.sol
cd eval_a1
python /home/usea/verify/scripts/postprocess_scribble.py scribble.sol scribble.clean.sol
solc scribble.clean.sol --bundle=Auction --invar-rule=checked --invar-stateful=on \
                        --invar-infer=on --c-model --output-dir=synth
cd synth
mkdir build
cd build
cmake ..
time make verify
```

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
rm -f eval_r1/scribble.sol eval_r1/scribble.clean.sol
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

```
cd /home/usea/verify/contracts/ownable/faults/
mkdir -p eval_o1
rm -f eval_o1/scribble.sol eval_o1/scribble.clean.sol
scribble o1.sol --output-mode flat --output eval_o1/scribble.sol
cd eval_o1
python /home/usea/verify/scripts/postprocess_scribble.py scribble.sol scribble.clean.sol
solc scribble.clean.sol --aux-users=5 --bundle=Ownable \
                        --concrete --c-model --output-dir=fuzz
cd fuzz
mkdir build
cd build
CC=clang-10 CXX=clang++-10 cmake -DFUZZ_RUNS=-1 ..
time make fuzz
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
                        --concrete --c-model --output-dir=fuzz
cd fuzz
mkdir build
cd build
CC=clang-10 CXX=clang++-10 cmake -DFUZZ_RUNS=-1 ..
time make fuzz
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
                        --concrete --c-model --output-dir=fuzz
cd fuzz
mkdir build
cd build
CC=clang-10 CXX=clang++-10 cmake -DFUZZ_RUNS=-1 ..
time make fuzz
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
                        --concrete --c-model --output-dir=fuzz
cd fuzz
mkdir build
cd build
CC=clang-10 CXX=clang++-10 cmake -DFUZZ_RUNS=-1 ..
time make fuzz
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
                        --concrete --c-model --output-dir=fuzz
cd fuzz
mkdir build
cd build
CC=clang-10 CXX=clang++-10 cmake -DFUZZ_RUNS=-1 ..
time make fuzz
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
                        --concrete --c-model --output-dir=fuzz
cd fuzz
mkdir build
cd build
CC=clang-10 CXX=clang++-10 cmake -DFUZZ_RUNS=-1 ..
time make fuzz
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
                        --concrete --c-model --output-dir=fuzz
cd fuzz
mkdir build
cd build
CC=clang-10 CXX=clang++-10 cmake -DFUZZ_RUNS=-1 ..
time make fuzz
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
                        --concrete --c-model --output-dir=fuzz
cd fuzz
mkdir build
cd build
CC=clang-10 CXX=clang++-10 cmake -DFUZZ_RUNS=-1 ..
time make fuzz
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
                        --concrete --c-model --output-dir=fuzz
cd fuzz
mkdir build
cd build
CC=clang-10 CXX=clang++-10 cmake -DFUZZ_RUNS=-1 ..
time make fuzz
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
                        --concrete --c-model --output-dir=fuzz
cd fuzz
mkdir build
cd build
CC=clang-10 CXX=clang++-10 cmake -DFUZZ_RUNS=-1 ..
time make fuzz
```

## Greybox Fuzzing (500 Users)

### Property: O1

```
cd /home/usea/verify/contracts/ownable/faults/
mkdir -p eval_o1
rm -f eval_o1/scribble.sol eval_o1/scribble.clean.sol
scribble o1.sol --output-mode flat --output eval_o1/scribble.sol
cd eval_o1
python /home/usea/verify/scripts/postprocess_scribble.py scribble.sol scribble.clean.sol
solc scribble.clean.sol --aux-users=500 --bundle=Ownable \
                        --concrete --c-model --output-dir=fuzz_lg
cd fuzz_lg
mkdir build
cd build
CC=clang-10 CXX=clang++-10 cmake -DFUZZ_RUNS=-1 ..
time make fuzz
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
                        --concrete --c-model --output-dir=fuzz_lg
cd fuzz_lg
mkdir build
cd build
CC=clang-10 CXX=clang++-10 cmake -DFUZZ_RUNS=-1 ..
time make fuzz
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
                        --concrete --c-model --output-dir=fuzz_lg
cd fuzz_lg
mkdir build
cd build
CC=clang-10 CXX=clang++-10 cmake -DFUZZ_RUNS=-1 ..
time make fuzz
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
                        --concrete --c-model --output-dir=fuzz_lg
cd fuzz_lg
mkdir build
cd build
CC=clang-10 CXX=clang++-10 cmake -DFUZZ_RUNS=-1 ..
time make fuzz
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
                        --concrete --c-model --output-dir=fuzz_lg
cd fuzz_lg
mkdir build
cd build
CC=clang-10 CXX=clang++-10 cmake -DFUZZ_RUNS=-1 ..
time make fuzz
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
                        --concrete --c-model --output-dir=fuzz_lg
cd fuzz_lg
mkdir build
cd build
CC=clang-10 CXX=clang++-10 cmake -DFUZZ_RUNS=-1 ..
time make fuzz
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
                        --concrete --c-model --output-dir=fuzz_lg
cd fuzz_lg
mkdir build
cd build
CC=clang-10 CXX=clang++-10 cmake -DFUZZ_RUNS=-1 ..
time make fuzz
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
                        --concrete --c-model --output-dir=fuzz_lg
cd fuzz_lg
mkdir build
cd build
CC=clang-10 CXX=clang++-10 cmake -DFUZZ_RUNS=-1 ..
time make fuzz
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
                        --concrete --c-model --output-dir=fuzz_lg
cd fuzz_lg
mkdir build
cd build
CC=clang-10 CXX=clang++-10 cmake -DFUZZ_RUNS=-1 ..
time make fuzz
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
                        --concrete --c-model --output-dir=fuzz_lg
cd fuzz_lg
mkdir build
cd build
CC=clang-10 CXX=clang++-10 cmake -DFUZZ_RUNS=-1 ..
time make fuzz
```

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
CC=clang-10 CXX=clang++-10 cmake -DKLEE_MAX_TIME=900s ..
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
CC=clang-10 CXX=clang++-10 cmake -DKLEE_MAX_TIME=900s ..
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
CC=clang-10 CXX=clang++-10 cmake -DKLEE_MAX_TIME=900s ..
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
cd build..
CC=clang-10 CXX=clang++-10 cmake -DKLEE_MAX_TIME=900s ..
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
CC=clang-10 CXX=clang++-10 cmake -DKLEE_MAX_TIME=900s ..
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
CC=clang-10 CXX=clang++-10 cmake -DKLEE_MAX_TIME=900s ..
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
CC=clang-10 CXX=clang++-10 cmake -DKLEE_MAX_TIME=900s ..
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
CC=clang-10 CXX=clang++-10 cmake -DKLEE_MAX_TIME=900s ..
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
CC=clang-10 CXX=clang++-10 cmake -DKLEE_MAX_TIME=900s ..
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
CC=clang-10 CXX=clang++-10 cmake -DKLEE_MAX_TIME=900s ..
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
CC=clang-10 CXX=clang++-10 cmake -DKLEE_MAX_TIME=900s ..
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
CC=clang-10 CXX=clang++-10 cmake -DKLEE_MAX_TIME=900s ..
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
CC=clang-10 CXX=clang++-10 cmake -DKLEE_MAX_TIME=900s ..
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
CC=clang-10 CXX=clang++-10 cmake -DKLEE_MAX_TIME=900s ..
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
CC=clang-10 CXX=clang++-10 cmake -DKLEE_MAX_TIME=900s ..
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
CC=clang-10 CXX=clang++-10 cmake -DKLEE_MAX_TIME=900s ..
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
CC=clang-10 CXX=clang++-10 cmake -DKLEE_MAX_TIME=900s ..
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
CC=clang-10 CXX=clang++-10 cmake -DKLEE_MAX_TIME=900s ..
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
CC=clang-10 CXX=clang++-10 cmake -DKLEE_MAX_TIME=900s ..
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
CC=clang-10 CXX=clang++-10 cmake -DKLEE_MAX_TIME=900s ..
time make symbex
```
