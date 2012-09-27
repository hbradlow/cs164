/* A Bison parser, made by GNU Bison 2.6.  */

/* Bison implementation for Yacc-like parsers in C
   
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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.6"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* "%code top" blocks.  */

/* Line 314 of yacc.c  */
#line 4 "apyc-parser.y"


#define YYPARAM Tree_Semantics< AST >
#define YYPRODUCING_TREES
#define YYERROR_FUNCTION_NAME error

# define YY_PARSER_1
# include "horn-parse-lex.cc"



/* Line 314 of yacc.c  */
#line 78 "apyc-parser.cc"



/* Copy the first part of user declarations.  */

/* Line 336 of yacc.c  */
#line 14 "apyc-parser.y"


    YYNAMESPACE_OPEN


/* Line 336 of yacc.c  */
#line 13 "apyc.hn"

  #include <string>
  #include "apyc.h"
  #include "ast.h"
#include <cstdio>
#include <cstdlib>
#include <string>

  using namespace std;

  static AST_Ptr theTree;


/* Line 336 of yacc.c  */
#line 133 "apyc-parser.y"


#define YY_PARSER_2
#include "horn-parse-lex.cc"


/* Line 336 of yacc.c  */
#line 156 "apyc-parser.y"

static yyvar yyv_ASSIGN;
static yyvar yyv_COLON;
static yyvar yyv_COMMA;
static yyvar yyv_COMPARE;
static yyvar yyv_DEDENT;
static yyvar yyv_DEF;
static yyvar yyv_EMPTY;
static yyvar yyv_EQUALS;
static yyvar yyv_FOR;
static yyvar yyv_FUNCTION_NAME;
static yyvar yyv_GT;
static yyvar yyv_GTE;
static yyvar yyv_ID;
static yyvar yyv_IN;
static yyvar yyv_INDENT;
static yyvar yyv_INT_LITERAL;
static yyvar yyv_ITERABLE;
static yyvar yyv_LPAREN;
static yyvar yyv_LT;
static yyvar yyv_LTE;
static yyvar yyv_RPAREN;
static yyvar yyv_STRING_LITERAL;
static yyvar yyv_WHILE;
static yyvar yyv_bool_stmt;
static yyvar yyv_def_stmt;
static yyvar yyv_dict;
static yyvar yyv_elif_stmt;
static yyvar yyv_expr_list;
static yyvar yyv_expression;
static yyvar yyv_expression_list;
static yyvar yyv_file;
static yyvar yyv_for_stmt;
static yyvar yyv_if_stmt;
static yyvar yyv_list;
static yyvar yyv_literal;
static yyvar yyv_parameter;
static yyvar yyv_parameter_list;
static yyvar yyv_print_stmt;
static yyvar yyv_stmt;
static yyvar yyv_stmt_list;
static yyvar yyv_string;
static yyvar yyv_tuple;
static yyvar yyv_while_stmt;



/* Line 336 of yacc.c  */
#line 164 "apyc-parser.cc"

# ifndef YY_NULL
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULL nullptr
#  else
#   define YY_NULL 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "apyc-parser.hh".  */
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
     LITERAL = 264,
     MODULE = 265,
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
     NUMERIC_LITERAL = 289,
     STRING_LITERAL = 290,
     TUPLE = 291,
     INT_LITERAL = 292,
     _TOK_1 = 293,
     _TOK_2 = 294,
     _TOK_0 = 295,
     _TOK_3 = 296,
     RAWSTRING = 297
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

/* Copy the second part of user declarations.  */


/* Line 353 of yacc.c  */
#line 273 "apyc-parser.cc"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  31
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   83

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  47
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  17
/* YYNRULES -- Number of rules.  */
#define YYNRULES  34
/* YYNRULES -- Number of states.  */
#define YYNSTATES  84

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   297

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      41,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      38,    39,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    40,     2,
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
      35,    36,    37,    42,    43,    44,    45,    46
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     5,     8,    10,    12,    14,    16,    18,
      20,    28,    36,    38,    45,    49,    53,    55,    62,    71,
      81,    85,    87,    89,    93,    95,    97,    99,   102,   106,
     109,   110,   113,   116,   117
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      48,     0,    -1,    49,    -1,    50,    49,    -1,     7,    -1,
      51,    -1,    54,    -1,    56,    -1,    55,    -1,    60,    -1,
      44,    53,    40,    29,    49,    25,    52,    -1,    42,    53,
      40,    29,    49,    25,    52,    -1,     7,    -1,    43,    53,
      40,    29,    49,    25,    -1,    60,    17,    53,    -1,    38,
      53,    39,    -1,    60,    -1,    30,    53,    16,    29,    49,
      25,    -1,    27,     5,    28,    13,    16,    29,    49,    25,
      -1,    26,    32,    14,    57,    15,    16,    29,    49,    25,
      -1,    58,    24,    57,    -1,    58,    -1,     5,    -1,     5,
      18,    60,    -1,    37,    -1,    35,    -1,    59,    -1,    32,
      61,    -1,     5,    18,    60,    -1,    60,    63,    -1,    -1,
      62,    41,    -1,    45,    61,    -1,    -1,    63,    24,    60,
      -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
<<<<<<< HEAD
       0,   107,   107,   112,   112,   113,   113,   113,   113,   113,
     115,   116,   116,   116,   118,   118,   118,   119,   120,   122,
     123,   123,   124,   124,   128,   128,   129,   134,   134,   138,
     141,   141,   141,   148,   149,   155,   158,   162,   148
=======
       0,   113,   113,   118,   118,   119,   119,   119,   119,   119,
     121,   122,   122,   122,   124,   124,   124,   125,   126,   128,
     129,   129,   130,   130,   137,   137,   143,   143,   143,   150,
     151,   158,   161,   165,   150
>>>>>>> e42dd43ea0197ce3b5ac24edba37c739fd822d7e
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INT", "STRING", "ID", "\"@println\"",
  "EMPTY", "\"@expr_list\"", "\"@literal\"", "\"@module\"", "\"@if_stmt\"",
  "\"@boolean_stmt\"", "\"@iterable\"", "\"@(\"", "\"@)\"", "\"@:\"",
  "\"@compare\"", "\"@=\"", "\"@==\"", "\"@>\"", "\"@<\"", "\"@>=\"",
  "\"@<=\"", "\",\"", "DEDENT", "DEF", "FOR", "IN", "INDENT", "WHILE",
  "DICT", "FUNCTION_NAME", "LIST", "NUMERIC_LITERAL", "STRING_LITERAL",
  "TUPLE", "INT_LITERAL", "\"(\"", "\")\"", "\":\"", "\"\\n\"", "\"elif\"",
  "\"else\"", "\"if\"", "\"print\"", "RAWSTRING", "$accept", "program",
  "stmt_list", "stmt", "if_stmt", "elif_stmt", "bool_stmt", "while_stmt",
  "for_stmt", "def_stmt", "parameter_list", "parameter", "literal",
  "expression", "expression_list", "print_stmt", "__0", YY_NULL
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,    40,    41,
      58,    10,   293,   294,   295,   296,   297
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    47,    48,    49,    49,    50,    50,    50,    50,    50,
      51,    52,    52,    52,    53,    53,    53,    54,    55,    56,
      57,    57,    58,    58,    59,    59,    60,    60,    60,    61,
      61,    49,    62,    63,    63
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     1,     1,
       7,     7,     1,     6,     3,     3,     1,     6,     8,     9,
       3,     1,     1,     3,     1,     1,     1,     2,     3,     2,
       0,     2,     2,     0,     3
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     4,     0,     0,     0,    30,    25,    24,     0,
      30,     0,     2,     0,     5,     6,     8,     7,    26,     9,
       0,     0,     0,     0,     0,     0,    16,    33,    27,     0,
      32,     1,     3,    31,    28,     0,     0,     0,     0,     0,
      29,     0,    22,     0,    21,     0,    15,     0,    14,     0,
       0,     0,     0,     0,     0,     0,    34,     0,    23,     0,
      20,     0,    17,     0,     0,     0,    12,     0,     0,    10,
       0,    18,     0,     0,    19,     0,     0,     0,     0,     0,
       0,     0,    13,    11
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,    11,    12,    13,    14,    69,    25,    15,    16,    17,
      43,    44,    18,    19,    28,    20,    40
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -33
static const yytype_int8 yypact[] =
{
      12,   -16,   -33,   -28,     0,    -2,    38,   -33,   -33,    -2,
      38,     8,   -33,    12,   -33,   -33,   -33,   -33,   -33,   -33,
     -32,    38,    -1,   -14,    -2,    -4,     3,   -33,   -33,   -25,
     -33,   -33,   -33,   -33,   -33,    16,    10,   -15,    -3,    -2,
       4,    17,     9,    14,    21,    25,   -33,    12,   -33,    38,
      12,    38,    39,    16,    29,     7,   -33,    36,   -33,    33,
     -33,    12,   -33,    11,    12,    41,   -33,    -2,    -2,   -33,
      42,   -33,    23,    31,   -33,    43,    45,    12,    12,    51,
      52,    11,   -33,   -33
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -33,   -33,   -13,   -33,   -33,     2,    -8,   -33,   -33,   -33,
      26,   -33,   -33,     1,    68,   -33,   -33
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      32,    29,    21,     1,    22,    23,    26,    27,    31,    33,
      26,    27,    38,    35,    36,    41,    37,     1,    66,     2,
      39,    42,    34,    45,    46,    26,    47,    51,    49,    52,
       6,    48,    62,     7,    55,     8,    24,    57,     3,     4,
      26,    54,     5,     1,     6,    53,    50,     7,    65,     8,
      56,    70,    58,    67,    68,    59,     9,    10,    61,    72,
      73,    63,    64,    75,    79,    80,    71,    74,    26,    26,
       6,    76,    77,     7,    78,     8,    81,    82,    30,    60,
       0,     0,     0,    83
};

#define yypact_value_is_default(yystate) \
  ((yystate) == (-33))

#define yytable_value_is_error(yytable_value) \
  YYID (0)

static const yytype_int8 yycheck[] =
{
      13,     9,    18,     5,    32,     5,     5,     6,     0,    41,
       9,    10,    16,    14,    28,    40,    24,     5,     7,     7,
      17,     5,    21,    13,    39,    24,    29,    18,    24,    15,
      32,    39,    25,    35,    47,    37,    38,    50,    26,    27,
      39,    16,    30,     5,    32,    24,    29,    35,    61,    37,
      49,    64,    51,    42,    43,    16,    44,    45,    29,    67,
      68,    25,    29,    40,    77,    78,    25,    25,    67,    68,
      32,    40,    29,    35,    29,    37,    25,    25,    10,    53,
      -1,    -1,    -1,    81
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     5,     7,    26,    27,    30,    32,    35,    37,    44,
      45,    48,    49,    50,    51,    54,    55,    56,    59,    60,
      62,    18,    32,     5,    38,    53,    60,    60,    61,    53,
      61,     0,    49,    41,    60,    14,    28,    53,    16,    17,
      63,    40,     5,    57,    58,    13,    39,    29,    53,    24,
      29,    18,    15,    24,    16,    49,    60,    49,    60,    16,
      57,    29,    25,    25,    29,    49,     7,    42,    43,    52,
      49,    25,    53,    53,    25,    40,    40,    29,    29,    49,
      49,    25,    25,    52
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256

/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (YYID (N))                                                     \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (YYID (0))
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])



/* This macro is provided for backward compatibility. */

#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
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

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
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
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULL, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  YYSIZE_T yysize1;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULL;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
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
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
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
                yyarg[yycount++] = yytname[yyx];
                yysize1 = yysize + yytnamerr (YY_NULL, yytname[yyx]);
                if (! (yysize <= yysize1
                       && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                  return 2;
                yysize = yysize1;
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  yysize1 = yysize + yystrlen (yyformat);
  if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
    return 2;
  yysize = yysize1;

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
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
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {
      case 3: /* "INT" */

/* Line 1381 of yacc.c  */
#line 154 "apyc-parser.y"
	{ (*yyvaluep)._destructor (); };

/* Line 1381 of yacc.c  */
#line 1276 "apyc-parser.cc"
	break;
      case 4: /* "STRING" */

/* Line 1381 of yacc.c  */
#line 154 "apyc-parser.y"
	{ (*yyvaluep)._destructor (); };

/* Line 1381 of yacc.c  */
#line 1285 "apyc-parser.cc"
	break;
      case 5: /* "ID" */

/* Line 1381 of yacc.c  */
#line 154 "apyc-parser.y"
	{ (*yyvaluep)._destructor (); };

/* Line 1381 of yacc.c  */
#line 1294 "apyc-parser.cc"
	break;
      case 6: /* "\"@println\"" */

/* Line 1381 of yacc.c  */
#line 154 "apyc-parser.y"
	{ (*yyvaluep)._destructor (); };

/* Line 1381 of yacc.c  */
#line 1303 "apyc-parser.cc"
	break;
      case 7: /* "EMPTY" */

/* Line 1381 of yacc.c  */
#line 154 "apyc-parser.y"
	{ (*yyvaluep)._destructor (); };

/* Line 1381 of yacc.c  */
#line 1312 "apyc-parser.cc"
	break;
      case 8: /* "\"@expr_list\"" */

/* Line 1381 of yacc.c  */
#line 154 "apyc-parser.y"
	{ (*yyvaluep)._destructor (); };

/* Line 1381 of yacc.c  */
#line 1321 "apyc-parser.cc"
	break;
      case 9: /* "\"@literal\"" */

/* Line 1381 of yacc.c  */
#line 154 "apyc-parser.y"
	{ (*yyvaluep)._destructor (); };

/* Line 1381 of yacc.c  */
#line 1330 "apyc-parser.cc"
	break;
      case 10: /* "\"@module\"" */

/* Line 1381 of yacc.c  */
#line 154 "apyc-parser.y"
	{ (*yyvaluep)._destructor (); };

/* Line 1381 of yacc.c  */
#line 1339 "apyc-parser.cc"
	break;
      case 11: /* "\"@if_stmt\"" */

/* Line 1381 of yacc.c  */
#line 154 "apyc-parser.y"
	{ (*yyvaluep)._destructor (); };

/* Line 1381 of yacc.c  */
#line 1348 "apyc-parser.cc"
	break;
      case 12: /* "\"@boolean_stmt\"" */

/* Line 1381 of yacc.c  */
#line 154 "apyc-parser.y"
	{ (*yyvaluep)._destructor (); };

/* Line 1381 of yacc.c  */
#line 1357 "apyc-parser.cc"
	break;
      case 13: /* "\"@iterable\"" */

/* Line 1381 of yacc.c  */
#line 154 "apyc-parser.y"
	{ (*yyvaluep)._destructor (); };

/* Line 1381 of yacc.c  */
#line 1366 "apyc-parser.cc"
	break;
      case 14: /* "\"@(\"" */

/* Line 1381 of yacc.c  */
#line 154 "apyc-parser.y"
	{ (*yyvaluep)._destructor (); };

/* Line 1381 of yacc.c  */
#line 1375 "apyc-parser.cc"
	break;
      case 15: /* "\"@)\"" */

/* Line 1381 of yacc.c  */
#line 154 "apyc-parser.y"
	{ (*yyvaluep)._destructor (); };

/* Line 1381 of yacc.c  */
#line 1384 "apyc-parser.cc"
	break;
      case 16: /* "\"@:\"" */

/* Line 1381 of yacc.c  */
#line 154 "apyc-parser.y"
	{ (*yyvaluep)._destructor (); };

/* Line 1381 of yacc.c  */
#line 1393 "apyc-parser.cc"
	break;
      case 17: /* "\"@compare\"" */

/* Line 1381 of yacc.c  */
#line 154 "apyc-parser.y"
	{ (*yyvaluep)._destructor (); };

/* Line 1381 of yacc.c  */
#line 1402 "apyc-parser.cc"
	break;
      case 18: /* "\"@=\"" */

/* Line 1381 of yacc.c  */
#line 154 "apyc-parser.y"
	{ (*yyvaluep)._destructor (); };

/* Line 1381 of yacc.c  */
#line 1411 "apyc-parser.cc"
	break;
      case 19: /* "\"@==\"" */

/* Line 1381 of yacc.c  */
#line 154 "apyc-parser.y"
	{ (*yyvaluep)._destructor (); };

/* Line 1381 of yacc.c  */
#line 1420 "apyc-parser.cc"
	break;
      case 20: /* "\"@>\"" */

/* Line 1381 of yacc.c  */
#line 154 "apyc-parser.y"
	{ (*yyvaluep)._destructor (); };

/* Line 1381 of yacc.c  */
#line 1429 "apyc-parser.cc"
	break;
      case 21: /* "\"@<\"" */

/* Line 1381 of yacc.c  */
#line 154 "apyc-parser.y"
	{ (*yyvaluep)._destructor (); };

/* Line 1381 of yacc.c  */
#line 1438 "apyc-parser.cc"
	break;
      case 22: /* "\"@>=\"" */

/* Line 1381 of yacc.c  */
#line 154 "apyc-parser.y"
	{ (*yyvaluep)._destructor (); };

/* Line 1381 of yacc.c  */
#line 1447 "apyc-parser.cc"
	break;
      case 23: /* "\"@<=\"" */

/* Line 1381 of yacc.c  */
#line 154 "apyc-parser.y"
	{ (*yyvaluep)._destructor (); };

/* Line 1381 of yacc.c  */
#line 1456 "apyc-parser.cc"
	break;
      case 24: /* "\",\"" */

/* Line 1381 of yacc.c  */
#line 154 "apyc-parser.y"
	{ (*yyvaluep)._destructor (); };

/* Line 1381 of yacc.c  */
#line 1465 "apyc-parser.cc"
	break;
      case 25: /* "DEDENT" */

/* Line 1381 of yacc.c  */
#line 154 "apyc-parser.y"
	{ (*yyvaluep)._destructor (); };

/* Line 1381 of yacc.c  */
#line 1474 "apyc-parser.cc"
	break;
      case 26: /* "DEF" */

/* Line 1381 of yacc.c  */
#line 154 "apyc-parser.y"
	{ (*yyvaluep)._destructor (); };

/* Line 1381 of yacc.c  */
#line 1483 "apyc-parser.cc"
	break;
      case 27: /* "FOR" */

/* Line 1381 of yacc.c  */
#line 154 "apyc-parser.y"
	{ (*yyvaluep)._destructor (); };

/* Line 1381 of yacc.c  */
#line 1492 "apyc-parser.cc"
	break;
      case 28: /* "IN" */

/* Line 1381 of yacc.c  */
#line 154 "apyc-parser.y"
	{ (*yyvaluep)._destructor (); };

/* Line 1381 of yacc.c  */
#line 1501 "apyc-parser.cc"
	break;
      case 29: /* "INDENT" */

/* Line 1381 of yacc.c  */
#line 154 "apyc-parser.y"
	{ (*yyvaluep)._destructor (); };

/* Line 1381 of yacc.c  */
#line 1510 "apyc-parser.cc"
	break;
      case 30: /* "WHILE" */

/* Line 1381 of yacc.c  */
#line 154 "apyc-parser.y"
	{ (*yyvaluep)._destructor (); };

/* Line 1381 of yacc.c  */
#line 1519 "apyc-parser.cc"
	break;
      case 31: /* "DICT" */

/* Line 1381 of yacc.c  */
#line 154 "apyc-parser.y"
	{ (*yyvaluep)._destructor (); };

/* Line 1381 of yacc.c  */
#line 1528 "apyc-parser.cc"
	break;
      case 32: /* "FUNCTION_NAME" */

/* Line 1381 of yacc.c  */
#line 154 "apyc-parser.y"
	{ (*yyvaluep)._destructor (); };

/* Line 1381 of yacc.c  */
#line 1537 "apyc-parser.cc"
	break;
      case 33: /* "LIST" */

/* Line 1381 of yacc.c  */
#line 154 "apyc-parser.y"
	{ (*yyvaluep)._destructor (); };

/* Line 1381 of yacc.c  */
#line 1546 "apyc-parser.cc"
	break;
      case 34: /* "NUMERIC_LITERAL" */

/* Line 1381 of yacc.c  */
#line 154 "apyc-parser.y"
	{ (*yyvaluep)._destructor (); };

/* Line 1381 of yacc.c  */
#line 1555 "apyc-parser.cc"
	break;
      case 35: /* "STRING_LITERAL" */

/* Line 1381 of yacc.c  */
#line 154 "apyc-parser.y"
	{ (*yyvaluep)._destructor (); };

/* Line 1381 of yacc.c  */
#line 1564 "apyc-parser.cc"
	break;
      case 36: /* "TUPLE" */

/* Line 1381 of yacc.c  */
#line 154 "apyc-parser.y"
	{ (*yyvaluep)._destructor (); };

/* Line 1381 of yacc.c  */
#line 1573 "apyc-parser.cc"
	break;
      case 37: /* "INT_LITERAL" */

/* Line 1381 of yacc.c  */
#line 154 "apyc-parser.y"
	{ (*yyvaluep)._destructor (); };

/* Line 1381 of yacc.c  */
#line 1582 "apyc-parser.cc"
	break;
      case 38: /* "\"(\"" */

/* Line 1381 of yacc.c  */
#line 154 "apyc-parser.y"
	{ (*yyvaluep)._destructor (); };

/* Line 1381 of yacc.c  */
#line 1591 "apyc-parser.cc"
	break;
      case 39: /* "\")\"" */

/* Line 1381 of yacc.c  */
#line 154 "apyc-parser.y"
	{ (*yyvaluep)._destructor (); };

/* Line 1381 of yacc.c  */
#line 1600 "apyc-parser.cc"
	break;
      case 40: /* "\":\"" */

/* Line 1381 of yacc.c  */
#line 154 "apyc-parser.y"
	{ (*yyvaluep)._destructor (); };

/* Line 1381 of yacc.c  */
#line 1609 "apyc-parser.cc"
	break;
      case 41: /* "\"\\n\"" */

/* Line 1381 of yacc.c  */
#line 154 "apyc-parser.y"
	{ (*yyvaluep)._destructor (); };

/* Line 1381 of yacc.c  */
#line 1618 "apyc-parser.cc"
	break;
      case 42: /* "\"elif\"" */

/* Line 1381 of yacc.c  */
#line 154 "apyc-parser.y"
	{ (*yyvaluep)._destructor (); };

/* Line 1381 of yacc.c  */
#line 1627 "apyc-parser.cc"
	break;
      case 43: /* "\"else\"" */

/* Line 1381 of yacc.c  */
#line 154 "apyc-parser.y"
	{ (*yyvaluep)._destructor (); };

/* Line 1381 of yacc.c  */
#line 1636 "apyc-parser.cc"
	break;
      case 44: /* "\"if\"" */

/* Line 1381 of yacc.c  */
#line 154 "apyc-parser.y"
	{ (*yyvaluep)._destructor (); };

/* Line 1381 of yacc.c  */
#line 1645 "apyc-parser.cc"
	break;
      case 45: /* "\"print\"" */

/* Line 1381 of yacc.c  */
#line 154 "apyc-parser.y"
	{ (*yyvaluep)._destructor (); };

/* Line 1381 of yacc.c  */
#line 1654 "apyc-parser.cc"
	break;
      case 46: /* "RAWSTRING" */

/* Line 1381 of yacc.c  */
#line 154 "apyc-parser.y"
	{ (*yyvaluep)._destructor (); };

/* Line 1381 of yacc.c  */
#line 1663 "apyc-parser.cc"
	break;
      case 48: /* "program" */

/* Line 1381 of yacc.c  */
#line 154 "apyc-parser.y"
	{ (*yyvaluep)._destructor (); };

/* Line 1381 of yacc.c  */
#line 1672 "apyc-parser.cc"
	break;
      case 49: /* "stmt_list" */

/* Line 1381 of yacc.c  */
#line 154 "apyc-parser.y"
	{ (*yyvaluep)._destructor (); };

/* Line 1381 of yacc.c  */
#line 1681 "apyc-parser.cc"
	break;
      case 50: /* "stmt" */

/* Line 1381 of yacc.c  */
#line 154 "apyc-parser.y"
	{ (*yyvaluep)._destructor (); };

/* Line 1381 of yacc.c  */
#line 1690 "apyc-parser.cc"
	break;
      case 51: /* "if_stmt" */

/* Line 1381 of yacc.c  */
#line 154 "apyc-parser.y"
	{ (*yyvaluep)._destructor (); };

/* Line 1381 of yacc.c  */
#line 1699 "apyc-parser.cc"
	break;
      case 52: /* "elif_stmt" */

/* Line 1381 of yacc.c  */
#line 154 "apyc-parser.y"
	{ (*yyvaluep)._destructor (); };

/* Line 1381 of yacc.c  */
#line 1708 "apyc-parser.cc"
	break;
      case 53: /* "bool_stmt" */

/* Line 1381 of yacc.c  */
#line 154 "apyc-parser.y"
	{ (*yyvaluep)._destructor (); };

/* Line 1381 of yacc.c  */
#line 1717 "apyc-parser.cc"
	break;
      case 54: /* "while_stmt" */

/* Line 1381 of yacc.c  */
#line 154 "apyc-parser.y"
	{ (*yyvaluep)._destructor (); };

/* Line 1381 of yacc.c  */
#line 1726 "apyc-parser.cc"
	break;
      case 55: /* "for_stmt" */

/* Line 1381 of yacc.c  */
#line 154 "apyc-parser.y"
	{ (*yyvaluep)._destructor (); };

/* Line 1381 of yacc.c  */
#line 1735 "apyc-parser.cc"
	break;
      case 56: /* "def_stmt" */

/* Line 1381 of yacc.c  */
#line 154 "apyc-parser.y"
	{ (*yyvaluep)._destructor (); };

/* Line 1381 of yacc.c  */
#line 1744 "apyc-parser.cc"
	break;
      case 57: /* "parameter_list" */

/* Line 1381 of yacc.c  */
#line 154 "apyc-parser.y"
	{ (*yyvaluep)._destructor (); };

/* Line 1381 of yacc.c  */
#line 1753 "apyc-parser.cc"
	break;
      case 58: /* "parameter" */

/* Line 1381 of yacc.c  */
#line 154 "apyc-parser.y"
	{ (*yyvaluep)._destructor (); };

/* Line 1381 of yacc.c  */
#line 1762 "apyc-parser.cc"
	break;
      case 59: /* "literal" */

/* Line 1381 of yacc.c  */
#line 154 "apyc-parser.y"
	{ (*yyvaluep)._destructor (); };

/* Line 1381 of yacc.c  */
#line 1771 "apyc-parser.cc"
	break;
      case 60: /* "expression" */

/* Line 1381 of yacc.c  */
#line 154 "apyc-parser.y"
	{ (*yyvaluep)._destructor (); };

/* Line 1381 of yacc.c  */
#line 1780 "apyc-parser.cc"
	break;
      case 61: /* "expression_list" */

/* Line 1381 of yacc.c  */
#line 154 "apyc-parser.y"
	{ (*yyvaluep)._destructor (); };

/* Line 1381 of yacc.c  */
#line 1789 "apyc-parser.cc"
	break;
      case 62: /* "print_stmt" */

/* Line 1381 of yacc.c  */
#line 154 "apyc-parser.y"
	{ (*yyvaluep)._destructor (); };

/* Line 1381 of yacc.c  */
#line 1798 "apyc-parser.cc"
	break;
      case 63: /* "__0" */

/* Line 1381 of yacc.c  */
#line 154 "apyc-parser.y"
	{ (*yyvaluep)._destructor (); };

/* Line 1381 of yacc.c  */
#line 1807 "apyc-parser.cc"
	break;

      default:
	break;
    }
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
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

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:

/* Line 1788 of yacc.c  */
#line 113 "apyc.hn"
    { YYCTLPA((yyval),0,1,&(yyvsp[(1) - (1)]));  yyv_stmt_list = (yyvsp[(1) - (1)]);theTree = YYMAKE_TREE(MODULE, yylhs.all_values ()); yylhs = NULL; }
    break;

  case 3:

/* Line 1788 of yacc.c  */
#line 118 "apyc.hn"
    { YYCTLPA((yyval),0,2,&(yyvsp[(1) - (2)]),&(yyvsp[(2) - (2)]));  yyv_stmt = (yyvsp[(1) - (2)]); yyv_stmt_list = (yyvsp[(2) - (2)]); }
    break;

  case 4:

/* Line 1788 of yacc.c  */
#line 118 "apyc.hn"
    { YYCTLPA((yyval),0,1,&(yyvsp[(1) - (1)]));  yyv_EMPTY = (yyvsp[(1) - (1)]); }
    break;

  case 5:

/* Line 1788 of yacc.c  */
#line 119 "apyc.hn"
    { YYCTLPA((yyval),0,1,&(yyvsp[(1) - (1)]));  yyv_if_stmt = (yyvsp[(1) - (1)]); }
    break;

  case 6:

/* Line 1788 of yacc.c  */
#line 119 "apyc.hn"
    { YYCTLPA((yyval),0,1,&(yyvsp[(1) - (1)]));  yyv_while_stmt = (yyvsp[(1) - (1)]); }
    break;

  case 7:

/* Line 1788 of yacc.c  */
#line 119 "apyc.hn"
    { YYCTLPA((yyval),0,1,&(yyvsp[(1) - (1)]));  yyv_def_stmt = (yyvsp[(1) - (1)]); }
    break;

  case 8:

/* Line 1788 of yacc.c  */
#line 119 "apyc.hn"
    { YYCTLPA((yyval),0,1,&(yyvsp[(1) - (1)]));  yyv_for_stmt = (yyvsp[(1) - (1)]); }
    break;

  case 9:

/* Line 1788 of yacc.c  */
#line 119 "apyc.hn"
    { YYCTLPA((yyval),0,1,&(yyvsp[(1) - (1)]));  yyv_expression = (yyvsp[(1) - (1)]); }
    break;

  case 10:

/* Line 1788 of yacc.c  */
#line 121 "apyc.hn"
    { YYCTLPA((yyval),0,7,&(yyvsp[(1) - (7)]),&(yyvsp[(2) - (7)]),&(yyvsp[(3) - (7)]),&(yyvsp[(4) - (7)]),&(yyvsp[(5) - (7)]),&(yyvsp[(6) - (7)]),&(yyvsp[(7) - (7)]));  (yyvsp[(3) - (7)]).ignore(); yyv_bool_stmt = (yyvsp[(2) - (7)]); yyv_INDENT = (yyvsp[(4) - (7)]); yyv_stmt_list = (yyvsp[(5) - (7)]); yyv_DEDENT = (yyvsp[(6) - (7)]); yyv_elif_stmt = (yyvsp[(7) - (7)]); }
    break;

  case 11:

/* Line 1788 of yacc.c  */
#line 122 "apyc.hn"
    { YYCTLPA((yyval),0,7,&(yyvsp[(1) - (7)]),&(yyvsp[(2) - (7)]),&(yyvsp[(3) - (7)]),&(yyvsp[(4) - (7)]),&(yyvsp[(5) - (7)]),&(yyvsp[(6) - (7)]),&(yyvsp[(7) - (7)]));  (yyvsp[(3) - (7)]).ignore(); yyv_bool_stmt = (yyvsp[(2) - (7)]); yyv_INDENT = (yyvsp[(4) - (7)]); yyv_stmt_list = (yyvsp[(5) - (7)]); yyv_DEDENT = (yyvsp[(6) - (7)]); yyv_elif_stmt = (yyvsp[(7) - (7)]); }
    break;

  case 12:

/* Line 1788 of yacc.c  */
#line 122 "apyc.hn"
    { YYCTLPA((yyval),0,1,&(yyvsp[(1) - (1)]));  yyv_EMPTY = (yyvsp[(1) - (1)]); }
    break;

  case 13:

/* Line 1788 of yacc.c  */
#line 122 "apyc.hn"
    { YYCTLPA((yyval),0,6,&(yyvsp[(1) - (6)]),&(yyvsp[(2) - (6)]),&(yyvsp[(3) - (6)]),&(yyvsp[(4) - (6)]),&(yyvsp[(5) - (6)]),&(yyvsp[(6) - (6)]));  (yyvsp[(3) - (6)]).ignore(); yyv_bool_stmt = (yyvsp[(2) - (6)]); yyv_INDENT = (yyvsp[(4) - (6)]); yyv_stmt_list = (yyvsp[(5) - (6)]); yyv_DEDENT = (yyvsp[(6) - (6)]); }
    break;

  case 14:

/* Line 1788 of yacc.c  */
#line 124 "apyc.hn"
    { YYCTLPA((yyval),0,3,&(yyvsp[(1) - (3)]),&(yyvsp[(2) - (3)]),&(yyvsp[(3) - (3)]));  yyv_expression = (yyvsp[(1) - (3)]); yyv_COMPARE = (yyvsp[(2) - (3)]); yyv_bool_stmt = (yyvsp[(3) - (3)]); }
    break;

  case 15:

/* Line 1788 of yacc.c  */
#line 124 "apyc.hn"
    { YYCTLPA((yyval),0,3,&(yyvsp[(1) - (3)]),&(yyvsp[(2) - (3)]),&(yyvsp[(3) - (3)]));  yyv_bool_stmt = (yyvsp[(2) - (3)]); }
    break;

  case 16:

/* Line 1788 of yacc.c  */
#line 124 "apyc.hn"
    { YYCTLPA((yyval),0,1,&(yyvsp[(1) - (1)]));  yyv_expression = (yyvsp[(1) - (1)]); }
    break;

  case 17:

/* Line 1788 of yacc.c  */
#line 125 "apyc.hn"
    { YYCTLPA((yyval),0,6,&(yyvsp[(1) - (6)]),&(yyvsp[(2) - (6)]),&(yyvsp[(3) - (6)]),&(yyvsp[(4) - (6)]),&(yyvsp[(5) - (6)]),&(yyvsp[(6) - (6)]));  (yyvsp[(3) - (6)]).ignore(); yyv_WHILE = (yyvsp[(1) - (6)]); yyv_bool_stmt = (yyvsp[(2) - (6)]); yyv_COLON = (yyvsp[(3) - (6)]); yyv_INDENT = (yyvsp[(4) - (6)]); yyv_stmt_list = (yyvsp[(5) - (6)]); yyv_DEDENT = (yyvsp[(6) - (6)]); }
    break;

  case 18:

/* Line 1788 of yacc.c  */
#line 126 "apyc.hn"
    { YYCTLPA((yyval),0,8,&(yyvsp[(1) - (8)]),&(yyvsp[(2) - (8)]),&(yyvsp[(3) - (8)]),&(yyvsp[(4) - (8)]),&(yyvsp[(5) - (8)]),&(yyvsp[(6) - (8)]),&(yyvsp[(7) - (8)]),&(yyvsp[(8) - (8)]));  (yyvsp[(5) - (8)]).ignore(); yyv_FOR = (yyvsp[(1) - (8)]); yyv_ID = (yyvsp[(2) - (8)]); yyv_IN = (yyvsp[(3) - (8)]); yyv_ITERABLE = (yyvsp[(4) - (8)]); yyv_COLON = (yyvsp[(5) - (8)]); yyv_INDENT = (yyvsp[(6) - (8)]); yyv_stmt_list = (yyvsp[(7) - (8)]); yyv_DEDENT = (yyvsp[(8) - (8)]); }
    break;

  case 19:

/* Line 1788 of yacc.c  */
#line 128 "apyc.hn"
    { YYCTLPA((yyval),0,9,&(yyvsp[(1) - (9)]),&(yyvsp[(2) - (9)]),&(yyvsp[(3) - (9)]),&(yyvsp[(4) - (9)]),&(yyvsp[(5) - (9)]),&(yyvsp[(6) - (9)]),&(yyvsp[(7) - (9)]),&(yyvsp[(8) - (9)]),&(yyvsp[(9) - (9)]));  (yyvsp[(3) - (9)]).ignore(); (yyvsp[(5) - (9)]).ignore(); (yyvsp[(6) - (9)]).ignore(); yyv_DEF = (yyvsp[(1) - (9)]); yyv_FUNCTION_NAME = (yyvsp[(2) - (9)]); yyv_LPAREN = (yyvsp[(3) - (9)]); yyv_parameter_list = (yyvsp[(4) - (9)]); yyv_RPAREN = (yyvsp[(5) - (9)]); yyv_COLON = (yyvsp[(6) - (9)]); yyv_INDENT = (yyvsp[(7) - (9)]); yyv_stmt_list = (yyvsp[(8) - (9)]); yyv_DEDENT = (yyvsp[(9) - (9)]); }
    break;

  case 20:

/* Line 1788 of yacc.c  */
#line 129 "apyc.hn"
    { YYCTLPA((yyval),0,3,&(yyvsp[(1) - (3)]),&(yyvsp[(2) - (3)]),&(yyvsp[(3) - (3)]));  (yyvsp[(2) - (3)]).ignore(); yyv_parameter = (yyvsp[(1) - (3)]); yyv_COMMA = (yyvsp[(2) - (3)]); yyv_parameter_list = (yyvsp[(3) - (3)]); }
    break;

  case 21:

/* Line 1788 of yacc.c  */
#line 129 "apyc.hn"
    { YYCTLPA((yyval),0,1,&(yyvsp[(1) - (1)]));  yyv_parameter = (yyvsp[(1) - (1)]); }
    break;

  case 22:

/* Line 1788 of yacc.c  */
#line 130 "apyc.hn"
    { YYCTLPA((yyval),0,1,&(yyvsp[(1) - (1)]));  yyv_ID = (yyvsp[(1) - (1)]); }
    break;

  case 23:

/* Line 1788 of yacc.c  */
#line 130 "apyc.hn"
    { YYCTLPA((yyval),0,3,&(yyvsp[(1) - (3)]),&(yyvsp[(2) - (3)]),&(yyvsp[(3) - (3)]));  yyv_ID = (yyvsp[(1) - (3)]); yyv_ASSIGN = (yyvsp[(2) - (3)]); yyv_expression = (yyvsp[(3) - (3)]); }
    break;

  case 24:

/* Line 1788 of yacc.c  */
#line 137 "apyc.hn"
    { YYCTLPA((yyval),0,1,&(yyvsp[(1) - (1)]));  yyv_INT_LITERAL = (yyvsp[(1) - (1)]);yylhs=yyv_INT_LITERAL; }
    break;

  case 25:

/* Line 1788 of yacc.c  */
#line 137 "apyc.hn"
    { YYCTLPA((yyval),0,1,&(yyvsp[(1) - (1)]));  yyv_STRING_LITERAL = (yyvsp[(1) - (1)]);yylhs = YYMAKE_TREE(STRING_LITERAL, yyv_STRING_LITERAL); }
    break;

  case 26:

/* Line 1788 of yacc.c  */
#line 143 "apyc.hn"
    { YYCTLPA((yyval),0,1,&(yyvsp[(1) - (1)]));  yyv_literal = (yyvsp[(1) - (1)]);yylhs=yyv_literal; }
    break;

  case 27:

/* Line 1788 of yacc.c  */
#line 143 "apyc.hn"
    { YYCTLPA((yyval),0,2,&(yyvsp[(1) - (2)]),&(yyvsp[(2) - (2)]));  yyv_FUNCTION_NAME = (yyvsp[(1) - (2)]); yyv_expression_list = (yyvsp[(2) - (2)]); }
    break;

  case 28:

/* Line 1788 of yacc.c  */
#line 143 "apyc.hn"
    { YYCTLPA((yyval),0,3,&(yyvsp[(1) - (3)]),&(yyvsp[(2) - (3)]),&(yyvsp[(3) - (3)]));  yyv_ID = (yyvsp[(1) - (3)]); yyv_ASSIGN = (yyvsp[(2) - (3)]); yyv_expression = (yyvsp[(3) - (3)]); }
    break;

  case 29:

/* Line 1788 of yacc.c  */
#line 150 "apyc.hn"
    { YYCTLA((yyval),0,2,&(yyvsp[(1) - (2)]),&(yyvsp[(2) - (2)])); yylhs = YYMAKE_TREE(EXPR_LIST, yylhs.all_values ()); }
    break;

  case 30:

/* Line 1788 of yacc.c  */
#line 151 "apyc.hn"
    { YYCTLPA((yyval),0,0); yylhs = YYMAKE_TREE(EXPR_LIST); }
    break;

<<<<<<< HEAD
  case 35:
/* Line 1787 of yacc.c  */
#line 155 "apyc.hn"
    { YYCTLPA((yyval),0,2,&(yyvsp[(1) - (2)]),&(yyvsp[(2) - (2)]));  (yyvsp[(2) - (2)]).ignore(); yyv_print_stmt = (yyvsp[(1) - (2)]); }
    break;

  case 36:
/* Line 1787 of yacc.c  */
#line 159 "apyc.hn"
    { YYCTLPA((yyval),0,2,&(yyvsp[(1) - (2)]),&(yyvsp[(2) - (2)]));  yyv_expression_list = (yyvsp[(2) - (2)]);yylhs = YYMAKE_TREE(PRINTLN, YYMAKE_TREE(EMPTY), yyv_expression_list); }
    break;

  case 37:
/* Line 1787 of yacc.c  */
#line 162 "apyc.hn"
=======
  case 31:

/* Line 1788 of yacc.c  */
#line 158 "apyc.hn"
    { YYCTLPA((yyval),0,2,&(yyvsp[(1) - (2)]),&(yyvsp[(2) - (2)]));  (yyvsp[(2) - (2)]).ignore(); yyv_print_stmt = (yyvsp[(1) - (2)]); }
    break;

  case 32:

/* Line 1788 of yacc.c  */
#line 162 "apyc.hn"
    { YYCTLPA((yyval),0,2,&(yyvsp[(1) - (2)]),&(yyvsp[(2) - (2)]));  yyv_expression_list = (yyvsp[(2) - (2)]);yylhs = YYMAKE_TREE(PRINTLN, YYMAKE_TREE(EMPTY), yyv_expression_list); }
    break;

  case 33:

/* Line 1788 of yacc.c  */
#line 165 "apyc.hn"
>>>>>>> e42dd43ea0197ce3b5ac24edba37c739fd822d7e
    { YYCTLPC((yyval),1,1,&(yyvsp[(0) - (0)]));  yyv_expression = (yyvsp[(0) - (0)]); }
    break;

  case 34:

/* Line 1788 of yacc.c  */
#line 150 "apyc.hn"
    { YYCTLC((yyval),1,4,&(yyvsp[(0) - (3)]),&(yyvsp[(1) - (3)]),&(yyvsp[(2) - (3)]),&(yyvsp[(3) - (3)]));  (yyvsp[(2) - (3)]).ignore(); yyv_expression = (yyvsp[(3) - (3)]); }
    break;



/* Line 1788 of yacc.c  */
#line 2327 "apyc-parser.cc"
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


<<<<<<< HEAD
/* Line 2048 of yacc.c  */
#line 457 "apyc-parser.y"
=======

/* Line 2049 of yacc.c  */
#line 447 "apyc-parser.y"
>>>>>>> e42dd43ea0197ce3b5ac24edba37c739fd822d7e



#line 173 "apyc.hn"


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


<<<<<<< HEAD
#line 486 "apyc-parser.y"
=======
#line 476 "apyc-parser.y"
>>>>>>> e42dd43ea0197ce3b5ac24edba37c739fd822d7e

const char* 
yyexternal_token_name (int syntax)
{
    int internal_num = YYTRANSLATE (syntax);
    return yytname[internal_num];
}

#include "apyc-lexer.cc"

YYNAMESPACE_CLOSE

