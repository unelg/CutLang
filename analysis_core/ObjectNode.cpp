//
//  ObjectNode.cpp
//  mm
//
//  Created by Anna-Monica  on 8/16/18.
//  Copyright © 2018 Anna-Monica. All rights reserved.
//
#include "ObjectNode.hpp"
#include "ValueNode.h"

ObjectNode::ObjectNode(std::string id,
                       Node* previous,
                       void (* func) (AnalysisObjects* ao, vector<Node*>* criteria, std::vector<myParticle *>* particles, std::string  name, std::string basename),
                       vector<Node*> criteria,
                       std::string s) {

    symbol=s;
    name=id;//this is useless because symbol already has name of the particle

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

    std::cout<<" I search:\n";
    ObjectNode* anode=(ObjectNode*)previous; 
    if (anode != NULL){
    while (anode->left != NULL) { cout<<".\n"; anode=(ObjectNode*)anode->left; }
      if (anode->name == "JET" ) type=2;
      if (anode->name == "MUO" ) type=0;
      if (anode->name == "ELE" ) type=1;
    std::cout<<" I found:" << anode->name<<" t:"<<type<<"\n";
    } else {
      if (id == "JET" ) type=2;
      if (id == "MUO" ) type=0;
      if (id == "ELE" ) type=1;
      std::cout<<" I have:"<<id<<" t:"<<type<<"\n";
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

}

double ObjectNode::evaluate(AnalysisObjects* ao){
    //test if the AO thing not null=> then avoid function call
    cout <<"In ObjNode Eval #JETt:"<< ao->jets.size() <<" working for:"<<name << "  type:"<<type<<"\n";
 
    std::string basename="xxx";
    while(left!=NULL) {
      
      ObjectNode* anode=(ObjectNode*)left;
      cout << "previous:"<<anode->name<<"\n";
// is it in the map list?
       basename=anode->name;
       if (ao->jets.find(basename)==ao->jets.end()  ){
 			cout << basename<<" is not computed\n";    
       			anode->evaluate(ao);
                        cout << "evaluated.\n";
       } else break;
       anode=(ObjectNode*)anode->left;
      }
      
    cout <<"before new set #JETtypes:"<< ao->jets.size()<< "#particles:"<< particles.size()<<"\n";

    (*createNewSet)(ao,&criteria,&particles, name, basename);//modify analysis object based on criteria here
    cout <<"After new set #JETtypes:"<< ao->jets.size() <<"\n"; 
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

void createNewJet(AnalysisObjects* ao,vector<Node*> *criteria,std::vector<myParticle *>* particles, std::string name, std::string basename){
    cout << "Creating new JETtype named:"<<name<<" #Jtypes:"<<ao->jets.size()<<"\n";
    int dodo=0;

    cout << "Duplicating:"<<basename<<"\n";
    ao->jets.insert( std::pair<string, vector<dbxJet> >(name, (ao->jets)[basename]) );
    for(auto cutIterator=criteria->begin();cutIterator!=criteria->end();cutIterator++){
        cout <<"JET DODO:"<<dodo<<"\n";
        dodo++;
        particles->clear();
        (*cutIterator)->getParticlesAt(particles,0);
//--------get the string name from the particles, as base collection, the new name is in "name"
        int ipart_max = (ao->jets)[name].size();

        cout << "size before loop:"<< ipart_max<<"\n";
        if(particles->size()==1){                            //-----------I have 1 particle set such as ELEs, JETs...
            for (int ipart=ipart_max-1; ipart>=0; ipart--){ // I have all particles, jets, in an event.
                particles->at(0)->index=ipart;             //----the index was originally 6213
                particles->at(0)->collection=name;             
                cout << "before cutIterator:"<<(*cutIterator)->getStr()<<" \n";
                bool ppassed=(*cutIterator)->evaluate(ao);
                cout << "after cutIterator evalutate\n";
                if (!ppassed) (ao->jets).find(name)->second.erase( (ao->jets).find(name)->second.begin()+ipart);
                cout << "maybe removed\n";
            }
        }
        else if(particles->size()==2){
            ValueNode abc=ValueNode();
            for (int ipart=ipart_max-1; ipart>=0; ipart--){
                particles->at(0)->index=ipart;  // 6213
                int ipart2_max;
                string base_collection2=particles->at(1)->collection;
                switch(particles->at(1)->type){
                    case 0: ipart2_max=(ao->muos)[base_collection2].size();
                        break;
                    case 1: ipart2_max=(ao->eles)[base_collection2].size();
                        break;
                    case 2: ipart2_max=(ao->jets)[base_collection2].size();
                        break;
//                    case 3: ipart2_max=abc.tagJets(ao, 1).size(); //b-jets
//                        break;
//                    case 4: ipart2_max=abc.tagJets(ao, 1).size(); //light jets
//                        break;
                    case 8: ipart2_max=(ao->gams)[base_collection2].size();
                        break;
                    default:
                        std::cerr << "WRONG PARTICLE TYPE! Try Jets:"<<particles->at(1)->type << std::endl;
                        break;
                }
                for (int kpart=ipart2_max-1; kpart>=0; kpart--){ 
                    particles->at(1)->index=kpart;             //6213
                    bool ppassed=(*cutIterator)->evaluate(ao);
                    if (!ppassed) {
                        (ao->jets).find(name)->second.erase( (ao->jets).find(name)->second.begin()+ipart);
                        break; // we can quit at first mismatch.
                    }
                } // end of loop over 2nd particle type
            } // loop over 1st particle type
        }
    } // end of cutIterator loop
   cout<<"created\n";
}

void createNewEle(AnalysisObjects* ao, vector<Node*> *criteria, std::vector<myParticle *> * particles, std::string name, std::string basename) {
    cout << "Creating new ELE obj now\n";
    for(auto cutIterator=criteria->begin();cutIterator!=criteria->end();cutIterator++) {
        particles->clear();
        (*cutIterator)->getParticlesAt(particles,0);
        ao->eles.insert( std::pair<string, vector<dbxElectron> >(name, (ao->eles)[basename]) );
        int ipart_max = (ao->jets)[basename].size();

        if(particles->size()==1){
            for (int ipart=ipart_max-1; ipart>=0; ipart--){
                particles->at(0)->index=ipart;
                bool ppassed=(*cutIterator)->evaluate(ao);
                if (!ppassed) (ao->eles).find(name)->second.erase( (ao->eles).find(name)->second.begin()+ipart);
                }
            }
        
        else if(particles->size()==2){
            ValueNode abc=ValueNode();
            for (int ipart=ipart_max-1; ipart>=0; ipart--){
                particles->at(0)->index=ipart;  // 6213
                int ipart2_max;
                string base_collection2=particles->at(1)->collection;
                switch(particles->at(1)->type){
                    case 0: ipart2_max=(ao->muos)[base_collection2].size();
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
                    default:
                        std::cerr << "WRONG PARTICLE TYPE! Try ELE:"<<particles->at(1)->type << std::endl;
                        break;
                }
                for (int kpart=ipart2_max-1; kpart>=0; kpart--){
                    particles->at(1)->index=kpart;
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
    for(auto cutIterator=criteria->begin();cutIterator!=criteria->end();cutIterator++) {
        particles->clear();
        (*cutIterator)->getParticlesAt(particles,0);
        string base_collection=particles->at(0)->collection;
        ao->muos.insert( std::pair<string, vector<dbxMuon> >(name, (ao->muos)[basename]) );
        int ipart_max = (ao->muos)[basename].size();
        
        if(particles->size()==1){
            for (int ipart=ipart_max-1; ipart>=0; ipart--){
                particles->at(0)->index=ipart;
                bool ppassed=(*cutIterator)->evaluate(ao);
                if (!ppassed) (ao->muos).find(name)->second.erase( (ao->muos).find(name)->second.begin()+ipart);
                }
            }

        else if(particles->size()==2){
            ValueNode abc=ValueNode();
            for (int ipart=ipart_max-1; ipart>=0; ipart--){
                particles->at(0)->index=ipart;  // 6213
                int ipart2_max;
                string base_collection2=particles->at(1)->collection;
                switch(particles->at(1)->type){
                    case 0: ipart2_max=(ao->muos)[base_collection2].size();
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
                    default:
                        std::cerr << "WRONG PARTICLE TYPE! Try MUO:"<<particles->at(1)->type << std::endl;
                        break;
                }
                for (int kpart=ipart2_max-1; kpart>=0; kpart--){
                    particles->at(1)->index=kpart;
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
    for(auto cutIterator=criteria->begin();cutIterator!=criteria->end();cutIterator++) {
        particles->clear();
        (*cutIterator)->getParticlesAt(particles,0);
        ao->gams.insert( std::pair<string, vector<dbxPhoton> >(name, (ao->gams)[basename]) );
        int ipart_max = (ao->gams)[basename].size();
        
        if(particles->size()==1){
            for (int ipart=ipart_max-1; ipart>=0; ipart--){
                particles->at(0)->index=ipart;
                bool ppassed=(*cutIterator)->evaluate(ao);
                if (!ppassed) (ao->gams).find(name)->second.erase( (ao->gams).find(name)->second.begin()+ipart);
                }
            }

        else if(particles->size()==2){
            ValueNode abc=ValueNode();
            for (int ipart=ipart_max-1; ipart>=0; ipart--){
                particles->at(0)->index=ipart;  // 6213
                int ipart2_max;
                string base_collection2=particles->at(1)->collection;
                switch(particles->at(1)->type){
                    case 0: ipart2_max=(ao->muos)[base_collection2].size();
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
                    default:
                        std::cerr << "WRONG PARTICLE TYPE! Try PHO:"<<particles->at(1)->type << std::endl;
                        break;
                }
                for (int kpart=ipart2_max-1; kpart>=0; kpart--){
                    particles->at(1)->index=kpart;
                    bool ppassed=(*cutIterator)->evaluate(ao);
                    if (!ppassed) {
                        (ao->gams).find(name)->second.erase( (ao->gams).find(name)->second.begin()+ipart);
                        break;
                    }
                } // second particle set
            }// first particle set
        }// end of two particles
    }// end of cutIterator
}
