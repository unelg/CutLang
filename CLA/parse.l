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
"def"|"define" return DEF;//case sensitive in this case
"cmd"|"cut"|"select"|"command" return CMD;
"reject" return REJEC;
"obj"|"object" return OBJ;
"algo"|"region"|"algorithm" return ALGO;
"take"|"using" return TAKE;
"histo" return HISTO;
"weight" return WEIGHT;
"table" return TABLE;
"TRGe" return TRGE;
"TRGm" return TRGM;
"ELE"|"ELECTRON" return ELE;//particles
"MUO"|"MUON"|"Muon" return MUO;
"Tau"|"TAU" return TAU;
"PHO"|"PHOTON" return PHO;
"JET"|"Jet" return JET;
"FJET"|"FatJet" return FJET;
[Gg][Ee][Nn] return GEN;
"LEP" return LEP;
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
"BJET" return BJET;
"QGJET" return QGJET;
"NUMET" return NUMET;
"METLV" return METLV;
[pP][hT][iI] return PHI;//functions
[eE][tT][aA] return ETA;
"AbsEta" return ABSETA;
"alias" return ALIAS;
[pP][tT] return PT;
[pP][zZ] return PZ;
"nbf" return NBF;
"dR" return DR;
"dPhi" return DPHI;
"dEta" return DETA;
"Size"|"Count"|"NumberOf"|"NumOf" return NUMOF;//no arg funcs
"HT" return HT;
"METMWT" return METMWT;
"MWT" return MWT;
"MET" return MET;
"ALL" return ALL;
"LEPsf" return LEPSF;
"bTagSF" return BTAGSF;
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
