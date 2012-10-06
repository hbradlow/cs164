import re

INDENT = '@71684aa3418631a412d6105e160131b9'
DEDENT = '@d2b3009662c463c2ab96d1a73872c6f1'
indent_len = len(INDENT)

def process(in_file):
    result_file = ""
    equivalent_blanks_pre = 0
    equivalent_blanks_cur = 0
    origin_index = 0
    input_text = open(in_file, 'r').read()
    single_quote_toggle = False  
    double_quote_toggle = False
    indent_stack_cur = 0
    indent_stack_pre = 0
    # depths of all the indents
    indent_depth_stack = [0]
    write_buffer = ""
    single_quote_stack = 0
    in_lonely_comment = False
    in_comment = False
    # in_docstring = False
    # True if still counting whitepsace at beginning of a line
    whitespace_left = True 
    space_sep_str_patt = r'(\"|\')(.*?)\1\s(\"|\')(.*?)\3'
    for ch in input_text:
        if in_comment:
            if not double_quote_toggle and not single_quote_toggle and ch == '\n':
                write_buffer += ch
                result_file += write_buffer
                write_buffer = ''
                in_comment = False
                whitespace_left = True
                continue
            elif ch == '"':
                double_quote_toggle = not double_quote_toggle
            elif ch == "'":
                single_quote_toggle = not single_quote_toggle
            else:
                continue
        if whitespace_left and not re.match(r'(\ |\t)', ch):
            indent_stack_pre = indent_stack_cur
            whitespace_left = False
            # No indentation on current line
            if equivalent_blanks_cur == 0:
                while indent_stack_cur > 0:
                    write_buffer += ' %s ' % DEDENT
                    indent_stack_cur -= 1
                    equivalent_blanks_pre = 0
                    equivalent_blanks_cur = 0
            elif equivalent_blanks_cur > equivalent_blanks_pre:
                write_buffer += ' %s ' % INDENT
                indent_depth_stack.append(equivalent_blanks_cur)
                equivalent_blanks_pre = equivalent_blanks_cur
                equivalent_blanks_cur = 0
                indent_stack_cur += 1
                #print "detected indentation"
            elif equivalent_blanks_pre == equivalent_blanks_cur:
                equivalent_blanks_cur = 0
            else:
                #print "detected dedentation"
                write_buffer += ' %s ' % DEDENT
                indent_depth_stack.pop()
                while indent_depth_stack[-1] > equivalent_blanks_cur:
                    indent_depth_stack.pop()
                    write_buffer += ' %s ' % DEDENT
                    indent_stack_cur -= 1
                equivalent_blanks_pre = equivalent_blanks_cur
                equivalent_blanks_cur = 0
                indent_stack_cur -= 1
            if ch == '#':
                while indent_stack_cur > indent_stack_pre:
                    write_buffer = write_buffer[:-indent_len -1]
                    indent_stack_cur -= 1
                in_lonely_comment = True
        elif whitespace_left: 
            if ch == ' ':
                equivalent_blanks_cur += 1
                continue
            else:
                equivalent_blanks_cur += 8
                continue
        if ch == '"':
            write_buffer += ch
            double_quote_toggle = not double_quote_toggle
        elif ch == "'":
            write_buffer += ch
            single_quote_toggle = not single_quote_toggle
        # comment at end of line
        elif ch == '#':
            in_comment = True

        # end of line
        elif not double_quote_toggle and not single_quote_toggle and ch == '\n':
            write_buffer += ch
            if in_lonely_comment:
                print 'end of comment'
                write_buffer = "\n"
            result_file += write_buffer 
            write_buffer = ""
            in_lonely_comment = False
            whitespace_left = True
        else:
            write_buffer += ch
    result_file += write_buffer
    while indent_stack_cur > 0:
        indent_stack_cur -= 1
        result_file += ' %s ' % DEDENT
    while re.search(space_sep_str_patt, result_file):
        result_file = re.sub(space_sep_str_patt, lambda m: '"' + m.group(2) + m.group(4) + '"', result_file)
    return result_file

if __name__ == '__main__':
    import sys
    arg = sys.argv[1]
    with open(arg.split('.')[0] + '.py.processed', 'w') as f:
        f.write(process(arg))
