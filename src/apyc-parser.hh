/* A Bison parser, made by GNU Bison 2.6.  */

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
     COMPARE = 272,
     LEFT_COMPARE = 273,
     CONTINUE = 274,
     DEDENT = 275,
     DEF = 276,
     DICT_DISPLAY = 277,
     EMPTY = 278,
     EXPR_LIST = 279,
     FOR = 280,
     FORMALS_LIST = 281,
     FUNCTION_TYPE = 282,
     IF = 283,
     IF_EXPR = 284,
     INDENT = 285,
     INT_LITERAL = 286,
     LIST_DISPLAY = 287,
     METHOD = 288,
     MODULE = 289,
     NATIVE = 290,
     NOT = 291,
     OR = 292,
     PAIR = 293,
     PRINT = 294,
     PRINTLN = 295,
     SLICING = 296,
     SLICING_TARGET = 297,
     STMT_LIST = 298,
     STRING_LITERAL = 299,
     SUBSCRIPTION = 300,
     SUBSCRIPTION_TARGET = 301,
     TARGET_LIST = 302,
     TYPE_FORMALS_LIST = 303,
     TUPLE = 304,
     TYPE = 305,
     TYPE_LIST = 306,
     TYPE_VAR = 307,
     TYPED_ID = 308,
     WHILE = 309,
     _TOK_4 = 310,
     _TOK_15 = 311,
     _TOK_14 = 312,
     _TOK_2 = 313,
     _TOK_1 = 314,
     _TOK_3 = 315,
     _TOK_9 = 316,
     _TOK_12 = 317,
     _TOK_11 = 318,
     _TOK_0 = 319,
     _TOK_6 = 320,
     _TOK_5 = 321,
     _TOK_13 = 322,
     _TOK_7 = 323,
     _TOK_8 = 324,
     _TOK_10 = 325,
     NEWLINE = 326,
     RAWSTRING = 327
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

