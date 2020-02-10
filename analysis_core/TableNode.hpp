//
//  TableNode.hpp
//  mm
//
//  Created by ngu  on Oct19.
//  Copyright © 2019 . All rights reserved.
//

#ifndef TableNode_hpp
#define TableNode_hpp

#include <stdio.h>
#include <math.h>
#include "Node.h"
//takes care of Table Operations
class TableNode : public Node{
private:
    double (*f)(double, AnalysisObjects* );
    std::vector<float> atable;

public:
    TableNode(double (*func)(double, AnalysisObjects*), 
              Node* l, std::vector<float> at, std::string s){
        f=func;
        symbol=s;
        left=l;
        atable=at;
        right=NULL;
    }

    virtual void getParticles(std::vector<myParticle *>* particles) override{
        left->getParticles(particles);
    }

    virtual void getParticlesAt(std::vector<myParticle *>* particles,int index) override{
        left->getParticlesAt(particles,index);
    }
    virtual void Reset() override{
        left->Reset();
    }
    virtual double evaluate(AnalysisObjects* ao) override{
            double aval=left->evaluate(ao);
// find the range
            double tval; 
            bool range_found=false;
            for (int it=0; it<atable.size(); it+=3){ // 3 is for 1D only. value, min, max.
             if ( aval>=atable[it+1] && aval<atable[it+2]){
              range_found=true;
              tval=atable[it];
//              std::cout << "aval:"<<aval<<" tval:"<<tval<<"\n";
              break;
             } 
            }
            if (!range_found) {std::cout << "Specified value "<< aval <<" is out of table range! Setting to ZERO.\n"; tval=0;}
            return (*f)(tval, ao);
    }
    virtual ~TableNode() {
    }

};

double tweight(double value, AnalysisObjects* ao ) {
    ao->evt.user_evt_weight *= value;
    return 1;
}

#endif /* TableNode */
