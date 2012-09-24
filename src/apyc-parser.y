/* -*-C++-*- */
/* Generated from apyc.hn at Mon Sep 24 03:46:51 2012 GMT. */

%code top {

#define YYPARAM Tree_Semantics< AST >
#define YYPRODUCING_TREES
#define YYERROR_FUNCTION_NAME error

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

%}

%debug
#line 25 "apyc.hn"


/* A token declaration such as
 *   %token INDENT
 * declares a new integer constant INDENT, which serves as a syntactic category
 * (suitable for output by the lexer) identifying a kind of token, which we
 * also often refer to as INDENT. A declaration such as
 *   %token IF "if"
 * defines a constant IF and makes it the syntactic category for the token
 * "if".  The built-in function yyexternal_token_name(...) maps between 
 * syntactic categories (like IF) and the token strings defined in these 
 * %token declarations (like "if").  
 *
 * The Horn system uses tokens as leaf nodes and as AST node operators.  A
 * rule such as
 *     if_stmt: "if"^ expression ":"! ...
 * with no action, by default creates an AST node whose operator is an "if"
 * token (with syntactic category IF, given the %token declaration above).
 * When the node type does not correspond to a token that appears in the 
 * program, we define a dummy token type that serves only as an AST
 * node type.  For example, we can define
 *     %token DICT_DISPLAY ...
 * and then use
 *     dict_display: "{"! key_datum_list? "}"! 
 *              { $$ = $^(DICT_DISPLAY, $*); }
 * in the grammar (using DICT_DISPLAY only in actions, not as a grammar
 * symbol).
 *
 * In this skeleton, we've used a simple kludge to extract the printed forms
 * of AST operators from the operators themselves.  When a token such as IF
 * is the operator, yyexternal_token_name returns the operator name directly.
 * When there is no such correspondence, as with DICT_DISPLAY, we'll define
 *     %token DICT_DISPLAY "@dict_display"
 * Since "@dict_display" is not a valid token (it would be an error for this
 * to appear in any Python program) and does not appear in the grammar, this
 * declaration has no effect on the language recognized.  However, it
 * still provides an easy way to find the external name of an operator (just
 * strip off the leading "@").  (We can't just use "dict_display", since that
 * would tell Horn to define 'dict_display' as a token, whereas it would be a
 * simple identifier if it actually appeared in a Python program.  This is
 * where the kludginess comes in.) The AST_Tree::external_name method does
 * this conversion, converting tokens that are supposed to represent
 * node operators to printable strings.
 */

%token PRINTLN "@println"
%token EMPTY 
%token EXPR_LIST "@expr_list"
%token MODULE "@module"

%token LITERAL "@literal"
%token IF_STMT "@if_stmt"
%token BOOLEAN_STMT "@boolean_stmt"
%token ITERABLE "@iterable"

%token LPAREN "@("
%token RPAREN "@)"
%token COLON "@:"
%token COMPARE "@compare"

%token ASSIGN "@="
%token ID "@id"

%token EQUALS "@=="
%token GT "@>"
%token LT "@<"
%token GTE "@>="
%token LTE "@<="

#line 113 "apyc-parser.y"

/* Horn prologue */

%defines
%token-table

%{

#define YY_PARSER_2
#include "horn-parse-lex.cc"

%}

/* Token definitions */

%token ',' ","
%token ':' ":"
%token '\n' "\n"
%token _TOK_0 "print"
%token  INT_LITERAL
%token  RAWSTRING


/* Destroying discarded semantic values. */
%destructor { $$._destructor (); } <>

%{
static yyvar yyv_ASSIGN;
static yyvar yyv_COLON;
static yyvar yyv_COMMA;
static yyvar yyv_COMPARE;
static yyvar yyv_DEDENT;
static yyvar yyv_DEF;
static yyvar yyv_ELIF;
static yyvar yyv_ELSE;
static yyvar yyv_EMPTY;
static yyvar yyv_EQUALS;
static yyvar yyv_FOR;
static yyvar yyv_FUNCTION;
static yyvar yyv_FUNCTION_NAME;
static yyvar yyv_GT;
static yyvar yyv_GTE;
static yyvar yyv_ID;
static yyvar yyv_IF;
static yyvar yyv_IN;
static yyvar yyv_INDENT;
static yyvar yyv_ITERABLE;
static yyvar yyv_LITERAL;
static yyvar yyv_LPAREN;
static yyvar yyv_LT;
static yyvar yyv_LTE;
static yyvar yyv_RPAREN;
static yyvar yyv_WHILE;
static yyvar yyv_bool_stmt;
static yyvar yyv_def_stmt;
static yyvar yyv_elif_stmt;
static yyvar yyv_expr_list;
static yyvar yyv_expression;
static yyvar yyv_expression_list;
static yyvar yyv_for_stmt;
static yyvar yyv_if_stmt;
static yyvar yyv_numeric_literal;
static yyvar yyv_parameter;
static yyvar yyv_parameter_list;
static yyvar yyv_print_stmt;
static yyvar yyv_stmt;
static yyvar yyv_stmt_list;
static yyvar yyv_string;
static yyvar yyv_string_literal;
static yyvar yyv_while_stmt;

%}

%%




program : 
#line 98 "apyc.hn"
 stmt_list   { YYCTLPA($$,0,1,&$1);  yyv_stmt_list = $1;theTree = YYMAKE_TREE(MODULE, yylhs.all_values ()); yylhs = NULL; } 
;



/* REPLACE THE FOLLOWING WITH SOMETHING REAL. */
stmt_list : 
#line 102 "apyc.hn"
 stmt stmt_list { YYCTLPA($$,0,2,&$1,&$2);  yyv_stmt = $1; yyv_stmt_list = $2; }
 | 
#line 102 "apyc.hn"
 EMPTY { YYCTLPA($$,0,1,&$1);  yyv_EMPTY = $1; }
;

 
stmt : 
#line 103 "apyc.hn"
 if_stmt { YYCTLPA($$,0,1,&$1);  yyv_if_stmt = $1; }
 | 
#line 103 "apyc.hn"
 while_stmt { YYCTLPA($$,0,1,&$1);  yyv_while_stmt = $1; }
 | 
#line 103 "apyc.hn"
 def_stmt { YYCTLPA($$,0,1,&$1);  yyv_def_stmt = $1; }
 | 
#line 103 "apyc.hn"
 for_stmt { YYCTLPA($$,0,1,&$1);  yyv_for_stmt = $1; }
 | 
#line 103 "apyc.hn"
 expression { YYCTLPA($$,0,1,&$1);  yyv_expression = $1; }
;



if_stmt : 
#line 105 "apyc.hn"
 IF bool_stmt COLON INDENT stmt_list DEDENT elif_stmt { YYCTLPA($$,0,7,&$1,&$2,&$3,&$4,&$5,&$6,&$7);  $3.ignore(); yyv_IF = $1; yyv_bool_stmt = $2; yyv_COLON = $3; yyv_INDENT = $4; yyv_stmt_list = $5; yyv_DEDENT = $6; yyv_elif_stmt = $7; }
;


elif_stmt : 
#line 106 "apyc.hn"
 ELIF bool_stmt COLON INDENT stmt_list DEDENT elif_stmt { YYCTLPA($$,0,7,&$1,&$2,&$3,&$4,&$5,&$6,&$7);  $3.ignore(); yyv_ELIF = $1; yyv_bool_stmt = $2; yyv_COLON = $3; yyv_INDENT = $4; yyv_stmt_list = $5; yyv_DEDENT = $6; yyv_elif_stmt = $7; }
 | 
#line 106 "apyc.hn"
 EMPTY { YYCTLPA($$,0,1,&$1);  yyv_EMPTY = $1; }
 | 
#line 106 "apyc.hn"
 ELSE bool_stmt ":" INDENT stmt_list DEDENT { YYCTLPA($$,0,6,&$1,&$2,&$3,&$4,&$5,&$6);  $3.ignore(); yyv_ELSE = $1; yyv_bool_stmt = $2; yyv_INDENT = $4; yyv_stmt_list = $5; yyv_DEDENT = $6; }
;


bool_stmt : 
#line 107 "apyc.hn"
 expression COMPARE bool_stmt { YYCTLPA($$,0,3,&$1,&$2,&$3);  yyv_expression = $1; yyv_COMPARE = $2; yyv_bool_stmt = $3; }
 | 
#line 107 "apyc.hn"
 LPAREN bool_stmt RPAREN { YYCTLPA($$,0,3,&$1,&$2,&$3);  $1.ignore(); $3.ignore(); yyv_LPAREN = $1; yyv_bool_stmt = $2; yyv_RPAREN = $3; }
 | 
#line 107 "apyc.hn"
 expression { YYCTLPA($$,0,1,&$1);  yyv_expression = $1; }
;



while_stmt : 
#line 109 "apyc.hn"
 WHILE bool_stmt COLON INDENT stmt_list DEDENT { YYCTLPA($$,0,6,&$1,&$2,&$3,&$4,&$5,&$6);  $3.ignore(); yyv_WHILE = $1; yyv_bool_stmt = $2; yyv_COLON = $3; yyv_INDENT = $4; yyv_stmt_list = $5; yyv_DEDENT = $6; }
;


for_stmt : 
#line 110 "apyc.hn"
 FOR ID IN ITERABLE COLON INDENT stmt_list DEDENT { YYCTLPA($$,0,8,&$1,&$2,&$3,&$4,&$5,&$6,&$7,&$8);  $5.ignore(); yyv_FOR = $1; yyv_ID = $2; yyv_IN = $3; yyv_ITERABLE = $4; yyv_COLON = $5; yyv_INDENT = $6; yyv_stmt_list = $7; yyv_DEDENT = $8; }
;



def_stmt : 
#line 112 "apyc.hn"
 DEF FUNCTION_NAME LPAREN parameter_list RPAREN COLON INDENT stmt_list DEDENT { YYCTLPA($$,0,9,&$1,&$2,&$3,&$4,&$5,&$6,&$7,&$8,&$9);  $3.ignore(); $5.ignore(); $6.ignore(); yyv_DEF = $1; yyv_FUNCTION_NAME = $2; yyv_LPAREN = $3; yyv_parameter_list = $4; yyv_RPAREN = $5; yyv_COLON = $6; yyv_INDENT = $7; yyv_stmt_list = $8; yyv_DEDENT = $9; }
;


parameter_list : 
#line 113 "apyc.hn"
 parameter COMMA parameter_list { YYCTLPA($$,0,3,&$1,&$2,&$3);  $2.ignore(); yyv_parameter = $1; yyv_COMMA = $2; yyv_parameter_list = $3; }
 | 
#line 113 "apyc.hn"
 parameter { YYCTLPA($$,0,1,&$1);  yyv_parameter = $1; }
;


parameter : 
#line 114 "apyc.hn"
 ID { YYCTLPA($$,0,1,&$1);  yyv_ID = $1; }
 | 
#line 114 "apyc.hn"
 ID ASSIGN expression { YYCTLPA($$,0,3,&$1,&$2,&$3);  yyv_ID = $1; yyv_ASSIGN = $2; yyv_expression = $3; }
;



compare : 
#line 116 "apyc.hn"
 EQUALS { YYCTLPA($$,0,1,&$1);  yyv_EQUALS = $1; }
 | 
#line 116 "apyc.hn"
 LTE { YYCTLPA($$,0,1,&$1);  yyv_LTE = $1; }
 | 
#line 116 "apyc.hn"
 GTE { YYCTLPA($$,0,1,&$1);  yyv_GTE = $1; }
 | 
#line 116 "apyc.hn"
 LT { YYCTLPA($$,0,1,&$1);  yyv_LT = $1; }
 | 
#line 116 "apyc.hn"
 GT { YYCTLPA($$,0,1,&$1);  yyv_GT = $1; }
;



literal : 
#line 118 "apyc.hn"
 string_literal { YYCTLPA($$,0,1,&$1);  yyv_string_literal = $1; }
 | 
#line 118 "apyc.hn"
 numeric_literal { YYCTLPA($$,0,1,&$1);  yyv_numeric_literal = $1; }
;


string_literal : 
#line 119 "apyc.hn"
 string { YYCTLPA($$,0,1,&$1);  yyv_string = $1; }
;




iterable : 
#line 122 "apyc.hn"
 expr_list { YYCTLPA($$,0,1,&$1);  yyv_expr_list = $1; }
;



expression : 
#line 125 "apyc.hn"

	LITERAL { YYCTLPA($$,0,1,&$1);  yyv_LITERAL = $1; }
 | 
#line 126 "apyc.hn"

	FUNCTION expression_list { YYCTLPA($$,0,2,&$1,&$2);  yyv_FUNCTION = $1; yyv_expression_list = $2; }
;



expression_list : 
#line 130 "apyc.hn"

      expression __0 { YYCTLA($$,0,2,&$1,&$2); yylhs = YYMAKE_TREE(EXPR_LIST, yylhs.all_values ()); } 
 | 
#line 131 "apyc.hn"
/* empty */ 
      /*empty*/       { YYCTLPA($$,0,0); yylhs = YYMAKE_TREE(EXPR_LIST); } 
;



	


/* REPLACE THE FOLLOWING WITH SOMETHING REAL. */
stmt_list : 
#line 139 "apyc.hn"
 print_stmt '\n' { YYCTLPA($$,0,2,&$1,&$2);  $2.ignore(); yyv_print_stmt = $1; }
;



print_stmt : 
#line 142 "apyc.hn"
 "print"  expression_list 
                      { YYCTLPA($$,0,2,&$1,&$2);  yyv_expression_list = $2;yylhs = YYMAKE_TREE(PRINTLN, YYMAKE_TREE(EMPTY), yyv_expression_list); } 
;

 __0 : /* empty */  { YYCTLPC($$,1,1,&$0);  yyv_expression = $0; }
 | 
#line 131 "apyc.hn"
 __0 "," expression { YYCTLC($$,1,4,&$0,&$1,&$2,&$3);  $2.ignore(); yyv_expression = $3; }
;




#line 390 "apyc-parser.y"

%%


#line 157 "apyc.hn"


bool debugParser;

int
AST::lineNumber ()
{
    return yylocation_line (loc ());
}

void
parse (FILE* f, const string& name)
{
    if (debugParser)
        yydebug = 1;
    yypush_lexer (f, name);
    theTree = NULL;
    yyparse ();
    if (theTree != NULL) {
        theTree->print (cout, 0);
    }
}


#line 420 "apyc-parser.y"

const char* 
yyexternal_token_name (int syntax)
{
    int internal_num = YYTRANSLATE (syntax);
    return yytname[internal_num];
}

#include "apyc-lexer.cc"

YYNAMESPACE_CLOSE
