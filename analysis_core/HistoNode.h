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
    float lowerLimitx;
    float upperLimitx;
    float lowerLimity;
    float upperLimity;
    int binsx;
    int binsy;
    int dim = 1;
    TH1D *ahisto1;
    TH2D *ahisto2;

public:

    HistoNode( std::string id,std::string desc,int nx, float xmin, float xmax, int ny, float ymin, float ymax, Node* l, Node* r){
        this->id=id;
        Desciption=desc;
        lowerLimitx=xmin;
        upperLimitx=xmax;
	lowerLimity=ymin;
	upperLimity=ymax;
        binsx=nx;
	binsy=ny;
        symbol="histo "+id+","+Desciption+","+std::to_string(xmin)+","+std::to_string(xmax)+","+std::to_string(nx)+","+std::to_string(ymin)+","+std::to_string(ymax)+","+std::to_string(ny);
        ahisto2 = new TH2D(id.data(), Desciption.data(), binsx, lowerLimitx, upperLimitx, binsy, lowerLimity, upperLimity);
	ahisto1 = NULL;
        left=l;
        right=r;
	dim = 2;
    }

    HistoNode( std::string id,std::string desc,int n, float l1, float l2,Node* l){
        this->id=id;
        Desciption=desc;
        lowerLimitx=l1;
        upperLimitx=l2;
        binsx=n;
        symbol="histo "+id+","+Desciption+","+std::to_string(l1)+","+std::to_string(l2)+","+std::to_string(n);
        ahisto1 = new TH1D(id.data(), Desciption.data(), binsx, lowerLimitx, upperLimitx);
	ahisto2 = NULL;
        left=l;
        right=NULL;
    }

    virtual void Reset() override{
    }

    virtual void getParticles(std::vector<myParticle *>* particles) override{
    }
    virtual void getParticlesAt(std::vector<myParticle *>* particles, int index) override{}
    virtual double evaluate(AnalysisObjects* ao) override {
        if (dim == 1)
		{
                      double value = left->evaluate(ao);
		      ahisto1->Fill(value, ao->evt.user_evt_weight);
		      return 1;
		}
	else
		{
		      double value1=left->evaluate(ao);
		      double value2=right->evaluate(ao);
        	      ahisto2->Fill(value1, value2, ao->evt.user_evt_weight);
        	      return 1;
		}
    }
    virtual ~HistoNode() {
        if (left!=NULL) delete left;
	if (right!=NULL) delete right;
    }
    
};

#endif /* HistoNode_h */
