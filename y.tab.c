/* A Bison parser, made by GNU Bison 3.5.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser.y"

  #include <stdio.h>
  #include <unistd.h>
  #include <stdlib.h>
  #include <string.h>
  #include "table.h"
	
	
	
  #define  YY_DECL int alpha_yylex (void* yylval)
  int yyerror (char* yaccProovidedMessage);
  extern int yylineno;
  int yylex();
  extern char* yytext;
  extern FILE* yyin;


  int globalscope = 0;
  int funcscope = 0;
  int open_func =0;

#line 92 "y.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
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
union YYSTYPE
{
#line 25 "parser.y"

  int intval;
  char* strval;
  float floatval;

#line 246 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */



#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))

/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

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

#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
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

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

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
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
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
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
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
#define YYLAST   530

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  49
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  38
/* YYNRULES -- Number of rules.  */
#define YYNRULES  96
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  181

#define YYUNDEFTOK  2
#define YYMAXUTOK   303


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
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
      95,    96,    97,    98,    99,   100,   101,   104,   106,   107,
     108,   109,   110,   113,   116,   120,   124,   127,   128,   129,
     130,   133,   134,   135,   138,   139,   142,   144,   146,   147,
     150,   151,   154,   155,   158,   158,   162,   163,   168,   168,
     171,   172,   172,   171,   173,   174,   174,   173,   177,   178,
     179,   180,   181,   182,   186,   187,   188,   191,   192,   195,
     195,   195,   198,   198,   198,   201,   202
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
  "rec_stmt", "block", "$@2", "funcdef", "$@3", "$@4", "$@5", "$@6", "$@7",
  "$@8", "const", "idlist", "ifstmt", "whilestmt", "$@9", "$@10",
  "forstmt", "$@11", "$@12", "returnstmt", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303
};
# endif

#define YYPACT_NINF (-132)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     230,   347,     7,     7,   347,   262,   289,  -132,  -132,  -132,
    -132,   -23,     9,    16,    23,   315,    11,    41,    30,  -132,
    -132,  -132,  -132,  -132,    32,    66,   230,   102,  -132,  -132,
    -132,   133,  -132,    74,  -132,  -132,  -132,  -132,  -132,  -132,
    -132,  -132,  -132,    56,    28,    74,    28,  -132,  -132,   480,
     -13,   -11,  -132,   193,    75,   347,  -132,  -132,  -132,    67,
    -132,   115,  -132,  -132,  -132,  -132,  -132,  -132,  -132,   347,
     347,   347,   347,   347,   347,   347,   347,   347,   347,   347,
     347,   347,  -132,   347,  -132,  -132,    71,    73,   347,   347,
    -132,  -132,  -132,   103,   347,   347,    77,   347,  -132,   347,
    -132,    90,  -132,   109,   392,   347,   347,   112,   110,  -132,
     198,   492,   503,   514,   514,   153,   153,   153,   153,    -6,
      -6,  -132,  -132,  -132,   480,  -132,   113,   438,    -9,  -132,
     459,    12,   109,    15,   480,  -132,   347,   230,   415,   -30,
     110,  -132,    94,  -132,  -132,   347,  -132,  -132,  -132,  -132,
     347,    14,   111,  -132,   347,    94,   116,   120,    19,   180,
    -132,   230,   230,   167,   122,  -132,  -132,  -132,  -132,  -132,
    -132,   347,  -132,    98,    21,    98,  -132,  -132,  -132,   230,
    -132
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       3,     0,     0,     0,     0,     0,     0,    78,    79,    43,
      80,     0,     0,     0,    70,     0,     0,     0,     0,    82,
      83,    81,    68,    13,     0,     0,     3,     0,    28,    14,
      36,    38,    46,    39,    40,    11,    12,    42,     5,     6,
       7,     8,    31,     0,    32,     0,    34,    30,    64,    58,
       0,     0,    62,     0,     0,     0,    89,    92,    74,     0,
      95,     0,     9,    10,    44,    67,    45,     1,     2,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     4,     0,    33,    35,     0,     0,     0,     0,
      52,    54,    55,     0,     0,     0,     0,     0,    60,     0,
      61,     0,    29,    41,     0,     0,     0,     0,    86,    96,
       0,    27,    26,    24,    25,    20,    21,    22,    23,    15,
      16,    17,    18,    19,    37,    47,     0,     0,     0,    49,
       0,     0,     0,     0,    59,    63,     0,     0,     0,     0,
      86,    84,    71,    69,    66,     0,    48,    56,    50,    51,
       0,     0,    87,    90,     0,    75,     0,     0,     0,     0,
      53,     0,     0,     0,     0,    85,    72,    57,    65,    88,
      91,     0,    76,     0,     0,     0,    73,    93,    77,     0,
      94
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -132,   124,   -98,    -1,  -132,  -132,  -132,    82,  -132,    87,
    -132,  -132,  -132,   -88,  -132,  -132,    58,  -132,  -132,  -131,
    -132,     0,  -132,  -132,  -132,  -132,  -132,  -132,  -132,     2,
    -132,  -132,  -132,  -132,  -132,  -132,  -132,  -132
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      90,    91,    92,    50,    34,    51,    52,    97,   110,    35,
      65,    36,    59,   157,   173,   107,   164,   175,    37,   142,
      38,    39,   105,   162,    40,   106,   179,    41
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      42,   128,    55,    47,    49,    53,    54,   131,    79,    80,
      81,    98,   144,   100,    61,   154,    99,   147,   139,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    43,    99,    56,   101,     9,    99,   149,   152,
     160,    57,   176,    96,   178,   167,    18,   177,   151,    86,
      87,    88,    58,    89,   104,    24,    62,   158,    99,    64,
      99,    66,   150,   169,   170,    99,    67,    99,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   180,   124,   174,    44,    46,    63,   127,    49,    45,
      45,    14,   108,   130,    49,    93,   133,    94,   134,    95,
     125,   103,   126,   132,   138,    49,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,   129,    48,   136,    49,    83,   140,   145,   141,
     156,    22,   155,   161,    49,   165,   166,    82,   172,   159,
      68,    84,    85,   163,    86,    87,    88,     0,    89,   135,
     109,    -1,    -1,    -1,    -1,    77,    78,    79,    80,    81,
      49,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
       0,     0,   171,     0,     0,     1,     2,     3,     4,   102,
       0,     5,     0,     6,   168,     7,     8,     9,    10,    11,
       0,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,   143,    23,     0,     0,    24,     1,     2,     3,
       4,     0,     0,     5,     0,     6,     0,     7,     8,     9,
      10,    11,     0,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,     0,    23,     0,     0,    24,     1,
       2,     3,     4,     0,     0,     5,     0,     6,     0,     7,
       8,     9,    10,     0,     0,     0,     0,     0,     0,     0,
       0,    18,    19,    20,    21,    48,     1,     2,     3,     4,
      24,     0,     5,     0,     6,     0,     7,     8,     9,    10,
       0,     0,     0,     0,    14,     0,     0,     0,    18,    19,
      20,    21,     1,     2,     3,     4,     0,    24,     5,     0,
       6,     0,     7,     8,     9,    10,     0,     0,     0,     0,
       0,     0,     0,     0,    18,    19,    20,    21,     0,     0,
      60,     0,     0,    24,     1,     2,     3,     4,     0,     0,
       5,     0,     6,     0,     7,     8,     9,    10,     0,     0,
       0,     0,     0,     0,     0,     0,    18,    19,    20,    21,
       0,     0,     0,     0,     0,    24,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   137,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   153,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,     0,     0,     0,     0,     0,
       0,     0,   146,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,     0,     0,     0,     0,
       0,     0,     0,   148,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      -1,    -1,    73,    74,    75,    76,    77,    78,    79,    80,
      81
};

static const yytype_int16 yycheck[] =
{
       1,    89,    25,     4,     5,     6,     6,    95,    14,    15,
      16,    24,   110,    24,    15,    45,    46,    26,   106,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    25,    46,    25,    46,    29,    46,    26,   137,
      26,    25,   173,    43,   175,    26,    39,    26,   136,    21,
      22,    23,    29,    25,    55,    48,    45,   145,    46,    29,
      46,    29,    47,   161,   162,    46,     0,    46,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,   179,    83,   171,     2,     3,    45,    88,    89,     2,
       3,    35,    25,    94,    95,    21,    97,    23,    99,    25,
      29,    26,    29,    26,   105,   106,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    29,    43,    25,   136,     3,    25,    25,    29,
      46,    43,   140,    32,   145,    29,    26,    45,    26,   150,
      26,    18,    19,   154,    21,    22,    23,    -1,    25,   101,
      45,     8,     9,    10,    11,    12,    13,    14,    15,    16,
     171,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      -1,    -1,    45,    -1,    -1,    17,    18,    19,    20,    26,
      -1,    23,    -1,    25,    44,    27,    28,    29,    30,    31,
      -1,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    -1,    -1,    48,    17,    18,    19,
      20,    -1,    -1,    23,    -1,    25,    -1,    27,    28,    29,
      30,    31,    -1,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    -1,    45,    -1,    -1,    48,    17,
      18,    19,    20,    -1,    -1,    23,    -1,    25,    -1,    27,
      28,    29,    30,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    39,    40,    41,    42,    43,    17,    18,    19,    20,
      48,    -1,    23,    -1,    25,    -1,    27,    28,    29,    30,
      -1,    -1,    -1,    -1,    35,    -1,    -1,    -1,    39,    40,
      41,    42,    17,    18,    19,    20,    -1,    48,    23,    -1,
      25,    -1,    27,    28,    29,    30,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    39,    40,    41,    42,    -1,    -1,
      45,    -1,    -1,    48,    17,    18,    19,    20,    -1,    -1,
      23,    -1,    25,    -1,    27,    28,    29,    30,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    39,    40,    41,    42,
      -1,    -1,    -1,    -1,    -1,    48,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    26,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    26,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    24,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    24,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    17,    18,    19,    20,    23,    25,    27,    28,    29,
      30,    31,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    45,    48,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    63,    68,    70,    77,    79,    80,
      83,    86,    52,    25,    56,    58,    56,    52,    43,    52,
      62,    64,    65,    52,    70,    25,    25,    25,    29,    71,
      45,    52,    45,    45,    29,    69,    29,     0,    50,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    45,     3,    18,    19,    21,    22,    23,    25,
      59,    60,    61,    21,    23,    25,    70,    66,    24,    46,
      24,    46,    26,    26,    52,    81,    84,    74,    25,    45,
      67,    52,    52,    52,    52,    52,    52,    52,    52,    52,
      52,    52,    52,    52,    52,    29,    29,    52,    62,    29,
      52,    62,    26,    52,    52,    65,    25,    26,    52,    62,
      25,    29,    78,    44,    51,    25,    24,    26,    24,    26,
      47,    62,    51,    26,    45,    78,    46,    72,    62,    52,
      26,    32,    82,    52,    75,    29,    26,    26,    44,    51,
      51,    45,    26,    73,    62,    76,    68,    26,    68,    85,
      51
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    49,    50,    50,    51,    51,    51,    51,    51,    51,
      51,    51,    51,    51,    52,    52,    52,    52,    52,    52,
      52,    52,    52,    52,    52,    52,    52,    52,    52,    53,
      53,    53,    53,    53,    53,    53,    53,    54,    55,    55,
      55,    55,    55,    56,    56,    56,    56,    57,    57,    57,
      57,    58,    58,    58,    59,    59,    60,    61,    62,    62,
      63,    63,    64,    64,    66,    65,    67,    67,    69,    68,
      71,    72,    73,    70,    74,    75,    76,    70,    77,    77,
      77,    77,    77,    77,    78,    78,    78,    79,    79,    81,
      82,    80,    84,    85,    83,    86,    86
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     0,     2,     1,     1,     1,     1,     2,
       2,     1,     1,     1,     1,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     1,     3,
       2,     2,     2,     2,     2,     2,     1,     3,     1,     1,
       1,     3,     1,     1,     2,     2,     1,     3,     4,     3,
       4,     4,     2,     6,     1,     1,     3,     5,     1,     3,
       3,     3,     1,     3,     0,     6,     2,     0,     0,     4,
       0,     0,     0,     8,     0,     0,     0,     9,     1,     1,
       1,     1,     1,     1,     1,     3,     0,     5,     7,     0,
       0,     7,     0,     0,    11,     2,     3
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
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


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
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
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
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
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
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
            else
              goto append;

          append:
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

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
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
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

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
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
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
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
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
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
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
          ++yyp;
          ++yyformat;
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
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

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
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
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
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
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
#line 61 "parser.y"
                     {;}
#line 1620 "y.tab.c"
    break;

  case 3:
#line 62 "parser.y"
        {;}
#line 1626 "y.tab.c"
    break;

  case 4:
#line 65 "parser.y"
               {;}
#line 1632 "y.tab.c"
    break;

  case 5:
#line 66 "parser.y"
           {printf("ifstmt;\n");}
#line 1638 "y.tab.c"
    break;

  case 6:
#line 67 "parser.y"
              {printf("whilestmt\n");}
#line 1644 "y.tab.c"
    break;

  case 7:
#line 68 "parser.y"
            {printf("forstmt\n");}
#line 1650 "y.tab.c"
    break;

  case 8:
#line 69 "parser.y"
               {printf("returnstmt\n");}
#line 1656 "y.tab.c"
    break;

  case 9:
#line 70 "parser.y"
               {printf("break;\n");}
#line 1662 "y.tab.c"
    break;

  case 10:
#line 71 "parser.y"
                  {printf("continue;\n");}
#line 1668 "y.tab.c"
    break;

  case 11:
#line 72 "parser.y"
          {;}
#line 1674 "y.tab.c"
    break;

  case 12:
#line 73 "parser.y"
            {;}
#line 1680 "y.tab.c"
    break;

  case 13:
#line 74 "parser.y"
         {printf(";\n");}
#line 1686 "y.tab.c"
    break;

  case 14:
#line 77 "parser.y"
                {;}
#line 1692 "y.tab.c"
    break;

  case 15:
#line 78 "parser.y"
                    {printf("%d + %d\n",(yyvsp[-2].intval),(yyvsp[0].intval)); (yyval.intval) = (yyvsp[-2].intval) + (yyvsp[0].intval);}
#line 1698 "y.tab.c"
    break;

  case 16:
#line 79 "parser.y"
                     {printf("%d - %d\n",(yyvsp[-2].intval),(yyvsp[0].intval)); (yyval.intval) = (yyvsp[-2].intval) - (yyvsp[0].intval);}
#line 1704 "y.tab.c"
    break;

  case 17:
#line 80 "parser.y"
                   {printf("%d * %d\n",(yyvsp[-2].intval),(yyvsp[0].intval)); (yyval.intval) = (yyvsp[-2].intval) * (yyvsp[0].intval);}
#line 1710 "y.tab.c"
    break;

  case 18:
#line 81 "parser.y"
                   {printf("%d / %d\n",(yyvsp[-2].intval),(yyvsp[0].intval)); (yyval.intval) = (yyvsp[-2].intval) / (yyvsp[0].intval);}
#line 1716 "y.tab.c"
    break;

  case 19:
#line 82 "parser.y"
                   {printf("%d MOD %d\n",(yyvsp[-2].intval),(yyvsp[0].intval)); (yyval.intval) = (yyvsp[-2].intval) % (yyvsp[0].intval);}
#line 1722 "y.tab.c"
    break;

  case 20:
#line 83 "parser.y"
                       {printf("%d > %d\n",(yyvsp[-2].intval),(yyvsp[0].intval)); if((yyvsp[-2].intval) > (yyvsp[0].intval)){(yyval.intval) = 1;}else{(yyval.intval) = 0;};}
#line 1728 "y.tab.c"
    break;

  case 21:
#line 84 "parser.y"
                          {printf("%d >= %d\n",(yyvsp[-2].intval),(yyvsp[0].intval)); if((yyvsp[-2].intval) >= (yyvsp[0].intval)){(yyval.intval) = 1;}else{(yyval.intval) = 0;};}
#line 1734 "y.tab.c"
    break;

  case 22:
#line 85 "parser.y"
                    {printf("%d < %d\n",(yyvsp[-2].intval),(yyvsp[0].intval)); if((yyvsp[-2].intval) < (yyvsp[0].intval)){(yyval.intval) = 1;}else{(yyval.intval) = 0;};}
#line 1740 "y.tab.c"
    break;

  case 23:
#line 86 "parser.y"
                       {printf("%d <= %d\n",(yyvsp[-2].intval),(yyvsp[0].intval)); if((yyvsp[-2].intval) <= (yyvsp[0].intval)){(yyval.intval) = 1;}else{(yyval.intval) = 0;};}
#line 1746 "y.tab.c"
    break;

  case 24:
#line 87 "parser.y"
                  {printf("%d == %d\n",(yyvsp[-2].intval),(yyvsp[0].intval)); if((yyvsp[-2].intval) == (yyvsp[0].intval)){(yyval.intval) = 1;}else{(yyval.intval) = 0;};}
#line 1752 "y.tab.c"
    break;

  case 25:
#line 88 "parser.y"
                      {printf("%d != %d\n",(yyvsp[-2].intval),(yyvsp[0].intval)); if((yyvsp[-2].intval) != (yyvsp[0].intval)){(yyval.intval) = 1;}else{(yyval.intval) = 0;};}
#line 1758 "y.tab.c"
    break;

  case 26:
#line 89 "parser.y"
                   {printf("%d AND %d\n",(yyvsp[-2].intval),(yyvsp[0].intval)); if((yyvsp[-2].intval) && (yyvsp[0].intval)){(yyval.intval) = 1;}else{(yyval.intval) = 0;};}
#line 1764 "y.tab.c"
    break;

  case 27:
#line 90 "parser.y"
                  {printf("%d OR %d\n",(yyvsp[-2].intval),(yyvsp[0].intval)); if((yyvsp[-2].intval) || (yyvsp[0].intval)){(yyval.intval) = 1;}else{(yyval.intval) = 0;};}
#line 1770 "y.tab.c"
    break;

  case 28:
#line 91 "parser.y"
          {;}
#line 1776 "y.tab.c"
    break;

  case 29:
#line 94 "parser.y"
                      {printf("L_PAR expr R_PAR\n");}
#line 1782 "y.tab.c"
    break;

  case 30:
#line 95 "parser.y"
                              {printf("UMINUS expr prec UMINUS\n");}
#line 1788 "y.tab.c"
    break;

  case 31:
#line 96 "parser.y"
              {printf("not expr\n");}
#line 1794 "y.tab.c"
    break;

  case 32:
#line 97 "parser.y"
                   {printf("D_PLUS lvalue\n");}
#line 1800 "y.tab.c"
    break;

  case 33:
#line 98 "parser.y"
                   {printf("lvalue D_PLUS\n");}
#line 1806 "y.tab.c"
    break;

  case 34:
#line 99 "parser.y"
                    {printf("D_MINUS lvalue\n");}
#line 1812 "y.tab.c"
    break;

  case 35:
#line 100 "parser.y"
                    {printf("lvalue D_MINUS\n");}
#line 1818 "y.tab.c"
    break;

  case 36:
#line 101 "parser.y"
            {;}
#line 1824 "y.tab.c"
    break;

  case 37:
#line 104 "parser.y"
                              {;}
#line 1830 "y.tab.c"
    break;

  case 38:
#line 106 "parser.y"
               {}
#line 1836 "y.tab.c"
    break;

  case 39:
#line 107 "parser.y"
             {printf("call\n");}
#line 1842 "y.tab.c"
    break;

  case 40:
#line 108 "parser.y"
                  {printf("objectdef\n");}
#line 1848 "y.tab.c"
    break;

  case 41:
#line 109 "parser.y"
                            {printf("L_PAR funcdef R_PAR\n");}
#line 1854 "y.tab.c"
    break;

  case 42:
#line 110 "parser.y"
              {;}
#line 1860 "y.tab.c"
    break;

  case 43:
#line 113 "parser.y"
          {
          table_lookup(yytext, "", 0, globalscope, open_func, yylineno);
        }
#line 1868 "y.tab.c"
    break;

  case 44:
#line 116 "parser.y"
                {

        table_lookup(yytext, "", 1 , globalscope, open_func, yylineno);
      }
#line 1877 "y.tab.c"
    break;

  case 45:
#line 120 "parser.y"
                  {

        table_lookup(yytext, "", 2 , globalscope, open_func, yylineno);
      }
#line 1886 "y.tab.c"
    break;

  case 46:
#line 124 "parser.y"
              {printf("member\n");}
#line 1892 "y.tab.c"
    break;

  case 47:
#line 127 "parser.y"
                     {printf("lvalue dot id\n");}
#line 1898 "y.tab.c"
    break;

  case 48:
#line 128 "parser.y"
                               {printf("lvalue L_BRA expr R_BRA\n");}
#line 1904 "y.tab.c"
    break;

  case 49:
#line 129 "parser.y"
                   {printf("call dot id\n");}
#line 1910 "y.tab.c"
    break;

  case 50:
#line 130 "parser.y"
                             {printf("call L_BRA expr R_BRA\n");}
#line 1916 "y.tab.c"
    break;

  case 51:
#line 133 "parser.y"
                            {printf("call L_PAR elist R_PAR\n");}
#line 1922 "y.tab.c"
    break;

  case 52:
#line 134 "parser.y"
                       {printf("lvalue callsuffix\n");}
#line 1928 "y.tab.c"
    break;

  case 53:
#line 135 "parser.y"
                                           {printf("L_PAR funcdef R_PAR L_PAR elist R_PAR\n");}
#line 1934 "y.tab.c"
    break;

  case 54:
#line 138 "parser.y"
                    {printf("callsuffix\n");}
#line 1940 "y.tab.c"
    break;

  case 55:
#line 139 "parser.y"
                      {printf("methodcall\n");}
#line 1946 "y.tab.c"
    break;

  case 56:
#line 142 "parser.y"
                           {printf("L_PAR elist R_PAR\n");}
#line 1952 "y.tab.c"
    break;

  case 57:
#line 144 "parser.y"
                                       {printf("D_DOT id L_PAR elist R_PAR\n");}
#line 1958 "y.tab.c"
    break;

  case 58:
#line 146 "parser.y"
             {;}
#line 1964 "y.tab.c"
    break;

  case 59:
#line 147 "parser.y"
                         {;}
#line 1970 "y.tab.c"
    break;

  case 60:
#line 150 "parser.y"
                            {printf("l_bra elist R_BRA\n");}
#line 1976 "y.tab.c"
    break;

  case 61:
#line 151 "parser.y"
                              {printf("L_BRA indexed R_BRA\n");}
#line 1982 "y.tab.c"
    break;

  case 62:
#line 154 "parser.y"
                    {printf("indexedelem\n");}
#line 1988 "y.tab.c"
    break;

  case 63:
#line 155 "parser.y"
                                  {printf("indexed comma indexedelem\n");}
#line 1994 "y.tab.c"
    break;

  case 64:
#line 158 "parser.y"
                    {globalscope++; }
#line 2000 "y.tab.c"
    break;

  case 65:
#line 158 "parser.y"
                                                            {printf("indexedelem\n"); globalscope--;}
#line 2006 "y.tab.c"
    break;

  case 66:
#line 162 "parser.y"
                        {;}
#line 2012 "y.tab.c"
    break;

  case 67:
#line 163 "parser.y"
            {;}
#line 2018 "y.tab.c"
    break;

  case 68:
#line 168 "parser.y"
            {globalscope++;}
#line 2024 "y.tab.c"
    break;

  case 69:
#line 168 "parser.y"
                                            { globalscope--;}
#line 2030 "y.tab.c"
    break;

  case 70:
#line 171 "parser.y"
              { funcscope++; table_lookup( yytext , "", 3 , globalscope, open_func, yylineno);}
#line 2036 "y.tab.c"
    break;

  case 71:
#line 172 "parser.y"
                      {funcscope--;}
#line 2042 "y.tab.c"
    break;

  case 72:
#line 172 "parser.y"
                                           { open_func++;}
#line 2048 "y.tab.c"
    break;

  case 73:
#line 172 "parser.y"
                                                                {open_func--;}
#line 2054 "y.tab.c"
    break;

  case 74:
#line 173 "parser.y"
                {funcscope++; table_lookup(yytext, "", 4 , globalscope, open_func, yylineno);}
#line 2060 "y.tab.c"
    break;

  case 75:
#line 174 "parser.y"
                    {funcscope--;}
#line 2066 "y.tab.c"
    break;

  case 76:
#line 174 "parser.y"
                                        {open_func++;}
#line 2072 "y.tab.c"
    break;

  case 77:
#line 174 "parser.y"
                                                            {open_func--;}
#line 2078 "y.tab.c"
    break;

  case 78:
#line 177 "parser.y"
          {;}
#line 2084 "y.tab.c"
    break;

  case 79:
#line 178 "parser.y"
           {printf("real\n");}
#line 2090 "y.tab.c"
    break;

  case 80:
#line 179 "parser.y"
             {printf("string\n");}
#line 2096 "y.tab.c"
    break;

  case 81:
#line 180 "parser.y"
          {printf("nil\n");}
#line 2102 "y.tab.c"
    break;

  case 82:
#line 181 "parser.y"
           {printf("true\n");}
#line 2108 "y.tab.c"
    break;

  case 83:
#line 182 "parser.y"
            {printf("false\n");}
#line 2114 "y.tab.c"
    break;

  case 84:
#line 186 "parser.y"
          {table_lookup( yytext , "", 5 , funcscope, open_func, yylineno);}
#line 2120 "y.tab.c"
    break;

  case 85:
#line 187 "parser.y"
                       {table_lookup( yytext , "", 6 , funcscope, open_func, yylineno);}
#line 2126 "y.tab.c"
    break;

  case 86:
#line 188 "parser.y"
       {;}
#line 2132 "y.tab.c"
    break;

  case 87:
#line 191 "parser.y"
                                 {printf("ifstmt\n");}
#line 2138 "y.tab.c"
    break;

  case 88:
#line 192 "parser.y"
                                             {printf("ifstmt 2\n");}
#line 2144 "y.tab.c"
    break;

  case 89:
#line 195 "parser.y"
                       {funcscope++;}
#line 2150 "y.tab.c"
    break;

  case 90:
#line 195 "parser.y"
                                                 {funcscope--;}
#line 2156 "y.tab.c"
    break;

  case 91:
#line 195 "parser.y"
                                                                    {printf("whilestmt\n"); globalscope++;}
#line 2162 "y.tab.c"
    break;

  case 92:
#line 198 "parser.y"
                   {funcscope++;}
#line 2168 "y.tab.c"
    break;

  case 93:
#line 198 "parser.y"
                                                                   {funcscope--;}
#line 2174 "y.tab.c"
    break;

  case 94:
#line 198 "parser.y"
                                                                                      {printf("forstmt\n"); globalscope++;}
#line 2180 "y.tab.c"
    break;

  case 95:
#line 201 "parser.y"
                       {printf("return\n");}
#line 2186 "y.tab.c"
    break;

  case 96:
#line 202 "parser.y"
                            {printf("return2\n");}
#line 2192 "y.tab.c"
    break;


#line 2196 "y.tab.c"

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
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

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
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

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


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
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
                  yystos[+*yyssp], yyvsp);
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
#line 205 "parser.y"


int yyerror(char* yaccProovidedMessage){
  fprintf(stderr, "%s: at line %d, before token: %s\n",yaccProovidedMessage, yylineno, yytext);
  fprintf(stderr, "INPUT NOT VALID\n");
  return -1;
}

int main(int argc, char** argv){
  symtable = create_new_symtable();
  /* table_insert("print", "[[library function]]", 0, 0, 0);
  table_insert("input", "[library function]", 0, 0, 0);
  table_insert("objectmemberkyes", "[library function]", 0, 0, 0);
  table_insert("objectotslmembers", "[library function]", 0, 0, 0);
  table_insert("objectcopy", "[library function]", 0, 0, 0);
  table_insert("totalarguments", "[library function]", 0, 0, 0);
  table_insert("argument", "[library function]", 0, 0, 0);
  table_insert("typeof", "[library function]", 0, 0, 0);
  table_insert("strtonum", "[library function]", 0, 0, 0);
  table_insert("sqrt", "[library function]", 0, 0, 0);
  table_insert("cos", "[library function]", 0, 0, 0);
  table_insert("sin", "[library function]", 0, 0, 0);*/
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
