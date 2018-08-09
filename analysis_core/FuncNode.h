//
//  FuncNode.h
//  mm
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

//takes care of functions with arguments
class FuncNode : public Node{
private:
    double (*f)(std::vector<myParticle>,AnalysisObjects* ao);
    std::vector<myParticle> inputParticles;
public:
    FuncNode(double (*func)(std::vector<myParticle>,AnalysisObjects* ao ),std::vector<myParticle> input,  std::string s ){
        f=func;
        symbol=s;
        inputParticles=input;
        left=NULL;
        right=NULL;
    }
    
    virtual double evaluate(AnalysisObjects* ao) {
        return (*f)(inputParticles,ao);
    }
    virtual ~FuncNode() {}
};

double MASS(vector<myParticle> v,AnalysisObjects* ao){
    double mass=0;
    dbxParticle myPart;
    for(vector<myParticle>::iterator i=v.begin();i!=v.end();i++){
               switch (i->type) { 
                                            case 0: myPart.setTlv(  myPart.lv()+ao->muos[ i->index ].lv() ); // 0 is muon
                                                    myPart.setCharge(myPart.q()+ao->muos[ i->index ].q()  );
                                                    myPart.setIsTight(ao->muos[ i->index ].isZCand()); // i am overloading the isTight
                                                    DEBUG("muon:"<<i->index <<" ");
                                                    break;
                                            case 1: myPart.setTlv(  myPart.lv()+ao->eles[ i->index ].lv() ); // 1 is electron
                                                    myPart.setCharge(myPart.q()+ao->eles[ i->index ].q()  );
                                                    myPart.setIsTight(ao->eles[ i->index ].isZCand()); // i am overloading the isTight
                                                    DEBUG("electron:"<<i->index<<"  ");
                                                    break;
                                           case 2:  DEBUG("jet:"<<i->index<<" ");
                                                    myPart.setTlv(myPart.lv()   +   ao->jets[ i->index ].lv() ); // 2 is any jet
                                                    break;
                                            case 3: myPart.setTlv(myPart.lv()+tagJets(ao, 1)[ i->index ].lv() ); // 3 is a b jet
                                                    DEBUG("b-jet:"<<i->index<<"  ");
                                                    break;
                                            case 4: myPart.setTlv(myPart.lv()+tagJets(ao, 0)[ i->index ].lv()); // 4 is light jet
                                                    DEBUG("qgjet:"<<i->index<<" ");
                                                    break;
                                            case 5: v_eta=ao->muos[i->index].lv().Eta();
                                                    ametlv.SetPtEtaPhiM(ao->met.Mod(), v_eta,ao->met.Phi(),0);
                                                    myPart.setTlv(myPart.lv()+ametlv); // met4v is v from MET using same eta approx.
                                                    DEBUG("muMET ");
                                                    break;
                                            case 6: v_eta=ao->eles[ i->index ].lv().Eta();
                                                    ametlv.SetPtEtaPhiM(ao->met.Mod(), v_eta,ao->met.Phi(),0);
                                                    myPart.setTlv(myPart.lv()+ametlv); // v from MET using same eta approx.
                                                    DEBUG("eleMET ");
                                                    break;
                                            case 7: DEBUG("MET LV\n ");
                                                    ametlv.SetPxPyPzE(ao->met.Px(), ao->met.Py(), 0, ao->met.Mod());
                                                    myPart.setTlv(myPart.lv()+ametlv); // v from MET using same eta approx.
                                                    break;
                                            case 8: DEBUG("gamma:"<< i->index <<" ");
                                                    myPart.setTlv(myPart.lv()+ao->gams[ i->index ].lv()); // 8 is gammas
                                                    break;

                                           default: std::cout<<"No such object! ERROR\n";
                                                    break;
                             } // end of case
    }
    m=myPart.lv().M();
    std::cout <<" m:"<<mass<<"\t";
    return mass;
}
//other functions to be added
#endif /* FuncNode_h */
