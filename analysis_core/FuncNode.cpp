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
         DEBUG("type:"<<(*i)->type<<" index:"<< (*i)->index<< " addr:"<<*i<<  "\t name:"<< (*i)->collection<<"\n");
         if (((*i)->collection).size() < 1 && (*i)->type!=7 ) cerr << "Object name SHOULD NOT be empty. type:"<<(*i)->type<<" idx:"<<(*i)->index <<"\n"; 
        }
        int ka;
        for(vector<myParticle*>::iterator i=input->begin();i!=input->end();i++){
                int atype=(*i)->type;
                int ai=(*i)->index;
             string ac=(*i)->collection;
             if (atype==7) ac="MET";

                switch (atype) {  //----burada STR ile mapda find ediliyor
		                                           case 10: DEBUG("truth:"<< (*i)->index <<" ");
		                                                    inputPart->setTlv(  inputPart->lv()+ao->truth[ac].at(ai).lv()); 
		                                                    inputPart->setCharge(inputPart->q()+ao->truth[ac].at(ai).q()  );
		                                                    inputPart->setPdgID(ao->truth[ac].at(ai).pdgID()  );
		                                                    break;
                                                case 0: //ao->muons_map-->find...
                                                        inputPart->setTlv(  inputPart->lv()+ao->muos[ac].at(ai).lv() ); // 0 is muon
                                                        inputPart->setCharge(inputPart->q()+ao->muos[ac].at(ai).q()  );
							                                          inputPart->setPdgID(ao->muos[ac].at(ai).pdgID()  );
                                                        inputPart->setIsTight(ao->muos[ac].at(ai).isZCand()); // i am overloading the isTight
                                                        ka=ao->muos[ac].at(ai).nAttribute();
                                                        for (int anat=0; anat<ka; anat++) inputPart->addAttribute(ao->muos[ac].at(ai).Attribute(anat) );
                                                        DEBUG("muon:"<<(*i)->index <<"  q:"<<ao->muos[ac].at(ai).q()<<"  ");
                                                        break;
                                                case 1: inputPart->setTlv(  inputPart->lv()+ao->eles[ac].at(ai).lv() ); // 1 is electron
                                                        inputPart->setCharge(inputPart->q()+ao->eles[ac].at(ai).q()  );
							                                          inputPart->setPdgID(ao->eles[ac].at(ai).pdgID()  );
                                                        inputPart->setIsTight(ao->eles[ac].at(ai).isZCand()); // i am overloading the isTight
                                                        ka=ao->eles[ac].at(ai).nAttribute();
                                                        for (int anat=0; anat<ka; anat++) inputPart->addAttribute(ao->eles[ac].at(ai).Attribute(anat) );
                                                        DEBUG("electron:"<<(*i)->index<<"  ");
                                                        break;
                                               case 11: inputPart->setTlv(  inputPart->lv()+ao->taus[ac].at(ai).lv() ); // 11 is tau
                                                        inputPart->setCharge(inputPart->q()+ao->taus[ac].at(ai).q()  );
							inputPart->setPdgID(ao->taus[ac].at(ai).pdgID()  );
                           //                             inputPart->setIsTight(ao->eles[ac].at(ai).isZCand()); // i am overloading the isTight
                                                        ka=ao->taus[ac].at(ai).nAttribute();
                                                        for (int anat=0; anat<ka; anat++) inputPart->addAttribute(ao->taus[ac].at(ai).Attribute(anat) );
                                                        DEBUG("TAU:"<<ai<<"  ");
                                                        break;
                                            	case 2: DEBUG("jet:"<<ai<<" ");
                                                        inputPart->setTlv(inputPart->lv()+ao->jets[ac].at(ai).lv() ); // 2 is any jet
                                                        inputPart->setFlavor( ao->jets[ac].at(ai).Flavor()   );
                                                        ka=ao->jets[ac].at(ai).nAttribute();
                                                        for (int anat=0; anat<ka; anat++) inputPart->addAttribute(ao->jets[ac].at(ai).Attribute(anat) );
                                                        break;
                                                case 3: inputPart->setTlv(inputPart->lv()+tagJets(ao, 1, ac)[ ai ].lv() ); // 3 is a b jet
                                                        DEBUG("b-jet:"<<ai<<"  ");
                                                        break;
                                                case 4: inputPart->setTlv(inputPart->lv()+tagJets(ao, 0, ac)[ ai ].lv()); // 4 is light jet
                                                        DEBUG("qgjet:"<<ai<<" ");
                                                        break;
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
                                                case 9: DEBUG("FatJet:"<< (*i)->index <<" ");
                                                        inputPart->setTlv(inputPart->lv()+ao->ljets[ac].at(ai).lv()); // 9 is gammas
                                                        inputPart->setFlavor( ao->ljets[ac].at(ai).Flavor()   );
                                                        ka=ao->ljets[ac].at(ai).nAttribute();
                                                        for (int anat=0; anat<ka; anat++) inputPart->addAttribute(ao->ljets[ac].at(ai).Attribute(anat) );
                                                        break;
                                               case 20: DEBUG("combo:"<< (*i)->index <<" ");
                                                        inputPart->setTlv(  inputPart->lv()+ao->combos[ac].at(ai).lv()); // 20 is combos
                                                        inputPart->setCharge(inputPart->q()+ao->combos[ac].at(ai).q()  );
                                                        break;

                                            default: std::cout<<" FN No such object! ERROR\n";
                                                        break;
                                } // end of case
        }// end of for
	
}

void FuncNode::setParticleIndex(int order, int newIndex){
                inputParticles.at(order)->index=newIndex;
}


void FuncNode::setUserObjects(Node *objectNodea, Node *objectNodeb, Node *objectNodec, Node *objectNoded){
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
       DEBUG(" Received:"<<input.size() <<" particles for "<<s<<"\n");

      for (int i=0; i<input.size(); i++){
       DEBUG(" orig i:"<<input[i]->index);
       apart.index=input[i]->index;
       apart.type=input[i]->type;
       apart.collection=input[i]->collection;
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
        DEBUG("function particleAt giver, size: "<< inputParticles.size()<<" idx:"<<index<<"\n");
        particles->push_back(inputParticles[index]);
}

double FuncNode::evaluate(AnalysisObjects* ao) {
     DEBUG("\nIn function Node evaluate\n");
// all objects in *ao are as they were read from the file   // returns 1, hardcoded. see ObjectNode.cpp  
     if(userObjectA) { userObjectA->evaluate(ao); 
                       int thistype=((ObjectNode*)userObjectA)->type;
                       string realname=((ObjectNode*)userObjectA)->name;
                       DEBUG("A t,n:"<<thistype<<" , "<< realname <<"\n");
                       for (int ipa=0; ipa<inputParticles.size(); ipa++){
                        if (inputParticles[ipa]->type == thistype) inputParticles[ipa]->collection=realname;
                       }
                     } // replace collection if needed
     if(userObjectB) { userObjectB->evaluate(ao);
                       int thistype=((ObjectNode*)userObjectB)->type;
                       string realname=((ObjectNode*)userObjectB)->name;
                       DEBUG("B t,n:"<<thistype<<" , "<< realname <<"\n");
                       for (int ipa=0; ipa<inputParticles.size(); ipa++){
                        if (inputParticles[ipa]->type == thistype) inputParticles[ipa]->collection=realname;
                       }
                     } 
     if(userObjectC)  userObjectC->evaluate(ao); 
     if(userObjectD)  userObjectD->evaluate(ao); 
     if ( userObjectA || userObjectB || userObjectC || userObjectD ) DEBUG("UOs EVALUATED:"<< getStr() <<"\n");

     partConstruct(ao, &inputParticles, &myPart);
     DEBUG("Particle constructed \t");
     return (*f)(&myPart );
     DEBUG("\n");
}

FuncNode::~FuncNode() {}

double Qof( dbxParticle* apart){
    double charge=apart->q();
    DEBUG(" q:"<<charge<<"\t");
    return charge;
}

double pdgIDof( dbxParticle* apart){
   double pdgID = apart->pdgID();
   DEBUG(" pdgIDof:"<<pdgID<<"\t");
   return pdgID;
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
//NGU
double MsoftDof( dbxParticle* apart){
    double MsoftD=apart->Attribute(0) ;
    DEBUG(" MsoftD:"<<MsoftD<<"\t");
    return MsoftD;
}
double DeepBof( dbxParticle* apart){
    double DeepB=apart->Flavor();
    DEBUG(" DeepB:"<<DeepB<<"\t");
    return DeepB;
}

double isBTag( dbxParticle* apart){
    bool Bval=((dbxJet*)apart)->isbtagged_77();
    DEBUG(" BTAG:"<<Bval<<"\t");
    return Bval;
}

double tau1of( dbxParticle* apart){
    double tau1=apart->Attribute(1) ;
    DEBUG(" tau1:"<<tau1<<"\t");
    return tau1;
}
double tau2of( dbxParticle* apart){
    double tau2=apart->Attribute(2) ;
    DEBUG(" tau2:"<<tau2<<"\t");
    return tau2;
}
double tau3of( dbxParticle* apart){
    double tau3=apart->Attribute(3) ;
    DEBUG(" tau3:"<<tau3<<"\t");
    return tau3;
}
//----------for electron and muons
double dzof( dbxParticle* apart){
    double dz=apart->Attribute(0) ;
    DEBUG(" dz:"<<dz<<"\t");
    return dz;
}

double dxyof( dbxParticle* apart){
    double dxy=apart->Attribute(1);
    DEBUG(" dxy:"<<dxy<<"\t");
    return dxy;
}
double relisoof( dbxParticle* apart){
   double v=apart->Attribute(2);
   DEBUG(" relisoof:"<<v<<"\t");
   return v;
}
double softIdof( dbxParticle* apart){
   double v=apart->Attribute(3);
   DEBUG(" softidof:"<<v<<"\t");
   return v;
}

//---------tau only........
double tauisoof( dbxParticle* apart){
   double v=apart->Attribute(0);
   DEBUG(" Tau iso of:"<<v<<"\t");
   return v;
}


double nbfof( dbxParticle* apart){
    double phi=(apart->lv()).Phi();
    DEBUG(" CORRECT ME NBF:"<<phi<<"\t");
    cout <<"--This is wrong--\n";
    return phi;
}
