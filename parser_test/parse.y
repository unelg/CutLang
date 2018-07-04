%{ 
#define YYSTYPE double
#include <math.h>
#include <iostream>
#include <string>
extern int yylex();
extern int yyparse();
void yyerror(const char *s) { std::cout << s << std::endl; } 
double result;
%}
%token NB
%token ID
%token SIN
%token COS
%token TAN
%left '+' '-'
%left '*' '/'
%right Unary
%right '^'
%%
input : e { result=$1;}
    |
    ;
e : e '+' e  { $$ = $1 + $3 ; }
   | e '-' e { $$ = $1 - $3 ; }
   | e '*' e { $$ = $1 * $3 ; }
   | e '/' e { $$ = $1 / $3*1.0 ; }
   | e '^' e { $$ = pow($1,$3) ;  } 	
   |'-' e %prec Unary { $$ = - $2 ; }
   | COS '(' e ')' { $$ = cos($3) ;}
   | SIN '(' e ')' { $$ = sin($3) ;}
   | TAN '(' e ')' { $$ = tan($3) ;}
   |'(' e ')' { $$ = $2 ;}
   | NB { $$ = $1 ;std::cout<<"NB: "<<$1<<std::endl;} 	
   ;
%%
int main(void) {yyparse(); 
			std::cout <<"Main Result: " <<result << std::endl;
			}
