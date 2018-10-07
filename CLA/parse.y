%error-verbose
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
extern int yylineno;
void yyerror(list<string> *parts,map<string,Node*>* NodeVars,map<string,vector<myParticle*> >* ListParts,
                map<int,Node*>* NodeCuts, map<string,Node*>* ObjectCuts,
                vector<double>* Initializations , vector<double>* DataFormats
                ,const char *s) { std::cerr << "Error: " << s << std::endl << "line: " << yylineno <<  std::endl; } 
int cutcount;
using namespace std;
string tmp;
int pnum;
int dnum;
vector<myParticle*> TmpParticle;
vector<myParticle*> TmpParticle1;//to be used for list of 2 particles
vector<Node*> TmpCriteria;
std::unordered_set<int> SearchNode::FORBIDDEN_INDICES;
//modify types to ints in myParticle => Done
//see how to give input to yyparse and get output -> DONE
//read file
//avoid global variables
//add histos -> DONE
//view input
%}
%union {
        Node* node;
	double real;
	char* s;//ADD POINTER TO NODE unique_ptr?
}
%parse-param {std::list<std::string> *parts}
%parse-param {std::map<std::string,Node*>* NodeVars}
%parse-param {std::map<std::string,std::vector<myParticle*> >* ListParts}
%parse-param {std::map<int,Node*>* NodeCuts}
%parse-param {std::map<std::string,Node*>* ObjectCuts}
%parse-param {std::vector<double>* Initializations}
%parse-param {std::vector<double>* DataFormats}
%token DEF CMD HISTO OBJ ALGO
%token ELE MUO LEP PHO JET BJET QGJET NUMET METLV //particle types
%token MINPTM MINPTG MINPTJ MINPTE MAXETAM MAXETAE MAXETAG MAXETAJ MAXMET TRGE TRGM
%token LVLO ATLASOD CMSOD DELPHES FCC LHCO
%token PHI ETA ABSETA PT PZ NBF DR DPHI DETA //functions
%token NELE NMUO NLEP NPHO NJET NBJET NQGJET HT METMWT MWT MET ALL LEPSF FILLHISTOS //simple funcs
%token MINIMIZE MAXIMIZE
%token <real> NB
%token <s> ID HID 
%token SIN COS TAN
%token <real> INT
%token OR AND 
%token LT GT LE GE EQ NE IRG ERG
%left OR
%left AND
%nonassoc LT GT LE GE EQ NE IRG ERG
%left '+' '-'
%left '*' '/'
%right '?'
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
                | TRGE  '=' INT {Initializations->at(9)=$3; }
                | TRGM  '=' INT {Initializations->at(10)=$3; }
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
                                        map<string,vector<myParticle*> >::iterator it ;
                                        string name = $2;
                                        it = ListParts->find(name);
                        
                                        if(it != ListParts->end()) {
                                                cout <<name<<" : " ;
                                                yyerror(NULL,NULL,NULL,NULL,NULL,NULL,NULL,"Particule already defined");
                                                YYERROR;//stops parsing if variable already defined
                                        }
                                        
                                        parts->push_back(name+" : "+$4);
                                        
                                                // std::cout<<"\n TMP List: \n";
                                                // vector<myParticle*>::iterator myiterator;
                                                // myiterator = TmpParticle.begin();
                                                // while (myiterator != TmpParticle.end()) {
                                                // std::cout << "type: " << myiterator->type << " index: " << myiterator->index << endl;
                                                // myiterator++;
                                                // }
                                        
                                        vector<myParticle*> newList;
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
                                                yyerror(NULL,NULL,NULL, NULL,NULL,NULL,NULL,"Variable already defined");
                                                YYERROR;//stops parsing if variable already defined
                                                
                                        }
                                        NodeVars->insert(make_pair(name,$4));
				}
        ;
//---------------------------------------
//---------------------------------------
function : '{' particules '}' 'm' {     
                                       vector<myParticle*> newList;
                                       TmpParticle.swap(newList);
                                       $$=new FuncNode(Mof,newList,"m");
                                  }
         | '{' particules '}' 'm' '(' ID ')' {     
                                       map<string,Node*>::iterator it = ObjectCuts->find($6);
                                       if(it == ObjectCuts->end()) {
                                           std::string message = "User object not defined: "; message += $6;
                                           yyerror(NULL,NULL,NULL,NULL,NULL,NULL,NULL,message.c_str());
                                           YYERROR;
                                       } else {
                                        vector<myParticle*> newList;
                                        TmpParticle.swap(newList);
                                        $$=new FuncNode(Mof,newList,"m", it->second);
                                       }
                                }
         | '{' particules '}' 'm' '(' ID ',' ID ')' {     
                                       map<string,Node*>::iterator it = ObjectCuts->find($6);
                                       map<string,Node*>::iterator kt = ObjectCuts->find($8);
                                       if(it == ObjectCuts->end()) {
                                           std::string message = "User object not defined: "; message += $6;
                                           yyerror(NULL,NULL,NULL,NULL,NULL,NULL,NULL,message.c_str());
                                           YYERROR;
                                       } else if(kt == ObjectCuts->end()) {
                                           std::string message = "User object not defined: "; message += $8;
                                           yyerror(NULL,NULL,NULL,NULL,NULL,NULL,NULL,message.c_str());
                                           YYERROR;
                                       } else {
                                        vector<myParticle*> newList;
                                        TmpParticle.swap(newList);
                                        $$=new FuncNode(Mof,newList,"m", it->second, kt->second);
                                       }
                                }
         | '{' particules '}' 'm' '(' ID ',' ID ',' ID ')' {     
                                       map<string,Node*>::iterator it = ObjectCuts->find($6);
                                       map<string,Node*>::iterator kt = ObjectCuts->find($8);
                                       map<string,Node*>::iterator lt = ObjectCuts->find($10);
                                       if(it == ObjectCuts->end()) {
                                           std::string message = "User object not defined: "; message += $6;
                                           yyerror(NULL,NULL,NULL,NULL,NULL,NULL,NULL,message.c_str());
                                           YYERROR;
                                       } else if(kt == ObjectCuts->end()) {
                                           std::string message = "User object not defined: "; message += $8;
                                           yyerror(NULL,NULL,NULL,NULL,NULL,NULL,NULL,message.c_str());
                                           YYERROR;
                                       } else if(lt == ObjectCuts->end()) {
                                           std::string message = "User object not defined: "; message += $10;
                                           yyerror(NULL,NULL,NULL,NULL,NULL,NULL,NULL,message.c_str());
                                           YYERROR;
                                       } else {
                                        vector<myParticle*> newList;
                                        TmpParticle.swap(newList);
                                        $$=new FuncNode(Mof,newList,"m", it->second, kt->second, lt->second);
                                       }
                                }
//---------------------------------------
         | '{' particules '}' 'q' {     
                                       vector<myParticle*> newList;
                                       TmpParticle.swap(newList);//then add newList to node
                                       $$=new FuncNode(Qof,newList,"q");
                                  }
         | '{' particules '}' 'q' '(' ID  ')' {     
                                       map<string,Node*>::iterator it = ObjectCuts->find($6);
                                       if(it == ObjectCuts->end()) {
                                           std::string message = "User object not defined: "; message += $6;
                                           yyerror(NULL,NULL,NULL,NULL,NULL,NULL,NULL,message.c_str());
                                           YYERROR;
                                       } else {
                                        vector<myParticle*> newList;
                                        TmpParticle.swap(newList);
                                        $$=new FuncNode(Qof,newList,"q", it->second);
                                       }
                                }
//---------------------------------------
         | '{' particules '}' 'P' {     
                                       vector<myParticle*> newList;
                                       TmpParticle.swap(newList);
                                       $$=new FuncNode(Pof,newList,"p");
                                  }
         | '{' particules '}' 'P' '(' ID  ')' {     
                                       map<string,Node*>::iterator it = ObjectCuts->find($6);
                                       if(it == ObjectCuts->end()) {
                                           std::string message = "User object not defined: "; message += $6;
                                           yyerror(NULL,NULL,NULL,NULL,NULL,NULL,NULL,message.c_str());
                                           YYERROR;
                                       } else {
                                        vector<myParticle*> newList;
                                        TmpParticle.swap(newList);
                                        $$=new FuncNode(Pof,newList,"p", it->second);
                                       }
                                }
//---------------------------------------
         | '{' particules '}' 'E' {     
                                        vector<myParticle*> newList;
                                        TmpParticle.swap(newList);
                                        $$=new FuncNode(Eof,newList,"e");
                                  }
         | '{' particules '}' 'E' '(' ID  ')' {     
                                       map<string,Node*>::iterator it = ObjectCuts->find($6);
                                       if(it == ObjectCuts->end()) {
                                           std::string message = "User object not defined: "; message += $6;
                                           yyerror(NULL,NULL,NULL,NULL,NULL,NULL,NULL,message.c_str());
                                           YYERROR;
                                       } else {
                                        vector<myParticle*> newList;
                                        TmpParticle.swap(newList);
                                        $$=new FuncNode(Eof,newList,"e", it->second);
                                       }
                                }
//---------------------------------------
         | '{' particules '}' PHI {     
                                        vector<myParticle*> newList;
                                        TmpParticle.swap(newList);
                                        $$=new FuncNode(Phiof,newList,"phi");
                                  }
         | '{' particules '}' PHI '(' ID  ')' {     
                                       map<string,Node*>::iterator it = ObjectCuts->find($6);
                                       if(it == ObjectCuts->end()) {
                                           std::string message = "User object not defined: "; message += $6;
                                           yyerror(NULL,NULL,NULL,NULL,NULL,NULL,NULL,message.c_str());
                                           YYERROR;
                                       } else {
                                        vector<myParticle*> newList;
                                        TmpParticle.swap(newList);
                                        $$=new FuncNode(Phiof,newList,"phi", it->second);
                                       }
                                }
//---------------------------------------
         | '{' particules '}' ETA {     
                                        vector<myParticle*> newList;
                                        TmpParticle.swap(newList);
                                        $$=new FuncNode(Etaof,newList,"eta");
                                  }
         | '{' particules '}' ETA '(' ID  ')' {     
                                       map<string,Node*>::iterator it = ObjectCuts->find($6);
                                       if(it == ObjectCuts->end()) {
                                           std::string message = "User object not defined: "; message += $6;
                                           yyerror(NULL,NULL,NULL,NULL,NULL,NULL,NULL,message.c_str());
                                           YYERROR;
                                       } else {
                                        vector<myParticle*> newList;
                                        TmpParticle.swap(newList);
                                        $$=new FuncNode(Etaof,newList,"eta", it->second);
                                       }
                                }
//---------------------------------------
         | '{' particules '}' ABSETA {     
                                        vector<myParticle*> newList;
                                        TmpParticle.swap(newList);
                                        $$=new FuncNode(AbsEtaof,newList,"abseta");
                                     }
         | '{' particules '}' ABSETA '(' ID  ')' {     
                                       map<string,Node*>::iterator it = ObjectCuts->find($6);
                                       if(it == ObjectCuts->end()) {
                                           std::string message = "User object not defined: "; message += $6;
                                           yyerror(NULL,NULL,NULL,NULL,NULL,NULL,NULL,message.c_str());
                                           YYERROR;
                                       } else {
                                        vector<myParticle*> newList;
                                        TmpParticle.swap(newList);
                                        $$=new FuncNode(AbsEtaof,newList,"abseta", it->second);
                                       }
                                }
//---------------------------------------
         | '{' particules '}' PT {     
                                        vector<myParticle*> newList;
                                        TmpParticle.swap(newList);
                                        $$=new FuncNode(Ptof,newList,"pt");
                                 }
         | '{' particules '}' PT '(' ID  ')' {     
                                       map<string,Node*>::iterator it = ObjectCuts->find($6);
                                       if(it == ObjectCuts->end()) {
                                           std::string message = "User object not defined: "; message += $6;
                                           yyerror(NULL,NULL,NULL,NULL,NULL,NULL,NULL,message.c_str());
                                           YYERROR;
                                       } else {
                                        vector<myParticle*> newList;
                                        TmpParticle.swap(newList);
                                        $$=new FuncNode(Ptof,newList,"pt", it->second);
                                       }
                                }
//---------------------------------------
         | '{' particules '}' PZ {     
                                        vector<myParticle*> newList;
                                        TmpParticle.swap(newList);
                                        $$=new FuncNode(Pzof,newList,"pz");
                                 }
         | '{' particules '}' PZ '(' ID  ')' {     
                                       map<string,Node*>::iterator it = ObjectCuts->find($6);
                                       if(it == ObjectCuts->end()) {
                                           std::string message = "User object not defined: "; message += $6;
                                           yyerror(NULL,NULL,NULL,NULL,NULL,NULL,NULL,message.c_str());
                                           YYERROR;
                                       } else {
                                        vector<myParticle*> newList;
                                        TmpParticle.swap(newList);
                                        $$=new FuncNode(Pzof,newList,"pz", it->second);
                                       }
                                }
//---------------------------------------
         | '{' particules '}' NBF {     
                                        vector<myParticle*> newList;
                                        TmpParticle.swap(newList);
                                        $$=new FuncNode(nbfof,newList,"nbf");
                                  }
         | list DR { 
                                        // std::cout<<"\n DR TMP1 List: \n";
                                        //         vector<myParticle*>::iterator myiterator;
                                        //         myiterator = TmpParticle1.begin();
                                        //         while (myiterator != TmpParticle1.end()) {
                                        //         std::cout << "type: " << myiterator->type << " index: " << myiterator->index << endl;
                                        //         myiterator++;
                                        //         }
                                        //         std::cout<<"\n DR TMP List: \n";
                                                
                                        //         myiterator = TmpParticle.begin();
                                        //         while (myiterator != TmpParticle.end()) {
                                        //         std::cout << "type: " << myiterator->type << " index: " << myiterator->index << endl;
                                        //         myiterator++;
                                        //         }
                                        
                                        vector<myParticle*> newList;
                                        TmpParticle.swap(newList);
                                        vector<myParticle*> newList1;
                                        TmpParticle1.swap(newList1);
                                        $$=new LFuncNode(dR,newList1,newList,"dR");
                                }
        | list DPHI { 
                                                vector<myParticle*> newList;
                                                TmpParticle.swap(newList);
                                                vector<myParticle*> newList1;
                                                TmpParticle1.swap(newList1);
                                                $$=new LFuncNode(dPhi,newList1,newList,"dPhi");
                                }
        | list DETA { 
                                                vector<myParticle*> newList;
                                                TmpParticle.swap(newList);
                                                vector<myParticle*> newList1;
                                                TmpParticle1.swap(newList1);
                                                $$=new LFuncNode(dEta,newList1,newList,"dEta");
                                }
//------------------------------------------
        | NELE {    
                                        string s="NELE";                                                              
                                        $$=new SFuncNode(neles,s);
               }

        | NELE '(' ID ')' {
                                       map<string,Node*>::iterator it = ObjectCuts->find($3);
                                       if(it == ObjectCuts->end()) {
                                           std::string message = "Object not defined: ";
                                           message += $3;
                                           yyerror(NULL,NULL,NULL,NULL,NULL,NULL,NULL,message.c_str());
                                           YYERROR;
                                       }
                                       else {
                                           string s="NELE";
                                           $$=new SFuncNode(neles, s, it->second);
                                       }
                           }
//------------------------------------------
        | NMUO {    
                                        string s="NMUO";                                                              
                                        $$=new SFuncNode(nmuos,s);
               }
        
        | NMUO '(' ID ')' {
                                       map<string,Node*>::iterator it = ObjectCuts->find($3);
                                       if(it == ObjectCuts->end()) {
                                           std::string message = "Object not defined: ";
                                           message += $3;
                                           yyerror(NULL,NULL,NULL,NULL,NULL,NULL,NULL,message.c_str());
                                           YYERROR;
                                       }
                                       else {
                                           string s="NMUO";
                                           $$=new SFuncNode(nmuos, s, it->second);
                                       }
                           }
//------------------------------------------
        | NLEP {    
                                        string s="NLEP";
                                        if(Initializations->at(10)>0){
                                                $$=new SFuncNode(nmuos,s);
                                        }
                                        else{
                                                $$=new SFuncNode(neles,s);
                                        }
               }                        
//------------------------------------------
        | NPHO {    
                                        string s="NPHO";                                                              
                                        $$=new SFuncNode(nphos,s);
               }
        | NPHO '(' ID  ')' {    
                                       map<string,Node*>::iterator it = ObjectCuts->find($3);
                                       if(it == ObjectCuts->end()) {
                                           std::string message = "Object not defined: ";
                                           message += $3;
                                           yyerror(NULL,NULL,NULL,NULL,NULL,NULL,NULL,message.c_str());
                                           YYERROR;
                                       } else {
                                           string s="NPHO";
                                           cout << "Found user defined object " << it->first << endl;
                                           $$=new SFuncNode(nphos, s, it->second);
                                       }
                           }
//------------------------------------------

        | NJET {    
                                        string s="NJET";                                                              
                                        $$=new SFuncNode(njets,s);
               }
        | NJET '(' ID  ')' {    
                                       map<string,Node*>::iterator it = ObjectCuts->find($3);
                                       if(it == ObjectCuts->end()) {
                                           std::string message = "Object not defined: ";
                                           message += $3;
                                           yyerror(NULL,NULL,NULL,NULL,NULL,NULL,NULL,message.c_str());
                                           YYERROR;
                                       } else {
                                           string s="NJET";
                                           cout << "Found user defined object " << it->first << endl;
                                           $$=new SFuncNode(njets, s, it->second);
                                       }
                           }
//------------------------------------------
        | NBJET {    
                                        string s="NBJET";                                                              
                                        $$=new SFuncNode(nbjets,s);
                }
        | NBJET '(' ID  ')' {    
                                       map<string,Node*>::iterator it = ObjectCuts->find($3);
                                       if(it == ObjectCuts->end()) {
                                           std::string message = "Object not defined: ";
                                           message += $3;
                                           yyerror(NULL,NULL,NULL,NULL,NULL,NULL,NULL,message.c_str());
                                           YYERROR;
                                       } else {
                                           string s="NBJET";
                                           cout << "Found user defined object " << it->first << endl;
                                           $$=new SFuncNode(nbjets, s, it->second);
                                       }
                            }
//------------------------------------------
        | NQGJET {    
                                        string s="NQGJET";                                                              
                                        $$=new SFuncNode(nljets,s);
                 }
        | NQGJET '(' ID  ')' {    
                                       map<string,Node*>::iterator it = ObjectCuts->find($3);
                                       if(it == ObjectCuts->end()) {
                                           std::string message = "Object not defined: ";
                                           message += $3;
                                           yyerror(NULL,NULL,NULL,NULL,NULL,NULL,NULL,message.c_str());
                                           YYERROR;
                                       } else {
                                           string s="NQGJET";
                                           cout << "Found user defined object " << it->first << endl;
                                           $$=new SFuncNode(nljets, s, it->second);
                                       }
                            }
//------------------------------------------
        | HT {    
                                        string s="HT";                                                              
                                        $$=new SFuncNode(ht,s);
             }
        | HT '(' ID  ')' {    
                                       map<string,Node*>::iterator it = ObjectCuts->find($3);
                                       if(it == ObjectCuts->end()) {
                                           std::string message = "Object not defined: ";
                                           message += $3;
                                           yyerror(NULL,NULL,NULL,NULL,NULL,NULL,NULL,message.c_str());
                                           YYERROR;
                                       } else {
                                           string s="HT";
                                           cout << "Found user defined object " << it->first << endl;
                                           $$=new SFuncNode(ht, s, it->second);
                                       }
                         }
//------------------------------------------
        | METMWT {    
                                        string s;                                                            
                                        if(Initializations->at(10)>0){
                                                s="m-METMWT";
                                                $$=new SFuncNode(mmetmwt,s);
                                                                        }
                                        else{
                                                s="e-METMWT";
                                                $$=new SFuncNode(emetmwt,s);
                                        }
                 }
//------------------------------------------
        | MWT {    
                                        string s;
                                        if(Initializations->at(10)>0){
                                                s="M-MWT";
                                                $$=new SFuncNode(mmwt, s);
                                        }else{
                                                s="E-MWT";
                                                $$=new SFuncNode(emwt,s);
                                        }
              }
        | MWT '(' ID ')' {    
                                       map<string,Node*>::iterator it = ObjectCuts->find($3);
                                       if(it == ObjectCuts->end()) {
                                           std::string message = "Object not defined: ";
                                           message += $3;
                                           yyerror(NULL,NULL,NULL,NULL,NULL,NULL,NULL,message.c_str());
                                           YYERROR;
                                       } else {
                                        string s;
                                        if(Initializations->at(10)>0){
                                                s="M-MWT";
                                                $$=new SFuncNode(mmwt,s, it->second);
                                        }else{
                                                s="E-MWT";
                                                $$=new SFuncNode(emwt,s, it->second);
                                        }
                                       }
                          }
//------------------------------------------
        | MET {    
                                        
                                        string s="MET";                                                              
                                        $$=new SFuncNode(met,s);
              }
//------------------------------------------
        | ALL {    
                                        
                                        $$=new SFuncNode(all,"all");

              }
//------------------------------------------
        | LEPSF {    
                                        
                                        string s="LEPSF";                                                              
                                        $$=new SFuncNode(all,s);
                }
        ;
//------------------------------------------
//------------------------------------------
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
                                struct myParticle* a =(struct myParticle*)malloc(sizeof(struct myParticle));
                                a->type =1;
                                a->index = (int)$3;
                                TmpParticle.push_back(a);                            
                                tmp="ele_"+to_string((int)$3);                        
                                $$=strdup(tmp.c_str());
                          }
        | MUO '_' index {       tmp="muo_"+to_string((int)$3);                        
                                $$=strdup(tmp.c_str());
                                struct myParticle* a =(struct myParticle*)malloc(sizeof(struct myParticle));
                                a->type = 0;
                                a->index = (int)$3;
                                TmpParticle.push_back(a);  
                        }
        | LEP '_' index {       tmp="lep_"+to_string((int)$3);                        
                                $$=strdup(tmp.c_str());
                                struct myParticle* a =(struct myParticle*)malloc(sizeof(struct myParticle));
                                if(Initializations->at(10)>0){
                                        a->type = 0;
                                }
                                else{
                                        a->type = 1;
                                }
                                a->index = (int)$3;
                                TmpParticle.push_back(a);  
                        }
        | PHO '_' index {       tmp="pho_"+to_string((int)$3);                        
                                $$=strdup(tmp.c_str());
                                struct myParticle* a =(struct myParticle*)malloc(sizeof(struct myParticle));
                                a->type = 8;
                                a->index = (int)$3;
                                TmpParticle.push_back(a);  
                                
                        }
        | JET '_' index {       tmp="jet_"+to_string((int)$3);                        
                                $$=strdup(tmp.c_str());
                                struct myParticle* a =(struct myParticle*)malloc(sizeof(struct myParticle));
                                a->type = 2;
                                a->index = (int)$3;
                                TmpParticle.push_back(a);  
                                
                        }
        | BJET '_' index {      tmp="bjet_"+to_string((int)$3);                        
                                $$=strdup(tmp.c_str());
                                struct myParticle* a =(struct myParticle*)malloc(sizeof(struct myParticle));
                                a->type = 3;
                                a->index = (int)$3;
                                TmpParticle.push_back(a);  
                                
                        }
        | QGJET '_' index {      tmp="qgjet_"+to_string((int)$3);                        
                                $$=strdup(tmp.c_str());
                                struct myParticle* a =(struct myParticle*)malloc(sizeof(struct myParticle));
                                a->type = 4;
                                a->index = (int)$3;
                                TmpParticle.push_back(a);  
                                
                        }
        | NUMET '_' index {     tmp="numet_"+to_string((int)$3);                        
                                $$=strdup(tmp.c_str());
                                struct myParticle* a =(struct myParticle*)malloc(sizeof(struct myParticle));
                                if(Initializations->at(10)>0){
                                        a->type = 5;
                                }
                                else{
                                        a->type = 6;
                                }
                                a->index = (int)$3;
                                TmpParticle.push_back(a);  
                                
                        }
        | METLV '_' index {     tmp="metlv_"+to_string((int)$3);                        
                                $$=strdup(tmp.c_str());
                                struct myParticle* a =(struct myParticle*)malloc(sizeof(struct myParticle));
                                a->type = 7;
                                a->index = (int)$3;
                                TmpParticle.push_back(a);  
                                
                        }
        | ID '_' index { //we want the original defintions as well -> put it in parts and put the rest in vectorParts
                //ngu

                map<string,vector<myParticle*> >::iterator it;
                it = ListParts->find($1);
     
                if(it == ListParts->end()) {

                       map<string,Node*>::iterator ito;
                       ito=ObjectCuts->find($1);
                       cout <<$1<<" : "; //------------new ID

                       if(ito != ObjectCuts->end()) {
                        cout <<" "<<$1<<" is a user particle, ";
// {std::map<std::string,Node*>* ObjectCuts}
//                        cout << ito->first <<"-------- \t";

                        if (ito->first.find("JET") !=std::string::npos ) {
                           cout <<"which is a JET\n";
                           tmp="jet_"+to_string((int)$3);
                                $$=strdup(tmp.c_str());
                                struct myParticle* a =(struct myParticle*)malloc(sizeof(struct myParticle));
                                a->type = 2;
                                a->index = (int)$3;
                                TmpParticle.push_back(a);
                        } 
                        else if (ito->first.find("ELE") !=std::string::npos ) {
                           cout <<"which is a ELE\n";
                           tmp="jet_"+to_string((int)$3);
                                $$=strdup(tmp.c_str());
                                struct myParticle* a =(struct myParticle*)malloc(sizeof(struct myParticle));
                                a->type = 1;
                                a->index = (int)$3;
                                TmpParticle.push_back(a);
                        }
                        else if (ito->first.find("MUO") !=std::string::npos ) {
                           cout <<"which is a MUO\n";
                           tmp="jet_"+to_string((int)$3);
                                $$=strdup(tmp.c_str());
                                struct myParticle* a =(struct myParticle*)malloc(sizeof(struct myParticle));
                                a->type = 0;
                                a->index = (int)$3;
                                TmpParticle.push_back(a);
                        }
                        else if (ito->first.find("PHO") !=std::string::npos ) {
                           cout <<"which is a MUO\n";
                           tmp="jet_"+to_string((int)$3);
                                $$=strdup(tmp.c_str());
                                struct myParticle* a =(struct myParticle*)malloc(sizeof(struct myParticle));
                                a->type = 8;
                                a->index = (int)$3;
                                TmpParticle.push_back(a);
                        }


                       } else {
                        yyerror(NULL,NULL,NULL,NULL,NULL,NULL,NULL,"Particle not defined");
                        YYERROR;//stops parsing if particle not found 
                       }
                }
                else {
                        vector<myParticle*> newList= it->second;
                        TmpParticle.insert(TmpParticle.end(), newList.begin(), newList.end());
                        $$=$1;
                }
             }
        | ID { //we want the original defintions as well -> put it in parts and put the rest in vectorParts

                map<string,vector<myParticle*> >::iterator it;
                it = ListParts->find($1);
     
                if(it == ListParts->end()) {

                       map<string,Node*>::iterator ito;
                       ito=ObjectCuts->find($1);
                       cout <<$1<<" : "; //------------new ID

                       if(ito != ObjectCuts->end()) {
                        cout <<" "<<$1<<" is a user particle\n ";
                        yyerror(NULL,NULL,NULL,NULL,NULL,NULL,NULL,"Particle not defined");
                        YYERROR;//stops parsing if particle not found 
                       }
                }
                else {
                        vector<myParticle*> newList= it->second;
                        TmpParticle.insert(TmpParticle.end(), newList.begin(), newList.end());
                        $$=$1;
                }
             }
        ;
index : '-' INT {$$=-$2;}
      | INT {$$= $1;}
      |     {$$= 6213;}
      ; 
objects : objectBlocs ALGO ID
        | ALGO
        | ALGO ID { cout << "Alg:\n"; }
        ;
objectBlocs : objectBlocs objectBloc
            | objectBloc
            ;
objectBloc : OBJ ID ':' ID criteria {
                                       cout<< " 2:"<<$2<<"  4:"<<$4<<"++++++++++++++++++++\n";
                                        vector<Node*> newList;
                                        TmpCriteria.swap(newList);
                                        //find previous object from ObjectCuts

                                        map<string, Node *>::iterator it ;
                                        it = ObjectCuts->find($4);
                        
                                        if(it == ObjectCuts->end()) {
                                                cout <<$4<<" : " ;
                                                yyerror(NULL,NULL,NULL,NULL,NULL,NULL,NULL,"Object not defined");
                                                YYERROR;
                                        }
                                        else {
                                                Node* previous=it->second;
                                                Node* obj=new ObjectNode($2,previous,NULL,newList,$2);
                                                ObjectCuts->insert(make_pair($2,obj));
                                        }
                                    }
           | OBJ ID ':' ELE criteria {
                                        cout<< " 2:"<<$2<<" is a new EleSet\n";
                                        vector<Node*> newList;
                                        TmpCriteria.swap(newList);
                                        Node* previous=new ObjectNode("Ele",NULL,createNewEle,newList,"obj Ele" );
                                        Node* obj=new ObjectNode($2,previous,NULL,newList,$2 );
                                        ObjectCuts->insert(make_pair($2,obj));
                                     }
           
           | OBJ ID ':' MUO criteria {
                                        cout<< " 2:"<<$2<<" is a new MuoSet\n";
                                        vector<Node*> newList;
                                        TmpCriteria.swap(newList);
                                        Node* previous=new ObjectNode("Muo",NULL,createNewMuo,newList,"obj Muo" );
                                        Node* obj=new ObjectNode($2,previous,NULL,newList,$2 );
                                        ObjectCuts->insert(make_pair($2,obj));
                                     }
           | OBJ ID ':' LEP criteria
           | OBJ ID ':' PHO criteria {
                                        cout<< " 2:"<<$2<<" is a new PhoSet\n";
                                        vector<Node*> newList;
                                        TmpCriteria.swap(newList);
                                        Node* previous=new ObjectNode("Pho",NULL,createNewPho,newList,"obj Pho" );
                                        Node* obj=new ObjectNode($2,previous,NULL,newList,$2 );
                                        ObjectCuts->insert(make_pair($2,obj));
                                      }
           | OBJ ID ':' JET criteria {
                                        cout<< " 2:"<<$2<<" is a new JetSet\n";
                                        vector<Node*> newList;
                                        TmpCriteria.swap(newList);
                                        Node* previous=new ObjectNode("Jet",NULL,createNewJet,newList,"obj Jet" ); //
                                        Node* obj=new ObjectNode($2,previous,NULL,newList,$2 );
                                        ObjectCuts->insert(make_pair($2,obj));
                                      }
           | OBJ ID ':' BJET criteria
           | OBJ ID ':' QGJET criteria
           | OBJ ID ':' NUMET criteria
           | OBJ ID ':' METLV criteria
           ;
criteria : criteria criterion
         | criterion
         ;
criterion : CMD condition { //find a way to print commands                                                                            
                                         TmpCriteria.push_back($2);
				}
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
                                        std::cout << "\nID:"<< $12 <<"\n";
                                        it = NodeVars->find($12);
                        
                                        if(it == NodeVars->end()) {
                                                cout <<$12<<" : " ;
                                                yyerror(NULL,NULL,NULL,NULL,NULL,NULL,NULL,"Variable not defined");
                                                YYERROR;//stops parsing if variable not found
                                        }
                                        else {
                                                Node* child=it->second;
                                                std::cout << "\nnew node:"<< $2 <<" t:"<<$4<<"| "<< $6 <<" "<< $8 <<" " << $10<<" @"<<child<<"\n";
                                                Node* h=new HistoNode($2,$4,$6,$8,$10,child);
                                                NodeCuts->insert(make_pair(++cutcount,h));
                                        }
    
				}
	;
description : description HID {                                                 
                                                char s [512];
                                                strcpy(s,$$); 
                                                strcat(s," ");
                                                strcat(s,$2);
                                                strcpy($$,s);                                       

                             }
            | HID {if (dnum==0){
                                                $$=strdup($1);                                                       
                                        }
                                        else{                                                
                                                char s [512];
                                                strcpy(s,$$); 
                                                strcat(s," ");
                                                strcat(s,$1);
                                                strcpy($$,s);
                                        }
                                        //dnum++;
                                        }
        ;
//--------------------------------------------------------------------------
//--------------------------------------------------------------------------
ifstatement : condition '?' action ':' action %prec '?' { 
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
condition : e LT e  { $$=new BinaryNode(lt,$1,$3,"<");  }
           | e GT e { $$=new BinaryNode(gt,$1,$3,">");  }
           | e LE e { $$=new BinaryNode(le,$1,$3,"<="); }  
           | e GE e { $$=new BinaryNode(ge,$1,$3,">="); }
           | e EQ e { $$=new BinaryNode(eq,$1,$3,"=="); } 
           | e NE e { $$=new BinaryNode(ne,$1,$3,"<>"); }   
           | e MINIMIZE e { $$=new SearchNode(minim,$1,$3,"~="); }
           | e MAXIMIZE e { $$=new SearchNode(maxim,$1,$3,"!="); }
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
   //to make the difference between ID + ID and ID ID in particules ->create two maps
   | ID { //we want the original defintions as well
                map<string, Node *>::iterator it ;
                it = NodeVars->find($1);
     
                if(it == NodeVars->end()) {
                        cout <<$1<<" : " ;
                        yyerror(NULL,NULL,NULL,NULL,NULL,NULL,NULL,"Variable not defined");
                        YYERROR;//stops parsing if variable not found
                        
                }
                else {
                        $$=it->second;
                }
                //get the node from variable map
               }
   ;
%%
