/* Generated from apyc.hn at Mon Sep 24 03:37:36 2012 GMT. */

%option 8bit nodefault noinput nounput noyywrap

%{ 
#define YY_LEXER_1
#include "horn-parse-lex.cc"
%}

%option outfile="apyc-lexer.cc"

%x YYPREFERRED

_EOF  "\377"


%%

@boolean_stmt	{ { YY_LEXLHS(BOOLEAN_STMT); YYLEXRET; } } 
@expr_list	{ { YY_LEXLHS(EXPR_LIST); YYLEXRET; } } 
@if_stmt	{ { YY_LEXLHS(IF_STMT); YYLEXRET; } } 
@iterable	{ { YY_LEXLHS(ITERABLE); YYLEXRET; } } 
@literal	{ { YY_LEXLHS(LITERAL); YYLEXRET; } } 
@module	{ { YY_LEXLHS(MODULE); YYLEXRET; } } 
@println	{ { YY_LEXLHS(PRINTLN); YYLEXRET; } } 
def	{ { YY_LEXLHS(_TOK_4); YYLEXRET; } } 
elif	{ { YY_LEXLHS(_TOK_1); YYLEXRET; } } 
else	{ { YY_LEXLHS(_TOK_2); YYLEXRET; } } 
for	{ { YY_LEXLHS(_TOK_5); YYLEXRET; } } 
if	{ { YY_LEXLHS(_TOK_0); YYLEXRET; } } 
in	{ { YY_LEXLHS(_TOK_6); YYLEXRET; } } 
print	{ { YY_LEXLHS(_TOK_7); YYLEXRET; } } 
while	{ { YY_LEXLHS(_TOK_3); YYLEXRET; } } 
[\012(-),:=]	{ { YYSIMPLELEXRET; } } 
(==|\<=|\>=|\<|\>)	{ { YY_LEXLHS(COMPARE); YYLEXRET; } } 
[\011\015 ]+	{ { YY_LEXLHS;  YYLEXRET; } } 
[1-9][0-9]*	{ { YY_LEXLHS(INT_LITERAL); YYLEXRET; } } 
\"\"	{ { YY_LEXLHS(STRING); YYLEXRET; } } 
r\"\"	{ { YY_LEXLHS(RAWSTRING); YYLEXRET; } } 


<YYPREFERRED>.|\n  { yyless(0); return -1; }
.|\n               { if (yytext[0] == YYEOF_CHAR) {
                         yyless (0);     
                         return YYEOF;
                     }
                     return yytext[0]; }

%%

#define YY_LEXER_2
#include "horn-parse-lex.cc"
