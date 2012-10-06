import re
patt = re.compile(r'\(list_display(\s\d+((\n\s+\(id\s\d+\s\w+\))*)\)\n\s+(\((list_display|id|tuple)\s\d+)((\n\s+\(\w+\s\d+\s\w+\))*)\))')
bad_patt = re.compile(r'\(list_display(\s\d+((\n\s+\(id\s\d+\s\w+\))*)\)\n\s+(\((list_display|id|tuple)\s\d+)((\n\s+\(\w+\s\d+\s\w+\))*)\))')
binop = r'\(assign\s\d+\n\s+\(binop'
def process(infile):
    f = open(infile, 'r')
    dump = f.read()
    if re.search(binop, dump):
        exit(1)
    result = patt.sub(r'(target_list \1', dump)

    f.close()
    return result


if __name__ == '__main__':
    import sys
    arg = sys.argv[1]
    result = process(arg)
    with open(arg, 'w') as f:
        f.write(result)
