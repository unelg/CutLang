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




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 31 "parse.y"
{
        Node* node;
	double real;
	char* s;//ADD POINTER TO NODE unique_ptr?
}
/* Line 1529 of yacc.c.  */
#line 195 "b.hpp"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

