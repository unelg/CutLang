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
#include "myParticle.h"

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
    Node* userObjectA;
    Node* userObjectB;
    Node* userObjectC;
    Node* userObjectD;
    std::string symbol;
    void getStr(TString *ss);
    void display(std::string indent);
public:

    virtual void Reset()=0;
    virtual void getParticles(std::vector<myParticle *>* particles)=0;
    virtual void getParticlesAt(std::vector<myParticle *>* particles,int index)=0;
    void display();
    virtual TString getStr();
    virtual void setUserObjects(Node *objectNodea = NULL, Node *objectNodeb = NULL, Node *objectNodec = NULL, Node *objectNoded = NULL){std::cout<<"Mother adds UOs.\n";
        userObjectA=objectNodea;
        userObjectB=objectNodeb;
        userObjectC=objectNodec;
        userObjectD=objectNoded;
     };

  virtual double evaluate(AnalysisObjects* ao){
   //  std::cout <<"BEFORE M:"<<ao->jets.size()<<"\n";
     if(userObjectA)  userObjectA->evaluate(ao); // returns 1, hardcoded. see ObjectNode.cpp
     if(userObjectB)  userObjectB->evaluate(ao); // returns 1, hardcoded. see ObjectNode.cpp
     if(userObjectC)  userObjectC->evaluate(ao); // returns 1, hardcoded. see ObjectNode.cpp
     if(userObjectD)  userObjectD->evaluate(ao); // returns 1, hardcoded. see ObjectNode.cpp
     if ( userObjectA || userObjectB || userObjectC || userObjectD ) std::cout<<"UOs EVALUATED:"<< getStr() <<"\n";
   //  std::cout <<"AFTER M:"<<ao->jets.size()<<"\n";

    return 0;
  }
    virtual ~ Node();
    std::vector<dbxJet> tagJets(AnalysisObjects *ao, int jtype) ;

};

#endif /* Node_h */
