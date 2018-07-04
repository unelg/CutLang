%{ 
//#define YYSTYPE double
#include <math.h>
#include <iostream>
#include <string.h>
#include <map>
#include <iterator>
extern int yylex();
extern int yyparse();
void yyerror(const char *s) { std::cout << s << std::endl; } 
double result;
using namespace std;
map<string,string> vars;
%}
%union {
	double real;
	char* s;
}
%token DEF
%token <s> VARDEF
%token CMD
%token <real> NB
%token <s> ID
%token SIN
%token COS
%token TAN
%left '+' '-'
%left '*' '/'
%right Unary
%right '^'
%%
input : definitions commands
     ;
definitions : definitions definition
            | 
            ;
definition : DEF ID VARDEF {
								string name = $2;
								string phrase= $3;
								vars.insert(make_pair(name,phrase));
								
							}
commands : commands command
        | 
        ;
command : CMD 
		;
// e : e '+' e  { $$ = $1 + $3 ; }
//    | e '-' e { $$ = $1 - $3 ; }
//    | e '*' e { $$ = $1 * $3 ; }
//    | e '/' e { $$ = $1 / $3*1.0 ; }
//    | e '^' e { $$ = pow($1,$3) ;  } 	
//    |'-' e %prec Unary { $$ = - $2 ; }
//    | COS '(' e ')' { $$ = cos($3) ;}
//    | SIN '(' e ')' { $$ = sin($3) ;}
//    | TAN '(' e ')' { $$ = tan($3) ;}
//    |'(' e ')' { $$ = $2 ;}
//    | NB { $$ = $1 ;std::cout<<"NB: "<<$1<<std::endl;} 	
//    ;
%%
int main(void) {yyparse(); 
cout<<"\n results: \n";
			std::map<std::string, string>::iterator it = vars.begin();
    while(it != vars.end())
    {
        std::cout<<it->first<<" :: "<<it->second<<std::endl;
        it++;
    }
			//std::cout <<"Main Result: " <<result << std::endl;
			}
