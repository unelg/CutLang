//include these and only compile main.cpp OR compile together
// #include "l.cpp"
// #include "b.cpp"
#include <iostream>
#include <map>
#include <list>
#include <vector>
#include <iterator>
#include "myParticle.h"
#include "Node.h"
using namespace std;
extern int yyparse(list<string> *parts,map<string,Node*>* NodeVars,map<string,vector<myParticle> >* ListParts,map<int,Node*>* NodeCuts,
                        vector<double>* Initializations , vector<double>* DataFormats
                );
extern FILE* yyin;
int main(void){

    list<string> parts; //for def of particles as given by user
    map<string,Node*> NodeVars;//for variable defintion
    map<string,vector<myParticle> > ListParts;//for particle definition
    map<int,Node*> NodeCuts;//cuts and histos
    vector<double> Initializations=vector<double>(11);
    vector<double> DataFormats=vector<double>(6);
    yyin=fopen("ini.txt","r");
    yyparse(&parts,&NodeVars,&ListParts,&NodeCuts,&Initializations,&DataFormats);
        cout<<"\n Initializing : \n";
        for (vector<double>::iterator a = Initializations.begin(); a  != Initializations.end(); a++){
                cout<<*a<<endl;
        }

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
    map<string,Node* >::iterator itv = NodeVars.begin();
    while(itv != NodeVars.end())
    {
            std::cout<<"**************************** "<<itv->first<<" :: "<<itv->second->evaluate()<<endl;
            itv->second->display();
            std::cout<<std::endl;
            itv++;
    }

    cout<<"\n CUTS : \n";
    std::map<int, Node*>::iterator iter = NodeCuts.begin();
    while(iter != NodeCuts.end())
    {
            cout<<"**************************** CUT "<<iter->first<<" :: "<<(bool)iter->second->evaluate()<<endl;
            iter->second->display();
            std::cout<<endl;
            iter++;
    }		
    return 0;
    
}