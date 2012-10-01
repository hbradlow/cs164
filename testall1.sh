#!/bin/bash
FILES=tests/correct/*_processed.py
for f in $FILES
do 
	echo "Compiling $f" 
	./apyc --phase=1 $f
done

FILES=tests/error/*_processed.py
for f in $FILES
do
	echo "Compiling error: $f"
	./apyc --phase=1 $f
done

rm tests/correct/*_processed*
rm tests/error/*_processed*
