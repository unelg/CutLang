/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

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

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
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
/* Tokens.  */
#define DEF 258
#define CMD 259
#define ELE 260
#define MUO 261
#define LEP 262
#define PHO 263
#define JET 264
#define BJET 265
#define QGJET 266
#define NUMET 267
#define METLV 268
#define PHI 269
#define ETA 270
#define ABSETA 271
#define PT 272
#define PZ 273
#define NBF 274
#define DR 275
#define DPHI 276
#define NELE 277
#define NMUO 278
#define NLEP 279
#define NPHO 280
#define NJET 281
#define NBJET 282
#define NQGJET 283
#define HT 284
#define METMWT 285
#define MWT 286
#define MET 287
#define ALL 288
#define LEPSF 289
#define FILLHISTOS 290
#define NB 291
#define ID 292
#define SIN 293
#define COS 294
#define TAN 295
#define INT 296
#define OR 297
#define AND 298
#define LT 299
#define GT 300
#define LE 301
#define GE 302
#define EQ 303
#define NE 304
#define IRG 305
#define ERG 306
#define Unary 307




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 26 "parse.y"
{
        Node* node;
	double real;
	char* s;//ADD POINTER TO NODE unique_ptr?
}
/* Line 1529 of yacc.c.  */
#line 159 "b.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

