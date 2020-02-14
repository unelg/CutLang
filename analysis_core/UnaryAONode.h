//
//  UnaryAONode.h
//  mm
//
//  Created by Anna-Monica  on 8/1/18.
//  Copyright © 2018 Anna-Monica. All rights reserved.
//

#ifndef UnaryAONode_h
#define UnaryAONode_h
#include "Node.h"
//takes care of Unary Minus and other Math.h functions
class UnaryAONode : public Node{
private:
    double (*f)(double);
public:
    UnaryAONode(double (*func)(double), Node* l, std::string s){
        f=func;
        symbol=s;
        left=l;
        right=NULL;
    }
    
    virtual void getParticles(std::vector<myParticle *>* particles) override{
         left->getParticles(particles);
    }

    virtual void getParticlesAt(std::vector<myParticle *>* particles, int index) override{
        left->getParticlesAt(particles,index);
    }

    virtual void Reset() override{
        left->Reset();
    }

    virtual double evaluate(AnalysisObjects* ao) override {
        return (*f)(left->evaluate(ao));
    }
    
    virtual ~UnaryAONode() {
        if (left!=NULL) delete left;
    }
    
};
double unaryMinu(double left) {
    return -left;
}
double hstep(double x){
	if(x>=0) {return 1;}
	else return 0;
}

//double COS SIN TAN ALREADY EXIST
#endif /* UnaryAONode_h */
