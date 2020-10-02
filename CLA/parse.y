%error-verbose
//%define parse.error verbose
%{ 

#include "NodeTree.h"
#include "ExternFunctions.h"
#include "bp_a.h"
#include <math.h>
#include "stdlib.h"
#include <iostream>
#include <string>
#include <map>
#include <list>
#include <vector>
#include <iterator>

//#define _CLV_
#ifdef _CLV_
#define DEBUG(a) std::cout<<a
#else
#define DEBUG(a)
#endif

//#define ERRBUG(a) std::cout<<a
#define ERRBUG(a) std::cerr<<a

extern int yylex();
extern int yylineno;
void yyerror(list<string> *parts,map<string,Node*>* NodeVars,map<string,vector<myParticle*> >* ListParts,
                map<int,Node*>* NodeCuts, map<int,Node*>* BinCuts, map<string,Node*>* ObjectCuts,
                vector<string>* Initializations , vector<double>* DataFormats, map <string, pair<vector<float>, bool> >* ListTables,
                map<string, vector<cntHisto> > *cntHistos, const char *s) { 
                   std::cerr << "ERROR: " << s << "\t" << " at line: " << yylineno <<  std::endl; } 
int cutcount;
int bincount;
using namespace std;
string tmp;
int pnum;
int dnum;
vector<float> tmpBinlist;
vector<float> tmpBoxlist;
vector<myParticle*> CombiParticle;
vector<myParticle*> TmpParticle;
vector<myParticle*> AliasList;
vector<myParticle*> TmpParticle1;//to be used for list of 2 particles
vector<myParticle*> TmpParticle2;//to be used for list of 3 particles
vector<Node*> TmpCriteria;
vector<Node*> TmpIDList;
vector<float> chist_a, chist_stat_p, chist_stat_n, chist_syst_p, chist_syst_n;
std::string current_cntHistDef;
std::map< std::string, unordered_set<int>  >SearchNode::FORBIDDEN_INDEX_LIST; 
std::map< std::string, double > SFuncNode::BUFFERED_VALUES; 
std::map< int, vector<myParticle *> > BPdbxA::particleBank;

//modify types to ints in myParticle => Done
//see how to give input to yyparse and get output -> DONE
//read file
//avoid global variables
//view input
%}
%union {
        Node* node;
       double real;
          int integer;
	char* s;//ADD POINTER TO NODE unique_ptr?
}
//%define parse.lac full
//%define parse.error verbose

%parse-param {std::list<std::string> *parts}
%parse-param {std::map<std::string,Node*>* NodeVars}
%parse-param {std::map<std::string,std::vector<myParticle*> >* ListParts}
%parse-param {std::map<int,Node*>* NodeCuts}
%parse-param {std::map<int,Node*>* BinCuts}
%parse-param {std::map<std::string,Node*>* ObjectCuts}
%parse-param {std::vector<std::string>* Initializations}
%parse-param {std::vector<double>* DataFormats}
%parse-param {std::map<std::string,std::pair<std::vector<float>, bool> >* ListTables}
%parse-param {std::map<std::string, std::vector<cntHisto> >* cntHistos}
%token COUNTSFORMAT COUNTS ERR_SYST ERR_STAT PROCESS
%token PAPEXPERIMENT PAPID PAPPUBLICATION PAPSQRTS PAPLUMI PAPARXIV PAPHEPDATA PAPDOI PAPTITLE
%token DEF CMD HISTO OBJ ALGO WEIGHT REJEC 
%token TABLE BINS TABLETYPE ERRORS NVARS ADLINFO
%token ELE MUO LEP TAU PHO JET BJET QGJET NUMET METLV GEN //particle types
%token TRGE TRGM SKPE SKPH SAVE
%token LVLO ATLASOD CMSOD DELPHES FCC LHCO
%token PHI ETA RAP ABSETA PT PZ NBF DR DPHI DETA //functions
%token NUMOF HT METMWT MWT MET ALL LEPSF BTAGSF PDGID  XSLUMICORRSF//simple funcs
%token DEEPB FJET MSOFTD TAU1 TAU2 TAU3 // razor additions
%token RELISO TAUISO DXY DZ SOFTID ISBTAG ISCTAG ISTAUTAG RELISOALL PFRELISO03ALL
%token IDDECAYMODE IDISOTIGHT IDANTIELETIGHT IDANTIMUTIGHT
%token TIGHTID PUID GENPARTIDX DECAYMODE
%token FMEGAJETS FMR FMTR FMT FMTAUTAU FMT2 // RAZOR external functions
%token FHEMISPHERE //hemisphere external function
%token MINIMIZE MAXIMIZE  APPLYHM
%token VERT VERX VERY VERZ VERTR STATUS CONSTITS
%token PERM COMB SORT TAKE UNION SUM ADD
%token ASCEND DESCEND ALIAS PM HLT_ISO_MU
%token <real> PNB
%token <real> NB 
%token <integer> INT
%token <s> ID HID 
%token SIN COS TAN ABS SQRT EXP LOG HSTEP SINH COSH TANH
%token OR AND 
%token MIN MAX
%token TRUE FALSE
%token LT GT LE GE EQ NE IRG ERG
%left OR
%left AND
%token NOT 
%nonassoc LT GT LE GE EQ NE IRG ERG
%left '+' '-'
%left '*' '/'
%right '?'
%right Unary
%right '^'
%type <integer> index bool
%type <node> e function condition action ifstatement
%type <s> particule particules list2 list3 description
%type <s> LEPTON
%type <s> ERRTYPE
%type <real> NUMBER
%%
input : initializations countformats definitions objects commands 
      | initializations countformats objects definitions  commands 
      | initializations countformats objects definitions objects commands 
      | initializations countformats definitions objects definitions  commands 
      ;
initializations : initializations initialization 
        | 
        ;
initialization :  TRGE  '=' INT {DataFormats->at(0)=$3; }
                | TRGM  '=' INT {DataFormats->at(1)=$3; }
                | SKPH  '=' INT {DataFormats->at(3)=$3; }
                | SKPE  '=' INT {DataFormats->at(2)=$3; }
                | ADLINFO ID { }
                | PAPTITLE description { }
                | PAPEXPERIMENT ID { }
                | PAPID description { }
                | PAPPUBLICATION description { }
                | PAPSQRTS NUMBER { }
                | PAPLUMI NUMBER { }
                | PAPARXIV description { }
                | PAPDOI description { }
                | PAPHEPDATA description { }
                ;
definitions : definitions definition 
            | 
            ;

countformats : countformats countformat
             |
             ;

countformat : COUNTSFORMAT ID { DEBUG($2<<" is a new format type\n"); current_cntHistDef=$2; }
            | PROCESS ID ',' description  { DEBUG($2<<" has name "<< $4 <<" without err \n"); 
               cntHisto ahist;
                        ahist.cH_name=$2;
                        ahist.cH_title=$4;
                        ahist.cH_StatErr=0;
                        ahist.cH_SystErr=0;
               (*cntHistos)[current_cntHistDef].push_back(ahist);
              } // no err
            | PROCESS ID ',' description ',' ERRTYPE ',' ERRTYPE { 
               DEBUG($2<<" has name "<< $4 <<" err1:"<< $6<<" err2:"<< $8<<" \n"); 
               cntHisto ahist;
                        ahist.cH_name=$2;
                        ahist.cH_title=$4;
                        ahist.cH_StatErr=$6;
                        ahist.cH_SystErr=$8;
               (*cntHistos)[current_cntHistDef].push_back(ahist);
              }
            ;
NUMBER : INT { $$ = (float)$1; } 
       | NB  { $$ = $1; }
       ;
LEPTON : ELE {$$="ELE";} | MUO {$$="MUO";} | TAU {$$="TAU";} ;
ERRTYPE: ERR_SYST { $$="ERR_SYST";} | ERR_STAT { $$="ERR_STAT";}

bool: TRUE {$$ = 1;} | FALSE {$$ =  0;} ;

definition : DEF ID  '=' particules {  DEBUG($2<<" will be defined as a new particle.\n");
                                        pnum=0;
                                        map<string,vector<myParticle*> >::iterator it ;
                                        string name = $2;
                                        it = ListParts->find(name);
                                        if(it != ListParts->end()) {
                                                DEBUG(name<<" : ");
                                                yyerror(NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,"Particule already defined");
                                                YYERROR;//stops parsing if variable already defined
                                        }
                                        parts->push_back(name+" : "+$4);
                                        vector<myParticle*> newList;
                                        TmpParticle.swap(newList);
                                        ListParts->insert(make_pair(name,newList));
				}
            | DEF ID '=' CONSTITS list2 {  DEBUG($2<<" will be defined as the children of particles.\n");
                                   pnum=0;
                                   string name = $2;
                                   map<string,vector<myParticle*> >::iterator itn;
                                   itn = ListParts->find(name);
                                   if(itn != ListParts->end()) {
                                           DEBUG(name<<" : ");
                                           yyerror(NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,"Particule already defined");
                                           YYERROR;//stops parsing if variable already defined
                                   }
                                  vector<myParticle*> newListM; TmpParticle1.swap(newListM);
                                  vector<myParticle*> newListC; TmpParticle.swap(newListC);
                                  string partMname=newListM[0]->collection;
                                  string partCname=newListC[0]->collection;
                              //    DEBUG( partMname <<" has child "<< partCname <<"\n");
                                  std::cout<< partMname <<" has child "<< partCname <<"\n";
                                  map<string, Node *>::iterator itM = ObjectCuts->find(partMname);
                                  map<string, Node *>::iterator itC = ObjectCuts->find(partCname);
                                  if(itM == ObjectCuts->end()) {
                                           ERRBUG(partMname<<" : ") ;
                                           yyerror(NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,"Object not defined");
                                           YYERROR;
                                  }
                                  if(itC == ObjectCuts->end()) {
                                           ERRBUG(partCname<<" : ") ;
                                           yyerror(NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,"Object not defined");
                                           YYERROR;
                                  }
                                  string nameo=name+"internalObj";
                                  Node* previous=itC->second; //--------- pdgID should be the same
                                  Node* c1= new SFuncNode(getIndex, newListC[0]->type, partMname, itC->second);
//--------------------------------------------------------   fun            id          str      Node*
                                  Node* n1= new UnaryAONode(abs,c1,"kill");
                                  vector<Node*> newCriList; // criterion list, will only have 1 selection                             
                                  newCriList.push_back(n1);
                                  Node* obj=new ObjectNode(nameo,previous,NULL,newCriList,nameo);
                                  ObjectCuts->insert(make_pair(nameo,obj) );

// now define the 0th particle of new obj 
                                  myParticle* a = new myParticle;
                                  a->type = newListC[0]->type; a->index =0; a->collection = nameo;
                                  vector<myParticle*> newList;
                                  newList.push_back(a);
// insert the 0th element of new obj                               
                                  ListParts->insert(make_pair(name,newList));
                                  parts->push_back(name+" : "+partCname);

				}
            | DEF ID '=' ADD '(' particule ')' {  DEBUG($2<<" will be defined as the ADDition of particles.\n");
                                   pnum=0;
                                   string name = $2;
                                   map<string,vector<myParticle*> >::iterator itn;
                                   itn = ListParts->find(name);
                                   if(itn != ListParts->end()) {
                                           DEBUG(name<<" : ");
                                           yyerror(NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,"Particule already defined");
                                           YYERROR;//stops parsing if variable already defined
                                   }
                                   vector<myParticle*> newpList;
                                   TmpParticle.swap(newpList);
                                   string partname=newpList[0]->collection;
                                   int ptype=newpList[0]->type; // type is JETS or FJETS etc..
                                   map<string, Node *>::iterator it;
                                   it = ObjectCuts->find(partname); // find from which object we are making the new one
                                   if(it == ObjectCuts->end()) {
                                           ERRBUG($6<<" : ") ;
                                           yyerror(NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,"Object not defined");
                                           YYERROR;
                                   } else {
                                           string nameo=name+"internalObj";
                                           Node* previous=it->second;
                                           Node* v0= new ValueNode(1);
                                           Node* c1= new SFuncNode(userfuncA, sumobj, ptype, nameo, it->second);
                                           Node* n1= new BinaryNode(eq,c1,v0,"==");
                                           vector<Node*> newCriList; // criterion list, will only have 1 selection                             
                                           newCriList.push_back(n1);
                                           Node* obj=new ObjectNode(nameo,previous,NULL,newCriList,nameo);
                                           ObjectCuts->insert(make_pair(nameo,obj));
// now define the 0th particle of new obj 
                                           myParticle* a = new myParticle;
                                           a->type = ptype; a->index =0; a->collection = nameo;
                                           vector<myParticle*> newList;
                                           newList.push_back(a);
// insert the 0th element of new obj                               
                                           ListParts->insert(make_pair(name,newList));
                                           parts->push_back(name+" : "+$6);
                                   }
            }
            |  DEF  ID  ':'  particules { DEBUG($2<<" will be defined as a new particle.\n");
                                        pnum=0;
                                        map<string,vector<myParticle*> >::iterator it ;
                                        string name = $2;
                                        it = ListParts->find(name);
                                        if(it != ListParts->end()) {
                                                DEBUG(name<<" : ");
                                                yyerror(NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,"Particule already defined");
                                                YYERROR;//stops parsing if variable already defined
                                        }
                                        if (TmpParticle.size() == 0) { // was wrong rule match
                                         cout << "MAGIC needed. We shouldnt be here. " << $2<< "\n";
                                         YYERROR;//stops parsing if variable already defined
//                                       map<string, Node*>::iterator ito;
//                                       ito= NodeVars->find(name);
//                                       if(ito!= NodeVars->end()) {
//                                              DEBUG(name<<" : ");
//                                              yyerror(NULL,NULL,NULL,NULL,NULL,NULL, NULL,NULL,NULL,NULL,"Variable already defined");
//                                              YYERROR;//stops parsing if variable already defined
//                                       }
//                                      vector<Node*> newList; //empty
//                                      TmpCriteria.swap(newList);
//                                      cout << "got #magic:"<<newList.size()<<"\n";
//                                      for (int np=0; np<newList.size(); np++) {
//                                               newList[np]->display();
//                                               cout <<"-----------------\n";
//                                               NodeVars->insert(make_pair(name,newList[np]));
//                                      }
//                                        
                                        } else {
                                         parts->push_back(name+" : "+$4);
                                         vector<myParticle*> newList;
                                         TmpParticle.swap(newList);
                                         ListParts->insert(make_pair(name,newList));
                                        }
                                }
           |  DEF ID  ':' e { DEBUG($2<<" is being worked on as a node variable.\n");
                                        pnum=0;
                                        map<string, Node*>::iterator it ;
                                        string name = $2;
                                        it = NodeVars->find(name);
                                        if(it != NodeVars->end()) {
                                                DEBUG(name<<" : ");
                                                yyerror(NULL,NULL,NULL,NULL,NULL,NULL, NULL,NULL,NULL,NULL,"Variable already defined");
                                                YYERROR;//stops parsing if variable already defined
                                        }
                                        if ( TmpParticle.size()>0) { // was wrong rule match
                                          cout << " still recovering...\t";
                                          vector<myParticle*> newList;
                                          TmpParticle.swap(newList);
                                          ListParts->insert(make_pair(name,newList));
                                          cout << "Done .\n";
                                        } else {
                                          NodeVars->insert(make_pair(name,$4));
                                        }
			     }
          |  DEF ID  '=' e { DEBUG($2<< " is being worked on as a node variable.\n");
                                        pnum=0;
                                        map<string, Node*>::iterator it ;
                                        string name = $2;
                                        it = NodeVars->find(name);
                                        if(it != NodeVars->end()) {
                                                DEBUG(name<<" : ");
                                                yyerror(NULL,NULL,NULL,NULL,NULL,NULL, NULL,NULL,NULL,NULL,"Variable already defined");
                                                YYERROR;//stops parsing if variable already defined
                                        }
                                        if ( TmpParticle.size()>0) { // was wrong rule match
                                          cout << " still recovering...\t";
                                          vector<myParticle*> newList;
                                          TmpParticle.swap(newList);
                                          ListParts->insert(make_pair(name,newList));
                                          cout << "Done .\n";
                                        } else {
                                          NodeVars->insert(make_pair(name,$4));
                                        }
			      }
    	    | TABLE ID TABLETYPE ID NVARS INT ERRORS bool boxlist {
                               DEBUG("TABLE "<< $2  << "Nvars:"<< $6<< "Err:"<< $8<< "\n");
                               map<string, pair< vector<float>, bool>  >::iterator itt;
                               string name = $2;
                               itt = ListTables->find(name);
                               if(itt != ListTables->end()) {
                                      DEBUG(name<<" : ");
                                      yyerror(NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,"Table already defined");
                                      YYERROR;//stops parsing if variable already defined
                               }
                               vector <float> newBinlist;
                               tmpBinlist.swap(newBinlist);
                               ListTables->insert(make_pair(name, make_pair(newBinlist, $8) ));
            }  
        ;
//---------------------------------------
function : '{' particules '}' 'm' {    vector<myParticle*> newList;
                                       TmpParticle.swap(newList);
                                       $$=new FuncNode(Mof,newList,"m");
                                       DEBUG("Mass function with:"<< newList.size() <<" particles.\n");
                                  }
         | 'm' '(' particules ')' {    vector<myParticle*> newList;
                                       TmpParticle.swap(newList);
                                       $$=new FuncNode(Mof,newList,"m");
                                       DEBUG("Mass function\n");
                                  }
         | 'q' '(' particules ')' {    vector<myParticle*> newList;
                                       TmpParticle.swap(newList);//then add newList to node
                                       $$=new FuncNode(Qof,newList,"q");
                                  }
         | '{' particules '}' 'q' {    vector<myParticle*> newList;
                                       TmpParticle.swap(newList);//then add newList to node
                                       $$=new FuncNode(Qof,newList,"q");
                                  }
        | CONSTITS '(' particules ')' {vector<myParticle*> newList;
                                       TmpParticle.swap(newList);//then add newList to node
                                       $$=new FuncNode(CCountof,newList,"ChildCountOf");
                                  } 
        | '{' particules '}' CONSTITS {vector<myParticle*> newList;
                                       TmpParticle.swap(newList);//then add newList to node
                                       $$=new FuncNode(CCountof,newList,"ChildCountOf");
                                  } 
         | PDGID '(' particules ')' {  vector<myParticle*> newList;
                                       TmpParticle.swap(newList);//then add newList to node
                                       if (TmpCriteria.size() < 1) {
                                        $$=new FuncNode(pdgIDof,newList,"pdgID");
                                       } else {
                                        $$=new FuncNode(pdgIDof,newList,"pdgID", TmpCriteria[0]);
                                       }
                                  }
         | '{' particules '}' PDGID {  vector<myParticle*> newList;
                                       TmpParticle.swap(newList);//then add newList to node
                                       $$=new FuncNode(pdgIDof,newList,"pdgID");
                                  }
         | '{' particules '}' 'P' {    vector<myParticle*> newList;
                                       TmpParticle.swap(newList);
                                       $$=new FuncNode(Pof,newList,"p");
                                  }
         | 'P' '(' particules ')' {    vector<myParticle*> newList;
                                       TmpParticle.swap(newList);
                                       $$=new FuncNode(Pof,newList,"p");
                                  }
         | '{' particules '}' 'E' {     vector<myParticle*> newList;
                                        TmpParticle.swap(newList);
                                        $$=new FuncNode(Eof,newList,"e");
                                  }
         | 'E' '(' particules ')' {     vector<myParticle*> newList;
                                        TmpParticle.swap(newList);
                                        $$=new FuncNode(Eof,newList,"e");
                                  }
         | '{' particules '}' ISTAUTAG {vector<myParticle*> newList;
                                        TmpParticle.swap(newList);
                                        $$=new FuncNode(isTauTag,newList,"TauTAG");
                                    }
         | ISTAUTAG '(' particules ')' {vector<myParticle*> newList;
                                        TmpParticle.swap(newList);
                                        $$=new FuncNode(isTauTag,newList,"TauTAG");
                                    }
         | '{' particules '}' ISCTAG {  vector<myParticle*> newList;
                                        TmpParticle.swap(newList);
                                        $$=new FuncNode(isBTag,newList,"CTAG");
                                    }
         | ISCTAG '(' particules ')' {  vector<myParticle*> newList;
                                        TmpParticle.swap(newList);
                                        $$=new FuncNode(isBTag,newList,"CTAG");
                                    }
         | '{' particules '}' ISBTAG {  vector<myParticle*> newList;
                                        TmpParticle.swap(newList);
                                        $$=new FuncNode(isBTag,newList,"BTAG");
                                    }
         | ISBTAG '(' particules ')' {  vector<myParticle*> newList;
                                        TmpParticle.swap(newList);
                                        $$=new FuncNode(isBTag,newList,"BTAG");
                                    }
         | '{' particules '}' DEEPB {   vector<myParticle*> newList;
                                        TmpParticle.swap(newList);
                                        $$=new FuncNode(DeepBof,newList,"deepB");
                                    }
         | DEEPB '(' particules ')' {   vector<myParticle*> newList;
                                        TmpParticle.swap(newList);
                                        $$=new FuncNode(DeepBof,newList,"deepB");
                                    }
         | '{' particules '}' MSOFTD {  vector<myParticle*> newList;
                                        TmpParticle.swap(newList);
                                        $$=new FuncNode(MsoftDof,newList,"msoftD");
                                  }
         | MSOFTD '(' particules ')' {  vector<myParticle*> newList;
                                        TmpParticle.swap(newList);
                                        $$=new FuncNode(MsoftDof,newList,"msoftD");
                                  }
         | '{' particules '}' TAU1 {    vector<myParticle*> newList;
                                        TmpParticle.swap(newList);
                                        $$=new FuncNode(tau1of,newList,"tau1");
                                  }
         | TAU1 '(' particules ')' {    vector<myParticle*> newList;
                                        TmpParticle.swap(newList);
                                        $$=new FuncNode(tau1of,newList,"tau1");
                                  }
         | '{' particules '}' TAU2 {    vector<myParticle*> newList;
                                        TmpParticle.swap(newList);
                                        $$=new FuncNode(tau2of,newList,"tau2");
                                  }
         | TAU2 '(' particules ')' {    vector<myParticle*> newList;
                                        TmpParticle.swap(newList);
                                        $$=new FuncNode(tau2of,newList,"tau2");
                                  }
         | '{' particules '}' TAU3 {    vector<myParticle*> newList;
                                        TmpParticle.swap(newList);
                                        $$=new FuncNode(tau3of,newList,"tau3");
                                  }
         | TAU3 '(' particules ')' {    vector<myParticle*> newList;
                                        TmpParticle.swap(newList);
                                        $$=new FuncNode(tau3of,newList,"tau3");
                                  }
         | '{' particules '}' DXY {     vector<myParticle*> newList;
                                        TmpParticle.swap(newList);
                                        $$=new FuncNode(dxyof,newList,"dxy");
                                  }
         | DXY '(' particules ')' {     vector<myParticle*> newList;
                                        TmpParticle.swap(newList);
                                        $$=new FuncNode(dxyof,newList,"dxy");
                                  }
         | '{' particules '}' DZ {      vector<myParticle*> newList;
                                        TmpParticle.swap(newList);
                                        $$=new FuncNode(dzof,newList,"dz");
                                  }
         | DZ '(' particules ')' {      vector<myParticle*> newList;
                                        TmpParticle.swap(newList);
                                        $$=new FuncNode(dzof,newList,"dz");
                                  }
         | '{' particules '}' VERTR {   vector<myParticle*> newList;
                                        TmpParticle.swap(newList);
                                        $$=new FuncNode(vtrof,newList,"vtr");
                                  }
         | VERTR '(' particules ')' {   vector<myParticle*> newList;
                                        TmpParticle.swap(newList);
                                        $$=new FuncNode(vtrof,newList,"vtr");
                                  }
         | '{' particules '}' VERZ {    vector<myParticle*> newList;
                                        TmpParticle.swap(newList);
                                        $$=new FuncNode(vzof,newList,"vz");
                                  }
         | VERZ '(' particules ')' {    vector<myParticle*> newList;
                                        TmpParticle.swap(newList);
                                        $$=new FuncNode(vzof,newList,"vz");
                                  }
         | '{' particules '}' VERY {    vector<myParticle*> newList;
                                        TmpParticle.swap(newList);
                                        $$=new FuncNode(vyof,newList,"vy");
                                  }
         | VERY '(' particules ')' {    vector<myParticle*> newList;
                                        TmpParticle.swap(newList);
                                        $$=new FuncNode(vyof,newList,"vy");
                                  }
         | '{' particules '}' VERX {    vector<myParticle*> newList;
                                        TmpParticle.swap(newList);
                                        $$=new FuncNode(vxof,newList,"vx");
                                  }
         | VERX '(' particules ')' {    vector<myParticle*> newList;
                                        TmpParticle.swap(newList);
                                        $$=new FuncNode(vxof,newList,"vx");
                                  }
         | '{' particules '}' VERT {    vector<myParticle*> newList;
                                        TmpParticle.swap(newList);
                                        $$=new FuncNode(vtof,newList,"vt");
                                  }
         | VERT '(' particules ')' {    vector<myParticle*> newList;
                                        TmpParticle.swap(newList);
                                        $$=new FuncNode(vtof,newList,"vt");
                                  }
         | '{' particules '}' RELISO {  vector<myParticle*> newList;
                                        TmpParticle.swap(newList);
                                        $$=new FuncNode(relisoof,newList,"miniPFRelIsoAll");
                                  }
         | RELISO '(' particules ')' {  vector<myParticle*> newList;
                                        TmpParticle.swap(newList);
                                        $$=new FuncNode(relisoof,newList,"miniPFRelIsoAll");
                                  }
         | '{' particules '}' RELISOALL {  vector<myParticle*> newList;
                                        TmpParticle.swap(newList);
                                        $$=new FuncNode(relisoallof,newList,"relIsoall");
                                  }
         | RELISOALL '(' particules ')' {  vector<myParticle*> newList;
                                        TmpParticle.swap(newList);
                                        $$=new FuncNode(relisoallof,newList,"relIsoall");
                                  }
         | '{' particules '}' PFRELISO03ALL {  vector<myParticle*> newList;
                                        TmpParticle.swap(newList);
                                        $$=new FuncNode(pfreliso03allof,newList,"pfRelIso03all");
                                  }
         | PFRELISO03ALL '(' particules ')' {  vector<myParticle*> newList;
                                        TmpParticle.swap(newList);
                                        $$=new FuncNode(pfreliso03allof,newList,"pfRelIso03all");
                                  }
         | '{' particules '}' IDDECAYMODE {  vector<myParticle*> newList;
                                        TmpParticle.swap(newList);
                                        $$=new FuncNode(iddecaymodeof,newList,"idDecayMode");
                                  }
         | IDDECAYMODE '(' particules ')' {  vector<myParticle*> newList;
                                        TmpParticle.swap(newList);
                                        $$=new FuncNode(iddecaymodeof,newList,"idDecayMode");
                                     }
         | '{' particules '}' IDISOTIGHT {  vector<myParticle*> newList;
                                        TmpParticle.swap(newList);
                                        $$=new FuncNode(idisotightof,newList,"idIsoTight");
                                  }
         | IDISOTIGHT '(' particules ')' {  vector<myParticle*> newList;
                                        TmpParticle.swap(newList);
                                        $$=new FuncNode(idisotightof,newList,"idIsoTight");
                                  }
         | '{' particules '}' IDANTIELETIGHT {  vector<myParticle*> newList;
                                        TmpParticle.swap(newList);
                                        $$=new FuncNode(idantieletightof,newList,"idAntiEleTight");
                                  }
         | IDANTIELETIGHT '(' particules ')' {  vector<myParticle*> newList;
                                        TmpParticle.swap(newList);
                                        $$=new FuncNode(idantieletightof,newList,"idAntiEleTight");
                                  }
         | '{' particules '}' IDANTIMUTIGHT {  vector<myParticle*> newList;
                                        TmpParticle.swap(newList);
                                        $$=new FuncNode(idantimutightof,newList,"idAntiMuTight");
                                  }
         | IDANTIMUTIGHT '(' particules ')' {  vector<myParticle*> newList;
                                        TmpParticle.swap(newList);
                                        $$=new FuncNode(idantimutightof,newList,"idAntiMuTight");

                                  }
         | '{' particules '}' TIGHTID {  vector<myParticle*> newList;
                                        TmpParticle.swap(newList);
                                        $$=new FuncNode(tightidof,newList,"tightId");
                                  }
         | TIGHTID '(' particules ')' {  vector<myParticle*> newList;
                                        TmpParticle.swap(newList);
                                        $$=new FuncNode(tightidof,newList,"tightId");
                                  }
         | '{' particules '}' PUID {  vector<myParticle*> newList;
                                        TmpParticle.swap(newList);
                                        $$=new FuncNode(puidof,newList,"puId");
                                  }
         | PUID '(' particules ')' {  vector<myParticle*> newList;
                                        TmpParticle.swap(newList);
                                        $$=new FuncNode(puidof,newList,"puId");
                                  }
         | '{' particules '}' GENPARTIDX {  vector<myParticle*> newList;
                                        TmpParticle.swap(newList);
                                        $$=new FuncNode(genpartidxof,newList,"genPartIdx");
                                  }
         | GENPARTIDX '(' particules ')' {  vector<myParticle*> newList;
                                        TmpParticle.swap(newList);
                                        $$=new FuncNode(genpartidxof,newList,"genPartIdx");
                                  }
         | '{' particules '}' DECAYMODE {  vector<myParticle*> newList;
                                        TmpParticle.swap(newList);
                                        $$=new FuncNode(decaymodeof,newList,"decayMode");
                                  }
         | DECAYMODE '(' particules ')' {  vector<myParticle*> newList;
                                        TmpParticle.swap(newList);
                                        $$=new FuncNode(decaymodeof,newList,"decayMode");
                                  }

         | '{' particules '}' SOFTID {  vector<myParticle*> newList;
                                        TmpParticle.swap(newList);
                                        $$=new FuncNode(softIdof,newList,"softId");
                                  }
         | SOFTID '(' particules ')' {  vector<myParticle*> newList;
                                        TmpParticle.swap(newList);
                                        $$=new FuncNode(softIdof,newList,"softId");
                                  }
         | '{' particules '}' STATUS {  vector<myParticle*> newList;
                                        TmpParticle.swap(newList);
                                        $$=new FuncNode(softIdof,newList,"status"); // status and softID are same attrib
                                  }
         | STATUS '(' particules ')' {  vector<myParticle*> newList;
                                        TmpParticle.swap(newList);
                                        $$=new FuncNode(softIdof,newList,"status"); // status and softID are same attrib
                                  }
         | '{' particules '}' TAUISO {  vector<myParticle*> newList;
                                        TmpParticle.swap(newList);
                                        $$=new FuncNode(tauisoof,newList,"dMVAnewDM2017v2");
                                  }
         | TAUISO '(' particules ')' {  vector<myParticle*> newList;
                                        TmpParticle.swap(newList);
                                        $$=new FuncNode(tauisoof,newList,"dMVAnewDM2017v2");
                                  }
         | '{' particules '}' PHI {     vector<myParticle*> newList;
                                        TmpParticle.swap(newList);
                                        $$=new FuncNode(Phiof,newList,"phi");
                                  }
         | PHI '(' particules ')' {     vector<myParticle*> newList;
                                        TmpParticle.swap(newList);
                                        $$=new FuncNode(Phiof,newList,"phi");
                                  }
         | '{' particules '}' RAP {     vector<myParticle*> newList;
                                        TmpParticle.swap(newList);
                                        $$=new FuncNode(Rapof,newList,"rap");
                                  }
         | RAP '(' particules ')' {     vector<myParticle*> newList;
                                        TmpParticle.swap(newList);
                                        $$=new FuncNode(Rapof,newList,"rap");
                                  }
         | '{' particules '}' ETA {     vector<myParticle*> newList;
                                        DEBUG("Eta with "<<TmpParticle.size()<<" particles\n");
                                        for (int ij=0; ij<TmpParticle.size(); ij++){
                                          DEBUG("Col:"<<TmpParticle[ij]->collection<< " type:"<<TmpParticle[ij]->type<<" idx:"<<TmpParticle[ij]->index<<"\n");
                                        }
                                        TmpParticle.swap(newList);
                                        $$=new FuncNode(Etaof,newList,"eta");
                                  }
         | ETA '(' particules ')' {     vector<myParticle*> newList;
                                        TmpParticle.swap(newList);
                                        $$=new FuncNode(Etaof,newList,"eta");
                                  }
         | ABSETA '(' particules ')' {  vector<myParticle*> newList;
                                        TmpParticle.swap(newList);
                                        $$=new FuncNode(AbsEtaof,newList,"abseta");
                                     }
         | '{' particules '}' ABSETA {  vector<myParticle*> newList;
                                        TmpParticle.swap(newList);
                                        $$=new FuncNode(AbsEtaof,newList,"abseta");
                                     }
         | '{' particules '}' PT {      vector<myParticle*> newList;
                                        TmpParticle.swap(newList);
                                        $$=new FuncNode(Ptof,newList,"pt");
                                 }
         | PT '(' particules ')' {      vector<myParticle*> newList;
                                        TmpParticle.swap(newList);
                                        $$=new FuncNode(Ptof,newList,"pt");
                                 }
         | '{' particules '}' PZ {      vector<myParticle*> newList;
                                        TmpParticle.swap(newList);
                                        $$=new FuncNode(Pzof,newList,"pz");
                                 }
         | PZ '(' particules ')' {      vector<myParticle*> newList;
                                        TmpParticle.swap(newList);
                                        $$=new FuncNode(Pzof,newList,"pz");
                                 }
         | '{' particules '}' NBF {     vector<myParticle*> newList;
                                        TmpParticle.swap(newList);
                                        $$=new FuncNode(nbfof,newList,"nbf");
                                  }
         | NBF '(' particules ')' {     vector<myParticle*> newList;
                                        TmpParticle.swap(newList);
                                        $$=new FuncNode(nbfof,newList,"nbf");
                                  }
//---------------------------------------
         | list2 DR { 			vector<myParticle*> newList;
                                        TmpParticle.swap(newList);
                                        vector<myParticle*> newList1;
                                        TmpParticle1.swap(newList1);
                                        $$=new LFuncNode(dR,newList1,newList,"dR");
                   }
         | DR list2 {            	vector<myParticle*> newList;
                                        TmpParticle.swap(newList);
                                        vector<myParticle*> newList1;
                                        TmpParticle1.swap(newList1);
                                        $$=new LFuncNode(dR,newList1,newList,"dR");
                   }
        | list2 DPHI { 			vector<myParticle*> newList;
                                        TmpParticle.swap(newList);
                                        vector<myParticle*> newList1;
                                        TmpParticle1.swap(newList1);
                                        $$=new LFuncNode(dPhi,newList1,newList,"dPhi");
                    }
        | DPHI list2 { 			vector<myParticle*> newList;
                                        TmpParticle.swap(newList);
                                        vector<myParticle*> newList1;
                                        TmpParticle1.swap(newList1);
                                        $$=new LFuncNode(dPhi,newList1,newList,"dPhi");
                    }
        | list2 DETA { 			vector<myParticle*> newList;
                                        TmpParticle.swap(newList);
                                        vector<myParticle*> newList1;
                                        TmpParticle1.swap(newList1);
                                        $$=new LFuncNode(dEta,newList1,newList,"dEta");
                    }
        | DETA list2 { 			vector<myParticle*> newList;
                                        TmpParticle.swap(newList);
                                        vector<myParticle*> newList1;
                                        TmpParticle1.swap(newList1);
                                        $$=new LFuncNode(dEta,newList1,newList,"dEta");
                    }
        | NUMOF '(' ID ')'  {          map<string,vector<myParticle*> >::iterator itdef=ListParts->find($3);
                                       map<string,Node*>::iterator it = ObjectCuts->find($3);
                                       if (itdef == ListParts->end() && (it == ObjectCuts->end()) ) {
                                           std::string message = "OBJect not defined: ";
                                           message += $3;
                                           yyerror(NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,message.c_str());
                                           YYERROR;
                                       } else {
                                           if (it != ObjectCuts->end()) {
                                            int type=((ObjectNode*)it->second)->type;
                                            $$=new SFuncNode(count, type, it->first, it->second);
                                           } else { // new type is defined using particle class summation
                                            vector<myParticle*> newList= itdef->second;
                                           }
                                       }
                           }
    | NUMOF '(' particules ')' {vector<myParticle*> newList;
                                     TmpParticle.swap(newList);
                                     DEBUG("Nb:"<<newList.size()<< " t:"<<newList[0]->type<<" c:"<<newList[0]->collection<<"\n");
                                     $$=new SFuncNode(count, newList[0]->type, newList[0]->collection);  
                                   }
    | FMT2 list3 {                  vector<myParticle*> newList;
                                    TmpParticle.swap(newList);
                                    vector<myParticle*> newList1;
                                    TmpParticle1.swap(newList1);
                                    vector<myParticle*> newList2;
                                    TmpParticle2.swap(newList2);
                                    int type=newList2[0]->type; // type is JETS or FJETS etc..
                                    $$=new SFuncNode(userfuncE, fMT2, type, "XXX" , newList2,  newList1, newList);
      }
    | SUM '(' ID  ')'   {      map<string,Node*>::iterator it = ObjectCuts->find($3);
                               if(it == ObjectCuts->end()) {
                                        std::string message = "Object not defined: ";
                                        message += $3;
                                        yyerror(NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,message.c_str());
                                        YYERROR;
                               } else {
                                       int type=((ObjectNode*)it->second)->type; // type is JETS or FJETS etc..
                                       $$=new SFuncNode(userfuncA, sumobj, type, "SUMOBJ" , it->second);
                               }
                       }
    | FHEMISPHERE '(' ID ',' INT ',' INT ')' { map<string,Node*>::iterator it = ObjectCuts->find($3);
                               if(it == ObjectCuts->end()) {
                                        std::string message = "Object not defined: ";
                                        message += $3;
                                        yyerror(NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,message.c_str());
                                        YYERROR;
                               } else {
                                      int seed =$5;
                                      int assoc=$7;
                                      //int type=((ObjectNode*)it->second)->type; // type is JETS or FJETS etc..
                                      int type=100*seed+assoc;
                                      $$=new SFuncNode(userfuncA, fhemisphere, type, "HEMISPHERE" , it->second);
                               }
                       }
    | FMEGAJETS '(' ID ')' { map<string,Node*>::iterator it = ObjectCuts->find($3);
                               if(it == ObjectCuts->end()) {
                                        std::string message = "Object not defined: ";
                                        message += $3;
                                        yyerror(NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,message.c_str());
                                        YYERROR;
                               } else {
                                         int type=((ObjectNode*)it->second)->type; // type is JETS or FJETS etc..
                                         $$=new SFuncNode(userfuncA, fmegajets, type, "MEGAJETS" , it->second);
                               }
                       }
      | FMR '(' ID ')' {        map<string,Node*>::iterator it = ObjectCuts->find($3);
                                if(it == ObjectCuts->end()) {
                                         std::string message = "Object not defined: ";
                                         message += $3;
                                         yyerror(NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,message.c_str());
                                         YYERROR;
                                } else {
                                         int type=((ObjectNode*)it->second)->type; // type is JETS or FJETS etc..
                                         $$=new SFuncNode(userfuncB, fMR, type, $3 , it->second);
                                }
                       }

      | FMTR '(' ID ',' MET ')'{   map<string,Node*>::iterator it = ObjectCuts->find($3);
                                   if (it == ObjectCuts->end()) {
                                         std::string message = "Object not defined: ";
                                         message += $3;
                                         yyerror(NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,message.c_str());
                                         YYERROR;
                                   } else {
                                         int type=((ObjectNode*)it->second)->type; // type is JETS or FJETS etc..
                                         $$=new SFuncNode(userfuncC, fMTR, type, $3 , it->second);
                                   }
                               }
      | FMTR '(' ID ',' ID ')'{   map<string,Node*>::iterator it = ObjectCuts->find($3);
                                  map<string,vector<myParticle*> >::iterator it2 = ListParts->find($5);
                                  if (it == ObjectCuts->end()) {
                                         std::string message = "Object not defined: ";
                                         message += $3;
                                         yyerror(NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,message.c_str());
                                         YYERROR;
                                  } else if (it2 == ListParts->end() ) {
                                         std::string message = "Particle not defined: ";
                                         message += $5;
                                         yyerror(NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,message.c_str());
                                         YYERROR;
                                  } else {
                                         int type=((ObjectNode*)it->second)->type; // type is JETS or FJETS etc..
                                         $$=new SFuncNode(userfuncD, fMTR2, type, $3 , it2->second,  it->second);
                                  }
                       }
        | FMTAUTAU list3 {          vector<myParticle*> newList;
                                    TmpParticle.swap(newList);
                                    vector<myParticle*> newList1;
                                    TmpParticle1.swap(newList1);
                                    vector<myParticle*> newList2;
                                    TmpParticle2.swap(newList2);
                                    int type=newList2[0]->type; // type is JETS or FJETS etc..
//                                  cout<< "AAAAAAAAAAA" <<newList[0]->type<<"\n";
//                                  cout<< "BBBBBBBBBBB" <<newList1[0]->type<<"\n";
//                                  cout<< "CCCCCCCCCCC" <<newList2[0]->type<<"\n";
                                    $$=new SFuncNode(userfuncE, fMtautau, type, "XXX" , newList2,  newList1, newList);
                        }
        | HT { $$=new SFuncNode(ht,1,"JET"); }
        | HT '(' ID  ')' {
                                       map<string,Node*>::iterator it = ObjectCuts->find($3);
                                       if(it == ObjectCuts->end()) {
                                           std::string message = "Object not defined: ";
                                           message += $3;
                                           yyerror(NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,message.c_str());
                                           YYERROR;
                                       } else {
                                           int id=((ObjectNode*)it->second)->type;
                                           $$=new SFuncNode(ht,id, it->first, it->second);
                                       }
                         }
       | MET {  $$=new SFuncNode(met,1, "MET"); }
       | HLT_ISO_MU {$$=new SFuncNode(hlt_iso_mu,1, "HLT_IsoMu17_eta2p1_LooseIsoPFTau20"); }
       | ALL {  $$=new SFuncNode(all,1, "all"); }
        ;
//-------------------------------------------------------------------------
 e : e '+' e { $$=new BinaryNode(add,$1,$3,"+"); }
   | e '-' e { $$=new BinaryNode(sub,$1,$3,"-"); }
   | e '*' e { $$=new BinaryNode(mult,$1,$3,"*"); }
   | e '/' e { $$=new BinaryNode(div,$1,$3,"/"); }
   | e '^' e { $$=new BinaryNode(pow,$1,$3,"^"); } 	
   |'-' e %prec Unary { $$=new UnaryAONode(unaryMinu,$2,"-"); }
   | HSTEP '(' e ')' { $$=new UnaryAONode(hstep,$3,"hstep"); } //Heavyside step function 
   | SQRT '(' e ')'  { $$=new UnaryAONode(sqrt,$3,"sqrt"); }
   | ABS '(' e ')'   { $$=new UnaryAONode(abs,$3,"fabs"); }
   | COS '(' e ')'   { $$=new UnaryAONode(cos,$3,"cos"); }
   | SIN '(' e ')'   { $$=new UnaryAONode(sin,$3,"sin"); }
   | TAN '(' e ')'   { $$=new UnaryAONode(tan,$3,"tan"); }
   | SINH '(' e ')'  { $$=new UnaryAONode(sinh,$3,"sinh"); }
   | COSH '(' e ')'  { $$=new UnaryAONode(cosh,$3,"cosh"); }
   | TANH '(' e ')'  { $$=new UnaryAONode(tanh,$3,"tanh"); }
   | EXP '(' e ')'   { $$=new UnaryAONode(exp,$3,"exp"); }
   | LOG '(' e ')'   { $$=new UnaryAONode(log,$3,"log"); }
   | SUM '(' e ')' {DEBUG("\t SUM function\n"); $$=new LoopNode(sumof,$3,"sum"); }
   | MIN '(' e ')' {DEBUG("\t MIN function\n"); $$=new LoopNode(minof,$3,"min"); }
   | MAX '(' e ')' {DEBUG("\t MAX function\n"); $$=new LoopNode(maxof,$3,"max"); }
   | MIN '(' idlist ')' {  DEBUG("\t MIN function IMPLEMENTED\n");  
                           vector <Node*> newIDlist;
                           TmpIDList.swap(newIDlist);
                           $$=new LoopNode(minof,newIDlist,"min");
                        }
   | MAX '(' idlist ')' {  DEBUG("\t MAX function IMPLEMENTED\n");  
                           vector <Node*> newIDlist;
                           TmpIDList.swap(newIDlist);
                           $$=new LoopNode(maxof,newIDlist,"max");
                        }
   |'(' e ')' {   $$=$2; }
   | NB {  tmp=to_string($1); $$=new ValueNode($1);} 
   | INT {  $$=new ValueNode($1);} 
   | function {$$=$1; pnum=0;}
   //to make the difference between ID + ID and ID ID in particules ->create two maps
   | ID { //we want the original defintions as well
                DEBUG($1<<" is a node variable candidate\n");
                map<string, Node *>::iterator it;
                it = NodeVars->find($1);
                if(it != NodeVars->end()) {
                  $$=it->second;
                } else { cout<<"\t"<<$1<<"\t";
                   map<string, Node *>::iterator ito;
//                 for (ito=ObjectCuts->begin(); ito!=ObjectCuts->end(); ito++){
//                  cout <<"Map has Object:"<<ito->first << "-vs-"<< string($1)<<"-\n"; 
//                 }
                   ito = ObjectCuts->find(string($1));
                   if(ito == ObjectCuts->end()) { //we did search for $1 as an object, not found.
                     map<string,vector<myParticle*> >::iterator itp;
                     itp=ListParts->find($1);
                     if(itp==ListParts->end() ) {
                       yyerror(NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,"is NOT a known object nor variable, not even a particle!");
                       YYERROR;
                     } else {
                       cout<<" is a particle, we wrongly assumed it was a variable. trying to rectify...\n";
                       vector<myParticle*> newList= itp->second;
                       DEBUG("A particule, name : "<< $1 << "    type : " << newList[0]->type << "      index: " << newList[0]->index);
                       TmpParticle.insert(TmpParticle.end(), newList.begin(), newList.end());
                       $$=NULL;
                     }
                   } else { 
                     cout <<"found as an object\n";
                     yyerror(NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,"is known as an object.");
                     YYERROR;//stops parsing if variable not found
                   }
                } 
        }
    | ID '(' ID ')' {
                map<string, Node *>::iterator it;
                it = NodeVars->find($1);
     
                if(it == NodeVars->end()) {
                        DEBUG($1<<" : ");
                        yyerror(NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,"Variable with paranthesis not defined");
                        YYERROR;//stops parsing if variable not found
                }
                else {
                        DEBUG(it->first <<" node ID recognized.\t");
                        DEBUG(it->second->getStr()<<"\n");
                }
                map<string,Node*>::iterator ito = ObjectCuts->find($3);
                if(ito == ObjectCuts->end()) {
                    std::string message = "User object not defined: "; message += $3;
                    yyerror(NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,message.c_str());
                    YYERROR;
                } else {
                    DEBUG(ito->first <<" OBJ id recognized.\n");
                    it->second->setUserObjects(ito->second);
                }
                $$=it->second;
    } 
   ;
//------------------------------------------
list2 : '{' particules { pnum=0; TmpParticle.swap(TmpParticle1); } ',' particules '}' { 
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
list3 : '{' particules { pnum=0; TmpParticle.swap(TmpParticle2); } ',' particules { TmpParticle.swap(TmpParticle1);} ',' particules '}' { 
                                                        string s=$2;
                                                        string s2=$5;
                                                        s="{ "+s+" , "+s2+" }";                        
                                                        $$=strdup(s.c_str());
                                                        }
      | '(' particules { pnum=0; TmpParticle.swap(TmpParticle2); } ',' particules { TmpParticle.swap(TmpParticle1);} ',' particules ')' {
                                                        string s=$2;
                                                        string s2=$5;
                                                        s="{ "+s+" , "+s2+" }";
                                                        $$=strdup(s.c_str());
                                                        }
     ;
particules : particules particule {                                                 
                            DEBUG("Got a new particle"<<$2<<", size:"<<TmpParticle.size()<<"\t");
                            int ip=TmpParticle.size()-1;
                            DEBUG("collection:"<<TmpParticle[ip]->collection<<" t:"<<TmpParticle[ip]->type<<" i:"<<TmpParticle[ip]->index<<"\n");
                                                string s=$$;
                                                string s2=$2;
                                                s=s+" "+s2;
                                                $$=strdup(s.c_str());
                            DEBUG("Check the new particle, size:"<<TmpParticle.size()<<"\t");
                            int ik=TmpParticle.size()-1;
                            DEBUG("collection:"<<TmpParticle[ik]->collection<<" t:"<<TmpParticle[ik]->type<<" i:"<<TmpParticle[ik]->index<<"\n");
                                  }
            | particules '+' particule {
                                                string s=$$;
                                                string s2=$3;
                                                s=s+" "+s2;
                                                $$=strdup(s.c_str());
                                  }
            | particule {   if (pnum==0){ $$=strdup($1);    }
                                        else{                                                
                                                string s=$$;
                                                string s2=$1;
                                                s=s+" "+s2;
                                                $$=strdup(s.c_str());
                                        }
                                        pnum++;
                            DEBUG("Got the first particle, size:"<<TmpParticle.size()<<"\t");
                            DEBUG("collection:"<<TmpParticle[0]->collection<<" t:"<<TmpParticle[0]->type<<" i:"<<TmpParticle[0]->index<<"\n");
                         }
//          | '+' particule  {   if (pnum==0){ $$=strdup($2); }
//                                      else{                                                
//                                              string s=$$;
//                                              string s2=$1;
//                                              s=s+" "+s2;
//                                              $$=strdup(s.c_str());
//                                      }
//                                      pnum++;
//                       }
            | '-' particule {  if (pnum==0){ 
                                            $$=strdup($2); }
                                        else{
                                                string s=$$;
                                                string s2=$2;
                                                s=s+" "+s2;
                                                $$=strdup(s.c_str());
                                        }
                                        TmpParticle[ TmpParticle.size()-1]->type*=-1;
                                        pnum++;
                         }
            ;
particule : GEN '_' index   {  DEBUG("truth particule:"<<(int)$3<<"\n");
                                myParticle* a = new myParticle;
                                a->type =10; a->index = (int)$3; a->collection = "Truth";
                                TmpParticle.push_back(a);                            
                                tmp="truth_"+to_string((int)$3);                        
                                $$=strdup(tmp.c_str());
			    }

	 | GEN '[' e ']' {     Node* child=$3;
                               cout << "TmpCri:"<<TmpCriteria.size()<<"\n";
                               TmpCriteria.push_back(child);
			       myParticle* a = new myParticle;
                               a->type =10; a->index = 6213; a->collection = "Truth";
                               TmpParticle.push_back(a);
                               tmp="truth_6213";
                               $$=strdup(tmp.c_str());
			  }

	 | GEN '[' index ']' { 
				myParticle* a = new myParticle;
                                a->type =10; a->index = (int)$3; a->collection = "Truth";
                                TmpParticle.push_back(a);
                                tmp="truth_"+to_string((int)$3);
                                $$=strdup(tmp.c_str());
			     }
        | GEN '[' index ':' index ']' {
                                tmp="truth_"+to_string((int)$3);
                                $$=strdup(tmp.c_str());
                                for (int ii=(int)$3; ii<=(int)$5; ii++){
                                 myParticle* a = new myParticle;
                                 a->type = 10; a->index = 10000+ii; a->collection = "Truth";
                                 if ((int)$5 == 6213) {
                                       a->index = 16213;
                                       TmpParticle.push_back(a);
                                       break;
                                 }else TmpParticle.push_back(a);
                                }
                        } 
        | GEN '_' index ':' index {
                                tmp="truth_"+to_string((int)$3);
                                $$=strdup(tmp.c_str());
                                for (int ii=(int)$3; ii<=(int)$5; ii++){
                                 myParticle* a = new myParticle;
                                 a->type = 10; a->index = 10000+ii; a->collection = "Truth";
                                 if ((int)$5 == 6213) {
                                       a->index = 16213;
                                       TmpParticle.push_back(a);
                                       break;
                                 }else TmpParticle.push_back(a);
                                }
                        } 

	 | GEN         {        DEBUG("all truth particles \t");
                                tmp="truth_6213";
                                $$=strdup(tmp.c_str());
				myParticle* a = new myParticle;
				a->type =truth_t; a->index= 6213; a->collection= "Truth";
                                TmpParticle.push_back(a);
			}
         | GEN CONSTITS {       DEBUG("all truth particules \t");
                                tmp="truth_6213";
                                $$=strdup(tmp.c_str());
                                myParticle* a = new myParticle;
                                a->type =consti_t; a->index= 6213; a->collection= "Truth";
                                TmpParticle.push_back(a);
                         }

	| ELE '_' index {       DEBUG("found an electron particule:"<<(int)$3<<"\t");
                                myParticle *a= new myParticle;
                                a->type =1; a->index = (int)$3; a->collection = "ELE";
                                TmpParticle.push_back(a);
                                DEBUG("type:"<<a->type<<"\n");                            
                                tmp="ele_"+to_string((int)$3);                        
                                $$=strdup(tmp.c_str());
                          }
        | ELE '[' index ']' {   myParticle* a = new myParticle;
                                a->type =electron_t; a->index = (int)$3; a->collection = "ELE";
                                TmpParticle.push_back(a);
                                tmp="ele_"+to_string((int)$3);
                                $$=strdup(tmp.c_str());
                            }
        | ELE               {
                                DEBUG("all electron particules \t");
                                myParticle* a = new myParticle;
                                a->type =electron_t; a->index = 6213; a->collection = "ELE";
                                TmpParticle.push_back(a);
                                tmp="ele_6213";
                                $$=strdup(tmp.c_str());
                            }
        | ELE '[' index ':' index ']' {
                                tmp="ele_"+to_string((int)$3);
                                $$=strdup(tmp.c_str());
                                for (int ii=(int)$3; ii<=(int)$5; ii++){
                                 myParticle* a = new myParticle;
                                 a->type = electron_t; a->index = 10000+ii; a->collection = "ELE";
                                 if ((int)$5 == 6213) {
                                       a->index = 16213;
                                       TmpParticle.push_back(a);
                                       break;
                                 }else TmpParticle.push_back(a);
                                }
                        } 
        | ELE '_' index ':' index {
                                tmp="ele_"+to_string((int)$3);
                                $$=strdup(tmp.c_str());
                                for (int ii=(int)$3; ii<=(int)$5; ii++){
                                 myParticle* a = new myParticle;
                                 a->type = electron_t; a->index = 10000+ii; a->collection = "ELE";
                                 if ((int)$5 == 6213) {
                                       a->index = 16213;
                                       TmpParticle.push_back(a);
                                       break;
                                 }else TmpParticle.push_back(a);
                                }
                        } 
        | MUO '[' index ']' {   
                                tmp="muo_"+to_string((int)$3);                        
                                $$=strdup(tmp.c_str());
                                myParticle* a = new myParticle;
                                a->type = 12; a->index = (int)$3; a->collection = "MUO";
                                TmpParticle.push_back(a);  
                        }
        | MUO '_' index {       
				tmp="muo_"+to_string((int)$3);                        
                                $$=strdup(tmp.c_str());
                                myParticle* a = new myParticle;
                                a->type = 12; a->index = (int)$3; a->collection = "MUO";
                                TmpParticle.push_back(a);  
                        }
       | MUO            {      
                                DEBUG("all muon particules \t");
                                tmp="muo_6213";
                                $$=strdup(tmp.c_str());
                                myParticle* a = new myParticle;
                                a->type = 12; a->index = 6213; a->collection = "MUO";
                                TmpParticle.push_back(a);
                        }
       | MUO '[' index ':' index ']' {
                                tmp="muo_"+to_string((int)$3);
                                $$=strdup(tmp.c_str());
                                for (int ii=(int)$3; ii<=(int)$5; ii++){
                                 myParticle* a = new myParticle;
                                 a->type = 12; a->index = 10000+ii; a->collection = "MUO";
                                 if ((int)$5 == 6213) {
                                       a->index = 16213;
                                       TmpParticle.push_back(a);
                                       break;
                                 }else TmpParticle.push_back(a);
                                }
                        } 

       | MUO '_' index ':' index {
                                tmp="muo_"+to_string((int)$3);
                                $$=strdup(tmp.c_str());
                                for (int ii=(int)$3; ii<=(int)$5; ii++){
                                 myParticle* a = new myParticle;
                                 a->type = 12; a->index = 10000+ii; a->collection = "MUO";
                                 if ((int)$5 == 6213) {
                                       a->index = 16213;
                                       TmpParticle.push_back(a);
                                       break;
                                 }else TmpParticle.push_back(a);
                                }
                        } 
        | TAU '[' index ']' {   
                                tmp="tau_"+to_string((int)$3);                        
                                $$=strdup(tmp.c_str());
                                myParticle* a = new myParticle;
                                a->type = 11; a->index = (int)$3; a->collection = "TAU";
                                TmpParticle.push_back(a);  
                        }
        | TAU '_' index {       
				tmp="tau_"+to_string((int)$3);                        
                                $$=strdup(tmp.c_str());
                                myParticle* a = new myParticle;
                                a->type = 11;
                                a->index = (int)$3;
                                a->collection = "TAU";
                                TmpParticle.push_back(a);  
                        }

        | TAU '[' index ':' index ']' {
                                tmp="tau_"+to_string((int)$3);
                                $$=strdup(tmp.c_str());
                                for (int ii=(int)$3; ii<=(int)$5; ii++){
                                 myParticle* a = new myParticle;
                                 a->type = 11; a->index = 10000+ii; a->collection = "TAU";
                                 if ((int)$5 == 6213) {
                                       a->index = 16213;
                                       TmpParticle.push_back(a);
                                       break;
                                 }else TmpParticle.push_back(a);
                                }
                        } 
        | TAU '_' index ':' index {
                                tmp="tau_"+to_string((int)$3);
                                $$=strdup(tmp.c_str());
                                for (int ii=(int)$3; ii<=(int)$5; ii++){
                                 myParticle* a = new myParticle;
                                 a->type = 11; a->index = 10000+ii; a->collection = "TAU";
                                 if ((int)$5 == 6213) {
                                       a->index = 16213;
                                       TmpParticle.push_back(a);
                                       break;
                                 }else TmpParticle.push_back(a);
                                }
                        } 

       | TAU            {      
                                DEBUG("all tau particules \t");
                                tmp="tau_6213";
                                $$=strdup(tmp.c_str());
                                myParticle* a = new myParticle;
                                a->type = 11; a->index = 6213; a->collection = "TAU";
                                TmpParticle.push_back(a);
                        }
        | LEP '_' index {       tmp="lep_"+to_string((int)$3);                        
                                $$=strdup(tmp.c_str());
                                myParticle* a = new myParticle;
                                a->type = 1; a->collection = "ELE";
                                if(DataFormats->at(1)>0) { a->type = 12;  a->collection = "MUO";}
                                a->index = (int)$3;
                                TmpParticle.push_back(a);  
                        }
        | LEP '[' index ':' index ']' {
                                tmp="lep_"+to_string((int)$3);
                                $$=strdup(tmp.c_str());
                                for (int ii=(int)$3; ii<=(int)$5; ii++){
                                 myParticle* a = new myParticle;
                                 a->type = 1; a->collection = "ELE";
                                 if(DataFormats->at(1)>0) { a->type = 12;  a->collection = "MUO";}
                                 a->index = 10000+ii;
                                 if ((int)$5 == 6213) {
                                       a->index = 16213;
                                       TmpParticle.push_back(a);
                                       break;
                                 }else TmpParticle.push_back(a);
                                }
                        } 
        | LEP '_' index ':' index {
                                tmp="lep_"+to_string((int)$3);
                                $$=strdup(tmp.c_str());
                                for (int ii=(int)$3; ii<=(int)$5; ii++){
                                 myParticle* a = new myParticle;
                                 a->type = 1; a->collection = "ELE";
                                 if(DataFormats->at(1)>0) { a->type = 12;  a->collection = "MUO";}
                                 a->index = 10000+ii;
                                 if ((int)$5 == 6213) {
                                       a->index = 16213;
                                       TmpParticle.push_back(a);
                                       break;
                                 }else TmpParticle.push_back(a);
                                }
                        } 
        | LEP '[' index ']' {   tmp="lep_"+to_string((int)$3);                        
                                $$=strdup(tmp.c_str());
                                myParticle* a = new myParticle;
                                a->index = (int)$3; a->type = 1; a->collection = "ELE";
                                if(DataFormats->at(1)>0) { a->type = 12;  a->collection = "MUO";}
                                TmpParticle.push_back(a);  
                        }

        | PHO '[' index ']' {   tmp="pho_"+to_string((int)$3);                        
                                $$=strdup(tmp.c_str());
                                myParticle* a = new myParticle;
                                a->type = 8; a->index = (int)$3; a->collection = "PHO";
                                TmpParticle.push_back(a);  
                        }

        | PHO '_' index {       tmp="pho_"+to_string((int)$3);                        
                                $$=strdup(tmp.c_str());
                                myParticle* a = new myParticle;
                                a->type = 8; a->index = (int)$3; a->collection = "PHO";
                                TmpParticle.push_back(a);  
                        }
        | PHO '[' index ':' index ']' {
                                tmp="pho_"+to_string((int)$3);
                                $$=strdup(tmp.c_str());
                                for (int ii=(int)$3; ii<=(int)$5; ii++){
                                 myParticle* a = new myParticle;
                                 a->type = 8; a->index = 10000+ii; a->collection = "PHO";
                                 if ((int)$5 == 6213) {
                                       a->index = 16213;
                                       TmpParticle.push_back(a);
                                       break;
                                 }else TmpParticle.push_back(a);
                                }
                        } 
        | PHO '_' index ':' index {
                                tmp="pho_"+to_string((int)$3);
                                $$=strdup(tmp.c_str());
                                for (int ii=(int)$3; ii<=(int)$5; ii++){
                                 myParticle* a = new myParticle;
                                 a->type = 8; a->index = 10000+ii; a->collection = "PHO";
                                 if ((int)$5 == 6213) {
                                       a->index = 16213;
                                       TmpParticle.push_back(a);
                                       break;
                                 }else TmpParticle.push_back(a);
                                }
                        } 
       | PHO            {      
                                DEBUG("all PHO particules \t");
                                tmp="pho_6213";
                                $$=strdup(tmp.c_str());
                                myParticle* a = new myParticle;
                                a->type = 8; a->index = 6213; a->collection = "PHO";
                                TmpParticle.push_back(a);
                        }
        | JET '[' index ']' {   tmp="jet_"+to_string((int)$3);                        
                                $$=strdup(tmp.c_str());
                                myParticle* a = new myParticle;
                                a->type = 2; a->index = (int)$3; a->collection = "JET";
                                TmpParticle.push_back(a);  
                        }
        | JET '[' index ':' index ']' {
                                tmp="jet_"+to_string((int)$3);
                                $$=strdup(tmp.c_str());
                                for (int ii=(int)$3; ii<=(int)$5; ii++){
                                 myParticle* a = new myParticle;
                                 a->type = 2; a->index = 10000+ii; a->collection = "JET";
                                 if ((int)$5 == 6213) {
                                       a->index = 16213;
                                       TmpParticle.push_back(a);
                                       break;
                                 }else TmpParticle.push_back(a);
                                }
                        } 
        | JET '_' index ':' index {
                                tmp="jet_"+to_string((int)$3);
                                $$=strdup(tmp.c_str());
                                for (int ii=(int)$3; ii<=(int)$5; ii++){
                                 myParticle* a = new myParticle;
                                 a->type = 2; a->index = 10000+ii; a->collection = "JET";
                                 if ((int)$5 == 6213) {
                                       a->index = 16213;
                                       TmpParticle.push_back(a);
                                       break;
                                 }else TmpParticle.push_back(a);
                                }
                        } 
        | JET '_' index {       tmp="jet_"+to_string((int)$3);                        
                                $$=strdup(tmp.c_str());
                                myParticle* a = new myParticle;
                                a->type = 2; a->index = (int)$3; a->collection = "JET";
                                TmpParticle.push_back(a);  
                        }
       | JET            {       DEBUG("all jet particules \t");
                                tmp="jet_6213";
                                $$=strdup(tmp.c_str());
                                myParticle* a = new myParticle;
                                a->type = 2; a->index = 6213; a->collection = "JET";
                                TmpParticle.push_back(a);
                        }
//-----------------------------------------------CONSTITS
       | JET  CONSTITS   {      DEBUG("all jet particules \t");
                                tmp="jet_6213";
                                $$=strdup(tmp.c_str());
                                myParticle* a = new myParticle;
                                a->type =consti_t; a->index = 6213; a->collection = "JET";
                                TmpParticle.push_back(a);
                         }
        | BJET           {      tmp="bjet_6213";                        
                                $$=strdup(tmp.c_str());
                                myParticle* a = new myParticle;
                                a->type = 3; a->index = 6213; a->collection = "JET";
                                TmpParticle.push_back(a);  
                        }
        | BJET '_' index {      tmp="bjet_"+to_string((int)$3);                        
                                $$=strdup(tmp.c_str());
                                myParticle* a = new myParticle;
                                a->type = 3; a->index = (int)$3; a->collection = "JET";
                                TmpParticle.push_back(a);  
                        }
        | BJET '[' index ']' {  tmp="bjet_"+to_string((int)$3);                        
                                $$=strdup(tmp.c_str());
                                myParticle* a = new myParticle;
                                a->type = 3; a->index = (int)$3; a->collection = "JET";
                                TmpParticle.push_back(a);  
                        }
        | BJET '[' index ':' index ']' {
                                tmp="bjet_"+to_string((int)$3);
                                $$=strdup(tmp.c_str());
                                for (int ii=(int)$3; ii<=(int)$5; ii++){
                                 myParticle* a = new myParticle;
                                 a->type = 3; a->index = 10000+ii; a->collection = "JET";
                                 if ((int)$5 == 6213) {
                                       a->index = 16213;
                                       TmpParticle.push_back(a);
                                       break;
                                 }else TmpParticle.push_back(a);
                                }
                        } 
        | BJET '_' index ':' index {
                                tmp="bjet_"+to_string((int)$3);
                                $$=strdup(tmp.c_str());
                                for (int ii=(int)$3; ii<=(int)$5; ii++){
                                 myParticle* a = new myParticle;
                                 a->type = 3; a->index = 10000+ii; a->collection = "JET";
                                 if ((int)$5 == 6213) {
                                       a->index = 16213;
                                       TmpParticle.push_back(a);
                                       break;
                                 }else TmpParticle.push_back(a);
                                }
                        } 
        | FJET '_' index {      tmp="fjet_"+to_string((int)$3);                        
                                $$=strdup(tmp.c_str());
                                myParticle* a = new myParticle;
                                a->type = 9; a->index = (int)$3; a->collection = "FJET";
                                TmpParticle.push_back(a);  
                        }
        | FJET '[' index ']' {  tmp="fjet_"+to_string((int)$3);                        
                                $$=strdup(tmp.c_str());
                                myParticle* a = new myParticle;
                                a->type = 9; a->index = (int)$3; a->collection = "FJET";
                                TmpParticle.push_back(a);  
                        }
        | FJET '[' index ':' index ']' {
                                tmp="bjet_"+to_string((int)$3);
                                $$=strdup(tmp.c_str());
                                for (int ii=(int)$3; ii<=(int)$5; ii++){
                                 myParticle* a = new myParticle;
                                 a->type = 9; a->index = 10000+ii; a->collection = "FJET";
                                 if ((int)$5 == 6213) {
                                       a->index = 16213;
                                       TmpParticle.push_back(a);
                                       break;
                                 }else TmpParticle.push_back(a);
                                }
                        } 
        | FJET '_' index ':' index {
                                tmp="bjet_"+to_string((int)$3);
                                $$=strdup(tmp.c_str());
                                for (int ii=(int)$3; ii<=(int)$5; ii++){
                                 myParticle* a = new myParticle;
                                 a->type = 9; a->index = 10000+ii; a->collection = "FJET";
                                 if ((int)$5 == 6213) {
                                       a->index = 16213;
                                       TmpParticle.push_back(a);
                                       break;
                                 }else TmpParticle.push_back(a);
                                }
                        } 
       | FJET           {      
                                DEBUG("all Fjet particules \t");
                                tmp="fjet_6213";
                                $$=strdup(tmp.c_str());
                                myParticle* a = new myParticle;
                                a->type = 9; a->index = 6213; a->collection = "FJET";
                                TmpParticle.push_back(a);
                        }
        | QGJET '[' index ']' { tmp="qgjet_"+to_string((int)$3);                        
                                $$=strdup(tmp.c_str());
                                myParticle* a = new myParticle;
                                a->type = 4; a->index = (int)$3; a->collection = "QCJET";
                                TmpParticle.push_back(a);  
                        }
        | QGJET '_' index {      tmp="qgjet_"+to_string((int)$3);                        
                                $$=strdup(tmp.c_str());
                                myParticle* a = new myParticle;
                                a->type = 4; a->index = (int)$3; a->collection = "QCJET";
                                TmpParticle.push_back(a);  
                        }
        | QGJET '[' index ':' index ']' {
                                tmp="qgjet_"+to_string((int)$3);
                                $$=strdup(tmp.c_str());
                                for (int ii=(int)$3; ii<=(int)$5; ii++){
                                 myParticle* a = new myParticle;
                                 a->type = 4; a->index = 10000+ii; a->collection = "QCJET";
                                 if ((int)$5 == 6213) {
                                       a->index = 16213;
                                       TmpParticle.push_back(a);
                                       break;
                                 }else TmpParticle.push_back(a);
                                }
                        } 
        | QGJET '_' index ':' index {
                                tmp="qgjet_"+to_string((int)$3);
                                $$=strdup(tmp.c_str());
                                for (int ii=(int)$3; ii<=(int)$5; ii++){
                                 myParticle* a = new myParticle;
                                 a->type = 4; a->index = 10000+ii; a->collection = "QCJET";
                                 if ((int)$5 == 6213) {
                                       a->index = 16213;
                                       TmpParticle.push_back(a);
                                       break;
                                 }else TmpParticle.push_back(a);
                                }
                        } 
        | NUMET '_' index {     tmp="numet_"+to_string((int)$3);                        
                                $$=strdup(tmp.c_str());
                                myParticle* a = new myParticle;
                                if(DataFormats->at(1)>0){
                                        a->type = 5;
                                }
                                else{
                                        a->type = 6;
                                }
                                a->index = (int)$3;
                                TmpParticle.push_back(a);  
                        }
/*
        | NUMET '[' index ':' index ']' {
                                tmp="numet_"+to_string((int)$3);
                                $$=strdup(tmp.c_str());
                                for (int ii=(int)$3; ii<=(int)$5; ii++){
                                 myParticle* a = new myParticle;
                                 a->type = 6;
				 if(DataFormats->at(1)>0) a->type = 5;
                                 a->index = 10000+ii;
				 TmpParticle.push_back(a);
                                }
                        } 
        | NUMET '_' index ':' index {
                                tmp="numet_"+to_string((int)$3);
                                $$=strdup(tmp.c_str());
                                for (int ii=(int)$3; ii<=(int)$5; ii++){
                                 myParticle* a = new myParticle;
                                 a->type = 6;
				 if(DataFormats->at(1)>0) a->type = 5;
                                 a->index = 10000+ii;
				 TmpParticle.push_back(a);
                                }
                        } 
*/
        | METLV '[' index ']' { tmp="metlv_"+to_string((int)$3);            
                                $$=strdup(tmp.c_str());
                                myParticle* a = new myParticle;
                                a->type = 7;
                                a->index = (int)$3;
                                TmpParticle.push_back(a);  
                        }
        | METLV '_' index {     tmp="metlv_"+to_string((int)$3);                        
                                $$=strdup(tmp.c_str());
                                myParticle* a = new myParticle;
                                a->type = 7;
                                a->index = (int)$3;
                                TmpParticle.push_back(a);  
                        }
        | ID '[' index ']' { //we want the original defintions as well -> put it in parts and put the rest in vectorParts
                DEBUG("ID with [ index ]\t");
                map<string,vector<myParticle*> >::iterator it;
                it = ListParts->find($1);
     
                if(it == ListParts->end()) {

                       map<string,Node*>::iterator ito;
                       ito=ObjectCuts->find($1);
                       DEBUG($1<<" : "); //------------new ID

                       if(ito != ObjectCuts->end()) {
                        DEBUG(" is a user object, type:"<< ((ObjectNode*) ito->second)->type<<" ");
                        int otype=((ObjectNode*) ito->second)->type;  

                        if (otype == 2 ) {
                           DEBUG("which is a JET\n");
                           tmp="jet_"+to_string((int)$3);
                                $$=strdup(tmp.c_str());
                                myParticle* a = new myParticle;
                                a->type = 2; a->index = (int)$3; a->collection = $1;
                                TmpParticle.push_back(a);
                        } 
                        else if (otype == 20 ) {
                           DEBUG("which is a composite\n");
                           tmp="compo_"+to_string((int)$3);
                                $$=strdup(tmp.c_str());
                                myParticle* a = new myParticle;
                                a->type = 20; a->index = (int)$3; a->collection = $1;
                                TmpParticle.push_back(a);
                        }
			                  else if (otype == 10 ) {
                           DEBUG("which is a GEN\n");
                           tmp="truth_"+to_string((int)$3);
                                $$=strdup(tmp.c_str());
                                myParticle* a = new myParticle;
                                a->type = 10; a->index = (int)$3; a->collection = $1;
                                TmpParticle.push_back(a);
                        } 
                        else if (otype == 1 ) {
                           DEBUG("which is a ELE\n");
                           tmp="ele_"+to_string((int)$3);
                                $$=strdup(tmp.c_str());
                                myParticle* a = new myParticle;
                                a->type = 1; a->index = (int)$3; a->collection = $1;
                                TmpParticle.push_back(a);
                        }
                        else if (otype==12 ) {
                           DEBUG("which is a MUO\n");
                           tmp="muo_"+to_string((int)$3);
                                $$=strdup(tmp.c_str());
                                myParticle* a = new myParticle;
                                a->type = 12; a->index = (int)$3; a->collection = $1;
                                TmpParticle.push_back(a);
                        }
                        else if (otype==11 ) {
                           DEBUG("which is a TAU\n");
                           tmp="tau_"+to_string((int)$3);
                                $$=strdup(tmp.c_str());
                                myParticle* a = new myParticle;
                                a->type = 11; a->index = (int)$3; a->collection = $1;
                                TmpParticle.push_back(a);
                        }
                        else if (otype==8 ) {
                           DEBUG("which is a PHO\n");
                           tmp="pho_"+to_string((int)$3);
                                $$=strdup(tmp.c_str());
                                myParticle* a = new myParticle;
                                a->type = 8; a->index = (int)$3; a->collection = $1;
                                TmpParticle.push_back(a);
                        }
                        else if (otype==9 ) {
                           DEBUG("which is a FatJET\n");
                           tmp="ljet_"+to_string((int)$3);
                                $$=strdup(tmp.c_str());
                                myParticle* a = new myParticle;
                                a->type = 9; a->index = (int)$3; a->collection = $1;
                                TmpParticle.push_back(a);
                        }
                       } else {
                        cout << $1 << " is a problem\n";
                        yyerror(NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,"Particle not defined");
                        YYERROR;//stops parsing if particle not found 
                       }
                } else {
                        vector<myParticle*> newList= it->second;
                        TmpParticle.insert(TmpParticle.end(), newList.begin(), newList.end());
                        $$=$1;
                }
             }
        | ID '[' index ':' index ']' { //we want the original defintions as well -> put it in parts and put the rest in vectorParts
                DEBUG("ID ---[]---\t");
                map<string,vector<myParticle*> >::iterator it;
                it = ListParts->find($1);
                if(it == ListParts->end()) {
                       map<string,Node*>::iterator ito;
                       ito=ObjectCuts->find($1);
                       DEBUG($1<<" : "); //------------new ID

                       if(ito != ObjectCuts->end()) {
                        DEBUG(" is a user object, type:"<< ((ObjectNode*) ito->second)->type<<" ");
                        int otype=((ObjectNode*) ito->second)->type;  

                        if (otype == 2 ) {
                           DEBUG("which is a JET\n");
                           tmp="jet_"+to_string((int)$3);
                                $$=strdup(tmp.c_str());
                                for (int ii=(int)$3; ii<=(int)$5; ii++){
                                  myParticle* a = new myParticle;
                                  a->type = 2; a->index=10000+ii; a->collection = $1;
                                  if ((int)$5 == 6213) {
                                       a->index = 16213;
                                       TmpParticle.push_back(a);
                                       break;
                                 }else TmpParticle.push_back(a);
                                }
                        } 
                        else if (otype == 20 ) {
                           DEBUG("which is a composite\n");
                           tmp="compo_"+to_string((int)$3);
                                $$=strdup(tmp.c_str());
                                for (int ii=(int)$3; ii<=(int)$5; ii++){
                                  myParticle* a = new myParticle;
                                  a->type = 20; a->index=10000+ii; a->collection = $1;
                                  if ((int)$5 == 6213) {
                                       a->index = 16213;
                                       TmpParticle.push_back(a);
                                       break;
                                 }else TmpParticle.push_back(a);
                                }
                        }
			else if (otype == 10 ) {
                           DEBUG("which is a GEN\n");
                           tmp="truth_"+to_string((int)$3);
                                $$=strdup(tmp.c_str());
                                for (int ii=(int)$3; ii<=(int)$5; ii++){
                                  myParticle* a = new myParticle;
                                  a->type = 10; a->index=10000+ii; a->collection = $1;
                                  if ((int)$5 == 6213) {
                                       a->index = 16213;
                                       TmpParticle.push_back(a);
                                       break;
                                 }else TmpParticle.push_back(a);
                                }
                        } 
                        else if (otype == 1 ) {
                           DEBUG("which is a ELE\n");
                           tmp="ele_"+to_string((int)$3);
                                $$=strdup(tmp.c_str());
                                for (int ii=(int)$3; ii<=(int)$5; ii++){
                                  myParticle* a = new myParticle;
                                  a->type = 1; a->index=10000+ii; a->collection = $1;
                                  if ((int)$5 == 6213) {
                                       a->index = 16213;
                                       TmpParticle.push_back(a);
                                       break;
                                 }else TmpParticle.push_back(a);
                                }
                        }
                        else if (otype==12 ) {
                           DEBUG("which is a MUO\n");
                           tmp="muo_"+to_string((int)$3);
                                $$=strdup(tmp.c_str());
                                for (int ii=(int)$3; ii<=(int)$5; ii++){
                                  myParticle* a = new myParticle;
                                  a->type = 12; a->index=10000+ii; a->collection = $1;
                                  if ((int)$5 == 6213) {
                                       a->index = 16213;
                                       TmpParticle.push_back(a);
                                       break;
                                 }else TmpParticle.push_back(a);
                                }
                        }
                        else if (otype==11 ) {
                           DEBUG("which is a TAU\n");
                           tmp="tau_"+to_string((int)$3);
                                $$=strdup(tmp.c_str());
                                for (int ii=(int)$3; ii<=(int)$5; ii++){
                                  myParticle* a = new myParticle;
                                  a->type = 11; a->index=10000+ii; a->collection = $1;
                                  if ((int)$5 == 6213) {
                                       a->index = 16213;
                                       TmpParticle.push_back(a);
                                       break;
                                 }else TmpParticle.push_back(a);
                                }
                        }
                        else if (otype==8 ) {
                           DEBUG("which is a PHO\n");
                           tmp="pho_"+to_string((int)$3);
                                $$=strdup(tmp.c_str());
                                for (int ii=(int)$3; ii<=(int)$5; ii++){
                                  myParticle* a = new myParticle;
                                  a->type = 8; a->index=10000+ii; a->collection = $1;
                                  if ((int)$5 == 6213) {
                                       a->index = 16213;
                                       TmpParticle.push_back(a);
                                       break;
                                 }else TmpParticle.push_back(a);
                                }
                        }
                        else if (otype==9 ) {
                           DEBUG("which is a FatJET\n");
                           tmp="ljet_"+to_string((int)$3);
                                $$=strdup(tmp.c_str());
                                for (int ii=(int)$3; ii<=(int)$5; ii++){
                                  myParticle* a = new myParticle;
                                  a->type = 9; a->index=10000+ii; a->collection = $1;
                                  if ((int)$5 == 6213) {
                                       a->index = 16213;
                                       TmpParticle.push_back(a);
                                       break;
                                 }else TmpParticle.push_back(a);
                                }
                        }
                       } else {
                        cout << $1 << " is not known.\n";
                        yyerror(NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,"Particle not defined");
                        YYERROR;//stops parsing if particle not found 
                       }
                } else {
                        vector<myParticle*> newList= it->second;
                        TmpParticle.insert(TmpParticle.end(), newList.begin(), newList.end());
                        $$=$1;
                }
             }
        | ID '_' index { //we want the original defintions as well -> put it in parts and put the rest in vectorParts
                //ngu
                DEBUG("Particle candidate "<< $1 <<" has _ and index:"<< $3<<"\n" );
                map<string,vector<myParticle*> >::iterator it;
                it = ListParts->find($1);
     
                if(it == ListParts->end()) {
                       map<string,Node*>::iterator ito;
                       ito=ObjectCuts->find($1);
                       DEBUG($1<<" : "); //------------new ID

                       if(ito != ObjectCuts->end()) {
                        DEBUG(" is a user object, type:"<< ((ObjectNode*) ito->second)->type<<" ");
                        int otype=((ObjectNode*) ito->second)->type;  

                        if (otype == 2 ) {
                           DEBUG("which is a JET\n");
                           tmp="jet_"+to_string((int)$3);
                                $$=strdup(tmp.c_str());
                                myParticle* a = new myParticle;
                                a->type = 2; a->index = (int)$3; a->collection = $1;
                                TmpParticle.push_back(a);
                        } 
                        else if (otype == 20 ) {
                           DEBUG("which is a composite\n");
                           tmp="compo_"+to_string((int)$3);
                                $$=strdup(tmp.c_str());
                                myParticle* a = new myParticle;
                                a->type = 20; a->index = (int)$3; a->collection = $1;
                                TmpParticle.push_back(a);
                           DEBUG(" TP size :"<<TmpParticle.size()<<"\n");
                        }
			                  else if (otype == 10 ) {
                           DEBUG("which is a GEN\n");
                           tmp="truth_"+to_string((int)$3);
                                $$=strdup(tmp.c_str());
                                myParticle* a = new myParticle;
                                a->type = 10; a->index = (int)$3; a->collection = $1;
                                TmpParticle.push_back(a);
                        }
                        else if (otype == 1 ) {
                           DEBUG("which is a ELE\n");
                           tmp="jet_"+to_string((int)$3);
                                $$=strdup(tmp.c_str());
                                myParticle* a = new myParticle;
                                a->type=otype; a->index = (int)$3; a->collection = $1;
                                TmpParticle.push_back(a);
                        }
                        else if (otype==12 ) {
                           DEBUG("which is a MUO\n");
                           tmp="jet_"+to_string((int)$3);
                                $$=strdup(tmp.c_str());
                                myParticle* a = new myParticle;
                                a->type=otype; a->index = (int)$3; a->collection = $1;
                                TmpParticle.push_back(a);
                        }
                        else if (otype==11 ) {
                           DEBUG("which is a TAU\n");
                           tmp="jet_"+to_string((int)$3);
                                $$=strdup(tmp.c_str());
                                myParticle* a = new myParticle;
                                a->type=otype; a->index = (int)$3; a->collection = $1;
                                TmpParticle.push_back(a);
                        }
                        else if (otype==8 ) {
                           DEBUG("which is a PHO\n");
                           tmp="jet_"+to_string((int)$3);
                                $$=strdup(tmp.c_str());
                                myParticle* a = new myParticle;
                                a->type=otype; a->index = (int)$3; a->collection = $1;
                                TmpParticle.push_back(a);
                        }
                        else if (otype==9 ) {
                           DEBUG("which is a FatJET\n");
                           tmp="jet_"+to_string((int)$3);
                                $$=strdup(tmp.c_str());
                                myParticle* a = new myParticle;
                                a->type=otype; a->index = (int)$3; a->collection = $1;
                                TmpParticle.push_back(a);
                        }
                       } else {
                        yyerror(NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,"Particle not defined");
                        YYERROR;//stops parsing if particle not found 
                       }
                } else {
                        vector<myParticle*> newList= it->second;
                        TmpParticle.insert(TmpParticle.end(), newList.begin(), newList.end());
                        $$=$1;
                }
             }
        | ID { //we want the original defintions as well -> put it in parts and put the rest in vectorParts

                DEBUG ("Particle candidate "<< $1 <<" has no index\n");
                map<string,vector<myParticle*> >::iterator it;
                it = ListParts->find($1);
     
                if(it == ListParts->end()) {
                       map<string,Node*>::iterator ito;
                       ito=ObjectCuts->find($1);
                       DEBUG($1<<" := "); //------------new ID
                       if(ito != ObjectCuts->end()) { // means found as an object
                        DEBUG(" is a user object, type:"<< ((ObjectNode*) ito->second)->type<<" ");
                        int otype=((ObjectNode*) ito->second)->type;

                        if (otype == 2 ) {
                           DEBUG("which is a JET\n");
                           tmp="jet_";
                                $$=strdup(tmp.c_str());
                                myParticle* a = new myParticle;
                                a->type=otype; a->index = 6213; a->collection = $1;
                                TmpParticle.push_back(a);
                        } 
                        else if (otype == 20 ) {
                           DEBUG("which is a composite\n");
                           tmp="compo_";
                                $$=strdup(tmp.c_str());
                                myParticle* a = new myParticle;
                                a->type=otype; a->index=6213; a->collection = $1;
                                TmpParticle.push_back(a);
                        }
			else if (otype == 10 ) {
                           DEBUG("which is a GEN\n");
                           tmp="truth_";
                                $$=strdup(tmp.c_str());
                                myParticle* a = new myParticle;
                                a->type=otype; a->index=6213; a->collection = $1;
                                TmpParticle.push_back(a);
                        } 
                        else if (otype == 1 ) {
                           DEBUG("which is a ELE\n");
                           tmp="ele_";
                                $$=strdup(tmp.c_str());
                                myParticle* a = new myParticle;
                                a->type=otype; a->index=6213; a->collection = $1;
                                TmpParticle.push_back(a);
                        }
                        else if (otype==12 ) {
                           DEBUG("which is a MUO\n");
                                tmp="muo_";
                                $$=strdup(tmp.c_str());
                                myParticle* a = new myParticle;
                                a->type=otype; a->index=6213; a->collection = $1;
                                TmpParticle.push_back(a);
                        }
                        else if (otype==11 ) {
                           DEBUG("which is a TAU\n");
                           tmp="tau_";
                                $$=strdup(tmp.c_str());
                                myParticle* a = new myParticle;
                                a->type=otype; a->index=6213; a->collection = $1;
                                TmpParticle.push_back(a);
                        }
                        else if (otype==8 ) {
                           DEBUG("which is a PHO\n");
                           tmp="pho_";
                                $$=strdup(tmp.c_str());
                                myParticle* a = new myParticle;
                                a->type=otype; a->index=6213; a->collection = $1;
                                TmpParticle.push_back(a);
                        }
                        else if (otype==9 ) {
                           DEBUG("which is a FatJET\n");
                           tmp="ljet_";
                                $$=strdup(tmp.c_str());
                                myParticle* a = new myParticle;
                                a->type=otype; a->index=6213; a->collection = $1;
                                TmpParticle.push_back(a);
                        }
                       } else {
                        ito=NodeVars->find($1);
                        if (ito==NodeVars->end()) { // not found even there!
                          cout << $1 << " is not a particle, object or variable. \n";
                          yyerror(NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,"ID not defined");
                          YYERROR;//stops parsing if particle not found 
                        }
                        cout <<  $1 << " is a node variable, this is a particle. TmpCri:"<<TmpCriteria.size() <<"\n";
                        cout << "doing some MAGIC\n";
//                      YYERROR;//stops parsing if particle not found 
                        TmpCriteria.push_back(ito->second );
                        //TmpParticle.push_back(ito->second );
                        tmp="MAGIC";
                        $$=strdup(tmp.c_str());               
                       }
                } else {
                        DEBUG("IDSize:"<<TmpParticle.size()<<" ");
                        vector<myParticle*> newList= it->second;
                        DEBUG("Defined as : "<< newList[0]->collection << "  type: " << newList[0]->type << "   index: " << newList[0]->index<<"\n");
                        DEBUG("Checking if it was previously checked.\n");
// check all cuts here, if we see size( $1) OK, otherwise add.
                        if (NodeCuts->size() > 0) {
                          std::map<int, Node*>::iterator iter = NodeCuts->begin();
                          std::size_t sfound=std::string::npos;
                          string aparticle=newList[0]->collection;
                          while(iter != NodeCuts->end()) {
                             string pippo=iter->second->getStr().Data();
                             sfound=pippo.find(aparticle);
                             if (sfound !=std::string::npos) {
                                DEBUG($1<< "found in previous cuts, nothing to do.\n");
                                break;
                             }
                             iter++;
                          }
                          if (sfound == std::string::npos){ 
                           cout << aparticle<< " is seen first time, Adding size>0 cut.\t";
                           map<string,Node*>::iterator it = ObjectCuts->find(aparticle);
                           if (it == ObjectCuts->end() ) {
                              std::string message = "OBJect not defined: ";
                              message += aparticle;
                              yyerror(NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,message.c_str());
                              YYERROR;
                           } else {
                              int type=((ObjectNode*)it->second)->type;
                              Node* ac=new SFuncNode(count, type, it->first, it->second);
                              Node* v0= new ValueNode(0);
                              Node* n1= new BinaryNode(ge,ac,v0,">=");
                              NodeCuts->insert(make_pair(++cutcount,n1));
                              DataFormats->push_back(double(cutcount));
                              cout << "done.\n";
                           }
                          }
                        }
                        TmpParticle.insert(TmpParticle.end(), newList.begin(), newList.end());
                        $$=$1;
                 }
        }
        ;
//----------------------------------------
index : '-' INT {$$=-$2;}
          | INT {$$= $1;}
          | {$$= 6213;} // NGU
      ; 
objects : objectBlocs ALGO ID
        | objectBlocs 
        | ALGO
        | ALGO ID {  DEBUG("Alg is:"<< $2 <<"\n"); 
                  }
        ;
objectBlocs : objectBlocs objectBloc
            | objectBloc
            ;
objectBloc : OBJ ID TAKE ID criteria {
                                        vector<Node*> newList; //empty
                                        TmpCriteria.swap(newList);
                                        map<string, Node *>::iterator it ;
                                        it = ObjectCuts->find($4); // find from which object we are making the new one
                                        if(it == ObjectCuts->end()) {
                                                ERRBUG($4<<" : ") ;
                                                yyerror(NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,"Object not defined");
                                                YYERROR;
                                        }
                                        else {
                                                Node* previous=it->second;
                                                std::string str=newList[0]->getStr().Data();
// forget me NOT 1/2.
                                                if ((str.find("MEGAJETS") != std::string::npos)
                                                  ||(str.find("MR")  != std::string::npos)
                                                  ||(str.find("HEMISPHERE")  != std::string::npos)
                                                  ||(str.find("SUMOBJ")  != std::string::npos)
                                                  ||(str.find("MTR") != std::string::npos))
                                                 {
                                                  Node *anode=newList[0];
                                                  while(anode->left!=NULL){ anode=anode->left; }
                                                 ((SFuncNode*)anode)->setSymbol($2);
                                                }
                                                Node* obj=new ObjectNode($2,previous,NULL,newList,$2);
                                                ObjectCuts->insert(make_pair($2,obj));
                                        }
                                    }
      | OBJ ID ':' ID criteria {
                                        vector<Node*> newList; //empty
                                        TmpCriteria.swap(newList);
                                        map<string, Node *>::iterator it ;
                                        it = ObjectCuts->find($4);
                                        if(it == ObjectCuts->end()) {
                                                ERRBUG($4<<" : ") ;
                                                yyerror(NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,"Object not defined");
                                                YYERROR;
                                        }
                                        else {
                                                Node* previous=it->second;
                                                std::string str=newList[0]->getStr().Data();
// forget me NOT 2/2.
                                                if ((str.find("MEGAJETS") != std::string::npos)
                                                  ||(str.find("MR")  != std::string::npos)
                                                  ||(str.find("HEMISPHERE")  != std::string::npos)
                                                  ||(str.find("SUMOBJ")  != std::string::npos)
                                                  ||(str.find("MTR") != std::string::npos))
                                                 {
                                                  Node *anode=newList[0];
                                                  while(anode->left!=NULL){ anode=anode->left; }
                                                 ((SFuncNode*)anode)->setSymbol($2);
                                                }
                                                Node* obj=new ObjectNode($2,previous,NULL,newList,$2);
                                                ObjectCuts->insert(make_pair($2,obj));
                                        }
                                    }
       | OBJ ID ':' COMB '(' particules ')' hamhum criteria {
                      vector<myParticle*> newPList;   
                      CombiParticle.swap(newPList);
                      DEBUG("PARTITION: "<<CombiParticle.size()<<"\n");
                      vector<Node*> newNList;         //empty
                      TmpCriteria.swap(newNList);
                      vector<Node*>::iterator it=newNList.begin();
                      Node* nnode= new FuncNode(Qof,newPList,"q"); // this is the combinatorics function
                      it= newNList.insert(it, nnode );

                      Node* previous=new ObjectNode("Combo",NULL,createNewParti,newNList,"Partition" );
                      Node*      obj=new ObjectNode($2,previous,NULL,newNList,$2 );
                      ObjectCuts->insert(make_pair($2,obj));
                      vector<myParticle*> junkvector;   
                      AliasList.swap(junkvector);
        }
//----------- UNION
        | OBJ ID ':' UNION '(' LEPTON ',' LEPTON ')' {
                                     DEBUG(" "<<$2<<" is a new **main Set with "<< $6 <<" and "<< $8 << "\n");
                                     myParticle* a = new myParticle;
                                     myParticle* b = new myParticle;
                                     a->index = 6213;
                                     b->index = 6213;
                                     if        (strcmp($6,"ELE") == 0 ) {
                                      a->type =1; a->collection = "ELE";
                                     } else if (strcmp($6,"MUO") == 0 ) {
                                      a->type =12; a->collection = "MUO";
                                     } else if (strcmp($6,"TAU") == 0 ) {
                                      a->type =11; a->collection = "TAU";
                                     }

                                     if        (strcmp($8,"ELE") == 0 ) {
                                      b->type =1; b->collection = "ELE";
                                     } else if (strcmp($8,"MUO") == 0 ) {
                                      b->type =12; b->collection = "MUO";
                                     } else if (strcmp($8,"TAU") == 0 ) {
                                      b->type =11; b->collection = "TAU";
                                     }
                                     vector<myParticle*> newList;
                                     newList.push_back(a);
                                     newList.push_back(b);
                                     Node* nnode= new FuncNode(Qof,newList,"q");
                                     vector<Node*> newNList; // cut list
                                     newNList.push_back(nnode);
                                     Node* previous=new ObjectNode("Combo",NULL,createNewCombo,newNList,"Lepto combi" );
                                     Node* obj=new ObjectNode($2,previous,NULL,newNList,$2 );
                                     ObjectCuts->insert(make_pair($2,obj));

                              }
        | OBJ ID ':' UNION '(' ID ',' ID ')' {
                                     DEBUG(" "<<$2<<" is a new Set with "<< $6 <<" and "<< $8 << "\n");
                                     myParticle* a = new myParticle;
                                     myParticle* b = new myParticle;
                                     a->index = 6213;
                                     b->index = 6213;
                                     vector<myParticle*> newList;
                                     map<string, Node *>::iterator it ;
                                     it = ObjectCuts->find($6);
                                     if(it == ObjectCuts->end()) {
                                                ERRBUG($6<<" : ") ;
                                                yyerror(NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,"Object not defined");
                                                YYERROR;
                                       }
                                     ObjectNode* child1=(ObjectNode*)it->second;
                                     a->type =child1->type; a->collection = $6;
//------------------second particle
                                      map<string, Node *>::iterator iu ;
                                      iu = ObjectCuts->find($8);
                                      if(iu == ObjectCuts->end()) {
                                               ERRBUG($8<<" : ") ;
                                               yyerror(NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,"Object not defined");
                                               YYERROR;
                                      }
                                      ObjectNode* child2=(ObjectNode*)iu->second;
                                      b->type =child2->type; b->collection = $8;
                                     
                                     newList.push_back(a);
                                     newList.push_back(b);
                                     Node* nnode= new FuncNode(Qof,newList,"q");
                                     vector<Node*> newNList; // cut list
                                     newNList.push_back(nnode);
                                     Node* previous=new ObjectNode("Combo",NULL,createNewCombo,newNList,"Lepto combi" );
                                     Node* obj=new ObjectNode($2,previous,NULL,newNList,$2 );
                                     ObjectCuts->insert(make_pair($2,obj));
                                  }
        | OBJ ID ':' UNION '(' LEPTON ',' LEPTON ',' LEPTON ')' {
                                     DEBUG(" "<<$2<<" is a new **main Set with "<< $6 <<" and "<< $8 << " and " << $10<<"\n");
                                     myParticle* a = new myParticle;
                                     myParticle* b = new myParticle;
                                     myParticle* c = new myParticle;
                                     a->index = 6213;
                                     b->index = 6213;
                                     c->index = 6213;
                                     if        (strcmp($6,"ELE") == 0 ) {
                                      a->type =1; a->collection = "ELE";
                                     } else if (strcmp($6,"MUO") == 0 ) {
                                      a->type =12; a->collection = "MUO";
                                     } else if (strcmp($6,"TAU") == 0 ) {
                                      a->type =11; a->collection = "TAU";
                                     }

                                     if        (strcmp($8,"ELE") == 0 ) {
                                      b->type =1; b->collection = "ELE";
                                     } else if (strcmp($8,"MUO") == 0 ) {
                                      b->type =12; b->collection = "MUO";
                                     } else if (strcmp($8,"TAU") == 0 ) {
                                      b->type =11; b->collection = "TAU";
                                     }

                                     if        (strcmp($10,"ELE") == 0 ) {
                                      c->type =1; c->collection = "ELE";
                                     } else if (strcmp($10,"MUO") == 0 ) {
                                      c->type =12; c->collection = "MUO";
                                     } else if (strcmp($10,"TAU") == 0 ) {
                                      c->type =11; c->collection = "TAU";
                                     }
                                     vector<myParticle*> newList;
                                     newList.push_back(a);
                                     newList.push_back(b);
                                     newList.push_back(c);
                                     Node* nnode= new FuncNode(Qof,newList,"q");
                                     vector<Node*> newNList; // cut list
                                     newNList.push_back(nnode);
                                     Node* previous=new ObjectNode("Combo",NULL,createNewCombo,newNList,"Lepto combi" );
                                     Node* obj=new ObjectNode($2,previous,NULL,newNList,$2 );
                                     ObjectCuts->insert(make_pair($2,obj));

                              }
         | OBJ ID TAKE ELE criteria {
                                        DEBUG(" "<<$2<<" is a new EleSet\n");
                                        vector<Node*> newList;
                                        TmpCriteria.swap(newList);
                                        Node* previous=new ObjectNode("ELE",NULL,createNewEle,newList,"obj ELE" );
                                        Node* obj=new ObjectNode($2,previous,NULL,newList,$2 );
                                        ObjectCuts->insert(make_pair($2,obj));
                                     }
         | OBJ ID ':' ELE criteria {
                                        DEBUG(" "<<$2<<" is a new EleSet\n");
                                        vector<Node*> newList;
                                        TmpCriteria.swap(newList);
                                        Node* previous=new ObjectNode("ELE",NULL,createNewEle,newList,"obj ELE" );
                                        Node* obj=new ObjectNode($2,previous,NULL,newList,$2 );
                                        ObjectCuts->insert(make_pair($2,obj));
                                     }
	 | OBJ ID TAKE GEN criteria {
                                        DEBUG(" "<<$2<<" is a new GenSet\n");
                                        vector<Node*> newList;
                                        TmpCriteria.swap(newList);
                                        Node* previous=new ObjectNode("Truth",NULL,createNewTruth,newList,"obj Truth" );
                                        Node* obj=new ObjectNode($2,previous,NULL,newList,$2 );
                                        ObjectCuts->insert(make_pair($2,obj));
                                     }
	 | OBJ ID ':' GEN criteria {
                                        DEBUG(" "<<$2<<" is a new GenSet\n");
                                        vector<Node*> newList;
                                        TmpCriteria.swap(newList);
                                        Node* previous=new ObjectNode("Truth",NULL,createNewTruth,newList,"obj Truth" );
                                        Node* obj=new ObjectNode($2,previous,NULL,newList,$2 );
                                        ObjectCuts->insert(make_pair($2,obj));
				   }
                                     
         | OBJ ID TAKE MUO criteria {
                                        DEBUG(" "<<$2<<" is a new MuoSet\n");
                                        vector<Node*> newList;
                                        TmpCriteria.swap(newList);
                                        Node* previous=new ObjectNode("MUO",NULL,createNewMuo,newList,"obj MUO" );
                                        Node* obj=new ObjectNode($2,previous,NULL,newList,$2 );
                                        ObjectCuts->insert(make_pair($2,obj));
                                     }
         | OBJ ID ':' MUO criteria {
                                        DEBUG(" "<<$2<<" is a new MuoSet\n");
                                        vector<Node*> newList;
                                        TmpCriteria.swap(newList);
                                        Node* previous=new ObjectNode("MUO",NULL,createNewMuo,newList,"obj MUO" );
                                        Node* obj=new ObjectNode($2,previous,NULL,newList,$2 );
                                        ObjectCuts->insert(make_pair($2,obj));
                                     }
         | OBJ ID TAKE TAU criteria {
                                        DEBUG(" "<<$2<<" is a new TauSet\n");
                                        vector<Node*> newList;
                                        TmpCriteria.swap(newList);
                                        Node* previous=new ObjectNode("TAU",NULL,createNewTau,newList,"obj TAU" );
                                        Node* obj=new ObjectNode($2,previous,NULL,newList,$2 );
                                        ObjectCuts->insert(make_pair($2,obj));
                                     }
         | OBJ ID ':' TAU criteria {
                                        DEBUG(" "<<$2<<" is a new TauSet\n");
                                        vector<Node*> newList;
                                        TmpCriteria.swap(newList);
                                        Node* previous=new ObjectNode("TAU",NULL,createNewTau,newList,"obj TAU" );
                                        Node* obj=new ObjectNode($2,previous,NULL,newList,$2 );
                                        ObjectCuts->insert(make_pair($2,obj));
                                     }
         | OBJ ID TAKE PHO criteria {   DEBUG(" "<<$2<<" is a new PhoSet\n");
                                        vector<Node*> newList;
                                        TmpCriteria.swap(newList);
                                        Node* previous=new ObjectNode("PHO",NULL,createNewPho,newList,"obj Pho" );
                                        Node* obj=new ObjectNode($2,previous,NULL,newList,$2 );
                                        ObjectCuts->insert(make_pair($2,obj));
                                    }
         | OBJ ID ':' PHO criteria {    DEBUG(" "<<$2<<" is a new PhoSet\n");
                                        vector<Node*> newList;
                                        TmpCriteria.swap(newList);
                                        Node* previous=new ObjectNode("PHO",NULL,createNewPho,newList,"obj Pho" );
                                        Node* obj=new ObjectNode($2,previous,NULL,newList,$2 );
                                        ObjectCuts->insert(make_pair($2,obj));
                                    }
         | OBJ ID TAKE JET criteria {   DEBUG(" "<<$2<<" is a new JetSet\n");
                                        vector<Node*> newList;
                                        TmpCriteria.swap(newList);
                                        Node* previous=new ObjectNode("JET",NULL,createNewJet,newList,"obj Jet" ); //
                                        Node* obj=new ObjectNode($2,previous,NULL,newList,$2 );
                                        ObjectCuts->insert(make_pair($2,obj));
                                    }
         | OBJ BJET ':' JET criteria {
                                       yyerror(NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,"*BJET* keyword already defined internally, use another name.");
                                       YYERROR;//stops parsing if variable not found
                                      }
         | OBJ ID ':' JET criteria {    DEBUG(" "<<$2<<" is a new JetSet\n");
                                        vector<Node*> newList;
                                        TmpCriteria.swap(newList);
                                        Node* previous=new ObjectNode("JET",NULL,createNewJet,newList,"obj Jet" ); //
                                        Node* obj=new ObjectNode($2,previous,NULL,newList,$2 );
                                        ObjectCuts->insert(make_pair($2,obj));
                                      }
           | OBJ ID TAKE FJET criteria {
                                        DEBUG(" "<<$2<<" is a new FatJetSet\n");
                                        vector<Node*> newList;
                                        TmpCriteria.swap(newList);
                                        Node* previous=new ObjectNode("FJET",NULL,createNewFJet,newList,"obj FatJet" ); //
                                        Node* obj=new ObjectNode($2,previous,NULL,newList,$2 );
                                        ObjectCuts->insert(make_pair($2,obj));
                                      }
           | OBJ ID ':' FJET criteria {
                                        DEBUG(" "<<$2<<" is a new FatJetSet\n");
                                        vector<Node*> newList;
                                        TmpCriteria.swap(newList);
                                        Node* previous=new ObjectNode("FJET",NULL,createNewFJet,newList,"obj FatJet" ); //
                                        Node* obj=new ObjectNode($2,previous,NULL,newList,$2 );
                                        ObjectCuts->insert(make_pair($2,obj));
                                      }
/*
	  | OBJ ID TAKE GEN criteria {
	                                        DEBUG(" "<<$2<<" is a new GenSet\n");
	                                        vector<Node*> newList;
	                                        TmpCriteria.swap(newList);
	                                        Node* previous=new ObjectNode("Truth",NULL,createNewTruth,newList,"obj Truth" );
	                                        Node* obj=new ObjectNode($2,previous,NULL,newList,$2 );
	                                        ObjectCuts->insert(make_pair($2,obj));
	                             }
	 | OBJ ID ':' GEN criteria {
	                                        DEBUG(" "<<$2<<" is a new GenSet\n");
	                                        vector<Node*> newList;
	                                        TmpCriteria.swap(newList);
	                                        Node* previous=new ObjectNode("Truth",NULL,createNewTruth,newList,"obj Truth" );
	                                        Node* obj=new ObjectNode($2,previous,NULL,newList,$2 );
	                                        ObjectCuts->insert(make_pair($2,obj));
				   }
*/	
             | OBJ ID TAKE LEP criteria
//           | OBJ ID ':' BJET criteria
//           | OBJ ID ':' QGJET criteria
//           | OBJ ID ':' NUMET criteria
//           | OBJ ID ':' METLV criteria
           ;
idlist  : ID ',' idlist { DEBUG($1<<" + "); 
               map<string, Node*>::iterator it ;
               string name = $1;
               it = NodeVars->find(name);
	       if(it == NodeVars->end()) { DEBUG(name<<" : "<<name<<"\n");
                                           yyerror(NULL,NULL,NULL,NULL,NULL,NULL, NULL,NULL,NULL,NULL,"Variable already defined");
                                           YYERROR;//stops parsing if variable already defined
                                        }
               TmpIDList.push_back(it->second);
        }
        | ID { DEBUG($1 <<"\n");
               map<string, Node*>::iterator it ;
               string name = $1;
               it = NodeVars->find(name);
	       if(it == NodeVars->end()) { DEBUG(name<<" : "<<name<<"\n");
                                           yyerror(NULL,NULL,NULL,NULL,NULL,NULL, NULL,NULL,NULL,NULL,"Variable already defined");
                                           YYERROR;//stops parsing if variable already defined
                                        }
               TmpIDList.push_back(it->second);
         }
        ;
counts  : acount 
        | counts ',' acount 
        ;
acount  : NUMBER '+' NUMBER '-' NUMBER '+' NUMBER '-' NUMBER { DEBUG(" + - +  -\n"); 
                                            chist_a.push_back($1); chist_stat_p.push_back($3); chist_stat_n.push_back($5);
                                                                   chist_syst_p.push_back($7); chist_syst_n.push_back($9);
                                         }
        | NUMBER '+' NUMBER '+' NUMBER '-' NUMBER '-' NUMBER { DEBUG(" + + -  -\n");
                                            chist_a.push_back($1); chist_stat_p.push_back($3); chist_stat_n.push_back($7);
                                                                   chist_syst_p.push_back($5); chist_syst_n.push_back($9);
                                         }
        | NUMBER PM NUMBER PM NUMBER { DEBUG(" 2 +-\n"); 
                                            chist_a.push_back($1); chist_stat_p.push_back($3); chist_stat_n.push_back($3);
                                                                   chist_syst_p.push_back($5); chist_syst_n.push_back($5);
                         }
        | NUMBER PM NUMBER '+' NUMBER '-' NUMBER { DEBUG(" +- +  -\n"); 
                                            chist_a.push_back($1); chist_stat_p.push_back($3); chist_stat_n.push_back($3);
                                                                   chist_syst_p.push_back($5); chist_syst_n.push_back($7);
                                 }
        | NUMBER '+' NUMBER '-' NUMBER PM NUMBER { DEBUG(" + -  +-\n"); 
                                            chist_a.push_back($1); chist_stat_p.push_back($3); chist_stat_n.push_back($5);
                                                                   chist_syst_p.push_back($7); chist_syst_n.push_back($7);
                                 }
        | NUMBER '+' NUMBER '-' NUMBER { DEBUG(" + -  \n"); 
                                            chist_a.push_back($1); chist_stat_p.push_back($3); chist_stat_n.push_back($5);
                                                                    chist_syst_p.push_back(0); chist_syst_n.push_back(0);
                                 }
        | NUMBER   PM    NUMBER  { DEBUG(" +-  \n"); 
                                            chist_a.push_back($1); chist_stat_p.push_back($3); chist_stat_n.push_back($3);
                                                                    chist_syst_p.push_back(0); chist_syst_n.push_back(0);
                                 }
        | NUMBER { DEBUG("no err\n"); 
                                            chist_a.push_back($1); chist_stat_p.push_back(0); chist_stat_n.push_back(0);
                                                                   chist_syst_p.push_back(0); chist_syst_n.push_back(0);
          }
        ;
boxlist : boxlist abox
        | abox
        ;
abox : NB  {
        tmpBinlist.push_back($1);
       }
       ;
hamhum : ALIAS ID {
          DEBUG ("ALIAS found.\t");
          TmpParticle.swap( CombiParticle);
          string name = $2;
          myParticle* a = new myParticle;
          a->type =20; a->index = 6213; a->collection = "Combo";
	  AliasList.push_back(a);
          ListParts->insert(make_pair(name,AliasList));
          DEBUG (name<<" inserted\n");
         }  
         ;
criteria : criteria criterion 
         | criterion 
         ;
criterion : CMD condition   { TmpCriteria.push_back($2); }
          | CMD action      { TmpCriteria.push_back($2); }
          | REJEC condition { Node* a = new BinaryNode(LogicalNot,$2,$2,"NOT");
                              TmpCriteria.push_back(a); }

          | HISTO ID ',' description ',' INT ',' NUMBER ',' NUMBER ',' ID {
                                        map<string, Node *>::iterator it ;
                                        it = NodeVars->find($12);
                                        if(it == NodeVars->end()) {
                                                DEBUG($12<<" : ");
                                                yyerror(NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,"Histo variable not defined");
                                                YYERROR;//stops parsing if variable not found
                                        }
                                        else {
                                                Node* child=it->second;
                                                Node* h=new HistoNode1D($2,$4,$6,$8,$10,child);
                                                TmpCriteria.push_back(h);
                                        }
    
				}
        | HISTO ID ',' description ',' INT ',' NUMBER ',' NUMBER ',' function {
                                                Node* h=new HistoNode1D($2,$4,$6,$8,$10,$12);
                                                TmpCriteria.push_back(h);
				}
	| HISTO ID ',' description ',' INT ',' NUMBER ',' NUMBER ',' INT ',' NUMBER ',' NUMBER ',' ID ',' ID {
					map<string, Node *>::iterator it1 ;
					map<string, Node *>::iterator it2 ;
                                        it1 = NodeVars->find($18);
					it2 = NodeVars->find($20);
                        
                                        if(it1 != NodeVars->end() && it2 != NodeVars->end()) {
                                                Node* child1=it1->second;
						Node* child2=it2->second;
                                                Node* h=new HistoNode2D($2,$4,$6,$8,$10,$12,$14, $16,child1,child2);
                                                TmpCriteria.push_back(h);
                                        }
                                        else {
						DEBUG($18 <<"or" << $20 <<" : ");
                                                yyerror(NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,"Histo variable not defined");
                                                YYERROR;//stops parsing if variable not found
                                        }
					}
	| HISTO ID ',' description ',' INT ',' NUMBER ',' NUMBER ',' INT ',' NUMBER ',' NUMBER ',' ID ',' function {
                                        map<string, Node *>::iterator it ;
                                        it = NodeVars->find($18);
                                        if(it == NodeVars->end()) {
                                                DEBUG($18<<" : ");
                                                yyerror(NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,"Histo variable not defined");
                                                YYERROR;//stops parsing if variable not found
                                        }
                                        else {
                                                Node* child=it->second;
                                                Node* h=new HistoNode2D($2,$4,$6,$8,$10,$12,$14, $16,child,$20);
                                                TmpCriteria.push_back(h);
                                        }
					}
	| HISTO ID ',' description ',' INT ',' NUMBER ',' NUMBER ',' INT ',' NUMBER ',' NUMBER ',' function ',' ID {
                                        //find child node
                                        map<string, Node *>::iterator it ;
                                        it = NodeVars->find($20);
                        
                                        if(it == NodeVars->end()) {
                                                DEBUG($20<<" : ");
                                                yyerror(NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,"Histo variable not defined");
                                                YYERROR;//stops parsing if variable not found
                                        }
                                        else {
                                                Node* child=it->second;
                                                Node* h=new HistoNode2D($2,$4,$6,$8,$10,$12,$14, $16, $18, child);
                                                NodeCuts->insert(make_pair(++cutcount,h));
                                                TmpCriteria.push_back(h);
                                        }
					}
	| HISTO ID ',' description ',' INT ',' NUMBER ',' NUMBER ',' INT ',' NUMBER ',' NUMBER ',' function ',' function {
                                                Node* h=new HistoNode2D($2,$4,$6,$8,$10,$12,$14, $16, $18, $20);
                                                TmpCriteria.push_back(h);
				}
	;
commands : commands command 
        | 
        ;
bins    : bins NUMBER {tmpBoxlist.push_back($2);}
        | NUMBER {tmpBoxlist.push_back($1);}
        ;
command : CMD condition { //find a way to print commands                                     
                        NodeCuts->insert(make_pair(++cutcount,$2));
	                }
	|REJEC condition {
			Node* a = new BinaryNode(LogicalNot,$2,$2,"NOT");
			NodeCuts->insert(make_pair(++cutcount,a));
			}
        | BINS e bins {
                        DEBUG("< lim:"<<tmpBoxlist[0]<<"\n");
                         Node* l2=new ValueNode(tmpBoxlist[0] );
                         Node* c2=new BinaryNode(le,$2,l2,"<=");
                         BinCuts->insert(make_pair(++bincount, c2));
                        for (int in=1; in<tmpBoxlist.size(); in++){
                         DEBUG("lim:"<<tmpBoxlist[in-1]<<" -- "<< tmpBoxlist[in]<<"\n");
                         Node* l1=new ValueNode(tmpBoxlist[in-1] );
                         Node* l2=new ValueNode(tmpBoxlist[in  ] );
                         Node* c1=new BinaryNode(ge,$2,l1,">=");
                         Node* c2=new BinaryNode(le,$2,l2,"<=");
                         Node* cl=new BinaryNode(LogicalAnd,c1,c2,"AND");
                         BinCuts->insert(make_pair(++bincount, cl));
                        }
                        DEBUG("> lim:"<<tmpBoxlist[tmpBoxlist.size()-1]<<"\n");
                         Node* l1=new ValueNode(tmpBoxlist[ tmpBoxlist.size()-1 ] );
                         Node* c1=new BinaryNode(ge,$2,l1,">=");
                         BinCuts->insert(make_pair(++bincount, c1));
                        tmpBoxlist.clear();
                      } 
        | BINS condition {  DEBUG("a new bin is found\n"); 
                            BinCuts->insert(make_pair(++bincount, $2));
                        }
        | ALGO ID {  cout << " ALGO: "<< $2<<" \t";
                  }
        | SAVE ID { NodeCuts->insert(make_pair(++cutcount, new SaveNode($2))); }
        | CMD ALL { Node* a = new SFuncNode(all,1, "all");
                    NodeCuts->insert(make_pair(++cutcount,a));
		  }
        | CMD LEPSF { Node* a=new SFuncNode(lepsf,1,"LEPSF");
                      NodeCuts->insert(make_pair(++cutcount,a));
                    }
        | CMD BTAGSF { Node* a=new SFuncNode(btagsf,1,"BTAGSF");
                       NodeCuts->insert(make_pair(++cutcount,a));
                    }
        | CMD XSLUMICORRSF {    
                        Node* a=new SFuncNode(xslumicorrsf,1,"XSLUMICORRSF");
                        NodeCuts->insert(make_pair(++cutcount,a));
                    }
        | CMD APPLYHM '(' ID '(' e ',' e ')' EQ INT ')' { 
                                DEBUG("Hit-Miss using "<< $4 <<" o/x:"<< $11 <<"\n");
                                map<string, pair<vector<float>, bool> >::iterator itt;
                                string name = $4;
                                itt = ListTables->find(name);
                                if(itt == ListTables->end()) {
                                       DEBUG(name<<" : ");
                                       yyerror(NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,"HM Table NOT defined");
                                       YYERROR;//stops parsing if table is not defined
                                }
                                Node* b;
				Node* a = new TableNode(thitmiss,$6, $8, itt->second, "applyHM"); //function, 
                                if ($11 < 0.5 ) {b = new LoopNode(hitmissR, a,"hitmissRej");}
                                else b = new LoopNode(hitmissA, a,"hitmissAcc");
                                NodeCuts->insert(make_pair(++cutcount,b));
                    }
        | CMD APPLYHM '(' ID '(' e ')' EQ INT ')' { 
                                DEBUG("Hit-Miss using "<< $4 <<" o/x:"<< $9 <<"\n");
                                map<string, pair<vector<float>, bool> >::iterator itt;
                                string name = $4;
                                itt = ListTables->find(name);
                                if(itt == ListTables->end()) {
                                       DEBUG(name<<" : ");
                                       yyerror(NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,"HM Table NOT defined");
                                       YYERROR;//stops parsing if table is not defined
                                }
                                Node* b;
				Node* a = new TableNode(thitmiss,$6,itt->second, "applyHM"); //function, 
                                if ($9 < 0.5 ) {b = new LoopNode(hitmissR, a,"hitmissRej");}
                                else b = new LoopNode(hitmissA, a,"hitmissAcc");
                                NodeCuts->insert(make_pair(++cutcount,b));
                    }
    	| WEIGHT ID ID {  map<string, Node *>::iterator it ;
                          it = NodeVars->find($3);
                          if(it == NodeVars->end()) {
                                DEBUG($3<<" : ");
                                yyerror(NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,"Weight variable not defined");
                                YYERROR;//stops parsing if variable not found
                           } 
                           Node* child=it->second;
                           Node* a = new SFuncNode(uweight, child ,$2);
			   NodeCuts->insert(make_pair(++cutcount,a));
                        }
 
    	| WEIGHT ID NB { Node* a = new SFuncNode(uweight,$3,$2); // (func, value, string)
			NodeCuts->insert(make_pair(++cutcount,a));
			}
    	| WEIGHT ID ID '(' function ')' {
                                DEBUG("Weight "<< $2  <<"Will be from table "<< $3<< " using variable: "<< $5 << "\n");
                                map<string, pair<vector<float>, bool> >::iterator itt;
                                string name = $3;
                                itt = ListTables->find(name);
                                if(itt == ListTables->end()) {
                                       DEBUG(name<<" : ");
                                       yyerror(NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,"Table NOT defined");
                                       YYERROR;//stops parsing if table is not defined
                                }
				Node* a = new TableNode(tweight,$5,itt->second, $2);
				NodeCuts->insert(make_pair(++cutcount,a));
			}
    	| WEIGHT ID ID '(' function ',' function ')' {
                                DEBUG("Weight named "<< $2  <<" will be from table "<< $3<< " using variables: "<< $5 <<","<< $7 << "\n");
                                map<string, pair<vector<float>,bool> >::iterator itt;
                                string name = $3;
                                itt = ListTables->find(name);
                                if(itt == ListTables->end()) {
                                       DEBUG(name<<" : ");
                                       yyerror(NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,"Table NOT defined");
                                       YYERROR;//stops parsing if table is not defined
                                }
				Node* a = new TableNode(tweight,$5, $7, itt->second, $2);
				NodeCuts->insert(make_pair(++cutcount,a));
			}



        | CMD ifstatement {   NodeCuts->insert(make_pair(++cutcount,$2));
		          }
        | COUNTS ID counts { DEBUG ("Getting counts fmt: "<<$2<<": ");
                       std::string aCutHist=$2;
                       std::map<string, std::vector<cntHisto> >::iterator chit;
                       chit = cntHistos->find(aCutHist);
                       DEBUG(chit->second.size()<<" =? "<<chist_a.size() <<"\n");
                       for (int ichi=0; ichi<chit->second.size(); ichi++){
                           chit->second.at(ichi).cH_means.push_back(chist_a[ichi] );
                           chit->second.at(ichi).cH_StatErr_p.push_back(chist_stat_p[ichi] );
                           chit->second.at(ichi).cH_StatErr_n.push_back(chist_stat_n[ichi] );
                           chit->second.at(ichi).cH_SystErr_p.push_back(chist_syst_p[ichi] );
                           chit->second.at(ichi).cH_SystErr_n.push_back(chist_syst_n[ichi] );
                       }
                       chist_a.clear();
                       chist_stat_p.clear(); chist_stat_n.clear(); chist_syst_p.clear(); chist_syst_n.clear();
                     }

        | HISTO ID ',' description ',' INT ',' NUMBER ',' NUMBER ',' ID {
                                        map<string, Node *>::iterator it ;
                                        it = NodeVars->find($12);
                        
                                        if(it == NodeVars->end()) {
                                                DEBUG($12<<" : ");
                                                yyerror(NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,"Histo variable not defined");
                                                YYERROR;//stops parsing if variable not found
                                        }
                                        else {
                                                Node* child=it->second;
                                                Node* h=new HistoNode1D($2,$4,$6,$8,$10,child);
                                                NodeCuts->insert(make_pair(++cutcount,h));
                                        }
				}
        | HISTO ID ',' description ',' INT ',' NUMBER ',' NUMBER ',' function {
                                                DEBUG("INT NB NB 1D func histo defined.\n");
                                                Node* h=new HistoNode1D($2,$4,$6,$8,$10,$12);
                                                NodeCuts->insert(make_pair(++cutcount,h));
				}
	| HISTO ID ',' description ',' INT ',' NUMBER ',' NUMBER ',' INT ',' NUMBER ',' NUMBER ',' ID ',' ID {
					map<string, Node *>::iterator it1 ;
					map<string, Node *>::iterator it2 ;
                                        it1 = NodeVars->find($18);
					it2 = NodeVars->find($20);
                                        if(it1 != NodeVars->end() && it2 != NodeVars->end()) {
                                                Node* child1=it1->second;
						Node* child2=it2->second;
                                                Node* h=new HistoNode2D($2,$4,$6,$8,$10,$12,$14, $16,child1,child2);
                                                NodeCuts->insert(make_pair(++cutcount,h));
                                        }
                                        else {
						DEBUG($18 <<"or" << $20 <<" : ");
                                                yyerror(NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,"Histo variable not defined");
                                                YYERROR;//stops parsing if variable not found
                                        }
					}
	| HISTO ID ',' description ',' INT ',' NUMBER ',' NUMBER ',' INT ',' NUMBER ',' NUMBER ',' ID ',' function {
                                        //find child node
                                        map<string, Node *>::iterator it ;
                                        it = NodeVars->find($18);
                        
                                        if(it == NodeVars->end()) {
                                                DEBUG($18<<" : ");
                                                yyerror(NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,"Histo variable not defined");
                                                YYERROR;//stops parsing if variable not found
                                        }
                                        else {
                                                Node* child=it->second;
                                                Node* h=new HistoNode2D($2,$4,$6,$8,$10,$12,$14, $16,child,$20);
                                                NodeCuts->insert(make_pair(++cutcount,h));
                                        }
					}
	| HISTO ID ',' description ',' INT ',' NUMBER ',' NUMBER ',' INT ',' NUMBER ',' NUMBER ',' function ',' ID {
                                        //find child node
                                        map<string, Node *>::iterator it ;
                                        it = NodeVars->find($20);
                                        if(it == NodeVars->end()) {
                                                DEBUG($20<<" : ");
                                                yyerror(NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,"Histo variable not defined");
                                                YYERROR;//stops parsing if variable not found
                                        }
                                        else {
                                                Node* child=it->second;
                                                Node* h=new HistoNode2D($2,$4,$6,$8,$10,$12,$14, $16, $18, child);
                                                NodeCuts->insert(make_pair(++cutcount,h));
                                        }
					}
	| HISTO ID ',' description ',' INT ',' NUMBER ',' NUMBER ',' INT ',' NUMBER ',' NUMBER ',' function ',' function {
                                                Node* h=new HistoNode2D($2,$4,$6,$8,$10,$12,$14, $16, $18, $20);
                                                NodeCuts->insert(make_pair(++cutcount,h));
				}
	| SORT e ASCEND { Node* sort = new SortNode($2,"ascend"); NodeCuts->insert(make_pair(++cutcount,sort));}
	| SORT e DESCEND {Node* sort = new SortNode($2,"descend");NodeCuts->insert(make_pair(++cutcount,sort));}
	;
description : description HID {                                                 
                                                string s=$$;
                                                string s2=$2;
                                                s=s+" "+s2;
                                                $$=strdup(s.c_str());
                              }
            | HID {if (dnum==0){ $$=strdup($1);                                                       
                               } else{  
                                                string s=$$;
                                                string s2=$1;
                                                s=s+" "+s2;
                                                $$=strdup(s.c_str());
                                       }
                  }
        ;
//--------------------------------------------------------------------------
ifstatement : condition '?' action ':' action %prec '?' { 
                        $$=new IfNode($1,$3,$5,"if");
                        } 
            ;
action : condition { $$=$1; }
       | ALL { $$=new SFuncNode(all,1,"all"); }
       | APPLYHM '(' ID '(' e ',' e ')' EQ INT ')' { 
                                DEBUG("Hit-Miss using "<< $3 <<" o/x:"<< $10 <<"\n");
                                map<string, pair<vector<float>, bool> >::iterator itt;
                                string name = $3;
                                itt = ListTables->find(name);
                                if(itt == ListTables->end()) {
                                       DEBUG(name<<" : ");
                                       yyerror(NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,"HM Table NOT defined");
                                       YYERROR;//stops parsing if table is not defined
                                }
                                Node* b;
				Node* a = new TableNode(thitmiss,$5, $7, itt->second, "applyHM"); //function, 
                                if ($10 < 0.5 ) {b = new LoopNode(hitmissR, a,"hitmissRej");}
                                else b = new LoopNode(hitmissA, a,"hitmissAcc");
                                $$=b;
                    }
        | APPLYHM '(' ID '(' e ')' EQ INT ')' { 
                                DEBUG("Hit-Miss using "<< $3 <<" o/x:"<< $8 <<"\n");
                                map<string, pair<vector<float>, bool> >::iterator itt;
                                string name = $3;
                                itt = ListTables->find(name);
                                if(itt == ListTables->end()) {
                                       DEBUG(name<<" : ");
                                       yyerror(NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,"HM Table NOT defined");
                                       YYERROR;//stops parsing if table is not defined
                                }
                                Node* b;
				Node* a = new TableNode(thitmiss,$5,itt->second, "applyHM"); //function, 
                                if ($8 < 0.5 ) {b = new LoopNode(hitmissR, a,"hitmissRej");}
                                else b = new LoopNode(hitmissA, a,"hitmissAcc");
                                $$=b;
                    }
       | ifstatement { $$=$1; }
       ;    
condition :  e LT e { $$=new BinaryNode(lt,$1,$3,"<");  }
           | e GT e { $$=new BinaryNode(gt,$1,$3,">");  }
           | e LE e { $$=new BinaryNode(le,$1,$3,"<="); }  
           | e GE e { $$=new BinaryNode(ge,$1,$3,">="); }
           | e EQ e { $$=new BinaryNode(eq,$1,$3,"=="); } 
           | e NE e { $$=new BinaryNode(ne,$1,$3,"<>"); }   
           | e MINIMIZE e { DEBUG ("MINIMIZE\n"); $$=new SearchNode(minim,$1,$3,"~="); }
           | e MAXIMIZE e { DEBUG ("MAXIMIZE\n");$$=new SearchNode(maxim,$1,$3,"!="); }
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
           | condition AND condition { $$=new BinaryNode(LogicalAnd,$1,$3,"AND"); } 
           | condition OR condition  { $$=new BinaryNode(LogicalOr, $1,$3,"OR"); }
	   |           NOT condition { $$=new BinaryNode(LogicalNot,$2,$2,"NOT"); }
           | '(' condition ')' { $$=$2; } 
           ;
%%
