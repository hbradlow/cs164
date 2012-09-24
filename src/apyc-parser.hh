/* A Bison parser, made by GNU Bison 2.6.  */

/* Bison interface for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2012 Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_APYC_PARSER_HH
# define YY_APYC_PARSER_HH
/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     INT = 258,
     STRING = 259,
     ID = 260,
     PRINTLN = 261,
     EMPTY = 262,
     EXPR_LIST = 263,
     MODULE = 264,
     LITERAL = 265,
     IF_STMT = 266,
     BOOLEAN_STMT = 267,
     ITERABLE = 268,
     LPAREN = 269,
     RPAREN = 270,
     COLON = 271,
     COMPARE = 272,
     ASSIGN = 273,
     EQUALS = 274,
     GT = 275,
     LT = 276,
     GTE = 277,
     LTE = 278,
     COMMA = 279,
     DEDENT = 280,
     DEF = 281,
     FOR = 282,
     IN = 283,
     INDENT = 284,
     WHILE = 285,
     DICT = 286,
     FUNCTION_NAME = 287,
     LIST = 288,
     NUM_LITERAL = 289,
     TUPLE = 290,
     _TOK_1 = 291,
     _TOK_2 = 292,
     _TOK_0 = 293,
     _TOK_3 = 294,
     INTS_LITERAL = 295,
     RAWSTRING = 296
   };
#endif


#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */

#endif /* !YY_APYC_PARSER_HH  */
