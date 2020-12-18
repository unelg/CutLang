//
//  ObjectNode.cpp
//  mm
//
//  Created by Anna-Monica  on 8/16/18.
//  Copyright © 2018 Anna-Monica. All rights reserved.
//
#include "ObjectNode.hpp"
#include "ValueNode.h"
#include <set>

#include "Comb.h"
#include "Denombrement.h"

//#define _CLV_
#ifdef _CLV_
#define DEBUG(a) std::cout<<a
#else
#define DEBUG(a)
#endif


ObjectNode::ObjectNode(std::string id,
                       Node* previous,
                       void (* func) (AnalysisObjects* ao, vector<Node*>* criteria, std::vector<myParticle *>* particles, std::string  name, std::string basename),
                       vector<Node*> criteria,
                       std::string s) {

    symbol=s; // e.g. "obj Ele"
    name=id;//this is useless because symbol already has name of the particle, e.g. "ELE"

    if(func==NULL) {
        createNewSet=((ObjectNode*)previous)->createNewSet;
    } else {
        createNewSet=func;
    }
    for(int i=0;i<criteria.size();i++){
        this->criteria.push_back(criteria[i]);
    }

    left=previous;
    right=NULL;

    ObjectNode* anode=(ObjectNode*)previous; 
    if (anode != NULL){
    while (anode->left != NULL) { anode=(ObjectNode*)anode->left; }
      if (anode->name == "MUO" ) type=muon_t;
      if (anode->name == "ELE" ) type=electron_t;
      if (anode->name == "JET" ) type=jet_t;
      if (anode->name == "PHO" ) type=photon_t;
      if (anode->name == "FJET") type=fjet_t;
      if (anode->name == "Truth") type=truth_t;
      if (anode->name == "TAU" ) type=tau_t;
      if (anode->name == "Combo" ) type=combo_t;
      DEBUG(" I found:" << anode->name<<" t:"<<type<<"\n");
    } else { // if null
      if (id == "MUO" ) type=muon_t;
      if (id == "ELE" ) type=electron_t;
      if (id == "JET" ) type=jet_t;
      if (id == "PHO" ) type=photon_t;
      if (id == "FJET") type=fjet_t;
      if (id == "Truth") type=truth_t;
      if (id == "TAU" ) type=tau_t;
      if (id == "Combo" ) type=combo_t;
      DEBUG(" I have:"<<id<<" t:"<<type<<"\n");
    }
}

ObjectNode::~ObjectNode(){}

void ObjectNode::Reset(){
    if(left!=NULL) {
        left->Reset();
    }
    for(auto it=criteria.begin();it!=criteria.end();it++){
        (*it)->Reset();
    }
}

void ObjectNode::getParticles(std::vector<myParticle *>* particles){
    cout<<"Calling get particles on ObjectNode-----doing nothing\n";
}

void ObjectNode::getParticlesAt(std::vector<myParticle *>* particles, int index){
  cout<<"Calling get particlesAT on ObjectNode-----doing nothing\n";
}

double ObjectNode::evaluate(AnalysisObjects* ao){
    //test if the AO thing not null=> then avoid function call
    DEBUG(" working for:"<<name << "  type:"<<type<<"\n");
    this->Reset(); ///////NGU
    std::string basename="xxx";
    bool keepworking=true;

    DEBUG("inital sets #types: J, FJ:"<< ao->jets.size()<<","<<ao->ljets.size()<<" E,M,T:"<< ao->eles.size()<<","<<ao->muos.size()<<","<<ao->taus.size() <<" P:"<<ao->gams.size() <<"\n"); 
    DEBUG("# iparticles:"<< particles.size()<<"\n");
    if (particles.size() >0) DEBUG("type:"<< particles[0]->type<<"\t index:"<<particles[0]->index <<"name:"<<particles[0]->collection<<"\n" );

    if (type == 0) {cerr <<"type 0 unknown\n"; exit(1);}
    while(left!=NULL && keepworking) {
      ObjectNode* anode=(ObjectNode*)left;
      basename=anode->name;
      DEBUG("previous:"<< basename<< "  type:"<<type<<"\n"); // Combo, 20
// is it in the map list?
       switch (type) {
        case muon_t:  if (ao->muos.find(basename)==ao->muos.end()  ){
               			anode->evaluate(ao);
                                DEBUG(" Muos evaluated.\n");
                      } else keepworking=false;
                      break;

	case truth_t: if (ao->truth.find(basename) == ao->truth.end() ){
				anode->evaluate(ao);
				DEBUG(" Truth evaluated.\n");
		      } else keepworking=false;
		      break;

       case electron_t:       if (ao->eles.find(basename)==ao->eles.end()  ){
               			anode->evaluate(ao);
                                DEBUG(" Eles evaluated.\n");
                      } else keepworking=false;
                      break;
       case tau_t:       if (ao->taus.find(basename)==ao->taus.end()  ){
               			anode->evaluate(ao);
                                DEBUG(" Taus evaluated.\n");
                      } else keepworking=false;
                      break;

        case jet_t:       if (ao->jets.find(basename)==ao->jets.end()  ){
               			anode->evaluate(ao);
                                DEBUG(" Jets evaluated.\n");
               	      } else keepworking=false;
                      break;
        case photon_t:       if (ao->gams.find(basename)==ao->gams.end()  ){
               			anode->evaluate(ao);
                                DEBUG(" *****Phos evaluated.\n");
               	      } else keepworking=false;
                      break;
        case fjet_t:       if (ao->ljets.find(basename)==ao->ljets.end()  ){
               			anode->evaluate(ao);
                                DEBUG(" *****FJETs evaluated.\n");
               	      } else keepworking=false;
                      break;
       case combo_t:       if (ao->combos.find(basename)==ao->combos.end()  ){
               			anode->evaluate(ao);
                                DEBUG(" *****COMBOs evaluated.\n");
               	      } else keepworking=false;
                      break;

        default:  break;
       }
       anode=(ObjectNode*)anode->left;
       DEBUG("~~~~~~~~~~~~~~MOVED LEFT\n");
      }
    DEBUG("#particles:"<< particles.size()<<"\n");
    map <string, std::vector<dbxJet>  >::iterator itj;
    for (itj=ao->jets.begin();itj!=ao->jets.end();itj++){
     if (itj->first == name) return 1;
    }
    map <string, std::vector<dbxElectron>  >::iterator ite;
    for (ite=ao->eles.begin();ite!=ao->eles.end();ite++){
     if (ite->first == name) return 1;
    }
    map <string, std::vector<dbxTruth> >::iterator ittr;
    for (ittr=ao->truth.begin();ittr!=ao->truth.end();ittr++){
     if (ittr->first == name) return 1;
    }
    map <string, std::vector<dbxMuon>  >::iterator itm;
    for (itm=ao->muos.begin();itm!=ao->muos.end();itm++){
     if (itm->first == name) return 1;
    }
    map <string, std::vector<dbxTau>  >::iterator itt;
    for (itt=ao->taus.begin();itt!=ao->taus.end();itt++){
     if (itt->first == name) return 1;
    }
    map <string, std::vector<dbxPhoton>  >::iterator itp;
    for (itp=ao->gams.begin();itp!=ao->gams.end();itp++){
     if (itp->first == name) return 1;
    }
    map <string, std::vector<dbxJet>  >::iterator itfj;
    for (itfj=ao->ljets.begin();itfj!=ao->ljets.end();itfj++){
     if (itfj->first == name) return 1;
    }
    map <string, std::vector<dbxParticle>  >::iterator itc;
    for (itc=ao->combos.begin();itc!=ao->combos.end();itc++){
     if (itc->first == name) return 1;
    }
    DEBUG("$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");  
    DEBUG("Before new set #types: J, FJ, E, M, T, P, Combo, Consti:"<< ao->jets.size()<<","<<ao->ljets.size()<<","<< ao->eles.size()<<","<<ao->muos.size()<<","<<ao->taus.size() <<","<<ao->gams.size()<<","<<ao->combos.size()<<","<<ao->constits.size() <<"\n"); 
//---------------
    (*createNewSet)(ao,&criteria,&particles, name, basename);//modify analysis object based on criteria here
//---------------
    DEBUG(" After new set #types: J, FJ, E, M, T, P, Combo, Consti:"<< ao->jets.size()<<","<<ao->ljets.size()<<","<< ao->eles.size()<<","<<ao->muos.size()<<","<<ao->taus.size() <<","<<ao->gams.size()<<","<<ao->combos.size()<<","<< ao->constits.size() <<"\n"); 
    DEBUG("$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");  

    for (itj=ao->jets.begin();itj!=ao->jets.end();itj++){
      DEBUG("\t #Jet typename:"<<itj->first<<"    size:"<<itj->second.size() <<"\n");
    }
    for (itp=ao->gams.begin();itp!=ao->gams.end();itp++){
      DEBUG("\t #Pho typename:"<<itp->first<<"    size:"<<itp->second.size() <<"\n");
    }
    for (itc=ao->combos.begin();itc!=ao->combos.end();itc++){
      DEBUG("\t #Com typename:"<<itc->first<<"    size:"<<itc->second.size() <<"\n");
    }
    //Save AO somewhere to return in next time
    return 1;
}
// ***********************************

void createNewJet(AnalysisObjects* ao,vector<Node*> *criteria,std::vector<myParticle *>* particles, std::string name, std::string basename){
    DEBUG("Creating new JETtype named:"<<name<<" #Jtypes:"<<ao->jets.size()<< " Duplicating:"<<basename<<"\n");
    ao->jets.insert( std::pair<string, vector<dbxJet> >(name, (ao->jets)[basename]) );
    DEBUG("Before all constituents "<< ao->constits.size() << "\n");
    for (int ipart=(ao->jets)[name].size()-1; ipart>=0; ipart--){ //Loop over all jets in the event.
       TString consname=name;        TString baseconsname=basename;
               consname+="_";                baseconsname+="_";
               consname+=ipart;              baseconsname+=ipart;
               consname+="c";                baseconsname+="c";
         ao->constits.insert( std::pair<string, vector<dbxParticle> >(consname.Data(), (ao->constits)[(string)baseconsname]) );
         DEBUG(consname<<" added.\t");
    }
    DEBUG("\n ALL Constits now:"<<ao->constits.size() <<"\n");

    for(auto cutIterator=criteria->begin();cutIterator!=criteria->end();cutIterator++){
        particles->clear();
        (*cutIterator)->getParticlesAt(particles,0);
        int ipart_max = (ao->jets)[name].size();
        bool simpleloop=true;
        bool constiloop=false;
 
        DEBUG("Nb of particles in this cut:"<<particles->size() <<"\n");
        if ( particles->size()==0) {
           DEBUG("No particle CutIte:"<<(*cutIterator)->getStr()<<"\n");
           bool ppassed=(*cutIterator)->evaluate(ao);
           continue;
        }
//---------this needs to be tested at PARSING TIME!!!!!!!!!! NGU TODO
        std::set<int> ptypeset; // set of types, same type twice doesn't exist.
        int t1=particles->at(0)->type;
        int t2;
        for ( int kp=0; kp<particles->size(); kp++ ) {
         ptypeset.insert( particles->at(kp)->type);
         if (particles->at(kp)->type == consti_t) constiloop=true;
        }
//--------------------- if we have a LoopNode(max, min, sum) no constiloop.
        TString mycutstr=(*cutIterator)->getStr();
        if ( mycutstr.Contains("sum") || mycutstr.Contains("max") || mycutstr.Contains("min")) constiloop=false;
        if ( ptypeset.size()>2 ) {cerr <<" 3 particle selection is not allowed in this version!\n"; exit(1);}
        if ( ptypeset.size()==2) {simpleloop=false;}
        std::set<int>::iterator ptit; 
        ptit=ptypeset.begin(); ptit++;
        t2=*ptit;
/*
object goodjets take Jet
  select  q(Jet constituents ) != 0                        # remove neutral constituents
  select pT(decayVert(Jet constituents) ) < minPVdistance  # remove far PrimaryVertex'ed constituents
  select Sum(pT(Jet constituents ) )    < maxjetchargedpT  # PT from remaining constituents
# example "goodJet_0c"
*/
//--------------------
        if (constiloop) { // basename: previous base object, name: new object
          for (int ipart=ipart_max-1; ipart>=0; ipart--){ // loop over all particles, jets, in an event.
            TString konsname=name;
                    konsname+="_";
                    konsname+=ipart;
                    konsname+="c";
             string consname=(string)konsname;
             int constiCount =(ao->constits).find(consname)->second.size();
             DEBUG("for "<<consname<<" constituents size:"<<constiCount<<"\n");
             for (int ic=constiCount-1; ic>=0; ic--){
//---------------these are the particles to be dealt with, like a loop!
              for (int jp=0; jp<particles->size(); jp++){//the particles in the cut, e.g. pT(JET_jp) > 10
                particles->at(jp)->index=ic;
                particles->at(jp)->collection=consname; // new name
                particles->at(jp)->type=consti_t;
              }
              DEBUG("For consti:"<<ic<<" CutIte:"<<(*cutIterator)->getStr()<<"\n"); // this is like qOf, applied on each constituent
              bool ppassed=(*cutIterator)->evaluate(ao); // check on constituents?
              DEBUG("Result:"<<ppassed<<"\n");
              if (!ppassed) { 
                            DEBUG("consti "<< ic <<" failed and will be removed.\n");
                            (ao->constits).find(consname)->second.erase( (ao->constits).find(consname)->second.begin()+ic); // erase consti
                            }
             }//end of loop over constituent
           if ( (ao->constits).find(consname)->second.size() < 1) {
               DEBUG(ipart<<"th jet removed from "<<name<<" since all constituents were removed.\n");
               (ao->jets).find(name)->second.erase( (ao->jets).find(name)->second.begin()+ipart); // erase jets without constituents
           }
          }// end of loop over all particles (jets) in the event.
         continue; // will move to the next cut iterator
        } // done with constis
//------------------------------just to see
/*
        for ( int ipa = (ao->jets)[name].size()-1; ipa>=0; ipa--){
            DEBUG(name <<" "<<ipa<<" has ");
            TString konsname=name;
                    konsname+="_";
                    konsname+=ipa;
                    konsname+="c";
             string consname=(string)konsname;
             int ciCount =(ao->constits).find(consname)->second.size();
            DEBUG(ciCount<<" constituents\n"); 
        }
*/

        if(simpleloop){
            for (int ipart=ipart_max-1; ipart>=0; ipart--){ // I have all particles, jets, in an event.
               for (int jp=0; jp<particles->size(); jp++){//the particles in the cut
                particles->at(jp)->index=ipart;
                particles->at(jp)->collection=name;
               }
               DEBUG("CutIte:"<<(*cutIterator)->getStr()<<"\t");
               bool ppassed=(*cutIterator)->evaluate(ao);
               DEBUG(ppassed<<"\n");
               if (!ppassed) (ao->jets).find(name)->second.erase( (ao->jets).find(name)->second.begin()+ipart);
            }
        } else { // if not a simple loop
            ValueNode abc=ValueNode();
            for (int ipart=ipart_max-1; ipart>=0; ipart--){
                particles->at(0)->index=ipart;  // 6213
                particles->at(0)->collection=name;             
                int ipart2_max=-1;
                string base_collection2=particles->at(1)->collection;
                try {
                switch(particles->at(1)->type){
                    case muon_t: ipart2_max=(ao->muos).at(base_collection2).size(); break;
	           case truth_t: ipart2_max=(ao->truth).at(base_collection2).size(); break;
                case electron_t: ipart2_max=(ao->eles).at(base_collection2).size(); break;
                     case jet_t: ipart2_max=(ao->jets).at(base_collection2).size(); break;
//                    case 3: ipart2_max=abc.tagJets(ao, 1).size(); //b-jets
//                        break;
//                    case 4: ipart2_max=abc.tagJets(ao, 1).size(); //light jets
//                        break;
                   case pureV_t: ipart2_max=1; break;
                  case photon_t: ipart2_max=(ao->gams).at(base_collection2).size(); break;
                    case fjet_t: ipart2_max=(ao->ljets).at(base_collection2).size(); break;
                     case tau_t: ipart2_max=(ao->taus).at(base_collection2).size(); break;
                   case combo_t: ipart2_max=(ao->combos)[base_collection2].size(); break;

                    default:
                        std::cerr << "WRONG PARTICLE JET TYPE:"<<particles->at(1)->type << std::endl;
                        break;
                }
                } catch(...) {
                            std::cerr << "YOU WANT A PARTICLE TYPE YOU DIDN'T CREATE:"<<base_collection2 <<" !\n"; 
                            _Exit(-1);
                }
                for (int kpart=ipart2_max-1; kpart>=0; kpart--){ 
                    particles->at(1)->index=kpart;             
                    particles->at(1)->collection=base_collection2;      
                    for (int jp=2; jp<particles->size(); jp++){
                     if (particles->at(jp)->type == t1) particles->at(jp)->index=ipart;
                     if (particles->at(jp)->type == t2) particles->at(jp)->index=kpart;
                    }

                    bool ppassed=(*cutIterator)->evaluate(ao);
                    if (!ppassed) {
                        (ao->jets).find(name)->second.erase( (ao->jets).find(name)->second.begin()+ipart);
                        break; // we can quit at first mismatch.
                    }
                } // end of loop over 2nd particle type
            } // loop over 1st particle type
        }
    } // end of cutIterator loop
   DEBUG("created\n");
}

void createNewEle(AnalysisObjects* ao, vector<Node*> *criteria, std::vector<myParticle *> * particles, std::string name, std::string basename) {
    DEBUG("Creating new ELEtype named:"<<name<<" #Etypes:"<<ao->eles.size()<< " Duplicating:"<<basename<<"\n");
    ao->eles.insert( std::pair<string, vector<dbxElectron> >(name, (ao->eles)[basename]) );
    for(auto cutIterator=criteria->begin();cutIterator!=criteria->end();cutIterator++) {
        particles->clear();
        (*cutIterator)->getParticlesAt(particles,0);
        int ipart_max = (ao->eles)[name].size();
        bool simpleloop=true;
 
        DEBUG("Psize:"<<particles->size() <<"\n");
        if ( particles->size()==0) {
           DEBUG("CutIte:"<<(*cutIterator)->getStr()<<"\n");
           bool ppassed=(*cutIterator)->evaluate(ao);
           continue;
        }
//---------this needs to be tested at PARSING TIME!!!!!!!!!! NGU TODO
        std::set<int> ptypeset;
        int t1=particles->at(0)->type;
        int t2;
        for ( int kp=0; kp<particles->size(); kp++ ) {
         ptypeset.insert( particles->at(kp)->type);
        }
        if ( ptypeset.size()>2 ) {cerr <<" 3 particle selection is not allowed in this version!\n"; exit(1);}
        if ( ptypeset.size()==2) {simpleloop=false; }
        std::set<int>::iterator ptit;
        ptit=ptypeset.begin(); ptit++;
        t2=*ptit;
 
        if(simpleloop){
            for (int ipart=ipart_max-1; ipart>=0; ipart--){
               for (int jp=0; jp<particles->size(); jp++){
                particles->at(jp)->index=ipart;
                particles->at(jp)->collection=name;
               }
                bool ppassed=(*cutIterator)->evaluate(ao);
                if (!ppassed) (ao->eles).find(name)->second.erase( (ao->eles).find(name)->second.begin()+ipart);
            }
        }
        else {
//################################# I have >=2 particles which should have the same index
            ValueNode abc=ValueNode();
            for (int ipart=ipart_max-1; ipart>=0; ipart--){ // loop over ALL electrons of the base class
                particles->at(0)->index=ipart;  // 6213
                particles->at(0)->collection=name;
                int ipart2_max;
                string base_collection2=particles->at(1)->collection;
                switch(particles->at(1)->type){
                    case muon_t: ipart2_max=(ao->muos)[base_collection2].size(); break;
	           case truth_t: ipart2_max=(ao->truth)[base_collection2].size(); break;
                case electron_t: ipart2_max=(ao->eles)[base_collection2].size(); break;
                     case jet_t: ipart2_max=(ao->jets)[base_collection2].size(); break;
//                  case 3: ipart2_max=abc.tagJets(ao, 1).size(); //b-jets
//                      break;
//                  case 4: ipart2_max=abc.tagJets(ao, 1).size(); //light jets
//                      break;
                 case photon_t: ipart2_max=(ao->gams)[base_collection2].size(); break;
                   case fjet_t: ipart2_max=(ao->ljets)[base_collection2].size(); break;
                    case tau_t: ipart2_max=(ao->taus)[base_collection2].size(); break;
                  case combo_t: ipart2_max=(ao->combos)[base_collection2].size(); break;

                    default:
                        std::cerr << "WRONG PARTICLE TYPE! Try ELE:"<<particles->at(1)->type << std::endl;
                        break;
                }
                for (int kpart=ipart2_max-1; kpart>=0; kpart--){
                    particles->at(1)->index=kpart;
                    particles->at(1)->collection=base_collection2;
                    for (int jp=2; jp<particles->size(); jp++){
                     if (particles->at(jp)->type == t1) particles->at(jp)->index=ipart;
                     if (particles->at(jp)->type == t2) particles->at(jp)->index=kpart;
                    }
                    bool ppassed=(*cutIterator)->evaluate(ao);
                    if (!ppassed) {
                        (ao->eles).find(name)->second.erase( (ao->eles).find(name)->second.begin()+ipart);
                        break;
                    }
                }
            }
        }
    }
}

void createNewMuo(AnalysisObjects* ao, vector<Node*> *criteria, std::vector<myParticle *> * particles, std::string name, std::string basename) {
    DEBUG("Creating new MUOtype named:"<<name<<" #MUOtypes:"<<ao->muos.size()<< " Duplicating:"<<basename<<"\t");
    ao->muos.insert( std::pair<string, vector<dbxMuon> >(name, (ao->muos)[basename]) );
    DEBUG(" #MUOtypes:"<<ao->muos.size()<< " Duplicated.\n");

    for(auto cutIterator=criteria->begin();cutIterator!=criteria->end();cutIterator++) {
        particles->clear();
        (*cutIterator)->getParticlesAt(particles,0);
        int ipart_max = (ao->muos)[name].size();
        bool simpleloop=true;
 
        DEBUG("Psize:"<<particles->size() <<"\t"<<" ipart_max:"<<ipart_max<<"\n");
        if ( particles->size()==0) {
           DEBUG("CutIte:"<<(*cutIterator)->getStr()<<"\n");
           bool kill_all=false;
           TString mycutstr=(*cutIterator)->getStr();
           if ( mycutstr.Contains("kill") ) kill_all=true;

           int retval=(*cutIterator)->evaluate(ao);
           DEBUG("RetVal:"<<retval<<"\n");
           if (kill_all) {
            for (int ipart=ipart_max-1; ipart>=0; ipart--){
               if (retval != ipart) { DEBUG("Killing muon:"<<ipart);
                   (ao->muos).find(name)->second.erase( (ao->muos).find(name)->second.begin()+ipart);
               }
            }
           }
           DEBUG("M---------------------------------\n");
           continue;
        }
        std::set<int> ptypeset;
        int t1=particles->at(0)->type;
        int t2;
        for ( int kp=0; kp<particles->size(); kp++ ) {
         ptypeset.insert( particles->at(kp)->type);
        }
        if ( ptypeset.size()>2 ) {cerr <<" 3 particle selection is not allowed in this version!\n"; exit(1);}
        if ( ptypeset.size()==2) {simpleloop=false; }
        std::set<int>::iterator ptit;
        ptit=ptypeset.begin(); ptit++;
        t2=*ptit; 

        if(simpleloop){
            DEBUG("ONE particle  Muon Loop \n");
            for (int ipart=ipart_max-1; ipart>=0; ipart--){
               for (int jp=0; jp<particles->size(); jp++){
                particles->at(jp)->index=ipart;
                particles->at(jp)->collection=name;
               }
               bool ppassed=(*cutIterator)->evaluate(ao);
               if (!ppassed) { DEBUG("Killing muon:"<<ipart);
                   (ao->muos).find(name)->second.erase( (ao->muos).find(name)->second.begin()+ipart);
               }
            }
        }
        else {
            DEBUG("TWO particle Muon Loop\n");
            ValueNode abc=ValueNode();
            for (int ipart=ipart_max-1; ipart>=0; ipart--){
                particles->at(0)->index=ipart;  // 6213
                int ipart2_max;
                string base_collection2=particles->at(1)->collection;
                switch(particles->at(1)->type){
                    case 12: ipart2_max=(ao->muos)[base_collection2].size(); break;
		    case 10: ipart2_max=(ao->truth)[base_collection2].size(); break;
                    case 1: ipart2_max=(ao->eles)[base_collection2].size(); break;
                    case 2: ipart2_max=(ao->jets)[base_collection2].size(); break;
//                  case 3: ipart2_max=abc.tagJets(ao, 1).size(); //b-jets
//                      break;
//                  case 4: ipart2_max=abc.tagJets(ao, 1).size(); //light jets
//                      break;
                    case 8: ipart2_max=(ao->gams)[base_collection2].size(); break;
                    case 9: ipart2_max=(ao->ljets)[base_collection2].size(); break;
                   case 11: ipart2_max=(ao->taus)[base_collection2].size(); break;
                   case 20: ipart2_max=(ao->combos)[base_collection2].size(); break;

                    default:
                        std::cerr << "WRONG PARTICLE TYPE! Try MUO:"<<particles->at(1)->type << std::endl;
                        break;
                }
                for (int kpart=ipart2_max-1; kpart>=0; kpart--){
                    particles->at(1)->index=kpart;

                    for (int jp=2; jp<particles->size(); jp++){
                     if (particles->at(jp)->type == t1) particles->at(jp)->index=ipart;
                     if (particles->at(jp)->type == t2) particles->at(jp)->index=kpart;
                    }

                    bool ppassed=(*cutIterator)->evaluate(ao);
                    if (!ppassed) {
                        (ao->muos).find(name)->second.erase( (ao->muos).find(name)->second.begin()+ipart);
                        break;
                    }
                } // second particle set
            }// first particle set
        }// end of two particles
    }// end of cutIterator
}
void createNewPho(AnalysisObjects* ao, vector<Node*> *criteria, std::vector<myParticle *> * particles, std::string name, std::string basename) {
    DEBUG("Creating new PHOtype named:"<<name<<" #Ptypes:"<<ao->gams.size()<< " Duplicating:"<<basename<<"\t");
    ao->gams.insert( std::pair<string, vector<dbxPhoton> >(name, (ao->gams)[basename]) );
    DEBUG(" #Ptypes:"<<ao->gams.size()<< " Duplicated.\n");

    for(auto cutIterator=criteria->begin();cutIterator!=criteria->end();cutIterator++) {
        particles->clear();
        (*cutIterator)->getParticlesAt(particles,0);
        int ipart_max = (ao->gams)[name].size();
        bool simpleloop=true;
 
        DEBUG("Psize:"<<particles->size() <<"\n");
        if ( particles->size()==0) {
           DEBUG("CutIte:"<<(*cutIterator)->getStr()<<"\n");
           bool ppassed=(*cutIterator)->evaluate(ao);
           continue;
        }
        std::set<int> ptypeset;
        int t1=particles->at(0)->type;
        int t2;
        for ( int kp=0; kp<particles->size(); kp++ ) {
         ptypeset.insert( particles->at(kp)->type);
        }
        if ( ptypeset.size()>2 ) {cerr <<" 3 particle selection is not allowed in this version!\n"; exit(1);}
        if ( ptypeset.size()==2) {simpleloop=false; }
        std::set<int>::iterator ptit;
        ptit=ptypeset.begin(); ptit++;
        t2=*ptit;
       
        if(simpleloop){
            DEBUG("size=1\n");
            for (int ipart=ipart_max-1; ipart>=0; ipart--){
               for (int jp=0; jp<particles->size(); jp++){
                particles->at(jp)->index=ipart;
                particles->at(jp)->collection=name;
               }
               bool ppassed=(*cutIterator)->evaluate(ao);
               if (!ppassed) (ao->gams).find(name)->second.erase( (ao->gams).find(name)->second.begin()+ipart);
            }
        }
        else {
            DEBUG("size=2\n");
            ValueNode abc=ValueNode();
            for (int ipart=ipart_max-1; ipart>=0; ipart--){
                particles->at(0)->index=ipart;  // 6213
                int ipart2_max;
                string base_collection2=particles->at(1)->collection;
                switch(particles->at(1)->type){
                    case 12: ipart2_max=(ao->muos)[base_collection2].size(); break;
		    case 10: ipart2_max=(ao->truth)[base_collection2].size(); break;
                    case 1: ipart2_max=(ao->eles)[base_collection2].size(); break;
                    case 2: ipart2_max=(ao->jets)[base_collection2].size(); break;
//                  case 3: ipart2_max=abc.tagJets(ao, 1).size(); //b-jets
//                      break;
//                  case 4: ipart2_max=abc.tagJets(ao, 1).size(); //light jets
//                      break;
                    case 8: ipart2_max=(ao->gams)[base_collection2].size(); break;
                    case 9: ipart2_max=(ao->ljets)[base_collection2].size(); break;
                   case 11: ipart2_max=(ao->taus)[base_collection2].size(); break;
                   case 20: ipart2_max=(ao->combos)[base_collection2].size();
                    default:
                        std::cerr << "WRONG PARTICLE TYPE! Try PHO:"<<particles->at(1)->type << std::endl;
                        break;
                }
                for (int kpart=ipart2_max-1; kpart>=0; kpart--){
                    particles->at(1)->index=kpart;
                    for (int jp=2; jp<particles->size(); jp++){
                     if (particles->at(jp)->type == t1) particles->at(jp)->index=ipart;
                     if (particles->at(jp)->type == t2) particles->at(jp)->index=kpart;
                    }
                    bool ppassed=(*cutIterator)->evaluate(ao);
                    if (!ppassed) {
                        (ao->gams).find(name)->second.erase( (ao->gams).find(name)->second.begin()+ipart);
                        break;
                    }
                } // second particle set
            }// first particle set
        }// end of two particles
    }// end of cutIterator
   DEBUG("PHOTONS created\n");
}
void createNewFJet(AnalysisObjects* ao, vector<Node*> *criteria, std::vector<myParticle *> * particles, std::string name, std::string basename) {
    DEBUG("Creating new FATJETtype named:"<<name<<" #Ttypes:"<<ao->ljets.size()<< " Duplicating:"<<basename<<"\t");
    ao->ljets.insert( std::pair<string, vector<dbxJet> >(name, (ao->ljets)[basename]) );
    DEBUG(" #Ttypes became:"<<ao->ljets.size()<< " \n");

    for(auto cutIterator=criteria->begin();cutIterator!=criteria->end();cutIterator++) {
        particles->clear();
        (*cutIterator)->getParticlesAt(particles,0);
        int ipart_max = (ao->ljets)[name].size();
        bool simpleloop=true;

        DEBUG("Psize:"<<particles->size() <<"\n");
        if ( particles->size()==0) {
           DEBUG("CutIte:"<<(*cutIterator)->getStr()<<"\n");
           bool ppassed=(*cutIterator)->evaluate(ao);
           continue;
        }
        std::set<int> ptypeset;
        int t1=particles->at(0)->type;
        int t2;
        for ( int kp=0; kp<particles->size(); kp++ ) {
         ptypeset.insert( particles->at(kp)->type);
        }
        if ( ptypeset.size()>2 ) {cerr <<" 3 particle selection is not allowed in this version!\n"; exit(1);}
        if ( ptypeset.size()==2) {simpleloop=false; }
        std::set<int>::iterator ptit;
        ptit=ptypeset.begin(); ptit++;
        t2=*ptit;
 
        if(simpleloop){
            DEBUG("Simple Loop\n");
            for (int ipart=ipart_max-1; ipart>=0; ipart--){
               for (int jp=0; jp<particles->size(); jp++){
                particles->at(jp)->index=ipart;
                particles->at(jp)->collection=name;
               }
               bool ppassed=(*cutIterator)->evaluate(ao);
               if (!ppassed) (ao->ljets).find(name)->second.erase( (ao->ljets).find(name)->second.begin()+ipart);
            }
        }
        else {
            DEBUG("size=2\n");
            ValueNode abc=ValueNode();
            for (int ipart=ipart_max-1; ipart>=0; ipart--){
                particles->at(0)->index=ipart;  // 6213
                int ipart2_max;
                string base_collection2=particles->at(1)->collection;
                switch(particles->at(1)->type){
                    case 12: ipart2_max=(ao->muos)[base_collection2].size(); break;
		    case 10: ipart2_max=(ao->truth)[base_collection2].size(); break;
                    case 1: ipart2_max=(ao->eles)[base_collection2].size(); break;
                    case 2: ipart2_max=(ao->jets)[base_collection2].size(); break;
//                  case 3: ipart2_max=abc.tagJets(ao, 1).size(); //b-jets
//                      break;
//                  case 4: ipart2_max=abc.tagJets(ao, 1).size(); //light jets
//                      break;
                    case 8: ipart2_max=(ao->gams)[base_collection2].size(); break;
                    case 9: ipart2_max=(ao->ljets)[base_collection2].size(); break;
                   case 11: ipart2_max=(ao->taus)[base_collection2].size(); break;
                   case 20: ipart2_max=(ao->combos)[base_collection2].size();
                    default:
                        std::cerr << "WRONG PARTICLE TYPE! Try FJET:"<<particles->at(1)->type << std::endl;
                        break;
                }
                for (int kpart=ipart2_max-1; kpart>=0; kpart--){
                    particles->at(1)->index=kpart;
                    for (int jp=2; jp<particles->size(); jp++){
                     if (particles->at(jp)->type == t1) particles->at(jp)->index=ipart;
                     if (particles->at(jp)->type == t2) particles->at(jp)->index=kpart;
                    }


                    bool ppassed=(*cutIterator)->evaluate(ao);
                    if (!ppassed) {
                        (ao->ljets).find(name)->second.erase( (ao->ljets).find(name)->second.begin()+ipart);
                        break;
                    }
                } // second particle set
            }// first particle set
        }// end of two particles
    }// end of cutIterator
   DEBUG("FATJETs created\n");
}
void createNewTau(AnalysisObjects* ao, vector<Node*> *criteria, std::vector<myParticle *> * particles, std::string name, std::string basename) {
    DEBUG("Creating new TAUtype named:"<<name<<" #Ttypes:"<<ao->taus.size()<< " Duplicating:"<<basename<<"\n");
    ao->taus.insert( std::pair<string, vector<dbxTau> >(name, (ao->taus)[basename]) );
    DEBUG(" #Ttypes:"<<ao->taus.size()<< " Duplicated.\n");

    for(auto cutIterator=criteria->begin();cutIterator!=criteria->end();cutIterator++) {
        particles->clear();
        (*cutIterator)->getParticlesAt(particles,0);
        int ipart_max = (ao->taus)[name].size();
        bool simpleloop=true;
 
        DEBUG("Psize:"<<particles->size() <<"\n");
        if ( particles->size()==0) {
           DEBUG("CutIte:"<<(*cutIterator)->getStr()<<"\n");
           bool kill_all=false;
           TString mycutstr=(*cutIterator)->getStr();
           if ( mycutstr.Contains("kill") ) kill_all=true;

           int retval=(*cutIterator)->evaluate(ao);
           DEBUG("RetVal:"<<retval<<"\n");
           if (kill_all) {
            for (int ipart=ipart_max-1; ipart>=0; ipart--){
               if (retval != ipart) { DEBUG("Killing muon:"<<ipart);
                   (ao->taus).find(name)->second.erase( (ao->taus).find(name)->second.begin()+ipart);
               }
            }
           }
           DEBUG("T---------------------------------\n");
           continue;
        }
        std::set<int> ptypeset;
        int t1=particles->at(0)->type;
        int t2;
        for ( int kp=0; kp<particles->size(); kp++ ) {
         ptypeset.insert( particles->at(kp)->type);
        }
        if ( ptypeset.size()>2 ) {cerr <<" 3 particle selection is not allowed in this version!\n"; exit(1);}
        if ( ptypeset.size()==2) {simpleloop=false; }
        std::set<int>::iterator ptit; 
        ptit=ptypeset.begin(); ptit++;
        t2=*ptit;      

        if(simpleloop){
            DEBUG("size=1\n");
            for (int ipart=ipart_max-1; ipart>=0; ipart--){
                particles->at(0)->index=ipart;
                particles->at(0)->collection=name;
                bool ppassed=(*cutIterator)->evaluate(ao);
                if (!ppassed) (ao->taus).find(name)->second.erase( (ao->taus).find(name)->second.begin()+ipart);
            }
        }
        else {
            DEBUG("size=2\n");
            ValueNode abc=ValueNode();
            for (int ipart=ipart_max-1; ipart>=0; ipart--){
                particles->at(0)->index=ipart;  // 6213
                int ipart2_max;
                string base_collection2=particles->at(1)->collection;
                switch(particles->at(1)->type){
                    case 12: ipart2_max=(ao->muos)[base_collection2].size(); break;
	            case 10: ipart2_max=(ao->truth)[base_collection2].size(); break; 
                    case 1: ipart2_max=(ao->eles)[base_collection2].size(); break;
                    case 2: ipart2_max=(ao->jets)[base_collection2].size(); break;
//                  case 3: ipart2_max=abc.tagJets(ao, 1).size(); //b-jets
//                      break;
//                  case 4: ipart2_max=abc.tagJets(ao, 1).size(); //light jets
//                      break;
                    case 8: ipart2_max=(ao->gams)[base_collection2].size(); break;
                    case 9: ipart2_max=(ao->ljets)[base_collection2].size(); break;
                   case 11: ipart2_max=(ao->taus)[base_collection2].size(); break;
                   case 20: ipart2_max=(ao->combos)[base_collection2].size();
                    default:
                        std::cerr << "WRONG PARTICLE TYPE! Try Tau:"<<particles->at(1)->type << std::endl;
                        break;
                }
                for (int kpart=ipart2_max-1; kpart>=0; kpart--){
                    particles->at(1)->index=kpart;
                    for (int jp=2; jp<particles->size(); jp++){
                     if (particles->at(jp)->type == t1) particles->at(jp)->index=ipart;
                     if (particles->at(jp)->type == t2) particles->at(jp)->index=kpart;
                    }


                    bool ppassed=(*cutIterator)->evaluate(ao);
                    if (!ppassed) {
                        (ao->taus).find(name)->second.erase( (ao->taus).find(name)->second.begin()+ipart);
                        break;
                    }
                } // second particle set
            }// first particle set
        }// end of two particles
    }// end of cutIterator
   DEBUG("TAUS created\n");
}
//------------------------
void createNewCombo(AnalysisObjects* ao, vector<Node*> *criteria, std::vector<myParticle *> * particles, std::string name, std::string basename) {
   DEBUG("Creating new COMBO type named:"<<name<<" previous Combo types #:"<<ao->combos.size()<<"\n"); //xxx

   vector<dbxParticle>  combination;
   dbxParticle *adbxp;
   TLorentzVector  alv;
   std::string collectionName;
   int ipart_max;

   for(auto cutIterator=criteria->begin();cutIterator!=criteria->end();cutIterator++){
        particles->clear();
        (*cutIterator)->getParticles(particles);

     DEBUG("Psize:"<<particles->size() <<"\n");
      for (int jj=0; jj<particles->size(); jj++){
       DEBUG("T:"<<particles->at(jj)->type<< " i:"<<particles->at(jj)->index<<" C:"<< particles->at(jj)->collection<<"\n");
       collectionName=particles->at(jj)->collection;

       switch(particles->at(jj)->type){
                  case muon_t: 
                            if ( (ao->muos).find(collectionName) == ao->muos.end() ) {
                               cout << "ERROR: "<<collectionName<<" collection is not DEFINED\n"
                                    << " Try adding:  select Size("<<collectionName<<") >= 0  to solve the problem.";
                               exit (1);
                            }
                            ipart_max=(ao->muos)[collectionName].size();
                            for (int ipart=0; ipart<ipart_max; ipart++){
                                alv=(ao->muos)[collectionName].at(ipart).lv();
                                adbxp= new dbxParticle(alv);
                                adbxp->setCharge((ao->muos)[collectionName].at(ipart).q() );
                                adbxp->setPdgID( (ao->muos)[collectionName].at(ipart).pdgID() );
                                combination.push_back(*adbxp);
                                delete adbxp;
                            }
                            break;
                    case electron_t: 
                            if ( (ao->eles).find(collectionName) == ao->eles.end() ) {
                               cout << "ERROR: "<<collectionName<<" is not previously used in Selection.\n"
                                    << " Try adding:  select Size("<<collectionName<<") >= 0  to solve the problem.";
                               exit (1);
                            }
                            ipart_max=(ao->eles)[collectionName].size();
                            for (int ipart=0; ipart<ipart_max; ipart++){
                                alv=(ao->eles)[collectionName].at(ipart).lv();
                                adbxp= new dbxParticle(alv);
                                adbxp->setCharge((ao->eles)[collectionName].at(ipart).q() );
                                adbxp->setPdgID( (ao->eles)[collectionName].at(ipart).pdgID() );
                                combination.push_back(*adbxp);
                                delete adbxp;
                            }
                            break;
		    case 10: ipart_max=(ao->truth)[collectionName].size();
                        break;
                    case 2: ipart_max=(ao->jets)[collectionName].size();
                        break;
//                  case 3: ipart_max=abc.tagJets(ao, 1).size(); //b-jets
//                      break;
//                  case 4: ipart_max=abc.tagJets(ao, 1).size(); //light jets
//                      break;
                    case 8: ipart_max=(ao->gams)[collectionName].size(); break;
                    case 9: ipart_max=(ao->ljets)[collectionName].size(); break;
                   case 11: ipart_max=(ao->taus)[collectionName].size();
                            for (int ipart=0; ipart<ipart_max; ipart++){
                                alv=(ao->taus)[collectionName].at(ipart).lv();
                                adbxp= new dbxParticle(alv);
                                adbxp->setCharge((ao->taus)[collectionName].at(ipart).q() );
                                adbxp->setPdgID( (ao->taus)[collectionName].at(ipart).pdgID() );
                                combination.push_back(*adbxp);
                                delete adbxp;
                            }
                            break;
                   case 20: ipart_max=(ao->combos)[collectionName].size(); 
                            for (int ipart=0; ipart<ipart_max; ipart++){
                                alv=(ao->combos)[collectionName].at(ipart).lv();
                                adbxp= new dbxParticle(alv);
                                adbxp->setCharge((ao->combos)[collectionName].at(ipart).q() );
                                adbxp->setPdgID( (ao->combos)[collectionName].at(ipart).pdgID() );
                                combination.push_back(*adbxp);
                                delete adbxp;
                            }
                            break;
                    default:
                        std::cerr << "WRONG PARTICLE COMBO TYPE! Type:"<<particles->at(jj)->type << std::endl;
                        break;
                }
        DEBUG("Adding # particles:"<<ipart_max<<"\n");

      } //end of particle loop
   }// end of  cut iterator loop
   ao->combos.insert( pair <string,vector<dbxParticle> > (name,     combination) );

   DEBUG("After addition, types #:"<<ao->combos.size()<< " \t");
   DEBUG(" added particle#:"<<(ao->combos)[name].size()<< " \n");

}

//------------------------------------------------
void createNewTruth(AnalysisObjects* ao, vector<Node*> *criteria, std::vector<myParticle *> * particles, std::string name, std::string basename) {
    DEBUG("Creating new GEN type named:"<<name<<" #Gtypes:"<<ao->truth.size()<<" #Gparticles:"<< (ao->truth)[basename].size() <<" Duplicating:"<<basename<<"\n"); 
    ao->truth.insert( std::pair<string, vector<dbxTruth> >(name, (ao->truth)[basename]) );
    DEBUG(ao->constits.size()<< " initial constits maps\n");
    map <string, std::vector<dbxParticle>  >::iterator itpa;
    for (itpa=ao->constits.begin();itpa!=ao->constits.end();itpa++){
     DEBUG(itpa->first<<" has "<<itpa->second.size()<<"\n" );
    }

    for(auto cutIterator=criteria->begin();cutIterator!=criteria->end();cutIterator++) {
        particles->clear();
        (*cutIterator)->getParticlesAt(particles,0);
        int ipart_max = (ao->truth)[name].size();
        bool simpleloop=true;
        bool constiloop=false;

        DEBUG("Number of particles in this cut:"<<particles->size() <<"\n");
        DEBUG("CutIte:"<<(*cutIterator)->getStr()<<"\n");
        if ( particles->size()==0) {
           bool ppassed=(*cutIterator)->evaluate(ao);
           continue;
        }
//---------this needs to be tested at PARSING TIME!!!!!!!!!! NGU TODO
        std::set<int> ptypeset;
        int t1=particles->at(0)->type;
        int t2;
        for ( int kp=0; kp<particles->size(); kp++ ) {
         ptypeset.insert( particles->at(kp)->type);
         DEBUG(kp<<" th particle ID is:"<<particles->at(kp)->type<<"\n");
         if (particles->at(kp)->type == consti_t) constiloop=true;
        }
//--------------------- if we have a LoopNode(max, min, sum) no constiloop.
        TString mycutstr=(*cutIterator)->getStr();
        if ( mycutstr.Contains("sum") || mycutstr.Contains("max") || mycutstr.Contains("min")) constiloop=false;
        if ( ptypeset.size()>2 ) {cerr <<" 3 particle selection is not allowed in this version!\n"; exit(1);}
        if ( ptypeset.size()==2) {simpleloop=false; }
        std::set<int>::iterator ptit;
        ptit=ptypeset.begin(); ptit++;
        t2=*ptit; 
//----------------------------
        if (constiloop) { // basename: previous base object, name: new object
          DEBUG("--GEN daugther loop-- "<< ipart_max<<"\n");
          for (int ipart=ipart_max-1; ipart>=0; ipart--){ // loop over all particles, jets, in an event.
//--------------the name is derived from particleID
             int pidx=(ao->truth)[name].at(ipart).ParticleIndx();
             TString colname=name + pidx;
             int constiCount = (ao->constits).find((string)colname)->second.size();
             DEBUG("for "<<name<<" children size:"<<constiCount<<"\n");
             for (int ic=constiCount-1; ic>=0; ic--){
//---------------these are the particles to be dealt with, like a loop!
              for (int jp=0; jp<particles->size(); jp++){//the particles in the cut, e.g. pT(JET_jp) > 10
                particles->at(jp)->index=ic;
                particles->at(jp)->collection=(string)colname; // new name
                particles->at(jp)->type=consti_t;
              }
              DEBUG("For child:"<<ic<<" CutIte:"<<(*cutIterator)->getStr()<<"\n"); // this is like qOf, applied on each constituent
              bool ppassed=(*cutIterator)->evaluate(ao); // check on constituents?
              DEBUG("Result:"<<ppassed<<"\n");
              if (!ppassed) { 
                   DEBUG("child "<< ic <<" failed and will be removed.\n");
                   (ao->constits).find((string)colname)->second.erase( (ao->constits).find((string)colname)->second.begin()+ic); // erase child
              }
             }//end of loop over constituent
           if ( (ao->constits).find((string)colname)->second.size() < 1) {
               DEBUG(ipart<<"th gen removed from "<<name<<" since all constituents were removed.\n");
               (ao->truth).find(name)->second.erase( (ao->truth).find(name)->second.begin()+ipart); // erase particle without children
           }
          }// end of loop over all particles (truth) in the event.
         continue; // will move to the next cut iterator
        } // done with constis
        DEBUG(name <<" has " << (ao->truth)[name].size()<<" particles left after constiloop.\n");
        map <string, std::vector<dbxParticle>  >::iterator itpa;

        if(simpleloop){
          DEBUG("--GEN simple loop-- "<< ipart_max<<"\n");
          for (int ipart=ipart_max-1; ipart>=0; ipart--){
             int pidx=(ao->truth)[name].at(ipart).ParticleIndx();
             for (int jp=0; jp<particles->size(); jp++){
                particles->at(jp)->index=ipart;
                particles->at(jp)->collection=name;
             }
             bool ppassed=(*cutIterator)->evaluate(ao);
             DEBUG(name<<" ID"<< pidx<<" Res:"<<ppassed<<"\n");
             if (!ppassed) {
                 TString dname;
                 dname = name + pidx;
                 itpa=(ao->constits).find((string)dname);
                 DEBUG("will delete:"<<dname<<"\n");
                 if (itpa!=(ao->constits).end()) (ao->constits).erase(itpa);
                 (ao->truth).find(name)->second.erase( (ao->truth).find(name)->second.begin()+ipart);
             }  
          }
          DEBUG(name <<" has " << (ao->truth)[name].size()<<" particles left after simpleloop.\n");
//------------------------------------
//put the children in a consti_t array
//------------------------------------
         DEBUG(ao->constits.size()<< " constits maps\n");
         for (itpa=ao->constits.begin();itpa!=ao->constits.end();itpa++){
          DEBUG(itpa->first<<" has "<<itpa->second.size()<<"\n" );
         }
         DEBUG("===============\n");
         TString dname;
         for (int ipart=(ao->truth)[name].size()-1; ipart>=0; ipart--){
           int child1=(ao->truth)[name].at(ipart).Attribute(8);
           int child2=(ao->truth)[name].at(ipart).Attribute(9);
           int pidx=(ao->truth)[name].at(ipart).ParticleIndx();
           DEBUG("Id:"<< pidx <<" has children:"<<child1<<" to "<<child2<<"\t");
           vector<dbxParticle> children;
           string genname="Truth";
           for (int ichild=child1; ichild<=child2; ichild++){
             children.push_back( (ao->truth)[genname].at(ichild) );
           }
           dname = name;
           dname+= pidx;
           (ao->constits).insert( std::pair<string, vector<dbxParticle> >((string)dname, children) );
           DEBUG(name <<" has " << (ao->constits).find((string)dname)->second.size()<<" dauthers inserted.\n");
         }
//------------DONE
        }
        else {
            ValueNode abc=ValueNode();
            for (int ipart=ipart_max-1; ipart>=0; ipart--){
                particles->at(0)->index=ipart;  // 6213
                int ipart2_max;
                string base_collection2=particles->at(1)->collection;
                switch(particles->at(1)->type){
                  case muon_t: ipart2_max=(ao->muos)[base_collection2].size();
                        break;
	         case truth_t: ipart2_max=(ao->truth)[base_collection2].size();
                        break;
                   case electron_t: ipart2_max=(ao->eles)[base_collection2].size();
                        break;
                   case jet_t: ipart2_max=(ao->jets)[base_collection2].size();
                        break;
                case photon_t: ipart2_max=(ao->gams)[base_collection2].size();
                        break;
                  case fjet_t: ipart2_max=(ao->ljets)[base_collection2].size();
                        break;
                   case tau_t: ipart2_max=(ao->taus)[base_collection2].size();
                        break;
                 case combo_t: ipart2_max=(ao->combos)[base_collection2].size();
                        break;
                      default:
                        std::cerr << "WRONG PARTICLE TYPE! Try Truth:"<<particles->at(1)->type << std::endl;
                        break;
                }
                for (int kpart=ipart2_max-1; kpart>=0; kpart--){
                    particles->at(1)->index=kpart;

                    for (int jp=2; jp<particles->size(); jp++){
                     if (particles->at(jp)->type == t1) particles->at(jp)->index=ipart;
                     if (particles->at(jp)->type == t2) particles->at(jp)->index=kpart;
                    }

                    bool ppassed=(*cutIterator)->evaluate(ao);
                    if (!ppassed) {
                        (ao->truth).find(name)->second.erase( (ao->truth).find(name)->second.begin()+ipart);
                        break;
                    }
                } // second particle set
            }// first particle set
        }// end of two particles
    }// end of cutIterator
}
 
void step_add_a_comb(vector<int> output_ii, vector<int> tab_select_jj, vector<int>& table_B_ii, int index_jj, int n, int pas )
{
	vector<int> temp(tab_select_jj.size()); 
	for(int i = 0; i<n; i++)
	{
		for(int j = 0; j<pas; j++)
			temp[j] = output_ii[j+i*pas];

		if(temp==tab_select_jj)
			{
        table_B_ii.push_back(index_jj);
      }
	}
}

void createNewParti(AnalysisObjects* ao, vector<Node*> *criteria, std::vector<myParticle *> * particles, std::string name, std::string basename) {
   DEBUG("Creating new PARTITION COMBO type named:"<<name<<" previous Combo types #:"<<ao->combos.size()<<"\n"); //xxx

   vector<dbxParticle>  combination;
   dbxParticle *adbxp;
   std::string collectionName;
   int ipart_max;
   vector<int> available_parts;
   int requested_max;
   int requested_size;

   auto cutIterator=criteria->begin();
   particles->clear();
   (*cutIterator)->getParticles(particles);
    requested_size=particles->size();
    DEBUG("iCut: "<<(*cutIterator)->getStr()<<"\n");
    DEBUG("iPsize:"<<particles->size() <<"\n");

// at this point I have the particles I will use to construct the combined object. like j1 and j2
// now we find how many of those particles we have in each event
    for (int jj=0; jj<particles->size(); jj++){
       DEBUG("Type:"<<particles->at(jj)->type<< " index:"<<particles->at(jj)->index<<" Coll:"<< particles->at(jj)->collection<<"\n");
       collectionName=particles->at(jj)->collection;
       switch(particles->at(jj)->type){
                   case muon_t: 
                            if ( (ao->muos).find(collectionName) == ao->muos.end() ) {
                               cout << "ERROR: "<<collectionName<<" collection is not DEFINED\n"
                                    << " Try adding:  select Size("<<collectionName<<") >= 0  to solve the problem.";
                               exit (1);
                            }
                            ipart_max=(ao->muos)[collectionName].size();
                            break;
                    case electron_t: 
                            if ( (ao->eles).find(collectionName) == ao->eles.end() ) {
                               cout << "ERROR: "<<collectionName<<" is not previously used in Selection.\n"
                                    << " Try adding:  select Size("<<collectionName<<") >= 0  to solve the problem.";
                               exit (1);
                            }
                            ipart_max=(ao->eles)[collectionName].size();
                            break;
		    case truth_t: ipart_max=(ao->truth)[collectionName].size();
                        break;
                    case jet_t: ipart_max=(ao->jets)[collectionName].size();
                        break;
                    case photon_t: ipart_max=(ao->gams)[collectionName].size();
                        break;
                    case fjet_t: ipart_max=(ao->ljets)[collectionName].size();
                        break;
                    case tau_t: ipart_max=(ao->taus)[collectionName].size();
                            break;
                    case combo_t: ipart_max=(ao->combos)[collectionName].size();
                            break;
                    default:
                        std::cerr << "WRONG PARTICLE TYPE in Parti! Type:"<<particles->at(jj)->type << std::endl;
                        break;
                }
        DEBUG("Max # particles:"<<ipart_max<<"\n");

        if ((jj>0) && (particles->at(jj)->type != particles->at(jj-1)->type) ) {
          available_parts.push_back(ipart_max);
        } 
        if (jj==0){
          available_parts.push_back(ipart_max);
          requested_max=ipart_max;
        } 
      } //end of particle loop

    vector<int> temp_index;
    vector<vector<int>> combi_out; 
    

    if (available_parts.size() < 2) {
//---- NANT's code to produce all the combined objetcs
    DEBUG ("req max:"<<requested_max <<" req_size:"<< requested_size <<" \n");
    Comb combinations_part (requested_max, requested_size);

#ifdef _CLV_
    combinations_part.affiche();
#endif
    combi_out = combinations_part.output();// exemple: out  = {{0,1} , {0,2}, {1,2}} si ipart_max = 3 et particles->size() = 2
    } else { // works for two particles for now
     for (int ipa1=0;  ipa1<available_parts[0]; ipa1++) {
      for (int ipa2=0;  ipa2<available_parts[1]; ipa2++) {
       DEBUG(ipa1 << " , " << ipa2<<"\n");
       temp_index.push_back(ipa1); temp_index.push_back(ipa2);
       combi_out.push_back(temp_index);
       temp_index.clear();
     }
     }
    }

    TLorentzVector  alv;
    int apq = 0;
    int apdgid=0;
    
    for(size_t k=0; k<combi_out.size(); ++k) {
      temp_index = combi_out[k]; // ex temp_index = {0,1} 
      for(size_t i = 0; i<temp_index.size(); ++i){
	DEBUG ("Now p index is:"<< temp_index[i]<< " type:"<< particles->at(i)->type<< " \n"); 
        collectionName=particles->at(i)->collection;
	switch(particles->at(i)->type){
	  case muon_t: 
            DEBUG ("getting a muon "<< collectionName <<" \n");
	    alv+=(ao->muos)[collectionName].at(temp_index[i]).lv();
	    apq+=(ao->muos)[collectionName].at(temp_index[i]).q();
	    apdgid+=(ao->muos)[collectionName].at(temp_index[i]).pdgID();
	    break;
	  case electron_t: 
	    alv+=(ao->eles)[collectionName].at(temp_index[i]).lv();
	    apq+=(ao->eles)[collectionName].at(temp_index[i]).q();
	    apdgid+=(ao->eles)[collectionName].at(temp_index[i]).pdgID();
	    break;
	  case truth_t:
	    alv+=(ao->truth)[collectionName].at(temp_index[i]).lv();
	    apq+=(ao->truth)[collectionName].at(temp_index[i]).q();
	    apdgid+=(ao->truth)[collectionName].at(temp_index[i]).pdgID();
	    break;
	  case jet_t:
	    alv+=(ao->jets)[collectionName].at(temp_index[i]).lv();
	    apq+=(ao->jets)[collectionName].at(temp_index[i]).q();
	    apdgid+=(ao->jets)[collectionName].at(temp_index[i]).pdgID();
	    break;
	  case photon_t: 
            alv+=(ao->gams)[collectionName].at(temp_index[i]).lv();
            apdgid+=(ao->gams)[collectionName].at(temp_index[i]).pdgID();
	    break;
	  case fjet_t: 
            alv+=(ao->ljets)[collectionName].at(temp_index[i]).lv();
	    apq+=(ao->ljets)[collectionName].at(temp_index[i]).q();
	    apdgid+=(ao->ljets)[collectionName].at(temp_index[i]).pdgID();
	    break;
	  case tau_t: 
            DEBUG ("getting a Tau "<< collectionName <<" \n");
	    alv+=(ao->taus)[collectionName].at(temp_index[i]).lv();
	    apq+=(ao->taus)[collectionName].at(temp_index[i]).q();
	    apdgid+=(ao->taus)[collectionName].at(temp_index[i]).pdgID();
	    break;
	  case combo_t: 
	    alv+=(ao->combos)[collectionName].at(temp_index[i]).lv();
	    apq+=(ao->combos)[collectionName].at(temp_index[i]).q();
	    apdgid+=(ao->combos)[collectionName].at(temp_index[i]).pdgID();
	    break;
	  default:
	    std::cerr << "WRONG particle TYPE! Type:"<<particles->at(i)->type << std::endl;
	    break;
	  }
         DEBUG("Added a particle\n");
          
        } 	  
        DEBUG("all combis added\n");
// we have the combined particle AND the indices of the parents

	adbxp= new dbxParticle(alv);
	adbxp->setCharge(apq);                            
	adbxp->setPdgID(apdgid);                          
	combination.push_back(*adbxp);
	delete adbxp;
        apq=0;
        apdgid=0;
        alv.SetPxPyPzE(0,0,0,0);
        DEBUG("\n");
    }
    ao->combos.insert( pair <string,vector<dbxParticle> > (name,     combination) );

     vector<vector<int>> bad_combinations;
       set<vector<int>> good_combinations;

//----------      
    ipart_max = (ao->combos)[name].size();
    cutIterator++; // now moving on to the real, first cut defining the new set.
    while ( cutIterator!=criteria->end() ){ // do the real cuts now.
      particles->clear();
      (*cutIterator)->getParticles(particles); // reset particles for each cut
      bool simpleloop=true;
      DEBUG("***** Cur Cut: "<<(*cutIterator)->getStr()<<"\t Psize:"<<particles->size() <<" max_partices in event:"<<ipart_max<<"\n");
      if ( particles->size()==0) {
           DEBUG("CutIte:"<<(*cutIterator)->getStr()<<"\n");
           bool ppassed=(*cutIterator)->evaluate(ao);
           continue;
      }
      std::set<int> ptypeset;
      std::set<int> pindexset;
      std::vector<int> index_backup;
      int t1=particles->at(0)->type;
      int tidx1=particles->at(0)->index;
      int t2;
      int tidx2;
      for ( int kp=0; kp<particles->size(); kp++ ) { // to count particle types,
         if (particles->at(kp)->type == 6213) {simpleloop=false; }
         ptypeset.insert( particles->at(kp)->type);
	 pindexset.insert( particles->at(kp)->index); 
         index_backup.push_back(particles->at(kp)->index ); // to take a backup
      }
      if ( ptypeset.size()>2 ) {cerr <<" 3 different particle type selection is not allowed in this version!\n"; exit(1);}
      std::set<int>::iterator ptit;
      std::set<int>::iterator pIit;
      ptit=ptypeset.begin(); ptit++;
      t2=*ptit;
      pIit=pindexset.begin(); pIit++;
      tidx2=*pIit;

      if(simpleloop){
           DEBUG("simpleloop, idx0:"<<tidx1<<"\n");
           for (int ipart=ipart_max-1; ipart>=0; ipart--){ //----------these are the combinations
               std::vector< vector<int> >::iterator itb; // bad list iterator
               DEBUG("\n===> combi index:"<<ipart<<"\n");
               itb=find (bad_combinations.begin(), bad_combinations.end(), combi_out[ipart]);
               if ( itb!= bad_combinations.end() ) {
                  DEBUG("SKIP aldeady bad combi\n");
                  continue; // skip the bad indices
               }
               DEBUG("Going to evaluate "<< combi_out[ipart][0] <<" " <<combi_out[ipart][1]  <<"\n");

               for (int jp=0; jp<particles->size(); jp++){ //
                tidx1=index_backup.at(jp);
                DEBUG(" this particle:"<<jp<<" index:"<< tidx1<<" type:"<< t1<<" name:"<<particles->at(jp)->collection<<"\n");
                if (tidx1 < 0) {  DEBUG("******Negative INDEX !!!\t");
                   temp_index = combi_out[ ipart ];
                   particles->at(jp)->index =temp_index[abs(1+tidx1)]; // means we respect order -1, -2 
                   DEBUG("new index: "<< particles->at(jp)->index  <<"\n");
                } else {
//                  particles->at(jp)->index=ipart;
//                  particles->at(jp)->collection=name;
                 ;
                }
               }

               bool ppassed=(*cutIterator)->evaluate(ao);
               DEBUG("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ P or F: ~~~~~~ "<<ppassed<<"\n");
               if (!ppassed) {
		// 			(ao->combos).find(name)->second.erase( (ao->combos).find(name)->second.begin()+ipart);
		 			bad_combinations.push_back(combi_out[ipart]);
		 			good_combinations.erase(combi_out[ipart]);
	     		    } else      good_combinations.insert(combi_out[ipart]);
           DEBUG("A cut finished.\n");
	   }
      } else {
	DEBUG("TWO particle type loop\n");
	ValueNode abc=ValueNode();
	for (int ipart=ipart_max-1; ipart>=0; ipart--){ // loop over combis
          std::vector< vector<int> >::iterator itb; // bad list iterator
          itb=find (bad_combinations.begin(), bad_combinations.end(), combi_out[ipart]);
          if ( itb!= bad_combinations.end() ) {
                  DEBUG("SKIP aldeady bad combi\n");
                  continue; // skip the bad indices
          }
          DEBUG("combi index:"<<ipart<<"\n");
          for (int jp=0; jp<particles->size(); jp++){ //
                tidx1=index_backup.at(jp);
                DEBUG(" this particle:"<<jp<<" index:"<< tidx1<<" type:"<< t1<<" name:"<<name<<"\n");
                if (tidx1 < 0) {  DEBUG("******Negative INDEX !!!\t");
                   temp_index = combi_out[ ipart ];
                   particles->at(jp)->index =temp_index[abs(1+tidx1)]; // means we respect order -1, -2 
                   DEBUG("new index: "<< particles->at(jp)->index  <<"\n");
                } else if (tidx1 == 6213){ // this is a loop over the other particles
			  int ipart2_max;
			  string base_collection2=particles->at(jp)->collection;
			  switch(particles->at(jp)->type){
			  case muon_t: ipart2_max=(ao->muos)[base_collection2].size(); break;
			  case truth_t: ipart2_max=(ao->truth)[base_collection2].size(); break;
			  case electron_t: ipart2_max=(ao->eles)[base_collection2].size(); break;
			  case jet_t: ipart2_max=(ao->jets)[base_collection2].size(); break;
			  case photon_t: ipart2_max=(ao->gams)[base_collection2].size(); break;
			  case fjet_t: ipart2_max=(ao->ljets)[base_collection2].size(); break;
			  case tau_t: ipart2_max=(ao->taus)[base_collection2].size(); break;
			  case combo_t: ipart2_max=(ao->combos)[base_collection2].size(); break;
			  default:
			    std::cerr << "WRONG PARTICLE TYPE! type:"<<particles->at(1)->type << std::endl;
			    break;
			  }
                   DEBUG("Its Max: "<< ipart2_max <<"\n");


                } else { // normal particles
                  particles->at(jp)->index=ipart;
                  particles->at(jp)->collection=name;
                }
          }
	  
          DEBUG("Going to evaluate "<< combi_out[ipart][0] <<" " <<combi_out[ipart][1]  <<"\n");
	  bool ppassed=(*cutIterator)->evaluate(ao);
	  DEBUG("ooooooooooooooooooo P or F: ~~~ "<<ppassed<<"\n");
	  if (!ppassed) {
	    (ao->combos).find(name)->second.erase( (ao->combos).find(name)->second.begin()+ipart);
	        bad_combinations.push_back(combi_out[ipart]);
	        good_combinations.erase(combi_out[ipart]);
	  }
	  else good_combinations.insert(combi_out[ipart]);

	    
	} // ipart loop
      } // two particle
      cutIterator++;
    }// end of  cut iterator loop

   if (requested_max<=0) { //probably no particle available,never here
     vector<vector<int>> table_B;
     indicesA indexA={table_B, 0, 0};
     ao->combosA.insert( pair <string, indicesA > (name,     indexA) );
     return;
   }

//---------- we will clean the bad ones

    int new_req_max= requested_max-1;
    if  (available_parts.size()>1 ) new_req_max = requested_size;    

    DEBUG("Before denombre : "<< requested_size<< "  max:"<<new_req_max<<"\n");
    vector<vector<int>> out_selection;


    if (available_parts.size() < 2) { // NANT
      Denombrement All_possibles_combinations = Denombrement(requested_size, new_req_max);
      DEBUG("Before selection : \n");
#ifdef _CLV_
      All_possibles_combinations.affiche();
#endif
    DEBUG("Number of bads:"<< bad_combinations.size() <<"\n");
    Denombrement All_possibilities_with_selection = Denombrement(requested_size, new_req_max, bad_combinations);
    DEBUG(endl <<"After removing the bads : " << endl);
#ifdef _CLV_
    All_possibilities_with_selection.affiche();
#endif
    out_selection = All_possibilities_with_selection.output();

    } else {
      DEBUG("Before my selection : \n");
     for (int ipa1=0;  ipa1<combi_out.size(); ipa1++) {
       for (int ipa2=0;  ipa2<combi_out[ipa1].size(); ipa2++) DEBUG( combi_out[ipa1][ipa2] << "  ");
       DEBUG("\n");
     }
     DEBUG("Number of bads:"<< bad_combinations.size() <<"\n");
    }// ngu
    
    DEBUG("After addition, types #:"<<ao->combos.size()<< " \t");
    DEBUG(" remaining combo particle#:"<<(ao->combos)[name].size()<< " \n");

    vector<int> index_B;
    for(int i = 0; i<good_combinations.size(); i++) index_B.push_back(i);

    DEBUG(endl << "We have "<< index_B.size() << " combined particles left" << endl);
    set<vector<int>> :: iterator it;
    DEBUG("The surviving particles are :\n");

    for(it=good_combinations.begin(); it!=good_combinations.end(); it++)
    {
      out_selection.push_back(*it);
      for(int i = 0; i<particles->size(); i++) DEBUG((*it)[i] << " ");
      DEBUG(" -> " << index_B[distance(good_combinations.begin(), it)] << endl);
    }
    DEBUG(endl <<"After removing the bads : " << endl);

    vector<vector<int>> table_B;
    for (int ipa1=0;  ipa1<out_selection.size(); ipa1++) {
       vector<int> aRow;
       for (int ipa2=0;  ipa2<out_selection[ipa1].size(); ipa2++) {
                 DEBUG( out_selection[ipa1][ipa2] << "  " );
                 aRow.push_back(out_selection[ipa1][ipa2] );
            }
       table_B.push_back(aRow);
       DEBUG("\n");
    }
    
/* 
     vector<vector<int>> table_B(out_selection.size());

    for(int ii=0; ii<out_selection.size(); ii++)
    {
    	for(it=good_combinations.begin(); it!=good_combinations.end(); it++)
    	{
    		step_add_a_comb(out_selection[ii], *it, table_B[ii], distance(good_combinations.begin(), it), out_selection[ii].size()/requested_size, requested_size);
    	}
    }
*/
    DEBUG( endl << "Converting combinations to index:" << endl);
    int amaxrow=0;
    for(int i = 0; i<table_B.size(); i++) {
        if (table_B[i].size() > amaxrow) amaxrow=table_B[i].size();
    	for(int j = 0; j<table_B[i].size(); j++) DEBUG(table_B[i][j] << " ");
    	DEBUG("\n"); 
    }

    indicesA indexA={table_B, amaxrow, (int)table_B.size() };
    ao->combosA.insert( pair <string, indicesA > (name,     indexA) );

    out_selection.clear();
//    NANT's code, to be commented in later
//     All_possibilities_with_selection.output(out_selection);
//     All_possibles_combinations.output(out_selection);
    
   DEBUG("--Create new Parti ends---\n");
}

