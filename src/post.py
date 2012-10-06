import re
patt =     re.compile(r'\(list_display(\s\d+((\n\s+\(id\s\d+\s\w+\))*)\)\n\s+(\())') 
bad_patt = re.compile(r'\(assign\s\d+\n\s+\(list_display(\s\d+((\n\s+\(id\s\d+\s\w+\))*\n\s+\((?!id)))')
bad_patt1 = re.compile(r'\(assign\s\d+\n\s+\(list_display(\s\d+((\n\s+\(id\s\d+\s\w+\))*\n\s+\((?!typed_id)))')
patt1 =    re.compile(r'\(tuple(\s\d+((\n\s+\(id\s\d+\s\w+\))*)\)\n\s+(\())') 
binop = r'\(assign\s\d+\n\s+\(binop'
def process(infile):
    f = open(infile, 'r')
    dump = f.read()
    if re.search(binop, dump):
        print "bad binop"
        exit(1)
    if re.search(bad_patt, dump) and re.search(bad_patt1, dump):
        print "something was not an id"
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
