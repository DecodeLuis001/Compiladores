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
     IDENTIFIER = 258,
     CONSTANT = 259,
     STRING_LITERAL = 260,
     SIZEOF = 261,
     PTR_OP = 262,
     INC_OP = 263,
     DEC_OP = 264,
     LEFT_OP = 265,
     RIGHT_OP = 266,
     LE_OP = 267,
     GE_OP = 268,
     EQ_OP = 269,
     NE_OP = 270,
     AND_OP = 271,
     OR_OP = 272,
     MUL_ASSIGN = 273,
     DIV_ASSIGN = 274,
     MOD_ASSIGN = 275,
     ADD_ASSIGN = 276,
     SUB_ASSIGN = 277,
     LEFT_ASSIGN = 278,
     RIGHT_ASSIGN = 279,
     AND_ASSIGN = 280,
     XOR_ASSIGN = 281,
     OR_ASSIGN = 282,
     TYPE_NAME = 283,
     TYPEDEF = 284,
     EXTERN = 285,
     STATIC = 286,
     AUTO = 287,
     REGISTER = 288,
     CHAR = 289,
     SHORT = 290,
     INT = 291,
     LONG = 292,
     SIGNED = 293,
     UNSIGNED = 294,
     FLOAT = 295,
     DOUBLE = 296,
     CONST = 297,
     VOLATILE = 298,
     VOID = 299,
     STRUCT = 300,
     UNION = 301,
     ENUM = 302,
     ELLIPSIS = 303,
     CASE = 304,
     DEFAULT = 305,
     IF = 306,
     ELSE = 307,
     SWITCH = 308,
     WHILE = 309,
     DO = 310,
     FOR = 311,
     GOTO = 312,
     CONTINUE = 313,
     BREAK = 314,
     RETURN = 315,
     NO_ELSE = 316
   };
#endif
/* Tokens.  */
#define IDENTIFIER 258
#define CONSTANT 259
#define STRING_LITERAL 260
#define SIZEOF 261
#define PTR_OP 262
#define INC_OP 263
#define DEC_OP 264
#define LEFT_OP 265
#define RIGHT_OP 266
#define LE_OP 267
#define GE_OP 268
#define EQ_OP 269
#define NE_OP 270
#define AND_OP 271
#define OR_OP 272
#define MUL_ASSIGN 273
#define DIV_ASSIGN 274
#define MOD_ASSIGN 275
#define ADD_ASSIGN 276
#define SUB_ASSIGN 277
#define LEFT_ASSIGN 278
#define RIGHT_ASSIGN 279
#define AND_ASSIGN 280
#define XOR_ASSIGN 281
#define OR_ASSIGN 282
#define TYPE_NAME 283
#define TYPEDEF 284
#define EXTERN 285
#define STATIC 286
#define AUTO 287
#define REGISTER 288
#define CHAR 289
#define SHORT 290
#define INT 291
#define LONG 292
#define SIGNED 293
#define UNSIGNED 294
#define FLOAT 295
#define DOUBLE 296
#define CONST 297
#define VOLATILE 298
#define VOID 299
#define STRUCT 300
#define UNION 301
#define ENUM 302
#define ELLIPSIS 303
#define CASE 304
#define DEFAULT 305
#define IF 306
#define ELSE 307
#define SWITCH 308
#define WHILE 309
#define DO 310
#define FOR 311
#define GOTO 312
#define CONTINUE 313
#define BREAK 314
#define RETURN 315
#define NO_ELSE 316




/* Copy the first part of user declarations.  */
#line 1 "ansic.y"

	#include<stdio.h>    
	#include<stdlib.h>
	#include<iostream>
	#include<iomanip>
	#include<fstream>
	#include<string>
	#include<cstring>
	#include<list>

	using namespace std;
	//Archivos ubicados en otras ubicaciones que no son el programa.
	extern int yylex();
	extern void yyerror(const char *);
	extern FILE *yyin;

	typedef struct symrec symrec;

	#include "symfuncs.h"

	#include "genlib.h"


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
#line 25 "ansic.y"
{
	struct 
    {
		union
		{
			char cval;
			long int ival;
			double dval;
			char *str;
			char *name;
		};
		int type;
    } token;
	VAR_DATA *id_data; /*Datos del identificador*/
	std::list< VAR_DATA * > *idlist;
	int scsp;
	int qual;
	int typsp;
	int op;
	int typ;
	int asop;
	int instr;
	std::list<int> *sqlist;
	VAR_DATA sym; /*para poner datos sobre una variable ya declarada*/
	struct
	{
		int typq;
		int level;
	}pstruc;
	struct
	{
		std::list<int> *breaklist;				//Salto a fuera de un switch
		std::list<int> *nextlist;				//Para salto siguiente de la instruccion.
		std::list<int> *continuelist;			//Para salto al inicio de un ciclo.
		std::list<GOTO_DATA *> *gotolist;		//Para salto con GOTO
		std::list<CASE_DATA *> *caselist;		//Para salto a los case de un switch.
	}lists;
}
/* Line 193 of yacc.c.  */
#line 280 "ansic.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 293 "ansic.tab.c"

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
#define YYFINAL  60
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1240

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  86
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  73
/* YYNRULES -- Number of rules.  */
#define YYNRULES  221
/* YYNRULES -- Number of states.  */
#define YYNSTATES  378

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   316

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    73,     2,     2,     2,    75,    68,     2,
      62,    63,    69,    70,    67,    71,    66,    74,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    81,    83,
      76,    82,    77,    80,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    64,     2,    65,    78,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    84,    79,    85,    72,     2,     2,     2,
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
      55,    56,    57,    58,    59,    60,    61
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     7,     9,    13,    15,    20,    24,
      29,    33,    37,    40,    43,    45,    49,    51,    54,    57,
      60,    63,    68,    70,    72,    74,    76,    78,    80,    82,
      87,    89,    93,    97,   101,   103,   107,   111,   113,   117,
     121,   123,   127,   131,   135,   139,   141,   145,   149,   151,
     155,   157,   161,   163,   167,   169,   174,   176,   181,   182,
     184,   185,   195,   197,   201,   203,   205,   207,   209,   211,
     213,   215,   217,   219,   221,   223,   225,   229,   231,   234,
     238,   240,   243,   245,   248,   250,   253,   255,   259,   261,
     265,   267,   269,   271,   273,   275,   277,   279,   281,   283,
     285,   287,   289,   291,   293,   295,   297,   299,   305,   310,
     313,   315,   317,   319,   322,   326,   329,   331,   334,   336,
     338,   342,   344,   347,   351,   356,   362,   365,   367,   371,
     373,   377,   379,   381,   384,   386,   388,   392,   397,   401,
     406,   411,   415,   417,   420,   423,   427,   429,   432,   434,
     438,   440,   444,   447,   450,   452,   454,   458,   460,   463,
     465,   467,   470,   474,   477,   481,   485,   490,   493,   497,
     501,   506,   508,   512,   517,   519,   523,   524,   526,   527,
     531,   533,   535,   537,   539,   540,   545,   551,   556,   559,
     563,   567,   572,   574,   577,   579,   583,   585,   588,   590,
     597,   608,   615,   617,   625,   635,   644,   656,   660,   663,
     666,   669,   673,   675,   678,   680,   682,   687,   688,   693,
     697,   698
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     154,     0,    -1,     3,    -1,     4,    -1,     5,    -1,    62,
     108,    63,    -1,    87,    -1,    88,    64,   108,    65,    -1,
      88,    62,    63,    -1,    88,    62,    89,    63,    -1,    88,
      66,     3,    -1,    88,     7,     3,    -1,    88,     8,    -1,
      88,     9,    -1,   106,    -1,    89,    67,   106,    -1,    88,
      -1,     8,    90,    -1,     9,    90,    -1,    91,    92,    -1,
       6,    90,    -1,     6,    62,   135,    63,    -1,    68,    -1,
      69,    -1,    70,    -1,    71,    -1,    72,    -1,    73,    -1,
      90,    -1,    62,   135,    63,    92,    -1,    92,    -1,    93,
      69,    92,    -1,    93,    74,    92,    -1,    93,    75,    92,
      -1,    93,    -1,    94,    70,    93,    -1,    94,    71,    93,
      -1,    94,    -1,    95,    10,    94,    -1,    95,    11,    94,
      -1,    95,    -1,    96,    76,    95,    -1,    96,    77,    95,
      -1,    96,    12,    95,    -1,    96,    13,    95,    -1,    96,
      -1,    97,    14,    96,    -1,    97,    15,    96,    -1,    97,
      -1,    98,    68,    97,    -1,    98,    -1,    99,    78,    98,
      -1,    99,    -1,   100,    79,    99,    -1,   100,    -1,   101,
      16,   143,   100,    -1,   101,    -1,   102,    17,   143,   101,
      -1,    -1,   102,    -1,    -1,   102,    80,   143,   108,    81,
     105,   103,   143,   104,    -1,   104,    -1,    90,   107,   106,
      -1,    82,    -1,    18,    -1,    19,    -1,    20,    -1,    21,
      -1,    22,    -1,    23,    -1,    24,    -1,    25,    -1,    26,
      -1,    27,    -1,   106,    -1,   108,    67,   106,    -1,   104,
      -1,   111,    83,    -1,   111,   112,    83,    -1,   114,    -1,
     114,   111,    -1,   115,    -1,   115,   111,    -1,   126,    -1,
     126,   111,    -1,   113,    -1,   112,    67,   113,    -1,   127,
      -1,   127,    82,   138,    -1,    29,    -1,    30,    -1,    31,
      -1,    32,    -1,    33,    -1,    44,    -1,    34,    -1,    35,
      -1,    36,    -1,    37,    -1,    40,    -1,    41,    -1,    38,
      -1,    39,    -1,   116,    -1,   123,    -1,    28,    -1,   117,
       3,    84,   118,    85,    -1,   117,    84,   118,    85,    -1,
     117,     3,    -1,    45,    -1,    46,    -1,   119,    -1,   118,
     119,    -1,   120,   121,    83,    -1,   115,   120,    -1,   115,
      -1,   126,   120,    -1,   126,    -1,   122,    -1,   121,    67,
     122,    -1,   127,    -1,    81,   109,    -1,   127,    81,   109,
      -1,    47,    84,   124,    85,    -1,    47,     3,    84,   124,
      85,    -1,    47,     3,    -1,   125,    -1,   124,    67,   125,
      -1,     3,    -1,     3,    82,   109,    -1,    42,    -1,    43,
      -1,   129,   128,    -1,   128,    -1,     3,    -1,    62,   127,
      63,    -1,   128,    64,   109,    65,    -1,   128,    64,    65,
      -1,   128,    62,   131,    63,    -1,   128,    62,   134,    63,
      -1,   128,    62,    63,    -1,    69,    -1,    69,   130,    -1,
      69,   129,    -1,    69,   130,   129,    -1,   126,    -1,   130,
     126,    -1,   132,    -1,   132,    67,    48,    -1,   133,    -1,
     132,    67,   133,    -1,   111,   127,    -1,   111,   136,    -1,
     111,    -1,     3,    -1,   134,    67,     3,    -1,   120,    -1,
     120,   136,    -1,   129,    -1,   137,    -1,   129,   137,    -1,
      62,   136,    63,    -1,    64,    65,    -1,    64,   109,    65,
      -1,   137,    64,    65,    -1,   137,    64,   109,    65,    -1,
      62,    63,    -1,    62,   131,    63,    -1,   137,    62,    63,
      -1,   137,    62,   131,    63,    -1,   106,    -1,    84,   139,
      85,    -1,    84,   139,    67,    85,    -1,   138,    -1,   139,
      67,   138,    -1,    -1,   144,    -1,    -1,   140,   142,   145,
      -1,   148,    -1,   150,    -1,   152,    -1,   153,    -1,    -1,
       3,    81,   143,   141,    -1,    49,   109,    81,   143,   141,
      -1,    50,    81,   143,   141,    -1,    84,    85,    -1,    84,
     147,    85,    -1,    84,   146,    85,    -1,    84,   146,   147,
      85,    -1,   110,    -1,   146,   110,    -1,   141,    -1,   147,
     143,   141,    -1,    83,    -1,   108,    83,    -1,   108,    -1,
      51,    62,   149,    63,   143,   141,    -1,    51,    62,   149,
      63,   143,   141,    52,   103,   143,   141,    -1,    53,    62,
     108,    63,   103,   141,    -1,   148,    -1,    54,   143,    62,
     149,    63,   143,   141,    -1,    55,   143,   141,    54,   143,
      62,   149,    63,    83,    -1,    56,    62,   148,   143,   151,
     143,    63,   141,    -1,    56,    62,   148,   143,   151,   143,
     108,    63,   103,   143,   141,    -1,    57,     3,    83,    -1,
      58,    83,    -1,    59,    83,    -1,    60,    83,    -1,    60,
     108,    83,    -1,   155,    -1,   154,   155,    -1,   156,    -1,
     110,    -1,   111,   127,   146,   145,    -1,    -1,   111,   127,
     157,   145,    -1,   127,   146,   145,    -1,    -1,   127,   158,
     145,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   134,   134,   149,   180,   202,   209,   213,   256,   265,
     282,   283,   284,   305,   327,   337,   347,   351,   364,   378,
     423,   436,   453,   457,   461,   465,   469,   473,   480,   493,
     524,   528,   536,   545,   556,   560,   569,   581,   585,   586,
     590,   594,   602,   610,   618,   629,   633,   641,   652,   656,
     668,   672,   684,   688,   700,   704,   715,   719,   729,   736,
     740,   740,   759,   763,  1009,  1013,  1017,  1021,  1025,  1029,
    1033,  1037,  1041,  1045,  1049,  1056,  1060,  1067,  1074,  1075,
    1110,  1116,  1121,  1127,  1132,  1138,  1146,  1153,  1161,  1165,
    1174,  1178,  1182,  1186,  1190,  1197,  1201,  1205,  1209,  1213,
    1217,  1221,  1225,  1229,  1233,  1236,  1240,  1247,  1248,  1249,
    1253,  1254,  1258,  1259,  1263,  1267,  1272,  1278,  1283,  1292,
    1293,  1297,  1298,  1299,  1303,  1304,  1305,  1309,  1310,  1314,
    1315,  1319,  1323,  1330,  1335,  1356,  1365,  1366,  1378,  1386,
    1393,  1394,  1402,  1407,  1412,  1417,  1426,  1430,  1439,  1443,
    1447,  1455,  1465,  1473,  1474,  1478,  1483,  1490,  1494,  1498,
    1499,  1500,  1504,  1505,  1506,  1507,  1508,  1509,  1510,  1511,
    1512,  1516,  1520,  1521,  1525,  1526,  1529,  1533,  1538,  1538,
    1546,  1554,  1559,  1564,  1570,  1576,  1585,  1596,  1606,  1613,
    1617,  1624,  1631,  1632,  1636,  1640,  1653,  1658,  1664,  1681,
    1689,  1698,  1738,  1756,  1768,  1776,  1788,  1805,  1814,  1823,
    1832,  1841,  1853,  1854,  1858,  1859,  1863,  1864,  1864,  1884,
    1885,  1885
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IDENTIFIER", "CONSTANT",
  "STRING_LITERAL", "SIZEOF", "PTR_OP", "INC_OP", "DEC_OP", "LEFT_OP",
  "RIGHT_OP", "LE_OP", "GE_OP", "EQ_OP", "NE_OP", "AND_OP", "OR_OP",
  "MUL_ASSIGN", "DIV_ASSIGN", "MOD_ASSIGN", "ADD_ASSIGN", "SUB_ASSIGN",
  "LEFT_ASSIGN", "RIGHT_ASSIGN", "AND_ASSIGN", "XOR_ASSIGN", "OR_ASSIGN",
  "TYPE_NAME", "TYPEDEF", "EXTERN", "STATIC", "AUTO", "REGISTER", "CHAR",
  "SHORT", "INT", "LONG", "SIGNED", "UNSIGNED", "FLOAT", "DOUBLE", "CONST",
  "VOLATILE", "VOID", "STRUCT", "UNION", "ENUM", "ELLIPSIS", "CASE",
  "DEFAULT", "IF", "ELSE", "SWITCH", "WHILE", "DO", "FOR", "GOTO",
  "CONTINUE", "BREAK", "RETURN", "NO_ELSE", "'('", "')'", "'['", "']'",
  "'.'", "','", "'&'", "'*'", "'+'", "'-'", "'~'", "'!'", "'/'", "'%'",
  "'<'", "'>'", "'^'", "'|'", "'?'", "':'", "'='", "';'", "'{'", "'}'",
  "$accept", "primary_expression", "postfix_expression",
  "argument_expression_list", "unary_expression", "unary_operator",
  "cast_expression", "multiplicative_expression", "additive_expression",
  "shift_expression", "relational_expression", "equality_expression",
  "and_expression", "exclusive_or_expression", "inclusive_or_expression",
  "logical_and_expression", "logical_or_expression", "M",
  "conditional_expression", "@1", "assignment_expression",
  "assignment_operator", "expression", "constant_expression",
  "declaration", "declaration_specifiers", "init_declarator_list",
  "init_declarator", "storage_class_specifier", "type_specifier",
  "struct_or_union_specifier", "struct_or_union",
  "struct_declaration_list", "struct_declaration",
  "specifier_qualifier_list", "struct_declarator_list",
  "struct_declarator", "enum_specifier", "enumerator_list", "enumerator",
  "type_qualifier", "declarator", "direct_declarator", "pointer",
  "type_qualifier_list", "parameter_type_list", "parameter_list",
  "parameter_declaration", "identifier_list", "type_name",
  "abstract_declarator", "direct_abstract_declarator", "initializer",
  "initializer_list", "P", "statement", "@2", "N", "labeled_statement",
  "compound_statement", "declaration_list", "statement_list",
  "expression_statement", "logic_expression", "selection_statement",
  "logic_expression_statement", "iteration_statement", "jump_statement",
  "translation_unit", "external_declaration", "function_definition", "@3",
  "@4", 0
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
     315,   316,    40,    41,    91,    93,    46,    44,    38,    42,
      43,    45,   126,    33,    47,    37,    60,    62,    94,   124,
      63,    58,    61,    59,   123,   125
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    86,    87,    87,    87,    87,    88,    88,    88,    88,
      88,    88,    88,    88,    89,    89,    90,    90,    90,    90,
      90,    90,    91,    91,    91,    91,    91,    91,    92,    92,
      93,    93,    93,    93,    94,    94,    94,    95,    95,    95,
      96,    96,    96,    96,    96,    97,    97,    97,    98,    98,
      99,    99,   100,   100,   101,   101,   102,   102,   103,   104,
     105,   104,   106,   106,   107,   107,   107,   107,   107,   107,
     107,   107,   107,   107,   107,   108,   108,   109,   110,   110,
     111,   111,   111,   111,   111,   111,   112,   112,   113,   113,
     114,   114,   114,   114,   114,   115,   115,   115,   115,   115,
     115,   115,   115,   115,   115,   115,   115,   116,   116,   116,
     117,   117,   118,   118,   119,   120,   120,   120,   120,   121,
     121,   122,   122,   122,   123,   123,   123,   124,   124,   125,
     125,   126,   126,   127,   127,   128,   128,   128,   128,   128,
     128,   128,   129,   129,   129,   129,   130,   130,   131,   131,
     132,   132,   133,   133,   133,   134,   134,   135,   135,   136,
     136,   136,   137,   137,   137,   137,   137,   137,   137,   137,
     137,   138,   138,   138,   139,   139,   140,   141,   142,   141,
     141,   141,   141,   141,   143,   144,   144,   144,   145,   145,
     145,   145,   146,   146,   147,   147,   148,   148,   149,   150,
     150,   150,   151,   152,   152,   152,   152,   153,   153,   153,
     153,   153,   154,   154,   155,   155,   156,   157,   156,   156,
     158,   156
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     3,     1,     4,     3,     4,
       3,     3,     2,     2,     1,     3,     1,     2,     2,     2,
       2,     4,     1,     1,     1,     1,     1,     1,     1,     4,
       1,     3,     3,     3,     1,     3,     3,     1,     3,     3,
       1,     3,     3,     3,     3,     1,     3,     3,     1,     3,
       1,     3,     1,     3,     1,     4,     1,     4,     0,     1,
       0,     9,     1,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     1,     2,     3,
       1,     2,     1,     2,     1,     2,     1,     3,     1,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     5,     4,     2,
       1,     1,     1,     2,     3,     2,     1,     2,     1,     1,
       3,     1,     2,     3,     4,     5,     2,     1,     3,     1,
       3,     1,     1,     2,     1,     1,     3,     4,     3,     4,
       4,     3,     1,     2,     2,     3,     1,     2,     1,     3,
       1,     3,     2,     2,     1,     1,     3,     1,     2,     1,
       1,     2,     3,     2,     3,     3,     4,     2,     3,     3,
       4,     1,     3,     4,     1,     3,     0,     1,     0,     3,
       1,     1,     1,     1,     0,     4,     5,     4,     2,     3,
       3,     4,     1,     2,     1,     3,     1,     2,     1,     6,
      10,     6,     1,     7,     9,     8,    11,     3,     2,     2,
       2,     3,     1,     2,     1,     1,     4,     0,     4,     3,
       0,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,   135,   106,    90,    91,    92,    93,    94,    96,    97,
      98,    99,   102,   103,   100,   101,   131,   132,    95,   110,
     111,     0,     0,   142,   215,     0,    80,    82,   104,     0,
     105,    84,   220,   134,     0,     0,   212,   214,   126,     0,
       0,   146,   144,   143,    78,     0,    86,    88,    81,    83,
     109,     0,    85,   192,     0,     0,     0,     0,     0,   133,
       1,   213,     0,   129,     0,   127,   136,   147,   145,     0,
      79,     0,     0,     0,     0,   116,     0,   112,     0,   118,
      88,   176,   193,   219,   221,   155,   141,   154,     0,   148,
     150,     0,     2,     3,     4,     0,     0,     0,     0,   138,
      22,    23,    24,    25,    26,    27,     6,    16,    28,     0,
      30,    34,    37,    40,    45,    48,    50,    52,    54,    56,
      59,    77,     0,     0,     0,     0,   124,    87,     0,    28,
      62,   171,    89,   216,   218,     0,   115,   108,   113,     0,
       0,   119,   121,   117,     2,     0,     0,     0,     0,   184,
     184,     0,     0,     0,     0,     0,   196,   188,    75,     0,
     178,   194,   177,   176,   184,   180,   181,   182,   183,     0,
       0,   152,   159,   153,   160,   139,     0,   140,     0,     0,
      20,     0,    17,    18,     0,   157,     0,     0,    12,    13,
       0,     0,     0,    19,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     184,   184,   184,   137,   125,   130,   128,   174,     0,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    64,
       0,   107,   122,     0,   114,     0,   184,     0,   184,     0,
       0,     0,   176,     0,     0,   208,   209,   210,     0,     0,
     197,     0,   190,   184,   189,   176,   167,     0,     0,   163,
       0,   161,     0,     0,   149,   151,   156,     0,     5,     0,
     159,   158,     0,    11,     8,     0,    14,     0,    10,    31,
      32,    33,    35,    36,    38,    39,    43,    44,    41,    42,
      46,    47,    49,    51,    53,     0,     0,     0,     0,   172,
      63,   120,   123,   176,   184,   176,   198,     0,     0,     0,
       0,   184,   207,   211,    76,   179,   191,   195,   168,   162,
     164,   169,     0,   165,     0,    21,    29,     9,     0,     7,
      55,    57,     0,   173,   175,   185,   176,   187,   184,    58,
       0,   184,     0,   170,   166,    15,    60,   186,   176,   176,
     184,     0,   202,   184,    58,   199,   201,   176,     0,     0,
     184,    58,   203,     0,   176,     0,     0,   184,     0,   205,
      58,    61,   176,   204,   184,   200,   176,   206
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,   106,   107,   275,   129,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   349,   130,   354,
     158,   230,   159,   122,    53,    54,    45,    46,    26,    27,
      28,    29,    76,    77,    78,   140,   141,    30,    64,    65,
      31,    32,    33,    34,    43,   257,    89,    90,    91,   186,
     258,   174,   132,   218,   160,   161,   251,   255,   162,    83,
      55,   164,   165,   307,   166,   353,   167,   168,    35,    36,
      37,    73,    56
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -281
static const yytype_int16 yypact[] =
{
     864,  -281,  -281,  -281,  -281,  -281,  -281,  -281,  -281,  -281,
    -281,  -281,  -281,  -281,  -281,  -281,  -281,  -281,  -281,  -281,
    -281,    15,    40,     4,  -281,    31,  1193,  1193,  -281,    23,
    -281,  1193,  1193,   -12,    39,   774,  -281,  -281,   -62,    12,
     -10,  -281,  -281,     4,  -281,   -34,  -281,  1017,  -281,  -281,
     -19,   991,  -281,  -281,    31,  1037,    -1,   909,   579,   -12,
    -281,  -281,    12,    -7,   -37,  -281,  -281,  -281,  -281,    40,
    -281,   437,  1037,    -1,   991,   991,   939,  -281,   126,   991,
       8,   293,  -281,  -281,  -281,  -281,  -281,    58,    62,    68,
    -281,   105,  -281,  -281,  -281,   674,   700,   700,   558,  -281,
    -281,  -281,  -281,  -281,  -281,  -281,  -281,   420,  -281,   721,
    -281,    49,    95,   183,   121,   187,    -8,    20,    81,   229,
      -3,  -281,   118,   -22,   721,    12,  -281,  -281,   437,   805,
    -281,  -281,  -281,  -281,  -281,   959,  -281,  -281,  -281,   721,
      96,  -281,   123,  -281,   176,   721,   185,   213,   215,  -281,
    -281,   216,   276,   198,   199,   485,  -281,  -281,  -281,   158,
    -281,  -281,  -281,   364,   200,  -281,  -281,  -281,  -281,   819,
     603,  -281,    22,  -281,    53,  -281,  1172,  -281,   280,   558,
    -281,   721,  -281,  -281,   156,   127,   221,   283,  -281,  -281,
     244,   721,   285,  -281,   721,   721,   721,   721,   721,   721,
     721,   721,   721,   721,   721,   721,   721,   721,   721,   721,
    -281,  -281,  -281,  -281,  -281,  -281,  -281,  -281,    -9,  -281,
    -281,  -281,  -281,  -281,  -281,  -281,  -281,  -281,  -281,  -281,
     721,  -281,  -281,   126,  -281,   721,  -281,   208,  -281,   721,
     721,   230,   469,   508,   210,  -281,  -281,  -281,   159,   721,
    -281,    -1,  -281,   206,  -281,   469,  -281,   232,   237,  -281,
     238,    53,  1136,   629,  -281,  -281,  -281,   241,  -281,  1094,
      64,  -281,   721,  -281,  -281,   167,  -281,    92,  -281,  -281,
    -281,  -281,    49,    49,    95,    95,   183,   183,   183,   183,
     121,   121,   187,    -8,    20,   721,   721,   721,   382,  -281,
    -281,  -281,  -281,   469,  -281,   469,   243,   242,   188,   721,
     257,  -281,  -281,  -281,  -281,  -281,  -281,  -281,  -281,  -281,
    -281,  -281,   255,  -281,   254,  -281,  -281,  -281,   721,  -281,
      81,   229,   -26,  -281,  -281,  -281,   469,  -281,  -281,  -281,
     278,  -281,   508,  -281,  -281,  -281,  -281,  -281,   469,   469,
    -281,   292,  -281,  -281,  -281,   304,  -281,   469,   721,   650,
    -281,  -281,  -281,   282,   469,   193,   721,  -281,   274,  -281,
    -281,  -281,   469,  -281,  -281,  -281,   469,  -281
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -281,  -281,  -281,  -281,   -58,  -281,   -99,    35,    44,    61,
      63,   151,   152,   150,    76,    78,  -281,  -143,   -57,  -281,
     -69,  -281,   -87,   -60,    19,     5,  -281,   306,  -281,   111,
    -281,  -281,   303,   -32,   -63,  -281,   146,  -281,   318,   256,
     141,     2,   -17,   -15,  -281,   -54,  -281,   207,  -281,   203,
     -74,  -165,  -122,  -281,  -281,  -136,  -281,   -80,  -281,   -52,
     -24,   226,  -234,  -280,  -281,  -281,  -281,  -281,  -281,   349,
    -281,  -281,  -281
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -218
static const yytype_int16 yytable[] =
{
     108,   121,   131,    88,    84,    25,   217,   261,    42,   311,
     193,   184,   136,   173,   211,    63,   143,    59,    38,    24,
     133,   134,    62,    72,    40,     1,    50,    47,    68,   340,
     125,    48,    49,    69,     1,   185,    52,   180,   182,   183,
      25,   249,     1,     1,   138,   125,    16,    17,   126,    70,
      57,   108,    58,    66,    24,   346,    80,   163,   298,   131,
     207,     1,    87,   214,   215,    74,   108,   121,   248,   241,
     242,    80,   172,    23,    82,   124,   299,   212,   363,   232,
     142,   108,   121,    81,   169,   237,   170,   108,   121,   171,
      71,    82,   184,    22,   184,   279,   280,   281,   208,    39,
      23,    22,    22,   138,   277,   261,   310,    51,   352,    23,
     260,   271,   108,   121,    44,   262,   185,   263,   194,   317,
     169,   276,   170,   195,   196,   175,   269,    23,   170,     1,
     295,   296,   297,   201,   202,   176,   108,   108,   108,   108,
     108,   108,   108,   108,   108,   108,   108,   108,   108,   108,
     108,   108,   306,   308,   172,    59,   303,   329,   305,   249,
     209,   300,    75,   233,    41,   197,   198,   335,   177,   337,
     270,    40,   178,   326,    87,   302,   334,   108,   121,   234,
     314,    87,    82,   213,    67,    75,    75,    75,    22,   269,
      75,   170,    79,   199,   200,    23,    23,   203,   204,   315,
     347,   205,   206,   324,   235,   108,   121,   139,   322,    75,
     332,   360,   355,   356,   108,    79,    79,    79,   367,   268,
      79,   362,   306,   249,   336,   249,   249,   374,   369,   131,
     327,   342,   282,   283,   328,   142,   375,   108,   108,    79,
     377,   250,   313,   284,   285,   210,    75,    92,    93,    94,
      95,   339,    96,    97,   270,   249,   370,   236,   348,   345,
     249,   351,   286,   287,   288,   289,   238,    87,   290,   291,
     357,   306,   365,   359,    87,   239,    79,   240,   243,   244,
     366,   245,   246,   266,   272,   254,   273,   372,   278,   304,
      75,   316,   309,   312,   376,   318,   144,    93,    94,    95,
     319,    96,    97,   320,   325,   338,    98,   274,   108,   371,
     249,   341,   100,   101,   102,   103,   104,   105,   343,   344,
      79,     2,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,   350,   145,   146,   147,   368,   148,   149,   150,   151,
     152,   153,   154,   155,   358,    98,   361,   373,   292,   294,
     293,   100,   101,   102,   103,   104,   105,   144,    93,    94,
      95,   330,    96,    97,   331,   127,   156,   135,   157,   301,
     123,   216,   267,   265,    61,    92,    93,    94,    95,   253,
      96,    97,     2,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,     0,   145,   146,   147,     0,   148,   149,   150,
     151,   152,   153,   154,   155,     0,    98,   187,   188,   189,
       0,     0,   100,   101,   102,   103,   104,   105,     0,     0,
      92,    93,    94,    95,    98,    96,    97,   156,     0,   252,
     100,   101,   102,   103,   104,   105,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   128,   333,     0,     0,
       0,     0,   144,    93,    94,    95,     0,    96,    97,     0,
       0,     0,   190,     0,   191,     0,   192,     0,    92,    93,
      94,    95,     0,    96,    97,     0,     0,     0,     0,    98,
       0,     0,     0,     0,     0,   100,   101,   102,   103,   104,
     105,    92,    93,    94,    95,     0,    96,    97,   145,   146,
     147,   128,   148,   149,   150,   151,   152,   153,   154,   155,
       0,    98,     0,     0,     0,     0,     0,   100,   101,   102,
     103,   104,   105,     0,     0,     0,     0,    98,     0,     0,
       0,     0,   156,   100,   101,   102,   103,   104,   105,     0,
       0,    92,    93,    94,    95,     0,    96,    97,   247,     0,
      98,     0,     0,     0,     0,     0,   100,   101,   102,   103,
     104,   105,    92,    93,    94,    95,     2,    96,    97,     0,
       0,   156,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    92,    93,    94,    95,
       0,    96,    97,     0,     0,     0,     0,     0,     0,     0,
      98,     0,     0,     0,     0,     0,   100,   101,   102,   103,
     104,   105,    92,    93,    94,    95,     0,    96,    97,     0,
       0,    98,     0,     0,    99,     0,     0,   100,   101,   102,
     103,   104,   105,    92,    93,    94,    95,     0,    96,    97,
       0,     0,     0,     0,     0,    98,     0,     0,   259,     0,
       0,   100,   101,   102,   103,   104,   105,    92,    93,    94,
      95,     0,    96,    97,     0,     0,     0,     0,     0,     0,
       0,    98,     0,     0,   323,     0,     0,   100,   101,   102,
     103,   104,   105,    92,    93,    94,    95,     0,    96,    97,
       0,     0,    98,   364,     0,     0,     0,     0,   100,   101,
     102,   103,   104,   105,    92,    93,    94,    95,     0,    96,
      97,     0,     0,     0,     0,     0,   179,     0,     0,     0,
       0,     0,   100,   101,   102,   103,   104,   105,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   181,     0,     0,     0,     0,     0,   100,   101,
     102,   103,   104,   105,    60,     0,     0,     1,     0,     0,
       0,     0,     0,    98,     0,     0,     0,     0,     0,   100,
     101,   102,   103,   104,   105,     0,     0,     0,     0,     0,
       0,     0,     2,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,     1,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,     0,     0,     0,    22,     0,     0,     0,
       0,     0,     0,    23,     0,     0,     0,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,     1,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   169,   256,   170,     0,     0,     0,   229,    23,     0,
       0,     0,     2,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    85,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    22,     0,     0,     0,
       0,     0,     0,    23,     0,     0,     0,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     2,     0,     0,
       0,     0,    86,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,     2,     0,     0,
       0,     0,     0,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     2,
       0,     0,     0,     0,   137,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,     0,
       0,     0,     0,     0,   231,     2,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,     2,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    71,
       0,  -217,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    81,     2,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   269,   256,   170,     0,
       0,     0,     0,    23,     2,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   321,
       2,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
     264,     2,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21
};

static const yytype_int16 yycheck[] =
{
      58,    58,    71,    57,    56,     0,   128,   172,    23,   243,
     109,    98,    75,    87,    17,     3,    79,    34,     3,     0,
      72,    73,    84,    47,    22,     3,     3,    25,    43,   309,
      67,    26,    27,    67,     3,    98,    31,    95,    96,    97,
      35,    67,     3,     3,    76,    67,    42,    43,    85,    83,
      62,   109,    64,    63,    35,    81,    54,    81,    67,   128,
      68,     3,    57,    85,   124,    84,   124,   124,   155,   149,
     150,    69,    87,    69,    55,    82,    85,    80,   358,   139,
      78,   139,   139,    84,    62,   145,    64,   145,   145,    87,
      82,    72,   179,    62,   181,   194,   195,   196,    78,    84,
      69,    62,    62,   135,   191,   270,   242,    84,   342,    69,
     170,   185,   170,   170,    83,    62,   179,    64,    69,   255,
      62,   190,    64,    74,    75,    63,    62,    69,    64,     3,
     210,   211,   212,    12,    13,    67,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   239,   240,   169,   172,   236,    65,   238,    67,
      79,   230,    51,    67,    23,    70,    71,   303,    63,   305,
     185,   169,    67,   272,   169,   235,   298,   235,   235,    83,
     249,   176,   163,    65,    43,    74,    75,    76,    62,    62,
      79,    64,    51,    10,    11,    69,    69,    76,    77,   251,
     336,    14,    15,   263,    81,   263,   263,    81,   262,    98,
     297,   354,   348,   349,   272,    74,    75,    76,   361,    63,
      79,   357,   309,    67,   304,    67,    67,   370,   364,   298,
      63,   311,   197,   198,    67,   233,   372,   295,   296,    98,
     376,    83,    83,   199,   200,    16,   135,     3,     4,     5,
       6,    63,     8,     9,   269,    67,    63,    81,   338,   328,
      67,   341,   201,   202,   203,   204,    81,   262,   205,   206,
     350,   358,   359,   353,   269,    62,   135,    62,    62,     3,
     360,    83,    83,     3,    63,    85,     3,   367,     3,    81,
     179,    85,    62,    83,   374,    63,     3,     4,     5,     6,
      63,     8,     9,    65,    63,    63,    62,    63,   366,   366,
      67,    54,    68,    69,    70,    71,    72,    73,    63,    65,
     179,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    63,    49,    50,    51,    63,    53,    54,    55,    56,
      57,    58,    59,    60,    62,    62,    52,    83,   207,   209,
     208,    68,    69,    70,    71,    72,    73,     3,     4,     5,
       6,   295,     8,     9,   296,    69,    83,    74,    85,   233,
      62,   125,   179,   176,    35,     3,     4,     5,     6,   163,
       8,     9,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    -1,    49,    50,    51,    -1,    53,    54,    55,
      56,    57,    58,    59,    60,    -1,    62,     7,     8,     9,
      -1,    -1,    68,    69,    70,    71,    72,    73,    -1,    -1,
       3,     4,     5,     6,    62,     8,     9,    83,    -1,    85,
      68,    69,    70,    71,    72,    73,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    84,    85,    -1,    -1,
      -1,    -1,     3,     4,     5,     6,    -1,     8,     9,    -1,
      -1,    -1,    62,    -1,    64,    -1,    66,    -1,     3,     4,
       5,     6,    -1,     8,     9,    -1,    -1,    -1,    -1,    62,
      -1,    -1,    -1,    -1,    -1,    68,    69,    70,    71,    72,
      73,     3,     4,     5,     6,    -1,     8,     9,    49,    50,
      51,    84,    53,    54,    55,    56,    57,    58,    59,    60,
      -1,    62,    -1,    -1,    -1,    -1,    -1,    68,    69,    70,
      71,    72,    73,    -1,    -1,    -1,    -1,    62,    -1,    -1,
      -1,    -1,    83,    68,    69,    70,    71,    72,    73,    -1,
      -1,     3,     4,     5,     6,    -1,     8,     9,    83,    -1,
      62,    -1,    -1,    -1,    -1,    -1,    68,    69,    70,    71,
      72,    73,     3,     4,     5,     6,    28,     8,     9,    -1,
      -1,    83,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,     3,     4,     5,     6,
      -1,     8,     9,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      62,    -1,    -1,    -1,    -1,    -1,    68,    69,    70,    71,
      72,    73,     3,     4,     5,     6,    -1,     8,     9,    -1,
      -1,    62,    -1,    -1,    65,    -1,    -1,    68,    69,    70,
      71,    72,    73,     3,     4,     5,     6,    -1,     8,     9,
      -1,    -1,    -1,    -1,    -1,    62,    -1,    -1,    65,    -1,
      -1,    68,    69,    70,    71,    72,    73,     3,     4,     5,
       6,    -1,     8,     9,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    62,    -1,    -1,    65,    -1,    -1,    68,    69,    70,
      71,    72,    73,     3,     4,     5,     6,    -1,     8,     9,
      -1,    -1,    62,    63,    -1,    -1,    -1,    -1,    68,    69,
      70,    71,    72,    73,     3,     4,     5,     6,    -1,     8,
       9,    -1,    -1,    -1,    -1,    -1,    62,    -1,    -1,    -1,
      -1,    -1,    68,    69,    70,    71,    72,    73,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    62,    -1,    -1,    -1,    -1,    -1,    68,    69,
      70,    71,    72,    73,     0,    -1,    -1,     3,    -1,    -1,
      -1,    -1,    -1,    62,    -1,    -1,    -1,    -1,    -1,    68,
      69,    70,    71,    72,    73,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,     3,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    -1,    -1,    -1,    62,    -1,    -1,    -1,
      -1,    -1,    -1,    69,    -1,    -1,    -1,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,     3,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    62,    63,    64,    -1,    -1,    -1,    82,    69,    -1,
      -1,    -1,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,     3,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    62,    -1,    -1,    -1,
      -1,    -1,    -1,    69,    -1,    -1,    -1,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    28,    -1,    -1,
      -1,    -1,    63,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    28,    -1,    -1,
      -1,    -1,    -1,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    28,
      -1,    -1,    -1,    -1,    85,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    -1,
      -1,    -1,    -1,    -1,    85,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    82,
      -1,    84,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    84,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    62,    63,    64,    -1,
      -1,    -1,    -1,    69,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    63,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    62,    69,   110,   111,   114,   115,   116,   117,
     123,   126,   127,   128,   129,   154,   155,   156,     3,    84,
     127,   126,   129,   130,    83,   112,   113,   127,   111,   111,
       3,    84,   111,   110,   111,   146,   158,    62,    64,   128,
       0,   155,    84,     3,   124,   125,    63,   126,   129,    67,
      83,    82,   146,   157,    84,   115,   118,   119,   120,   126,
     127,    84,   110,   145,   145,     3,    63,   111,   131,   132,
     133,   134,     3,     4,     5,     6,     8,     9,    62,    65,
      68,    69,    70,    71,    72,    73,    87,    88,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   104,   109,   124,    82,    67,    85,   113,    84,    90,
     104,   106,   138,   145,   145,   118,   120,    85,   119,    81,
     121,   122,   127,   120,     3,    49,    50,    51,    53,    54,
      55,    56,    57,    58,    59,    60,    83,    85,   106,   108,
     140,   141,   144,   146,   147,   148,   150,   152,   153,    62,
      64,   127,   129,   136,   137,    63,    67,    63,    67,    62,
      90,    62,    90,    90,   108,   120,   135,     7,     8,     9,
      62,    64,    66,    92,    69,    74,    75,    70,    71,    10,
      11,    12,    13,    76,    77,    14,    15,    68,    78,    79,
      16,    17,    80,    65,    85,   109,   125,   138,   139,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    82,
     107,    85,   109,    67,    83,    81,    81,   109,    81,    62,
      62,   143,   143,    62,     3,    83,    83,    83,   108,    67,
      83,   142,    85,   147,    85,   143,    63,   131,   136,    65,
     109,   137,    62,    64,    48,   133,     3,   135,    63,    62,
     129,   136,    63,     3,    63,    89,   106,   108,     3,    92,
      92,    92,    93,    93,    94,    94,    95,    95,    95,    95,
      96,    96,    97,    98,    99,   143,   143,   143,    67,    85,
     106,   122,   109,   143,    81,   143,   108,   149,   108,    62,
     141,   148,    83,    83,   106,   145,    85,   141,    63,    63,
      65,    63,   131,    65,   109,    63,    92,    63,    67,    65,
     100,   101,   108,    85,   138,   141,   143,   141,    63,    63,
     149,    54,   143,    63,    65,   106,    81,   141,   143,   103,
      63,   143,   148,   151,   105,   141,   141,   143,    62,   143,
     103,    52,   141,   149,    63,   108,   143,   103,    63,   141,
      63,   104,   143,    83,   103,   141,   143,   141
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
      yyerror (YY_("syntax error: cannot back up")); \
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
		  Type, Value); \
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
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
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
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
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
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
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
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
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
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

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
int yyparse (void);
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
yyparse (void)
#else
int
yyparse ()

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
        case 2:
#line 134 "ansic.y"
    {
								string *name = new string((yyvsp[(1) - (1)].token.name));
								symrec *s = getsym(name);
								if(s == NULL)
								{
									printf("Variable: %s", (yyvsp[(1) - (1)].token.name));
									yyerror("Not declared");
								}
								(yyval.sym).var = s; 		/*La variavle de la tabla de simbolos que se encontro con getsym()*/
								(yyval.sym).typ = s->typ; 	/*El tipo se obtuvo de la tabla de simbolos*/
								(yyval.sym).dimlist = s->dimlist;
								(yyval.sym).plevel = 0;
								printf("primary_expression: IDENTIFIER\n");
								cout << "<" << *name << ">\n";
							;}
    break;

  case 3:
#line 149 "ansic.y"
    {	printf("primary_expression : CONSTANT\n");
								symrec *s;
								std::string *name;
								switch((yyvsp[(1) - (1)].token.type))
								{
									case INTVAL:
										name = newtemp();	/*crear una variable temporal*/
										s = putsym(name, INTVAL | CONST_SPEC);
										(yyval.sym).val.intval = (yyvsp[(1) - (1)].token.ival);
										*(int *)(datablock+s->offset) = (yyvsp[(1) - (1)].token.ival);
										(yyval.sym).typ = s->typ;
										(yyval.sym).var = s;
										break;
									case DOUBLEVAL:
										name = newtemp();	/*crear una variable temporal*/
										s = putsym(name, DOUBLEVAL | CONST_SPEC);
										(yyval.sym).val.doubleval = (yyvsp[(1) - (1)].token.dval);
										*(double *)(datablock+s->offset) = (yyvsp[(1) - (1)].token.dval);
										(yyval.sym).typ = s->typ;
										(yyval.sym).var = s;
										break;
									case CHARVAL:
										name = newtemp();	/*crear una variable temporal*/
										s = putsym(name, CHARVAL | CONST_SPEC);
										(yyval.sym).val.charval = (yyvsp[(1) - (1)].token.cval);
										*(char *)(datablock+s->offset) = (yyvsp[(1) - (1)].token.cval);
										(yyval.sym).typ = s->typ;
										(yyval.sym).var = s;
										break;
								}
							;}
    break;

  case 4:
#line 180 "ansic.y"
    {	
								
								symrec *s;
								std::string *name;
								string *str = new string((yyvsp[(1) - (1)].token.str));
								printf("primary_expression: STRING_LITERAL\n");
								cout << "<\"" << *str << "\">\n";
								/*Crear variable temporal para guardar cadena*/
								name = newtemp();
								/*Agregar variable temporal a tabla de simbolos*/
								s = putsym(name, STRVAL | CONST_SPEC);
								/*Determinar tamano de cadena*/
								s->size = strlen((yyvsp[(1) - (1)].token.str))+1;
								/*Copiar cadena a bloque de datos datablock*/
								memcpy(datablock+s->offset, (yyvsp[(1) - (1)].token.str), s->size);
								/*Incrementar valor de posicion libre en bloque de datos*/
								data_location(s->size);
								/*Propagar atributos de variable temporal al nodo padre primary_expression*/
								(yyval.sym).name =name;
								(yyval.sym).typ = s->typ;
								(yyval.sym).var = s;
							;}
    break;

  case 5:
#line 202 "ansic.y"
    {
								printf("primary_expression: '(' expression ')'\n");
								(yyval.sym) = (yyvsp[(2) - (3)].sym);
							;}
    break;

  case 6:
#line 209 "ansic.y"
    {
																printf("postfix_expression: primary_expression\n");
																(yyval.sym) = (yyvsp[(1) - (1)].sym);
															;}
    break;

  case 7:
#line 213 "ansic.y"
    {
																printf("postfix_expression: postfix_expression '[' expression ']'	\n");
																(yyval.sym) = (yyvsp[(1) - (4)].sym);
																if((yyvsp[(1) - (4)].sym).var == NULL)
																{
																	yyerror("Error: Array name must be specified\n");
																}
																if(!isintegral((yyvsp[(3) - (4)].sym).typ))
																{
																	yyerror("Array subscript must be integral\n");
																}
																if((yyvsp[(1) - (4)].sym).plevel > 0)
																{
																	string *name = newtemp();
																	symrec *s0 = putsym(name, INTVAL | CONST_SPEC);
																	*(int *)(datablock+s0->offset) = getsizeof((yyval.sym).typ);
																	name = newtemp();
																	symrec *s1 = putsym(name, INTVAL | CONST_SPEC);
																	*(int *)(datablock+s1->offset) = getrdim((yyval.sym).dimlist, (yyvsp[(1) - (4)].sym).plevel - 1);
																	name = newtemp();
																	symrec *s2 = putsym(name, INTVAL | VAR_SPEC);
																	gencode(MULT_IR, (yyvsp[(3) - (4)].sym).var, s0, s2);
																	name = newtemp();
																	symrec *s3 = putsym(name, INTVAL | VAR_SPEC);
																	gencode(MULT_IR, (yyval.sym).var2, s1, s3);
																	name = newtemp();
																	symrec *s4 = putsym(name, INTVAL | VAR_SPEC);
																	gencode(ADD_IR, s3, s2, s4);
																	(yyval.sym).var2 = s4;
																}
																else
																{
																	string *name = newtemp();
																	symrec *s1 = putsym(name, INTVAL | CONST_SPEC);
																	*(int *)(datablock+s1->offset) = getsizeof((yyval.sym).typ);
																	name = newtemp();
																	symrec *s2 = putsym(name, INTVAL | VAR_SPEC);
																	gencode(MULT_IR, (yyvsp[(3) - (4)].sym).var, s1, s2);
																	(yyval.sym).var2 = s2;
																}
																(yyval.sym).typ |= ARRAY_SPEC;
																(yyval.sym).plevel++;
															;}
    break;

  case 8:
#line 256 "ansic.y"
    {
																symrec *s;
																std::string *name = newtemp();
																printf("postfix_expression: postfix_expression '(' ')'\n");
																s = putsym(name, (yyvsp[(1) - (3)].sym).typ & 0x1F);
																(yyval.sym).typ = s->typ;
																gencode(CALL_IR, (yyvsp[(1) - (3)].sym).var, nullptr, s);
																(yyval.sym).var = s;
															;}
    break;

  case 9:
#line 265 "ansic.y"
    {
																printf("postfix_expression: postfix_expression '(' argument_expression_list ')'\n");
																symrec *s, *s2, *s3;
																std::list<VAR_DATA *>::reverse_iterator it;
																std::string *name = newtemp();
																s = putsym(name, (yyvsp[(1) - (4)].sym).typ & 0x1F);
																(yyval.sym).typ = s->typ;
																for(it = (yyvsp[(3) - (4)].sym).arglist->rbegin(); it != (yyvsp[(3) - (4)].sym).arglist->rend(); it++)
																{
																	gencode(PARAM_IR, (*it)->var, nullptr, nullptr);
																}
																s3 = new symrec();
																s3->name = "";
																s3->offset = (yyvsp[(3) - (4)].sym).arglist->size();
																gencode(CALL_IR, (yyvsp[(1) - (4)].sym).var, s3, s);
																(yyval.sym).var = s;
															;}
    break;

  case 10:
#line 282 "ansic.y"
    {printf("postfix_expression: postfix_expression '.' IDENTIFIER\n");;}
    break;

  case 11:
#line 283 "ansic.y"
    {printf("postfix_expression: postfix_expression PTR_OP IDENTIFIER\n");;}
    break;

  case 12:
#line 284 "ansic.y"
    {
																printf("postfix_expression: postfix_expression INC_OP	\n");
																if((yyvsp[(1) - (2)].sym).typ & VAR_SPEC)
																{
																	/*Crear variable temporal para guardar valor de postfix_expression antes de incremento*/
																	std::string *name = newtemp();
																	symrec *s;
																	/*Agregar variable temporal a tabla de simbolos*/
																	s = putsym(name, (yyvsp[(1) - (2)].sym).typ);
																	/*Generar instruccion de codigo intermedio para asignacion*/
																	gencode(STORE_IR, (yyvsp[(1) - (2)].sym).var, nullptr, s);
																	gencode(INC_IR, (yyvsp[(1) - (2)].sym).var, nullptr, (yyvsp[(1) - (2)].sym).var);
																	(yyval.sym).name = name;
																	(yyval.sym).typ = (yyvsp[(1) - (2)].sym).typ;
																	(yyval.sym).var = s;
																}
																else
																{
																	yyerror("Error : Operand of increment operator must be an variable name\n");
																}
															;}
    break;

  case 13:
#line 305 "ansic.y"
    {
																printf("postfix_expression: postfix_expression DEC_OP\n");
																if((yyvsp[(1) - (2)].sym).typ & VAR_SPEC)
																{
																	/*Crear variable temporal para guardar valor de postfix_expression antes de incremento*/
																	std::string *name = newtemp();
																	symrec *s;
																	/*Agregar variable temporal a tabla de simbolos*/
																	s = putsym(name, (yyvsp[(1) - (2)].sym).typ);
																	/*Generar instruccion de codigo intermedio para asignacion*/
																	gencode(STORE_IR, (yyvsp[(1) - (2)].sym).var, nullptr, s);
																	gencode(DEC_IR, (yyvsp[(1) - (2)].sym).var, nullptr, (yyvsp[(1) - (2)].sym).var);
																	(yyval.sym).name = name;
																	(yyval.sym).typ = (yyvsp[(1) - (2)].sym).typ;
																	(yyval.sym).var = s;
																}
																else
																	yyerror("Error : Operand of decrement operator must be an variable name\n");
															;}
    break;

  case 14:
#line 327 "ansic.y"
    {	
																printf("argument_expression_list: assignment_expression\n");
																std::list<VAR_DATA *> *newlist = new std::list<VAR_DATA *>();
																VAR_DATA *newstruc = new VAR_DATA();
																*newstruc = (yyvsp[(1) - (1)].sym);
																newlist->push_back(newstruc);
																(yyval.sym).name = new std::string();
																(yyval.sym).typ = 0;
																(yyval.sym).arglist = newlist;
															;}
    break;

  case 15:
#line 337 "ansic.y"
    {
																printf("argument_expression_list: argument_expression_list ',' assignment_expression\n");
																VAR_DATA *newstruc = new VAR_DATA();
																*newstruc = (yyvsp[(3) - (3)].sym);
																(yyval.sym) = (yyvsp[(1) - (3)].sym);
																(yyval.sym).arglist->push_back(newstruc);
															;}
    break;

  case 16:
#line 347 "ansic.y"
    {
											(yyval.sym) = (yyvsp[(1) - (1)].sym);	
											printf("unary_expression: postfix_expression\n");
										;}
    break;

  case 17:
#line 351 "ansic.y"
    {
											printf("unary_expression: INC_OP unary_expression\n");
											if((yyvsp[(2) - (2)].sym).typ & VAR_SPEC)
											{
												/*Generar instruccion de codigo intermedio para incremento*/
												gencode(INC_IR, (yyvsp[(2) - (2)].sym).var, nullptr, (yyvsp[(2) - (2)].sym).var);
												/*Propagar atributos de variable temporal al nodo padre postfix_expression*/
												(yyval.sym).name = (yyvsp[(2) - (2)].sym).name;
												(yyval.sym).typ = (yyvsp[(2) - (2)].sym).typ;
												(yyval.sym).var = (yyvsp[(2) - (2)].sym).var;
											}
											else
												yyerror("Error : Operand of increment operator must be an variable name\n");;}
    break;

  case 18:
#line 364 "ansic.y"
    {
											printf("unary_expression: DEC_OP unary_expression\n");
											if((yyvsp[(2) - (2)].sym).typ & VAR_SPEC)
											{
												/*Generar instruccion de codigo intermedio para incremento*/
												gencode(DEC_IR, (yyvsp[(2) - (2)].sym).var, nullptr, (yyvsp[(2) - (2)].sym).var);
												/*Propagar atributos de variable temporal al nodo padre postfix_expression*/
												(yyval.sym).name = (yyvsp[(2) - (2)].sym).name;
												(yyval.sym).typ = (yyvsp[(2) - (2)].sym).typ;
												(yyval.sym).var = (yyvsp[(2) - (2)].sym).var;
											}
											else
												yyerror("Error : Operand of decrement operator must be an variable name\n");
										;}
    break;

  case 19:
#line 378 "ansic.y"
    {
											printf("unary_expression: unary_operator cast_expression\n");
											std::string *name;
											symrec *s;
											if((yyvsp[(1) - (2)].op) == PLUS_OP)
											{
												(yyval.sym) = (yyvsp[(2) - (2)].sym);
											}			
											name = newtemp();
											/*Generar instruccion de codigo intermedio*/
											switch((yyvsp[(1) - (2)].op))
											{
												case ADDR_OP:
													s = putsym(name, INTVAL);
													gencode(ADDRESS_IR, (yyvsp[(2) - (2)].sym).var, nullptr, s);
													(yyval.sym).typ = INTVAL;
													break;
												case DEREF_OP:
													if(!ispointer((yyvsp[(2) - (2)].sym).typ))
														yyerror("Error: Operand must be a ponter!\n");
													s = putsym(name, (yyvsp[(2) - (2)].sym).typ & ~POINTER_SPEC);
													gencode(DEREF_IR, (yyvsp[(2) - (2)].sym).var, nullptr, s);
													(yyval.sym).typ = (yyvsp[(2) - (2)].sym).typ;
													break;
												case MINUS_OP:
													s = putsym(name, (yyvsp[(2) - (2)].sym).typ);
													gencode(MINUS_IR, (yyvsp[(2) - (2)].sym).var, nullptr, s);
													(yyval.sym).typ = (yyvsp[(2) - (2)].sym).typ;
													break;
												case TWOCOMP_OP:
													s = putsym(name, INTVAL);
													gencode(TWOCOMP_IR, (yyvsp[(2) - (2)].sym).var, nullptr, s);
													(yyval.sym).typ = INTVAL;
													break;
												case NOT_OP:
													s = putsym(name, INTVAL);
													gencode(NOT_IR, (yyvsp[(2) - (2)].sym).var, nullptr, s);
													(yyval.sym).truelist = (yyvsp[(2) - (2)].sym).falselist;
													(yyval.sym).falselist = (yyvsp[(2) - (2)].sym).truelist;
													(yyval.sym).typ = INTVAL;
												break;
											}
											(yyval.sym).name = name;
											(yyval.sym).var = s;
										;}
    break;

  case 20:
#line 423 "ansic.y"
    {
											printf("unary_expression : SIZEOF unary_expression\n");
											/*Crear variable temporal para guardar valor tamano de unary_expression*/
											std::string *name = newtemp();
											symrec *s;
											/*Agregar variable temporal a tabla de simbolos*/
											s = putsym(name, INTVAL | CONST_SPEC);
											/*Copiar tamano de unary_expression en bloque de datos datablock*/
											*(int *)(datablock+s->offset) = getsizeof((yyvsp[(2) - (2)].sym).typ);
											/*Propagar atributos de postfix_expression al nodo padre unary_expression*/
											(yyval.sym).name = name;
											(yyval.sym).typ = INTVAL | CONST_SPEC;
											(yyval.sym).var = s;;}
    break;

  case 21:
#line 436 "ansic.y"
    {
											printf("unary_expression : SIZEOF '(' type_name ')'\n");
											/*Crear variable temporal para guardar valor tamano de unary_expression*/
											std::string *name = newtemp();
											symrec *s;
											/*Agregar variable temporal a tabla de simbolos*/
											s = putsym(name, INTVAL | CONST_SPEC);
											/*Copiar tamano de unary_expression en bloque de datos datablock*/
											*(int *)(datablock+s->offset) = getsizeof((yyvsp[(3) - (4)].typ));
											/*Propagar atributos de postfix_expression al nodo padre unary_expression*/
											(yyval.sym).name = name;
											(yyval.sym).typ = INTVAL | CONST_SPEC;
											(yyval.sym).var = s;
										;}
    break;

  case 22:
#line 453 "ansic.y"
    {
				printf("unary_operator: '&'\n");
				(yyval.op) = ADDR_OP;
			;}
    break;

  case 23:
#line 457 "ansic.y"
    {
				printf("unary_operator: '*'\n");
				(yyval.op) = DEREF_OP;
			;}
    break;

  case 24:
#line 461 "ansic.y"
    {
				printf("unary_operator: '+'\n");
				(yyval.op) = PLUS_OP;
			;}
    break;

  case 25:
#line 465 "ansic.y"
    {
				printf("unary_operator: '-'\n");
				(yyval.op) = MINUS_OP;
			;}
    break;

  case 26:
#line 469 "ansic.y"
    {
				printf("unary_operator: '~'\n");
				(yyval.op) = TWOCOMP_OP;
			;}
    break;

  case 27:
#line 473 "ansic.y"
    {
				printf("unary_operator: '!'\n");
				(yyval.op) = NOT_OP;
			;}
    break;

  case 28:
#line 480 "ansic.y"
    {
												(yyval.sym) = (yyvsp[(1) - (1)].sym);
												printf("cast_expression: unary_expression\n");
												if(isarray((yyvsp[(1) - (1)].sym).typ))
												{
													string *name = newtemp();
													symrec *s = putsym(name, (yyvsp[(1) - (1)].sym).typ & ~ARRAY_SPEC);
													gencode(LOADA_IR, (yyvsp[(1) - (1)].sym).var, (yyvsp[(1) - (1)].sym).var2, s);
													(yyval.sym).name = name;
													(yyval.sym).typ = s->typ;
													(yyval.sym).var = s;
												}
											;}
    break;

  case 29:
#line 493 "ansic.y"
    {
												printf("cast_expression: '(' type_name ')' cast_expression\n");
												std::string *name = newtemp();
												symrec *s;
												int typ = (yyvsp[(2) - (4)].typ) & 0x1F;
												switch(typ)
												{
													case CHARVAL:
														s = putsym(name, CHARVAL | VAR_SPEC);
														gencode(CHAR_IR, (yyvsp[(4) - (4)].sym).var, NULL, s);
														break;
													case INTVAL:
														s = putsym(name, INTVAL | VAR_SPEC);
														gencode(INT_IR, (yyvsp[(4) - (4)].sym).var, NULL, s);
														break;
													case FVAL:
														s = putsym(name, FVAL | VAR_SPEC);
														gencode(FLOAT_IR, (yyvsp[(4) - (4)].sym).var, NULL, s);
														break;
													case DOUBLEVAL:
														s = putsym(name, DOUBLEVAL | VAR_SPEC);
														gencode(DOUBLE_IR, (yyvsp[(4) - (4)].sym).var, NULL, s);
														break;
												}
												(yyval.sym).name = name;
												(yyval.sym).typ = s->typ;
												(yyval.sym).var = s;
											;}
    break;

  case 30:
#line 524 "ansic.y"
    {
															(yyval.sym) = (yyvsp[(1) - (1)].sym);
															printf("multiplicative_expression: cast_expression\n");
														;}
    break;

  case 31:
#line 528 "ansic.y"
    {
															printf("multiplicative_expression: multiplicative_expression '*' cast_expression\n");
															std::string *name = newtemp(); /*Crear nueva variable temporal para resultado*/
															symrec *s;
															s = putsym(name, gettype((yyvsp[(1) - (3)].sym).typ, (yyvsp[(3) - (3)].sym).typ) & (~CONST_SPEC | VAR_SPEC));
															gencode(MULT_IR, (yyvsp[(1) - (3)].sym).var, (yyvsp[(3) - (3)].sym).var, s);
															(yyval.sym).name = name;
															(yyval.sym).var = s;;}
    break;

  case 32:
#line 536 "ansic.y"
    {
															printf("multiplicative_expression: multiplicative_expression '/' cast_expression\n");
															std::string *name = newtemp(); /*Crear nueva variable temporal para resultado*/
															symrec *s;
															s = putsym(name, gettype((yyvsp[(1) - (3)].sym).typ, (yyvsp[(3) - (3)].sym).typ) & (~CONST_SPEC | VAR_SPEC));
															gencode(DIV_IR, (yyvsp[(1) - (3)].sym).var, (yyvsp[(3) - (3)].sym).var, s);
															(yyval.sym).name = name;
															(yyval.sym).var = s;
														;}
    break;

  case 33:
#line 545 "ansic.y"
    {
															printf("multiplicative_expression: multiplicative_expression '%%' cast_expression\n");
															std::string *name = newtemp(); /*Crear nueva variable temporal para resultado*/
															symrec *s;
															s = putsym(name, gettype((yyvsp[(1) - (3)].sym).typ, (yyvsp[(3) - (3)].sym).typ) & (~CONST_SPEC | VAR_SPEC));
															gencode(MOD_IR, (yyvsp[(1) - (3)].sym).var, (yyvsp[(3) - (3)].sym).var, s);
															(yyval.sym).name = name;
															(yyval.sym).var = s;;}
    break;

  case 34:
#line 556 "ansic.y"
    {
																(yyval.sym) = (yyvsp[(1) - (1)].sym);
																printf("additive_expression: multiplicative_expression	\n");
															;}
    break;

  case 35:
#line 560 "ansic.y"
    {
																printf("additive_expression: additive_expression '+' multiplicative_expression\n");
																std::string *name = newtemp(); /*Crear nueva variable temporal para resultado*/
																symrec *s;
																s = putsym(name, gettype((yyvsp[(1) - (3)].sym).typ, (yyvsp[(3) - (3)].sym).typ) & (~CONST_SPEC | VAR_SPEC));
																gencode(ADD_IR, (yyvsp[(1) - (3)].sym).var, (yyvsp[(3) - (3)].sym).var, s);
																(yyval.sym).name = name;
																(yyval.sym).var = s;
															;}
    break;

  case 36:
#line 569 "ansic.y"
    {
																printf("additive_expression: additive_expression '-' multiplicative_expression\n");
																std::string *name = newtemp(); /*Crear nueva variable temporal para resultado*/
																symrec *s;
																s = putsym(name, gettype((yyvsp[(1) - (3)].sym).typ, (yyvsp[(3) - (3)].sym).typ) & (~CONST_SPEC | VAR_SPEC));
																gencode(SUB_IR, (yyvsp[(1) - (3)].sym).var, (yyvsp[(3) - (3)].sym).var, s);
																(yyval.sym).name = name;
																(yyval.sym).var = s;
															;}
    break;

  case 37:
#line 581 "ansic.y"
    {
															(yyval.sym) = (yyvsp[(1) - (1)].sym);
															printf("shift_expression: additive_expression\n");
														;}
    break;

  case 38:
#line 585 "ansic.y"
    {printf("shift_expression: shift_expression LEFT_OP additive_expression\n");;}
    break;

  case 39:
#line 586 "ansic.y"
    {printf("shift_expression: shift_expression RIGHT_OP additive_expression\n");;}
    break;

  case 40:
#line 590 "ansic.y"
    {
															(yyval.sym) = (yyvsp[(1) - (1)].sym);
															printf("relational_expression: shift_expression\n");
														;}
    break;

  case 41:
#line 594 "ansic.y"
    {
															printf("relational_expression: relational_expression '<' shift_expression\n");
															symrec *s1 = (yyvsp[(1) - (3)].sym).var, *s2 = (yyvsp[(3) - (3)].sym).var;
															(yyval.sym).truelist = makelist(nextinstr);
															gencode(IF_LT_IR, s1, s2, nullptr);
															(yyval.sym).falselist = makelist(nextinstr);
															gencode(GOTO_IR);
														;}
    break;

  case 42:
#line 602 "ansic.y"
    {
															printf("relational_expression: relational_expression '>' shift_expression\n");
															symrec *s1 = (yyvsp[(1) - (3)].sym).var, *s2 = (yyvsp[(3) - (3)].sym).var;
															(yyval.sym).truelist = makelist(nextinstr);
															gencode(IF_GT_IR, s1, s2, nullptr);
															(yyval.sym).falselist = makelist(nextinstr);
															gencode(GOTO_IR);
														;}
    break;

  case 43:
#line 610 "ansic.y"
    {
															printf("relational_expression: relational_expression LE_OP shift_expression\n");
															symrec *s1 = (yyvsp[(1) - (3)].sym).var, *s2 = (yyvsp[(3) - (3)].sym).var;
															(yyval.sym).truelist = makelist(nextinstr);
															gencode(IF_LE_IR, s1, s2, nullptr);
															(yyval.sym).falselist = makelist(nextinstr);
															gencode(GOTO_IR);
														;}
    break;

  case 44:
#line 618 "ansic.y"
    {
															printf("relational_expression: relational_expression GE_OP shift_expression\n");
															symrec *s1 = (yyvsp[(1) - (3)].sym).var, *s2 = (yyvsp[(3) - (3)].sym).var;
															(yyval.sym).truelist = makelist(nextinstr);
															gencode(IF_GE_IR, s1, s2, nullptr);
															(yyval.sym).falselist = makelist(nextinstr);
															gencode(GOTO_IR);
														;}
    break;

  case 45:
#line 629 "ansic.y"
    {
															(yyval.sym) = (yyvsp[(1) - (1)].sym);
															printf("equality_expression: relational_expression	\n");
														;}
    break;

  case 46:
#line 633 "ansic.y"
    {
															printf("equality_expression: equality_expression EQ_OP relational_expression\n");
															symrec *s1 = (yyvsp[(1) - (3)].sym).var, *s2 = (yyvsp[(3) - (3)].sym).var;
															(yyval.sym).truelist = makelist(nextinstr);
															gencode(IF_EQ_IR, s1, s2, nullptr);
															(yyval.sym).falselist = makelist(nextinstr);
															gencode(GOTO_IR);
														;}
    break;

  case 47:
#line 641 "ansic.y"
    {
															printf("equality_expression: equality_expression NE_OP relational_expression\n");
															symrec *s1 = (yyvsp[(1) - (3)].sym).var, *s2 = (yyvsp[(3) - (3)].sym).var;
															(yyval.sym).truelist = makelist(nextinstr);
															gencode(IF_NE_IR, s1, s2, nullptr);
															(yyval.sym).falselist = makelist(nextinstr);
															gencode(GOTO_IR);
														;}
    break;

  case 48:
#line 652 "ansic.y"
    {
																	(yyval.sym) = (yyvsp[(1) - (1)].sym);
																	printf("and_expression: equality_expression\n");
																;}
    break;

  case 49:
#line 656 "ansic.y"
    {
																	printf("and_expression: and_expression '&' equality_expression\n");
																	std::string *name = newtemp();
																	symrec *s;
																	s = putsym(name, gettype((yyvsp[(1) - (3)].sym).typ, (yyvsp[(3) - (3)].sym).typ) &  (~CONST_SPEC | VAR_SPEC));
																	gencode(AND_IR, (yyvsp[(1) - (3)].sym).var, (yyvsp[(3) - (3)].sym).var, s);
																	(yyval.sym).name = name;
																	(yyval.sym).var = s;
																;}
    break;

  case 50:
#line 668 "ansic.y"
    {
																	(yyval.sym) = (yyvsp[(1) - (1)].sym);
																	printf("exclusive_or_expression: and_expression\n");
																;}
    break;

  case 51:
#line 672 "ansic.y"
    {
																	printf("exclusive_or_expression: exclusive_or_expression '^' and_expression\n");
																	std::string *name = newtemp();
																	symrec *s;
																	s = putsym(name, gettype((yyvsp[(1) - (3)].sym).typ, (yyvsp[(3) - (3)].sym).typ) &  (~CONST_SPEC | VAR_SPEC));
																	gencode(XOR_IR, (yyvsp[(1) - (3)].sym).var, (yyvsp[(3) - (3)].sym).var, s);
																	(yyval.sym).name = name;
																	(yyval.sym).var = s;
																;}
    break;

  case 52:
#line 684 "ansic.y"
    {
																	(yyval.sym) = (yyvsp[(1) - (1)].sym);
																	printf("inclusive_or_expression: exclusive_or_expression\n");
																;}
    break;

  case 53:
#line 688 "ansic.y"
    {
																	printf("inclusive_or_expression: inclusive_or_expression '|' exclusive_or_expression\n");
																	std::string *name = newtemp();
																	symrec *s;
																	s = putsym(name, gettype((yyvsp[(1) - (3)].sym).typ, (yyvsp[(3) - (3)].sym).typ) &  (~CONST_SPEC | VAR_SPEC));
																	gencode(OR_IR, (yyvsp[(1) - (3)].sym).var, (yyvsp[(3) - (3)].sym).var, s);
																	(yyval.sym).name = name;
																	(yyval.sym).var = s;
																;}
    break;

  case 54:
#line 700 "ansic.y"
    {
																	(yyval.sym) = (yyvsp[(1) - (1)].sym);
																	printf("logical_and_expression: inclusive_or_expression\n");
																;}
    break;

  case 55:
#line 704 "ansic.y"
    {
																	printf("logical_and_expression: logical_and_expression AND_OP inclusive_or_expression\n");
																	backpatch((yyvsp[(1) - (4)].sym).truelist, (yyvsp[(3) - (4)].instr));
																	(yyval.sym).truelist = (yyvsp[(4) - (4)].sym).truelist;
																	(yyval.sym).falselist = (yyvsp[(1) - (4)].sym).falselist;
																	(yyval.sym).falselist->merge(*((yyvsp[(4) - (4)].sym).falselist));
																	(yyval.sym).typ = INTVAL;
																;}
    break;

  case 56:
#line 715 "ansic.y"
    {
																	(yyval.sym) = (yyvsp[(1) - (1)].sym);
																	printf("logical_or_expression: logical_and_expression\n");
																;}
    break;

  case 57:
#line 719 "ansic.y"
    {
																	printf("logical_or_expression: logical_or_expression OR_OP logical_and_expression\n");
																	backpatch((yyvsp[(1) - (4)].sym).falselist, (yyvsp[(3) - (4)].instr)); //El 3 es la N.
																	(yyval.sym).falselist = (yyvsp[(4) - (4)].sym).falselist;
																	(yyval.sym).truelist = (yyvsp[(1) - (4)].sym).truelist;
																	(yyval.sym).truelist->merge(*((yyvsp[(4) - (4)].sym).truelist));
																	(yyval.sym).typ = INTVAL;
																;}
    break;

  case 58:
#line 729 "ansic.y"
    {
					/*Agregar direccion de la siguiente intruccion de IR en atributo nextlist y generar instruccion de salto pendiente.*/
					(yyval.lists).nextlist = makelist(nextinstr);
					gencode(GOTO_IR);
				;}
    break;

  case 59:
#line 736 "ansic.y"
    {
																				(yyval.sym) = (yyvsp[(1) - (1)].sym);
																				printf("conditional_expression: logical_or_expression\n");
																			;}
    break;

  case 60:
#line 740 "ansic.y"
    {
																				string *name = newtemp();
																				symrec *s = putsym(name, (yyvsp[(4) - (5)].sym).typ & (~CONST_SPEC | VAR_SPEC));
																				gencode(STORE_IR, (yyvsp[(4) - (5)].sym).var, NULL, s);
																				(yyvsp[(4) - (5)].sym).var = s;
																			;}
    break;

  case 61:
#line 746 "ansic.y"
    {
																				//printf("conditional_expression: logical_or_expression '?' expression ':' conditional_expression\n");
																				gencode(STORE_IR, (yyvsp[(9) - (9)].sym).var, NULL, (yyvsp[(4) - (9)].sym).var);
																				(yyval.sym).var = (yyvsp[(4) - (9)].sym).var;
																				backpatch((yyvsp[(1) - (9)].sym).truelist, (yyvsp[(3) - (9)].instr));
																				backpatch((yyvsp[(1) - (9)].sym).falselist, (yyvsp[(8) - (9)].instr));
																				backpatch((yyvsp[(7) - (9)].lists).nextlist, nextinstr);
																				(yyval.sym).truelist = nullptr;
																				(yyval.sym).falselist = nullptr;
																			;}
    break;

  case 62:
#line 759 "ansic.y"
    {
																			(yyval.sym) = (yyvsp[(1) - (1)].sym);
																			printf("assignment_expression: conditional_expression\n");
																		;}
    break;

  case 63:
#line 763 "ansic.y"
    {
																			printf("assignment_expression: unary_expression assignment_operator assignment_expression\n");
																				/*Verifica si hat saltos pendientes en assignment_expression
																				Si los hay, asigna el valor logico 0 o 1*/
																			if((yyvsp[(3) - (3)].sym).truelist || (yyvsp[(3) - (3)].sym).falselist)
																			{
																				std::string *name = newtemp(); /*Nueva variable tempotal*/
																				symrec *s1, *s0;
																				s0 = putsym(name, INTVAL | CONST_SPEC);
																				*(int*)(datablock+s0->offset) = 0;
																				name = newtemp();
																				s1 = putsym(name, INTVAL | CONST_SPEC);
																				*(int*)(datablock+s1->offset) = 1;
																				name = newtemp();
																				(yyvsp[(3) - (3)].sym).var = putsym(name, INTVAL | VAR_SPEC);
																				(yyvsp[(3) - (3)].sym).typ = INTVAL | VAR_SPEC;
																				(yyvsp[(3) - (3)].sym).name = name;
																				backpatch((yyvsp[(3) - (3)].sym).truelist, nextinstr);
																				gencode(STORE_IR, s1, nullptr, (yyvsp[(3) - (3)].sym).var);
																				gencode(GOTO_IR, nullptr, nullptr, nextinstr+2);
																				backpatch((yyvsp[(3) - (3)].sym).falselist, nextinstr);
																				gencode(STORE_IR, s0, nullptr, (yyvsp[(3) - (3)].sym).var);
																			}
																			switch((yyvsp[(2) - (3)].asop))
																			{
																				case EQ_ASSIGN_OP:
																					if(!isarray((yyvsp[(1) - (3)].sym).typ))
																						gencode(STORE_IR, (yyvsp[(3) - (3)].sym).var, nullptr, (yyvsp[(1) - (3)].sym).var);
																					else
																						gencode(STOREA_IR, (yyvsp[(3) - (3)].sym).var, (yyvsp[(1) - (3)].sym).var2, (yyvsp[(1) - (3)].sym).var);
																					break;
																				case MUL_ASSIGN_OP:
																					if(!isarray((yyvsp[(1) - (3)].sym).typ))
																					{
																						std::string *name = newtemp(); /*Crear nueva variable temporal para resultado*/
																						symrec *s;
																						s = putsym(name, gettype((yyvsp[(1) - (3)].sym).typ, (yyvsp[(3) - (3)].sym).typ) & (~CONST_SPEC | VAR_SPEC));
																						gencode(MULT_IR, (yyvsp[(1) - (3)].sym).var, (yyvsp[(3) - (3)].sym).var, s);
																						gencode(STORE_IR, s, nullptr, (yyvsp[(1) - (3)].sym).var);
																					}
																					else
																					{
																						std::string *name = newtemp();
																						std::string *name1 = newtemp();
																						symrec *s, *result;
																						s = putsym(name, (yyvsp[(1) - (3)].sym).typ & (~ARRAY_SPEC | VAR_SPEC));
																						result = putsym(name1, gettype((yyvsp[(1) - (3)].sym).typ, (yyvsp[(3) - (3)].sym).typ) & (~ARRAY_SPEC | VAR_SPEC));
																						gencode(LOADA_IR, (yyvsp[(1) - (3)].sym).var, (yyvsp[(1) - (3)].sym).var2, s);
																						gencode(MULT_IR, s, (yyvsp[(3) - (3)].sym).var, result); 
																						gencode(STOREA_IR, result, (yyvsp[(1) - (3)].sym).var2, (yyvsp[(1) - (3)].sym).var);
																					}
																					break;
																				case DIV_ASSIGN_OP:
																					if(!isarray((yyvsp[(1) - (3)].sym).typ))
																					{
																						std::string *name = newtemp(); /*Crear nueva variable temporal para resultado*/
																						symrec *s;
																						s = putsym(name, gettype((yyvsp[(1) - (3)].sym).typ, (yyvsp[(3) - (3)].sym).typ) & (~CONST_SPEC | VAR_SPEC));
																						gencode(DIV_IR, (yyvsp[(1) - (3)].sym).var, (yyvsp[(3) - (3)].sym).var, s);
																						gencode(STORE_IR, s, nullptr, (yyvsp[(1) - (3)].sym).var);
																					}
																					else
																					{
																						std::string *name = newtemp();
																						std::string *name1 = newtemp();
																						symrec *s, *result;
																						s = putsym(name, (yyvsp[(1) - (3)].sym).typ & (~ARRAY_SPEC | VAR_SPEC));
																						result = putsym(name1, gettype((yyvsp[(1) - (3)].sym).typ, (yyvsp[(3) - (3)].sym).typ) & (~ARRAY_SPEC | VAR_SPEC));
																						gencode(LOADA_IR, (yyvsp[(1) - (3)].sym).var, (yyvsp[(1) - (3)].sym).var2, s);
																						gencode(DIV_IR, s, (yyvsp[(3) - (3)].sym).var, result); 
																						gencode(STOREA_IR, result, (yyvsp[(1) - (3)].sym).var2, (yyvsp[(1) - (3)].sym).var);
																					}
																					break;
																				case MOD_ASSIGN_OP:
																					if(!isarray((yyvsp[(1) - (3)].sym).typ))
																					{
																						std::string *name = newtemp(); /*Crear nueva variable temporal para resultado*/
																						symrec *s;
																						s = putsym(name, gettype((yyvsp[(1) - (3)].sym).typ, (yyvsp[(3) - (3)].sym).typ) & (~CONST_SPEC | VAR_SPEC));
																						gencode(MOD_IR, (yyvsp[(1) - (3)].sym).var, (yyvsp[(3) - (3)].sym).var, s);
																						gencode(STORE_IR, s, nullptr, (yyvsp[(1) - (3)].sym).var);
																					}
																					else
																					{
																						std::string *name = newtemp();
																						std::string *name1 = newtemp();
																						symrec *s, *result;
																						s = putsym(name, (yyvsp[(1) - (3)].sym).typ & (~ARRAY_SPEC | VAR_SPEC));
																						result = putsym(name1, gettype((yyvsp[(1) - (3)].sym).typ, (yyvsp[(3) - (3)].sym).typ) & (~ARRAY_SPEC | VAR_SPEC));
																						gencode(LOADA_IR, (yyvsp[(1) - (3)].sym).var, (yyvsp[(1) - (3)].sym).var2, s);
																						gencode(MOD_IR, s, (yyvsp[(3) - (3)].sym).var, result); 
																						gencode(STOREA_IR, result, (yyvsp[(1) - (3)].sym).var2, (yyvsp[(1) - (3)].sym).var);
																					}
																					break;
																				case ADD_ASSIGN_OP:
																					if(!isarray((yyvsp[(1) - (3)].sym).typ))
																					{
																						std::string *name = newtemp(); /*Crear nueva variable temporal para resultado*/
																						symrec *s;
																						s = putsym(name, gettype((yyvsp[(1) - (3)].sym).typ, (yyvsp[(3) - (3)].sym).typ) & (~CONST_SPEC | VAR_SPEC));
																						gencode(ADD_IR, (yyvsp[(1) - (3)].sym).var, (yyvsp[(3) - (3)].sym).var, s);
																						gencode(STORE_IR, s, nullptr, (yyvsp[(1) - (3)].sym).var);
																					}
																					else
																					{
																						std::string *name = newtemp();
																						std::string *name1 = newtemp();
																						symrec *s, *result;
																						s = putsym(name, (yyvsp[(1) - (3)].sym).typ & (~ARRAY_SPEC | VAR_SPEC));
																						result = putsym(name1, gettype((yyvsp[(1) - (3)].sym).typ, (yyvsp[(3) - (3)].sym).typ) & (~ARRAY_SPEC | VAR_SPEC));
																						gencode(LOADA_IR, (yyvsp[(1) - (3)].sym).var, (yyvsp[(1) - (3)].sym).var2, s);
																						gencode(ADD_IR, s, (yyvsp[(3) - (3)].sym).var, result); 
																						gencode(STOREA_IR, result, (yyvsp[(1) - (3)].sym).var2, (yyvsp[(1) - (3)].sym).var);
																					}
																					break;
																				case SUB_ASSIGN_OP:
																					if(!isarray((yyvsp[(1) - (3)].sym).typ))
																					{
																						std::string *name = newtemp(); /*Crear nueva variable temporal para resultado*/
																						symrec *s;
																						s = putsym(name, gettype((yyvsp[(1) - (3)].sym).typ, (yyvsp[(3) - (3)].sym).typ) & (~CONST_SPEC | VAR_SPEC));
																						gencode(SUB_IR, (yyvsp[(1) - (3)].sym).var, (yyvsp[(3) - (3)].sym).var, s);
																						gencode(STORE_IR, s, nullptr, (yyvsp[(1) - (3)].sym).var);
																					}
																					else
																					{
																						std::string *name = newtemp();
																						std::string *name1 = newtemp();
																						symrec *s, *result;
																						s = putsym(name, (yyvsp[(1) - (3)].sym).typ & (~ARRAY_SPEC | VAR_SPEC));
																						result = putsym(name1, gettype((yyvsp[(1) - (3)].sym).typ, (yyvsp[(3) - (3)].sym).typ) & (~ARRAY_SPEC | VAR_SPEC));
																						gencode(LOADA_IR, (yyvsp[(1) - (3)].sym).var, (yyvsp[(1) - (3)].sym).var2, s);
																						gencode(SUB_IR, s, (yyvsp[(3) - (3)].sym).var, result); 
																						gencode(STOREA_IR, result, (yyvsp[(1) - (3)].sym).var2, (yyvsp[(1) - (3)].sym).var);
																					}
																					break;
																				case LEFT_ASSIGN_OP:
																					if(!isarray((yyvsp[(1) - (3)].sym).typ))
																					{
																						std::string *name = newtemp(); /*Crear nueva variable temporal para resultado*/
																						symrec *s;
																						s = putsym(name, gettype((yyvsp[(1) - (3)].sym).typ, (yyvsp[(3) - (3)].sym).typ) & (~CONST_SPEC | VAR_SPEC));
																						gencode(LSHIFT_IR, (yyvsp[(1) - (3)].sym).var, (yyvsp[(3) - (3)].sym).var, s);
																						gencode(STORE_IR, s, nullptr, (yyvsp[(1) - (3)].sym).var);
																					}
																					else
																					{
																						std::string *name = newtemp();
																						std::string *name1 = newtemp();
																						symrec *s, *result;
																						s = putsym(name, (yyvsp[(1) - (3)].sym).typ & (~ARRAY_SPEC | VAR_SPEC));
																						result = putsym(name1, gettype((yyvsp[(1) - (3)].sym).typ, (yyvsp[(3) - (3)].sym).typ) & (~ARRAY_SPEC | VAR_SPEC));
																						gencode(LOADA_IR, (yyvsp[(1) - (3)].sym).var, (yyvsp[(1) - (3)].sym).var2, s);
																						gencode(LSHIFT_IR, s, (yyvsp[(3) - (3)].sym).var, result); 
																						gencode(STOREA_IR, result, (yyvsp[(1) - (3)].sym).var2, (yyvsp[(1) - (3)].sym).var);
																					}
																					break;
																				case RIGHT_ASSIGN_OP:
																					if(!isarray((yyvsp[(1) - (3)].sym).typ))
																					{
																						std::string *name = newtemp(); /*Crear nueva variable temporal para resultado*/
																						symrec *s;
																						s = putsym(name, gettype((yyvsp[(1) - (3)].sym).typ, (yyvsp[(3) - (3)].sym).typ) & (~CONST_SPEC | VAR_SPEC));
																						gencode(RSHIFT_IR, (yyvsp[(1) - (3)].sym).var, (yyvsp[(3) - (3)].sym).var, s);
																						gencode(STORE_IR, s, nullptr, (yyvsp[(1) - (3)].sym).var);
																					}
																					else
																					{
																						std::string *name = newtemp();
																						std::string *name1 = newtemp();
																						symrec *s, *result;
																						s = putsym(name, (yyvsp[(1) - (3)].sym).typ & (~ARRAY_SPEC | VAR_SPEC));
																						result = putsym(name1, gettype((yyvsp[(1) - (3)].sym).typ, (yyvsp[(3) - (3)].sym).typ) & (~ARRAY_SPEC | VAR_SPEC));
																						gencode(LOADA_IR, (yyvsp[(1) - (3)].sym).var, (yyvsp[(1) - (3)].sym).var2, s);
																						gencode(RSHIFT_IR, s, (yyvsp[(3) - (3)].sym).var, result); 
																						gencode(STOREA_IR, result, (yyvsp[(1) - (3)].sym).var2, (yyvsp[(1) - (3)].sym).var);
																					}
																					break;
																				case AND_ASSIGN_OP:
																					if(!isarray((yyvsp[(1) - (3)].sym).typ))
																					{
																						std::string *name = newtemp(); /*Crear nueva variable temporal para resultado*/
																						symrec *s;
																						s = putsym(name, gettype((yyvsp[(1) - (3)].sym).typ, (yyvsp[(3) - (3)].sym).typ) & (~CONST_SPEC | VAR_SPEC));
																						gencode(AND_IR, (yyvsp[(1) - (3)].sym).var, (yyvsp[(3) - (3)].sym).var, s);
																						gencode(STORE_IR, s, nullptr, (yyvsp[(1) - (3)].sym).var);
																					}
																					else
																					{
																						std::string *name = newtemp();
																						std::string *name1 = newtemp();
																						symrec *s, *result;
																						s = putsym(name, (yyvsp[(1) - (3)].sym).typ & (~ARRAY_SPEC | VAR_SPEC));
																						result = putsym(name1, gettype((yyvsp[(1) - (3)].sym).typ, (yyvsp[(3) - (3)].sym).typ) & (~ARRAY_SPEC | VAR_SPEC));
																						gencode(LOADA_IR, (yyvsp[(1) - (3)].sym).var, (yyvsp[(1) - (3)].sym).var2, s);
																						gencode(AND_IR, s, (yyvsp[(3) - (3)].sym).var, result); 
																						gencode(STOREA_IR, result, (yyvsp[(1) - (3)].sym).var2, (yyvsp[(1) - (3)].sym).var);
																					}
																					break;
																				case XOR_ASSIGN_OP:
																					if(!isarray((yyvsp[(1) - (3)].sym).typ))
																					{
																						std::string *name = newtemp(); /*Crear nueva variable temporal para resultado*/
																						symrec *s;
																						s = putsym(name, gettype((yyvsp[(1) - (3)].sym).typ, (yyvsp[(3) - (3)].sym).typ) & (~CONST_SPEC | VAR_SPEC));
																						gencode(XOR_IR, (yyvsp[(1) - (3)].sym).var, (yyvsp[(3) - (3)].sym).var, s);
																						gencode(STORE_IR, s, nullptr, (yyvsp[(1) - (3)].sym).var);
																					}
																					else
																					{
																						std::string *name = newtemp();
																						std::string *name1 = newtemp();
																						symrec *s, *result;
																						s = putsym(name, (yyvsp[(1) - (3)].sym).typ & (~ARRAY_SPEC | VAR_SPEC));
																						result = putsym(name1, gettype((yyvsp[(1) - (3)].sym).typ, (yyvsp[(3) - (3)].sym).typ) & (~ARRAY_SPEC | VAR_SPEC));
																						gencode(LOADA_IR, (yyvsp[(1) - (3)].sym).var, (yyvsp[(1) - (3)].sym).var2, s);
																						gencode(XOR_IR, s, (yyvsp[(3) - (3)].sym).var, result); 
																						gencode(STOREA_IR, result, (yyvsp[(1) - (3)].sym).var2, (yyvsp[(1) - (3)].sym).var);
																					}
																					break;
																				case OR_ASSIGN_OP:
																					if(!isarray((yyvsp[(1) - (3)].sym).typ))
																					{
																						std::string *name = newtemp(); /*Crear nueva variable temporal para resultado*/
																						symrec *s;
																						s = putsym(name, gettype((yyvsp[(1) - (3)].sym).typ, (yyvsp[(3) - (3)].sym).typ) & (~CONST_SPEC | VAR_SPEC));
																						gencode(OR_IR, (yyvsp[(1) - (3)].sym).var, (yyvsp[(3) - (3)].sym).var, s);
																						gencode(STORE_IR, s, nullptr, (yyvsp[(1) - (3)].sym).var);
																					}
																					else
																					{
																						std::string *name = newtemp();
																						std::string *name1 = newtemp();
																						symrec *s, *result;
																						s = putsym(name, (yyvsp[(1) - (3)].sym).typ & (~ARRAY_SPEC | VAR_SPEC));
																						result = putsym(name1, gettype((yyvsp[(1) - (3)].sym).typ, (yyvsp[(3) - (3)].sym).typ) & (~ARRAY_SPEC | VAR_SPEC));
																						gencode(LOADA_IR, (yyvsp[(1) - (3)].sym).var, (yyvsp[(1) - (3)].sym).var2, s);
																						gencode(OR_IR, s, (yyvsp[(3) - (3)].sym).var, result); 
																						gencode(STOREA_IR, result, (yyvsp[(1) - (3)].sym).var2, (yyvsp[(1) - (3)].sym).var);
																					}
																					break;
																			}
																		;}
    break;

  case 64:
#line 1009 "ansic.y"
    {
						printf("assignment_operator: '='\n");
						(yyval.asop) = EQ_ASSIGN_OP;
					;}
    break;

  case 65:
#line 1013 "ansic.y"
    {
						printf("assignment_operator: MUL_ASSIGN\n");
						(yyval.asop) = MUL_ASSIGN_OP;
					;}
    break;

  case 66:
#line 1017 "ansic.y"
    {
						printf("assignment_operator: DIV_ASSIGN\n");
						(yyval.asop) = DIV_ASSIGN_OP;
					;}
    break;

  case 67:
#line 1021 "ansic.y"
    {
						printf("assignment_operator: MOD_ASSIGN\n");
						(yyval.asop) = MOD_ASSIGN_OP;
					;}
    break;

  case 68:
#line 1025 "ansic.y"
    {
						printf("assignment_operator: ADD_ASSIGN\n");
						(yyval.asop) = ADD_ASSIGN_OP;
					;}
    break;

  case 69:
#line 1029 "ansic.y"
    {
						printf("assignment_operator: SUB_ASSIGN\n");
						(yyval.asop) = SUB_ASSIGN_OP;
					;}
    break;

  case 70:
#line 1033 "ansic.y"
    {
						printf("assignment_operator: LEFT_ASSIGN\n");
						(yyval.asop) = LEFT_ASSIGN_OP;
					;}
    break;

  case 71:
#line 1037 "ansic.y"
    {
						printf("assignment_operator: RIGHT_ASSIGN\n");
						(yyval.asop) = RIGHT_ASSIGN_OP;
					;}
    break;

  case 72:
#line 1041 "ansic.y"
    {
						printf("assignment_operator: AND_ASSIGN\n");
						(yyval.asop) = AND_ASSIGN_OP;
					;}
    break;

  case 73:
#line 1045 "ansic.y"
    {
						printf("assignment_operator: XOR_ASSIGN\n");
						(yyval.asop) = XOR_ASSIGN_OP;
					;}
    break;

  case 74:
#line 1049 "ansic.y"
    {
						printf("assignment_operator: OR_ASSIGN\n");
						(yyval.asop) = OR_ASSIGN_OP;
					;}
    break;

  case 75:
#line 1056 "ansic.y"
    {
															(yyval.sym) = (yyvsp[(1) - (1)].sym);
															printf("expression: assignment_expression\n");
														;}
    break;

  case 76:
#line 1060 "ansic.y"
    {
															(yyval.sym) = (yyvsp[(1) - (3)].sym);
															printf("expression: expression ',' assignment_expression\n");
														;}
    break;

  case 77:
#line 1067 "ansic.y"
    {
															printf("constant_expression: conditional_expression\n");
															(yyval.sym) = (yyvsp[(1) - (1)].sym);
														;}
    break;

  case 78:
#line 1074 "ansic.y"
    {printf("declaration: declaration_specifiers ';'\n");;}
    break;

  case 79:
#line 1075 "ansic.y"
    {	
															int typ;
															printf("declaration: declaration_specifiers init_declarator_list ';'\n");
															typ = get_type((yyvsp[(1) - (3)].sqlist));
															std::list<VAR_DATA *>::iterator it;
															cout << "Declaring Variable: "<< endl;
															for(it = (yyvsp[(2) - (3)].idlist)->begin(); it != (yyvsp[(2) - (3)].idlist)->end(); it++)
															{
																symrec *s;
																cout << *(*it)->name <<endl;
																if(isarray((*it)->typ))
																{
																	installarray((*it)->name, typ | VAR_SPEC | ((*it)->typ & ~0x1F), (*it)->dimlist);
																}
																else
																{
																	if(isfunction((*it)->typ))
																		s = install((*it)->name, typ | FUNC_SPEC | ((*it)->typ & ~0x1F));
																	else
																		s = install((*it)->name, typ | VAR_SPEC | ((*it)->typ & ~0x1F));
																		if((*it)->init)
																		{
																			if(currscope > 0)	/*Verifica que sea variable local*/
																				gencode(STORE_IR, (*it)->var, nullptr, s);
																		}
																		else
																		{
																			initvar(s, (*it)->var);
																		}
																}
															}
														;}
    break;

  case 80:
#line 1110 "ansic.y"
    {
															list<int> *newlist = new list<int>;
															printf("declaration_specifiers: \n");
															newlist->push_back((yyvsp[(1) - (1)].scsp));
															(yyval.sqlist) = newlist;
														;}
    break;

  case 81:
#line 1116 "ansic.y"
    {
															printf("declaration_specifiers: \n");
															(yyval.sqlist) = (yyvsp[(2) - (2)].sqlist);
															(yyval.sqlist)->push_back((yyvsp[(1) - (2)].scsp));
														;}
    break;

  case 82:
#line 1121 "ansic.y"
    {
															list<int> *newlist = new list<int>;
															printf("declaration_specifiers: \n");
															newlist->push_back((yyvsp[(1) - (1)].typsp));
															(yyval.sqlist) = newlist;
														;}
    break;

  case 83:
#line 1127 "ansic.y"
    {
															printf("declaration_specifiers: \n");
															(yyval.sqlist) = (yyvsp[(2) - (2)].sqlist);
															(yyval.sqlist)->push_back((yyvsp[(1) - (2)].typsp));
														;}
    break;

  case 84:
#line 1132 "ansic.y"
    {
															list<int> *newlist = new list<int>;
															printf("declaration_specifiers: \n");
															newlist->push_back((yyvsp[(1) - (1)].qual));
															(yyval.sqlist) = newlist;
														;}
    break;

  case 85:
#line 1138 "ansic.y"
    {
															printf("declaration_specifiers: \n");
															(yyval.sqlist) = (yyvsp[(2) - (2)].sqlist);
															(yyval.sqlist)->push_back((yyvsp[(1) - (2)].qual));
														;}
    break;

  case 86:
#line 1146 "ansic.y"
    {
														std::list<VAR_DATA *> *newlist = new std::list<VAR_DATA *>;
														VAR_DATA *newstruc = (yyvsp[(1) - (1)].id_data);
														printf("init_declarator_list: init_declarator");
														newlist->push_back(newstruc);
														(yyval.idlist) = newlist;
													;}
    break;

  case 87:
#line 1153 "ansic.y"
    {
														printf("init_declarator_list: init_declarator_list ',' init_declarator");
														(yyvsp[(1) - (3)].idlist)->push_back((yyvsp[(3) - (3)].id_data));
														(yyval.idlist) = (yyvsp[(1) - (3)].idlist);
													;}
    break;

  case 88:
#line 1161 "ansic.y"
    {
										printf("init_declarator: declarator");
										(yyval.id_data) = (yyvsp[(1) - (1)].id_data);
									;}
    break;

  case 89:
#line 1165 "ansic.y"
    {
										printf("init_declarator: declarator '=' initializer");
										(yyval.id_data) = (yyvsp[(1) - (3)].id_data);
										(yyval.id_data)->init = 1;
										(yyval.id_data)->var = (yyvsp[(3) - (3)].sym).var;
									;}
    break;

  case 90:
#line 1174 "ansic.y"
    {
					printf("storage_class_specifier: TYPEDEF\n");
					(yyval.scsp) = TYPENAME_SPEC;
				;}
    break;

  case 91:
#line 1178 "ansic.y"
    {
					printf("storage_class_specifier: EXTERN\n");
					(yyval.scsp) = EXTERN_SPEC;
				;}
    break;

  case 92:
#line 1182 "ansic.y"
    {
					printf("storage_class_specifier: STATIC\n");
					(yyval.scsp) = STATIC_SPEC;
				;}
    break;

  case 93:
#line 1186 "ansic.y"
    {
					printf("storage_class_specifier: AUTO\n");
					(yyval.scsp) = AUTO_SPEC;
				;}
    break;

  case 94:
#line 1190 "ansic.y"
    {
					printf("storage_class_specifier: REGISTER\n");
					(yyval.scsp) = REGISTER_SPEC;
				;}
    break;

  case 95:
#line 1197 "ansic.y"
    {
										printf("type_specifier: VOID\n");
										(yyval.typsp) = VOID_SPEC;
									;}
    break;

  case 96:
#line 1201 "ansic.y"
    {
										printf("type_specifier: CHAR\n");
										(yyval.typsp) = CHAR_SPEC;
									;}
    break;

  case 97:
#line 1205 "ansic.y"
    {
										printf("type_specifier: SHORT\n");
										(yyval.typsp) = SHORT_SPEC;
									;}
    break;

  case 98:
#line 1209 "ansic.y"
    {
										printf("type_specifier: INT\n");
										(yyval.typsp) = INT_SPEC;
									;}
    break;

  case 99:
#line 1213 "ansic.y"
    {
										printf("type_specifier: LONG\n");
										(yyval.typsp) = LONG_SPEC;
									;}
    break;

  case 100:
#line 1217 "ansic.y"
    {
										printf("type_specifier: FLOAT\n");
										(yyval.typsp) = FLOAT_SPEC;
									;}
    break;

  case 101:
#line 1221 "ansic.y"
    {
										printf("type_specifier: DOUBLE\n");
										(yyval.typsp) = DOUBLE_SPEC;
									;}
    break;

  case 102:
#line 1225 "ansic.y"
    {
										printf("type_specifier: SIGNED\n");
										(yyval.typsp) = SIGNED_SPEC;
									;}
    break;

  case 103:
#line 1229 "ansic.y"
    {
										printf("type_specifier: UNSIGNED\n");
										(yyval.typsp) = UNSIGNED_SPEC;
									;}
    break;

  case 104:
#line 1233 "ansic.y"
    {
										printf("type_specifier: struct_or_union_specifier\n");
									;}
    break;

  case 105:
#line 1236 "ansic.y"
    {
										printf("type_specifier: enum_specifier\n");
										(yyval.typsp) = ENUM_SPEC;
									;}
    break;

  case 106:
#line 1240 "ansic.y"
    {
										printf("type_specifier: TYPE_NAME\n");
										(yyval.typsp) = TYPENAME_SPEC;
									;}
    break;

  case 107:
#line 1247 "ansic.y"
    {printf("struct_or_union_specifier: \n");;}
    break;

  case 108:
#line 1248 "ansic.y"
    {printf("struct_or_union_specifier: \n");;}
    break;

  case 109:
#line 1249 "ansic.y"
    {printf("struct_or_union_specifier: \n");;}
    break;

  case 110:
#line 1253 "ansic.y"
    {printf("struct_or_union: STRUCT\n");;}
    break;

  case 111:
#line 1254 "ansic.y"
    {printf("struct_or_union: UNION\n");;}
    break;

  case 112:
#line 1258 "ansic.y"
    {printf("struct_declaration_list: struct_declaration\n");;}
    break;

  case 113:
#line 1259 "ansic.y"
    {printf("struct_declaration_list: struct_declaration_list struct_declaration\n");;}
    break;

  case 114:
#line 1263 "ansic.y"
    {printf("struct_declaration: specifier_qualifier_list struct_declarator_list ';'\n");;}
    break;

  case 115:
#line 1267 "ansic.y"
    {
																		printf("specifier_qualifier_list: type_specifier specifier_qualifier_list\n");
																		(yyval.sqlist) = (yyvsp[(2) - (2)].sqlist);
																		(yyval.sqlist)->push_back((yyvsp[(1) - (2)].typsp));
																	;}
    break;

  case 116:
#line 1272 "ansic.y"
    {
																		printf("specifier_qualifier_list: type_specifier\n");
																		std::list<int> *newlist = new std::list<int>;
																		newlist->push_back((yyvsp[(1) - (1)].typsp));
																		(yyval.sqlist) = newlist;
																	;}
    break;

  case 117:
#line 1278 "ansic.y"
    {
																		printf("specifier_qualifier_list: type_qualifier specifier_qualifier_list\n");
																		(yyval.sqlist) = (yyvsp[(2) - (2)].sqlist);
																		(yyval.sqlist)->push_back((yyvsp[(1) - (2)].qual));
																	;}
    break;

  case 118:
#line 1283 "ansic.y"
    {
																		printf("specifier_qualifier_list: type_qualifier\n");
																		std::list<int> *newlist = new std::list<int>;
																		newlist->push_back((yyvsp[(1) - (1)].qual));
																		(yyval.sqlist) = newlist;
																	;}
    break;

  case 119:
#line 1292 "ansic.y"
    {printf("struct_declarator_list: struct_declarator\n");;}
    break;

  case 120:
#line 1293 "ansic.y"
    {printf("struct_declarator_list: struct_declarator_list ',' struct_declarator\n");;}
    break;

  case 121:
#line 1297 "ansic.y"
    {printf("struct_declarator: declarator\n");;}
    break;

  case 122:
#line 1298 "ansic.y"
    {printf("struct_declarator: ':' constant_expression\n");;}
    break;

  case 123:
#line 1299 "ansic.y"
    {printf("struct_declarator: declarator ':' constant_expression\n");;}
    break;

  case 124:
#line 1303 "ansic.y"
    {printf("enum_specifier: ENUM '{' enumerator_list '}'\n");;}
    break;

  case 125:
#line 1304 "ansic.y"
    {printf("enum_specifier: ENUM IDENTIFIER '{' enumerator_list '}'\n");;}
    break;

  case 126:
#line 1305 "ansic.y"
    {printf("enum_specifier: ENUM IDENTIFIER\n");;}
    break;

  case 127:
#line 1309 "ansic.y"
    {printf("enumerator_list: enumerator\n");;}
    break;

  case 128:
#line 1310 "ansic.y"
    {printf("enumerator_list: enumerator_list ',' enumerator\n");;}
    break;

  case 129:
#line 1314 "ansic.y"
    {printf("enumerator: IDENTIFIER\n");;}
    break;

  case 130:
#line 1315 "ansic.y"
    {printf("enumerator: IDENTIFIER '=' constant_expression\n");;}
    break;

  case 131:
#line 1319 "ansic.y"
    {
						printf("type_qualifier: CONST\n");
						(yyval.qual) = CONST_SPEC;
					;}
    break;

  case 132:
#line 1323 "ansic.y"
    {
						printf("type_qualifier: VOLATILE\n");
						(yyval.qual) = VOLATILE_SPEC;
					;}
    break;

  case 133:
#line 1330 "ansic.y"
    {	printf("declarator: pointer direct_declarator\n");
										(yyval.id_data) = (yyvsp[(2) - (2)].id_data);
										(yyval.id_data)->plevel = (yyvsp[(1) - (2)].pstruc).level;
										(yyval.id_data)->typ |= POINTER_SPEC | (yyvsp[(1) - (2)].pstruc).typq;
									;}
    break;

  case 134:
#line 1335 "ansic.y"
    {
										printf("declarator: direct_declarator\n");
										(yyval.id_data) = (yyvsp[(1) - (1)].id_data);
										if(isarray((yyval.id_data)->typ))
										{
											//Arreglos sin dimensiones son punteros.
											if(allzero((yyval.id_data)->dimlist))
											{
												(yyval.id_data)->typ &= ~ARRAY_SPEC;
												(yyval.id_data)->typ |= POINTER_SPEC;
											}
										}
										/*else
										{
											if(product($$->dimlist)==0)	//Esta linea da error.
												yyerror("Array dimensions must be specified\n");
										}*/
									;}
    break;

  case 135:
#line 1356 "ansic.y"
    {
															string *name = new string((yyvsp[(1) - (1)].token.name));
															printf("direct_declarator: IDENTIFIER");
															cout << "<" << *name << ">\n";
															VAR_DATA *newsym = new VAR_DATA();
															newsym->name = new string((yyvsp[(1) - (1)].token.name));
															newsym->dimlist = nullptr;
															(yyval.id_data) = newsym;
														;}
    break;

  case 136:
#line 1365 "ansic.y"
    {printf("direct_declarator: '(' declarator ')'\n");;}
    break;

  case 137:
#line 1366 "ansic.y"
    {
															printf("direct_declarator: direct_declarator '[' constant_expression ']'\n");
															if(!isintegral((yyvsp[(3) - (4)].sym).typ))
																yyerror("Array dimensions must be integral");
															if(!isconstant((yyvsp[(3) - (4)].sym).typ))
																yyerror("Array dimensions must be constant");
															(yyval.id_data) = (yyvsp[(1) - (4)].id_data);
															if((yyval.id_data)->dimlist == nullptr)
																(yyval.id_data)->dimlist = new list<int >;
															(yyval.id_data)->dimlist->push_back((yyvsp[(3) - (4)].sym).val.intval);
															(yyval.id_data)->typ |= ARRAY_SPEC;
														;}
    break;

  case 138:
#line 1378 "ansic.y"
    {
															printf("direct_declarator: direct_declarator '[' ']'\n");
															(yyval.id_data) = (yyvsp[(1) - (3)].id_data);
															if((yyval.id_data)->dimlist == nullptr)
																(yyval.id_data)->dimlist->push_back(0);
															(yyval.id_data)->dimlist->push_back(0);
															(yyval.id_data)->typ |= ARRAY_SPEC;
														;}
    break;

  case 139:
#line 1386 "ansic.y"
    {
															printf("direct_declarator: direct_declarator '(' parameter_type_list ')'\n");
															(yyval.id_data) = (yyvsp[(1) - (4)].id_data);
															(yyval.id_data)->typ |= FUNC_SPEC;
															(yyval.id_data)->arglist = (yyvsp[(3) - (4)].idlist);
															(yyval.id_data)->init = 0;
														;}
    break;

  case 140:
#line 1393 "ansic.y"
    {printf("direct_declarator: direct_declarator '(' identifier_list ')'\n");;}
    break;

  case 141:
#line 1394 "ansic.y"
    {
															printf("direct_declarator: direct_declarator '(' ')'\n");
															(yyval.id_data) = (yyvsp[(1) - (3)].id_data);
															(yyval.id_data)->typ |= FUNC_SPEC;
														;}
    break;

  case 142:
#line 1402 "ansic.y"
    {
											printf("pointer: '*'\n");
											(yyval.pstruc).typq = 0;
											(yyval.pstruc).level = 1;
										;}
    break;

  case 143:
#line 1407 "ansic.y"
    {
											printf("pointer: '*' type_qualifier_list\n");
											(yyval.pstruc).typq = (yyvsp[(2) - (2)].qual);
											(yyval.pstruc).level = 1;
										;}
    break;

  case 144:
#line 1412 "ansic.y"
    {
											printf("pointer: '*' pointer\n");
											(yyval.pstruc).typq = (yyvsp[(2) - (2)].pstruc).typq;
											(yyval.pstruc).level = (yyvsp[(2) - (2)].pstruc).level+1;
										;}
    break;

  case 145:
#line 1417 "ansic.y"
    {
											printf("pointer: '*' type_qualifier_list pointer\n");
											(yyval.pstruc) = (yyvsp[(3) - (3)].pstruc);
											(yyval.pstruc).typq = (yyvsp[(2) - (3)].qual);
											(yyval.pstruc).level++;
										;}
    break;

  case 146:
#line 1426 "ansic.y"
    {
														printf("type_qualifier_list: type_qualifier\n");
														(yyval.qual) = (yyvsp[(1) - (1)].qual);
													;}
    break;

  case 147:
#line 1430 "ansic.y"
    {
														printf("type_qualifier_list: type_qualifier_list type_qualifier\n");
														(yyval.qual) = (yyvsp[(1) - (2)].qual);
														(yyval.qual) |= (yyvsp[(2) - (2)].qual);
													;}
    break;

  case 148:
#line 1439 "ansic.y"
    {
														printf("parameter_type_list: parameter_list\n");
														(yyval.idlist) = (yyvsp[(1) - (1)].idlist);
													;}
    break;

  case 149:
#line 1443 "ansic.y"
    {printf("parameter_type_list: parameter_list ',' ELLIPSIS\n");;}
    break;

  case 150:
#line 1447 "ansic.y"
    {
														printf("parameter_list: parameter_declaration\n");
														std::list<VAR_DATA *> *newlist = new std::list<VAR_DATA *>;
														VAR_DATA *newstruc = new VAR_DATA();
														*newstruc = (yyvsp[(1) - (1)].sym);
														newlist->push_back(newstruc);
														(yyval.idlist) = newlist;
													;}
    break;

  case 151:
#line 1455 "ansic.y"
    {
														printf("parameter_list: parameter_list ',' parameter_declaration\n");
														(yyval.idlist) = (yyvsp[(1) - (3)].idlist);
														VAR_DATA *newstruc = new VAR_DATA();
														*newstruc = (yyvsp[(3) - (3)].sym);
														(yyval.idlist)->push_back(newstruc);
													;}
    break;

  case 152:
#line 1465 "ansic.y"
    {
														printf("parameter_declaration: declaration_specifiers declarator\n");
														(yyval.sym).name = (yyvsp[(2) - (2)].id_data)->name;
														if(!isarray((yyvsp[(2) - (2)].id_data)->typ))
															(yyval.sym).typ = get_type((yyvsp[(1) - (2)].sqlist));
														else
															(yyval.sym).typ = (yyval.sym).typ = get_type((yyvsp[(1) - (2)].sqlist)) | ARRAY_SPEC;
													;}
    break;

  case 153:
#line 1473 "ansic.y"
    {printf("parameter_declaration: declaration_specifiers abstract_declarator\n");;}
    break;

  case 154:
#line 1474 "ansic.y"
    {printf("parameter_declaration: declaration_specifiers\n");;}
    break;

  case 155:
#line 1478 "ansic.y"
    {
															string *name = new string((yyvsp[(1) - (1)].token.name));
															printf("identifier_list: IDENTIFIER");
															cout << "<" << *name << ">\n";
														;}
    break;

  case 156:
#line 1483 "ansic.y"
    {	string *name = new string((yyvsp[(3) - (3)].token.name));
															printf("identifier_list: identifier_list ',' IDENTIFIER");
															cout << "<" << *name << ">\n";
														;}
    break;

  case 157:
#line 1490 "ansic.y"
    {
															printf("type_name: specifier_qualifier_list\n");
															(yyval.typ) = get_type((yyvsp[(1) - (1)].sqlist));
														;}
    break;

  case 158:
#line 1494 "ansic.y"
    {printf("type_name: specifier_qualifier_list abstract_declarator\n");;}
    break;

  case 159:
#line 1498 "ansic.y"
    {printf("abstract_declarator: pointer\n");;}
    break;

  case 160:
#line 1499 "ansic.y"
    {printf("abstract_declarator: direct_abstract_declarator\n");;}
    break;

  case 161:
#line 1500 "ansic.y"
    {printf("abstract_declarator: pointer direct_abstract_declarator\n");;}
    break;

  case 162:
#line 1504 "ansic.y"
    {printf("direct_abstract_declarator: '(' abstract_declarator ')'\n");;}
    break;

  case 163:
#line 1505 "ansic.y"
    {printf("direct_abstract_declarator: '[' ']'\n");;}
    break;

  case 164:
#line 1506 "ansic.y"
    {printf("direct_abstract_declarator: '[' constant_expression ']'\n");;}
    break;

  case 165:
#line 1507 "ansic.y"
    {printf("direct_abstract_declarator: direct_abstract_declarator '[' ']'\n");;}
    break;

  case 166:
#line 1508 "ansic.y"
    {printf("direct_abstract_declarator: direct_abstract_declarator '[' constant_expression ']'\n");;}
    break;

  case 167:
#line 1509 "ansic.y"
    {printf("direct_abstract_declarator: '(' ')'\n");;}
    break;

  case 168:
#line 1510 "ansic.y"
    {printf("direct_abstract_declarator: '(' parameter_type_list ')'\n");;}
    break;

  case 169:
#line 1511 "ansic.y"
    {printf("direct_abstract_declarator: direct_abstract_declarator '(' ')'\n");;}
    break;

  case 170:
#line 1512 "ansic.y"
    {printf("direct_abstract_declarator: direct_abstract_declarator '(' parameter_type_list ')'\n");;}
    break;

  case 171:
#line 1516 "ansic.y"
    {
												printf("initializer: assignment_expression	\n");
												(yyval.sym) = (yyvsp[(1) - (1)].sym)
											;}
    break;

  case 172:
#line 1520 "ansic.y"
    {printf("initializer: '{' initializer_list '}'\n");;}
    break;

  case 173:
#line 1521 "ansic.y"
    {printf("initializer: '{' initializer_list ',' '}'\n");;}
    break;

  case 174:
#line 1525 "ansic.y"
    {printf("initializer_list: initializer\n");;}
    break;

  case 175:
#line 1526 "ansic.y"
    {printf("initializer_list: initializer_list ',' initializer\n");;}
    break;

  case 177:
#line 1533 "ansic.y"
    {
												printf("statement: labeled_statement\n");
												(yyval.lists) = (yyvsp[(1) - (1)].lists);
												(yyval.lists).nextlist = NULL;
											;}
    break;

  case 178:
#line 1538 "ansic.y"
    {
												enter_scope();
											;}
    break;

  case 179:
#line 1541 "ansic.y"
    {
												printf("statement: compound_statement\n");
												exit_scope();
												(yyval.lists) = (yyvsp[(3) - (3)].lists);
											;}
    break;

  case 180:
#line 1546 "ansic.y"
    {
												printf("statement: expression_statement\n");
												(yyval.lists).gotolist = NULL;
												(yyval.lists).nextlist = NULL;
												(yyval.lists).breaklist = NULL;
												(yyval.lists).caselist = NULL;
												(yyval.lists).continuelist = NULL;	
											;}
    break;

  case 181:
#line 1554 "ansic.y"
    {
												printf("statement: selection_statement\n");
												(yyval.lists) = (yyvsp[(1) - (1)].lists);
												(yyval.lists).caselist = NULL;
											;}
    break;

  case 182:
#line 1559 "ansic.y"
    {
												printf("statement: iteration_statement\n");
												(yyval.lists) = (yyvsp[(1) - (1)].lists);
												(yyval.lists).caselist = NULL;
											;}
    break;

  case 183:
#line 1564 "ansic.y"
    {
												printf("statement: jump_statement\n");
												(yyval.lists) = (yyvsp[(1) - (1)].lists);
												(yyval.lists).caselist = NULL;
											;}
    break;

  case 184:
#line 1570 "ansic.y"
    {
						/*Retorna la direccion de la siugiente intruccion de IR*/
						(yyval.instr) = nextinstr;
					;}
    break;

  case 185:
#line 1576 "ansic.y"
    {
														printf("labeled_statement: IDENTIFIER ':' statement\n");
														putlab(new string((yyvsp[(1) - (4)].token.name)), (yyvsp[(3) - (4)].instr));
														(yyval.lists).gotolist = NULL;
														(yyval.lists).nextlist = NULL;
														(yyval.lists).breaklist = NULL;
														(yyval.lists).caselist = NULL;
														(yyval.lists).continuelist = NULL;
													;}
    break;

  case 186:
#line 1585 "ansic.y"
    {
														printf("labeled_statement: CASE constant_expression ':' statement\n");
														(yyval.lists).gotolist = (yyvsp[(5) - (5)].lists).gotolist;
														(yyval.lists).breaklist = (yyvsp[(5) - (5)].lists).breaklist;
														(yyval.lists).continuelist = (yyvsp[(5) - (5)].lists).continuelist;
														if(!isconstant((yyvsp[(2) - (5)].sym).typ))
															yyerror("Error : CASE expression must be constant\n");
														if(!isintegral((yyvsp[(2) - (5)].sym).typ))
															yyerror("Error : CASE expression must be integral constant\n");
														(yyval.lists).caselist = makecaselist((yyvsp[(2) - (5)].sym).val, (yyvsp[(2) - (5)].sym).typ, (yyvsp[(4) - (5)].instr));
													;}
    break;

  case 187:
#line 1596 "ansic.y"
    {
														printf("labeled_statement: DEFAULT ':' statement\n");
														(yyval.lists).gotolist = (yyvsp[(4) - (4)].lists).gotolist;
														(yyval.lists).breaklist = (yyvsp[(4) - (4)].lists).breaklist;
														(yyval.lists).continuelist = (yyvsp[(4) - (4)].lists).continuelist;
														(yyval.lists).caselist = makecaselist((yyvsp[(3) - (4)].instr));
													;}
    break;

  case 188:
#line 1606 "ansic.y"
    {
													printf("compound_statement: '{' '}'\n");
													(yyval.lists).nextlist = NULL;
													(yyval.lists).breaklist = NULL;
													(yyval.lists).gotolist = NULL;
													(yyval.lists).continuelist = NULL;
												;}
    break;

  case 189:
#line 1613 "ansic.y"
    {
													printf("compound_statement: '{' statement_list '}'\n");
													(yyval.lists) = (yyvsp[(2) - (3)].lists);
												;}
    break;

  case 190:
#line 1617 "ansic.y"
    {
													printf("compound_statement: '{' declaration_list '}'\n");
													(yyval.lists).nextlist = NULL;
													(yyval.lists).breaklist = NULL;
													(yyval.lists).gotolist = NULL;
													(yyval.lists).continuelist = NULL;
												;}
    break;

  case 191:
#line 1624 "ansic.y"
    {
													printf("compound_statement: '{' declaration_list statement_list '}'\n");
													(yyval.lists) = (yyvsp[(3) - (4)].lists);
												;}
    break;

  case 192:
#line 1631 "ansic.y"
    {printf("declaration_list: declaration\n");;}
    break;

  case 193:
#line 1632 "ansic.y"
    {printf("declaration_list: declaration_list declaration\n");;}
    break;

  case 194:
#line 1636 "ansic.y"
    {
												printf("statement_list: statement\n");
												(yyval.lists) = (yyvsp[(1) - (1)].lists);
											;}
    break;

  case 195:
#line 1640 "ansic.y"
    {
												printf("statement_list: statement_list statement\n");
												backpatch((yyvsp[(1) - (3)].lists).nextlist, (yyvsp[(2) - (3)].instr));
												(yyval.lists) = (yyvsp[(1) - (3)].lists);
												(yyval.lists).nextlist = (yyvsp[(3) - (3)].lists).nextlist;
												(yyval.lists).breaklist = merge((yyvsp[(1) - (3)].lists).breaklist, (yyvsp[(3) - (3)].lists).breaklist);
												(yyval.lists).continuelist = merge((yyvsp[(1) - (3)].lists).continuelist, (yyvsp[(3) - (3)].lists).continuelist);
												(yyval.lists).gotolist = merge((yyvsp[(1) - (3)].lists).gotolist, (yyvsp[(3) - (3)].lists).gotolist);
												(yyval.lists).caselist = merge((yyvsp[(1) - (3)].lists).caselist, (yyvsp[(3) - (3)].lists).caselist);
											;}
    break;

  case 196:
#line 1653 "ansic.y"
    {
								printf("expression_statement: ';'\n");
								(yyval.sym).truelist = nullptr;
								(yyval.sym).falselist = nullptr;
							;}
    break;

  case 197:
#line 1658 "ansic.y"
    {
								printf("expression_statement: expression ';'\n");
								(yyval.sym) = (yyvsp[(1) - (2)].sym);
							;}
    break;

  case 198:
#line 1664 "ansic.y"
    {
														(yyval.sym) = (yyvsp[(1) - (1)].sym);
														/*Verificar si expression es comparacion u operacion logica*/
														if((yyvsp[(1) - (1)].sym).truelist == nullptr || (yyvsp[(1) - (1)].sym).falselist == nullptr)
														{
															std::string *name = newtemp(); /*Nueva variable temporal*/
															symrec *s0;
															s0 = putsym(name, INTVAL | CONST_SPEC);
															*(int *)(datablock+s0->offset) = 0;
															(yyval.sym).truelist = makelist(nextinstr);
															gencode(IF_NE_IR, (yyvsp[(1) - (1)].sym).var, s0, nullptr);
															(yyval.sym).falselist = makelist(nextinstr);
															gencode(GOTO_IR);
														}
													;}
    break;

  case 199:
#line 1681 "ansic.y"
    {
																	printf("selection_statement: IF '(' expression ')' statement\n");
																	backpatch((yyvsp[(3) - (6)].sym).truelist, (yyvsp[(5) - (6)].instr));
																	(yyval.lists).nextlist = merge((yyvsp[(3) - (6)].sym).falselist, (yyvsp[(6) - (6)].lists).nextlist);
																	(yyval.lists).breaklist = (yyvsp[(6) - (6)].lists).breaklist;
																	(yyval.lists).continuelist = (yyvsp[(6) - (6)].lists).continuelist;
																	(yyval.lists).gotolist = (yyvsp[(6) - (6)].lists).gotolist;
																;}
    break;

  case 200:
#line 1689 "ansic.y"
    {
																		printf("selection_statement: IF '(' expression ')' statement ELSE statement\n");
																		backpatch((yyvsp[(3) - (10)].sym).truelist, (yyvsp[(5) - (10)].instr));
																		backpatch((yyvsp[(3) - (10)].sym).falselist, (yyvsp[(9) - (10)].instr));
																		(yyval.lists).nextlist = merge((yyvsp[(6) - (10)].lists).nextlist, (yyvsp[(8) - (10)].lists).nextlist, (yyvsp[(10) - (10)].lists).nextlist);
																		(yyval.lists).breaklist = merge((yyvsp[(6) - (10)].lists).breaklist, (yyvsp[(10) - (10)].lists).breaklist);
																		(yyval.lists).continuelist = merge((yyvsp[(6) - (10)].lists).continuelist, (yyvsp[(10) - (10)].lists).continuelist);
																		(yyval.lists).gotolist = merge((yyvsp[(6) - (10)].lists).gotolist, (yyvsp[(10) - (10)].lists).gotolist);
																	;}
    break;

  case 201:
#line 1698 "ansic.y"
    {
																printf("selection_statement: SWITCH '(' expression ')' statement\n");
																if(!isintegral((yyvsp[(3) - (6)].sym).typ))
																	yyerror("Error : switch expression must be integral\n");
																(yyvsp[(6) - (6)].lists).breaklist = merge((yyvsp[(6) - (6)].lists).breaklist, makelist(nextinstr));
																gencode(GOTO_IR);
																backpatch((yyvsp[(5) - (6)].lists).nextlist, nextinstr);
																std::list<CASE_DATA *>::iterator it;
																if((yyvsp[(6) - (6)].lists).caselist != NULL)
																{
																	for(it = (yyvsp[(6) - (6)].lists).caselist->begin(); it != (yyvsp[(6) - (6)].lists).caselist->end(); it++)
																	{
																		int addr = (*it)->addr;
																		int typ = (*it)->typ;
																		if(typ == VOIDVAL)
																			gencode(GOTO_IR, addr);
																		else
																		{
																			std::string *name = newtemp();
																			symrec *s = putsym(name, INTVAL | CONST_SPEC);
																			symrec *s1 = (yyvsp[(3) - (6)].sym).var;
																			*(int *)((char *)datablock+s->offset) = (*it)->val.intval;
																			if(isconstant((yyvsp[(3) - (6)].sym).typ))
																			{
																				name = newtemp();
																				s1 = putsym(name, INTVAL | CONST_SPEC);
																				*(int *)((char *)datablock+s1->offset) = (yyvsp[(3) - (6)].sym).val.intval;
																			}
																			gencode(IF_EQ_IR, s, s1, addr);
																		}
																	}
																}
																backpatch((yyvsp[(6) - (6)].lists).breaklist, nextinstr);
																(yyval.lists).breaklist = NULL;
																(yyval.lists).continuelist = (yyvsp[(6) - (6)].lists).continuelist;
																(yyval.lists).gotolist = (yyvsp[(6) - (6)].lists).gotolist;
																(yyval.lists).nextlist = NULL;
															;}
    break;

  case 202:
#line 1738 "ansic.y"
    {
														(yyval.sym) = (yyvsp[(1) - (1)].sym);
														/*Verificar si expression es comparacion u operacion logica*/
														if((yyvsp[(1) - (1)].sym).truelist == nullptr || (yyvsp[(1) - (1)].sym).falselist == nullptr)
														{
															std::string *name = newtemp(); /*Nueva variable temporal*/
															symrec *s0;
															s0 = putsym(name, INTVAL | CONST_SPEC);
															*(int *)(datablock+s0->offset) = 0;
															(yyval.sym).truelist = makelist(nextinstr);
															gencode(IF_NE_IR, (yyvsp[(1) - (1)].sym).var, s0, nullptr);
															(yyval.sym).falselist = makelist(nextinstr);
															gencode(GOTO_IR);
														}
													;}
    break;

  case 203:
#line 1756 "ansic.y"
    {
																						printf("iteration_statement: WHILE '(' expression ')' statement\n");
																						backpatch((yyvsp[(7) - (7)].lists).nextlist, (yyvsp[(2) - (7)].instr));
																						backpatch((yyvsp[(7) - (7)].lists).continuelist, (yyvsp[(2) - (7)].instr));
																						backpatch((yyvsp[(4) - (7)].sym).truelist, (yyvsp[(6) - (7)].instr));
																						(yyval.lists).nextlist = (yyvsp[(4) - (7)].sym).falselist;
																						gencode(GOTO_IR, (yyvsp[(2) - (7)].instr));
																						backpatch((yyvsp[(7) - (7)].lists).breaklist, nextinstr);
																						(yyval.lists).breaklist = NULL;
																						(yyval.lists).continuelist = NULL;
																						(yyval.lists).gotolist = (yyvsp[(7) - (7)].lists).gotolist;
																					;}
    break;

  case 204:
#line 1768 "ansic.y"
    {
																						printf("iteration_statement: DO statement WHILE '(' expression ')' ';'\n");
																						backpatch((yyvsp[(7) - (9)].sym).truelist, (yyvsp[(2) - (9)].instr));
																						backpatch((yyvsp[(3) - (9)].lists).nextlist, (yyvsp[(5) - (9)].instr));
																						backpatch((yyvsp[(3) - (9)].lists).breaklist, nextinstr);
																						(yyval.lists).breaklist = NULL;
																						(yyval.lists).nextlist = (yyvsp[(7) - (9)].sym).falselist;
																					;}
    break;

  case 205:
#line 1776 "ansic.y"
    {
																						printf("iteration_statement: FOR '(' expression_statement expression_statement ')' statement\n");
																						backpatch((yyvsp[(5) - (8)].sym).truelist, (yyvsp[(6) - (8)].instr));
																						backpatch((yyvsp[(8) - (8)].lists).nextlist, (yyvsp[(4) - (8)].instr));
																						backpatch((yyvsp[(8) - (8)].lists).continuelist, (yyvsp[(4) - (8)].instr));
																						(yyval.lists).nextlist = (yyvsp[(5) - (8)].sym).falselist;
																						gencode(GOTO_IR, (yyvsp[(4) - (8)].instr));
																						backpatch((yyvsp[(8) - (8)].lists).breaklist, nextinstr);
																						(yyval.lists).breaklist = NULL;
																						(yyval.lists).continuelist = NULL;
																						(yyval.lists).gotolist = (yyvsp[(8) - (8)].lists).gotolist
																					;}
    break;

  case 206:
#line 1789 "ansic.y"
    {
																						printf("iteration_statement: FOR '(' expression_statement expression_statement expression ')' statement\n");
																						backpatch((yyvsp[(5) - (11)].sym).truelist, (yyvsp[(10) - (11)].instr));	/*Completar saltos en verdadero de comparacion a N3*/
																						backpatch((yyvsp[(11) - (11)].lists).nextlist, (yyvsp[(6) - (11)].instr));	/*Completar saltos de statement a N2*/
																						backpatch((yyvsp[(11) - (11)].lists).continuelist, (yyvsp[(6) - (11)].instr));
																						backpatch((yyvsp[(9) - (11)].lists).nextlist, (yyvsp[(4) - (11)].instr));		/*Completar saltos de Ma N1*/
																						(yyval.lists).nextlist = (yyvsp[(5) - (11)].sym).falselist;		/*Propagar saltos en falso de comparacion*/
																						gencode(GOTO_IR, (yyvsp[(6) - (11)].instr));			/*Insertar salto a N2*/
																						backpatch((yyvsp[(11) - (11)].lists).breaklist, nextinstr);
																						(yyval.lists).breaklist = NULL;
																						(yyval.lists).continuelist = NULL;
																						(yyval.lists).gotolist = (yyvsp[(11) - (11)].lists).gotolist;
																					;}
    break;

  case 207:
#line 1805 "ansic.y"
    {
									printf("jump_statement: GOTO IDENTIFIER ';'\n");
									(yyval.lists).continuelist = NULL;
									(yyval.lists).breaklist = NULL;
									(yyval.lists).nextlist = NULL;
									(yyval.lists).caselist = NULL;
									(yyval.lists).gotolist = makelist(new string((yyvsp[(2) - (3)].token.name)), nextinstr);
									gencode(GOTO_IR);
								;}
    break;

  case 208:
#line 1814 "ansic.y"
    {
									printf("jump_statement: CONTINUE ';'\n");
									(yyval.lists).breaklist = NULL;
									(yyval.lists).nextlist = NULL;
									(yyval.lists).caselist = NULL;
									(yyval.lists).gotolist = NULL;
									(yyval.lists).continuelist = makelist(nextinstr);
									gencode(GOTO_IR);
								;}
    break;

  case 209:
#line 1823 "ansic.y"
    {
									printf("jump_statement: BREAK ';'	\n");
									(yyval.lists).gotolist = NULL;
									(yyval.lists).nextlist = NULL;
									(yyval.lists).caselist = NULL;
									(yyval.lists).continuelist = NULL;
									(yyval.lists).breaklist = makelist(nextinstr);
									gencode(GOTO_IR);
								;}
    break;

  case 210:
#line 1832 "ansic.y"
    {
									printf("jump_statement: RETURN ';'\n");
									(yyval.lists).gotolist = NULL;
									(yyval.lists).nextlist = NULL;
									(yyval.lists).caselist = NULL;
									(yyval.lists).breaklist = NULL;
									(yyval.lists).continuelist = NULL;
									gencode(RET_IR);
								;}
    break;

  case 211:
#line 1841 "ansic.y"
    {
									printf("jump_statement: RETURN expression ';'\n");
									(yyval.lists).gotolist = NULL;
									(yyval.lists).nextlist = NULL;
									(yyval.lists).caselist = NULL;
									(yyval.lists).breaklist = NULL;
									(yyval.lists).continuelist = NULL;
									gencode(RET_IR, (yyvsp[(2) - (3)].sym).var, nullptr, nullptr);
								;}
    break;

  case 212:
#line 1853 "ansic.y"
    {printf("translation_unit: external_declaration\n");;}
    break;

  case 213:
#line 1854 "ansic.y"
    {printf("translation_unit: external_declaration\n");;}
    break;

  case 214:
#line 1858 "ansic.y"
    {printf("external_declaration: function_definition\n");;}
    break;

  case 215:
#line 1859 "ansic.y"
    {printf("external_declaration: declaration\n");;}
    break;

  case 216:
#line 1863 "ansic.y"
    {printf("function_definition : declaration_specifiers declarator declaration_list compound_statement\n");;}
    break;

  case 217:
#line 1864 "ansic.y"
    {
																					int typ = get_type((yyvsp[(1) - (2)].sqlist)) | (yyvsp[(2) - (2)].id_data)->typ;
																					curr_func = install((yyvsp[(2) - (2)].id_data)->name, typ);
																					gencode(PROC_IR, curr_func);
																					localsyms = new symboltable();
																					enter_scope();
																					installarg((yyvsp[(2) - (2)].id_data)->arglist);
																					/*Iniciar nueva tabla de etiquetas*/
																					lab_table.clear();
																					setargs();
																				;}
    break;

  case 218:
#line 1875 "ansic.y"
    {
																					
																					printf("function_definition : declaration_specifiers declarator compound_statement\n");
																					//printlocalvars();
																					exit_scope();
																					curr_func->func_desc.sym_table = localsyms;
																					gencode(ENDPROC_IR, curr_func);
																					//patch_gotos($4.gotolist);
																				;}
    break;

  case 219:
#line 1884 "ansic.y"
    {printf("function_definition : declarator declaration_list compound_statement\n");;}
    break;

  case 220:
#line 1885 "ansic.y"
    {
																					int typ = (yyvsp[(1) - (1)].id_data)->typ;
																					curr_func = install((yyvsp[(1) - (1)].id_data)->name, typ);
																					gencode(PROC_IR, curr_func);
																					localsyms = new symboltable();
																					enter_scope();
																					installarg((yyvsp[(1) - (1)].id_data)->arglist);
																					/*Iniciar nueva tabla de etiquetas*/
																					lab_table.clear();
																					setargs();
																				;}
    break;

  case 221:
#line 1896 "ansic.y"
    {	printf("function_definition : declarator compound_statement\n");
																					//printlocalvars();
																					exit_scope();
																					curr_func->func_desc.sym_table = localsyms;
																					gencode(ENDPROC_IR, curr_func);
																					patch_gotos((yyvsp[(3) - (3)].lists).gotolist);
																				;}
    break;


/* Line 1267 of yacc.c.  */
#line 4501 "ansic.tab.c"
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
      yyerror (YY_("syntax error"));
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
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
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
		      yytoken, &yylval);
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
		  yystos[yystate], yyvsp);
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
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 1904 "ansic.y"


int main(int argc, char *argv[])
{
	//Guarda nombre de archivo compilarse.
	string fname;
	printf("Analizador Sintactico de ANSI C 2021 version 0.6\n\n");
	//Crea tabla de simbolos globales
	printf("\n");
	sym_table = new symboltable();
	printf("\n");
	if(argc > 1)
	{
		yyin = fopen(argv[1], "r");
		fname = argv[1];
	}
	else
	{
		cout << "Uso: " << argv[0] << "<filename>\n";	
	}
	yyparse();							//Se empieza a hacer el analizis sintactico
	printvars();						//se termina hasta que ya no se retorna ningun token
	printf("\n");
	printf("Codigo intermedio: \n");
	print_icode();
	print_code(fname);
	return 0;
}

