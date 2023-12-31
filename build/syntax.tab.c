/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
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
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "syntax.y"

    // 1
    #include "parse_tree.h"
    #include "semantic.h"
    #include "ir_gen.h"
    #include "yyerror_ow.h"
    #include "lex.yy.c"
    void yyerror(const char*);

    FILE* file_out = NULL;
    FILE* tree_out = NULL;
    int errors = 0;

    #define PRINT_ERROR(type, error_node) { \
        ++errors; \
        yyerror_ow(file_out, type, error_node->lineno); \
    }

#line 90 "/home/mango/workspace/CS323-Compilers/CS323_Compiler/build/syntax.tab.c"

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

#include "syntax.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_INT = 3,                        /* INT  */
  YYSYMBOL_FLOAT = 4,                      /* FLOAT  */
  YYSYMBOL_CHAR = 5,                       /* CHAR  */
  YYSYMBOL_ID = 6,                         /* ID  */
  YYSYMBOL_TYPE = 7,                       /* TYPE  */
  YYSYMBOL_STRUCT = 8,                     /* STRUCT  */
  YYSYMBOL_IF = 9,                         /* IF  */
  YYSYMBOL_ELSE = 10,                      /* ELSE  */
  YYSYMBOL_WHILE = 11,                     /* WHILE  */
  YYSYMBOL_RETURN = 12,                    /* RETURN  */
  YYSYMBOL_DOT = 13,                       /* DOT  */
  YYSYMBOL_SEMI = 14,                      /* SEMI  */
  YYSYMBOL_COMMA = 15,                     /* COMMA  */
  YYSYMBOL_ASSIGN = 16,                    /* ASSIGN  */
  YYSYMBOL_LT = 17,                        /* LT  */
  YYSYMBOL_LE = 18,                        /* LE  */
  YYSYMBOL_GT = 19,                        /* GT  */
  YYSYMBOL_GE = 20,                        /* GE  */
  YYSYMBOL_NE = 21,                        /* NE  */
  YYSYMBOL_EQ = 22,                        /* EQ  */
  YYSYMBOL_PLUS = 23,                      /* PLUS  */
  YYSYMBOL_MINUS = 24,                     /* MINUS  */
  YYSYMBOL_MUL = 25,                       /* MUL  */
  YYSYMBOL_DIV = 26,                       /* DIV  */
  YYSYMBOL_AND = 27,                       /* AND  */
  YYSYMBOL_OR = 28,                        /* OR  */
  YYSYMBOL_NOT = 29,                       /* NOT  */
  YYSYMBOL_LP = 30,                        /* LP  */
  YYSYMBOL_RP = 31,                        /* RP  */
  YYSYMBOL_LB = 32,                        /* LB  */
  YYSYMBOL_RB = 33,                        /* RB  */
  YYSYMBOL_LC = 34,                        /* LC  */
  YYSYMBOL_RC = 35,                        /* RC  */
  YYSYMBOL_ERROR = 36,                     /* ERROR  */
  YYSYMBOL_YYACCEPT = 37,                  /* $accept  */
  YYSYMBOL_Program = 38,                   /* Program  */
  YYSYMBOL_ExtDefList = 39,                /* ExtDefList  */
  YYSYMBOL_ExtDef = 40,                    /* ExtDef  */
  YYSYMBOL_ExtDecList = 41,                /* ExtDecList  */
  YYSYMBOL_Specifier = 42,                 /* Specifier  */
  YYSYMBOL_StructSpecifier = 43,           /* StructSpecifier  */
  YYSYMBOL_VarDec = 44,                    /* VarDec  */
  YYSYMBOL_FunDec = 45,                    /* FunDec  */
  YYSYMBOL_VarList = 46,                   /* VarList  */
  YYSYMBOL_ParamDec = 47,                  /* ParamDec  */
  YYSYMBOL_CompSt = 48,                    /* CompSt  */
  YYSYMBOL_StmtList = 49,                  /* StmtList  */
  YYSYMBOL_Stmt = 50,                      /* Stmt  */
  YYSYMBOL_DefList = 51,                   /* DefList  */
  YYSYMBOL_Def = 52,                       /* Def  */
  YYSYMBOL_DecList = 53,                   /* DecList  */
  YYSYMBOL_Dec = 54,                       /* Dec  */
  YYSYMBOL_Exp = 55,                       /* Exp  */
  YYSYMBOL_Args = 56                       /* Args  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




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

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
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
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
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

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

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
#define YYFINAL  11
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   409

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  37
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  20
/* YYNRULES -- Number of rules.  */
#define YYNRULES  79
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  141

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   291


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

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
      35,    36
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    82,    82,    91,    92,    94,    95,    96,    97,   101,
     105,   109,   110,   114,   115,   117,   118,   122,   123,   124,
     126,   127,   128,   132,   137,   138,   140,   144,   146,   147,
     148,   150,   151,   152,   153,   154,   155,   156,   160,   164,
     168,   175,   176,   178,   179,   184,   185,   187,   188,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   222,   226,   231,   232
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "INT", "FLOAT", "CHAR",
  "ID", "TYPE", "STRUCT", "IF", "ELSE", "WHILE", "RETURN", "DOT", "SEMI",
  "COMMA", "ASSIGN", "LT", "LE", "GT", "GE", "NE", "EQ", "PLUS", "MINUS",
  "MUL", "DIV", "AND", "OR", "NOT", "LP", "RP", "LB", "RB", "LC", "RC",
  "ERROR", "$accept", "Program", "ExtDefList", "ExtDef", "ExtDecList",
  "Specifier", "StructSpecifier", "VarDec", "FunDec", "VarList",
  "ParamDec", "CompSt", "StmtList", "Stmt", "DefList", "Def", "DecList",
  "Dec", "Exp", "Args", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-46)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-5)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     124,     1,   -46,     4,     7,   -46,   124,    60,   -46,   -46,
      24,   -46,   -46,   -46,    29,   -46,   -46,    50,    -7,    36,
       6,    68,   -46,   -46,    13,    57,   212,   -46,    13,    28,
       6,   -46,   -46,    13,    22,    56,   -46,   -46,    40,   -46,
     -46,   -46,    47,    70,    73,   234,   234,   234,   234,   -46,
     -46,    69,   212,   212,    66,    -4,    51,    90,   -46,   -46,
      74,   -46,   -46,     6,   -46,    26,   234,   234,    94,   218,
     318,   122,   -46,   -46,   -46,   -46,   103,   -46,   234,   234,
     234,   234,   234,   234,   234,   234,   234,   234,   234,   234,
     234,   234,   234,   234,   -46,   -46,    13,   -46,   -46,   -46,
     256,    23,   150,   178,   -46,   -46,   -46,   -46,   -46,   298,
     372,   372,   372,   372,   372,   372,   218,   218,    65,    65,
     358,   338,   277,   298,   298,   -46,   234,   -46,   -46,   223,
     223,   223,   223,   -46,   -46,   -46,   117,   -46,   -46,   223,
     -46
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,    13,     0,     0,     2,     0,     0,    14,    10,
      16,     1,     3,     8,    17,     6,    19,     0,    11,     0,
      42,     0,     9,     5,     0,     0,    30,     7,     0,     0,
      42,    23,    21,     0,     0,    25,    17,    12,     0,    70,
      71,    72,    69,     0,     0,     0,     0,     0,     0,    74,
      32,     0,    30,    30,     0,    47,     0,    45,    15,    41,
      26,    22,    20,     0,    18,     0,     0,     0,     0,    63,
      64,     0,    27,    28,    29,    37,     0,    31,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    44,    43,     0,    24,    77,    66,
      79,     0,     0,     0,    38,    36,    75,    62,    68,    49,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      50,    51,     0,    73,    48,    46,     0,    76,    65,     0,
       0,     0,     0,    67,    78,    39,    33,    40,    35,     0,
      34
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -46,   -46,   123,   -46,   104,     5,   -46,   -24,   -46,    71,
     -46,   114,   -35,   270,   -14,   -46,    41,   -46,   -45,    10
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     4,     5,     6,    17,    28,     8,    18,    19,    34,
      35,    50,    51,    52,    53,    30,    56,    57,    54,   101
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      68,    69,    70,    71,    55,     7,    29,    11,    24,    60,
      10,     7,    93,     2,     3,     9,    59,    73,    74,    36,
     100,   102,   103,    61,   127,    25,    33,    98,    25,    39,
      40,    41,    42,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,    16,
      46,    22,    94,    62,   128,    47,    48,    99,    20,    21,
      38,    13,    49,    58,    23,    95,    14,    75,    33,    31,
      26,    63,    55,    64,    15,     2,     3,    65,    76,    76,
      77,   100,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,   104,    16,    91,    91,    32,
      66,    92,    92,    67,    72,    96,    25,    76,   105,   108,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,   106,    -4,     1,    91,   139,    37,    12,
      92,     2,     3,    27,    97,    76,   134,   125,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,   129,     0,   107,    91,     0,     0,     0,    92,     0,
       0,     0,     0,    76,     0,     0,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,   131,
       0,   130,    91,     0,     0,     0,    92,     0,     0,     0,
       0,    76,     0,     0,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,     0,     0,   132,
      91,     0,     0,     0,    92,    39,    40,    41,    42,     2,
       3,    43,     0,    44,    45,     0,    39,    40,    41,    42,
       0,    76,    43,     0,    44,    45,    46,    39,    40,    41,
      42,    47,    48,    87,    88,     0,    26,    46,    49,     0,
      91,     0,    47,    48,    92,     0,     0,    26,    46,    49,
       0,     0,     0,    47,    48,     0,     0,     0,     0,    76,
      49,   126,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,     0,     0,     0,    91,     0,
      76,     0,    92,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,     0,     0,     0,    91,
     133,    76,     0,    92,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,     0,     0,     0,
      91,    76,     0,     0,    92,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,     0,     0,     0,
      91,    76,     0,     0,    92,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,     0,     0,     0,     0,
      91,    76,     0,     0,    92,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    76,     0,     0,     0,     0,
      91,     0,     0,     0,    92,    85,    86,    87,    88,   135,
     136,   137,   138,     0,    91,     0,     0,     0,    92,   140
};

static const yytype_int16 yycheck[] =
{
      45,    46,    47,    48,    28,     0,    20,     0,    15,    33,
       6,     6,    16,     7,     8,    14,    30,    52,    53,     6,
      65,    66,    67,     1,     1,    32,    21,     1,    32,     3,
       4,     5,     6,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    36,
      24,     1,     1,    31,    31,    29,    30,    31,    34,    30,
       3,     1,    36,    35,    14,    14,     6,     1,    63,     1,
      34,    15,    96,    33,    14,     7,     8,    30,    13,    13,
      14,   126,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,     1,    36,    32,    32,    31,
      30,    36,    36,    30,    35,    15,    32,    13,    14,     6,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,     1,     0,     1,    32,    10,    24,     6,
      36,     7,     8,    19,    63,    13,   126,    96,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,     1,    -1,    31,    32,    -1,    -1,    -1,    36,    -1,
      -1,    -1,    -1,    13,    -1,    -1,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,     1,
      -1,    31,    32,    -1,    -1,    -1,    36,    -1,    -1,    -1,
      -1,    13,    -1,    -1,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    -1,    -1,    31,
      32,    -1,    -1,    -1,    36,     3,     4,     5,     6,     7,
       8,     9,    -1,    11,    12,    -1,     3,     4,     5,     6,
      -1,    13,     9,    -1,    11,    12,    24,     3,     4,     5,
       6,    29,    30,    25,    26,    -1,    34,    24,    36,    -1,
      32,    -1,    29,    30,    36,    -1,    -1,    34,    24,    36,
      -1,    -1,    -1,    29,    30,    -1,    -1,    -1,    -1,    13,
      36,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    -1,    -1,    -1,    32,    -1,
      13,    -1,    36,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    -1,    -1,    -1,    32,
      33,    13,    -1,    36,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    -1,    -1,    -1,
      32,    13,    -1,    -1,    36,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    -1,    -1,    -1,
      32,    13,    -1,    -1,    36,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    -1,    -1,    -1,    -1,
      32,    13,    -1,    -1,    36,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    13,    -1,    -1,    -1,    -1,
      32,    -1,    -1,    -1,    36,    23,    24,    25,    26,   129,
     130,   131,   132,    -1,    32,    -1,    -1,    -1,    36,   139
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     1,     7,     8,    38,    39,    40,    42,    43,    14,
       6,     0,    39,     1,     6,    14,    36,    41,    44,    45,
      34,    30,     1,    14,    15,    32,    34,    48,    42,    51,
      52,     1,    31,    42,    46,    47,     6,    41,     3,     3,
       4,     5,     6,     9,    11,    12,    24,    29,    30,    36,
      48,    49,    50,    51,    55,    44,    53,    54,    35,    51,
      44,     1,    31,    15,    33,    30,    30,    30,    55,    55,
      55,    55,    35,    49,    49,     1,    13,    14,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    32,    36,    16,     1,    14,    15,    46,     1,    31,
      55,    56,    55,    55,     1,    14,     1,    31,     6,    55,
      55,    55,    55,    55,    55,    55,    55,    55,    55,    55,
      55,    55,    55,    55,    55,    53,    15,     1,    31,     1,
      31,     1,    31,    33,    56,    50,    50,    50,    50,    10,
      50
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    37,    38,    39,    39,    40,    40,    40,    40,    40,
      40,    41,    41,    42,    42,    43,    43,    44,    44,    44,
      45,    45,    45,    45,    46,    46,    47,    48,    49,    49,
      49,    50,    50,    50,    50,    50,    50,    50,    50,    50,
      50,    51,    51,    52,    52,    53,    53,    54,    54,    55,
      55,    55,    55,    55,    55,    55,    55,    55,    55,    55,
      55,    55,    55,    55,    55,    55,    55,    55,    55,    55,
      55,    55,    55,    55,    55,    55,    55,    55,    56,    56
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     0,     3,     2,     3,     2,     3,
       2,     1,     3,     1,     1,     5,     2,     1,     4,     1,
       4,     3,     4,     3,     3,     1,     2,     3,     2,     2,
       0,     2,     1,     5,     7,     5,     3,     2,     3,     5,
       5,     2,     0,     3,     3,     1,     3,     1,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     2,     2,     4,     3,     4,     3,     1,
       1,     1,     1,     3,     1,     3,     4,     3,     3,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


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

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


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




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
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
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
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
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
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
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

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
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
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
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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
  case 2: /* Program: ExtDefList  */
#line 82 "syntax.y"
                    { 
        (yyval.node) = new_interior_node("Program", 1, (yyvsp[0].node));
        if (errors == 0) {
            print_tree((yyval.node), 0, tree_out);
            parse_program((yyval.node));
            translate_program((yyval.node));
        }
    }
#line 1281 "/home/mango/workspace/CS323-Compilers/CS323_Compiler/build/syntax.tab.c"
    break;

  case 3: /* ExtDefList: ExtDef ExtDefList  */
#line 91 "syntax.y"
                              { (yyval.node) = new_interior_node("ExtDefList", 2, (yyvsp[-1].node), (yyvsp[0].node)); }
#line 1287 "/home/mango/workspace/CS323-Compilers/CS323_Compiler/build/syntax.tab.c"
    break;

  case 4: /* ExtDefList: %empty  */
#line 92 "syntax.y"
             { (yyval.node) = new_interior_node("Epsilon", -1); }
#line 1293 "/home/mango/workspace/CS323-Compilers/CS323_Compiler/build/syntax.tab.c"
    break;

  case 5: /* ExtDef: Specifier ExtDecList SEMI  */
#line 94 "syntax.y"
                                  { (yyval.node) = new_interior_node("ExtDef", 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)); }
#line 1299 "/home/mango/workspace/CS323-Compilers/CS323_Compiler/build/syntax.tab.c"
    break;

  case 6: /* ExtDef: Specifier SEMI  */
#line 95 "syntax.y"
                     { (yyval.node) = new_interior_node("ExtDef", 2, (yyvsp[-1].node), (yyvsp[0].node)); }
#line 1305 "/home/mango/workspace/CS323-Compilers/CS323_Compiler/build/syntax.tab.c"
    break;

  case 7: /* ExtDef: Specifier FunDec CompSt  */
#line 96 "syntax.y"
                              { (yyval.node) = new_interior_node("ExtDef", 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)); }
#line 1311 "/home/mango/workspace/CS323-Compilers/CS323_Compiler/build/syntax.tab.c"
    break;

  case 8: /* ExtDef: Specifier error  */
#line 97 "syntax.y"
                      {
        (yyval.node) = new_interior_node("ExtDef", 1, (yyvsp[-1].node));
        PRINT_ERROR(MISS_SEMI, (yyvsp[-1].node))
    }
#line 1320 "/home/mango/workspace/CS323-Compilers/CS323_Compiler/build/syntax.tab.c"
    break;

  case 9: /* ExtDef: Specifier ExtDecList error  */
#line 101 "syntax.y"
                                 {
        (yyval.node) = new_interior_node("ExtDef", 2, (yyvsp[-2].node), (yyvsp[-1].node));
        PRINT_ERROR(MISS_SEMI, (yyvsp[-1].node))
    }
#line 1329 "/home/mango/workspace/CS323-Compilers/CS323_Compiler/build/syntax.tab.c"
    break;

  case 10: /* ExtDef: error SEMI  */
#line 105 "syntax.y"
                 {
        ++errors;
    }
#line 1337 "/home/mango/workspace/CS323-Compilers/CS323_Compiler/build/syntax.tab.c"
    break;

  case 11: /* ExtDecList: VarDec  */
#line 109 "syntax.y"
                   { (yyval.node) = new_interior_node("ExtDecList", 1, (yyvsp[0].node)); }
#line 1343 "/home/mango/workspace/CS323-Compilers/CS323_Compiler/build/syntax.tab.c"
    break;

  case 12: /* ExtDecList: VarDec COMMA ExtDecList  */
#line 110 "syntax.y"
                              { (yyval.node) = new_interior_node("ExtDecList", 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)); }
#line 1349 "/home/mango/workspace/CS323-Compilers/CS323_Compiler/build/syntax.tab.c"
    break;

  case 13: /* Specifier: TYPE  */
#line 114 "syntax.y"
                { (yyval.node) = new_interior_node("Specifier", 1, (yyvsp[0].node)); }
#line 1355 "/home/mango/workspace/CS323-Compilers/CS323_Compiler/build/syntax.tab.c"
    break;

  case 14: /* Specifier: StructSpecifier  */
#line 115 "syntax.y"
                      { (yyval.node) = new_interior_node("Specifier", 1, (yyvsp[0].node)); }
#line 1361 "/home/mango/workspace/CS323-Compilers/CS323_Compiler/build/syntax.tab.c"
    break;

  case 15: /* StructSpecifier: STRUCT ID LC DefList RC  */
#line 117 "syntax.y"
                                         { (yyval.node) = new_interior_node("StructSpecifier", 5, (yyvsp[-4].node), (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)); }
#line 1367 "/home/mango/workspace/CS323-Compilers/CS323_Compiler/build/syntax.tab.c"
    break;

  case 16: /* StructSpecifier: STRUCT ID  */
#line 118 "syntax.y"
                { (yyval.node) = new_interior_node("StructSpecifier", 2, (yyvsp[-1].node), (yyvsp[0].node)); }
#line 1373 "/home/mango/workspace/CS323-Compilers/CS323_Compiler/build/syntax.tab.c"
    break;

  case 17: /* VarDec: ID  */
#line 122 "syntax.y"
           { (yyval.node) = new_interior_node("VarDec", 1, (yyvsp[0].node)); }
#line 1379 "/home/mango/workspace/CS323-Compilers/CS323_Compiler/build/syntax.tab.c"
    break;

  case 18: /* VarDec: VarDec LB INT RB  */
#line 123 "syntax.y"
                       { (yyval.node) = new_interior_node("VarDec", 4, (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)); }
#line 1385 "/home/mango/workspace/CS323-Compilers/CS323_Compiler/build/syntax.tab.c"
    break;

  case 19: /* VarDec: ERROR  */
#line 124 "syntax.y"
            { (yyval.node) = new_interior_node("VarDec", 1, (yyvsp[0].node)); ++errors; }
#line 1391 "/home/mango/workspace/CS323-Compilers/CS323_Compiler/build/syntax.tab.c"
    break;

  case 20: /* FunDec: ID LP VarList RP  */
#line 126 "syntax.y"
                         { (yyval.node) = new_interior_node("FunDec", 4, (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)); }
#line 1397 "/home/mango/workspace/CS323-Compilers/CS323_Compiler/build/syntax.tab.c"
    break;

  case 21: /* FunDec: ID LP RP  */
#line 127 "syntax.y"
               { (yyval.node) = new_interior_node("FunDec", 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)); }
#line 1403 "/home/mango/workspace/CS323-Compilers/CS323_Compiler/build/syntax.tab.c"
    break;

  case 22: /* FunDec: ID LP VarList error  */
#line 128 "syntax.y"
                          {
        (yyval.node) = new_interior_node("FunDec", 3, (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node));
        PRINT_ERROR(MISS_RP, (yyvsp[-1].node))
    }
#line 1412 "/home/mango/workspace/CS323-Compilers/CS323_Compiler/build/syntax.tab.c"
    break;

  case 23: /* FunDec: ID LP error  */
#line 132 "syntax.y"
                  {
        (yyval.node) = new_interior_node("FunDec", 2, (yyvsp[-2].node), (yyvsp[-1].node));
        PRINT_ERROR(MISS_RP, (yyvsp[-1].node))
    }
#line 1421 "/home/mango/workspace/CS323-Compilers/CS323_Compiler/build/syntax.tab.c"
    break;

  case 24: /* VarList: ParamDec COMMA VarList  */
#line 137 "syntax.y"
                                { (yyval.node) = new_interior_node("VarList", 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)); }
#line 1427 "/home/mango/workspace/CS323-Compilers/CS323_Compiler/build/syntax.tab.c"
    break;

  case 25: /* VarList: ParamDec  */
#line 138 "syntax.y"
               { (yyval.node) = new_interior_node("VarList", 1, (yyvsp[0].node)); }
#line 1433 "/home/mango/workspace/CS323-Compilers/CS323_Compiler/build/syntax.tab.c"
    break;

  case 26: /* ParamDec: Specifier VarDec  */
#line 140 "syntax.y"
                           { (yyval.node) = new_interior_node("ParamDec", 2, (yyvsp[-1].node), (yyvsp[0].node)); }
#line 1439 "/home/mango/workspace/CS323-Compilers/CS323_Compiler/build/syntax.tab.c"
    break;

  case 27: /* CompSt: LC StmtList RC  */
#line 144 "syntax.y"
                       { (yyval.node) = new_interior_node("CompSt", 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)); }
#line 1445 "/home/mango/workspace/CS323-Compilers/CS323_Compiler/build/syntax.tab.c"
    break;

  case 28: /* StmtList: Stmt StmtList  */
#line 146 "syntax.y"
                        { (yyval.node) = new_interior_node("StmtList", 2, (yyvsp[-1].node), (yyvsp[0].node)); }
#line 1451 "/home/mango/workspace/CS323-Compilers/CS323_Compiler/build/syntax.tab.c"
    break;

  case 29: /* StmtList: DefList StmtList  */
#line 147 "syntax.y"
                       {(yyval.node) = new_interior_node("StmtList", 2, (yyvsp[-1].node), (yyvsp[0].node)); }
#line 1457 "/home/mango/workspace/CS323-Compilers/CS323_Compiler/build/syntax.tab.c"
    break;

  case 30: /* StmtList: %empty  */
#line 148 "syntax.y"
             { (yyval.node) = new_interior_node("Epsilon", -1); }
#line 1463 "/home/mango/workspace/CS323-Compilers/CS323_Compiler/build/syntax.tab.c"
    break;

  case 31: /* Stmt: Exp SEMI  */
#line 150 "syntax.y"
               { (yyval.node) = new_interior_node("Stmt", 2, (yyvsp[-1].node), (yyvsp[0].node)); }
#line 1469 "/home/mango/workspace/CS323-Compilers/CS323_Compiler/build/syntax.tab.c"
    break;

  case 32: /* Stmt: CompSt  */
#line 151 "syntax.y"
             { (yyval.node) = new_interior_node("Stmt", 1, (yyvsp[0].node)); }
#line 1475 "/home/mango/workspace/CS323-Compilers/CS323_Compiler/build/syntax.tab.c"
    break;

  case 33: /* Stmt: IF LP Exp RP Stmt  */
#line 152 "syntax.y"
                        { (yyval.node) = new_interior_node("Stmt", 5, (yyvsp[-4].node), (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)); }
#line 1481 "/home/mango/workspace/CS323-Compilers/CS323_Compiler/build/syntax.tab.c"
    break;

  case 34: /* Stmt: IF LP Exp RP Stmt ELSE Stmt  */
#line 153 "syntax.y"
                                  { (yyval.node) = new_interior_node("Stmt", 7, (yyvsp[-6].node), (yyvsp[-5].node), (yyvsp[-4].node), (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)); }
#line 1487 "/home/mango/workspace/CS323-Compilers/CS323_Compiler/build/syntax.tab.c"
    break;

  case 35: /* Stmt: WHILE LP Exp RP Stmt  */
#line 154 "syntax.y"
                           { (yyval.node) = new_interior_node("Stmt", 5, (yyvsp[-4].node), (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)); }
#line 1493 "/home/mango/workspace/CS323-Compilers/CS323_Compiler/build/syntax.tab.c"
    break;

  case 36: /* Stmt: RETURN Exp SEMI  */
#line 155 "syntax.y"
                      { (yyval.node) = new_interior_node("Stmt", 2, (yyvsp[-2].node), (yyvsp[-1].node)); }
#line 1499 "/home/mango/workspace/CS323-Compilers/CS323_Compiler/build/syntax.tab.c"
    break;

  case 37: /* Stmt: Exp error  */
#line 156 "syntax.y"
                {
        (yyval.node) = new_interior_node("Stmt", 1, (yyvsp[-1].node));
        PRINT_ERROR(MISS_SEMI, (yyvsp[-1].node))
    }
#line 1508 "/home/mango/workspace/CS323-Compilers/CS323_Compiler/build/syntax.tab.c"
    break;

  case 38: /* Stmt: RETURN Exp error  */
#line 160 "syntax.y"
                       {
        (yyval.node) = new_interior_node("Stmt", 2, (yyvsp[-2].node), (yyvsp[-1].node));
        PRINT_ERROR(MISS_SEMI, (yyvsp[-1].node))
    }
#line 1517 "/home/mango/workspace/CS323-Compilers/CS323_Compiler/build/syntax.tab.c"
    break;

  case 39: /* Stmt: IF LP Exp error Stmt  */
#line 164 "syntax.y"
                           { 
        (yyval.node) = new_interior_node("Stmt", 4, (yyvsp[-4].node), (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[0].node));
        PRINT_ERROR(MISS_RP, (yyvsp[-2].node))
    }
#line 1526 "/home/mango/workspace/CS323-Compilers/CS323_Compiler/build/syntax.tab.c"
    break;

  case 40: /* Stmt: WHILE LP Exp error Stmt  */
#line 168 "syntax.y"
                              {
        (yyval.node) = new_interior_node("Stmt", 3, (yyvsp[-4].node), (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[0].node));
        PRINT_ERROR(MISS_RP, (yyvsp[-2].node))
    }
#line 1535 "/home/mango/workspace/CS323-Compilers/CS323_Compiler/build/syntax.tab.c"
    break;

  case 41: /* DefList: Def DefList  */
#line 175 "syntax.y"
                     { (yyval.node) = new_interior_node("DefList", 2, (yyvsp[-1].node), (yyvsp[0].node)); }
#line 1541 "/home/mango/workspace/CS323-Compilers/CS323_Compiler/build/syntax.tab.c"
    break;

  case 42: /* DefList: %empty  */
#line 176 "syntax.y"
             { (yyval.node) = new_interior_node("Epsilon", -1); }
#line 1547 "/home/mango/workspace/CS323-Compilers/CS323_Compiler/build/syntax.tab.c"
    break;

  case 43: /* Def: Specifier DecList SEMI  */
#line 178 "syntax.y"
                            { (yyval.node) = new_interior_node("Def", 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)); }
#line 1553 "/home/mango/workspace/CS323-Compilers/CS323_Compiler/build/syntax.tab.c"
    break;

  case 44: /* Def: Specifier DecList error  */
#line 179 "syntax.y"
                              {
        (yyval.node) = new_interior_node("Def", 2, (yyvsp[-2].node), (yyvsp[-1].node));
        PRINT_ERROR(MISS_SEMI, (yyvsp[-1].node))
    }
#line 1562 "/home/mango/workspace/CS323-Compilers/CS323_Compiler/build/syntax.tab.c"
    break;

  case 45: /* DecList: Dec  */
#line 184 "syntax.y"
             { (yyval.node) = new_interior_node("DecList", 1, (yyvsp[0].node)); }
#line 1568 "/home/mango/workspace/CS323-Compilers/CS323_Compiler/build/syntax.tab.c"
    break;

  case 46: /* DecList: Dec COMMA DecList  */
#line 185 "syntax.y"
                        { (yyval.node) = new_interior_node("DecList", 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)); }
#line 1574 "/home/mango/workspace/CS323-Compilers/CS323_Compiler/build/syntax.tab.c"
    break;

  case 47: /* Dec: VarDec  */
#line 187 "syntax.y"
            { (yyval.node) = new_interior_node("Dec", 1, (yyvsp[0].node)); }
#line 1580 "/home/mango/workspace/CS323-Compilers/CS323_Compiler/build/syntax.tab.c"
    break;

  case 48: /* Dec: VarDec ASSIGN Exp  */
#line 188 "syntax.y"
                        { (yyval.node) = new_interior_node("Dec", 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)); }
#line 1586 "/home/mango/workspace/CS323-Compilers/CS323_Compiler/build/syntax.tab.c"
    break;

  case 49: /* Exp: Exp ASSIGN Exp  */
#line 192 "syntax.y"
                    { (yyval.node) = new_interior_node("Exp", 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)); }
#line 1592 "/home/mango/workspace/CS323-Compilers/CS323_Compiler/build/syntax.tab.c"
    break;

  case 50: /* Exp: Exp AND Exp  */
#line 193 "syntax.y"
                  { (yyval.node) = new_interior_node("Exp", 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)); }
#line 1598 "/home/mango/workspace/CS323-Compilers/CS323_Compiler/build/syntax.tab.c"
    break;

  case 51: /* Exp: Exp OR Exp  */
#line 194 "syntax.y"
                 { (yyval.node) = new_interior_node("Exp", 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)); }
#line 1604 "/home/mango/workspace/CS323-Compilers/CS323_Compiler/build/syntax.tab.c"
    break;

  case 52: /* Exp: Exp LT Exp  */
#line 195 "syntax.y"
                 { (yyval.node) = new_interior_node("Exp", 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)); }
#line 1610 "/home/mango/workspace/CS323-Compilers/CS323_Compiler/build/syntax.tab.c"
    break;

  case 53: /* Exp: Exp LE Exp  */
#line 196 "syntax.y"
                 { (yyval.node) = new_interior_node("Exp", 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)); }
#line 1616 "/home/mango/workspace/CS323-Compilers/CS323_Compiler/build/syntax.tab.c"
    break;

  case 54: /* Exp: Exp GT Exp  */
#line 197 "syntax.y"
                 { (yyval.node) = new_interior_node("Exp", 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)); }
#line 1622 "/home/mango/workspace/CS323-Compilers/CS323_Compiler/build/syntax.tab.c"
    break;

  case 55: /* Exp: Exp GE Exp  */
#line 198 "syntax.y"
                 { (yyval.node) = new_interior_node("Exp", 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)); }
#line 1628 "/home/mango/workspace/CS323-Compilers/CS323_Compiler/build/syntax.tab.c"
    break;

  case 56: /* Exp: Exp NE Exp  */
#line 199 "syntax.y"
                 { (yyval.node) = new_interior_node("Exp", 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)); }
#line 1634 "/home/mango/workspace/CS323-Compilers/CS323_Compiler/build/syntax.tab.c"
    break;

  case 57: /* Exp: Exp EQ Exp  */
#line 200 "syntax.y"
                 { (yyval.node) = new_interior_node("Exp", 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)); }
#line 1640 "/home/mango/workspace/CS323-Compilers/CS323_Compiler/build/syntax.tab.c"
    break;

  case 58: /* Exp: Exp PLUS Exp  */
#line 201 "syntax.y"
                   { (yyval.node) = new_interior_node("Exp", 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)); }
#line 1646 "/home/mango/workspace/CS323-Compilers/CS323_Compiler/build/syntax.tab.c"
    break;

  case 59: /* Exp: Exp MINUS Exp  */
#line 202 "syntax.y"
                    { (yyval.node) = new_interior_node("Exp", 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)); }
#line 1652 "/home/mango/workspace/CS323-Compilers/CS323_Compiler/build/syntax.tab.c"
    break;

  case 60: /* Exp: Exp MUL Exp  */
#line 203 "syntax.y"
                  { (yyval.node) = new_interior_node("Exp", 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)); }
#line 1658 "/home/mango/workspace/CS323-Compilers/CS323_Compiler/build/syntax.tab.c"
    break;

  case 61: /* Exp: Exp DIV Exp  */
#line 204 "syntax.y"
                  { (yyval.node) = new_interior_node("Exp", 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)); }
#line 1664 "/home/mango/workspace/CS323-Compilers/CS323_Compiler/build/syntax.tab.c"
    break;

  case 62: /* Exp: LP Exp RP  */
#line 205 "syntax.y"
                { (yyval.node) = new_interior_node("Exp", 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)); }
#line 1670 "/home/mango/workspace/CS323-Compilers/CS323_Compiler/build/syntax.tab.c"
    break;

  case 63: /* Exp: MINUS Exp  */
#line 206 "syntax.y"
                { (yyval.node) = new_interior_node("Exp", 2, (yyvsp[-1].node), (yyvsp[0].node)); }
#line 1676 "/home/mango/workspace/CS323-Compilers/CS323_Compiler/build/syntax.tab.c"
    break;

  case 64: /* Exp: NOT Exp  */
#line 207 "syntax.y"
              { (yyval.node) = new_interior_node("Exp", 2, (yyvsp[-1].node), (yyvsp[0].node)); }
#line 1682 "/home/mango/workspace/CS323-Compilers/CS323_Compiler/build/syntax.tab.c"
    break;

  case 65: /* Exp: ID LP Args RP  */
#line 208 "syntax.y"
                    { (yyval.node) = new_interior_node("Exp", 4, (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)); }
#line 1688 "/home/mango/workspace/CS323-Compilers/CS323_Compiler/build/syntax.tab.c"
    break;

  case 66: /* Exp: ID LP RP  */
#line 209 "syntax.y"
               { (yyval.node) = new_interior_node("Exp", 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)); }
#line 1694 "/home/mango/workspace/CS323-Compilers/CS323_Compiler/build/syntax.tab.c"
    break;

  case 67: /* Exp: Exp LB Exp RB  */
#line 210 "syntax.y"
                    { (yyval.node) = new_interior_node("Exp", 4, (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)); }
#line 1700 "/home/mango/workspace/CS323-Compilers/CS323_Compiler/build/syntax.tab.c"
    break;

  case 68: /* Exp: Exp DOT ID  */
#line 211 "syntax.y"
                 { (yyval.node) = new_interior_node("Exp", 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)); }
#line 1706 "/home/mango/workspace/CS323-Compilers/CS323_Compiler/build/syntax.tab.c"
    break;

  case 69: /* Exp: ID  */
#line 212 "syntax.y"
         { (yyval.node) = new_interior_node("Exp", 1, (yyvsp[0].node)); }
#line 1712 "/home/mango/workspace/CS323-Compilers/CS323_Compiler/build/syntax.tab.c"
    break;

  case 70: /* Exp: INT  */
#line 213 "syntax.y"
          { (yyval.node) = new_interior_node("Exp", 1, (yyvsp[0].node)); }
#line 1718 "/home/mango/workspace/CS323-Compilers/CS323_Compiler/build/syntax.tab.c"
    break;

  case 71: /* Exp: FLOAT  */
#line 214 "syntax.y"
            { (yyval.node) = new_interior_node("Exp", 1, (yyvsp[0].node)); }
#line 1724 "/home/mango/workspace/CS323-Compilers/CS323_Compiler/build/syntax.tab.c"
    break;

  case 72: /* Exp: CHAR  */
#line 215 "syntax.y"
           { (yyval.node) = new_interior_node("Exp", 1, (yyvsp[0].node)); }
#line 1730 "/home/mango/workspace/CS323-Compilers/CS323_Compiler/build/syntax.tab.c"
    break;

  case 73: /* Exp: Exp ERROR Exp  */
#line 216 "syntax.y"
                    { (yyval.node) = new_interior_node("Exp", 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)); ++errors; }
#line 1736 "/home/mango/workspace/CS323-Compilers/CS323_Compiler/build/syntax.tab.c"
    break;

  case 74: /* Exp: ERROR  */
#line 217 "syntax.y"
            { (yyval.node) = new_interior_node("Exp", 1, (yyvsp[0].node)); ++errors; }
#line 1742 "/home/mango/workspace/CS323-Compilers/CS323_Compiler/build/syntax.tab.c"
    break;

  case 75: /* Exp: LP Exp error  */
#line 218 "syntax.y"
                   { 
        (yyval.node) = new_interior_node("Exp", 2, (yyvsp[-2].node), (yyvsp[-1].node)); 
        PRINT_ERROR(MISS_EXP, (yyvsp[-1].node))    
    }
#line 1751 "/home/mango/workspace/CS323-Compilers/CS323_Compiler/build/syntax.tab.c"
    break;

  case 76: /* Exp: ID LP Args error  */
#line 222 "syntax.y"
                       {
        (yyval.node) = new_interior_node("Exp", 3, (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node)); 
        PRINT_ERROR(MISS_RP, (yyvsp[-1].node));
    }
#line 1760 "/home/mango/workspace/CS323-Compilers/CS323_Compiler/build/syntax.tab.c"
    break;

  case 77: /* Exp: ID LP error  */
#line 226 "syntax.y"
                  {
        (yyval.node) = new_interior_node("Exp", 3, (yyvsp[-2].node), (yyvsp[-1].node));
        PRINT_ERROR(MISS_RP, (yyvsp[-1].node));
    }
#line 1769 "/home/mango/workspace/CS323-Compilers/CS323_Compiler/build/syntax.tab.c"
    break;

  case 78: /* Args: Exp COMMA Args  */
#line 231 "syntax.y"
                     { (yyval.node) = new_interior_node("Args", 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)); }
#line 1775 "/home/mango/workspace/CS323-Compilers/CS323_Compiler/build/syntax.tab.c"
    break;

  case 79: /* Args: Exp  */
#line 232 "syntax.y"
          { (yyval.node) = new_interior_node("Args", 1, (yyvsp[0].node)); }
#line 1781 "/home/mango/workspace/CS323-Compilers/CS323_Compiler/build/syntax.tab.c"
    break;


#line 1785 "/home/mango/workspace/CS323-Compilers/CS323_Compiler/build/syntax.tab.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

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
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
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
  ++yynerrs;

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

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
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
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 235 "syntax.y"

void yyerror (const char *s)
{
  #ifdef VERBOSE
  fprintf (stderr, "ERROR: Line %d, %s \"%s\"\n", yylineno, s, yytext);
  #endif
}

int main (int argc, char **argv)
{
    int len = strlen(argv[1]);
    char* tmp = (char *)malloc(sizeof(char) * len);
    strcpy(tmp, argv[1]);
    strcpy(tmp + len - 3, "out");
    file_out = fopen(tmp, "w");
    
    char* tmp_tree = (char *)malloc(sizeof(char) * len);
    strcpy(tmp_tree, argv[1]);
    strcpy(tmp_tree + len - 3, "tre");
    tree_out = fopen(tmp_tree, "w");

    printf("%s\n", tmp);
    printf("%s\n", tmp_tree);

    yyin = fopen(argv[1], "r");
    yyparse();
    
    fclose(file_out);
}
