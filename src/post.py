import re
patt = re.compile(r'\(list_display(\s\d+((\n\s+\(id\s\d+\s\w+\))*)\)\n\s+(\(list_display\s\d+)((\n\s+\(\w+\s\d+\s\w+\))*)\))')
def process(infile):
    with open(infile, 'r') as f:
        result = patt.sub(r'(target_list \1', f.read())
    return result


if __name__ == '__main__':
    import sys
    arg = sys.argv[1]
    with open(arg.split('.')[0] + '.ast.processed', 'w') as f:
        f.write(process(arg))
