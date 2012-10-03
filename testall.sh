#!/bin/bash
FILES=tests/correct/*.py
echo "TESTING CORRECT"
for f in $FILES
do 
	./apyc --phase=1 $f
done
echo "TESTING ERRORS" 
FILES=tests/error/*.py
for f in $FILES 
do
./apyc --phase=1 $f &> /dev/null
rc=$?
if [[ $rc != 1 ]] ; then
    echo "Did not fail on $f"
fi
done
