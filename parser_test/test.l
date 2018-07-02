%option noyywrap
%{
#include "stdlib.h"
#include <string>
#include "y.tab.h"
%}
integer [0-9]+
exp [eE][+-]?{integer}
real {integer}("."{integer})?{exp}?
%%
[ \t\n] ;
[tT][aA][nN] return TAN;
[sS][iI][nN] return SIN;
[cC][oO][sS] return COS;
{real} sscanf(yytext, "%lf",&yylval);return NB ;
[-+*/()^] return *yytext;
[a-zA-Z]+ return ID;
"#".*"\n" ;
%%
