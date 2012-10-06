import re
patt = re.compile(r'\(list_display(\s\d+((\n\s+\(id\s\d+\s\w+\))*)\)\n\s+(\())') 
patt1 = re.compile(r'\(tuple(\s\d+((\n\s+\(id\s\d+\s\w+\))*)\)\n\s+(\())') 
bad_patt = re.compile(r'\(list_display(\s\d+((\n\s+\(id\s\d+\s\w+\))*\s\d+\((?!id)))')
binop = r'\(assign\s\d+\n\s+\(binop'
def process(infile):
    f = open(infile, 'r')
    dump = f.read()
    if re.search(binop, dump) or re.search(bad_patt, dump):
        print "bad ast"
        exit(1)
    result = patt.sub(r'(target_list \1', dump)
    result = patt1.sub(r'(target_list \1', result)

    f.close()
    return result


if __name__ == '__main__':
    import sys
    arg = sys.argv[1]
    result = process(arg)
    with open(arg, 'w') as f:
        f.write(result)
