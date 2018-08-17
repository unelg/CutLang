//
//  ObjectNode.cpp
//  mm
//
//  Created by Anna-Monica  on 8/16/18.
//  Copyright © 2018 Anna-Monica. All rights reserved.
//

#include "ObjectNode.hpp"

ObjectNode::ObjectNode(ObjectNode* previous,vector<Node*> criteria,  std::string s ){
    
    symbol=s;
    for(int i=0;i<criteria.size();i++){
        this->criteria.push_back(criteria[i]);
    }
    left=previous;
    right=NULL;
}

void ObjectNode::Reset(){
    left->Reset();
    for(auto it=criteria.begin();it!=criteria.end();it++){
        (*it)->Reset();
    }
}

void ObjectNode::getParticles(std::vector<myParticle *>* particles){
    cout<<"Calling get particles on ObjectNode-----doing nothing\n";
}

double ObjectNode::evaluate(AnalysisObjects* ao){
    left->evaluate(ao);//modify ao accordingly
    //construct based on criteria here
    return 1;
}

 ObjectNode::~ObjectNode(){}
