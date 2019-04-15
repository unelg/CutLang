#include "Node.h"

//generic node interface

void Node::getStr(TString *ss){
        if(left!=NULL) left->getStr(ss); 
               (*ss)+=" ";
               (*ss)+=symbol;
        if(right!=NULL) right->getStr(ss);
}

void Node::display(std::string indent){
        if(left!=NULL) left->display(indent+"     "); 
        std::cout<<indent+symbol<<std::endl;
        if(right!=NULL) right->display("\n"+indent+"     ");
}

void Node::display(){ this->display(""); }
     TString Node::getStr(){ TString ss; this->getStr(&ss); return ss; 
}
     
Node::~ Node(){
    }
std::vector<dbxJet> Node::tagJets(AnalysisObjects *ao, int jtype) {                   
                                std::vector<dbxJet>      rjets;
                                for (size_t jj=0; jj<ao->jets.size(); jj++) 
                                  if (ao->jets.at(jj).isbtagged_77() == jtype) {rjets.push_back(ao->jets.at(jj)); }
                                return rjets;
}

