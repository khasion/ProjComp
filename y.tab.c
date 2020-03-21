/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "parser.y" /* yacc.c:339  */

  #include <stdio.h>
  #include <unistd.h>
  #include <stdlib.h>
  #include <string.h>
  #include "table.h"



  #define  YY_DECL int alpha_yylex (void* yylval)
  void yyerror (char* yaccProovidedMessage);
  extern int yylineno;
  int yylex();
  extern char* yytext;
  extern FILE* yyin;

  int gloop = 0;
  int globalscope = 0;
  int funcscope = 0;
  int open_func =0;

#line 88 "y.tab.c" /* yacc.c:339  */

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
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    ASSIGN = 258,
    OR = 259,
    AND = 260,
    EQ = 261,
    NOT_EQ = 262,
    GREATER = 263,
    GREATER_EQ = 264,
    LESS = 265,
    LESS_EQ = 266,
    PLUS = 267,
    MINUS = 268,
    MUL = 269,
    DIV = 270,
    MOD = 271,
    NOT = 272,
    D_PLUS = 273,
    D_MINUS = 274,
    UMINUS = 275,
    DOT = 276,
    D_DOT = 277,
    L_BRA = 278,
    R_BRA = 279,
    L_PAR = 280,
    R_PAR = 281,
    INT = 282,
    REAL = 283,
    ID = 284,
    STRING = 285,
    IF = 286,
    ELSE = 287,
    WHILE = 288,
    FOR = 289,
    FUNC = 290,
    RETURN = 291,
    BREAK = 292,
    CONTINUE = 293,
    LOCAL = 294,
    TRUE = 295,
    FALSE = 296,
    NIL = 297,
    LC_BRA = 298,
    RC_BRA = 299,
    SEMI = 300,
    COMMA = 301,
    COLON = 302,
    D_COLON = 303
  };
#endif
/* Tokens.  */
#define ASSIGN 258
#define OR 259
#define AND 260
#define EQ 261
#define NOT_EQ 262
#define GREATER 263
#define GREATER_EQ 264
#define LESS 265
#define LESS_EQ 266
#define PLUS 267
#define MINUS 268
#define MUL 269
#define DIV 270
#define MOD 271
#define NOT 272
#define D_PLUS 273
#define D_MINUS 274
#define UMINUS 275
#define DOT 276
#define D_DOT 277
#define L_BRA 278
#define R_BRA 279
#define L_PAR 280
#define R_PAR 281
#define INT 282
#define REAL 283
#define ID 284
#define STRING 285
#define IF 286
#define ELSE 287
#define WHILE 288
#define FOR 289
#define FUNC 290
#define RETURN 291
#define BREAK 292
#define CONTINUE 293
#define LOCAL 294
#define TRUE 295
#define FALSE 296
#define NIL 297
#define LC_BRA 298
#define RC_BRA 299
#define SEMI 300
#define COMMA 301
#define COLON 302
#define D_COLON 303

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 25 "parser.y" /* yacc.c:355  */

  int intval;
  char* strval;
  float floatval;

#line 230 "y.tab.c" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 245 "y.tab.c" /* yacc.c:358  */

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
#define YYFINAL  67
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   522

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  49
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  38
/* YYNRULES -- Number of rules.  */
#define YYNRULES  97
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  181

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   303

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
      45,    46,    47,    48
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    61,    61,    62,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    94,
      95,    96,    97,   104,   111,   119,   126,   129,   138,   139,
     140,   141,   142,   145,   150,   154,   159,   162,   163,   164,
     165,   168,   169,   170,   173,   174,   177,   179,   181,   182,
     183,   186,   187,   191,   192,   195,   195,   199,   200,   205,
     205,   208,   209,   208,   210,   211,   210,   214,   215,   216,
     217,   218,   219,   223,   224,   225,   228,   229,   232,   232,
     232,   232,   235,   235,   235,   235,   238,   239
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ASSIGN", "OR", "AND", "EQ", "NOT_EQ",
  "GREATER", "GREATER_EQ", "LESS", "LESS_EQ", "PLUS", "MINUS", "MUL",
  "DIV", "MOD", "NOT", "D_PLUS", "D_MINUS", "UMINUS", "DOT", "D_DOT",
  "L_BRA", "R_BRA", "L_PAR", "R_PAR", "INT", "REAL", "ID", "STRING", "IF",
  "ELSE", "WHILE", "FOR", "FUNC", "RETURN", "BREAK", "CONTINUE", "LOCAL",
  "TRUE", "FALSE", "NIL", "LC_BRA", "RC_BRA", "SEMI", "COMMA", "COLON",
  "D_COLON", "$accept", "program", "stmt", "expr", "term", "assignexpr",
  "primary", "lvalue", "member", "call", "callsuffix", "normcall",
  "methodcall", "elist", "objectdef", "indexed", "indexedelem", "$@1",
  "rec_stmt", "block", "$@2", "funcdef", "$@3", "$@4", "$@5", "$@6",
  "const", "idlist", "ifstmt", "whilestmt", "$@7", "$@8", "$@9", "forstmt",
  "$@10", "$@11", "$@12", "returnstmt", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303
};
# endif

#define YYPACT_NINF -163

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-163)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  (!!((Yytable_value) == (-1)))

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     234,   351,     4,     4,   351,   266,   293,  -163,  -163,  -163,
    -163,   -18,  -163,  -163,     5,   319,   -34,   -32,     7,  -163,
    -163,  -163,  -163,  -163,    10,    41,   234,    97,  -163,  -163,
    -163,   128,  -163,    74,  -163,  -163,  -163,  -163,  -163,  -163,
    -163,  -163,  -163,    15,    26,    74,    26,  -163,  -163,   484,
     -16,   -14,  -163,   197,    29,   351,    38,    42,  -163,    61,
    -163,   110,  -163,  -163,  -163,  -163,  -163,  -163,  -163,   351,
     351,   351,   351,   351,   351,   351,   351,   351,   351,   351,
     351,   351,  -163,   351,  -163,  -163,    60,    62,   351,   351,
    -163,  -163,  -163,   105,   351,   351,   113,   351,  -163,   351,
    -163,    93,  -163,   115,   396,  -163,  -163,   116,  -163,  -163,
     202,   157,   495,   506,   506,   405,   405,   405,   405,    69,
      69,  -163,  -163,  -163,   484,  -163,   119,   442,   -11,  -163,
     463,    11,   115,    12,   484,  -163,   351,   234,   351,   351,
    -163,   123,  -163,  -163,   351,  -163,  -163,  -163,  -163,   351,
      14,   122,   419,    82,   123,  -163,    16,    18,   184,  -163,
     234,  -163,   351,    19,   102,   129,  -163,  -163,  -163,   234,
     171,   102,  -163,  -163,  -163,   351,  -163,    20,  -163,   234,
    -163
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,     0,     0,     0,     0,    60,     0,    77,    78,    43,
      79,     0,    88,    92,    71,     0,     0,     0,     0,    81,
      82,    80,    69,    13,     0,     0,     3,     0,    28,    14,
      36,    38,    46,    39,    40,    11,    12,    42,     5,     6,
       7,     8,    31,     0,    32,     0,    34,    30,    65,    58,
       0,     0,    63,     0,     0,     0,     0,     0,    74,     0,
      96,     0,     9,    10,    44,    68,    45,     1,     2,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     4,     0,    33,    35,     0,     0,     0,    60,
      52,    54,    55,     0,     0,    60,     0,     0,    61,     0,
      62,     0,    29,    41,     0,    89,    93,     0,    72,    97,
       0,    27,    26,    24,    25,    20,    21,    22,    23,    15,
      16,    17,    18,    19,    37,    47,     0,     0,     0,    49,
       0,     0,     0,     0,    59,    64,    60,     0,     0,    60,
      75,    85,    70,    67,    60,    48,    56,    50,    51,     0,
       0,    86,     0,     0,    85,    83,     0,     0,     0,    53,
       0,    90,     0,     0,     0,     0,    57,    66,    87,     0,
       0,     0,    73,    84,    91,    60,    76,     0,    94,     0,
      95
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -163,   131,   -79,    -1,  -163,  -163,  -163,   127,  -163,   130,
    -163,  -163,  -163,   -83,  -163,  -163,    55,  -163,  -163,  -162,
    -163,    -5,  -163,  -163,  -163,  -163,  -163,     6,  -163,  -163,
    -163,  -163,  -163,  -163,  -163,  -163,  -163,  -163
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      90,    91,    92,    50,    34,    51,    52,    97,   110,    35,
      65,    36,    59,   141,   107,   154,    37,   156,    38,    39,
      56,   138,   169,    40,    57,   139,   179,    41
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      42,    54,   172,    47,    49,    53,   128,    55,    98,   176,
     100,    62,   131,    63,    61,   146,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    43,
      99,   143,   101,     9,    58,    99,    64,   148,    96,    66,
     159,    67,   164,    18,   166,   171,   178,    86,    87,    88,
      14,    89,    24,   150,   104,   103,   153,    99,   151,   149,
      99,   157,   165,   105,    99,   165,    99,   106,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   168,   124,    79,    80,    81,   108,   127,    49,   125,
     174,   126,   177,   130,    49,    93,   133,    94,   134,    95,
     180,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,   162,    99,    44,
      46,    83,    45,    45,   129,    49,    48,   152,    49,   132,
     136,   140,    82,    49,   144,    22,    84,    85,   158,    86,
      87,    88,   155,    89,   160,   109,   135,    68,   173,     0,
     163,   170,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    49,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,     0,     0,   175,     0,     0,     1,
       2,     3,     4,   102,     0,     5,     0,     6,   167,     7,
       8,     9,    10,    11,     0,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,   142,    23,     0,     0,
      24,     1,     2,     3,     4,     0,     0,     5,     0,     6,
       0,     7,     8,     9,    10,    11,     0,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,     0,    23,
       0,     0,    24,     1,     2,     3,     4,     0,     0,     5,
       0,     6,     0,     7,     8,     9,    10,     0,     0,     0,
       0,     0,     0,     0,     0,    18,    19,    20,    21,    48,
       1,     2,     3,     4,    24,     0,     5,     0,     6,     0,
       7,     8,     9,    10,     0,     0,     0,     0,    14,     0,
       0,     0,    18,    19,    20,    21,     1,     2,     3,     4,
       0,    24,     5,     0,     6,     0,     7,     8,     9,    10,
       0,     0,     0,     0,     0,     0,     0,     0,    18,    19,
      20,    21,     0,     0,    60,     0,     0,    24,     1,     2,
       3,     4,     0,     0,     5,     0,     6,     0,     7,     8,
       9,    10,     0,     0,     0,     0,     0,     0,     0,     0,
      18,    19,    20,    21,     0,     0,     0,     0,     0,    24,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    -1,    -1,    -1,    -1,    77,    78,    79,
      80,    81,   137,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   161,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,     0,
       0,     0,     0,     0,     0,     0,   145,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
       0,     0,     0,     0,     0,     0,     0,   147,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    -1,    -1,    73,    74,    75,    76,    77,    78,
      79,    80,    81
};

static const yytype_int16 yycheck[] =
{
       1,     6,   164,     4,     5,     6,    89,    25,    24,   171,
      24,    45,    95,    45,    15,    26,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    25,
      46,   110,    46,    29,    29,    46,    29,    26,    43,    29,
      26,     0,    26,    39,    26,    26,    26,    21,    22,    23,
      35,    25,    48,   136,    55,    26,   139,    46,   137,    47,
      46,   144,    46,    25,    46,    46,    46,    25,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,   160,    83,    14,    15,    16,    25,    88,    89,    29,
     169,    29,   175,    94,    95,    21,    97,    23,    99,    25,
     179,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    45,    46,     2,
       3,     3,     2,     3,    29,   136,    43,   138,   139,    26,
      25,    25,    45,   144,    25,    43,    18,    19,   149,    21,
      22,    23,    29,    25,    32,    45,   101,    26,    29,    -1,
     154,   162,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,   175,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    -1,    -1,    45,    -1,    -1,    17,
      18,    19,    20,    26,    -1,    23,    -1,    25,    44,    27,
      28,    29,    30,    31,    -1,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    -1,    -1,
      48,    17,    18,    19,    20,    -1,    -1,    23,    -1,    25,
      -1,    27,    28,    29,    30,    31,    -1,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    -1,    45,
      -1,    -1,    48,    17,    18,    19,    20,    -1,    -1,    23,
      -1,    25,    -1,    27,    28,    29,    30,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    39,    40,    41,    42,    43,
      17,    18,    19,    20,    48,    -1,    23,    -1,    25,    -1,
      27,    28,    29,    30,    -1,    -1,    -1,    -1,    35,    -1,
      -1,    -1,    39,    40,    41,    42,    17,    18,    19,    20,
      -1,    48,    23,    -1,    25,    -1,    27,    28,    29,    30,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    39,    40,
      41,    42,    -1,    -1,    45,    -1,    -1,    48,    17,    18,
      19,    20,    -1,    -1,    23,    -1,    25,    -1,    27,    28,
      29,    30,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      39,    40,    41,    42,    -1,    -1,    -1,    -1,    -1,    48,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    26,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    26,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    24,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    24,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    17,    18,    19,    20,    23,    25,    27,    28,    29,
      30,    31,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    45,    48,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    63,    68,    70,    75,    77,    78,
      82,    86,    52,    25,    56,    58,    56,    52,    43,    52,
      62,    64,    65,    52,    70,    25,    79,    83,    29,    71,
      45,    52,    45,    45,    29,    69,    29,     0,    50,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    45,     3,    18,    19,    21,    22,    23,    25,
      59,    60,    61,    21,    23,    25,    70,    66,    24,    46,
      24,    46,    26,    26,    52,    25,    25,    73,    25,    45,
      67,    52,    52,    52,    52,    52,    52,    52,    52,    52,
      52,    52,    52,    52,    52,    29,    29,    52,    62,    29,
      52,    62,    26,    52,    52,    65,    25,    26,    80,    84,
      25,    72,    44,    51,    25,    24,    26,    24,    26,    47,
      62,    51,    52,    62,    74,    29,    76,    62,    52,    26,
      32,    26,    45,    76,    26,    46,    26,    44,    51,    81,
      52,    26,    68,    29,    51,    45,    68,    62,    26,    85,
      51
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    49,    50,    50,    51,    51,    51,    51,    51,    51,
      51,    51,    51,    51,    52,    52,    52,    52,    52,    52,
      52,    52,    52,    52,    52,    52,    52,    52,    52,    53,
      53,    53,    53,    53,    53,    53,    53,    54,    55,    55,
      55,    55,    55,    56,    56,    56,    56,    57,    57,    57,
      57,    58,    58,    58,    59,    59,    60,    61,    62,    62,
      62,    63,    63,    64,    64,    66,    65,    67,    67,    69,
      68,    71,    72,    70,    73,    74,    70,    75,    75,    75,
      75,    75,    75,    76,    76,    76,    77,    77,    79,    80,
      81,    78,    83,    84,    85,    82,    86,    86
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     0,     2,     1,     1,     1,     1,     2,
       2,     1,     1,     1,     1,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     1,     3,
       2,     2,     2,     2,     2,     2,     1,     3,     1,     1,
       1,     3,     1,     1,     2,     2,     1,     3,     4,     3,
       4,     4,     2,     6,     1,     1,     3,     5,     1,     3,
       0,     3,     3,     1,     3,     0,     6,     2,     0,     0,
       4,     0,     0,     7,     0,     0,     8,     1,     1,     1,
       1,     1,     1,     1,     3,     0,     5,     7,     0,     0,
       0,     8,     0,     0,     0,    12,     2,     3
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

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

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
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
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
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
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
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
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
  int yytoken = 0;
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

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
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


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 61 "parser.y" /* yacc.c:1646  */
    {;}
#line 1520 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 62 "parser.y" /* yacc.c:1646  */
    {;}
#line 1526 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 65 "parser.y" /* yacc.c:1646  */
    {;}
#line 1532 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 66 "parser.y" /* yacc.c:1646  */
    {;}
#line 1538 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 67 "parser.y" /* yacc.c:1646  */
    {;}
#line 1544 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 68 "parser.y" /* yacc.c:1646  */
    {;}
#line 1550 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 69 "parser.y" /* yacc.c:1646  */
    {;}
#line 1556 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 70 "parser.y" /* yacc.c:1646  */
    {if (gloop == 0) printf("Use of 'break' while not in a loop at line %d\n" , yylineno);}
#line 1562 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 71 "parser.y" /* yacc.c:1646  */
    {if (gloop == 0) printf("Use of 'continue' while not in a loop at line %d\n" , yylineno);}
#line 1568 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 72 "parser.y" /* yacc.c:1646  */
    {;}
#line 1574 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 73 "parser.y" /* yacc.c:1646  */
    {;}
#line 1580 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 74 "parser.y" /* yacc.c:1646  */
    {;}
#line 1586 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 78 "parser.y" /* yacc.c:1646  */
    { (yyval.intval) = (yyvsp[-2].intval) + (yyvsp[0].intval);}
#line 1592 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 79 "parser.y" /* yacc.c:1646  */
    { (yyval.intval) = (yyvsp[-2].intval) - (yyvsp[0].intval);}
#line 1598 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 80 "parser.y" /* yacc.c:1646  */
    { (yyval.intval) = (yyvsp[-2].intval) * (yyvsp[0].intval);}
#line 1604 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 81 "parser.y" /* yacc.c:1646  */
    { (yyval.intval) = (yyvsp[-2].intval) / (yyvsp[0].intval);}
#line 1610 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 82 "parser.y" /* yacc.c:1646  */
    { (yyval.intval) = (yyvsp[-2].intval) % (yyvsp[0].intval);}
#line 1616 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 83 "parser.y" /* yacc.c:1646  */
    { if((yyvsp[-2].intval) > (yyvsp[0].intval)){(yyval.intval) = 1;}else{(yyval.intval) = 0;};}
#line 1622 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 84 "parser.y" /* yacc.c:1646  */
    { if((yyvsp[-2].intval) >= (yyvsp[0].intval)){(yyval.intval) = 1;}else{(yyval.intval) = 0;};}
#line 1628 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 85 "parser.y" /* yacc.c:1646  */
    { if((yyvsp[-2].intval) < (yyvsp[0].intval)){(yyval.intval) = 1;}else{(yyval.intval) = 0;};}
#line 1634 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 86 "parser.y" /* yacc.c:1646  */
    { if((yyvsp[-2].intval) <= (yyvsp[0].intval)){(yyval.intval) = 1;}else{(yyval.intval) = 0;};}
#line 1640 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 87 "parser.y" /* yacc.c:1646  */
    { if((yyvsp[-2].intval) == (yyvsp[0].intval)){(yyval.intval) = 1;}else{(yyval.intval) = 0;};}
#line 1646 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 88 "parser.y" /* yacc.c:1646  */
    { if((yyvsp[-2].intval) != (yyvsp[0].intval)){(yyval.intval) = 1;}else{(yyval.intval) = 0;};}
#line 1652 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 89 "parser.y" /* yacc.c:1646  */
    { if((yyvsp[-2].intval) && (yyvsp[0].intval)){(yyval.intval) = 1;}else{(yyval.intval) = 0;};}
#line 1658 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 90 "parser.y" /* yacc.c:1646  */
    { if((yyvsp[-2].intval) || (yyvsp[0].intval)){(yyval.intval) = 1;}else{(yyval.intval) = 0;};}
#line 1664 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 91 "parser.y" /* yacc.c:1646  */
    {;}
#line 1670 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 94 "parser.y" /* yacc.c:1646  */
    {;}
#line 1676 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 95 "parser.y" /* yacc.c:1646  */
    {;}
#line 1682 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 96 "parser.y" /* yacc.c:1646  */
    {;}
#line 1688 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 97 "parser.y" /* yacc.c:1646  */
    {
      if((yyvsp[0].strval) != NULL && !strcmp((yyvsp[0].strval),"[userfunc]")){
        printf("ERROR: Using ProgramFunc as an lvalue at line: %d\n" , yylineno);
      }else if((yyvsp[0].strval) != NULL && !strcmp((yyvsp[0].strval),"[library function]")){
        printf("ERROR:Using LibFunc as an lvalue at line: %d\n" , yylineno);
      }
      }
#line 1700 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 104 "parser.y" /* yacc.c:1646  */
    {
      if((yyvsp[-1].strval) != NULL && !strcmp((yyvsp[-1].strval),"[userfunc]")){
            printf("ERROR:Using ProgramFunc as an lvalue at line: %d\n" , yylineno);
      }else if((yyvsp[-1].strval) != NULL && !strcmp((yyvsp[-1].strval),"[library function]")){
        printf("ERROR:Using LibFunc as an lvalue at line: %d\n" , yylineno);
      }
      }
#line 1712 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 111 "parser.y" /* yacc.c:1646  */
    {

      if((yyvsp[0].strval) != NULL && !strcmp((yyvsp[0].strval),"[userfunc]")){
            printf("ERROR:Using ProgramFunc as an lvalue at line: %d\n" , yylineno);
      }else if((yyvsp[0].strval) != NULL && !strcmp((yyvsp[0].strval),"[library function]")){
        printf("ERROR:Using LibFunc as an lvalue at line: %d\n" , yylineno);;
      }
      }
#line 1725 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 119 "parser.y" /* yacc.c:1646  */
    {
      if((yyvsp[-1].strval) != NULL && !strcmp((yyvsp[-1].strval),"[userfunc]")){
        printf("ERROR:Using ProgramFunc as an lvalue at line: %d\n" , yylineno);
      }else if((yyvsp[-1].strval) != NULL && !strcmp((yyvsp[-1].strval),"[library function]")){
        printf("ERROR:Using LibFunc as an lvalue at line: %d\n" , yylineno);
      }
      }
#line 1737 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 126 "parser.y" /* yacc.c:1646  */
    {;}
#line 1743 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 129 "parser.y" /* yacc.c:1646  */
    {
            //printf("%s yes\n",$1);
            if((yyvsp[-2].strval) != NULL && !strcmp((yyvsp[-2].strval),"[userfunc]")){
              printf("ERROR:Using ProgramFunc as an lvalue at line: %d\n" , yylineno);
            } else if((yyvsp[-2].strval) != NULL && !strcmp((yyvsp[-2].strval),"[library function]")){
              printf("ERROR:Using LibFunc as an lvalue at line: %d\n" , yylineno);
            }
            }
#line 1756 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 138 "parser.y" /* yacc.c:1646  */
    {}
#line 1762 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 139 "parser.y" /* yacc.c:1646  */
    {;}
#line 1768 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 140 "parser.y" /* yacc.c:1646  */
    {;}
#line 1774 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 141 "parser.y" /* yacc.c:1646  */
    {;}
#line 1780 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 142 "parser.y" /* yacc.c:1646  */
    {;}
#line 1786 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 145 "parser.y" /* yacc.c:1646  */
    {
          DataItem* tmp = table_lookup(yytext, "", 0, globalscope, funcscope, yylineno);
          /* printf("%s aleksi\n",tmp->type); */
          (yyval.strval) = tmp->type;
        }
#line 1796 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 150 "parser.y" /* yacc.c:1646  */
    {
        DataItem* tmp = table_lookup(yytext, "", 1 , globalscope, funcscope, yylineno);
        (yyval.strval) = tmp->type;
      }
#line 1805 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 154 "parser.y" /* yacc.c:1646  */
    {
        DataItem* tmp = table_lookup(yytext, "", 2 , globalscope, funcscope, yylineno);
        (yyval.strval) = tmp->type;

      }
#line 1815 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 159 "parser.y" /* yacc.c:1646  */
    {;}
#line 1821 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 162 "parser.y" /* yacc.c:1646  */
    {;}
#line 1827 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 163 "parser.y" /* yacc.c:1646  */
    {;}
#line 1833 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 164 "parser.y" /* yacc.c:1646  */
    {;}
#line 1839 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 165 "parser.y" /* yacc.c:1646  */
    {;}
#line 1845 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 168 "parser.y" /* yacc.c:1646  */
    {;}
#line 1851 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 169 "parser.y" /* yacc.c:1646  */
    {;}
#line 1857 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 170 "parser.y" /* yacc.c:1646  */
    {;}
#line 1863 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 173 "parser.y" /* yacc.c:1646  */
    {;}
#line 1869 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 174 "parser.y" /* yacc.c:1646  */
    {;}
#line 1875 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 177 "parser.y" /* yacc.c:1646  */
    {;}
#line 1881 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 179 "parser.y" /* yacc.c:1646  */
    {;}
#line 1887 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 181 "parser.y" /* yacc.c:1646  */
    {;}
#line 1893 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 182 "parser.y" /* yacc.c:1646  */
    {;}
#line 1899 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 183 "parser.y" /* yacc.c:1646  */
    {;}
#line 1905 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 186 "parser.y" /* yacc.c:1646  */
    {;}
#line 1911 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 187 "parser.y" /* yacc.c:1646  */
    {;}
#line 1917 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 191 "parser.y" /* yacc.c:1646  */
    {;}
#line 1923 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 192 "parser.y" /* yacc.c:1646  */
    {;}
#line 1929 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 195 "parser.y" /* yacc.c:1646  */
    {globalscope++; }
#line 1935 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 195 "parser.y" /* yacc.c:1646  */
    { globalscope--;}
#line 1941 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 199 "parser.y" /* yacc.c:1646  */
    {;}
#line 1947 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 200 "parser.y" /* yacc.c:1646  */
    {;}
#line 1953 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 205 "parser.y" /* yacc.c:1646  */
    {globalscope++;}
#line 1959 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 205 "parser.y" /* yacc.c:1646  */
    { globalscope--;}
#line 1965 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 208 "parser.y" /* yacc.c:1646  */
    {  table_lookup( yytext , "", 3 , globalscope, funcscope, yylineno);}
#line 1971 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 209 "parser.y" /* yacc.c:1646  */
    {funcscope++;}
#line 1977 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 209 "parser.y" /* yacc.c:1646  */
    {hide(funcscope--);}
#line 1983 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 210 "parser.y" /* yacc.c:1646  */
    { table_lookup(yytext, "", 4 , globalscope, funcscope, yylineno);}
#line 1989 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 211 "parser.y" /* yacc.c:1646  */
    {funcscope++;}
#line 1995 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 211 "parser.y" /* yacc.c:1646  */
    {hide(funcscope--);}
#line 2001 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 214 "parser.y" /* yacc.c:1646  */
    {;}
#line 2007 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 215 "parser.y" /* yacc.c:1646  */
    {;}
#line 2013 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 216 "parser.y" /* yacc.c:1646  */
    {;}
#line 2019 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 217 "parser.y" /* yacc.c:1646  */
    {;}
#line 2025 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 218 "parser.y" /* yacc.c:1646  */
    {;}
#line 2031 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 219 "parser.y" /* yacc.c:1646  */
    {;}
#line 2037 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 223 "parser.y" /* yacc.c:1646  */
    {table_lookup( yytext , "", 5 , funcscope, funcscope  , yylineno);}
#line 2043 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 224 "parser.y" /* yacc.c:1646  */
    {table_lookup( yytext , "", 6 , funcscope , funcscope, yylineno);}
#line 2049 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 225 "parser.y" /* yacc.c:1646  */
    {;}
#line 2055 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 229 "parser.y" /* yacc.c:1646  */
    {;}
#line 2061 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 232 "parser.y" /* yacc.c:1646  */
    {gloop++;}
#line 2067 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 232 "parser.y" /* yacc.c:1646  */
    {funcscope++;}
#line 2073 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 232 "parser.y" /* yacc.c:1646  */
    {funcscope--;}
#line 2079 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 232 "parser.y" /* yacc.c:1646  */
    {gloop--; globalscope++;}
#line 2085 "y.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 235 "parser.y" /* yacc.c:1646  */
    {gloop++;}
#line 2091 "y.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 235 "parser.y" /* yacc.c:1646  */
    {funcscope++;}
#line 2097 "y.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 235 "parser.y" /* yacc.c:1646  */
    {funcscope--;}
#line 2103 "y.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 235 "parser.y" /* yacc.c:1646  */
    {gloop--; globalscope++;}
#line 2109 "y.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 238 "parser.y" /* yacc.c:1646  */
    {if (funcscope == 0) printf("Use of 'return' while not in a function at line %d\n" , yylineno);}
#line 2115 "y.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 239 "parser.y" /* yacc.c:1646  */
    {if (funcscope == 0) printf("Use of 'return' while not in a function at line %d\n" , yylineno);}
#line 2121 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2125 "y.tab.c" /* yacc.c:1646  */
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


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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
  /* Do not reclaim the symbols of the rule whose action triggered
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
  return yyresult;
}
#line 242 "parser.y" /* yacc.c:1906  */


void yyerror(char* yaccProovidedMessage){
  fprintf(stderr, "%s: at line %d, before token: %s\n",yaccProovidedMessage, yylineno, yytext);
  fprintf(stderr, "INPUT NOT VALID\n");
}

int main(int argc, char** argv){
  symtable = create_new_symtable();
  table_insert("print", "[library function]", 7, 0, 0, 0);
  table_insert("input", "[library function]", 7, 0, 0, 0);
  table_insert("objectmemberkyes", "[library function]", 7, 0, 0, 0);
  table_insert("objectotslmembers", "[library function]", 7, 0, 0, 0);
  table_insert("objectcopy", "[library function]", 7, 0, 0, 0);
  table_insert("totalarguments", "[library function]", 7, 0, 0, 0);
  table_insert("argument", "[library function]", 7, 0, 0, 0);
  table_insert("typeof", "[library function]", 7, 0, 0, 0);
  table_insert("strtonum", "[library function]", 7, 0, 0, 0);
  table_insert("sqrt", "[library function]", 7, 0, 0, 0);
  table_insert("cos", "[library function]", 7, 0, 0, 0);
  table_insert("sin", "[library function]", 7, 0, 0, 0);
  //print_table();
  if(argc > 1){
    if(!(yyin = fopen(argv[1], "r"))){
      fprintf(stderr, "Cannot read  file: %s\n", argv[1]);
      return 1;
    }
  } else {
    yyin = stdin;
  }
  yyparse();
  print_table();
  return 0;
}
