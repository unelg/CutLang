%option noyywrap
%{
class Node;
#include "stdlib.h"
#include <string>
#include <iostream>
#include "b.hpp"
%}
integer [0-9]+
exp [eE][+-]?{integer}
real {integer}("."{integer})?{exp}?
varname [a-zA-Z]+{integer}
vardef {varname}" "?":"" "?.*"\n"
%%
"def" return DEF;//case sensitive in this case
"cmd" return CMD;
"obj" return OBJ;
"algo" return ALGO;
"histo" return HISTO;
"minptm" return MINPTM;
"minptg" return MINPTG;
"minptj" return MINPTJ;
"minpte" return MINPTE;
"maxetam" return MAXETAM;
"maxetae" return MAXETAE;
"maxetag" return MAXETAG;
"maxetaj" return MAXETAJ;
"maxmet" return MAXMET;
"TRGe" return TRGE;
"TRGm" return TRGM;
"btag_lowthreshold_LVL0" return LVLO;
"btag_lowthreshold_ATLASOD" return ATLASOD;
"btag_lowthreshold_CMSOD" return CMSOD;
"btag_lowthreshold_DELPHES" return DELPHES;
"btag_lowthreshold_FCC" return FCC;
"btag_lowthreshold_LHCO" return LHCO;
"ELE" return ELE;//particles
"MUO" return MUO;
"LEP" return LEP;
"PHO" return PHO;
"JET" return JET;
"BJET" return BJET;
"QGJET" return QGJET;
"NUMET" return NUMET;
"METLV" return METLV;
"Phi" return PHI;//functions
"Eta" return ETA;
"AbsEta" return ABSETA;
"Pt" return PT;
"Pz" return PZ;
"nbf" return NBF;
"dR" return DR;
"dPhi" return DPHI;
"nELE" return NELE;//no arg funcs
"nMUO" return NMUO;
"nLEP" return NLEP;
"nPHO" return NPHO;
"nJET" return NJET;
"nBJET" return NBJET;
"nQGJET" return NQGJET;
"HT" return HT;
"METMWT" return METMWT;
"MWT" return MWT;
"MET" return MET;
"ALL" return ALL;
"LEPsf" return LEPSF;
"FillHistos" return FILLHISTOS;
"=="|"EQ" return EQ;//comparison operators
"!="|"NE" return NE;
"<="|"LE" return LE;
">="|"GE" return GE;
"<"|"LT" return LT;
">"|"GT" return GT;
"[]" return IRG;
"][" return ERG;
"AND"|"&&" return AND;//logical ops
"OR"|"||" return OR;
"#".*"\n" ;
[ \t\n] ;
[tT][aA][nN] return TAN;
[sS][iI][nN] return SIN;
[cC][oO][sS] return COS;
{integer} sscanf(yytext, "%lf",&yylval.real);return INT;
{real} sscanf(yytext, "%lf",&yylval.real);return NB ;
[-+*/()^:{}_mqPE,?=] return *yytext;
[a-zA-Z]+{integer}?[a-zA-Z]* yylval.s=strdup(yytext);return ID;
%%
