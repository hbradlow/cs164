#!/bin/bash
FILES=tests/correct/*.py
echo "TESTING CORRECT"
for f in $FILES
do 
	./apyc --phase=1 $f &> /dev/null
	rc=$?
	if [[ $rc != 0 ]] ; then
		echo "Did not fail on $f"
	fi
	str="--ast"
	if [[ $1 = $str ]] ; then
		echo
		echo
		echo "AST FOR $f"
		cat ${f%.*}.ast
	fi
done
echo
echo "TESTING ERRORS" 
echo
FILES=tests/error/*.py
for f in $FILES 
do
./apyc --phase=1 $f &> /dev/null
rc=$?
if [[ $rc != 1 ]] ; then
    echo "Did not fail on $f"
fi
done

