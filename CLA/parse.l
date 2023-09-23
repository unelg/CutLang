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
[dD][eE][fF]|[dD][eE][fF][iI][Nn][eE] return DEF;//case sensitive in this case
[cC][mM][dD]|[cC][uU][tT]|[sS][eE][lL][eE][cC][tT] return CMD;
[rR][eE][jJ][eE][cC][tT] return REJEC;
[oO][bB][jJ]|[oO][bB][jJ][eE][cC][tT] return OBJ;
[aA][lL][gG][oO]|[rR][eE][gG][iI][oO][nN]|"algorithm" return ALGO;
"TRGe" return TRGE;
"TRGm" return TRGM;

[iI][nN][fF][oO] return ADLINFO;
"experiment" return PAPEXPERIMENT;
"id" return PAPID;
[tT][iI][tT][lL][eE] return PAPTITLE;
"publication" return PAPPUBLICATION;
"sqrtS" return PAPSQRTS;
"lumi"  return PAPLUMI;
"arXiv" return PAPARXIV;
"hepdata" return PAPHEPDATA;
"doi"    return PAPDOI;

"counts"  return COUNTS;
"countsformat" return COUNTSFORMAT;
"stat" return ERR_STAT;
"syst" return ERR_SYST;
"process" return PROCESS;

"systematic" return SYSTEMATIC;
"ttree" return SYST_TTREE;
"weight_mc"    return SYST_W_MC;
"weight_pileup"    return SYST_W_PILEUP;
"weight_jvt"    return SYST_W_JVT;
"weight_leptonSF" return SYST_W_LEP;
"weight_BTagSF"   return SYST_W_BTAG;
"RunYear" return RUNYEAR;
"mcChannelNumber" return MCCHANNELNUMBER;
[eE][vV][eE][nN][tT][nN][oO] return EVENTNO;
[rR][uU][nN][nN][oO] return RUNNO;
[lL][bB][nN][oO] return LBNO;
"OME" return OME;

[pP][rR][iI][nN][tT] return PRINT;
[oO][nN]|[tT][rR][uU][eE] return TRUE; 
[oO][fF][fF]|[fF][aA][lL][sS][eE] return FALSE; 
[Nn][Vv][Aa][Rr][Ss] return NVARS;
[eE][rR][rR][oO][rR][sS] return ERRORS;
[tT][aA][bB][lL][eE][tT][yY][pP][eE] return TABLETYPE;
[tT][aA][kK][eE]|[uU][sS][iI][nN][gG] return TAKE;
[hH][iI][sS][tT][oO] return HISTO;
[wW][eE][iI][gG][hH][tT] return WEIGHT;
[tT][aA][bB][lL][eE] return TABLE;
[Ss][Kk][Ii][Pp][Hh][Ii][Ss][Tt][Oo][Ss] return SKPH;
[Ss][Kk][Ii][Pp][Ee][Ff][Ff][Ss] return SKPE;
[Gg][Ee][Nn] return GEN;
[eE][lL][eE]|"Electron"|"electron" return ELE;//particles
[mM][uU][oO]|"Muon"|"muon" return MUO;
[tT][aA][uU] return TAU;
[tT][rR][kK] return TRK;
[pP][hH][oO]|"Photon" return PHO;
[jJ][eE][tT] return JET;
[fF][jJ][eE][tT]|"FatJet" return FJET;
[qQ][gG][jJ][eE][tT] return QGJET;
[bB][iI][nN] return BINS;
"daughter"|"constituents" return CONSTITS;
"NUMET" return NUMET;
"METLV" return METLV;
"LEP" return LEP;
"BJET" return BJET;
[iI][nN][dD][eE][xX] return IDX;

[Mm][eE][tT][sS][iI][gG] return METSIGNIF;
"applyHM" return APPLYHM;
"applyPTF"|"scalePT"  return APPLYPTF;
"applyEF"|"scaleE"  return APPLYEF;
"genPartIdx" return GENPARTIDX;

[uU][nN][iI][oO][nN] return UNION;
[aA][lL][iI][aA][sS] return ALIAS;

[bB][tT][aA][gG] return ISBTAG;
[cC][tT][aA][gG] return ISCTAG;
[tT][aA][uU][tT][aA][gG] return ISTAUTAG;

[pP][dD][gG][iI][dD] return PDGID;
[fF][lL][aA][vV][oO][rR]|[bB][tT][aA][gG][gG][eE][rR] return FLAVOR;
[pP][tT][cC][oO][nN][eE] return PTCONE;
[eE][tT][cC][oO][nN][eE] return ETCONE;

[vV][eE][rR][tT][eE][xX][tT] return VERT;
[vV][eE][rR][tT][eE][xX][xX] return VERX;
[vV][eE][rR][tT][eE][xX][yY] return VERY;
[vV][eE][rR][tT][eE][xX][zZ] return VERZ;
[vV][eE][rR][tT][eE][xX][tT][rR] return VERTR;

"fmegajets" return FMEGAJETS;
"fhemisphere" return FHEMISPHERE;
"fMR" return FMR;
"fMTR" return FMTR;
"fMT2" return FMT2;
"fMTauTau" return FMTAUTAU;
[mM][iI][nN][iI][iI][sS][oO] return MINIISO;
[aA][bB][sS][iI][sS][oO] return ABSISO;

"dxy"|[dD]"0" return DXY;
"edxy"|[eE][dD]"0" return EDXY;
"dz" return DZ;
"edz" return EDZ;

"m_HF_Classification" return HFCLASSIFICATION; // generalize event variables.
"fTTrr" return TTBARNNLOREC;

[pP][hH][iI] return PHI;//functions
[eE][tT][aA] return ETA;
[rR][aA][pP] return RAP;
[Aa][bB][sS][Ee][tT][aA] return ABSETA;
[pP][tT] return PT;
[pP][zZ] return PZ;
[dD][rR] return DR;
[dD][pP][hH][iI] return DPHI;
[dD][eE][tT][aA] return DETA;
[sS][iI][zZ][eE]|"Count"|"NumOf" return NUMOF;//no arg funcs 
[nN][bB][jJ] return NBF;
[fF][hH][tT] return HT; // attention
"MET" return MET;
"LEPsf" return LEPSF;
"bTagSF" return BTAGSF;
"XSLumiCorrSF" return XSLUMICORRSF;

[aA][nN][yY][oO][fF] return ANYOF;
[aA][lL][lL][oO][fF] return ALLOF;
[aA][lL][lL] return ALL;
[nN][oO][nN][eE] return NONE;
"=="|"EQ" return EQ;//comparison operators
"!="|"NE" return NE;
"~!" return MAXIMIZE;
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
[aA][vV][eE] return AVE;
[sS][uU][mM] return SUM;
[aA][dD][dD] return ADD;
[sS][aA][vV][eE] return SAVE;
[cC][sS][vV] return CSV;
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
[dD][Ee][lL][Tt][aA] return DELTA;
[aA][bB][sS] return ABS;
[sS][qQ][rR][tT] return SQRT;
[sS][oO][rR][tT] return SORT;
[cC][oO][mM][bB] return COMB;
[pP][eE][rR][mM] return PERM;
[mM][iI][nN] return MIN;
[mM][aA][xX] return MAX;
"+-"|"-+" return PM;
"<<"|">>" return *yytext;
[-]?{integer} sscanf(yytext, "%d",&yylval.integer);return INT;
[-]?{real} sscanf(yytext, "%lf",&yylval.real);return NB ;
{real} sscanf(yytext, "%lf",&yylval.real);return PNB ;
[-+*/()&|^:\[\]{}_mqPE,?=] return *yytext;
[a-zA-Z0-9]+(?:_[a-zA-Z]+[a-zA-Z0-9]*)*[a-zA-Z0-9]+ yylval.s=strdup(yytext);return ID;
"\""[^\"]*"\"" yylval.s=strdup(yytext);return HID;
%%
