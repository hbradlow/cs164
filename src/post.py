import re
patt = re.compile(r'\(list_display(\s\d+((\n\s+\(id\s\d+\s\w+\))*)\)\n\s+(\())')
bad_patt = re.compile(r'\assign\s\d+\n\s+\(list_display(\s\d+((\n\s+\(id\s\d+\s\w+\))*\s\d+\((?!id)))')
binop = r'\(assign\s\d+\n\s+\(binop'
def process(infile):
    f = open(infile, 'r')
    dump = f.read()
    if re.search(binop, dump) or re.search(bad_patt, dump):
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
