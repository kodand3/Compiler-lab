/* A Bison parser, made by GNU Bison 3.5.1.  */

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
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "exprtree.y"

    #include <stdlib.h>
    #include <stdio.h>
    #include "exprtree.h"
    #include "exprtree.c"
    #include <string.h>
    #include <math.h>
    #include "printTree.c"
   
    int yylex(void);
    extern FILE *yyin;
    FILE* fout;
    
    int tStack[3], tLast = -1;
    int returnType = -1;
   

#line 88 "y.tab.c"

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
    DECL = 258,
    ENDDECL = 259,
    ID = 260,
    NUM = 261,
    INT = 262,
    STRT = 263,
    MAIN = 264,
    BREAK = 265,
    CONTINUE = 266,
    READ = 267,
    WRITE = 268,
    IF = 269,
    THEN = 270,
    ELSE = 271,
    ENDIF = 272,
    WHILE = 273,
    DO = 274,
    ENDWHILE = 275,
    REPEAT = 276,
    UNTIL = 277,
    RET = 278,
    STRC = 279,
    BGN = 280,
    END = 281,
    BREAKPOINT = 282,
    AND = 283,
    OR = 284,
    TUPLE = 285
  };
#endif
/* Tokens.  */
#define DECL 258
#define ENDDECL 259
#define ID 260
#define NUM 261
#define INT 262
#define STRT 263
#define MAIN 264
#define BREAK 265
#define CONTINUE 266
#define READ 267
#define WRITE 268
#define IF 269
#define THEN 270
#define ELSE 271
#define ENDIF 272
#define WHILE 273
#define DO 274
#define ENDWHILE 275
#define REPEAT 276
#define UNTIL 277
#define RET 278
#define STRC 279
#define BGN 280
#define END 281
#define BREAKPOINT 282
#define AND 283
#define OR 284
#define TUPLE 285

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 18 "exprtree.y"

       struct ASTNode *node;
       struct Paramstruct *paramlist;
       struct Lsymbol *lentry;
       char *sval;
       int nval;
   

#line 209 "y.tab.c"

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
#define YYFINAL  13
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   454

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  49
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  32
/* YYNRULES -- Number of rules.  */
#define YYNRULES  85
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  199

#define YYUNDEFTOK  2
#define YYMAXUTOK   285


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
       2,     2,     2,    33,     2,     2,     2,    39,    48,     2,
      44,    45,    37,    35,    41,    36,     2,    38,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    40,
      31,    34,    32,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    42,     2,    43,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    46,     2,    47,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    39,    39,    54,    66,    79,    79,    80,    80,    81,
      82,    82,    84,    85,    86,    87,    88,    96,    97,    99,
     149,   201,   207,   209,   219,   220,   223,   223,   224,   224,
     225,   226,   226,   228,   229,   237,   248,   261,   267,   268,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   284,   285,   288,   291,   297,   302,   307,   312,   315,
     320,   325,   330,   335,   344,   347,   350,   353,   356,   359,
     360,   363,   366,   369,   372,   375,   378,   381,   384,   387,
     388,   392,   393,   396,   404,   405
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "DECL", "ENDDECL", "ID", "NUM", "INT",
  "STRT", "MAIN", "BREAK", "CONTINUE", "READ", "WRITE", "IF", "THEN",
  "ELSE", "ENDIF", "WHILE", "DO", "ENDWHILE", "REPEAT", "UNTIL", "RET",
  "STRC", "BGN", "END", "BREAKPOINT", "AND", "OR", "TUPLE", "'<'", "'>'",
  "'!'", "'='", "'+'", "'-'", "'*'", "'/'", "'%'", "';'", "','", "'['",
  "']'", "'('", "')'", "'{'", "'}'", "'&'", "$accept", "program",
  "GDeclBlock", "GDeclList", "GDecl", "GIdList", "Gid", "FDefBlock",
  "FDef", "ParamList", "Param", "Type", "LDeclBlock", "LDeclList", "LDecl",
  "LIdList", "Lid", "MainBlock", "Body", "Slist", "Stmt", "Assignable",
  "InputStmt", "OutputStmt", "AsgStmt", "Ifstmt", "Whilestmt",
  "Repeatstmt", "Dowhilestmt", "ReturnStmt", "expr", "ArgList", YY_NULLPTR
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
     285,    60,    62,    33,    61,    43,    45,    42,    47,    37,
      59,    44,    91,    93,    40,    41,   123,   125,    38
};
# endif

#define YYPACT_NINF (-73)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      13,    42,    45,    51,    22,   -73,   -73,   -73,   -73,    62,
     -73,     4,    16,   -73,    45,    22,   -73,    68,   -73,   -73,
     -73,    30,    75,    65,   -73,    38,   -73,   -73,    49,    94,
       0,   -73,   -73,     4,    63,    95,    71,   -73,    34,   -73,
       5,   -73,     8,    40,   -73,    95,   -73,   -73,   115,   -73,
      83,   235,   100,    84,    89,   -73,   -73,   -73,     5,    88,
     -73,    98,    90,    96,    97,   101,   102,   104,   235,   235,
     113,   111,   147,   235,   -73,   121,   -73,   -73,   -73,   -73,
     -73,   -73,   -73,   -73,   109,   -73,     8,    87,   -73,   -73,
     -73,   113,   -73,   -73,     7,   113,   113,   113,   255,   174,
      57,   -73,   -73,   113,     7,   -73,   368,   -73,   -73,   -73,
     134,   113,   -73,   100,   116,   -73,     5,   342,   117,   252,
     267,   282,   125,   130,   113,   297,   -73,   113,   113,   105,
     110,   142,   144,   113,   113,   113,   113,   113,   -73,   -73,
     381,   133,   -73,   -73,   140,   143,   149,   175,   179,   113,
     113,   394,    53,   -73,   415,   406,   113,    -1,   113,    -1,
     113,   113,   -24,   -24,   -73,   -73,   -73,   -73,   -73,   113,
     -73,   -73,   235,   235,   312,   327,   113,   -73,    -1,    -1,
      -1,    -1,   355,   154,   194,   -14,   160,   394,   -73,   235,
     162,   163,   -73,   -73,   215,   -73,   -73,   169,   -73
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     0,     4,     6,    24,    25,     0,
       8,     0,     0,     1,    24,     0,    18,     0,     3,     5,
       7,    12,     0,     0,    11,     0,    17,     2,     0,     0,
       0,    16,     9,     0,     0,     0,     0,    15,     0,    22,
       0,    10,     0,     0,    13,     0,    14,    33,     0,    23,
       0,     0,     0,     0,     0,    21,    34,    27,     0,     0,
      29,    51,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    39,     0,    40,    41,    42,    43,
      44,    47,    48,    49,     0,    36,     0,     0,    32,    26,
      28,     0,    45,    46,     0,     0,     0,     0,     0,     0,
      51,    78,    79,     0,     0,    80,     0,    50,    54,    38,
      49,     0,    35,     0,     0,    30,     0,     0,     0,     0,
       0,     0,     0,     0,    85,     0,    81,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    63,    37,
       0,     0,    20,    31,    52,     0,     0,     0,     0,     0,
       0,    84,     0,    69,    77,    76,     0,    70,     0,    71,
       0,     0,    64,    65,    66,    67,    68,    57,    19,     0,
      55,    56,     0,     0,     0,     0,     0,    82,    72,    73,
      74,    75,     0,     0,     0,     0,     0,    83,    53,     0,
       0,     0,    62,    61,     0,    59,    60,     0,    58
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -73,   -73,   -73,   -73,   185,   -73,   177,   -73,   201,   183,
     178,    67,   136,   -73,   165,   -73,   -57,    17,   -46,   -65,
     -71,   -51,   -73,   -73,   -73,   -73,   -73,   -73,   -73,   146,
     -72,   -73
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,     4,     9,    10,    23,    24,    15,    16,    38,
      39,    40,    52,    59,    60,    87,    49,     5,    53,    73,
      74,   105,    76,    77,    78,    79,    80,    81,    82,    83,
     106,   152
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      75,    88,   109,    98,    99,   173,    84,     7,     8,    21,
      47,    50,    61,   135,   136,   137,     1,    75,    75,   117,
       2,    18,    75,   119,   120,   121,   192,   109,   109,    14,
       8,   125,    27,    51,   133,   134,   135,   136,   137,   140,
     114,    22,    48,   118,    72,    37,     6,    75,    75,     7,
       8,    13,   151,   126,    12,   154,   155,   157,   159,   143,
      25,   162,   163,   164,   165,   166,    19,   141,    11,     7,
       8,    17,    29,    28,    30,    45,    11,   174,   175,    46,
      31,    45,    17,    34,   178,    54,   179,    57,   180,   181,
       7,     8,    89,    35,   176,     7,     8,   182,   177,    91,
      36,   124,     7,     8,   187,    32,    33,   183,   184,    42,
     100,   101,   109,   109,    44,   100,   101,    58,   100,   101,
      56,    75,    75,   109,   194,    51,    58,   115,   116,   102,
      92,    85,    75,    75,   102,    86,    93,   102,    75,   156,
      91,    94,    72,    75,   158,    95,    96,    72,    97,   103,
      72,   107,   108,   104,   103,   111,   112,   103,   104,    61,
     139,   104,   145,   142,    62,    63,    64,    65,    66,   149,
     189,   190,    67,    68,   150,    69,   160,    70,   161,    61,
     168,    71,   169,   170,    62,    63,    64,    65,    66,   171,
     172,    72,    67,    68,    20,    69,   123,    70,   173,    61,
     193,    71,   195,   196,    62,    63,    64,    65,    66,   198,
      41,    72,    67,    68,   191,    69,    26,    70,    43,   110,
      61,    71,   113,    55,    90,    62,    63,    64,    65,    66,
       0,    72,   197,    67,    68,     0,    69,     0,    70,     0,
      61,     0,    71,     0,     0,    62,    63,    64,    65,    66,
       0,     0,    72,    67,    68,     0,    69,     0,    70,     0,
      61,     0,    71,     0,     0,    62,    63,    64,    65,    66,
       0,     0,    72,   122,    68,     0,    69,     0,    70,     0,
     127,   128,    71,   129,   130,   131,   132,   133,   134,   135,
     136,   137,    72,     0,     0,   127,   128,   146,   129,   130,
     131,   132,   133,   134,   135,   136,   137,     0,     0,     0,
     127,   128,   147,   129,   130,   131,   132,   133,   134,   135,
     136,   137,     0,     0,     0,   127,   128,   148,   129,   130,
     131,   132,   133,   134,   135,   136,   137,     0,     0,     0,
     127,   128,   153,   129,   130,   131,   132,   133,   134,   135,
     136,   137,     0,     0,     0,   127,   128,   185,   129,   130,
     131,   132,   133,   134,   135,   136,   137,     0,     0,     0,
     127,   128,   186,   129,   130,   131,   132,   133,   134,   135,
     136,   137,     0,   127,   128,   144,   129,   130,   131,   132,
     133,   134,   135,   136,   137,     0,   127,   128,   188,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   127,
     128,     0,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   167,   127,   128,     0,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   127,     0,     0,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   129,   130,   131,   132,
     133,   134,   135,   136,   137
};

static const yytype_int16 yycheck[] =
{
      51,    58,    73,    68,    69,    19,    52,     7,     8,     5,
       5,     3,     5,    37,    38,    39,     3,    68,    69,    91,
       7,     4,    73,    95,    96,    97,    40,    98,    99,     7,
       8,   103,    15,    25,    35,    36,    37,    38,    39,   111,
      86,    37,    37,    94,    37,    45,     4,    98,    99,     7,
       8,     0,   124,   104,     9,   127,   128,   129,   130,   116,
      44,   133,   134,   135,   136,   137,     4,   113,     1,     7,
       8,     4,    42,     5,    44,    41,     9,   149,   150,    45,
       5,    41,    15,    45,   156,    45,   158,     4,   160,   161,
       7,     8,     4,    44,    41,     7,     8,   169,    45,    42,
       6,    44,     7,     8,   176,    40,    41,   172,   173,    46,
       5,     6,   183,   184,    43,     5,     6,    50,     5,     6,
       5,   172,   173,   194,   189,    25,    59,    40,    41,    24,
      40,    47,   183,   184,    24,    46,    40,    24,   189,    34,
      42,    44,    37,   194,    34,    44,    44,    37,    44,    44,
      37,    40,     5,    48,    44,    34,    47,    44,    48,     5,
      26,    48,    45,    47,    10,    11,    12,    13,    14,    44,
      16,    17,    18,    19,    44,    21,    34,    23,    34,     5,
      47,    27,    42,    40,    10,    11,    12,    13,    14,    40,
      15,    37,    18,    19,     9,    21,    22,    23,    19,     5,
      40,    27,    40,    40,    10,    11,    12,    13,    14,    40,
      33,    37,    18,    19,    20,    21,    15,    23,    35,    73,
       5,    27,    86,    45,    59,    10,    11,    12,    13,    14,
      -1,    37,    17,    18,    19,    -1,    21,    -1,    23,    -1,
       5,    -1,    27,    -1,    -1,    10,    11,    12,    13,    14,
      -1,    -1,    37,    18,    19,    -1,    21,    -1,    23,    -1,
       5,    -1,    27,    -1,    -1,    10,    11,    12,    13,    14,
      -1,    -1,    37,    18,    19,    -1,    21,    -1,    23,    -1,
      28,    29,    27,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    37,    -1,    -1,    28,    29,    45,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    -1,    -1,    -1,
      28,    29,    45,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    -1,    -1,    -1,    28,    29,    45,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    -1,    -1,    -1,
      28,    29,    45,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    -1,    -1,    -1,    28,    29,    45,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    -1,    -1,    -1,
      28,    29,    45,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    -1,    28,    29,    43,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    -1,    28,    29,    43,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    28,
      29,    -1,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    28,    29,    -1,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    28,    -1,    -1,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    31,    32,    33,    34,
      35,    36,    37,    38,    39
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     7,    50,    51,    66,     4,     7,     8,    52,
      53,    60,     9,     0,     7,    56,    57,    60,    66,     4,
      53,     5,    37,    54,    55,    44,    57,    66,     5,    42,
      44,     5,    40,    41,    45,    44,     6,    45,    58,    59,
      60,    55,    46,    58,    43,    41,    45,     5,    37,    65,
       3,    25,    61,    67,    45,    59,     5,     4,    60,    62,
      63,     5,    10,    11,    12,    13,    14,    18,    19,    21,
      23,    27,    37,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    67,    47,    46,    64,    65,     4,
      63,    42,    40,    40,    44,    44,    44,    44,    68,    68,
       5,     6,    24,    44,    48,    70,    79,    40,     5,    69,
      78,    34,    47,    61,    67,    40,    41,    79,    70,    79,
      79,    79,    18,    22,    44,    79,    70,    28,    29,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    26,
      79,    67,    47,    65,    43,    45,    45,    45,    45,    44,
      44,    79,    80,    45,    79,    79,    34,    79,    34,    79,
      34,    34,    79,    79,    79,    79,    79,    40,    47,    42,
      40,    40,    15,    19,    79,    79,    41,    45,    79,    79,
      79,    79,    79,    68,    68,    45,    45,    79,    43,    16,
      17,    20,    40,    40,    68,    40,    40,    17,    40
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    49,    50,    50,    50,    51,    51,    52,    52,    53,
      54,    54,    55,    55,    55,    55,    55,    56,    56,    57,
      57,    58,    58,    59,    60,    60,    61,    61,    62,    62,
      63,    64,    64,    65,    65,    66,    66,    67,    68,    68,
      69,    69,    69,    69,    69,    69,    69,    69,    69,    69,
      69,    70,    70,    70,    70,    71,    72,    73,    74,    74,
      75,    76,    77,    78,    79,    79,    79,    79,    79,    79,
      79,    79,    79,    79,    79,    79,    79,    79,    79,    79,
      79,    79,    79,    80,    80,    80
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     3,     2,     1,     3,     2,     2,     1,     3,
       3,     1,     1,     4,     4,     3,     2,     2,     1,     9,
       8,     3,     1,     2,     1,     1,     3,     2,     2,     1,
       3,     3,     1,     1,     2,     8,     7,     4,     2,     1,
       1,     1,     1,     1,     1,     2,     2,     1,     1,     1,
       2,     1,     4,     7,     2,     5,     5,     4,    10,     8,
       8,     7,     7,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     4,     4,     4,     4,     3,     3,     1,     1,
       1,     2,     4,     3,     1,     0
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
#line 39 "exprtree.y"
                                           {
                (yyval.node) = TreeCreate(-1, N_SLIST, NULL, (Constant) 0, NULL, (yyvsp[-1].node), (yyvsp[0].node), NULL);
                printf("Parsing complete\n");
                // printGST();
                printT((yyval.node), 0);
   
                fprintf(fout, "0\n2056\n0\n0\n0\n0\n0\n0\nMOV SP, %d\nPUSH R0\nCALL F0\nMOV R0, \"Exit\"\nPUSH R0\nMOV R0, 10\nPUSH R0\nPUSH R0\nPUSH R0\nPUSH R0\nCALL 0\n", 4095+gstSize);
                // R0 is pushed for storing return value of main
                // trying to store it outside stack will cause error
                
                codeGen((yyval.node), fout);
                fclose(fout);
                printGST();
                exit(1);
            }
#line 1578 "y.tab.c"
    break;

  case 3:
#line 54 "exprtree.y"
                                 {
                (yyval.node) = (yyvsp[0].node); 
                printf("Parsing complete\n");
                printGST();
                printT((yyval.node), 0);
   
                fprintf(fout, "0\n2056\n0\n0\n0\n0\n0\n0\nMOV SP, %d\nPUSH R0\nCALL F0\nMOV R0, \"Exit\"\nPUSH R0\nMOV R0, 10\nPUSH R0\nPUSH R0\nPUSH R0\nPUSH R0\nCALL 0\n", 4095 + gstSize);
       
                codeGen((yyval.node), fout);
                fclose(fout);
                exit(1);
            }
#line 1595 "y.tab.c"
    break;

  case 4:
#line 66 "exprtree.y"
                      {
                (yyval.node) = (yyvsp[0].node); 
                printf("Parsing complete\n");
                printT((yyval.node), 0);
   
                fprintf(fout, "0\n2056\n0\n0\n0\n0\n0\n0\nMOV SP, %d\nPUSH R0\nCALL F0\nMOV R0, \"Exit\"\nPUSH R0\nMOV R0, 10\nPUSH R0\nPUSH R0\nPUSH R0\nPUSH R0\nCALL 0\n", 4095 + gstSize);
       
                codeGen((yyval.node), fout);
                fclose(fout);
                exit(1);
            }
#line 1611 "y.tab.c"
    break;

  case 9:
#line 81 "exprtree.y"
                           {--tLast;}
#line 1617 "y.tab.c"
    break;

  case 12:
#line 84 "exprtree.y"
           {GInstall((yyvsp[0].sval), tStack[tLast], 1, NULL);}
#line 1623 "y.tab.c"
    break;

  case 13:
#line 85 "exprtree.y"
                       {GInstall((yyvsp[-3].sval), tStack[tLast], (yyvsp[-1].nval), NULL);}
#line 1629 "y.tab.c"
    break;

  case 14:
#line 86 "exprtree.y"
                             {GInstall((yyvsp[-3].sval), tStack[tLast], 0, (yyvsp[-1].paramlist)); LST = NULL;}
#line 1635 "y.tab.c"
    break;

  case 15:
#line 87 "exprtree.y"
                   {GInstall ((yyvsp[-2].sval), tStack[tLast], 0, NULL); LST = NULL;}
#line 1641 "y.tab.c"
    break;

  case 16:
#line 88 "exprtree.y"
               {
            if (tStack[tLast] == T_STR)
                GInstall((yyvsp[0].sval), T_STRP, 1, NULL);
            else if (tStack[tLast] == T_INT)
                GInstall((yyvsp[0].sval), T_INTP, 1, NULL);
        }
#line 1652 "y.tab.c"
    break;

  case 17:
#line 96 "exprtree.y"
                             {(yyval.node) = TreeCreate(-1, N_SLIST, NULL, (Constant) 0, NULL, (yyvsp[-1].node), (yyvsp[0].node), NULL);}
#line 1658 "y.tab.c"
    break;

  case 18:
#line 97 "exprtree.y"
                   {(yyval.node) = (yyvsp[0].node);}
#line 1664 "y.tab.c"
    break;

  case 19:
#line 99 "exprtree.y"
                                                           {
             Gsymbol *x = GLookup((yyvsp[-7].sval));
             if (x == NULL || x->size != 0) {
                 printf("Function not declared: %s\n", (yyvsp[-7].sval));
                 exit(1);
             } else if ( x->flabel != -1 ) {
                 printf("Func redefined: %s\n", (yyvsp[-7].sval));
                 exit(1);
             } else if (tStack[tLast] != x->type || x->type != (yyvsp[-1].node)->type) {
                 printf("Func decl|def|body type mismatch: %s\n", (yyvsp[-7].sval));
                 exit(1);
             } 
   
             Paramstruct *t1 = (yyvsp[-5].paramlist), *t2 = x->paramlist;
             int p = 0;
             while(t1 != NULL && t2 != NULL) {
                 if (strcmp(t1->name, t2->name) || t1->type != t2->type) {
                     printf("Func parameter mismatch: %s\n", (yyvsp[-7].sval));
                     exit(1);
                 }
                 t1 = t1->next; t2 = t2->next; p++;
             }
   
             if(t1 == NULL && t2 == NULL) {
                 // binding assignment
                 Lsymbol *t = LST;
                 for (int i = 0; i < p; i++) {
                     t->binding = -(i + 3);
                     t = t->next;
                 }
                 p = 1;
                 while (t != NULL) {
                     t->binding = p++;
                     t = t->next;
                 }
   
                 (yyvsp[-1].node)->name = (yyvsp[-7].sval);
                 (yyvsp[-1].node)->Gentry = x;
                 (yyvsp[-1].node)->Lentry = LST;
                 (yyval.node) = (yyvsp[-1].node);
   
                 x->flabel = ++fcount;
                 LST = NULL;
                 --tLast;
                 returnType = -1;
             } else {
                 printf("Func parameter mismatch: %s\n", (yyvsp[-7].sval));
                 exit(1);
             }
         }
#line 1719 "y.tab.c"
    break;

  case 20:
#line 149 "exprtree.y"
                                                {
             Gsymbol *x = GLookup((yyvsp[-6].sval));
             if (x == NULL || x->size != 0) {
                 printf("Function not declared: %s\n", (yyvsp[-6].sval));
                 exit(1);
             } else if ( x->flabel != -1 ) {
                 printf("Func redefined: %s\n", (yyvsp[-6].sval));
                 exit(1);
             } else if (tStack[tLast] != x->type || x->type != (yyvsp[-1].node)->type) {
                 printf("Func decl|def|body type mismatch: %s\n", (yyvsp[-6].sval));
                 exit(1);
             } 
   
             Paramstruct *t1 = (yyvsp[-4].paramlist), *t2 = x->paramlist;
             int p = 0;
             while(t1 != NULL && t2 != NULL) {
                 if (strcmp(t1->name, t2->name) || t1->type != t2->type) {
                     printf("Func parameter mismatch: %s\n", (yyvsp[-6].sval));
                     exit(1);
                 }
                 t1 = t1->next; t2 = t2->next; p++;
             }
   
             if(t1 == NULL && t2 == NULL) {
                 // binding assignment
                 Lsymbol *t = LST;
                 for (int i = 0; i < p; i++) {
                     t->binding = -(i + 3);
                     t = t->next;
                 }
                 p = 1;
                 while (t != NULL) {
                     t->binding = p++;
                     t = t->next;
                 }
   
                 (yyvsp[-1].node)->name = (yyvsp[-6].sval);
                 (yyvsp[-1].node)->Gentry = x;
                 (yyvsp[-1].node)->Lentry = LST;
                 (yyval.node) = (yyvsp[-1].node);
                 
                 x->flabel = 1;
                 LST = NULL;
                 --tLast;
                 returnType = -1;
             } else {
                 printf("Func parameter mismatch: %s\n", (yyvsp[-6].sval));
                 exit(1);
             }
         }
#line 1774 "y.tab.c"
    break;

  case 21:
#line 201 "exprtree.y"
                                  {
                  Paramstruct *t = (yyvsp[-2].paramlist);
                  while(t->next != NULL)
                      t = t->next;
                  t->next = (yyvsp[0].paramlist);
              }
#line 1785 "y.tab.c"
    break;

  case 22:
#line 207 "exprtree.y"
                    {(yyval.paramlist) = (yyvsp[0].paramlist);}
#line 1791 "y.tab.c"
    break;

  case 23:
#line 209 "exprtree.y"
                   {
              (yyval.paramlist) = (Paramstruct *)malloc(sizeof(Paramstruct));
              (yyval.paramlist)->name = (yyvsp[0].lentry)->name;
              (yyval.paramlist)->type = ((yyvsp[0].lentry)->type == T_STRP || (yyvsp[0].lentry)->type == T_INTP)?(T_INT):((yyvsp[0].lentry)->type);
              (yyval.paramlist)->next = NULL;
   
              tLast--;
          }
#line 1804 "y.tab.c"
    break;

  case 24:
#line 219 "exprtree.y"
             {tStack[++tLast] = T_INT;}
#line 1810 "y.tab.c"
    break;

  case 25:
#line 220 "exprtree.y"
              {tStack[++tLast] = T_STR;}
#line 1816 "y.tab.c"
    break;

  case 30:
#line 225 "exprtree.y"
                           {--tLast;}
#line 1822 "y.tab.c"
    break;

  case 33:
#line 228 "exprtree.y"
           {(yyval.lentry) = LInstall((yyvsp[0].sval), tStack[tLast]);}
#line 1828 "y.tab.c"
    break;

  case 34:
#line 229 "exprtree.y"
               {
            if (tStack[tLast] == T_STR)
                (yyval.lentry) = LInstall((yyvsp[0].sval), T_STRP);
            else if (tStack[tLast] == T_INT)
                (yyval.lentry) = LInstall((yyvsp[0].sval), T_INTP);
        }
#line 1839 "y.tab.c"
    break;

  case 35:
#line 237 "exprtree.y"
                                                       {
                  int p = 1;
                  for (Lsymbol *l = LST; l != NULL; l = l->next)
                      l->binding = p++;
   
                  (yyvsp[-1].node)->nodetype = N_MAIN;
                  (yyvsp[-1].node)->Lentry = LST;
                  LST = NULL;
                  returnType = -1;
                  (yyval.node) = (yyvsp[-1].node);
              }
#line 1855 "y.tab.c"
    break;

  case 36:
#line 248 "exprtree.y"
                                            {
                  int p = 1;
                  for (Lsymbol *l = LST; l != NULL; l = l->next)
                      l->binding = p++;
   
                  (yyvsp[-1].node)->nodetype = N_MAIN;
                  (yyvsp[-1].node)->Lentry = LST;
                  LST = NULL;
                  returnType = -1;
                  (yyval.node) = (yyvsp[-1].node);
              }
#line 1871 "y.tab.c"
    break;

  case 37:
#line 261 "exprtree.y"
                                  {
             // $$ = $2; $$->nodetype = N_BODY; $$->type = returnType;
             (yyval.node) = TreeCreate(returnType, N_BODY, NULL, (Constant) 0, NULL, (yyvsp[-2].node), (yyvsp[-1].node), NULL);
         }
#line 1880 "y.tab.c"
    break;

  case 38:
#line 267 "exprtree.y"
                     {(yyval.node) = TreeCreate(-1, N_SLIST, NULL, (Constant) 0, NULL, (yyvsp[-1].node), (yyvsp[0].node), NULL);}
#line 1886 "y.tab.c"
    break;

  case 39:
#line 268 "exprtree.y"
               {(yyval.node) = (yyvsp[0].node);}
#line 1892 "y.tab.c"
    break;

  case 40:
#line 271 "exprtree.y"
                   {(yyval.node) = (yyvsp[0].node);}
#line 1898 "y.tab.c"
    break;

  case 41:
#line 272 "exprtree.y"
                    {(yyval.node) = (yyvsp[0].node);}
#line 1904 "y.tab.c"
    break;

  case 42:
#line 273 "exprtree.y"
                 {(yyval.node) = (yyvsp[0].node);}
#line 1910 "y.tab.c"
    break;

  case 43:
#line 274 "exprtree.y"
                {(yyval.node) = (yyvsp[0].node);}
#line 1916 "y.tab.c"
    break;

  case 44:
#line 275 "exprtree.y"
                   {(yyval.node) = (yyvsp[0].node);}
#line 1922 "y.tab.c"
    break;

  case 45:
#line 276 "exprtree.y"
                   {(yyval.node) = TreeCreate(-1, N_BREAK, NULL, (Constant)0, NULL, NULL, NULL, NULL);}
#line 1928 "y.tab.c"
    break;

  case 46:
#line 277 "exprtree.y"
                      {(yyval.node) = TreeCreate(-1, N_CONTINUE, NULL, (Constant)0, NULL, NULL, NULL, NULL);}
#line 1934 "y.tab.c"
    break;

  case 47:
#line 278 "exprtree.y"
                    {(yyval.node) = (yyvsp[0].node);}
#line 1940 "y.tab.c"
    break;

  case 48:
#line 279 "exprtree.y"
                     {(yyval.node) = (yyvsp[0].node);}
#line 1946 "y.tab.c"
    break;

  case 49:
#line 280 "exprtree.y"
                    {(yyval.node) = (yyvsp[0].node);}
#line 1952 "y.tab.c"
    break;

  case 50:
#line 281 "exprtree.y"
                        {(yyval.node) = TreeCreate(-1, N_BRKP, NULL, (Constant) 0, NULL, NULL, NULL, NULL);}
#line 1958 "y.tab.c"
    break;

  case 51:
#line 284 "exprtree.y"
                  {(yyval.node) = TreeCreate(-1, N_ID, (yyvsp[0].sval), (Constant)0, NULL, NULL, NULL, NULL);}
#line 1964 "y.tab.c"
    break;

  case 52:
#line 285 "exprtree.y"
                               {
                   (yyval.node) = TreeCreate(-1, N_ID, (yyvsp[-3].sval), (Constant)0, NULL, (yyvsp[-1].node), NULL, NULL);
               }
#line 1972 "y.tab.c"
    break;

  case 53:
#line 288 "exprtree.y"
                                            {
                   (yyval.node) = TreeCreate(-1, N_ID, (yyvsp[-6].sval), (Constant)0, NULL, (yyvsp[-4].node), (yyvsp[-1].node), NULL);
               }
#line 1980 "y.tab.c"
    break;

  case 54:
#line 291 "exprtree.y"
                      {
                   // $$ = createTree(0, -1, $2, 27, NULL, NULL, NULL);
                   (yyval.node) = TreeCreate(-1, N_PTR, (yyvsp[0].sval), (Constant)0, NULL, NULL, NULL, NULL);
               }
#line 1989 "y.tab.c"
    break;

  case 55:
#line 297 "exprtree.y"
                                          {
                   (yyval.node) = TreeCreate(-1, N_READ, NULL, (Constant) 0, NULL, (yyvsp[-2].node), NULL, NULL);
              }
#line 1997 "y.tab.c"
    break;

  case 56:
#line 302 "exprtree.y"
                                      {
                   (yyval.node) = TreeCreate(-1, N_WRITE, NULL, (Constant) 0, NULL, (yyvsp[-2].node), NULL, NULL);
               }
#line 2005 "y.tab.c"
    break;

  case 57:
#line 307 "exprtree.y"
                                    {
               (yyval.node) = TreeCreate(-1, N_ASGN, NULL, (Constant) 0, NULL, (yyvsp[-3].node), (yyvsp[-1].node), NULL);
            }
#line 2013 "y.tab.c"
    break;

  case 58:
#line 312 "exprtree.y"
                                                           {
               (yyval.node) = TreeCreate(-1, N_IF, NULL, (Constant) 0, NULL, (yyvsp[-7].node), (yyvsp[-4].node), (yyvsp[-2].node));
           }
#line 2021 "y.tab.c"
    break;

  case 59:
#line 315 "exprtree.y"
                                                {
               (yyval.node) = TreeCreate(-1, N_IF, NULL, (Constant) 0, NULL, (yyvsp[-5].node), (yyvsp[-2].node), NULL);
           }
#line 2029 "y.tab.c"
    break;

  case 60:
#line 320 "exprtree.y"
                                                       {
                  (yyval.node) = TreeCreate(-1, N_WHILE, NULL, (Constant) 0, NULL, (yyvsp[-5].node), (yyvsp[-2].node), NULL);
              }
#line 2037 "y.tab.c"
    break;

  case 61:
#line 325 "exprtree.y"
                                                   {
                   (yyval.node) = TreeCreate(-1, N_REPEAT, NULL, (Constant) 0, NULL, (yyvsp[-5].node), (yyvsp[-2].node), NULL);
               }
#line 2045 "y.tab.c"
    break;

  case 62:
#line 330 "exprtree.y"
                                                {
                   (yyval.node) = TreeCreate(-1, N_DOWHILE, NULL, (Constant) 0, NULL, (yyvsp[-5].node), (yyvsp[-2].node), NULL);
                }
#line 2053 "y.tab.c"
    break;

  case 63:
#line 335 "exprtree.y"
                            {
                   if (returnType != -1 && returnType != (yyvsp[-1].node)->type) {
                       printf("Return stmt type mismatch\n");
                       exit(1);
                   } 
                   returnType = (yyvsp[-1].node)->type;
                   (yyval.node) = TreeCreate(returnType, N_RET, NULL, (Constant) 0, NULL, (yyvsp[-1].node), NULL, NULL);
               }
#line 2066 "y.tab.c"
    break;

  case 64:
#line 344 "exprtree.y"
                          {
               (yyval.node) = TreeCreate(T_INT, N_PLUS, NULL, (Constant) 0, NULL, (yyvsp[-2].node), (yyvsp[0].node), NULL);
           }
#line 2074 "y.tab.c"
    break;

  case 65:
#line 347 "exprtree.y"
                         {
               (yyval.node) = TreeCreate(T_INT, N_MINUS, NULL, (Constant) 0, NULL, (yyvsp[-2].node), (yyvsp[0].node), NULL);
           }
#line 2082 "y.tab.c"
    break;

  case 66:
#line 350 "exprtree.y"
                         {
               (yyval.node) = TreeCreate(T_INT, N_MUL, NULL, (Constant) 0, NULL, (yyvsp[-2].node), (yyvsp[0].node), NULL);
           }
#line 2090 "y.tab.c"
    break;

  case 67:
#line 353 "exprtree.y"
                         {
               (yyval.node) = TreeCreate(T_INT, N_DIV, NULL, (Constant) 0, NULL, (yyvsp[-2].node), (yyvsp[0].node), NULL);
           }
#line 2098 "y.tab.c"
    break;

  case 68:
#line 356 "exprtree.y"
                         {
               (yyval.node) = TreeCreate(T_INT, N_MOD, NULL, (Constant) 0, NULL, (yyvsp[-2].node), (yyvsp[0].node), NULL);
           }
#line 2106 "y.tab.c"
    break;

  case 69:
#line 359 "exprtree.y"
                         {(yyval.node) = (yyvsp[-1].node);}
#line 2112 "y.tab.c"
    break;

  case 70:
#line 360 "exprtree.y"
                         {
               (yyval.node) = TreeCreate(T_BOOL, N_LT, NULL, (Constant) 0, NULL, (yyvsp[-2].node), (yyvsp[0].node), NULL);
           }
#line 2120 "y.tab.c"
    break;

  case 71:
#line 363 "exprtree.y"
                         {
               (yyval.node) = TreeCreate(T_BOOL, N_GT, NULL, (Constant) 0, NULL, (yyvsp[-2].node), (yyvsp[0].node), NULL);
           }
#line 2128 "y.tab.c"
    break;

  case 72:
#line 366 "exprtree.y"
                             {
               (yyval.node) = TreeCreate(T_BOOL, N_LE, NULL, (Constant) 0, NULL, (yyvsp[-3].node), (yyvsp[0].node), NULL);
           }
#line 2136 "y.tab.c"
    break;

  case 73:
#line 369 "exprtree.y"
                             {
               (yyval.node) = TreeCreate(T_BOOL, N_GE, NULL, (Constant) 0, NULL, (yyvsp[-3].node), (yyvsp[0].node), NULL);
           }
#line 2144 "y.tab.c"
    break;

  case 74:
#line 372 "exprtree.y"
                             {
               (yyval.node) = TreeCreate(T_BOOL, N_NE, NULL, (Constant) 0, NULL, (yyvsp[-3].node), (yyvsp[0].node), NULL);
           }
#line 2152 "y.tab.c"
    break;

  case 75:
#line 375 "exprtree.y"
                             {
               (yyval.node) = TreeCreate(T_BOOL, N_EQ, NULL, (Constant) 0, NULL, (yyvsp[-3].node), (yyvsp[0].node), NULL);
           }
#line 2160 "y.tab.c"
    break;

  case 76:
#line 378 "exprtree.y"
                        {
               (yyval.node) = TreeCreate(T_BOOL, N_OR, NULL, (Constant) 0, NULL, (yyvsp[-2].node), (yyvsp[0].node), NULL);
           }
#line 2168 "y.tab.c"
    break;

  case 77:
#line 381 "exprtree.y"
                         {
               (yyval.node) = TreeCreate(T_BOOL, N_AND, NULL, (Constant) 0, NULL, (yyvsp[-2].node), (yyvsp[0].node), NULL);
           }
#line 2176 "y.tab.c"
    break;

  case 78:
#line 384 "exprtree.y"
                 {
               (yyval.node)=TreeCreate(T_INT, N_CONST, NULL, (Constant) (yyvsp[0].nval), NULL, NULL, NULL, NULL);  
           }
#line 2184 "y.tab.c"
    break;

  case 79:
#line 387 "exprtree.y"
                {(yyval.node) = (yyvsp[0].node);}
#line 2190 "y.tab.c"
    break;

  case 80:
#line 388 "exprtree.y"
                      {
               (yyvsp[0].node)->value.intval = 1;
               (yyval.node) = (yyvsp[0].node);
           }
#line 2199 "y.tab.c"
    break;

  case 81:
#line 392 "exprtree.y"
                          {(yyvsp[0].node)->type = T_INT; (yyval.node) = (yyvsp[0].node);}
#line 2205 "y.tab.c"
    break;

  case 82:
#line 393 "exprtree.y"
                              {(yyval.node) = TreeCreate(-1, N_FUNC, (yyvsp[-3].sval), (Constant) 0, (yyvsp[-1].node), NULL, NULL, NULL);}
#line 2211 "y.tab.c"
    break;

  case 83:
#line 396 "exprtree.y"
                             {
               ASTNode *t = (yyvsp[-2].node);
               while (t->ptr3 != NULL)
                   t = t->ptr3;
               t->ptr3 = (yyvsp[0].node);
               (yyvsp[0].node)->ptr3 = NULL;
               (yyval.node) = (yyvsp[-2].node);
            }
#line 2224 "y.tab.c"
    break;

  case 84:
#line 404 "exprtree.y"
                 {(yyval.node) = (yyvsp[0].node); (yyval.node)->ptr3 = NULL;}
#line 2230 "y.tab.c"
    break;

  case 85:
#line 405 "exprtree.y"
                        {(yyval.node) = NULL;}
#line 2236 "y.tab.c"
    break;


#line 2240 "y.tab.c"

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
#line 409 "exprtree.y"

   
   int yyerror(char const *s)
   {
       printf("yyerror %s\n",s);
   }
   
   
   int main(int argc, char **args) {
       if (argc > 1) 
           yyin = fopen(args[1], "r");
       fout = fopen("program.xsm", "w");
       yyparse();
       return 0;
   }
