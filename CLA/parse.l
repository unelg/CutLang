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
"ELE"|"ELECTRON" return ELE;//particles
"MUO"|"MUON"|"Muon" return MUO;
"Tau"|"TAU" return TAU;
"PHO"|"PHOTON" return PHO;
"JET"|"Jet" return JET;
"FJET"|"FatJet" return FJET;
"LEP" return LEP;
"PDGID" return PDGID;
"WEIGHT" return WEIGHT;
"btagDeepB" return DEEPB;
"msoftdrop" return MSOFTD;
"tau1" return TAU1;
"tau2" return TAU2;
"tau3" return TAU3;
"fmegajets" return FMEGAJETS;
"fMR" return FMR;
"fMTR" return FMTR;
"miniPFRelIsoAll" return RELISO;
"dxy" return DXY;
"dz" return DZ;
"dMVAnewDM2017v2" return TAUISO;
"softId" return SOFTID;
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
"dEta" return DETA;
"Size"|"Count"|"NumberOf"|"NumOf" return NUMOF;//no arg funcs
"HT" return HT;
"METMWT" return METMWT;
"MWT" return MWT;
"MET" return MET;
"ALL" return ALL;
"LEPsf" return LEPSF;
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
"AND"|"&&" return AND;//logical ops
"OR"|"||" return OR;
"NOT" return NOT;
"#".*"\n" ;
[ \t\n] ;
[tT][aA][nN] return TAN;
[sS][iI][nN] return SIN;
[cC][oO][sS] return COS;
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
