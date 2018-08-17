//
//  IfNode.h
//  mm
//
//  Created by Anna-Monica  on 8/14/18.
//  Copyright © 2018 Anna-Monica. All rights reserved.
//

#ifndef IfNode_h
#define IfNode_h
#include "Node.h"
using namespace std;
//takes care of If statements
class IfNode : public Node{
private:
    Node * condition;
public:
    IfNode(Node* c,Node* l, Node* r,  std::string s ){
        
        symbol=s;
        condition=c;
        left=l;
        right=r;
        
    }
    
    virtual void getParticles(std::vector<myParticle *>* particles) override{
    }

    virtual void getParticlesAt(std::vector<myParticle *>* particles, int index) override{

    }
    virtual void Reset() override{
    }
    
    virtual double evaluate(AnalysisObjects* ao) override{
        double testResult=condition->evaluate(ao);
        if((bool) testResult) return left->evaluate(ao);
        else return right->evaluate(ao);
    }
    virtual ~IfNode() {}
};

#endif /* IfNode_h */
