#!/bin/bash
FILES=tests/correct/*.py
echo "TESTING CORRECT"
for f in $FILES
do 
	./apyc --phase=1 $f
done
echo
echo "TESTING ERRORS" 
echo
FILES=tests/error/*.py
for f in $FILES 
do
	./apyc --phase=1 $f
	echo "Compiling error: $f"
done

