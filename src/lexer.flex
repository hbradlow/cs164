/* Lexer for Python Dialect */

DIGIT [0-9]
ID [a-zA-z][a-zA-Z0-9_]*
char* originalIndent;
%%
 /* Multiline comments */ 
"/*"(("*"[^/])|(\"[^"]*\")|[^*"])*"*/" {printf( "COMMENT: %s", yytext);}
 /* One line comments */
"//".*\n    {printf( "COMMENT: %s", yytext);} 

 /* KEYWORDS */
and|as|assert|break|class|continue|def|del|elif|else|except|exec|finally|for|from|global|if|import|in|is|lambda|not|or|pass|print|raise|return|try|while|with|yield  {printf( "KEYWORD: %s\n", yytext);}

{DIGIT}+    {printf( "INTEGER: %i\n", atoi(yytext));}

{DIGIT}+"."+{DIGIT}*    {printf( "FLOAT: %f\n", atof(yytext));}

{ID}    {printf( "ID: %s\n", yytext);}

"+"|"-"|"*"|"/" {printf ( "OPERATOR: %s", yytext);}

"."     {printf ("DOT: %s", yytext);}


%%
