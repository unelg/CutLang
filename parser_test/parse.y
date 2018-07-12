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
%token <s> VARDEF
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
%token PHI
%token ETA
%token ABSETA
%token PT
%token PZ
%token NBF
%token DR
%token DPHI
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
%type <s> function
//%type <s> secondHalf
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
                                                YYERROR;//stops parsing if variable already defined
                                                
                                        }
                                         
                                         string phrase= $4;
                                         vars.insert(make_pair(name,phrase));
                                         cout<<"\nend "<<$4<<endl;
                                         
				}
           ;
vardef : particules {pnum=0;}
       | function { pnum=0;}
       ;
function : '{' particules '}' 'm' {     
                                        string s=$2;
                                        tmp="{ "+s+" }m";                        
                                        $$=strdup(tmp.c_str());

                                }
         | '{' particules '}' 'q' {     
                                        string s=$2;
                                        tmp="{ "+s+" }q";                        
                                        $$=strdup(tmp.c_str());

                                }
         | '{' particules '}' 'P' {     
                                        string s=$2;
                                        tmp="{ "+s+" }P";                        
                                        $$=strdup(tmp.c_str());

                                }
         | '{' particules '}' 'E' {     
                                        string s=$2;
                                        tmp="{ "+s+" }E";                        
                                        $$=strdup(tmp.c_str());

                                }
         | '{' particules '}' PHI {     
                                        string s=$2;
                                        tmp="{ "+s+" }Phi";                        
                                        $$=strdup(tmp.c_str());

                                }
         | '{' particules '}' ETA {     
                                        string s=$2;
                                        tmp="{ "+s+" }Eta";                        
                                        $$=strdup(tmp.c_str());

                                }
         | '{' particules '}' ABSETA {     
                                        string s=$2;
                                        tmp="{ "+s+" }AbsEta";                        
                                        $$=strdup(tmp.c_str());

                                }
         | '{' particules '}' PT {     
                                        string s=$2;
                                        tmp="{ "+s+" }Pt";                        
                                        $$=strdup(tmp.c_str());

                                }
         | '{' particules '}' PZ {     
                                        string s=$2;
                                        tmp="{ "+s+" }Pz";                        
                                        $$=strdup(tmp.c_str());

                                }
         | '{' particules '}' NBF {     
                                        string s=$2;
                                        tmp="{ "+s+" }ndf";                        
                                        $$=strdup(tmp.c_str());

                                }
         | '{' particules ',' particules '}' DR {    //needs debugging 
                                        pnum=0;
                                        string s=$2;
                                        string s2=$4;
                                        s="{ "+s+" , "+s2+" }dR";                        
                                        $$=strdup(s.c_str());
                                        cout<<" hey : "<<s2<<endl;

                                }
        | '{' particules ',' particules '}' DPHI {     
                                        pnum=0;
                                        string s=$2;
                                        string s2=$4;
                                        s="{ "+s+" , "+s2+" }dPhi";                        
                                        $$=strdup(s.c_str());
                                        cout<<" hey : "<<s2<<endl;

                                }
        ;
particules : particules particule { 
        
                                        if (pnum==0){
                                                
                                                $$=strdup($2);
                                                pnum++;
                                                //cout<<" p0 : "<<$$<<endl;
                                        }
                                        else{
                                                
                                                char s [512];
                                                strcpy(s,$$); 
                                                strcat(s," ");
                                                strcat(s,$2);
                                                strcpy($$,s);

                                        }
                                        //cout<<" p : "<<$$<<endl;
                                        //free($2); MEMORY LEAK?

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
        | ID { //needs testing
                map<string, string>::iterator it ;
                it = vars.find($1);
     
                if(it == vars.end()) {
                        cout <<$1<<" : " ;
                        yyerror("Variable not defined");
                        YYERROR;//stops parsing if variable not found
                        
                }
                else {
                        tmp= it->second ;
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
