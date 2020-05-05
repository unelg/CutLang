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
#include "Hemisphere.h"
#include "CMSSUS16048_functions.h"
#include "mt2_bisect.h"

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
    Node* userObjectA;
    Node* userObjectB;
    double (*f)(AnalysisObjects*, string, float);
    double (*g1)(AnalysisObjects*, string, int, std::vector<TLorentzVector> (*func)(std::vector<TLorentzVector>));
    double (*g2)(AnalysisObjects*, string, int,                      double (*func)(std::vector<TLorentzVector>));
    double (*g3)(AnalysisObjects*, string, int,                      double (*func)(std::vector<TLorentzVector>, TVector2 ));
    double (*g4)(AnalysisObjects*, string, int,   TLorentzVector,    double (*func)(std::vector<TLorentzVector>, TLorentzVector ));
    double (*g5)(AnalysisObjects*, string, int, TLorentzVector, TLorentzVector, TLorentzVector,   double (*func)(TLorentzVector, TLorentzVector, TLorentzVector ));
    std::vector<TLorentzVector> (*h1)(std::vector<TLorentzVector>);
                         double (*h2)(std::vector<TLorentzVector>);
                         double (*h3)(std::vector<TLorentzVector>, TVector2 );
                         double (*h4)(std::vector<TLorentzVector>, TLorentzVector );
                         double (*h5)(TLorentzVector, TLorentzVector, TLorentzVector );

    bool ext;
    int type = 1;
    float value = 1.0;
    std::vector<myParticle*> inputParticlesA;
    std::vector<myParticle*> inputParticlesB;
    std::vector<myParticle*> inputParticlesC;
public:
    SFuncNode(double (*func)(AnalysisObjects* ao, string s, float val), 
              float val, 
              std::string s, 
              Node *objectNodeA = NULL, Node *objectNodeB = NULL) {
        f=func;
        g1=NULL;
        g2=NULL;
        g3=NULL;
        g4=NULL;
        g5=NULL;
        ext=false;
        value=val;
        symbol=s;
        left=NULL;
        right=NULL;
        userObjectA = objectNodeA;
        userObjectB = objectNodeB;
    }

//-------------------------extern.........
    SFuncNode(double (*func)(AnalysisObjects* ao, string s, int id, std::vector<TLorentzVector> (*gunc) (std::vector<TLorentzVector> jets)),
              std::vector<TLorentzVector> (*tunc) (std::vector<TLorentzVector> jets),
                      int id, 
               std::string s, 
               Node *objectNodeA = NULL, Node *objectNodeB = NULL) {
        DEBUG("*****************************************EXTERN SF :"<<s <<"\n");
        f=NULL;
        g3=NULL;
        g2=NULL;
        g4=NULL;
        g5=NULL;
        g1=func;
        h1=tunc;
        ext=true;
        type=id;
        symbol=s;
        left=NULL;
        right=NULL;
        userObjectA = objectNodeA;
        userObjectB = objectNodeB;
    }
    SFuncNode(double (*func)(AnalysisObjects* ao, string s, int id, double (*gunc) (std::vector<TLorentzVector> jets)),
              double (*tunc) (std::vector<TLorentzVector> jets),
                      int id, 
               std::string s, 
               Node *objectNodeA = NULL, Node *objectNodeB = NULL) {
        DEBUG("*****************************************EXTERN SF :"<<s <<"\n");
        f=NULL;
        g5=NULL;
        g4=NULL;
        g3=NULL;
        g1=NULL;
        g2=func;
        h2=tunc;
        ext=true;
        type=id;
        symbol=s;
        left=NULL;
        right=NULL;
        userObjectA = objectNodeA;
        userObjectB = objectNodeB;
    }
    SFuncNode(double (*func)(AnalysisObjects* ao, string s, int id, double (*gunc) (std::vector<TLorentzVector> jets, TVector2 amet)),
              double (*tunc) (std::vector<TLorentzVector> jets, TVector2 amet),
                      int id, 
               std::string s, 
               Node *objectNodeA = NULL, Node *objectNodeB = NULL) {
        DEBUG("*****************************************EXTERN SF :"<<s <<"\n");
        f=NULL;
        g1=NULL;
        g2=NULL;
        g4=NULL;
        g5=NULL;
        g3=func;
        h3=tunc;
        ext=true;
        type=id;
        symbol=s;
        left=NULL;
        right=NULL;
        userObjectA = objectNodeA;
        userObjectB = objectNodeB;
    }
    SFuncNode(double (*func)(AnalysisObjects* ao, string s, int id, TLorentzVector alv, double (*gunc) (std::vector<TLorentzVector> jets, TLorentzVector amet)),
              double (*tunc) (std::vector<TLorentzVector> jets, TLorentzVector amet),
                      int id, 
               std::string s,
               std::vector<myParticle*> input, 
               Node *objectNodeA = NULL, Node *objectNodeB = NULL) {
        DEBUG("*****************************************EXTERN SF :"<<s <<"\n");
        f=NULL;
        g1=NULL;
        g2=NULL;
        g3=NULL;
        g5=NULL;
        g4=func;
        h4=tunc;
        ext=true;
        type=id;
        symbol=s;
        left=NULL;
        right=NULL;
        inputParticlesA=input;
        userObjectA = objectNodeA;
        userObjectB = objectNodeB;
    }
    SFuncNode(double (*func)(AnalysisObjects* ao, string s, int id, TLorentzVector a1, TLorentzVector a2, TLorentzVector b1, double (*gunc) (TLorentzVector lep1, TLorentzVector lep2, TLorentzVector amet)),
              double (*tunc) (TLorentzVector lep1, TLorentzVector lep2, TLorentzVector amet),
                      int id, 
               std::string s,
               std::vector<myParticle*> input1, 
               std::vector<myParticle*> input2, 
               std::vector<myParticle*> input3, 
               Node *objectNodeA = NULL, Node *objectNodeB = NULL) {
        DEBUG("*****************************************EXTERN SF T5:"<<s <<"\n");
        f=NULL;
        g1=NULL;
        g2=NULL;
        g3=NULL;
        g4=NULL;
        g5=func;
        h5=tunc;
        ext=true;
        type=id;
        symbol=s;
        left=NULL;
        right=NULL;
        inputParticlesA=input1;
        inputParticlesB=input2;
        inputParticlesC=input3;
        userObjectA = objectNodeA;
        userObjectB = objectNodeB;
 }

//---------------------------end of externs
virtual void setSymbol(string s) { symbol=s; }
    
virtual double evaluate(AnalysisObjects* ao) override {
        DEBUG("*******In SF, Extern True/False:"<< ext <<"\n"); 
        if(userObjectA && !ext) {
           DEBUG("\t a user obj\n"); 
           userObjectA->evaluate(ao); // returns 1, hardcoded. see ObjectNode.cpp
           DEBUG("user obj done.\n"); 
        }
        if(userObjectB && !ext) {
           DEBUG("\t b user obj\n"); 
           userObjectB->evaluate(ao); // returns 1, hardcoded. see ObjectNode.cpp
           DEBUG("user obj done.\n"); 
        }
        dbxParticle *aPart= new dbxParticle;
        dbxParticle *bPart= new dbxParticle;
        dbxParticle *cPart= new dbxParticle;

        if ( inputParticlesA.size()>0 ){
           aPart->Reset();
           TLorentzVector ametlv;
           DEBUG("\t input particles A\n"); 
           for(vector<myParticle*>::iterator i=inputParticlesA.begin();i!=inputParticlesA.end();i++){
               DEBUG("type:"<<(*i)->type<<" index:"<< (*i)->index<< " addr:"<<*i<<  "\t name:"<< (*i)->collection<<"\n");
              int atype=(*i)->type;
                int ai=(*i)->index;
             string ac=(*i)->collection;
             if (atype==7) ac="MET";

               switch (atype) { 
		  case 10:  aPart->setTlv(  aPart->lv()+ao->truth[ac].at(ai).lv() );   break;
                  case 12:  aPart->setTlv(  aPart->lv()+ao->muos[ac].at(ai).lv() );   break;
                  case  1:  aPart->setTlv(  aPart->lv()+ao->eles[ac].at(ai).lv() );   break;
                  case 11:  aPart->setTlv(  aPart->lv()+ao->taus[ac].at(ai).lv() );   break;
                  case  2:  aPart->setTlv(  aPart->lv()+ao->jets[ac].at(ai).lv() );   break;
                  case 20:  aPart->setTlv(  aPart->lv()+ao->combos[ac].at(ai).lv() ); break;
                   case 9:  aPart->setTlv(  aPart->lv()+ao->ljets[ac].at(ai).lv() );  break;
                   case 8:  aPart->setTlv(  aPart->lv()+ao->gams[ac].at(ai).lv() );   break;
                   case 7: DEBUG("MET LV\n ");
                            ametlv.SetPxPyPzE(ao->met[ac].Px(), ao->met[ac].Py(), 0, ao->met[ac].Mod());
                            aPart->setTlv(aPart->lv()+ametlv); // v from MET using same eta approx.
                            break;
                   default: std::cout<<"SFN No such object! ERROR\n";
                            break;

               } // end of switch
           }// end of for

           DEBUG("aPart constructed \t");
        }
        if ( inputParticlesB.size()>0 ){
           bPart->Reset();
           TLorentzVector ametlv;
           DEBUG("\t input particles B \n"); 
           for(vector<myParticle*>::iterator i=inputParticlesB.begin();i!=inputParticlesB.end();i++){
               DEBUG("type:"<<(*i)->type<<" index:"<< (*i)->index<< " addr:"<<*i<<  "\t name:"<< (*i)->collection<<"\n");
              int atype=(*i)->type;
                int ai=(*i)->index;
             string ac=(*i)->collection;
             if (atype==7) ac="MET";

               switch (atype) { 
		   case 10:  bPart->setTlv(  bPart->lv()+ao->truth[ac].at(ai).lv() );   break;
                   case 12:  bPart->setTlv(  bPart->lv()+ao->muos[ac].at(ai).lv() );   break;
                   case  1:  bPart->setTlv(  bPart->lv()+ao->eles[ac].at(ai).lv() );   break;
                   case 11:  bPart->setTlv(  bPart->lv()+ao->taus[ac].at(ai).lv() );   break;
                   case  2:  bPart->setTlv(  bPart->lv()+ao->jets[ac].at(ai).lv() );   break;
                   case 20:  aPart->setTlv(  bPart->lv()+ao->combos[ac].at(ai).lv() ); break;
                   case  9:  bPart->setTlv(  bPart->lv()+ao->ljets[ac].at(ai).lv() );  break;
                   case  8:  bPart->setTlv(  bPart->lv()+ao->gams[ac].at(ai).lv() );   break;
                   case  7: DEBUG("MET LV\n ");
                            ametlv.SetPxPyPzE(ao->met[ac].Px(), ao->met[ac].Py(), 0, ao->met[ac].Mod());
                            bPart->setTlv(bPart->lv()+ametlv); // v from MET using same eta approx.
                            break;
                   default: std::cout<<"SFN No such object! ERROR\n";
                            break;

               } // end of switch
           }// end of for

           DEBUG("bPart constructed \t");
        }
        if ( inputParticlesC.size()>0 ){
           cPart->Reset();
           TLorentzVector ametlv;
           DEBUG("\t input particles C \n"); 
           for(vector<myParticle*>::iterator i=inputParticlesC.begin();i!=inputParticlesC.end();i++){
               DEBUG("type:"<<(*i)->type<<" index:"<< (*i)->index<< " addr:"<<*i<<  "\t name:"<< (*i)->collection<<"\n");
              int atype=(*i)->type;
                int ai=(*i)->index;
             string ac=(*i)->collection;
             if (atype==7) ac="MET";

               switch (atype) { 
		   case 10:  cPart->setTlv(  cPart->lv()+ao->truth[ac].at(ai).lv() );   break;
                   case 12:  cPart->setTlv(  cPart->lv()+ao->muos[ac].at(ai).lv() );   break;
                   case  1:  cPart->setTlv(  cPart->lv()+ao->eles[ac].at(ai).lv() );   break;
                   case 11:  cPart->setTlv(  cPart->lv()+ao->taus[ac].at(ai).lv() );   break;
                   case  2:  cPart->setTlv(  cPart->lv()+ao->jets[ac].at(ai).lv() );   break;
                   case 20:  cPart->setTlv(  cPart->lv()+ao->combos[ac].at(ai).lv() ); break;
                   case  9:  cPart->setTlv(  cPart->lv()+ao->ljets[ac].at(ai).lv() );  break;
                   case  8:  cPart->setTlv(  cPart->lv()+ao->gams[ac].at(ai).lv() );   break;
                   case  7: DEBUG("MET LV\n ");
                            ametlv.SetPxPyPzE(ao->met[ac].Px(), ao->met[ac].Py(), 0, ao->met[ac].Mod());
                            cPart->setTlv(cPart->lv()+ametlv); // v from MET using same eta approx.
                            break;
                   default: std::cout<<"SFN No such object! ERROR\n";
                            break;

               } // end of switch
           }// end of for

           DEBUG("cPart constructed \t");
        }

        DEBUG("*****************EXTERN TF evaluate? T/F:"<< ext <<"\n");
        if(ext) { 
               DEBUG("external user function evaluate\n");
              if (g1 != NULL) return (*g1)(ao, symbol, type, h1 );
              if (g2 != NULL) return (*g2)(ao, symbol, type, h2 );
              if (g3 != NULL) return (*g3)(ao, symbol, type, h3 );
              if (g4 != NULL) return (*g4)(ao, symbol, type, aPart->lv(), h4);
              if (g5 != NULL) return (*g5)(ao, symbol, type, aPart->lv(), bPart->lv(), cPart->lv(), h5);
        }              
        DEBUG ("Symbol:"<<symbol<<" Value:"<<value<<"\n");
        return (*f)(ao, symbol, value);
}

    virtual void Reset() override{}
    virtual void getParticles(std::vector<myParticle *>* particles) override{}
    virtual void getParticlesAt(std::vector<myParticle *>* particles, int index) override{}
    virtual ~SFuncNode() {}
};

double all(AnalysisObjects* ao, string s, float id){
    return 1;
}

double uweight(AnalysisObjects* ao, string s, float value){
	ao->evt.user_evt_weight *= value;
	return 1;
}

double lepsf(AnalysisObjects* ao, string s, float value){
	ao->evt.user_evt_weight *= ao->evt.weight_leptonSF;
	return 1;
}

double btagsf(AnalysisObjects* ao, string s, float value){
        ao->evt.user_evt_weight *= ao->evt.weight_bTagSF_77;
        return 1;
}

double count(AnalysisObjects* ao, string s, float id) {
    particleType pid = (particleType)id;

    DEBUG("STR:"<<s<<" Type:"<<pid<<" #J types:"<<ao->jets.size() << " #M types:"<<ao->muos.size()<<"\n");
    map <string, std::vector<dbxJet>  >::iterator it;
    for (it=ao->jets.begin();it!=ao->jets.end();it++){
      DEBUG("\t #Jtypename:"<<it->first<<"    size:"<<it->second.size() <<"\n");
    }

    DEBUG("\n");
    map <string,  indicesA  >::iterator itp;
    for (itp=ao->combosA.begin();itp!=ao->combosA.end();itp++){
      DEBUG("#C typename:"<<itp->first<<"    size:"<<itp->second.tableA.size() <<"\n");
    }

    ValueNode abc=ValueNode();
    switch (pid) {
//   case consti_t:   return (ao->truth.at(s).size()); break;
     case truth_t:    return (ao->truth.at(s).size()); break;
     case muon_t:     return (ao->muos.at(s).size()); break;
     case electron_t: return (ao->eles.at(s).size()); break;
     case tau_t:      return (ao->taus.at(s).size()); break;
     case jet_t:      return (ao->jets.at(s).size()); break;
     case bjet_t:     return ( (abc.tagJets(ao, 1, s) ).size()); break;
     case lightjet_t: return ( (abc.tagJets(ao, 0, s) ).size()); break;
     case fjet_t:     return (ao->ljets.at(s).size()); break;
     case photon_t:   return (ao->gams.at(s).size()); break;
     case combo_t:    if (ao->combosA.find(s)!=ao->combosA.end() ){ 
                           DEBUG(s<<" tableA max r,c:"<<ao->combosA.at(s).max_row
                                  <<" "<< ao->combosA.at(s).max_col<<"\n");
                             return (ao->combosA.at(s).max_row);
                      } else { DEBUG(s<<" Normal\n");    // to be continued     
                               return (ao->combos.at(s).size() );
                      } 
                      break;
     default:        std::cerr<<"No such Particle Type:\n"; return (-1); break;
    }
    return (-1);
}

double met(AnalysisObjects* ao, string s, float id){
     DEBUG("MET:" << ao->met["MET"].Mod() <<"\n");
    return ( ao->met["MET"].Mod() );
}

double ht(AnalysisObjects* ao, string s, float id){
    double sum_htjet=0;
    for (UInt_t i=0; i<ao->jets.at(s).size(); i++) sum_htjet+=ao->jets.at(s).at(i).lv().Pt();
    return (sum_htjet  );       
}


double userfuncA(AnalysisObjects* ao, string s, int id, std::vector<TLorentzVector> (*func)(std::vector<TLorentzVector> jets ) ){
// string contains what to send
// id contains the particle type ASSUME ID=JET TYPE,

   DEBUG("UserfunctionA, s:"<<s<< "id: "<<id<<"\n");

   std::vector<TLorentzVector> myjets;
   for (UInt_t i=0; i<ao->jets.at(s).size(); i++) myjets.push_back(ao->jets.at(s).at(i).lv() );
   DEBUG("evaluating external function on jets: :"<<s<<"\n");
   std::vector<TLorentzVector> retjets= (*func)(myjets);
   DEBUG("external function Done. size:"<<retjets.size()<<"\n");
   for (int ipart=ao->jets.at(s).size()-1; ipart>=0; ipart--){ // I have all particles, jets, in an event.
     if (ipart > (retjets.size()-1) ) { 
         (ao->jets).find(s)->second.erase( (ao->jets).find(s)->second.begin()+ipart);
     } else {
          ao->jets.at(s).at(ipart).setTlv( retjets[ipart] );
     } 
   }
    return (1);       
}
double userfuncB(AnalysisObjects* ao, string s, int id, 
         double (*func)(std::vector<TLorentzVector> jets ) ){
// string contains what to send
// id contains the particle type ASSUME ID=JET TYPE,

   DEBUG("UserfunctionB :"<<s<<"\n");

   std::vector<TLorentzVector> myjets;
   for (UInt_t i=0; i<ao->jets.at(s).size(); i++) myjets.push_back(ao->jets.at(s).at(i).lv() );
   DEBUG("evaluating external function :"<<s<<"\n");
   double retvalue= (*func)(myjets);
   return (retvalue);       
}
double userfuncC(AnalysisObjects* ao, string s, int id, 
         double (*func)(std::vector<TLorentzVector> jets, TVector2 amet ) ){
// string contains what to send
// id contains the particle type ASSUME ID=JET TYPE,

   DEBUG("UserfunctionC :"<<s<<"\n");

   std::vector<TLorentzVector> myjets;
        TVector2 mymet=ao->met["MET"];
   for (UInt_t i=0; i<ao->jets.at(s).size(); i++) myjets.push_back(ao->jets.at(s).at(i).lv() );
   DEBUG("evaluating external function :"<<s<<"\n");
   double retvalue= (*func)(myjets, mymet);
   return (retvalue);       
}

double userfuncD(AnalysisObjects* ao, string s, int id, TLorentzVector alv, 
         double (*func)(std::vector<TLorentzVector> jets, TLorentzVector amet ) ){
// string contains what to send
// id contains the particle type ASSUME ID=JET TYPE,

   DEBUG("UserfunctionD :"<<s<<"\n");

   std::vector<TLorentzVector> myjets;
   for (UInt_t i=0; i<ao->jets.at(s).size(); i++) myjets.push_back(ao->jets.at(s).at(i).lv() );
   DEBUG("evaluating external function :"<<s<<"\n");
   double retvalue= (*func)(myjets, alv);
   return (retvalue);       
}

double userfuncE(AnalysisObjects* ao, string s, int id, TLorentzVector l1, TLorentzVector l2,  TLorentzVector m1,
         double (*func)(TLorentzVector la, TLorentzVector lb, TLorentzVector amet ) ){
// string contains what to send
// id contains the particle type ASSUME ID=JET TYPE,

   DEBUG("UserfunctionE :"<<s<<"\n");
   DEBUG("evaluating external function :"<<s<<"\n");
   double retvalue= (*func)(l1, l2, m1);
   return (retvalue);
}

std::vector<TLorentzVector> fhemisphere(std::vector<TLorentzVector> myjets, int seed, int assoc) {
    // Convert
    std::vector<float> px;
    std::vector<float> py;
    std::vector<float> pz;
    std::vector<float> E;
    for (int i=0; i<myjets.size(); i++) {
      px.push_back(myjets[i].Px());
      py.push_back(myjets[i].Py());
      pz.push_back(myjets[i].Pz());
      E.push_back(myjets[i].E());
    }
    // Run the hemisphere algorithm
    Hemisphere hemis(px, py, pz, E, seed, assoc);
    // Get the vector that gives int values for group number assigned to each jet
    std::vector<int> hemisgroup = hemis.getGrouping();
    // Combine jets in each group into one object
    std::vector<TLorentzVector> myhemispheres;
    TLorentzVector h1, h2;
    for (int i=0; i<myjets.size(); i++) {
      int hg = hemisgroup[i];
      if (hg == 1) h1 += myjets[i];
      if (hg == 2) h2 += myjets[i];
    }
    myhemispheres.push_back(h1);
    myhemispheres.push_back(h2);
    return myhemispheres;

}

double fMT2(TLorentzVector lep1, TLorentzVector lep2, TLorentzVector amet){
  double retval;
  DEBUG("MT2 function wrapper\n");
  mt2_bisect::mt2 mt2_event;
// Set momenta and the mass of the invisible particle, mn:
// where array pa[0..2], pb[0..2], pmiss[0..2] contains (mass,px,py)
  double pa[3], pb[3], pmiss[3];
  pa[0]=lep1.M();  pb[0]=lep2.M();  pmiss[0]=amet.M();
  pa[1]=lep1.Px(); pb[1]=lep2.Px(); pmiss[1]=amet.Px();
  pa[2]=lep1.Py(); pb[2]=lep2.Py(); pmiss[2]=amet.Py();
  double mn=0.0;

  mt2_event.set_momenta( pa, pb, pmiss );
  mt2_event.set_mn( mn ); 
  retval=mt2_event.get_mt2();
  return (retval);
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
