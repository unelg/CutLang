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
map<string,string> parts;
%}
%union {
	double real;
	char* s;
}
%token DEF
%token CMD
%token ELE MUO LEP PHO JET BJET QGJET NUMET METLV //particle types
%token PHI ETA ABSETA PT PZ NBF DR DPHI //functions
%token NELE NMUO NLEP NPHO NJET NBJET NQGJET HT METMWT MWT MET ALL LEPSF FILLHISTOS //simple funcs
%token <real> NB
%token <s> ID 
%token SIN COS TAN
%token <real> INT
//TO ADD IN LEX see course
// %token OR AND NOT
// %token LT GT LE GE EQ NEQ
// %left OR
// %left AND
// %right NOT
// %nonassoc LT GT LE GE EQ NEQ
%left '+' '-'
%left '*' '/'
%right Unary
%right '^'
%type <real> index
%type <s> particule particules list function e
%%
input : definitions commands 
     ;
definitions : definitions definition 
            | 
            ;
definition : DEF ID ':' particules {
                                        pnum=0;
                                        map<string, string>::iterator it ;
                                        string name = $2;
                                        it = parts.find(name);
                        
                                        if(it != parts.end()) {
                                                cout <<name<<" : " ;
                                                yyerror("Particule already defined");
                                                YYERROR;//stops parsing if variable already defined
                                                
                                        }
                                         
                                         string phrase= $4;
                                         parts.insert(make_pair(name,phrase));
                                         cout<<"\ndef "<<$2<<":"<<$4<<endl;
                                         
				}
            | DEF ID ':' e {
                                        pnum=0;
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
                                         cout<<"\ndef "<<$2<<":"<<$4<<endl;
                                         
				}
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
         | list DR {     
                                        
                                        string s=$1;                                       
                                        s=s+"dR";                        
                                        $$=strdup(s.c_str());
                                }
        | list DPHI {    
                                        
                                        string s=$1;                                       
                                        s=s+"dPhi";                        
                                        $$=strdup(s.c_str());
                                }
        ;
list : '{' particules { pnum=0; } ',' particules '}' { 
                                                        string s=$2;
                                                        string s2=$5;
                                                        s="{ "+s+" , "+s2+" }";                        
                                                        $$=strdup(s.c_str());

                                                        }
     ;
particules : particules particule {                                                 
                                                char s [512];
                                                strcpy(s,$$); 
                                                strcat(s," ");
                                                strcat(s,$2);
                                                strcpy($$,s);                                       

                                        }
            | particule {if (pnum==0){
                                                $$=strdup($1);
                                                pnum++;                                                
                                        }
                                        else{                                                
                                                char s [512];
                                                strcpy(s,$$); 
                                                strcat(s," ");
                                                strcat(s,$1);
                                                strcpy($$,s);
                                        }}
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
        | ID { //we want the original defintions as well
                map<string, string>::iterator it ;
                it = parts.find($1);
     
                if(it == parts.end()) {
                        cout <<$1<<" : " ;
                        yyerror("Particule not defined");
                        YYERROR;//stops parsing if variable not found
                        
                }
                else {
                        tmp= it->second ;
                        $$=strdup(tmp.c_str());
                }

               }
        ;
index : '-' INT {$$=-$2;}
      | INT {$$= $1;}
      ; 
commands : commands command 
        | 
        ;
command : CMD {;} //to continue
	;
e : e '+' e  { string s1=$1; string s3=$3;
               tmp=s1+" + "+s3;   
               $$=strdup(tmp.c_str()); 
               }
   | e '-' e { string s1=$1; string s3=$3;
               tmp=s1+" - "+s3;   
               $$=strdup(tmp.c_str()); 
               }
   | e '*' e { string s1=$1; string s3=$3;
               tmp=s1+" * "+s3;   
               $$=strdup(tmp.c_str()); 
               }
   | e '/' e { string s1=$1; string s3=$3;
               tmp=s1+" / "+s3;   
               $$=strdup(tmp.c_str()); 
               }
   | e '^' e { string s1=$1; string s3=$3;
               tmp=s1+" ^ "+s3;   
               $$=strdup(tmp.c_str()); 
               } 	
   |'-' e %prec Unary { string s1=$2;
               tmp=" -"+s1;   
               $$=strdup(tmp.c_str()); 
               }
   | COS '(' e ')' { string s3=$3;
               tmp=" cos( "+s3+" ) ";   
               $$=strdup(tmp.c_str()); 
               }
   | SIN '(' e ')' { string s3=$3;
               tmp=" sin( "+s3+" ) ";   
               $$=strdup(tmp.c_str()); 
               }
   | TAN '(' e ')' { string s3=$3;
               tmp=" tan( "+s3+" ) ";   
               $$=strdup(tmp.c_str()); 
               }
   |'(' e ')' { string s3=$2;
               tmp=" ( "+s3+" ) ";   
               $$=strdup(tmp.c_str()); 
               }
   | NB { tmp=to_string($1); $$=strdup(tmp.c_str()); } 
   | INT { tmp=to_string((int)$1); $$=strdup(tmp.c_str()); } 
   | function {$$=$1; pnum=0;}
   // !!!!!!!!make the difference between ID + ID and ID ID in particules!!!!!!!!!!!->create two maps
   | ID { //we want the original defintions as well
                map<string, string>::iterator it ;
                it = vars.find($1);
     
                if(it == vars.end()) {
                        cout <<$1<<" : " ;
                        yyerror("Variable not defined");
                        YYERROR;//stops parsing if variable not found
                        
                }
                else {
                        tmp= it->second ;
                        $$=strdup(tmp.c_str());
                }
               }
   ;
%%
int main(void) {
        yyparse(); 
        cout<<"\n Variables results: \n";
	std::map<std::string, string>::iterator it = vars.begin();
        while(it != vars.end())
        {
                std::cout<<it->first<<" :: "<<it->second<<std::endl;
                it++;
        }
        cout<<"\n Particles results: \n";
	 it = parts.begin();
        while(it != parts.end())
        {
                std::cout<<it->first<<" :: "<<it->second<<std::endl;
                it++;
        }
			
                }


                //calculator
// e : e '+' e  { $$ = $1 + $3 ;string s=$2;
//                                         tmp="{ "+s+" }m";                        
//                                         $$=strdup(tmp.c_str()); }
//    | e '-' e { $$ = $1 - $3 ; }
//    | e '*' e { $$ = $1 * $3 ; }
//    | e '/' e { $$ = $1 / $3*1.0 ; }
//    | e '^' e { $$ = pow($1,$3) ;  } 	
//    |'-' e %prec Unary { $$ = - $2 ; }
//    | COS '(' e ')' { $$ = cos($3) ;}
//    | SIN '(' e ')' { $$ = sin($3) ;}
//    | TAN '(' e ')' { $$ = tan($3) ;}
//    |'(' e ')' { $$ = $2 ;}
//    | NB { $$ = $1 ;} 
//    | INT { $$ = $1 ;}	
//    | function 
//    ;
