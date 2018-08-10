//
//  FuncNode.h
//  mm -=-=-=-=
//
//  Created by Anna-Monica  on 8/2/18.
//  Copyright © 2018 Anna-Monica. All rights reserved.
//

#ifndef FuncNode_h
#define FuncNode_h
#include <vector>
#include "myParticle.h"
#include "Node.h"
using namespace std;

//#define _CLV_

#ifdef _CLV_
#define DEBUG(a) std::cout<<a
#else
#define DEBUG(a)
#endif

//takes care of functions with arguments
class FuncNode : public Node{
private:
        double (*f)(dbxParticle* apart);
        float v_eta;
        TLorentzVector ametlv;

protected:
    
    std::vector<myParticle> inputParticles;
    std::vector<myParticle> originalParticles;
    dbxParticle myPart;
    
public:
    FuncNode(double (*func)(dbxParticle* apart ),std::vector<myParticle> input,  std::string s ){
        f=func;
        symbol=s;
        inputParticles=input;
        originalParticles=input;
        left=NULL;
        right=NULL;
    }

    std::vector<dbxJet> tagJets(AnalysisObjects *ao, int jtype) {                   
                                std::vector<dbxJet>      rjets;
                                for (size_t jj=0; jj<ao->jets.size(); jj++) 
                                  if (ao->jets.at(jj).isbtagged_77() == jtype) {rjets.push_back(ao->jets.at(jj)); }
                                return rjets;
    }
    
virtual void setParticleIndex(int order, int newIndex){
        inputParticles.at(order).index=newIndex;
}

virtual int getParticleIndex(int order){
        return inputParticles.at(order).index;
}

virtual void Reset(){
        for(int i=0;i<originalParticles.size();i++){
                inputParticles[i]=originalParticles[i];
        }
}

virtual std::vector<myParticle>* getParticles(){
        return &inputParticles;
} 

void partConstruct(AnalysisObjects *ao, std::vector<myParticle> input, dbxParticle* inputPart){
    inputPart->Reset();
    for(vector<myParticle>::iterator i=input.begin();i!=input.end();i++){
               int atype=i->type;
               switch (atype) { 
                                            case 0: inputPart->setTlv(  inputPart->lv()+ao->muos[ i->index ].lv() ); // 0 is muon
                                                    inputPart->setCharge(inputPart->q()+ao->muos[ i->index ].q()  );
                                                    inputPart->setIsTight(ao->muos[ i->index ].isZCand()); // i am overloading the isTight
                                                    DEBUG("muon:"<<i->index <<" ");
                                                    break;
                                            case 1: inputPart->setTlv(  inputPart->lv()+ao->eles[ i->index ].lv() ); // 1 is electron
                                                    inputPart->setCharge(inputPart->q()+ao->eles[ i->index ].q()  );
                                                    inputPart->setIsTight(ao->eles[ i->index ].isZCand()); // i am overloading the isTight
                                                    DEBUG("electron:"<<i->index<<"  ");
                                                    break;
                                           case 2:  DEBUG("jet:"<<i->index<<" ");
                                                    inputPart->setTlv(inputPart->lv()   +   ao->jets[ i->index ].lv() ); // 2 is any jet
                                                    break;
                                            case 3: inputPart->setTlv(inputPart->lv()+tagJets(ao, 1)[ i->index ].lv() ); // 3 is a b jet
                                                    DEBUG("b-jet:"<<i->index<<"  ");
                                                    break;
                                            case 4: inputPart->setTlv(inputPart->lv()+tagJets(ao, 0)[ i->index ].lv()); // 4 is light jet
                                                    DEBUG("qgjet:"<<i->index<<" ");
                                                    break;
                                            case 5: v_eta=ao->muos[i->index].lv().Eta();
                                                    ametlv.SetPtEtaPhiM(ao->met.Mod(), v_eta,ao->met.Phi(),0);
                                                    inputPart->setTlv(inputPart->lv()+ametlv); // met4v is v from MET using same eta approx.
                                                    DEBUG("muMET ");
                                                    break;
                                            case 6: v_eta=ao->eles[ i->index ].lv().Eta();
                                                    ametlv.SetPtEtaPhiM(ao->met.Mod(), v_eta,ao->met.Phi(),0);
                                                    inputPart->setTlv(inputPart->lv()+ametlv); // v from MET using same eta approx.
                                                    DEBUG("eleMET ");
                                                    break;
                                            case 7: DEBUG("MET LV\n ");
                                                    ametlv.SetPxPyPzE(ao->met.Px(), ao->met.Py(), 0, ao->met.Mod());
                                                    inputPart->setTlv(inputPart->lv()+ametlv); // v from MET using same eta approx.
                                                    break;
                                            case 8: DEBUG("gamma:"<< i->index <<" ");
                                                    inputPart->setTlv(inputPart->lv()+ao->gams[ i->index ].lv()); // 8 is gammas
                                                    break;

                                           default: std::cout<<"No such object! ERROR\n";
                                                    break;
                             } // end of case
    }// end of for
  
}


virtual double evaluate(AnalysisObjects* ao) {
partConstruct(ao, inputParticles,&myPart);
return (*f)(&myPart );
}

virtual ~FuncNode() {}
};


double Qof( dbxParticle* apart){
    double charge=apart->q();
    DEBUG(" q:"<charge<<"\t");
    return charge;
}

double Mof( dbxParticle* apart){
    double mass=(apart->lv()).M();
    DEBUG(" m:"<<mass<<"\t");
    return mass;
}

double Eof( dbxParticle* apart){
    double energy=(apart->lv()).E();
    DEBUG(" E:"<<energy<<"\t");
    return energy;
}

double Pof( dbxParticle* apart){
    double p=(apart->lv()).P();
    DEBUG(" P:"<<p<<"\t");
    return p;
}

double Pzof( dbxParticle* apart){
    double pz=(apart->lv()).Pz();
    DEBUG(" Pz:"<<pz<<"\t");
    return pz;
}
double Ptof( dbxParticle* apart){
    double pt=(apart->lv()).Pt();
    DEBUG(" Pt:"<<pt<<"\t");
    return pt;
}

double AbsEtaof( dbxParticle* apart){
    double aeta=fabs((apart->lv()).Eta() );
    DEBUG(" AEta:"<<aeta<<"\t");
    return aeta;
}

double Etaof( dbxParticle* apart){
    double eta=(apart->lv()).Eta();
    DEBUG(" Eta:"<<eta<<"\t");
    return eta;
}

double Phiof( dbxParticle* apart){
    double phi=(apart->lv()).Phi();
    DEBUG(" phi:"<<phi<<"\t");
    return phi;
}


double nbfof( dbxParticle* apart){
    double phi=(apart->lv()).Phi();
    DEBUG(" CORRECT ME NBF:"<<phi<<"\t");
    return phi;
}




//other functions to be added
#endif /* FuncNode_h */
