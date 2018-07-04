%option noyywrap
%{
#include "stdlib.h"
#include <string>
#include <iostream>
#include "y.tab.h"
int i=0;
%}
integer [0-9]+
exp [eE][+-]?{integer}
real {integer}("."{integer})?{exp}?
varname [a-zA-Z]+{integer}
vardef {varname}" "?":"" "?.*"\n"
%%
"def" return DEF;//case sensitive in this case
"cmd" return CMD;
"#".* ;
[ \t\n] ;
[tT][aA][nN] return TAN;
[sS][iI][nN] return SIN;
[cC][oO][sS] return COS;
{real} sscanf(yytext, "%lf",&yylval.real);return NB ;
[-+*/()^:{}] return *yytext;
[a-zA-Z]+{integer} yylval.s=strdup(yytext);return ID;
":"[^#]* {std::cout<<++i<<" "<<yytext<<std::endl;
            yylval.s=strdup(yytext);
            return (VARDEF);
        }
%%
