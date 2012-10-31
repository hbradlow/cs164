/* A Bison parser, made by GNU Bison 2.6.2.  */

/* Skeleton interface for Bison GLR parsers in C
   
      Copyright (C) 2002-2012 Free Software Foundation, Inc.
   
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
     UNOP = 261,
     DIVDIV = 262,
     POW = 263,
     AND = 264,
     ASSIGN = 265,
     ATTRIBUTEREF = 266,
     BINOP = 267,
     BLOCK = 268,
     BREAK = 269,
     CALL = 270,
     CLASS_BLOCK = 271,
     CLASS = 272,
     COMPARE = 273,
     LEFT_COMPARE = 274,
     CONTINUE = 275,
     DEDENT = 276,
     DEF = 277,
     DICT_DISPLAY = 278,
     EMPTY = 279,
     EXPR_LIST = 280,
     FOR = 281,
     FORMALS_LIST = 282,
     FUNCTION_TYPE = 283,
     IF = 284,
     IF_EXPR = 285,
     INDENT = 286,
     INT_LITERAL = 287,
     LIST_DISPLAY = 288,
     METHOD = 289,
     MODULE = 290,
     NATIVE = 291,
     NOT = 292,
     OR = 293,
     PAIR = 294,
     PRINT = 295,
     PRINTLN = 296,
     SLICING = 297,
     SLICING_TARGET = 298,
     STMT_LIST = 299,
     STRING_LITERAL = 300,
     SUBSCRIPTION = 301,
     SUBSCRIPTION_TARGET = 302,
     TARGET_LIST = 303,
     TYPE_FORMALS_LIST = 304,
     TUPLE = 305,
     TYPE = 306,
     TYPE_LIST = 307,
     TYPE_VAR = 308,
     TYPED_ID = 309,
     WHILE = 310,
     _TOK_4 = 311,
     _TOK_15 = 312,
     _TOK_14 = 313,
     _TOK_2 = 314,
     _TOK_1 = 315,
     _TOK_3 = 316,
     _TOK_9 = 317,
     _TOK_12 = 318,
     _TOK_11 = 319,
     _TOK_0 = 320,
     _TOK_6 = 321,
     _TOK_5 = 322,
     _TOK_13 = 323,
     _TOK_7 = 324,
     _TOK_8 = 325,
     _TOK_10 = 326,
     NEWLINE = 327,
     RAWSTRING = 328
   };
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_APYC_PARSER_HH  */
