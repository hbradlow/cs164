#!/bin/bash
FILES=tests/correct/*.py
for f in $FILES
do 
echo "Compiling $f" 
./apyc --phase=1 $f
done
FILES=tests/error/*.py
for f in $FILES 
do
echo "Compiling error: $f"
./apyc --phase=1 $f
done
