//
//  SFuncNode.h
//  mm
//
//  Created by Anna-Monica  on 8/2/18.
//  Copyright © 2018 Anna-Monica. All rights reserved.
//

#ifndef SFuncNode_h
#define SFuncNode_h
#include "Node.h"
using namespace std;
//takes care of functions with arguments
class SFuncNode : public Node{
private:
    //should add something related to trigger types
    double (*f)(AnalysisObjects* ao);
public:
    SFuncNode(double (*func)(AnalysisObjects* ao),  std::string s ){
        f=func;
        symbol=s;
        left=NULL;
        right=NULL;
    }
    
    virtual double evaluate(AnalysisObjects* ao) {
        return (*f)(ao);
    }
    virtual ~SFuncNode() {}
};

double all(AnalysisObjects* ao){
    return 1;
}

double njets(AnalysisObjects* ao){
    return (ao->jets.size() );
}
double neles(AnalysisObjects* ao){
    return (ao->eles.size() );
}
double nmuos(AnalysisObjects* ao){
    return (ao->muos.size() );
}
double nphos(AnalysisObjects* ao){
    return (ao->gams.size() );
}

#endif /* SFuncNode_h */
