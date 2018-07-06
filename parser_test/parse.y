%{ 
//#define YYSTYPE double
#include <math.h>
#include "stdlib.h"
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
//%token <s> VARDEF
%token CMD
%token ELE
%token MUO
%token LEP
%token PHO
%token JET
%token BJET
%token QGJET
%token NUMET
%token METLV
%token <real> NB
%token <s> ID
%token SIN
%token COS
%token TAN
%token <real> INT
%left '+' '-'
%left '*' '/'
%right Unary
%right '^'
%type <real> index
%type <s> particule
%type <s> particules
%%
input : definitions commands
     ;
definitions : definitions definition
            | 
            ;
definition : DEF ID ':' particules {
                                         string name = $2;
                                         string phrase= $4;
                                         vars.insert(make_pair(name,phrase));
							        }
particules : particules particule { std::cout<<$2<<std::endl;}
            |
            ;
particule : ELE '_' index {
                            //do something with name and index?
                            //std::cout<<"ele_"<<$3<<std::endl;
                            
                            string tmp="ele_"+to_string($3);
                            //////////////////////////$$=strdup(tmp);
                            
                            }
        | MUO '_' index {std::cout<<"muo_"<<$3<<std::endl;}
        | LEP '_' index {std::cout<<"lep_"<<$3<<std::endl;}
        | PHO '_' index {std::cout<<"pho_"<<$3<<std::endl;}
        | JET '_' index {std::cout<<"jet_"<<$3<<std::endl;}
        | BJET '_' index {std::cout<<"bjet_"<<$3<<std::endl;}
        | QGJET '_' index {std::cout<<"qgjet_"<<$3<<std::endl;}
        | NUMET '_' index {std::cout<<"numet_"<<$3<<std::endl;}
        | METLV '_' index {std::cout<<"metlv_"<<$3<<std::endl;}
        ;
index : '-' INT {$$=-$2;}
      | INT {$$= $1;}
      ; 
commands : commands command
        | 
        ;
command : CMD //to continue
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
//we should also match integers in here INT
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
