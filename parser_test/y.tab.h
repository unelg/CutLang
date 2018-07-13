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
     VARDEF = 259,
     CMD = 260,
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
     NB = 278,
     ID = 279,
     SIN = 280,
     COS = 281,
     TAN = 282,
     INT = 283,
     Unary = 284
   };
#endif
/* Tokens.  */
#define DEF 258
#define VARDEF 259
#define CMD 260
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
#define NB 278
#define ID 279
#define SIN 280
#define COS 281
#define TAN 282
#define INT 283
#define Unary 284




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 18 "parse.y"
{
	double real;
	char* s;
}
/* Line 1529 of yacc.c.  */
#line 112 "y.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

