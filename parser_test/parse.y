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
void yyerror(list<string> *parts,map<string,Node*>* NodeVars,map<string,vector<myParticle> >* ListParts,
                map<int,Node*>* NodeCuts,
                vector<double>* Initializations , vector<double>* DataFormats
                ,const char *s) { std::cout << s << std::endl; } 
int cutcount;
using namespace std;
string tmp;
int pnum;
int dnum;
vector<myParticle> TmpParticle;
vector<myParticle> TmpParticle1;//to be used for list of 2 particles

//modify types to ints in myParticle => codes?
//see how to give input to yyparse and get output -> DONE
//read file -> DONE
//avoid global variables -> DONE
//add histos -> DONE
//view input
%}
%union {
        Node* node;
	double real;
	char* s;//ADD POINTER TO NODE unique_ptr?
}
%parse-param {list<string> *parts} 
%parse-param {map<string,Node*>* NodeVars} 
%parse-param {map<string,vector<myParticle> >* ListParts} 
%parse-param {map<int,Node*>* NodeCuts}
%parse-param {vector<double>* Initializations}
%parse-param {vector<double>* DataFormats}
%token DEF CMD HISTO OBJ ALGO
%token ELE MUO LEP PHO JET BJET QGJET NUMET METLV //particle types
%token MINPTM MINPTG MINPTJ MINPTE MAXETAM MAXETAE MAXETAG MAXETAJ MAXMET TRGE TRGM
%token LVLO ATLASOD CMSOD DELPHES FCC LHCO
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
%type <node> e function condition action ifstatement
%type <s> particule particules list description
%%
input : initializations definitions objects commands 
     ;
initializations : initializations initialization 
        | 
        ;
initialization : MINPTE '=' NB {Initializations->at(0)=$3;}
                | MINPTM '=' NB {Initializations->at(1)=$3;}
                | MINPTJ '=' NB {Initializations->at(2)=$3;}
                | MINPTG '=' NB {Initializations->at(3)=$3;}
                | MAXETAE '=' NB {Initializations->at(4)=$3;}
                | MAXETAM '=' NB {Initializations->at(5)=$3;}
                | MAXETAJ '=' NB {Initializations->at(6)=$3;}
                | MAXETAG '=' NB {Initializations->at(7)=$3;}
                | MAXMET '=' NB {Initializations->at(8)=$3;}
                | TRGE  '=' INT {Initializations->at(9)=$3;}
                | TRGM  '=' INT {Initializations->at(10)=$3;}
                | LVLO '=' NB  {DataFormats->at(0)=$3;}
                | ATLASOD '=' NB {DataFormats->at(1)=$3;}
                | CMSOD '=' NB {DataFormats->at(2)=$3;}
                | DELPHES '=' NB {DataFormats->at(3)=$3;}
                | FCC '=' NB {DataFormats->at(4)=$3;}
                | LHCO '=' NB {DataFormats->at(5)=$3;}
                ;
definitions : definitions definition 
            | 
            ;
definition : DEF  ID  ':' particules {

                                        pnum=0;
                                        map<string,vector<myParticle> >::iterator it ;
                                        string name = $2;
                                        it = ListParts->find(name);
                        
                                        if(it != ListParts->end()) {
                                                cout <<name<<" : " ;
                                                yyerror(NULL,NULL,NULL,NULL,NULL,NULL,"Particule already defined");
                                                YYERROR;//stops parsing if variable already defined
                                                
                                        }
                                        
                                        parts->push_back(name+" : "+$4);
                                        
                                        
                                                // std::cout<<"\n TMP List: \n";
                                                // vector<myParticle>::iterator myiterator;
                                                // myiterator = TmpParticle.begin();
                                                // while (myiterator != TmpParticle.end()) {
                                                // std::cout << "type: " << myiterator->type << " index: " << myiterator->index << endl;
                                                // myiterator++;
                                                // }
                                        
                                        vector<myParticle> newList;
                                        TmpParticle.swap(newList);
                                        ListParts->insert(make_pair(name,newList));
                                                                                
				}
            |  DEF ID  ':' e {
                                        pnum=0;
                                         map<string, Node*>::iterator it ;
                                         string name = $2;
                                         it = NodeVars->find(name);
                        
                                        if(it != NodeVars->end()) {
                                                cout <<name<<" : " ;
                                                yyerror(NULL,NULL,NULL,NULL,NULL,NULL,"Variable already defined");
                                                YYERROR;//stops parsing if variable already defined
                                                
                                        }
                                        NodeVars->insert(make_pair(name,$4));
				}
        ;
objects : objectBlocs ALGO
        | 
        ;
objectBlocs : objectBlocs objectBloc
            | objectBloc
            ;
objectBloc : OBJ ID ':' ID criteria
           | OBJ ID ':' ELE criteria
           | OBJ ID ':' MUO criteria
           | OBJ ID ':' LEP criteria
           | OBJ ID ':' PHO criteria
           | OBJ ID ':' JET criteria
           | OBJ ID ':' BJET criteria
           | OBJ ID ':' QGJET criteria
           | OBJ ID ':' NUMET criteria
           | OBJ ID ':' METLV criteria     
           ;
criteria : criteria criterion
         | criterion
         ;
criterion : CMD condition {cout<<"CRITERION!!!!!!!!!!!!\n";
                                $2->display();}
        ;           
function : '{' particules '}' 'm' {     
                                        string s=$2;
                                        tmp="{ "+s+" }m";                        
                                        //$$=strdup(tmp.c_str());
                                        // std::cout<<"\n M List: \n";
                                        //         vector<myParticle>::iterator myiterator;
                                        //         myiterator = TmpParticle.begin();
                                        //         while (myiterator != TmpParticle.end()) {
                                        //         std::cout << "type: " << myiterator->type << " index: " << myiterator->index << endl;
                                        //         myiterator++;
                                        //         }
                                        vector<myParticle> newList;
                                        TmpParticle.swap(newList);
                                        $$=new FuncNode(MASS,newList,"m");

                                }
         | '{' particules '}' 'q' {     
                                        string s=$2;
                                        tmp="{ "+s+" }q";                        
                                        vector<myParticle> newList;
                                        TmpParticle.swap(newList);//then add newList to node
                                        $$=new FuncNode(MASS,newList,"q");
                                }
         | '{' particules '}' 'P' {     
                                        vector<myParticle> newList;
                                        TmpParticle.swap(newList);
                                        $$=new FuncNode(MASS,newList,"p");
                                }
         | '{' particules '}' 'E' {     
                                        vector<myParticle> newList;
                                        TmpParticle.swap(newList);
                                        $$=new FuncNode(MASS,newList,"e");
                                }
         | '{' particules '}' PHI {     
                                        vector<myParticle> newList;
                                        TmpParticle.swap(newList);
                                        $$=new FuncNode(MASS,newList,"phi");
                                }
         | '{' particules '}' ETA {     
                                        vector<myParticle> newList;
                                        TmpParticle.swap(newList);
                                        $$=new FuncNode(MASS,newList,"eta");
                                }
         | '{' particules '}' ABSETA {     
                                        vector<myParticle> newList;
                                        TmpParticle.swap(newList);
                                        $$=new FuncNode(MASS,newList,"abseta");
                                }
         | '{' particules '}' PT {     
                                        vector<myParticle> newList;
                                        TmpParticle.swap(newList);
                                        $$=new FuncNode(MASS,newList,"pt");
                                }
         | '{' particules '}' PZ {     
                                        vector<myParticle> newList;
                                        TmpParticle.swap(newList);
                                        $$=new FuncNode(MASS,newList,"pz");
                                }
         | '{' particules '}' NBF {     
                                        vector<myParticle> newList;
                                        TmpParticle.swap(newList);
                                        $$=new FuncNode(MASS,newList,"nbf");
                                }
         | list DR { 

                                        vector<myParticle> newList;
                                        TmpParticle.swap(newList);
                                        vector<myParticle> newList1;
                                        TmpParticle1.swap(newList1);
                                        $$=new LFuncNode(dR,newList1,newList,"dR");
                                }
        | list DPHI { 
                                                vector<myParticle> newList;
                                                TmpParticle.swap(newList);
                                                vector<myParticle> newList1;
                                                TmpParticle1.swap(newList1);
                                                $$=new LFuncNode(dR,newList1,newList,"dphi");

                                }
        | NELE {                                            
                                        string s="NELE";                                                              
                                        $$=new SFuncNode(all,s);
                                }
        | NMUO {    
                                        
                                        string s="NMUO";                                                              
                                        $$=new SFuncNode(all,s);
                                }
        | NLEP {    
                                        
                                        string s="NLEP";                                                              
                                        $$=new SFuncNode(all,s);
                                }                        
        | NPHO {    
                                        
                                        string s="NPHO";                                                              
                                        $$=new SFuncNode(all,s);
                                }
        | NJET {                                           
                                        string s="NJET";                                                              
                                        $$=new SFuncNode(all,s);
                                }
        | NBJET {                                            
                                        string s="NBJET";                                                              
                                        $$=new SFuncNode(all,s);
                                }
        | NQGJET {    
                                        
                                        string s="NQGJET";                                                              
                                        $$=new SFuncNode(all,s);
                                }
        | HT {    
                                        
                                        string s="HT";                                                              
                                        $$=new SFuncNode(all,s);
                                }
        | METMWT {    
                                        
                                        string s="METMWT";                                                              
                                        $$=new SFuncNode(all,s);
                                }
        | MWT {    
                                        
                                        string s="MWT";                                                              
                                        $$=new SFuncNode(all,s);
                                }
        | MET {    
                                        
                                        string s="MET";                                                              
                                        $$=new SFuncNode(all,s);
                                }
        | ALL {    
                                        
                                        $$=new SFuncNode(all,"all");

                                }
        | LEPSF {    
                                        
                                        string s="LEPSF";                                                              
                                        $$=new SFuncNode(all,s);
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
                                a.type = 1;
                                a.index = (int)$3;
                                TmpParticle.push_back(a);                            
                                tmp="ele_"+to_string((int)$3);                        
                                $$=strdup(tmp.c_str());
                                                        
                            }
        | MUO '_' index {       tmp="muo_"+to_string((int)$3);                        
                                $$=strdup(tmp.c_str());
                                myParticle a;
                                a.type = 0;
                                a.index = (int)$3;
                                TmpParticle.push_back(a);  
                                
                        }
        | LEP '_' index {       tmp="lep_"+to_string((int)$3);                        
                                $$=strdup(tmp.c_str());
                                myParticle a;
                                a.type = 9;
                                a.index = (int)$3;
                                TmpParticle.push_back(a);  
                                
                        }
        | PHO '_' index {       tmp="pho_"+to_string((int)$3);                        
                                $$=strdup(tmp.c_str());
                                myParticle a;
                                a.type = 8;
                                a.index = (int)$3;
                                TmpParticle.push_back(a);  
                                
                        }
        | JET '_' index {       tmp="jet_"+to_string((int)$3);                        
                                $$=strdup(tmp.c_str());
                                myParticle a;
                                a.type = 2;
                                a.index = (int)$3;
                                TmpParticle.push_back(a);  
                                
                        }
        | BJET '_' index {      tmp="bjet_"+to_string((int)$3);                        
                                $$=strdup(tmp.c_str());
                                myParticle a;
                                a.type = 3;
                                a.index = (int)$3;
                                TmpParticle.push_back(a);  
                                
                        }
        | QGJET '_' index {      tmp="qgjet_"+to_string((int)$3);                        
                                $$=strdup(tmp.c_str());
                                myParticle a;
                                a.type = 4;
                                a.index = (int)$3;
                                TmpParticle.push_back(a);  
                                
                        }
        | NUMET '_' index {       tmp="numet_"+to_string((int)$3);                        
                                $$=strdup(tmp.c_str());
                                myParticle a;
                                a.type = 5;
                                a.index = (int)$3;
                                TmpParticle.push_back(a);  
                                
                        }
        | METLV '_' index {     tmp="metlv_"+to_string((int)$3);                        
                                $$=strdup(tmp.c_str());
                                myParticle a;
                                a.type = 6;
                                a.index = (int)$3;
                                TmpParticle.push_back(a);  
                                
                        }
        | ID { //we want the original defintions as well -> put it in parts and put the rest in vectorParts
                
                map<string,vector<myParticle> >::iterator it;
                it = ListParts->find($1);
     
                if(it == ListParts->end()) {
                        cout <<$1<<" : " ;
                        yyerror(NULL,NULL,NULL,NULL,NULL,NULL,"Particule not defined");
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
      | {$$=6213;}
      ; 
commands : commands command 
        | 
        ;
command : CMD condition { //find a way to print commands                                     
                                         NodeCuts->insert(make_pair(++cutcount,$2));
				}
        | CMD ALL {                                         
                                        Node* a=new SFuncNode(all,"all");
                                        NodeCuts->insert(make_pair(++cutcount,a));
				}
        | CMD ifstatement {                                         
                                        NodeCuts->insert(make_pair(++cutcount,$2));
    
				}
        | HISTO ID ',' description ',' INT ',' INT ',' INT ',' ID {
                                        //find child node
                                        map<string, Node *>::iterator it ;
                                        it = NodeVars->find($12);
                        
                                        if(it == NodeVars->end()) {
                                                cout <<$12<<" : " ;
                                                yyerror(NULL,NULL,NULL,NULL,NULL,NULL,"Variable not defined");
                                                YYERROR;//stops parsing if variable not found
                                                
                                        }
                                        else {
                                                Node* child=it->second;
                                                Node* h=new HistoNode($2,$4,$6,$8,$10,child);
                                                NodeCuts->insert(make_pair(++cutcount,h));
                                        }

                                        
    
				}
	;
description : description ID {                                                 
                                                char s [512];
                                                strcpy(s,$$); 
                                                strcat(s," ");
                                                strcat(s,$2);
                                                strcpy($$,s);                                       

                                        }
            | ID {if (dnum==0){
                                                $$=strdup($1);                                                       
                                        }
                                        else{                                                
                                                char s [512];
                                                strcpy(s,$$); 
                                                strcat(s," ");
                                                strcat(s,$1);
                                                strcpy($$,s);
                                        }
                                        dnum++;}
        ;
ifstatement : condition '?' action ':' action { 
                        $$=new IfNode($1,$3,$5,"if");
                        } 
            ;
action : condition {
                        $$=$1;
                        }
       | ALL {
               $$=new SFuncNode(all,"all");
               }
       | ifstatement {
                        $$=$1;
                        }
       ;    
condition : e LT e  { 
                                        $$=new BinaryNode(lt,$1,$3,"<"); 
                                        }
           | e GT e { 
                                        $$=new BinaryNode(gt,$1,$3,">"); 
                                        }
           | e LE e { 
                                        $$=new BinaryNode(le,$1,$3,"<="); 
                                        }  
           | e GE e  { 
                                        $$=new BinaryNode(ge,$1,$3,">="); 
                                        }
           | e EQ e { 
                                        $$=new BinaryNode(eq,$1,$3,"=="); 
                                        } 
           | e NE e { 
                                        $$=new BinaryNode(ne,$1,$3,"!="); 
                                        }   
           | e IRG e e {                Node* limit1=$3;
                                        Node* limit2=$4;
                                        Node* c1=new BinaryNode(ge,$1,limit1,">=");
                                        Node* c2=new BinaryNode(le,$1,limit2,"<=");
                                        $$=new BinaryNode(LogicalAnd,c1,c2,"AND"); 
                                        
                                        } 
           | e ERG e e {                Node* limit1=$3;
                                        Node* limit2=$4;
                                        Node* c1=new BinaryNode(gt,$1,limit1,">");
                                        Node* c2=new BinaryNode(lt,$1,limit2,"<");
                                        $$=new BinaryNode(LogicalAnd,c1,c2,"AND"); 
                                        
                                        }                            
           | condition AND condition { 
                                        $$=new BinaryNode(LogicalAnd,$1,$3,"AND"); 
                                        } 
           | condition OR condition { 
                                        $$=new BinaryNode(LogicalOr,$1,$3,"OR"); 
                                        }
           | '(' condition ')' { 
                                        $$=$2; 
                                } 
            ;
e : e '+' e  { 
                $$=new BinaryNode(add,$1,$3,"+"); 
               }
   | e '-' e { 
                $$=new BinaryNode(sub,$1,$3,"-"); 
               }
   | e '*' e { 
                $$=new BinaryNode(mult,$1,$3,"*"); 
               }
   | e '/' e { 
                $$=new BinaryNode(div,$1,$3,"/"); 
               }
   | e '^' e {          
               $$=new BinaryNode(pow,$1,$3,"^");
               } 	
   |'-' e %prec Unary { 
                        $$=new UnaryAONode(unaryMinu,$2,"-");
               }
   | COS '(' e ')' {    
                        $$=new UnaryAONode(cos,$3,"cos"); 
               }
   | SIN '(' e ')' {    //string s3=$3;
                        // tmp=" sin( "+s3+" ) ";   
                        // $$=strdup(tmp.c_str()); 
                        $$=new UnaryAONode(sin,$3,"sin");
               }
   | TAN '(' e ')' {    //string s3=$3;
                        //tmp=" tan( "+s3+" ) ";   
                        //$$=strdup(tmp.c_str()); 
                        $$=new UnaryAONode(tan,$3,"tan");
               }
   |'(' e ')' {    //string s3=$2;
                        //tmp=" ( "+s3+" ) ";   
                        //$$=strdup(tmp.c_str()); 
                        $$=$2;
               }
   | NB {       tmp=to_string($1); 
                //$$=strdup(tmp.c_str()); MAKE A TMP STRING AND CONCAT 
                $$=new ValueNode($1);
                } 
   | INT {  
                $$=new ValueNode($1);
                } 
   | function {$$=$1; pnum=0;}
   
   | ID { //we want the original defintions as well
                map<string, Node *>::iterator it ;
                it = NodeVars->find($1);
     
                if(it == NodeVars->end()) {
                        cout <<$1<<" : " ;
                        yyerror(NULL,NULL,NULL,NULL,NULL,NULL,"Variable not defined");
                        YYERROR;//stops parsing if variable not found
                        
                }
                else {
                        $$=it->second;
                }
                //get the node from variable map
               }
   ;
%%


