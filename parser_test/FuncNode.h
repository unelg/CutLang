//
//  FuncNode.h
//  mm
//
//  Created by Anna-Monica  on 8/2/18.
//  Copyright © 2018 Anna-Monica. All rights reserved.
//

#ifndef FuncNode_h
#define FuncNode_h
#include <vector>
#include "myParticle.h"
#include "Node.h"
using namespace std;
//takes care of functions with arguments
class FuncNode : public Node{
private:
    double (*f)(std::vector<myParticle>);
    std::vector<myParticle> inputParticles;
public:
    FuncNode(double (*func)(std::vector<myParticle> ),std::vector<myParticle> input,  std::string s ){
        f=func;
        symbol=s;
        inputParticles=input;
        left=NULL;
        right=NULL;
    }
    
    virtual double evaluate() {
        return (*f)(inputParticles);
    }
    virtual ~FuncNode() {}
};

double MASS(vector<myParticle> v){
    double mass=0;
    for(vector<myParticle>::iterator i=v.begin();i!=v.end();i++){
        mass+=i->index;
    }
    std::cout <<" m:"<<mass<<"\t";
    return mass;
}
//other functions to be added
#endif /* FuncNode_h */
