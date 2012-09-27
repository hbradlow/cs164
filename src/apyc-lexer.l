<<<<<<< HEAD
/* Generated from apyc.hn at Thu Sep 27 05:55:38 2012 GMT. */
=======
/* Generated from apyc.hn at Thu Sep 27 05:51:43 2012 GMT. */
>>>>>>> e42dd43ea0197ce3b5ac24edba37c739fd822d7e

%option 8bit nodefault noinput nounput noyywrap

%{ 
#define YY_LEXER_1
#include "horn-parse-lex.cc"
%}

%option outfile="apyc-lexer.cc"

%x YYPREFERRED

_EOF  "\377"


%%

@\(	{ { YY_LEXLHS(LPAREN); YYLEXRET; } } 
@\)	{ { YY_LEXLHS(RPAREN); YYLEXRET; } } 
@:	{ { YY_LEXLHS(COLON); YYLEXRET; } } 
@\<	{ { YY_LEXLHS(LT); YYLEXRET; } } 
@\<=	{ { YY_LEXLHS(LTE); YYLEXRET; } } 
@=	{ { YY_LEXLHS(ASSIGN); YYLEXRET; } } 
@==	{ { YY_LEXLHS(EQUALS); YYLEXRET; } } 
@\>	{ { YY_LEXLHS(GT); YYLEXRET; } } 
@\>=	{ { YY_LEXLHS(GTE); YYLEXRET; } } 
@boolean_stmt	{ { YY_LEXLHS(BOOLEAN_STMT); YYLEXRET; } } 
@compare	{ { YY_LEXLHS(COMPARE); YYLEXRET; } } 
@expr_list	{ { YY_LEXLHS(EXPR_LIST); YYLEXRET; } } 
@if_stmt	{ { YY_LEXLHS(IF_STMT); YYLEXRET; } } 
@iterable	{ { YY_LEXLHS(ITERABLE); YYLEXRET; } } 
@literal	{ { YY_LEXLHS(LITERAL); YYLEXRET; } } 
@module	{ { YY_LEXLHS(MODULE); YYLEXRET; } } 
@println	{ { YY_LEXLHS(PRINTLN); YYLEXRET; } } 
elif	{ { YY_LEXLHS(_TOK_1); YYLEXRET; } } 
else	{ { YY_LEXLHS(_TOK_2); YYLEXRET; } } 
if	{ { YY_LEXLHS(_TOK_0); YYLEXRET; } } 
print	{ { YY_LEXLHS(_TOK_3); YYLEXRET; } } 
,	{ { YY_LEXLHS(COMMA); YYLEXRET; } } 
[\012(-):]	{ { YYSIMPLELEXRET; } } 
[\011\015 ]+	{ { YY_LEXLHS;  YYLEXRET; } } 
[1-9][0-9]*	{ { YY_LEXLHS(INT_LITERAL); YYLEXRET; } } 
\"[1-9]*\"	{ { YY_LEXLHS(STRING_LITERAL); YYLEXRET; } } 
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
