#include "FuncNode.h"

//#define _CLV_
#ifdef _CLV_
#define DEBUG(a) std::cout<<a
#else
#define DEBUG(a)
#endif

void FuncNode::ResetParticles(){
            for(int i=0;i<originalParticles.size();i++){
            DEBUG("Recall orig i:"<<originalParticles[i].index);
                    *(inputParticles[i])=originalParticles[i];
            }
}
    
void FuncNode::partConstruct(AnalysisObjects *ao, std::vector<myParticle*> *input, dbxParticle* inputPart){
        inputPart->Reset();
        
        for(vector<myParticle*>::iterator i=input->begin();i!=input->end();i++){
         DEBUG("type:"<<(*i)->type<<" index:"<< (*i)->index<< " addr:"<<*i<<   "\n");
        }
        for(vector<myParticle*>::iterator i=input->begin();i!=input->end();i++){
                int atype=(*i)->type;
                switch (atype) { 
                                                case 0: inputPart->setTlv(  inputPart->lv()+ao->muos[ (*i)->index ].lv() ); // 0 is muon
                                                        inputPart->setCharge(inputPart->q()+ao->muos[ (*i)->index ].q()  );
                                                        inputPart->setIsTight(ao->muos[ (*i)->index ].isZCand()); // i am overloading the isTight
                                                        DEBUG("muon:"<<(*i)->index <<"  q:"<<ao->muos[ (*i)->index ].q()<<"  ");
                                                        break;
                                                case 1: inputPart->setTlv(  inputPart->lv()+ao->eles[ (*i)->index ].lv() ); // 1 is electron
                                                        inputPart->setCharge(inputPart->q()+ao->eles[ (*i)->index ].q()  );
                                                        inputPart->setIsTight(ao->eles[ (*i)->index ].isZCand()); // i am overloading the isTight
                                                        DEBUG("electron:"<<(*i)->index<<"  ");
                                                        break;
                                            	case 2: DEBUG("jet:"<<(*i)->index<<" ");
                                                        inputPart->setTlv(inputPart->lv()   +   ao->jets[ (*i)->index ].lv() ); // 2 is any jet
                                                        //inputPart->setTlv( ao->jets[ (*i)->index ].lv() ); // 2 is any jet
                                                        break;
                                                case 3: inputPart->setTlv(inputPart->lv()+tagJets(ao, 1)[ (*i)->index ].lv() ); // 3 is a b jet
                                                        DEBUG("b-jet:"<<(*i)->index<<"  ");
                                                        break;
                                                case 4: inputPart->setTlv(inputPart->lv()+tagJets(ao, 0)[ (*i)->index ].lv()); // 4 is light jet
                                                        DEBUG("qgjet:"<<(*i)->index<<" ");
                                                        break;
                                                case 5: v_eta=ao->muos[(*i)->index].lv().Eta();
                                                        ametlv.SetPtEtaPhiM(ao->met.Mod(), v_eta,ao->met.Phi(),0);
                                                        inputPart->setTlv(inputPart->lv()+ametlv); // met4v is v from MET using same eta approx.
                                                        DEBUG("muMET ");
                                                        break;
                                                case 6: v_eta=ao->eles[ (*i)->index ].lv().Eta();
                                                        ametlv.SetPtEtaPhiM(ao->met.Mod(), v_eta,ao->met.Phi(),0);
                                                        inputPart->setTlv(inputPart->lv()+ametlv); // v from MET using same eta approx.
                                                        DEBUG("eleMET ");
                                                        break;
                                                case 7: DEBUG("MET LV\n ");
                                                        ametlv.SetPxPyPzE(ao->met.Px(), ao->met.Py(), 0, ao->met.Mod());
                                                        inputPart->setTlv(inputPart->lv()+ametlv); // v from MET using same eta approx.
                                                        break;
                                                case 8: DEBUG("gamma:"<< (*i)->index <<" ");
                                                        inputPart->setTlv(inputPart->lv()+ao->gams[ (*i)->index ].lv()); // 8 is gammas
                                                        break;

                                            default: std::cout<<"No such object! ERROR\n";
                                                        break;
                                } // end of case
        }// end of for
  
}

void FuncNode::setParticleIndex(int order, int newIndex){
                inputParticles.at(order)->index=newIndex;
}

//int FuncNode::getParticleIndex(int order){
//            return inputParticles.at(order)->index;
//}


    FuncNode::FuncNode(double (*func)(dbxParticle* apart ),std::vector<myParticle*> input,  std::string s ){
        f=func;
        symbol=s;
        inputParticles=input;
        myParticle apart;
      for (int i=0; i<input.size(); i++){
       DEBUG("orig i:"<<input[i]->index);
       apart.index=input[i]->index;
       apart.type=input[i]->type;
       originalParticles.push_back(apart);
      }
        left=NULL;
        right=NULL;
}
    
void FuncNode::Reset() {
        this->ResetParticles();
}

void FuncNode::getParticles(std::vector<myParticle *>* particles) {
        int size=particles->size();
        for (int i=0; i<inputParticles.size(); i++){
            
            bool found=false;
            for(int j=0;j<size;j++){
                if (inputParticles[i]->index==particles->at(j)->index)
                {
                    found=true;break;
                }
            }

            if(!found){
                particles->push_back(inputParticles[i]);
            }

            }    
}

void FuncNode::getParticlesAt(std::vector<myParticle *>* particles, int index){
        particles->push_back(inputParticles[index]);
}

double FuncNode::evaluate(AnalysisObjects* ao) {
     partConstruct(ao, &inputParticles,&myPart);
     DEBUG(" constructed \t");
     return (*f)(&myPart );
}

FuncNode::~FuncNode() {}



double Qof( dbxParticle* apart){
    double charge=apart->q();
    DEBUG(" q:"<<charge<<"\t");
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