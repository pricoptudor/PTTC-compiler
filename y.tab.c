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
#line 1 "limbaj.y"

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
extern FILE* yyin;
extern char* yytext;
extern int yylineno;

#define MAX_SIZE 100

int CURR_SCOPE=0;
int INC_SCOPE=1000;

struct var{
     char nume[MAX_SIZE];
     char valoare_sir[MAX_SIZE];
     double valoare_num; //default=0 in decalratie
     int tip;
     int constant; //default=0 in declaratie
     int scope;
};

struct fun{
     char nume[MAX_SIZE];
     int tip;
     struct parametri* param;
     struct var* return_val;
};

struct parametri{
     int param_nr;
     int param_tip[20];
};

struct structura{
     char nume[MAX_SIZE];
     int member_nr;
     char member_name[MAX_SIZE][MAX_SIZE];
     int var_decl_nr;
     char var_declared[MAX_SIZE][MAX_SIZE];
     int scope;
};

struct var* moveVar(char* i);
struct var* moveNum(double n, int tip);
struct var* expr_calc_single(struct var* e, int c);
struct var* expr_calc_double(struct var* e1, struct var* e2, int c);
struct var* array_get_value(char* id, int pos);
struct var* moveSir(char* str, int tip);
struct var* moveArray(struct var* a);
struct var* array_get_size(char *id);
struct var* moveFunc(struct var* v);
struct var* callFunctionSimple(char *id);
struct var* callFunctionComplex(char *id, struct parametri* p);
struct parametri* insertFirstParam(int tip);
struct var* moveStructMember(char* id, char* member);

int arr_count=0;
int arr_size[MAX_SIZE];
int var_count = 0;
int fun_count=0;
int struct_count=0;
struct var arr_table[MAX_SIZE][MAX_SIZE];
struct var var_table[MAX_SIZE];
struct fun fun_table[MAX_SIZE];
struct structura struct_table[MAX_SIZE];


#line 140 "y.tab.c"

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
    PROG_BEGIN = 258,
    PROG_END = 259,
    GLOBAL_BEGIN = 260,
    GLOBAL_END = 261,
    FNC_STR_BEGIN = 262,
    FNC_STR_END = 263,
    MAIN_BEGIN = 264,
    MAIN_END = 265,
    CONST = 266,
    INT = 267,
    FLOAT = 268,
    CHAR = 269,
    STRING = 270,
    BOOL = 271,
    ARRAY = 272,
    ARRAY_INSERT = 273,
    ARRAY_DELETE = 274,
    ARRAY_GET = 275,
    ARRAY_SIZE = 276,
    ADUNARE = 277,
    SCADERE = 278,
    INMULTIRE = 279,
    IMPARTIRE = 280,
    INCREMENT = 281,
    DECREMENT = 282,
    EQUAL = 283,
    NEQUAL = 284,
    LOWER = 285,
    LEQ = 286,
    GREATER = 287,
    GEQ = 288,
    AND = 289,
    OR = 290,
    ASSIGN = 291,
    PRINT = 292,
    STRUCT_BEGIN = 293,
    STRUCT_END = 294,
    STRUCT_TYPE = 295,
    FUNCTION_BEGIN = 296,
    FUNCTION_END = 297,
    FUNCTION_TYPE = 298,
    RETURN = 299,
    COMMENT = 300,
    IF_BEGIN = 301,
    IF_END = 302,
    ELSE_BEGIN = 303,
    ELSE_END = 304,
    WHILE_BEGIN = 305,
    WHILE_END = 306,
    FOR_BEGIN = 307,
    FOR_END = 308,
    NUMBER = 309,
    NUMBER_FLOAT = 310,
    ID = 311,
    ANYTHING = 312,
    VALUE_CHR = 313
  };
#endif
/* Tokens.  */
#define PROG_BEGIN 258
#define PROG_END 259
#define GLOBAL_BEGIN 260
#define GLOBAL_END 261
#define FNC_STR_BEGIN 262
#define FNC_STR_END 263
#define MAIN_BEGIN 264
#define MAIN_END 265
#define CONST 266
#define INT 267
#define FLOAT 268
#define CHAR 269
#define STRING 270
#define BOOL 271
#define ARRAY 272
#define ARRAY_INSERT 273
#define ARRAY_DELETE 274
#define ARRAY_GET 275
#define ARRAY_SIZE 276
#define ADUNARE 277
#define SCADERE 278
#define INMULTIRE 279
#define IMPARTIRE 280
#define INCREMENT 281
#define DECREMENT 282
#define EQUAL 283
#define NEQUAL 284
#define LOWER 285
#define LEQ 286
#define GREATER 287
#define GEQ 288
#define AND 289
#define OR 290
#define ASSIGN 291
#define PRINT 292
#define STRUCT_BEGIN 293
#define STRUCT_END 294
#define STRUCT_TYPE 295
#define FUNCTION_BEGIN 296
#define FUNCTION_END 297
#define FUNCTION_TYPE 298
#define RETURN 299
#define COMMENT 300
#define IF_BEGIN 301
#define IF_END 302
#define ELSE_BEGIN 303
#define ELSE_END 304
#define WHILE_BEGIN 305
#define WHILE_END 306
#define FOR_BEGIN 307
#define FOR_END 308
#define NUMBER 309
#define NUMBER_FLOAT 310
#define ID 311
#define ANYTHING 312
#define VALUE_CHR 313

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 86 "limbaj.y"

	double num; 
	char nume_var[1000]; 
     char sir_var[1000];
	int type_id;
     struct var* strct;
     struct parametri* strct_param;
     struct fun* fnc;

#line 318 "y.tab.c"

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
typedef yytype_int16 yy_state_t;

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
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   631

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  65
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  49
/* YYNRULES -- Number of rules.  */
#define YYNRULES  142
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  296

#define YYUNDEFTOK  2
#define YYMAXUTOK   313


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
      59,    60,     2,     2,    61,     2,    64,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    62,    63,
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
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   119,   119,   120,   121,   125,   126,   129,   130,   133,
     137,   138,   142,   145,   146,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   162,   165,   168,   169,
     172,   173,   177,   181,   182,   185,   186,   187,   190,   193,
     194,   197,   198,   199,   200,   201,   202,   203,   206,   207,
     210,   211,   214,   218,   219,   220,   224,   225,   228,   231,
     232,   236,   239,   242,   243,   247,   250,   253,   254,   258,
     261,   264,   267,   270,   273,   274,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   292,   293,   294,
     295,   296,   299,   300,   301,   302,   303,   304,   305,   308,
     309,   310,   313,   314,   315,   316,   317,   318,   319,   320,
     321,   322,   323,   324,   327,   332,   333,   334,   335,   336,
     337,   338,   339,   342,   345,   346,   347,   348,   349,   350,
     351,   352,   353,   354,   355,   356,   360,   361,   364,   365,
     366,   367,   368
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "PROG_BEGIN", "PROG_END", "GLOBAL_BEGIN",
  "GLOBAL_END", "FNC_STR_BEGIN", "FNC_STR_END", "MAIN_BEGIN", "MAIN_END",
  "CONST", "INT", "FLOAT", "CHAR", "STRING", "BOOL", "ARRAY",
  "ARRAY_INSERT", "ARRAY_DELETE", "ARRAY_GET", "ARRAY_SIZE", "ADUNARE",
  "SCADERE", "INMULTIRE", "IMPARTIRE", "INCREMENT", "DECREMENT", "EQUAL",
  "NEQUAL", "LOWER", "LEQ", "GREATER", "GEQ", "AND", "OR", "ASSIGN",
  "PRINT", "STRUCT_BEGIN", "STRUCT_END", "STRUCT_TYPE", "FUNCTION_BEGIN",
  "FUNCTION_END", "FUNCTION_TYPE", "RETURN", "COMMENT", "IF_BEGIN",
  "IF_END", "ELSE_BEGIN", "ELSE_END", "WHILE_BEGIN", "WHILE_END",
  "FOR_BEGIN", "FOR_END", "NUMBER", "NUMBER_FLOAT", "ID", "ANYTHING",
  "VALUE_CHR", "'('", "')'", "','", "':'", "';'", "'.'", "$accept",
  "afisare", "function_decl", "lista_param", "param", "block_function",
  "structure", "block_struct", "struct_statement", "progr", "global",
  "block_global", "global_statement", "fnc_str", "block_fnc_str",
  "fnc_str_statement", "main", "block_main", "main_statement",
  "function_call", "call_param_list", "call_param", "control_statement",
  "control_if", "if_begin", "block_if", "control_else", "else_begin",
  "block_else", "control_while", "while_begin", "block_while",
  "control_for", "for_begin", "for_condition", "for_init", "for_increment",
  "block_for", "declaratii", "tip", "variable", "expr", "math_expr",
  "struct_member", "boolean_expr", "comment", "array_operation",
  "array_returns", "assignment", YY_NULLPTR
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
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,    40,
      41,    44,    58,    59,    46
};
# endif

#define YYPACT_NINF (-252)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       2,    24,    35,   174,    50,  -252,   226,  -252,  -252,  -252,
    -252,  -252,   406,     8,  -252,   465,  -252,    -3,    20,  -252,
      17,    65,   406,    27,    29,    31,  -252,  -252,  -252,    45,
      47,   406,  -252,  -252,    18,  -252,  -252,   400,    97,    81,
      76,  -252,  -252,   351,    59,    82,  -252,  -252,   305,    98,
    -252,  -252,  -252,    96,    63,    32,  -252,    89,  -252,  -252,
     103,  -252,   119,  -252,   137,    90,  -252,    92,   130,  -252,
    -252,   477,   529,   529,  -252,  -252,   -11,  -252,  -252,   529,
    -252,   574,  -252,  -252,  -252,  -252,    94,   138,   245,   574,
     139,   143,   144,  -252,  -252,   500,  -252,  -252,  -252,  -252,
     529,   529,   406,  -252,  -252,  -252,  -252,  -252,   574,     3,
       3,   151,   153,   145,   461,   529,   529,   529,   529,   529,
     529,   529,   529,   529,   529,   529,   529,   525,   406,   578,
    -252,   159,  -252,     1,   -24,    11,   513,   -30,  -252,  -252,
     574,   574,   156,   157,   162,   167,   188,   191,   187,  -252,
    -252,     3,     3,  -252,  -252,   596,   596,   134,   134,   134,
     134,    70,    70,   406,   194,   195,  -252,  -252,   -25,   192,
     -20,  -252,   199,  -252,   529,  -252,    -9,  -252,   574,    39,
      56,    58,    64,    75,   198,  -252,   197,   200,   207,   529,
     225,   211,  -252,   217,   -13,   212,   506,  -252,   400,   222,
     406,  -252,   484,  -252,   529,  -252,   231,  -252,   232,  -252,
     233,  -252,   235,  -252,   236,  -252,   400,   400,   400,   242,
     244,  -252,   247,   523,  -252,  -252,   251,   252,   142,   220,
    -252,   400,  -252,  -252,  -252,   214,   248,   259,   261,   264,
    -252,   266,  -252,   280,  -252,   326,   273,  -252,  -252,   270,
     271,   435,  -252,  -252,  -252,   170,  -252,   340,  -252,  -252,
    -252,  -252,  -252,   287,  -252,  -252,  -252,  -252,  -252,    53,
    -252,  -252,  -252,  -252,  -252,  -252,  -252,   110,  -252,  -252,
    -252,   281,  -252,   170,  -252,  -252,   400,   265,   282,  -252,
     386,  -252,   304,  -252,  -252,  -252
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     1,     0,    87,    88,    89,
      90,    91,     0,     0,   123,     0,    29,     0,     0,    31,
       0,     0,     0,     0,     0,     0,    27,    28,    30,    76,
       0,     0,    35,    36,     0,    34,    37,     0,     0,     0,
      81,    80,    86,     0,     0,     0,    32,    33,     0,     0,
      58,    66,    70,     0,     0,     0,    40,     0,    47,    53,
       0,    54,     0,    55,     0,     0,    46,     0,     0,    26,
      85,     0,     0,     0,   103,   104,   102,    79,    78,     0,
     107,    77,    99,   105,   101,   106,     0,     0,     0,     2,
       0,     0,     0,   139,   140,     0,    43,    38,    39,    42,
       0,     0,     0,    44,    45,    41,    84,    83,    82,   108,
     109,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      14,     0,    25,     0,     0,     0,     0,     0,   142,   141,
     138,     0,   101,   101,     0,     0,     0,     0,     0,   114,
     100,   110,   111,   112,   113,   115,   116,   117,   118,   119,
     120,   121,   122,     0,     0,     0,    12,    13,     0,     0,
       0,     7,     0,     3,     0,    48,     0,    51,    52,     0,
       0,     0,     0,     0,     0,   135,     0,     0,     0,     0,
       0,     0,   137,     0,     0,     0,     0,    15,     0,     0,
       0,     9,     0,    49,     0,   125,     0,   126,     0,   124,
       0,   128,     0,   127,     0,   134,     0,     0,     0,   101,
       0,   136,     0,     0,    20,    19,     0,     0,     0,     0,
      11,     0,     8,     4,    50,     0,     0,     0,     0,     0,
      60,     0,    68,     0,    75,     0,     0,    72,    24,     0,
       0,     0,    18,    17,    16,     0,    10,     0,   130,   131,
     129,   133,   132,    56,    59,    65,    67,    69,    74,     0,
      71,    73,    23,    22,    21,    94,    95,    92,    98,    97,
      93,     0,    96,     0,    62,    57,     0,     0,     0,    64,
       0,     5,     0,    61,    63,     6
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -252,  -252,  -252,  -252,   147,   118,  -252,  -252,   221,  -252,
    -252,  -252,   343,  -252,  -252,   328,  -252,  -252,   -34,   -37,
    -252,   161,  -252,  -252,  -252,  -252,  -252,  -252,  -252,  -252,
    -252,  -252,  -252,  -252,  -252,  -252,  -252,  -252,     4,     0,
      84,    25,  -252,  -252,   -99,     5,  -252,  -251,   122
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    54,    32,   170,   171,   229,    33,   129,   130,     2,
       4,    15,    16,    21,    34,    35,    38,    55,   230,    80,
     176,   177,    58,    59,    60,   241,   285,   286,   290,    61,
      62,   243,    63,    64,   144,   145,   270,   245,    65,    18,
     281,   141,    82,    83,    84,    66,    67,    85,    68
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      57,   142,   143,    56,   282,     1,    23,    17,    19,   111,
     112,   196,    24,     7,     8,     9,    10,    11,    57,    17,
      19,    98,    39,   223,   184,    36,    46,   117,   118,     3,
     185,    45,   282,    72,    73,     5,   173,   174,   197,    36,
     199,   200,    97,     6,     7,     8,     9,    10,    11,    12,
     224,   203,   204,   113,    49,    30,    30,    20,    31,    31,
      28,   169,    14,    14,    25,    74,    75,    76,    81,    48,
      79,   175,    13,    89,    37,    49,    29,    14,    50,    93,
      94,    43,    51,    40,    52,    41,   131,    42,    53,    95,
     219,   132,   115,   116,   117,   118,   108,   109,   110,   205,
     206,    69,   146,    44,   114,   127,     7,     8,     9,    10,
      11,   128,    71,   114,    91,    92,   207,   208,   209,   210,
     140,    86,    93,    94,   211,   212,    96,   164,   165,   131,
     111,   112,    95,   172,   132,   213,   214,    70,    87,    14,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,    99,   103,    90,   104,   115,   116,   117,   118,
     178,    57,   100,   193,   115,   116,   117,   118,   125,   126,
     119,   120,   121,   122,   123,   124,   125,   126,   101,    57,
      57,    57,   240,   242,   244,     6,     7,     8,     9,    10,
      11,    12,    57,   105,    57,   256,   102,   133,   135,   202,
     172,   149,   136,   137,    57,   254,    57,   264,    57,   266,
     147,   268,   148,    49,    13,   168,   186,   187,   280,    14,
      57,   228,   188,   256,   275,   276,   277,   278,   279,   178,
     189,     6,     7,     8,     9,    10,    11,    12,     7,     8,
       9,    10,    11,    22,   190,   191,   280,   192,   251,    57,
     194,   195,   289,    57,   198,   201,   294,    48,   215,   216,
      13,   220,   217,    49,   255,    14,    50,    72,    73,   218,
      51,   221,    52,   222,   258,   225,    53,     6,     7,     8,
       9,    10,    11,    12,   231,   235,   236,   237,    49,   238,
     239,     6,     7,     8,     9,    10,    11,    12,   247,    74,
      75,    76,   134,    48,    79,   246,    13,   291,   259,    49,
     248,    14,    50,   263,   252,   253,    51,    48,    52,   260,
      13,   261,    53,    49,   262,    14,    50,    72,    73,   269,
      51,   265,    52,   272,   273,   284,    53,     6,     7,     8,
       9,    10,    11,    12,   287,   292,   295,   232,    49,   257,
     167,     6,     7,     8,     9,    10,    11,    12,    27,    74,
      75,    76,    47,    48,    88,   234,    13,   288,   271,    49,
       0,    14,    50,    72,    73,     0,    51,    48,    52,   267,
      13,     0,    53,    49,   283,    14,    50,     0,     0,     0,
      51,     0,    52,     0,    49,     0,    53,     6,     7,     8,
       9,    10,    11,    12,     0,    74,    75,    76,    77,    78,
      79,     6,     7,     8,     9,    10,    11,    12,     7,     8,
       9,    10,    11,    48,     0,     0,    13,     0,     0,    49,
       0,    14,    50,     0,     0,   293,    51,    48,    52,     0,
      13,     0,    53,    49,     0,    14,    50,     0,     0,     0,
      51,     0,    52,     0,     0,     0,    53,   115,   116,   117,
     118,     0,     0,   119,   120,   121,   122,   123,   124,   125,
     126,    26,     0,     0,     0,     0,     6,     7,     8,     9,
      10,    11,    12,   115,   116,   117,   118,     0,     0,   119,
     120,   121,   122,   123,   124,   125,   126,     0,   274,    72,
      73,     0,     0,     0,     0,    13,   115,   116,   117,   118,
      14,     0,   119,   120,   121,   122,   123,   124,   125,   126,
      49,   150,    72,    73,     0,     0,     0,     0,    72,    73,
       0,    74,    75,    76,   106,   107,    79,     7,     8,     9,
      10,    11,   163,    49,   233,    72,    73,     0,     0,    49,
       0,    72,    73,     0,    74,    75,    76,   138,   139,    79,
      74,    75,    76,   226,   227,    79,    49,   179,   180,   181,
     182,   183,    49,     0,     0,     0,     0,    74,    75,    76,
     249,   250,    79,    74,    75,    76,     0,     0,    79,   127,
       7,     8,     9,    10,    11,   128,   115,   116,   117,   118,
       0,     0,   119,   120,   121,   122,   123,   124,   125,   126,
       0,     0,     0,     0,     0,     0,     0,   166,   115,   116,
     117,   118,     0,    14,     0,     0,   121,   122,   123,   124,
     125,   126
};

static const yytype_int16 yycheck[] =
{
      37,   100,   101,    37,   255,     3,     6,     3,     3,    20,
      21,    36,    12,    12,    13,    14,    15,    16,    55,    15,
      15,    55,    22,    36,    54,    20,     8,    24,    25,     5,
      60,    31,   283,    22,    23,     0,    60,    61,    63,    34,
      60,    61,    10,    11,    12,    13,    14,    15,    16,    17,
      63,    60,    61,    64,    43,    38,    38,     7,    41,    41,
      63,    60,    45,    45,    56,    54,    55,    56,    43,    37,
      59,    60,    40,    48,     9,    43,    56,    45,    46,    26,
      27,    36,    50,    56,    52,    56,    86,    56,    56,    36,
     189,    86,    22,    23,    24,    25,    71,    72,    73,    60,
      61,     4,   102,    56,    79,    11,    12,    13,    14,    15,
      16,    17,    36,    88,    18,    19,    60,    61,    60,    61,
      95,    62,    26,    27,    60,    61,    63,   127,   128,   129,
      20,    21,    36,   133,   129,    60,    61,    56,    56,    45,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,    63,    63,    56,    63,    22,    23,    24,    25,
     135,   198,    59,   163,    22,    23,    24,    25,    34,    35,
      28,    29,    30,    31,    32,    33,    34,    35,    59,   216,
     217,   218,   216,   217,   218,    11,    12,    13,    14,    15,
      16,    17,   229,    63,   231,   229,    59,    59,    59,   174,
     200,    56,    59,    59,   241,    63,   243,   241,   245,   243,
      59,   245,    59,    43,    40,    56,    60,    60,   255,    45,
     257,   196,    60,   257,    54,    55,    56,    57,    58,   204,
      63,    11,    12,    13,    14,    15,    16,    17,    12,    13,
      14,    15,    16,    17,    56,    54,   283,    60,   223,   286,
      56,    56,   286,   290,    62,    56,   290,    37,    60,    62,
      40,    36,    62,    43,    44,    45,    46,    22,    23,    62,
      50,    60,    52,    56,    60,    63,    56,    11,    12,    13,
      14,    15,    16,    17,    62,    54,    54,    54,    43,    54,
      54,    11,    12,    13,    14,    15,    16,    17,    54,    54,
      55,    56,    57,    37,    59,    63,    40,    42,    60,    43,
      63,    45,    46,    47,    63,    63,    50,    37,    52,    60,
      40,    60,    56,    43,    60,    45,    46,    22,    23,    56,
      50,    51,    52,    63,    63,    48,    56,    11,    12,    13,
      14,    15,    16,    17,    63,    63,    42,   200,    43,   231,
     129,    11,    12,    13,    14,    15,    16,    17,    15,    54,
      55,    56,    34,    37,    59,   204,    40,   283,   246,    43,
      -1,    45,    46,    22,    23,    -1,    50,    37,    52,    53,
      40,    -1,    56,    43,    44,    45,    46,    -1,    -1,    -1,
      50,    -1,    52,    -1,    43,    -1,    56,    11,    12,    13,
      14,    15,    16,    17,    -1,    54,    55,    56,    57,    58,
      59,    11,    12,    13,    14,    15,    16,    17,    12,    13,
      14,    15,    16,    37,    -1,    -1,    40,    -1,    -1,    43,
      -1,    45,    46,    -1,    -1,    49,    50,    37,    52,    -1,
      40,    -1,    56,    43,    -1,    45,    46,    -1,    -1,    -1,
      50,    -1,    52,    -1,    -1,    -1,    56,    22,    23,    24,
      25,    -1,    -1,    28,    29,    30,    31,    32,    33,    34,
      35,     6,    -1,    -1,    -1,    -1,    11,    12,    13,    14,
      15,    16,    17,    22,    23,    24,    25,    -1,    -1,    28,
      29,    30,    31,    32,    33,    34,    35,    -1,    63,    22,
      23,    -1,    -1,    -1,    -1,    40,    22,    23,    24,    25,
      45,    -1,    28,    29,    30,    31,    32,    33,    34,    35,
      43,    60,    22,    23,    -1,    -1,    -1,    -1,    22,    23,
      -1,    54,    55,    56,    57,    58,    59,    12,    13,    14,
      15,    16,    17,    43,    60,    22,    23,    -1,    -1,    43,
      -1,    22,    23,    -1,    54,    55,    56,    57,    58,    59,
      54,    55,    56,    57,    58,    59,    43,    54,    55,    56,
      57,    58,    43,    -1,    -1,    -1,    -1,    54,    55,    56,
      57,    58,    59,    54,    55,    56,    -1,    -1,    59,    11,
      12,    13,    14,    15,    16,    17,    22,    23,    24,    25,
      -1,    -1,    28,    29,    30,    31,    32,    33,    34,    35,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    39,    22,    23,
      24,    25,    -1,    45,    -1,    -1,    30,    31,    32,    33,
      34,    35
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,    74,     5,    75,     0,    11,    12,    13,    14,
      15,    16,    17,    40,    45,    76,    77,   103,   104,   110,
       7,    78,    17,   104,   104,    56,     6,    77,    63,    56,
      38,    41,    67,    71,    79,    80,   110,     9,    81,   104,
      56,    56,    56,    36,    56,   104,     8,    80,    37,    43,
      46,    50,    52,    56,    66,    82,    83,    84,    87,    88,
      89,    94,    95,    97,    98,   103,   110,   111,   113,     4,
      56,    36,    22,    23,    54,    55,    56,    57,    58,    59,
      84,   106,   107,   108,   109,   112,    62,    56,    59,   106,
      56,    18,    19,    26,    27,    36,    63,    10,    83,    63,
      59,    59,    59,    63,    63,    63,    57,    58,   106,   106,
     106,    20,    21,    64,   106,    22,    23,    24,    25,    28,
      29,    30,    31,    32,    33,    34,    35,    11,    17,    72,
      73,   104,   110,    59,    57,    59,    59,    59,    57,    58,
     106,   106,   109,   109,    99,   100,   104,    59,    59,    56,
      60,   106,   106,   106,   106,   106,   106,   106,   106,   106,
     106,   106,   106,    17,   104,   104,    39,    73,    56,    60,
      68,    69,   104,    60,    61,    60,    85,    86,   106,    54,
      55,    56,    57,    58,    54,    60,    60,    60,    60,    63,
      56,    54,    60,   104,    56,    56,    36,    63,    62,    60,
      61,    56,   106,    60,    61,    60,    61,    60,    61,    60,
      61,    60,    61,    60,    61,    60,    62,    62,    62,   109,
      36,    60,    56,    36,    63,    63,    57,    58,   106,    70,
      83,    62,    69,    60,    86,    54,    54,    54,    54,    54,
      83,    90,    83,    96,    83,   102,    63,    54,    63,    57,
      58,   106,    63,    63,    63,    44,    83,    70,    60,    60,
      60,    60,    60,    47,    83,    51,    83,    53,    83,    56,
     101,   113,    63,    63,    63,    54,    55,    56,    57,    58,
      84,   105,   112,    44,    48,    91,    92,    63,   105,    83,
      93,    42,    63,    49,    83,    42
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    65,    66,    66,    66,    67,    67,    68,    68,    69,
      70,    70,    71,    72,    72,    73,    73,    73,    73,    73,
      73,    73,    73,    73,    73,    73,    74,    75,    76,    76,
      77,    77,    78,    79,    79,    80,    80,    80,    81,    82,
      82,    83,    83,    83,    83,    83,    83,    83,    84,    84,
      85,    85,    86,    87,    87,    87,    88,    88,    89,    90,
      90,    91,    92,    93,    93,    94,    95,    96,    96,    97,
      98,    99,   100,   101,   102,   102,   103,   103,   103,   103,
     103,   103,   103,   103,   103,   103,   103,   104,   104,   104,
     104,   104,   105,   105,   105,   105,   105,   105,   105,   106,
     106,   106,   107,   107,   107,   107,   107,   107,   107,   107,
     107,   107,   107,   107,   108,   109,   109,   109,   109,   109,
     109,   109,   109,   110,   111,   111,   111,   111,   111,   111,
     111,   111,   111,   111,   111,   111,   112,   112,   113,   113,
     113,   113,   113
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     4,     6,    11,    12,     1,     3,     2,
       2,     1,     5,     2,     1,     3,     5,     5,     5,     4,
       4,     6,     6,     6,     5,     1,     5,     3,     2,     1,
       2,     1,     3,     2,     1,     1,     1,     1,     3,     2,
       1,     2,     2,     2,     2,     2,     1,     1,     4,     5,
       3,     1,     1,     1,     1,     1,     7,     8,     1,     2,
       1,     3,     1,     2,     1,     7,     1,     2,     1,     7,
       1,     5,     4,     1,     2,     1,     2,     4,     4,     4,
       3,     3,     5,     5,     5,     4,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       3,     1,     1,     1,     1,     1,     1,     1,     2,     2,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     1,     5,     5,     5,     5,     5,     7,
       7,     7,     7,     7,     5,     4,     5,     4,     3,     2,
       2,     3,     3
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
#line 119 "limbaj.y"
                                                   { afisare_var((yyvsp[0].strct)); }
#line 1775 "y.tab.c"
    break;

  case 3:
#line 120 "limbaj.y"
                                                   { printf("Print: %s\n", (yyvsp[-1].sir_var)); }
#line 1781 "y.tab.c"
    break;

  case 4:
#line 121 "limbaj.y"
                                                   { afisare_sir_var((yyvsp[-3].sir_var),(yyvsp[-1].strct)); }
#line 1787 "y.tab.c"
    break;

  case 5:
#line 125 "limbaj.y"
                                                                                                                   { insertFun((yyvsp[-9].type_id),(yyvsp[-8].nume_var),(yyvsp[-2].strct)); }
#line 1793 "y.tab.c"
    break;

  case 6:
#line 126 "limbaj.y"
                                                                                                                   { insertFunParam((yyvsp[-10].type_id),(yyvsp[-9].nume_var),(yyvsp[-7].strct_param),(yyvsp[-2].strct)); }
#line 1799 "y.tab.c"
    break;

  case 7:
#line 129 "limbaj.y"
                                        { (yyval.strct_param) = insertFirstParam((yyvsp[0].type_id)); }
#line 1805 "y.tab.c"
    break;

  case 8:
#line 130 "limbaj.y"
                                        { insertParam((yyval.strct_param),(yyvsp[0].type_id)); }
#line 1811 "y.tab.c"
    break;

  case 9:
#line 133 "limbaj.y"
                                        { (yyval.type_id) = (yyvsp[-1].type_id); }
#line 1817 "y.tab.c"
    break;

  case 12:
#line 142 "limbaj.y"
                                                            { def_structura((yyvsp[-3].nume_var)); }
#line 1823 "y.tab.c"
    break;

  case 15:
#line 149 "limbaj.y"
                                                                      { add_struct_member((yyvsp[-1].nume_var)); }
#line 1829 "y.tab.c"
    break;

  case 16:
#line 150 "limbaj.y"
                                                                      { add_struct_member((yyvsp[-3].nume_var)); }
#line 1835 "y.tab.c"
    break;

  case 17:
#line 151 "limbaj.y"
                                                                      { add_struct_member((yyvsp[-3].nume_var)); }
#line 1841 "y.tab.c"
    break;

  case 18:
#line 152 "limbaj.y"
                                                                      { add_struct_member((yyvsp[-3].nume_var)); }
#line 1847 "y.tab.c"
    break;

  case 19:
#line 153 "limbaj.y"
                                                                      { add_struct_member((yyvsp[-1].nume_var)); }
#line 1853 "y.tab.c"
    break;

  case 20:
#line 154 "limbaj.y"
                                                                      { printf("Const variables must be initialized at declaration!\n"); yyerror((yyvsp[-1].nume_var)); exit(0); }
#line 1859 "y.tab.c"
    break;

  case 21:
#line 155 "limbaj.y"
                                                                      { add_struct_member((yyvsp[-3].nume_var)); }
#line 1865 "y.tab.c"
    break;

  case 22:
#line 156 "limbaj.y"
                                                                      { add_struct_member((yyvsp[-3].nume_var)); }
#line 1871 "y.tab.c"
    break;

  case 23:
#line 157 "limbaj.y"
                                                                      { add_struct_member((yyvsp[-3].nume_var)); }
#line 1877 "y.tab.c"
    break;

  case 24:
#line 158 "limbaj.y"
                                                                      { printf("Const arrays cannot be declared!\n"); yyerror((yyvsp[-1].nume_var)); exit(0); }
#line 1883 "y.tab.c"
    break;

  case 26:
#line 162 "limbaj.y"
                                                       { print_tables(); printf("Exit succesfully\n"); exit(0); }
#line 1889 "y.tab.c"
    break;

  case 27:
#line 165 "limbaj.y"
                                                       { CURR_SCOPE=INC_SCOPE; }
#line 1895 "y.tab.c"
    break;

  case 32:
#line 177 "limbaj.y"
                                                       { CURR_SCOPE=1; }
#line 1901 "y.tab.c"
    break;

  case 48:
#line 206 "limbaj.y"
                                                            { (yyval.strct) = callFunctionSimple((yyvsp[-2].nume_var)); }
#line 1907 "y.tab.c"
    break;

  case 49:
#line 207 "limbaj.y"
                                                            { (yyval.strct) = callFunctionComplex((yyvsp[-3].nume_var),(yyvsp[-1].strct_param)); }
#line 1913 "y.tab.c"
    break;

  case 50:
#line 210 "limbaj.y"
                                                  { insertParam((yyval.strct_param), (yyvsp[0].strct)->tip); }
#line 1919 "y.tab.c"
    break;

  case 51:
#line 211 "limbaj.y"
                                                  { (yyval.strct_param) = insertFirstParam((yyvsp[0].strct)->tip); }
#line 1925 "y.tab.c"
    break;

  case 52:
#line 214 "limbaj.y"
                              { (yyval.strct) = (yyvsp[0].strct); }
#line 1931 "y.tab.c"
    break;

  case 56:
#line 224 "limbaj.y"
                                                                                 { CURR_SCOPE=1; }
#line 1937 "y.tab.c"
    break;

  case 57:
#line 225 "limbaj.y"
                                                                                 { CURR_SCOPE=1; }
#line 1943 "y.tab.c"
    break;

  case 58:
#line 228 "limbaj.y"
                         { CURR_SCOPE=++INC_SCOPE; }
#line 1949 "y.tab.c"
    break;

  case 61:
#line 236 "limbaj.y"
                                                  { CURR_SCOPE=1; }
#line 1955 "y.tab.c"
    break;

  case 62:
#line 239 "limbaj.y"
                         { CURR_SCOPE=++INC_SCOPE; }
#line 1961 "y.tab.c"
    break;

  case 65:
#line 247 "limbaj.y"
                                                                                 { CURR_SCOPE=1; }
#line 1967 "y.tab.c"
    break;

  case 66:
#line 250 "limbaj.y"
                              { CURR_SCOPE=++INC_SCOPE; }
#line 1973 "y.tab.c"
    break;

  case 69:
#line 258 "limbaj.y"
                                                                           { CURR_SCOPE=1; }
#line 1979 "y.tab.c"
    break;

  case 70:
#line 261 "limbaj.y"
                         { CURR_SCOPE=++INC_SCOPE; }
#line 1985 "y.tab.c"
    break;

  case 76:
#line 278 "limbaj.y"
                                                   { decl_var_simple((yyvsp[-1].type_id), (yyvsp[0].nume_var), 0); }
#line 1991 "y.tab.c"
    break;

  case 77:
#line 279 "limbaj.y"
                                                   { decl_var_expr((yyvsp[-3].type_id), (yyvsp[-2].nume_var), (yyvsp[0].strct), 0); }
#line 1997 "y.tab.c"
    break;

  case 78:
#line 280 "limbaj.y"
                                                   { decl_var_assign_str((yyvsp[-3].type_id), (yyvsp[-2].nume_var), (yyvsp[0].sir_var), 0); }
#line 2003 "y.tab.c"
    break;

  case 79:
#line 281 "limbaj.y"
                                                   { decl_var_assign_str((yyvsp[-3].type_id), (yyvsp[-2].nume_var), (yyvsp[0].sir_var), 0); }
#line 2009 "y.tab.c"
    break;

  case 80:
#line 282 "limbaj.y"
                                                   { decl_arr_simple((yyvsp[-1].type_id), (yyvsp[0].nume_var), 0); }
#line 2015 "y.tab.c"
    break;

  case 81:
#line 283 "limbaj.y"
                                                   { printf("Const variables must be initialized at declaration!\n"); yyerror((yyvsp[0].nume_var)); exit(0); }
#line 2021 "y.tab.c"
    break;

  case 82:
#line 284 "limbaj.y"
                                                   { decl_var_expr((yyvsp[-3].type_id), (yyvsp[-2].nume_var), (yyvsp[0].strct), 1); }
#line 2027 "y.tab.c"
    break;

  case 83:
#line 285 "limbaj.y"
                                                   { decl_var_assign_str((yyvsp[-3].type_id), (yyvsp[-2].nume_var), (yyvsp[0].sir_var), 1); }
#line 2033 "y.tab.c"
    break;

  case 84:
#line 286 "limbaj.y"
                                                   { decl_var_assign_str((yyvsp[-3].type_id), (yyvsp[-2].nume_var), (yyvsp[0].sir_var), 1); }
#line 2039 "y.tab.c"
    break;

  case 85:
#line 287 "limbaj.y"
                                                   { printf("Const arrays cannot be declared!\n"); yyerror((yyvsp[0].nume_var)); exit(0); }
#line 2045 "y.tab.c"
    break;

  case 86:
#line 288 "limbaj.y"
                                                   { decl_struct_var((yyvsp[-1].nume_var), (yyvsp[0].nume_var)); }
#line 2051 "y.tab.c"
    break;

  case 87:
#line 292 "limbaj.y"
               { (yyval.type_id)=0; }
#line 2057 "y.tab.c"
    break;

  case 88:
#line 293 "limbaj.y"
               { (yyval.type_id)=1; }
#line 2063 "y.tab.c"
    break;

  case 89:
#line 294 "limbaj.y"
               { (yyval.type_id)=2; }
#line 2069 "y.tab.c"
    break;

  case 90:
#line 295 "limbaj.y"
               { (yyval.type_id)=3; }
#line 2075 "y.tab.c"
    break;

  case 91:
#line 296 "limbaj.y"
               { (yyval.type_id)=4; }
#line 2081 "y.tab.c"
    break;

  case 92:
#line 299 "limbaj.y"
                                   { (yyval.strct) = moveVar((yyvsp[0].nume_var)); }
#line 2087 "y.tab.c"
    break;

  case 93:
#line 300 "limbaj.y"
                                      { (yyval.strct) = moveFunc((yyvsp[0].strct)); }
#line 2093 "y.tab.c"
    break;

  case 94:
#line 301 "limbaj.y"
                                   { (yyval.strct) = moveNum((yyvsp[0].num), 0); }
#line 2099 "y.tab.c"
    break;

  case 95:
#line 302 "limbaj.y"
                                   { (yyval.strct) = moveNum((yyvsp[0].num), 1); }
#line 2105 "y.tab.c"
    break;

  case 96:
#line 303 "limbaj.y"
                                   { (yyval.strct) = moveArray((yyvsp[0].strct)); }
#line 2111 "y.tab.c"
    break;

  case 97:
#line 304 "limbaj.y"
                                   { (yyval.strct) = moveSir((yyvsp[0].sir_var), 2); }
#line 2117 "y.tab.c"
    break;

  case 98:
#line 305 "limbaj.y"
                                   { (yyval.strct) = moveSir((yyvsp[0].sir_var), 3); }
#line 2123 "y.tab.c"
    break;

  case 99:
#line 308 "limbaj.y"
                                   { (yyval.strct) = (yyvsp[0].strct); }
#line 2129 "y.tab.c"
    break;

  case 100:
#line 309 "limbaj.y"
                                   { (yyval.strct) = (yyvsp[-1].strct); }
#line 2135 "y.tab.c"
    break;

  case 101:
#line 310 "limbaj.y"
                                   { (yyval.strct) = (yyvsp[0].strct); }
#line 2141 "y.tab.c"
    break;

  case 102:
#line 313 "limbaj.y"
                                   { (yyval.strct) = moveVar((yyvsp[0].nume_var)); }
#line 2147 "y.tab.c"
    break;

  case 103:
#line 314 "limbaj.y"
                                   { (yyval.strct) = moveNum((yyvsp[0].num), 0); }
#line 2153 "y.tab.c"
    break;

  case 104:
#line 315 "limbaj.y"
                                   { (yyval.strct) = moveNum((yyvsp[0].num), 1); }
#line 2159 "y.tab.c"
    break;

  case 105:
#line 316 "limbaj.y"
                                   { (yyval.strct) = (yyvsp[0].strct); }
#line 2165 "y.tab.c"
    break;

  case 106:
#line 317 "limbaj.y"
                                   { (yyval.strct) = (yyvsp[0].strct); }
#line 2171 "y.tab.c"
    break;

  case 107:
#line 318 "limbaj.y"
                                   { (yyval.strct) = (yyvsp[0].strct); }
#line 2177 "y.tab.c"
    break;

  case 108:
#line 319 "limbaj.y"
                                   { (yyval.strct) = expr_calc_single((yyvsp[0].strct), 0); }
#line 2183 "y.tab.c"
    break;

  case 109:
#line 320 "limbaj.y"
                                   { (yyval.strct) = expr_calc_single((yyvsp[0].strct), 1); }
#line 2189 "y.tab.c"
    break;

  case 110:
#line 321 "limbaj.y"
                                   { (yyval.strct) = expr_calc_double((yyvsp[-2].strct), (yyvsp[0].strct), 0); }
#line 2195 "y.tab.c"
    break;

  case 111:
#line 322 "limbaj.y"
                                   { (yyval.strct) = expr_calc_double((yyvsp[-2].strct), (yyvsp[0].strct), 1); }
#line 2201 "y.tab.c"
    break;

  case 112:
#line 323 "limbaj.y"
                                   { (yyval.strct) = expr_calc_double((yyvsp[-2].strct), (yyvsp[0].strct), 2); }
#line 2207 "y.tab.c"
    break;

  case 113:
#line 324 "limbaj.y"
                                   { (yyval.strct) = expr_calc_double((yyvsp[-2].strct), (yyvsp[0].strct), 3); }
#line 2213 "y.tab.c"
    break;

  case 114:
#line 327 "limbaj.y"
                                   { (yyval.strct) = moveStructMember((yyvsp[-2].nume_var), (yyvsp[0].nume_var)); }
#line 2219 "y.tab.c"
    break;

  case 115:
#line 332 "limbaj.y"
                                      { (yyval.strct) = expr_calc_double((yyvsp[-2].strct), (yyvsp[0].strct), 4); }
#line 2225 "y.tab.c"
    break;

  case 116:
#line 333 "limbaj.y"
                                      { (yyval.strct) = expr_calc_double((yyvsp[-2].strct), (yyvsp[0].strct), 5); }
#line 2231 "y.tab.c"
    break;

  case 117:
#line 334 "limbaj.y"
                                      { (yyval.strct) = expr_calc_double((yyvsp[-2].strct), (yyvsp[0].strct), 6); }
#line 2237 "y.tab.c"
    break;

  case 118:
#line 335 "limbaj.y"
                                      { (yyval.strct) = expr_calc_double((yyvsp[-2].strct), (yyvsp[0].strct), 7); }
#line 2243 "y.tab.c"
    break;

  case 119:
#line 336 "limbaj.y"
                                      { (yyval.strct) = expr_calc_double((yyvsp[-2].strct), (yyvsp[0].strct), 8); }
#line 2249 "y.tab.c"
    break;

  case 120:
#line 337 "limbaj.y"
                                      { (yyval.strct) = expr_calc_double((yyvsp[-2].strct), (yyvsp[0].strct), 9); }
#line 2255 "y.tab.c"
    break;

  case 121:
#line 338 "limbaj.y"
                                      { (yyval.strct) = expr_calc_double((yyvsp[-2].strct), (yyvsp[0].strct), 10); }
#line 2261 "y.tab.c"
    break;

  case 122:
#line 339 "limbaj.y"
                                      { (yyval.strct) = expr_calc_double((yyvsp[-2].strct), (yyvsp[0].strct), 11); }
#line 2267 "y.tab.c"
    break;

  case 124:
#line 345 "limbaj.y"
                                                                         { array_insert_id((yyvsp[-4].nume_var), (yyvsp[-1].nume_var)); }
#line 2273 "y.tab.c"
    break;

  case 125:
#line 346 "limbaj.y"
                                                                         { array_insert_nr((yyvsp[-4].nume_var), (yyvsp[-1].num), 0); }
#line 2279 "y.tab.c"
    break;

  case 126:
#line 347 "limbaj.y"
                                                                         { array_insert_nr((yyvsp[-4].nume_var), (yyvsp[-1].num), 1); }
#line 2285 "y.tab.c"
    break;

  case 127:
#line 348 "limbaj.y"
                                                                         { array_insert_str((yyvsp[-4].nume_var), (yyvsp[-1].sir_var), 2); }
#line 2291 "y.tab.c"
    break;

  case 128:
#line 349 "limbaj.y"
                                                                         { array_insert_str((yyvsp[-4].nume_var), (yyvsp[-1].sir_var), 3); }
#line 2297 "y.tab.c"
    break;

  case 129:
#line 350 "limbaj.y"
                                                                         { array_insert_id_pos((yyvsp[-6].nume_var), (yyvsp[-3].nume_var), (yyvsp[-1].num)); }
#line 2303 "y.tab.c"
    break;

  case 130:
#line 351 "limbaj.y"
                                                                         { array_insert_nr_pos((yyvsp[-6].nume_var), (yyvsp[-3].num), (yyvsp[-1].num), 0); }
#line 2309 "y.tab.c"
    break;

  case 131:
#line 352 "limbaj.y"
                                                                         { array_insert_nr_pos((yyvsp[-6].nume_var), (yyvsp[-3].num), (yyvsp[-1].num), 1); }
#line 2315 "y.tab.c"
    break;

  case 132:
#line 353 "limbaj.y"
                                                                         { array_insert_str_pos((yyvsp[-6].nume_var), (yyvsp[-3].sir_var), (yyvsp[-1].num), 2); }
#line 2321 "y.tab.c"
    break;

  case 133:
#line 354 "limbaj.y"
                                                                         { array_insert_str_pos((yyvsp[-6].nume_var), (yyvsp[-3].sir_var), (yyvsp[-1].num), 3); }
#line 2327 "y.tab.c"
    break;

  case 134:
#line 355 "limbaj.y"
                                                                         { array_delete_pos((yyvsp[-4].nume_var), (yyvsp[-1].num)); }
#line 2333 "y.tab.c"
    break;

  case 135:
#line 356 "limbaj.y"
                                                                         { array_delete((yyvsp[-3].nume_var)); }
#line 2339 "y.tab.c"
    break;

  case 136:
#line 360 "limbaj.y"
                                                            { (yyval.strct) = array_get_value((yyvsp[-4].nume_var), (yyvsp[-1].num)); }
#line 2345 "y.tab.c"
    break;

  case 137:
#line 361 "limbaj.y"
                                                            { (yyval.strct) = array_get_size((yyvsp[-3].nume_var)); }
#line 2351 "y.tab.c"
    break;

  case 138:
#line 364 "limbaj.y"
                                         { id_assign_var((yyvsp[-2].nume_var), (yyvsp[0].strct)); }
#line 2357 "y.tab.c"
    break;

  case 139:
#line 365 "limbaj.y"
                                       { inc_dec_val((yyvsp[-1].nume_var), 1); }
#line 2363 "y.tab.c"
    break;

  case 140:
#line 366 "limbaj.y"
                                       { inc_dec_val((yyvsp[-1].nume_var), -1); }
#line 2369 "y.tab.c"
    break;

  case 141:
#line 367 "limbaj.y"
                                       { id_assign_str((yyvsp[-2].nume_var), (yyvsp[0].sir_var), 2); }
#line 2375 "y.tab.c"
    break;

  case 142:
#line 368 "limbaj.y"
                                       { id_assign_str((yyvsp[-2].nume_var), (yyvsp[0].sir_var), 3); }
#line 2381 "y.tab.c"
    break;


#line 2385 "y.tab.c"

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
#line 371 "limbaj.y"


struct var* moveStructMember(char* id, char* member)
{
     int index=-1;
     for(int i=0;i<struct_count;++i)
     {
          if(strcmp(struct_table[i].nume,id)==0)
          {
               index=i;
          }
     }
     if(index==-1)
     {
          printf("Structure not defined!\n");
          yyerror(id);
          exit(0);
     }
     else
     {
          int flag=-1;
          for(int i=0;i<struct_table[index].member_nr;++i)
          {
               if(strcmp(member,struct_table[index].member_name[i])==0)
               {
                    flag=0;
               }
          }
          if(flag==-1)
          {
               printf("Structure does not have that member!\n");
               yyerror(id);
               exit(0);
          }
          else
          {
               struct var* v=(struct var*)malloc(sizeof(struct var));
               v->valoare_num=0;
               v->tip=0;
               return v;
          }
     }
}

int init_global_scope()
{
     for(int i=0;i<var_count;++i)
     {
          var_table[i].scope=CURR_SCOPE;
     }

     for(int i=0;i<arr_count;++i)
     {
          for(int j=0;j<arr_size[i];++j)
          {
               arr_table[i][j].scope=CURR_SCOPE;        
          }
     }
}

int decl_struct_var(char *nume_struct, char* nume_var)
{
     int index=-1;
     for(int i=0;i<struct_count;++i)
     {
          if(strcmp(struct_table[i].nume,nume_struct)==0)
          {
               index=i;
          }
     }
     if(index==-1)
     {
          printf("Structure not defined!\n");
          yyerror(nume_struct);
          exit(0);
     }
     strcpy(struct_table[index].var_declared[struct_table[index].var_decl_nr],nume_var);
     struct_table[index].var_decl_nr++;
}

int def_structura(char* nume_struct)
{
     int index=-1;
     for(int i=0;i<struct_count;++i)
     {
          if(strcmp(struct_table[i].nume,nume_struct)==0)
          {
               index=i;
          }
     }
     if(index!=-1)
     {
          printf("Structure already defined!\n");
          yyerror(nume_struct);
          exit(0);
     }
     strcpy(struct_table[struct_count].nume,nume_struct);
     struct_table[struct_count].var_decl_nr=0;
     struct_count++;
}

int add_struct_member(char *nume)
{
     for(int i=0;i<struct_table[struct_count].member_nr;++i)
     {
          if(strcmp(struct_table[struct_count].member_name[i],nume)==0)
          {
               printf("Struct member already declared.\n");
               yyerror(nume);
               exit(0);
          }
     }
     struct_table[struct_count].member_nr++; 
     strcpy(struct_table[struct_count].member_name[struct_table[struct_count].member_nr-1],nume);
}

int decl_var_expr(int tip, char* id, struct var* v, int cnst)
{
     int index=get_var_index(id);
     if(index!=-1 && CURR_SCOPE==var_table[index].scope)
     {
          printf("Variable already declared!\n");
          yyerror(id);
          exit(0);
     }

     if(tip!=v->tip)
     {
          printf("Types not matching!\n");
          yyerror(id);
          exit(0);
     }

     strcpy(var_table[var_count].nume, id);

     var_table[var_count].valoare_num=v->valoare_num;
     var_table[var_count].tip=tip;

     var_table[var_count].constant=cnst;
     strcpy(var_table[var_count].valoare_sir, v->valoare_sir);

     var_table[var_count].scope=CURR_SCOPE;
     var_count++;
}

void print_tables()
{
     int fd;
     if(-1 == (fd=open("symbol_table.txt", O_CREAT | O_RDWR, 0777)))
     {
          printf("Eroare deschidere fisier symbol table.\n");
          exit(0);
     }

     char line[2*MAX_SIZE];
     for(int i=0;i<var_count;++i)
     {
          sprintf(line,"Nume: %s, ",var_table[i].nume);

          switch(var_table[i].tip)
          {
               case 0:
                    strcat(line,"tip: integer, ");
                    write(fd,line,strlen(line));
                    sprintf(line,"valoare: %.0f, ",var_table[i].valoare_num);
                    break;
               case 1:
                    strcat(line,"tip: float, ");
                    write(fd,line,strlen(line));
                    sprintf(line,"valoare: %lf, ",var_table[i].valoare_num);
                    break;
               case 2:
                    strcat(line,"tip: char, ");
                    write(fd,line,strlen(line));
                    sprintf(line,"valoare: %c, ",var_table[i].valoare_sir[0]);
                    break;
               case 3:
                    strcat(line,"tip: string, ");
                    write(fd,line,strlen(line));
                    sprintf(line,"valoare: %s, ",var_table[i].valoare_sir);
                    break;
               case 4:
                    strcat(line,"tip: bool, ");
                    write(fd,line,strlen(line));
                    if(var_table[i].valoare_num==0)
                    {
                         sprintf(line,"valoare: false, ");
                    }
                    else
                    {
                         sprintf(line,"valoare: true, ");
                    }
                    break;
          }

          if(var_table[i].constant==1)
          {
               strcat(line,"constant: 1\n");
          }
          else
          {
               strcat(line,"constant: 0\n");
          }
          write(fd,line,strlen(line));
     }

     for(int i=0;i<arr_count;++i)
     {
          sprintf(line,"Nume: %s, ",arr_table[i][0].nume);

          switch(arr_table[i][0].tip)
          {
               case 0:
                    strcat(line,"tip: array integer, ");
                    write(fd,line,strlen(line));
                    for(int j=0;j<arr_size[i];++j)
                    {
                         sprintf(line,"valoare %d: %.0f, ",j,arr_table[i][j].valoare_num);
                         write(fd,line,strlen(line));
                    }
                    break;
               case 1:
                    strcat(line,"tip: array float, ");
                    write(fd,line,strlen(line));
                    for(int j=0;j<arr_size[i];++j)
                    {
                         sprintf(line,"valoare %d: %lf, ",j,arr_table[i][j].valoare_num);
                         write(fd,line,strlen(line));
                    }
                    break;
               case 2:
                    strcat(line,"tip: array char, ");
                    write(fd,line,strlen(line));
                    for(int j=0;j<arr_size[i];++j)
                    {
                         sprintf(line,"valoare %d: %c, ",j,arr_table[i][j].valoare_sir[0]);
                         write(fd,line,strlen(line));
                    }
                    break;
               case 3:
                    strcat(line,"tip: array string, ");
                    write(fd,line,strlen(line));
                    for(int j=0;j<arr_size[i];++j)
                    {
                         sprintf(line,"valoare %d: %s, ",j,arr_table[i][j].valoare_sir);
                         write(fd,line,strlen(line));
                    }
                    break;
               case 4:
                    strcat(line,"tip: array bool, ");
                    write(fd,line,strlen(line));
                    for(int j=0;j<arr_size[i];++j)
                    {
                         if(arr_table[i][j].valoare_num==0)
                         {
                              sprintf(line,"valoare %d: false, ",j);
                         }
                         else
                         {
                              sprintf(line,"valoare %d: true, ",j);
                         }  
                         write(fd,line,strlen(line));
                    }
                    break;
          }

          if(arr_table[i][0].constant==1)
          {
               sprintf(line,"constant: 1\n");
          }
          else
          {
               sprintf(line,"constant: 0\n");
          }
          write(fd,line,strlen(line));
     }

     for(int i=0;i<struct_count;++i)
     {
          sprintf(line,"Nume structura: %s, ",struct_table[i].nume);
          write(fd,line,strlen(line));

          for(int j=0;j<struct_table[i].member_nr;++j)
          {
               sprintf(line,"Camp %d: %s, ",j,struct_table[i].member_name[j]);
               write(fd,line,strlen(line));
          }
     }

     close(fd);

     if(-1 == (fd=open("symbol_table_functions.txt", O_CREAT | O_RDWR, 0777)))
     {
          printf("Eroare deschidere fisier symbol table.\n");
          exit(0);
     }

     for(int i=0;i<fun_count;++i)
     {
          sprintf(line,"Nume: %s, ",fun_table[i].nume);

          switch(fun_table[i].tip)
          {
               case 0:
                    strcat(line,"tip: integer, ");
                    break;
               case 1:
                    strcat(line,"tip: float, ");
                    break;
               case 2:
                    strcat(line,"tip: char, ");
                    break;
               case 3:
                    strcat(line,"tip: string, ");
                    break;
               case 4:
                    strcat(line,"tip: bool, ");
                    break;
          }
          write(fd,line,strlen(line));

          for(int j=0;j<fun_table[i].param->param_nr;++j)
          {
               switch(fun_table[i].param->param_tip[j])
               {
                    case 0:
                         sprintf(line,"parametru %d: integer, ",j);
                         break;
                    case 1:
                         sprintf(line,"parametru %d: float, ",j);
                         break;
                    case 2:
                         sprintf(line,"parametru %d: char, ",j);
                         break;
                    case 3:
                         sprintf(line,"parametru %d: string, ",j);
                         break;
                    case 4:
                         sprintf(line,"parametru %d: bool, ",j);
                         break;
               }
               write(fd,line,strlen(line));
          }
     }

     close(fd);
}

struct parametri* insertFirstParam(int tip)
{
     struct parametri* p = (struct parametri*)malloc(sizeof(struct parametri));

     p->param_nr=1;
     p->param_tip[0]=tip;

     return p;
}

struct var* moveFunc(struct var* v)
{
     int index=get_var_index(v->nume);
     if(index==-1)
     {
          printf("Function undeclared\n");
          yyerror(v->nume);
          exit(0);
     }
     else
     {
          struct var* aux=(struct var*)malloc(sizeof(struct var));
          memcpy(aux,v,sizeof(struct var));
          return aux;
     }
}

int verify_param(struct parametri* p,struct parametri* r)
{
     if(p->param_nr!=r->param_nr)
     {
          return 0;
     }
     for(int i=0;i<p->param_nr;++i)
     {
          if(p->param_tip[i]!=r->param_tip[i])
          {
               return 0;
          }
     }
     return 1;
}

int get_fun_index(char *id, struct parametri* p)
{
     if(p==NULL)
     {
          for(int i=0;i<fun_count;++i)
          {
               if(strcmp(id,fun_table[i].nume)==0)
               {
                    return i;
               }
          }
     }
     else
     {
          for(int i=0; i<fun_count; i++)
          {
               if(strcmp(id, fun_table[i].nume)==0 && verify_param(fun_table[i].param,p))
               {
                    return i;
               }
          }
     }
     
     return -1;
}

struct var* callFunctionSimple(char *id)
{
     int index=get_fun_index(id,NULL);
     if(index==-1)
     {
          printf("Function undeclared!\n");
          yyerror(id);
          exit(0);
     }

     struct var* v=(struct var*)malloc(sizeof(struct var));
     memcpy(v,fun_table[index].return_val,sizeof(struct var));

     return v;
}

struct var* callFunctionComplex(char *id, struct parametri* p)
{
     int index=get_fun_index(id,p);
     if(index==-1)
     {
          printf("Function undeclared\n");
          yyerror(id);
          exit(0);
     }

     struct var* v=(struct var*)malloc(sizeof(struct var));
     memcpy(v,fun_table[index].return_val,sizeof(struct var));

     return v;
}

struct var* array_get_size(char *id)
{
     struct var* v=(struct var*)malloc(sizeof(struct var));

     v->tip=0;

     int index=get_arr_index(id);
     if(index==-1)
     {
          printf("Array undeclared!\n");
          yyerror(id);
          exit(0);
     }
     v->valoare_num=arr_size[index];

     return v;
}

int array_insert_str(char* id, char* str, int tip)
{
     int arr_index=get_arr_index(id);
     if(arr_table[arr_index][0].tip!=tip)
     {
          printf("Array type clash!\n");
          yyerror(id);
          exit(0);
     }
     else
     {
          if(arr_size[arr_index]>=MAX_SIZE)
          {
               printf("Array insert position out of bound!\n");
               yyerror(id);
               exit(0);
          }
          else
          {
               strcpy(arr_table[arr_index][arr_size[arr_index]].valoare_sir, str);
               arr_table[arr_index][arr_size[arr_index]].tip=tip;
               arr_size[arr_index]++;
          }
     }
     return 1;
}

int array_insert_str_pos(char* id, char* val, int insert_pos, int tip)
{
     int arr_index=get_arr_index(id);
     if(arr_table[arr_index][0].tip!=tip)
     {
          printf("Array type clash!\n");
          yyerror(id);
          exit(0);
     }
     else
     {
          if(insert_pos<0 || insert_pos>=arr_size[arr_index] || arr_size[arr_index]>=MAX_SIZE)
          {
               printf("Array insert position out of bound!\n");
               yyerror(id);
               exit(0);
          }
          else
          {
               for(int i=arr_size[arr_index]; i>insert_pos; i--)
               {
                    memcpy(&arr_table[arr_index][i], &arr_table[arr_index][i-1], sizeof(struct var));
               }
               
               strcpy(arr_table[arr_index][insert_pos].valoare_sir, val);
               arr_table[arr_index][insert_pos].tip=tip;
               arr_size[arr_index]++;
          }
     }
     return 1;
}

int array_insert_nr_pos(char* id, double val, int insert_pos, int tip)
{
     int arr_index=get_arr_index(id);
     if(arr_table[arr_index][0].tip!=tip)
     {
          printf("Array type clash!\n");
          yyerror(id);
          exit(0);
     }
     else
     {
          if(insert_pos<0 || insert_pos>=arr_size[arr_index] || arr_size[arr_index]>=MAX_SIZE)
          {
               printf("Array insert position out of bound!\n");
               yyerror(id);
               exit(0);
          }
          else
          {
               for(int i=arr_size[arr_index]; i>insert_pos; i--)
               {
                    memcpy(&arr_table[arr_index][i], &arr_table[arr_index][i-1], sizeof(struct var));
               }

               arr_table[arr_index][insert_pos].valoare_num=val;
               arr_size[arr_index]++;
          }
     }
     return 1;
}


int array_insert_nr(char* id, double val, int tip)
{
     int arr_index=get_arr_index(id);
     if(arr_table[arr_index][0].tip!=tip)
     {
          printf("Type clash array insert!\n");
          yyerror(id);
          exit(0);
     }
     else
     {
          if(arr_size[arr_index]>=MAX_SIZE)
          {
               printf("Array insert over max size!\n");
               yyerror(id);
               exit(0);
          }
          else
          {
               arr_table[arr_index][arr_size[arr_index]].valoare_num=val;
               arr_size[arr_index]++;
          }
     }
     return 1;
}


int array_insert_id_pos(char* id, char* id_pos, int insert_pos)
{
     int var_index=get_var_index(id_pos);
     int arr_index=get_arr_index(id);
     if(var_table[var_index].tip!=arr_table[arr_index][0].tip)
     {
          printf("Type clash array insert!\n");
          yyerror(id);
          exit(0);
     }
     else
     {
          if(insert_pos<0 || insert_pos>=arr_size[arr_index] || arr_size[arr_index]>=MAX_SIZE)
          {
               printf("Array insert position out of bound!\n");
               yyerror(id);
               exit(0);
          }
          else
          {
               for(int i=arr_size[arr_index]; i>insert_pos; i--)
               {
                    memcpy(&arr_table[arr_index][i], &arr_table[arr_index][i-1], sizeof(struct var));
               }

               memcpy(&arr_table[arr_index][insert_pos], &var_table[var_index], sizeof(struct var));
               strcpy(arr_table[arr_index][insert_pos].nume,id);
               arr_size[arr_index]++;
          }
     }
     return 1;
}

int array_insert_id(char* id, char* id_pos)
{
     int var_index=get_var_index(id_pos);
     int arr_index=get_arr_index(id);
     if(var_table[var_index].tip!=arr_table[arr_index][0].tip)
     {
          printf("Types clash array insert!\n");
          yyerror(id);
          exit(0);
     }
     else
     {
          if(arr_size[arr_index]>=MAX_SIZE)
          {
               printf("Array insert position outside position!\n");
               yyerror(id);
               exit(0);
          }
          else
          {
               memcpy(&arr_table[arr_index][arr_size[arr_index]], &var_table[var_index], sizeof(struct var));
               strcpy(arr_table[arr_index][arr_size[arr_index]].nume,id);
               arr_size[arr_index]++;
          }
     }
     return 1;
}

int array_delete(char* id)
{
     int index=get_arr_index(id);
     if(arr_size[index]<=0)
     {
          printf("Array can't delete any element!\n");
          yyerror(id);
          exit(0);
     }
     arr_size[index]--;

}

int array_delete_pos(char* id, double pos)
{
     int index=get_arr_index(id);
     if(pos>=arr_size[index] || pos<0 || arr_size[index]<=0)
     {
          printf("Array delete position outside bounds!\n");
          yyerror(id);
          exit(0);
     }
     else
     {
          for(int i=(int)pos; i<arr_size[index]-1; i++)
          {
               memcpy(&arr_table[index][i], &arr_table[index][i+1], sizeof(struct var));
          }
          arr_size[index]--;

     }
}

int decl_arr_simple(int tip, char* id, int cnst)
{
     int index=get_arr_index(id);
     if(index!=-1 && CURR_SCOPE==var_table[index].scope)
     {
          printf("Array already declared!\n");
          yyerror(id);
          exit(0);
     }

     strcpy(arr_table[arr_count][0].nume, id);
     arr_table[arr_count][0].valoare_num=0;
     arr_table[arr_count][0].tip=tip;
     arr_table[arr_count][0].constant=cnst;
     arr_table[arr_count][0].scope=CURR_SCOPE;
     strcpy(arr_table[arr_count][0].valoare_sir, "");
     arr_size[arr_count]=0;
     arr_count++;

}

int decl_var_simple(int tip, char* id, int cnst)
{
     int index=get_var_index(id);
     if(index!=-1 && CURR_SCOPE==var_table[index].scope)
     {
          printf("Variable already declared!\n");
          yyerror(id);
          exit(0);
     }

     strcpy(var_table[var_count].nume, id);
     var_table[var_count].valoare_num=0;
     var_table[var_count].tip=tip;
     var_table[var_count].constant=cnst;
     strcpy(var_table[var_count].valoare_sir, "");
     var_table[var_count].scope=CURR_SCOPE;
     var_count++;


}

int decl_var_assign_str(int tip, char* id, char* val, int cnst)
{
     int index=get_var_index(id);
     if(index!=-1 && CURR_SCOPE==var_table[index].scope)
     {
          printf("Variable already declared!\n");
          yyerror(id);
          exit(0);
     }
     strcpy(var_table[var_count].nume, id);
     var_table[var_count].valoare_num=0;
     var_table[var_count].tip=tip;
     var_table[var_count].constant=cnst;
     var_table[var_count].scope=CURR_SCOPE;
     strcpy(var_table[var_count].valoare_sir, val);
     var_count++;
}

int id_assign_str(char* id, char* str, int tip)
{
     int index=get_var_index(id);
     if(index==-1)
     {
          printf("Variable not declared!\n");
          yyerror(id);
          exit(0);
     }
     else
     {
          if(var_table[index].tip!=tip)
          {
               printf("Assign types not matching.\n");
               yyerror(id);
               exit(0);
          }

          if(var_table[index].constant==1)
          {
               printf("Cannot modify constant variables!\n");
               yyerror(id);
               exit(0);
          }
          strcpy(var_table[index].valoare_sir, str);
     }
}

int id_assign_var(char* id, struct var* v)
{
     int index=get_var_index(id);
     if(index==-1)
     {
          printf("Variable not declared!\n");
          yyerror(id);
          exit(0);
     }
     else
     {
          if(var_table[index].tip!=v->tip && (var_table[index].tip!=4&&v->tip==0))
          {
               printf("Assign types not matching.\n");
               yyerror(id);
               exit(0);
          }

          if(var_table[index].constant==1)
          {
               printf("Cannot modify constant variables!\n");
               yyerror(id);
               exit(0);
          }

          int flag=0;
          if(var_table[index].tip==4)
          {
               flag=1;
          }
          memcpy(&var_table[index], v, sizeof(struct var));
          if(flag==1)
          {
               var_table[index].tip=4;
          }
          strcpy(var_table[index].nume,id);
     }
}

int inc_dec_val(char* id, double x)
{
     int index=get_var_index(id);
     if(index==-1)
     {
          printf("Variable not declared!\n");
          yyerror(id);
          exit(0);
     }
     else
     {
          if(var_table[index].constant==1)
          {
               printf("Cannot modify constant variables!\n");
               yyerror(id);
               exit(0);
          }

          var_table[index].valoare_num+=x;
     }
}

struct var * expr_calc_single(struct var* e, int c)
{
     struct var* v=(struct var*)malloc(sizeof(struct var));
     memcpy(v, e, sizeof(struct var));
     if(v->tip<2)
     {
          if(c==1)
          {
               v->valoare_num*=-1;
          }
     } 
     return v;  
}

struct var* expr_calc_double(struct var* e1, struct var* e2, int c)
{
     if(e1->tip>2||e2->tip>2)
     {
          printf("Expressions type not allowed.\n");
          char err[10];
          strcpy(err,'expr');
          yyerror(err);
          exit(0);
     }

     struct var* v=(struct var*)malloc(sizeof(struct var));
     memcpy(v, e1, sizeof(struct var));
     if(e2->tip == 1)
     {
          v->tip=1;
     }
     if(e1->tip<2 && e2->tip<2)
     {
          switch(c)
          {
               case 0:
                    v->valoare_num+=e2->valoare_num;
               break;
                 case 1:
                    v->valoare_num-=e2->valoare_num;
               break;
                 case 2:
                    v->valoare_num*=e2->valoare_num;
               break;
                 case 3:
                    v->valoare_num/=e2->valoare_num;
               break;
                 case 4:
                    v->valoare_num=(v->valoare_num==e2->valoare_num);
               break;
                 case 5:
                    v->valoare_num=(v->valoare_num!=e2->valoare_num);
               break;
                 case 6:
                    v->valoare_num=(v->valoare_num<e2->valoare_num);
               break;
                 case 7:
                    v->valoare_num=(v->valoare_num<=e2->valoare_num);
               break;
                 case 8:
                    v->valoare_num=(v->valoare_num>e2->valoare_num);
               break;
                 case 9:
                    v->valoare_num=(v->valoare_num>=e2->valoare_num);
               break;
                 case 10:
                    v->valoare_num=(v->valoare_num&&e2->valoare_num);
               break;
                 case 11:
                    v->valoare_num=(v->valoare_num||e2->valoare_num);
               break;
          }
     }
     return v;
}

struct var* moveVar(char* i)
{
     int index=get_var_index(i);
     if(index==-1)
     {
          printf("Variable undeclared!\n");
          yyerror(i);
          exit(0);
     }
     else
     {
          return &var_table[index];
     }
}

struct var* moveNum(double n, int tip)
{
     struct var* v=(struct var*)malloc(sizeof(struct var));

     v->valoare_num=n;
     v->tip=tip;

     return v;
}

struct var* moveSir(char* str, int tip)
{
     struct var* v=(struct var*)malloc(sizeof(struct var));

     strcpy(v->valoare_sir, str);
     v->tip=tip;

     return v;
}

struct var* moveArray(struct var* a)
{
     struct var* v = (struct var*)malloc(sizeof(struct var));
     memcpy(v, a, sizeof(struct var));
     return v;
}


struct var* array_get_value(char* id, int pos)
{
     struct var* v=(struct var*)malloc(sizeof(struct var));

     int index=get_arr_index(id);
     if(index==-1)
     {
          printf("Array undeclared!\n");
          yyerror(id);
          exit(0);
     }
     else
     {
          if(arr_size[index]<=pos)
          {
               printf("Array undeclared!\n");
               yyerror(id);
               exit(0);
          }
          else
          {
               
               memcpy(v, &arr_table[index][pos], sizeof(struct var));
          }
     }
     return v;
}


int insertParam(struct parametri* p, int x)
{
     p->param_tip[p->param_nr++]=x;
     return 1;
}

int insertFun(int tip, char* name, struct var* variabila)
{
     for(int i=0;i<fun_count;++i)
     {
          if(strcmp(name,fun_table[i].nume)==0 && tip==fun_table[i].tip && fun_table[i].param->param_nr==0)
          {
               printf("Function already declared!\n");
               yyerror(name);
               exit(0);
          }
     }

     strcpy(fun_table[fun_count].nume, name);
     fun_table[fun_count].tip=tip;
     fun_table[fun_count].return_val=(struct var*)malloc(sizeof(struct var));
     memcpy(fun_table[fun_count].return_val, variabila, sizeof(struct var));
     fun_table[fun_count].param=(struct parametri*)malloc(sizeof(struct parametri));
     fun_table[fun_count].param->param_nr=0;
     fun_count++;
     return 1;
}

int insertFunParam(int tip, char* name, struct parametri* lista, struct var* variabila)
{
     for(int i=0;i<fun_count;++i)
     {
          if(strcmp(name,fun_table[i].nume)==0 && tip==fun_table[i].tip && fun_table[i].param->param_nr==lista->param_nr)
          {
               int flag=1;
               for(int j=0;j<fun_table[i].param->param_nr;++j)
               {
                    if(fun_table[i].param->param_tip[j]!=lista->param_tip[j])
                    {
                         flag=-1;
                    }
               }
               if(flag==1)
               {
                    printf("Function already declared!\n");
                    yyerror(name);
                    exit(0);
               }
          }
     }
     

     strcpy(fun_table[fun_count].nume, name);
     fun_table[fun_count].tip=tip;
     fun_table[fun_count].return_val=(struct var*)malloc(sizeof(struct var));
     memcpy(fun_table[fun_count].return_val, variabila, sizeof(struct var));
     fun_table[fun_count].param=(struct parametri*)malloc(sizeof(struct parametri));
     memcpy(fun_table[fun_count].param, lista, sizeof(struct parametri));
     fun_count++;
     return 1;
}

int afisare_var(struct var* variabila)
{
     if(variabila->tip == 0)
     {
          printf("%.0f",variabila->valoare_num);
     }
     else if(variabila->tip == 1)
     {
          printf("%lf",variabila->valoare_num);
     }
     else if(variabila->tip == 2)
     {
          printf("%c",variabila->valoare_sir[0]);
     }
     else if(variabila->tip == 3)
     {
          printf("%s",variabila->valoare_sir);
     }
     else if(variabila->tip == 4)
     {
          if(variabila->valoare_num==0)
          {
               printf("false");
          }
          else
          {
               printf("true");
          }
     }
     printf("\n");
}

// int => 0 ; float => 1 ; char => 2 ; string => 3 ; bool => 4 ; 
int afisare_sir_var(char* sir, struct var* variabila)
{
     printf("%s ",sir);
     if(variabila->tip == 0)
     {
          printf("%.0f",variabila->valoare_num);
     }
     else if(variabila->tip == 1)
     {
          printf("%lf",variabila->valoare_num);
     }
     else if(variabila->tip == 2)
     {
          printf("%c",variabila->valoare_sir[0]);
     }
     else if(variabila->tip == 3)
     {
          printf("%s",variabila->valoare_sir);
     }
     else if(variabila->tip == 4)
     {
          if(variabila->valoare_num==0)
          {
               printf("false");
          }
          else
          {
               printf("true");
          }
     }
     printf("\n");
}

int get_var_index(char* name)
{
     for(int i=var_count-1; i>=0; i--)
     {
          if(strcmp(name, var_table[i].nume)==0 && (CURR_SCOPE==var_table[i].scope || var_table[i].scope<=1))
          {
               return i;
          }
     }
     return -1;
}

int get_arr_index(char* name)
{
     for(int i=0; i<arr_count; i++)
     {
          if(strcmp(name, arr_table[i][0].nume)==0)
          {
               return i;
          }
     }
     return -1;
}

int yyerror(char * s){
     printf("Eroare: '%s' la linia: %d\n",s,yylineno);
}

int main(int argc, char** argv){
     yyin=fopen(argv[1],"r");
     yyparse();
} 
