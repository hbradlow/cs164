# Run all the indentation tests
# For each test case, outputs a ?.out file with indention characters added.
# Pass argument "clean" to remove all the .out files

if [ -z $1 ] 
then
	for f in tests/indentation/indent*.py
	do
		python pre.py $f
	done
else
	if [ $1 = "clean" ]
	then
		for f in tests/indentation/indent*.out
		do
			rm $f
		done
	fi
fi
