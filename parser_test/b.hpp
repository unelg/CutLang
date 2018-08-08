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
     PHI = 270,
     ETA = 271,
     ABSETA = 272,
     PT = 273,
     PZ = 274,
     NBF = 275,
     DR = 276,
     DPHI = 277,
     NELE = 278,
     NMUO = 279,
     NLEP = 280,
     NPHO = 281,
     NJET = 282,
     NBJET = 283,
     NQGJET = 284,
     HT = 285,
     METMWT = 286,
     MWT = 287,
     MET = 288,
     ALL = 289,
     LEPSF = 290,
     FILLHISTOS = 291,
     NB = 292,
     ID = 293,
     SIN = 294,
     COS = 295,
     TAN = 296,
     INT = 297,
     OR = 298,
     AND = 299,
     LT = 300,
     GT = 301,
     LE = 302,
     GE = 303,
     EQ = 304,
     NE = 305,
     IRG = 306,
     ERG = 307,
     Unary = 308
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
#define PHI 270
#define ETA 271
#define ABSETA 272
#define PT 273
#define PZ 274
#define NBF 275
#define DR 276
#define DPHI 277
#define NELE 278
#define NMUO 279
#define NLEP 280
#define NPHO 281
#define NJET 282
#define NBJET 283
#define NQGJET 284
#define HT 285
#define METMWT 286
#define MWT 287
#define MET 288
#define ALL 289
#define LEPSF 290
#define FILLHISTOS 291
#define NB 292
#define ID 293
#define SIN 294
#define COS 295
#define TAN 296
#define INT 297
#define OR 298
#define AND 299
#define LT 300
#define GT 301
#define LE 302
#define GE 303
#define EQ 304
#define NE 305
#define IRG 306
#define ERG 307
#define Unary 308




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 28 "parse.y"
{
        Node* node;
	double real;
	char* s;//ADD POINTER TO NODE unique_ptr?
}
/* Line 1529 of yacc.c.  */
#line 161 "b.hpp"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

