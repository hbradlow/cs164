/* Generated from apyc.hn at Wed Oct 31 02:02:15 2012 GMT. */

%option 8bit nodefault noinput nounput noyywrap

%{ 
#define YY_LEXER_1
#include "horn-parse-lex.cc"
%}

%option outfile="apyc-lexer.cc"

%x YYPREFERRED

_EOF  "\377"


                    /* Lexical Rules */

_LETTER	[A-Za-z]


_DIGIT	[0-9]
 

_OCTAL	[0-7]


_OTHERCHAR	[\001-\011\013-!#-&(-[\]-\376]


_ESCAPE	([\\][\001-\376])


_NOT_NL_APOSTR	({_OTHERCHAR}|["]|{_ESCAPE})


_NOT_NL_QUOTE	({_OTHERCHAR}|[']|{_ESCAPE})


_SHORTSTRING	('{_NOT_NL_APOSTR}*'|["]{_NOT_NL_QUOTE}*["])


_NOT_APOSTR	({_OTHERCHAR}|{_ESCAPE}|["]|\n)

_NOT_QUOTE	({_OTHERCHAR}|{_ESCAPE}|[']|\n)


_LONGSTRING	('''({_NOT_APOSTR}*(('|''){_NOT_APOSTR})?)*'''|\"\"\"({_NOT_QUOTE}*((\"|\"\"){_NOT_QUOTE})?)*\"\"\")


_POSDIGIT	[1-9]

  
_DECIMALINTEGER	({_POSDIGIT}{_DIGIT}*|0)

  
_OCTINTEGER	(0{_OCTAL}+)

  
_HEXDIGIT	({_DIGIT}|[a-f]|[A-F])

_HEXINTEGER	(0(x|X){_HEXDIGIT}+)

  
_INTEGER	({_DECIMALINTEGER}|{_OCTINTEGER}|{_HEXINTEGER})


_WS	[\011 ]


_NL	(\r?\n)


_COMMENT	(#[\001-\011\013-\376]*)


%%

!=	{ { YY_LEXLHS(_TOK_4); YYLEXRET; } } 
\*\*	{ { YY_LEXLHS(POW); YYLEXRET; } } 
-\>	{ { YY_LEXLHS(_TOK_15); YYLEXRET; } } 
\/\/	{ { YY_LEXLHS(DIVDIV); YYLEXRET; } } 
::	{ { YY_LEXLHS(_TOK_14); YYLEXRET; } } 
\<=	{ { YY_LEXLHS(_TOK_2); YYLEXRET; } } 
==	{ { YY_LEXLHS(_TOK_1); YYLEXRET; } } 
\>=	{ { YY_LEXLHS(_TOK_3); YYLEXRET; } } 
\>\>	{ { YY_LEXLHS(_TOK_9); YYLEXRET; } } 
@@block	{ { YY_LEXLHS(CLASS_BLOCK); YYLEXRET; } } 
@@slicing	{ { YY_LEXLHS(SLICING_TARGET); YYLEXRET; } } 
@@subscription	{ { YY_LEXLHS(SUBSCRIPTION_TARGET); YYLEXRET; } } 
@assign	{ { YY_LEXLHS(ASSIGN); YYLEXRET; } } 
@attributeref	{ { YY_LEXLHS(ATTRIBUTEREF); YYLEXRET; } } 
@binop	{ { YY_LEXLHS(BINOP); YYLEXRET; } } 
@block	{ { YY_LEXLHS(BLOCK); YYLEXRET; } } 
@call	{ { YY_LEXLHS(CALL); YYLEXRET; } } 
@class	{ { YY_LEXLHS(CLASS); YYLEXRET; } } 
@compare	{ { YY_LEXLHS(COMPARE); YYLEXRET; } } 
@def	{ { YY_LEXLHS(METHOD); YYLEXRET; } } 
@dict_display	{ { YY_LEXLHS(DICT_DISPLAY); YYLEXRET; } } 
@expr_list	{ { YY_LEXLHS(EXPR_LIST); YYLEXRET; } } 
@formals_list	{ { YY_LEXLHS(FORMALS_LIST); YYLEXRET; } } 
@function_type	{ { YY_LEXLHS(FUNCTION_TYPE); YYLEXRET; } } 
@if_expr	{ { YY_LEXLHS(IF_EXPR); YYLEXRET; } } 
@int_literal	{ { YY_LEXLHS(INT_LITERAL); YYLEXRET; } } 
@left_compare	{ { YY_LEXLHS(LEFT_COMPARE); YYLEXRET; } } 
@list_display	{ { YY_LEXLHS(LIST_DISPLAY); YYLEXRET; } } 
@module	{ { YY_LEXLHS(MODULE); YYLEXRET; } } 
@pair	{ { YY_LEXLHS(PAIR); YYLEXRET; } } 
@print	{ { YY_LEXLHS(PRINT); YYLEXRET; } } 
@println	{ { YY_LEXLHS(PRINTLN); YYLEXRET; } } 
@slicing	{ { YY_LEXLHS(SLICING); YYLEXRET; } } 
@stmt_list	{ { YY_LEXLHS(STMT_LIST); YYLEXRET; } } 
@subscription	{ { YY_LEXLHS(SUBSCRIPTION); YYLEXRET; } } 
@target_list	{ { YY_LEXLHS(TARGET_LIST); YYLEXRET; } } 
@tuple	{ { YY_LEXLHS(TUPLE); YYLEXRET; } } 
@type	{ { YY_LEXLHS(TYPE); YYLEXRET; } } 
@type_formals_list	{ { YY_LEXLHS(TYPE_FORMALS_LIST); YYLEXRET; } } 
@type_list	{ { YY_LEXLHS(TYPE_LIST); YYLEXRET; } } 
@type_var	{ { YY_LEXLHS(TYPE_VAR); YYLEXRET; } } 
@typed_id	{ { YY_LEXLHS(TYPED_ID); YYLEXRET; } } 
@unop	{ { YY_LEXLHS(UNOP); YYLEXRET; } } 
and	{ { YY_LEXLHS(AND); YYLEXRET; } } 
break	{ { YY_LEXLHS(BREAK); YYLEXRET; } } 
class	{ { YY_LEXLHS(_TOK_12); YYLEXRET; } } 
continue	{ { YY_LEXLHS(CONTINUE); YYLEXRET; } } 
def	{ { YY_LEXLHS(DEF); YYLEXRET; } } 
elif	{ { YY_LEXLHS(_TOK_11); YYLEXRET; } } 
else	{ { YY_LEXLHS(_TOK_0); YYLEXRET; } } 
for	{ { YY_LEXLHS(FOR); YYLEXRET; } } 
if	{ { YY_LEXLHS(IF); YYLEXRET; } } 
in	{ { YY_LEXLHS(_TOK_6); YYLEXRET; } } 
is	{ { YY_LEXLHS(_TOK_5); YYLEXRET; } } 
native	{ { YY_LEXLHS(NATIVE); YYLEXRET; } } 
not	{ { YY_LEXLHS(NOT); YYLEXRET; } } 
of	{ { YY_LEXLHS(_TOK_13); YYLEXRET; } } 
or	{ { YY_LEXLHS(OR); YYLEXRET; } } 
pass	{ { YY_LEXLHS(_TOK_7); YYLEXRET; } } 
print	{ { YY_LEXLHS(_TOK_8); YYLEXRET; } } 
return	{ { YY_LEXLHS(_TOK_10); YYLEXRET; } } 
while	{ { YY_LEXLHS(WHILE); YYLEXRET; } } 
\(	{ { YY_LEXLHS('(');incr (bracket_depth); YYLEXRET; } } 
\)	{ { YY_LEXLHS(')');decr (bracket_depth); YYLEXRET; } } 
\[	{ { YY_LEXLHS('[');incr (bracket_depth); YYLEXRET; } } 
\]	{ { YY_LEXLHS(']');decr (bracket_depth); YYLEXRET; } } 
\{	{ { YY_LEXLHS('{');incr (bracket_depth); YYLEXRET; } } 
\}	{ { YY_LEXLHS('}');decr (bracket_depth); YYLEXRET; } } 
[%*-/:->]	{ { YYSIMPLELEXRET; } } 
(as|try|yield|exec|del|future|with|assert|except|finally|global|raise|import|from|lambda)	{ { YY_LEXLHS; error (yysource_location (), 
                         "The '%s' symbol is not part of our subset",
                         yylhs.text ()); YYLEXRET; } } 
({_LETTER}|_)({_LETTER}|{_DIGIT}|_)*	{ { YY_LEXLHS(ID); YYLEXRET; } } 
[$]({_LETTER}|{_DIGIT}|_)*	{ { YY_LEXLHS(TYPE_VAR); YYLEXRET; } } 
('{_NOT_NL_APOSTR}*|["]{_NOT_NL_QUOTE}*)	{ { YY_LEXLHS; error (yysource_location (), "unterminated string"); YYLEXRET; } } 
('''({_NOT_APOSTR}*(('|''){_NOT_APOSTR})?)*|\"\"\"({_NOT_QUOTE}*((\"|\"\"){_NOT_QUOTE})?)*)	{ { YY_LEXLHS; error (yysource_location (), "unterminated long string"); YYLEXRET; } } 
{_SHORTSTRING}	{ { YY_LEXLHS(STRING);yylhs = AST::make_token (STRING, yylhs.text_size ()-2, yylhs.text ()+1, false); YYLEXRET; } } 
{_LONGSTRING}	{ { YY_LEXLHS(STRING);yylhs = AST::make_token (STRING, yylhs.text_size ()-6, yylhs.text ()+3, false); YYLEXRET; } } 
(r|R){_SHORTSTRING}	{ { YY_LEXLHS(RAWSTRING);yylhs = AST::make_token (RAWSTRING, yylhs.text_size ()-3, yylhs.text ()+2, false); YYLEXRET; } } 
(r|R){_LONGSTRING}	{ { YY_LEXLHS(RAWSTRING);yylhs = AST::make_token (RAWSTRING, yylhs.text_size ()-7, yylhs.text ()+4, false); YYLEXRET; } } 
{_INTEGER}	{ { YY_LEXLHS(INT_LITERAL);check_numeral (yylhs.text ()); YYLEXRET; } } 
(0x|0X)	{ { YY_LEXLHS;  YYLEXRET; } } 
0{_DIGIT}+	{ { YY_LEXLHS; error (yysource_location (), "invalid numeral"); YYLEXRET; } } 
<YYPREFERRED>^{_WS}*{_COMMENT}?{_NL}/[\000-\377]	{ { YY_LEXLHS;  YYLEXRET; } } 
<YYPREFERRED>^{_WS}*/[\000-\377]	{ { YY_LEXLHS; YYSET_TOKEN (do_indent(yylhs.text ())); YYLEXRET; } } 
{_EOF}	{ { YY_LEXLHS; int tok = do_indent (""); 
                  if (pop_source_file () || tok > 0) 
                      YYSET_TOKEN (tok);
                  else
                      YYSET_TOKEN (0); YYLEXRET; } } 
{_WS}*{_COMMENT}?	{ { YY_LEXLHS;  YYLEXRET; } } 
{_NL}	{ { YY_LEXLHS(NEWLINE);if (bracket_depth > 0) {
                      yy_set_bol (0);
                      YYIGNORE;
                  } YYLEXRET; } } 
\\{_NL}{_WS}*	{ { YY_LEXLHS; yy_set_bol (0); YYLEXRET; } } 
[\001-~]	{ { YY_LEXLHS; error (yysource_location (), "invalid character"); YYLEXRET; } } 


<YYPREFERRED>.|\n  { yyless(0); return -1; }
.|\n               { if (yytext[0] == YYEOF_CHAR) {
                         yyless (0);     
                         return YYEOF;
                     }
                     return yytext[0]; }

%%

#define YY_LEXER_2
#include "horn-parse-lex.cc"
