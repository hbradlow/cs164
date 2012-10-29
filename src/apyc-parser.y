/* -*-C++-*- */
/* Generated from apyc.hn at Mon Oct 29 01:13:00 2012 GMT. */

%code top {

#define YYPARAM Tree_Semantics< AST >
#define YYPRODUCING_TREES
#define YYERROR_FUNCTION_NAME parse_error

# define YY_PARSER_1
# include "horn-parse-lex.cc"
}

%{

    YYNAMESPACE_OPEN

%}

/* User prologue code */


#line 7 "apyc.hn"


%token INT
%token STRING
%token ID

%{
    #include <string>
    #include "apyc.h"
    #include "ast.h"

    using namespace std;

    static AST_Ptr theTree;
   
    static const char* last_source_loc;

    /** Report an error (same arguments as error) at LOC, or the end of the 
     *  last file if LOC is unknown. */
    static void parse_error (const char* loc, const char* format, ...);

    /** Assuming that TEXT is the whitespace at the beginning of a line, returns
     *  or queues the indicated INDENT and DEDENT tokens. */
    static int do_indent(const char* text);

    /** Nesting level of current source position in '[', '(', and '{'
     *  brackets. */
    static int bracket_depth;
    /** Current nesting depth within "if", "while", and "for" statements. */
    static int control_depth;
    /** Current nesting depth within "def" and "class" statements. */
    static int defn_depth;
    /** Current loop depth within "while" and "for" statements. */
    static int loop_depth;
    /** Current nesting depth within "def" statements (functions). */
    static int func_depth;

    /** Output an error message if a "def" statement is not permitted
     *  at the current source position. */
    static void check_def_placement ();
    /** Output an error message if a "class" statement is not permitted
     *  at the current source position. */
    static void check_class_placement ();
    /** Output an error message TEXT is not in the required range for
     *  integer numerals.  It is assumed to have the form of a valid
     *  numeral otherwise. */
    static void check_numeral (const char* text);
    /** Output an error message if not nested in the main body of a loop (
     *  (not including its "else" clause). */
    static void check_in_loop ();
    /** Output an error message if not nested inside a function definition. */
    static void check_in_func ();

    /** Finish processing the current source file, and return to the
     *  previous one.  Returns true iff there is a previous source
     *  file and false if at the end of input. */
    static bool pop_source_file ();

    /** Create a "unop" node out of operator OP (a token) and operand
     *  RIGHT. */
    static AST_Ptr make_unop (const List_Ptr& operands);
    /** Create a "binop" node out of operator OP (a token) and operands
     *  LEFT and RIGHT. */
    static AST_Ptr make_binop (const List_Ptr& operands);

    /** Create an id out of the text and location of TOKEN, which must be a
     *  token. */
    static AST_Ptr make_id (AST_Ptr& token);
    /** Create an id out of the text and location of (*OPERAND)[0]. OPERAND 
     *  must be a singleton list containing a token. */
    static AST_Ptr make_id (const List_Ptr& operand);

    /** Increment COUNT. */
    static inline void
    incr (int& count)
    {
        count += 1;
    }

    /** Decrement COUNT, but no further than 0. */
    static inline void
    decr (int& count)
    { 
        count -= 1;
        if (count < 0)
            count = 0;
    }
%}

%debug
#line 97 "apyc.hn"


%left "or"
%left "and"
%left "not"
%left "<" ">" "==" ">=" "<=" "!=" "is" "in"
%left "+" "-"
%left "%" "*" "/" "//"
%left UNOP
%right "**"

%token DIVDIV "//"
%token POW "**"

/* The following tokens represent keywords and node types, sometimes both.
 * In order to keep information about node types together, I've used a little 
 * trick.  In a rule such as
 *     if_stmt: "if"^ expression ":"! ...
 * where the relevant keyword also happens to coincide with the external
 * name of the AST operator corresponding to this statement, we define
 *     %token IF "if"
 * In a rule such as
 *     dict_display: "{"! key_datum_list? "}"! 
 *              { $$ = $^(DICT_DISPLAY, $*); }
 * where the there is no such correspondence, we define instead
 *     %token DICT_DISPLAY "@dict_display"
 * Since "@dict_display" is not a valid token (it would be an error for this
 * to appear in any Python program) and does not appear in the grammar, this
 * declaration has no effect on the lexical language recognized.  However, it
 * still provides an easy way to find the external name of an operator.
 * Suppose that yyexternal_token_name(SYNTAX) is NAME for an operator 
 * whose syntactic category is SYNTAX.  If NAME starts with k "@" characters,
 * then by default the external AST operator name for SYNTAX is NAME+k;
 * otherwise, it is simply NAME.  Hence, the lexical token strings can do double
 * duty.   This convention allows us to have several different operators with 
 * the same printed name, and also prevents operators whose names are not
 * keywords from interfering with the use of those names as legitimate
 * identifiers. */

%token AND "and"
%token ASSIGN "@assign"
%token ATTRIBUTEREF "@attributeref"
%token BINOP "@binop"
%token BLOCK "@block"
%token BREAK "break"
%token CALL "@call"
%token CLASS_BLOCK "@@block"
%token COMPARE "@compare"
%token LEFT_COMPARE "@left_compare"
%token CONTINUE "continue"
%token DEDENT
%token DEF "def"
%token DICT_DISPLAY "@dict_display"
%token EMPTY
%token EXPR_LIST "@expr_list"
%token FOR "for"
%token FORMALS_LIST "@formals_list"
%token FUNCTION_TYPE "@function_type"
%token IF "if"
%token IF_EXPR "@if_expr"
%token INDENT 
%token INT_LITERAL "@int_literal"
%token LIST_DISPLAY "@list_display"
%token METHOD "@def"
%token MODULE "@module"
%token NATIVE "native"
%token NOT "not"
%token OR "or"
%token PAIR "@pair"
%token PRINT "@print"
%token PRINTLN "@println"
%token SLICING "@slicing"
%token SLICING_TARGET "@@slicing"
%token STMT_LIST "@stmt_list"
%token STRING_LITERAL
%token SUBSCRIPTION "@subscription"
%token SUBSCRIPTION_TARGET "@@subscription"
%token TARGET_LIST "@target_list"
%token TYPE_FORMALS_LIST "@type_formals_list"
%token TUPLE "@tuple"
%token TYPE "@type"
%token TYPE_LIST "@type_list"
%token TYPE_VAR "@type_var"
%token TYPED_ID "@typed_id"
%token UNOP "@unop"
%token WHILE "while"

%glr-parser

%expect-rr 18
%expect 2

#line 208 "apyc-parser.y"

/* Horn prologue */

%defines
%token-table

%{

#define YY_PARSER_2
#include "horn-parse-lex.cc"

%}

/* Token definitions */

%token _TOK_4 "!="
%token '%' "%"
%token '(' "("
%token ')' ")"
%token '*' "*"
%token '+' "+"
%token ',' ","
%token '-' "-"
%token _TOK_15 "->"
%token '.' "."
%token '/' "/"
%token ':' ":"
%token _TOK_14 "::"
%token ';' ";"
%token '<' "<"
%token _TOK_2 "<="
%token '=' "="
%token _TOK_1 "=="
%token '>' ">"
%token _TOK_3 ">="
%token _TOK_9 ">>"
%token '[' "["
%token ']' "]"
%token _TOK_12 "class"
%token _TOK_11 "elif"
%token _TOK_0 "else"
%token _TOK_6 "in"
%token _TOK_5 "is"
%token _TOK_13 "of"
%token _TOK_7 "pass"
%token _TOK_8 "print"
%token _TOK_10 "return"
%token '{' "{"
%token '}' "}"
%token  NEWLINE
%token  RAWSTRING


/* Destroying discarded semantic values. */
%destructor { $$._destructor (); } <>

%{
static yyvar yyv_DEDENT;
static yyvar yyv_ID;
static yyvar yyv_INDENT;
static yyvar yyv_INT_LITERAL;
static yyvar yyv_NEWLINE;
static yyvar yyv_RAWSTRING;
static yyvar yyv_STRING;
static yyvar yyv_TYPE_VAR;
static yyvar yyv_argument_list;
static yyvar yyv_assignment_stmt;
static yyvar yyv_atom;
static yyvar yyv_attributeref;
static yyvar yyv_bound;
static yyvar yyv_break_stmt;
static yyvar yyv_call;
static yyvar yyv_classbody;
static yyvar yyv_classdef;
static yyvar yyv_comp_operator;
static yyvar yyv_compound_stmt;
static yyvar yyv_cond;
static yyvar yyv_conditional_expression;
static yyvar yyv_continue_stmt;
static yyvar yyv_dict_display;
static yyvar yyv_elifs;
static yyvar yyv_else_clause;
static yyvar yyv_elsepart;
static yyvar yyv_empty;
static yyvar yyv_enclosure;
static yyvar yyv_error;
static yyvar yyv_expr1;
static yyvar yyv_expr2;
static yyvar yyv_expr3;
static yyvar yyv_expression;
static yyvar yyv_expression_list0_no_comma;
static yyvar yyv_expression_list_no_comma;
static yyvar yyv_expression_or_list;
static yyvar yyv_expression_or_list0;
static yyvar yyv_expression_stmt;
static yyvar yyv_for_stmt;
static yyvar yyv_funcbody;
static yyvar yyv_funcdef;
static yyvar yyv_funcname;
static yyvar yyv_identifier;
static yyvar yyv_if_stmt;
static yyvar yyv_key_datum;
static yyvar yyv_key_datum_list;
static yyvar yyv_left;
static yyvar yyv_left_compare;
static yyvar yyv_list_display;
static yyvar yyv_literal;
static yyvar yyv_name;
static yyvar yyv_native;
static yyvar yyv_op;
static yyvar yyv_opt_type_annotation;
static yyvar yyv_parameter;
static yyvar yyv_parameter_list;
static yyvar yyv_parameterized_type;
static yyvar yyv_parenth_form;
static yyvar yyv_pass_stmt;
static yyvar yyv_primary;
static yyvar yyv_print_stmt;
static yyvar yyv_return_stmt;
static yyvar yyv_right;
static yyvar yyv_simple_stmt;
static yyvar yyv_slicing;
static yyvar yyv_statement;
static yyvar yyv_stmt_list;
static yyvar yyv_stmts;
static yyvar yyv_string_piece;
static yyvar yyv_stringliteral;
static yyvar yyv_subscription;
static yyvar yyv_suite;
static yyvar yyv_target;
static yyvar yyv_target_list;
static yyvar yyv_target_list1;
static yyvar yyv_thenpart;
static yyvar yyv_type;
static yyvar yyv_type_annotation;
static yyvar yyv_type_formals;
static yyvar yyv_type_list;
static yyvar yyv_type_params;
static yyvar yyv_type_var;
static yyvar yyv_types;
static yyvar yyv_while_stmt;

%}

%%

         

                        /* Main Grammar */

program : 
#line 349 "apyc.hn"
 __14 
                { YYCTLA($$,0,1,&$1); yylhs = YYMAKE_TREE (MODULE, yylhs.all_values ());
                  yylhs.set_loc (NULL);
                  theTree = yylhs.value (); } 
;



identifier : 
#line 356 "apyc.hn"
 ID { YYCTLPA($$,0,1,&$1);  yyv_ID = $1; }
;



atom : 
#line 359 "apyc.hn"
 identifier { YYCTLPA($$,0,1,&$1);  yyv_identifier = $1; }
 | 
#line 359 "apyc.hn"
 literal { YYCTLPA($$,0,1,&$1);  yyv_literal = $1; }
 | 
#line 359 "apyc.hn"
 enclosure { YYCTLPA($$,0,1,&$1);  yyv_enclosure = $1; }
;


  
enclosure : 
#line 362 "apyc.hn"
 parenth_form { YYCTLPA($$,0,1,&$1);  yyv_parenth_form = $1; }
 | 
#line 362 "apyc.hn"
 list_display { YYCTLPA($$,0,1,&$1);  yyv_list_display = $1; }
 | 
#line 362 "apyc.hn"
 dict_display { YYCTLPA($$,0,1,&$1);  yyv_dict_display = $1; }
;



literal : 
#line 365 "apyc.hn"
 
      stringliteral { YYCTLPA($$,0,1,&$1);  yyv_stringliteral = $1; }
 | 
#line 367 "apyc.hn"
 INT_LITERAL { YYCTLPA($$,0,1,&$1);  yyv_INT_LITERAL = $1; }
;



string_piece : 
#line 370 "apyc.hn"

      STRING { YYCTLPA($$,0,1,&$1);  yyv_STRING = $1; }
 | 
#line 372 "apyc.hn"
 RAWSTRING { YYCTLPA($$,0,1,&$1);  yyv_RAWSTRING = $1; }
;



/* The definition of stringliteral assumes that the first string_piece is
 * not required to retain its initial value.  Additional string literals are
 * appended to it as a side effect. */
stringliteral : 
#line 378 "apyc.hn"

      string_piece { YYCTLPA($$,0,1,&$1);  yyv_string_piece = $1; }
 | 
#line 380 "apyc.hn"
 stringliteral string_piece
                { YYCTLPA($$,0,2,&$1,&$2);  yyv_stringliteral = $1; yyv_string_piece = $2;yyv_stringliteral.value()->as_token()
                     ->append_text(yyv_string_piece.value()->as_token()
                                   ->string_text()); 
                  yylhs = yyv_stringliteral; } 
;



parenth_form : 
#line 387 "apyc.hn"
 "(" expression ")" { YYCTLPA($$,0,3,&$1,&$2,&$3);  $1.ignore(); $3.ignore(); yyv_expression = $2; }
 | 
#line 388 "apyc.hn"
 "(" __19 ")" 
                { YYCTLA($$,0,3,&$1,&$2,&$3);  $1.ignore(); $3.ignore();yylhs = YYMAKE_TREE(TUPLE, yylhs.all_values ()); } 
;



list_display : 
#line 392 "apyc.hn"
 "[" __20 "]" 
                { YYCTLA($$,0,3,&$1,&$2,&$3);  $1.ignore(); $3.ignore();yylhs = YYMAKE_TREE(LIST_DISPLAY, yylhs.all_values ()); } 
;


  
dict_display : 
#line 396 "apyc.hn"
 "{" __21 "}"
                { YYCTLA($$,0,3,&$1,&$2,&$3);  $1.ignore(); $3.ignore();yylhs = YYMAKE_TREE(DICT_DISPLAY, yylhs.all_values ()); } 
;


  
key_datum_list : 
#line 400 "apyc.hn"
 key_datum __23 __9 { YYCTLA($$,0,3,&$1,&$2,&$3);  }
;


  
key_datum : 
#line 403 "apyc.hn"
 expression ":" expression 
                { YYCTLPA($$,0,3,&$1,&$2,&$3);  $2.ignore(); yyv_expression = $1; yyv_expression = $3;yylhs = YYMAKE_TREE(PAIR, yylhs.all_values ()); } 
;



primary : 
#line 407 "apyc.hn"
 atom { YYCTLPA($$,0,1,&$1);  yyv_atom = $1; }
 | 
#line 408 "apyc.hn"
 attributeref { YYCTLPA($$,0,1,&$1);  yyv_attributeref = $1; }
 | 
#line 409 "apyc.hn"
 subscription { YYCTLPA($$,0,1,&$1);  yyv_subscription = $1; }
 | 
#line 410 "apyc.hn"
 slicing { YYCTLPA($$,0,1,&$1);  yyv_slicing = $1; }
 | 
#line 411 "apyc.hn"
 call { YYCTLPA($$,0,1,&$1);  yyv_call = $1; }
;



attributeref : 
#line 414 "apyc.hn"
 primary "." identifier 
                { YYCTLPA($$,0,3,&$1,&$2,&$3);  $2.ignore(); yyv_primary = $1; yyv_identifier = $3;yylhs = YYMAKE_TREE(ATTRIBUTEREF, yylhs.all_values ()); } 
;



subscription : 
#line 418 "apyc.hn"
 primary "[" expression_or_list "]" 
                { YYCTLPA($$,0,4,&$1,&$2,&$3,&$4);  $2.ignore(); $4.ignore(); yyv_primary = $1; yyv_expression_or_list = $3;yylhs = YYMAKE_TREE (SUBSCRIPTION, yyv_primary.value (),
                           yyv_expression_or_list.value (), 
                           make_id ("__getitem__", yyv_expression_or_list.loc ())); } 
;



slicing : 
#line 425 "apyc.hn"
 primary "[" bound  ":" bound  "]" 
      	        { YYCTLPA($$,0,6,&$1,&$2,&$3,&$4,&$5,&$6);  $2.ignore(); $4.ignore(); $6.ignore(); yyv_primary = $1; yyv_left = $3; yyv_bound = $3; yyv_right = $5; yyv_bound = $5;yylhs = YYMAKE_TREE (SLICING, yyv_primary.value (), 
                           yyv_left.value (), yyv_right.value (), 
                           make_id ("__getslice__", yyv_left.loc ())); } 
;



bound : 
#line 431 "apyc.hn"
 
      expression { YYCTLPA($$,0,1,&$1);  yyv_expression = $1; }
 | 
#line 433 "apyc.hn"
 empty { YYCTLPA($$,0,1,&$1);  yyv_empty = $1; }
;



call : 
#line 436 "apyc.hn"
 primary "(" argument_list ")" 
                { YYCTLPA($$,0,4,&$1,&$2,&$3,&$4);  $2.ignore(); $4.ignore(); yyv_primary = $1; yyv_argument_list = $3;yylhs = YYMAKE_TREE(CALL, yylhs.all_values ()); } 
 | 
#line 438 "apyc.hn"
 parameterized_type "(" argument_list ")" 
                { YYCTLPA($$,0,4,&$1,&$2,&$3,&$4);  $2.ignore(); $4.ignore(); yyv_parameterized_type = $1; yyv_argument_list = $3;yylhs = YYMAKE_TREE(CALL, yylhs.all_values ()); } 
;


  
argument_list : 
#line 442 "apyc.hn"
 __15
                /* Trailing comma requires GLR*/
                { YYCTLA($$,0,1,&$1); yylhs = YYMAKE_TREE(EXPR_LIST, yylhs.all_values ()); } 
;


  
expression : 
#line 447 "apyc.hn"
 
      conditional_expression { YYCTLPA($$,0,1,&$1);  yyv_conditional_expression = $1; }
;



  
conditional_expression : 
#line 452 "apyc.hn"
 expr1  "if" expr1  "else" expression  
                { YYCTLPA($$,0,5,&$1,&$2,&$3,&$4,&$5);  $2.ignore(); $4.ignore(); yyv_thenpart = $1; yyv_expr1 = $1; yyv_cond = $3; yyv_expr1 = $3; yyv_elsepart = $5; yyv_expression = $5;yylhs = YYMAKE_TREE(IF_EXPR, yyv_cond.value(), yyv_thenpart.value (), 
                          yyv_elsepart.value ()); } 
 | 
#line 456 "apyc.hn"
 expr1 { YYCTLPA($$,0,1,&$1);  yyv_expr1 = $1; }
;



  
expr1 : 
#line 460 "apyc.hn"
 
      expr2 { YYCTLPA($$,0,1,&$1);  yyv_expr2 = $1; }
 | 
#line 462 "apyc.hn"
 expr1 "or" expr1 { YYCTLPA($$,0,3,&$1,&$2,&$3);  $2.mark_tree_op (); yyv_expr1 = $1; yyv_expr1 = $3; }
 | 
#line 462 "apyc.hn"
 expr1 "and" expr1 { YYCTLPA($$,0,3,&$1,&$2,&$3);  $2.mark_tree_op (); yyv_expr1 = $1; yyv_expr1 = $3; }
 | 
#line 463 "apyc.hn"
 "not" expr1
                { YYCTLPA($$,0,2,&$1,&$2);  yyv_expr1 = $2;yylhs = make_unop (yylhs.all_values ()); } 
;



expression_list_no_comma : 
#line 467 "apyc.hn"

      expression __22   /* Requires GLR for trailiing "," */
                { YYCTLA($$,0,2,&$1,&$2); yylhs = YYMAKE_TREE(EXPR_LIST, yylhs.all_values ()); } 
;



expression_list0_no_comma : 
#line 473 "apyc.hn"
 __16
                { YYCTLA($$,0,1,&$1); yylhs = YYMAKE_TREE(EXPR_LIST, yylhs.all_values ()); } 
;



expression_or_list : 
#line 477 "apyc.hn"

       expression { YYCTLPA($$,0,1,&$1);  yyv_expression = $1; }
 | 
#line 479 "apyc.hn"
 __1 __8
                { YYCTLA($$,0,2,&$1,&$2); yylhs = YYMAKE_TREE(TUPLE, yylhs.all_values ()); } 
;



expression_or_list0 : 
#line 483 "apyc.hn"

      expression_or_list { YYCTLPA($$,0,1,&$1);  yyv_expression_or_list = $1; }
 | 
#line 485 "apyc.hn"
 empty { YYCTLPA($$,0,1,&$1);  yyv_empty = $1; }
;



comp_operator : 
#line 489 "apyc.hn"
 __0
                { YYCTLA($$,0,1,&$1); yylhs = make_id(yylhs.all_values ()); } 
 | 
#line 491 "apyc.hn"
 "is"  "not" 
                { YYCTLPA($$,0,2,&$1,&$2);  yyv_op = $1;yylhs = make_id("isnot", yyv_op.loc()); } 
 | 
#line 493 "apyc.hn"
 "not"  "in"
                { YYCTLPA($$,0,2,&$1,&$2);  yyv_op = $1;yylhs = make_id("notin", yyv_op.loc()); } 
;



expr2 : 
#line 497 "apyc.hn"
 
      left_compare comp_operator expr3
                { YYCTLPA($$,0,3,&$1,&$2,&$3);  yyv_left_compare = $1; yyv_comp_operator = $2; yyv_expr3 = $3;yylhs = YYMAKE_TREE(COMPARE, yylhs.all_values ()); } 
 | 
#line 500 "apyc.hn"
 expr3 comp_operator expr3  
                { YYCTLPA($$,0,3,&$1,&$2,&$3);  yyv_expr3 = $1; yyv_comp_operator = $2; yyv_expr3 = $3;yylhs = YYMAKE_TREE(COMPARE, yylhs.all_values ()); } 
 | 
#line 502 "apyc.hn"
 expr3 { YYCTLPA($$,0,1,&$1);  yyv_expr3 = $1; }
;



left_compare : 
#line 505 "apyc.hn"

      expr3 comp_operator expr3
                { YYCTLPA($$,0,3,&$1,&$2,&$3);  yyv_expr3 = $1; yyv_comp_operator = $2; yyv_expr3 = $3;yylhs = YYMAKE_TREE(LEFT_COMPARE, yylhs.all_values ()); } 
 | 
#line 508 "apyc.hn"
 left_compare comp_operator expr3
                { YYCTLPA($$,0,3,&$1,&$2,&$3);  yyv_left_compare = $1; yyv_comp_operator = $2; yyv_expr3 = $3;yylhs = YYMAKE_TREE(LEFT_COMPARE, yylhs.all_values ()); } 
;



expr3 : 
#line 512 "apyc.hn"
 
      primary { YYCTLPA($$,0,1,&$1);  yyv_primary = $1; }
 | 
#line 514 "apyc.hn"
 "-" expr3
                { YYCTLPA($$,0,2,&$1,&$2);  yyv_expr3 = $2;yylhs = make_unop (yylhs.all_values ()); }  %prec UNOP
 | 
#line 516 "apyc.hn"
 "+" expr3
                { YYCTLPA($$,0,2,&$1,&$2);  yyv_expr3 = $2;yylhs = make_unop (yylhs.all_values ()); }  %prec UNOP
 | 
#line 518 "apyc.hn"
 expr3 "+"
     expr3
                { YYCTLPA($$,0,3,&$1,&$2,&$3);  yyv_expr3 = $1; yyv_expr3 = $3;yylhs = make_binop (yylhs.all_values ()); } 
 | 
#line 518 "apyc.hn"
 expr3 "-"
     expr3
                { YYCTLPA($$,0,3,&$1,&$2,&$3);  yyv_expr3 = $1; yyv_expr3 = $3;yylhs = make_binop (yylhs.all_values ()); } 
 | 
#line 518 "apyc.hn"
 expr3 "*"
     expr3
                { YYCTLPA($$,0,3,&$1,&$2,&$3);  yyv_expr3 = $1; yyv_expr3 = $3;yylhs = make_binop (yylhs.all_values ()); } 
 | 
#line 518 "apyc.hn"
 expr3 "/"
     expr3
                { YYCTLPA($$,0,3,&$1,&$2,&$3);  yyv_expr3 = $1; yyv_expr3 = $3;yylhs = make_binop (yylhs.all_values ()); } 
 | 
#line 518 "apyc.hn"
 expr3 "//"
     expr3
                { YYCTLPA($$,0,3,&$1,&$2,&$3);  yyv_expr3 = $1; yyv_expr3 = $3;yylhs = make_binop (yylhs.all_values ()); } 
 | 
#line 518 "apyc.hn"
 expr3 "%"
     expr3
                { YYCTLPA($$,0,3,&$1,&$2,&$3);  yyv_expr3 = $1; yyv_expr3 = $3;yylhs = make_binop (yylhs.all_values ()); } 
 | 
#line 518 "apyc.hn"
 expr3 "**"
     expr3
                { YYCTLPA($$,0,3,&$1,&$2,&$3);  yyv_expr3 = $1; yyv_expr3 = $3;yylhs = make_binop (yylhs.all_values ()); } 
;


             
simple_stmt : 
#line 524 "apyc.hn"

      expression_stmt { YYCTLPA($$,0,1,&$1);  yyv_expression_stmt = $1; }
 | 
#line 526 "apyc.hn"
 assignment_stmt { YYCTLPA($$,0,1,&$1);  yyv_assignment_stmt = $1; }
 | 
#line 527 "apyc.hn"
 pass_stmt { YYCTLPA($$,0,1,&$1);  yyv_pass_stmt = $1; }
 | 
#line 528 "apyc.hn"
 print_stmt { YYCTLPA($$,0,1,&$1);  yyv_print_stmt = $1; }
 | 
#line 529 "apyc.hn"
 return_stmt { YYCTLPA($$,0,1,&$1);  yyv_return_stmt = $1; }
 | 
#line 530 "apyc.hn"
 break_stmt { YYCTLPA($$,0,1,&$1);  yyv_break_stmt = $1; }
 | 
#line 531 "apyc.hn"
 continue_stmt { YYCTLPA($$,0,1,&$1);  yyv_continue_stmt = $1; }
;



expression_stmt : 
#line 534 "apyc.hn"
 expression_or_list { YYCTLPA($$,0,1,&$1);  yyv_expression_or_list = $1; }
;



assignment_stmt : 
#line 537 "apyc.hn"
 
      target_list "=" expression_or_list
                { YYCTLPA($$,0,3,&$1,&$2,&$3);  $2.ignore(); yyv_target_list = $1; yyv_expression_or_list = $3;yylhs = YYMAKE_TREE (ASSIGN, yylhs.all_values ()); } 
 | 
#line 540 "apyc.hn"
 target_list "=" assignment_stmt
                { YYCTLPA($$,0,3,&$1,&$2,&$3);  $2.ignore(); yyv_target_list = $1; yyv_assignment_stmt = $3;yylhs = YYMAKE_TREE (ASSIGN, yylhs.all_values ()); } 
;



target_list : 
#line 544 "apyc.hn"
 
      target { YYCTLPA($$,0,1,&$1);  yyv_target = $1; }
 | 
#line 546 "apyc.hn"
 "(" target ")" { YYCTLPA($$,0,3,&$1,&$2,&$3);  $1.ignore(); $3.ignore(); yyv_target = $2; }
 | 
#line 547 "apyc.hn"
 target_list1 { YYCTLPA($$,0,1,&$1);  yyv_target_list1 = $1; }
 | 
#line 548 "apyc.hn"
 "(" target_list1 ")" { YYCTLPA($$,0,3,&$1,&$2,&$3);  $1.ignore(); $3.ignore(); yyv_target_list1 = $2; }
 | 
#line 549 "apyc.hn"
 "[" target_list1 "]" { YYCTLPA($$,0,3,&$1,&$2,&$3);  $1.ignore(); $3.ignore(); yyv_target_list1 = $2; }
 | 
#line 550 "apyc.hn"
 "[" target "]"
                { YYCTLPA($$,0,3,&$1,&$2,&$3);  $1.ignore(); $3.ignore(); yyv_target = $2;yylhs = YYMAKE_TREE (TARGET_LIST, yylhs.all_values ()); } 
;



target_list1 : /* empty */  { YYCTLPA($$,0,0);  }
 | 
#line 555 "apyc.hn"
 target __4 __9
                { YYCTLA($$,0,3,&$1,&$2,&$3); yylhs = YYMAKE_TREE(TARGET_LIST, yylhs.all_values ()); } 
 | 
#line 557 "apyc.hn"
 target ","
                { YYCTLPA($$,0,2,&$1,&$2);  $2.ignore(); yyv_target = $1;yylhs = YYMAKE_TREE(TARGET_LIST, yyv_target.value ()); } 
;


  
target : 
#line 561 "apyc.hn"
  
      identifier { YYCTLPA($$,0,1,&$1);  yyv_identifier = $1; }
 | 
#line 563 "apyc.hn"
 identifier type_annotation
                { YYCTLPA($$,0,2,&$1,&$2);  yyv_identifier = $1; yyv_type_annotation = $2;yylhs = YYMAKE_TREE(TYPED_ID, yylhs.all_values ()); } 
 | 
#line 565 "apyc.hn"
 attributeref { YYCTLPA($$,0,1,&$1);  yyv_attributeref = $1; }
 | 
#line 566 "apyc.hn"
 subscription { YYCTLPA($$,0,1,&$1);  yyv_subscription = $1; }
 | 
#line 567 "apyc.hn"
 slicing { YYCTLPA($$,0,1,&$1);  yyv_slicing = $1; }
;



pass_stmt : 
#line 570 "apyc.hn"
 "pass"   
                { YYCTLPA($$,0,1,&$1);  $1.ignore();yylhs = YYMAKE_TREE(STMT_LIST); } 
;



print_stmt : 
#line 574 "apyc.hn"
 
      "print" empty expression_list0_no_comma
                { YYCTLPA($$,0,3,&$1,&$2,&$3);  $1.ignore(); yyv_empty = $2; yyv_expression_list0_no_comma = $3;yylhs = YYMAKE_TREE(PRINTLN, yylhs.all_values ()); } 
 | 
#line 577 "apyc.hn"
 "print" ">>" expression 
                { YYCTLPA($$,0,3,&$1,&$2,&$3);  $1.ignore(); $2.ignore(); yyv_expression = $3;yylhs = YYMAKE_TREE(PRINTLN, yyv_expression.value (), YYMAKE_TREE(EXPR_LIST)); } 
 | 
#line 579 "apyc.hn"
 "print" ">>" expression "," expression_list_no_comma
                { YYCTLPA($$,0,5,&$1,&$2,&$3,&$4,&$5);  $1.ignore(); $2.ignore(); $4.ignore(); yyv_expression = $3; yyv_expression_list_no_comma = $5;yylhs = YYMAKE_TREE(PRINTLN, yylhs.all_values ()); } 
 | 
#line 581 "apyc.hn"
 "print" empty expression_list_no_comma ","
                { YYCTLPA($$,0,4,&$1,&$2,&$3,&$4);  $1.ignore(); $4.ignore(); yyv_empty = $2; yyv_expression_list_no_comma = $3;yylhs = YYMAKE_TREE(PRINT, yylhs.all_values ()); } 
 | 
#line 583 "apyc.hn"
 "print" ">>" expression "," expression_list_no_comma ","
                { YYCTLPA($$,0,6,&$1,&$2,&$3,&$4,&$5,&$6);  $1.ignore(); $2.ignore(); $4.ignore(); $6.ignore(); yyv_expression = $3; yyv_expression_list_no_comma = $5;yylhs = YYMAKE_TREE(PRINT, yylhs.all_values ()); } 
;



return_stmt : 
#line 587 "apyc.hn"
 "return" expression_or_list0
                { YYCTLPA($$,0,2,&$1,&$2);  $1.mark_tree_op (); yyv_expression_or_list0 = $2;check_in_func (); } 
;



break_stmt : 
#line 591 "apyc.hn"
 "break" { YYCTLPA($$,0,1,&$1);  $1.mark_tree_op ();check_in_loop (); } 
;



continue_stmt : 
#line 594 "apyc.hn"
 "continue" { YYCTLPA($$,0,1,&$1);  $1.mark_tree_op ();check_in_loop (); } 
;



compound_stmt : 
#line 597 "apyc.hn"
 
      if_stmt { YYCTLPA($$,0,1,&$1);  yyv_if_stmt = $1; }
 | 
#line 599 "apyc.hn"
 while_stmt { YYCTLPA($$,0,1,&$1);  yyv_while_stmt = $1; }
 | 
#line 600 "apyc.hn"
 for_stmt { YYCTLPA($$,0,1,&$1);  yyv_for_stmt = $1; }
 | 
#line 601 "apyc.hn"
 funcdef { YYCTLPA($$,0,1,&$1);  yyv_funcdef = $1; }
 | 
#line 602 "apyc.hn"
 classdef { YYCTLPA($$,0,1,&$1);  yyv_classdef = $1; }
;



stmts : 
#line 605 "apyc.hn"
 
      stmt_list NEWLINE { YYCTLPA($$,0,2,&$1,&$2);  $2.ignore(); yyv_stmt_list = $1; yyv_NEWLINE = $2; }
 | 
#line 607 "apyc.hn"
 NEWLINE INDENT __2 DEDENT { YYCTLA($$,0,4,&$1,&$2,&$3,&$4);  $1.ignore(); $2.ignore(); $4.ignore(); yyv_DEDENT = $4; }
 | 
#line 608 "apyc.hn"
 __error__ NEWLINE { YYCTLPA($$,0,2,&$1,&$2);  $1.ignore(); $2.ignore(); yyv_NEWLINE = $2; }
 | 
#line 609 "apyc.hn"
 NEWLINE INDENT __error__ DEDENT { YYCTLPA($$,0,4,&$1,&$2,&$3,&$4);  $1.ignore(); $2.ignore(); $3.ignore(); $4.ignore(); yyv_NEWLINE = $1; yyv_INDENT = $2; yyv_DEDENT = $4; }
;


  
suite : 
#line 612 "apyc.hn"

      stmts     { YYCTLPA($$,0,1,&$1);  yyv_stmts = $1;yylhs = YYMAKE_TREE(STMT_LIST, yylhs.all_values ()); } 
;



statement : 
#line 616 "apyc.hn"
 stmt_list NEWLINE { YYCTLPA($$,0,2,&$1,&$2);  $2.ignore(); yyv_stmt_list = $1; yyv_NEWLINE = $2; }
 | 
#line 616 "apyc.hn"
 compound_stmt { YYCTLPA($$,0,1,&$1);  yyv_compound_stmt = $1; }
;


  
stmt_list : 
#line 619 "apyc.hn"
 
      simple_stmt __24 __10 { YYCTLA($$,0,3,&$1,&$2,&$3);  }
;



if_stmt : 
#line 623 "apyc.hn"
 
      "if" expression ":"
                { YYCTLP($$, 0, 0);  yyv_expression = $2;incr (control_depth); }  
         suite
      elifs
                { YYCTLA($$,0,6,&$1,&$2,&$3,&$4,&$5,&$6);  $1.mark_tree_op (); $3.ignore(); yyv_suite = $5; yyv_elifs = $6;decr (control_depth); } 
;



elifs : 
#line 631 "apyc.hn"

      "elif" expression ":" suite elifs 
                { YYCTLPA($$,0,5,&$1,&$2,&$3,&$4,&$5);  $1.ignore(); $3.ignore(); yyv_expression = $2; yyv_suite = $4; yyv_elifs = $5;yylhs = YYMAKE_TREE (IF, yylhs.all_values ()); } 
 | 
#line 634 "apyc.hn"
 else_clause { YYCTLPA($$,0,1,&$1);  yyv_else_clause = $1; }
;



else_clause : 
#line 637 "apyc.hn"
/* empty */ 
       /* empty */
                { YYCTLPA($$,0,0); yylhs = YYMAKE_TREE(STMT_LIST); } 
 | 
#line 640 "apyc.hn"
 "else" ":" suite { YYCTLPA($$,0,3,&$1,&$2,&$3);  $1.ignore(); $2.ignore(); yyv_suite = $3; }
;



while_stmt : 
#line 643 "apyc.hn"
 
      "while" expression ":" 
                { YYCTLP($$, 0, 0);  yyv_expression = $2;incr (control_depth); incr (loop_depth); }  
           suite
                { YYCTL($$, 0, 0);  yyv_suite = $5;decr (loop_depth); } 
      else_clause
                { YYCTLA($$,0,7,&$1,&$2,&$3,&$4,&$5,&$6,&$7);  $1.mark_tree_op (); $3.ignore(); yyv_else_clause = $7;decr (control_depth); } 
;



for_stmt : 
#line 652 "apyc.hn"
 
      "for" target_list "in" expression_or_list ":" 
                { YYCTLP($$, 0, 0);  yyv_target_list = $2; yyv_expression_or_list = $4;incr (control_depth); incr (loop_depth); }  
           suite
                { YYCTL($$, 0, 0);  yyv_suite = $7;decr (loop_depth); } 
      else_clause
                { YYCTLA($$,0,9,&$1,&$2,&$3,&$4,&$5,&$6,&$7,&$8,&$9);  $1.mark_tree_op (); $3.ignore(); $5.ignore(); yyv_else_clause = $9;decr (control_depth); } 
;



funcdef : 
#line 661 "apyc.hn"
 
      "def" funcname "(" parameter_list ")" opt_type_annotation ":" 
                { YYCTLP($$, 0, 0);  yyv_funcname = $2; yyv_parameter_list = $4; yyv_opt_type_annotation = $6;check_def_placement (); 
                  incr (defn_depth); incr (func_depth); } 
           funcbody
                { YYCTLA($$,0,9,&$1,&$2,&$3,&$4,&$5,&$6,&$7,&$8,&$9);  $1.ignore(); $3.ignore(); $5.ignore(); $7.ignore(); yyv_funcbody = $9;decr (defn_depth); decr (func_depth); 
		  if (func_depth != 0 || defn_depth != 1)
		      yylhs = YYMAKE_TREE (DEF, yylhs.all_values ()); 
		  else
		      yylhs = YYMAKE_TREE (METHOD, yylhs.all_values ()); } 
;



funcbody : 
#line 675 "apyc.hn"

      stmts     { YYCTLPA($$,0,1,&$1);  yyv_stmts = $1;yylhs = YYMAKE_TREE(BLOCK, yylhs.all_values ()); } 
 | 
#line 677 "apyc.hn"
 native    { YYCTLPA($$,0,1,&$1);  yyv_native = $1;yylhs = YYMAKE_TREE(BLOCK, yylhs.all_values ()); } 
 | 
#line 678 "apyc.hn"
 NEWLINE INDENT native DEDENT
                { YYCTLPA($$,0,4,&$1,&$2,&$3,&$4);  $1.ignore(); $2.ignore(); $4.ignore(); yyv_NEWLINE = $1; yyv_INDENT = $2; yyv_native = $3; yyv_DEDENT = $4;yylhs = YYMAKE_TREE(BLOCK, yylhs.all_values ()); } 
;



native : 
#line 682 "apyc.hn"

      "native" stringliteral NEWLINE { YYCTLPA($$,0,3,&$1,&$2,&$3);  $1.mark_tree_op (); $3.ignore(); yyv_stringliteral = $2; yyv_NEWLINE = $3; }
;



parameter_list : 
#line 686 "apyc.hn"
/* empty */  
      /* empty */
                { YYCTLPA($$,0,0); yylhs = YYMAKE_TREE(FORMALS_LIST); } 
 | 
#line 689 "apyc.hn"
 __13 parameter __11 
                { YYCTLA($$,0,3,&$1,&$2,&$3); yylhs = YYMAKE_TREE(FORMALS_LIST, yylhs.all_values ()); } 
;


  

parameter : 
#line 694 "apyc.hn"
 identifier { YYCTLPA($$,0,1,&$1);  yyv_identifier = $1; }
 | 
#line 695 "apyc.hn"
 identifier type_annotation  { YYCTLPA($$,0,2,&$1,&$2);  yyv_identifier = $1; yyv_type_annotation = $2;yylhs = YYMAKE_TREE(TYPED_ID, yylhs.all_values ()); } 
;


  
funcname : 
#line 698 "apyc.hn"
  identifier { YYCTLPA($$,0,1,&$1);  yyv_identifier = $1; }
;



classdef : 
#line 700 "apyc.hn"
 "class" identifier  type_formals ":" 
                { YYCTLP($$, 0, 0);  yyv_name = $2; yyv_identifier = $2; yyv_type_formals = $3;check_class_placement (); incr (defn_depth); }  
               classbody
                { YYCTLA($$,0,6,&$1,&$2,&$3,&$4,&$5,&$6);  $1.mark_tree_op (); $4.ignore(); yyv_classbody = $6;decr (defn_depth); } 
;


  
type_formals : 
#line 707 "apyc.hn"
 __18
                { YYCTLA($$,0,1,&$1); yylhs = YYMAKE_TREE(TYPE_FORMALS_LIST, yylhs.all_values ()); } 
;



classbody : 
#line 711 "apyc.hn"

      stmts     { YYCTLPA($$,0,1,&$1);  yyv_stmts = $1;yylhs = YYMAKE_TREE(CLASS_BLOCK, yylhs.all_values ()); } 
;



type_annotation : 
#line 715 "apyc.hn"
 "::" type { YYCTLPA($$,0,2,&$1,&$2);  $1.ignore(); yyv_type = $2; }
;



opt_type_annotation : 
#line 718 "apyc.hn"
 
      type_annotation { YYCTLPA($$,0,1,&$1);  yyv_type_annotation = $1; }
 | 
#line 720 "apyc.hn"
 empty { YYCTLPA($$,0,1,&$1);  yyv_empty = $1; }
;

      

type : 
#line 723 "apyc.hn"
 
      parameterized_type { YYCTLPA($$,0,1,&$1);  yyv_parameterized_type = $1; }
 | 
#line 725 "apyc.hn"
 identifier 
                { YYCTLPA($$,0,1,&$1);  yyv_identifier = $1;yylhs = YYMAKE_TREE(TYPE, yyv_identifier, YYMAKE_TREE(TYPE_LIST)); } 
 | 
#line 727 "apyc.hn"
 type_var { YYCTLPA($$,0,1,&$1);  yyv_type_var = $1; }
 | 
#line 728 "apyc.hn"
 "(" type_list ")" "->" type
                { YYCTLPA($$,0,5,&$1,&$2,&$3,&$4,&$5);  $1.ignore(); $3.ignore(); $4.ignore(); yyv_type_list = $2; yyv_type = $5;yylhs = YYMAKE_TREE(FUNCTION_TYPE, 
                          yyv_type.value (), yyv_type_list.value ()); } 
;



type_var : 
#line 733 "apyc.hn"

      TYPE_VAR  { YYCTLPA($$,0,1,&$1);  yyv_TYPE_VAR = $1;yylhs = YYMAKE_TREE(TYPE_VAR, yylhs.all_values ()); } 
;



parameterized_type : 
#line 737 "apyc.hn"

      identifier type_params { YYCTLPA($$,0,2,&$1,&$2);  yyv_identifier = $1; yyv_type_params = $2;yylhs = YYMAKE_TREE(TYPE, yylhs.all_values ()); } 
;



type_params : 
#line 742 "apyc.hn"
 __6
                { YYCTLA($$,0,1,&$1); yylhs = YYMAKE_TREE(TYPE_LIST, yylhs.all_values ()); } 
;

 

type_list : 
#line 746 "apyc.hn"
 __17    { YYCTLA($$,0,1,&$1); yylhs = YYMAKE_TREE(TYPE_LIST, yylhs.all_values ()); } 
;



types : 
#line 750 "apyc.hn"
 
      type { YYCTLPA($$,0,1,&$1);  yyv_type = $1; }
 | 
#line 752 "apyc.hn"
 types ',' type { YYCTLPA($$,0,3,&$1,&$2,&$3);  $2.ignore(); yyv_types = $1; yyv_type = $3; }
;



empty : 
#line 755 "apyc.hn"
/* empty */ 
      /* empty */
                { YYCTLPA($$,0,0); yylhs = YYMAKE_TREE(EMPTY); yylhs.set_loc (yysource_location ()); } 
;

 __0 : 
#line 489 "apyc.hn"
 "<" { YYCTLPC($$,0,1,&$1);  }
 | 
#line 489 "apyc.hn"
 ">" { YYCTLPC($$,0,1,&$1);  }
 | 
#line 489 "apyc.hn"
 "==" { YYCTLPC($$,0,1,&$1);  }
 | 
#line 489 "apyc.hn"
 "<=" { YYCTLPC($$,0,1,&$1);  }
 | 
#line 489 "apyc.hn"
 ">=" { YYCTLPC($$,0,1,&$1);  }
 | 
#line 489 "apyc.hn"
 "!=" { YYCTLPC($$,0,1,&$1);  }
 | 
#line 489 "apyc.hn"
 "is" { YYCTLPC($$,0,1,&$1);  }
 | 
#line 489 "apyc.hn"
 "in" { YYCTLPC($$,0,1,&$1);  }
;

 __1 : 
#line 479 "apyc.hn"
 expression "," { YYCTLPC($$,0,2,&$1,&$2);  $2.ignore(); yyv_expression = $1; }
 | 
#line 479 "apyc.hn"
 __1 expression "," { YYCTLC($$,0,3,&$1,&$2,&$3);  $3.ignore(); yyv_expression = $2; }
;

 __2 : 
#line 607 "apyc.hn"
 statement { YYCTLPC($$,2,3,&$-1,&$0,&$1);  yyv_NEWLINE = $-1; yyv_INDENT = $0; yyv_statement = $1; }
 | 
#line 607 "apyc.hn"
 __2 statement { YYCTLC($$,2,4,&$-1,&$0,&$1,&$2);  yyv_statement = $2; }
;

 __3 : 
#line 388 "apyc.hn"
 "," expression { YYCTLPC($$,2,4,&$-1,&$0,&$1,&$2);  $1.ignore(); yyv_expression = $0; yyv_expression = $2; }
 | 
#line 388 "apyc.hn"
 __3 "," expression { YYCTLC($$,2,5,&$-1,&$0,&$1,&$2,&$3);  $2.ignore(); yyv_expression = $3; }
;

 __4 : 
#line 555 "apyc.hn"
 "," target { YYCTLPC($$,1,3,&$0,&$1,&$2);  $1.ignore(); yyv_target = $0; yyv_target = $2; }
 | 
#line 555 "apyc.hn"
 __4 "," target { YYCTLC($$,1,4,&$0,&$1,&$2,&$3);  $2.ignore(); yyv_target = $3; }
;

 __5 : 
#line 388 "apyc.hn"
 "," { YYCTLPC($$,2,3,&$-1,&$0,&$1);  $1.ignore(); yyv_expression = $0; }
 | 
#line 388 "apyc.hn"
 __3 __12 { YYCTLC($$,2,4,&$-1,&$0,&$1,&$2);  }
;

 __6 : 
#line 742 "apyc.hn"
 "of" "[" types "]" { YYCTLPC($$,0,4,&$1,&$2,&$3,&$4);  $1.ignore(); $2.ignore(); $4.ignore(); yyv_types = $3; }
 | 
#line 742 "apyc.hn"
 "of" type { YYCTLPC($$,0,2,&$1,&$2);  $1.ignore(); yyv_type = $2; }
;

 __7 : 
#line 349 "apyc.hn"
 NEWLINE { YYCTLC($$,1,2,&$0,&$1);  $1.ignore(); yyv_NEWLINE = $1; }
 | 
#line 349 "apyc.hn"
 statement { YYCTLC($$,1,2,&$0,&$1);  yyv_statement = $1; }
;

 __8 : /* empty */  { YYCTLC($$,1,1,&$0);  }
 | 
#line 479 "apyc.hn"
 expression { YYCTLC($$,1,2,&$0,&$1);  yyv_expression = $1; }
;

 __9 : /* empty */  { YYCTLC($$,2,2,&$-1,&$0);  }
 | 
#line 400 "apyc.hn"
 "," { YYCTLC($$,2,3,&$-1,&$0,&$1);  $1.ignore(); }
;

 __10 : /* empty */  { YYCTLC($$,2,2,&$-1,&$0);  }
 | 
#line 620 "apyc.hn"
 ";" { YYCTLC($$,2,3,&$-1,&$0,&$1);  $1.ignore(); }
;

 __11 : /* empty */  { YYCTLC($$,2,2,&$-1,&$0);  yyv_parameter = $0; }
 | 
#line 689 "apyc.hn"
 "," { YYCTLC($$,2,3,&$-1,&$0,&$1);  $1.ignore(); yyv_parameter = $0; }
;

 __12 : /* empty */  { YYCTLC($$,3,3,&$-2,&$-1,&$0);  }
 | 
#line 388 "apyc.hn"
 "," { YYCTLC($$,3,4,&$-2,&$-1,&$0,&$1);  $1.ignore(); }
;

 __13 : /* empty */  { YYCTLPC($$,0,0);  }
 | 
#line 689 "apyc.hn"
 __13 parameter "," { YYCTLC($$,0,3,&$1,&$2,&$3);  $3.ignore(); yyv_parameter = $2; }
;

 __14 : /* empty */  { YYCTLPC($$,0,0);  }
 | 
#line 349 "apyc.hn"
 __14 __7 { YYCTLC($$,0,2,&$1,&$2);  }
;

 __15 : /* empty */  { YYCTLPC($$,0,0);  }
 | 
#line 442 "apyc.hn"
 expression __22 __9 { YYCTLC($$,0,3,&$1,&$2,&$3);  }
;

 __16 : /* empty */  { YYCTLPC($$,0,0);  }
 | 
#line 473 "apyc.hn"
 expression __22 { YYCTLC($$,0,2,&$1,&$2);  }
;

 __17 : /* empty */  { YYCTLPC($$,0,0);  }
 | 
#line 746 "apyc.hn"

      types { YYCTLPC($$,0,1,&$1);  yyv_types = $1; }
;

 __18 : /* empty */  { YYCTLPC($$,0,0);  }
 | 
#line 707 "apyc.hn"
 "of" "[" type_var __26 "]" { YYCTLC($$,0,5,&$1,&$2,&$3,&$4,&$5);  $1.ignore(); $2.ignore(); $5.ignore(); }
;

 __19 : /* empty */  { YYCTLPC($$,1,1,&$0);  }
 | 
#line 388 "apyc.hn"
 expression __5 { YYCTLC($$,1,3,&$0,&$1,&$2);  }
;

 __20 : /* empty */  { YYCTLPC($$,1,1,&$0);  }
 | 
#line 392 "apyc.hn"
 expression __25 __12 { YYCTLC($$,1,4,&$0,&$1,&$2,&$3);  }
;

 __21 : /* empty */  { YYCTLPC($$,1,1,&$0);  }
 | 
#line 396 "apyc.hn"
 key_datum_list { YYCTLPC($$,1,2,&$0,&$1);  yyv_key_datum_list = $1; }
;

 __22 : /* empty */  { YYCTLPC($$,1,1,&$0);  yyv_expression = $0; }
 | 
#line 442 "apyc.hn"
 __22 "," expression { YYCTLC($$,1,4,&$0,&$1,&$2,&$3);  $2.ignore(); yyv_expression = $3; }
;

 __23 : /* empty */  { YYCTLPC($$,1,1,&$0);  yyv_key_datum = $0; }
 | 
#line 400 "apyc.hn"
 __23 "," key_datum { YYCTLC($$,1,4,&$0,&$1,&$2,&$3);  $2.ignore(); yyv_key_datum = $3; }
;

 __24 : /* empty */  { YYCTLPC($$,1,1,&$0);  yyv_simple_stmt = $0; }
 | 
#line 620 "apyc.hn"
 __24 ";" simple_stmt { YYCTLC($$,1,4,&$0,&$1,&$2,&$3);  $2.ignore(); yyv_simple_stmt = $3; }
;

 __25 : /* empty */  { YYCTLPC($$,2,2,&$-1,&$0);  yyv_expression = $0; }
 | 
#line 392 "apyc.hn"
 __25 "," expression { YYCTLC($$,2,5,&$-1,&$0,&$1,&$2,&$3);  $2.ignore(); yyv_expression = $3; }
;

 __26 : /* empty */  { YYCTLPC($$,3,3,&$-2,&$-1,&$0);  yyv_type_var = $0; }
 | 
#line 707 "apyc.hn"
 __26 "," type_var { YYCTLC($$,3,6,&$-2,&$-1,&$0,&$1,&$2,&$3);  $2.ignore(); yyv_type_var = $3; }
;



__error__ : error   { $$._clear (); } ;
#line 1406 "apyc-parser.y"

%%


#line 760 "apyc.hn"


#include <stack>

static stack<int> indentation_stack;
bool debugParser;
static vector<FILE*> files;

/** A mapping from binary operators to corresponding method
 *  names (as tokens).  Initialized from BINOP_MAP_INIT. */
static map<string, const char*> binop_method_map;
/** A mapping from unary operators to corresponding method
 *  names (as tokens).  Initialized from UNOP_MAP_INIT. */
static map<string, const char*> unop_method_map;

static const char* BINOP_MAP_INIT[] = {
    "+", "__add__",  "-", "__sub__",  "*", "__mul__",  "//", "__floordiv__",
    "/", "__floordiv__",  "%", "__mod__",  "**", "__pow__", 
    "in", "__contains__", "notin", "__notcontains__", 
    "is", "__is__", "isnot", "__isnot__",
    "<", "__lt__", ">", "__gt__", "<=", "__le__", ">=", "__ge__",
    "==", "__eq__", "!=", "__ne__",
    0,  0
};

static const char* UNOP_MAP_INIT[] = {
    "-",  "__neg__", "+", "__pos__", "not", "__not__",
    0, 0
};

static const char*
get_unop_method (const string& op)
{
    const char* result = unop_method_map[op];
    assert (result != NULL);
    return result;
}

static const char*
get_binop_method (const string& op)
{
    const char* result = binop_method_map[op];
    assert (result != NULL);
    return result;
}

static void
check_def_placement ()
{
    if (control_depth > 0)
        error (yysource_location (), "illegally nested def statement");
}

static void
check_class_placement ()
{
    if (control_depth > 0 || defn_depth > 0)
        error (yysource_location (), "illegally nested class definition");
}

static void
check_in_loop ()
{
    if (loop_depth == 0)
        error (yysource_location (), "statement must be in a loop");
}

static void
check_in_func ()
{
    if (func_depth == 0)
        error (yysource_location (), "statement must be in a function body");
}

static void
check_numeral (const char* text)
{
    if (text[0] == '0' && (text[1] == 'x' || text[1] == 'X')) {
        text += 2;
        while (*text == '0')
            text += 1;
        if (strlen (text) > 8 || 
            (strlen (text) == 8 && strcmp (text, "80000000") > 0))
            error (yysource_location (), "hex numeral too large");
    } else if (text[0] == '0') {
        while (*text == '0')
            text += 1;
        if (strlen (text) > 11 || 
            (strlen (text) == 11 && strcmp (text, "20000000000") > 0))
            error (yysource_location (), "octal numeral too large");
    } else if (strlen (text) > 10 || 
            (strlen (text) == 10 && strcmp (text, "2147483648") > 0))
            error (yysource_location (), "decimal numeral too large");
}

/** The equivalent number of spaces to TEXT, a sequence of whitespace 
 *  characters. */
static int
indent_length (const char* text)
{
    int n;
    n = 0;
    for (const char* p = text; *p != '\0'; p += 1) {
        if (*p == '\t')
            n = (n + 8) & ~7;
        else
            n += 1;
    }
    return n;
}

static int
do_indent (const char* text)
{
    int amount = indent_length (text);

    if (indentation_stack.empty())
        indentation_stack.push (0);
    
    if (amount > indentation_stack.top ()) {
        indentation_stack.push (amount);
        return INDENT;
    }

    if (amount < indentation_stack.top ()) {
        indentation_stack.pop ();
        while (amount < indentation_stack.top ()) {
            yyqueue_token (DEDENT, 0, 0, "", 8);
            indentation_stack.pop ();
        }
        if (amount != indentation_stack.top ()) {
            error (text, "improper indentation");
        }
        return DEDENT;
    }

    return -1;
}

static AST_Ptr
make_unop (const List_Ptr& operands)
{
    AST_Ptr op = operands->at (0);

    return YYMAKE_TREE (UNOP, make_id (op), operands->at (1),
                        make_id (get_unop_method(op->as_string ()),
                                 op->loc ()));
}

static AST_Ptr
make_binop (const List_Ptr& operands)
{
    AST_Ptr op = operands->at (1);

    return YYMAKE_TREE (BINOP, operands->at (0), make_id (op), operands->at (2), 
                        make_id (get_binop_method(op->as_string ()),
                                 op->loc ()));
}

static AST_Ptr
make_id (AST_Ptr& token)
{
    AST_Ptr result = AST::make_token (ID, token->text_size (), 
                                      token->as_chars (), false);
    result->set_loc (token->loc ());
    return result;
}

static AST_Ptr
make_id (const List_Ptr& operands)
{
    return make_id (operands->at (0));
}

int
AST::lineNumber ()
{
    return yylocation_line (loc ());
}

static
bool pop_source_file ()
{
    last_source_loc = yysource_location ();
    fclose (files.back ());
    files.pop_back ();
    yypop_lexer ();
    return !files.empty ();
}

void
add_source_file (const string& name)
{
    FILE* f = fopen (name.c_str (), "r");

    if (f == NULL)
        error_no_file ("Could not open %s", name.c_str ());
    files.push_back(f);
    yypush_lexer (f, name);
}

void
parse_error (const char* loc, const char* message, ...)
{
    if (loc == NULL)
        error (last_source_loc, message);
    else
        error (loc, message);
}

void
parse_init ()
{
    yypush_lexer ("", "<beginning of source>");
    for (size_t i = 0; BINOP_MAP_INIT[i] != NULL; i += 2)
	binop_method_map[BINOP_MAP_INIT[i]] =
	    BINOP_MAP_INIT[i+1];
    for (size_t i = 0; UNOP_MAP_INIT[i] != NULL; i += 2)
	unop_method_map[UNOP_MAP_INIT[i]] =
	    UNOP_MAP_INIT[i+1];
}        

AST_Ptr
parse ()
{
    if (debugParser)
	yydebug = 1;
    last_source_loc = NULL;

    theTree = NULL;
    yyparse ();
            
    return theTree;
}


#line 1648 "apyc-parser.y"

const char* 
yyexternal_token_name (int syntax)
{
    int internal_num = YYTRANSLATE (syntax);
    return yytname[internal_num];
}

#include "apyc-lexer.cc"

YYNAMESPACE_CLOSE
