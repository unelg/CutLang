//
//  ObjectNode.cpp
//  mm
//
//  Created by Anna-Monica  on 8/16/18.
//  Copyright © 2018 Anna-Monica. All rights reserved.
//
#include "ObjectNode.hpp"

ObjectNode::ObjectNode(string id,
                       Node* previous,
                       void (* func) (AnalysisObjects* ao, vector<Node*>* criteria, std::vector<myParticle *>* particles),
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
    if(left!=NULL) {
        left->evaluate(ao);//modify ao accordingly
    }
    (*createNewSet)(ao,&criteria,&particles);//modify analysis object based on criteria here
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

void createNewJet(AnalysisObjects* ao,vector<Node*> *criteria,std::vector<myParticle *>* particles){
    for(auto cutIterator=criteria->begin();cutIterator!=criteria->end();cutIterator++){
        int ipart_max = ao->jets.size();
        particles->clear();
        (*cutIterator)->getParticlesAt(particles,0);
        
        if(particles->size()==1){ //-----------I have 1 particle set such as ELEs, JETs...
            for (int ipart=ipart_max-1; ipart>=0; ipart--){ // I have all particles, jets, in an event.
                particles->at(0)->index=ipart;             //----the index was originally 6213
                bool ppassed=(*cutIterator)->evaluate(ao);
                if (!ppassed) {
                    ao->jets.erase(ao->jets.begin()+ipart);
                }
            }
        }

        else if(particles->size()==2){
            for (int ipart=ipart_max-1; ipart>=0; ipart--){
                particles->at(0)->index=ipart;  // 6213
                int ipart2_max;
                switch(particles->at(1)->type){
                    case 0: ipart2_max=ao->muos.size();
                        break;
                    case 1: ipart2_max=ao->eles.size();
                        break;
                    case 8: ipart2_max = ao->gams.size();
                        break;
                    default:
                        std::cerr << "WRONG PARTICLE TYPE!" << std::endl;
                        break;
                }
                for (int kpart=ipart2_max-1; kpart>=0; kpart--){ 
                    particles->at(1)->index=kpart;             //6213
                    bool ppassed=(*cutIterator)->evaluate(ao);
                    if (!ppassed) {
                        ao->jets.erase(ao->jets.begin()+ipart);
                        break; // we can quit at first mismatch.
                    }
                } // end of loop over 2nd particle type

            }
        }
    } // end of cutIterator loop
}

void createNewEle(AnalysisObjects* ao, vector<Node*> *criteria, std::vector<myParticle *> * particles) {
    for(auto cutIterator=criteria->begin();cutIterator!=criteria->end();cutIterator++) {
        int ipart_max = ao->eles.size();
        particles->clear();
        (*cutIterator)->getParticlesAt(particles,0);
        
        if(particles->size()==1){
            for (int ipart=ipart_max-1; ipart>=0; ipart--){
                particles->at(0)->index=ipart;
                bool ppassed=(*cutIterator)->evaluate(ao);
                //DEBUG("\n tested:"<<ipart<< " passed =>"<< ppassed <<"\n");
                if (!ppassed) ao->eles.erase(ao->eles.begin()+ipart);
                }
            }
        
        else if(particles->size()==2){
            for (int ipart=ipart_max-1; ipart>=0; ipart--){
                particles->at(0)->index=ipart;  // 6213
                int ipart2_max;
                switch(particles->at(1)->type){
                    case 0: ipart2_max=ao->muos.size();
                        break;
                    case 2: ipart2_max=ao->jets.size();
                        break;
                    case 8: ipart2_max = ao->gams.size();
                        break;
                    default:
                        std::cerr << "WRONG PARTICLE TYPE!" << std::endl;
                        break;
                }
                for (int kpart=ipart2_max-1; kpart>=0; kpart--){
                    particles->at(1)->index=kpart;
                    bool ppassed=(*cutIterator)->evaluate(ao);
                    if (!ppassed) {
                        ao->eles.erase(ao->eles.begin()+ipart);
                        break;
                    }
                }
            }
        }
    }
}

void createNewMuo(AnalysisObjects* ao, vector<Node*> *criteria, std::vector<myParticle *> * particles) {
    for(auto cutIterator=criteria->begin();cutIterator!=criteria->end();cutIterator++) {
        int ipart_max = ao->muos.size();
        particles->clear();
        (*cutIterator)->getParticlesAt(particles,0);
        
        if(particles->size()==1){
            for (int ipart=ipart_max-1; ipart>=0; ipart--){
                particles->at(0)->index=ipart;
                bool ppassed=(*cutIterator)->evaluate(ao);
                //DEBUG("\n tested:"<<ipart<< " passed =>"<< ppassed <<"\n");
                if (!ppassed) ao->muos.erase(ao->muos.begin()+ipart);
                }
            }

        else if(particles->size()==2){
            for (int ipart=ipart_max-1; ipart>=0; ipart--){
                particles->at(0)->index=ipart;  // 6213
                int ipart2_max;
                switch(particles->at(1)->type){
                    case 1: ipart2_max=ao->eles.size();
                        break;
                    case 2: ipart2_max=ao->jets.size();
                        break;
                    case 8: ipart2_max = ao->gams.size();
                        break;
                    default:
                        std::cerr << "WRONG PARTICLE TYPE!" << std::endl;
                        break;
                }
                for (int kpart=ipart2_max-1; kpart>=0; kpart--){
                    particles->at(1)->index=kpart;
                    bool ppassed=(*cutIterator)->evaluate(ao);
                    if (!ppassed) {
                        ao->muos.erase(ao->muos.begin()+ipart);
                        break;
                    }
                }
            }
        }
    }
}
