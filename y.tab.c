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

     #define  YY_DECL int alpha_yylex (void* yylval)
     void yyerror (char* yaccProovidedMessage);
     int yylex();
     extern int yylineno;
     extern char* yytext;
     extern FILE* yyin;
     unsigned gloop = 0;
     unsigned loopcounter = 0;

#line 87 "y.tab.c"

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
#line 20 "parser.y"

     int intval;
     char* strval;
     float floatval;
     struct expr* exprval;
     struct stmt_t stmtval;
     struct call callval;
     struct symbol symval;
     struct prefix prefval;

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
#define YYFINAL  70
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   586

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  49
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  48
/* YYNRULES -- Number of rules.  */
#define YYNRULES  107
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  194

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
       0,    68,    68,    69,    78,    89,    90,    91,    92,    93,
      99,   105,   106,   107,   110,   111,   116,   121,   126,   131,
     136,   146,   156,   166,   178,   188,   198,   212,   225,   228,
     229,   236,   241,   257,   274,   290,   311,   314,   342,   343,
     344,   345,   349,   352,   356,   363,   367,   370,   371,   377,
     378,   381,   382,   391,   398,   399,   402,   408,   414,   418,
     420,   424,   427,   437,   449,   450,   453,   457,   458,   461,
     461,   464,   468,   473,   484,   490,   497,   498,   500,   510,
     511,   512,   513,   514,   515,   518,   519,   520,   523,   530,
     536,   539,   545,   551,   559,   567,   568,   570,   572,   577,
     580,   580,   587,   587,   598,   600,   603,   609
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
  "methodcall", "elist", "comma_elist", "objectdef", "indexed",
  "indexedelem", "rec_stmt", "block", "$@1", "funcname", "funcprefix",
  "funcargs", "funcbody", "funcblockstart", "funcblockend", "funcdef",
  "const", "idlist", "ifprefix", "elseprefix", "ifstmt", "whilestart",
  "whilecond", "whilestmt", "loopstart", "loopend", "loopstmt", "N", "M",
  "forprefix", "$@2", "forstmt", "$@3", "break", "continue", "returnstmt", YY_NULLPTR
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
     290,   380,   -10,   -10,   380,    -7,   322,  -165,  -165,  -165,
    -165,   -17,  -165,  -165,   -12,   348,  -165,  -165,    28,  -165,
    -165,  -165,  -165,  -165,    30,    70,   290,   181,  -165,  -165,
    -165,    21,  -165,    77,  -165,  -165,     5,  -165,  -165,   290,
    -165,    47,  -165,  -165,  -165,    39,    43,  -165,  -165,    54,
      33,    77,    33,  -165,   380,   161,    68,   -18,  -165,   425,
      69,   380,    74,  -165,  -165,  -165,   204,  -165,  -165,  -165,
    -165,  -165,  -165,  -165,   380,   380,   380,   380,   380,   380,
     380,   380,   380,   380,   380,  -165,   380,  -165,  -165,    65,
      75,   380,   380,  -165,  -165,  -165,    78,   380,   380,    83,
    -165,    82,   380,   290,   380,  -165,  -165,    80,   117,   380,
    -165,  -165,  -165,    72,  -165,    92,   448,   380,  -165,   258,
     380,   380,   559,   559,    53,    53,    53,    53,    95,    95,
    -165,  -165,  -165,   536,  -165,    93,   494,   108,  -165,   515,
     109,  -165,     1,    94,  -165,   290,   471,  -165,   110,    92,
     380,   161,  -165,   380,  -165,    96,  -165,  -165,   548,   570,
     380,  -165,  -165,  -165,  -165,  -165,   111,  -165,  -165,  -165,
    -165,   290,  -165,  -165,   246,  -165,   112,  -165,   116,  -165,
    -165,  -165,   290,  -165,  -165,   380,  -165,  -165,  -165,   223,
    -165,  -165,  -165,  -165
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       3,     0,     0,     0,     0,    59,     0,    79,    80,    43,
      81,     0,    92,   100,    72,     0,   104,   105,     0,    83,
      84,    82,    69,    13,     0,     0,     3,     0,    28,    14,
      36,    38,    46,    39,    40,    11,     0,    12,    42,     0,
       5,     0,     6,    98,     7,     0,     0,     8,    31,     0,
      32,     0,    34,    30,     0,    61,     0,     0,    64,     0,
       0,     0,     0,    71,    73,   106,     0,    44,    68,    45,
       1,     2,    99,    99,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     4,     0,    33,    35,     0,
       0,     0,    59,    52,    54,    55,     0,     0,    59,    87,
      76,    90,     0,     0,    59,     9,    10,     0,     0,     0,
      58,    62,    63,     0,    29,    41,     0,    59,   107,     0,
       0,     0,    24,    25,    20,    21,    22,    23,    15,    16,
      17,    18,    19,    37,    47,     0,     0,     0,    49,     0,
       0,    85,     0,     0,    89,     0,     0,    95,     0,     0,
       0,    61,    65,    59,    88,     0,    70,    67,    27,    26,
      59,    48,    56,    50,    51,    74,     0,    75,    77,    91,
      93,     0,    94,    98,     0,    60,     0,    99,     0,    86,
      78,    96,     0,    66,    53,     0,    57,    97,   102,     0,
      98,   101,    95,   103
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -165,   118,   -32,    -1,  -165,  -165,  -165,    46,  -165,    49,
    -165,  -165,  -165,   -67,    -8,  -165,  -165,    32,  -165,     3,
    -165,  -165,  -165,  -165,  -165,  -165,  -165,    -4,  -165,  -165,
    -165,  -165,  -165,  -165,  -165,  -165,  -165,  -165,   -45,  -164,
     -72,  -165,  -165,  -165,  -165,  -165,  -165,  -165
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      93,    94,    95,    56,   110,    34,    57,    58,   119,    35,
      68,    64,    36,   100,   168,   143,   180,    37,    38,   142,
      39,   145,    40,    41,   103,    42,   171,   187,   172,   104,
     120,    43,    62,    44,   190,    45,    46,    47
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      48,   121,    60,    53,    55,    59,   112,   101,    61,   182,
       1,     2,     3,     4,    66,    49,     5,    63,     6,     9,
       7,     8,     9,    10,    86,   137,   192,   165,   113,    18,
      99,   140,    18,    19,    20,    21,    54,   148,    24,    87,
      88,    24,    89,    90,    91,   107,    92,   166,    50,    52,
     155,    51,    51,   108,    89,    90,    91,    67,    92,    69,
     116,    -1,    -1,    -1,    -1,    80,    81,    82,    83,    84,
      70,   147,   102,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   105,   133,   176,   157,   106,    14,
     136,    55,   111,   178,   134,   115,   139,    55,    96,   117,
      97,   146,    98,    55,   135,   185,   149,   138,   151,    82,
      83,    84,   141,   169,   144,    54,    55,   153,   160,   158,
     159,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,   162,   164,   173,    22,   184,   181,
     179,   177,   186,   175,    71,   152,   167,   193,     0,   174,
     188,     0,    55,     0,     0,     0,     0,     0,     0,    55,
       0,     0,     0,     0,   150,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,     0,     0,
       0,     0,     0,     0,   189,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   109,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,     0,     0,     0,     0,     0,    85,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   118,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,     0,     0,     0,     0,     0,   191,     0,
       0,     0,     0,     0,     0,     1,     2,     3,     4,     0,
       0,     5,     0,     6,     0,     7,     8,     9,    10,    11,
     183,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,   156,    23,     0,     0,    24,     1,     2,     3,
       4,     0,     0,     5,     0,     6,     0,     7,     8,     9,
      10,    11,     0,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,     0,    23,     0,     0,    24,     1,
       2,     3,     4,     0,     0,     5,     0,     6,     0,     7,
       8,     9,    10,     0,     0,     0,     0,    14,     0,     0,
       0,    18,    19,    20,    21,     1,     2,     3,     4,     0,
      24,     5,     0,     6,     0,     7,     8,     9,    10,     0,
       0,     0,     0,     0,     0,     0,     0,    18,    19,    20,
      21,     0,     0,    65,     0,     0,    24,     1,     2,     3,
       4,     0,     0,     5,     0,     6,     0,     7,     8,     9,
      10,     0,     0,     0,     0,     0,     0,     0,     0,    18,
      19,    20,    21,     0,     0,     0,     0,     0,    24,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   114,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   154,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   170,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,     0,     0,     0,     0,     0,     0,     0,   161,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,     0,     0,     0,     0,     0,     0,     0,   163,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    -1,    -1,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84
};

static const yytype_int16 yycheck[] =
{
       1,    73,     6,     4,     5,     6,    24,    39,    25,   173,
      17,    18,    19,    20,    15,    25,    23,    29,    25,    29,
      27,    28,    29,    30,     3,    92,   190,    26,    46,    39,
      25,    98,    39,    40,    41,    42,    43,   104,    48,    18,
      19,    48,    21,    22,    23,    49,    25,    46,     2,     3,
     117,     2,     3,    54,    21,    22,    23,    29,    25,    29,
      61,     8,     9,    10,    11,    12,    13,    14,    15,    16,
       0,   103,    25,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    45,    86,   153,   119,    45,    35,
      91,    92,    24,   160,    29,    26,    97,    98,    21,    25,
      23,   102,    25,   104,    29,   177,    26,    29,   109,    14,
      15,    16,    29,   145,    32,    43,   117,    25,    25,   120,
     121,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    26,    26,    26,    43,    26,   171,
      29,    45,    26,   151,    26,   113,   143,   192,    -1,   150,
     182,    -1,   153,    -1,    -1,    -1,    -1,    -1,    -1,   160,
      -1,    -1,    -1,    -1,    47,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    -1,    -1,
      -1,    -1,    -1,    -1,   185,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    46,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    -1,    -1,    -1,    -1,    -1,    45,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    45,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    -1,    -1,    -1,    -1,    -1,    45,    -1,
      -1,    -1,    -1,    -1,    -1,    17,    18,    19,    20,    -1,
      -1,    23,    -1,    25,    -1,    27,    28,    29,    30,    31,
      44,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    -1,    -1,    48,    17,    18,    19,
      20,    -1,    -1,    23,    -1,    25,    -1,    27,    28,    29,
      30,    31,    -1,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    -1,    45,    -1,    -1,    48,    17,
      18,    19,    20,    -1,    -1,    23,    -1,    25,    -1,    27,
      28,    29,    30,    -1,    -1,    -1,    -1,    35,    -1,    -1,
      -1,    39,    40,    41,    42,    17,    18,    19,    20,    -1,
      48,    23,    -1,    25,    -1,    27,    28,    29,    30,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    39,    40,    41,
      42,    -1,    -1,    45,    -1,    -1,    48,    17,    18,    19,
      20,    -1,    -1,    23,    -1,    25,    -1,    27,    28,    29,
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
      14,    15,    16,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    17,    18,    19,    20,    23,    25,    27,    28,    29,
      30,    31,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    45,    48,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    64,    68,    71,    76,    77,    79,
      81,    82,    84,    90,    92,    94,    95,    96,    52,    25,
      56,    58,    56,    52,    43,    52,    62,    65,    66,    52,
      76,    25,    91,    29,    70,    45,    52,    29,    69,    29,
       0,    50,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    45,     3,    18,    19,    21,
      22,    23,    25,    59,    60,    61,    21,    23,    25,    25,
      72,    51,    25,    83,    88,    45,    45,    76,    52,    46,
      63,    24,    24,    46,    26,    26,    52,    25,    45,    67,
      89,    89,    52,    52,    52,    52,    52,    52,    52,    52,
      52,    52,    52,    52,    29,    29,    52,    62,    29,    52,
      62,    29,    78,    74,    32,    80,    52,    51,    62,    26,
      47,    52,    66,    25,    26,    62,    44,    51,    52,    52,
      25,    24,    26,    24,    26,    26,    46,    68,    73,    51,
      26,    85,    87,    26,    52,    63,    62,    45,    62,    29,
      75,    51,    88,    44,    26,    89,    26,    86,    51,    52,
      93,    45,    88,    87
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
      63,    63,    64,    64,    65,    65,    66,    67,    67,    69,
      68,    70,    70,    71,    72,    73,    74,    75,    76,    77,
      77,    77,    77,    77,    77,    78,    78,    78,    79,    80,
      81,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      91,    90,    93,    92,    94,    95,    96,    96
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     0,     2,     1,     1,     1,     1,     2,
       2,     1,     1,     1,     1,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     4,     4,     1,     3,
       2,     2,     2,     2,     2,     2,     1,     3,     1,     1,
       1,     3,     1,     1,     2,     2,     1,     3,     4,     3,
       4,     4,     2,     6,     1,     1,     3,     5,     2,     0,
       3,     0,     3,     3,     1,     3,     5,     2,     0,     0,
       4,     1,     0,     2,     3,     1,     0,     0,     5,     1,
       1,     1,     1,     1,     1,     1,     3,     0,     4,     1,
       2,     4,     1,     3,     4,     0,     0,     3,     0,     0,
       0,     8,     0,     9,     1,     1,     2,     3
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
#line 68 "parser.y"
                             {;}
#line 1640 "y.tab.c"
    break;

  case 3:
#line 69 "parser.y"
            {;}
#line 1646 "y.tab.c"
    break;

  case 4:
#line 78 "parser.y"
                    {
               resettemp();
               if ((yyvsp[-1].exprval)->type == 5) {
                    printf("HEY%s\n", (yyvsp[-1].exprval)->sym->name);
                    emit(assign, newexpr_constbool(1), NULL, (yyval.stmtval), nextquad(), yylineno);
                    emit(jump, NULL, NULL, NULL, nextquad() + 2, yylineno);
                    emit(assign, newexpr_constbool(0), NULL, (yyval.stmtval), nextquad(), yylineno);
                    backpatch((yyvsp[-1].exprval)->truelist, nextquad() - 3);
                    backpatch((yyvsp[-1].exprval)->falselist, nextquad() - 1);
               }
          }
#line 1662 "y.tab.c"
    break;

  case 6:
#line 90 "parser.y"
                      {;}
#line 1668 "y.tab.c"
    break;

  case 7:
#line 91 "parser.y"
                    {;}
#line 1674 "y.tab.c"
    break;

  case 8:
#line 92 "parser.y"
                       {;}
#line 1680 "y.tab.c"
    break;

  case 9:
#line 93 "parser.y"
                       {
               make_stmt(&(yyvsp[-1].stmtval));
               (yyval.stmtval).breaklist = newlist(nextquad());
               emit(jump, NULL, NULL, NULL, 0, yylineno);
               if (gloop == 0) Error(3, yytext, yylineno);
          }
#line 1691 "y.tab.c"
    break;

  case 10:
#line 99 "parser.y"
                          {
               make_stmt(&(yyvsp[-1].stmtval));
               (yyval.stmtval).contlist = newlist(nextquad());
               emit(jump, NULL, NULL, NULL, 0, yylineno);
               if (gloop == 0) Error(4, yytext, yylineno);
          }
#line 1702 "y.tab.c"
    break;

  case 11:
#line 105 "parser.y"
                  {;}
#line 1708 "y.tab.c"
    break;

  case 12:
#line 106 "parser.y"
                    {;}
#line 1714 "y.tab.c"
    break;

  case 13:
#line 107 "parser.y"
                 {;}
#line 1720 "y.tab.c"
    break;

  case 14:
#line 110 "parser.y"
                   { (yyval.exprval) = (yyvsp[0].exprval); }
#line 1726 "y.tab.c"
    break;

  case 15:
#line 111 "parser.y"
                           {
               (yyval.exprval) = newexpr(arithexpr_e);
               (yyval.exprval)->sym = newtemp();
               emit(op_add, (yyvsp[-2].exprval), (yyvsp[0].exprval), (yyval.exprval), nextquad() + 1, yylineno);
          }
#line 1736 "y.tab.c"
    break;

  case 16:
#line 116 "parser.y"
                            {
               (yyval.exprval) = newexpr(arithexpr_e);
               (yyval.exprval)->sym = newtemp();
               emit(op_sub, (yyvsp[-2].exprval), (yyvsp[0].exprval), (yyval.exprval), nextquad() + 1, yylineno);
          }
#line 1746 "y.tab.c"
    break;

  case 17:
#line 121 "parser.y"
                          {
               (yyval.exprval) = newexpr(arithexpr_e);
               (yyval.exprval)->sym = newtemp();
               emit(op_mul, (yyvsp[-2].exprval), (yyvsp[0].exprval), (yyval.exprval), nextquad() + 1, yylineno);
          }
#line 1756 "y.tab.c"
    break;

  case 18:
#line 126 "parser.y"
                          {
               (yyval.exprval) = newexpr(arithexpr_e);
               (yyval.exprval)->sym = newtemp();
               emit(op_div, (yyvsp[-2].exprval), (yyvsp[0].exprval), (yyval.exprval), nextquad() + 1, yylineno);
          }
#line 1766 "y.tab.c"
    break;

  case 19:
#line 131 "parser.y"
                          {
               (yyval.exprval) = newexpr(arithexpr_e);
               (yyval.exprval)->sym = newtemp();
               emit(op_mod, (yyvsp[-2].exprval), (yyvsp[0].exprval), (yyval.exprval), nextquad() + 1, yylineno);
          }
#line 1776 "y.tab.c"
    break;

  case 20:
#line 136 "parser.y"
                              {
               (yyval.exprval) = newexpr(boolexpr_e);
               (yyval.exprval)->sym = newtemp();
               (yyval.exprval)->truelist = newlist(nextquad());
               (yyval.exprval)->falselist = newlist(nextquad() + 1);
               emit(if_less, (yyvsp[-2].exprval), (yyvsp[0].exprval), (yyval.exprval), 0, yylineno);
               //emit(assign, newexpr_constbool('0'), NULL, $$, nextquad() + 1, yylineno);
               emit(jump, NULL, NULL, NULL , 0, yylineno);
               //emit(assign, newexpr_constbool('1'), NULL, $$, nextquad() + 1, yylineno);
          }
#line 1791 "y.tab.c"
    break;

  case 21:
#line 146 "parser.y"
                                 {
               (yyval.exprval) = newexpr(boolexpr_e);
               (yyval.exprval)->sym = newtemp();
               (yyval.exprval)->truelist = newlist(nextquad());
               (yyval.exprval)->falselist = newlist(nextquad()+1);
               emit(if_lesseq, (yyvsp[-2].exprval), (yyvsp[0].exprval), (yyval.exprval), 0, yylineno);
               //emit(assign, newexpr_constbool('0'), NULL, $$, 69, yylineno);
               emit(jump, NULL, NULL, NULL , 0, yylineno);
               //(assign, newexpr_constbool('1'), NULL, $$, 69 ,yylineno);
          }
#line 1806 "y.tab.c"
    break;

  case 22:
#line 156 "parser.y"
                           {
               (yyval.exprval) = newexpr(boolexpr_e);
               (yyval.exprval)->sym = newtemp();
               (yyval.exprval)->truelist = newlist(nextquad());
               (yyval.exprval)->falselist = newlist(nextquad()+1);
               emit(if_less, (yyvsp[-2].exprval), (yyvsp[0].exprval), (yyval.exprval), 0, yylineno);
               //emit(assign, newexpr_constbool('0'), NULL, $<exprval>$, 69,yylineno);
               emit(jump, NULL, NULL, NULL , 0, yylineno);
               //emit(assign, newexpr_constbool('1'), NULL, $<exprval>$, 69 , yylineno);
           }
#line 1821 "y.tab.c"
    break;

  case 23:
#line 166 "parser.y"
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
#line 1838 "y.tab.c"
    break;

  case 24:
#line 178 "parser.y"
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
#line 1853 "y.tab.c"
    break;

  case 25:
#line 188 "parser.y"
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
#line 1868 "y.tab.c"
    break;

  case 26:
#line 198 "parser.y"
                            {
               backpatch((yyvsp[-3].exprval)->truelist, (yyvsp[-1].intval));

               (yyval.exprval) = newexpr(boolexpr_e);
               (yyval.exprval)->sym = newtemp();


               (yyval.exprval)->truelist = (yyvsp[0].exprval)->truelist;
               (yyval.exprval)->falselist = mergelist((yyvsp[-3].exprval)->falselist, (yyvsp[0].exprval)->falselist);

               /*emit(assign, newexpr_constbool(1), NULL, $$, nextquad(), yylineno);
               emit(jump, NULL, NULL, NULL, nextquad() + 1, yylineno);
               emit(assign, newexpr_constbool(0), NULL, $$, nextquad() + 1, yylineno);*/
          }
#line 1887 "y.tab.c"
    break;

  case 27:
#line 212 "parser.y"
                           {
               backpatch((yyvsp[-3].exprval)->falselist, (yyvsp[-1].intval));

               (yyval.exprval) = newexpr(boolexpr_e);
               (yyval.exprval)->sym = newtemp();

               (yyval.exprval)->truelist = mergelist((yyvsp[-3].exprval)->truelist, (yyvsp[0].exprval)->truelist);
               (yyval.exprval)->falselist = (yyvsp[0].exprval)->falselist;

               /*emit(assign, newexpr_constbool(1), NULL, $$, nextquad() + 1, yylineno);
               emit(jump, NULL, NULL, NULL, nextquad() + 2, yylineno);
               emit(assign, newexpr_constbool(0), NULL, $$, nextquad() + 1, yylineno);*/
          }
#line 1905 "y.tab.c"
    break;

  case 28:
#line 225 "parser.y"
                 {(yyval.exprval) = (yyvsp[0].exprval);}
#line 1911 "y.tab.c"
    break;

  case 29:
#line 228 "parser.y"
                         {(yyval.exprval) = (yyvsp[-1].exprval);}
#line 1917 "y.tab.c"
    break;

  case 30:
#line 229 "parser.y"
                                     {
               (yyval.exprval)->truelist = (yyvsp[0].exprval)->falselist;
               (yyval.exprval)->falselist = (yyvsp[0].exprval)->truelist;
               check_arith((yyvsp[0].exprval), (yyvsp[0].exprval)->sym->name);
               (yyval.exprval) = newexpr(arithexpr_e);
               (yyval.exprval)->sym = istempexpr((yyvsp[0].exprval)) ? (yyvsp[0].exprval)->sym : newtemp();
               emit(uminus, (yyvsp[0].exprval), (yyval.exprval), NULL, nextquad() + 1,yylineno); }
#line 1929 "y.tab.c"
    break;

  case 31:
#line 236 "parser.y"
                     {
               (yyval.exprval) = newexpr(boolexpr_e);
               (yyval.exprval)->sym = newtemp();
               emit(op_not, (yyvsp[0].exprval), (yyval.exprval), NULL, 0, yylineno);
          }
#line 1939 "y.tab.c"
    break;

  case 32:
#line 241 "parser.y"
                          {
               if((yyvsp[0].exprval) != NULL && (yyvsp[0].exprval)->type == programfunc_e) Error(0, yytext, yylineno);
               else if((yyvsp[0].exprval) != NULL && (yyvsp[0].exprval)->type == libraryfunc_e) Error(1, yytext, yylineno);
               check_arith((yyvsp[0].exprval), (yyvsp[0].exprval)->sym->name);
               if ((yyvsp[0].exprval)->type == tableitem_e) {
                    (yyval.exprval) = emit_iftableitem((yyvsp[0].exprval));
                    emit(op_add, (yyval.exprval), newexpr_constnum(1), (yyval.exprval),0,yylineno);
                    emit(tablesetelem, (yyvsp[0].exprval), (yyvsp[0].exprval)->index, (yyval.exprval));
               }
               else {
                    emit(op_add, (yyvsp[0].exprval), newexpr_constnum(1), (yyvsp[0].exprval),0,yylineno);
                    (yyval.exprval) = newexpr(arithexpr_e);
                    (yyval.exprval)->sym = newtemp();
                    emit(assign, (yyvsp[0].exprval), NULL, (yyval.exprval),0,yylineno);
               }
          }
#line 1960 "y.tab.c"
    break;

  case 33:
#line 257 "parser.y"
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
                    emit( tablesetelem, (yyvsp[-1].exprval), (yyvsp[-1].exprval)->index, value,0,yylineno);
               }
               else {
                    emit(assign, (yyvsp[-1].exprval), NULL , (yyval.exprval), 0, yylineno);
                    emit(op_add, (yyvsp[-1].exprval), newexpr_constnum(1), (yyvsp[-1].exprval), 0, yylineno);
               }
          }
#line 1982 "y.tab.c"
    break;

  case 34:
#line 274 "parser.y"
                           {
               if((yyvsp[0].exprval) != NULL && (yyvsp[0].exprval)->type == programfunc_e) Error(0, yytext, yylineno);
               else if((yyvsp[0].exprval) != NULL && (yyvsp[0].exprval)->type == libraryfunc_e) Error(1, yytext, yylineno);
               check_arith((yyvsp[0].exprval), (yyvsp[0].exprval)->sym->name);
               if ((yyvsp[0].exprval)->type == tableitem_e) {
                    (yyval.exprval) = emit_iftableitem((yyvsp[0].exprval));
                    emit(op_sub, (yyval.exprval), newexpr_constnum(1), (yyval.exprval), nextquad() + 1,yylineno);
                    emit(tablesetelem, (yyvsp[0].exprval), (yyvsp[0].exprval)->index, (yyval.exprval));
               }
               else {
                    emit(op_sub, (yyvsp[0].exprval), newexpr_constnum(1), (yyvsp[0].exprval),0,yylineno);
                    (yyval.exprval) = newexpr(arithexpr_e);
                    (yyval.exprval)->sym = newtemp();
                    emit(assign, (yyvsp[0].exprval), NULL, (yyval.exprval),0,yylineno);
               }
          }
#line 2003 "y.tab.c"
    break;

  case 35:
#line 290 "parser.y"
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
                    emit( tablesetelem, (yyvsp[-1].exprval), (yyvsp[-1].exprval)->index, value,0,yylineno);
               }
               else {
                    emit(assign, (yyvsp[-1].exprval), NULL, (yyval.exprval), nextquad() + 1,yylineno);
                    emit(op_sub, (yyvsp[-1].exprval), newexpr_constnum(1), (yyvsp[-1].exprval), nextquad() + 1,yylineno);
               }
          }
#line 2029 "y.tab.c"
    break;

  case 36:
#line 311 "parser.y"
                    {(yyval.exprval)=(yyvsp[0].exprval);}
#line 2035 "y.tab.c"
    break;

  case 37:
#line 314 "parser.y"
                                   {
                    if((yyvsp[-2].exprval) != NULL && (yyvsp[-2].exprval)->type == programfunc_e) Error(0, yytext, yylineno);
                    else if((yyvsp[-2].exprval) != NULL && (yyvsp[-2].exprval)->type == libraryfunc_e) Error(1, yytext, yylineno);
                    if ((yyvsp[-2].exprval)->type == tableitem_e)  {
                         emit(tablesetelem, (yyvsp[-2].exprval), (yyvsp[-2].exprval)->index, (yyvsp[0].exprval), nextquad() + 1, yylineno);
                         (yyval.exprval) = emit_iftableitem ((yyvsp[-2].exprval));
                         (yyval.exprval)->type = assignexpr_e;
                    }
                    else {
                         if ( (yyvsp[0].exprval)->type == 5) {
                              (yyval.exprval) = newexpr(boolexpr_e);
                              (yyval.exprval)->sym = newtemp();

                              backpatch((yyvsp[0].exprval)->truelist, nextquad());
                              backpatch((yyvsp[0].exprval)->falselist, nextquad() + 2);

                              emit(assign, newexpr_constbool(1), (Expr*) 0, (yyvsp[0].exprval), nextquad() + 1, yylineno);
                              emit(jump, NULL, NULL, NULL, nextquad() + 2, yylineno);
                              emit(assign, newexpr_constbool(0), (Expr*) 0, (yyvsp[0].exprval), nextquad() + 1, yylineno);
                         }
                         (yyval.exprval) = newexpr(assignexpr_e);
                         (yyval.exprval)->sym = newtemp();
                         emit(assign, (yyvsp[0].exprval), (Expr*) 0, (yyval.exprval), nextquad() + 1, yylineno);
                         emit(assign, (yyval.exprval), (Expr*) 0, (yyvsp[-2].exprval), nextquad() + 1, yylineno);
                    }
               }
#line 2066 "y.tab.c"
    break;

  case 38:
#line 342 "parser.y"
                       { (yyval.exprval) = emit_iftableitem((yyvsp[0].exprval));}
#line 2072 "y.tab.c"
    break;

  case 39:
#line 343 "parser.y"
                 {;}
#line 2078 "y.tab.c"
    break;

  case 40:
#line 344 "parser.y"
                      {;}
#line 2084 "y.tab.c"
    break;

  case 41:
#line 345 "parser.y"
                                {
               (yyval.exprval) = newexpr(programfunc_e);
               (yyval.exprval)->sym = &(yyvsp[-1].symval);
          }
#line 2093 "y.tab.c"
    break;

  case 42:
#line 349 "parser.y"
                  {;}
#line 2099 "y.tab.c"
    break;

  case 43:
#line 352 "parser.y"
                   {
               Symbol* item = lvalue_id(yytext, yylineno);
               (yyval.exprval) = lvalue_expr(item);
          }
#line 2108 "y.tab.c"
    break;

  case 44:
#line 356 "parser.y"
                     {
               Symbol* item = lvalue_localid(yytext, yylineno);
               if ( item && item->type == programfunc_s) {
                    fprintf(stderr, "Warning  :  %s is a function.", yytext);
               }
               (yyval.exprval) = lvalue_expr(item);
          }
#line 2120 "y.tab.c"
    break;

  case 45:
#line 363 "parser.y"
                       {
               Symbol* item = lvalue_dcolonid(yytext, yylineno);
               (yyval.exprval) = lvalue_expr(item);
          }
#line 2129 "y.tab.c"
    break;

  case 46:
#line 367 "parser.y"
                   {(yyval.exprval) = (yyvsp[0].exprval);}
#line 2135 "y.tab.c"
    break;

  case 47:
#line 370 "parser.y"
                              {(yyval.exprval) = member_item((yyvsp[-2].exprval), yytext);}
#line 2141 "y.tab.c"
    break;

  case 48:
#line 371 "parser.y"
                                    {
               (yyvsp[-3].exprval) = emit_iftableitem((yyvsp[-3].exprval));
               (yyval.exprval) = newexpr(tableitem_e);
               (yyval.exprval)->sym = (yyvsp[-3].exprval)->sym;
               (yyval.exprval)->index = (yyvsp[-1].exprval);
          }
#line 2152 "y.tab.c"
    break;

  case 49:
#line 377 "parser.y"
                        {;}
#line 2158 "y.tab.c"
    break;

  case 50:
#line 378 "parser.y"
                                  {;}
#line 2164 "y.tab.c"
    break;

  case 51:
#line 381 "parser.y"
                               { (yyval.exprval) = make_call((yyval.exprval), (yyvsp[-1].exprval));}
#line 2170 "y.tab.c"
    break;

  case 52:
#line 382 "parser.y"
                              {
               (yyvsp[-1].exprval) = emit_iftableitem((yyvsp[-1].exprval));
               if ((yyvsp[0].callval).method){
                    Expr* t = (yyvsp[-1].exprval);
                    (yyvsp[-1].exprval) = emit_iftableitem(member_item(t, (yyvsp[0].callval).name));
                    (yyvsp[0].callval).elist->next = t;
               }
               (yyval.exprval) = make_call((yyvsp[-1].exprval), (yyvsp[0].callval).elist);
          }
#line 2184 "y.tab.c"
    break;

  case 53:
#line 391 "parser.y"
                                                  {
               Expr* func = newexpr(programfunc_e);
               func->sym = &(yyvsp[-4].symval);
               (yyval.exprval) = make_call(func, (yyvsp[-1].exprval));
          }
#line 2194 "y.tab.c"
    break;

  case 54:
#line 398 "parser.y"
                         { (yyval.callval) = (yyvsp[0].callval); }
#line 2200 "y.tab.c"
    break;

  case 55:
#line 399 "parser.y"
                            {(yyval.callval) = (yyvsp[0].callval);}
#line 2206 "y.tab.c"
    break;

  case 56:
#line 402 "parser.y"
                                  {
                    (yyval.callval).elist = (yyvsp[-1].exprval);
                    (yyval.callval).method = 0;
                    (yyval.callval).name = NULL;
               }
#line 2216 "y.tab.c"
    break;

  case 57:
#line 408 "parser.y"
                                       {
               (yyval.callval).elist = (yyvsp[-1].exprval);
               (yyval.callval).method = 1;
               (yyval.callval).name = (yyvsp[-3].strval);
          }
#line 2226 "y.tab.c"
    break;

  case 58:
#line 414 "parser.y"
                         {
               (yyval.exprval) = (yyvsp[-1].exprval);
               (yyval.exprval)->next = (yyvsp[0].exprval);
          }
#line 2235 "y.tab.c"
    break;

  case 59:
#line 418 "parser.y"
            {(yyval.exprval) = NULL;}
#line 2241 "y.tab.c"
    break;

  case 60:
#line 420 "parser.y"
                                      {
                    (yyval.exprval) = (yyvsp[-1].exprval);
                    (yyval.exprval)->next = (yyvsp[0].exprval);
               }
#line 2250 "y.tab.c"
    break;

  case 61:
#line 424 "parser.y"
                 {(yyval.exprval) = NULL;}
#line 2256 "y.tab.c"
    break;

  case 62:
#line 427 "parser.y"
                                  {
                    int i;
                    Expr* t = newexpr(newtable_e);
                    t->sym = newtemp();
                    emit(tablecreate, t, NULL, NULL,0,yylineno);
                    for (i = 0; (yyvsp[-1].exprval); (yyvsp[-1].exprval) = (yyvsp[-1].exprval)->next)  {
                         emit(tablesetelem, t, newexpr_constnum(i++), (yyvsp[-1].exprval),0,yylineno);
                    }
                    (yyval.exprval) = t;
               }
#line 2271 "y.tab.c"
    break;

  case 63:
#line 437 "parser.y"
                                     {
                    Expr* t = newexpr(newtable_e);
                    t->sym = newtemp();
                    emit(tablecreate, t, NULL, NULL, nextquad() + 1,yylineno);
                    while ((yyvsp[-1].exprval)) {
                         emit(tablesetelem, t, (yyvsp[-1].exprval), (yyvsp[-1].exprval)->index, nextquad() + 1, yylineno);
                         (yyvsp[-1].exprval) = (yyvsp[-1].exprval)->next;
                    }
                    (yyval.exprval) = t;
               }
#line 2286 "y.tab.c"
    break;

  case 64:
#line 449 "parser.y"
                                    {;}
#line 2292 "y.tab.c"
    break;

  case 65:
#line 450 "parser.y"
                                           {;}
#line 2298 "y.tab.c"
    break;

  case 67:
#line 457 "parser.y"
                             {;}
#line 2304 "y.tab.c"
    break;

  case 68:
#line 458 "parser.y"
                 {;}
#line 2310 "y.tab.c"
    break;

  case 69:
#line 461 "parser.y"
                       { nextscope();}
#line 2316 "y.tab.c"
    break;

  case 70:
#line 461 "parser.y"
                                                      { hide(currscope()); exitscope();}
#line 2322 "y.tab.c"
    break;

  case 71:
#line 464 "parser.y"
                           {
                    funcname_id(yytext, yylineno);
                    (yyval.strval) = (yyvsp[0].strval);
                }
#line 2331 "y.tab.c"
    break;

  case 72:
#line 468 "parser.y"
                 {
                    funcname_noname(yytext, yylineno);
                    (yyval.strval) = newtempname();
               }
#line 2340 "y.tab.c"
    break;

  case 73:
#line 473 "parser.y"
                              {
                    (yyval.symval) = *create_item(programfunc_s, (yyvsp[0].strval), currscopespace(), currscopespaceoffset(), currscope(), currfuncscope(), yylineno);
                    (yyval.symval).iaddress = nextquad();
                    emit(funcstart, (yyval.symval), NULL, NULL, nextquad() + 1, yylineno);
                    /*push(scopeoffsetstack, currscopeoffset());*/
                    enterscopespace();
                    resetformalargsoffset();

               }
#line 2354 "y.tab.c"
    break;

  case 74:
#line 484 "parser.y"
                                   {
                    enterfuncscope();
                    enterscopespace();
                    resetfunctionlocaloffset();
               }
#line 2364 "y.tab.c"
    break;

  case 75:
#line 490 "parser.y"
                      {
                    exitfuncscope();
                    (yyval.intval) = currscopespaceoffset();
                    exitscopespace();
               }
#line 2374 "y.tab.c"
    break;

  case 76:
#line 497 "parser.y"
               { /*push(loopcounterstack, loopcounter); loopcounter=0; */}
#line 2380 "y.tab.c"
    break;

  case 77:
#line 498 "parser.y"
                { /*loopcounter = pop(loopcounterstack);*/ }
#line 2386 "y.tab.c"
    break;

  case 78:
#line 500 "parser.y"
                                                                        {
               /*int offset;*/
               exitscopespace();
               (yyvsp[-4].symval).totalLocals = (yyvsp[-1].intval);
               /*offset = pop_and_top(scopeoffsetStack);
               /restorecurrscopeoffset(offset);*/
               (yyval.symval) = (yyvsp[-4].symval);
               emit(funcend, (yyvsp[-4].symval),  NULL ,  NULL, nextquad(), yylineno);
          }
#line 2400 "y.tab.c"
    break;

  case 79:
#line 510 "parser.y"
            { (yyval.exprval) = newexpr_constnum((yyvsp[0].intval));}
#line 2406 "y.tab.c"
    break;

  case 80:
#line 511 "parser.y"
                 { (yyval.exprval) = newexpr_constnum((yyvsp[0].floatval));}
#line 2412 "y.tab.c"
    break;

  case 81:
#line 512 "parser.y"
                   { (yyval.exprval) = newexpr_conststring((yyvsp[0].strval));}
#line 2418 "y.tab.c"
    break;

  case 82:
#line 513 "parser.y"
                { (yyval.exprval) = newexpr(nil_e);}
#line 2424 "y.tab.c"
    break;

  case 83:
#line 514 "parser.y"
                 { (yyval.exprval) = newexpr_constbool(1);}
#line 2430 "y.tab.c"
    break;

  case 84:
#line 515 "parser.y"
                  { (yyval.exprval) = newexpr_constbool(0);}
#line 2436 "y.tab.c"
    break;

  case 85:
#line 518 "parser.y"
           { idlist_id(yytext, yylineno);}
#line 2442 "y.tab.c"
    break;

  case 86:
#line 519 "parser.y"
                            { idlist_commaid(yytext, yylineno);}
#line 2448 "y.tab.c"
    break;

  case 87:
#line 520 "parser.y"
            {;}
#line 2454 "y.tab.c"
    break;

  case 88:
#line 523 "parser.y"
                                    {
               emit(if_eq, (yyvsp[-1].exprval), newexpr_constbool(1), NULL, nextquad() + 2, yylineno);
               (yyval.intval) = nextquad();
               emit(jump, NULL , NULL, NULL, 0, yylineno);
          }
#line 2464 "y.tab.c"
    break;

  case 89:
#line 530 "parser.y"
                     {
                     (yyval.intval) = nextquad();
                     emit(jump, NULL, NULL, NULL, 0, yylineno);
               }
#line 2473 "y.tab.c"
    break;

  case 90:
#line 536 "parser.y"
                                     {
                     patchlabel((yyvsp[-1].intval), nextquad());
                }
#line 2481 "y.tab.c"
    break;

  case 91:
#line 539 "parser.y"
                                                {
                     patchlabel((yyvsp[-3].intval), ((yyvsp[-1].intval))+1);
                     patchlabel((yyvsp[-1].intval), nextquad());
               }
#line 2490 "y.tab.c"
    break;

  case 92:
#line 545 "parser.y"
                      {
                    gloop++;
                    (yyval.intval) = nextquad();
               }
#line 2499 "y.tab.c"
    break;

  case 93:
#line 551 "parser.y"
                                 {
                    emit(if_eq, (yyvsp[-1].exprval), newexpr_constbool(1), nextquad()+2, NULL, 0, yylineno);
                    (yyval.intval) = nextquad();
                    emit(jump, NULL, NULL, NULL, 0, yylineno);
               }
#line 2509 "y.tab.c"
    break;

  case 94:
#line 559 "parser.y"
                                                  {
                    gloop--;
                    emit(jump, NULL, NULL, (yyvsp[-3].intval), 0, yylineno);
                    patchlabel((yyvsp[-2].intval), nextquad());
                    patchlist((yyvsp[-1].stmtval).breaklist, nextquad());
                    patchlist((yyvsp[-1].stmtval).contlist, (yyvsp[-3].intval));
               }
#line 2521 "y.tab.c"
    break;

  case 95:
#line 567 "parser.y"
                { ++loopcounter;}
#line 2527 "y.tab.c"
    break;

  case 96:
#line 568 "parser.y"
                     { --loopcounter;}
#line 2533 "y.tab.c"
    break;

  case 97:
#line 570 "parser.y"
                                 { (yyval.stmtval) = (yyvsp[-1].stmtval);}
#line 2539 "y.tab.c"
    break;

  case 98:
#line 572 "parser.y"
        {
          (yyval.intval) = nextquad();
          emit(jump, NULL, NULL, NULL, 0, yylineno);
     }
#line 2548 "y.tab.c"
    break;

  case 99:
#line 577 "parser.y"
     {(yyval.intval) = nextquad();}
#line 2554 "y.tab.c"
    break;

  case 100:
#line 580 "parser.y"
                    {gloop++;}
#line 2560 "y.tab.c"
    break;

  case 101:
#line 580 "parser.y"
                                                             {
                    (yyval.prefval).test = (yyvsp[-2].intval);
                    (yyval.prefval).enter = nextquad();
                    emit(if_eq, (yyvsp[-1].exprval), newexpr_constbool(1), NULL, 0, yylineno);
               }
#line 2570 "y.tab.c"
    break;

  case 102:
#line 587 "parser.y"
                                               {gloop--;}
#line 2576 "y.tab.c"
    break;

  case 103:
#line 587 "parser.y"
                                                                     {
               patchlabel((yyvsp[-8].prefval).enter, (yyvsp[-4].intval)+1);
               patchlabel((yyvsp[-7].intval), nextquad());
               patchlabel((yyvsp[-4].intval), (yyvsp[-8].prefval).test);
               patchlabel((yyvsp[-1].intval), (yyvsp[-7].intval)+1);

               patchlist((yyvsp[-3].stmtval).breaklist, nextquad());
               patchlist((yyvsp[-3].stmtval).contlist, (yyvsp[-7].intval)+1);
          }
#line 2590 "y.tab.c"
    break;

  case 104:
#line 598 "parser.y"
             {}
#line 2596 "y.tab.c"
    break;

  case 105:
#line 600 "parser.y"
                   {}
#line 2602 "y.tab.c"
    break;

  case 106:
#line 603 "parser.y"
                            { 
                    if (currfuncscope() == 0) Error(2, yytext, yylineno);
                    else {
                         emit(ret, NULL, NULL, NULL, nextquad() + 1, yylineno);
                    }
               }
#line 2613 "y.tab.c"
    break;

  case 107:
#line 609 "parser.y"
                                     {
                    if (currfuncscope() == 0) Error(2, yytext, yylineno);
                    emit(ret, NULL, NULL, (yyvsp[-1].exprval), nextquad() + 1, yylineno);
                  }
#line 2622 "y.tab.c"
    break;


#line 2626 "y.tab.c"

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
#line 615 "parser.y"


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
