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
std::unordered_set<int> SearchNode::FORBIDDEN_INDICES[5];
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
          int integer;
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
%token ELE MUO LEP TAU PHO JET BJET QGJET NUMET METLV //particle types
%token MINPTM MINPTG MINPTJ MINPTE MAXETAM MAXETAE MAXETAG MAXETAJ MAXMET TRGE TRGM
%token LVLO ATLASOD CMSOD DELPHES FCC LHCO
%token PHI ETA ABSETA PT PZ NBF DR DPHI DETA //functions
%token NUMOF HT METMWT MWT MET ALL LEPSF FILLHISTOS //simple funcs
%token DEEPB FJET MSOFTD TAU1 TAU2 TAU3 // razor additions
%token RELISO TAUISO DXY DZ SOFTID
%token FMEGAJETS FMR FMTR FMT // RAZOR external functions
%token MINIMIZE MAXIMIZE
%token PERM COMB SORT
%token <real> NB
%token <integer> INT
%token <s> ID HID 
%token SIN COS TAN ABS
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
%type <integer> index
%type <node> e function condition action ifstatement
%type <s> particule particules list description
%%
input : initializations definitions objects commands 
      | initializations objects definitions  commands 
      | initializations definitions objects definitions  commands 
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
                | TRGM  '=' INT {Initializations->at(10)=0.0; }
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
function : '{' particules '}' 'm' {     
                                       vector<myParticle*> newList;
                                       TmpParticle.swap(newList);
                                       $$=new FuncNode(Mof,newList,"m");
                                       cout << "Mass function\n";
                                  }
         | 'm' '(' particules ')' {     
                                       vector<myParticle*> newList;
                                       TmpParticle.swap(newList);
                                       $$=new FuncNode(Mof,newList,"m");
                                       cout << "Mass function\n";
                                  }
         | '{' particules '}' 'm' '(' ID ')' {     
                                       map<string,Node*>::iterator it = ObjectCuts->find($6);
                                       if(it == ObjectCuts->end()) {
                                           std::string message = "User object not defined: "; message += $6;
                                           yyerror(NULL,NULL,NULL,NULL,NULL,NULL,NULL,message.c_str());
                                           YYERROR;
                                       } else {
                                        cout << "Mass function with "<< $6<<"\n";
                                        vector<myParticle*> newList;
                                        TmpParticle.swap(newList);
                                        $$=new FuncNode(Mof,newList,"m", it->second);
                                       }
                                }
//---------------------------------------
//       | '{' particules '}' 'm' '(' ID ',' ID ')' {     
//                                     map<string,Node*>::iterator it = ObjectCuts->find($6);
//                                     map<string,Node*>::iterator kt = ObjectCuts->find($8);
//                                     if(it == ObjectCuts->end()) {
//                                         std::string message = "User object not defined: "; message += $6;
//                                         yyerror(NULL,NULL,NULL,NULL,NULL,NULL,NULL,message.c_str());
//                                         YYERROR;
//                                     } else if(kt == ObjectCuts->end()) {
//                                         std::string message = "User object not defined: "; message += $8;
//                                         yyerror(NULL,NULL,NULL,NULL,NULL,NULL,NULL,message.c_str());
//                                         YYERROR;
//                                     } else {
//                                      vector<myParticle*> newList;
//                                      TmpParticle.swap(newList);
//                                      $$=new FuncNode(Mof,newList,"m", it->second, kt->second);
//                                     }
//                              }
//       | '{' particules '}' 'm' '(' ID ',' ID ',' ID ')' {     
//                                     map<string,Node*>::iterator it = ObjectCuts->find($6);
//                                     map<string,Node*>::iterator kt = ObjectCuts->find($8);
//                                     map<string,Node*>::iterator lt = ObjectCuts->find($10);
//                                     if(it == ObjectCuts->end()) {
//                                         std::string message = "User object not defined: "; message += $6;
//                                         yyerror(NULL,NULL,NULL,NULL,NULL,NULL,NULL,message.c_str());
//                                         YYERROR;
//                                     } else if(kt == ObjectCuts->end()) {
//                                         std::string message = "User object not defined: "; message += $8;
//                                         yyerror(NULL,NULL,NULL,NULL,NULL,NULL,NULL,message.c_str());
//                                         YYERROR;
//                                     } else if(lt == ObjectCuts->end()) {
//                                         std::string message = "User object not defined: "; message += $10;
//                                         yyerror(NULL,NULL,NULL,NULL,NULL,NULL,NULL,message.c_str());
//                                         YYERROR;
//                                     } else {
//                                      vector<myParticle*> newList;
//                                      TmpParticle.swap(newList);
//                                      $$=new FuncNode(Mof,newList,"m", it->second, kt->second, lt->second);
//                                     }
//                              }
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
//---------------------------------------
         | '{' particules '}' DEEPB {     
                                        vector<myParticle*> newList;
                                        TmpParticle.swap(newList);
                                        $$=new FuncNode(DeepBof,newList,"deepB");
                                  }
         | DEEPB '(' particules ')' {     
                                        vector<myParticle*> newList;
                                        TmpParticle.swap(newList);
                                        $$=new FuncNode(DeepBof,newList,"deepB");
                                  }
         | '{' particules '}' MSOFTD {     
                                        vector<myParticle*> newList;
                                        TmpParticle.swap(newList);
                                        $$=new FuncNode(MsoftDof,newList,"msoftD");
                                  }
         | MSOFTD '(' particules ')' {     
                                        vector<myParticle*> newList;
                                        TmpParticle.swap(newList);
                                        $$=new FuncNode(MsoftDof,newList,"msoftD");
                                  }
         | '{' particules '}' TAU1 {     
                                        vector<myParticle*> newList;
                                        TmpParticle.swap(newList);
                                        $$=new FuncNode(tau1of,newList,"tau1");
                                  }
         | TAU1 '(' particules ')' {     
                                        vector<myParticle*> newList;
                                        TmpParticle.swap(newList);
                                        $$=new FuncNode(tau1of,newList,"tau1");
                                  }
         | '{' particules '}' TAU2 {     
                                        vector<myParticle*> newList;
                                        TmpParticle.swap(newList);
                                        $$=new FuncNode(tau2of,newList,"tau2");
                                  }
         | TAU2 '(' particules ')' {     
                                        vector<myParticle*> newList;
                                        TmpParticle.swap(newList);
                                        $$=new FuncNode(tau2of,newList,"tau2");
                                  }
         | '{' particules '}' TAU3 {     
                                        vector<myParticle*> newList;
                                        TmpParticle.swap(newList);
                                        $$=new FuncNode(tau3of,newList,"tau3");
                                  }
         | TAU3 '(' particules ')' {     
                                        vector<myParticle*> newList;
                                        TmpParticle.swap(newList);
                                        $$=new FuncNode(tau3of,newList,"tau3");
                                  }

         | '{' particules '}' DXY {     
                                        vector<myParticle*> newList;
                                        TmpParticle.swap(newList);
                                        $$=new FuncNode(dxyof,newList,"dxy");
                                  }
         | DXY '(' particules ')' {     
                                        vector<myParticle*> newList;
                                        TmpParticle.swap(newList);
                                        $$=new FuncNode(dxyof,newList,"dxy");
                                  }
         | '{' particules '}' DZ {     
                                        vector<myParticle*> newList;
                                        TmpParticle.swap(newList);
                                        $$=new FuncNode(dzof,newList,"dz");
                                  }
         | DZ '(' particules ')' {     
                                        vector<myParticle*> newList;
                                        TmpParticle.swap(newList);
                                        $$=new FuncNode(dzof,newList,"dz");
                                  }
         | '{' particules '}' RELISO {     
                                        vector<myParticle*> newList;
                                        TmpParticle.swap(newList);
                                        $$=new FuncNode(relisoof,newList,"miniPFRelIsoAll");
                                  }
         | RELISO '(' particules ')' {     
                                        vector<myParticle*> newList;
                                        TmpParticle.swap(newList);
                                        $$=new FuncNode(relisoof,newList,"miniPFRelIsoAll");
                                  }
         | '{' particules '}' SOFTID {     
                                        vector<myParticle*> newList;
                                        TmpParticle.swap(newList);
                                        $$=new FuncNode(softIdof,newList,"softId");
                                  }
         | SOFTID '(' particules ')' {     
                                        vector<myParticle*> newList;
                                        TmpParticle.swap(newList);
                                        $$=new FuncNode(softIdof,newList,"softId");
                                  }
         | '{' particules '}' TAUISO {     
                                        vector<myParticle*> newList;
                                        TmpParticle.swap(newList);
                                        $$=new FuncNode(tauisoof,newList,"dMVAnewDM2017v2");
                                  }
         | TAUISO '(' particules ')' {     
                                        vector<myParticle*> newList;
                                        TmpParticle.swap(newList);
                                        $$=new FuncNode(tauisoof,newList,"dMVAnewDM2017v2");
                                  }
//---------------------------------------
//---------------------------------------
         | '{' particules '}' PHI {     
                                        vector<myParticle*> newList;
                                        TmpParticle.swap(newList);
                                        $$=new FuncNode(Phiof,newList,"phi");
                                  }
         | PHI '(' particules ')' {     
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
         | ETA '(' particules ')' {     
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
         | PT '(' particules ')' {     
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
                                        $$=new FuncNode(Ptof,newList,"pt", it->second, it->first); // NGUUUUUUUUUUUUUUUUU
                                       }
                                }
//---------------------------------------
         | '{' particules '}' PZ {     
                                        vector<myParticle*> newList;
                                        TmpParticle.swap(newList);
                                        $$=new FuncNode(Pzof,newList,"pz");
                                 }
         | PZ '(' particules ')' {     
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
                                        vector<myParticle*> newList;
                                        TmpParticle.swap(newList);
                                        vector<myParticle*> newList1;
                                        TmpParticle1.swap(newList1);
                                        $$=new LFuncNode(dR,newList1,newList,"dR");
                   }
         | DR list { 
                                        vector<myParticle*> newList;
                                        TmpParticle.swap(newList);
                                        vector<myParticle*> newList1;
                                        TmpParticle1.swap(newList1);
                                        $$=new LFuncNode(dR,newList1,newList,"dR");
                   }
         | list DR  '(' ID  ')' {  //-----------with user objects
                                       map<string,Node*>::iterator it = ObjectCuts->find($4);
                                       if(it == ObjectCuts->end()) {
                                           std::string message = "User object not defined: "; message += $4;
                                           yyerror(NULL,NULL,NULL,NULL,NULL,NULL,NULL,message.c_str());
                                           YYERROR;
                                       } else {
                                        vector<myParticle*> newList;
                                        TmpParticle.swap(newList);
                                        vector<myParticle*> newList1;
                                        TmpParticle1.swap(newList1);
                                        $$=new LFuncNode(dR,newList1,newList,"dR", it->second);
                                       }

                                }
        | list DPHI { 
                                                vector<myParticle*> newList;
                                                TmpParticle.swap(newList);
                                                vector<myParticle*> newList1;
                                                TmpParticle1.swap(newList1);
                                                $$=new LFuncNode(dPhi,newList1,newList,"dPhi");
                    }
        | DPHI list { 
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
        | DETA list { 
                                                vector<myParticle*> newList;
                                                TmpParticle.swap(newList);
                                                vector<myParticle*> newList1;
                                                TmpParticle1.swap(newList1);
                                                $$=new LFuncNode(dEta,newList1,newList,"dEta");
                    }
        | NUMOF '(' ID ')'  {      
                                       map<string,Node*>::iterator it = ObjectCuts->find($3);
                                       if(it == ObjectCuts->end()) {
                                           std::string message = "Object not defined: ";
                                           message += $3;
                                           yyerror(NULL,NULL,NULL,NULL,NULL,NULL,NULL,message.c_str());
                                           YYERROR;
                                       }
                                       else {
                                            int type=((ObjectNode*)it->second)->type;
                                            $$=new SFuncNode(count,            type, it->first, it->second);
                                       }
                           }
        | NUMOF '(' ELE ')' {       
                                           $$=new SFuncNode(count, 1, "ELE");
                            }
        | NUMOF '(' MUO ')' {       
                                           $$=new SFuncNode(count, 0, "MUO");
                            }
        | NUMOF '(' TAU ')' {       
                                           $$=new SFuncNode(count, 11, "TAU");
                            }
        | NUMOF '(' JET ')' {       
                                           $$=new SFuncNode(count, 2, "JET");
                            }
        | NUMOF '(' FJET ')' {       
                                           $$=new SFuncNode(count, 9, "FJET");
                            }
//------------------------------------------
        | FMEGAJETS '(' ID  ')' {
                                       map<string,Node*>::iterator it = ObjectCuts->find($3);
                                       if(it == ObjectCuts->end()) {
                                           std::string message = "Object not defined: ";
                                           message += $3;
                                           yyerror(NULL,NULL,NULL,NULL,NULL,NULL,NULL,message.c_str());
                                           YYERROR;
                                       } else {
                                           int type=((ObjectNode*)it->second)->type; // type is JETS or FJETS etc..
                                           $$=new SFuncNode(userfunc, fmegajets, type, it->first, it->second);
                                       }
                         }
//------------------------------------------
        | HT {
                                        $$=new SFuncNode(ht,0,"JET");
             }
        | HT '(' ID  ')' {
                                       map<string,Node*>::iterator it = ObjectCuts->find($3);
                                       if(it == ObjectCuts->end()) {
                                           std::string message = "Object not defined: ";
                                           message += $3;
                                           yyerror(NULL,NULL,NULL,NULL,NULL,NULL,NULL,message.c_str());
                                           YYERROR;
                                       } else {
                                           int id=((ObjectNode*)it->second)->type;
                                           $$=new SFuncNode(ht,id, it->first, it->second);
                                       }
                         }
       | MET {
                                        $$=new SFuncNode(met,0, "MET");
              }
        | ALL {    
                                        $$=new SFuncNode(all,0, "all");
              }
//------------------------------------------
        | LEPSF {    
                                        string s="LEPSF";                                                              
                                        $$=new SFuncNode(all,0,s);
                }
//      | COMB '(' particules  ')' {
//                                      VECTOR<MYPARTICLE*> NEWLIST;
//                                      TMPPARTICLE.SWAP(NEWLIST);
//                                      $$=NEW FUNCNODE(PZOF,NEWLIST,"C");
//           | e MINIMIZE e { $$=new SearchNode(minim,$1,$3,"~="); }
//                                  }
//      | PERM '(' particules  ')' {
//                                      VECTOR<MYPARTICLE*> NEWLIST;
//                                      TMPPARTICLE.SWAP(NEWLIST);
//                                      $$=NEW FUNCNODE(PZOF,NEWLIST,"PZ");
//                                  }
//      | SORT '(' particules ',' condition ')' {
//                                      VECTOR<MYPARTICLE*> NEWLIST;
//                                      TMPPARTICLE.SWAP(NEWLIST);
//                                      $$=NEW FUNCNODE(PZOF,NEWLIST,"PZ");
//                                  }
        ;
//------------------------------------------
//------------------------------------------
list : '{' particules { pnum=0; TmpParticle.swap(TmpParticle1); } ',' particules '}' { 
                                                        string s=$2;
                                                        string s2=$5;
                                                        s="{ "+s+" , "+s2+" }";                        
                                                        $$=strdup(s.c_str());
                                                        }
     | '(' particules { pnum=0; TmpParticle.swap(TmpParticle1); } ',' particules ')' {
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
            | particule {   if (pnum==0){
                                                $$=strdup($1);                                                       
                                        }
                                        else{                                                
                                                char s [512];
                                                strcpy(s,$$); 
                                                strcat(s," ");
                                                strcat(s,$1);
                                                strcpy($$,s);
                                        }
                                        pnum++;
                         }
            | particule '+' {   if (pnum==0){
                                                $$=strdup($1);                                                       
                                        }
                                        else{                                                
                                                char s [512];
                                                strcpy(s,$$); 
                                                strcat(s," ");
                                                strcat(s,$1);
                                                strcpy($$,s);
                                        }
                                        pnum++;
                         }
            ;
particule : ELE '_' index {
                                struct myParticle* a =(struct myParticle*)malloc(sizeof(struct myParticle));
                                a->type =1;
                                a->index = (int)$3;
                                a->collection = "ELE";
                                TmpParticle.push_back(a);                            
                                tmp="ele_"+to_string((int)$3);                        
                                $$=strdup(tmp.c_str());
                          }
        | ELE '[' index ']' {
                                struct myParticle* a =(struct myParticle*)malloc(sizeof(struct myParticle));
                                a->type =1;
                                a->index = (int)$3;
                                a->collection = "ELE";
                                TmpParticle.push_back(a);
                                tmp="ele_"+to_string((int)$3);
                                $$=strdup(tmp.c_str());
                            }
        | MUO '[' index ']' {   
                                tmp="muo_"+to_string((int)$3);                        
                                $$=strdup(tmp.c_str());
                                struct myParticle* a =(struct myParticle*)malloc(sizeof(struct myParticle));
                                a->type = 0;
                                a->index = (int)$3;
                                a->collection = "MUO";
                                TmpParticle.push_back(a);  
                        }
        | MUO '_' index {       
				tmp="muo_"+to_string((int)$3);                        
                                $$=strdup(tmp.c_str());
                                struct myParticle* a =(struct myParticle*)malloc(sizeof(struct myParticle));
                                a->type = 0;
                                a->index = (int)$3;
                                a->collection = "MUO";
                                TmpParticle.push_back(a);  
                        }
        | TAU '[' index ']' {   
                                tmp="tau_"+to_string((int)$3);                        
                                $$=strdup(tmp.c_str());
                                struct myParticle* a =(struct myParticle*)malloc(sizeof(struct myParticle));
                                a->type = 11;
                                a->index = (int)$3;
                                a->collection = "TAU";
                                TmpParticle.push_back(a);  
                        }
        | TAU '_' index {       
				tmp="tau_"+to_string((int)$3);                        
                                $$=strdup(tmp.c_str());
                                struct myParticle* a =(struct myParticle*)malloc(sizeof(struct myParticle));
                                a->type = 11;
                                a->index = (int)$3;
                                a->collection = "TAU";
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
        | PHO '[' index ']' {   tmp="pho_"+to_string((int)$3);                        
                                $$=strdup(tmp.c_str());
                                struct myParticle* a =(struct myParticle*)malloc(sizeof(struct myParticle));
                                a->type = 8;
                                a->index = (int)$3;
                                a->collection = "PHO";
                                TmpParticle.push_back(a);  
                        }
        | PHO '_' index {       tmp="pho_"+to_string((int)$3);                        
                                $$=strdup(tmp.c_str());
                                struct myParticle* a =(struct myParticle*)malloc(sizeof(struct myParticle));
                                a->type = 8;
                                a->index = (int)$3;
                                a->collection = "PHO";
                                TmpParticle.push_back(a);  
                        }
        | JET '[' index ']' {   tmp="jet_"+to_string((int)$3);                        
                                $$=strdup(tmp.c_str());
                                struct myParticle* a =(struct myParticle*)malloc(sizeof(struct myParticle));
                                a->type = 2;
                                a->index = (int)$3;
                                a->collection = "JET";
                                TmpParticle.push_back(a);  
                        }
        | JET '_' index {       tmp="jet_"+to_string((int)$3);                        
                                $$=strdup(tmp.c_str());
                                struct myParticle* a =(struct myParticle*)malloc(sizeof(struct myParticle));
                                a->type = 2;
                                a->index = (int)$3;
                                a->collection = "JET";
                                TmpParticle.push_back(a);  
                        }
        | BJET '_' index {      tmp="bjet_"+to_string((int)$3);                        
                                $$=strdup(tmp.c_str());
                                struct myParticle* a =(struct myParticle*)malloc(sizeof(struct myParticle));
                                a->type = 3;
                                a->index = (int)$3;
                                TmpParticle.push_back(a);  
                        }
        | BJET '[' index ']' {  tmp="bjet_"+to_string((int)$3);                        
                                $$=strdup(tmp.c_str());
                                struct myParticle* a =(struct myParticle*)malloc(sizeof(struct myParticle));
                                a->type = 3;
                                a->index = (int)$3;
                                TmpParticle.push_back(a);  
                        }
        | FJET '_' index {      tmp="bjet_"+to_string((int)$3);                        
                                $$=strdup(tmp.c_str());
                                struct myParticle* a =(struct myParticle*)malloc(sizeof(struct myParticle));
                                a->type = 9;
                                a->index = (int)$3;
                                TmpParticle.push_back(a);  
                        }
        | FJET '[' index ']' {  tmp="bjet_"+to_string((int)$3);                        
                                $$=strdup(tmp.c_str());
                                struct myParticle* a =(struct myParticle*)malloc(sizeof(struct myParticle));
                                a->type = 9;
                                a->index = (int)$3;
                                TmpParticle.push_back(a);  
                        }
        | QGJET '[' index ']' { tmp="qgjet_"+to_string((int)$3);                        
                                $$=strdup(tmp.c_str());
                                struct myParticle* a =(struct myParticle*)malloc(sizeof(struct myParticle));
                                a->type = 4;
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
                cout<<"ID ------------------------\n";
                map<string,vector<myParticle*> >::iterator it;
                it = ListParts->find($1);
     
                if(it == ListParts->end()) {

                       map<string,Node*>::iterator ito;
                       ito=ObjectCuts->find($1);
                       cout <<$1<<" : "; //------------new ID

                       if(ito != ObjectCuts->end()) {
                        cout <<" "<<$1<<" is a user particle, ";

                        if (ito->first.find("JET") !=std::string::npos ) {
                           cout <<"which is a JET\n";
                           tmp="jet_"+to_string((int)$3);
                                $$=strdup(tmp.c_str());
                                struct myParticle* a =(struct myParticle*)malloc(sizeof(struct myParticle));
                                a->type = 2;
                                a->index = (int)$3;
                                a->collection = $1;
                                TmpParticle.push_back(a);
                        } 
                        else if (ito->first.find("ELE") !=std::string::npos ) {
                           cout <<"which is a ELE\n";
                           tmp="jet_"+to_string((int)$3);
                                $$=strdup(tmp.c_str());
                                struct myParticle* a =(struct myParticle*)malloc(sizeof(struct myParticle));
                                a->type = 1;
                                a->index = (int)$3;
                                a->collection = $1;
                                TmpParticle.push_back(a);
                        }
                        else if (ito->first.find("MUO") !=std::string::npos ) {
                           cout <<"which is a MUO\n";
                           tmp="jet_"+to_string((int)$3);
                                $$=strdup(tmp.c_str());
                                struct myParticle* a =(struct myParticle*)malloc(sizeof(struct myParticle));
                                a->type = 0;
                                a->index = (int)$3;
                                a->collection = $1;
                                TmpParticle.push_back(a);
                        }
                        else if (ito->first.find("TAU") !=std::string::npos ) {
                           cout <<"which is a TAU\n";
                           tmp="jet_"+to_string((int)$3);
                                $$=strdup(tmp.c_str());
                                struct myParticle* a =(struct myParticle*)malloc(sizeof(struct myParticle));
                                a->type = 11;
                                a->index = (int)$3;
                                a->collection = $1;
                                TmpParticle.push_back(a);
                        }
                        else if (ito->first.find("PHO") !=std::string::npos ) {
                           cout <<"which is a PHO\n";
                           tmp="jet_"+to_string((int)$3);
                                $$=strdup(tmp.c_str());
                                struct myParticle* a =(struct myParticle*)malloc(sizeof(struct myParticle));
                                a->type = 8;
                                a->index = (int)$3;
                                a->collection = $1;
                                TmpParticle.push_back(a);
                        }
                        else if (ito->first.find("FJET") !=std::string::npos ) {
                           cout <<"which is a FatJET\n";
                           tmp="jet_"+to_string((int)$3);
                                $$=strdup(tmp.c_str());
                                struct myParticle* a =(struct myParticle*)malloc(sizeof(struct myParticle));
                                a->type = 9;
                                a->index = (int)$3;
                                a->collection = $1;
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
          | {$$= 6213;} // NGU
      ; 
objects : objectBlocs ALGO ID
        | objectBlocs DEF  ID
        | ALGO
        | ALGO ID {  cout << "++++++++++++++++++++++++ as Alg:\n"; 
                  }
        ;
objectBlocs : objectBlocs objectBloc
            | objectBloc
            ;
objectBloc : OBJ ID ':' ID criteria {
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
                                        Node* previous=new ObjectNode("ELE",NULL,createNewEle,newList,"obj Ele" );
                                        Node* obj=new ObjectNode($2,previous,NULL,newList,$2 );
                                        ObjectCuts->insert(make_pair($2,obj));
                                     }
           | OBJ ID ':' MUO criteria {
                                        cout<< " 2:"<<$2<<" is a new MuoSet\n";
                                        vector<Node*> newList;
                                        TmpCriteria.swap(newList);
                                        Node* previous=new ObjectNode("MUO",NULL,createNewMuo,newList,"obj Muo" );
                                        Node* obj=new ObjectNode($2,previous,NULL,newList,$2 );
                                        ObjectCuts->insert(make_pair($2,obj));
                                     }
           | OBJ ID ':' TAU criteria {
                                        cout<< " 2:"<<$2<<" is a new TauSet\n";
                                        vector<Node*> newList;
                                        TmpCriteria.swap(newList);
                                        Node* previous=new ObjectNode("TAU",NULL,createNewTau,newList,"obj Tau" );
                                        Node* obj=new ObjectNode($2,previous,NULL,newList,$2 );
                                        ObjectCuts->insert(make_pair($2,obj));
                                     }
           | OBJ ID ':' LEP criteria
           | OBJ ID ':' PHO criteria {
                                        cout<< " 2:"<<$2<<" is a new PhoSet\n";
                                        vector<Node*> newList;
                                        TmpCriteria.swap(newList);
                                        Node* previous=new ObjectNode("PHO",NULL,createNewPho,newList,"obj Pho" );
                                        Node* obj=new ObjectNode($2,previous,NULL,newList,$2 );
                                        ObjectCuts->insert(make_pair($2,obj));
                                      }
           | OBJ ID ':' JET criteria {
                                        cout<< " 2:"<<$2<<" is a new JetSet\n";
                                        vector<Node*> newList;
                                        TmpCriteria.swap(newList);
                                        Node* previous=new ObjectNode("JET",NULL,createNewJet,newList,"obj Jet" ); //
                                        Node* obj=new ObjectNode($2,previous,NULL,newList,$2 );
                                        ObjectCuts->insert(make_pair($2,obj));
                                      }
           | OBJ ID ':' FJET criteria {
                                        cout<< " 2:"<<$2<<" is a new FatJetSet\n";
                                        vector<Node*> newList;
                                        TmpCriteria.swap(newList);
                                        Node* previous=new ObjectNode("FJET",NULL,createNewFJet,newList,"obj FatJet" ); //
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
        | ALGO ID {  cout << " runing Algo:"<< $2<<"\n";
                  }
        | CMD ALL {                                         
                                        Node* a=new SFuncNode(all,0, "all");
                                        NodeCuts->insert(make_pair(++cutcount,a));
				}
        | CMD ifstatement {                                         
                                        NodeCuts->insert(make_pair(++cutcount,$2));
    
				}
        | HISTO ID ',' description ',' INT ',' INT ',' INT ',' ID {
                                        //find child node
                                        map<string, Node *>::iterator it ;
//                                        std::cout << "\nID:"<< $12 <<"\n";
                                        it = NodeVars->find($12);
                        
                                        if(it == NodeVars->end()) {
                                                cout <<$12<<" : " ;
                                                yyerror(NULL,NULL,NULL,NULL,NULL,NULL,NULL,"Histo variable not defined");
                                                YYERROR;//stops parsing if variable not found
                                        }
                                        else {
                                                Node* child=it->second;
//                                              std::cout << "\nnew node:"<< $2 <<" t:"<<$4<<"| "<< $6 <<" "<< $8 <<" " << $10<<" @"<<child<<"\n";
                                                Node* h=new HistoNode($2,$4,$6,$8,$10,child);
                                                NodeCuts->insert(make_pair(++cutcount,h));
                                        }
    
				}
        | HISTO ID ',' description ',' INT ',' NB ',' NB ',' ID {
                                        //find child node
                                        map<string, Node *>::iterator it ;
//                                        std::cout << "\nID:"<< $12 <<"\n";
                                        it = NodeVars->find($12);
                        
                                        if(it == NodeVars->end()) {
                                                cout <<$12<<" : " ;
                                                yyerror(NULL,NULL,NULL,NULL,NULL,NULL,NULL,"Histo variable not defined");
                                                YYERROR;//stops parsing if variable not found
                                        }
                                        else {
                                                Node* child=it->second;
//                                              std::cout << "\nnew node:"<< $2 <<" t:"<<$4<<"| "<< $6 <<" "<< $8 <<" " << $10<<" @"<<child<<"\n";
                                                Node* h=new HistoNode($2,$4,$6,$8,$10,child);
                                                NodeCuts->insert(make_pair(++cutcount,h));
                                        }
    
				}
        | HISTO ID ',' description ',' INT ',' NB ',' NB ',' function {
//                                              std::cout << "\nnew node:"<< $2 <<" t:"<<$4<<"| "<< $6 <<" "<< $8 <<" " << $10<<" @"<<child<<"\n";
                                                Node* h=new HistoNode($2,$4,$6,$8,$10,$12);
                                                NodeCuts->insert(make_pair(++cutcount,h));
				}
        | HISTO ID ',' description ',' INT ',' INT ',' INT ',' function {
//                                              std::cout << "\nnew node:"<< $2 <<" t:"<<$4<<"| "<< $6 <<" "<< $8 <<" " << $10<<" @"<<child<<"\n";
                                                Node* h=new HistoNode($2,$4,$6,$8,$10,$12);
                                                NodeCuts->insert(make_pair(++cutcount,h));
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
                                } else{                                                
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
               $$=new SFuncNode(all,0,"all");
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
//         | e '(' ID ')' MINIMIZE e { 
//                                    map<string,Node*>::iterator ito = ObjectCuts->find($3);
//                                    if(ito == ObjectCuts->end()) {
//                                         std::string message = "User object not defined: "; message += $3;
//                                         yyerror(NULL,NULL,NULL,NULL,NULL,NULL,NULL,message.c_str());
//                                         YYERROR;
//                                    } else {
//                                         cout <<ito->first <<" recognized for search.\n";
//                                         $$=new SearchNode(minim,$1,$6,"~=",ito); 
//                                    }
//                                   }
           | e MAXIMIZE e { $$=new SearchNode(maxim,$1,$3,"!="); }
           | e IRG e e {                Node* limit1=$3;
                                        Node* limit2=$4;
                                        Node* c1=new BinaryNode(ge,$1,limit1,">=");
                                        Node* c2=new BinaryNode(le,$1,limit2,"<=");
                                        $$=new BinaryNode(LogicalAnd,c1,c2,"AND"); 
                                        
                                        } 
           | e ERG e e {                Node* limit1=$3;
                                        Node* limit2=$4;
                                        Node* c1=new BinaryNode(le,$1,limit1,"<=");
                                        Node* c2=new BinaryNode(ge,$1,limit2,">=");
                                        $$=new BinaryNode(LogicalOr,c1,c2,"OR"); 
                                        
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
   | ABS '(' e ')' {    
                        $$=new UnaryAONode(cos,$3,"fabs"); 
               }
   | COS '(' e ')' {    
                        $$=new UnaryAONode(cos,$3,"cos"); 
               }
   | SIN '(' e ')' {    
                        $$=new UnaryAONode(sin,$3,"sin");
               }
   | TAN '(' e ')' {    
                        $$=new UnaryAONode(tan,$3,"tan");
               }
   |'(' e ')' {   
                        $$=$2;
               }
   | NB {       tmp=to_string($1); 
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
    | ID '(' ID ')' {
                map<string, Node *>::iterator it ;
                it = NodeVars->find($1);
     
                if(it == NodeVars->end()) {
                        cout <<$1<<" : " ;
                        yyerror(NULL,NULL,NULL,NULL,NULL,NULL,NULL,"Variable not defined");
                        YYERROR;//stops parsing if variable not found
                }
                else {
                        cout <<it->first <<" node ID recognized.\t";
                        cout <<it->second->getStr()<<"\n";
                }
                map<string,Node*>::iterator ito = ObjectCuts->find($3);
                                      if(ito == ObjectCuts->end()) {
                                           std::string message = "User object not defined: "; message += $3;
                                           yyerror(NULL,NULL,NULL,NULL,NULL,NULL,NULL,message.c_str());
                                           YYERROR;
                                      } else {
                                        cout <<ito->first <<" OBJ id recognized.\n";
                                        it->second->setUserObjects(ito->second);
                                      }
                        $$=it->second;
    } 
   ;
%%
