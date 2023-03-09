#include "FuncNode.h"

//#define _CLV_
#ifdef _CLV_
#define DEBUG(a) std::cout<<a
#else
#define DEBUG(a)
#endif

extern TTreeReader *ttreader;

void FuncNode::ResetParticles(){
      for(int i=0;i<originalParticles.size();i++){
/*
        cout <<"O Collection:"<<originalParticles[i].collection<<" type:"<< originalParticles[i].type<<" index:"<<originalParticles[i].index<<"\n";
        cout <<"R Collection:"<<inputParticles[i]->collection<<" type:"<< inputParticles[i]->type<<" index:"<<inputParticles[i]->index<<"\n";
*/
        DEBUG("Recall orig i:"<<originalParticles[i].index);
        *(inputParticles[i])=originalParticles[i];
      }
}
 
//map <string, double > attribute_map;
   
void FuncNode::partConstruct(AnalysisObjects *ao, std::vector<myParticle*> *input, dbxParticle* inputPart){
        inputPart->Reset();
        DEBUG("\n");
        for(vector<myParticle*>::iterator i=input->begin();i!=input->end();i++){
         DEBUG("CONSTRUCT type:"<<(*i)->type<<" index:"<< (*i)->index<< " addr:"<<*i<<  "\t name:"<< (*i)->collection<<"\n");
         if (((*i)->collection).size() < 1 && abs((*i)->type)!=7 ) cerr << "Object name SHOULD NOT be empty. type:"<<(*i)->type
                            << " size:"<< ((*i)->collection).size()<< " idx:"<<(*i)->index <<"\n"; 
        }
        int ka;
        DEBUG("inputPart q:"<<inputPart->q()<<" pdgID:"<<inputPart->pdgID()<<"\n");
        for(vector<myParticle*>::iterator i=input->begin();i!=input->end();i++){
                int atype=abs((*i)->type);
          short int sgn=atype/(*i)->type;
                int ai=(*i)->index;
             string ac=(*i)->collection;
             if (ai >= 10000) continue; // skip the loop particles
             if (atype==7) ac="MET";
                DEBUG("adding:"<<ac<<" idx:"<<ai<<" type:"<<atype<<"\n");
                switch (atype) {  //----burada STR ile mapda find ediliyor
		                           case track_t: DEBUG("track:"<< (*i)->index <<" ");
		                                         inputPart->setTlv(  inputPart->lv()+sgn*ao->track[ac].at(ai).lv()); 
		                                         inputPart->setCharge(inputPart->q()+ao->track[ac].at(ai).q()  );
		                                         inputPart->setPdgID(ao->track[ac].at(ai).pdgID()  );
		                                         inputPart->setPtCone(ao->track[ac].at(ai).PtCone()  );
		                                         inputPart->setParticleIndx(inputPart->ParticleIndx() + ao->track[ac].at(ai).ParticleIndx()  );
                                                         ka=ao->track[ac].at(ai).nAttribute();
                                                         DEBUG("Trk Nattr:"<<ka<<"\n");
                                                         for (int anat=0; anat<ka; anat++) {
                                                          cout << "TRKAttr:"<<anat<< " :"<<ao->track[ac].at(ai).Attribute(anat)<<"\n";
                                                            inputPart->addAttribute(ao->track[ac].at(ai).Attribute(anat) );
                                                         }
//                                                          cout <<"----------------done----------------------\n";
		                                         break;
		                           case truth_t: DEBUG("truth:"<< (*i)->index <<" ");

		                                         inputPart->setTlv(  inputPart->lv()+sgn*ao->truth[ac].at(ai).lv()); 
		                                         inputPart->setCharge(inputPart->q()+ao->truth[ac].at(ai).q()  );
		                                         inputPart->setPdgID(inputPart->pdgID() + ao->truth[ac].at(ai).pdgID()  );
		                                         inputPart->setParticleIndx(ao->truth[ac].at(ai).ParticleIndx()  );
                                                         ka=ao->truth[ac].at(ai).nAttribute();
                                                         DEBUG("Gen Nattr:"<<ka<<"\n");
                                                         for (int anat=0; anat<ka; anat++) {
                   //                                         cout << "GenAttr:"<<anat<< " :"<<ao->truth[ac].at(ai).Attribute(anat)<<"\n";
                                                            inputPart->addAttribute(ao->truth[ac].at(ai).Attribute(anat) );
                                                         }
                                                        if (special_function) {
                                             			int nix=ao->truth[ac].at(ai).ParticleIndx();
								double avalue=ttrdr->readvalue(nix);
                                          			DEBUG(ac<<"read and pushed new attrib:"<< avalue << "\n");
      								inputPart->addAttribute(avalue);
                                                        }
		                                        break;
                                           case muon_t: //ao->muons_map-->find...
                                                        inputPart->setTlv(  inputPart->lv()+sgn*ao->muos[ac].at(ai).lv() ); 
                                                        inputPart->setCharge(inputPart->q()+ao->muos[ac].at(ai).q()  );
  							inputPart->setPdgID(inputPart->pdgID() + ao->muos[ac].at(ai).pdgID()  );
//							inputPart->setPdgID(ao->muos[ac].at(ai).pdgID()  );
							inputPart->setParticleIndx(inputPart->ParticleIndx() + ao->muos[ac].at(ai).ParticleIndx()  );
                                                        inputPart->setIsTight (ao->muos[ac].at(ai).isTight() ); 
                                                        inputPart->setIsMedium(ao->muos[ac].at(ai).isMedium() ); 
                                                        inputPart->setIsLoose (ao->muos[ac].at(ai).isLoose() ); 
                                                        ka=ao->muos[ac].at(ai).nAttribute();
                                                        for (int anat=0; anat<ka; anat++) inputPart->addAttribute(ao->muos[ac].at(ai).Attribute(anat) );
                                                        inputPart->addAttribute(ao->muos[ac].at(ai).isZCand() );
                                                        if (special_function) {
                                             			int nix=ao->muos[ac].at(ai).ParticleIndx();
								double avalue=ttrdr->readvalue(nix);
                                          			DEBUG(ac<<"read and pushed new attrib:"<< avalue << "\n");
      								inputPart->addAttribute(avalue);
                                                        }
                                                        DEBUG("muon:"<<(*i)->index <<"  q:"<<ao->muos[ac].at(ai).q()<<"  Pt:" <<ao->muos[ac].at(ai).lv().Pt()<<"  ");
                                                        break;
                                       case electron_t: inputPart->setTlv(  inputPart->lv()+sgn*ao->eles[ac].at(ai).lv() ); 
                                                        inputPart->setCharge(inputPart->q()+ao->eles[ac].at(ai).q()  );
							inputPart->setPdgID(inputPart->pdgID() + ao->eles[ac].at(ai).pdgID()  );
							inputPart->setParticleIndx(ao->eles[ac].at(ai).ParticleIndx()  );
                                                        inputPart->setIsTight (ao->eles[ac].at(ai).isTight() ); 
                                                        inputPart->setIsMedium(ao->eles[ac].at(ai).isMedium() ); 
                                                        inputPart->setIsLoose (ao->eles[ac].at(ai).isLoose() ); 
                                                        ka=ao->eles[ac].at(ai).nAttribute();
                                                        DEBUG("e- Nattr:"<<ka<<"\n");
                                                        for (int anat=0; anat<ka; anat++) inputPart->addAttribute(ao->eles[ac].at(ai).Attribute(anat) );
                                                        inputPart->addAttribute(ao->eles[ac].at(ai).isZCand() );
                                                        if (special_function) {
                                             			int nix=ao->eles[ac].at(ai).ParticleIndx();
								double avalue=ttrdr->readvalue(nix);
                                          			DEBUG(ac<<"read and pushed new attrib:"<< avalue << "\n");
      								inputPart->addAttribute(avalue);
                                                        }
                                                        DEBUG("electron:"<<(*i)->index<<"  ");
                                                        break;
                                            case tau_t: inputPart->setTlv(  inputPart->lv()+sgn*ao->taus[ac].at(ai).lv() ); 
                                                        inputPart->setCharge(inputPart->q()+ao->taus[ac].at(ai).q()  );
							inputPart->setPdgID(inputPart->pdgID() + ao->taus[ac].at(ai).pdgID()  );
							inputPart->setParticleIndx(ao->taus[ac].at(ai).ParticleIndx()  );
                                                        inputPart->setIsTight (ao->taus[ac].at(ai).isTight() ); 
                                                        inputPart->setIsMedium(ao->taus[ac].at(ai).isMedium() ); 
                                                        inputPart->setIsLoose (ao->taus[ac].at(ai).isLoose() ); 
                                                        ka=ao->taus[ac].at(ai).nAttribute();
                                                        for (int anat=0; anat<ka; anat++) inputPart->addAttribute(ao->taus[ac].at(ai).Attribute(anat) );
                                                        if (special_function) {
                                             			int nix=ao->taus[ac].at(ai).ParticleIndx();
								double avalue=ttrdr->readvalue(nix);
                                          			DEBUG(ac<<"read and pushed new attrib:"<< avalue << "\n");
      								inputPart->addAttribute(avalue);
                                                        }
                                                        DEBUG("TAU:"<<ai<<"  ");
                                                        break;
                                      case muonlikeV_t: v_eta=ao->muos[ac].at(ai).lv().Eta();
                                                        ametlv.SetPtEtaPhiM(ao->met[ac].Mod(), v_eta,ao->met[ac].Phi(),0);
                                                        inputPart->setTlv(inputPart->lv()+sgn*ametlv); // met4v is v from MET using same eta approx.
                                                        DEBUG("muMET ");
                                                        break;
                                  case electronlikeV_t: v_eta=ao->eles[ac].at(ai).lv().Eta();
                                                        ametlv.SetPtEtaPhiM(ao->met[ac].Mod(), v_eta,ao->met[ac].Phi(),0);
                                                        inputPart->setTlv(inputPart->lv()+sgn*ametlv); // v from MET using same eta approx.
                                                        DEBUG("eleMET ");
                                                        break;
                                          case pureV_t: DEBUG("MET LV\n ");
                                                        ametlv.SetPxPyPzE(ao->met[ac].Px(), ao->met[ac].Py(), 0, ao->met[ac].Mod());
                                                        inputPart->setTlv(inputPart->lv()+sgn*ametlv); 
                                                        break;
                                         case photon_t: DEBUG("gamma:"<< (*i)->index <<" ");
                                                        inputPart->setTlv(inputPart->lv()+sgn*ao->gams[ac].at(ai).lv()); 
							inputPart->setParticleIndx(ao->gams[ac].at(ai).ParticleIndx()  );
                                                        ka=ao->gams[ac].at(ai).nAttribute();
                                                        inputPart->setIsTight (ao->gams[ac].at(ai).isTight() ); 
                                                        inputPart->setIsMedium(ao->gams[ac].at(ai).isMedium() ); 
                                                        inputPart->setIsLoose (ao->gams[ac].at(ai).isLoose() ); 
                                                        for (int anat=0; anat<ka; anat++) inputPart->addAttribute(ao->gams[ac].at(ai).Attribute(anat) );
                                                        break;
                                            case jet_t: DEBUG("jet:"<<ai<<" \t");
                                                        inputPart->setTlv(inputPart->lv()+sgn*ao->jets[ac].at(ai).lv() ); // any jet
                                                        inputPart->setFlavor(inputPart->Flavor() +ao->jets[ac].at(ai).Flavor()   );
                                                        inputPart->setCharge(inputPart->q()+ao->jets[ac].at(ai).q()  );
                                                        inputPart->setIsTight (ao->jets[ac].at(ai).isTight() // previous value 
                                                                     | (ao->jets[ac].at(ai).isbtagged_77() + 2*ao->jets[ac].at(ai).isTautagged() // bitwise or
                                                            ) ); 
                                                        inputPart->setIsMedium(ao->jets[ac].at(ai).isMedium() ); 
                                                        inputPart->setIsLoose (ao->jets[ac].at(ai).isLoose() ); 
							inputPart->setParticleIndx(ao->jets[ac].at(ai).ParticleIndx()  );
                                                        ka=ao->jets[ac].at(ai).nAttribute();
                                                        for (int anat=0; anat<ka; anat++) inputPart->addAttribute(ao->jets[ac].at(ai).Attribute(anat) );
                                                        if (special_function) {
                                             			int nix=ao->jets[ac].at(ai).ParticleIndx();
								double avalue=ttrdr->readvalue(nix);
                                          			DEBUG(ac<<"read and pushed new attrib:"<< avalue << "\n");
      								inputPart->addAttribute(avalue);
                                                        }
                                                        break;

                                           case fjet_t: DEBUG("FatJet:"<< ai<<" \n");
                                                        inputPart->setTlv(inputPart->lv()+sgn*ao->ljets[ac].at(ai).lv());
                                                        inputPart->setFlavor(inputPart->Flavor() +ao->ljets[ac].at(ai).Flavor()   );
							inputPart->setParticleIndx(ao->ljets[ac].at(ai).ParticleIndx()  );
                                                        inputPart->setIsTight( inputPart->isTight() // add to the existing one
                                                                 + ao->ljets[ac].at(ai).isbtagged_77() +100* ao->ljets[ac].at(ai).isTautagged() );
                                                        ka=ao->ljets[ac].at(ai).nAttribute();
                                                        for (int anat=0; anat<ka; anat++) inputPart->addAttribute(ao->ljets[ac].at(ai).Attribute(anat) );
                                                        break; 
                                         
					   case bjet_t: inputPart->setTlv(inputPart->lv()+sgn*tagJets(ao, 1, ac)[ ai ].lv() ); // b jet
                                                        inputPart->setIsTight( tagJets(ao,1, ac)[ai].isbtagged_77()   );
                                                        if (special_function) {
                                             			int nix=ao->ljets[ac].at(ai).ParticleIndx();
								double avalue=ttrdr->readvalue(nix);
                                          			DEBUG(ac<<"read and pushed new attrib:"<< avalue << "\n");
      								inputPart->addAttribute(avalue);
                                                        }
                                                        DEBUG("b-jet:"<<ai<<"  ");
                                                        break;
                                       case lightjet_t: inputPart->setTlv(inputPart->lv()+sgn*tagJets(ao, 0, ac)[ ai ].lv()); 
                                                        inputPart->setIsTight( tagJets(ao,0, ac)[ai].isbtagged_77()   );
//							inputPart->setParticleIndx(inputPart->ParticleIndx() + ao->ljets[ac].at(ai).ParticleIndx()  );
                                                        DEBUG("qgjet:"<<ai<<" ");
                                                        break;
                                          case combo_t: DEBUG("combo:"<< (*i)->index <<" ");
                                                        inputPart->setTlv(  inputPart->lv()+sgn*ao->combos[ac].at(ai).lv()); 
                                                        inputPart->setCharge(inputPart->q()+ao->combos[ac].at(ai).q()  );
                                                        DEBUG("initial pdgID:"<< inputPart->pdgID() <<" add pdgID:"<<ao->combos[ac].at(ai).pdgID()<<"\n");
							inputPart->setPdgID(inputPart->pdgID()+ao->combos[ac].at(ai).pdgID()  );
                                                        break;

                                         case consti_t: DEBUG("consti:"<< (*i)->index <<" ");
                                                        inputPart->setTlv(  inputPart->lv()+sgn*ao->constits[ac].at(ai).lv()); 
                                                        inputPart->setCharge(inputPart->q()+ao->constits[ac].at(ai).q()  );
                                                        DEBUG("initial pdgID:"<< inputPart->pdgID() <<" add pdgID:"<<ao->constits[ac].at(ai).pdgID()<<"\n");
							inputPart->setPdgID(inputPart->pdgID()+ao->constits[ac].at(ai).pdgID()  );
                                                        break;

                                            default: std::cout<<"FN. No such object of type "<<atype<<" collection:"<<ac<<" idx:"<<ai<<" ERROR!\n";
                                                        exit(1);
                                                        break;
                                } // end of case
        }// end of for
	
}

void FuncNode::setParticleIndex(int order, int newIndex){
                inputParticles.at(order)->index=newIndex;
}
void FuncNode::setParticleType(int order, int newType){
                inputParticles.at(order)->type=newType;
}
void FuncNode::setParticleCollection(int order, string newName){
                inputParticles.at(order)->collection=newName;
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
        inputParticles=input; // type, index, string=ELE, crELE, ELEsr... and/or Node*objectNode
        myParticle apart;
        userObjectA=objectNodea;
        userObjectB=objectNodeb;
        userObjectC=objectNodec;
        userObjectD=objectNoded;
       DEBUG(" Received:"<<input.size() <<" particles for "<<s<<"\n");

        if (s.find('"') != std::string::npos) {
         s.erase(std::remove( s.begin(), s.end(), '\"' ),s.end());
         cout << "** sf:"<< s<<"\t"; //this is special function
         special_function=true;
         TTree *at = ttreader->GetTree();
         TBranch *ab= at->GetBranch(s.c_str() );
         std::string bc_name=ab->GetClassName();
         cout << " type:"<<bc_name<<"\n";
         if (  bc_name.find("vector<float>") != std::string::npos ) {
             ttrdrF = new myTTreaderF( ttreader, s);
             ttrdr=ttrdrF;
         } else if (bc_name.find("vector<double>") != std::string::npos ) {
             ttrdrD = new myTTreaderD( ttreader, s);
             ttrdr=ttrdrD;
         } else if (bc_name.find("vector<int>") != std::string::npos ) {
             ttrdrI= new myTTreaderI ( ttreader, s);
             ttrdr=ttrdrI;
         } else if (bc_name.find("vector<bool>") != std::string::npos ) {
             ttrdrB= new myTTreaderB ( ttreader, s);
             ttrdr=ttrdrB;
         } else {
            cerr << s << " of type "<< bc_name << " can not be handled by this version of CL !!!!!!!\n";
            special_function=false;
         }
//double avalue=ttrdr->readvalue(index);

        } else special_function=false;

      for (int i=0; i<input.size(); i++){
//     cout <<" Collection:"<<inputParticles[i]->collection<<" type:"<< inputParticles[i]->type<<" index:"<<inputParticles[i]->index<<"\n";
       DEBUG(" orig i:"<<input[i]->index);
       apart.index=input[i]->index;
       apart.type=input[i]->type;
       apart.collection=input[i]->collection;
       originalParticles.push_back(apart);
 //      cout <<"O Collection:"<<originalParticles[i].collection<<" type:"<< originalParticles[i].type<<" index:"<<originalParticles[i].index<<"\n";
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
            DEBUG("FN getP i:"<<i<<" idx:"<<inputParticles[i]->index <<"\n");
            bool found=false;
            for(int j=0;j<size;j++){
                if (inputParticles[i]->index==particles->at(j)->index && inputParticles[i]->collection==particles->at(j)->collection)  // AHA BU !!!!!!!!!!!!!!
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
        DEBUG("FunctionNode particleAt giver, size: "<< inputParticles.size()<<" idx:"<<index<<"\n");
        particles->push_back(inputParticles[index]);
}

double FuncNode::evaluate(AnalysisObjects* ao) {
     DEBUG("\nIn function Node evaluate, #particles:"<< inputParticles.size() <<"\n");
// all objects in *ao are as they were read from the file   // returns 1, hardcoded. see ObjectNode.cpp  
     if(userObjectA) { double retval=userObjectA->evaluate(ao); 
                       DEBUG("UOA RetVal:"<< retval  <<"\n");
                       int thistype=((ObjectNode*)userObjectA)->type;
                       string realname=((ObjectNode*)userObjectA)->name;
                       DEBUG("A t,n:"<<thistype<<" , "<< realname <<"\n");
                       for (int ipa=0; ipa<inputParticles.size(); ipa++){
                        DEBUG("T:"<<inputParticles[ipa]->type<<" idx:"<<inputParticles[ipa]->index<<"\n");
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

     DEBUG("P_0 Type:"<<inputParticles[0]->type<<" collection:"
                      << inputParticles[0]->collection << " index:"<<inputParticles[0]->index<<"\n");


     bool failed=false;
     for (int kk=0; kk<inputParticles.size(); kk++){
      if (inputParticles[kk]->index < 0) failed=true;
     }
     if (failed) return 98765432.1;

     if (inputParticles[0]->index == 6213) {
      string base_collection2=inputParticles[0]->collection;
      int base_type2=inputParticles[0]->type;
      int ipart2_max=-1;
     try {
                switch(abs(inputParticles[0]->type) ){ 
                   case 12: ipart2_max=(ao->muos).at(base_collection2).size(); break;
                   case 10: ipart2_max=(ao->truth).at(base_collection2).size(); break;
                    case 1: ipart2_max=(ao->eles).at(base_collection2).size(); break;
                    case 2: ipart2_max=(ao->jets).at(base_collection2).size(); break;
                    case 7: ipart2_max=1; break;
                    case 8: ipart2_max=(ao->gams).at(base_collection2).size(); break;
                    case 9: ipart2_max=(ao->ljets).at(base_collection2).size(); break;
                   case 11: ipart2_max=(ao->taus).at(base_collection2).size(); break;
                   case 20: ipart2_max=(ao->combos)[base_collection2].size(); break;

                   default:
                       std::cerr << "WRONG PARTICLE TYPE:"<<inputParticles[0]->type << std::endl; break;
                }
     } catch(...) {
//                    is it an object we can create?
//                    userObjectA->evaluate(ao); // returns 1, hardcoded. see ObjectNode.cpp
                            std::cerr << "YOU WANT A PARTICLE TYPE YOU DIDN'T CREATE:"<<base_collection2 <<" !\n";
                            _Exit(-1);
     }
        // now we know how many we want
        DEBUG ("loop over "<< ipart2_max<<" particles\t");
        std::vector<myParticle*>  inputParticles1;
        std::vector<myParticle>  inputParticles0;
        for (int ip2=0; ip2 < ipart2_max; ip2++){
            myParticle * aparticle = new myParticle;
                         aparticle->type= base_type2;
                         aparticle->collection= base_collection2;
                         aparticle->index=ip2;
                         DEBUG( "index="<<ip2<<" ");
              inputParticles0.push_back(*aparticle);
              delete aparticle;
        }
        DEBUG("\n");
        double total=0;
        for (int ji=0; ji<inputParticles0.size(); ji++){
         inputParticles1.push_back( &inputParticles0[ji]);
         partConstruct(ao, &inputParticles1,&myPart);
         DEBUG("a particle constructed \t");
         double retval=(*f)(&myPart );
         DEBUG("yielded:" <<  retval<<"\n");    
         total+=retval;
         inputParticles1.clear();
        }
        inputParticles0.clear();
        DEBUG("FuncNode Sum:"<<total<<"\n");
        return total;
     } else {
//
      
//------------simply execute
      partConstruct(ao, &inputParticles, &myPart);
     }
     DEBUG("Particle constructed \t");
     return (*f)(&myPart );
     DEBUG(" .\n");
}

FuncNode::~FuncNode() {}

double Qof( dbxParticle* apart){
    double charge=apart->q();
    DEBUG(" q:"<<charge<<"\t");
    return charge;
}

double flavorof( dbxParticle* apart){
    double flavor=apart->Flavor();
    DEBUG(" flavor:"<<flavor<<"\t");
    return flavor;
}

double pdgIDof( dbxParticle* apart){
   double pdgID = apart->pdgID();
   DEBUG(" pdgIDof:"<<pdgID<<"\t");
   return pdgID;
}

double IDXof( dbxParticle* apart){
   double IDX = apart->ParticleIndx();
   DEBUG(" IDXof:"<<IDX<<"\t");
   return IDX;
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

double Rapof( dbxParticle* apart){
    double rap=(apart->lv()).Rapidity();
    DEBUG(" Rap:"<<rap<<"\t");
    return rap;
}

double Phiof( dbxParticle* apart){
    double phi=(apart->lv()).Phi();
    DEBUG(" phi:"<<phi<<"\t");
    return phi;
}

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
double PtConeof( dbxParticle* apart){
    double ptc=apart->PtCone();
    DEBUG(" PTC:"<<ptc<<"\t");
    return ptc;
}
double EtConeof( dbxParticle* apart){
    double etc=apart->EtCone();
    DEBUG(" ETC:"<<etc<<"\t");
    return etc;
}

double isBTag( dbxParticle* apart){
    bool Bval=((apart)->isTight())&1; //
    DEBUG(" BTAG:"<<Bval<<"\t");
    return Bval;
}
double isTauTag( dbxParticle* apart){
    bool Tval=((apart)->isTight())&2; //
    DEBUG(" TauTAG:"<<Tval<<"\t");
    return Tval;
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
    double dz=999;
    int ka=apart->nAttribute();
    if (ka>0) dz=apart->Attribute(0) ;
    DEBUG(" dz:"<<dz<<"\t");
    return dz;
}
double edzof( dbxParticle* apart){
    double dz=999;
    int ka=apart->nAttribute();
    if (ka>0) dz=apart->Attribute(4) ;
    DEBUG(" edz:"<<dz<<"\t");
    return dz;
}
double edxyof( dbxParticle* apart){
    double dxy=999;
    int ka=apart->nAttribute();
    if (ka>1) dxy=apart->Attribute(3) ;
    DEBUG(" edxy:"<<dxy<<"\t");
    return dxy;
}
double dxyof( dbxParticle* apart){
    double dxy=999;
    int ka=apart->nAttribute();
    if (ka>1) dxy=apart->Attribute(1) ;
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
double vzof( dbxParticle* apart){ 
   double v=apart->Attribute(4);
   DEBUG(" vert z of:"<<v<<"\t");
   return v;
}
double vyof( dbxParticle* apart){ 
   double v=apart->Attribute(5);
   DEBUG(" vert y of:"<<v<<"\t");
   return v;
}
double vxof( dbxParticle* apart){ 
   double v=apart->Attribute(6);
   DEBUG(" vert x of:"<<v<<"\t");
   return v;
}
double vtof( dbxParticle* apart){ 
   double v=apart->Attribute(7);
   DEBUG(" vert t of:"<<v<<"\t");
   return v;
}
double vtrof( dbxParticle* apart){ 
   double vx=apart->Attribute(6);
   double vy=apart->Attribute(5);
   double v=sqrt(vx*vx+vy*vy);
   DEBUG(" vert tr of:"<<v<<"\t");
   return v;
}
double tauisoof( dbxParticle* apart){
   double v=apart->Attribute(0); // tau attri0
   DEBUG(" Tau iso of:"<<v<<"\t");
   return v;
}
double CCountof( dbxParticle* apart){
   double v=apart->Attribute(9) - apart->Attribute(8)+1;
   DEBUG("# Children :"<<v<<"\n");
   return v;
}
//---------for tau's added by SS
double iddecaymodeof( dbxParticle* apart){
   double v=apart->Attribute(1);
   DEBUG(" iddecaymode:"<<v<<"\t");
   return v;
}
double idisotightof( dbxParticle* apart){
   double v=apart->Attribute(2);
   DEBUG(" idisotight:"<<v<<"\t");
   return v;
}
double idantieletightof( dbxParticle* apart){
   double v=apart->Attribute(3);
   DEBUG(" idantieletight:"<<v<<"\t");
   return v;
}
double idantimutightof( dbxParticle* apart){
   double v=apart->Attribute(4);
   DEBUG(" idantimutight:"<<v<<"\t");
   return v;
}
double tightidof( dbxParticle* apart){
   double v=apart->Attribute(4);
   DEBUG(" tightID for mus:"<<v<<"\t");
   return v;
}
double puidof( dbxParticle* apart){
   double v=apart->Attribute(0);
   DEBUG(" PU ID for jets:"<<v<<"\t");
   return v;
}
double genpartidxof( dbxParticle* apart){
   double v=apart->Attribute(5);
   DEBUG(" genPartIdx:"<<v<<"\t");
   return v;
}
double relisoallof( dbxParticle* apart){
   double v=apart->Attribute(6);
   DEBUG(" tau reliso_all:"<<v<<"\t");
   return v;
}

double sieieof( dbxParticle* apart){
   double v=apart->Attribute(0);
   DEBUG(" Photon sieie:"<<v<<"\t");
   return v;
}

double sub1btagof( dbxParticle* apart){
   double v=apart->Attribute(4);
   DEBUG(" fatjet sub1btagof:"<<v<<"\t");
   return v;
}

double sub2btagof( dbxParticle* apart){
   double v=apart->Attribute(5);
   DEBUG(" fatjet sub2btagof:"<<v<<"\t");
   return v;
}

double decaymodeof( dbxParticle* apart){
   double v=apart->Attribute(7);
   DEBUG(" tau decay mode:"<<v<<"\t");
   return v;
}
double pfreliso03allof( dbxParticle* apart){
   double v=apart->Attribute(6);
   DEBUG(" muon pfRelIso03_all:"<<v<<"\t");
   return v;
}

double mvatightof(dbxParticle* apart){
    return 1*(int)apart->Attribute(0);
}
double mvalooseof(dbxParticle* apart){
    return 1*(int)apart->Attribute(1);
}

double isTight(dbxParticle* apart){
    return 1*(int)(apart->isTight()&1);
}
double isMedium(dbxParticle* apart){
    return 1*(int)apart->isMedium();
}
double isLoose(dbxParticle* apart){
    return 1*(int)apart->isLoose();
}

double isZcandid(dbxParticle* apart){
    return apart->Attribute( apart->nAttribute() -1);
}

double IsoVarof( dbxParticle* apart){
 return apart->Attribute(3);
}

double MiniIsoVarof( dbxParticle* apart){
 return apart->Attribute(3); // TO BE REVIEWED
}

double specialf( dbxParticle* apart){
// cout << "we got:"<< apart->Attribute(apart->nAttribute() -1)<<"\n";
 return apart->Attribute(apart->nAttribute() -1);
}

//------------------------------
double nbfof( dbxParticle* apart){
    int nbf=(apart->isTight() % 100 ); // modulo 100 to remove possible tau tags
    DEBUG("NBJ:"<<nbf<<"\n");
    return nbf;
}
//------------TRK
double truthIDof( dbxParticle* apart){
 return apart->Attribute(0);
}
double truthParentIDof( dbxParticle* apart){
 return apart->Attribute(1);
}
double averageMuof( dbxParticle* apart){
 return apart->Attribute(2);
}
double truthMatchProbof( dbxParticle* apart){
 return apart->Attribute(3);
}

