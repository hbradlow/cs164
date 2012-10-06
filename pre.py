import re

INDENT = '@71684aa3418631a412d6105e160131b9'
DEDENT = '@d2b3009662c463c2ab96d1a73872c6f1'
indent_len = len(INDENT)
#remove all lonely comments
def preprocess(infile):
    with open(infile, 'r') as f:
        f = f.read()
        lonely_patt = r'#.*$'
        f = re.sub(lonely_patt, lambda m: '#comment\n', f)
        return f

def process(in_file):
    result_file = ""
    equivalent_blanks_pre = 0
    equivalent_blanks_cur = 0
    origin_index = 0
    input_text = preprocess(in_file)
    #print input_text

    # balance
    paren_stack = 0
    brace_stack = 0
    curly_stack = 0
    
    slash_count = 0

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
    balanced = False

    # True if still counting whitepsace at beginning of a line
    whitespace_left = True 

    triple_patt = r'(\"\"\"|\'\'\')(.*?)\1\s*(\"\"\"|\'\'\')(.*?)\3'
    space_sep_str_patt = r'(\'|\")(.*?)\1\s*(\"|\')(.*?)\3'
    multiline_patt = r'((.|\"|\')*\\\n(.*\\\n)*((.|\"|\')*\n))'
    # matches a space_separated_string and then a triple string
    multi_a_patt = r'(((\'|\").*?\3)\s*((\"\"\"|\'\'\').*?\5))'
    # matches a triple_string and then a space_separated_strin
    multi_b_patt = r'(((\"\"\"|\'\'\').*?\3)\s*((\'|\").*?\5))'
    # build up multiline statements in here
    line_buffer = ''
    for ch in input_text:
        balanced = paren_stack == 0 and curly_stack == 0 and brace_stack == 0
        if in_lonely_comment:
            if ch == '\n' and not single_quote_toggle and not double_quote_toggle:
                result_file += '\n'
                write_buffer = ''
                in_lonely_comment = False
                in_comment = False
                continue
        if not in_comment and not in_lonely_comment:
            if ch == '(':
                paren_stack += 1
            elif ch == ')':
                paren_stack -= 1
            elif ch == '[':
                brace_stack += 1
            elif ch == ']':
                brace_stack -= 1
            elif ch == '{':
                curly_stack += 1
            elif ch == '}':
                curly_stack -= 1
        if in_comment:
            if not double_quote_toggle and not single_quote_toggle and ch == '\n':
                if balanced:
                    write_buffer += ch
                else:
                    #print 'not balanced'
                    write_buffer +=  '\\'
                    write_buffer += ch
                    slash_count += 1
                result_file += write_buffer
                write_buffer = ''
                in_comment = False
                in_lonely_comment = False
                whitespace_left = True
                continue
            elif ch == '"':
                if not single_quote_toggle:
                    double_quote_toggle = not double_quote_toggle
            elif ch == "'":
                if not double_quote_toggle:
                    single_quote_toggle = not single_quote_toggle
            else:
                continue
            continue
        # first non-whitespace char of the line
        elif whitespace_left and not re.match(r'(\ |\t)', ch):
            #print 'newline: %d' % equivalent_blanks_cur
            print "equivalent_blanks_cur: %d" % equivalent_blanks_cur
            print "equivalent_blanks_pre: %d" % equivalent_blanks_pre
            if ch == '\n':
                print "empty line"
                whitespace_left = True
                write_buffer += '\n'
                equivalent_blanks_pre = equivalent_blanks_cur
                equivalent_blanks_cur = 0
                #print indent_depth_stack
                continue
            indent_stack_pre = indent_stack_cur
            whitespace_left = False
            # need a dedent
            if ch == '#':
                write_buffer = ''
                in_lonely_comment = True
                #print 'in a lonely comment'
            elif equivalent_blanks_cur < indent_depth_stack[-1]:
                while indent_depth_stack[-1] > equivalent_blanks_cur:
                    print indent_depth_stack, equivalent_blanks_cur
                    print 'wrote a dedent' + '\n'
                    indent_depth_stack.pop()
                    write_buffer += ' %s ' % DEDENT
                    indent_stack_cur -= 1
                result_file += write_buffer
                write_buffer = ''
                equivalent_blanks_pre = indent_depth_stack[-1]
                equivalent_blanks_cur = 0
                
            # No indentation on current line
            elif equivalent_blanks_cur == 0:
                while indent_depth_stack[-1] > equivalent_blanks_cur:
                    print indent_depth_stack, equivalent_blanks_cur
                    print 'wrote a dedent' + '\n'
                    write_buffer += ' %s ' % DEDENT
                    indent_stack_cur -= 1
                    indent_depth_stack.pop()
                    #print "detected dedentation: first non"
            elif equivalent_blanks_cur > equivalent_blanks_pre:
                if no_indent:
                    print "no indent on"
                    write_buffer += ch
                    continue
                write_buffer += ' %s ' % INDENT
                print indent_depth_stack, equivalent_blanks_cur
                print 'wrote an indent'
                indent_depth_stack.append(equivalent_blanks_cur)
                equivalent_blanks_pre = equivalent_blanks_cur
                equivalent_blanks_cur = 0
                indent_stack_cur += 1
                #print "detected indentation"
            elif equivalent_blanks_pre == equivalent_blanks_cur:
                equivalent_blanks_cur = 0
            else:
                print "detected dedentation"
                write_buffer += ' %s ' % DEDENT
                indent_depth_stack.pop()
                while indent_depth_stack[-1] > equivalent_blanks_cur:
                    indent_depth_stack.pop()
                    write_buffer += ' %s ' % DEDENT
                    indent_stack_cur -= 1
                equivalent_blanks_pre = equivalent_blanks_cur
                equivalent_blanks_cur = 0
                indent_stack_cur -= 1
        elif whitespace_left: 
            if balanced and ch == ' ':
                equivalent_blanks_cur += 1
                #print equivalent_blanks_cur
                continue
            else:
                if balanced:
                    equivalent_blanks_cur += 8
                continue
        if ch == '"':
            write_buffer += ch
            if not single_quote_toggle:
                double_quote_toggle = not double_quote_toggle
        elif ch == "'":
            write_buffer += ch
            if not double_quote_toggle:
                single_quote_toggle = not single_quote_toggle
        # comment at end of line
        elif ch == '#':
            in_comment = True
        # end of line
        elif not balanced and ch == '\n' or (not double_quote_toggle and not single_quote_toggle and ch == '\n'):
            if not balanced:
                #print "this shit ain't balanced"
                #print write_buffer
                write_buffer += '\\'
                slash_count += 1
            elif len(write_buffer) > 0 and write_buffer[-1] == '\\':
                slash_count += 1
                no_indent = True
            else:
                no_indent = False
                write_buffer += slash_count*'\n'
                slash_count = 0
            write_buffer += ch
            #print '----'
            #print write_buffer
            #print '----'
            if in_lonely_comment:
                #print 'end of comment'
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
        indent_depth_stack.pop()
    while re.search(multiline_patt, result_file):
        result_file = re.sub(multiline_patt, lambda m: re.sub(r'\s*\\\n\s*', '', m.groups()[0]), result_file)
        #print result_file
    while re.search(multi_a_patt, result_file):
        result_file = re.sub(multi_a_patt, lambda m: "'" + eval(m.groups()[1]) + eval(m.groups()[3]) + "'", result_file)
    #print result_file
    while re.search(multi_b_patt, result_file):
        result_file = re.sub(multi_b_patt, lambda m: '"' + eval(m.groups()[1]) + eval(m.groups()[3]) + '"', result_file)
    while re.search(triple_patt, result_file):
        match = re.search(triple_patt, result_file)
        result_file = re.sub(triple_patt, lambda m: '"' + m.group(2) + m.group(4) + '"', result_file)
    while re.search(space_sep_str_patt, result_file):
        match = re.search(space_sep_str_patt, result_file)
        result_file = re.sub(space_sep_str_patt, lambda m: '"' + m.group(2) + m.group(4) + '"', result_file)
    return result_file

if __name__ == '__main__':
    import sys
    arg = sys.argv[1]
    with open(arg.split('.')[0] + '.py.processed', 'w') as f:
        try:
            f.write(process(arg))
        except:
            exit(1)
