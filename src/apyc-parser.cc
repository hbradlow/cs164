/* A Bison parser, made by GNU Bison 2.6.  */

/* Skeleton implementation for Bison GLR parsers in C
   
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

/* C GLR parser skeleton written by Paul Hilfinger.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.6"

/* Skeleton name.  */
#define YYSKELETON_NAME "glr.c"

/* Pure parsers.  */
#define YYPURE 0


/* "%code top" blocks.  */

/* Line 193 of glr.c  */
#line 4 "apyc-parser.y"


#define YYPARAM Tree_Semantics< AST >
#define YYPRODUCING_TREES
#define YYERROR_FUNCTION_NAME parse_error

# define YY_PARSER_1
# include "horn-parse-lex.cc"



/* Line 193 of glr.c  */
#line 65 "apyc-parser.cc"




/* Copy the first part of user declarations.  */

/* Line 210 of glr.c  */
#line 14 "apyc-parser.y"


    YYNAMESPACE_OPEN


/* Line 210 of glr.c  */
#line 13 "apyc.hn"

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

/* Line 210 of glr.c  */
#line 214 "apyc-parser.y"


#define YY_PARSER_2
#include "horn-parse-lex.cc"


/* Line 210 of glr.c  */
#line 264 "apyc-parser.y"

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



/* Line 210 of glr.c  */
#line 262 "apyc-parser.cc"

# ifndef YY_NULL
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULL nullptr
#  else
#   define YY_NULL 0
#  endif
# endif

#include "apyc-parser.hh"

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Default (constant) value used for initialization for null
   right-hand sides.  Unlike the standard yacc.c template,
   here we set the default value of $$ to a zeroed-out value.
   Since the default value is undefined, this behavior is
   technically correct.  */
static YYSTYPE yyval_default;

/* Copy the second part of user declarations.  */


/* Line 233 of glr.c  */
#line 293 "apyc-parser.cc"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
#endif

#ifndef YYFREE
# define YYFREE free
#endif
#ifndef YYMALLOC
# define YYMALLOC malloc
#endif
#ifndef YYREALLOC
# define YYREALLOC realloc
#endif

#define YYSIZEMAX ((size_t) -1)

#ifdef __cplusplus
   typedef bool yybool;
#else
   typedef unsigned char yybool;
#endif
#define yytrue 1
#define yyfalse 0

#ifndef YYSETJMP
# include <setjmp.h>
# define YYJMP_BUF jmp_buf
# define YYSETJMP(env) setjmp (env)
# define YYLONGJMP(env, val) longjmp (env, val)
#endif

/*-----------------.
| GCC extensions.  |
`-----------------*/

#ifndef __attribute__
/* This feature is available in gcc versions 2.5 and later.  */
# if (! defined __GNUC__ || __GNUC__ < 2 \
      || (__GNUC__ == 2 && __GNUC_MINOR__ < 5))
#  define __attribute__(Spec) /* empty */
# endif
#endif


#ifdef __cplusplus
# define YYOPTIONAL_LOC(Name) /* empty */
#else
# define YYOPTIONAL_LOC(Name) Name __attribute__ ((__unused__))
#endif

#ifndef YYASSERT
# define YYASSERT(condition) ((void) ((condition) || (abort (), 0)))
#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   819

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  91
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  105
/* YYNRULES -- Number of rules.  */
#define YYNRULES  213
/* YYNRULES -- Number of states.  */
#define YYNSTATES  320
/* YYMAXRHS -- Maximum number of symbols on right-hand side of rule.  */
#define YYMAXRHS 9
/* YYMAXLEFT -- Maximum number of symbols to the left of a handle
   accessed by $0, $-1, etc., in any rule.  */
#define YYMAXLEFT 3

/* YYTRANSLATE(X) -- Bison symbol number corresponding to X.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   327

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const unsigned char yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    56,     2,     2,
      57,    58,    59,    60,    61,    62,    64,    65,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    66,    68,
      69,    71,    73,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    76,     2,    77,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    87,     2,    88,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    63,    67,    70,    72,    74,    75,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    89,    90
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const unsigned short int yyprhs[] =
{
       0,     0,     3,     5,     7,     9,    11,    13,    15,    17,
      19,    21,    23,    25,    27,    29,    32,    36,    40,    44,
      48,    52,    56,    58,    60,    62,    64,    66,    70,    75,
      82,    84,    86,    91,    96,    98,   100,   106,   108,   110,
     114,   118,   121,   124,   126,   128,   131,   133,   135,   137,
     140,   143,   147,   151,   153,   157,   161,   163,   166,   169,
     173,   177,   181,   185,   189,   193,   197,   199,   201,   203,
     205,   207,   209,   211,   213,   217,   221,   223,   227,   229,
     233,   237,   241,   242,   246,   249,   251,   254,   256,   258,
     260,   262,   266,   270,   276,   281,   288,   291,   293,   295,
     297,   299,   301,   303,   305,   308,   313,   316,   321,   323,
     326,   328,   332,   333,   340,   346,   348,   349,   353,   354,
     355,   363,   364,   365,   375,   376,   386,   388,   390,   395,
     399,   400,   404,   406,   409,   411,   412,   419,   421,   423,
     426,   428,   430,   432,   434,   436,   442,   444,   447,   449,
     451,   453,   457,   458,   460,   462,   464,   466,   468,   470,
     472,   474,   477,   481,   483,   486,   489,   493,   496,   500,
     502,   505,   510,   513,   515,   517,   518,   520,   521,   523,
     524,   526,   527,   529,   530,   532,   533,   537,   538,   541,
     542,   546,   547,   550,   551,   553,   554,   560,   561,   564,
     565,   569,   570,   572,   573,   577,   578,   582,   583,   587,
     588,   592,   593,   597
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const short int yyrhs[] =
{
      92,     0,    -1,   182,    -1,     5,    -1,    93,    -1,    96,
      -1,    95,    -1,    99,    -1,   100,    -1,   101,    -1,    98,
      -1,    31,    -1,     4,    -1,    90,    -1,    97,    -1,    98,
      97,    -1,    57,   111,    58,    -1,    57,   187,    58,    -1,
      76,   188,    77,    -1,    87,   189,    88,    -1,   103,   191,
     177,    -1,   111,    66,   111,    -1,    94,    -1,   105,    -1,
     106,    -1,   107,    -1,   109,    -1,   104,    64,    93,    -1,
     104,    76,   116,    77,    -1,   104,    76,   108,    66,   108,
      77,    -1,   111,    -1,   167,    -1,   104,    57,   110,    58,
      -1,   163,    57,   110,    58,    -1,   183,    -1,   112,    -1,
     113,    28,   113,    80,   111,    -1,   113,    -1,   119,    -1,
     113,    37,   113,    -1,   113,     9,   113,    -1,    36,   113,
      -1,   111,   190,    -1,   184,    -1,   111,    -1,   169,   176,
      -1,   116,    -1,   167,    -1,   168,    -1,    82,    36,    -1,
      36,    81,    -1,   120,   118,   121,    -1,   121,   118,   121,
      -1,   121,    -1,   121,   118,   121,    -1,   120,   118,   121,
      -1,   104,    -1,    62,   121,    -1,    60,   121,    -1,   121,
      60,   121,    -1,   121,    62,   121,    -1,   121,    59,   121,
      -1,   121,    65,   121,    -1,   121,     7,   121,    -1,   121,
      56,   121,    -1,   121,     8,   121,    -1,   123,    -1,   124,
      -1,   128,    -1,   129,    -1,   130,    -1,   131,    -1,   132,
      -1,   116,    -1,   125,    71,   116,    -1,   125,    71,   124,
      -1,   127,    -1,    57,   127,    58,    -1,   126,    -1,    57,
     126,    58,    -1,    76,   126,    77,    -1,    76,   127,    77,
      -1,    -1,   127,   172,   177,    -1,   127,    61,    -1,    93,
      -1,    93,   159,    -1,   105,    -1,   106,    -1,   107,    -1,
      84,    -1,    85,   167,   115,    -1,    85,    75,   111,    -1,
      85,    75,   111,    61,   114,    -1,    85,   167,   114,    61,
      -1,    85,    75,   111,    61,   114,    61,    -1,    86,   117,
      -1,    14,    -1,    19,    -1,   138,    -1,   142,    -1,   145,
      -1,   148,    -1,   155,    -1,   137,    89,    -1,    89,    30,
     170,    20,    -1,   195,    89,    -1,    89,    30,   195,    20,
      -1,   134,    -1,   137,    89,    -1,   133,    -1,   122,   192,
     178,    -1,    -1,    28,   111,    66,   139,   135,   140,    -1,
      79,   111,    66,   135,   140,    -1,   141,    -1,    -1,    80,
      66,   135,    -1,    -1,    -1,    54,   111,    66,   143,   135,
     144,   141,    -1,    -1,    -1,    25,   125,    81,   116,    66,
     146,   135,   147,   141,    -1,    -1,    21,   154,    57,   152,
      58,   160,    66,   149,   150,    -1,   134,    -1,   151,    -1,
      89,    30,   151,    20,    -1,    35,    98,    89,    -1,    -1,
     181,   153,   179,    -1,    93,    -1,    93,   159,    -1,    93,
      -1,    -1,    78,    93,   157,    66,   156,   158,    -1,   186,
      -1,   134,    -1,    67,   161,    -1,   159,    -1,   167,    -1,
     163,    -1,    93,    -1,   162,    -1,    57,   165,    58,    63,
     161,    -1,    52,    -1,    93,   164,    -1,   174,    -1,   185,
      -1,   161,    -1,   166,    61,   161,    -1,    -1,    69,    -1,
      73,    -1,    72,    -1,    70,    -1,    74,    -1,    55,    -1,
      82,    -1,    81,    -1,   111,    61,    -1,   169,   111,    61,
      -1,   136,    -1,   170,   136,    -1,    61,   111,    -1,   171,
      61,   111,    -1,    61,   127,    -1,   172,    61,   127,    -1,
      61,    -1,   171,   180,    -1,    83,    76,   166,    77,    -1,
      83,   161,    -1,    89,    -1,   136,    -1,    -1,   111,    -1,
      -1,    61,    -1,    -1,    68,    -1,    -1,    61,    -1,    -1,
      61,    -1,    -1,   181,   153,    61,    -1,    -1,   182,   175,
      -1,    -1,   111,   190,   177,    -1,    -1,   111,   190,    -1,
      -1,   166,    -1,    -1,    83,    76,   162,   194,    77,    -1,
      -1,   111,   173,    -1,    -1,   111,   193,   180,    -1,    -1,
     102,    -1,    -1,   190,    61,   111,    -1,    -1,   191,    61,
     103,    -1,    -1,   192,    68,   122,    -1,    -1,   193,    61,
     111,    -1,    -1,   194,    61,   162,    -1,     1,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const unsigned short int yyrline[] =
{
       0,   349,   349,   356,   359,   359,   359,   362,   362,   362,
     366,   367,   371,   372,   379,   380,   387,   388,   392,   396,
     400,   403,   407,   408,   409,   410,   411,   414,   418,   425,
     432,   433,   436,   438,   442,   448,   452,   456,   461,   462,
     462,   463,   468,   473,   478,   479,   484,   485,   489,   491,
     493,   498,   500,   502,   506,   508,   513,   514,   516,   518,
     518,   518,   518,   518,   518,   518,   525,   526,   527,   528,
     529,   530,   531,   534,   538,   540,   545,   546,   547,   548,
     549,   550,   556,   555,   557,   562,   563,   565,   566,   567,
     570,   575,   577,   579,   581,   583,   587,   591,   594,   598,
     599,   600,   601,   602,   606,   607,   608,   609,   613,   616,
     616,   620,   625,   624,   632,   634,   639,   640,   645,   647,
     644,   654,   656,   653,   663,   662,   676,   677,   678,   683,
     688,   689,   694,   695,   698,   701,   700,   707,   712,   715,
     719,   720,   724,   725,   727,   728,   734,   738,   742,   746,
     751,   752,   757,   489,   489,   489,   489,   489,   489,   489,
     489,   479,   479,   607,   607,   388,   388,   555,   555,   388,
     388,   742,   742,   349,   349,   352,   479,   482,   400,   403,
     620,   623,   689,   692,   388,   391,   689,   692,   349,   352,
     442,   445,   473,   476,   747,   750,   707,   710,   388,   391,
     392,   395,   396,   399,   442,   445,   400,   403,   620,   623,
     392,   395,   707,   712
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INT", "STRING", "ID", "\"@unop\"",
  "\"//\"", "\"**\"", "\"and\"", "\"@assign\"", "\"@attributeref\"",
  "\"@binop\"", "\"@block\"", "\"break\"", "\"@call\"", "\"@@block\"",
  "\"@compare\"", "\"@left_compare\"", "\"continue\"", "DEDENT", "\"def\"",
  "\"@dict_display\"", "EMPTY", "\"@expr_list\"", "\"for\"",
  "\"@formals_list\"", "\"@function_type\"", "\"if\"", "\"@if_expr\"",
  "INDENT", "\"@int_literal\"", "\"@list_display\"", "\"@def\"",
  "\"@module\"", "\"native\"", "\"not\"", "\"or\"", "\"@pair\"",
  "\"@print\"", "\"@println\"", "\"@slicing\"", "\"@@slicing\"",
  "\"@stmt_list\"", "STRING_LITERAL", "\"@subscription\"",
  "\"@@subscription\"", "\"@target_list\"", "\"@type_formals_list\"",
  "\"@tuple\"", "\"@type\"", "\"@type_list\"", "\"@type_var\"",
  "\"@typed_id\"", "\"while\"", "\"!=\"", "\"%\"", "\"(\"", "\")\"",
  "\"*\"", "\"+\"", "\",\"", "\"-\"", "\"->\"", "\".\"", "\"/\"", "\":\"",
  "\"::\"", "\";\"", "\"<\"", "\"<=\"", "\"=\"", "\"==\"", "\">\"",
  "\">=\"", "\">>\"", "\"[\"", "\"]\"", "\"class\"", "\"elif\"",
  "\"else\"", "\"in\"", "\"is\"", "\"of\"", "\"pass\"", "\"print\"",
  "\"return\"", "\"{\"", "\"}\"", "NEWLINE", "RAWSTRING", "$accept",
  "program", "identifier", "atom", "enclosure", "literal", "string_piece",
  "stringliteral", "parenth_form", "list_display", "dict_display",
  "key_datum_list", "key_datum", "primary", "attributeref", "subscription",
  "slicing", "bound", "call", "argument_list", "expression",
  "conditional_expression", "expr1", "expression_list_no_comma",
  "expression_list0_no_comma", "expression_or_list", "expression_or_list0",
  "comp_operator", "expr2", "left_compare", "expr3", "simple_stmt",
  "expression_stmt", "assignment_stmt", "target_list", "target_list1",
  "target", "pass_stmt", "print_stmt", "return_stmt", "break_stmt",
  "continue_stmt", "compound_stmt", "stmts", "suite", "statement",
  "stmt_list", "if_stmt", "@1", "elifs", "else_clause", "while_stmt", "@2",
  "@3", "for_stmt", "@4", "@5", "funcdef", "@6", "funcbody", "native",
  "parameter_list", "parameter", "funcname", "classdef", "@7",
  "type_formals", "classbody", "type_annotation", "opt_type_annotation",
  "type", "type_var", "parameterized_type", "type_params", "type_list",
  "types", "empty", "__0", "__1", "__2", "__3", "__4", "__5", "__6", "__7",
  "__8", "__9", "__10", "__11", "__12", "__13", "__14", "__15", "__16",
  "__17", "__18", "__19", "__20", "__21", "__22", "__23", "__24", "__25",
  "__26", "__error__", YY_NULL
};
#endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const unsigned char yyr1[] =
{
       0,    91,    92,    93,    94,    94,    94,    95,    95,    95,
      96,    96,    97,    97,    98,    98,    99,    99,   100,   101,
     102,   103,   104,   104,   104,   104,   104,   105,   106,   107,
     108,   108,   109,   109,   110,   111,   112,   112,   113,   113,
     113,   113,   114,   115,   116,   116,   117,   117,   118,   118,
     118,   119,   119,   119,   120,   120,   121,   121,   121,   121,
     121,   121,   121,   121,   121,   121,   122,   122,   122,   122,
     122,   122,   122,   123,   124,   124,   125,   125,   125,   125,
     125,   125,   126,   126,   126,   127,   127,   127,   127,   127,
     128,   129,   129,   129,   129,   129,   130,   131,   132,   133,
     133,   133,   133,   133,   134,   134,   134,   134,   135,   136,
     136,   137,   139,   138,   140,   140,   141,   141,   143,   144,
     142,   146,   147,   145,   149,   148,   150,   150,   150,   151,
     152,   152,   153,   153,   154,   156,   155,   157,   158,   159,
     160,   160,   161,   161,   161,   161,   162,   163,   164,   165,
     166,   166,   167,   168,   168,   168,   168,   168,   168,   168,
     168,   169,   169,   170,   170,   171,   171,   172,   172,   173,
     173,   174,   174,   175,   175,   176,   176,   177,   177,   178,
     178,   179,   179,   180,   180,   181,   181,   182,   182,   183,
     183,   184,   184,   185,   185,   186,   186,   187,   187,   188,
     188,   189,   189,   190,   190,   191,   191,   192,   192,   193,
     193,   194,   194,   195
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const unsigned char yyr2[] =
{
       0,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     3,     3,     3,     3,
       3,     3,     1,     1,     1,     1,     1,     3,     4,     6,
       1,     1,     4,     4,     1,     1,     5,     1,     1,     3,
       3,     2,     2,     1,     1,     2,     1,     1,     1,     2,
       2,     3,     3,     1,     3,     3,     1,     2,     2,     3,
       3,     3,     3,     3,     3,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     3,     1,     3,     1,     3,
       3,     3,     0,     3,     2,     1,     2,     1,     1,     1,
       1,     3,     3,     5,     4,     6,     2,     1,     1,     1,
       1,     1,     1,     1,     2,     4,     2,     4,     1,     2,
       1,     3,     0,     6,     5,     1,     0,     3,     0,     0,
       7,     0,     0,     9,     0,     9,     1,     1,     4,     3,
       0,     3,     1,     2,     1,     0,     6,     1,     1,     2,
       1,     1,     1,     1,     1,     5,     1,     2,     1,     1,
       1,     3,     0,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     3,     1,     2,     2,     3,     2,     3,     1,
       2,     4,     2,     1,     1,     0,     1,     0,     1,     0,
       1,     0,     1,     0,     1,     0,     3,     0,     2,     0,
       3,     0,     2,     0,     1,     0,     5,     0,     2,     0,
       3,     0,     1,     0,     3,     0,     3,     0,     3,     0,
       3,     0,     3,     1
};

/* YYDPREC[RULE-NUM] -- Dynamic precedence of rule #RULE-NUM (0 if none).  */
static const unsigned char yydprec[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0
};

/* YYMERGER[RULE-NUM] -- Index of merging function for rule #RULE-NUM.  */
static const unsigned char yymerger[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0
};

/* YYDEFACT[S] -- default reduction number in state S.  Performed when
   YYTABLE doesn't specify something else to do.  Zero means the default
   is an error.  */
static const unsigned char yydefact[] =
{
     187,     0,     2,     1,    12,     3,    97,    98,     0,    82,
       0,    11,     0,     0,    82,     0,     0,    82,     0,    90,
     152,   152,   201,   173,    13,     4,    22,     6,     5,    14,
      10,     7,     8,     9,    56,    23,    24,    25,    26,    44,
      35,    37,    73,    38,     0,    53,   207,    66,    67,     0,
      78,    76,    68,    69,    70,    71,    72,   110,   174,     0,
      99,   100,   101,   102,   103,     0,   175,   188,   134,     0,
       0,     0,   197,   199,     4,    23,    24,    25,     0,    41,
       0,     0,     0,     0,     0,    58,    57,   209,     0,     0,
       0,   195,     0,   191,    46,    96,    47,   202,   205,     0,
       0,     0,     0,    86,   147,   148,    15,   189,     0,   152,
     161,     0,     0,     0,     0,   158,   153,   156,   155,   154,
     157,   160,   159,     0,    48,     0,     0,     0,     0,     0,
       0,     0,     0,   179,    82,    84,   177,   109,   189,   176,
      45,   130,     0,   112,   118,    16,   169,   183,   198,    79,
      77,    17,   183,    80,    81,    18,     0,     0,   137,    92,
     203,     0,    91,    43,   177,     0,    19,   146,   193,   143,
     139,   144,   142,     0,   172,     0,   203,    34,    27,     0,
      30,     0,    31,    40,     0,    39,    50,    49,    51,    63,
      65,    64,    61,    59,    60,    62,    52,    82,   111,    74,
      75,   167,   178,    83,     0,   162,     0,     0,     0,     0,
       0,   165,   184,   170,   184,   200,     0,   135,     0,   192,
      94,   178,    20,    21,   150,     0,   194,   149,     0,    32,
     177,   152,    28,     0,   208,   168,    33,   152,   132,   181,
     121,   213,     0,   108,   116,     0,     0,   119,   166,   210,
     211,     0,   203,    93,     0,   206,     0,     0,   171,   178,
     190,     0,    30,    36,   140,     0,   141,   133,   182,   131,
       0,     0,     0,     0,   113,   115,   104,   106,   116,     0,
     138,   136,    42,    95,   204,     0,   151,    29,   124,   122,
     163,    82,     0,     0,     0,   120,     0,   196,   145,     0,
     116,   105,   164,   107,     0,   117,   212,     0,     0,   126,
     125,   127,   123,   116,     0,     0,   114,   129,     0,   128
};

/* YYPDEFGOTO[NTERM-NUM].  */
static const short int yydefgoto[] =
{
      -1,     1,    74,    26,    27,    28,    29,    30,    31,    32,
      33,    97,    98,    34,    75,    76,    77,   179,    38,   175,
      39,    40,    41,   161,   162,    42,    95,   123,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,   243,   244,   290,   245,    60,   209,   274,
     275,    61,   210,   278,    62,   270,   300,    63,   299,   310,
     311,   206,   239,    69,    64,   251,   157,   281,   103,   265,
     224,   171,    65,   104,   225,   226,   182,   124,    66,   291,
     147,   136,   148,   105,    67,   140,   203,   198,   269,   213,
     207,     2,   177,   163,   227,   158,    84,    90,   100,   219,
     164,   133,   152,   279,   246
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -239
static const short int yypact[] =
{
    -239,    36,   543,  -239,  -239,  -239,  -239,  -239,    48,    40,
     408,  -239,   408,   408,    52,   462,   462,   188,    48,  -239,
     -14,   408,   408,  -239,  -239,   297,  -239,  -239,  -239,  -239,
      15,  -239,  -239,  -239,     5,    -3,   155,   162,  -239,    11,
    -239,    26,  -239,  -239,   683,   677,  -239,  -239,  -239,     8,
    -239,    12,  -239,  -239,  -239,  -239,  -239,  -239,  -239,    -9,
    -239,  -239,  -239,  -239,  -239,    29,   408,  -239,  -239,    33,
       5,    34,   408,   408,    38,  -239,  -239,  -239,    56,  -239,
      57,   -10,    85,    97,    86,   149,   149,  -239,    88,   -11,
      91,    79,   408,   408,  -239,  -239,  -239,  -239,  -239,   103,
      75,    84,    44,  -239,  -239,  -239,  -239,   408,    48,   408,
    -239,   408,   408,   408,    92,  -239,  -239,  -239,  -239,  -239,
    -239,  -239,   136,   462,  -239,   462,   462,   462,   462,   462,
     462,   462,   462,   112,   633,    80,   120,  -239,   408,   127,
    -239,   184,   408,  -239,  -239,  -239,   408,   129,  -239,  -239,
    -239,  -239,   130,  -239,  -239,  -239,   123,   128,  -239,   140,
    -239,   142,  -239,  -239,   145,   408,  -239,  -239,    84,    38,
    -239,  -239,  -239,    84,  -239,   153,  -239,  -239,  -239,   146,
      14,   138,  -239,  -239,    23,   208,  -239,  -239,   707,   149,
     149,   149,   149,   118,   118,   149,   737,   621,  -239,  -239,
    -239,  -239,    80,  -239,   160,  -239,   163,    48,   159,   499,
     499,  -239,   408,  -239,   408,  -239,   176,  -239,   408,   168,
    -239,   408,  -239,  -239,  -239,   172,   180,  -239,    21,  -239,
     181,   408,  -239,   408,  -239,  -239,  -239,   177,   177,   185,
    -239,  -239,   223,  -239,   -39,   167,   173,  -239,  -239,  -239,
    -239,   499,  -239,   193,   408,  -239,   198,    84,  -239,   408,
    -239,   186,  -239,  -239,  -239,   200,  -239,  -239,   262,  -239,
     499,   421,   408,   211,  -239,  -239,  -239,  -239,   199,    63,
    -239,  -239,   219,  -239,  -239,    84,  -239,  -239,  -239,  -239,
    -239,   587,   261,   216,   499,  -239,   176,  -239,  -239,   455,
     199,  -239,  -239,  -239,   499,  -239,  -239,    15,   254,  -239,
    -239,  -239,  -239,   -39,    18,   331,  -239,  -239,   265,  -239
};

/* YYPGOTO[NTERM-NUM].  */
static const short int yypgoto[] =
{
    -239,  -239,    -2,  -239,  -239,  -239,   -27,   -21,  -239,  -239,
    -239,  -239,    67,    -4,     0,    25,    50,    69,  -239,   169,
     165,  -239,     6,    87,  -239,     4,  -239,   253,  -239,  -239,
      22,   109,  -239,   174,   300,   147,    -6,  -239,  -239,  -239,
    -239,  -239,  -239,  -223,  -200,    -1,     2,  -239,  -239,     1,
    -235,  -239,  -239,  -239,  -239,  -239,  -239,  -239,  -239,  -239,
      -5,  -239,  -239,  -239,  -239,  -239,  -239,  -239,  -191,  -239,
     -71,  -203,   -81,  -239,  -239,   139,     3,  -239,  -239,  -239,
    -239,  -239,  -239,  -239,  -239,  -239,  -135,  -239,  -239,   166,
    -239,  -239,  -239,  -239,  -239,  -239,  -239,  -239,  -239,  -150,
    -239,  -239,  -239,  -239,  -238
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -187
static const short int yytable[] =
{
      25,    58,    35,   106,    59,    70,    68,    25,    83,    35,
     247,    89,    25,   250,    35,    25,    91,    35,    79,     4,
     172,   172,     4,    93,    96,    94,   230,    36,   280,   222,
     170,   174,   111,   292,    36,   111,     3,    85,    86,    36,
     272,   273,    36,   295,     4,     5,   264,   267,   145,     5,
     135,   146,    37,     5,   112,   -23,     4,     5,   -23,    37,
     113,    92,   107,   113,    37,   312,   154,    37,   -87,   108,
     289,    11,   110,   135,   -23,   110,   309,   292,   -23,   134,
     137,   109,   257,    11,     4,     5,   138,   172,    12,     5,
     141,   -44,   172,   306,   305,   260,   167,    14,   258,   169,
     169,   168,   282,   233,   313,    24,   178,   317,    24,    72,
     -82,    11,    15,   181,    16,   142,    17,   183,   184,   185,
     173,   102,   143,   144,   296,   125,   126,    22,    73,   201,
      24,    70,    25,    25,    35,    35,   167,    72,   199,    22,
     297,   168,    24,   149,   151,   188,   208,   189,   190,   191,
     192,   193,   194,   195,   196,   150,    73,   126,   135,    36,
      36,    82,   156,   166,    88,   153,   169,    22,   155,   165,
      24,   169,   187,   186,   127,    78,   172,   128,    80,    81,
     197,   202,    87,   131,    37,    37,   286,    99,   205,  -185,
     212,   214,     4,     5,   217,    25,   235,    35,    70,   216,
      25,   218,    35,   220,   172,   238,   221,    25,    25,    35,
      35,   229,   231,   -24,   298,   232,   -24,   111,   236,    11,
     -25,   237,    36,   -25,    12,   240,   -88,    36,   167,   254,
     256,   139,   -24,   -89,    36,    36,   -24,    81,    87,   -25,
     266,   257,   259,   -25,   101,    72,   268,    37,    15,    25,
      16,    35,    37,   271,   283,   169,   276,   159,   160,    37,
      37,   285,   277,   287,    73,   -82,   288,  -186,    25,    25,
      35,    35,   176,    59,   180,    22,    36,   294,    24,   273,
     254,   303,   304,   169,   315,   319,   314,   106,   255,    25,
     302,    35,    25,    59,    35,    36,    36,    25,   132,    35,
     261,    37,    25,   176,    35,   253,   234,   204,   200,    71,
     318,   211,   228,    25,   316,    35,    36,    59,   215,    36,
      37,    37,     0,     0,    36,     0,     0,     0,     0,    36,
     223,     0,   241,     0,     0,     4,     5,     0,     0,     0,
      36,    37,     0,     0,    37,     6,     0,     0,     0,    37,
       7,     0,     8,     0,    37,    -4,     9,     0,    -4,    10,
       0,     0,    11,     0,   101,    37,   307,    12,   -85,     0,
       0,     0,     0,     0,    -4,     0,     0,   248,    -4,   249,
     102,     0,     0,   252,     0,    13,    99,     0,    14,     0,
       0,    15,     0,    16,     0,     0,   262,     0,   263,     0,
       0,     0,   -82,     0,     0,     0,     0,    17,     0,    18,
       0,     0,     4,     5,     0,    19,    20,    21,    22,   284,
       0,    24,   241,     0,   284,     4,     5,     0,     0,     0,
       0,     0,     0,     0,     0,     6,     0,   293,     0,    11,
       7,     0,     8,     0,    12,     0,     9,     0,     0,    10,
       0,     0,    11,     0,     0,     0,   241,    12,     0,     4,
       5,     0,     0,     0,     0,    72,     4,     5,    15,     6,
      16,     0,     0,     0,     7,    13,     0,     0,    14,     0,
       0,    15,     0,    16,    73,     0,    11,     0,     0,     0,
     307,    12,   -82,    11,     0,    22,     0,    17,    24,    18,
     241,     0,     0,     4,     5,    19,    20,    21,    22,     0,
       0,    24,    14,     6,     0,    15,     0,    16,     7,    72,
       0,     0,    15,     0,    16,     0,   -82,     0,     0,     0,
      11,    17,     0,     0,     0,    12,     0,     0,    73,    19,
      20,    21,    22,     0,   308,    24,     0,     4,     5,    22,
       0,     0,    24,     0,     0,     0,    14,     6,     0,    15,
       0,    16,     7,     0,     8,     0,     0,     0,     9,     0,
     -82,    10,     0,     0,    11,    17,     0,     0,     0,    12,
       0,     0,     0,    19,    20,    21,    22,     0,   242,    24,
       0,     4,     5,     0,     0,     0,     0,    13,     0,     0,
      14,     6,     0,    15,     0,    16,     7,   301,     8,     0,
       0,     0,     9,     0,   -82,    10,     0,     0,    11,    17,
       0,    18,     0,    12,     0,     4,     5,    19,    20,    21,
      22,     0,    23,    24,     0,     6,     0,     4,     5,     0,
       7,    13,     0,     0,    14,     0,     0,    15,     0,    16,
       0,     0,    11,     0,     0,     0,     0,    12,     0,     0,
       0,     0,     0,    17,    11,    18,     0,     0,     0,    12,
       0,    19,    20,    21,    22,     0,     0,    24,    14,     0,
       0,    15,     0,    16,   125,   126,     0,     0,     0,     0,
      14,     0,     0,    15,     0,    16,     0,    17,     0,     0,
       0,     0,     0,     0,     0,    19,    20,    21,    22,    17,
    -180,    24,     0,   114,   125,   126,     0,     0,     0,   114,
      22,     0,     0,    24,     0,     0,     0,     0,     0,     0,
       0,     0,   115,   127,     0,     0,   128,   129,   115,   130,
       0,     0,   131,   -55,   125,   126,   116,   117,     0,   118,
     119,   120,   116,   117,     0,   118,   119,   120,   121,   122,
       0,     0,   -55,   127,   121,   122,   128,   129,     0,   130,
       0,     0,   131,   -54,     0,     0,   -55,   -55,     0,   -55,
     -55,   -55,     0,     0,     0,     0,     0,     0,   -55,   -55,
       0,     0,   -54,   127,     0,     0,   128,   129,     0,   130,
       0,     0,   131,     0,     0,     0,   -54,   -54,     0,   -54,
     -54,   -54,     0,     0,     0,     0,     0,     0,   -54,   -54
};

/* YYCONFLP[YYPACT[STATE-NUM]] -- Pointer into YYCONFL of start of
   list of conflicting reductions corresponding to action entry for
   state STATE-NUM in yytable.  0 means no conflicts.  The list in
   yyconfl is terminated by a rule number of 0.  */
static const unsigned char yyconflp[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    13,     0,     0,    15,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    17,     0,     0,     0,    19,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       1,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    21,     0,     0,    23,     0,     0,     0,
      29,     0,     0,    31,     0,     0,     0,     0,     0,    37,
       0,     0,    25,     0,     0,     0,    27,     0,     0,    33,
       0,     0,     0,    35,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     3,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      39,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     5,     0,     0,     7,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     9,     0,     0,     0,    11,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0
};

/* YYCONFL[I] -- lists of conflicting rule numbers, each terminated by
   0, pointed into by YYCONFLP.  */
static const short int yyconfl[] =
{
       0,   197,     0,   199,     0,    85,     0,    85,     0,    85,
       0,    85,     0,    87,     0,    87,     0,    87,     0,    87,
       0,    88,     0,    88,     0,    88,     0,    88,     0,    89,
       0,    89,     0,    89,     0,    89,     0,    42,     0,    42,
       0
};

static const short int yycheck[] =
{
       2,     2,     2,    30,     2,     9,     8,     9,    14,     9,
     210,    17,    14,   216,    14,    17,    18,    17,    12,     4,
     101,   102,     4,    20,    21,    21,   176,     2,   251,   164,
     101,   102,     9,   271,     9,     9,     0,    15,    16,    14,
      79,    80,    17,   278,     4,     5,   237,   238,    58,     5,
      61,    61,     2,     5,    28,    58,     4,     5,    61,     9,
      37,    75,    57,    37,    14,   300,    77,    17,    71,    64,
     270,    31,    61,    61,    77,    61,   299,   315,    81,    71,
      89,    76,    61,    31,     4,     5,    57,   168,    36,     5,
      57,    77,   173,   296,   294,   230,    52,    57,    77,   101,
     102,    57,   252,    80,   304,    90,   108,    89,    90,    57,
      58,    31,    60,   109,    62,    81,    76,   111,   112,   113,
      76,    83,    66,    66,    61,     7,     8,    87,    76,   135,
      90,   135,   134,   135,   134,   135,    52,    57,   134,    87,
      77,    57,    90,    58,    58,   123,   142,   125,   126,   127,
     128,   129,   130,   131,   132,    58,    76,     8,    61,   134,
     135,    14,    83,    88,    17,    77,   168,    87,    77,    66,
      90,   173,    36,    81,    56,    10,   257,    59,    13,    14,
      68,    61,    17,    65,   134,   135,   257,    22,    61,     5,
      61,    61,     4,     5,    66,   197,   202,   197,   202,    76,
     202,    61,   202,    61,   285,   207,    61,   209,   210,   209,
     210,    58,    66,    58,   285,    77,    61,     9,    58,    31,
      58,    58,   197,    61,    36,    66,    71,   202,    52,    61,
      58,    66,    77,    71,   209,   210,    81,    72,    73,    77,
     237,    61,    61,    81,    67,    57,    61,   197,    60,   251,
      62,   251,   202,    30,    61,   257,    89,    92,    93,   209,
     210,    63,    89,    77,    76,    77,    66,     5,   270,   271,
     270,   271,   107,   271,   109,    87,   251,    66,    90,    80,
      61,    20,    66,   285,    30,    20,   307,   314,   221,   291,
     291,   291,   294,   291,   294,   270,   271,   299,    45,   299,
     231,   251,   304,   138,   304,   218,   197,   138,   134,     9,
     315,   146,   173,   315,   313,   315,   291,   315,   152,   294,
     270,   271,    -1,    -1,   299,    -1,    -1,    -1,    -1,   304,
     165,    -1,     1,    -1,    -1,     4,     5,    -1,    -1,    -1,
     315,   291,    -1,    -1,   294,    14,    -1,    -1,    -1,   299,
      19,    -1,    21,    -1,   304,    58,    25,    -1,    61,    28,
      -1,    -1,    31,    -1,    67,   315,    35,    36,    71,    -1,
      -1,    -1,    -1,    -1,    77,    -1,    -1,   212,    81,   214,
      83,    -1,    -1,   218,    -1,    54,   221,    -1,    57,    -1,
      -1,    60,    -1,    62,    -1,    -1,   231,    -1,   233,    -1,
      -1,    -1,    71,    -1,    -1,    -1,    -1,    76,    -1,    78,
      -1,    -1,     4,     5,    -1,    84,    85,    86,    87,   254,
      -1,    90,     1,    -1,   259,     4,     5,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    14,    -1,   272,    -1,    31,
      19,    -1,    21,    -1,    36,    -1,    25,    -1,    -1,    28,
      -1,    -1,    31,    -1,    -1,    -1,     1,    36,    -1,     4,
       5,    -1,    -1,    -1,    -1,    57,     4,     5,    60,    14,
      62,    -1,    -1,    -1,    19,    54,    -1,    -1,    57,    -1,
      -1,    60,    -1,    62,    76,    -1,    31,    -1,    -1,    -1,
      35,    36,    71,    31,    -1,    87,    -1,    76,    90,    78,
       1,    -1,    -1,     4,     5,    84,    85,    86,    87,    -1,
      -1,    90,    57,    14,    -1,    60,    -1,    62,    19,    57,
      -1,    -1,    60,    -1,    62,    -1,    71,    -1,    -1,    -1,
      31,    76,    -1,    -1,    -1,    36,    -1,    -1,    76,    84,
      85,    86,    87,    -1,    89,    90,    -1,     4,     5,    87,
      -1,    -1,    90,    -1,    -1,    -1,    57,    14,    -1,    60,
      -1,    62,    19,    -1,    21,    -1,    -1,    -1,    25,    -1,
      71,    28,    -1,    -1,    31,    76,    -1,    -1,    -1,    36,
      -1,    -1,    -1,    84,    85,    86,    87,    -1,    89,    90,
      -1,     4,     5,    -1,    -1,    -1,    -1,    54,    -1,    -1,
      57,    14,    -1,    60,    -1,    62,    19,    20,    21,    -1,
      -1,    -1,    25,    -1,    71,    28,    -1,    -1,    31,    76,
      -1,    78,    -1,    36,    -1,     4,     5,    84,    85,    86,
      87,    -1,    89,    90,    -1,    14,    -1,     4,     5,    -1,
      19,    54,    -1,    -1,    57,    -1,    -1,    60,    -1,    62,
      -1,    -1,    31,    -1,    -1,    -1,    -1,    36,    -1,    -1,
      -1,    -1,    -1,    76,    31,    78,    -1,    -1,    -1,    36,
      -1,    84,    85,    86,    87,    -1,    -1,    90,    57,    -1,
      -1,    60,    -1,    62,     7,     8,    -1,    -1,    -1,    -1,
      57,    -1,    -1,    60,    -1,    62,    -1,    76,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    84,    85,    86,    87,    76,
      89,    90,    -1,    36,     7,     8,    -1,    -1,    -1,    36,
      87,    -1,    -1,    90,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    55,    56,    -1,    -1,    59,    60,    55,    62,
      -1,    -1,    65,    36,     7,     8,    69,    70,    -1,    72,
      73,    74,    69,    70,    -1,    72,    73,    74,    81,    82,
      -1,    -1,    55,    56,    81,    82,    59,    60,    -1,    62,
      -1,    -1,    65,    36,    -1,    -1,    69,    70,    -1,    72,
      73,    74,    -1,    -1,    -1,    -1,    -1,    -1,    81,    82,
      -1,    -1,    55,    56,    -1,    -1,    59,    60,    -1,    62,
      -1,    -1,    65,    -1,    -1,    -1,    69,    70,    -1,    72,
      73,    74,    -1,    -1,    -1,    -1,    -1,    -1,    81,    82
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const unsigned char yystos[] =
{
       0,    92,   182,     0,     4,     5,    14,    19,    21,    25,
      28,    31,    36,    54,    57,    60,    62,    76,    78,    84,
      85,    86,    87,    89,    90,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   104,   105,   106,   107,   109,   111,
     112,   113,   116,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   136,   137,
     138,   142,   145,   148,   155,   163,   169,   175,    93,   154,
     104,   125,    57,    76,    93,   105,   106,   107,   111,   113,
     111,   111,   126,   127,   187,   121,   121,   111,   126,   127,
     188,    93,    75,   167,   116,   117,   167,   102,   103,   111,
     189,    67,    83,   159,   164,   174,    97,    57,    64,    76,
      61,     9,    28,    37,    36,    55,    69,    70,    72,    73,
      74,    81,    82,   118,   168,     7,     8,    56,    59,    60,
      62,    65,   118,   192,    71,    61,   172,    89,    57,   111,
     176,    57,    81,    66,    66,    58,    61,   171,   173,    58,
      58,    58,   193,    77,    77,    77,    83,   157,   186,   111,
     111,   114,   115,   184,   191,    66,    88,    52,    57,    93,
     161,   162,   163,    76,   161,   110,   111,   183,    93,   108,
     111,   116,   167,   113,   113,   113,    81,    36,   121,   121,
     121,   121,   121,   121,   121,   121,   121,    68,   178,   116,
     124,   127,    61,   177,   110,    61,   152,   181,   116,   139,
     143,   111,    61,   180,    61,   180,    76,    66,    61,   190,
      61,    61,   177,   111,   161,   165,   166,   185,   166,    58,
     190,    66,    77,    80,   122,   127,    58,    58,    93,   153,
      66,     1,    89,   134,   135,   137,   195,   135,   111,   111,
     162,   156,   111,   114,    61,   103,    58,    61,    77,    61,
     177,   108,   111,   111,   159,   160,   167,   159,    61,   179,
     146,    30,    79,    80,   140,   141,    89,    89,   144,   194,
     134,   158,   190,    61,   111,    63,   161,    77,    66,   135,
     136,   170,   195,   111,    66,   141,    61,    77,   161,   149,
     147,    20,   136,    20,    66,   135,   162,    35,    89,   134,
     150,   151,   141,   135,    98,    30,   140,    89,   151,    20
};

/* Error token number */
#define YYTERROR 1


#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N) ((void) 0)
#endif


#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif

/* YYLEX -- calling `yylex' with the right arguments.  */
#define YYLEX yylex ()

YYSTYPE yylval;

int yynerrs;
int yychar;

static const int YYEOF = 0;
static const int YYEMPTY = -2;

typedef enum { yyok, yyaccept, yyabort, yyerr } YYRESULTTAG;

#define YYCHK(YYE)                                                           \
   do { YYRESULTTAG yyflag = YYE; if (yyflag != yyok) return yyflag; }       \
   while (YYID (0))

#if YYDEBUG

# ifndef YYFPRINTF
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)          \
do {                                                            \
  if (yydebug)                                                  \
    {                                                           \
      YYFPRINTF (stderr, "%s ", Title);                         \
      yy_symbol_print (stderr, Type, Value);        \
      YYFPRINTF (stderr, "\n");                                 \
    }                                                           \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;

#else /* !YYDEBUG */

# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)

#endif /* !YYDEBUG */

/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   SIZE_MAX < YYMAXDEPTH * sizeof (GLRStackItem)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif

/* Minimum number of free items on the stack allowed after an
   allocation.  This is to allow allocation and initialization
   to be completed by functions that call yyexpandGLRStack before the
   stack is expanded, thus insuring that all necessary pointers get
   properly redirected to new data.  */
#define YYHEADROOM 2

#ifndef YYSTACKEXPANDABLE
# if (! defined __cplusplus \
      || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL))
#  define YYSTACKEXPANDABLE 1
# else
#  define YYSTACKEXPANDABLE 0
# endif
#endif

#if YYSTACKEXPANDABLE
# define YY_RESERVE_GLRSTACK(Yystack)                   \
  do {                                                  \
    if (Yystack->yyspaceLeft < YYHEADROOM)              \
      yyexpandGLRStack (Yystack);                       \
  } while (YYID (0))
#else
# define YY_RESERVE_GLRSTACK(Yystack)                   \
  do {                                                  \
    if (Yystack->yyspaceLeft < YYHEADROOM)              \
      yyMemoryExhausted (Yystack);                      \
  } while (YYID (0))
#endif


#if YYERROR_VERBOSE

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static size_t
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      size_t yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return strlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

#endif /* !YYERROR_VERBOSE */

/** State numbers, as in LALR(1) machine */
typedef int yyStateNum;

/** Rule numbers, as in LALR(1) machine */
typedef int yyRuleNum;

/** Grammar symbol */
typedef short int yySymbol;

/** Item references, as in LALR(1) machine */
typedef short int yyItemNum;

typedef struct yyGLRState yyGLRState;
typedef struct yyGLRStateSet yyGLRStateSet;
typedef struct yySemanticOption yySemanticOption;
typedef union yyGLRStackItem yyGLRStackItem;
typedef struct yyGLRStack yyGLRStack;

struct yyGLRState {
  /** Type tag: always true.  */
  yybool yyisState;
  /** Type tag for yysemantics.  If true, yysval applies, otherwise
   *  yyfirstVal applies.  */
  yybool yyresolved;
  /** Number of corresponding LALR(1) machine state.  */
  yyStateNum yylrState;
  /** Preceding state in this stack */
  yyGLRState* yypred;
  /** Source position of the first token produced by my symbol */
  size_t yyposn;
  union {
    /** First in a chain of alternative reductions producing the
     *  non-terminal corresponding to this state, threaded through
     *  yynext.  */
    yySemanticOption* yyfirstVal;
    /** Semantic value for this state.  */
    YYSTYPE yysval;
  } yysemantics;
};

struct yyGLRStateSet {
  yyGLRState** yystates;
  /** During nondeterministic operation, yylookaheadNeeds tracks which
   *  stacks have actually needed the current lookahead.  During deterministic
   *  operation, yylookaheadNeeds[0] is not maintained since it would merely
   *  duplicate yychar != YYEMPTY.  */
  yybool* yylookaheadNeeds;
  size_t yysize, yycapacity;
};

struct yySemanticOption {
  /** Type tag: always false.  */
  yybool yyisState;
  /** Rule number for this reduction */
  yyRuleNum yyrule;
  /** The last RHS state in the list of states to be reduced.  */
  yyGLRState* yystate;
  /** The lookahead for this reduction.  */
  int yyrawchar;
  YYSTYPE yyval;
  /** Next sibling in chain of options.  To facilitate merging,
   *  options are chained in decreasing order by address.  */
  yySemanticOption* yynext;
};

/** Type of the items in the GLR stack.  The yyisState field
 *  indicates which item of the union is valid.  */
union yyGLRStackItem {
  yyGLRState yystate;
  yySemanticOption yyoption;
};

struct yyGLRStack {
  int yyerrState;


  YYJMP_BUF yyexception_buffer;
  yyGLRStackItem* yyitems;
  yyGLRStackItem* yynextFree;
  size_t yyspaceLeft;
  yyGLRState* yysplitPoint;
  yyGLRState* yylastDeleted;
  yyGLRStateSet yytops;
};

#if YYSTACKEXPANDABLE
static void yyexpandGLRStack (yyGLRStack* yystackp);
#endif

static void yyFail (yyGLRStack* yystackp, const char* yymsg)
  __attribute__ ((__noreturn__));
static void
yyFail (yyGLRStack* yystackp, const char* yymsg)
{
  if (yymsg != YY_NULL)
    yyerror (yymsg);
  YYLONGJMP (yystackp->yyexception_buffer, 1);
}

static void yyMemoryExhausted (yyGLRStack* yystackp)
  __attribute__ ((__noreturn__));
static void
yyMemoryExhausted (yyGLRStack* yystackp)
{
  YYLONGJMP (yystackp->yyexception_buffer, 2);
}

#if YYDEBUG || YYERROR_VERBOSE
/** A printable representation of TOKEN.  */
static inline const char*
yytokenName (yySymbol yytoken)
{
  if (yytoken == YYEMPTY)
    return "";

  return yytname[yytoken];
}
#endif

/** Fill in YYVSP[YYLOW1 .. YYLOW0-1] from the chain of states starting
 *  at YYVSP[YYLOW0].yystate.yypred.  Leaves YYVSP[YYLOW1].yystate.yypred
 *  containing the pointer to the next state in the chain.  */
static void yyfillin (yyGLRStackItem *, int, int) __attribute__ ((__unused__));
static void
yyfillin (yyGLRStackItem *yyvsp, int yylow0, int yylow1)
{
  int i;
  yyGLRState *s = yyvsp[yylow0].yystate.yypred;
  for (i = yylow0-1; i >= yylow1; i -= 1)
    {
      YYASSERT (s->yyresolved);
      yyvsp[i].yystate.yyresolved = yytrue;
      yyvsp[i].yystate.yysemantics.yysval = s->yysemantics.yysval;
      s = yyvsp[i].yystate.yypred = s->yypred;
    }
}

/* Do nothing if YYNORMAL or if *YYLOW <= YYLOW1.  Otherwise, fill in
 * YYVSP[YYLOW1 .. *YYLOW-1] as in yyfillin and set *YYLOW = YYLOW1.
 * For convenience, always return YYLOW1.  */
static inline int yyfill (yyGLRStackItem *, int *, int, yybool)
     __attribute__ ((__unused__));
static inline int
yyfill (yyGLRStackItem *yyvsp, int *yylow, int yylow1, yybool yynormal)
{
  if (!yynormal && yylow1 < *yylow)
    {
      yyfillin (yyvsp, *yylow, yylow1);
      *yylow = yylow1;
    }
  return yylow1;
}

/** Perform user action for rule number YYN, with RHS length YYRHSLEN,
 *  and top stack item YYVSP.  YYLVALP points to place to put semantic
 *  value ($$), and yylocp points to place for location information
 *  (@$).  Returns yyok for normal return, yyaccept for YYACCEPT,
 *  yyerr for YYERROR, yyabort for YYABORT.  */
/*ARGSUSED*/ static YYRESULTTAG
yyuserAction (yyRuleNum yyn, int yyrhslen, yyGLRStackItem* yyvsp,
              yyGLRStack* yystackp,
              YYSTYPE* yyvalp)
{
  yybool yynormal __attribute__ ((__unused__)) =
    (yystackp->yysplitPoint == YY_NULL);
  int yylow;
# undef yyerrok
# define yyerrok (yystackp->yyerrState = 0)
# undef YYACCEPT
# define YYACCEPT return yyaccept
# undef YYABORT
# define YYABORT return yyabort
# undef YYERROR
# define YYERROR return yyerrok, yyerr
# undef YYRECOVERING
# define YYRECOVERING() (yystackp->yyerrState != 0)
# undef yyclearin
# define yyclearin (yychar = YYEMPTY)
# undef YYFILL
# define YYFILL(N) yyfill (yyvsp, &yylow, N, yynormal)
# undef YYBACKUP
# define YYBACKUP(Token, Value)                                              \
  return yyerror (YY_("syntax error: cannot back up")),     \
         yyerrok, yyerr

  yylow = 1;
  if (yyrhslen == 0)
    *yyvalp = yyval_default;
  else
    *yyvalp = yyvsp[YYFILL (1-yyrhslen)].yystate.yysemantics.yysval;
  switch (yyn)
    {
        case 2:

/* Line 895 of glr.c  */
#line 350 "apyc.hn"
    { YYCTLA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval)); yylhs = YYMAKE_TREE (MODULE, yylhs.all_values ());
                  yylhs.set_loc (NULL);
                  theTree = yylhs.value (); }
    break;

  case 3:

/* Line 895 of glr.c  */
#line 356 "apyc.hn"
    { YYCTLPA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval));  yyv_ID = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval); }
    break;

  case 4:

/* Line 895 of glr.c  */
#line 359 "apyc.hn"
    { YYCTLPA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval));  yyv_identifier = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval); }
    break;

  case 5:

/* Line 895 of glr.c  */
#line 359 "apyc.hn"
    { YYCTLPA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval));  yyv_literal = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval); }
    break;

  case 6:

/* Line 895 of glr.c  */
#line 359 "apyc.hn"
    { YYCTLPA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval));  yyv_enclosure = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval); }
    break;

  case 7:

/* Line 895 of glr.c  */
#line 362 "apyc.hn"
    { YYCTLPA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval));  yyv_parenth_form = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval); }
    break;

  case 8:

/* Line 895 of glr.c  */
#line 362 "apyc.hn"
    { YYCTLPA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval));  yyv_list_display = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval); }
    break;

  case 9:

/* Line 895 of glr.c  */
#line 362 "apyc.hn"
    { YYCTLPA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval));  yyv_dict_display = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval); }
    break;

  case 10:

/* Line 895 of glr.c  */
#line 366 "apyc.hn"
    { YYCTLPA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval));  yyv_stringliteral = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval); }
    break;

  case 11:

/* Line 895 of glr.c  */
#line 367 "apyc.hn"
    { YYCTLPA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval));  yyv_INT_LITERAL = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval); }
    break;

  case 12:

/* Line 895 of glr.c  */
#line 371 "apyc.hn"
    { YYCTLPA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval));  yyv_STRING = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval); }
    break;

  case 13:

/* Line 895 of glr.c  */
#line 372 "apyc.hn"
    { YYCTLPA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval));  yyv_RAWSTRING = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval); }
    break;

  case 14:

/* Line 895 of glr.c  */
#line 379 "apyc.hn"
    { YYCTLPA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval));  yyv_string_piece = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval); }
    break;

  case 15:

/* Line 895 of glr.c  */
#line 381 "apyc.hn"
    { YYCTLPA(((*yyvalp)),0,2,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (2))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (2))].yystate.yysemantics.yysval));  yyv_stringliteral = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (2))].yystate.yysemantics.yysval); yyv_string_piece = (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (2))].yystate.yysemantics.yysval);yyv_stringliteral.value()->as_token()
                     ->append_text(yyv_string_piece.value()->as_token()
                                   ->string_text()); 
                  yylhs = yyv_stringliteral; }
    break;

  case 16:

/* Line 895 of glr.c  */
#line 387 "apyc.hn"
    { YYCTLPA(((*yyvalp)),0,3,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (3))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval).ignore(); yyv_expression = (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (3))].yystate.yysemantics.yysval); }
    break;

  case 17:

/* Line 895 of glr.c  */
#line 389 "apyc.hn"
    { YYCTLA(((*yyvalp)),0,3,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (3))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval).ignore();yylhs = YYMAKE_TREE(TUPLE, yylhs.all_values ()); }
    break;

  case 18:

/* Line 895 of glr.c  */
#line 393 "apyc.hn"
    { YYCTLA(((*yyvalp)),0,3,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (3))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval).ignore();yylhs = YYMAKE_TREE(LIST_DISPLAY, yylhs.all_values ()); }
    break;

  case 19:

/* Line 895 of glr.c  */
#line 397 "apyc.hn"
    { YYCTLA(((*yyvalp)),0,3,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (3))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval).ignore();yylhs = YYMAKE_TREE(DICT_DISPLAY, yylhs.all_values ()); }
    break;

  case 20:

/* Line 895 of glr.c  */
#line 400 "apyc.hn"
    { YYCTLA(((*yyvalp)),0,3,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (3))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval));  }
    break;

  case 21:

/* Line 895 of glr.c  */
#line 404 "apyc.hn"
    { YYCTLPA(((*yyvalp)),0,3,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (3))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (3))].yystate.yysemantics.yysval).ignore(); yyv_expression = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval); yyv_expression = (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval);yylhs = YYMAKE_TREE(PAIR, yylhs.all_values ()); }
    break;

  case 22:

/* Line 895 of glr.c  */
#line 407 "apyc.hn"
    { YYCTLPA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval));  yyv_atom = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval); }
    break;

  case 23:

/* Line 895 of glr.c  */
#line 408 "apyc.hn"
    { YYCTLPA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval));  yyv_attributeref = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval); }
    break;

  case 24:

/* Line 895 of glr.c  */
#line 409 "apyc.hn"
    { YYCTLPA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval));  yyv_subscription = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval); }
    break;

  case 25:

/* Line 895 of glr.c  */
#line 410 "apyc.hn"
    { YYCTLPA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval));  yyv_slicing = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval); }
    break;

  case 26:

/* Line 895 of glr.c  */
#line 411 "apyc.hn"
    { YYCTLPA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval));  yyv_call = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval); }
    break;

  case 27:

/* Line 895 of glr.c  */
#line 415 "apyc.hn"
    { YYCTLPA(((*yyvalp)),0,3,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (3))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (3))].yystate.yysemantics.yysval).ignore(); yyv_primary = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval); yyv_identifier = (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval);yylhs = YYMAKE_TREE(ATTRIBUTEREF, yylhs.all_values ()); }
    break;

  case 28:

/* Line 895 of glr.c  */
#line 419 "apyc.hn"
    { YYCTLPA(((*yyvalp)),0,4,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (4))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (4))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (4))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((4) - (4))].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (4))].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL ((4) - (4))].yystate.yysemantics.yysval).ignore(); yyv_primary = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (4))].yystate.yysemantics.yysval); yyv_expression_or_list = (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (4))].yystate.yysemantics.yysval);yylhs = YYMAKE_TREE (SUBSCRIPTION, yyv_primary.value (),
                           yyv_expression_or_list.value (), 
                           make_id ("__getitem__", yyv_expression_or_list.loc ())); }
    break;

  case 29:

/* Line 895 of glr.c  */
#line 426 "apyc.hn"
    { YYCTLPA(((*yyvalp)),0,6,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (6))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (6))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (6))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((4) - (6))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((5) - (6))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((6) - (6))].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (6))].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL ((4) - (6))].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL ((6) - (6))].yystate.yysemantics.yysval).ignore(); yyv_primary = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (6))].yystate.yysemantics.yysval); yyv_left = (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (6))].yystate.yysemantics.yysval); yyv_bound = (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (6))].yystate.yysemantics.yysval); yyv_right = (((yyGLRStackItem const *)yyvsp)[YYFILL ((5) - (6))].yystate.yysemantics.yysval); yyv_bound = (((yyGLRStackItem const *)yyvsp)[YYFILL ((5) - (6))].yystate.yysemantics.yysval);yylhs = YYMAKE_TREE (SLICING, yyv_primary.value (), 
                           yyv_left.value (), yyv_right.value (), 
                           make_id ("__getslice__", yyv_left.loc ())); }
    break;

  case 30:

/* Line 895 of glr.c  */
#line 432 "apyc.hn"
    { YYCTLPA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval));  yyv_expression = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval); }
    break;

  case 31:

/* Line 895 of glr.c  */
#line 433 "apyc.hn"
    { YYCTLPA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval));  yyv_empty = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval); }
    break;

  case 32:

/* Line 895 of glr.c  */
#line 437 "apyc.hn"
    { YYCTLPA(((*yyvalp)),0,4,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (4))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (4))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (4))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((4) - (4))].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (4))].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL ((4) - (4))].yystate.yysemantics.yysval).ignore(); yyv_primary = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (4))].yystate.yysemantics.yysval); yyv_argument_list = (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (4))].yystate.yysemantics.yysval);yylhs = YYMAKE_TREE(CALL, yylhs.all_values ()); }
    break;

  case 33:

/* Line 895 of glr.c  */
#line 439 "apyc.hn"
    { YYCTLPA(((*yyvalp)),0,4,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (4))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (4))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (4))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((4) - (4))].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (4))].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL ((4) - (4))].yystate.yysemantics.yysval).ignore(); yyv_parameterized_type = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (4))].yystate.yysemantics.yysval); yyv_argument_list = (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (4))].yystate.yysemantics.yysval);yylhs = YYMAKE_TREE(CALL, yylhs.all_values ()); }
    break;

  case 34:

/* Line 895 of glr.c  */
#line 444 "apyc.hn"
    { YYCTLA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval)); yylhs = YYMAKE_TREE(EXPR_LIST, yylhs.all_values ()); }
    break;

  case 35:

/* Line 895 of glr.c  */
#line 448 "apyc.hn"
    { YYCTLPA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval));  yyv_conditional_expression = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval); }
    break;

  case 36:

/* Line 895 of glr.c  */
#line 453 "apyc.hn"
    { YYCTLPA(((*yyvalp)),0,5,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (5))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (5))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (5))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((4) - (5))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((5) - (5))].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (5))].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL ((4) - (5))].yystate.yysemantics.yysval).ignore(); yyv_thenpart = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (5))].yystate.yysemantics.yysval); yyv_expr1 = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (5))].yystate.yysemantics.yysval); yyv_cond = (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (5))].yystate.yysemantics.yysval); yyv_expr1 = (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (5))].yystate.yysemantics.yysval); yyv_elsepart = (((yyGLRStackItem const *)yyvsp)[YYFILL ((5) - (5))].yystate.yysemantics.yysval); yyv_expression = (((yyGLRStackItem const *)yyvsp)[YYFILL ((5) - (5))].yystate.yysemantics.yysval);yylhs = YYMAKE_TREE(IF_EXPR, yyv_cond.value(), yyv_thenpart.value (), 
                          yyv_elsepart.value ()); }
    break;

  case 37:

/* Line 895 of glr.c  */
#line 456 "apyc.hn"
    { YYCTLPA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval));  yyv_expr1 = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval); }
    break;

  case 38:

/* Line 895 of glr.c  */
#line 461 "apyc.hn"
    { YYCTLPA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval));  yyv_expr2 = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval); }
    break;

  case 39:

/* Line 895 of glr.c  */
#line 462 "apyc.hn"
    { YYCTLPA(((*yyvalp)),0,3,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (3))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (3))].yystate.yysemantics.yysval).mark_tree_op (); yyv_expr1 = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval); yyv_expr1 = (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval); }
    break;

  case 40:

/* Line 895 of glr.c  */
#line 462 "apyc.hn"
    { YYCTLPA(((*yyvalp)),0,3,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (3))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (3))].yystate.yysemantics.yysval).mark_tree_op (); yyv_expr1 = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval); yyv_expr1 = (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval); }
    break;

  case 41:

/* Line 895 of glr.c  */
#line 464 "apyc.hn"
    { YYCTLPA(((*yyvalp)),0,2,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (2))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (2))].yystate.yysemantics.yysval));  yyv_expr1 = (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (2))].yystate.yysemantics.yysval);yylhs = make_unop (yylhs.all_values ()); }
    break;

  case 42:

/* Line 895 of glr.c  */
#line 469 "apyc.hn"
    { YYCTLA(((*yyvalp)),0,2,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (2))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (2))].yystate.yysemantics.yysval)); yylhs = YYMAKE_TREE(EXPR_LIST, yylhs.all_values ()); }
    break;

  case 43:

/* Line 895 of glr.c  */
#line 474 "apyc.hn"
    { YYCTLA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval)); yylhs = YYMAKE_TREE(EXPR_LIST, yylhs.all_values ()); }
    break;

  case 44:

/* Line 895 of glr.c  */
#line 478 "apyc.hn"
    { YYCTLPA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval));  yyv_expression = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval); }
    break;

  case 45:

/* Line 895 of glr.c  */
#line 480 "apyc.hn"
    { YYCTLA(((*yyvalp)),0,2,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (2))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (2))].yystate.yysemantics.yysval)); yylhs = YYMAKE_TREE(TUPLE, yylhs.all_values ()); }
    break;

  case 46:

/* Line 895 of glr.c  */
#line 484 "apyc.hn"
    { YYCTLPA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval));  yyv_expression_or_list = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval); }
    break;

  case 47:

/* Line 895 of glr.c  */
#line 485 "apyc.hn"
    { YYCTLPA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval));  yyv_empty = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval); }
    break;

  case 48:

/* Line 895 of glr.c  */
#line 490 "apyc.hn"
    { YYCTLA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval)); yylhs = make_id(yylhs.all_values ()); }
    break;

  case 49:

/* Line 895 of glr.c  */
#line 492 "apyc.hn"
    { YYCTLPA(((*yyvalp)),0,2,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (2))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (2))].yystate.yysemantics.yysval));  yyv_op = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (2))].yystate.yysemantics.yysval);yylhs = make_id("isnot", yyv_op.loc()); }
    break;

  case 50:

/* Line 895 of glr.c  */
#line 494 "apyc.hn"
    { YYCTLPA(((*yyvalp)),0,2,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (2))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (2))].yystate.yysemantics.yysval));  yyv_op = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (2))].yystate.yysemantics.yysval);yylhs = make_id("notin", yyv_op.loc()); }
    break;

  case 51:

/* Line 895 of glr.c  */
#line 499 "apyc.hn"
    { YYCTLPA(((*yyvalp)),0,3,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (3))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval));  yyv_left_compare = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval); yyv_comp_operator = (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (3))].yystate.yysemantics.yysval); yyv_expr3 = (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval);yylhs = YYMAKE_TREE(COMPARE, yylhs.all_values ()); }
    break;

  case 52:

/* Line 895 of glr.c  */
#line 501 "apyc.hn"
    { YYCTLPA(((*yyvalp)),0,3,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (3))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval));  yyv_expr3 = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval); yyv_comp_operator = (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (3))].yystate.yysemantics.yysval); yyv_expr3 = (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval);yylhs = YYMAKE_TREE(COMPARE, yylhs.all_values ()); }
    break;

  case 53:

/* Line 895 of glr.c  */
#line 502 "apyc.hn"
    { YYCTLPA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval));  yyv_expr3 = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval); }
    break;

  case 54:

/* Line 895 of glr.c  */
#line 507 "apyc.hn"
    { YYCTLPA(((*yyvalp)),0,3,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (3))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval));  yyv_expr3 = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval); yyv_comp_operator = (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (3))].yystate.yysemantics.yysval); yyv_expr3 = (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval);yylhs = YYMAKE_TREE(LEFT_COMPARE, yylhs.all_values ()); }
    break;

  case 55:

/* Line 895 of glr.c  */
#line 509 "apyc.hn"
    { YYCTLPA(((*yyvalp)),0,3,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (3))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval));  yyv_left_compare = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval); yyv_comp_operator = (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (3))].yystate.yysemantics.yysval); yyv_expr3 = (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval);yylhs = YYMAKE_TREE(LEFT_COMPARE, yylhs.all_values ()); }
    break;

  case 56:

/* Line 895 of glr.c  */
#line 513 "apyc.hn"
    { YYCTLPA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval));  yyv_primary = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval); }
    break;

  case 57:

/* Line 895 of glr.c  */
#line 515 "apyc.hn"
    { YYCTLPA(((*yyvalp)),0,2,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (2))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (2))].yystate.yysemantics.yysval));  yyv_expr3 = (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (2))].yystate.yysemantics.yysval);yylhs = make_unop (yylhs.all_values ()); }
    break;

  case 58:

/* Line 895 of glr.c  */
#line 517 "apyc.hn"
    { YYCTLPA(((*yyvalp)),0,2,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (2))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (2))].yystate.yysemantics.yysval));  yyv_expr3 = (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (2))].yystate.yysemantics.yysval);yylhs = make_unop (yylhs.all_values ()); }
    break;

  case 59:

/* Line 895 of glr.c  */
#line 520 "apyc.hn"
    { YYCTLPA(((*yyvalp)),0,3,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (3))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval));  yyv_expr3 = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval); yyv_expr3 = (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval);yylhs = make_binop (yylhs.all_values ()); }
    break;

  case 60:

/* Line 895 of glr.c  */
#line 520 "apyc.hn"
    { YYCTLPA(((*yyvalp)),0,3,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (3))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval));  yyv_expr3 = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval); yyv_expr3 = (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval);yylhs = make_binop (yylhs.all_values ()); }
    break;

  case 61:

/* Line 895 of glr.c  */
#line 520 "apyc.hn"
    { YYCTLPA(((*yyvalp)),0,3,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (3))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval));  yyv_expr3 = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval); yyv_expr3 = (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval);yylhs = make_binop (yylhs.all_values ()); }
    break;

  case 62:

/* Line 895 of glr.c  */
#line 520 "apyc.hn"
    { YYCTLPA(((*yyvalp)),0,3,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (3))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval));  yyv_expr3 = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval); yyv_expr3 = (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval);yylhs = make_binop (yylhs.all_values ()); }
    break;

  case 63:

/* Line 895 of glr.c  */
#line 520 "apyc.hn"
    { YYCTLPA(((*yyvalp)),0,3,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (3))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval));  yyv_expr3 = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval); yyv_expr3 = (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval);yylhs = make_binop (yylhs.all_values ()); }
    break;

  case 64:

/* Line 895 of glr.c  */
#line 520 "apyc.hn"
    { YYCTLPA(((*yyvalp)),0,3,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (3))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval));  yyv_expr3 = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval); yyv_expr3 = (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval);yylhs = make_binop (yylhs.all_values ()); }
    break;

  case 65:

/* Line 895 of glr.c  */
#line 520 "apyc.hn"
    { YYCTLPA(((*yyvalp)),0,3,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (3))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval));  yyv_expr3 = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval); yyv_expr3 = (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval);yylhs = make_binop (yylhs.all_values ()); }
    break;

  case 66:

/* Line 895 of glr.c  */
#line 525 "apyc.hn"
    { YYCTLPA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval));  yyv_expression_stmt = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval); }
    break;

  case 67:

/* Line 895 of glr.c  */
#line 526 "apyc.hn"
    { YYCTLPA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval));  yyv_assignment_stmt = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval); }
    break;

  case 68:

/* Line 895 of glr.c  */
#line 527 "apyc.hn"
    { YYCTLPA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval));  yyv_pass_stmt = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval); }
    break;

  case 69:

/* Line 895 of glr.c  */
#line 528 "apyc.hn"
    { YYCTLPA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval));  yyv_print_stmt = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval); }
    break;

  case 70:

/* Line 895 of glr.c  */
#line 529 "apyc.hn"
    { YYCTLPA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval));  yyv_return_stmt = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval); }
    break;

  case 71:

/* Line 895 of glr.c  */
#line 530 "apyc.hn"
    { YYCTLPA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval));  yyv_break_stmt = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval); }
    break;

  case 72:

/* Line 895 of glr.c  */
#line 531 "apyc.hn"
    { YYCTLPA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval));  yyv_continue_stmt = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval); }
    break;

  case 73:

/* Line 895 of glr.c  */
#line 534 "apyc.hn"
    { YYCTLPA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval));  yyv_expression_or_list = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval); }
    break;

  case 74:

/* Line 895 of glr.c  */
#line 539 "apyc.hn"
    { YYCTLPA(((*yyvalp)),0,3,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (3))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (3))].yystate.yysemantics.yysval).ignore(); yyv_target_list = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval); yyv_expression_or_list = (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval);yylhs = YYMAKE_TREE (ASSIGN, yylhs.all_values ()); }
    break;

  case 75:

/* Line 895 of glr.c  */
#line 541 "apyc.hn"
    { YYCTLPA(((*yyvalp)),0,3,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (3))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (3))].yystate.yysemantics.yysval).ignore(); yyv_target_list = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval); yyv_assignment_stmt = (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval);yylhs = YYMAKE_TREE (ASSIGN, yylhs.all_values ()); }
    break;

  case 76:

/* Line 895 of glr.c  */
#line 545 "apyc.hn"
    { YYCTLPA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval));  yyv_target = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval); }
    break;

  case 77:

/* Line 895 of glr.c  */
#line 546 "apyc.hn"
    { YYCTLPA(((*yyvalp)),0,3,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (3))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval).ignore(); yyv_target = (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (3))].yystate.yysemantics.yysval); }
    break;

  case 78:

/* Line 895 of glr.c  */
#line 547 "apyc.hn"
    { YYCTLPA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval));  yyv_target_list1 = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval); }
    break;

  case 79:

/* Line 895 of glr.c  */
#line 548 "apyc.hn"
    { YYCTLPA(((*yyvalp)),0,3,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (3))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval).ignore(); yyv_target_list1 = (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (3))].yystate.yysemantics.yysval); }
    break;

  case 80:

/* Line 895 of glr.c  */
#line 549 "apyc.hn"
    { YYCTLPA(((*yyvalp)),0,3,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (3))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval).ignore(); yyv_target_list1 = (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (3))].yystate.yysemantics.yysval); }
    break;

  case 81:

/* Line 895 of glr.c  */
#line 551 "apyc.hn"
    { YYCTLPA(((*yyvalp)),0,3,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (3))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval).ignore(); yyv_target = (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (3))].yystate.yysemantics.yysval);yylhs = YYMAKE_TREE (TARGET_LIST, yylhs.all_values ()); }
    break;

  case 82:

/* Line 895 of glr.c  */
#line 556 "apyc.hn"
    { YYCTLPA(((*yyvalp)),0,0);  }
    break;

  case 83:

/* Line 895 of glr.c  */
#line 556 "apyc.hn"
    { YYCTLA(((*yyvalp)),0,3,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (3))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval)); yylhs = YYMAKE_TREE(TARGET_LIST, yylhs.all_values ()); }
    break;

  case 84:

/* Line 895 of glr.c  */
#line 558 "apyc.hn"
    { YYCTLPA(((*yyvalp)),0,2,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (2))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (2))].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (2))].yystate.yysemantics.yysval).ignore(); yyv_target = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (2))].yystate.yysemantics.yysval);yylhs = YYMAKE_TREE(TARGET_LIST, yyv_target.value ()); }
    break;

  case 85:

/* Line 895 of glr.c  */
#line 562 "apyc.hn"
    { YYCTLPA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval));  yyv_identifier = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval); }
    break;

  case 86:

/* Line 895 of glr.c  */
#line 564 "apyc.hn"
    { YYCTLPA(((*yyvalp)),0,2,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (2))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (2))].yystate.yysemantics.yysval));  yyv_identifier = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (2))].yystate.yysemantics.yysval); yyv_type_annotation = (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (2))].yystate.yysemantics.yysval);yylhs = YYMAKE_TREE(TYPED_ID, yylhs.all_values ()); }
    break;

  case 87:

/* Line 895 of glr.c  */
#line 565 "apyc.hn"
    { YYCTLPA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval));  yyv_attributeref = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval); }
    break;

  case 88:

/* Line 895 of glr.c  */
#line 566 "apyc.hn"
    { YYCTLPA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval));  yyv_subscription = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval); }
    break;

  case 89:

/* Line 895 of glr.c  */
#line 567 "apyc.hn"
    { YYCTLPA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval));  yyv_slicing = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval); }
    break;

  case 90:

/* Line 895 of glr.c  */
#line 571 "apyc.hn"
    { YYCTLPA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval).ignore();yylhs = YYMAKE_TREE(STMT_LIST); }
    break;

  case 91:

/* Line 895 of glr.c  */
#line 576 "apyc.hn"
    { YYCTLPA(((*yyvalp)),0,3,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (3))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval).ignore(); yyv_empty = (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (3))].yystate.yysemantics.yysval); yyv_expression_list0_no_comma = (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval);yylhs = YYMAKE_TREE(PRINTLN, yylhs.all_values ()); }
    break;

  case 92:

/* Line 895 of glr.c  */
#line 578 "apyc.hn"
    { YYCTLPA(((*yyvalp)),0,3,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (3))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (3))].yystate.yysemantics.yysval).ignore(); yyv_expression = (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval);yylhs = YYMAKE_TREE(PRINTLN, yyv_expression.value (), YYMAKE_TREE(EXPR_LIST)); }
    break;

  case 93:

/* Line 895 of glr.c  */
#line 580 "apyc.hn"
    { YYCTLPA(((*yyvalp)),0,5,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (5))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (5))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (5))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((4) - (5))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((5) - (5))].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (5))].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (5))].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL ((4) - (5))].yystate.yysemantics.yysval).ignore(); yyv_expression = (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (5))].yystate.yysemantics.yysval); yyv_expression_list_no_comma = (((yyGLRStackItem const *)yyvsp)[YYFILL ((5) - (5))].yystate.yysemantics.yysval);yylhs = YYMAKE_TREE(PRINTLN, yylhs.all_values ()); }
    break;

  case 94:

/* Line 895 of glr.c  */
#line 582 "apyc.hn"
    { YYCTLPA(((*yyvalp)),0,4,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (4))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (4))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (4))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((4) - (4))].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (4))].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL ((4) - (4))].yystate.yysemantics.yysval).ignore(); yyv_empty = (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (4))].yystate.yysemantics.yysval); yyv_expression_list_no_comma = (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (4))].yystate.yysemantics.yysval);yylhs = YYMAKE_TREE(PRINT, yylhs.all_values ()); }
    break;

  case 95:

/* Line 895 of glr.c  */
#line 584 "apyc.hn"
    { YYCTLPA(((*yyvalp)),0,6,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (6))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (6))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (6))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((4) - (6))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((5) - (6))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((6) - (6))].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (6))].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (6))].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL ((4) - (6))].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL ((6) - (6))].yystate.yysemantics.yysval).ignore(); yyv_expression = (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (6))].yystate.yysemantics.yysval); yyv_expression_list_no_comma = (((yyGLRStackItem const *)yyvsp)[YYFILL ((5) - (6))].yystate.yysemantics.yysval);yylhs = YYMAKE_TREE(PRINT, yylhs.all_values ()); }
    break;

  case 96:

/* Line 895 of glr.c  */
#line 588 "apyc.hn"
    { YYCTLPA(((*yyvalp)),0,2,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (2))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (2))].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (2))].yystate.yysemantics.yysval).mark_tree_op (); yyv_expression_or_list0 = (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (2))].yystate.yysemantics.yysval);check_in_func (); }
    break;

  case 97:

/* Line 895 of glr.c  */
#line 591 "apyc.hn"
    { YYCTLPA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval).mark_tree_op ();check_in_loop (); }
    break;

  case 98:

/* Line 895 of glr.c  */
#line 594 "apyc.hn"
    { YYCTLPA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval).mark_tree_op ();check_in_loop (); }
    break;

  case 99:

/* Line 895 of glr.c  */
#line 598 "apyc.hn"
    { YYCTLPA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval));  yyv_if_stmt = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval); }
    break;

  case 100:

/* Line 895 of glr.c  */
#line 599 "apyc.hn"
    { YYCTLPA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval));  yyv_while_stmt = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval); }
    break;

  case 101:

/* Line 895 of glr.c  */
#line 600 "apyc.hn"
    { YYCTLPA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval));  yyv_for_stmt = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval); }
    break;

  case 102:

/* Line 895 of glr.c  */
#line 601 "apyc.hn"
    { YYCTLPA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval));  yyv_funcdef = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval); }
    break;

  case 103:

/* Line 895 of glr.c  */
#line 602 "apyc.hn"
    { YYCTLPA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval));  yyv_classdef = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval); }
    break;

  case 104:

/* Line 895 of glr.c  */
#line 606 "apyc.hn"
    { YYCTLPA(((*yyvalp)),0,2,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (2))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (2))].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (2))].yystate.yysemantics.yysval).ignore(); yyv_stmt_list = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (2))].yystate.yysemantics.yysval); yyv_NEWLINE = (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (2))].yystate.yysemantics.yysval); }
    break;

  case 105:

/* Line 895 of glr.c  */
#line 607 "apyc.hn"
    { YYCTLA(((*yyvalp)),0,4,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (4))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (4))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (4))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((4) - (4))].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (4))].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (4))].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL ((4) - (4))].yystate.yysemantics.yysval).ignore(); yyv_DEDENT = (((yyGLRStackItem const *)yyvsp)[YYFILL ((4) - (4))].yystate.yysemantics.yysval); }
    break;

  case 106:

/* Line 895 of glr.c  */
#line 608 "apyc.hn"
    { YYCTLPA(((*yyvalp)),0,2,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (2))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (2))].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (2))].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (2))].yystate.yysemantics.yysval).ignore(); yyv_NEWLINE = (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (2))].yystate.yysemantics.yysval); }
    break;

  case 107:

/* Line 895 of glr.c  */
#line 609 "apyc.hn"
    { YYCTLPA(((*yyvalp)),0,4,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (4))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (4))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (4))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((4) - (4))].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (4))].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (4))].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (4))].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL ((4) - (4))].yystate.yysemantics.yysval).ignore(); yyv_NEWLINE = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (4))].yystate.yysemantics.yysval); yyv_INDENT = (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (4))].yystate.yysemantics.yysval); yyv_DEDENT = (((yyGLRStackItem const *)yyvsp)[YYFILL ((4) - (4))].yystate.yysemantics.yysval); }
    break;

  case 108:

/* Line 895 of glr.c  */
#line 613 "apyc.hn"
    { YYCTLPA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval));  yyv_stmts = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval);yylhs = YYMAKE_TREE(STMT_LIST, yylhs.all_values ()); }
    break;

  case 109:

/* Line 895 of glr.c  */
#line 616 "apyc.hn"
    { YYCTLPA(((*yyvalp)),0,2,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (2))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (2))].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (2))].yystate.yysemantics.yysval).ignore(); yyv_stmt_list = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (2))].yystate.yysemantics.yysval); yyv_NEWLINE = (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (2))].yystate.yysemantics.yysval); }
    break;

  case 110:

/* Line 895 of glr.c  */
#line 616 "apyc.hn"
    { YYCTLPA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval));  yyv_compound_stmt = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval); }
    break;

  case 111:

/* Line 895 of glr.c  */
#line 620 "apyc.hn"
    { YYCTLA(((*yyvalp)),0,3,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (3))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval));  }
    break;

  case 112:

/* Line 895 of glr.c  */
#line 625 "apyc.hn"
    { YYCTLP(((*yyvalp)), 0, 0);  yyv_expression = (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (3))].yystate.yysemantics.yysval);incr (control_depth); }
    break;

  case 113:

/* Line 895 of glr.c  */
#line 628 "apyc.hn"
    { YYCTLA(((*yyvalp)),0,6,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (6))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (6))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (6))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((4) - (6))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((5) - (6))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((6) - (6))].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (6))].yystate.yysemantics.yysval).mark_tree_op (); (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (6))].yystate.yysemantics.yysval).ignore(); yyv_suite = (((yyGLRStackItem const *)yyvsp)[YYFILL ((5) - (6))].yystate.yysemantics.yysval); yyv_elifs = (((yyGLRStackItem const *)yyvsp)[YYFILL ((6) - (6))].yystate.yysemantics.yysval);decr (control_depth); }
    break;

  case 114:

/* Line 895 of glr.c  */
#line 633 "apyc.hn"
    { YYCTLPA(((*yyvalp)),0,5,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (5))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (5))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (5))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((4) - (5))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((5) - (5))].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (5))].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (5))].yystate.yysemantics.yysval).ignore(); yyv_expression = (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (5))].yystate.yysemantics.yysval); yyv_suite = (((yyGLRStackItem const *)yyvsp)[YYFILL ((4) - (5))].yystate.yysemantics.yysval); yyv_elifs = (((yyGLRStackItem const *)yyvsp)[YYFILL ((5) - (5))].yystate.yysemantics.yysval);yylhs = YYMAKE_TREE (IF, yylhs.all_values ()); }
    break;

  case 115:

/* Line 895 of glr.c  */
#line 634 "apyc.hn"
    { YYCTLPA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval));  yyv_else_clause = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval); }
    break;

  case 116:

/* Line 895 of glr.c  */
#line 639 "apyc.hn"
    { YYCTLPA(((*yyvalp)),0,0); yylhs = YYMAKE_TREE(STMT_LIST); }
    break;

  case 117:

/* Line 895 of glr.c  */
#line 640 "apyc.hn"
    { YYCTLPA(((*yyvalp)),0,3,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (3))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (3))].yystate.yysemantics.yysval).ignore(); yyv_suite = (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval); }
    break;

  case 118:

/* Line 895 of glr.c  */
#line 645 "apyc.hn"
    { YYCTLP(((*yyvalp)), 0, 0);  yyv_expression = (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (3))].yystate.yysemantics.yysval);incr (control_depth); incr (loop_depth); }
    break;

  case 119:

/* Line 895 of glr.c  */
#line 647 "apyc.hn"
    { YYCTL(((*yyvalp)), 0, 0);  yyv_suite = (((yyGLRStackItem const *)yyvsp)[YYFILL ((5) - (5))].yystate.yysemantics.yysval);decr (loop_depth); }
    break;

  case 120:

/* Line 895 of glr.c  */
#line 649 "apyc.hn"
    { YYCTLA(((*yyvalp)),0,7,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (7))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (7))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (7))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((4) - (7))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((5) - (7))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((6) - (7))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((7) - (7))].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (7))].yystate.yysemantics.yysval).mark_tree_op (); (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (7))].yystate.yysemantics.yysval).ignore(); yyv_else_clause = (((yyGLRStackItem const *)yyvsp)[YYFILL ((7) - (7))].yystate.yysemantics.yysval);decr (control_depth); }
    break;

  case 121:

/* Line 895 of glr.c  */
#line 654 "apyc.hn"
    { YYCTLP(((*yyvalp)), 0, 0);  yyv_target_list = (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (5))].yystate.yysemantics.yysval); yyv_expression_or_list = (((yyGLRStackItem const *)yyvsp)[YYFILL ((4) - (5))].yystate.yysemantics.yysval);incr (control_depth); incr (loop_depth); }
    break;

  case 122:

/* Line 895 of glr.c  */
#line 656 "apyc.hn"
    { YYCTL(((*yyvalp)), 0, 0);  yyv_suite = (((yyGLRStackItem const *)yyvsp)[YYFILL ((7) - (7))].yystate.yysemantics.yysval);decr (loop_depth); }
    break;

  case 123:

/* Line 895 of glr.c  */
#line 658 "apyc.hn"
    { YYCTLA(((*yyvalp)),0,9,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (9))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (9))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (9))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((4) - (9))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((5) - (9))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((6) - (9))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((7) - (9))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((8) - (9))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((9) - (9))].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (9))].yystate.yysemantics.yysval).mark_tree_op (); (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (9))].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL ((5) - (9))].yystate.yysemantics.yysval).ignore(); yyv_else_clause = (((yyGLRStackItem const *)yyvsp)[YYFILL ((9) - (9))].yystate.yysemantics.yysval);decr (control_depth); }
    break;

  case 124:

/* Line 895 of glr.c  */
#line 663 "apyc.hn"
    { YYCTLP(((*yyvalp)), 0, 0);  yyv_funcname = (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (7))].yystate.yysemantics.yysval); yyv_parameter_list = (((yyGLRStackItem const *)yyvsp)[YYFILL ((4) - (7))].yystate.yysemantics.yysval); yyv_opt_type_annotation = (((yyGLRStackItem const *)yyvsp)[YYFILL ((6) - (7))].yystate.yysemantics.yysval);check_def_placement (); 
                  incr (defn_depth); incr (func_depth); }
    break;

  case 125:

/* Line 895 of glr.c  */
#line 666 "apyc.hn"
    { YYCTLA(((*yyvalp)),0,9,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (9))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (9))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (9))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((4) - (9))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((5) - (9))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((6) - (9))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((7) - (9))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((8) - (9))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((9) - (9))].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (9))].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (9))].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL ((5) - (9))].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL ((7) - (9))].yystate.yysemantics.yysval).ignore(); yyv_funcbody = (((yyGLRStackItem const *)yyvsp)[YYFILL ((9) - (9))].yystate.yysemantics.yysval);decr (defn_depth); decr (func_depth); 
		  if (func_depth != 0 || defn_depth != 1)
		      yylhs = YYMAKE_TREE (DEF, yylhs.all_values ()); 
		  else
		      yylhs = YYMAKE_TREE (METHOD, yylhs.all_values ()); }
    break;

  case 126:

/* Line 895 of glr.c  */
#line 676 "apyc.hn"
    { YYCTLPA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval));  yyv_stmts = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval);yylhs = YYMAKE_TREE(BLOCK, yylhs.all_values ()); }
    break;

  case 127:

/* Line 895 of glr.c  */
#line 677 "apyc.hn"
    { YYCTLPA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval));  yyv_native = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval);yylhs = YYMAKE_TREE(BLOCK, yylhs.all_values ()); }
    break;

  case 128:

/* Line 895 of glr.c  */
#line 679 "apyc.hn"
    { YYCTLPA(((*yyvalp)),0,4,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (4))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (4))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (4))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((4) - (4))].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (4))].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (4))].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL ((4) - (4))].yystate.yysemantics.yysval).ignore(); yyv_NEWLINE = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (4))].yystate.yysemantics.yysval); yyv_INDENT = (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (4))].yystate.yysemantics.yysval); yyv_native = (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (4))].yystate.yysemantics.yysval); yyv_DEDENT = (((yyGLRStackItem const *)yyvsp)[YYFILL ((4) - (4))].yystate.yysemantics.yysval);yylhs = YYMAKE_TREE(BLOCK, yylhs.all_values ()); }
    break;

  case 129:

/* Line 895 of glr.c  */
#line 683 "apyc.hn"
    { YYCTLPA(((*yyvalp)),0,3,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (3))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval).mark_tree_op (); (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval).ignore(); yyv_stringliteral = (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (3))].yystate.yysemantics.yysval); yyv_NEWLINE = (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval); }
    break;

  case 130:

/* Line 895 of glr.c  */
#line 688 "apyc.hn"
    { YYCTLPA(((*yyvalp)),0,0); yylhs = YYMAKE_TREE(FORMALS_LIST); }
    break;

  case 131:

/* Line 895 of glr.c  */
#line 690 "apyc.hn"
    { YYCTLA(((*yyvalp)),0,3,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (3))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval)); yylhs = YYMAKE_TREE(FORMALS_LIST, yylhs.all_values ()); }
    break;

  case 132:

/* Line 895 of glr.c  */
#line 694 "apyc.hn"
    { YYCTLPA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval));  yyv_identifier = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval); }
    break;

  case 133:

/* Line 895 of glr.c  */
#line 695 "apyc.hn"
    { YYCTLPA(((*yyvalp)),0,2,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (2))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (2))].yystate.yysemantics.yysval));  yyv_identifier = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (2))].yystate.yysemantics.yysval); yyv_type_annotation = (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (2))].yystate.yysemantics.yysval);yylhs = YYMAKE_TREE(TYPED_ID, yylhs.all_values ()); }
    break;

  case 134:

/* Line 895 of glr.c  */
#line 698 "apyc.hn"
    { YYCTLPA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval));  yyv_identifier = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval); }
    break;

  case 135:

/* Line 895 of glr.c  */
#line 701 "apyc.hn"
    { YYCTLP(((*yyvalp)), 0, 0);  yyv_name = (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (4))].yystate.yysemantics.yysval); yyv_identifier = (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (4))].yystate.yysemantics.yysval); yyv_type_formals = (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (4))].yystate.yysemantics.yysval);check_class_placement (); incr (defn_depth); }
    break;

  case 136:

/* Line 895 of glr.c  */
#line 703 "apyc.hn"
    { YYCTLA(((*yyvalp)),0,6,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (6))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (6))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (6))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((4) - (6))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((5) - (6))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((6) - (6))].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (6))].yystate.yysemantics.yysval).mark_tree_op (); (((yyGLRStackItem const *)yyvsp)[YYFILL ((4) - (6))].yystate.yysemantics.yysval).ignore(); yyv_classbody = (((yyGLRStackItem const *)yyvsp)[YYFILL ((6) - (6))].yystate.yysemantics.yysval);decr (defn_depth); }
    break;

  case 137:

/* Line 895 of glr.c  */
#line 708 "apyc.hn"
    { YYCTLA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval)); yylhs = YYMAKE_TREE(TYPE_FORMALS_LIST, yylhs.all_values ()); }
    break;

  case 138:

/* Line 895 of glr.c  */
#line 712 "apyc.hn"
    { YYCTLPA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval));  yyv_stmts = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval);yylhs = YYMAKE_TREE(CLASS_BLOCK, yylhs.all_values ()); }
    break;

  case 139:

/* Line 895 of glr.c  */
#line 715 "apyc.hn"
    { YYCTLPA(((*yyvalp)),0,2,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (2))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (2))].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (2))].yystate.yysemantics.yysval).ignore(); yyv_type = (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (2))].yystate.yysemantics.yysval); }
    break;

  case 140:

/* Line 895 of glr.c  */
#line 719 "apyc.hn"
    { YYCTLPA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval));  yyv_type_annotation = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval); }
    break;

  case 141:

/* Line 895 of glr.c  */
#line 720 "apyc.hn"
    { YYCTLPA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval));  yyv_empty = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval); }
    break;

  case 142:

/* Line 895 of glr.c  */
#line 724 "apyc.hn"
    { YYCTLPA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval));  yyv_parameterized_type = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval); }
    break;

  case 143:

/* Line 895 of glr.c  */
#line 726 "apyc.hn"
    { YYCTLPA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval));  yyv_identifier = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval);yylhs = YYMAKE_TREE(TYPE, yyv_identifier, YYMAKE_TREE(TYPE_LIST)); }
    break;

  case 144:

/* Line 895 of glr.c  */
#line 727 "apyc.hn"
    { YYCTLPA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval));  yyv_type_var = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval); }
    break;

  case 145:

/* Line 895 of glr.c  */
#line 729 "apyc.hn"
    { YYCTLPA(((*yyvalp)),0,5,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (5))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (5))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (5))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((4) - (5))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((5) - (5))].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (5))].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (5))].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL ((4) - (5))].yystate.yysemantics.yysval).ignore(); yyv_type_list = (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (5))].yystate.yysemantics.yysval); yyv_type = (((yyGLRStackItem const *)yyvsp)[YYFILL ((5) - (5))].yystate.yysemantics.yysval);yylhs = YYMAKE_TREE(FUNCTION_TYPE, 
                          yyv_type.value (), yyv_type_list.value ()); }
    break;

  case 146:

/* Line 895 of glr.c  */
#line 734 "apyc.hn"
    { YYCTLPA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval));  yyv_TYPE_VAR = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval);yylhs = YYMAKE_TREE(TYPE_VAR, yylhs.all_values ()); }
    break;

  case 147:

/* Line 895 of glr.c  */
#line 738 "apyc.hn"
    { YYCTLPA(((*yyvalp)),0,2,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (2))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (2))].yystate.yysemantics.yysval));  yyv_identifier = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (2))].yystate.yysemantics.yysval); yyv_type_params = (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (2))].yystate.yysemantics.yysval);yylhs = YYMAKE_TREE(TYPE, yylhs.all_values ()); }
    break;

  case 148:

/* Line 895 of glr.c  */
#line 743 "apyc.hn"
    { YYCTLA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval)); yylhs = YYMAKE_TREE(TYPE_LIST, yylhs.all_values ()); }
    break;

  case 149:

/* Line 895 of glr.c  */
#line 746 "apyc.hn"
    { YYCTLA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval)); yylhs = YYMAKE_TREE(TYPE_LIST, yylhs.all_values ()); }
    break;

  case 150:

/* Line 895 of glr.c  */
#line 751 "apyc.hn"
    { YYCTLPA(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval));  yyv_type = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval); }
    break;

  case 151:

/* Line 895 of glr.c  */
#line 752 "apyc.hn"
    { YYCTLPA(((*yyvalp)),0,3,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (3))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (3))].yystate.yysemantics.yysval).ignore(); yyv_types = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval); yyv_type = (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval); }
    break;

  case 152:

/* Line 895 of glr.c  */
#line 757 "apyc.hn"
    { YYCTLPA(((*yyvalp)),0,0); yylhs = YYMAKE_TREE(EMPTY); yylhs.set_loc (yysource_location ()); }
    break;

  case 153:

/* Line 895 of glr.c  */
#line 489 "apyc.hn"
    { YYCTLPC(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval));  }
    break;

  case 154:

/* Line 895 of glr.c  */
#line 489 "apyc.hn"
    { YYCTLPC(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval));  }
    break;

  case 155:

/* Line 895 of glr.c  */
#line 489 "apyc.hn"
    { YYCTLPC(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval));  }
    break;

  case 156:

/* Line 895 of glr.c  */
#line 489 "apyc.hn"
    { YYCTLPC(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval));  }
    break;

  case 157:

/* Line 895 of glr.c  */
#line 489 "apyc.hn"
    { YYCTLPC(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval));  }
    break;

  case 158:

/* Line 895 of glr.c  */
#line 489 "apyc.hn"
    { YYCTLPC(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval));  }
    break;

  case 159:

/* Line 895 of glr.c  */
#line 489 "apyc.hn"
    { YYCTLPC(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval));  }
    break;

  case 160:

/* Line 895 of glr.c  */
#line 489 "apyc.hn"
    { YYCTLPC(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval));  }
    break;

  case 161:

/* Line 895 of glr.c  */
#line 479 "apyc.hn"
    { YYCTLPC(((*yyvalp)),0,2,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (2))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (2))].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (2))].yystate.yysemantics.yysval).ignore(); yyv_expression = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (2))].yystate.yysemantics.yysval); }
    break;

  case 162:

/* Line 895 of glr.c  */
#line 479 "apyc.hn"
    { YYCTLC(((*yyvalp)),0,3,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (3))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval).ignore(); yyv_expression = (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (3))].yystate.yysemantics.yysval); }
    break;

  case 163:

/* Line 895 of glr.c  */
#line 607 "apyc.hn"
    { YYCTLPC(((*yyvalp)),2,3,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((-1) - (1))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((0) - (1))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval));  yyv_NEWLINE = (((yyGLRStackItem const *)yyvsp)[YYFILL ((-1) - (1))].yystate.yysemantics.yysval); yyv_INDENT = (((yyGLRStackItem const *)yyvsp)[YYFILL ((0) - (1))].yystate.yysemantics.yysval); yyv_statement = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval); }
    break;

  case 164:

/* Line 895 of glr.c  */
#line 607 "apyc.hn"
    { YYCTLC(((*yyvalp)),2,4,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((-1) - (2))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((0) - (2))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (2))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (2))].yystate.yysemantics.yysval));  yyv_statement = (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (2))].yystate.yysemantics.yysval); }
    break;

  case 165:

/* Line 895 of glr.c  */
#line 388 "apyc.hn"
    { YYCTLPC(((*yyvalp)),2,4,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((-1) - (2))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((0) - (2))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (2))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (2))].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (2))].yystate.yysemantics.yysval).ignore(); yyv_expression = (((yyGLRStackItem const *)yyvsp)[YYFILL ((0) - (2))].yystate.yysemantics.yysval); yyv_expression = (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (2))].yystate.yysemantics.yysval); }
    break;

  case 166:

/* Line 895 of glr.c  */
#line 388 "apyc.hn"
    { YYCTLC(((*yyvalp)),2,5,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((-1) - (3))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((0) - (3))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (3))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (3))].yystate.yysemantics.yysval).ignore(); yyv_expression = (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval); }
    break;

  case 167:

/* Line 895 of glr.c  */
#line 555 "apyc.hn"
    { YYCTLPC(((*yyvalp)),1,3,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((0) - (2))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (2))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (2))].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (2))].yystate.yysemantics.yysval).ignore(); yyv_target = (((yyGLRStackItem const *)yyvsp)[YYFILL ((0) - (2))].yystate.yysemantics.yysval); yyv_target = (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (2))].yystate.yysemantics.yysval); }
    break;

  case 168:

/* Line 895 of glr.c  */
#line 555 "apyc.hn"
    { YYCTLC(((*yyvalp)),1,4,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((0) - (3))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (3))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (3))].yystate.yysemantics.yysval).ignore(); yyv_target = (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval); }
    break;

  case 169:

/* Line 895 of glr.c  */
#line 388 "apyc.hn"
    { YYCTLPC(((*yyvalp)),2,3,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((-1) - (1))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((0) - (1))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval).ignore(); yyv_expression = (((yyGLRStackItem const *)yyvsp)[YYFILL ((0) - (1))].yystate.yysemantics.yysval); }
    break;

  case 170:

/* Line 895 of glr.c  */
#line 388 "apyc.hn"
    { YYCTLC(((*yyvalp)),2,4,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((-1) - (2))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((0) - (2))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (2))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (2))].yystate.yysemantics.yysval));  }
    break;

  case 171:

/* Line 895 of glr.c  */
#line 742 "apyc.hn"
    { YYCTLPC(((*yyvalp)),0,4,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (4))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (4))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (4))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((4) - (4))].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (4))].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (4))].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL ((4) - (4))].yystate.yysemantics.yysval).ignore(); yyv_types = (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (4))].yystate.yysemantics.yysval); }
    break;

  case 172:

/* Line 895 of glr.c  */
#line 742 "apyc.hn"
    { YYCTLPC(((*yyvalp)),0,2,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (2))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (2))].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (2))].yystate.yysemantics.yysval).ignore(); yyv_type = (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (2))].yystate.yysemantics.yysval); }
    break;

  case 173:

/* Line 895 of glr.c  */
#line 349 "apyc.hn"
    { YYCTLC(((*yyvalp)),1,2,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((0) - (1))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval).ignore(); yyv_NEWLINE = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval); }
    break;

  case 174:

/* Line 895 of glr.c  */
#line 349 "apyc.hn"
    { YYCTLC(((*yyvalp)),1,2,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((0) - (1))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval));  yyv_statement = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval); }
    break;

  case 175:

/* Line 895 of glr.c  */
#line 352 "apyc.hn"
    { YYCTLC(((*yyvalp)),1,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((0) - (0))].yystate.yysemantics.yysval));  }
    break;

  case 176:

/* Line 895 of glr.c  */
#line 479 "apyc.hn"
    { YYCTLC(((*yyvalp)),1,2,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((0) - (1))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval));  yyv_expression = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval); }
    break;

  case 177:

/* Line 895 of glr.c  */
#line 482 "apyc.hn"
    { YYCTLC(((*yyvalp)),2,2,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((-1) - (0))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((0) - (0))].yystate.yysemantics.yysval));  }
    break;

  case 178:

/* Line 895 of glr.c  */
#line 400 "apyc.hn"
    { YYCTLC(((*yyvalp)),2,3,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((-1) - (1))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((0) - (1))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval).ignore(); }
    break;

  case 179:

/* Line 895 of glr.c  */
#line 403 "apyc.hn"
    { YYCTLC(((*yyvalp)),2,2,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((-1) - (0))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((0) - (0))].yystate.yysemantics.yysval));  }
    break;

  case 180:

/* Line 895 of glr.c  */
#line 620 "apyc.hn"
    { YYCTLC(((*yyvalp)),2,3,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((-1) - (1))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((0) - (1))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval).ignore(); }
    break;

  case 181:

/* Line 895 of glr.c  */
#line 623 "apyc.hn"
    { YYCTLC(((*yyvalp)),2,2,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((-1) - (0))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((0) - (0))].yystate.yysemantics.yysval));  yyv_parameter = (((yyGLRStackItem const *)yyvsp)[YYFILL ((0) - (0))].yystate.yysemantics.yysval); }
    break;

  case 182:

/* Line 895 of glr.c  */
#line 689 "apyc.hn"
    { YYCTLC(((*yyvalp)),2,3,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((-1) - (1))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((0) - (1))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval).ignore(); yyv_parameter = (((yyGLRStackItem const *)yyvsp)[YYFILL ((0) - (1))].yystate.yysemantics.yysval); }
    break;

  case 183:

/* Line 895 of glr.c  */
#line 692 "apyc.hn"
    { YYCTLC(((*yyvalp)),3,3,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((-2) - (0))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((-1) - (0))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((0) - (0))].yystate.yysemantics.yysval));  }
    break;

  case 184:

/* Line 895 of glr.c  */
#line 388 "apyc.hn"
    { YYCTLC(((*yyvalp)),3,4,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((-2) - (1))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((-1) - (1))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((0) - (1))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval).ignore(); }
    break;

  case 185:

/* Line 895 of glr.c  */
#line 391 "apyc.hn"
    { YYCTLPC(((*yyvalp)),0,0);  }
    break;

  case 186:

/* Line 895 of glr.c  */
#line 689 "apyc.hn"
    { YYCTLC(((*yyvalp)),0,3,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (3))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval).ignore(); yyv_parameter = (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (3))].yystate.yysemantics.yysval); }
    break;

  case 187:

/* Line 895 of glr.c  */
#line 692 "apyc.hn"
    { YYCTLPC(((*yyvalp)),0,0);  }
    break;

  case 188:

/* Line 895 of glr.c  */
#line 349 "apyc.hn"
    { YYCTLC(((*yyvalp)),0,2,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (2))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (2))].yystate.yysemantics.yysval));  }
    break;

  case 189:

/* Line 895 of glr.c  */
#line 352 "apyc.hn"
    { YYCTLPC(((*yyvalp)),0,0);  }
    break;

  case 190:

/* Line 895 of glr.c  */
#line 442 "apyc.hn"
    { YYCTLC(((*yyvalp)),0,3,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (3))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval));  }
    break;

  case 191:

/* Line 895 of glr.c  */
#line 445 "apyc.hn"
    { YYCTLPC(((*yyvalp)),0,0);  }
    break;

  case 192:

/* Line 895 of glr.c  */
#line 473 "apyc.hn"
    { YYCTLC(((*yyvalp)),0,2,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (2))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (2))].yystate.yysemantics.yysval));  }
    break;

  case 193:

/* Line 895 of glr.c  */
#line 476 "apyc.hn"
    { YYCTLPC(((*yyvalp)),0,0);  }
    break;

  case 194:

/* Line 895 of glr.c  */
#line 747 "apyc.hn"
    { YYCTLPC(((*yyvalp)),0,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval));  yyv_types = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval); }
    break;

  case 195:

/* Line 895 of glr.c  */
#line 750 "apyc.hn"
    { YYCTLPC(((*yyvalp)),0,0);  }
    break;

  case 196:

/* Line 895 of glr.c  */
#line 707 "apyc.hn"
    { YYCTLC(((*yyvalp)),0,5,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (5))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (5))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (5))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((4) - (5))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((5) - (5))].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (5))].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (5))].yystate.yysemantics.yysval).ignore(); (((yyGLRStackItem const *)yyvsp)[YYFILL ((5) - (5))].yystate.yysemantics.yysval).ignore(); }
    break;

  case 197:

/* Line 895 of glr.c  */
#line 710 "apyc.hn"
    { YYCTLPC(((*yyvalp)),1,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((0) - (0))].yystate.yysemantics.yysval));  }
    break;

  case 198:

/* Line 895 of glr.c  */
#line 388 "apyc.hn"
    { YYCTLC(((*yyvalp)),1,3,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((0) - (2))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (2))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (2))].yystate.yysemantics.yysval));  }
    break;

  case 199:

/* Line 895 of glr.c  */
#line 391 "apyc.hn"
    { YYCTLPC(((*yyvalp)),1,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((0) - (0))].yystate.yysemantics.yysval));  }
    break;

  case 200:

/* Line 895 of glr.c  */
#line 392 "apyc.hn"
    { YYCTLC(((*yyvalp)),1,4,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((0) - (3))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (3))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval));  }
    break;

  case 201:

/* Line 895 of glr.c  */
#line 395 "apyc.hn"
    { YYCTLPC(((*yyvalp)),1,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((0) - (0))].yystate.yysemantics.yysval));  }
    break;

  case 202:

/* Line 895 of glr.c  */
#line 396 "apyc.hn"
    { YYCTLPC(((*yyvalp)),1,2,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((0) - (1))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval));  yyv_key_datum_list = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval); }
    break;

  case 203:

/* Line 895 of glr.c  */
#line 399 "apyc.hn"
    { YYCTLPC(((*yyvalp)),1,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((0) - (0))].yystate.yysemantics.yysval));  yyv_expression = (((yyGLRStackItem const *)yyvsp)[YYFILL ((0) - (0))].yystate.yysemantics.yysval); }
    break;

  case 204:

/* Line 895 of glr.c  */
#line 442 "apyc.hn"
    { YYCTLC(((*yyvalp)),1,4,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((0) - (3))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (3))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (3))].yystate.yysemantics.yysval).ignore(); yyv_expression = (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval); }
    break;

  case 205:

/* Line 895 of glr.c  */
#line 445 "apyc.hn"
    { YYCTLPC(((*yyvalp)),1,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((0) - (0))].yystate.yysemantics.yysval));  yyv_key_datum = (((yyGLRStackItem const *)yyvsp)[YYFILL ((0) - (0))].yystate.yysemantics.yysval); }
    break;

  case 206:

/* Line 895 of glr.c  */
#line 400 "apyc.hn"
    { YYCTLC(((*yyvalp)),1,4,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((0) - (3))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (3))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (3))].yystate.yysemantics.yysval).ignore(); yyv_key_datum = (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval); }
    break;

  case 207:

/* Line 895 of glr.c  */
#line 403 "apyc.hn"
    { YYCTLPC(((*yyvalp)),1,1,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((0) - (0))].yystate.yysemantics.yysval));  yyv_simple_stmt = (((yyGLRStackItem const *)yyvsp)[YYFILL ((0) - (0))].yystate.yysemantics.yysval); }
    break;

  case 208:

/* Line 895 of glr.c  */
#line 620 "apyc.hn"
    { YYCTLC(((*yyvalp)),1,4,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((0) - (3))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (3))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (3))].yystate.yysemantics.yysval).ignore(); yyv_simple_stmt = (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval); }
    break;

  case 209:

/* Line 895 of glr.c  */
#line 623 "apyc.hn"
    { YYCTLPC(((*yyvalp)),2,2,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((-1) - (0))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((0) - (0))].yystate.yysemantics.yysval));  yyv_expression = (((yyGLRStackItem const *)yyvsp)[YYFILL ((0) - (0))].yystate.yysemantics.yysval); }
    break;

  case 210:

/* Line 895 of glr.c  */
#line 392 "apyc.hn"
    { YYCTLC(((*yyvalp)),2,5,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((-1) - (3))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((0) - (3))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (3))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (3))].yystate.yysemantics.yysval).ignore(); yyv_expression = (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval); }
    break;

  case 211:

/* Line 895 of glr.c  */
#line 395 "apyc.hn"
    { YYCTLPC(((*yyvalp)),3,3,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((-2) - (0))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((-1) - (0))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((0) - (0))].yystate.yysemantics.yysval));  yyv_type_var = (((yyGLRStackItem const *)yyvsp)[YYFILL ((0) - (0))].yystate.yysemantics.yysval); }
    break;

  case 212:

/* Line 895 of glr.c  */
#line 707 "apyc.hn"
    { YYCTLC(((*yyvalp)),3,6,&(((yyGLRStackItem const *)yyvsp)[YYFILL ((-2) - (3))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((-1) - (3))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((0) - (3))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (3))].yystate.yysemantics.yysval),&(((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval));  (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (3))].yystate.yysemantics.yysval).ignore(); yyv_type_var = (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval); }
    break;

  case 213:

/* Line 895 of glr.c  */
#line 712 "apyc.hn"
    { ((*yyvalp))._clear (); }
    break;



/* Line 895 of glr.c  */
#line 3070 "apyc-parser.cc"
      default: break;
    }

  return yyok;
# undef yyerrok
# undef YYABORT
# undef YYACCEPT
# undef YYERROR
# undef YYBACKUP
# undef yyclearin
# undef YYRECOVERING
}


/*ARGSUSED*/ static void
yyuserMerge (int yyn, YYSTYPE* yy0, YYSTYPE* yy1)
{
  YYUSE (yy0);
  YYUSE (yy1);

  switch (yyn)
    {
      
      default: break;
    }
}

                              /* Bison grammar-table manipulation.  */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {
      case 3: /* "INT" */

/* Line 925 of glr.c  */
#line 262 "apyc-parser.y"
	{ (*yyvaluep)._destructor (); };

/* Line 925 of glr.c  */
#line 3123 "apyc-parser.cc"
	break;
      case 4: /* "STRING" */

/* Line 925 of glr.c  */
#line 262 "apyc-parser.y"
	{ (*yyvaluep)._destructor (); };

/* Line 925 of glr.c  */
#line 3132 "apyc-parser.cc"
	break;
      case 5: /* "ID" */

/* Line 925 of glr.c  */
#line 262 "apyc-parser.y"
	{ (*yyvaluep)._destructor (); };

/* Line 925 of glr.c  */
#line 3141 "apyc-parser.cc"
	break;
      case 6: /* "\"@unop\"" */

/* Line 925 of glr.c  */
#line 262 "apyc-parser.y"
	{ (*yyvaluep)._destructor (); };

/* Line 925 of glr.c  */
#line 3150 "apyc-parser.cc"
	break;
      case 7: /* "\"//\"" */

/* Line 925 of glr.c  */
#line 262 "apyc-parser.y"
	{ (*yyvaluep)._destructor (); };

/* Line 925 of glr.c  */
#line 3159 "apyc-parser.cc"
	break;
      case 8: /* "\"**\"" */

/* Line 925 of glr.c  */
#line 262 "apyc-parser.y"
	{ (*yyvaluep)._destructor (); };

/* Line 925 of glr.c  */
#line 3168 "apyc-parser.cc"
	break;
      case 9: /* "\"and\"" */

/* Line 925 of glr.c  */
#line 262 "apyc-parser.y"
	{ (*yyvaluep)._destructor (); };

/* Line 925 of glr.c  */
#line 3177 "apyc-parser.cc"
	break;
      case 10: /* "\"@assign\"" */

/* Line 925 of glr.c  */
#line 262 "apyc-parser.y"
	{ (*yyvaluep)._destructor (); };

/* Line 925 of glr.c  */
#line 3186 "apyc-parser.cc"
	break;
      case 11: /* "\"@attributeref\"" */

/* Line 925 of glr.c  */
#line 262 "apyc-parser.y"
	{ (*yyvaluep)._destructor (); };

/* Line 925 of glr.c  */
#line 3195 "apyc-parser.cc"
	break;
      case 12: /* "\"@binop\"" */

/* Line 925 of glr.c  */
#line 262 "apyc-parser.y"
	{ (*yyvaluep)._destructor (); };

/* Line 925 of glr.c  */
#line 3204 "apyc-parser.cc"
	break;
      case 13: /* "\"@block\"" */

/* Line 925 of glr.c  */
#line 262 "apyc-parser.y"
	{ (*yyvaluep)._destructor (); };

/* Line 925 of glr.c  */
#line 3213 "apyc-parser.cc"
	break;
      case 14: /* "\"break\"" */

/* Line 925 of glr.c  */
#line 262 "apyc-parser.y"
	{ (*yyvaluep)._destructor (); };

/* Line 925 of glr.c  */
#line 3222 "apyc-parser.cc"
	break;
      case 15: /* "\"@call\"" */

/* Line 925 of glr.c  */
#line 262 "apyc-parser.y"
	{ (*yyvaluep)._destructor (); };

/* Line 925 of glr.c  */
#line 3231 "apyc-parser.cc"
	break;
      case 16: /* "\"@@block\"" */

/* Line 925 of glr.c  */
#line 262 "apyc-parser.y"
	{ (*yyvaluep)._destructor (); };

/* Line 925 of glr.c  */
#line 3240 "apyc-parser.cc"
	break;
      case 17: /* "\"@compare\"" */

/* Line 925 of glr.c  */
#line 262 "apyc-parser.y"
	{ (*yyvaluep)._destructor (); };

/* Line 925 of glr.c  */
#line 3249 "apyc-parser.cc"
	break;
      case 18: /* "\"@left_compare\"" */

/* Line 925 of glr.c  */
#line 262 "apyc-parser.y"
	{ (*yyvaluep)._destructor (); };

/* Line 925 of glr.c  */
#line 3258 "apyc-parser.cc"
	break;
      case 19: /* "\"continue\"" */

/* Line 925 of glr.c  */
#line 262 "apyc-parser.y"
	{ (*yyvaluep)._destructor (); };

/* Line 925 of glr.c  */
#line 3267 "apyc-parser.cc"
	break;
      case 20: /* "DEDENT" */

/* Line 925 of glr.c  */
#line 262 "apyc-parser.y"
	{ (*yyvaluep)._destructor (); };

/* Line 925 of glr.c  */
#line 3276 "apyc-parser.cc"
	break;
      case 21: /* "\"def\"" */

/* Line 925 of glr.c  */
#line 262 "apyc-parser.y"
	{ (*yyvaluep)._destructor (); };

/* Line 925 of glr.c  */
#line 3285 "apyc-parser.cc"
	break;
      case 22: /* "\"@dict_display\"" */

/* Line 925 of glr.c  */
#line 262 "apyc-parser.y"
	{ (*yyvaluep)._destructor (); };

/* Line 925 of glr.c  */
#line 3294 "apyc-parser.cc"
	break;
      case 23: /* "EMPTY" */

/* Line 925 of glr.c  */
#line 262 "apyc-parser.y"
	{ (*yyvaluep)._destructor (); };

/* Line 925 of glr.c  */
#line 3303 "apyc-parser.cc"
	break;
      case 24: /* "\"@expr_list\"" */

/* Line 925 of glr.c  */
#line 262 "apyc-parser.y"
	{ (*yyvaluep)._destructor (); };

/* Line 925 of glr.c  */
#line 3312 "apyc-parser.cc"
	break;
      case 25: /* "\"for\"" */

/* Line 925 of glr.c  */
#line 262 "apyc-parser.y"
	{ (*yyvaluep)._destructor (); };

/* Line 925 of glr.c  */
#line 3321 "apyc-parser.cc"
	break;
      case 26: /* "\"@formals_list\"" */

/* Line 925 of glr.c  */
#line 262 "apyc-parser.y"
	{ (*yyvaluep)._destructor (); };

/* Line 925 of glr.c  */
#line 3330 "apyc-parser.cc"
	break;
      case 27: /* "\"@function_type\"" */

/* Line 925 of glr.c  */
#line 262 "apyc-parser.y"
	{ (*yyvaluep)._destructor (); };

/* Line 925 of glr.c  */
#line 3339 "apyc-parser.cc"
	break;
      case 28: /* "\"if\"" */

/* Line 925 of glr.c  */
#line 262 "apyc-parser.y"
	{ (*yyvaluep)._destructor (); };

/* Line 925 of glr.c  */
#line 3348 "apyc-parser.cc"
	break;
      case 29: /* "\"@if_expr\"" */

/* Line 925 of glr.c  */
#line 262 "apyc-parser.y"
	{ (*yyvaluep)._destructor (); };

/* Line 925 of glr.c  */
#line 3357 "apyc-parser.cc"
	break;
      case 30: /* "INDENT" */

/* Line 925 of glr.c  */
#line 262 "apyc-parser.y"
	{ (*yyvaluep)._destructor (); };

/* Line 925 of glr.c  */
#line 3366 "apyc-parser.cc"
	break;
      case 31: /* "\"@int_literal\"" */

/* Line 925 of glr.c  */
#line 262 "apyc-parser.y"
	{ (*yyvaluep)._destructor (); };

/* Line 925 of glr.c  */
#line 3375 "apyc-parser.cc"
	break;
      case 32: /* "\"@list_display\"" */

/* Line 925 of glr.c  */
#line 262 "apyc-parser.y"
	{ (*yyvaluep)._destructor (); };

/* Line 925 of glr.c  */
#line 3384 "apyc-parser.cc"
	break;
      case 33: /* "\"@def\"" */

/* Line 925 of glr.c  */
#line 262 "apyc-parser.y"
	{ (*yyvaluep)._destructor (); };

/* Line 925 of glr.c  */
#line 3393 "apyc-parser.cc"
	break;
      case 34: /* "\"@module\"" */

/* Line 925 of glr.c  */
#line 262 "apyc-parser.y"
	{ (*yyvaluep)._destructor (); };

/* Line 925 of glr.c  */
#line 3402 "apyc-parser.cc"
	break;
      case 35: /* "\"native\"" */

/* Line 925 of glr.c  */
#line 262 "apyc-parser.y"
	{ (*yyvaluep)._destructor (); };

/* Line 925 of glr.c  */
#line 3411 "apyc-parser.cc"
	break;
      case 36: /* "\"not\"" */

/* Line 925 of glr.c  */
#line 262 "apyc-parser.y"
	{ (*yyvaluep)._destructor (); };

/* Line 925 of glr.c  */
#line 3420 "apyc-parser.cc"
	break;
      case 37: /* "\"or\"" */

/* Line 925 of glr.c  */
#line 262 "apyc-parser.y"
	{ (*yyvaluep)._destructor (); };

/* Line 925 of glr.c  */
#line 3429 "apyc-parser.cc"
	break;
      case 38: /* "\"@pair\"" */

/* Line 925 of glr.c  */
#line 262 "apyc-parser.y"
	{ (*yyvaluep)._destructor (); };

/* Line 925 of glr.c  */
#line 3438 "apyc-parser.cc"
	break;
      case 39: /* "\"@print\"" */

/* Line 925 of glr.c  */
#line 262 "apyc-parser.y"
	{ (*yyvaluep)._destructor (); };

/* Line 925 of glr.c  */
#line 3447 "apyc-parser.cc"
	break;
      case 40: /* "\"@println\"" */

/* Line 925 of glr.c  */
#line 262 "apyc-parser.y"
	{ (*yyvaluep)._destructor (); };

/* Line 925 of glr.c  */
#line 3456 "apyc-parser.cc"
	break;
      case 41: /* "\"@slicing\"" */

/* Line 925 of glr.c  */
#line 262 "apyc-parser.y"
	{ (*yyvaluep)._destructor (); };

/* Line 925 of glr.c  */
#line 3465 "apyc-parser.cc"
	break;
      case 42: /* "\"@@slicing\"" */

/* Line 925 of glr.c  */
#line 262 "apyc-parser.y"
	{ (*yyvaluep)._destructor (); };

/* Line 925 of glr.c  */
#line 3474 "apyc-parser.cc"
	break;
      case 43: /* "\"@stmt_list\"" */

/* Line 925 of glr.c  */
#line 262 "apyc-parser.y"
	{ (*yyvaluep)._destructor (); };

/* Line 925 of glr.c  */
#line 3483 "apyc-parser.cc"
	break;
      case 44: /* "STRING_LITERAL" */

/* Line 925 of glr.c  */
#line 262 "apyc-parser.y"
	{ (*yyvaluep)._destructor (); };

/* Line 925 of glr.c  */
#line 3492 "apyc-parser.cc"
	break;
      case 45: /* "\"@subscription\"" */

/* Line 925 of glr.c  */
#line 262 "apyc-parser.y"
	{ (*yyvaluep)._destructor (); };

/* Line 925 of glr.c  */
#line 3501 "apyc-parser.cc"
	break;
      case 46: /* "\"@@subscription\"" */

/* Line 925 of glr.c  */
#line 262 "apyc-parser.y"
	{ (*yyvaluep)._destructor (); };

/* Line 925 of glr.c  */
#line 3510 "apyc-parser.cc"
	break;
      case 47: /* "\"@target_list\"" */

/* Line 925 of glr.c  */
#line 262 "apyc-parser.y"
	{ (*yyvaluep)._destructor (); };

/* Line 925 of glr.c  */
#line 3519 "apyc-parser.cc"
	break;
      case 48: /* "\"@type_formals_list\"" */

/* Line 925 of glr.c  */
#line 262 "apyc-parser.y"
	{ (*yyvaluep)._destructor (); };

/* Line 925 of glr.c  */
#line 3528 "apyc-parser.cc"
	break;
      case 49: /* "\"@tuple\"" */

/* Line 925 of glr.c  */
#line 262 "apyc-parser.y"
	{ (*yyvaluep)._destructor (); };

/* Line 925 of glr.c  */
#line 3537 "apyc-parser.cc"
	break;
      case 50: /* "\"@type\"" */

/* Line 925 of glr.c  */
#line 262 "apyc-parser.y"
	{ (*yyvaluep)._destructor (); };

/* Line 925 of glr.c  */
#line 3546 "apyc-parser.cc"
	break;
      case 51: /* "\"@type_list\"" */

/* Line 925 of glr.c  */
#line 262 "apyc-parser.y"
	{ (*yyvaluep)._destructor (); };

/* Line 925 of glr.c  */
#line 3555 "apyc-parser.cc"
	break;
      case 52: /* "\"@type_var\"" */

/* Line 925 of glr.c  */
#line 262 "apyc-parser.y"
	{ (*yyvaluep)._destructor (); };

/* Line 925 of glr.c  */
#line 3564 "apyc-parser.cc"
	break;
      case 53: /* "\"@typed_id\"" */

/* Line 925 of glr.c  */
#line 262 "apyc-parser.y"
	{ (*yyvaluep)._destructor (); };

/* Line 925 of glr.c  */
#line 3573 "apyc-parser.cc"
	break;
      case 54: /* "\"while\"" */

/* Line 925 of glr.c  */
#line 262 "apyc-parser.y"
	{ (*yyvaluep)._destructor (); };

/* Line 925 of glr.c  */
#line 3582 "apyc-parser.cc"
	break;
      case 55: /* "\"!=\"" */

/* Line 925 of glr.c  */
#line 262 "apyc-parser.y"
	{ (*yyvaluep)._destructor (); };

/* Line 925 of glr.c  */
#line 3591 "apyc-parser.cc"
	break;
      case 56: /* "\"%\"" */

/* Line 925 of glr.c  */
#line 262 "apyc-parser.y"
	{ (*yyvaluep)._destructor (); };

/* Line 925 of glr.c  */
#line 3600 "apyc-parser.cc"
	break;
      case 57: /* "\"(\"" */

/* Line 925 of glr.c  */
#line 262 "apyc-parser.y"
	{ (*yyvaluep)._destructor (); };

/* Line 925 of glr.c  */
#line 3609 "apyc-parser.cc"
	break;
      case 58: /* "\")\"" */

/* Line 925 of glr.c  */
#line 262 "apyc-parser.y"
	{ (*yyvaluep)._destructor (); };

/* Line 925 of glr.c  */
#line 3618 "apyc-parser.cc"
	break;
      case 59: /* "\"*\"" */

/* Line 925 of glr.c  */
#line 262 "apyc-parser.y"
	{ (*yyvaluep)._destructor (); };

/* Line 925 of glr.c  */
#line 3627 "apyc-parser.cc"
	break;
      case 60: /* "\"+\"" */

/* Line 925 of glr.c  */
#line 262 "apyc-parser.y"
	{ (*yyvaluep)._destructor (); };

/* Line 925 of glr.c  */
#line 3636 "apyc-parser.cc"
	break;
      case 61: /* "\",\"" */

/* Line 925 of glr.c  */
#line 262 "apyc-parser.y"
	{ (*yyvaluep)._destructor (); };

/* Line 925 of glr.c  */
#line 3645 "apyc-parser.cc"
	break;
      case 62: /* "\"-\"" */

/* Line 925 of glr.c  */
#line 262 "apyc-parser.y"
	{ (*yyvaluep)._destructor (); };

/* Line 925 of glr.c  */
#line 3654 "apyc-parser.cc"
	break;
      case 63: /* "\"->\"" */

/* Line 925 of glr.c  */
#line 262 "apyc-parser.y"
	{ (*yyvaluep)._destructor (); };

/* Line 925 of glr.c  */
#line 3663 "apyc-parser.cc"
	break;
      case 64: /* "\".\"" */

/* Line 925 of glr.c  */
#line 262 "apyc-parser.y"
	{ (*yyvaluep)._destructor (); };

/* Line 925 of glr.c  */
#line 3672 "apyc-parser.cc"
	break;
      case 65: /* "\"/\"" */

/* Line 925 of glr.c  */
#line 262 "apyc-parser.y"
	{ (*yyvaluep)._destructor (); };

/* Line 925 of glr.c  */
#line 3681 "apyc-parser.cc"
	break;
      case 66: /* "\":\"" */

/* Line 925 of glr.c  */
#line 262 "apyc-parser.y"
	{ (*yyvaluep)._destructor (); };

/* Line 925 of glr.c  */
#line 3690 "apyc-parser.cc"
	break;
      case 67: /* "\"::\"" */

/* Line 925 of glr.c  */
#line 262 "apyc-parser.y"
	{ (*yyvaluep)._destructor (); };

/* Line 925 of glr.c  */
#line 3699 "apyc-parser.cc"
	break;
      case 68: /* "\";\"" */

/* Line 925 of glr.c  */
#line 262 "apyc-parser.y"
	{ (*yyvaluep)._destructor (); };

/* Line 925 of glr.c  */
#line 3708 "apyc-parser.cc"
	break;
      case 69: /* "\"<\"" */

/* Line 925 of glr.c  */
#line 262 "apyc-parser.y"
	{ (*yyvaluep)._destructor (); };

/* Line 925 of glr.c  */
#line 3717 "apyc-parser.cc"
	break;
      case 70: /* "\"<=\"" */

/* Line 925 of glr.c  */
#line 262 "apyc-parser.y"
	{ (*yyvaluep)._destructor (); };

/* Line 925 of glr.c  */
#line 3726 "apyc-parser.cc"
	break;
      case 71: /* "\"=\"" */

/* Line 925 of glr.c  */
#line 262 "apyc-parser.y"
	{ (*yyvaluep)._destructor (); };

/* Line 925 of glr.c  */
#line 3735 "apyc-parser.cc"
	break;
      case 72: /* "\"==\"" */

/* Line 925 of glr.c  */
#line 262 "apyc-parser.y"
	{ (*yyvaluep)._destructor (); };

/* Line 925 of glr.c  */
#line 3744 "apyc-parser.cc"
	break;
      case 73: /* "\">\"" */

/* Line 925 of glr.c  */
#line 262 "apyc-parser.y"
	{ (*yyvaluep)._destructor (); };

/* Line 925 of glr.c  */
#line 3753 "apyc-parser.cc"
	break;
      case 74: /* "\">=\"" */

/* Line 925 of glr.c  */
#line 262 "apyc-parser.y"
	{ (*yyvaluep)._destructor (); };

/* Line 925 of glr.c  */
#line 3762 "apyc-parser.cc"
	break;
      case 75: /* "\">>\"" */

/* Line 925 of glr.c  */
#line 262 "apyc-parser.y"
	{ (*yyvaluep)._destructor (); };

/* Line 925 of glr.c  */
#line 3771 "apyc-parser.cc"
	break;
      case 76: /* "\"[\"" */

/* Line 925 of glr.c  */
#line 262 "apyc-parser.y"
	{ (*yyvaluep)._destructor (); };

/* Line 925 of glr.c  */
#line 3780 "apyc-parser.cc"
	break;
      case 77: /* "\"]\"" */

/* Line 925 of glr.c  */
#line 262 "apyc-parser.y"
	{ (*yyvaluep)._destructor (); };

/* Line 925 of glr.c  */
#line 3789 "apyc-parser.cc"
	break;
      case 78: /* "\"class\"" */

/* Line 925 of glr.c  */
#line 262 "apyc-parser.y"
	{ (*yyvaluep)._destructor (); };

/* Line 925 of glr.c  */
#line 3798 "apyc-parser.cc"
	break;
      case 79: /* "\"elif\"" */

/* Line 925 of glr.c  */
#line 262 "apyc-parser.y"
	{ (*yyvaluep)._destructor (); };

/* Line 925 of glr.c  */
#line 3807 "apyc-parser.cc"
	break;
      case 80: /* "\"else\"" */

/* Line 925 of glr.c  */
#line 262 "apyc-parser.y"
	{ (*yyvaluep)._destructor (); };

/* Line 925 of glr.c  */
#line 3816 "apyc-parser.cc"
	break;
      case 81: /* "\"in\"" */

/* Line 925 of glr.c  */
#line 262 "apyc-parser.y"
	{ (*yyvaluep)._destructor (); };

/* Line 925 of glr.c  */
#line 3825 "apyc-parser.cc"
	break;
      case 82: /* "\"is\"" */

/* Line 925 of glr.c  */
#line 262 "apyc-parser.y"
	{ (*yyvaluep)._destructor (); };

/* Line 925 of glr.c  */
#line 3834 "apyc-parser.cc"
	break;
      case 83: /* "\"of\"" */

/* Line 925 of glr.c  */
#line 262 "apyc-parser.y"
	{ (*yyvaluep)._destructor (); };

/* Line 925 of glr.c  */
#line 3843 "apyc-parser.cc"
	break;
      case 84: /* "\"pass\"" */

/* Line 925 of glr.c  */
#line 262 "apyc-parser.y"
	{ (*yyvaluep)._destructor (); };

/* Line 925 of glr.c  */
#line 3852 "apyc-parser.cc"
	break;
      case 85: /* "\"print\"" */

/* Line 925 of glr.c  */
#line 262 "apyc-parser.y"
	{ (*yyvaluep)._destructor (); };

/* Line 925 of glr.c  */
#line 3861 "apyc-parser.cc"
	break;
      case 86: /* "\"return\"" */

/* Line 925 of glr.c  */
#line 262 "apyc-parser.y"
	{ (*yyvaluep)._destructor (); };

/* Line 925 of glr.c  */
#line 3870 "apyc-parser.cc"
	break;
      case 87: /* "\"{\"" */

/* Line 925 of glr.c  */
#line 262 "apyc-parser.y"
	{ (*yyvaluep)._destructor (); };

/* Line 925 of glr.c  */
#line 3879 "apyc-parser.cc"
	break;
      case 88: /* "\"}\"" */

/* Line 925 of glr.c  */
#line 262 "apyc-parser.y"
	{ (*yyvaluep)._destructor (); };

/* Line 925 of glr.c  */
#line 3888 "apyc-parser.cc"
	break;
      case 89: /* "NEWLINE" */

/* Line 925 of glr.c  */
#line 262 "apyc-parser.y"
	{ (*yyvaluep)._destructor (); };

/* Line 925 of glr.c  */
#line 3897 "apyc-parser.cc"
	break;
      case 90: /* "RAWSTRING" */

/* Line 925 of glr.c  */
#line 262 "apyc-parser.y"
	{ (*yyvaluep)._destructor (); };

/* Line 925 of glr.c  */
#line 3906 "apyc-parser.cc"
	break;
      case 92: /* "program" */

/* Line 925 of glr.c  */
#line 262 "apyc-parser.y"
	{ (*yyvaluep)._destructor (); };

/* Line 925 of glr.c  */
#line 3915 "apyc-parser.cc"
	break;
      case 93: /* "identifier" */

/* Line 925 of glr.c  */
#line 262 "apyc-parser.y"
	{ (*yyvaluep)._destructor (); };

/* Line 925 of glr.c  */
#line 3924 "apyc-parser.cc"
	break;
      case 94: /* "atom" */

/* Line 925 of glr.c  */
#line 262 "apyc-parser.y"
	{ (*yyvaluep)._destructor (); };

/* Line 925 of glr.c  */
#line 3933 "apyc-parser.cc"
	break;
      case 95: /* "enclosure" */

/* Line 925 of glr.c  */
#line 262 "apyc-parser.y"
	{ (*yyvaluep)._destructor (); };

/* Line 925 of glr.c  */
#line 3942 "apyc-parser.cc"
	break;
      case 96: /* "literal" */

/* Line 925 of glr.c  */
#line 262 "apyc-parser.y"
	{ (*yyvaluep)._destructor (); };

/* Line 925 of glr.c  */
#line 3951 "apyc-parser.cc"
	break;
      case 97: /* "string_piece" */

/* Line 925 of glr.c  */
#line 262 "apyc-parser.y"
	{ (*yyvaluep)._destructor (); };

/* Line 925 of glr.c  */
#line 3960 "apyc-parser.cc"
	break;
      case 98: /* "stringliteral" */

/* Line 925 of glr.c  */
#line 262 "apyc-parser.y"
	{ (*yyvaluep)._destructor (); };

/* Line 925 of glr.c  */
#line 3969 "apyc-parser.cc"
	break;
      case 99: /* "parenth_form" */

/* Line 925 of glr.c  */
#line 262 "apyc-parser.y"
	{ (*yyvaluep)._destructor (); };

/* Line 925 of glr.c  */
#line 3978 "apyc-parser.cc"
	break;
      case 100: /* "list_display" */

/* Line 925 of glr.c  */
#line 262 "apyc-parser.y"
	{ (*yyvaluep)._destructor (); };

/* Line 925 of glr.c  */
#line 3987 "apyc-parser.cc"
	break;
      case 101: /* "dict_display" */

/* Line 925 of glr.c  */
#line 262 "apyc-parser.y"
	{ (*yyvaluep)._destructor (); };

/* Line 925 of glr.c  */
#line 3996 "apyc-parser.cc"
	break;
      case 102: /* "key_datum_list" */

/* Line 925 of glr.c  */
#line 262 "apyc-parser.y"
	{ (*yyvaluep)._destructor (); };

/* Line 925 of glr.c  */
#line 4005 "apyc-parser.cc"
	break;
      case 103: /* "key_datum" */

/* Line 925 of glr.c  */
#line 262 "apyc-parser.y"
	{ (*yyvaluep)._destructor (); };

/* Line 925 of glr.c  */
#line 4014 "apyc-parser.cc"
	break;
      case 104: /* "primary" */

/* Line 925 of glr.c  */
#line 262 "apyc-parser.y"
	{ (*yyvaluep)._destructor (); };

/* Line 925 of glr.c  */
#line 4023 "apyc-parser.cc"
	break;
      case 105: /* "attributeref" */

/* Line 925 of glr.c  */
#line 262 "apyc-parser.y"
	{ (*yyvaluep)._destructor (); };

/* Line 925 of glr.c  */
#line 4032 "apyc-parser.cc"
	break;
      case 106: /* "subscription" */

/* Line 925 of glr.c  */
#line 262 "apyc-parser.y"
	{ (*yyvaluep)._destructor (); };

/* Line 925 of glr.c  */
#line 4041 "apyc-parser.cc"
	break;
      case 107: /* "slicing" */

/* Line 925 of glr.c  */
#line 262 "apyc-parser.y"
	{ (*yyvaluep)._destructor (); };

/* Line 925 of glr.c  */
#line 4050 "apyc-parser.cc"
	break;
      case 108: /* "bound" */

/* Line 925 of glr.c  */
#line 262 "apyc-parser.y"
	{ (*yyvaluep)._destructor (); };

/* Line 925 of glr.c  */
#line 4059 "apyc-parser.cc"
	break;
      case 109: /* "call" */

/* Line 925 of glr.c  */
#line 262 "apyc-parser.y"
	{ (*yyvaluep)._destructor (); };

/* Line 925 of glr.c  */
#line 4068 "apyc-parser.cc"
	break;
      case 110: /* "argument_list" */

/* Line 925 of glr.c  */
#line 262 "apyc-parser.y"
	{ (*yyvaluep)._destructor (); };

/* Line 925 of glr.c  */
#line 4077 "apyc-parser.cc"
	break;
      case 111: /* "expression" */

/* Line 925 of glr.c  */
#line 262 "apyc-parser.y"
	{ (*yyvaluep)._destructor (); };

/* Line 925 of glr.c  */
#line 4086 "apyc-parser.cc"
	break;
      case 112: /* "conditional_expression" */

/* Line 925 of glr.c  */
#line 262 "apyc-parser.y"
	{ (*yyvaluep)._destructor (); };

/* Line 925 of glr.c  */
#line 4095 "apyc-parser.cc"
	break;
      case 113: /* "expr1" */

/* Line 925 of glr.c  */
#line 262 "apyc-parser.y"
	{ (*yyvaluep)._destructor (); };

/* Line 925 of glr.c  */
#line 4104 "apyc-parser.cc"
	break;
      case 114: /* "expression_list_no_comma" */

/* Line 925 of glr.c  */
#line 262 "apyc-parser.y"
	{ (*yyvaluep)._destructor (); };

/* Line 925 of glr.c  */
#line 4113 "apyc-parser.cc"
	break;
      case 115: /* "expression_list0_no_comma" */

/* Line 925 of glr.c  */
#line 262 "apyc-parser.y"
	{ (*yyvaluep)._destructor (); };

/* Line 925 of glr.c  */
#line 4122 "apyc-parser.cc"
	break;
      case 116: /* "expression_or_list" */

/* Line 925 of glr.c  */
#line 262 "apyc-parser.y"
	{ (*yyvaluep)._destructor (); };

/* Line 925 of glr.c  */
#line 4131 "apyc-parser.cc"
	break;
      case 117: /* "expression_or_list0" */

/* Line 925 of glr.c  */
#line 262 "apyc-parser.y"
	{ (*yyvaluep)._destructor (); };

/* Line 925 of glr.c  */
#line 4140 "apyc-parser.cc"
	break;
      case 118: /* "comp_operator" */

/* Line 925 of glr.c  */
#line 262 "apyc-parser.y"
	{ (*yyvaluep)._destructor (); };

/* Line 925 of glr.c  */
#line 4149 "apyc-parser.cc"
	break;
      case 119: /* "expr2" */

/* Line 925 of glr.c  */
#line 262 "apyc-parser.y"
	{ (*yyvaluep)._destructor (); };

/* Line 925 of glr.c  */
#line 4158 "apyc-parser.cc"
	break;
      case 120: /* "left_compare" */

/* Line 925 of glr.c  */
#line 262 "apyc-parser.y"
	{ (*yyvaluep)._destructor (); };

/* Line 925 of glr.c  */
#line 4167 "apyc-parser.cc"
	break;
      case 121: /* "expr3" */

/* Line 925 of glr.c  */
#line 262 "apyc-parser.y"
	{ (*yyvaluep)._destructor (); };

/* Line 925 of glr.c  */
#line 4176 "apyc-parser.cc"
	break;
      case 122: /* "simple_stmt" */

/* Line 925 of glr.c  */
#line 262 "apyc-parser.y"
	{ (*yyvaluep)._destructor (); };

/* Line 925 of glr.c  */
#line 4185 "apyc-parser.cc"
	break;
      case 123: /* "expression_stmt" */

/* Line 925 of glr.c  */
#line 262 "apyc-parser.y"
	{ (*yyvaluep)._destructor (); };

/* Line 925 of glr.c  */
#line 4194 "apyc-parser.cc"
	break;
      case 124: /* "assignment_stmt" */

/* Line 925 of glr.c  */
#line 262 "apyc-parser.y"
	{ (*yyvaluep)._destructor (); };

/* Line 925 of glr.c  */
#line 4203 "apyc-parser.cc"
	break;
      case 125: /* "target_list" */

/* Line 925 of glr.c  */
#line 262 "apyc-parser.y"
	{ (*yyvaluep)._destructor (); };

/* Line 925 of glr.c  */
#line 4212 "apyc-parser.cc"
	break;
      case 126: /* "target_list1" */

/* Line 925 of glr.c  */
#line 262 "apyc-parser.y"
	{ (*yyvaluep)._destructor (); };

/* Line 925 of glr.c  */
#line 4221 "apyc-parser.cc"
	break;
      case 127: /* "target" */

/* Line 925 of glr.c  */
#line 262 "apyc-parser.y"
	{ (*yyvaluep)._destructor (); };

/* Line 925 of glr.c  */
#line 4230 "apyc-parser.cc"
	break;
      case 128: /* "pass_stmt" */

/* Line 925 of glr.c  */
#line 262 "apyc-parser.y"
	{ (*yyvaluep)._destructor (); };

/* Line 925 of glr.c  */
#line 4239 "apyc-parser.cc"
	break;
      case 129: /* "print_stmt" */

/* Line 925 of glr.c  */
#line 262 "apyc-parser.y"
	{ (*yyvaluep)._destructor (); };

/* Line 925 of glr.c  */
#line 4248 "apyc-parser.cc"
	break;
      case 130: /* "return_stmt" */

/* Line 925 of glr.c  */
#line 262 "apyc-parser.y"
	{ (*yyvaluep)._destructor (); };

/* Line 925 of glr.c  */
#line 4257 "apyc-parser.cc"
	break;
      case 131: /* "break_stmt" */

/* Line 925 of glr.c  */
#line 262 "apyc-parser.y"
	{ (*yyvaluep)._destructor (); };

/* Line 925 of glr.c  */
#line 4266 "apyc-parser.cc"
	break;
      case 132: /* "continue_stmt" */

/* Line 925 of glr.c  */
#line 262 "apyc-parser.y"
	{ (*yyvaluep)._destructor (); };

/* Line 925 of glr.c  */
#line 4275 "apyc-parser.cc"
	break;
      case 133: /* "compound_stmt" */

/* Line 925 of glr.c  */
#line 262 "apyc-parser.y"
	{ (*yyvaluep)._destructor (); };

/* Line 925 of glr.c  */
#line 4284 "apyc-parser.cc"
	break;
      case 134: /* "stmts" */

/* Line 925 of glr.c  */
#line 262 "apyc-parser.y"
	{ (*yyvaluep)._destructor (); };

/* Line 925 of glr.c  */
#line 4293 "apyc-parser.cc"
	break;
      case 135: /* "suite" */

/* Line 925 of glr.c  */
#line 262 "apyc-parser.y"
	{ (*yyvaluep)._destructor (); };

/* Line 925 of glr.c  */
#line 4302 "apyc-parser.cc"
	break;
      case 136: /* "statement" */

/* Line 925 of glr.c  */
#line 262 "apyc-parser.y"
	{ (*yyvaluep)._destructor (); };

/* Line 925 of glr.c  */
#line 4311 "apyc-parser.cc"
	break;
      case 137: /* "stmt_list" */

/* Line 925 of glr.c  */
#line 262 "apyc-parser.y"
	{ (*yyvaluep)._destructor (); };

/* Line 925 of glr.c  */
#line 4320 "apyc-parser.cc"
	break;
      case 138: /* "if_stmt" */

/* Line 925 of glr.c  */
#line 262 "apyc-parser.y"
	{ (*yyvaluep)._destructor (); };

/* Line 925 of glr.c  */
#line 4329 "apyc-parser.cc"
	break;
      case 139: /* "@1" */

/* Line 925 of glr.c  */
#line 262 "apyc-parser.y"
	{ (*yyvaluep)._destructor (); };

/* Line 925 of glr.c  */
#line 4338 "apyc-parser.cc"
	break;
      case 140: /* "elifs" */

/* Line 925 of glr.c  */
#line 262 "apyc-parser.y"
	{ (*yyvaluep)._destructor (); };

/* Line 925 of glr.c  */
#line 4347 "apyc-parser.cc"
	break;
      case 141: /* "else_clause" */

/* Line 925 of glr.c  */
#line 262 "apyc-parser.y"
	{ (*yyvaluep)._destructor (); };

/* Line 925 of glr.c  */
#line 4356 "apyc-parser.cc"
	break;
      case 142: /* "while_stmt" */

/* Line 925 of glr.c  */
#line 262 "apyc-parser.y"
	{ (*yyvaluep)._destructor (); };

/* Line 925 of glr.c  */
#line 4365 "apyc-parser.cc"
	break;
      case 143: /* "@2" */

/* Line 925 of glr.c  */
#line 262 "apyc-parser.y"
	{ (*yyvaluep)._destructor (); };

/* Line 925 of glr.c  */
#line 4374 "apyc-parser.cc"
	break;
      case 144: /* "@3" */

/* Line 925 of glr.c  */
#line 262 "apyc-parser.y"
	{ (*yyvaluep)._destructor (); };

/* Line 925 of glr.c  */
#line 4383 "apyc-parser.cc"
	break;
      case 145: /* "for_stmt" */

/* Line 925 of glr.c  */
#line 262 "apyc-parser.y"
	{ (*yyvaluep)._destructor (); };

/* Line 925 of glr.c  */
#line 4392 "apyc-parser.cc"
	break;
      case 146: /* "@4" */

/* Line 925 of glr.c  */
#line 262 "apyc-parser.y"
	{ (*yyvaluep)._destructor (); };

/* Line 925 of glr.c  */
#line 4401 "apyc-parser.cc"
	break;
      case 147: /* "@5" */

/* Line 925 of glr.c  */
#line 262 "apyc-parser.y"
	{ (*yyvaluep)._destructor (); };

/* Line 925 of glr.c  */
#line 4410 "apyc-parser.cc"
	break;
      case 148: /* "funcdef" */

/* Line 925 of glr.c  */
#line 262 "apyc-parser.y"
	{ (*yyvaluep)._destructor (); };

/* Line 925 of glr.c  */
#line 4419 "apyc-parser.cc"
	break;
      case 149: /* "@6" */

/* Line 925 of glr.c  */
#line 262 "apyc-parser.y"
	{ (*yyvaluep)._destructor (); };

/* Line 925 of glr.c  */
#line 4428 "apyc-parser.cc"
	break;
      case 150: /* "funcbody" */

/* Line 925 of glr.c  */
#line 262 "apyc-parser.y"
	{ (*yyvaluep)._destructor (); };

/* Line 925 of glr.c  */
#line 4437 "apyc-parser.cc"
	break;
      case 151: /* "native" */

/* Line 925 of glr.c  */
#line 262 "apyc-parser.y"
	{ (*yyvaluep)._destructor (); };

/* Line 925 of glr.c  */
#line 4446 "apyc-parser.cc"
	break;
      case 152: /* "parameter_list" */

/* Line 925 of glr.c  */
#line 262 "apyc-parser.y"
	{ (*yyvaluep)._destructor (); };

/* Line 925 of glr.c  */
#line 4455 "apyc-parser.cc"
	break;
      case 153: /* "parameter" */

/* Line 925 of glr.c  */
#line 262 "apyc-parser.y"
	{ (*yyvaluep)._destructor (); };

/* Line 925 of glr.c  */
#line 4464 "apyc-parser.cc"
	break;
      case 154: /* "funcname" */

/* Line 925 of glr.c  */
#line 262 "apyc-parser.y"
	{ (*yyvaluep)._destructor (); };

/* Line 925 of glr.c  */
#line 4473 "apyc-parser.cc"
	break;
      case 155: /* "classdef" */

/* Line 925 of glr.c  */
#line 262 "apyc-parser.y"
	{ (*yyvaluep)._destructor (); };

/* Line 925 of glr.c  */
#line 4482 "apyc-parser.cc"
	break;
      case 156: /* "@7" */

/* Line 925 of glr.c  */
#line 262 "apyc-parser.y"
	{ (*yyvaluep)._destructor (); };

/* Line 925 of glr.c  */
#line 4491 "apyc-parser.cc"
	break;
      case 157: /* "type_formals" */

/* Line 925 of glr.c  */
#line 262 "apyc-parser.y"
	{ (*yyvaluep)._destructor (); };

/* Line 925 of glr.c  */
#line 4500 "apyc-parser.cc"
	break;
      case 158: /* "classbody" */

/* Line 925 of glr.c  */
#line 262 "apyc-parser.y"
	{ (*yyvaluep)._destructor (); };

/* Line 925 of glr.c  */
#line 4509 "apyc-parser.cc"
	break;
      case 159: /* "type_annotation" */

/* Line 925 of glr.c  */
#line 262 "apyc-parser.y"
	{ (*yyvaluep)._destructor (); };

/* Line 925 of glr.c  */
#line 4518 "apyc-parser.cc"
	break;
      case 160: /* "opt_type_annotation" */

/* Line 925 of glr.c  */
#line 262 "apyc-parser.y"
	{ (*yyvaluep)._destructor (); };

/* Line 925 of glr.c  */
#line 4527 "apyc-parser.cc"
	break;
      case 161: /* "type" */

/* Line 925 of glr.c  */
#line 262 "apyc-parser.y"
	{ (*yyvaluep)._destructor (); };

/* Line 925 of glr.c  */
#line 4536 "apyc-parser.cc"
	break;
      case 162: /* "type_var" */

/* Line 925 of glr.c  */
#line 262 "apyc-parser.y"
	{ (*yyvaluep)._destructor (); };

/* Line 925 of glr.c  */
#line 4545 "apyc-parser.cc"
	break;
      case 163: /* "parameterized_type" */

/* Line 925 of glr.c  */
#line 262 "apyc-parser.y"
	{ (*yyvaluep)._destructor (); };

/* Line 925 of glr.c  */
#line 4554 "apyc-parser.cc"
	break;
      case 164: /* "type_params" */

/* Line 925 of glr.c  */
#line 262 "apyc-parser.y"
	{ (*yyvaluep)._destructor (); };

/* Line 925 of glr.c  */
#line 4563 "apyc-parser.cc"
	break;
      case 165: /* "type_list" */

/* Line 925 of glr.c  */
#line 262 "apyc-parser.y"
	{ (*yyvaluep)._destructor (); };

/* Line 925 of glr.c  */
#line 4572 "apyc-parser.cc"
	break;
      case 166: /* "types" */

/* Line 925 of glr.c  */
#line 262 "apyc-parser.y"
	{ (*yyvaluep)._destructor (); };

/* Line 925 of glr.c  */
#line 4581 "apyc-parser.cc"
	break;
      case 167: /* "empty" */

/* Line 925 of glr.c  */
#line 262 "apyc-parser.y"
	{ (*yyvaluep)._destructor (); };

/* Line 925 of glr.c  */
#line 4590 "apyc-parser.cc"
	break;
      case 168: /* "__0" */

/* Line 925 of glr.c  */
#line 262 "apyc-parser.y"
	{ (*yyvaluep)._destructor (); };

/* Line 925 of glr.c  */
#line 4599 "apyc-parser.cc"
	break;
      case 169: /* "__1" */

/* Line 925 of glr.c  */
#line 262 "apyc-parser.y"
	{ (*yyvaluep)._destructor (); };

/* Line 925 of glr.c  */
#line 4608 "apyc-parser.cc"
	break;
      case 170: /* "__2" */

/* Line 925 of glr.c  */
#line 262 "apyc-parser.y"
	{ (*yyvaluep)._destructor (); };

/* Line 925 of glr.c  */
#line 4617 "apyc-parser.cc"
	break;
      case 171: /* "__3" */

/* Line 925 of glr.c  */
#line 262 "apyc-parser.y"
	{ (*yyvaluep)._destructor (); };

/* Line 925 of glr.c  */
#line 4626 "apyc-parser.cc"
	break;
      case 172: /* "__4" */

/* Line 925 of glr.c  */
#line 262 "apyc-parser.y"
	{ (*yyvaluep)._destructor (); };

/* Line 925 of glr.c  */
#line 4635 "apyc-parser.cc"
	break;
      case 173: /* "__5" */

/* Line 925 of glr.c  */
#line 262 "apyc-parser.y"
	{ (*yyvaluep)._destructor (); };

/* Line 925 of glr.c  */
#line 4644 "apyc-parser.cc"
	break;
      case 174: /* "__6" */

/* Line 925 of glr.c  */
#line 262 "apyc-parser.y"
	{ (*yyvaluep)._destructor (); };

/* Line 925 of glr.c  */
#line 4653 "apyc-parser.cc"
	break;
      case 175: /* "__7" */

/* Line 925 of glr.c  */
#line 262 "apyc-parser.y"
	{ (*yyvaluep)._destructor (); };

/* Line 925 of glr.c  */
#line 4662 "apyc-parser.cc"
	break;
      case 176: /* "__8" */

/* Line 925 of glr.c  */
#line 262 "apyc-parser.y"
	{ (*yyvaluep)._destructor (); };

/* Line 925 of glr.c  */
#line 4671 "apyc-parser.cc"
	break;
      case 177: /* "__9" */

/* Line 925 of glr.c  */
#line 262 "apyc-parser.y"
	{ (*yyvaluep)._destructor (); };

/* Line 925 of glr.c  */
#line 4680 "apyc-parser.cc"
	break;
      case 178: /* "__10" */

/* Line 925 of glr.c  */
#line 262 "apyc-parser.y"
	{ (*yyvaluep)._destructor (); };

/* Line 925 of glr.c  */
#line 4689 "apyc-parser.cc"
	break;
      case 179: /* "__11" */

/* Line 925 of glr.c  */
#line 262 "apyc-parser.y"
	{ (*yyvaluep)._destructor (); };

/* Line 925 of glr.c  */
#line 4698 "apyc-parser.cc"
	break;
      case 180: /* "__12" */

/* Line 925 of glr.c  */
#line 262 "apyc-parser.y"
	{ (*yyvaluep)._destructor (); };

/* Line 925 of glr.c  */
#line 4707 "apyc-parser.cc"
	break;
      case 181: /* "__13" */

/* Line 925 of glr.c  */
#line 262 "apyc-parser.y"
	{ (*yyvaluep)._destructor (); };

/* Line 925 of glr.c  */
#line 4716 "apyc-parser.cc"
	break;
      case 182: /* "__14" */

/* Line 925 of glr.c  */
#line 262 "apyc-parser.y"
	{ (*yyvaluep)._destructor (); };

/* Line 925 of glr.c  */
#line 4725 "apyc-parser.cc"
	break;
      case 183: /* "__15" */

/* Line 925 of glr.c  */
#line 262 "apyc-parser.y"
	{ (*yyvaluep)._destructor (); };

/* Line 925 of glr.c  */
#line 4734 "apyc-parser.cc"
	break;
      case 184: /* "__16" */

/* Line 925 of glr.c  */
#line 262 "apyc-parser.y"
	{ (*yyvaluep)._destructor (); };

/* Line 925 of glr.c  */
#line 4743 "apyc-parser.cc"
	break;
      case 185: /* "__17" */

/* Line 925 of glr.c  */
#line 262 "apyc-parser.y"
	{ (*yyvaluep)._destructor (); };

/* Line 925 of glr.c  */
#line 4752 "apyc-parser.cc"
	break;
      case 186: /* "__18" */

/* Line 925 of glr.c  */
#line 262 "apyc-parser.y"
	{ (*yyvaluep)._destructor (); };

/* Line 925 of glr.c  */
#line 4761 "apyc-parser.cc"
	break;
      case 187: /* "__19" */

/* Line 925 of glr.c  */
#line 262 "apyc-parser.y"
	{ (*yyvaluep)._destructor (); };

/* Line 925 of glr.c  */
#line 4770 "apyc-parser.cc"
	break;
      case 188: /* "__20" */

/* Line 925 of glr.c  */
#line 262 "apyc-parser.y"
	{ (*yyvaluep)._destructor (); };

/* Line 925 of glr.c  */
#line 4779 "apyc-parser.cc"
	break;
      case 189: /* "__21" */

/* Line 925 of glr.c  */
#line 262 "apyc-parser.y"
	{ (*yyvaluep)._destructor (); };

/* Line 925 of glr.c  */
#line 4788 "apyc-parser.cc"
	break;
      case 190: /* "__22" */

/* Line 925 of glr.c  */
#line 262 "apyc-parser.y"
	{ (*yyvaluep)._destructor (); };

/* Line 925 of glr.c  */
#line 4797 "apyc-parser.cc"
	break;
      case 191: /* "__23" */

/* Line 925 of glr.c  */
#line 262 "apyc-parser.y"
	{ (*yyvaluep)._destructor (); };

/* Line 925 of glr.c  */
#line 4806 "apyc-parser.cc"
	break;
      case 192: /* "__24" */

/* Line 925 of glr.c  */
#line 262 "apyc-parser.y"
	{ (*yyvaluep)._destructor (); };

/* Line 925 of glr.c  */
#line 4815 "apyc-parser.cc"
	break;
      case 193: /* "__25" */

/* Line 925 of glr.c  */
#line 262 "apyc-parser.y"
	{ (*yyvaluep)._destructor (); };

/* Line 925 of glr.c  */
#line 4824 "apyc-parser.cc"
	break;
      case 194: /* "__26" */

/* Line 925 of glr.c  */
#line 262 "apyc-parser.y"
	{ (*yyvaluep)._destructor (); };

/* Line 925 of glr.c  */
#line 4833 "apyc-parser.cc"
	break;
      case 195: /* "__error__" */

/* Line 925 of glr.c  */
#line 262 "apyc-parser.y"
	{ (*yyvaluep)._destructor (); };

/* Line 925 of glr.c  */
#line 4842 "apyc-parser.cc"
	break;

      default:
	break;
    }
}

/** Number of symbols composing the right hand side of rule #RULE.  */
static inline int
yyrhsLength (yyRuleNum yyrule)
{
  return yyr2[yyrule];
}

static void
yydestroyGLRState (char const *yymsg, yyGLRState *yys)
{
  if (yys->yyresolved)
    yydestruct (yymsg, yystos[yys->yylrState],
                &yys->yysemantics.yysval);
  else
    {
#if YYDEBUG
      if (yydebug)
        {
          if (yys->yysemantics.yyfirstVal)
            YYFPRINTF (stderr, "%s unresolved ", yymsg);
          else
            YYFPRINTF (stderr, "%s incomplete ", yymsg);
          yy_symbol_print (stderr, yystos[yys->yylrState],
                           YY_NULL);
          YYFPRINTF (stderr, "\n");
        }
#endif

      if (yys->yysemantics.yyfirstVal)
        {
          yySemanticOption *yyoption = yys->yysemantics.yyfirstVal;
          yyGLRState *yyrh;
          int yyn;
          for (yyrh = yyoption->yystate, yyn = yyrhsLength (yyoption->yyrule);
               yyn > 0;
               yyrh = yyrh->yypred, yyn -= 1)
            yydestroyGLRState (yymsg, yyrh);
        }
    }
}

/** Left-hand-side symbol for rule #RULE.  */
static inline yySymbol
yylhsNonterm (yyRuleNum yyrule)
{
  return yyr1[yyrule];
}

#define yypact_value_is_default(yystate) \
  ((yystate) == (-239))

/** True iff LR state STATE has only a default reduction (regardless
 *  of token).  */
static inline yybool
yyisDefaultedState (yyStateNum yystate)
{
  return yypact_value_is_default (yypact[yystate]);
}

/** The default reduction for STATE, assuming it has one.  */
static inline yyRuleNum
yydefaultAction (yyStateNum yystate)
{
  return yydefact[yystate];
}

#define yytable_value_is_error(yytable_value) \
  YYID (0)

/** Set *YYACTION to the action to take in YYSTATE on seeing YYTOKEN.
 *  Result R means
 *    R < 0:  Reduce on rule -R.
 *    R = 0:  Error.
 *    R > 0:  Shift to state R.
 *  Set *CONFLICTS to a pointer into yyconfl to 0-terminated list of
 *  conflicting reductions.
 */
static inline void
yygetLRActions (yyStateNum yystate, int yytoken,
                int* yyaction, const short int** yyconflicts)
{
  int yyindex = yypact[yystate] + yytoken;
  if (yypact_value_is_default (yypact[yystate])
      || yyindex < 0 || YYLAST < yyindex || yycheck[yyindex] != yytoken)
    {
      *yyaction = -yydefact[yystate];
      *yyconflicts = yyconfl;
    }
  else if (! yytable_value_is_error (yytable[yyindex]))
    {
      *yyaction = yytable[yyindex];
      *yyconflicts = yyconfl + yyconflp[yyindex];
    }
  else
    {
      *yyaction = 0;
      *yyconflicts = yyconfl + yyconflp[yyindex];
    }
}

static inline yyStateNum
yyLRgotoState (yyStateNum yystate, yySymbol yylhs)
{
  int yyr;
  yyr = yypgoto[yylhs - YYNTOKENS] + yystate;
  if (0 <= yyr && yyr <= YYLAST && yycheck[yyr] == yystate)
    return yytable[yyr];
  else
    return yydefgoto[yylhs - YYNTOKENS];
}

static inline yybool
yyisShiftAction (int yyaction)
{
  return 0 < yyaction;
}

static inline yybool
yyisErrorAction (int yyaction)
{
  return yyaction == 0;
}

                                /* GLRStates */

/** Return a fresh GLRStackItem.  Callers should call
 * YY_RESERVE_GLRSTACK afterwards to make sure there is sufficient
 * headroom.  */

static inline yyGLRStackItem*
yynewGLRStackItem (yyGLRStack* yystackp, yybool yyisState)
{
  yyGLRStackItem* yynewItem = yystackp->yynextFree;
  yystackp->yyspaceLeft -= 1;
  yystackp->yynextFree += 1;
  yynewItem->yystate.yyisState = yyisState;
  return yynewItem;
}

/** Add a new semantic action that will execute the action for rule
 *  RULENUM on the semantic values in RHS to the list of
 *  alternative actions for STATE.  Assumes that RHS comes from
 *  stack #K of *STACKP. */
static void
yyaddDeferredAction (yyGLRStack* yystackp, size_t yyk, yyGLRState* yystate,
                     yyGLRState* rhs, yyRuleNum yyrule)
{
  yySemanticOption* yynewOption =
    &yynewGLRStackItem (yystackp, yyfalse)->yyoption;
  yynewOption->yystate = rhs;
  yynewOption->yyrule = yyrule;
  if (yystackp->yytops.yylookaheadNeeds[yyk])
    {
      yynewOption->yyrawchar = yychar;
      yynewOption->yyval = yylval;
    }
  else
    yynewOption->yyrawchar = YYEMPTY;
  yynewOption->yynext = yystate->yysemantics.yyfirstVal;
  yystate->yysemantics.yyfirstVal = yynewOption;

  YY_RESERVE_GLRSTACK (yystackp);
}

                                /* GLRStacks */

/** Initialize SET to a singleton set containing an empty stack.  */
static yybool
yyinitStateSet (yyGLRStateSet* yyset)
{
  yyset->yysize = 1;
  yyset->yycapacity = 16;
  yyset->yystates = (yyGLRState**) YYMALLOC (16 * sizeof yyset->yystates[0]);
  if (! yyset->yystates)
    return yyfalse;
  yyset->yystates[0] = YY_NULL;
  yyset->yylookaheadNeeds =
    (yybool*) YYMALLOC (16 * sizeof yyset->yylookaheadNeeds[0]);
  if (! yyset->yylookaheadNeeds)
    {
      YYFREE (yyset->yystates);
      return yyfalse;
    }
  return yytrue;
}

static void yyfreeStateSet (yyGLRStateSet* yyset)
{
  YYFREE (yyset->yystates);
  YYFREE (yyset->yylookaheadNeeds);
}

/** Initialize STACK to a single empty stack, with total maximum
 *  capacity for all stacks of SIZE.  */
static yybool
yyinitGLRStack (yyGLRStack* yystackp, size_t yysize)
{
  yystackp->yyerrState = 0;
  yynerrs = 0;
  yystackp->yyspaceLeft = yysize;
  yystackp->yyitems =
    (yyGLRStackItem*) YYMALLOC (yysize * sizeof yystackp->yynextFree[0]);
  if (!yystackp->yyitems)
    return yyfalse;
  yystackp->yynextFree = yystackp->yyitems;
  yystackp->yysplitPoint = YY_NULL;
  yystackp->yylastDeleted = YY_NULL;
  return yyinitStateSet (&yystackp->yytops);
}


#if YYSTACKEXPANDABLE
# define YYRELOC(YYFROMITEMS,YYTOITEMS,YYX,YYTYPE) \
  &((YYTOITEMS) - ((YYFROMITEMS) - (yyGLRStackItem*) (YYX)))->YYTYPE

/** If STACK is expandable, extend it.  WARNING: Pointers into the
    stack from outside should be considered invalid after this call.
    We always expand when there are 1 or fewer items left AFTER an
    allocation, so that we can avoid having external pointers exist
    across an allocation.  */
static void
yyexpandGLRStack (yyGLRStack* yystackp)
{
  yyGLRStackItem* yynewItems;
  yyGLRStackItem* yyp0, *yyp1;
  size_t yynewSize;
  size_t yyn;
  size_t yysize = yystackp->yynextFree - yystackp->yyitems;
  if (YYMAXDEPTH - YYHEADROOM < yysize)
    yyMemoryExhausted (yystackp);
  yynewSize = 2*yysize;
  if (YYMAXDEPTH < yynewSize)
    yynewSize = YYMAXDEPTH;
  yynewItems = (yyGLRStackItem*) YYMALLOC (yynewSize * sizeof yynewItems[0]);
  if (! yynewItems)
    yyMemoryExhausted (yystackp);
  for (yyp0 = yystackp->yyitems, yyp1 = yynewItems, yyn = yysize;
       0 < yyn;
       yyn -= 1, yyp0 += 1, yyp1 += 1)
    {
      *yyp1 = *yyp0;
      if (*(yybool *) yyp0)
        {
          yyGLRState* yys0 = &yyp0->yystate;
          yyGLRState* yys1 = &yyp1->yystate;
          if (yys0->yypred != YY_NULL)
            yys1->yypred =
              YYRELOC (yyp0, yyp1, yys0->yypred, yystate);
          if (! yys0->yyresolved && yys0->yysemantics.yyfirstVal != YY_NULL)
            yys1->yysemantics.yyfirstVal =
              YYRELOC (yyp0, yyp1, yys0->yysemantics.yyfirstVal, yyoption);
        }
      else
        {
          yySemanticOption* yyv0 = &yyp0->yyoption;
          yySemanticOption* yyv1 = &yyp1->yyoption;
          if (yyv0->yystate != YY_NULL)
            yyv1->yystate = YYRELOC (yyp0, yyp1, yyv0->yystate, yystate);
          if (yyv0->yynext != YY_NULL)
            yyv1->yynext = YYRELOC (yyp0, yyp1, yyv0->yynext, yyoption);
        }
    }
  if (yystackp->yysplitPoint != YY_NULL)
    yystackp->yysplitPoint = YYRELOC (yystackp->yyitems, yynewItems,
                                 yystackp->yysplitPoint, yystate);

  for (yyn = 0; yyn < yystackp->yytops.yysize; yyn += 1)
    if (yystackp->yytops.yystates[yyn] != YY_NULL)
      yystackp->yytops.yystates[yyn] =
        YYRELOC (yystackp->yyitems, yynewItems,
                 yystackp->yytops.yystates[yyn], yystate);
  YYFREE (yystackp->yyitems);
  yystackp->yyitems = yynewItems;
  yystackp->yynextFree = yynewItems + yysize;
  yystackp->yyspaceLeft = yynewSize - yysize;
}
#endif

static void
yyfreeGLRStack (yyGLRStack* yystackp)
{
  YYFREE (yystackp->yyitems);
  yyfreeStateSet (&yystackp->yytops);
}

/** Assuming that S is a GLRState somewhere on STACK, update the
 *  splitpoint of STACK, if needed, so that it is at least as deep as
 *  S.  */
static inline void
yyupdateSplit (yyGLRStack* yystackp, yyGLRState* yys)
{
  if (yystackp->yysplitPoint != YY_NULL && yystackp->yysplitPoint > yys)
    yystackp->yysplitPoint = yys;
}

/** Invalidate stack #K in STACK.  */
static inline void
yymarkStackDeleted (yyGLRStack* yystackp, size_t yyk)
{
  if (yystackp->yytops.yystates[yyk] != YY_NULL)
    yystackp->yylastDeleted = yystackp->yytops.yystates[yyk];
  yystackp->yytops.yystates[yyk] = YY_NULL;
}

/** Undelete the last stack that was marked as deleted.  Can only be
    done once after a deletion, and only when all other stacks have
    been deleted.  */
static void
yyundeleteLastStack (yyGLRStack* yystackp)
{
  if (yystackp->yylastDeleted == YY_NULL || yystackp->yytops.yysize != 0)
    return;
  yystackp->yytops.yystates[0] = yystackp->yylastDeleted;
  yystackp->yytops.yysize = 1;
  YYDPRINTF ((stderr, "Restoring last deleted stack as stack #0.\n"));
  yystackp->yylastDeleted = YY_NULL;
}

static inline void
yyremoveDeletes (yyGLRStack* yystackp)
{
  size_t yyi, yyj;
  yyi = yyj = 0;
  while (yyj < yystackp->yytops.yysize)
    {
      if (yystackp->yytops.yystates[yyi] == YY_NULL)
        {
          if (yyi == yyj)
            {
              YYDPRINTF ((stderr, "Removing dead stacks.\n"));
            }
          yystackp->yytops.yysize -= 1;
        }
      else
        {
          yystackp->yytops.yystates[yyj] = yystackp->yytops.yystates[yyi];
          /* In the current implementation, it's unnecessary to copy
             yystackp->yytops.yylookaheadNeeds[yyi] since, after
             yyremoveDeletes returns, the parser immediately either enters
             deterministic operation or shifts a token.  However, it doesn't
             hurt, and the code might evolve to need it.  */
          yystackp->yytops.yylookaheadNeeds[yyj] =
            yystackp->yytops.yylookaheadNeeds[yyi];
          if (yyj != yyi)
            {
              YYDPRINTF ((stderr, "Rename stack %lu -> %lu.\n",
                          (unsigned long int) yyi, (unsigned long int) yyj));
            }
          yyj += 1;
        }
      yyi += 1;
    }
}

/** Shift to a new state on stack #K of STACK, corresponding to LR state
 * LRSTATE, at input position POSN, with (resolved) semantic value SVAL.  */
static inline void
yyglrShift (yyGLRStack* yystackp, size_t yyk, yyStateNum yylrState,
            size_t yyposn,
            YYSTYPE* yyvalp)
{
  yyGLRState* yynewState = &yynewGLRStackItem (yystackp, yytrue)->yystate;

  yynewState->yylrState = yylrState;
  yynewState->yyposn = yyposn;
  yynewState->yyresolved = yytrue;
  yynewState->yypred = yystackp->yytops.yystates[yyk];
  yynewState->yysemantics.yysval = *yyvalp;
  yystackp->yytops.yystates[yyk] = yynewState;

  YY_RESERVE_GLRSTACK (yystackp);
}

/** Shift stack #K of YYSTACK, to a new state corresponding to LR
 *  state YYLRSTATE, at input position YYPOSN, with the (unresolved)
 *  semantic value of YYRHS under the action for YYRULE.  */
static inline void
yyglrShiftDefer (yyGLRStack* yystackp, size_t yyk, yyStateNum yylrState,
                 size_t yyposn, yyGLRState* rhs, yyRuleNum yyrule)
{
  yyGLRState* yynewState = &yynewGLRStackItem (yystackp, yytrue)->yystate;

  yynewState->yylrState = yylrState;
  yynewState->yyposn = yyposn;
  yynewState->yyresolved = yyfalse;
  yynewState->yypred = yystackp->yytops.yystates[yyk];
  yynewState->yysemantics.yyfirstVal = YY_NULL;
  yystackp->yytops.yystates[yyk] = yynewState;

  /* Invokes YY_RESERVE_GLRSTACK.  */
  yyaddDeferredAction (yystackp, yyk, yynewState, rhs, yyrule);
}

/** Pop the symbols consumed by reduction #RULE from the top of stack
 *  #K of STACK, and perform the appropriate semantic action on their
 *  semantic values.  Assumes that all ambiguities in semantic values
 *  have been previously resolved.  Set *VALP to the resulting value,
 *  and *LOCP to the computed location (if any).  Return value is as
 *  for userAction.  */
static inline YYRESULTTAG
yydoAction (yyGLRStack* yystackp, size_t yyk, yyRuleNum yyrule,
            YYSTYPE* yyvalp)
{
  int yynrhs = yyrhsLength (yyrule);

  if (yystackp->yysplitPoint == YY_NULL)
    {
      /* Standard special case: single stack.  */
      yyGLRStackItem* rhs = (yyGLRStackItem*) yystackp->yytops.yystates[yyk];
      YYASSERT (yyk == 0);
      yystackp->yynextFree -= yynrhs;
      yystackp->yyspaceLeft += yynrhs;
      yystackp->yytops.yystates[0] = & yystackp->yynextFree[-1].yystate;
      return yyuserAction (yyrule, yynrhs, rhs, yystackp,
                           yyvalp);
    }
  else
    {
      /* At present, doAction is never called in nondeterministic
       * mode, so this branch is never taken.  It is here in
       * anticipation of a future feature that will allow immediate
       * evaluation of selected actions in nondeterministic mode.  */
      int yyi;
      yyGLRState* yys;
      yyGLRStackItem yyrhsVals[YYMAXRHS + YYMAXLEFT + 1];
      yys = yyrhsVals[YYMAXRHS + YYMAXLEFT].yystate.yypred
        = yystackp->yytops.yystates[yyk];
      for (yyi = 0; yyi < yynrhs; yyi += 1)
        {
          yys = yys->yypred;
          YYASSERT (yys);
        }
      yyupdateSplit (yystackp, yys);
      yystackp->yytops.yystates[yyk] = yys;
      return yyuserAction (yyrule, yynrhs, yyrhsVals + YYMAXRHS + YYMAXLEFT - 1,
                           yystackp, yyvalp);
    }
}

#if !YYDEBUG
# define YY_REDUCE_PRINT(Args)
#else
# define YY_REDUCE_PRINT(Args)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print Args;               \
} while (YYID (0))

/*----------------------------------------------------------.
| Report that the RULE is going to be reduced on stack #K.  |
`----------------------------------------------------------*/

/*ARGSUSED*/ static inline void
yy_reduce_print (yyGLRStack* yystackp, size_t yyk, yyRuleNum yyrule,
                 YYSTYPE* yyvalp)
{
  int yynrhs = yyrhsLength (yyrule);
  yybool yynormal __attribute__ ((__unused__)) =
    (yystackp->yysplitPoint == YY_NULL);
  yyGLRStackItem* yyvsp = (yyGLRStackItem*) yystackp->yytops.yystates[yyk];
  int yylow = 1;
  int yyi;
  YYUSE (yyvalp);
  YYFPRINTF (stderr, "Reducing stack %lu by rule %d (line %lu):\n",
             (unsigned long int) yyk, yyrule - 1,
             (unsigned long int) yyrline[yyrule]);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
                       &(((yyGLRStackItem const *)yyvsp)[YYFILL ((yyi + 1) - (yynrhs))].yystate.yysemantics.yysval)
                                              );
      YYFPRINTF (stderr, "\n");
    }
}
#endif

/** Pop items off stack #K of STACK according to grammar rule RULE,
 *  and push back on the resulting nonterminal symbol.  Perform the
 *  semantic action associated with RULE and store its value with the
 *  newly pushed state, if FORCEEVAL or if STACK is currently
 *  unambiguous.  Otherwise, store the deferred semantic action with
 *  the new state.  If the new state would have an identical input
 *  position, LR state, and predecessor to an existing state on the stack,
 *  it is identified with that existing state, eliminating stack #K from
 *  the STACK.  In this case, the (necessarily deferred) semantic value is
 *  added to the options for the existing state's semantic value.
 */
static inline YYRESULTTAG
yyglrReduce (yyGLRStack* yystackp, size_t yyk, yyRuleNum yyrule,
             yybool yyforceEval)
{
  size_t yyposn = yystackp->yytops.yystates[yyk]->yyposn;

  if (yyforceEval || yystackp->yysplitPoint == YY_NULL)
    {
      YYSTYPE yysval;

      YY_REDUCE_PRINT ((yystackp, yyk, yyrule, &yysval));
      YYCHK (yydoAction (yystackp, yyk, yyrule, &yysval));
      YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyrule], &yysval, &yyloc);
      yyglrShift (yystackp, yyk,
                  yyLRgotoState (yystackp->yytops.yystates[yyk]->yylrState,
                                 yylhsNonterm (yyrule)),
                  yyposn, &yysval);
    }
  else
    {
      size_t yyi;
      int yyn;
      yyGLRState* yys, *yys0 = yystackp->yytops.yystates[yyk];
      yyStateNum yynewLRState;

      for (yys = yystackp->yytops.yystates[yyk], yyn = yyrhsLength (yyrule);
           0 < yyn; yyn -= 1)
        {
          yys = yys->yypred;
          YYASSERT (yys);
        }
      yyupdateSplit (yystackp, yys);
      yynewLRState = yyLRgotoState (yys->yylrState, yylhsNonterm (yyrule));
      YYDPRINTF ((stderr,
                  "Reduced stack %lu by rule #%d; action deferred.  Now in state %d.\n",
                  (unsigned long int) yyk, yyrule - 1, yynewLRState));
      for (yyi = 0; yyi < yystackp->yytops.yysize; yyi += 1)
        if (yyi != yyk && yystackp->yytops.yystates[yyi] != YY_NULL)
          {
            yyGLRState *yysplit = yystackp->yysplitPoint;
            yyGLRState *yyp = yystackp->yytops.yystates[yyi];
            while (yyp != yys && yyp != yysplit && yyp->yyposn >= yyposn)
              {
                if (yyp->yylrState == yynewLRState && yyp->yypred == yys)
                  {
                    yyaddDeferredAction (yystackp, yyk, yyp, yys0, yyrule);
                    yymarkStackDeleted (yystackp, yyk);
                    YYDPRINTF ((stderr, "Merging stack %lu into stack %lu.\n",
                                (unsigned long int) yyk,
                                (unsigned long int) yyi));
                    return yyok;
                  }
                yyp = yyp->yypred;
              }
          }
      yystackp->yytops.yystates[yyk] = yys;
      yyglrShiftDefer (yystackp, yyk, yynewLRState, yyposn, yys0, yyrule);
    }
  return yyok;
}

static size_t
yysplitStack (yyGLRStack* yystackp, size_t yyk)
{
  if (yystackp->yysplitPoint == YY_NULL)
    {
      YYASSERT (yyk == 0);
      yystackp->yysplitPoint = yystackp->yytops.yystates[yyk];
    }
  if (yystackp->yytops.yysize >= yystackp->yytops.yycapacity)
    {
      yyGLRState** yynewStates;
      yybool* yynewLookaheadNeeds;

      yynewStates = YY_NULL;

      if (yystackp->yytops.yycapacity
          > (YYSIZEMAX / (2 * sizeof yynewStates[0])))
        yyMemoryExhausted (yystackp);
      yystackp->yytops.yycapacity *= 2;

      yynewStates =
        (yyGLRState**) YYREALLOC (yystackp->yytops.yystates,
                                  (yystackp->yytops.yycapacity
                                   * sizeof yynewStates[0]));
      if (yynewStates == YY_NULL)
        yyMemoryExhausted (yystackp);
      yystackp->yytops.yystates = yynewStates;

      yynewLookaheadNeeds =
        (yybool*) YYREALLOC (yystackp->yytops.yylookaheadNeeds,
                             (yystackp->yytops.yycapacity
                              * sizeof yynewLookaheadNeeds[0]));
      if (yynewLookaheadNeeds == YY_NULL)
        yyMemoryExhausted (yystackp);
      yystackp->yytops.yylookaheadNeeds = yynewLookaheadNeeds;
    }
  yystackp->yytops.yystates[yystackp->yytops.yysize]
    = yystackp->yytops.yystates[yyk];
  yystackp->yytops.yylookaheadNeeds[yystackp->yytops.yysize]
    = yystackp->yytops.yylookaheadNeeds[yyk];
  yystackp->yytops.yysize += 1;
  return yystackp->yytops.yysize-1;
}

/** True iff Y0 and Y1 represent identical options at the top level.
 *  That is, they represent the same rule applied to RHS symbols
 *  that produce the same terminal symbols.  */
static yybool
yyidenticalOptions (yySemanticOption* yyy0, yySemanticOption* yyy1)
{
  if (yyy0->yyrule == yyy1->yyrule)
    {
      yyGLRState *yys0, *yys1;
      int yyn;
      for (yys0 = yyy0->yystate, yys1 = yyy1->yystate,
           yyn = yyrhsLength (yyy0->yyrule);
           yyn > 0;
           yys0 = yys0->yypred, yys1 = yys1->yypred, yyn -= 1)
        if (yys0->yyposn != yys1->yyposn)
          return yyfalse;
      return yytrue;
    }
  else
    return yyfalse;
}

/** Assuming identicalOptions (Y0,Y1), destructively merge the
 *  alternative semantic values for the RHS-symbols of Y1 and Y0.  */
static void
yymergeOptionSets (yySemanticOption* yyy0, yySemanticOption* yyy1)
{
  yyGLRState *yys0, *yys1;
  int yyn;
  for (yys0 = yyy0->yystate, yys1 = yyy1->yystate,
       yyn = yyrhsLength (yyy0->yyrule);
       yyn > 0;
       yys0 = yys0->yypred, yys1 = yys1->yypred, yyn -= 1)
    {
      if (yys0 == yys1)
        break;
      else if (yys0->yyresolved)
        {
          yys1->yyresolved = yytrue;
          yys1->yysemantics.yysval = yys0->yysemantics.yysval;
        }
      else if (yys1->yyresolved)
        {
          yys0->yyresolved = yytrue;
          yys0->yysemantics.yysval = yys1->yysemantics.yysval;
        }
      else
        {
          yySemanticOption** yyz0p = &yys0->yysemantics.yyfirstVal;
          yySemanticOption* yyz1 = yys1->yysemantics.yyfirstVal;
          while (YYID (yytrue))
            {
              if (yyz1 == *yyz0p || yyz1 == YY_NULL)
                break;
              else if (*yyz0p == YY_NULL)
                {
                  *yyz0p = yyz1;
                  break;
                }
              else if (*yyz0p < yyz1)
                {
                  yySemanticOption* yyz = *yyz0p;
                  *yyz0p = yyz1;
                  yyz1 = yyz1->yynext;
                  (*yyz0p)->yynext = yyz;
                }
              yyz0p = &(*yyz0p)->yynext;
            }
          yys1->yysemantics.yyfirstVal = yys0->yysemantics.yyfirstVal;
        }
    }
}

/** Y0 and Y1 represent two possible actions to take in a given
 *  parsing state; return 0 if no combination is possible,
 *  1 if user-mergeable, 2 if Y0 is preferred, 3 if Y1 is preferred.  */
static int
yypreference (yySemanticOption* y0, yySemanticOption* y1)
{
  yyRuleNum r0 = y0->yyrule, r1 = y1->yyrule;
  int p0 = yydprec[r0], p1 = yydprec[r1];

  if (p0 == p1)
    {
      if (yymerger[r0] == 0 || yymerger[r0] != yymerger[r1])
        return 0;
      else
        return 1;
    }
  if (p0 == 0 || p1 == 0)
    return 0;
  if (p0 < p1)
    return 3;
  if (p1 < p0)
    return 2;
  return 0;
}

static YYRESULTTAG yyresolveValue (yyGLRState* yys,
                                   yyGLRStack* yystackp);


/** Resolve the previous N states starting at and including state S.  If result
 *  != yyok, some states may have been left unresolved possibly with empty
 *  semantic option chains.  Regardless of whether result = yyok, each state
 *  has been left with consistent data so that yydestroyGLRState can be invoked
 *  if necessary.  */
static YYRESULTTAG
yyresolveStates (yyGLRState* yys, int yyn,
                 yyGLRStack* yystackp)
{
  if (0 < yyn)
    {
      YYASSERT (yys->yypred);
      YYCHK (yyresolveStates (yys->yypred, yyn-1, yystackp));
      if (! yys->yyresolved)
        YYCHK (yyresolveValue (yys, yystackp));
    }
  return yyok;
}

/** Resolve the states for the RHS of OPT, perform its user action, and return
 *  the semantic value and location.  Regardless of whether result = yyok, all
 *  RHS states have been destroyed (assuming the user action destroys all RHS
 *  semantic values if invoked).  */
static YYRESULTTAG
yyresolveAction (yySemanticOption* yyopt, yyGLRStack* yystackp,
                 YYSTYPE* yyvalp)
{
  yyGLRStackItem yyrhsVals[YYMAXRHS + YYMAXLEFT + 1];
  int yynrhs = yyrhsLength (yyopt->yyrule);
  YYRESULTTAG yyflag =
    yyresolveStates (yyopt->yystate, yynrhs, yystackp);
  if (yyflag != yyok)
    {
      yyGLRState *yys;
      for (yys = yyopt->yystate; yynrhs > 0; yys = yys->yypred, yynrhs -= 1)
        yydestroyGLRState ("Cleanup: popping", yys);
      return yyflag;
    }

  yyrhsVals[YYMAXRHS + YYMAXLEFT].yystate.yypred = yyopt->yystate;
  {
    int yychar_current = yychar;
    YYSTYPE yylval_current = yylval;
    yychar = yyopt->yyrawchar;
    yylval = yyopt->yyval;
    yyflag = yyuserAction (yyopt->yyrule, yynrhs,
                           yyrhsVals + YYMAXRHS + YYMAXLEFT - 1,
                           yystackp, yyvalp);
    yychar = yychar_current;
    yylval = yylval_current;
  }
  return yyflag;
}

#if YYDEBUG
static void
yyreportTree (yySemanticOption* yyx, int yyindent)
{
  int yynrhs = yyrhsLength (yyx->yyrule);
  int yyi;
  yyGLRState* yys;
  yyGLRState* yystates[1 + YYMAXRHS];
  yyGLRState yyleftmost_state;

  for (yyi = yynrhs, yys = yyx->yystate; 0 < yyi; yyi -= 1, yys = yys->yypred)
    yystates[yyi] = yys;
  if (yys == YY_NULL)
    {
      yyleftmost_state.yyposn = 0;
      yystates[0] = &yyleftmost_state;
    }
  else
    yystates[0] = yys;

  if (yyx->yystate->yyposn < yys->yyposn + 1)
    YYFPRINTF (stderr, "%*s%s -> <Rule %d, empty>\n",
               yyindent, "", yytokenName (yylhsNonterm (yyx->yyrule)),
               yyx->yyrule - 1);
  else
    YYFPRINTF (stderr, "%*s%s -> <Rule %d, tokens %lu .. %lu>\n",
               yyindent, "", yytokenName (yylhsNonterm (yyx->yyrule)),
               yyx->yyrule - 1, (unsigned long int) (yys->yyposn + 1),
               (unsigned long int) yyx->yystate->yyposn);
  for (yyi = 1; yyi <= yynrhs; yyi += 1)
    {
      if (yystates[yyi]->yyresolved)
        {
          if (yystates[yyi-1]->yyposn+1 > yystates[yyi]->yyposn)
            YYFPRINTF (stderr, "%*s%s <empty>\n", yyindent+2, "",
                       yytokenName (yyrhs[yyprhs[yyx->yyrule]+yyi-1]));
          else
            YYFPRINTF (stderr, "%*s%s <tokens %lu .. %lu>\n", yyindent+2, "",
                       yytokenName (yyrhs[yyprhs[yyx->yyrule]+yyi-1]),
                       (unsigned long int) (yystates[yyi - 1]->yyposn + 1),
                       (unsigned long int) yystates[yyi]->yyposn);
        }
      else
        yyreportTree (yystates[yyi]->yysemantics.yyfirstVal, yyindent+2);
    }
}
#endif

/*ARGSUSED*/ static YYRESULTTAG
yyreportAmbiguity (yySemanticOption* yyx0,
                   yySemanticOption* yyx1)
{
  YYUSE (yyx0);
  YYUSE (yyx1);

#if YYDEBUG
  YYFPRINTF (stderr, "Ambiguity detected.\n");
  YYFPRINTF (stderr, "Option 1,\n");
  yyreportTree (yyx0, 2);
  YYFPRINTF (stderr, "\nOption 2,\n");
  yyreportTree (yyx1, 2);
  YYFPRINTF (stderr, "\n");
#endif

  yyerror (YY_("syntax is ambiguous"));
  return yyabort;
}

/** Resolve the ambiguity represented in state S, perform the indicated
 *  actions, and set the semantic value of S.  If result != yyok, the chain of
 *  semantic options in S has been cleared instead or it has been left
 *  unmodified except that redundant options may have been removed.  Regardless
 *  of whether result = yyok, S has been left with consistent data so that
 *  yydestroyGLRState can be invoked if necessary.  */
static YYRESULTTAG
yyresolveValue (yyGLRState* yys, yyGLRStack* yystackp)
{
  yySemanticOption* yyoptionList = yys->yysemantics.yyfirstVal;
  yySemanticOption* yybest = yyoptionList;
  yySemanticOption** yypp;
  yybool yymerge = yyfalse;
  YYSTYPE yysval;
  YYRESULTTAG yyflag;

  for (yypp = &yyoptionList->yynext; *yypp != YY_NULL; )
    {
      yySemanticOption* yyp = *yypp;

      if (yyidenticalOptions (yybest, yyp))
        {
          yymergeOptionSets (yybest, yyp);
          *yypp = yyp->yynext;
        }
      else
        {
          switch (yypreference (yybest, yyp))
            {
            case 0:
              return yyreportAmbiguity (yybest, yyp);
              break;
            case 1:
              yymerge = yytrue;
              break;
            case 2:
              break;
            case 3:
              yybest = yyp;
              yymerge = yyfalse;
              break;
            default:
              /* This cannot happen so it is not worth a YYASSERT (yyfalse),
                 but some compilers complain if the default case is
                 omitted.  */
              break;
            }
          yypp = &yyp->yynext;
        }
    }

  if (yymerge)
    {
      yySemanticOption* yyp;
      int yyprec = yydprec[yybest->yyrule];
      yyflag = yyresolveAction (yybest, yystackp, &yysval);
      if (yyflag == yyok)
        for (yyp = yybest->yynext; yyp != YY_NULL; yyp = yyp->yynext)
          {
            if (yyprec == yydprec[yyp->yyrule])
              {
                YYSTYPE yysval_other;
                yyflag = yyresolveAction (yyp, yystackp, &yysval_other);
                if (yyflag != yyok)
                  {
                    yydestruct ("Cleanup: discarding incompletely merged value for",
                                yystos[yys->yylrState],
                                &yysval);
                    break;
                  }
                yyuserMerge (yymerger[yyp->yyrule], &yysval, &yysval_other);
              }
          }
    }
  else
    yyflag = yyresolveAction (yybest, yystackp, &yysval);

  if (yyflag == yyok)
    {
      yys->yyresolved = yytrue;
      yys->yysemantics.yysval = yysval;
    }
  else
    yys->yysemantics.yyfirstVal = YY_NULL;
  return yyflag;
}

static YYRESULTTAG
yyresolveStack (yyGLRStack* yystackp)
{
  if (yystackp->yysplitPoint != YY_NULL)
    {
      yyGLRState* yys;
      int yyn;

      for (yyn = 0, yys = yystackp->yytops.yystates[0];
           yys != yystackp->yysplitPoint;
           yys = yys->yypred, yyn += 1)
        continue;
      YYCHK (yyresolveStates (yystackp->yytops.yystates[0], yyn, yystackp
                             ));
    }
  return yyok;
}

static void
yycompressStack (yyGLRStack* yystackp)
{
  yyGLRState* yyp, *yyq, *yyr;

  if (yystackp->yytops.yysize != 1 || yystackp->yysplitPoint == YY_NULL)
    return;

  for (yyp = yystackp->yytops.yystates[0], yyq = yyp->yypred, yyr = YY_NULL;
       yyp != yystackp->yysplitPoint;
       yyr = yyp, yyp = yyq, yyq = yyp->yypred)
    yyp->yypred = yyr;

  yystackp->yyspaceLeft += yystackp->yynextFree - yystackp->yyitems;
  yystackp->yynextFree = ((yyGLRStackItem*) yystackp->yysplitPoint) + 1;
  yystackp->yyspaceLeft -= yystackp->yynextFree - yystackp->yyitems;
  yystackp->yysplitPoint = YY_NULL;
  yystackp->yylastDeleted = YY_NULL;

  while (yyr != YY_NULL)
    {
      yystackp->yynextFree->yystate = *yyr;
      yyr = yyr->yypred;
      yystackp->yynextFree->yystate.yypred = &yystackp->yynextFree[-1].yystate;
      yystackp->yytops.yystates[0] = &yystackp->yynextFree->yystate;
      yystackp->yynextFree += 1;
      yystackp->yyspaceLeft -= 1;
    }
}

static YYRESULTTAG
yyprocessOneStack (yyGLRStack* yystackp, size_t yyk,
                   size_t yyposn)
{
  int yyaction;
  const short int* yyconflicts;
  yyRuleNum yyrule;

  while (yystackp->yytops.yystates[yyk] != YY_NULL)
    {
      yyStateNum yystate = yystackp->yytops.yystates[yyk]->yylrState;
      YYDPRINTF ((stderr, "Stack %lu Entering state %d\n",
                  (unsigned long int) yyk, yystate));

      YYASSERT (yystate != YYFINAL);

      if (yyisDefaultedState (yystate))
        {
          yyrule = yydefaultAction (yystate);
          if (yyrule == 0)
            {
              YYDPRINTF ((stderr, "Stack %lu dies.\n",
                          (unsigned long int) yyk));
              yymarkStackDeleted (yystackp, yyk);
              return yyok;
            }
          YYCHK (yyglrReduce (yystackp, yyk, yyrule, yyfalse));
        }
      else
        {
          yySymbol yytoken;
          yystackp->yytops.yylookaheadNeeds[yyk] = yytrue;
          if (yychar == YYEMPTY)
            {
              YYDPRINTF ((stderr, "Reading a token: "));
              yychar = YYLEX;
            }

          if (yychar <= YYEOF)
            {
              yychar = yytoken = YYEOF;
              YYDPRINTF ((stderr, "Now at end of input.\n"));
            }
          else
            {
              yytoken = YYTRANSLATE (yychar);
              YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
            }

          yygetLRActions (yystate, yytoken, &yyaction, &yyconflicts);

          while (*yyconflicts != 0)
            {
              size_t yynewStack = yysplitStack (yystackp, yyk);
              YYDPRINTF ((stderr, "Splitting off stack %lu from %lu.\n",
                          (unsigned long int) yynewStack,
                          (unsigned long int) yyk));
              YYCHK (yyglrReduce (yystackp, yynewStack,
                                  *yyconflicts, yyfalse));
              YYCHK (yyprocessOneStack (yystackp, yynewStack,
                                        yyposn));
              yyconflicts += 1;
            }

          if (yyisShiftAction (yyaction))
            break;
          else if (yyisErrorAction (yyaction))
            {
              YYDPRINTF ((stderr, "Stack %lu dies.\n",
                          (unsigned long int) yyk));
              yymarkStackDeleted (yystackp, yyk);
              break;
            }
          else
            YYCHK (yyglrReduce (yystackp, yyk, -yyaction,
                                yyfalse));
        }
    }
  return yyok;
}

/*ARGSUSED*/ static void
yyreportSyntaxError (yyGLRStack* yystackp)
{
  if (yystackp->yyerrState != 0)
    return;
#if ! YYERROR_VERBOSE
  yyerror (YY_("syntax error"));
#else
  yySymbol yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);
  size_t yysize0 = yytnamerr (YY_NULL, yytokenName (yytoken));
  size_t yysize = yysize0;
  size_t yysize1;
  yybool yysize_overflow = yyfalse;
  char* yymsg = YY_NULL;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULL;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected").  */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[yystackp->yytops.yystates[0]->yylrState];
      yyarg[yycount++] = yytokenName (yytoken);
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for this
             state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;
          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytokenName (yyx);
                yysize1 = yysize + yytnamerr (YY_NULL, yytokenName (yyx));
                yysize_overflow |= yysize1 < yysize;
                yysize = yysize1;
              }
        }
    }

  switch (yycount)
    {
#define YYCASE_(N, S)                   \
      case N:                           \
        yyformat = S;                   \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
    }

  yysize1 = yysize + strlen (yyformat);
  yysize_overflow |= yysize1 < yysize;
  yysize = yysize1;

  if (!yysize_overflow)
    yymsg = (char *) YYMALLOC (yysize);

  if (yymsg)
    {
      char *yyp = yymsg;
      int yyi = 0;
      while ((*yyp = *yyformat))
        {
          if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
            {
              yyp += yytnamerr (yyp, yyarg[yyi++]);
              yyformat += 2;
            }
          else
            {
              yyp++;
              yyformat++;
            }
        }
      yyerror (yymsg);
      YYFREE (yymsg);
    }
  else
    {
      yyerror (YY_("syntax error"));
      yyMemoryExhausted (yystackp);
    }
#endif /* YYERROR_VERBOSE */
  yynerrs += 1;
}

/* Recover from a syntax error on *YYSTACKP, assuming that *YYSTACKP->YYTOKENP,
   yylval, and yylloc are the syntactic category, semantic value, and location
   of the lookahead.  */
/*ARGSUSED*/ static void
yyrecoverSyntaxError (yyGLRStack* yystackp)
{
  size_t yyk;
  int yyj;

  if (yystackp->yyerrState == 3)
    /* We just shifted the error token and (perhaps) took some
       reductions.  Skip tokens until we can proceed.  */
    while (YYID (yytrue))
      {
        yySymbol yytoken;
        if (yychar == YYEOF)
          yyFail (yystackp, YY_NULL);
        if (yychar != YYEMPTY)
          {
            yytoken = YYTRANSLATE (yychar);
            yydestruct ("Error: discarding",
                        yytoken, &yylval);
          }
        YYDPRINTF ((stderr, "Reading a token: "));
        yychar = YYLEX;
        if (yychar <= YYEOF)
          {
            yychar = yytoken = YYEOF;
            YYDPRINTF ((stderr, "Now at end of input.\n"));
          }
        else
          {
            yytoken = YYTRANSLATE (yychar);
            YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
          }
        yyj = yypact[yystackp->yytops.yystates[0]->yylrState];
        if (yypact_value_is_default (yyj))
          return;
        yyj += yytoken;
        if (yyj < 0 || YYLAST < yyj || yycheck[yyj] != yytoken)
          {
            if (yydefact[yystackp->yytops.yystates[0]->yylrState] != 0)
              return;
          }
        else if (! yytable_value_is_error (yytable[yyj]))
          return;
      }

  /* Reduce to one stack.  */
  for (yyk = 0; yyk < yystackp->yytops.yysize; yyk += 1)
    if (yystackp->yytops.yystates[yyk] != YY_NULL)
      break;
  if (yyk >= yystackp->yytops.yysize)
    yyFail (yystackp, YY_NULL);
  for (yyk += 1; yyk < yystackp->yytops.yysize; yyk += 1)
    yymarkStackDeleted (yystackp, yyk);
  yyremoveDeletes (yystackp);
  yycompressStack (yystackp);

  /* Now pop stack until we find a state that shifts the error token.  */
  yystackp->yyerrState = 3;
  while (yystackp->yytops.yystates[0] != YY_NULL)
    {
      yyGLRState *yys = yystackp->yytops.yystates[0];
      yyj = yypact[yys->yylrState];
      if (! yypact_value_is_default (yyj))
        {
          yyj += YYTERROR;
          if (0 <= yyj && yyj <= YYLAST && yycheck[yyj] == YYTERROR
              && yyisShiftAction (yytable[yyj]))
            {
              /* Shift the error token.  */
              YY_SYMBOL_PRINT ("Shifting", yystos[yytable[yyj]],
                               &yylval, &yyerrloc);
              yyglrShift (yystackp, 0, yytable[yyj],
                          yys->yyposn, &yylval);
              yys = yystackp->yytops.yystates[0];
              break;
            }
        }
      if (yys->yypred != YY_NULL)
        yydestroyGLRState ("Error: popping", yys);
      yystackp->yytops.yystates[0] = yys->yypred;
      yystackp->yynextFree -= 1;
      yystackp->yyspaceLeft += 1;
    }
  if (yystackp->yytops.yystates[0] == YY_NULL)
    yyFail (yystackp, YY_NULL);
}

#define YYCHK1(YYE)                                                          \
  do {                                                                       \
    switch (YYE) {                                                           \
    case yyok:                                                               \
      break;                                                                 \
    case yyabort:                                                            \
      goto yyabortlab;                                                       \
    case yyaccept:                                                           \
      goto yyacceptlab;                                                      \
    case yyerr:                                                              \
      goto yyuser_error;                                                     \
    default:                                                                 \
      goto yybuglab;                                                         \
    }                                                                        \
  } while (YYID (0))


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
  int yyresult;
  yyGLRStack yystack;
  yyGLRStack* const yystackp = &yystack;
  size_t yyposn;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY;
  yylval = yyval_default;


  if (! yyinitGLRStack (yystackp, YYINITDEPTH))
    goto yyexhaustedlab;
  switch (YYSETJMP (yystack.yyexception_buffer))
    {
    case 0: break;
    case 1: goto yyabortlab;
    case 2: goto yyexhaustedlab;
    default: goto yybuglab;
    }
  yyglrShift (&yystack, 0, 0, 0, &yylval);
  yyposn = 0;

  while (YYID (yytrue))
    {
      /* For efficiency, we have two loops, the first of which is
         specialized to deterministic operation (single stack, no
         potential ambiguity).  */
      /* Standard mode */
      while (YYID (yytrue))
        {
          yyRuleNum yyrule;
          int yyaction;
          const short int* yyconflicts;

          yyStateNum yystate = yystack.yytops.yystates[0]->yylrState;
          YYDPRINTF ((stderr, "Entering state %d\n", yystate));
          if (yystate == YYFINAL)
            goto yyacceptlab;
          if (yyisDefaultedState (yystate))
            {
              yyrule = yydefaultAction (yystate);
              if (yyrule == 0)
                {

                  yyreportSyntaxError (&yystack);
                  goto yyuser_error;
                }
              YYCHK1 (yyglrReduce (&yystack, 0, yyrule, yytrue));
            }
          else
            {
              yySymbol yytoken;
              if (yychar == YYEMPTY)
                {
                  YYDPRINTF ((stderr, "Reading a token: "));
                  yychar = YYLEX;
                }

              if (yychar <= YYEOF)
                {
                  yychar = yytoken = YYEOF;
                  YYDPRINTF ((stderr, "Now at end of input.\n"));
                }
              else
                {
                  yytoken = YYTRANSLATE (yychar);
                  YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
                }

              yygetLRActions (yystate, yytoken, &yyaction, &yyconflicts);
              if (*yyconflicts != 0)
                break;
              if (yyisShiftAction (yyaction))
                {
                  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
                  yychar = YYEMPTY;
                  yyposn += 1;
                  yyglrShift (&yystack, 0, yyaction, yyposn, &yylval);
                  if (0 < yystack.yyerrState)
                    yystack.yyerrState -= 1;
                }
              else if (yyisErrorAction (yyaction))
                {

                  yyreportSyntaxError (&yystack);
                  goto yyuser_error;
                }
              else
                YYCHK1 (yyglrReduce (&yystack, 0, -yyaction, yytrue));
            }
        }

      while (YYID (yytrue))
        {
          yySymbol yytoken_to_shift;
          size_t yys;

          for (yys = 0; yys < yystack.yytops.yysize; yys += 1)
            yystackp->yytops.yylookaheadNeeds[yys] = yychar != YYEMPTY;

          /* yyprocessOneStack returns one of three things:

              - An error flag.  If the caller is yyprocessOneStack, it
                immediately returns as well.  When the caller is finally
                yyparse, it jumps to an error label via YYCHK1.

              - yyok, but yyprocessOneStack has invoked yymarkStackDeleted
                (&yystack, yys), which sets the top state of yys to NULL.  Thus,
                yyparse's following invocation of yyremoveDeletes will remove
                the stack.

              - yyok, when ready to shift a token.

             Except in the first case, yyparse will invoke yyremoveDeletes and
             then shift the next token onto all remaining stacks.  This
             synchronization of the shift (that is, after all preceding
             reductions on all stacks) helps prevent double destructor calls
             on yylval in the event of memory exhaustion.  */

          for (yys = 0; yys < yystack.yytops.yysize; yys += 1)
            YYCHK1 (yyprocessOneStack (&yystack, yys, yyposn));
          yyremoveDeletes (&yystack);
          if (yystack.yytops.yysize == 0)
            {
              yyundeleteLastStack (&yystack);
              if (yystack.yytops.yysize == 0)
                yyFail (&yystack, YY_("syntax error"));
              YYCHK1 (yyresolveStack (&yystack));
              YYDPRINTF ((stderr, "Returning to deterministic operation.\n"));

              yyreportSyntaxError (&yystack);
              goto yyuser_error;
            }

          /* If any yyglrShift call fails, it will fail after shifting.  Thus,
             a copy of yylval will already be on stack 0 in the event of a
             failure in the following loop.  Thus, yychar is set to YYEMPTY
             before the loop to make sure the user destructor for yylval isn't
             called twice.  */
          yytoken_to_shift = YYTRANSLATE (yychar);
          yychar = YYEMPTY;
          yyposn += 1;
          for (yys = 0; yys < yystack.yytops.yysize; yys += 1)
            {
              int yyaction;
              const short int* yyconflicts;
              yyStateNum yystate = yystack.yytops.yystates[yys]->yylrState;
              yygetLRActions (yystate, yytoken_to_shift, &yyaction,
                              &yyconflicts);
              /* Note that yyconflicts were handled by yyprocessOneStack.  */
              YYDPRINTF ((stderr, "On stack %lu, ", (unsigned long int) yys));
              YY_SYMBOL_PRINT ("shifting", yytoken_to_shift, &yylval, &yylloc);
              yyglrShift (&yystack, yys, yyaction, yyposn,
                          &yylval);
              YYDPRINTF ((stderr, "Stack %lu now in state #%d\n",
                          (unsigned long int) yys,
                          yystack.yytops.yystates[yys]->yylrState));
            }

          if (yystack.yytops.yysize == 1)
            {
              YYCHK1 (yyresolveStack (&yystack));
              YYDPRINTF ((stderr, "Returning to deterministic operation.\n"));
              yycompressStack (&yystack);
              break;
            }
        }
      continue;
    yyuser_error:
      yyrecoverSyntaxError (&yystack);
      yyposn = yystack.yytops.yystates[0]->yyposn;
    }

 yyacceptlab:
  yyresult = 0;
  goto yyreturn;

 yybuglab:
  YYASSERT (yyfalse);
  goto yyabortlab;

 yyabortlab:
  yyresult = 1;
  goto yyreturn;

 yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturn;

 yyreturn:
  if (yychar != YYEMPTY)
    yydestruct ("Cleanup: discarding lookahead",
                YYTRANSLATE (yychar), &yylval);

  /* If the stack is well-formed, pop the stack until it is empty,
     destroying its entries as we go.  But free the stack regardless
     of whether it is well-formed.  */
  if (yystack.yyitems)
    {
      yyGLRState** yystates = yystack.yytops.yystates;
      if (yystates)
        {
          size_t yysize = yystack.yytops.yysize;
          size_t yyk;
          for (yyk = 0; yyk < yysize; yyk += 1)
            if (yystates[yyk])
              {
                while (yystates[yyk])
                  {
                    yyGLRState *yys = yystates[yyk];
                  if (yys->yypred != YY_NULL)
                      yydestroyGLRState ("Cleanup: popping", yys);
                    yystates[yyk] = yys->yypred;
                    yystack.yynextFree -= 1;
                    yystack.yyspaceLeft += 1;
                  }
                break;
              }
        }
      yyfreeGLRStack (&yystack);
    }

  /* Make sure YYID is used.  */
  return YYID (yyresult);
}

/* DEBUGGING ONLY */
#if YYDEBUG
static void yypstack (yyGLRStack* yystackp, size_t yyk)
  __attribute__ ((__unused__));
static void yypdumpstack (yyGLRStack* yystackp) __attribute__ ((__unused__));

static void
yy_yypstack (yyGLRState* yys)
{
  if (yys->yypred)
    {
      yy_yypstack (yys->yypred);
      YYFPRINTF (stderr, " -> ");
    }
  YYFPRINTF (stderr, "%d@%lu", yys->yylrState,
             (unsigned long int) yys->yyposn);
}

static void
yypstates (yyGLRState* yyst)
{
  if (yyst == YY_NULL)
    YYFPRINTF (stderr, "<null>");
  else
    yy_yypstack (yyst);
  YYFPRINTF (stderr, "\n");
}

static void
yypstack (yyGLRStack* yystackp, size_t yyk)
{
  yypstates (yystackp->yytops.yystates[yyk]);
}

#define YYINDEX(YYX)                                                         \
    ((YYX) == YY_NULL ? -1 : (yyGLRStackItem*) (YYX) - yystackp->yyitems)


static void
yypdumpstack (yyGLRStack* yystackp)
{
  yyGLRStackItem* yyp;
  size_t yyi;
  for (yyp = yystackp->yyitems; yyp < yystackp->yynextFree; yyp += 1)
    {
      YYFPRINTF (stderr, "%3lu. ",
                 (unsigned long int) (yyp - yystackp->yyitems));
      if (*(yybool *) yyp)
        {
          YYFPRINTF (stderr, "Res: %d, LR State: %d, posn: %lu, pred: %ld",
                     yyp->yystate.yyresolved, yyp->yystate.yylrState,
                     (unsigned long int) yyp->yystate.yyposn,
                     (long int) YYINDEX (yyp->yystate.yypred));
          if (! yyp->yystate.yyresolved)
            YYFPRINTF (stderr, ", firstVal: %ld",
                       (long int) YYINDEX (yyp->yystate
                                             .yysemantics.yyfirstVal));
        }
      else
        {
          YYFPRINTF (stderr, "Option. rule: %d, state: %ld, next: %ld",
                     yyp->yyoption.yyrule - 1,
                     (long int) YYINDEX (yyp->yyoption.yystate),
                     (long int) YYINDEX (yyp->yyoption.yynext));
        }
      YYFPRINTF (stderr, "\n");
    }
  YYFPRINTF (stderr, "Tops:");
  for (yyi = 0; yyi < yystackp->yytops.yysize; yyi += 1)
    YYFPRINTF (stderr, "%lu: %ld; ", (unsigned long int) yyi,
               (long int) YYINDEX (yystackp->yytops.yystates[yyi]));
  YYFPRINTF (stderr, "\n");
}
#endif



/* Line 2606 of glr.c  */
#line 1407 "apyc-parser.y"



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

