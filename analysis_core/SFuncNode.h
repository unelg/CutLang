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
#include "Razorfunc.h"

//#define _CLV_
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
    double (*g)(AnalysisObjects*, string, int, std::vector<TLorentzVector> (*func)(std::vector<TLorentzVector>));
    std::vector<TLorentzVector> (*h)(std::vector<TLorentzVector>);
    int type;
    bool ext;
public:
    SFuncNode(double (*func)(AnalysisObjects* ao, string s, int id), 
                      int id, 
               std::string s, 
               Node *objectNode = NULL) {
        f=func;
        g=NULL;
        ext=false;
        type=id;
        symbol=s;
        left=NULL;
        right=NULL;
        userObject = objectNode;
    }
//-------------------------
    SFuncNode(double (*func)(AnalysisObjects* ao, string s, int id, std::vector<TLorentzVector> (*gunc) (std::vector<TLorentzVector> jets)),
              std::vector<TLorentzVector> (*tunc) (std::vector<TLorentzVector> jets),
                      int id, 
               std::string s, 
               Node *objectNode = NULL) {
        f=NULL;
        g=func;
        h=tunc;
        ext=false;
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
           DEBUG("user obj done.\n"); 
        }
        std::vector<TLorentzVector> ajets;  
        if(g != NULL) (*g)(ao, symbol, type, h );
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

    DEBUG("STR:"<<s<<" Type:"<<id<< "#J types:"<<ao->jets.size() << " #P types:"<<ao->gams.size()<<"\n");
    map <string, std::vector<dbxJet>  >::iterator it;
    for (it=ao->jets.begin();it!=ao->jets.end();it++){
      DEBUG("\t #Jtypename:"<<it->first<<"    size:"<<it->second.size() <<"\n");
    }
    map <string, std::vector<dbxPhoton>  >::iterator itp;
    for (itp=ao->gams.begin();itp!=ao->gams.end();itp++){
      DEBUG("\t #Ptypename:"<<itp->first<<"    size:"<<itp->second.size() <<"\n");
    }

    switch (pid) {
     case muon_t:     return (ao->muos.at(s).size()); break;
     case electron_t: return (ao->eles.at(s).size()); break;
     case tau_t:      return (ao->taus.at(s).size()); break;
     case jet_t:      return (ao->jets.at(s).size()); break;
     case ljet_t:     return (ao->ljets.at(s).size()); break;
     case photon_t:   return (ao->gams.at(s).size()); break;
     default:         return (-1); break;
    }
    return (-1);
}
double met(AnalysisObjects* ao, string s, int id){
     DEBUG("MET:" << ao->met["MET"].Mod() <<"\n");
    return ( ao->met["MET"].Mod() );
}

double ht(AnalysisObjects* ao, string s, int id){
    double sum_htjet=0;
    for (UInt_t i=0; i<ao->jets.at(s).size(); i++) sum_htjet+=ao->jets.at(s).at(i).lv().Pt();
    return (sum_htjet  );       
}


double userfunc(AnalysisObjects* ao, string s, int id, std::vector<TLorentzVector> (*func)(std::vector<TLorentzVector> jets ) ){
// string contains what to send
// id contains the particle type

  // assume id=jet type,
   std::vector<TLorentzVector> myjets;
   for (UInt_t i=0; i<ao->jets.at(s).size(); i++) myjets.push_back(ao->jets.at(s).at(i).lv() );
   std::vector<TLorentzVector> retjets= (*func)(myjets);

    return (1);       
}








/*
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
