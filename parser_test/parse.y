%{ 
//#define YYSTYPE double
#include <math.h>
#include "stdlib.h"
#include <iostream>
#include <string>
#include <map>
#include <iterator>
extern int yylex();
extern int yyparse();
void yyerror(const char *s) { std::cout << s << std::endl; } 
double result;
using namespace std;
string tmp;
int pnum;
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
%type <s> vardef
%type <s> particule
%type <s> particules
%%
input : definitions commands
     ;
definitions : definitions definition
            | 
            ;
definition : DEF ID ':' vardef {
                                         
                                         map<string, string>::iterator it ;
                                         string name = $2;
                                        it = vars.find(name);
                        
                                        if(it != vars.end()) {
                                                cout <<name<<" : " ;
                                                yyerror("Variable already defined");
                                                YYERROR;//stops parsing
                                                
                                        }
                                         
                                         string phrase= $4;
                                         vars.insert(make_pair(name,phrase));
                                         cout<<"\nend "<<$4<<endl;
                                         
				}
           ;
vardef : particules {pnum=0;}
       | function
       ;
function : '{' particules '}' 'm' ////////////////
        ;
particules : particules particule { 
                                        if (pnum==0){
                                                
                                                $$=strdup($2);
                                                pnum++;
                                        }
                                        else{
                                                
                                                char s [1024];
                                                strcpy(s,$$); 
                                                strcat(s," ");
                                                strcat(s,$2);
                                                strcpy($$,s);

                                        }

                                        free($2);

                                        }
            | 
            ;
particule : ELE '_' index {
                            //do something with name and index? Maybe put them in lists
                                                        
                            tmp="ele_"+to_string((int)$3);                        
                            $$=strdup(tmp.c_str());
                                                        
                            }
        | MUO '_' index {       tmp="muo_"+to_string((int)$3);                        
                                $$=strdup(tmp.c_str());
                                
                        }
        | LEP '_' index {       tmp="lep_"+to_string((int)$3);                        
                                $$=strdup(tmp.c_str());
                                
                        }
        | PHO '_' index {       tmp="pho_"+to_string((int)$3);                        
                                $$=strdup(tmp.c_str());
                                
                        }
        | JET '_' index {       tmp="jet_"+to_string((int)$3);                        
                                $$=strdup(tmp.c_str());
                                
                        }
        | BJET '_' index {       tmp="bjet_"+to_string((int)$3);                        
                                $$=strdup(tmp.c_str());
                                
                        }
        | QGJET '_' index {       tmp="qgjet_"+to_string((int)$3);                        
                                $$=strdup(tmp.c_str());
                                
                        }
        | NUMET '_' index {       tmp="numet_"+to_string((int)$3);                        
                                $$=strdup(tmp.c_str());
                                
                        }
        | METLV '_' index {       tmp="metlv_"+to_string((int)$3);                        
                                $$=strdup(tmp.c_str());
                                
                        }
        | ID { 
                map<string, string>::iterator it ;
                it = vars.find($1);
     
                if(it == vars.end()) {
                        cout <<$1<<" : " ;
                        yyerror("Variable not defined");
                        YYERROR;//stops parsing
                        
                }
                else {tmp= it->second ;
                $$=strdup(tmp.c_str());}

                }
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
//we should also match integers in here INT and check which one is detected first NB or INT
%%
int main(void) {
        yyparse(); 
        cout<<"\n results: \n";
	std::map<std::string, string>::iterator it = vars.begin();
        while(it != vars.end())
        {
                std::cout<<it->first<<" :: "<<it->second<<std::endl;
                it++;
        }
	//std::cout <<"Main Result: " <<result << std::endl;
			
                }
