#/bin/bash

make > /dev/null
./apyc -dp --phase=1 $1
tmp=`echo $1 | cut -d '.' -f 1`
ast="$tmp.ast"
unparsed="$tmp.unparsed"
originalOutput="$tmp.1.unparsed"
unparsedOutput="$tmp.2.unparsed"

echo "========================== AST =========================="
cat $ast
echo
echo "========================= Input ========================="
cat $1
echo
echo "======================== Unparse ========================"
externalTests/../software/pyunparse $ast | tee $unparsed
echo
echo "======================== Output from #1 ========================"
python $1 > $originalOutput
cat $originalOutput
echo
echo "======================== Output from #2 ========================"
python $unparsed > $unparsedOutput
cat $unparsedOutput

echo "======================== Diff  ========================"
diff $originalOutput $unparsedOutput

rm $ast
rm $unparsed
rm $originalOutput
rm $unparsedOutput
