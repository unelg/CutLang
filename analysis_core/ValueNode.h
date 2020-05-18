//
//  ValueNode.h
//  mm
//
//  Created by Anna-Monica  on 7/31/18.
//  Copyright © 2018 Anna-Monica. All rights reserved.
//

#ifndef ValueNode_h
#define ValueNode_h
#include "Node.h"
//takes care of integers and real values
class ValueNode :public Node{
private:
    double value;
public:
    ValueNode(double v=0){
                value=v;
                left=NULL;
                right=NULL;
                char buf[64];
                std::sprintf(buf, "%.2f", v);
                symbol=std::string(buf);
               // symbol=std::to_string(v);
            }
    
    virtual void getParticles(std::vector<myParticle *>* particles) override{}
    virtual void getParticlesAt(std::vector<myParticle *>* particles,int index) override{}
    virtual void Reset() override{}
    virtual double evaluate(AnalysisObjects* ao) override {
        return value;
    }
    
    virtual ~ValueNode() {}
};

#endif /* ValueNode_h */
