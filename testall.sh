#!/bin/bash
FILES=tests/correct/*.py
echo "TESTING CORRECT"
for f in $FILES
do 
<<<<<<< HEAD
echo "Compiling $f" 
./apyc --phase=1 $f
done
=======
	./apyc --phase=1 $f
done
echo
echo "TESTING ERRORS" 
echo
>>>>>>> a34dcf4735a7a4db44f00562392dcc0629268996
FILES=tests/error/*.py
for f in $FILES 
do
echo "Compiling error: $f"
./apyc --phase=1 $f
done
