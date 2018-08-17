//
//  ObjectNode.hpp
//  mm
//
//  Created by Anna-Monica  on 8/16/18.
//  Copyright © 2018 Anna-Monica. All rights reserved.
//

#ifndef ObjectNode_hpp
#define ObjectNode_hpp
#include <vector>
#include <stdio.h>
#include "Node.h"
using namespace std;
//takes care of user defined objects
class ObjectNode : public Node{
private:
    //not sure if we need to use it---------ObjectNode* previous;
    //vector<dbxParticle> newParticles;
    vector<Node*> criteria;
    
public:
    ObjectNode(ObjectNode* previous,vector<Node*> criteria,  std::string s );
    
    virtual void Reset() override;
    
    virtual void getParticles(std::vector<myParticle *>* particles) override;
    
    virtual double evaluate(AnalysisObjects* ao) override;
    
    virtual ~ObjectNode();
};
#endif /* ObjectNode_hpp */
