%option noyywrap
%option yylineno
%{
class Node;
#include "stdlib.h"
#include <string>
#include <map>
#include <list>
#include <vector>
#include <iostream>
#include "myParticle.h"
#include "b.hpp"
%}
integer [0-9]+
exp `[eE][+-]?{integer}'
real {integer}("."{integer})
varname [a-zA-Z]+{integer}
vardef {varname}" "?":"" "?.*"\n"
%%
[dD][eE][fF]|"define" return DEF;//case sensitive in this case
[cC][mM][dD]|[cC][uU][tT]|[sS][eE][lL][eE][cC][tT] return CMD;
"reject" return REJEC;
"obj"|"object" return OBJ;
"algo"|"region"|"algorithm" return ALGO;
"take"|"using" return TAKE;
"histo" return HISTO;
[wW][eE][iI][gG][hH][tT] return WEIGHT;
[tT][aA][bB][lL][eE] return TABLE;
"TRGe" return TRGE;
"TRGm" return TRGM;

[eE][lL][eE]|"ELECTRON" return ELE;//particles
[mM][uU][oO]|"MUON" return MUO;
[tT][aA][uU] return TAU;
[pP][hH][oO]|"PHOTON" return PHO;
[jJ][eE][tT] return JET;
[Gg][Ee][Nn] return GEN;
"FJET"|"FatJet" return FJET;
"BJET" return BJET;
"QGJET" return QGJET;
"LEP" return LEP;
"NUMET" return NUMET;
"METLV" return METLV;
"MET" return MET;
"ALL" return ALL;

"PDGID" return PDGID;
"btagDeepB" return DEEPB;
[bB][tT][aA][gG] return ISBTAG;
"msoftdrop" return MSOFTD;
"tau1" return TAU1;
"tau2" return TAU2;
"tau3" return TAU3;
"fmegajets" return FMEGAJETS;
"fMR" return FMR;
"fMTR" return FMTR;
"fMTauTau" return FMTAUTAU;
"miniPFRelIsoAll" return RELISO;
"dxy" return DXY;
"dz" return DZ;
"dMVAnewDM2017v2" return TAUISO;
"softId" return SOFTID;
"alias" return ALIAS;

  /* ************* generic functions ******* */
[pP][hT][iI] return PHI;
[eE][tT][aA] return ETA;
[aA][bB][sS][eE][tT][aA] return ETA;
[pP][tT] return PT;
[pP][zZ] return PZ;
[dD][rR] return DR;
[dD][pP][hH][iI] return DPHI;
[dD][eE][tT][aA] return DETA;
[Ss][Ii][Zz][Ee]|[cC][Oo][uU][nN][tT]|[nN][uU][mM][bB][eE][rR] return NUMOF;//no arg funcs
[hH][tT] return HT;
"METMWT" return METMWT;
"MWT" return MWT;
"LEPsf" return LEPSF;
"bTagSF" return BTAGSF;
"nbf" return NBF;

"=="|"EQ" return EQ;//comparison operators
"<>"|"NE" return NE;
"!=" return MAXIMIZE;
"~=" return MINIMIZE;
"<="|"LE" return LE;
">="|"GE" return GE;
"<"|"LT" return LT;
">"|"GT" return GT;
"[]" return IRG;
"][" return ERG;
"AND"|"&&"|"and" return AND;//logical ops
"OR"|"||"|"or" return OR;
"NOT" return NOT;
"#".*"\n" ;
[ \t\n] ;
[uU][nN][iI][oO][nN] return UNION;
[sS][aA][vV][eE] return SAVE;
[Aa][Ss][Cc][Ee][Nn][Dd] return ASCEND;
[Dd][Ee][Ss][Cc][Ee][Nn][Dd] return DESCEND;
[tT][aA][nN] return TAN;
[sS][iI][nN] return SIN;
[cC][oO][sS] return COS;
[sS][iI][nN][hH] return SINH;
[cC][oO][sS][hH] return COSH;
[tT][aA][nN][hH] return TANH;
[eE][xX][pP] return EXP;
[lL][oO][gG] return LOG;
[Hh][Ss][Tt][Ee][Pp] return HSTEP;
[aA][bB][sS] return ABS;
[sS][qQ][rR][tT] return SQRT;
[sS][oO][rR][tT] return SORT;
[cC][oO][mM][bB] return COMB;
[pP][eE][rR][mM] return PERM;
{integer} sscanf(yytext, "%d",&yylval.integer);return INT;
{real} sscanf(yytext, "%lf",&yylval.real);return NB ;
[-+*/()^:\[\]{}_mqPE,?=] return *yytext;
[a-zA-Z]+{integer}?[a-zA-Z]+{integer}* yylval.s=strdup(yytext);return ID;
"\"".*"\"" yylval.s=strdup(yytext);return HID;
%%
