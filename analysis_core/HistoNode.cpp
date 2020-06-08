#include "HistoNode.h"


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
    
