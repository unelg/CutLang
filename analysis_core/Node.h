//
//  Node.h
//  mm
//
//  Created by Anna-Monica  on 7/31/18.
//  Copyright © 2018 Anna-Monica. All rights reserved.
//

#ifndef Node_h
#define Node_h
#include <string>
#include <iostream>

#include "dbxParticle.h"
#include "dbx_electron.h"
#include "dbx_photon.h"
#include "dbx_muon.h"
#include "dbx_jet.h"
#include "analysis_core.h"

struct AnalysisObjects {
    std::vector<dbxMuon>     muos;
    std::vector<dbxElectron> eles;
    std::vector<dbxPhoton>   gams;
    std::vector<dbxJet>      jets;
    TVector2            met;
    evt_data            evt;
};

//generic node interface
class Node{
protected:
    Node* left;
    Node* right;
    std::string symbol;
    void getStr(TString *ss){
        if(left!=NULL) left->getStr(ss); 
               (*ss)+=" ";
               (*ss)+=symbol;
        if(right!=NULL) right->getStr(ss);
    }
    void display(std::string indent){
        if(left!=NULL) left->display(indent+"     "); 
        std::cout<<indent+symbol<<std::endl;
        if(right!=NULL) right->display("\n"+indent+"     ");
    }
public:

    virtual void Reset()=0;
    virtual void getParticles(std::vector<myParticle *>* particles)=0;
    void display(){ this->display(""); }
    virtual TString getStr(){ TString ss; this->getStr(&ss); return ss; }
    virtual double evaluate(AnalysisObjects* ao)=0;
    virtual ~ Node(){
    }
    std::vector<dbxJet> tagJets(AnalysisObjects *ao, int jtype) {                   
                                std::vector<dbxJet>      rjets;
                                for (size_t jj=0; jj<ao->jets.size(); jj++) 
                                  if (ao->jets.at(jj).isbtagged_77() == jtype) {rjets.push_back(ao->jets.at(jj)); }
                                return rjets;
    }

};

#endif /* Node_h */
