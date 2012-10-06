#include "builtin.hpp"
#include "sys.hpp"
#include "re.hpp"
#include "pre.hpp"

namespace __pre__ {

str *const_0, *const_1, *const_10, *const_11, *const_12, *const_13, *const_14, *const_15, *const_16, *const_17, *const_18, *const_19, *const_2, *const_20, *const_21, *const_22, *const_23, *const_24, *const_25, *const_26, *const_27, *const_28, *const_29, *const_3, *const_4, *const_5, *const_6, *const_7, *const_8, *const_9;


str *DEDENT, *INDENT, *__name__, *arg;
__ss_int indent_len;
file *f;


static inline void *__lambda3__(__re__::match_object *m);
static inline str *__lambda4__(__re__::match_object *m);
static inline str *__lambda0__(__re__::match_object *m);
static inline str *__lambda5__(__re__::match_object *m);
static inline void *__lambda2__(__re__::match_object *m);
static inline str *__lambda1__(__re__::match_object *m);

static inline void *__lambda3__(__re__::match_object *m) {
    
    return (((const_0)->__add__())->__add__())->__add__(const_0);
}

static inline str *__lambda4__(__re__::match_object *m) {
    
    return __add_strs(4, const_0, m->group(1, 2), m->group(1, 4), const_0);
}

static inline str *__lambda0__(__re__::match_object *m) {
    
    return const_1;
}

static inline str *__lambda5__(__re__::match_object *m) {
    
    return __add_strs(4, const_0, m->group(1, 2), m->group(1, 4), const_0);
}

static inline void *__lambda2__(__re__::match_object *m) {
    
    return (((const_2)->__add__())->__add__())->__add__(const_2);
}

static inline str *__lambda1__(__re__::match_object *m) {
    
    return __re__::sub(const_3, const_4, (m->groups(0))->__getfast__(0), 0);
}

pyiter<str *> *preprocess(str *infile) {
    str *lonely_patt;
    pyiter<str *> *f;

    WITH_VAR(open(infile, const_5),f,0)
        f = f->read();
        lonely_patt = const_6;
        f = __re__::sub(lonely_patt, __lambda0__, f, 0);
        return f;
    END_WITH
    return 0;
}

str *process(str *in_file) {
    __re__::match_object *match;
    pyiter<str *> *__3, *input_text;
    __ss_bool __10, __11, __12, __13, __14, __15, __16, __17, __18, __19, __20, __21, __22, __23, __24, __25, __26, __27, __28, __29, __30, __7, __8, __9, balanced, double_quote_toggle, in_comment, in_lonely_comment, no_indent, single_quote_toggle, whitespace_left;
    __iter<str *> *__4;
    str *ch, *line_buffer, *multi_a_patt, *multi_b_patt, *multiline_patt, *result_file, *space_sep_str_patt, *triple_patt, *write_buffer;
    pyiter<str *>::for_in_loop __6;
    list<__ss_int> *indent_depth_stack;
    __ss_int __5, brace_stack, curly_stack, equivalent_blanks_cur, equivalent_blanks_pre, indent_stack_cur, indent_stack_pre, origin_index, paren_stack, single_quote_stack, slash_count;

    result_file = const_4;
    equivalent_blanks_pre = 0;
    equivalent_blanks_cur = 0;
    origin_index = 0;
    input_text = preprocess(in_file);
    paren_stack = 0;
    brace_stack = 0;
    curly_stack = 0;
    slash_count = 0;
    single_quote_toggle = False;
    double_quote_toggle = False;
    indent_stack_cur = 0;
    indent_stack_pre = 0;
    indent_depth_stack = (new list<__ss_int>(1,0));
    write_buffer = const_4;
    single_quote_stack = 0;
    in_lonely_comment = False;
    in_comment = False;
    balanced = False;
    whitespace_left = True;
    triple_patt = const_7;
    space_sep_str_patt = const_8;
    multiline_patt = const_9;
    multi_a_patt = const_10;
    multi_b_patt = const_11;
    line_buffer = const_4;

    FOR_IN(ch,input_text,3,5,6)
        balanced = __AND(___bool((paren_stack==0)), __AND(___bool((curly_stack==0)), ___bool((brace_stack==0)), 8), 7);
        if (in_lonely_comment) {
            if ((__eq(ch, const_12) and __NOT(single_quote_toggle) and __NOT(double_quote_toggle))) {
                result_file = (result_file)->__iadd__(const_12);
                write_buffer = const_4;
                in_lonely_comment = False;
                in_comment = False;
                continue;
            }
        }
        if ((__NOT(in_comment) and __NOT(in_lonely_comment))) {
            if (__eq(ch, const_13)) {
                paren_stack = (paren_stack+1);
            }
            else if (__eq(ch, const_14)) {
                paren_stack = (paren_stack-1);
            }
            else if (__eq(ch, const_15)) {
                brace_stack = (brace_stack+1);
            }
            else if (__eq(ch, const_16)) {
                brace_stack = (brace_stack-1);
            }
            else if (__eq(ch, const_17)) {
                curly_stack = (curly_stack+1);
            }
            else if (__eq(ch, const_18)) {
                curly_stack = (curly_stack-1);
            }
        }
        if (in_comment) {
            if ((__NOT(double_quote_toggle) and __NOT(single_quote_toggle) and __eq(ch, const_12))) {
                if (balanced) {
                    write_buffer = (write_buffer)->__iadd__(ch);
                }
                else {
                    write_buffer = (write_buffer)->__iadd__(const_19);
                    write_buffer = (write_buffer)->__iadd__(ch);
                    slash_count = (slash_count+1);
                }
                result_file = (result_file)->__iadd__(write_buffer);
                write_buffer = const_4;
                in_comment = False;
                in_lonely_comment = False;
                whitespace_left = True;
                continue;
            }
            else if (__eq(ch, const_0)) {
                if (__NOT(single_quote_toggle)) {
                    double_quote_toggle = __NOT(double_quote_toggle);
                }
            }
            else if (__eq(ch, const_2)) {
                if (__NOT(double_quote_toggle)) {
                    single_quote_toggle = __NOT(single_quote_toggle);
                }
            }
            else {
                continue;
            }
            continue;
        }
        else if ((whitespace_left and __NOT(___bool(__re__::match(const_20, ch, 0))))) {
            if (__eq(ch, const_12)) {
                whitespace_left = True;
                write_buffer = (write_buffer)->__iadd__(const_12);
                equivalent_blanks_pre = equivalent_blanks_cur;
                equivalent_blanks_cur = 0;
                continue;
            }
            indent_stack_pre = indent_stack_cur;
            whitespace_left = False;
            if (__eq(ch, const_21)) {
                write_buffer = const_4;
                in_lonely_comment = True;
            }
            else if ((equivalent_blanks_cur<indent_depth_stack->__getfast__((-1)))) {

                while ((indent_depth_stack->__getfast__((-1))>equivalent_blanks_cur)) {
                    indent_depth_stack->pop();
                    write_buffer = (write_buffer)->__iadd__(__modct(const_22, 1, DEDENT));
                    indent_stack_cur = (indent_stack_cur-1);
                }
                result_file = (result_file)->__iadd__(write_buffer);
                write_buffer = const_4;
                equivalent_blanks_pre = indent_depth_stack->__getfast__((-1));
            }
            else if ((equivalent_blanks_cur==0)) {

                while ((indent_stack_cur>0)) {
                    write_buffer = (write_buffer)->__iadd__(__modct(const_22, 1, DEDENT));
                    indent_stack_cur = (indent_stack_cur-1);
                    equivalent_blanks_pre = 0;
                    equivalent_blanks_cur = 0;
                    indent_depth_stack->pop();
                }
            }
            else if ((equivalent_blanks_cur>equivalent_blanks_pre)) {
                if (no_indent) {
                    write_buffer = (write_buffer)->__iadd__(ch);
                    continue;
                }
                write_buffer = (write_buffer)->__iadd__(__modct(const_22, 1, INDENT));
                indent_depth_stack->append(equivalent_blanks_cur);
                equivalent_blanks_pre = equivalent_blanks_cur;
                equivalent_blanks_cur = 0;
                indent_stack_cur = (indent_stack_cur+1);
            }
            else if ((equivalent_blanks_pre==equivalent_blanks_cur)) {
                equivalent_blanks_cur = 0;
            }
            else {
                write_buffer = (write_buffer)->__iadd__(__modct(const_22, 1, DEDENT));
                indent_depth_stack->pop();

                while ((indent_depth_stack->__getfast__((-1))>equivalent_blanks_cur)) {
                    indent_depth_stack->pop();
                    write_buffer = (write_buffer)->__iadd__(__modct(const_22, 1, DEDENT));
                    indent_stack_cur = (indent_stack_cur-1);
                }
                equivalent_blanks_pre = equivalent_blanks_cur;
                equivalent_blanks_cur = 0;
                indent_stack_cur = (indent_stack_cur-1);
            }
        }
        else if (whitespace_left) {
            if ((balanced and __eq(ch, const_23))) {
                equivalent_blanks_cur = (equivalent_blanks_cur+1);
                continue;
            }
            else {
                if (balanced) {
                    equivalent_blanks_cur = (equivalent_blanks_cur+8);
                }
                continue;
            }
        }
        if (__eq(ch, const_0)) {
            write_buffer = (write_buffer)->__iadd__(ch);
            if (__NOT(single_quote_toggle)) {
                double_quote_toggle = __NOT(double_quote_toggle);
            }
        }
        else if (__eq(ch, const_2)) {
            write_buffer = (write_buffer)->__iadd__(ch);
            if (__NOT(double_quote_toggle)) {
                single_quote_toggle = __NOT(single_quote_toggle);
            }
        }
        else if (__eq(ch, const_21)) {
            in_comment = True;
        }
        else if (((__NOT(balanced) and __eq(ch, const_12)) or (__NOT(double_quote_toggle) and __NOT(single_quote_toggle) and __eq(ch, const_12)))) {
            if (__NOT(balanced)) {
                write_buffer = (write_buffer)->__iadd__(const_19);
                slash_count = (slash_count+1);
            }
            else if (((len(write_buffer)>0) and __eq(write_buffer->__getfast__((-1)), const_19))) {
                slash_count = (slash_count+1);
                no_indent = True;
            }
            else {
                no_indent = False;
                write_buffer = (write_buffer)->__iadd__(__mul2(slash_count, const_12));
                slash_count = 0;
            }
            write_buffer = (write_buffer)->__iadd__(ch);
            if (in_lonely_comment) {
                write_buffer = const_12;
            }
            result_file = (result_file)->__iadd__(write_buffer);
            write_buffer = const_4;
            in_lonely_comment = False;
            whitespace_left = True;
        }
        else {
            write_buffer = (write_buffer)->__iadd__(ch);
        }
    END_FOR

    result_file = (result_file)->__iadd__(write_buffer);

    while ((indent_stack_cur>0)) {
        indent_stack_cur = (indent_stack_cur-1);
        result_file = (result_file)->__iadd__(__modct(const_22, 1, DEDENT));
        indent_depth_stack->pop();
    }

    while (___bool(__re__::search(multiline_patt, result_file, 0))) {
        result_file = __re__::sub(multiline_patt, __lambda1__, result_file, 0);
        print2(NULL,0,1, result_file);
    }

    while (___bool(__re__::search(multi_a_patt, result_file, 0))) {
        result_file = __re__::sub(multi_a_patt, __lambda2__, result_file, 0);
    }
    print2(NULL,0,1, result_file);

    while (___bool(__re__::search(multi_b_patt, result_file, 0))) {
        result_file = __re__::sub(multi_b_patt, __lambda3__, result_file, 0);
    }

    while (___bool(__re__::search(triple_patt, result_file, 0))) {
        match = __re__::search(triple_patt, result_file, 0);
        result_file = __re__::sub(triple_patt, __lambda4__, result_file, 0);
    }

    while (___bool(__re__::search(space_sep_str_patt, result_file, 0))) {
        match = __re__::search(space_sep_str_patt, result_file, 0);
        result_file = __re__::sub(space_sep_str_patt, __lambda5__, result_file, 0);
    }
    return result_file;
}

void __init() {
    const_0 = __char_cache[34];;
    const_1 = new str("#comment\n");
    const_2 = __char_cache[39];;
    const_3 = new str("\\s*\\\\\\n\\s*");
    const_4 = new str("");
    const_5 = __char_cache[114];;
    const_6 = new str("#.*$");
    const_7 = new str("(\\\"\\\"\\\"|\\'\\'\\')(.*?)\\1\\s*(\\\"\\\"\\\"|\\'\\'\\')(.*?)\\3");
    const_8 = new str("(\\'|\\\")(.*?)\\1\\s*(\\\"|\\')(.*?)\\3");
    const_9 = new str("((.|\\\"|\\')*\\\\\\n(.*\\\\\\n)*((.|\\\"|\\')*\\n))");
    const_10 = new str("(((\\'|\\\").*?\\3)\\s*((\\\"\\\"\\\"|\\'\\'\\').*?\\5))");
    const_11 = new str("(((\\\"\\\"\\\"|\\'\\'\\').*?\\3)\\s*((\\'|\\\").*?\\5))");
    const_12 = __char_cache[10];;
    const_13 = __char_cache[40];;
    const_14 = __char_cache[41];;
    const_15 = __char_cache[91];;
    const_16 = __char_cache[93];;
    const_17 = __char_cache[123];;
    const_18 = __char_cache[125];;
    const_19 = __char_cache[92];;
    const_20 = new str("(\\ |\\t)");
    const_21 = __char_cache[35];;
    const_22 = new str(" %s ");
    const_23 = __char_cache[32];;
    const_24 = new str("@71684aa3418631a412d6105e160131b9");
    const_25 = new str("@d2b3009662c463c2ab96d1a73872c6f1");
    const_26 = new str("__main__");
    const_27 = __char_cache[46];;
    const_28 = new str(".py.processed");
    const_29 = __char_cache[119];;

    __name__ = new str("__main__");

    INDENT = const_24;
    DEDENT = const_25;
    indent_len = len(INDENT);
    if (__eq(__name__, const_26)) {
        arg = (__sys__::argv)->__getfast__(1);
        WITH_VAR(open(((arg->split(const_27))->__getfast__(0))->__add__(const_28), const_29),f,1)
            f->write(process(arg));
        END_WITH
    }
}

} // module namespace

int main(int __ss_argc, char **__ss_argv) {
    __shedskin__::__init();
    __re__::__init();
    __sys__::__init(__ss_argc, __ss_argv);
    __shedskin__::__start(__pre__::__init);
}
