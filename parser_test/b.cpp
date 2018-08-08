/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     DEF = 258,
     CMD = 259,
     HISTO = 260,
     ELE = 261,
     MUO = 262,
     LEP = 263,
     PHO = 264,
     JET = 265,
     BJET = 266,
     QGJET = 267,
     NUMET = 268,
     METLV = 269,
     MINPTM = 270,
     MINPTG = 271,
     MINPTJ = 272,
     MINPTE = 273,
     MAXETAM = 274,
     MAXETAE = 275,
     MAXETAG = 276,
     MAXETAJ = 277,
     MAXMET = 278,
     TRGE = 279,
     TRGM = 280,
     LVLO = 281,
     ATLASOD = 282,
     CMSOD = 283,
     DELPHES = 284,
     FCC = 285,
     LHCO = 286,
     PHI = 287,
     ETA = 288,
     ABSETA = 289,
     PT = 290,
     PZ = 291,
     NBF = 292,
     DR = 293,
     DPHI = 294,
     NELE = 295,
     NMUO = 296,
     NLEP = 297,
     NPHO = 298,
     NJET = 299,
     NBJET = 300,
     NQGJET = 301,
     HT = 302,
     METMWT = 303,
     MWT = 304,
     MET = 305,
     ALL = 306,
     LEPSF = 307,
     FILLHISTOS = 308,
     NB = 309,
     ID = 310,
     SIN = 311,
     COS = 312,
     TAN = 313,
     INT = 314,
     OR = 315,
     AND = 316,
     LT = 317,
     GT = 318,
     LE = 319,
     GE = 320,
     EQ = 321,
     NE = 322,
     IRG = 323,
     ERG = 324,
     Unary = 325
   };
#endif
/* Tokens.  */
#define DEF 258
#define CMD 259
#define HISTO 260
#define ELE 261
#define MUO 262
#define LEP 263
#define PHO 264
#define JET 265
#define BJET 266
#define QGJET 267
#define NUMET 268
#define METLV 269
#define MINPTM 270
#define MINPTG 271
#define MINPTJ 272
#define MINPTE 273
#define MAXETAM 274
#define MAXETAE 275
#define MAXETAG 276
#define MAXETAJ 277
#define MAXMET 278
#define TRGE 279
#define TRGM 280
#define LVLO 281
#define ATLASOD 282
#define CMSOD 283
#define DELPHES 284
#define FCC 285
#define LHCO 286
#define PHI 287
#define ETA 288
#define ABSETA 289
#define PT 290
#define PZ 291
#define NBF 292
#define DR 293
#define DPHI 294
#define NELE 295
#define NMUO 296
#define NLEP 297
#define NPHO 298
#define NJET 299
#define NBJET 300
#define NQGJET 301
#define HT 302
#define METMWT 303
#define MWT 304
#define MET 305
#define ALL 306
#define LEPSF 307
#define FILLHISTOS 308
#define NB 309
#define ID 310
#define SIN 311
#define COS 312
#define TAN 313
#define INT 314
#define OR 315
#define AND 316
#define LT 317
#define GT 318
#define LE 319
#define GE 320
#define EQ 321
#define NE 322
#define IRG 323
#define ERG 324
#define Unary 325




/* Copy the first part of user declarations.  */
#line 1 "parse.y"
 
#include "NodeTree.h"
#include <math.h>
#include "stdlib.h"
#include <iostream>
#include <string>
#include <map>
#include <list>
#include <vector>
#include <iterator>
extern int yylex();
void yyerror(list<string> *parts,map<string,Node*>* NodeVars,map<string,vector<myParticle> >* ListParts,
                map<int,Node*>* NodeCuts,
                vector<double>* Initializations , vector<double>* DataFormats
                ,const char *s) { std::cout << s << std::endl; } 
int cutcount;
using namespace std;
string tmp;
int pnum;
int dnum;
vector<myParticle> TmpParticle;
vector<myParticle> TmpParticle1;//to be used for list of 2 particles

//modify types to ints in myParticle => codes?
//see how to give input to yyparse and get output -> DONE
//read file
//avoid global variables
//add histos -> DONE
//view input


/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 31 "parse.y"
{
        Node* node;
	double real;
	char* s;//ADD POINTER TO NODE unique_ptr?
}
/* Line 193 of yacc.c.  */
#line 273 "b.cpp"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 286 "b.cpp"

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
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
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
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   483

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  89
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  19
/* YYNRULES -- Number of rules.  */
#define YYNRULES  103
/* YYNRULES -- Number of states.  */
#define YYNSTATES  217

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   325

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      87,    88,    72,    70,    84,    71,     2,    73,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    77,     2,
       2,    76,     2,    86,     2,     2,     2,     2,     2,    83,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      82,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    75,    85,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    80,
       2,     2,     2,    81,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    78,     2,    79,     2,     2,     2,     2,
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
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    74
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     7,    10,    11,    15,    19,    23,    27,
      31,    35,    39,    43,    47,    51,    55,    59,    63,    67,
      71,    75,    79,    82,    83,    88,    93,    98,   103,   108,
     113,   118,   123,   128,   133,   138,   143,   146,   149,   151,
     153,   155,   157,   159,   161,   163,   165,   167,   169,   171,
     173,   175,   176,   183,   186,   188,   192,   196,   200,   204,
     208,   212,   216,   220,   224,   226,   229,   231,   234,   235,
     238,   241,   244,   257,   260,   262,   268,   270,   272,   274,
     278,   282,   286,   290,   294,   298,   303,   308,   312,   316,
     320,   324,   328,   332,   336,   340,   343,   348,   353,   358,
     362,   364,   366,   368
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      90,     0,    -1,    91,    93,   101,    -1,    91,    92,    -1,
      -1,    18,    76,    54,    -1,    15,    76,    54,    -1,    17,
      76,    54,    -1,    16,    76,    54,    -1,    20,    76,    54,
      -1,    19,    76,    54,    -1,    22,    76,    54,    -1,    21,
      76,    54,    -1,    23,    76,    54,    -1,    24,    76,    59,
      -1,    25,    76,    59,    -1,    26,    76,    54,    -1,    27,
      76,    54,    -1,    28,    76,    54,    -1,    29,    76,    54,
      -1,    30,    76,    54,    -1,    31,    76,    54,    -1,    93,
      94,    -1,    -1,     3,    55,    77,    98,    -1,     3,    55,
      77,   107,    -1,    78,    98,    79,    80,    -1,    78,    98,
      79,    81,    -1,    78,    98,    79,    82,    -1,    78,    98,
      79,    83,    -1,    78,    98,    79,    32,    -1,    78,    98,
      79,    33,    -1,    78,    98,    79,    34,    -1,    78,    98,
      79,    35,    -1,    78,    98,    79,    36,    -1,    78,    98,
      79,    37,    -1,    96,    38,    -1,    96,    39,    -1,    40,
      -1,    41,    -1,    42,    -1,    43,    -1,    44,    -1,    45,
      -1,    46,    -1,    47,    -1,    48,    -1,    49,    -1,    50,
      -1,    51,    -1,    52,    -1,    -1,    78,    98,    97,    84,
      98,    79,    -1,    98,    99,    -1,    99,    -1,     6,    85,
     100,    -1,     7,    85,   100,    -1,     8,    85,   100,    -1,
       9,    85,   100,    -1,    10,    85,   100,    -1,    11,    85,
     100,    -1,    12,    85,   100,    -1,    13,    85,   100,    -1,
      14,    85,   100,    -1,    55,    -1,    71,    59,    -1,    59,
      -1,   101,   102,    -1,    -1,     4,   106,    -1,     4,    51,
      -1,     4,   104,    -1,     5,    55,    84,   103,    84,    59,
      84,    59,    84,    59,    84,    55,    -1,   103,    55,    -1,
      55,    -1,   106,    86,   105,    77,   105,    -1,   106,    -1,
      51,    -1,   104,    -1,   107,    62,   107,    -1,   107,    63,
     107,    -1,   107,    64,   107,    -1,   107,    65,   107,    -1,
     107,    66,   107,    -1,   107,    67,   107,    -1,   107,    68,
     107,   107,    -1,   107,    69,   107,   107,    -1,   106,    61,
     106,    -1,   106,    60,   106,    -1,    87,   106,    88,    -1,
     107,    70,   107,    -1,   107,    71,   107,    -1,   107,    72,
     107,    -1,   107,    73,   107,    -1,   107,    75,   107,    -1,
      71,   107,    -1,    57,    87,   107,    88,    -1,    56,    87,
     107,    88,    -1,    58,    87,   107,    88,    -1,    87,   107,
      88,    -1,    54,    -1,    59,    -1,    95,    -1,    55,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    65,    65,    67,    68,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    88,    89,    91,   121,   136,   152,   159,   164,
     169,   174,   179,   184,   189,   194,   199,   221,   230,   235,
     240,   245,   250,   255,   260,   265,   270,   275,   280,   285,
     290,   296,   296,   304,   312,   324,   333,   341,   349,   357,
     365,   373,   381,   389,   397,   416,   417,   419,   420,   422,
     425,   429,   433,   454,   462,   474,   480,   483,   486,   490,
     493,   496,   499,   502,   505,   508,   515,   522,   525,   528,
     532,   535,   538,   541,   544,   547,   550,   553,   558,   563,
     568,   572,   575,   577
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "DEF", "CMD", "HISTO", "ELE", "MUO",
  "LEP", "PHO", "JET", "BJET", "QGJET", "NUMET", "METLV", "MINPTM",
  "MINPTG", "MINPTJ", "MINPTE", "MAXETAM", "MAXETAE", "MAXETAG", "MAXETAJ",
  "MAXMET", "TRGE", "TRGM", "LVLO", "ATLASOD", "CMSOD", "DELPHES", "FCC",
  "LHCO", "PHI", "ETA", "ABSETA", "PT", "PZ", "NBF", "DR", "DPHI", "NELE",
  "NMUO", "NLEP", "NPHO", "NJET", "NBJET", "NQGJET", "HT", "METMWT", "MWT",
  "MET", "ALL", "LEPSF", "FILLHISTOS", "NB", "ID", "SIN", "COS", "TAN",
  "INT", "OR", "AND", "LT", "GT", "LE", "GE", "EQ", "NE", "IRG", "ERG",
  "'+'", "'-'", "'*'", "'/'", "Unary", "'^'", "'='", "':'", "'{'", "'}'",
  "'m'", "'q'", "'P'", "'E'", "','", "'_'", "'?'", "'('", "')'", "$accept",
  "input", "initializations", "initialization", "definitions",
  "definition", "function", "list", "@1", "particules", "particule",
  "index", "commands", "command", "description", "ifstatement", "action",
  "condition", "e", 0
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
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
      43,    45,    42,    47,   325,    94,    61,    58,   123,   125,
     109,   113,    80,    69,    44,    95,    63,    40,    41
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    89,    90,    91,    91,    92,    92,    92,    92,    92,
      92,    92,    92,    92,    92,    92,    92,    92,    92,    92,
      92,    92,    93,    93,    94,    94,    95,    95,    95,    95,
      95,    95,    95,    95,    95,    95,    95,    95,    95,    95,
      95,    95,    95,    95,    95,    95,    95,    95,    95,    95,
      95,    97,    96,    98,    98,    99,    99,    99,    99,    99,
      99,    99,    99,    99,    99,   100,   100,   101,   101,   102,
     102,   102,   102,   103,   103,   104,   105,   105,   105,   106,
     106,   106,   106,   106,   106,   106,   106,   106,   106,   106,
     107,   107,   107,   107,   107,   107,   107,   107,   107,   107,
     107,   107,   107,   107
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     3,     2,     0,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     2,     0,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     2,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     0,     6,     2,     1,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     1,     2,     1,     2,     0,     2,
       2,     2,    12,     2,     1,     5,     1,     1,     1,     3,
       3,     3,     3,     3,     3,     4,     4,     3,     3,     3,
       3,     3,     3,     3,     3,     2,     4,     4,     4,     3,
       1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,     0,    23,     1,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     3,    68,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    22,     2,     6,     8,     7,     5,    10,     9,    12,
      11,    13,    14,    15,    16,    17,    18,    19,    20,    21,
       0,     0,     0,    67,     0,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,   100,   103,
       0,     0,     0,   101,     0,     0,     0,   102,     0,    71,
      69,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    49,    64,     0,    24,    54,    25,     0,     0,
       0,    95,    64,    51,     0,     0,    36,    37,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    53,     0,     0,     0,     0,
       0,    89,    99,    88,    87,    49,    78,     0,    76,    79,
      80,    81,    82,    83,    84,     0,     0,    90,    91,    92,
      93,    94,    74,     0,    66,     0,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    97,    96,    98,    30,    31,
      32,    33,    34,    35,    26,    27,    28,    29,     0,     0,
       0,    85,    86,    73,     0,    65,     0,    75,    91,     0,
      52,     0,     0,     0,     0,     0,    72
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,    21,    22,    41,    87,    88,   150,   105,
     106,   176,    42,    63,   173,   156,   157,   158,    91
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -104
static const yytype_int16 yypact[] =
{
    -104,     4,   438,  -104,   -70,   -67,   -59,   -57,   -55,   -52,
     -34,   -20,    -6,     5,     6,     9,    15,    18,    24,    37,
      56,  -104,    76,   -42,    33,    81,    83,    97,   113,   114,
     120,   121,   122,   124,   130,   145,   158,   160,   161,   168,
     151,  -104,    32,  -104,  -104,  -104,  -104,  -104,  -104,  -104,
    -104,  -104,  -104,  -104,  -104,  -104,  -104,  -104,  -104,  -104,
     143,   194,   170,  -104,    98,  -104,  -104,  -104,  -104,  -104,
    -104,  -104,  -104,  -104,  -104,  -104,    73,  -104,  -104,  -104,
     136,   140,   141,  -104,   242,   152,   290,  -104,     0,  -104,
      29,   408,   147,   144,   162,   169,   174,   182,   183,   184,
     186,   189,  -104,    58,   242,   152,  -104,   107,   242,   242,
     242,   155,  -104,    19,   -47,   364,  -104,  -104,   290,   290,
     338,   242,   242,   242,   242,   242,   242,   242,   242,   242,
     242,   242,   242,   242,   177,   -36,   -36,   -36,   -36,   -36,
     -36,   -36,   -36,   -36,    46,  -104,   138,   185,   191,    90,
     192,  -104,  -104,   209,  -104,     3,  -104,   198,    29,   107,
     107,   107,   107,   107,   107,   146,   146,    20,    20,   155,
     155,   155,  -104,   -50,  -104,   218,  -104,  -104,  -104,  -104,
    -104,  -104,  -104,  -104,  -104,  -104,  -104,  -104,  -104,  -104,
    -104,  -104,  -104,  -104,  -104,  -104,  -104,  -104,   152,   338,
     242,   107,   107,  -104,   219,  -104,    41,  -104,    11,   196,
    -104,   236,   226,   252,   228,   259,  -104
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -104,  -104,  -104,  -104,  -104,  -104,  -104,  -104,  -104,   -84,
    -103,   166,  -104,  -104,  -104,   254,   117,   -43,   -64
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -104
static const yytype_int16 yytable[] =
{
     107,   113,   145,   -77,     3,   203,    23,   -77,   -77,    24,
     145,   -95,    43,   118,   119,   -95,   -95,    25,    90,    26,
     111,    27,   115,   174,    28,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   204,   175,    61,    62,   116,   117,
     144,   151,    29,   114,   146,   147,   148,    93,    94,    95,
      96,    97,    98,    99,   100,   101,    30,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
      31,   -95,   -95,   -70,   112,   153,   154,   -70,   -70,    40,
     -77,    32,    33,   -95,   -95,    34,   133,    44,   -95,   118,
     119,    35,   131,   132,    36,   133,   112,   -95,   149,   -95,
      37,   201,   202,   145,    93,    94,    95,    96,    97,    98,
      99,   100,   101,    38,   206,   120,   129,   130,   131,   132,
     210,   133,   188,   189,   190,   191,   192,   193,  -103,  -103,
    -103,  -103,    39,  -103,   152,    45,   208,    46,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,   102,
      77,    47,    78,   103,    80,    81,    82,    83,    93,    94,
      95,    96,    97,    98,    99,   100,   101,    48,    49,    84,
     194,   195,   196,   197,    50,    51,    85,   129,   130,   131,
     132,    52,   133,    53,    54,   104,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,   102,    77,    55,
      78,    79,    80,    81,    82,    83,    60,   112,   129,   130,
     131,   132,    56,   133,    57,    58,   129,   200,   131,   132,
      64,   133,    59,   108,    85,    92,   185,   109,   110,   135,
     133,   134,   172,   104,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,   136,    78,    79,
      80,    81,    82,    83,   137,   129,   130,   131,   132,   138,
     133,   129,   130,   131,   132,    84,   133,   139,   140,   141,
     119,   142,    85,   186,   143,   199,   198,   205,   209,   187,
     211,    86,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,   102,    77,   212,    78,    79,    80,    81,
      82,    83,   177,   178,   179,   180,   181,   182,   183,   184,
     213,   214,   215,    84,   216,    89,   207,     0,     0,     0,
      85,     0,     0,     0,     0,     0,     0,     0,     0,   104,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,   102,    77,     0,    78,    79,    80,    81,    82,    83,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    84,     0,     0,     0,     0,     0,     0,    85,     0,
       0,     0,     0,     0,     0,     0,     0,    86,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,   155,
      77,     0,    78,    79,    80,    81,    82,    83,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    84,
       0,     0,     0,     0,     0,     0,    85,     0,     0,     0,
       0,     0,     0,     0,     0,    86,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,     0,   133,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   152,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,     0,   133
};

static const yytype_int16 yycheck[] =
{
      64,    85,   105,     0,     0,    55,    76,     4,     5,    76,
     113,     0,    54,    60,    61,     4,     5,    76,    61,    76,
      84,    76,    86,    59,    76,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    84,    71,     4,     5,    38,    39,
     104,    88,    76,    86,   108,   109,   110,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    76,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
      76,    60,    61,     0,    55,   118,   119,     4,     5,     3,
      77,    76,    76,    72,    73,    76,    75,    54,    77,    60,
      61,    76,    72,    73,    76,    75,    55,    86,    79,    88,
      76,   165,   166,   206,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    76,   198,    86,    70,    71,    72,    73,
      79,    75,    32,    33,    34,    35,    36,    37,    70,    71,
      72,    73,    76,    75,    88,    54,   200,    54,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    54,    54,    55,    56,    57,    58,    59,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    54,    54,    71,
      80,    81,    82,    83,    54,    54,    78,    70,    71,    72,
      73,    59,    75,    59,    54,    87,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    54,
      54,    55,    56,    57,    58,    59,    55,    55,    70,    71,
      72,    73,    54,    75,    54,    54,    70,    71,    72,    73,
      77,    75,    54,    87,    78,    55,    88,    87,    87,    85,
      75,    84,    55,    87,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    85,    54,    55,
      56,    57,    58,    59,    85,    70,    71,    72,    73,    85,
      75,    70,    71,    72,    73,    71,    75,    85,    85,    85,
      61,    85,    78,    88,    85,    77,    84,    59,    59,    88,
      84,    87,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    59,    54,    55,    56,    57,
      58,    59,   136,   137,   138,   139,   140,   141,   142,   143,
      84,    59,    84,    71,    55,    61,   199,    -1,    -1,    -1,
      78,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    87,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    -1,    54,    55,    56,    57,    58,    59,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    71,    -1,    -1,    -1,    -1,    -1,    -1,    78,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    87,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    -1,    54,    55,    56,    57,    58,    59,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    71,
      -1,    -1,    -1,    -1,    -1,    -1,    78,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    87,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    -1,    75,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    88,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    -1,    75
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    90,    91,     0,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    92,    93,    76,    76,    76,    76,    76,    76,    76,
      76,    76,    76,    76,    76,    76,    76,    76,    76,    76,
       3,    94,   101,    54,    54,    54,    54,    54,    54,    54,
      54,    54,    59,    59,    54,    54,    54,    54,    54,    54,
      55,     4,     5,   102,    77,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    54,    55,
      56,    57,    58,    59,    71,    78,    87,    95,    96,   104,
     106,   107,    55,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    51,    55,    87,    98,    99,   107,    87,    87,
      87,   107,    55,    98,   106,   107,    38,    39,    60,    61,
      86,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    75,    84,    85,    85,    85,    85,    85,
      85,    85,    85,    85,   107,    99,   107,   107,   107,    79,
      97,    88,    88,   106,   106,    51,   104,   105,   106,   107,
     107,   107,   107,   107,   107,   107,   107,   107,   107,   107,
     107,   107,    55,   103,    59,    71,   100,   100,   100,   100,
     100,   100,   100,   100,   100,    88,    88,    88,    32,    33,
      34,    35,    36,    37,    80,    81,    82,    83,    84,    77,
      71,   107,   107,    55,    84,    59,    98,   105,   107,    59,
      79,    84,    59,    84,    59,    84,    55
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
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (parts, NodeVars, ListParts, NodeCuts, Initializations, DataFormats, YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
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
		  Type, Value, parts, NodeVars, ListParts, NodeCuts, Initializations, DataFormats); \
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
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, list<string> *parts, map<string,Node*>* NodeVars, map<string,vector<myParticle> >* ListParts, map<int,Node*>* NodeCuts, vector<double>* Initializations, vector<double>* DataFormats)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep, parts, NodeVars, ListParts, NodeCuts, Initializations, DataFormats)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    list<string> *parts;
    map<string,Node*>* NodeVars;
    map<string,vector<myParticle> >* ListParts;
    map<int,Node*>* NodeCuts;
    vector<double>* Initializations;
    vector<double>* DataFormats;
#endif
{
  if (!yyvaluep)
    return;
  YYUSE (parts);
  YYUSE (NodeVars);
  YYUSE (ListParts);
  YYUSE (NodeCuts);
  YYUSE (Initializations);
  YYUSE (DataFormats);
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
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, list<string> *parts, map<string,Node*>* NodeVars, map<string,vector<myParticle> >* ListParts, map<int,Node*>* NodeCuts, vector<double>* Initializations, vector<double>* DataFormats)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep, parts, NodeVars, ListParts, NodeCuts, Initializations, DataFormats)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    list<string> *parts;
    map<string,Node*>* NodeVars;
    map<string,vector<myParticle> >* ListParts;
    map<int,Node*>* NodeCuts;
    vector<double>* Initializations;
    vector<double>* DataFormats;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep, parts, NodeVars, ListParts, NodeCuts, Initializations, DataFormats);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
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
yy_reduce_print (YYSTYPE *yyvsp, int yyrule, list<string> *parts, map<string,Node*>* NodeVars, map<string,vector<myParticle> >* ListParts, map<int,Node*>* NodeCuts, vector<double>* Initializations, vector<double>* DataFormats)
#else
static void
yy_reduce_print (yyvsp, yyrule, parts, NodeVars, ListParts, NodeCuts, Initializations, DataFormats)
    YYSTYPE *yyvsp;
    int yyrule;
    list<string> *parts;
    map<string,Node*>* NodeVars;
    map<string,vector<myParticle> >* ListParts;
    map<int,Node*>* NodeCuts;
    vector<double>* Initializations;
    vector<double>* DataFormats;
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
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       , parts, NodeVars, ListParts, NodeCuts, Initializations, DataFormats);
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule, parts, NodeVars, ListParts, NodeCuts, Initializations, DataFormats); \
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

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, list<string> *parts, map<string,Node*>* NodeVars, map<string,vector<myParticle> >* ListParts, map<int,Node*>* NodeCuts, vector<double>* Initializations, vector<double>* DataFormats)
#else
static void
yydestruct (yymsg, yytype, yyvaluep, parts, NodeVars, ListParts, NodeCuts, Initializations, DataFormats)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
    list<string> *parts;
    map<string,Node*>* NodeVars;
    map<string,vector<myParticle> >* ListParts;
    map<int,Node*>* NodeCuts;
    vector<double>* Initializations;
    vector<double>* DataFormats;
#endif
{
  YYUSE (yyvaluep);
  YYUSE (parts);
  YYUSE (NodeVars);
  YYUSE (ListParts);
  YYUSE (NodeCuts);
  YYUSE (Initializations);
  YYUSE (DataFormats);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (list<string> *parts, map<string,Node*>* NodeVars, map<string,vector<myParticle> >* ListParts, map<int,Node*>* NodeCuts, vector<double>* Initializations, vector<double>* DataFormats);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
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
yyparse (list<string> *parts, map<string,Node*>* NodeVars, map<string,vector<myParticle> >* ListParts, map<int,Node*>* NodeCuts, vector<double>* Initializations, vector<double>* DataFormats)
#else
int
yyparse (parts, NodeVars, ListParts, NodeCuts, Initializations, DataFormats)
    list<string> *parts;
    map<string,Node*>* NodeVars;
    map<string,vector<myParticle> >* ListParts;
    map<int,Node*>* NodeCuts;
    vector<double>* Initializations;
    vector<double>* DataFormats;
#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

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
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

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

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
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
        case 5:
#line 70 "parse.y"
    {Initializations->at(0)=(yyvsp[(3) - (3)].real);;}
    break;

  case 6:
#line 71 "parse.y"
    {Initializations->at(1)=(yyvsp[(3) - (3)].real);;}
    break;

  case 7:
#line 72 "parse.y"
    {Initializations->at(2)=(yyvsp[(3) - (3)].real);;}
    break;

  case 8:
#line 73 "parse.y"
    {Initializations->at(3)=(yyvsp[(3) - (3)].real);;}
    break;

  case 9:
#line 74 "parse.y"
    {Initializations->at(4)=(yyvsp[(3) - (3)].real);;}
    break;

  case 10:
#line 75 "parse.y"
    {Initializations->at(5)=(yyvsp[(3) - (3)].real);;}
    break;

  case 11:
#line 76 "parse.y"
    {Initializations->at(6)=(yyvsp[(3) - (3)].real);;}
    break;

  case 12:
#line 77 "parse.y"
    {Initializations->at(7)=(yyvsp[(3) - (3)].real);;}
    break;

  case 13:
#line 78 "parse.y"
    {Initializations->at(8)=(yyvsp[(3) - (3)].real);;}
    break;

  case 14:
#line 79 "parse.y"
    {Initializations->at(9)=(yyvsp[(3) - (3)].real);;}
    break;

  case 15:
#line 80 "parse.y"
    {Initializations->at(10)=(yyvsp[(3) - (3)].real);;}
    break;

  case 16:
#line 81 "parse.y"
    {DataFormats->at(0)=(yyvsp[(3) - (3)].real);;}
    break;

  case 17:
#line 82 "parse.y"
    {DataFormats->at(1)=(yyvsp[(3) - (3)].real);;}
    break;

  case 18:
#line 83 "parse.y"
    {DataFormats->at(2)=(yyvsp[(3) - (3)].real);;}
    break;

  case 19:
#line 84 "parse.y"
    {DataFormats->at(3)=(yyvsp[(3) - (3)].real);;}
    break;

  case 20:
#line 85 "parse.y"
    {DataFormats->at(4)=(yyvsp[(3) - (3)].real);;}
    break;

  case 21:
#line 86 "parse.y"
    {DataFormats->at(5)=(yyvsp[(3) - (3)].real);;}
    break;

  case 24:
#line 91 "parse.y"
    {

                                        pnum=0;
                                        map<string,vector<myParticle> >::iterator it ;
                                        string name = (yyvsp[(2) - (4)].s);
                                        it = ListParts->find(name);
                        
                                        if(it != ListParts->end()) {
                                                cout <<name<<" : " ;
                                                yyerror(NULL,NULL,NULL,NULL,NULL,NULL,"Particule already defined");
                                                YYERROR;//stops parsing if variable already defined
                                                
                                        }
                                        
                                        parts->push_back(name+" : "+(yyvsp[(4) - (4)].s));
                                        
                                        
                                                // std::cout<<"\n TMP List: \n";
                                                // vector<myParticle>::iterator myiterator;
                                                // myiterator = TmpParticle.begin();
                                                // while (myiterator != TmpParticle.end()) {
                                                // std::cout << "type: " << myiterator->type << " index: " << myiterator->index << endl;
                                                // myiterator++;
                                                // }
                                        
                                        vector<myParticle> newList;
                                        TmpParticle.swap(newList);
                                        ListParts->insert(make_pair(name,newList));
                                                                                
				;}
    break;

  case 25:
#line 121 "parse.y"
    {
                                        pnum=0;
                                         map<string, Node*>::iterator it ;
                                         string name = (yyvsp[(2) - (4)].s);
                                         it = NodeVars->find(name);
                        
                                        if(it != NodeVars->end()) {
                                                cout <<name<<" : " ;
                                                yyerror(NULL,NULL,NULL,NULL,NULL,NULL,"Variable already defined");
                                                YYERROR;//stops parsing if variable already defined
                                                
                                        }
                                        NodeVars->insert(make_pair(name,(yyvsp[(4) - (4)].node)));
				;}
    break;

  case 26:
#line 136 "parse.y"
    {     
                                        string s=(yyvsp[(2) - (4)].s);
                                        tmp="{ "+s+" }m";                        
                                        //$$=strdup(tmp.c_str());
                                        // std::cout<<"\n M List: \n";
                                        //         vector<myParticle>::iterator myiterator;
                                        //         myiterator = TmpParticle.begin();
                                        //         while (myiterator != TmpParticle.end()) {
                                        //         std::cout << "type: " << myiterator->type << " index: " << myiterator->index << endl;
                                        //         myiterator++;
                                        //         }
                                        vector<myParticle> newList;
                                        TmpParticle.swap(newList);
                                        (yyval.node)=new FuncNode(MASS,newList,"m");

                                ;}
    break;

  case 27:
#line 152 "parse.y"
    {     
                                        string s=(yyvsp[(2) - (4)].s);
                                        tmp="{ "+s+" }q";                        
                                        vector<myParticle> newList;
                                        TmpParticle.swap(newList);//then add newList to node
                                        (yyval.node)=new FuncNode(MASS,newList,"q");
                                ;}
    break;

  case 28:
#line 159 "parse.y"
    {     
                                        vector<myParticle> newList;
                                        TmpParticle.swap(newList);
                                        (yyval.node)=new FuncNode(MASS,newList,"p");
                                ;}
    break;

  case 29:
#line 164 "parse.y"
    {     
                                        vector<myParticle> newList;
                                        TmpParticle.swap(newList);
                                        (yyval.node)=new FuncNode(MASS,newList,"e");
                                ;}
    break;

  case 30:
#line 169 "parse.y"
    {     
                                        vector<myParticle> newList;
                                        TmpParticle.swap(newList);
                                        (yyval.node)=new FuncNode(MASS,newList,"phi");
                                ;}
    break;

  case 31:
#line 174 "parse.y"
    {     
                                        vector<myParticle> newList;
                                        TmpParticle.swap(newList);
                                        (yyval.node)=new FuncNode(MASS,newList,"eta");
                                ;}
    break;

  case 32:
#line 179 "parse.y"
    {     
                                        vector<myParticle> newList;
                                        TmpParticle.swap(newList);
                                        (yyval.node)=new FuncNode(MASS,newList,"abseta");
                                ;}
    break;

  case 33:
#line 184 "parse.y"
    {     
                                        vector<myParticle> newList;
                                        TmpParticle.swap(newList);
                                        (yyval.node)=new FuncNode(MASS,newList,"pt");
                                ;}
    break;

  case 34:
#line 189 "parse.y"
    {     
                                        vector<myParticle> newList;
                                        TmpParticle.swap(newList);
                                        (yyval.node)=new FuncNode(MASS,newList,"pz");
                                ;}
    break;

  case 35:
#line 194 "parse.y"
    {     
                                        vector<myParticle> newList;
                                        TmpParticle.swap(newList);
                                        (yyval.node)=new FuncNode(MASS,newList,"nbf");
                                ;}
    break;

  case 36:
#line 199 "parse.y"
    { 
                                        // std::cout<<"\n DR TMP1 List: \n";
                                        //         vector<myParticle>::iterator myiterator;
                                        //         myiterator = TmpParticle1.begin();
                                        //         while (myiterator != TmpParticle1.end()) {
                                        //         std::cout << "type: " << myiterator->type << " index: " << myiterator->index << endl;
                                        //         myiterator++;
                                        //         }
                                        //         std::cout<<"\n DR TMP List: \n";
                                                
                                        //         myiterator = TmpParticle.begin();
                                        //         while (myiterator != TmpParticle.end()) {
                                        //         std::cout << "type: " << myiterator->type << " index: " << myiterator->index << endl;
                                        //         myiterator++;
                                        //         }
                                        
                                        vector<myParticle> newList;
                                        TmpParticle.swap(newList);
                                        vector<myParticle> newList1;
                                        TmpParticle1.swap(newList1);
                                        (yyval.node)=new LFuncNode(dR,newList1,newList,"dR");
                                ;}
    break;

  case 37:
#line 221 "parse.y"
    { 
                                                vector<myParticle> newList;
                                                TmpParticle.swap(newList);
                                                vector<myParticle> newList1;
                                                TmpParticle1.swap(newList1);
                                                (yyval.node)=new LFuncNode(dR,newList1,newList,"dphi");


                                ;}
    break;

  case 38:
#line 230 "parse.y"
    {    
                                        
                                        string s="NELE";                                                              
                                        (yyval.node)=new SFuncNode(all,s);
                                ;}
    break;

  case 39:
#line 235 "parse.y"
    {    
                                        
                                        string s="NMUO";                                                              
                                        (yyval.node)=new SFuncNode(all,s);
                                ;}
    break;

  case 40:
#line 240 "parse.y"
    {    
                                        
                                        string s="NLEP";                                                              
                                        (yyval.node)=new SFuncNode(all,s);
                                ;}
    break;

  case 41:
#line 245 "parse.y"
    {    
                                        
                                        string s="NPHO";                                                              
                                        (yyval.node)=new SFuncNode(all,s);
                                ;}
    break;

  case 42:
#line 250 "parse.y"
    {    
                                        
                                        string s="NJET";                                                              
                                        (yyval.node)=new SFuncNode(all,s);
                                ;}
    break;

  case 43:
#line 255 "parse.y"
    {    
                                        
                                        string s="NBJET";                                                              
                                        (yyval.node)=new SFuncNode(all,s);
                                ;}
    break;

  case 44:
#line 260 "parse.y"
    {    
                                        
                                        string s="NQGJET";                                                              
                                        (yyval.node)=new SFuncNode(all,s);
                                ;}
    break;

  case 45:
#line 265 "parse.y"
    {    
                                        
                                        string s="HT";                                                              
                                        (yyval.node)=new SFuncNode(all,s);
                                ;}
    break;

  case 46:
#line 270 "parse.y"
    {    
                                        
                                        string s="METMWT";                                                              
                                        (yyval.node)=new SFuncNode(all,s);
                                ;}
    break;

  case 47:
#line 275 "parse.y"
    {    
                                        
                                        string s="MWT";                                                              
                                        (yyval.node)=new SFuncNode(all,s);
                                ;}
    break;

  case 48:
#line 280 "parse.y"
    {    
                                        
                                        string s="MET";                                                              
                                        (yyval.node)=new SFuncNode(all,s);
                                ;}
    break;

  case 49:
#line 285 "parse.y"
    {    
                                        
                                        (yyval.node)=new SFuncNode(all,"all");

                                ;}
    break;

  case 50:
#line 290 "parse.y"
    {    
                                        
                                        string s="LEPSF";                                                              
                                        (yyval.node)=new SFuncNode(all,s);
                                ;}
    break;

  case 51:
#line 296 "parse.y"
    { pnum=0; TmpParticle.swap(TmpParticle1); ;}
    break;

  case 52:
#line 296 "parse.y"
    { 
                                                        string s=(yyvsp[(2) - (6)].s);
                                                        string s2=(yyvsp[(5) - (6)].s);
                                                        s="{ "+s+" , "+s2+" }";                        
                                                        (yyval.s)=strdup(s.c_str());

                                                        ;}
    break;

  case 53:
#line 304 "parse.y"
    {                                                 
                                                char s [512];
                                                strcpy(s,(yyval.s)); 
                                                strcat(s," ");
                                                strcat(s,(yyvsp[(2) - (2)].s));
                                                strcpy((yyval.s),s);                                       

                                        ;}
    break;

  case 54:
#line 312 "parse.y"
    {if (pnum==0){
                                                (yyval.s)=strdup((yyvsp[(1) - (1)].s));                                                       
                                        }
                                        else{                                                
                                                char s [512];
                                                strcpy(s,(yyval.s)); 
                                                strcat(s," ");
                                                strcat(s,(yyvsp[(1) - (1)].s));
                                                strcpy((yyval.s),s);
                                        }
                                        pnum++;;}
    break;

  case 55:
#line 324 "parse.y"
    {
                                myParticle a;
                                a.type = "ELE";
                                a.index = (int)(yyvsp[(3) - (3)].real);
                                TmpParticle.push_back(a);                            
                                tmp="ele_"+to_string((int)(yyvsp[(3) - (3)].real));                        
                                (yyval.s)=strdup(tmp.c_str());
                                                        
                            ;}
    break;

  case 56:
#line 333 "parse.y"
    {       tmp="muo_"+to_string((int)(yyvsp[(3) - (3)].real));                        
                                (yyval.s)=strdup(tmp.c_str());
                                myParticle a;
                                a.type = "MUO";
                                a.index = (int)(yyvsp[(3) - (3)].real);
                                TmpParticle.push_back(a);  
                                
                        ;}
    break;

  case 57:
#line 341 "parse.y"
    {       tmp="lep_"+to_string((int)(yyvsp[(3) - (3)].real));                        
                                (yyval.s)=strdup(tmp.c_str());
                                myParticle a;
                                a.type = "LEP";
                                a.index = (int)(yyvsp[(3) - (3)].real);
                                TmpParticle.push_back(a);  
                                
                        ;}
    break;

  case 58:
#line 349 "parse.y"
    {       tmp="pho_"+to_string((int)(yyvsp[(3) - (3)].real));                        
                                (yyval.s)=strdup(tmp.c_str());
                                myParticle a;
                                a.type = "PHO";
                                a.index = (int)(yyvsp[(3) - (3)].real);
                                TmpParticle.push_back(a);  
                                
                        ;}
    break;

  case 59:
#line 357 "parse.y"
    {       tmp="jet_"+to_string((int)(yyvsp[(3) - (3)].real));                        
                                (yyval.s)=strdup(tmp.c_str());
                                myParticle a;
                                a.type = "JET";
                                a.index = (int)(yyvsp[(3) - (3)].real);
                                TmpParticle.push_back(a);  
                                
                        ;}
    break;

  case 60:
#line 365 "parse.y"
    {      tmp="bjet_"+to_string((int)(yyvsp[(3) - (3)].real));                        
                                (yyval.s)=strdup(tmp.c_str());
                                myParticle a;
                                a.type = "BJET";
                                a.index = (int)(yyvsp[(3) - (3)].real);
                                TmpParticle.push_back(a);  
                                
                        ;}
    break;

  case 61:
#line 373 "parse.y"
    {      tmp="qgjet_"+to_string((int)(yyvsp[(3) - (3)].real));                        
                                (yyval.s)=strdup(tmp.c_str());
                                myParticle a;
                                a.type = "QGJET";
                                a.index = (int)(yyvsp[(3) - (3)].real);
                                TmpParticle.push_back(a);  
                                
                        ;}
    break;

  case 62:
#line 381 "parse.y"
    {       tmp="numet_"+to_string((int)(yyvsp[(3) - (3)].real));                        
                                (yyval.s)=strdup(tmp.c_str());
                                myParticle a;
                                a.type = "NUMET";
                                a.index = (int)(yyvsp[(3) - (3)].real);
                                TmpParticle.push_back(a);  
                                
                        ;}
    break;

  case 63:
#line 389 "parse.y"
    {     tmp="metlv_"+to_string((int)(yyvsp[(3) - (3)].real));                        
                                (yyval.s)=strdup(tmp.c_str());
                                myParticle a;
                                a.type = "METLV";
                                a.index = (int)(yyvsp[(3) - (3)].real);
                                TmpParticle.push_back(a);  
                                
                        ;}
    break;

  case 64:
#line 397 "parse.y"
    { //we want the original defintions as well -> put it in parts and put the rest in vectorParts
                
                map<string,vector<myParticle> >::iterator it;
                it = ListParts->find((yyvsp[(1) - (1)].s));
     
                if(it == ListParts->end()) {
                        cout <<(yyvsp[(1) - (1)].s)<<" : " ;
                        yyerror(NULL,NULL,NULL,NULL,NULL,NULL,"Particule not defined");
                        YYERROR;//stops parsing if particle not found
                        
                }
                else {
                        vector<myParticle> newList= it->second;
                        TmpParticle.insert(TmpParticle.end(), newList.begin(), newList.end());
                        (yyval.s)=(yyvsp[(1) - (1)].s);
                }

               ;}
    break;

  case 65:
#line 416 "parse.y"
    {(yyval.real)=-(yyvsp[(2) - (2)].real);;}
    break;

  case 66:
#line 417 "parse.y"
    {(yyval.real)= (yyvsp[(1) - (1)].real);;}
    break;

  case 69:
#line 422 "parse.y"
    { //find a way to print commands                                     
                                         NodeCuts->insert(make_pair(++cutcount,(yyvsp[(2) - (2)].node)));
				;}
    break;

  case 70:
#line 425 "parse.y"
    {                                         
                                        Node* a=new SFuncNode(all,"all");
                                        NodeCuts->insert(make_pair(++cutcount,a));
				;}
    break;

  case 71:
#line 429 "parse.y"
    {                                         
                                        //NodeCuts->insert(make_pair(++cutcount,$2));
    
				;}
    break;

  case 72:
#line 433 "parse.y"
    {
                                        //find child node
                                        map<string, Node *>::iterator it ;
                                        it = NodeVars->find((yyvsp[(12) - (12)].s));
                        
                                        if(it == NodeVars->end()) {
                                                cout <<(yyvsp[(12) - (12)].s)<<" : " ;
                                                yyerror(NULL,NULL,NULL,NULL,NULL,NULL,"Variable not defined");
                                                YYERROR;//stops parsing if variable not found
                                                
                                        }
                                        else {
                                                Node* child=it->second;
                                                Node* h=new HistoNode((yyvsp[(2) - (12)].s),(yyvsp[(4) - (12)].s),(yyvsp[(6) - (12)].real),(yyvsp[(8) - (12)].real),(yyvsp[(10) - (12)].real),child);
                                                NodeCuts->insert(make_pair(++cutcount,h));
                                        }

                                        
    
				;}
    break;

  case 73:
#line 454 "parse.y"
    {                                                 
                                                char s [512];
                                                strcpy(s,(yyval.s)); 
                                                strcat(s," ");
                                                strcat(s,(yyvsp[(2) - (2)].s));
                                                strcpy((yyval.s),s);                                       

                                        ;}
    break;

  case 74:
#line 462 "parse.y"
    {if (dnum==0){
                                                (yyval.s)=strdup((yyvsp[(1) - (1)].s));                                                       
                                        }
                                        else{                                                
                                                char s [512];
                                                strcpy(s,(yyval.s)); 
                                                strcat(s," ");
                                                strcat(s,(yyvsp[(1) - (1)].s));
                                                strcpy((yyval.s),s);
                                        }
                                        dnum++;;}
    break;

  case 75:
#line 474 "parse.y"
    { 
                        // string s1=$1; string s3=$3;string s4=$5;
                        // tmp=s1+" ? "+s3+" : "+s4;   
                        // $$=strdup(tmp.c_str()); 
                        ;}
    break;

  case 76:
#line 480 "parse.y"
    {
                        //$$=$1;
                        ;}
    break;

  case 77:
#line 483 "parse.y"
    {
               //tmp= " all " ;$$=strdup(tmp.c_str());
               ;}
    break;

  case 78:
#line 486 "parse.y"
    {
                        //$$=$1;
                        ;}
    break;

  case 79:
#line 490 "parse.y"
    { 
                                        (yyval.node)=new BinaryNode(lt,(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node),"<"); 
                                        ;}
    break;

  case 80:
#line 493 "parse.y"
    { 
                                        (yyval.node)=new BinaryNode(gt,(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node),">"); 
                                        ;}
    break;

  case 81:
#line 496 "parse.y"
    { 
                                        (yyval.node)=new BinaryNode(le,(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node),"<="); 
                                        ;}
    break;

  case 82:
#line 499 "parse.y"
    { 
                                        (yyval.node)=new BinaryNode(ge,(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node),">="); 
                                        ;}
    break;

  case 83:
#line 502 "parse.y"
    { 
                                        (yyval.node)=new BinaryNode(eq,(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node),"=="); 
                                        ;}
    break;

  case 84:
#line 505 "parse.y"
    { 
                                        (yyval.node)=new BinaryNode(ne,(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node),"!="); 
                                        ;}
    break;

  case 85:
#line 508 "parse.y"
    {                Node* limit1=(yyvsp[(3) - (4)].node);
                                        Node* limit2=(yyvsp[(4) - (4)].node);
                                        Node* c1=new BinaryNode(ge,(yyvsp[(1) - (4)].node),limit1,">=");
                                        Node* c2=new BinaryNode(le,(yyvsp[(1) - (4)].node),limit2,"<=");
                                        (yyval.node)=new BinaryNode(LogicalAnd,c1,c2,"AND"); 
                                        
                                        ;}
    break;

  case 86:
#line 515 "parse.y"
    {                Node* limit1=(yyvsp[(3) - (4)].node);
                                        Node* limit2=(yyvsp[(4) - (4)].node);
                                        Node* c1=new BinaryNode(gt,(yyvsp[(1) - (4)].node),limit1,">");
                                        Node* c2=new BinaryNode(lt,(yyvsp[(1) - (4)].node),limit2,"<");
                                        (yyval.node)=new BinaryNode(LogicalAnd,c1,c2,"AND"); 
                                        
                                        ;}
    break;

  case 87:
#line 522 "parse.y"
    { 
                                        (yyval.node)=new BinaryNode(LogicalAnd,(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node),"AND"); 
                                        ;}
    break;

  case 88:
#line 525 "parse.y"
    { 
                                        (yyval.node)=new BinaryNode(LogicalOr,(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node),"OR"); 
                                        ;}
    break;

  case 89:
#line 528 "parse.y"
    { 
                                        (yyval.node)=(yyvsp[(2) - (3)].node); 
                                ;}
    break;

  case 90:
#line 532 "parse.y"
    { 
                (yyval.node)=new BinaryNode(add,(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node),"+"); 
               ;}
    break;

  case 91:
#line 535 "parse.y"
    { 
                (yyval.node)=new BinaryNode(sub,(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node),"-"); 
               ;}
    break;

  case 92:
#line 538 "parse.y"
    { 
                (yyval.node)=new BinaryNode(mult,(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node),"*"); 
               ;}
    break;

  case 93:
#line 541 "parse.y"
    { 
                (yyval.node)=new BinaryNode(div,(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node),"/"); 
               ;}
    break;

  case 94:
#line 544 "parse.y"
    {          
               (yyval.node)=new BinaryNode(pow,(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node),"^");
               ;}
    break;

  case 95:
#line 547 "parse.y"
    { 
                        (yyval.node)=new UnaryAONode(unaryMinu,(yyvsp[(2) - (2)].node),"-");
               ;}
    break;

  case 96:
#line 550 "parse.y"
    {    
                        (yyval.node)=new UnaryAONode(cos,(yyvsp[(3) - (4)].node),"cos"); 
               ;}
    break;

  case 97:
#line 553 "parse.y"
    {    //string s3=$3;
                        // tmp=" sin( "+s3+" ) ";   
                        // $$=strdup(tmp.c_str()); 
                        (yyval.node)=new UnaryAONode(sin,(yyvsp[(3) - (4)].node),"sin");
               ;}
    break;

  case 98:
#line 558 "parse.y"
    {    //string s3=$3;
                        //tmp=" tan( "+s3+" ) ";   
                        //$$=strdup(tmp.c_str()); 
                        (yyval.node)=new UnaryAONode(tan,(yyvsp[(3) - (4)].node),"tan");
               ;}
    break;

  case 99:
#line 563 "parse.y"
    {    //string s3=$2;
                        //tmp=" ( "+s3+" ) ";   
                        //$$=strdup(tmp.c_str()); 
                        (yyval.node)=(yyvsp[(2) - (3)].node);
               ;}
    break;

  case 100:
#line 568 "parse.y"
    {       tmp=to_string((yyvsp[(1) - (1)].real)); 
                //$$=strdup(tmp.c_str()); MAKE A TMP STRING AND CONCAT 
                (yyval.node)=new ValueNode((yyvsp[(1) - (1)].real));
                ;}
    break;

  case 101:
#line 572 "parse.y"
    {  
                (yyval.node)=new ValueNode((yyvsp[(1) - (1)].real));
                ;}
    break;

  case 102:
#line 575 "parse.y"
    {(yyval.node)=(yyvsp[(1) - (1)].node); pnum=0;;}
    break;

  case 103:
#line 577 "parse.y"
    { //we want the original defintions as well
                map<string, Node *>::iterator it ;
                it = NodeVars->find((yyvsp[(1) - (1)].s));
     
                if(it == NodeVars->end()) {
                        cout <<(yyvsp[(1) - (1)].s)<<" : " ;
                        yyerror(NULL,NULL,NULL,NULL,NULL,NULL,"Variable not defined");
                        YYERROR;//stops parsing if variable not found
                        
                }
                else {
                        (yyval.node)=it->second;
                }
                //get the node from variable map
               ;}
    break;


/* Line 1267 of yacc.c.  */
#line 2654 "b.cpp"
      default: break;
    }
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
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (parts, NodeVars, ListParts, NodeCuts, Initializations, DataFormats, YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (parts, NodeVars, ListParts, NodeCuts, Initializations, DataFormats, yymsg);
	  }
	else
	  {
	    yyerror (parts, NodeVars, ListParts, NodeCuts, Initializations, DataFormats, YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
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
		      yytoken, &yylval, parts, NodeVars, ListParts, NodeCuts, Initializations, DataFormats);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse look-ahead token after shifting the error
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
      if (yyn != YYPACT_NINF)
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
		  yystos[yystate], yyvsp, parts, NodeVars, ListParts, NodeCuts, Initializations, DataFormats);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

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

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (parts, NodeVars, ListParts, NodeCuts, Initializations, DataFormats, YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval, parts, NodeVars, ListParts, NodeCuts, Initializations, DataFormats);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp, parts, NodeVars, ListParts, NodeCuts, Initializations, DataFormats);
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


#line 593 "parse.y"




