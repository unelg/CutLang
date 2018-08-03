/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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

#ifndef YY_YY_B_HPP_INCLUDED
# define YY_YY_B_HPP_INCLUDED
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
    DEF = 258,
    CMD = 259,
    ELE = 260,
    MUO = 261,
    LEP = 262,
    PHO = 263,
    JET = 264,
    BJET = 265,
    QGJET = 266,
    NUMET = 267,
    METLV = 268,
    PHI = 269,
    ETA = 270,
    ABSETA = 271,
    PT = 272,
    PZ = 273,
    NBF = 274,
    DR = 275,
    DPHI = 276,
    NELE = 277,
    NMUO = 278,
    NLEP = 279,
    NPHO = 280,
    NJET = 281,
    NBJET = 282,
    NQGJET = 283,
    HT = 284,
    METMWT = 285,
    MWT = 286,
    MET = 287,
    ALL = 288,
    LEPSF = 289,
    FILLHISTOS = 290,
    NB = 291,
    ID = 292,
    SIN = 293,
    COS = 294,
    TAN = 295,
    INT = 296,
    OR = 297,
    AND = 298,
    LT = 299,
    GT = 300,
    LE = 301,
    GE = 302,
    EQ = 303,
    NE = 304,
    IRG = 305,
    ERG = 306,
    Unary = 307
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 26 "parse.y" /* yacc.c:1909  */

        Node* node;
	double real;
	char* s;//ADD POINTER TO NODE unique_ptr?

#line 113 "b.hpp" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_B_HPP_INCLUDED  */
