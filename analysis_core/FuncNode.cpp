#include "FuncNode.h"

#define _CLV_
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
         DEBUG("type:"<<(*i)->type<<" index:"<< (*i)->index<< " addr:"<<*i<<  "\n");
         DEBUG("name:"<<(*i)->collection <<"\n"); // burada STR de print et
        }
        for(vector<myParticle*>::iterator i=input->begin();i!=input->end();i++){
                int atype=(*i)->type;
                int ai=(*i)->index;
             string ac=(*i)->collection;
                switch (atype) {  //----burada STR ile mapda find ediliyor
                                                case 0: //ao->muons_map-->find...
                                                        inputPart->setTlv(  inputPart->lv()+ao->muos[ac].at(ai).lv() ); // 0 is muon
                                                        inputPart->setCharge(inputPart->q()+ao->muos[ac].at(ai).q()  );
                                                        inputPart->setIsTight(ao->muos[ac].at(ai).isZCand()); // i am overloading the isTight
                                                        DEBUG("muon:"<<(*i)->index <<"  q:"<<ao->muos[ac].at(ai).q()<<"  ");
                                                        break;
                                                case 1: inputPart->setTlv(  inputPart->lv()+ao->eles[ac].at(ai).lv() ); // 1 is electron
                                                        inputPart->setCharge(inputPart->q()+ao->eles[ac].at(ai).q()  );
                                                        inputPart->setIsTight(ao->eles[ac].at(ai).isZCand()); // i am overloading the isTight
                                                        DEBUG("electron:"<<(*i)->index<<"  ");
                                                        break;
                                            	case 2: DEBUG("jet:"<<(*i)->index<<" ");
                                                        inputPart->setTlv(inputPart->lv()+ao->jets[ac].at(ai).lv() ); // 2 is any jet
                                                        break;
///                                             case 3: inputPart->setTlv(inputPart->lv()+tagJets(ao, 1)[ (*i)->index ].lv() ); // 3 is a b jet
///                                                     DEBUG("b-jet:"<<(*i)->index<<"  ");
///                                                     break;
///                                             case 4: inputPart->setTlv(inputPart->lv()+tagJets(ao, 0)[ (*i)->index ].lv()); // 4 is light jet
///                                                     DEBUG("qgjet:"<<(*i)->index<<" ");
///                                                     break;
/// --------------------------------------------std::map<std::string, TVector2                 > met;
                                                case 5: v_eta=ao->muos[ac].at(ai).lv().Eta();
                                                        ametlv.SetPtEtaPhiM(ao->met[ac].Mod(), v_eta,ao->met[ac].Phi(),0);
                                                        inputPart->setTlv(inputPart->lv()+ametlv); // met4v is v from MET using same eta approx.
                                                        DEBUG("muMET ");
                                                        break;
                                                case 6: v_eta=ao->eles[ac].at(ai).lv().Eta();
                                                        ametlv.SetPtEtaPhiM(ao->met[ac].Mod(), v_eta,ao->met[ac].Phi(),0);
                                                        inputPart->setTlv(inputPart->lv()+ametlv); // v from MET using same eta approx.
                                                        DEBUG("eleMET ");
                                                        break;
                                                case 7: DEBUG("MET LV\n ");
                                                        ametlv.SetPxPyPzE(ao->met[ac].Px(), ao->met[ac].Py(), 0, ao->met[ac].Mod());
                                                        inputPart->setTlv(inputPart->lv()+ametlv); // v from MET using same eta approx.
                                                        break;
                                                case 8: DEBUG("gamma:"<< (*i)->index <<" ");
                                                        inputPart->setTlv(inputPart->lv()+ao->gams[ac].at(ai).lv()); // 8 is gammas
                                                        break;

                                            default: std::cout<<"No such object! ERROR\n";
                                                        break;
                                } // end of case
        }// end of for
  
}

void FuncNode::setParticleIndex(int order, int newIndex){
                inputParticles.at(order)->index=newIndex;
}


void FuncNode::setUserObjects(Node *objectNodea, Node *objectNodeb, Node *objectNodec, Node *objectNoded){
    cout <<"Adding UOs 2 FN\n";
        userObjectA=objectNodea;
        userObjectB=objectNodeb;
        userObjectC=objectNodec;
        userObjectD=objectNoded;
}

FuncNode::FuncNode(double (*func)(dbxParticle* apart ), std::vector<myParticle*> input, std::string s, 
                         Node *objectNodea, std::string as,  Node *objectNodeb, Node *objectNodec, Node *objectNoded ){
        f=func;
        symbol=s;
        inputParticles=input; // type, index, string=ELE, crELE, ELEsr... ve/veya Node*objectNode
        myParticle apart;
        userObjectA=objectNodea;
        userObjectB=objectNodeb;
        userObjectC=objectNodec;
        userObjectD=objectNoded;

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
     cout <<"In function Node evaluate\n";
// all objects in *ao are as they were read from the file     
     if(userObjectA)  userObjectA->evaluate(ao); // returns 1, hardcoded. see ObjectNode.cpp
     if(userObjectB)  userObjectB->evaluate(ao); // returns 1, hardcoded. see ObjectNode.cpp
     if(userObjectC)  userObjectC->evaluate(ao); // returns 1, hardcoded. see ObjectNode.cpp
     if(userObjectD)  userObjectD->evaluate(ao); // returns 1, hardcoded. see ObjectNode.cpp
     if ( userObjectA || userObjectB || userObjectC || userObjectD ) cout<<"UOs EVALUATED:"<< getStr() <<"\n";
// now *ao is enhanced with new collections

//   diyelim multi layered ao yapildi... her parcacik icin STR de var.
     partConstruct(ao, &inputParticles, &myPart);
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
