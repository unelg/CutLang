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
class LFuncNode : public FuncNode{
private:
    double (*f2)(dbxParticle* part1,dbxParticle* part2);
    
    std::vector<myParticle*> inputParticles2;
    std::vector<myParticle> originalParticles2;
    dbxParticle myPart2;

public:
    LFuncNode(double (*func)(dbxParticle* part1,dbxParticle* part2),std::vector<myParticle*> input1,std::vector<myParticle*> input2,std::string s )
    : FuncNode(NULL,input1,s) {
        f2=func;
        inputParticles2=input2;
        myParticle apart2;
        for (int i=0; i<input2.size(); i++){
           apart2.index=input2[i]->index;
           apart2.type=input2[i]->type;
         originalParticles2.push_back(apart2);
        }
    }
    
    virtual void setParticleIndex(int order, int newIndex){
        if(order<inputParticles.size()){
            inputParticles.at(order)->index=newIndex;
        }
        else{
            inputParticles2.at(order-inputParticles.size())->index=newIndex;
        }
    }

    virtual void resetParticleIndex(){
          for(int i=0;i<originalParticles.size();i++){
                *(inputParticles[i])=originalParticles[i];

          }
          for(int i=0;i<originalParticles2.size();i++){
              *(inputParticles2[i])=originalParticles2[i];

          }
    }

    virtual std::vector<myParticle*>* getParticles(){
            return &inputParticles;
    }
    virtual double evaluate(AnalysisObjects* ao) {
        partConstruct(ao, inputParticles,&myPart);
        partConstruct(ao, inputParticles2,&myPart2);
        return (*f2)(&myPart,&myPart2);
    }
    virtual ~LFuncNode() {}
};

double dR(dbxParticle* apart,dbxParticle* apart2){
    std::cout<<"FILL THIS FUNCTION!\n";

    return 0;
}

#endif /* LFuncNode_h */
