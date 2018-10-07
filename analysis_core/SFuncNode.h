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
using namespace std;
//takes care of functions with arguments
class SFuncNode : public Node {
private:
    //should add something related to trigger types
    Node* userObject;
    double (*f)(AnalysisObjects*);
public:
    SFuncNode(double (*func)(AnalysisObjects* ao), std::string s, Node *objectNode = NULL) 
    {
        f=func;
        symbol=s;
        left=NULL;
        right=NULL;
        userObject = objectNode;
    }
    
    virtual double evaluate(AnalysisObjects* ao) override {
        if(userObject) {
            userObject->evaluate(ao); // returns 1, hardcoded. see ObjectNode.cpp
        }
        return (*f)(ao);
    }

    virtual void Reset() override{}
    virtual void getParticles(std::vector<myParticle *>* particles) override{}
    virtual void getParticlesAt(std::vector<myParticle *>* particles, int index) override{}
    virtual ~SFuncNode() {}
};

double all(AnalysisObjects* ao){
    return 1;
}
double njets(AnalysisObjects* ao) {
    return (ao->jets.size());
}
double neles(AnalysisObjects* ao){
    return (ao->eles.size() );
}
double nmuos(AnalysisObjects* ao){
    return (ao->muos.size() );
}
double nphos(AnalysisObjects* ao){
    return (ao->gams.size() );
}
double met(AnalysisObjects* ao){
    return ( ao->met.Mod() );
}
double nbjets(AnalysisObjects* ao){
    ValueNode abc=ValueNode();
    return (abc.tagJets(ao, 1).size() );
}

double nljets(AnalysisObjects* ao){
    ValueNode abc=ValueNode();
    return (abc.tagJets(ao, 0).size() );
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


#endif /* SFuncNode_h */
