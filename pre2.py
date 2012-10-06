import re
import sys

#indentation token
INDENT = '@71684aa3418631a412d6105e160131b9'
#dedentation token
DEDENT = '@d2b3009662c463c2ab96d1a73872c6f1'
indent_len = len(INDENT)

# remove all lonely comments (comments with a line to themselves)
def preprocess(infile):
    with open(infile, 'r') as f:
        f = f.read()
        lonely_patt = r'#.*$'
        f = re.sub(lonely_patt, lambda m: '#comment\n', f)
        return f

# return a string with indentation added, comments removed, 
# multiline expressions combined into a single expression, etc.
def process(in_file):
    result_file = ""
    equivalent_blanks_pre = 0
    equivalent_blanks_cur = 0
    origin_index = 0
    input_text = preprocess(in_file)

    # balance
    paren_stack = 0
    brace_stack = 0
    curly_stack = 0
    balanced = False
    
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

    # True if still counting whitepsace at beginning of a line
    whitespace_left = True 

   # matches two triple quoted strings (''' or """) in a row, separated by
   # 0 or more spaces
    triple_patt = r'(\"\"\"|\'\'\')(.*?)\1\s*(\"\"\"|\'\'\')(.*?)\3'

    # matches two '"' or "'" delimited strings in a row, separated 
    # by 0 or more spaces
    space_sep_str_patt = r'(\'|\")(.*?)\1\s*(\"|\')(.*?)\3'

    # matches a string or statement over multiple lines, each line followed by a '\'
    multiline_patt = r'((.|\"|\')*\\\n(.*\\\n)*((.|\"|\')*\n))'

    # matches a space_separated_string and then a triple string
    multi_a_patt = r'(((\'|\").*?\3)\s*((\"\"\"|\'\'\').*?\5))'

    # matches a triple_string and then a space_separated_strin
    multi_b_patt = r'(((\"\"\"|\'\'\').*?\3)\s*((\'|\").*?\5))'

    # build up multiline statements in here
    line_buffer = ''

    for ch in input_text:
        if in_lonely_comment:
            if ch == '\n' and not single_quote_toggle and not double_quote_toggle:
                result_file += '\n'
                write_buffer = ''
                in_lonely_comment = False
                in_comment = False
                continue
        # keep track of balance
        balanced = paren_stack == 0 and curly_stack == 0 and brace_stack == 0
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

        # ch is the first non-whitespace char of the line
        elif whitespace_left and not re.match(r'(\ |\t)', ch):
            #print 'newline: %d' % equivalent_blanks_cur
            if ch == '\n':
                #print "empty line"
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

            # some dedentation will be necessary
            elif equivalent_blanks_cur < indent_depth_stack[-1]:
                #print 'fewer blanks: %s' % ch
                while indent_depth_stack[-1] > equivalent_blanks_cur:
                    indent_depth_stack.pop()
                    write_buffer += ' %s ' % DEDENT
                    indent_stack_cur -= 1
                    #print 'wrote a dedent'
                result_file += write_buffer
                write_buffer = ''
                equivalent_blanks_pre = indent_depth_stack[-1]
                
            # No indentation on current line
            elif equivalent_blanks_cur == 0:
                while indent_stack_cur > 0:
                    write_buffer += ' %s ' % DEDENT
                    indent_stack_cur -= 1
                    equivalent_blanks_pre = 0
                    equivalent_blanks_cur = 0
                    indent_depth_stack.pop()
                    #print "detected dedentation: first non"

            elif equivalent_blanks_cur > equivalent_blanks_pre:
                #print "maybe going to indent"
                if no_indent:
                    #print "no indent on"
                    write_buffer += ch
                    continue
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

        # still have not reached the first non-qhitespace char on this line
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
        elif (not balanced and ch == '\n') or \
            (not double_quote_toggle and not single_quote_toggle and ch == '\n'):
            if not balanced:
                #print "this shit ain't balanced"
                #print write_buffer
                write_buffer += '\\'
                slash_count += 1
            elif len(write_buffer) > 0 and write_buffer[-1] == '\\':
                slash_count += 1
                no_indent = True
            # it's the last line in a multiline construction - if we were in one
            else:
                no_indent = False
                write_buffer += slash_count*'\n'
                slash_count = 0
            write_buffer += ch
            result_file += write_buffer 
            write_buffer = ""
            in_lonely_comment = False
            in_comment = False
            whitespace_left = True
        else:
            write_buffer += ch
    result_file += write_buffer

    # add all required dedentation at the end of the file
    while indent_stack_cur > 0:
        indent_stack_cur -= 1
        result_file += ' %s ' % DEDENT
        indent_depth_stack.pop()

    # replace multiline expressions with single line expressions, preserving 
    # spacing by inserting newlines
    while re.search(multiline_patt, result_file):
        result_file = re.sub(multiline_patt, lambda m: re.sub(r'\s*\\\n\s*', '', m.groups()[0]), result_file)
        print result_file

    # replace space separated strings of type a with a single string
    while re.search(multi_a_patt, result_file):
        result_file = re.sub(multi_a_patt, lambda m: "'" + eval(m.groups()[1]) + eval(m.groups()[3]) + "'", result_file)
    print result_file

    # replace space separated strings of type b with a  single string
    while re.search(multi_b_patt, result_file):
        result_file = re.sub(multi_b_patt, lambda m: '"' + eval(m.groups()[1]) + eval(m.groups()[3]) + '"', result_file)

    # replace triple quoted space separated strings
    while re.search(triple_patt, result_file):
        match = re.search(triple_patt, result_file)
        result_file = re.sub(triple_patt, lambda m: '"' + m.group(2) + m.group(4) + '"', result_file)

    # replace regular space separated strings
    while re.search(space_sep_str_patt, result_file):
        match = re.search(space_sep_str_patt, result_file)
        result_file = re.sub(space_sep_str_patt, lambda m: '"' + m.group(2) + m.group(4) + '"', result_file)
    return result_file

if __name__ == '__main__':
    arg = sys.argv[1]
    with open(arg.split('.')[0] + '.py.processed', 'w') as f:
        f.write(process(arg))