//
//  LFuncNode.h
//  mm
//
//  Created by Anna-Monica  on 8/2/18.
//  Copyright © 2018 Anna-Monica. All rights reserved.
//

#ifndef LFuncNode_h
#define LFuncNode_h
#include <vector>
#include "myParticle.h"
#include "Node.h"
using namespace std;
//takes care of functions with arguments
class LFuncNode : public Node{
private:
    double (*f)(std::vector<myParticle>,std::vector<myParticle>);
    std::vector<myParticle> inputParticles1;
    std::vector<myParticle> inputParticles2;
public:
    LFuncNode(double (*func)(std::vector<myParticle>,std::vector<myParticle> ),std::vector<myParticle> input1,std::vector<myParticle> input2,std::string s ){
        f=func;
        symbol=s;
        inputParticles1=input1;
        inputParticles2=input2;
        left=NULL;
        right=NULL;
    }
    
    virtual double evaluate() {
        return (*f)(inputParticles1,inputParticles2);
    }
    virtual ~LFuncNode() {}
};

double dR(vector<myParticle> v,vector<myParticle> w){
    double mass1=0;
    for(vector<myParticle>::iterator i=v.begin();i!=v.end();i++){
        mass1+=i->index;
    }
    double mass2=0;
    for(vector<myParticle>::iterator i=w.begin();i!=w.end();i++){
        mass2+=i->index;
    }

    return mass1-mass2;
}

#endif /* LFuncNode_h */
