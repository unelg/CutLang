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
     condition->getParticles(particles);
    }

    virtual void getParticlesAt(std::vector<myParticle *>* particles, int index) override{
     condition->getParticlesAt(particles, index);
    }

    virtual void Reset() override{
    }
    
    virtual double evaluate(AnalysisObjects* ao) override{
/*
           std::vector<myParticle *>  bparticles;
           std::vector<myParticle *> *aparticles=&bparticles;
           cout <<"\nCL:"<<(this)->left->getStr()<<"\n";
           cout <<"CR:"<<(this)->right->getStr()<<"\n";
           (this)->left->getParticlesAt(aparticles,0);
           cout <<"B condition CL of "<<aparticles->size()<<" \t T:"<< aparticles->at(0)->type <<
                              " I:"<< aparticles->at(0)->index << " C:"<< aparticles->at(0)->collection << "\n";

           aparticles->clear();
           (this)->right->getParticlesAt(aparticles,0);
           cout <<"B condition CR of "<<aparticles->size()<<" \t T:"<< aparticles->at(0)->type <<
                              " I:"<< aparticles->at(0)->index << " C:"<< aparticles->at(0)->collection << "\n";
*/

        double testResult=condition->evaluate(ao);
/*
           cout <<"~~~~~condition evaluted as:"<<testResult<<"\n";
           aparticles->clear();
           (this)->left->getParticlesAt(aparticles,0);
           cout <<"A condition CL of "<<aparticles->size()<<" \t T:"<< aparticles->at(0)->type <<
                              " I:"<< aparticles->at(0)->index << " C:"<< aparticles->at(0)->collection << "\n";

           aparticles->clear();
           (this)->right->getParticlesAt(aparticles,0);
           cout <<"A condition CR of "<<aparticles->size()<<" \t T:"<< aparticles->at(0)->type <<
                              " I:"<< aparticles->at(0)->index << " C:"<< aparticles->at(0)->collection << "\n";
*/
        if ((bool) testResult) {
           return left->evaluate(ao);
        } else {                  
           return right->evaluate(ao);
        }
    }
    virtual ~IfNode() {}
};

#endif /* IfNode_h */
