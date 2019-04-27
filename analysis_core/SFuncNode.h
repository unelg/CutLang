//
//  SFuncNode.h
//  mm
//
//  Created by Anna-Monica  on 8/2/18.
//  Copyright © 2018 Anna-Monica. All rights reserved.
//

#ifndef SFuncNode_h
#define SFuncNode_h
#include "Node.h"

#ifdef _CLV_
#define DEBUG(a) std::cout<<a
#else
#define DEBUG(a)
#endif

using namespace std;
//takes care of functions with arguments
class SFuncNode : public Node {
private:
    //should add something related to trigger types
    Node* userObject;
    double (*f)(AnalysisObjects*, string, int);
    int type;
public:
    SFuncNode(double (*func)(AnalysisObjects* ao, string s, int id), 
                      int id, 
               std::string s, 
               Node *objectNode = NULL) {
        f=func;
        type=id;
        symbol=s;
        left=NULL;
        right=NULL;
        userObject = objectNode;
    }
    
    virtual double evaluate(AnalysisObjects* ao) override {
        DEBUG("In SF Eval\n"); 
        if(userObject) {
           DEBUG("\t a user obj\n"); 
           userObject->evaluate(ao); // returns 1, hardcoded. see ObjectNode.cpp
        }
        return (*f)(ao, symbol, type);
    }

    virtual void Reset() override{}
    virtual void getParticles(std::vector<myParticle *>* particles) override{}
    virtual void getParticlesAt(std::vector<myParticle *>* particles, int index) override{}
    virtual ~SFuncNode() {}
};

double all(AnalysisObjects* ao, string s, int id){
    return 1;
}
double count(AnalysisObjects* ao, string s, int id) {
    particleType pid = (particleType)id;

    DEBUG("STR:"<<s<<" Type:"<<id<< "#J types:"<<ao->jets.size() <<"\n");
    map <string, std::vector<dbxJet>  >::iterator it;
    for (it=ao->jets.begin();it!=ao->jets.end();it++){
      DEBUG("\t #Jtypename:"<<it->first<<"    size:"<<it->second.size() <<"\n");
    }


    switch (pid) {
     case muon_t:     return (ao->muos[s].size()); break;
     case electron_t: return (ao->eles[s].size()); break;
     case jet_t:      return (ao->jets[s].size()); break;
     default:         return (-1); break;
    }
    return (-1);
}
/*
double met(AnalysisObjects* ao){
    return ( ao->met["MET"].Mod() );
}
double nbjets(AnalysisObjects* ao){
    ValueNode abc=ValueNode();
//    return (abc.tagJets(ao, 1).size() );
    return (1);
}

double nljets(AnalysisObjects* ao){
    ValueNode abc=ValueNode();
//    return (abc.tagJets(ao, 0).size() );
    return (1);
}

double ht(AnalysisObjects* ao){
    double sum_htjet=0;
    for (UInt_t i=0; i<ao->jets.size(); i++) sum_htjet+=ao->jets.at(i).lv().Pt();
    return (sum_htjet  );       
}

double emwt(AnalysisObjects* ao){
    double theLeptonTrkPhi = ao->eles.at(0).lv().Phi();
    double           leppt = ao->eles.at(0).lv().Pt();
    double dphi_e_et = fabs(theLeptonTrkPhi - ao->met.Phi());
    if (dphi_e_et>M_PI) dphi_e_et=2*M_PI-dphi_e_et;
    float mwt=sqrt(2*leppt*ao->met.Mod()*(1-cos(dphi_e_et)));
    return (mwt);
} 

double mmwt(AnalysisObjects* ao){
    double theLeptonTrkPhi = ao->muos.at(0).lv().Phi();
    double           leppt = ao->muos.at(0).lv().Pt();
    double dphi_e_et = fabs(theLeptonTrkPhi - ao->met.Phi());
    if (dphi_e_et>M_PI) dphi_e_et=2*M_PI-dphi_e_et;
    float mwt=sqrt(2*leppt*ao->met.Mod()*(1-cos(dphi_e_et)));
    return (mwt);
} 

double mmetmwt(AnalysisObjects* ao){
    double theLeptonTrkPhi = ao->muos.at(0).lv().Phi();
    double           leppt = ao->muos.at(0).lv().Pt();
    double dphi_e_et = fabs(theLeptonTrkPhi - ao->met.Phi());
    if (dphi_e_et>M_PI) dphi_e_et=2*M_PI-dphi_e_et;
    float mwt=sqrt(2*leppt*ao->met.Mod()*(1-cos(dphi_e_et)));
    return (mwt+ao->met.Mod() );
}

double emetmwt(AnalysisObjects* ao){
    double theLeptonTrkPhi = ao->eles.at(0).lv().Phi();
    double           leppt = ao->eles.at(0).lv().Pt();
    double dphi_e_et = fabs(theLeptonTrkPhi - ao->met.Phi());
    if (dphi_e_et>M_PI) dphi_e_et=2*M_PI-dphi_e_et;
    float mwt=sqrt(2*leppt*ao->met.Mod()*(1-cos(dphi_e_et)));
    return (mwt+ao->met.Mod() );
}
*/

#endif /* SFuncNode_h */
