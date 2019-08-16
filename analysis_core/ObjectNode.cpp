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

#define _CLV_
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
      if (anode->name == "MUO" ) type=0;
      if (anode->name == "ELE" ) type=1;
      if (anode->name == "JET" ) type=2;
      if (anode->name == "PHO" ) type=8;
      if (anode->name == "FJET") type=9;
      if (anode->name == "Truth") type=10;
      if (anode->name == "TAU" ) type=11;
      if (anode->name == "Combo" ) type=20;
      DEBUG(" I found:" << anode->name<<" t:"<<type<<"\n");
    } else { // if null
      if (id == "MUO" ) type=0;
      if (id == "ELE" ) type=1;
      if (id == "JET" ) type=2;
      if (id == "PHO" ) type=8;
      if (id == "FJET") type=9;
      if (id == "Truth") type=10;
      if (id == "TAU" ) type=11;
      if (id == "Combo" ) type=20;
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
    this->Reset(); ///////NGU
    DEBUG(" working for:"<<name << "  type:"<<type<<"\n");
    std::string basename="xxx";
    bool keepworking=true;

    DEBUG("inital sets #types: J, FJ, E, M, T, P:"<< ao->jets.size()<<","<<ao->ljets.size()<<","<< ao->eles.size()<<","<<ao->muos.size()<<","<<ao->taus.size() <<","<<ao->gams.size() <<"\n"); 
    DEBUG("# iparticles:"<< particles.size()<<"\n");
    if (particles.size() >0) DEBUG("type:"<< particles[0]->type<<"\t"<<particles[0]->collection<<"\n" );

    while(left!=NULL && keepworking) {
      ObjectNode* anode=(ObjectNode*)left;
      basename=anode->name;
      DEBUG("previous:"<< basename<< "  type:"<<type<<"\n"); // Combo, 20
// is it in the map list?
       switch (type) {
        case 0:       if (ao->muos.find(basename)==ao->muos.end()  ){
               			anode->evaluate(ao);
                                DEBUG(" Muos evaluated.\n");
                      } else keepworking=false;
                      break;

	case 10:      if (ao->truth.find(basename) == ao->truth.end() ){
				anode->evaluate(ao);
				DEBUG(" Truth evaluated.\n");
		      } else keepworking=false;
		      break;

        case 1:       if (ao->eles.find(basename)==ao->eles.end()  ){
               			anode->evaluate(ao);
                                DEBUG(" Eles evaluated.\n");
                      } else keepworking=false;
                      break;
       case 11:       if (ao->taus.find(basename)==ao->taus.end()  ){
               			anode->evaluate(ao);
                                DEBUG(" Taus evaluated.\n");
                      } else keepworking=false;
                      break;

        case 2:       if (ao->jets.find(basename)==ao->jets.end()  ){
               			anode->evaluate(ao);
                                DEBUG(" Jets evaluated.\n");
               	      } else keepworking=false;
                      break;
        case 8:       if (ao->gams.find(basename)==ao->gams.end()  ){
               			anode->evaluate(ao);
                                DEBUG(" *****Phos evaluated.\n");
               	      } else keepworking=false;
                      break;
        case 9:       if (ao->ljets.find(basename)==ao->ljets.end()  ){
               			anode->evaluate(ao);
                                DEBUG(" *****FJETs evaluated.\n");
               	      } else keepworking=false;
                      break;
       case 20:       if (ao->combos.find(basename)==ao->combos.end()  ){
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
      
    DEBUG("Before new set #types: J, FJ, E, M, T, P, C:"<< ao->jets.size()<<","<<ao->ljets.size()<<","<< ao->eles.size()<<","<<ao->muos.size()<<","<<ao->taus.size() <<","<<ao->gams.size()<<","<<ao->combos.size() <<"\n"); 
//---------------
    (*createNewSet)(ao,&criteria,&particles, name, basename);//modify analysis object based on criteria here
//---------------
    DEBUG(" After new set #types: J, FJ, E, M, T, P, C:"<< ao->jets.size()<<","<<ao->ljets.size()<<","<< ao->eles.size()<<","<<ao->muos.size()<<","<<ao->taus.size() <<","<<ao->gams.size()<<","<<ao->combos.size() <<"\n"); 

    for (itj=ao->jets.begin();itj!=ao->jets.end();itj++){
      DEBUG("\t #J typename:"<<itj->first<<"    size:"<<itj->second.size() <<"\n");
    }
    for (itp=ao->gams.begin();itp!=ao->gams.end();itp++){
      DEBUG("\t #P typename:"<<itp->first<<"    size:"<<itp->second.size() <<"\n");
    }
    for (itc=ao->combos.begin();itc!=ao->combos.end();itc++){
      DEBUG("\t #C typename:"<<itc->first<<"    size:"<<itc->second.size() <<"\n");
    }
    //Save AO somewhere to return in next time
    return 1;
}

// MUO     0
// ELE     1
// JET     2
// BJET    3
// QGJET   4
// NUMET_M 5 
// NUMET_E 6
// METLV   7
// PHO     8
// Tau    11 

void createNewJet(AnalysisObjects* ao,vector<Node*> *criteria,std::vector<myParticle *>* particles, std::string name, std::string basename){
    DEBUG("Creating new JETtype named:"<<name<<" #Jtypes:"<<ao->jets.size()<< " Duplicating:"<<basename<<"\n");
    ao->jets.insert( std::pair<string, vector<dbxJet> >(name, (ao->jets)[basename]) );
    for(auto cutIterator=criteria->begin();cutIterator!=criteria->end();cutIterator++){
        particles->clear();
        (*cutIterator)->getParticlesAt(particles,0);
        int ipart_max = (ao->jets)[name].size();
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
            for (int ipart=ipart_max-1; ipart>=0; ipart--){ // I have all particles, jets, in an event.
               for (int jp=0; jp<particles->size(); jp++){
                particles->at(jp)->index=ipart;
                particles->at(jp)->collection=name;
               }
                DEBUG("CutIte:"<<(*cutIterator)->getStr()<<"\n");
                bool ppassed=(*cutIterator)->evaluate(ao);
                if (!ppassed) (ao->jets).find(name)->second.erase( (ao->jets).find(name)->second.begin()+ipart);
            }
        }
        else {
            ValueNode abc=ValueNode();
            for (int ipart=ipart_max-1; ipart>=0; ipart--){
                particles->at(0)->index=ipart;  // 6213
                particles->at(0)->collection=name;             
                int ipart2_max=-1;
                string base_collection2=particles->at(1)->collection;
                try {
                switch(particles->at(1)->type){
                    case 0: ipart2_max=(ao->muos).at(base_collection2).size(); break;
		    case 10: ipart2_max=(ao->truth).at(base_collection2).size(); break;
                    case 1: ipart2_max=(ao->eles).at(base_collection2).size(); break;
                    case 2: ipart2_max=(ao->jets).at(base_collection2).size(); break;
//                    case 3: ipart2_max=abc.tagJets(ao, 1).size(); //b-jets
//                        break;
//                    case 4: ipart2_max=abc.tagJets(ao, 1).size(); //light jets
//                        break;
                    case 7: ipart2_max=1; break;
                    case 8: ipart2_max=(ao->gams).at(base_collection2).size(); break;
                    case 9: ipart2_max=(ao->ljets).at(base_collection2).size(); break;
                   case 11: ipart2_max=(ao->taus).at(base_collection2).size(); break;
                    default:
                        std::cerr << "WRONG PARTICLE TYPE:"<<particles->at(1)->type << std::endl;
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
                    case 0: ipart2_max=(ao->muos)[base_collection2].size();
                        break;
		    case 10: ipart2_max=(ao->truth)[base_collection2].size();
                        break;
                    case 1: ipart2_max=(ao->eles)[base_collection2].size();
                        break;
                    case 2: ipart2_max=(ao->jets)[base_collection2].size();
                        break;
//                  case 3: ipart2_max=abc.tagJets(ao, 1).size(); //b-jets
//                      break;
//                  case 4: ipart2_max=abc.tagJets(ao, 1).size(); //light jets
//                      break;
                    case 8: ipart2_max=(ao->gams)[base_collection2].size();
                        break;
                    case 9: ipart2_max=(ao->ljets)[base_collection2].size();
                        break;
                   case 11: ipart2_max=(ao->taus)[base_collection2].size();
                        break;
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
    ao->muos.insert( std::pair<string, vector<dbxMuon> >(name, (ao->muos)[basename]) );
    for(auto cutIterator=criteria->begin();cutIterator!=criteria->end();cutIterator++) {
        particles->clear();
        (*cutIterator)->getParticlesAt(particles,0);
        int ipart_max = (ao->muos)[name].size();
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
            for (int ipart=ipart_max-1; ipart>=0; ipart--){
               for (int jp=0; jp<particles->size(); jp++){
                particles->at(jp)->index=ipart;
                particles->at(jp)->collection=name;
               }
               bool ppassed=(*cutIterator)->evaluate(ao);
               if (!ppassed) (ao->muos).find(name)->second.erase( (ao->muos).find(name)->second.begin()+ipart);
            }
        }
        else {
            ValueNode abc=ValueNode();
            for (int ipart=ipart_max-1; ipart>=0; ipart--){
                particles->at(0)->index=ipart;  // 6213
                int ipart2_max;
                string base_collection2=particles->at(1)->collection;
                switch(particles->at(1)->type){
                    case 0: ipart2_max=(ao->muos)[base_collection2].size();
                        break;
		    case 10: ipart2_max=(ao->truth)[base_collection2].size();
                        break;
                    case 1: ipart2_max=(ao->eles)[base_collection2].size();
                        break;
                    case 2: ipart2_max=(ao->jets)[base_collection2].size();
                        break;
//                  case 3: ipart2_max=abc.tagJets(ao, 1).size(); //b-jets
//                      break;
//                  case 4: ipart2_max=abc.tagJets(ao, 1).size(); //light jets
//                      break;
                    case 8: ipart2_max=(ao->gams)[base_collection2].size();
                        break;
                    case 9: ipart2_max=(ao->ljets)[base_collection2].size();
                        break;
                   case 11: ipart2_max=(ao->taus)[base_collection2].size();
                        break;
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
                    case 0: ipart2_max=(ao->muos)[base_collection2].size();
                        break;
		    case 10: ipart2_max=(ao->truth)[base_collection2].size();
                        break;
                    case 1: ipart2_max=(ao->eles)[base_collection2].size();
                        break;
                    case 2: ipart2_max=(ao->jets)[base_collection2].size();
                        break;
//                  case 3: ipart2_max=abc.tagJets(ao, 1).size(); //b-jets
//                      break;
//                  case 4: ipart2_max=abc.tagJets(ao, 1).size(); //light jets
//                      break;
                    case 8: ipart2_max=(ao->gams)[base_collection2].size();
                        break;
                    case 9: ipart2_max=(ao->ljets)[base_collection2].size();
                        break;
                   case 11: ipart2_max=(ao->taus)[base_collection2].size();
                        break;
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
                    case 0: ipart2_max=(ao->muos)[base_collection2].size();
                        break;
		    case 10: ipart2_max=(ao->truth)[base_collection2].size();
                        break;
                    case 1: ipart2_max=(ao->eles)[base_collection2].size();
                        break;
                    case 2: ipart2_max=(ao->jets)[base_collection2].size();
                        break;
//                  case 3: ipart2_max=abc.tagJets(ao, 1).size(); //b-jets
//                      break;
//                  case 4: ipart2_max=abc.tagJets(ao, 1).size(); //light jets
//                      break;
                    case 8: ipart2_max=(ao->gams)[base_collection2].size();
                        break;
                    case 9: ipart2_max=(ao->ljets)[base_collection2].size();
                        break;
                   case 11: ipart2_max=(ao->taus)[base_collection2].size();
                        break;
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
                    case 0: ipart2_max=(ao->muos)[base_collection2].size();
                        break;
	            case 10: ipart2_max=(ao->truth)[base_collection2].size();
                        break; 
                    case 1: ipart2_max=(ao->eles)[base_collection2].size();
                        break;
                    case 2: ipart2_max=(ao->jets)[base_collection2].size();
                        break;
//                  case 3: ipart2_max=abc.tagJets(ao, 1).size(); //b-jets
//                      break;
//                  case 4: ipart2_max=abc.tagJets(ao, 1).size(); //light jets
//                      break;
                    case 8: ipart2_max=(ao->gams)[base_collection2].size();
                        break;
                    case 9: ipart2_max=(ao->ljets)[base_collection2].size();
                        break;
                   case 11: ipart2_max=(ao->taus)[base_collection2].size();
                        break;
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
                    case 0: 
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
                                combination.push_back(*adbxp);
                                delete adbxp;
                            }
                            break;
                    case 1: 
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
                    case 8: ipart_max=(ao->gams)[collectionName].size();
                        break;
                    case 9: ipart_max=(ao->ljets)[collectionName].size();
                        break;
                   case 11: ipart_max=(ao->taus)[collectionName].size();
                            for (int ipart=0; ipart<ipart_max; ipart++){
                                alv=(ao->taus)[collectionName].at(ipart).lv();
                                adbxp= new dbxParticle(alv);
                                adbxp->setCharge((ao->taus)[collectionName].at(ipart).q() );
                                combination.push_back(*adbxp);
                                delete adbxp;
                            }
                            break;
                    default:
                        std::cerr << "WRONG PARTICLE TYPE! Type:"<<particles->at(jj)->type << std::endl;
                        break;
                }
        DEBUG("Adding # particles:"<<ipart_max<<"\n");

      } //end of particle loop
   }// end of  cut iterator loop
   ao->combos.insert( pair <string,vector<dbxParticle> > (name,     combination) );

   DEBUG("After addition, types #:"<<ao->combos.size()<< " \t");
   DEBUG(" added particle#:"<<(ao->combos)[name].size()<< " \n");

}


void createNewTruth(AnalysisObjects* ao, vector<Node*> *criteria, std::vector<myParticle *> * particles, std::string name, std::string basename) {
    ao->truth.insert( std::pair<string, vector<dbxTruth> >(name, (ao->truth)[basename]) );
    for(auto cutIterator=criteria->begin();cutIterator!=criteria->end();cutIterator++) {
        particles->clear();
        (*cutIterator)->getParticlesAt(particles,0);
        int ipart_max = (ao->truth)[name].size();
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
            for (int ipart=ipart_max-1; ipart>=0; ipart--){
               for (int jp=0; jp<particles->size(); jp++){
                particles->at(jp)->index=ipart;
                particles->at(jp)->collection=name;
               }
               bool ppassed=(*cutIterator)->evaluate(ao);
               if (!ppassed) (ao->truth).find(name)->second.erase( (ao->truth).find(name)->second.begin()+ipart);
            }
        }
        else {
            ValueNode abc=ValueNode();
            for (int ipart=ipart_max-1; ipart>=0; ipart--){
                particles->at(0)->index=ipart;  // 6213
                int ipart2_max;
                string base_collection2=particles->at(1)->collection;
                switch(particles->at(1)->type){
                    case 0: ipart2_max=(ao->truth)[base_collection2].size();
                        break;
		    case 10: ipart2_max=(ao->truth)[base_collection2].size();
                        break;
                    case 1: ipart2_max=(ao->eles)[base_collection2].size();
                        break;
                    case 2: ipart2_max=(ao->jets)[base_collection2].size();
                        break;
//                  case 3: ipart2_max=abc.tagJets(ao, 1).size(); //b-jets
//                      break;
//                  case 4: ipart2_max=abc.tagJets(ao, 1).size(); //light jets
//                      break;
                    case 8: ipart2_max=(ao->gams)[base_collection2].size();
                        break;
                    case 9: ipart2_max=(ao->ljets)[base_collection2].size();
                        break;
                   case 11: ipart2_max=(ao->taus)[base_collection2].size();
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
 

void createNewParti(AnalysisObjects* ao, vector<Node*> *criteria, std::vector<myParticle *> * particles, std::string name, std::string basename) {
   DEBUG("Creating new PARTITION COMBO type named:"<<name<<" previous Combo types #:"<<ao->combos.size()<<"\n"); //xxx

   vector<dbxParticle>  combination;
   dbxParticle *adbxp;
   std::string collectionName;
   int ipart_max;

   auto cutIterator=criteria->begin();
   particles->clear();
   (*cutIterator)->getParticles(particles);
    DEBUG("iCut: "<<(*cutIterator)->getStr()<<"\n");
    DEBUG("iPsize:"<<particles->size() <<"\n");

// at this point I have the particles I will use to construct the combined object. like j1 and j2
// now we find how many of those particles we have in each event
    for (int jj=0; jj<particles->size(); jj++){
       DEBUG("T:"<<particles->at(jj)->type<< " i:"<<particles->at(jj)->index<<" C:"<< particles->at(jj)->collection<<"\n");
       collectionName=particles->at(jj)->collection;
       switch(particles->at(jj)->type){
                    case 0: 
                            if ( (ao->muos).find(collectionName) == ao->muos.end() ) {
                               cout << "ERROR: "<<collectionName<<" collection is not DEFINED\n"
                                    << " Try adding:  select Size("<<collectionName<<") >= 0  to solve the problem.";
                               exit (1);
                            }
                            ipart_max=(ao->muos)[collectionName].size();
                            break;
                    case 1: 
                            if ( (ao->eles).find(collectionName) == ao->eles.end() ) {
                               cout << "ERROR: "<<collectionName<<" is not previously used in Selection.\n"
                                    << " Try adding:  select Size("<<collectionName<<") >= 0  to solve the problem.";
                               exit (1);
                            }
                            ipart_max=(ao->eles)[collectionName].size();
                            break;
		    case 10: ipart_max=(ao->truth)[collectionName].size();
                        break;
                    case 2: ipart_max=(ao->jets)[collectionName].size();
                        break;
                    case 8: ipart_max=(ao->gams)[collectionName].size();
                        break;
                    case 9: ipart_max=(ao->ljets)[collectionName].size();
                        break;
                   case 11: ipart_max=(ao->taus)[collectionName].size();
                            break;
                    default:
                        std::cerr << "WRONG PARTICLE TYPE! Type:"<<particles->at(jj)->type << std::endl;
                        break;
                }
        DEBUG("Max # particles:"<<ipart_max<<"\n");
      } //end of particle loop

//---- NANT's code to produce all the combined objetcs
    Comb combinations_part (ipart_max, particles->size());
//    combinations_part.affiche();

    vector<int> temp_index;
    vector<vector<int>> combi_out = combinations_part.output();// exemple: out  = {{0,1} , {0,2}, {1,2}} si ipart_max = 3 et particles->size() = 2
    TLorentzVector  alv;
    int apq = 0;
    
    for(size_t k=0; k<combi_out.size(); ++k) {
      temp_index = combi_out[k]; // ex temp_index = {0,1} 
      for(size_t i = 0; i<temp_index.size(); ++i){
	  DEBUG ("Now p index is:"<< temp_index[i]<<" \t"); 
	  switch(particles->at(i)->type){
	  case 0: 
	    alv+=(ao->muos)[collectionName].at(temp_index[i]).lv();
	    apq+=(ao->muos)[collectionName].at(temp_index[i]).q();
	    break;
	  case 1: 
	    alv+=(ao->eles)[collectionName].at(temp_index[i]).lv();
	    apq+=(ao->eles)[collectionName].at(temp_index[i]).q();
	    break;
	  case 10:
	    alv+=(ao->truth)[collectionName].at(temp_index[i]).lv();
	    apq+=(ao->truth)[collectionName].at(temp_index[i]).q();
	    break;
	  case 2:
	    alv+=(ao->jets)[collectionName].at(temp_index[i]).lv();
	    apq+=(ao->jets)[collectionName].at(temp_index[i]).q();
	    break;
	  case 8: alv+=(ao->gams)[collectionName].at(temp_index[i]).lv();
	    break;
	  case 9: alv+=(ao->ljets)[collectionName].at(temp_index[i]).lv();
	    apq+=(ao->ljets)[collectionName].at(temp_index[i]).q();
	    break;
	  case 11: 
	    alv+=(ao->taus)[collectionName].at(temp_index[i]).lv();
	    apq+=(ao->taus)[collectionName].at(temp_index[i]).q();
	    break;
	  default:
	    std::cerr << "WRONG PARTICLE TYPE! Type:"<<particles->at(i)->type << std::endl;
	    break;
	  }
        } 	  
// we have the combined particle AND the indices of the parents

	adbxp= new dbxParticle(alv);
	adbxp->setCharge(apq);                            
	combination.push_back(*adbxp);
	delete adbxp;
        apq=0;
        alv.SetPxPyPzE(0,0,0,0);
        DEBUG("\n");
    }
    ao->combos.insert( pair <string,vector<dbxParticle> > (name,     combination) );


//----------      
    cutIterator++; // now moving on to the real, first cut defining the new set.
    while ( cutIterator!=criteria->end() ){ // do the real cuts now.
      particles->clear();
      (*cutIterator)->getParticlesAt(particles,0);
      int ipart_max = (ao->combos)[name].size();
      bool simpleloop=true;
      DEBUG("*** Cur Cut: "<<(*cutIterator)->getStr()<<"\t Psize:"<<particles->size() <<" max_partices in event:"<<ipart_max<<"\n");
      if ( particles->size()==0) {
           DEBUG("CutIte:"<<(*cutIterator)->getStr()<<"\n");
           bool ppassed=(*cutIterator)->evaluate(ao);
           continue;
      }
      std::set<int> ptypeset;
      int t1=particles->at(0)->type;
      int tidx1=particles->at(0)->index;
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
           DEBUG("simpleloop, idx0:"<<tidx1<<"\n");
           for (int ipart=ipart_max-1; ipart>=0; ipart--){ //----------these are the combinations
               for (int jp=0; jp<particles->size(); jp++){ //
                DEBUG("p_index:"<<ipart<<" j_index:"<<jp<<" type:"<< t1<<" name:"<<name<<"\n");
                if (tidx1 < 0) {  DEBUG("******Negative INDEX !!!\t");
                   temp_index = combi_out[ ipart ];
                   particles->at(jp)->index =temp_index[abs(1+tidx1)];
                   DEBUG("new index: "<< particles->at(jp)->index  <<"\n");
                } else {
                  particles->at(jp)->index=ipart;
                  particles->at(jp)->collection=name;
                }

               }


               DEBUG("Going to evalutate\n");
               bool ppassed=(*cutIterator)->evaluate(ao);
               DEBUG("P or F:"<<ppassed<<"\n");
               if (!ppassed) (ao->combos).find(name)->second.erase( (ao->combos).find(name)->second.begin()+ipart);
            }
      } else {
           DEBUG("TWO particle loop\n");
      }

      cutIterator++;
    }// end of  cut iterator loop

   DEBUG("After addition, types #:"<<ao->combos.size()<< " \t");
   DEBUG(" added particle#:"<<(ao->combos)[name].size()<< " \n");

}

