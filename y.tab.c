/* A Bison parser, made by GNU Bison 3.5.4.  */

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
#define YYBISON_VERSION "3.5.4"

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
     #include "quads.h"
     #include "stack.h"

     #define  YY_DECL int alpha_yylex (void* yylval)
     void yyerror (char* yaccProovidedMessage);
     int yylex();
     extern int yylineno;
     extern char* yytext;
     extern FILE* yyin;
     unsigned gloop = 0;
     unsigned loopcounter = 0;
     Stack* breakstack;
     Stack* contstack;
     Stack* loopcounterstack;
     Stack* scopeoffsetstack;

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
     struct expr* exprval;
     struct stmt_t stmtval;
     struct call callval;
     struct symbol* symval;
     struct prefix prefval;

#line 251 "y.tab.c"

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
#define YYFINAL  71
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   584

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  49
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  48
/* YYNRULES -- Number of rules.  */
#define YYNRULES  107
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  192

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
static const yytype_int16 yyrline[] =
{
       0,    74,    74,    77,    80,    86,    93,    94,    95,    96,
      97,   103,   109,   110,   111,   116,   117,   122,   127,   132,
     137,   142,   152,   162,   172,   184,   194,   204,   204,   227,
     227,   249,   252,   253,   259,   276,   292,   309,   325,   346,
     349,   369,   370,   371,   372,   376,   379,   383,   390,   394,
     397,   398,   404,   405,   408,   409,   418,   425,   426,   429,
     435,   441,   445,   447,   451,   454,   464,   476,   477,   480,
     484,   485,   488,   488,   491,   495,   501,   514,   520,   527,
     528,   530,   544,   545,   546,   547,   548,   549,   552,   553,
     554,   557,   567,   573,   576,   582,   588,   597,   606,   611,
     614,   614,   624,   624,   635,   643,   652,   658
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
  "D_COLON", "$accept", "program", "stmts", "stmt", "expr", "$@1", "$@2",
  "term", "assignexpr", "primary", "lvalue", "member", "call",
  "callsuffix", "normcall", "methodcall", "elist", "comma_elist",
  "objectdef", "indexed", "indexedelem", "rec_stmt", "block", "$@3",
  "funcname", "funcprefix", "funcargs", "funcbody", "funcblockstart",
  "funcblockend", "funcdef", "const", "idlist", "ifprefix", "elseprefix",
  "ifstmt", "whilestart", "whilecond", "whilestmt", "N", "M", "forprefix",
  "$@4", "forstmt", "$@5", "break", "continue", "returnstmt", YY_NULLPTR
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

#define YYPACT_NINF (-165)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     260,   390,   390,    18,    18,   293,   325,  -165,  -165,  -165,
    -165,   -15,  -165,  -165,    -7,   357,  -165,  -165,    -6,  -165,
    -165,  -165,  -165,  -165,    16,    26,   260,  -165,   167,  -165,
    -165,  -165,    93,  -165,    37,  -165,  -165,     2,  -165,  -165,
     260,  -165,    21,  -165,  -165,  -165,     8,    10,  -165,  -165,
    -165,    24,    27,    37,    27,   390,   124,    39,    -4,  -165,
     435,    41,   390,    40,  -165,  -165,  -165,   181,  -165,  -165,
    -165,  -165,  -165,  -165,  -165,   390,   390,   390,   390,   390,
     390,   390,   390,   390,   390,   390,  -165,   390,  -165,  -165,
      44,    58,   390,   390,  -165,  -165,  -165,    59,   390,   390,
      60,  -165,    36,   390,   260,   390,  -165,  -165,    43,    25,
     390,  -165,  -165,  -165,    47,  -165,    45,   458,   390,  -165,
     227,  -165,  -165,   557,   557,   133,   133,   133,   133,    -3,
      -3,  -165,  -165,  -165,   546,  -165,    68,   504,    69,  -165,
     525,    73,  -165,    -2,    51,  -165,   260,   481,  -165,    74,
      45,   390,   124,  -165,   390,  -165,    61,  -165,  -165,   390,
     390,   390,  -165,  -165,  -165,  -165,  -165,    76,  -165,  -165,
    -165,  -165,  -165,   209,  -165,    77,  -165,   222,   568,    81,
    -165,  -165,   260,  -165,  -165,   390,  -165,  -165,   194,  -165,
    -165,  -165
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     0,    62,     0,    82,    83,    46,
      84,     0,    95,   100,    75,     0,   104,   105,     0,    86,
      87,    85,    72,    14,     0,     0,     2,     3,     0,    31,
      15,    39,    41,    49,    42,    43,    12,     0,    13,    45,
       0,     6,     0,     7,    98,     8,     0,     0,     9,    33,
      34,     0,    35,     0,    37,     0,    64,     0,     0,    67,
       0,     0,     0,     0,    74,    76,   106,     0,    47,    71,
      48,     1,     4,    29,    27,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     5,     0,    36,    38,
       0,     0,     0,    62,    55,    57,    58,     0,     0,    62,
      90,    79,    93,     0,     0,    62,    10,    11,     0,     0,
       0,    61,    65,    66,     0,    32,    44,     0,    62,   107,
       0,    99,    99,    25,    26,    21,    22,    23,    24,    16,
      17,    18,    19,    20,    40,    50,     0,     0,     0,    52,
       0,     0,    88,     0,     0,    92,     0,     0,    97,     0,
       0,     0,    64,    68,    62,    91,     0,    73,    70,     0,
       0,    62,    51,    59,    53,    54,    77,     0,    78,    80,
      94,    96,    98,     0,    63,     0,    99,    30,    28,     0,
      89,    81,     0,    69,    56,     0,    60,   102,     0,    98,
     101,   103
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -165,  -165,  -165,   -19,    -1,  -165,  -165,  -165,  -165,  -165,
      13,  -165,    15,  -165,  -165,  -165,   -90,   -44,  -165,  -165,
       5,  -165,   -34,  -165,  -165,  -165,  -165,  -165,  -165,  -165,
       0,  -165,  -165,  -165,  -165,  -165,  -165,  -165,  -165,  -164,
    -120,  -165,  -165,  -165,  -165,  -165,  -165,  -165
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    25,    26,    27,    28,   122,   121,    29,    30,    31,
      32,    33,    34,    94,    95,    96,    57,   111,    35,    58,
      59,   120,    36,    69,    65,    37,   101,   169,   144,   181,
      38,    39,   143,    40,   146,    41,    42,   104,    43,   105,
     159,    44,    63,    45,   189,    46,    47,    48
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      49,    50,   160,   138,    56,    60,    61,    72,   182,   141,
      62,    83,    84,    85,    67,   149,    52,    54,    53,    53,
     113,   102,    64,    68,   166,   191,    71,   100,   156,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,   114,    51,   167,    70,   103,     9,    90,    91,
      92,   108,    93,   106,   109,   107,   185,    18,    97,    14,
      98,   117,    99,   112,   175,   118,    24,   116,   145,   150,
     154,   179,   151,   135,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   148,   134,   136,   139,   142,
      55,   137,    56,   161,    22,   163,    87,   140,    56,   165,
     172,   158,   147,   184,    56,   180,   176,   186,   174,   152,
     168,    88,    89,     0,    90,    91,    92,    56,    93,   153,
       0,     0,     0,     0,     0,     0,     0,   170,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    -1,    -1,    -1,    -1,    81,    82,    83,    84,    85,
     173,     0,     0,    56,     0,     0,     0,     0,   177,   178,
      56,     0,     0,   187,     0,     0,     0,     0,     0,     0,
     110,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,   188,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,     0,    86,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,   119,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,   190,
       1,     0,     0,     0,     2,     3,     4,     0,     0,     0,
       5,     0,     6,   183,     7,     8,     9,    10,    11,     0,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,   157,    23,     1,     0,    24,     0,     2,     3,     4,
       0,     0,     0,     5,     0,     6,     0,     7,     8,     9,
      10,    11,     0,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,     0,    23,     1,     0,    24,     0,
       2,     3,     4,     0,     0,     0,     5,     0,     6,     0,
       7,     8,     9,    10,     0,     0,     0,     0,     0,     0,
       0,     0,    18,    19,    20,    21,    55,     0,     1,     0,
       0,    24,     2,     3,     4,     0,     0,     0,     5,     0,
       6,     0,     7,     8,     9,    10,     0,     0,     0,     0,
      14,     0,     0,     0,    18,    19,    20,    21,     0,     0,
       1,     0,     0,    24,     2,     3,     4,     0,     0,     0,
       5,     0,     6,     0,     7,     8,     9,    10,     0,     0,
       0,     0,     0,     0,     0,     0,    18,    19,    20,    21,
       0,     0,    66,     1,     0,    24,     0,     2,     3,     4,
       0,     0,     0,     5,     0,     6,     0,     7,     8,     9,
      10,     0,     0,     0,     0,     0,     0,     0,     0,    18,
      19,    20,    21,     0,     0,     0,     0,     0,    24,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   115,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   155,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   171,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,     0,     0,     0,     0,     0,     0,     0,   162,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,     0,     0,     0,     0,     0,     0,     0,   164,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    -1,    -1,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85
};

static const yytype_int16 yycheck[] =
{
       1,     2,   122,    93,     5,     6,     6,    26,   172,    99,
      25,    14,    15,    16,    15,   105,     3,     4,     3,     4,
      24,    40,    29,    29,    26,   189,     0,    25,   118,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    46,    25,    46,    29,    25,    29,    21,    22,
      23,    51,    25,    45,    55,    45,   176,    39,    21,    35,
      23,    62,    25,    24,   154,    25,    48,    26,    32,    26,
      25,   161,    47,    29,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,   104,    87,    29,    29,    29,
      43,    92,    93,    25,    43,    26,     3,    98,    99,    26,
      26,   120,   103,    26,   105,    29,    45,    26,   152,   110,
     144,    18,    19,    -1,    21,    22,    23,   118,    25,   114,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   146,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,     8,     9,    10,    11,    12,    13,    14,    15,    16,
     151,    -1,    -1,   154,    -1,    -1,    -1,    -1,   159,   160,
     161,    -1,    -1,   182,    -1,    -1,    -1,    -1,    -1,    -1,
      46,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,   185,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    -1,    45,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    45,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    45,
      13,    -1,    -1,    -1,    17,    18,    19,    -1,    -1,    -1,
      23,    -1,    25,    44,    27,    28,    29,    30,    31,    -1,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    13,    -1,    48,    -1,    17,    18,    19,
      -1,    -1,    -1,    23,    -1,    25,    -1,    27,    28,    29,
      30,    31,    -1,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    -1,    45,    13,    -1,    48,    -1,
      17,    18,    19,    -1,    -1,    -1,    23,    -1,    25,    -1,
      27,    28,    29,    30,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    39,    40,    41,    42,    43,    -1,    13,    -1,
      -1,    48,    17,    18,    19,    -1,    -1,    -1,    23,    -1,
      25,    -1,    27,    28,    29,    30,    -1,    -1,    -1,    -1,
      35,    -1,    -1,    -1,    39,    40,    41,    42,    -1,    -1,
      13,    -1,    -1,    48,    17,    18,    19,    -1,    -1,    -1,
      23,    -1,    25,    -1,    27,    28,    29,    30,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    39,    40,    41,    42,
      -1,    -1,    45,    13,    -1,    48,    -1,    17,    18,    19,
      -1,    -1,    -1,    23,    -1,    25,    -1,    27,    28,    29,
      30,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    39,
      40,    41,    42,    -1,    -1,    -1,    -1,    -1,    48,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    26,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    26,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    26,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    24,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    24,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    13,    17,    18,    19,    23,    25,    27,    28,    29,
      30,    31,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    45,    48,    50,    51,    52,    53,    56,
      57,    58,    59,    60,    61,    67,    71,    74,    79,    80,
      82,    84,    85,    87,    90,    92,    94,    95,    96,    53,
      53,    25,    59,    61,    59,    43,    53,    65,    68,    69,
      53,    79,    25,    91,    29,    73,    45,    53,    29,    72,
      29,     0,    52,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    45,     3,    18,    19,
      21,    22,    23,    25,    62,    63,    64,    21,    23,    25,
      25,    75,    52,    25,    86,    88,    45,    45,    79,    53,
      46,    66,    24,    24,    46,    26,    26,    53,    25,    45,
      70,    55,    54,    53,    53,    53,    53,    53,    53,    53,
      53,    53,    53,    53,    53,    29,    29,    53,    65,    29,
      53,    65,    29,    81,    77,    32,    83,    53,    52,    65,
      26,    47,    53,    69,    25,    26,    65,    44,    52,    89,
      89,    25,    24,    26,    24,    26,    26,    46,    71,    76,
      52,    26,    26,    53,    66,    65,    45,    53,    53,    65,
      29,    78,    88,    44,    26,    89,    26,    52,    53,    93,
      45,    88
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    49,    50,    51,    51,    52,    52,    52,    52,    52,
      52,    52,    52,    52,    52,    53,    53,    53,    53,    53,
      53,    53,    53,    53,    53,    53,    53,    54,    53,    55,
      53,    53,    56,    56,    56,    56,    56,    56,    56,    56,
      57,    58,    58,    58,    58,    58,    59,    59,    59,    59,
      60,    60,    60,    60,    61,    61,    61,    62,    62,    63,
      64,    65,    65,    66,    66,    67,    67,    68,    68,    69,
      70,    70,    72,    71,    73,    73,    74,    75,    76,    77,
      78,    79,    80,    80,    80,    80,    80,    80,    81,    81,
      81,    82,    83,    84,    84,    85,    86,    87,    88,    89,
      91,    90,    93,    92,    94,    95,    96,    96
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     2,     1,     1,     1,     1,
       2,     2,     1,     1,     1,     1,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     0,     5,     0,
       5,     1,     3,     2,     2,     2,     2,     2,     2,     1,
       3,     1,     1,     1,     3,     1,     1,     2,     2,     1,
       3,     4,     3,     4,     4,     2,     6,     1,     1,     3,
       5,     2,     0,     3,     0,     3,     3,     1,     3,     5,
       2,     0,     0,     4,     1,     0,     2,     3,     1,     0,
       0,     5,     1,     1,     1,     1,     1,     1,     1,     3,
       0,     4,     1,     2,     4,     1,     3,     3,     0,     0,
       0,     8,     0,     8,     1,     1,     2,     3
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
#line 74 "parser.y"
                      {;}
#line 1645 "y.tab.c"
    break;

  case 3:
#line 77 "parser.y"
             {
               (yyval.stmtval) = (yyvsp[0].stmtval);
          }
#line 1653 "y.tab.c"
    break;

  case 4:
#line 80 "parser.y"
                      {
               (yyval.stmtval).breaklist = mergelist((yyvsp[-1].stmtval).breaklist, (yyvsp[0].stmtval).breaklist); 
               (yyval.stmtval).contlist = mergelist((yyvsp[-1].stmtval).contlist, (yyvsp[0].stmtval).contlist);
          }
#line 1662 "y.tab.c"
    break;

  case 5:
#line 86 "parser.y"
                    {
               make_stmt(&(yyval.stmtval));
               resettemp();
               if ((yyvsp[-1].exprval)->type == 5) {
                    patchboolean((yyvsp[-1].exprval), yylineno);
               }
          }
#line 1674 "y.tab.c"
    break;

  case 6:
#line 93 "parser.y"
                   { make_stmt(&(yyval.stmtval));}
#line 1680 "y.tab.c"
    break;

  case 7:
#line 94 "parser.y"
                      { make_stmt(&(yyval.stmtval));}
#line 1686 "y.tab.c"
    break;

  case 8:
#line 95 "parser.y"
                    { make_stmt(&(yyval.stmtval));}
#line 1692 "y.tab.c"
    break;

  case 9:
#line 96 "parser.y"
                       { make_stmt(&(yyval.stmtval));}
#line 1698 "y.tab.c"
    break;

  case 10:
#line 97 "parser.y"
                       {
               make_stmt(&(yyval.stmtval));
               (yyval.stmtval).breaklist = (yyvsp[-1].stmtval).breaklist;
               (yyval.stmtval).contlist = (yyvsp[-1].stmtval).contlist;
               if (gloop == 0) Error(3, yytext, yylineno);
          }
#line 1709 "y.tab.c"
    break;

  case 11:
#line 103 "parser.y"
                          {
               make_stmt(&(yyval.stmtval));
               (yyval.stmtval).breaklist = (yyvsp[-1].stmtval).breaklist;
               (yyval.stmtval).contlist = (yyvsp[-1].stmtval).contlist;
               if (gloop == 0) Error(4, yytext, yylineno);
          }
#line 1720 "y.tab.c"
    break;

  case 12:
#line 109 "parser.y"
                  { (yyval.stmtval) = (yyvsp[0].stmtval);}
#line 1726 "y.tab.c"
    break;

  case 13:
#line 110 "parser.y"
                    { make_stmt(&(yyval.stmtval));}
#line 1732 "y.tab.c"
    break;

  case 14:
#line 111 "parser.y"
                 { make_stmt(&(yyval.stmtval));}
#line 1738 "y.tab.c"
    break;

  case 15:
#line 116 "parser.y"
                   { (yyval.exprval) = (yyvsp[0].exprval); }
#line 1744 "y.tab.c"
    break;

  case 16:
#line 117 "parser.y"
                           {
               (yyval.exprval) = newexpr(arithexpr_e);
               (yyval.exprval)->sym = newtemp();
               emit(op_add, (yyvsp[-2].exprval), (yyvsp[0].exprval), (yyval.exprval), nextquad() + 1, yylineno);
          }
#line 1754 "y.tab.c"
    break;

  case 17:
#line 122 "parser.y"
                            {
               (yyval.exprval) = newexpr(arithexpr_e);
               (yyval.exprval)->sym = newtemp();
               emit(op_sub, (yyvsp[-2].exprval), (yyvsp[0].exprval), (yyval.exprval), nextquad() + 1, yylineno);
          }
#line 1764 "y.tab.c"
    break;

  case 18:
#line 127 "parser.y"
                          {
               (yyval.exprval) = newexpr(arithexpr_e);
               (yyval.exprval)->sym = newtemp();
               emit(op_mul, (yyvsp[-2].exprval), (yyvsp[0].exprval), (yyval.exprval), nextquad() + 1, yylineno);
          }
#line 1774 "y.tab.c"
    break;

  case 19:
#line 132 "parser.y"
                          {
               (yyval.exprval) = newexpr(arithexpr_e);
               (yyval.exprval)->sym = newtemp();
               emit(op_div, (yyvsp[-2].exprval), (yyvsp[0].exprval), (yyval.exprval), nextquad() + 1, yylineno);
          }
#line 1784 "y.tab.c"
    break;

  case 20:
#line 137 "parser.y"
                          {
               (yyval.exprval) = newexpr(arithexpr_e);
               (yyval.exprval)->sym = newtemp();
               emit(op_mod, (yyvsp[-2].exprval), (yyvsp[0].exprval), (yyval.exprval), nextquad() + 1, yylineno);
          }
#line 1794 "y.tab.c"
    break;

  case 21:
#line 142 "parser.y"
                              {
               (yyval.exprval) = newexpr(boolexpr_e);
               (yyval.exprval)->sym = newtemp();
               (yyval.exprval)->truelist = newlist(nextquad());
               (yyval.exprval)->falselist = newlist(nextquad() + 1);
               emit(if_greater, (yyvsp[-2].exprval), (yyvsp[0].exprval), NULL, 0, yylineno);
               //emit(assign, newexpr_constbool('0'), NULL, $$, nextquad() + 1, yylineno);
               emit(jump, NULL, NULL, NULL , 0, yylineno);
               //emit(assign, newexpr_constbool('1'), NULL, $$, nextquad() + 1, yylineno);
          }
#line 1809 "y.tab.c"
    break;

  case 22:
#line 152 "parser.y"
                                 {
               (yyval.exprval) = newexpr(boolexpr_e);
               (yyval.exprval)->sym = newtemp();
               (yyval.exprval)->truelist = newlist(nextquad());
               (yyval.exprval)->falselist = newlist(nextquad()+1);
               emit(if_lesseq, (yyvsp[-2].exprval), (yyvsp[0].exprval), NULL, 0, yylineno);
               //emit(assign, newexpr_constbool('0'), NULL, $$, 69, yylineno);
               emit(jump, NULL, NULL, NULL , 0, yylineno);
               //(assign, newexpr_constbool('1'), NULL, $$, 69 ,yylineno);
          }
#line 1824 "y.tab.c"
    break;

  case 23:
#line 162 "parser.y"
                           {
               (yyval.exprval) = newexpr(boolexpr_e);
               (yyval.exprval)->sym = newtemp();
               (yyval.exprval)->truelist = newlist(nextquad());
               (yyval.exprval)->falselist = newlist(nextquad()+1);
               emit(if_less, (yyvsp[-2].exprval), (yyvsp[0].exprval), NULL, 0, yylineno);
               //emit(assign, newexpr_constbool('0'), NULL, $<exprval>$, 69,yylineno);
               emit(jump, NULL, NULL, NULL , 0, yylineno);
               //emit(assign, newexpr_constbool('1'), NULL, $<exprval>$, 69 , yylineno);
           }
#line 1839 "y.tab.c"
    break;

  case 24:
#line 172 "parser.y"
                              {
               (yyval.exprval) = newexpr(boolexpr_e);
               (yyval.exprval)->sym = newtemp();

               (yyval.exprval)->truelist = newlist(nextquad());
               (yyval.exprval)->falselist = newlist(nextquad()+1);

               emit(if_greatereq, (yyvsp[-2].exprval), (yyvsp[0].exprval), (yyval.exprval), 0, yylineno);
               //emit(assign, newexpr_constbool('0'), NULL, $<exprval>$, 69,yylineno);
               emit(jump, NULL, NULL, NULL , 0, yylineno);
               //emit(assign, newexpr_constbool('1'), NULL, $<exprval>$, 69 , yylineno);
          }
#line 1856 "y.tab.c"
    break;

  case 25:
#line 184 "parser.y"
                         {
               (yyval.exprval) = newexpr(boolexpr_e);
               (yyval.exprval)->sym = newtemp();
               (yyval.exprval)->truelist = newlist(nextquad());
               (yyval.exprval)->falselist = newlist(nextquad()+1);
               emit(if_eq, (yyvsp[-2].exprval), (yyvsp[0].exprval), (yyval.exprval), 0, yylineno);
               //emit(assign, newexpr_constbool('0'), NULL, $<exprval>$, 69,yylineno);
               emit(jump, NULL, NULL, NULL , 0, yylineno);
               //emit(assign, newexpr_constbool('1'), NULL, $<exprval>$, 69 , yylineno);
           }
#line 1871 "y.tab.c"
    break;

  case 26:
#line 194 "parser.y"
                             {
               (yyval.exprval) = newexpr(boolexpr_e);
               (yyval.exprval)->sym = newtemp();
               (yyval.exprval)->truelist = newlist(nextquad());
               (yyval.exprval)->falselist = newlist(nextquad()+1);
               emit(if_noteq, (yyvsp[-2].exprval), (yyvsp[0].exprval), NULL, 0, yylineno);
               //emit(assign, newexpr_constbool('0'), NULL, $<exprval>$, 69,yylineno);
               emit(jump, NULL, NULL, NULL , 0, yylineno);
               //emit(assign, newexpr_constbool('1'), NULL, $<exprval>$, 69 , yylineno);
           }
#line 1886 "y.tab.c"
    break;

  case 27:
#line 204 "parser.y"
                     {
               if( (yyvsp[-1].exprval) && (yyvsp[-1].exprval)->type != 5){
                    (yyvsp[-1].exprval)->truelist = newlist(nextquad());
                    (yyvsp[-1].exprval)->falselist = newlist(nextquad()+1);
                    emit(if_eq, (yyvsp[-1].exprval), newexpr_constbool(1), NULL, 0, yylineno);
                    emit(jump, NULL, NULL, NULL , 0, yylineno);
              
               }
          }
#line 1900 "y.tab.c"
    break;

  case 28:
#line 212 "parser.y"
                   {
               if((yyvsp[0].exprval) && (yyvsp[0].exprval)->type != 5){
                    (yyvsp[0].exprval)->truelist = newlist(nextquad());
                    (yyvsp[0].exprval)->falselist = newlist(nextquad()+1);
                    emit(if_eq, (yyvsp[0].exprval), newexpr_constbool(1), NULL, 0, yylineno);
                    emit(jump, NULL, NULL, NULL , 0, yylineno);
               }

              (yyval.exprval) = newexpr(boolexpr_e);
              (yyval.exprval)->sym = newtemp();
              backpatch((yyvsp[-4].exprval)->truelist, (yyvsp[-1].intval));

              (yyval.exprval)->truelist = (yyvsp[0].exprval)->truelist;
              (yyval.exprval)->falselist = mergelist((yyvsp[-4].exprval)->falselist, (yyvsp[0].exprval)->falselist);
          }
#line 1920 "y.tab.c"
    break;

  case 29:
#line 227 "parser.y"
                    {
               if((yyvsp[-1].exprval) && (yyvsp[-1].exprval)->type != 5){
                    (yyvsp[-1].exprval)->truelist = newlist(nextquad());
                    (yyvsp[-1].exprval)->falselist = newlist(nextquad()+1);
                    emit(if_eq, (yyvsp[-1].exprval), newexpr_constbool(1), NULL, 0, yylineno);
                    emit(jump, NULL, NULL, NULL , 0, yylineno);
               }
          }
#line 1933 "y.tab.c"
    break;

  case 30:
#line 234 "parser.y"
                   {
               if( (yyvsp[0].exprval) && (yyvsp[0].exprval)->type != 5){
                    (yyvsp[0].exprval)->truelist = newlist(nextquad());
                    (yyvsp[0].exprval)->falselist = newlist(nextquad()+1);
                    emit(if_eq, (yyvsp[0].exprval), newexpr_constbool(1), NULL, 0, yylineno);
                    emit(jump, NULL, NULL, NULL , 0, yylineno);
               }
               backpatch((yyvsp[-4].exprval)->falselist, (yyvsp[-1].intval));

               (yyval.exprval) = newexpr(boolexpr_e);
               (yyval.exprval)->sym = newtemp();

               (yyval.exprval)->truelist = mergelist((yyvsp[-4].exprval)->truelist, (yyvsp[0].exprval)->truelist);
               (yyval.exprval)->falselist = (yyvsp[0].exprval)->falselist;
          }
#line 1953 "y.tab.c"
    break;

  case 31:
#line 249 "parser.y"
                 {(yyval.exprval) = (yyvsp[0].exprval);}
#line 1959 "y.tab.c"
    break;

  case 32:
#line 252 "parser.y"
                         {(yyval.exprval) = (yyvsp[-1].exprval);}
#line 1965 "y.tab.c"
    break;

  case 33:
#line 253 "parser.y"
                                    {
               check_arith((yyvsp[0].exprval), (yyvsp[0].exprval)->sym->name);
               (yyval.exprval) = newexpr(arithexpr_e);
               (yyval.exprval)->sym = istempexpr((yyvsp[0].exprval)) ? (yyvsp[0].exprval)->sym : newtemp();
               emit(uminus, (yyvsp[0].exprval), NULL, (yyval.exprval), nextquad() + 1,yylineno); 
          }
#line 1976 "y.tab.c"
    break;

  case 34:
#line 259 "parser.y"
                     {
               /*if($2->type != 5){
                    $2->truelist = newlist(nextquad());
                    $2->falselist = newlist(nextquad()+1);
                    emit(if_eq, $2, newexpr_constbool(1), NULL, 0, yylineno);
                    emit(jump, NULL, NULL, NULL , 0, yylineno);
               }*/
               (yyvsp[0].exprval)->truelist = newlist(nextquad());
               (yyvsp[0].exprval)->falselist = newlist(nextquad() + 1);
               emit(if_eq, (yyvsp[0].exprval), newexpr_constbool(1), NULL, 0, yylineno);
               emit(jump, NULL, NULL, NULL , 0, yylineno);

               (yyval.exprval) = newexpr(boolexpr_e);
               (yyval.exprval)->sym = newtemp();
               (yyval.exprval)->truelist = (yyvsp[0].exprval)->falselist;
               (yyval.exprval)->falselist = (yyvsp[0].exprval)->truelist;
          }
#line 1998 "y.tab.c"
    break;

  case 35:
#line 276 "parser.y"
                          {
               if((yyvsp[0].exprval) != NULL && (yyvsp[0].exprval)->type == programfunc_e) Error(0, yytext, yylineno);
               else if((yyvsp[0].exprval) != NULL && (yyvsp[0].exprval)->type == libraryfunc_e) Error(1, yytext, yylineno);
               check_arith((yyvsp[0].exprval), (yyvsp[0].exprval)->sym->name);
               if ((yyvsp[0].exprval)->type == tableitem_e) {
                    (yyval.exprval) = emit_iftableitem((yyvsp[0].exprval));
                    emit(op_add, (yyval.exprval), newexpr_constnum(1), (yyval.exprval), nextquad() + 1,yylineno);
                    emit(tablesetelem, (yyvsp[0].exprval), (yyvsp[0].exprval)->index, (yyval.exprval), nextquad() + 1, yylineno);
               }
               else {
                    emit(op_add, (yyvsp[0].exprval), newexpr_constnum(1), (yyvsp[0].exprval), nextquad() + 1, yylineno);
                    (yyval.exprval) = newexpr(arithexpr_e);
                    (yyval.exprval)->sym = newtemp();
                    emit(assign, (yyvsp[0].exprval), NULL, (yyval.exprval), nextquad() + 1,yylineno);
               }
          }
#line 2019 "y.tab.c"
    break;

  case 36:
#line 292 "parser.y"
                          {
               if((yyvsp[-1].exprval) != NULL && (yyvsp[-1].exprval)->type == programfunc_e) Error(0, yytext, yylineno);
               else if((yyvsp[-1].exprval) != NULL && (yyvsp[-1].exprval)->type == libraryfunc_e) Error(1,yytext, yylineno);
               check_arith((yyval.exprval), (yyvsp[-1].exprval)->sym->name);
               (yyval.exprval) = newexpr(var_e);
               (yyval.exprval)->sym= newtemp();
               if ((yyvsp[-1].exprval)->type == tableitem_e){
                    Expr* value = emit_iftableitem((yyvsp[-1].exprval));
                    emit(assign, value, NULL,(yyval.exprval),0,yylineno);
                    emit(op_add, value, newexpr_constnum(1), value,0,yylineno);
                    emit( tablesetelem, (yyvsp[-1].exprval), (yyvsp[-1].exprval)->index, value, nextquad() + 1,yylineno);
               }
               else {
                    emit(assign, (yyvsp[-1].exprval), NULL , (yyval.exprval), nextquad() + 1, yylineno);
                    emit(op_add, (yyvsp[-1].exprval), newexpr_constnum(1), (yyvsp[-1].exprval), nextquad() + 1, yylineno);
               }
          }
#line 2041 "y.tab.c"
    break;

  case 37:
#line 309 "parser.y"
                           {
               if((yyvsp[0].exprval) != NULL && (yyvsp[0].exprval)->type == programfunc_e) Error(0, yytext, yylineno);
               else if((yyvsp[0].exprval) != NULL && (yyvsp[0].exprval)->type == libraryfunc_e) Error(1, yytext, yylineno);
               check_arith((yyvsp[0].exprval), (yyvsp[0].exprval)->sym->name);
               if ((yyvsp[0].exprval)->type == tableitem_e) {
                    (yyval.exprval) = emit_iftableitem((yyvsp[0].exprval));
                    emit(op_sub, (yyval.exprval), newexpr_constnum(1), (yyval.exprval), 0,yylineno);
                    emit(tablesetelem, (yyvsp[0].exprval), (yyvsp[0].exprval)->index, (yyval.exprval), nextquad() + 1, yylineno);
               }
               else {
                    emit(op_sub, (yyvsp[0].exprval), newexpr_constnum(1), (yyvsp[0].exprval), nextquad() + 1,yylineno);
                    (yyval.exprval) = newexpr(arithexpr_e);
                    (yyval.exprval)->sym = newtemp();
                    emit(assign, (yyvsp[0].exprval), NULL, (yyval.exprval), nextquad() + 1,yylineno);
               }
          }
#line 2062 "y.tab.c"
    break;

  case 38:
#line 325 "parser.y"
                           {
               if((yyvsp[-1].exprval) != NULL && (yyvsp[-1].exprval)->type == programfunc_e) {
                    Error(0, yytext, yylineno);
               }
               else if((yyvsp[-1].exprval) != NULL && (yyvsp[-1].exprval)->type == libraryfunc_e) {
                    Error(1, yytext, yylineno);
               }
               check_arith((yyval.exprval), (yyvsp[-1].exprval)->sym->name);
               (yyval.exprval) = newexpr(var_e);
               (yyval.exprval)->sym= newtemp();
               if ((yyvsp[-1].exprval)->type == tableitem_e){
                    Expr* value = emit_iftableitem((yyvsp[-1].exprval));
                    emit(assign, value, NULL,(yyval.exprval),0,yylineno);
                    emit(op_sub, value, newexpr_constnum(1), value,0,yylineno);
                    emit( tablesetelem, (yyvsp[-1].exprval), (yyvsp[-1].exprval)->index, value, nextquad() + 1,yylineno);
               }
               else {
                    emit(assign, (yyvsp[-1].exprval), NULL, (yyval.exprval), nextquad() + 1,yylineno);
                    emit(op_sub, (yyvsp[-1].exprval), newexpr_constnum(1), (yyvsp[-1].exprval), nextquad() + 1,yylineno);
               }
          }
#line 2088 "y.tab.c"
    break;

  case 39:
#line 346 "parser.y"
                    {(yyval.exprval)=(yyvsp[0].exprval);}
#line 2094 "y.tab.c"
    break;

  case 40:
#line 349 "parser.y"
                                   {
                    if((yyvsp[-2].exprval) != NULL && (yyvsp[-2].exprval)->type == programfunc_e) Error(0, yytext, yylineno);
                    else if((yyvsp[-2].exprval) != NULL && (yyvsp[-2].exprval)->type == libraryfunc_e) Error(1, yytext, yylineno);
                    if ((yyvsp[-2].exprval)->type == tableitem_e)  {
                         emit(tablesetelem, (yyvsp[0].exprval), (yyvsp[-2].exprval)->index, (yyvsp[-2].exprval), nextquad() + 1, yylineno);
                         (yyval.exprval) = emit_iftableitem ((yyvsp[-2].exprval));
                         (yyval.exprval)->type = assignexpr_e;
                    }
                    else {
                         if ( (yyvsp[0].exprval)->type == 5) {
                              patchboolean((yyvsp[0].exprval), yylineno);
                         }
                         (yyval.exprval) = newexpr(assignexpr_e);
                         (yyval.exprval)->sym = newtemp();
                         emit(assign, (yyvsp[0].exprval), (Expr*) 0, (yyval.exprval), nextquad() + 1, yylineno);
                         emit(assign, (yyval.exprval), (Expr*) 0, (yyvsp[-2].exprval), nextquad() + 1, yylineno);
                    }
               }
#line 2117 "y.tab.c"
    break;

  case 41:
#line 369 "parser.y"
                       { (yyval.exprval) = emit_iftableitem((yyvsp[0].exprval));}
#line 2123 "y.tab.c"
    break;

  case 42:
#line 370 "parser.y"
                 {;}
#line 2129 "y.tab.c"
    break;

  case 43:
#line 371 "parser.y"
                      {;}
#line 2135 "y.tab.c"
    break;

  case 44:
#line 372 "parser.y"
                                {
               (yyval.exprval) = newexpr(programfunc_e);
               (yyval.exprval)->sym = (yyvsp[-1].symval);
          }
#line 2144 "y.tab.c"
    break;

  case 45:
#line 376 "parser.y"
                  {;}
#line 2150 "y.tab.c"
    break;

  case 46:
#line 379 "parser.y"
                   {
               Symbol* item = lvalue_id(yytext, yylineno);
               (yyval.exprval) = lvalue_expr(item);
          }
#line 2159 "y.tab.c"
    break;

  case 47:
#line 383 "parser.y"
                     {
               Symbol* item = lvalue_localid(yytext, yylineno);
               if ( item && item->type == programfunc_s) {
                    fprintf(stderr, "Warning  :  %s is a function.", yytext);
               }
               (yyval.exprval) = lvalue_expr(item);
          }
#line 2171 "y.tab.c"
    break;

  case 48:
#line 390 "parser.y"
                       {
               Symbol* item = lvalue_dcolonid(yytext, yylineno);
               (yyval.exprval) = lvalue_expr(item);
          }
#line 2180 "y.tab.c"
    break;

  case 49:
#line 394 "parser.y"
                   {(yyval.exprval) = (yyvsp[0].exprval);}
#line 2186 "y.tab.c"
    break;

  case 50:
#line 397 "parser.y"
                              {(yyval.exprval) = member_item((yyvsp[-2].exprval), yytext);}
#line 2192 "y.tab.c"
    break;

  case 51:
#line 398 "parser.y"
                                    {
               (yyvsp[-3].exprval) = emit_iftableitem((yyvsp[-3].exprval));
               (yyval.exprval) = newexpr(tableitem_e);
               (yyval.exprval)->sym = (yyvsp[-3].exprval)->sym;
               (yyval.exprval)->index = (yyvsp[-1].exprval);
          }
#line 2203 "y.tab.c"
    break;

  case 52:
#line 404 "parser.y"
                        {;}
#line 2209 "y.tab.c"
    break;

  case 53:
#line 405 "parser.y"
                                  {;}
#line 2215 "y.tab.c"
    break;

  case 54:
#line 408 "parser.y"
                               { (yyval.exprval) = make_call((yyval.exprval), (yyvsp[-1].exprval));}
#line 2221 "y.tab.c"
    break;

  case 55:
#line 409 "parser.y"
                              {
               (yyvsp[-1].exprval) = emit_iftableitem((yyvsp[-1].exprval));
               if ((yyvsp[0].callval).method){
                    Expr* t = (yyvsp[-1].exprval);
                    (yyvsp[-1].exprval) = emit_iftableitem(member_item(t, (yyvsp[0].callval).name));
                    (yyvsp[0].callval).elist->next = t;
               }
               (yyval.exprval) = make_call((yyvsp[-1].exprval), (yyvsp[0].callval).elist);
          }
#line 2235 "y.tab.c"
    break;

  case 56:
#line 418 "parser.y"
                                                  {
               Expr* func = newexpr(programfunc_e);
               func->sym = (yyvsp[-4].symval);
               (yyval.exprval) = make_call(func, (yyvsp[-1].exprval));
          }
#line 2245 "y.tab.c"
    break;

  case 57:
#line 425 "parser.y"
                         { (yyval.callval) = (yyvsp[0].callval); }
#line 2251 "y.tab.c"
    break;

  case 58:
#line 426 "parser.y"
                            {(yyval.callval) = (yyvsp[0].callval);}
#line 2257 "y.tab.c"
    break;

  case 59:
#line 429 "parser.y"
                                  {
                    (yyval.callval).elist = (yyvsp[-1].exprval);
                    (yyval.callval).method = 0;
                    (yyval.callval).name = NULL;
               }
#line 2267 "y.tab.c"
    break;

  case 60:
#line 435 "parser.y"
                                       {
               (yyval.callval).elist = (yyvsp[-1].exprval);
               (yyval.callval).method = 1;
               (yyval.callval).name = (yyvsp[-3].strval);
          }
#line 2277 "y.tab.c"
    break;

  case 61:
#line 441 "parser.y"
                         {
               (yyval.exprval) = (yyvsp[-1].exprval);
               (yyval.exprval)->next = (yyvsp[0].exprval);
          }
#line 2286 "y.tab.c"
    break;

  case 62:
#line 445 "parser.y"
            {(yyval.exprval) = NULL;}
#line 2292 "y.tab.c"
    break;

  case 63:
#line 447 "parser.y"
                                      {
                    (yyval.exprval) = (yyvsp[-1].exprval);
                    (yyval.exprval)->next = (yyvsp[0].exprval);
               }
#line 2301 "y.tab.c"
    break;

  case 64:
#line 451 "parser.y"
                 {(yyval.exprval) = NULL;}
#line 2307 "y.tab.c"
    break;

  case 65:
#line 454 "parser.y"
                                  {
                    int i;
                    Expr* t = newexpr(newtable_e);
                    t->sym = newtemp();
                    emit(tablecreate, t, NULL, NULL,0,yylineno);
                    for (i = 0; (yyvsp[-1].exprval); (yyvsp[-1].exprval) = (yyvsp[-1].exprval)->next)  {
                         emit(tablesetelem, t, newexpr_constnum(i++), (yyvsp[-1].exprval), nextquad() + 1,yylineno);
                    }
                    (yyval.exprval) = t;
               }
#line 2322 "y.tab.c"
    break;

  case 66:
#line 464 "parser.y"
                                     {
                    Expr* t = newexpr(newtable_e);
                    t->sym = newtemp();
                    emit(tablecreate, t, NULL, NULL, nextquad() + 1, yylineno);
                    while ((yyvsp[-1].exprval)) {
                         emit(tablesetelem, t, (yyvsp[-1].exprval), (yyvsp[-1].exprval)->index, nextquad() + 1, yylineno);
                         (yyvsp[-1].exprval) = (yyvsp[-1].exprval)->next;
                    }
                    (yyval.exprval) = t;
               }
#line 2337 "y.tab.c"
    break;

  case 67:
#line 476 "parser.y"
                                    {;}
#line 2343 "y.tab.c"
    break;

  case 68:
#line 477 "parser.y"
                                           {;}
#line 2349 "y.tab.c"
    break;

  case 70:
#line 484 "parser.y"
                             { (yyval.stmtval) = (yyvsp[0].stmtval);}
#line 2355 "y.tab.c"
    break;

  case 71:
#line 485 "parser.y"
                 {;}
#line 2361 "y.tab.c"
    break;

  case 72:
#line 488 "parser.y"
                       { nextscope();}
#line 2367 "y.tab.c"
    break;

  case 73:
#line 488 "parser.y"
                                                       { (yyval.stmtval) = (yyvsp[-1].stmtval); hide(currscope()); exitscope();}
#line 2373 "y.tab.c"
    break;

  case 74:
#line 491 "parser.y"
                           {
                    funcname_id(yytext, yylineno);
                    (yyval.strval) = (yyvsp[0].strval);
                }
#line 2382 "y.tab.c"
    break;

  case 75:
#line 495 "parser.y"
                 {
                    Symbol* temp;
                    temp = funcname_noname(yytext, yylineno);
                    (yyval.strval) = temp->name;
               }
#line 2392 "y.tab.c"
    break;

  case 76:
#line 501 "parser.y"
                              {
                    (yyval.symval) = table_lookup((yyvsp[0].strval), currscope());
                    (yyval.symval)->iaddress = nextquad();
                    Expr* e = newexpr(programfunc_e);
                    e->sym = (yyval.symval);
                    //emit(jump, NULL, NULL, NULL, 0, yylineno);
                    emit(funcstart, e, NULL, NULL, nextquad() + 1, yylineno);
                    push(scopeoffsetstack, currscopespaceoffset());
                    enterscopespace();
                    resetformalargsoffset();
               }
#line 2408 "y.tab.c"
    break;

  case 77:
#line 514 "parser.y"
                                   {
                    enterfuncscope();
                    enterscopespace();
                    resetfunctionlocaloffset();
               }
#line 2418 "y.tab.c"
    break;

  case 78:
#line 520 "parser.y"
                      {
                    exitfuncscope();
                    (yyval.intval) = currscopespaceoffset();
                    exitscopespace();
               }
#line 2428 "y.tab.c"
    break;

  case 79:
#line 527 "parser.y"
               { push(loopcounterstack, loopcounter); loopcounter=0;}
#line 2434 "y.tab.c"
    break;

  case 80:
#line 528 "parser.y"
                { loopcounter = pop(loopcounterstack);}
#line 2440 "y.tab.c"
    break;

  case 81:
#line 530 "parser.y"
                                                                        {
               int offset;
               (yyvsp[-4].symval)->totalLocals = (yyvsp[-1].intval);
               exitscopespace();
               offset = pop_and_top(scopeoffsetstack);
               restorecurrscopeoffset(offset);
               (yyval.symval) = (yyvsp[-4].symval);

               Expr* e = newexpr(programfunc_e);
               e->sym = (yyval.symval);
               emit(funcend, e,  NULL ,  NULL, nextquad() + 1, yylineno);
               //backpatch($1->iaddress, nextquad());
          }
#line 2458 "y.tab.c"
    break;

  case 82:
#line 544 "parser.y"
            { (yyval.exprval) = newexpr_constnum((yyvsp[0].intval));}
#line 2464 "y.tab.c"
    break;

  case 83:
#line 545 "parser.y"
                 { (yyval.exprval) = newexpr_constnum((yyvsp[0].floatval));}
#line 2470 "y.tab.c"
    break;

  case 84:
#line 546 "parser.y"
                   { (yyval.exprval) = newexpr_conststring((yyvsp[0].strval));}
#line 2476 "y.tab.c"
    break;

  case 85:
#line 547 "parser.y"
                { (yyval.exprval) = newexpr(nil_e);}
#line 2482 "y.tab.c"
    break;

  case 86:
#line 548 "parser.y"
                 { (yyval.exprval) = newexpr_constbool(1);}
#line 2488 "y.tab.c"
    break;

  case 87:
#line 549 "parser.y"
                  { (yyval.exprval) = newexpr_constbool(0);}
#line 2494 "y.tab.c"
    break;

  case 88:
#line 552 "parser.y"
           { idlist_id(yytext, yylineno);}
#line 2500 "y.tab.c"
    break;

  case 89:
#line 553 "parser.y"
                            { idlist_commaid(yytext, yylineno);}
#line 2506 "y.tab.c"
    break;

  case 90:
#line 554 "parser.y"
            {;}
#line 2512 "y.tab.c"
    break;

  case 91:
#line 557 "parser.y"
                                    {
               if ((yyvsp[-1].exprval) && (yyvsp[-1].exprval)->type == 5) {
                    patchboolean((yyvsp[-1].exprval), yylineno);
               }
               emit(if_eq, (yyvsp[-1].exprval), newexpr_constbool(1), NULL, nextquad() + 2, yylineno);
               (yyval.intval) = nextquad();
               emit(jump, NULL , NULL, NULL, 0, yylineno);
          }
#line 2525 "y.tab.c"
    break;

  case 92:
#line 567 "parser.y"
                     {
                    (yyval.intval) = nextquad();
                    emit(jump, NULL, NULL, NULL, 0, yylineno);
               }
#line 2534 "y.tab.c"
    break;

  case 93:
#line 573 "parser.y"
                                     {
                    patchlabel((yyvsp[-1].intval), nextquad());
               }
#line 2542 "y.tab.c"
    break;

  case 94:
#line 576 "parser.y"
                                               {
                    patchlabel((yyvsp[-3].intval), ((yyvsp[-1].intval))+1);
                    patchlabel((yyvsp[-1].intval), nextquad());
               }
#line 2551 "y.tab.c"
    break;

  case 95:
#line 582 "parser.y"
                      {
                    gloop++;
                    (yyval.intval) = nextquad();
               }
#line 2560 "y.tab.c"
    break;

  case 96:
#line 588 "parser.y"
                                 {
                    if ( (yyvsp[-1].exprval)->type == 5) {
                         patchboolean((yyvsp[-1].exprval), yylineno);
                    }
                    emit(if_eq, (yyvsp[-1].exprval), newexpr_constbool(1), NULL, nextquad()+2, yylineno);
                    (yyval.intval) = nextquad();
                    emit(jump, NULL, NULL, NULL, 0, yylineno);
               }
#line 2573 "y.tab.c"
    break;

  case 97:
#line 597 "parser.y"
                                          {
                    gloop--;
                    emit(jump, NULL, NULL, NULL, (yyvsp[-2].intval), yylineno);
                    patchlabel((yyvsp[-1].intval), nextquad());

                    patchlist(pop(breakstack), nextquad());
                    patchlist(pop(contstack), (yyvsp[-2].intval));
               }
#line 2586 "y.tab.c"
    break;

  case 98:
#line 606 "parser.y"
        {
          (yyval.intval) = nextquad();
          emit(jump, NULL, NULL, NULL, 0, yylineno);
     }
#line 2595 "y.tab.c"
    break;

  case 99:
#line 611 "parser.y"
     {(yyval.intval) = nextquad();}
#line 2601 "y.tab.c"
    break;

  case 100:
#line 614 "parser.y"
                    {gloop++;}
#line 2607 "y.tab.c"
    break;

  case 101:
#line 614 "parser.y"
                                                             {
                    if ( (yyvsp[-1].exprval)->type == 5) {
                         patchboolean((yyvsp[-1].exprval), yylineno);
                    }
                    (yyval.prefval).test = (yyvsp[-2].intval);
                    (yyval.prefval).enter = nextquad();
                    emit(if_eq, (yyvsp[-1].exprval), newexpr_constbool(1), NULL, 0, yylineno);
               }
#line 2620 "y.tab.c"
    break;

  case 102:
#line 624 "parser.y"
                                               {gloop--;}
#line 2626 "y.tab.c"
    break;

  case 103:
#line 624 "parser.y"
                                                             {
               patchlabel((yyvsp[-7].prefval).enter, (yyvsp[-3].intval)+1);
               patchlabel((yyvsp[-6].intval), nextquad());
               patchlabel((yyvsp[-3].intval), (yyvsp[-7].prefval).test);
               patchlabel((yyvsp[0].intval), (yyvsp[-6].intval)+1);

               patchlist(pop(breakstack), nextquad());
               patchlist(pop(contstack), (yyvsp[-6].intval)+1);
          }
#line 2640 "y.tab.c"
    break;

  case 104:
#line 635 "parser.y"
                {
               make_stmt(&(yyval.stmtval));
               (yyval.stmtval).breaklist = newlist(nextquad());
               emit(jump, NULL, NULL, NULL, 0, yylineno);
               breakstack = push(breakstack, (yyval.stmtval).breaklist);
          }
#line 2651 "y.tab.c"
    break;

  case 105:
#line 643 "parser.y"
                   {
               make_stmt(&(yyval.stmtval));
               (yyval.stmtval).contlist = newlist(nextquad());
               emit(jump, NULL, NULL, NULL, 0, yylineno);
               contstack = push(contstack, (yyval.stmtval).contlist);
          }
#line 2662 "y.tab.c"
    break;

  case 106:
#line 652 "parser.y"
                            {
                    if (currfuncscope() == 0) Error(2, yytext, yylineno);
                    else {
                         emit(ret, NULL, NULL, NULL, nextquad() + 1, yylineno);
                    }
               }
#line 2673 "y.tab.c"
    break;

  case 107:
#line 658 "parser.y"
                                  {
                    if (currfuncscope() == 0) Error(2, yytext, yylineno);
                    emit(ret, NULL, NULL, (yyvsp[-1].exprval), nextquad() + 1, yylineno);
               }
#line 2682 "y.tab.c"
    break;


#line 2686 "y.tab.c"

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
#line 664 "parser.y"


void yyerror(char* yaccProovidedMessage) {
       fprintf(stderr, "%s: at line %d, before token: %s\n",yaccProovidedMessage, yylineno, yytext);
       fprintf(stderr, "INPUT NOT VALID\n");
}

int main(int argc, char** argv) {
     symtable = create_new_symtable();
     init_quad();
     table_insert(libraryfunc_s, "print", currscopespace(), currscopespaceoffset(), currscope(), currfuncscope(), 0);
     table_insert(libraryfunc_s, "input", currscopespace(), currscopespaceoffset(), currscope(), currfuncscope(), 0);
     table_insert(libraryfunc_s, "objectmemberkyes", currscopespace(), currscopespaceoffset(), currscope(), currfuncscope(), 0);
     table_insert(libraryfunc_s, "objectotslmembers", currscopespace(), currscopespaceoffset(), currscope(), currfuncscope(), 0);
     table_insert(libraryfunc_s, "objectcopy", currscopespace(), currscopespaceoffset(), currscope(), currfuncscope(), 0);
     table_insert(libraryfunc_s, "totalarguments", currscopespace(), currscopespaceoffset(), currscope(), currfuncscope(), 0);
     table_insert(libraryfunc_s, "argument", currscopespace(), currscopespaceoffset(), currscope(), currfuncscope(), 0);
     table_insert(libraryfunc_s, "typeof", currscopespace(), currscopespaceoffset(), currscope(), currfuncscope(), 0);
     table_insert(libraryfunc_s, "strtonum", currscopespace(), currscopespaceoffset(), currscope(), currfuncscope(), 0);
     table_insert(libraryfunc_s, "sqrt", currscopespace(), currscopespaceoffset(), currscope(), currfuncscope(), 0);
     table_insert(libraryfunc_s, "cos", currscopespace(), currscopespaceoffset(), currscope(), currfuncscope(), 0);
     table_insert(libraryfunc_s, "sin", currscopespace(), currscopespaceoffset(), currscope(), currfuncscope(), 0);
     if(argc > 1){
          if(!(yyin = fopen(argv[1], "r"))){
               fprintf(stderr, "Cannot read  file: %s\n", argv[1]);
               return 1;
          }
     } else {
          yyin = stdin;
     }
     yyparse();
     //print_table();
     print_intermediate();
     free_table(symtable);
     return 0;
}
