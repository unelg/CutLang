//
//  ObjectNode.cpp
//  mm
//
//  Created by Anna-Monica  on 8/16/18.
//  Copyright © 2018 Anna-Monica. All rights reserved.
//

#include "ObjectNode.hpp"

ObjectNode::ObjectNode(string id,Node* previous, void (* func) (AnalysisObjects* ao,vector<Node*>* criteria,std::vector<myParticle *>* particles ), vector<Node*> criteria,  std::string s ){
    
    symbol=s;
    name=id;//this is useless because symbol already has name of the particle

    if(func==NULL) createNewSet=((ObjectNode*)previous)->createNewSet;
    else createNewSet=func;
    for(int i=0;i<criteria.size();i++){
        this->criteria.push_back(criteria[i]);
    }
    left=previous;
    right=NULL;
}

void ObjectNode::Reset(){
    if(left!=NULL) left->Reset();
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
    if(left!=NULL) left->evaluate(ao);//modify ao accordingly
    (*createNewSet)(ao,&criteria,&particles);//modify analysis object based on criteria here
    return 1;
}

 ObjectNode::~ObjectNode(){}

 void createNewJet (AnalysisObjects* ao,vector<Node*> *criteria,std::vector<myParticle *>* particles){
    
    for(auto cutIterator=criteria->begin();cutIterator!=criteria->end();cutIterator++){
         
         
        int ipart_max;
        ipart_max=ao->jets.size();

        particles->clear();
        (*cutIterator)->getParticlesAt(particles,0);
        if(particles->size()==1){
            for (int ipart=ipart_max-1; ipart>=0; ipart--){
                //setParticleIndex(0, ipart);----must be same as instrcution below
                particles->at(0)->index=ipart;
                bool ppassed=(*cutIterator)->evaluate(ao);
                //DEBUG("\n tested:"<<ipart<< " passed =>"<< ppassed <<"\n");
                if (!ppassed) ao->jets.erase(ao->jets.begin()+ipart);

                }
            }

        else if(particles->size()==2){
            cout<<"!!!Case of two parameter function to be implemented!!!\n";
        }
    }
}

//functions for ele,muo,etc... to be added             
