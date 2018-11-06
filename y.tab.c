/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 6 "comp.yacc" /* yacc.c:339  */

#include <iostream>
#include <string>
#include <stdlib.h>
#include <map>


// Declare stuff from Flex that Bison needs to know about:
int yylex(void);
extern int yyparse();
extern FILE *yyin;
 
void yyerror(const char *s);

#line 81 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 1 "comp.yacc" /* yacc.c:355  */

      #include <list>
      using namespace std;

#line 116 "y.tab.c" /* yacc.c:355  */

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    ADD_EQUAL = 258,
    SUB_EQUAL = 259,
    MUL_EQUAL = 260,
    DIV_EQUAL = 261,
    RES_EQUAL = 262,
    OR = 263,
    AND = 264,
    EQUAL = 265,
    NOT_EQUAL = 266,
    LESS_EQUAL = 267,
    GREATER_EQUAL = 268,
    NEG = 269,
    NUMBER = 270,
    WHILE = 271,
    VAR = 272,
    DEF = 273,
    INT = 274,
    BOOL = 275,
    FOR = 276,
    IF = 277,
    ELSE = 279,
    WRITE = 280,
    READ = 281,
    STRING_TYPE = 282,
    STRING = 283,
    ID = 284,
    TRUE = 285,
    FALSE = 286,
    RETURN = 287,
    SKIP = 288,
    STOP = 289,
    ENDOFFILE = 290
  };
#endif
/* Tokens.  */
#define ADD_EQUAL 258
#define SUB_EQUAL 259
#define MUL_EQUAL 260
#define DIV_EQUAL 261
#define RES_EQUAL 262
#define OR 263
#define AND 264
#define EQUAL 265
#define NOT_EQUAL 266
#define LESS_EQUAL 267
#define GREATER_EQUAL 268
#define NEG 269
#define NUMBER 270
#define WHILE 271
#define VAR 272
#define DEF 273
#define INT 274
#define BOOL 275
#define FOR 276
#define IF 277
#define ELSE 279
#define WRITE 280
#define READ 281
#define STRING_TYPE 282
#define STRING 283
#define ID 284
#define TRUE 285
#define FALSE 286
#define RETURN 287
#define SKIP 288
#define STOP 289
#define ENDOFFILE 290

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 24 "comp.yacc" /* yacc.c:355  */

	char *sval;
      int   ival;
      list<int*> *stmts;

#line 202 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


extern YYSTYPE yylval;
extern YYLTYPE yylloc;
int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 233 "y.tab.c" /* yacc.c:358  */

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
#else
typedef signed char yytype_int8;
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
# elif ! defined YYSIZE_T
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
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
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
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
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
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

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
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  21
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   506

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  55
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  39
/* YYNRULES -- Number of rules.  */
#define YYNRULES  105
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  205

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   290

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    32,     2,     2,     2,    31,     2,     2,
       3,     4,    29,    27,    10,    28,     2,    30,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    18,     9,
      23,    11,    25,    17,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     5,     2,     6,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     7,     2,     8,     2,     2,     2,     2,
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
       2,     2,     2,     2,     2,     2,     1,     2,    12,    13,
      14,    15,    16,    19,    20,    21,    22,    24,    26,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    85,    85,    89,    90,    94,    95,    98,    99,   102,
     103,   106,   107,   108,   111,   112,   113,   114,   117,   118,
     121,   124,   127,   130,   131,   134,   135,   137,   138,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   169,   170,   173,   174,   177,   178,   182,   186,
     187,   190,   191,   194,   195,   196,   197,   201,   202,   205,
     206,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   222,   225,   226,   227,   228,   229,   230,   232,   233,
     236,   239,   242,   245,   248,   249,   252,   253,   256,   257,
     260,   263,   266,   267,   268,   269
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "'('", "')'", "'['", "']'", "'{'", "'}'",
  "';'", "','", "'='", "\"+=\"", "\"-=\"", "\"*=\"", "\"/=\"", "\"%=\"",
  "'?'", "':'", "\"||\"", "\"&&\"", "\"==\"", "\"!=\"", "'<'", "\"<=\"",
  "'>'", "\">=\"", "'+'", "'-'", "'*'", "'/'", "'%'", "'!'", "NEG",
  "NUMBER", "WHILE", "VAR", "DEF", "INT", "BOOL", "FOR", "IF", "\"then\"",
  "ELSE", "WRITE", "READ", "STRING_TYPE", "STRING", "ID", "TRUE", "FALSE",
  "RETURN", "SKIP", "STOP", "ENDOFFILE", "$accept", "programa", "decSub",
  "listaDec", "dec", "decVar", "listaSpecVars", "specVar",
  "specVarSimples", "specVarSimplesIni", "specVarArranjo",
  "specVarArranjoIni", "arranjo", "variavel", "listaExp", "Exp", "decProc",
  "decFunc", "listaParam", "specParams", "listaParams", "param", "bloco",
  "listaCmd", "cmd", "cmdSimples", "cmdAtrib", "atrib", "cmdIf",
  "cmdWhile", "cmdFor", "cmdStop", "cmdSkip", "cmdReturn",
  "cmdChamadaProc", "cmdChamadaFunc", "cmdRead", "cmdWrite", "type", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,    40,    41,    91,    93,   123,   125,    59,
      44,    61,   258,   259,   260,   261,   262,    63,    58,   263,
     264,   265,   266,    60,   267,    62,   268,    43,    45,    42,
      47,    37,    33,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290
};
# endif

#define YYPACT_NINF -141

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-141)))

#define YYTABLE_NINF -3

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      31,     8,    15,   -43,    22,  -141,    29,  -141,  -141,  -141,
    -141,  -141,  -141,    77,    13,  -141,  -141,  -141,  -141,  -141,
      67,  -141,  -141,   203,   203,    15,    37,  -141,    14,   203,
     203,   203,  -141,  -141,    74,  -141,  -141,  -141,   373,  -141,
     475,  -141,  -141,  -141,    73,    25,     3,    76,    85,  -141,
       2,  -141,   291,  -141,  -141,    24,   203,    90,   203,   203,
     203,   203,   203,   203,   203,   203,   203,   203,   203,   203,
     203,   203,    72,  -141,   118,    37,  -141,   101,    46,    60,
      60,    37,  -141,  -141,    87,   475,   399,   109,   460,   304,
     331,   357,   357,    83,    83,    83,    83,    -5,    -5,  -141,
    -141,  -141,   115,  -141,   120,   121,   124,   203,    80,    97,
     170,   122,   134,   141,   231,  -141,   214,  -141,  -141,  -141,
     136,  -141,  -141,  -141,  -141,  -141,  -141,  -141,  -141,  -141,
     139,  -141,    37,  -141,  -141,  -141,  -141,  -141,   203,  -141,
     203,   203,  -141,   203,    80,   203,    95,   142,   143,   180,
    -141,   422,  -141,  -141,  -141,   233,   203,   203,   203,   203,
     203,   203,  -141,  -141,  -141,  -141,   139,   475,    82,   475,
     475,   319,   147,   347,  -141,  -141,   148,    89,  -141,  -141,
     475,   475,   475,   475,   475,   475,  -141,  -141,   203,   253,
     203,   253,  -141,   151,   475,  -141,   445,    86,  -141,    80,
     253,   146,  -141,   253,  -141
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     8,     0,     5,     7,     3,
       4,    10,    19,    18,     0,    11,    14,    15,    16,    17,
       0,     1,     6,     0,     0,     0,     0,    13,     0,     0,
       0,     0,    30,    33,    25,    31,    32,    29,     0,    51,
      20,    12,   102,   104,   103,     0,     0,    61,     0,    56,
       0,    59,     0,    39,    40,     0,     0,    21,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     9,     0,     0,    52,     0,     0,     0,
       0,     0,    41,    98,     0,    27,     0,     0,     0,    50,
      49,    47,    48,    43,    44,    45,    46,    34,    35,    36,
      37,    38,     0,    66,     0,     0,     0,     0,     0,    25,
       0,     0,     0,     0,     0,    70,     0,    67,    69,    71,
       0,    72,    73,    74,    75,    76,    77,    78,    79,    80,
       0,    62,     0,    53,    57,    60,    58,    99,     0,    26,
       0,     0,   105,     0,     0,     0,     0,    25,     0,     0,
      94,     0,    93,    92,    64,     0,     0,     0,     0,     0,
       0,     0,    65,    68,    81,    54,     0,    28,     0,    23,
      42,     0,     0,     0,   101,   100,     0,     0,    95,    63,
      82,    83,    84,    85,    86,    87,    55,    22,     0,     0,
       0,     0,    96,     0,    24,    90,     0,    88,    97,     0,
       0,     0,    89,     0,    91
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -141,  -141,  -141,    94,    -4,  -141,  -141,    55,  -141,  -141,
    -141,  -141,  -141,   -59,   -94,   -23,  -141,  -141,  -141,    93,
    -141,    71,   -27,    48,  -105,  -141,  -141,  -140,  -141,  -141,
    -141,  -141,  -141,  -141,  -141,  -141,  -141,  -141,   -72
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     4,     5,     6,     7,     8,    14,    15,    16,    17,
      18,    19,   168,    37,    84,    85,     9,    10,    48,    49,
      50,    51,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,    39,   128,   129,    45
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      38,    40,    22,   130,   172,    20,    52,    53,    54,   136,
      74,   163,    80,   146,    12,   114,    12,    11,    46,    76,
      81,    75,    21,    25,    69,    70,    71,    29,    83,    -2,
       1,    26,     1,    86,    73,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   148,
     163,   133,    30,    74,   114,   177,    31,   114,    32,   201,
     166,    13,    47,    13,   132,     2,     3,     2,     3,    27,
      28,    33,    34,    35,    36,    42,    43,    55,    72,    56,
      41,    77,    23,    44,   195,   114,   197,   151,    24,    78,
     187,   137,   188,   193,    79,   202,   114,   138,   204,   138,
     149,    87,    56,   165,   174,   138,   102,   131,    47,    22,
      67,    68,    69,    70,    71,   167,   140,   169,   170,     1,
     171,   142,   173,   143,   144,    74,   103,   145,   147,   200,
     114,   152,   114,   180,   181,   182,   183,   184,   185,   186,
     114,   114,     1,   153,   114,   164,    74,    56,    74,   154,
     203,   135,   175,   104,     2,     3,   190,   192,   105,   106,
     198,   155,   107,   108,     0,   194,   109,   196,   113,   110,
     111,   112,   134,    29,     0,     0,   104,     2,     3,   150,
       0,   105,   106,    29,   176,   107,   108,     0,     0,   109,
       0,     0,   110,   111,   112,     0,     0,     0,    30,     0,
       0,     0,    31,     0,    32,     0,    29,     0,    30,     0,
       0,     0,    31,     0,    32,     0,     0,    33,    34,    35,
      36,    74,   162,     0,     0,     0,     0,    33,    34,    35,
      36,    30,     0,     0,     0,    31,     0,    32,     0,     0,
      74,   179,   156,   157,   158,   159,   160,   161,     0,   104,
      33,    34,    35,    36,   105,   106,     0,     0,   107,   108,
      74,     0,   109,     0,     0,   110,   111,   112,   104,     0,
       0,     0,     0,   105,   106,     0,     0,   107,   108,     0,
       0,   109,     0,     0,   110,   111,   112,     0,   104,     0,
       0,     0,     0,   105,   106,    82,     0,   107,   108,     0,
       0,   109,     0,     0,   110,   111,   112,     0,    58,     0,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,   189,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    58,     0,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,   191,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,     0,    58,     0,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    57,
      63,    64,    65,    66,    67,    68,    69,    70,    71,     0,
      58,     0,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,   139,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    58,     0,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,   178,     0,     0,     0,     0,     0,     0,     0,    58,
       0,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,   199,     0,     0,     0,     0,     0,
       0,     0,    58,     0,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    58,   141,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    58,     0,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71
};

static const yytype_int16 yycheck[] =
{
      23,    24,     6,    75,   144,    48,    29,    30,    31,    81,
       7,   116,    10,   107,     1,    74,     1,     9,     4,    46,
      18,    18,     0,    10,    29,    30,    31,     3,     4,     0,
       1,    18,     1,    56,     9,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,   108,
     155,    78,    28,     7,   113,   149,    32,   116,    34,   199,
     132,    48,    48,    48,    18,    36,    37,    36,    37,    14,
       3,    47,    48,    49,    50,    38,    39,     3,     5,     5,
      25,     5,     5,    46,   189,   144,   191,   110,    11,     4,
       8,     4,    10,     4,     9,   200,   155,    10,   203,    10,
       3,    11,     5,   130,     9,    10,    34,     6,    48,   113,
      27,    28,    29,    30,    31,   138,     7,   140,   141,     1,
     143,     6,   145,     3,     3,     7,     8,     3,    48,    43,
     189,     9,   191,   156,   157,   158,   159,   160,   161,   166,
     199,   200,     1,     9,   203,     9,     7,     5,     7,     8,
       4,    80,     9,    35,    36,    37,     9,     9,    40,    41,
       9,   113,    44,    45,    -1,   188,    48,   190,    74,    51,
      52,    53,    79,     3,    -1,    -1,    35,    36,    37,     9,
      -1,    40,    41,     3,     4,    44,    45,    -1,    -1,    48,
      -1,    -1,    51,    52,    53,    -1,    -1,    -1,    28,    -1,
      -1,    -1,    32,    -1,    34,    -1,     3,    -1,    28,    -1,
      -1,    -1,    32,    -1,    34,    -1,    -1,    47,    48,    49,
      50,     7,     8,    -1,    -1,    -1,    -1,    47,    48,    49,
      50,    28,    -1,    -1,    -1,    32,    -1,    34,    -1,    -1,
       7,     8,    11,    12,    13,    14,    15,    16,    -1,    35,
      47,    48,    49,    50,    40,    41,    -1,    -1,    44,    45,
       7,    -1,    48,    -1,    -1,    51,    52,    53,    35,    -1,
      -1,    -1,    -1,    40,    41,    -1,    -1,    44,    45,    -1,
      -1,    48,    -1,    -1,    51,    52,    53,    -1,    35,    -1,
      -1,    -1,    -1,    40,    41,     4,    -1,    44,    45,    -1,
      -1,    48,    -1,    -1,    51,    52,    53,    -1,    17,    -1,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,     4,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    17,    -1,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,     4,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    -1,    17,    -1,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,     6,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    -1,
      17,    -1,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,     6,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    17,    -1,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,     9,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    17,
      -1,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,     9,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    17,    -1,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    17,    -1,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,    36,    37,    56,    57,    58,    59,    60,    71,
      72,     9,     1,    48,    61,    62,    63,    64,    65,    66,
      48,     0,    59,     5,    11,    10,    18,    62,     3,     3,
      28,    32,    34,    47,    48,    49,    50,    68,    70,    90,
      70,    62,    38,    39,    46,    93,     4,    48,    73,    74,
      75,    76,    70,    70,    70,     3,     5,     6,    17,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,     5,     9,     7,    18,    77,     5,     4,     9,
      10,    18,     4,     4,    69,    70,    70,    11,    70,    70,
      70,    70,    70,    70,    70,    70,    70,    70,    70,    70,
      70,    70,    34,     8,    35,    40,    41,    44,    45,    48,
      51,    52,    53,    58,    68,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    91,    92,
      93,     6,    18,    77,    74,    76,    93,     4,    10,     6,
       7,    18,     6,     3,     3,     3,    69,    48,    68,     3,
       9,    70,     9,     9,     8,    78,    11,    12,    13,    14,
      15,    16,     8,    79,     9,    77,    93,    70,    67,    70,
      70,    70,    82,    70,     9,     9,     4,    69,     9,     8,
      70,    70,    70,    70,    70,    70,    77,     8,    10,     4,
       9,     4,     9,     4,    70,    79,    70,    79,     9,     9,
      43,    82,    79,     4,    79
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    55,    56,    57,    57,    58,    58,    59,    59,    60,
      60,    61,    61,    61,    62,    62,    62,    62,    63,    63,
      64,    65,    66,    67,    67,    68,    68,    69,    69,    70,
      70,    70,    70,    70,    70,    70,    70,    70,    70,    70,
      70,    70,    70,    70,    70,    70,    70,    70,    70,    70,
      70,    70,    71,    71,    72,    72,    73,    73,    74,    75,
      75,    76,    76,    77,    77,    77,    77,    78,    78,    79,
      79,    80,    80,    80,    80,    80,    80,    80,    80,    80,
      80,    81,    82,    82,    82,    82,    82,    82,    83,    83,
      84,    85,    86,    87,    88,    88,    89,    89,    90,    90,
      91,    92,    93,    93,    93,    93
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     2,     1,     1,     5,
       2,     1,     3,     2,     1,     1,     1,     1,     1,     1,
       3,     4,     8,     1,     3,     1,     4,     1,     3,     1,
       1,     1,     1,     1,     3,     3,     3,     3,     3,     2,
       2,     3,     5,     3,     3,     3,     3,     3,     3,     3,
       3,     1,     5,     6,     7,     8,     1,     3,     3,     1,
       3,     1,     3,     4,     3,     3,     2,     1,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     3,     3,     3,     3,     3,     3,     5,     7,
       5,     9,     2,     2,     2,     3,     4,     5,     3,     4,
       3,     3,     1,     1,     1,     4
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


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
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
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
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static unsigned
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  unsigned res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
 }

#  define YY_LOCATION_PRINT(File, Loc)          \
  yy_location_print_ (File, &(Loc))

# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value, Location); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  YYUSE (yylocationp);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                       , &(yylsp[(yyi + 1) - (yynrhs)])                       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule); \
} while (0)

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
#ifndef YYINITDEPTH
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
static YYSIZE_T
yystrlen (const char *yystr)
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
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
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
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
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

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

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

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Location data for the lookahead symbol.  */
YYLTYPE yylloc
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.
       'yyls': related to locations.

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

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[3];

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yylsp = yyls = yylsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  yylsp[0] = yylloc;
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
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yyls1, yysize * sizeof (*yylsp),
                    &yystacksize);

        yyls = yyls1;
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
        YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

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
      yychar = yylex ();
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
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END
  *++yylsp = yylloc;
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
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];

  /* Default location.  */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 85 "comp.yacc" /* yacc.c:1646  */
    { }
#line 1610 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 89 "comp.yacc" /* yacc.c:1646  */
    { }
#line 1616 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 90 "comp.yacc" /* yacc.c:1646  */
    { }
#line 1622 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 94 "comp.yacc" /* yacc.c:1646  */
    { }
#line 1628 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 95 "comp.yacc" /* yacc.c:1646  */
    { }
#line 1634 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 98 "comp.yacc" /* yacc.c:1646  */
    { }
#line 1640 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 99 "comp.yacc" /* yacc.c:1646  */
    { }
#line 1646 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 102 "comp.yacc" /* yacc.c:1646  */
    { }
#line 1652 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 103 "comp.yacc" /* yacc.c:1646  */
    { cout << "declaração de variável inválida na linha " << (yylsp[-1]).first_line << endl; }
#line 1658 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 106 "comp.yacc" /* yacc.c:1646  */
    { }
#line 1664 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 107 "comp.yacc" /* yacc.c:1646  */
    { }
#line 1670 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 108 "comp.yacc" /* yacc.c:1646  */
    { }
#line 1676 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 111 "comp.yacc" /* yacc.c:1646  */
    { }
#line 1682 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 112 "comp.yacc" /* yacc.c:1646  */
    { }
#line 1688 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 113 "comp.yacc" /* yacc.c:1646  */
    { }
#line 1694 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 114 "comp.yacc" /* yacc.c:1646  */
    { }
#line 1700 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 118 "comp.yacc" /* yacc.c:1646  */
    {cout << "Era esperado um identificador de variável na linha " << (yylsp[0]).first_line << " e coluna " << (yylsp[0]).first_column << endl;}
#line 1706 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 121 "comp.yacc" /* yacc.c:1646  */
    { }
#line 1712 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 124 "comp.yacc" /* yacc.c:1646  */
    { }
#line 1718 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 127 "comp.yacc" /* yacc.c:1646  */
    { }
#line 1724 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 131 "comp.yacc" /* yacc.c:1646  */
    { }
#line 1730 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 134 "comp.yacc" /* yacc.c:1646  */
    { }
#line 1736 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 135 "comp.yacc" /* yacc.c:1646  */
    { }
#line 1742 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 138 "comp.yacc" /* yacc.c:1646  */
    { }
#line 1748 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 142 "comp.yacc" /* yacc.c:1646  */
    { }
#line 1754 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 143 "comp.yacc" /* yacc.c:1646  */
    { }
#line 1760 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 144 "comp.yacc" /* yacc.c:1646  */
    { }
#line 1766 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 145 "comp.yacc" /* yacc.c:1646  */
    { }
#line 1772 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 146 "comp.yacc" /* yacc.c:1646  */
    { }
#line 1778 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 147 "comp.yacc" /* yacc.c:1646  */
    { }
#line 1784 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 148 "comp.yacc" /* yacc.c:1646  */
    { }
#line 1790 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 149 "comp.yacc" /* yacc.c:1646  */
    { }
#line 1796 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 150 "comp.yacc" /* yacc.c:1646  */
    { }
#line 1802 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 151 "comp.yacc" /* yacc.c:1646  */
    { }
#line 1808 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 152 "comp.yacc" /* yacc.c:1646  */
    { }
#line 1814 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 153 "comp.yacc" /* yacc.c:1646  */
    { }
#line 1820 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 154 "comp.yacc" /* yacc.c:1646  */
    { }
#line 1826 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 155 "comp.yacc" /* yacc.c:1646  */
    { }
#line 1832 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 156 "comp.yacc" /* yacc.c:1646  */
    { }
#line 1838 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 157 "comp.yacc" /* yacc.c:1646  */
    { }
#line 1844 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 158 "comp.yacc" /* yacc.c:1646  */
    { }
#line 1850 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 159 "comp.yacc" /* yacc.c:1646  */
    { }
#line 1856 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 160 "comp.yacc" /* yacc.c:1646  */
    { }
#line 1862 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 161 "comp.yacc" /* yacc.c:1646  */
    { }
#line 1868 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 162 "comp.yacc" /* yacc.c:1646  */
    { }
#line 1874 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 163 "comp.yacc" /* yacc.c:1646  */
    { }
#line 1880 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 164 "comp.yacc" /* yacc.c:1646  */
    { }
#line 1886 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 169 "comp.yacc" /* yacc.c:1646  */
    { }
#line 1892 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 170 "comp.yacc" /* yacc.c:1646  */
    { }
#line 1898 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 173 "comp.yacc" /* yacc.c:1646  */
    { }
#line 1904 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 174 "comp.yacc" /* yacc.c:1646  */
    { }
#line 1910 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 177 "comp.yacc" /* yacc.c:1646  */
    { }
#line 1916 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 178 "comp.yacc" /* yacc.c:1646  */
    { }
#line 1922 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 182 "comp.yacc" /* yacc.c:1646  */
    { }
#line 1928 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 186 "comp.yacc" /* yacc.c:1646  */
    {}
#line 1934 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 187 "comp.yacc" /* yacc.c:1646  */
    { }
#line 1940 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 190 "comp.yacc" /* yacc.c:1646  */
    { }
#line 1946 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 191 "comp.yacc" /* yacc.c:1646  */
    { }
#line 1952 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 194 "comp.yacc" /* yacc.c:1646  */
    { }
#line 1958 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 195 "comp.yacc" /* yacc.c:1646  */
    { }
#line 1964 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 196 "comp.yacc" /* yacc.c:1646  */
    { }
#line 1970 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 197 "comp.yacc" /* yacc.c:1646  */
    { }
#line 1976 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 201 "comp.yacc" /* yacc.c:1646  */
    {}
#line 1982 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 202 "comp.yacc" /* yacc.c:1646  */
    { }
#line 1988 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 205 "comp.yacc" /* yacc.c:1646  */
    {}
#line 1994 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 206 "comp.yacc" /* yacc.c:1646  */
    {}
#line 2000 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 210 "comp.yacc" /* yacc.c:1646  */
    { }
#line 2006 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 211 "comp.yacc" /* yacc.c:1646  */
    { }
#line 2012 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 212 "comp.yacc" /* yacc.c:1646  */
    { }
#line 2018 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 213 "comp.yacc" /* yacc.c:1646  */
    { }
#line 2024 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 214 "comp.yacc" /* yacc.c:1646  */
    { }
#line 2030 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 215 "comp.yacc" /* yacc.c:1646  */
    { }
#line 2036 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 216 "comp.yacc" /* yacc.c:1646  */
    { }
#line 2042 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 217 "comp.yacc" /* yacc.c:1646  */
    { }
#line 2048 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 218 "comp.yacc" /* yacc.c:1646  */
    { }
#line 2054 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 219 "comp.yacc" /* yacc.c:1646  */
    { }
#line 2060 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 222 "comp.yacc" /* yacc.c:1646  */
    { }
#line 2066 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 225 "comp.yacc" /* yacc.c:1646  */
    { }
#line 2072 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 226 "comp.yacc" /* yacc.c:1646  */
    { }
#line 2078 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 227 "comp.yacc" /* yacc.c:1646  */
    { }
#line 2084 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 228 "comp.yacc" /* yacc.c:1646  */
    { }
#line 2090 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 229 "comp.yacc" /* yacc.c:1646  */
    { }
#line 2096 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 230 "comp.yacc" /* yacc.c:1646  */
    { }
#line 2102 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 232 "comp.yacc" /* yacc.c:1646  */
    { }
#line 2108 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 233 "comp.yacc" /* yacc.c:1646  */
    { }
#line 2114 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 236 "comp.yacc" /* yacc.c:1646  */
    { }
#line 2120 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 239 "comp.yacc" /* yacc.c:1646  */
    { }
#line 2126 "y.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 242 "comp.yacc" /* yacc.c:1646  */
    { }
#line 2132 "y.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 245 "comp.yacc" /* yacc.c:1646  */
    { }
#line 2138 "y.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 248 "comp.yacc" /* yacc.c:1646  */
    { }
#line 2144 "y.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 249 "comp.yacc" /* yacc.c:1646  */
    { }
#line 2150 "y.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 252 "comp.yacc" /* yacc.c:1646  */
    { }
#line 2156 "y.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 253 "comp.yacc" /* yacc.c:1646  */
    { }
#line 2162 "y.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 256 "comp.yacc" /* yacc.c:1646  */
    { }
#line 2168 "y.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 257 "comp.yacc" /* yacc.c:1646  */
    { }
#line 2174 "y.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 260 "comp.yacc" /* yacc.c:1646  */
    { }
#line 2180 "y.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 263 "comp.yacc" /* yacc.c:1646  */
    { }
#line 2186 "y.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 266 "comp.yacc" /* yacc.c:1646  */
    { }
#line 2192 "y.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 267 "comp.yacc" /* yacc.c:1646  */
    { }
#line 2198 "y.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 268 "comp.yacc" /* yacc.c:1646  */
    { }
#line 2204 "y.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 269 "comp.yacc" /* yacc.c:1646  */
    { }
#line 2210 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2214 "y.tab.c" /* yacc.c:1646  */
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
  *++yylsp = yyloc;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
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

  yyerror_range[1] = yylloc;

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
                      yytoken, &yylval, &yylloc);
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

  yyerror_range[1] = yylsp[1-yylen];
  /* Do not reclaim the symbols of the rule whose action triggered
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
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

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

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
  *++yylsp = yyloc;

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
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp, yylsp);
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
  return yyresult;
}
#line 271 "comp.yacc" /* yacc.c:1906  */


int main(int, char**) {
	// Open a file handle to a particular file:
	FILE *myfile = fopen("teste1.grc", "r");
	// Make sure it is valid:
	if (!myfile) {
		cout << "I can't open the file!" << endl;
		return -1;
	}
	// Set Flex to read from it instead of defaulting to STDIN:
	yyin = myfile;
	
	// Parse through the input:
	yyparse();
	
	
}

void yyerror (char const *msg) {
      cout << "\x1B[35mErro sintático - \x1B[37m " << msg << " na linha " << yylloc.first_line << " e coluna " << yylloc.first_column << endl;
      //fprintf(stderr,"\x1B[35mErro sintático : \x1B[37m%s Linha %d Coluna %d\n",msg, yylloc.first_line, yylloc.first_column);
}
