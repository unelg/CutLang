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
    bool pval;
public:
    ValueNode(double v=0){
                value=v;
                pval=true;
                left=NULL;
                right=NULL;
                symbol=std::to_string(v);
            }
    ValueNode(std::string evtvar){
                value=0;
                left=NULL;
                right=NULL;
                pval=false;
                symbol=evtvar;
            }
    
    virtual void getParticles(std::vector<myParticle *>* particles) override{}
    virtual void getParticlesAt(std::vector<myParticle *>* particles,int index) override{}
    virtual void Reset() override{}
    virtual double evaluate(AnalysisObjects* ao) override {
        if (pval) return value;
        if (symbol=="RunYear")   return ao->evt.RunYear;
        if (symbol=="ChannelNo") return ao->evt.ChannelNo;
        if (symbol=="HFCLASSIFICATION") return ao->evt.m_HF_Classification;
        
        return ao->evt.event_no; // TO BE improved
    }
    
    virtual ~ValueNode() {}
};

#endif /* ValueNode_h */
