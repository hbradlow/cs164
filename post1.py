def process(infile):
    result_file = ''
    assign_block = ''
    f = open(infile, 'r')
    paren_depth = 0
    assign_depth = -1
    for line in f:
        if assign_flag and not paren:
            for ch in line.strip():
                if ch = '(':
                    paren_depth += 1
                elif ch = ')':
                    paren_depth -= 1
                assign_block += ch
            assign_block += '\n'
        else:
            line_split = line.strip().split(' ')
            node_name = line_split[0][1:]
            if node_name == 'assign':
                assign_flag = True
                assign_depth = paren_depth -1
            for ch in ' '.join(line_split):
            







def typedIds(infile):
    f = open(infile, 'r')
    paren_counter = 0
    result_file = ''
    assign_block = ''

    # on if currently in an assign block
    assign_flag = False

    # indent level for the assign
    assign_mark = -1
    for line in f:
        print paren_counter
        paren_counter += 1
        for ch in line:
            if ch == ' ':
                result_file += ch
            else:
                break
        line_split = line.strip().split(' ')
        node_name = line_split[0][1:]
        # some regular node
        if not assign_flag and node_name != 'assign':
            for ch in ' '.join(line_split):
                result_file += ch
                if ch == ')':
                    paren_counter -= 1
            result_file += '\n'
        elif assign_flag:
            if paren_counter == assign_mark:
                ha = handleAssign(assign_block)
                print ha
                if type(ha) is int:
                    exit(1)
                else:
                    result_file += ha
                    assign_mark = -1
                    assign_block = ''
            else:
                for ch in line:
                    assign_block += ch
                    if ch == '(':
                        paren_counter += 1
                    elif ch == ')':
                        paren_counter -= 1
                assign_block += '\n'
        # it's an assign!
        else:
            print line
            assign_mark = paren_counter -1
            assign_flag = True
            for ch in line:
                assign_block += ch
                if ch == '(':
                    paren_counter += 1
                elif ch == ')':
                    paren_counter -= 1
    print paren_counter
    return result_file

# Return the augmented assign block
def handleAssign(assign_block):
    result_file = ''
    paren_counter = 0
    node_types = ['id', 'typed_id', 'subscription']
    in_target_list = True
    for line in assign_block:
        for ch in line:
            if ch == ' ':
                result_file += ' '
            else:
                break
        paren_counter += 1
        result_file += '('
        if paren_counter == 1 and left_side:
            line_split = line.strip().split(' ')
            node_name = line_split[0][1:]
            result_file += node_name
            print node_name
            if node_name == 'list_display':
                result_file += 'target_list'
            elif node_name not in node_types:
                # bad node
                return -1
            else:
                for ch in ' '.join(line_split[1:]):
                    if ch == ')':
                        paren_counter -= 1
                        if paren_counter == 1:
                            left_side = False
                    result_file += ch
        elif paren_counter == 2 and left_side:
            line_split = line.strip().split(' ')
            node_name = line_split[0][1:]
            result_file += node_name
            print node_name
            if node_name not in node_types:
                return -1
            else:
                for ch in ' '.join(line_split[1:]):
                    if ch == ')':
                        paren_counter -= 1
                        if paren_counter == 1:
                            left_side = False
                    result_file += ch
        else:
            for ch in line:
                result_file += ch
                if ch == '(':
                    paren_counter += 1
                elif ch == ')':
                    paren_counter -= 1
    return result_file
                    

            


if __name__ == '__main__':
    import sys
    arg = sys.argv[1]
    result = typedIds(arg)
    with open(arg, 'w') as f:
        f.write(result)
