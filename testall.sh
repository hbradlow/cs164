#!/bin/bash
FILES=tests/correct/*.py
for f in $FILES
do 
	echo "Compiling $f" 
	python pre.py $f
done

FILES=tests/error/*.py
for f in $FILES 
do
	python pre.py $f
	echo "Compiling error: $f"
done

