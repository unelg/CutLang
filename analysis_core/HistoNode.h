//
//  HistoNode.h
//  mm
//
//  Created by Anna-Monica  on 8/6/18.
//  Copyright © 2018 Anna-Monica. All rights reserved.
//

#ifndef HistoNode_h
#define HistoNode_h
#include "Node.h"
#include <string>
#include "TH1F.h"
#include "TH2F.h"

class HistoNode : public Node{
private:
    std::string id;
    std::string Desciption;
    int lowerLimit;
    int upperLimit;
    int bins;
    TH1D *ahisto;
public:
    HistoNode( std::string id, std::string desc, int n, int l1, int l2, Node* l){
        this->id=id;
        Desciption=desc;
        lowerLimit=l1;
        upperLimit=l2;
        bins=n;
        symbol="histo "+id+","+Desciption+","+std::to_string(l1)+","+std::to_string(l2)+","+std::to_string(n);
        ahisto = new TH1D(id.data(), Desciption.data(), bins, lowerLimit, upperLimit);
        left=l;
        right=NULL;
    }

    virtual void Reset() override{
    }

    virtual void getParticles(std::vector<myParticle *>* particles) override{
    }
    virtual void getParticlesAt(std::vector<myParticle *>* particles, int index) override{}
    virtual double evaluate(AnalysisObjects* ao) override {
        double value=left->evaluate(ao);
        ahisto->Fill(value, 1.);
        return 1;
    }
    virtual ~HistoNode() {
        if (left!=NULL) delete left;
    }
    
};

#endif /* HistoNode_h */
