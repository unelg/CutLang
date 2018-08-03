%{ 
#include "NodeTree.h"
#include <math.h>
#include "stdlib.h"
#include <iostream>
#include <string>
#include <map>
#include <list>
#include <vector>
#include <iterator>
extern int yylex();
extern int yyparse();
void yyerror(const char *s) { std::cout << s << std::endl; } 
int cutcount;
using namespace std;
string tmp;
int pnum;
map<string,string> vars;
list<string> parts; //for def of particles as given by user
map<string,vector<myParticle> > ListParts;//for particle definition
vector<myParticle> TmpParticle;
vector<myParticle> TmpParticle1;//to be used for list of 2 particles
map<int,string> cuts;
%}
%union {
        Node* node;
	double real;
	char* s;//ADD POINTER TO NODE unique_ptr?
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
%token OR AND 
%token LT GT LE GE EQ NE IRG ERG
%left OR
%left AND
%nonassoc LT GT LE GE EQ NE IRG ERG
%left '+' '-'
%left '*' '/'
%right Unary
%right '^'
%type <real> index
%type <s> particule particules list function e condition action ifstatement
%%
input : definitions commands 
     ;
definitions : definitions definition 
            | 
            ;
definition : DEF  ID  ':' particules {

                                        pnum=0;
                                        map<string,vector<myParticle> >::iterator it ;
                                        string name = $2;
                                        it = ListParts.find(name);
                        
                                        if(it != ListParts.end()) {
                                                cout <<name<<" : " ;
                                                yyerror("Particule already defined");
                                                YYERROR;//stops parsing if variable already defined
                                                
                                        }
                                        
                                        parts.push_back(name+" : "+$4);
                                        //List part 
                                        
                                                std::cout<<"\n TMP List: \n";
                                                vector<myParticle>::iterator myiterator;
                                                myiterator = TmpParticle.begin();
                                                while (myiterator != TmpParticle.end()) {
                                                std::cout << "type: " << myiterator->type << " index: " << myiterator->index << endl;
                                                myiterator++;
                                                }
                                        
                                        vector<myParticle> newList;
                                        TmpParticle.swap(newList);
                                        ListParts.insert(make_pair(name,newList));
                                                                                
				}
            |  DEF ID  ':' e {//create node and insert it in map string->node
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
                                         
				}
        ;
function : '{' particules '}' 'm' {     //have to empty list in here and ready to create the node
                                        string s=$2;
                                        tmp="{ "+s+" }m";                        
                                        $$=strdup(tmp.c_str());
                                        std::cout<<"\n M List: \n";
                                                vector<myParticle>::iterator myiterator;
                                                myiterator = TmpParticle.begin();
                                                while (myiterator != TmpParticle.end()) {
                                                std::cout << "type: " << myiterator->type << " index: " << myiterator->index << endl;
                                                myiterator++;
                                                }
                                        vector<myParticle> newList;
                                        TmpParticle.swap(newList);
                                        //then add newList to node

                                }
         | '{' particules '}' 'q' {     
                                        string s=$2;
                                        tmp="{ "+s+" }q";                        
                                        $$=strdup(tmp.c_str());
                                        std::cout<<"\n Q List: \n";
                                                vector<myParticle>::iterator myiterator;
                                                myiterator = TmpParticle.begin();
                                                while (myiterator != TmpParticle.end()) {
                                                std::cout << "type: " << myiterator->type << " index: " << myiterator->index << endl;
                                                myiterator++;
                                                }
                                        vector<myParticle> newList;
                                        TmpParticle.swap(newList);//then add newList to node

                                }
         | '{' particules '}' 'P' {     
                                        string s=$2;
                                        tmp="{ "+s+" }P";                        
                                        $$=strdup(tmp.c_str());

                                        vector<myParticle> newList;
                                        TmpParticle.swap(newList);//then add newList to node

                                }
         | '{' particules '}' 'E' {     
                                        string s=$2;
                                        tmp="{ "+s+" }E";                        
                                        $$=strdup(tmp.c_str());

                                        vector<myParticle> newList;
                                        TmpParticle.swap(newList);//then add newList to node
                                }
         | '{' particules '}' PHI {     
                                        string s=$2;
                                        tmp="{ "+s+" }Phi";                        
                                        $$=strdup(tmp.c_str());

                                        vector<myParticle> newList;
                                        TmpParticle.swap(newList);//then add newList to node
                                }
         | '{' particules '}' ETA {     
                                        string s=$2;
                                        tmp="{ "+s+" }Eta";                        
                                        $$=strdup(tmp.c_str());

                                        vector<myParticle> newList;
                                        TmpParticle.swap(newList);//then add newList to node
                                }
         | '{' particules '}' ABSETA {     
                                        string s=$2;
                                        tmp="{ "+s+" }AbsEta";                        
                                        $$=strdup(tmp.c_str());

                                        vector<myParticle> newList;
                                        TmpParticle.swap(newList);//then add newList to node
                                }
         | '{' particules '}' PT {     
                                        string s=$2;
                                        tmp="{ "+s+" }Pt";                        
                                        $$=strdup(tmp.c_str());

                                        vector<myParticle> newList;
                                        TmpParticle.swap(newList);//then add newList to node
                                }
         | '{' particules '}' PZ {     
                                        string s=$2;
                                        tmp="{ "+s+" }Pz";                        
                                        $$=strdup(tmp.c_str());

                                        vector<myParticle> newList;
                                        TmpParticle.swap(newList);//then add newList to node
                                }
         | '{' particules '}' NBF {     
                                        string s=$2;
                                        tmp="{ "+s+" }ndf";                        
                                        $$=strdup(tmp.c_str());

                                        vector<myParticle> newList;
                                        TmpParticle.swap(newList);//then add newList to node
                                }
         | list DR {     //create Node with TmpParticle1,TmpParticle
                                        
                                        string s=$1;                                       
                                        s=s+"dR";                        
                                        $$=strdup(s.c_str());
                                        std::cout<<"\n DR TMP1 List: \n";
                                                vector<myParticle>::iterator myiterator;
                                                myiterator = TmpParticle1.begin();
                                                while (myiterator != TmpParticle1.end()) {
                                                std::cout << "type: " << myiterator->type << " index: " << myiterator->index << endl;
                                                myiterator++;
                                                }
                                                std::cout<<"\n DR TMP List: \n";
                                                
                                                myiterator = TmpParticle.begin();
                                                while (myiterator != TmpParticle.end()) {
                                                std::cout << "type: " << myiterator->type << " index: " << myiterator->index << endl;
                                                myiterator++;
                                                }
                                        
                                        vector<myParticle> newList;
                                        TmpParticle.swap(newList);
                                        vector<myParticle> newList1;
                                        TmpParticle1.swap(newList1);
                                }
        | list DPHI {    //create Node with newlist1,newlist
                                        
                                        string s=$1;                                       
                                        s=s+"dPhi";                        
                                        $$=strdup(s.c_str());

                                        std::cout<<"\n Dphi TMP1 List: \n";
                                                vector<myParticle>::iterator myiterator;
                                                myiterator = TmpParticle1.begin();
                                                while (myiterator != TmpParticle1.end()) {
                                                std::cout << "type: " << myiterator->type << " index: " << myiterator->index << endl;
                                                myiterator++;
                                                }
                                                std::cout<<"\n Dphi TMP List: \n";
                                                
                                                myiterator = TmpParticle.begin();
                                                while (myiterator != TmpParticle.end()) {
                                                std::cout << "type: " << myiterator->type << " index: " << myiterator->index << endl;
                                                myiterator++;
                                                }

                                                vector<myParticle> newList;
                                                TmpParticle.swap(newList);
                                                vector<myParticle> newList1;
                                                TmpParticle1.swap(newList1);
                                }
        | NELE {    
                                        
                                        string s="NELE";                                                              
                                        $$=strdup(s.c_str());
                                }
        | NMUO {    
                                        
                                        string s="NMUO";                                                              
                                        $$=strdup(s.c_str());
                                }
        | NLEP {    
                                        
                                        string s="NLEP";                                                              
                                        $$=strdup(s.c_str());
                                }                        
        | NPHO {    
                                        
                                        string s="NPHO";                                                              
                                        $$=strdup(s.c_str());
                                }
        | NJET {    
                                        
                                        string s="NJET";                                                              
                                        $$=strdup(s.c_str());
                                }
        | NBJET {    
                                        
                                        string s="NBJET";                                                              
                                        $$=strdup(s.c_str());
                                }
        | NQGJET {    
                                        
                                        string s="NQGJET";                                                              
                                        $$=strdup(s.c_str());
                                }
        | HT {    
                                        
                                        string s="HT";                                                              
                                        $$=strdup(s.c_str());
                                }
        | METMWT {    
                                        
                                        string s="METMWT";                                                              
                                        $$=strdup(s.c_str());
                                }
        | MWT {    
                                        
                                        string s="MWT";                                                              
                                        $$=strdup(s.c_str());
                                }
        | MET {    
                                        
                                        string s="MET";                                                              
                                        $$=strdup(s.c_str());
                                }
        | ALL {    
                                        
                                        string s="ALL";                                                              
                                        $$=strdup(s.c_str());
                                }
        | LEPSF {    
                                        
                                        string s="LEPSF";                                                              
                                        $$=strdup(s.c_str());
                                }
        ;
list : '{' particules { pnum=0; TmpParticle.swap(TmpParticle1); } ',' particules '}' { 
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
                                        }
                                        else{                                                
                                                char s [512];
                                                strcpy(s,$$); 
                                                strcat(s," ");
                                                strcat(s,$1);
                                                strcpy($$,s);
                                        }
                                        pnum++;}
            ;
particule : ELE '_' index {
                                myParticle a;
                                a.type = "ELE";
                                a.index = (int)$3;
                                TmpParticle.push_back(a);                            
                                tmp="ele_"+to_string((int)$3);                        
                                $$=strdup(tmp.c_str());
                                                        
                            }
        | MUO '_' index {       tmp="muo_"+to_string((int)$3);                        
                                $$=strdup(tmp.c_str());
                                myParticle a;
                                a.type = "MUO";
                                a.index = (int)$3;
                                TmpParticle.push_back(a);  
                                
                        }
        | LEP '_' index {       tmp="lep_"+to_string((int)$3);                        
                                $$=strdup(tmp.c_str());
                                myParticle a;
                                a.type = "LEP";
                                a.index = (int)$3;
                                TmpParticle.push_back(a);  
                                
                        }
        | PHO '_' index {       tmp="pho_"+to_string((int)$3);                        
                                $$=strdup(tmp.c_str());
                                myParticle a;
                                a.type = "PHO";
                                a.index = (int)$3;
                                TmpParticle.push_back(a);  
                                
                        }
        | JET '_' index {       tmp="jet_"+to_string((int)$3);                        
                                $$=strdup(tmp.c_str());
                                myParticle a;
                                a.type = "JET";
                                a.index = (int)$3;
                                TmpParticle.push_back(a);  
                                
                        }
        | BJET '_' index {      tmp="bjet_"+to_string((int)$3);                        
                                $$=strdup(tmp.c_str());
                                myParticle a;
                                a.type = "BJET";
                                a.index = (int)$3;
                                TmpParticle.push_back(a);  
                                
                        }
        | QGJET '_' index {      tmp="qgjet_"+to_string((int)$3);                        
                                $$=strdup(tmp.c_str());
                                myParticle a;
                                a.type = "QGJET";
                                a.index = (int)$3;
                                TmpParticle.push_back(a);  
                                
                        }
        | NUMET '_' index {       tmp="numet_"+to_string((int)$3);                        
                                $$=strdup(tmp.c_str());
                                myParticle a;
                                a.type = "NUMET";
                                a.index = (int)$3;
                                TmpParticle.push_back(a);  
                                
                        }
        | METLV '_' index {     tmp="metlv_"+to_string((int)$3);                        
                                $$=strdup(tmp.c_str());
                                myParticle a;
                                a.type = "METLV";
                                a.index = (int)$3;
                                TmpParticle.push_back(a);  
                                
                        }
        | ID { //we want the original defintions as well -> put it in parts and put the rest in vectorParts
                
                map<string,vector<myParticle> >::iterator it;
                it = ListParts.find($1);
     
                if(it == ListParts.end()) {
                        cout <<$1<<" : " ;
                        yyerror("Particule not defined");
                        YYERROR;//stops parsing if particle not found
                        
                }
                else {
                        vector<myParticle> newList= it->second;
                        TmpParticle.insert(TmpParticle.end(), newList.begin(), newList.end());
                        $$=$1;
                }

               }
        ;
index : '-' INT {$$=-$2;}
      | INT {$$= $1;}
      ; 
commands : commands command 
        | 
        ;
command : CMD condition {                                         
                                         string phrase= $2;
                                         cuts.insert(make_pair(cutcount++,phrase));
    
				}
        | CMD ALL {                                         
                                         string phrase= " all ";
                                         cuts.insert(make_pair(cutcount++,phrase));
    
				}
        | CMD ifstatement {                                         
                                         string phrase= $2;
                                         cuts.insert(make_pair(cutcount++,phrase));
    
				}
	;
ifstatement : condition '?' action ':' action { string s1=$1; string s3=$3;string s4=$5;
                        tmp=s1+" ? "+s3+" : "+s4;   
                        $$=strdup(tmp.c_str()); 
                        } 
            ;
action : condition {$$=$1;}
       | ALL {tmp= " all " ;$$=strdup(tmp.c_str());}
       | ifstatement {$$=$1;}
       ;    
condition : e LT e  { string s1=$1; string s3=$3; 
                        tmp=s1+" < "+s3;   
                        $$=strdup(tmp.c_str()); 
                        }
           | e GT e { string s1=$1; string s3=$3;
                        tmp=s1+" > "+s3;   
                        $$=strdup(tmp.c_str()); 
                        }
           | e LE e { string s1=$1; string s3=$3;
                        tmp=s1+" <= "+s3;   
                        $$=strdup(tmp.c_str()); 
                        }  
           | e GE e  { string s1=$1; string s3=$3;
                        tmp=s1+" >= "+s3;   
                        $$=strdup(tmp.c_str()); 
                        }
           | e EQ e { string s1=$1; string s3=$3;
                        tmp=s1+" == "+s3;   
                        $$=strdup(tmp.c_str()); 
                        }
           | e NE e { string s1=$1; string s3=$3;
                        tmp=s1+" != "+s3;   
                        $$=strdup(tmp.c_str()); 
                        }  
           | e IRG NB NB { string s1=$1; string s3=to_string($3);string s4=to_string($4);//combine 2 nodes
                        tmp=s1+" [] "+s3+" "+s4;   
                        $$=strdup(tmp.c_str()); 
                        }  
           | e ERG NB NB { string s1=$1; string s3=to_string($3);string s4=to_string($4);//combine 2 nodes
                        tmp=s1+" ][ "+s3+" "+s4; 
                        $$=strdup(tmp.c_str()); 
                        }                            
           | condition AND condition { string s1=$1; string s3=$3;
                        tmp=s1+" and "+s3;   
                        $$=strdup(tmp.c_str()); 
                        } 
           | condition OR condition { string s1=$1; string s3=$3;
                        tmp=s1+" or "+s3;   
                        $$=strdup(tmp.c_str()); 
                        } 
           | '(' condition ')' { string s3=$2;
                                tmp=" ( "+s3+" ) ";   
                                $$=strdup(tmp.c_str()); 
                                } 
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
   //to make the difference between ID + ID and ID ID in particules ->create two maps
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
                //get the node from variable map
               }
   ;
%%
int main(void) {
        yyparse(); 

cout<<"\n Particle Lists: \n";
        
        for (map<string,vector<myParticle> >::iterator it1 = ListParts.begin(); it1 != ListParts.end(); it1++)
                {
                cout << it1->first << ": ";
                for (vector<myParticle>::iterator lit = it1->second.begin(); lit  != it1->second.end(); lit++)
                cout << lit->type << "_" << lit->index << " ";
                cout << "\n";
                }
                
        
        cout<<"\n Particles defintions as given by user: \n";
	 
        std::list<std::string>::iterator it = parts.begin();
        while(it != parts.end())
        {
                std::cout<<(*it)<<std::endl;
                it++;
        }

        cout<<"\n Variables results: \n";
	map<string,string >::iterator itv = vars.begin();
        while(itv != vars.end())
        {
                std::cout<<itv->first<<" :: "<<itv->second<<std::endl;
                itv++;
        }

	cout<<"\n CUTS : \n";
	std::map<int, string>::iterator iter = cuts.begin();
        while(iter != cuts.end())
        {
                cout<<iter->first<<" :: "<<iter->second<<endl;
                iter++;
        }		
                }


                // simple calculator
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
