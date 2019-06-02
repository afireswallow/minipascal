/* A Bison parser, made by GNU Bison 3.0.  */

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
#define YYBISON_VERSION "3.0"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 ".\\ast_yacc.y" /* yacc.c:339  */

#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

#include "ast.c"

#define MAXSTR 20
#define MAXMEMBER 100

#define INTTYPE  0
#define REALTYPE 1
#define ARRAYTYPE 5

extern struct node root;

extern int yylex();
extern FILE* yyin;
extern char str1[20];
/*int CheckKeyWord(char *str);*/
void OutputQ(void);
int yyparse();
void OutputIList(void);
int yyerror(char*);

int LookUp(char* name);
int Enter(char* name);
int Entry(char* name);
int Gen(char* op, int arg1, int arg2, int result);
int NewTemp(void);
int Merge(int p1, int p2);
void BackPatch(int p, int t);
void make_node(struct node *father, char *s);
void make_father(struct node **nd, char *s);
void output_ast(struct node *nd, int num);

int VarCount=0;
int SymbolCount = 0;
int TempCount = 0;
int add = 0;
FILE* fp;
int NXQ=0;  /* used to indicate the number of next Quater*/


struct QUATERLIST {
	char op[6];
	int arg1,arg2,result;
} 
QuaterList[MAXMEMBER];

struct VARLIST{
	char name[20];
	int type;
	int addr;
	/*union{int Iv;float Rv;} Value;*/
} VarList[MAXMEMBER];

struct SYMBOLLIST{
	char name[20];
	int type;
	int addr;
} SymbolList[MAXMEMBER];


#line 133 "ast_yacc.tab.c" /* yacc.c:339  */

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
   by #include "ast_yacc.tab.h".  */
#ifndef YY_YY_AST_YACC_TAB_H_INCLUDED
# define YY_YY_AST_YACC_TAB_H_INCLUDED
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
    Iden = 300,
    IntNo = 301,
    RealNo = 302,
    Program = 400,
    Begin = 401,
    End = 402,
    Var = 403,
    Integer = 404,
    Real = 405,
    While = 406,
    Do = 407,
    If = 408,
    Then = 409,
    Else = 410,
    Or = 411,
    And = 412,
    Not = 413,
    For = 414,
    To = 415,
    Array = 416,
    Of = 417,
    LE = 500,
    GE = 501,
    NE = 502,
    UMINUS = 504
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 69 ".\\ast_yacc.y" /* yacc.c:355  */

	struct { struct node *nd; int n;} Iv;
	struct { struct node *nd; int n;} CH;
	struct { struct node *nd; int n;} NO;
	struct { struct node *nd; int TC,FC;} _BExpr;
	struct { struct node *nd; int LoopStartPlace, Chain;} _WBD;
	struct { struct node *nd; int type,place;} _Expr;
	struct { struct node *nd; char s[5];} _Rop;
	struct { struct node *nd; int n;} First;
	char str[20];
	struct node *ast_node;
	struct { struct node *nd; int place, Chain, Loop;} _FoL;

#line 215 "ast_yacc.tab.c" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_AST_YACC_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 230 "ast_yacc.tab.c" /* yacc.c:358  */

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

#ifndef __attribute__
/* This feature is available in gcc versions 2.5 and later.  */
# if (! defined __GNUC__ || __GNUC__ < 2 \
      || (__GNUC__ == 2 && __GNUC_MINOR__ < 5))
#  define __attribute__(Spec) /* empty */
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
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   119

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  43
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  26
/* YYNRULES -- Number of rules.  */
#define YYNRULES  55
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  106

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   504

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
      41,    42,    32,    30,    40,    31,    36,    33,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    37,    35,
      27,    29,    28,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    38,     2,    39,     2,     2,     2,     2,     2,     2,
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
       2,     2,     2,     2,     2,     2,     1,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       3,     4,     5,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      24,    25,    26,     2,    34
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   147,   147,   147,   163,   171,   180,   187,   194,   218,
     225,   232,   245,   257,   268,   276,   284,   293,   300,   308,
     316,   326,   333,   345,   349,   359,   375,   388,   400,   412,
     420,   435,   449,   459,   470,   480,   490,   499,   502,   515,
     524,   536,   545,   554,   563,   574,   584,   594,   603,   612,
     622,   629,   636,   643,   650,   657
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "Iden", "IntNo", "RealNo", "Program",
  "Begin", "End", "Var", "Integer", "Real", "While", "Do", "If", "Then",
  "Else", "Or", "And", "Not", "For", "To", "Array", "Of", "LE", "GE", "NE",
  "'<'", "'>'", "'='", "'+'", "'-'", "'*'", "'/'", "UMINUS", "';'", "'.'",
  "':'", "'['", "']'", "','", "'('", "')'", "$accept", "ProgDef", "$@1",
  "SubProg", "VarDef", "VarDefList", "VarDefState", "Type", "VarList",
  "StateList", "S_L", "Statement", "CompState", "AsignState", "ISE", "IBT",
  "WBD", "Wh", "ForLoop", "Expr", "BoolExpr", "BoolExprAnd", "BoolExprOr",
  "Variable", "Const", "RelationOp", YY_NULL
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   503,   300,   301,   302,   400,   401,   402,   403,
     404,   405,   406,   407,   408,   409,   410,   411,   412,   413,
     414,   415,   416,   417,   500,   501,   502,    60,    62,    61,
      43,    45,    42,    47,   504,    59,    46,    58,    91,    93,
      44,    40,    41
};
# endif

#define YYPACT_NINF -45

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-45)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      -3,    11,    22,   -45,   -45,    13,    42,    58,    35,    50,
     -45,    34,   -45,    10,   -45,   -45,    56,   -45,    58,    78,
      58,   -45,    33,    58,     8,    56,   -45,   -45,   -45,    56,
      56,    56,    33,    -9,    38,   -45,   -45,   -45,    52,   -45,
     -45,   -45,   -45,    33,    36,    33,    77,    27,    33,    33,
     -45,   -45,    57,   -45,   -45,   -45,   -45,    75,   -45,    80,
      56,    36,    63,    91,   -45,    36,   -45,    54,   -12,   -45,
     -45,   -45,   -45,   -45,   -45,    36,    36,    36,    36,    36,
     -45,   -45,   -45,    55,    55,    70,   -45,   -45,   -45,    81,
      36,    76,   -23,   -45,   -45,    21,    21,   -45,   -45,    81,
      36,    81,    93,    81,    78,   -45
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     2,     1,     0,     0,     0,     0,     0,
      47,     0,     7,     0,    13,     3,    23,     4,     5,     0,
       0,    29,     0,     0,     0,    23,    15,    21,    17,    23,
      23,    23,     0,     0,     0,     6,     9,    10,     0,     8,
      12,    48,    49,     0,     0,     0,     0,     0,     0,     0,
      38,    39,     0,    24,    16,    14,    18,    19,    20,     0,
      23,     0,     0,     0,    43,     0,    37,     0,     0,    55,
      53,    54,    50,    51,    52,     0,     0,     0,     0,     0,
      27,    46,    45,    41,    42,     0,    26,    28,    22,    31,
       0,     0,     0,    36,    44,    32,    33,    34,    35,    40,
       0,    25,     0,    30,     0,    11
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -45,   -45,   -45,   -45,   -45,   -45,    99,    14,   -45,   -45,
     -45,    -2,   110,   -45,   -45,   -45,   -45,   -45,   -45,   -44,
      17,   -45,   -45,    -5,   -45,   -45
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,     5,     8,     9,    11,    12,    39,    13,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    46,
      47,    48,    49,    50,    51,    79
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      66,    67,    14,     1,    60,    81,    82,    75,    76,    77,
      78,    34,    61,    14,     3,    40,    53,    89,    52,    93,
      34,    92,     4,    55,    34,    34,    34,    56,    57,    58,
      94,    95,    96,    97,    98,    99,    10,    41,    42,    10,
      41,    42,    80,    54,    81,    82,   101,    19,     6,    59,
      20,     7,    43,    77,    78,    34,   103,    16,    88,    10,
      64,    10,    68,    16,    44,    83,    84,    44,    21,    18,
      22,    15,    81,    82,    45,    62,    23,    65,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    36,    37,
      63,    86,    90,    87,    85,    91,    93,    81,    82,   100,
      38,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    75,    76,    77,    78,   102,   104,    35,   105,    17
};

static const yytype_uint8 yycheck[] =
{
      44,    45,     7,     6,    13,    17,    18,    30,    31,    32,
      33,    16,    21,    18,     3,    20,     8,    61,    23,    42,
      25,    65,     0,    25,    29,    30,    31,    29,    30,    31,
      42,    75,    76,    77,    78,    79,     3,     4,     5,     3,
       4,     5,    15,    35,    17,    18,    90,    37,    35,    32,
      40,     9,    19,    32,    33,    60,   100,     7,    60,     3,
      43,     3,    45,     7,    31,    48,    49,    31,    12,    35,
      14,    36,    17,    18,    41,    37,    20,    41,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    10,    11,
      38,    16,    29,    13,    37,     4,    42,    17,    18,    29,
      22,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    30,    31,    32,    33,    39,    23,    18,   104,     9
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     6,    44,     3,     0,    45,    35,     9,    46,    47,
       3,    48,    49,    51,    66,    36,     7,    55,    35,    37,
      40,    12,    14,    20,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    66,    49,    10,    11,    22,    50,
      66,     4,     5,    19,    31,    41,    62,    63,    64,    65,
      66,    67,    66,     8,    35,    54,    54,    54,    54,    63,
      13,    21,    37,    38,    63,    41,    62,    62,    63,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    68,
      15,    17,    18,    63,    63,    37,    16,    13,    54,    62,
      29,     4,    62,    42,    42,    62,    62,    62,    62,    62,
      29,    62,    39,    62,    23,    50
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    43,    45,    44,    46,    47,    48,    48,    49,    50,
      50,    50,    51,    51,    52,    52,    53,    54,    54,    54,
      54,    54,    54,    54,    55,    56,    57,    58,    59,    60,
      61,    61,    62,    62,    62,    62,    62,    62,    62,    62,
      63,    63,    63,    63,    63,    64,    65,    66,    67,    67,
      68,    68,    68,    68,    68,    68
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     6,     2,     3,     3,     1,     3,     1,
       1,     6,     3,     1,     2,     1,     2,     1,     2,     2,
       2,     1,     3,     0,     3,     4,     3,     3,     3,     1,
       5,     3,     3,     3,     3,     3,     3,     2,     1,     1,
       3,     2,     2,     2,     3,     2,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1
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
  YYSIZE_T yysize0 = yytnamerr (YY_NULL, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULL;
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
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULL, yytname[yyx]);
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
#line 147 ".\\ast_yacc.y" /* yacc.c:1646  */
    {set_node_val_str(&root,str1);}
#line 1383 "ast_yacc.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 148 ".\\ast_yacc.y" /* yacc.c:1646  */
    {
			printf("\n\n**** test ast node ****\n");
			(yyval.ast_node)=&root;
			make_node((yyval.ast_node), "Program");
			make_node((yyval.ast_node), root.val.str);
			make_node((yyval.ast_node), ";");
        	add_son_node((yyval.ast_node), (yyvsp[-1].ast_node));
			make_node((yyval.ast_node), ".");

			output_ast(&root, 0);

			printf("**** Program %s ****\n",root.val.str);
        }
#line 1401 "ast_yacc.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 164 ".\\ast_yacc.y" /* yacc.c:1646  */
    {
			make_father(&(yyval.ast_node), "SubProg");
			add_son_node((yyval.ast_node), (yyvsp[-1].CH).nd);
			add_son_node((yyval.ast_node), (yyvsp[0].CH).nd);
		}
#line 1411 "ast_yacc.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 172 ".\\ast_yacc.y" /* yacc.c:1646  */
    {
			make_father(&(yyval.CH).nd, "VarDef");
			make_node((yyval.CH).nd, "Var");
			add_son_node((yyval.CH).nd, (yyvsp[-1].CH).nd);
			make_node((yyval.CH).nd, ";");
		}
#line 1422 "ast_yacc.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 181 ".\\ast_yacc.y" /* yacc.c:1646  */
    {
			make_father(&(yyval.CH).nd, "VarDefList");
			add_son_node((yyval.CH).nd, (yyvsp[-2].CH).nd);
			make_node((yyval.CH).nd, ";");
			add_son_node((yyval.CH).nd, (yyvsp[0].CH).nd);
		}
#line 1433 "ast_yacc.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 188 ".\\ast_yacc.y" /* yacc.c:1646  */
    {
			make_father(&(yyval.CH).nd, "VarDefList");
			add_son_node((yyval.CH).nd, (yyvsp[0].CH).nd);
        }
#line 1442 "ast_yacc.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 195 ".\\ast_yacc.y" /* yacc.c:1646  */
    {
			for (int i = 0; i < SymbolCount; i++){
				if (SymbolList[SymbolCount - i].type == 2){
					SymbolList[SymbolCount - i].type = (yyvsp[0].Iv).n;
					VarList[VarCount].type = (yyvsp[0].Iv).n;
					strcpy(VarList[VarCount].name, SymbolList[SymbolCount - i].name);
					if ((yyvsp[0].Iv).n == ARRAYTYPE) {
						SymbolList[SymbolCount - i].addr = add;
						VarList[VarCount].addr = add;
					}
					VarCount++;
				}
				else {
					break;
				}
			}

			make_father(&(yyval.CH).nd, "VarDefState");
			add_son_node((yyval.CH).nd, (yyvsp[-2].First).nd);
			make_node((yyval.CH).nd, ":");
			add_son_node((yyval.CH).nd, (yyvsp[0].Iv).nd);
		}
#line 1469 "ast_yacc.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 219 ".\\ast_yacc.y" /* yacc.c:1646  */
    {
			(yyval.Iv).n = INTTYPE;

			make_father(&(yyval.Iv).nd, "Type");
			make_node((yyval.Iv).nd, "Integer");
		}
#line 1480 "ast_yacc.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 226 ".\\ast_yacc.y" /* yacc.c:1646  */
    {
			(yyval.Iv).n = REALTYPE;

			make_father(&(yyval.Iv).nd, "Type");
			make_node((yyval.Iv).nd, "Real");
		}
#line 1491 "ast_yacc.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 233 ".\\ast_yacc.y" /* yacc.c:1646  */
    {
			(yyval.Iv).n = ARRAYTYPE;

			add = atoi(str1);
			make_father(&(yyval.Iv).nd, "Type");
			make_node((yyval.Iv).nd, "[");
			make_node((yyval.Iv).nd, str1);
			make_node((yyval.Iv).nd, "]");
			make_node((yyval.Iv).nd, "Of");
			add_son_node((yyval.Iv).nd, (yyvsp[0].Iv).nd);
		}
#line 1507 "ast_yacc.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 246 ".\\ast_yacc.y" /* yacc.c:1646  */
    {
			if ((yyvsp[0].NO).n) {
				yyerror("repeat the var\n");
				return 0;
			}

			make_father(&(yyval.First).nd, "VarList");
			add_son_node((yyval.First).nd, (yyvsp[-2].First).nd);
			make_node((yyval.First).nd, ",");
			add_son_node((yyval.First).nd, (yyvsp[0].NO).nd);
		}
#line 1523 "ast_yacc.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 258 ".\\ast_yacc.y" /* yacc.c:1646  */
    {
			if ((yyvsp[0].NO).n) {	
				yyerror("repeat the var\n");
				return 0;
			}

			make_father(&(yyval.First).nd, "VarList");
			add_son_node((yyval.First).nd, (yyvsp[0].NO).nd);
		}
#line 1537 "ast_yacc.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 269 ".\\ast_yacc.y" /* yacc.c:1646  */
    {
			(yyval.CH).n = (yyvsp[0].CH).n;

			make_father(&(yyval.CH).nd, "StateList");
			add_son_node((yyval.CH).nd, (yyvsp[-1].CH).nd);
			add_son_node((yyval.CH).nd, (yyvsp[0].CH).nd);
		}
#line 1549 "ast_yacc.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 277 ".\\ast_yacc.y" /* yacc.c:1646  */
    {
			(yyval.CH).n = (yyvsp[0].CH).n;

			make_father(&(yyval.CH).nd, "StateList");
			add_son_node((yyval.CH).nd, (yyvsp[0].CH).nd);
		}
#line 1560 "ast_yacc.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 285 ".\\ast_yacc.y" /* yacc.c:1646  */
    {
			BackPatch((yyvsp[-1].CH).n, NXQ);

			make_father(&(yyval.CH).nd, "S_L");
			add_son_node((yyval.CH).nd, (yyvsp[-1].CH).nd);
			make_node((yyval.CH).nd, ";");
		}
#line 1572 "ast_yacc.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 294 ".\\ast_yacc.y" /* yacc.c:1646  */
    {
			(yyval.CH).n = 0;

			make_father(&(yyval.CH).nd, "Statement");
			add_son_node((yyval.CH).nd, (yyvsp[0].CH).nd);
		}
#line 1583 "ast_yacc.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 301 ".\\ast_yacc.y" /* yacc.c:1646  */
    {
			(yyval.CH).n = Merge((yyvsp[-1].CH).n, (yyvsp[0].CH).n);

			make_father(&(yyval.CH).nd, "Statement");
			add_son_node((yyval.CH).nd, (yyvsp[-1].CH).nd);
			add_son_node((yyval.CH).nd, (yyvsp[0].CH).nd);
		}
#line 1595 "ast_yacc.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 309 ".\\ast_yacc.y" /* yacc.c:1646  */
    {
			(yyval.CH).n = Merge((yyvsp[-1].CH).n, (yyvsp[0].CH).n);

			make_father(&(yyval.CH).nd, "Statement");
			add_son_node((yyval.CH).nd, (yyvsp[-1].CH).nd);
			add_son_node((yyval.CH).nd, (yyvsp[0].CH).nd);
		}
#line 1607 "ast_yacc.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 317 ".\\ast_yacc.y" /* yacc.c:1646  */
    {
			BackPatch((yyvsp[0].CH).n, (yyvsp[-1]._WBD).LoopStartPlace);
			Gen("j", 0, 0, (yyvsp[-1]._WBD).LoopStartPlace);
			(yyval.CH).n = (yyvsp[-1]._WBD).Chain;

			make_father(&(yyval.CH).nd, "Statement");
			add_son_node((yyval.CH).nd, (yyvsp[-1]._WBD).nd);
			add_son_node((yyval.CH).nd, (yyvsp[0].CH).nd);
		}
#line 1621 "ast_yacc.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 327 ".\\ast_yacc.y" /* yacc.c:1646  */
    {
			(yyval.CH).n = (yyvsp[0].CH).n;

			make_father(&(yyval.CH).nd, "Statement");
			add_son_node((yyval.CH).nd, (yyvsp[0].CH).nd);
		}
#line 1632 "ast_yacc.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 334 ".\\ast_yacc.y" /* yacc.c:1646  */
    {
			BackPatch((yyvsp[0].CH).n, NXQ);
			Gen("+", (yyvsp[-2]._FoL).place, 1, (yyvsp[-2]._FoL).place);
			Gen("j", 0, 0, (yyvsp[-2]._FoL).Loop);
			(yyval.CH).n = (yyvsp[-2]._FoL).Chain;

			make_father(&(yyval.CH).nd, "Statement");
			add_son_node((yyval.CH).nd, (yyvsp[-2]._FoL).nd);
			make_node((yyval.CH).nd, "Do");
			add_son_node((yyval.CH).nd, (yyvsp[0].CH).nd);
		}
#line 1648 "ast_yacc.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 345 ".\\ast_yacc.y" /* yacc.c:1646  */
    {
			make_father(&(yyval.CH).nd, "Statement");
	    }
#line 1656 "ast_yacc.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 350 ".\\ast_yacc.y" /* yacc.c:1646  */
    {
			(yyval.CH).n = (yyvsp[-1].CH).n;

			make_father(&(yyval.CH).nd, "CompState");
			make_node((yyval.CH).nd, "Begin");
			add_son_node((yyval.CH).nd, (yyvsp[-1].CH).nd);
			make_node((yyval.CH).nd, "End");
		}
#line 1669 "ast_yacc.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 360 ".\\ast_yacc.y" /* yacc.c:1646  */
    {
			if ((yyvsp[-3].NO).n)
				Gen(":=", (yyvsp[0]._Expr).place, 0, (yyvsp[-3].NO).n);
			else {
				yyerror("variable wrong!\n");
				return 0;
			}

			make_father(&(yyval.CH).nd, "AsignState");
			add_son_node((yyval.CH).nd, (yyvsp[-3].NO).nd);
			make_node((yyval.CH).nd, ":");
			make_node((yyval.CH).nd, "=");
			add_son_node((yyval.CH).nd, (yyvsp[0]._Expr).nd);
		}
#line 1688 "ast_yacc.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 376 ".\\ast_yacc.y" /* yacc.c:1646  */
    {
			int q = NXQ;
			Gen("j", 0, 0, 0);
			BackPatch((yyvsp[-2].CH).n, NXQ);
			(yyval.CH).n = Merge((yyvsp[-1].CH).n, q);

			make_father(&(yyval.CH).nd, "ISE");
			add_son_node((yyval.CH).nd, (yyvsp[-2].CH).nd);
			add_son_node((yyval.CH).nd, (yyvsp[-1].CH).nd);
			make_node((yyval.CH).nd, "Else");
		}
#line 1704 "ast_yacc.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 389 ".\\ast_yacc.y" /* yacc.c:1646  */
    {
			BackPatch((yyvsp[-1]._BExpr).TC, NXQ);
			(yyval.CH).n = (yyvsp[-1]._BExpr).FC;

			make_father(&(yyval.CH).nd, "IBT");
			make_node((yyval.CH).nd, "If");
			add_son_node((yyval.CH).nd, (yyvsp[-1]._BExpr).nd);
			make_node((yyval.CH).nd, "Then");
		}
#line 1718 "ast_yacc.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 401 ".\\ast_yacc.y" /* yacc.c:1646  */
    {
			BackPatch((yyvsp[-1]._BExpr).TC, NXQ);
			(yyval._WBD).Chain = (yyvsp[-1]._BExpr).FC;
			(yyval._WBD).LoopStartPlace = (yyvsp[-2].CH).n;

			make_father(&(yyval._WBD).nd, "WBD");
			add_son_node((yyval._WBD).nd, (yyvsp[-2].CH).nd);
			add_son_node((yyval._WBD).nd, (yyvsp[-1]._BExpr).nd);
			make_node((yyval._WBD).nd, "Do");
		}
#line 1733 "ast_yacc.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 413 ".\\ast_yacc.y" /* yacc.c:1646  */
    {
			(yyval.CH).n = NXQ;

			make_father(&(yyval.CH).nd, "Wh");
			make_node((yyval.CH).nd, "While");
        }
#line 1744 "ast_yacc.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 421 ".\\ast_yacc.y" /* yacc.c:1646  */
    {
			char c[5];
			sprintf(c, "%d", (yyvsp[-3].NO).n);
			int i = Entry(c);
			Gen("=", (yyvsp[0]._Expr).place, 0, i);
			(yyval._FoL).place = i;

			make_father(&(yyval._FoL).nd, "ForLoop");
			make_node((yyval._FoL).nd, "For");
			add_son_node((yyval._FoL).nd, (yyvsp[-3].NO).nd);
			make_node((yyval._FoL).nd, ":");
			make_node((yyval._FoL).nd, "=");
			add_son_node((yyval._FoL).nd, (yyvsp[0]._Expr).nd);
		}
#line 1763 "ast_yacc.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 436 ".\\ast_yacc.y" /* yacc.c:1646  */
    {
			int p = NXQ;
			(yyval._FoL).Loop = NXQ;
			Gen("j<=", (yyvsp[-2]._FoL).place, (yyvsp[0]._Expr).place, p+2);
			(yyval._FoL).place = (yyvsp[-2]._FoL).place;
			(yyval._FoL).Chain = NXQ;
			Gen("j", 0, 0, 0);

			make_father(&(yyval._FoL).nd, "ForLoop");
			add_son_node((yyval._FoL).nd, (yyvsp[-2]._FoL).nd);
			make_node((yyval._FoL).nd, "To");
			add_son_node((yyval._FoL).nd, (yyvsp[0]._Expr).nd);
		}
#line 1781 "ast_yacc.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 450 ".\\ast_yacc.y" /* yacc.c:1646  */
    {
			(yyval._Expr).place = NewTemp();
			Gen("+", (yyvsp[-2]._Expr).place, (yyvsp[0]._Expr).place, (yyval._Expr).place);

			make_father(&(yyval._Expr).nd, "Expr");
			add_son_node((yyval._Expr).nd, (yyvsp[-2]._Expr).nd);
			make_node((yyval._Expr).nd, "+");
			add_son_node((yyval._Expr).nd, (yyvsp[0]._Expr).nd);
		}
#line 1795 "ast_yacc.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 460 ".\\ast_yacc.y" /* yacc.c:1646  */
    {
			(yyval._Expr).place = NewTemp();
			Gen("-", (yyvsp[-2]._Expr).place, (yyvsp[0]._Expr).place, (yyval._Expr).place);

			make_father(&(yyval._Expr).nd, "Expr");
			add_son_node((yyval._Expr).nd, (yyvsp[-2]._Expr).nd);
			make_node((yyval._Expr).nd, "-");
			add_son_node((yyval._Expr).nd, (yyvsp[0]._Expr).nd);
		}
#line 1809 "ast_yacc.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 471 ".\\ast_yacc.y" /* yacc.c:1646  */
    {
			(yyval._Expr).place = NewTemp();
			Gen("*", (yyvsp[-2]._Expr).place, (yyvsp[0]._Expr).place, (yyval._Expr).place);

			make_father(&(yyval._Expr).nd, "Expr");
			add_son_node((yyval._Expr).nd, (yyvsp[-2]._Expr).nd);
			make_node((yyval._Expr).nd, "*");
			add_son_node((yyval._Expr).nd, (yyvsp[0]._Expr).nd);
		}
#line 1823 "ast_yacc.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 481 ".\\ast_yacc.y" /* yacc.c:1646  */
    {
			(yyval._Expr).place = NewTemp();
			Gen("/", (yyvsp[-2]._Expr).place, (yyvsp[0]._Expr).place, (yyval._Expr).place);

			make_father(&(yyval._Expr).nd, "Expr");
			add_son_node((yyval._Expr).nd, (yyvsp[-2]._Expr).nd);
			make_node((yyval._Expr).nd, "/");
			add_son_node((yyval._Expr).nd, (yyvsp[0]._Expr).nd);
		}
#line 1837 "ast_yacc.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 491 ".\\ast_yacc.y" /* yacc.c:1646  */
    {
			(yyval._Expr).place = (yyvsp[-1]._Expr).place;

			make_father(&(yyval._Expr).nd, "Expr");
			make_node((yyval._Expr).nd, "(");
			add_son_node((yyval._Expr).nd, (yyvsp[-1]._Expr).nd);
			make_node((yyval._Expr).nd, ")");
		}
#line 1850 "ast_yacc.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 500 ".\\ast_yacc.y" /* yacc.c:1646  */
    {
		}
#line 1857 "ast_yacc.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 503 ".\\ast_yacc.y" /* yacc.c:1646  */
    {
			if ((yyvsp[0].NO).n)
				(yyval._Expr).place = (yyvsp[0].NO).n;
			else {
				yyerror("variable wrong!\n");
				return 0;
			}

			make_father(&(yyval._Expr).nd, "Expr");
			add_son_node((yyval._Expr).nd, (yyvsp[0].NO).nd);
		}
#line 1873 "ast_yacc.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 516 ".\\ast_yacc.y" /* yacc.c:1646  */
    {
			(yyval._Expr).place = (yyvsp[0]._Expr).place;

			make_father(&(yyval._Expr).nd, "Expr");
			add_son_node((yyval._Expr).nd, (yyvsp[0]._Expr).nd);
		}
#line 1884 "ast_yacc.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 525 ".\\ast_yacc.y" /* yacc.c:1646  */
    {
			(yyval._BExpr).TC = NXQ;
			(yyval._BExpr).FC = NXQ + 1;
			Gen((yyvsp[-1]._Rop).s, (yyvsp[-2]._Expr).place, (yyvsp[0]._Expr).place, 0);
			Gen("j", 0, 0, 0);

			make_father(&(yyval._BExpr).nd, "BoolExpr");
			add_son_node((yyval._BExpr).nd, (yyvsp[-2]._Expr).nd);
			add_son_node((yyval._BExpr).nd, (yyvsp[-1]._Rop).nd);
			add_son_node((yyval._BExpr).nd, (yyvsp[0]._Expr).nd);
		}
#line 1900 "ast_yacc.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 537 ".\\ast_yacc.y" /* yacc.c:1646  */
    {
			(yyval._BExpr).TC = (yyvsp[0]._BExpr).TC;
			(yyval._BExpr).FC = Merge((yyvsp[-1]._BExpr).FC, (yyvsp[0]._BExpr).FC);

			make_father(&(yyval._BExpr).nd, "BoolExpr");
			add_son_node((yyval._BExpr).nd, (yyvsp[-1]._BExpr).nd);
			add_son_node((yyval._BExpr).nd, (yyvsp[0]._BExpr).nd);
		}
#line 1913 "ast_yacc.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 546 ".\\ast_yacc.y" /* yacc.c:1646  */
    {
			(yyval._BExpr).FC = (yyvsp[0]._BExpr).FC;
			(yyval._BExpr).TC = Merge((yyvsp[-1]._BExpr).TC, (yyvsp[0]._BExpr).TC);

			make_father(&(yyval._BExpr).nd, "BoolExpr");
			add_son_node((yyval._BExpr).nd, (yyvsp[-1]._BExpr).nd);
			add_son_node((yyval._BExpr).nd, (yyvsp[0]._BExpr).nd);
		}
#line 1926 "ast_yacc.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 555 ".\\ast_yacc.y" /* yacc.c:1646  */
    {
			(yyval._BExpr).TC = (yyvsp[0]._BExpr).FC;
			(yyval._BExpr).FC = (yyvsp[0]._BExpr).TC;

			make_father(&(yyval._BExpr).nd, "BoolExpr");
			make_node((yyval._BExpr).nd, "Not");
			add_son_node((yyval._BExpr).nd, (yyvsp[0]._BExpr).nd);
		}
#line 1939 "ast_yacc.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 564 ".\\ast_yacc.y" /* yacc.c:1646  */
    {
			(yyval._BExpr).TC = (yyvsp[-1]._BExpr).TC;
			(yyval._BExpr).FC = (yyvsp[-1]._BExpr).FC;

			make_father(&(yyval._BExpr).nd, "BoolExpr");
			make_node((yyval._BExpr).nd, "(");
			add_son_node((yyval._BExpr).nd, (yyvsp[-1]._BExpr).nd);
			make_node((yyval._BExpr).nd, ")");
		}
#line 1953 "ast_yacc.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 575 ".\\ast_yacc.y" /* yacc.c:1646  */
    {
			BackPatch((yyvsp[-1]._BExpr).TC, NXQ);
			(yyval._BExpr).FC = (yyvsp[-1]._BExpr).FC;

			make_father(&(yyval._BExpr).nd, "BoolExprAnd");
			add_son_node((yyval._BExpr).nd, (yyvsp[-1]._BExpr).nd);
			make_node((yyval._BExpr).nd, "And");
		}
#line 1966 "ast_yacc.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 585 ".\\ast_yacc.y" /* yacc.c:1646  */
    {
			BackPatch((yyvsp[-1]._BExpr).FC, NXQ);
			(yyval._BExpr).TC = (yyvsp[-1]._BExpr).TC;

			make_father(&(yyval._BExpr).nd, "BoolExprOr");
			add_son_node((yyval._BExpr).nd, (yyvsp[-1]._BExpr).nd);
			make_node((yyval._BExpr).nd, "Or");
		}
#line 1979 "ast_yacc.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 595 ".\\ast_yacc.y" /* yacc.c:1646  */
    {
			(yyval.NO).n = LookUp(str1);
			Entry(str1);

			make_father(&(yyval.NO).nd, "Variable");
			make_node((yyval.NO).nd, str1);
		}
#line 1991 "ast_yacc.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 604 ".\\ast_yacc.y" /* yacc.c:1646  */
    {
			int t = Entry(str1);
			SymbolList[t].type = INTTYPE;
			(yyval._Expr).place = t;

			make_father(&(yyval._Expr).nd, "Const");
			make_node((yyval._Expr).nd, str1);
		}
#line 2004 "ast_yacc.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 613 ".\\ast_yacc.y" /* yacc.c:1646  */
    {
			int t = Entry(str1);
			SymbolList[t].type = REALTYPE;
			(yyval._Expr).place = t;

			make_father(&(yyval._Expr).nd, "Const");
			make_node((yyval._Expr).nd, str1);
		}
#line 2017 "ast_yacc.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 623 ".\\ast_yacc.y" /* yacc.c:1646  */
    {
			strcpy((yyval._Rop).s, "j<");

			make_father(&(yyval._Rop).nd, "RelationOp");
			make_node((yyval._Rop).nd, "<");
		}
#line 2028 "ast_yacc.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 630 ".\\ast_yacc.y" /* yacc.c:1646  */
    {
			strcpy((yyval._Rop).s, "j>");

			make_father(&(yyval._Rop).nd, "RelationOp");
			make_node((yyval._Rop).nd, ">");
		}
#line 2039 "ast_yacc.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 637 ".\\ast_yacc.y" /* yacc.c:1646  */
    {
			strcpy((yyval._Rop).s, "j=");

			make_father(&(yyval._Rop).nd, "RelationOp");
			make_node((yyval._Rop).nd, "=");
		}
#line 2050 "ast_yacc.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 644 ".\\ast_yacc.y" /* yacc.c:1646  */
    {
			strcpy((yyval._Rop).s, "j>=");

			make_father(&(yyval._Rop).nd, "RelationOp");
			make_node((yyval._Rop).nd, ">=");
		}
#line 2061 "ast_yacc.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 651 ".\\ast_yacc.y" /* yacc.c:1646  */
    {
			strcpy((yyval._Rop).s, "j<>");

			make_father(&(yyval._Rop).nd, "RelationOp");
			make_node((yyval._Rop).nd, "<>");
		}
#line 2072 "ast_yacc.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 658 ".\\ast_yacc.y" /* yacc.c:1646  */
    {
			strcpy((yyval._Rop).s, "j<=");

			make_father(&(yyval._Rop).nd, "RelationOp");
			make_node((yyval._Rop).nd, "<=");
		}
#line 2083 "ast_yacc.tab.c" /* yacc.c:1646  */
    break;


#line 2087 "ast_yacc.tab.c" /* yacc.c:1646  */
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
#line 666 ".\\ast_yacc.y" /* yacc.c:1906  */

/*int yylex(void)
{ 
}
*/

int LookUp(char* name) {
	for (int i = 1; i <= SymbolCount; i++)
		if (!strcmp(SymbolList[i].name, name)) {
			return i;
		}
	return 0;
}

int Enter(char* name) {
	SymbolCount++;
	strcpy(SymbolList[SymbolCount].name, name);
	SymbolList[SymbolCount].type = 2;
	return SymbolCount;
}

int Entry(char* name) {
	int i = LookUp(name);
	if (i)
		return i;
	else
		return Enter(name);
}

int Gen(char* op, int arg1, int arg2, int result) {
	strcpy(QuaterList[NXQ].op, op);
	QuaterList[NXQ].arg1 = arg1;
	QuaterList[NXQ].arg2 = arg2;
	QuaterList[NXQ].result = result;
	NXQ++;
	return NXQ - 1;
}

int NewTemp(void) {
	SymbolCount++;
	TempCount++;
	char c[6];
	sprintf(c, "T%d", TempCount);

	strcpy(SymbolList[SymbolCount].name, c);
	SymbolList[SymbolCount].type = -1;
	return SymbolCount;
}

int Merge(int p1, int p2) {
	int p;
	if (!p2) 
		return p1;
	else {
		p = p2;
		while (QuaterList[p].result)
			p = QuaterList[p].result;
		QuaterList[p].result = p1;
		return p2;
	}
}

void BackPatch(int p, int t) {
	int q = p;
	while (q) {
		int q1 = QuaterList[q].result;
		QuaterList[q].result = t;
		q = q1;
	}
	return;
}

void make_node(struct node *father, char *s) {
	struct node *ndd;
	make_father(&ndd, s);
	add_son_node(father, ndd);
}

void make_father(struct node **nd, char *s) {
	new_node(nd);
	init_node(*nd);
	set_node_val_str(*nd, s);
}

void output_ast(struct node *nd, int num) {
	if (nd == NULL)
		return;

	printf("%d", num);

	for (int i = 0; i < num; i++) {
		printf("   ");
	}

	printf("%s\n", nd->val.str);
	output_ast(nd->son, num+1);
	output_ast(nd->next, num);
}

void OutputQ(void)
{
	int i=0;
	
	if(i>=NXQ) {
		printf("no quater exists!\n");
	}
		
	for(i=0;i<NXQ;i++) {
	
		printf("(%3d) ( %5s, ",i,QuaterList[i].op);
		if(QuaterList[i].arg1)
			printf("%6s, ",SymbolList[QuaterList[i].arg1].name);
		else
			printf("      , ");
			
		if(QuaterList[i].arg2)
			printf("%6s, ",SymbolList[QuaterList[i].arg2].name);
		else printf("      , ");
		
		if((QuaterList[i].op[0]=='j')||(QuaterList[i].op[0]=='S')) 
			printf("%6d )\n",QuaterList[i].result);
		else if(QuaterList[i].result)
			printf("%6s )\n",SymbolList[QuaterList[i].result].name);
		else printf("-\t )\n");
	}
	
	return;
}

int main(int argc, char *argv[])
{
	yyin=stdin;
	// init_node(&root);
	
	if(argc>1) {
		if((yyin=fopen(argv[1],"r"))==NULL) {
			printf("Can't open file %s\n",argv[1]);
			return -1;
		}
	}
	
	yyparse();
	
	OutputQ();
	
	OutputIList();
	
	return 0;
}

int yyerror(char *errstr)
{
	printf(" %s\n",errstr);
	return 0;
}

void OutputIList(void)
{
	int i=0;
	
	printf(" No.\t name \t\t   type\n");
	
	if(i>=VarCount) {
		printf("Variable Table is NULL!\n");
	}
	
	for(i=0;i<VarCount;i++) {
		printf("%4d\t%6s\t\t",i,VarList[i].name);
		if(VarList[i].type == REALTYPE) {
			printf(" REAL  \n");
		} else if (VarList[i].type == INTTYPE) {
			printf(" INTEGER\n"); 
		} else {
			printf(" ARRAY\t\t%d\n", VarList[i].addr);
		}
	}

	printf(" No.\t name \t\t   type\n");
	
	i = 0;
	printf("Symbol Table:\n");
	if(SymbolCount == 0) {
		printf("Symbol Table is NULL!\n");
	}
	
	for(i=1;i<=SymbolCount;i++) {
		printf("%4d\t%6s\t\t",i,SymbolList[i].name);
		if(SymbolList[i].type == REALTYPE) {
			printf(" REAL  \n");
		} else if (SymbolList[i].type == INTTYPE) {
			printf(" INTEGER\n"); 
		} else if (SymbolList[i].type == ARRAYTYPE) {
			printf(" ARRAY\t\t%d\n", SymbolList[i].addr);
		} else if (SymbolList[i].type == -1) {
			printf(" Temp\n");
		} else {
			printf(" None Type\n");
		}
	}
	
	return;
}
