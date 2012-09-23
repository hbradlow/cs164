/* Generated from apyc.hn at Sun Sep 23 10:42:17 2012 GMT. */

%option 8bit nodefault noinput nounput noyywrap

%{ 
#define YY_LEXER_1
#include "horn-parse-lex.cc"
%}

%option outfile="apyc-lexer.cc"

%x YYPREFERRED

_EOF  "\377"


%%

@expr_list	{ { YY_LEXLHS(EXPR_LIST); YYLEXRET; } } 
@module	{ { YY_LEXLHS(MODULE); YYLEXRET; } } 
@println	{ { YY_LEXLHS(PRINTLN); YYLEXRET; } } 
print	{ { YY_LEXLHS(_TOK_0); YYLEXRET; } } 
[\012,]	{ { YYSIMPLELEXRET; } } 
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
