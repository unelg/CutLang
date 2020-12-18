#ifndef HistoNode_h
#define HistoNode_h

#include "Node.h"
#include <string>
#include "TH1F.h"
#include "TH2F.h"

using namespace std;

class HistoNode1D : public Node{
private:
    std::string id;
    std::string Desciption;
    float lowerLimitx;
    float upperLimitx;
    int binsx;
    TH1D *ahisto1;
    std::vector<myParticle*> inputParticles;

public:
    HistoNode1D( std::string id,std::string desc,int n, float l1, float l2,Node* l){
        this->id=id;
        Desciption=desc;
        lowerLimitx=l1;
        upperLimitx=l2;
        binsx=n;
        symbol="histo "+id+","+Desciption+","+std::to_string(l1)+","+std::to_string(l2)+","+std::to_string(n);
        ahisto1 = new TH1D(id.data(), Desciption.data(), binsx, lowerLimitx, upperLimitx);
        left=l;
        right=NULL;
    }
virtual void Reset() override{ left->Reset(); } 

virtual void getParticles(std::vector<myParticle *>* particles) override{
         left->getParticles(particles);
    }
virtual void getParticlesAt(std::vector<myParticle *>* particles, int index) override{}
double evaluate(AnalysisObjects* ao) override;
virtual ~HistoNode1D(){
  if (left!=NULL) delete left;
	if (right!=NULL) delete right;
}

};
//----------------------------------------------------------------
class HistoNode2D : public Node{
private:
    std::string id;
    std::string Desciption;
    float lowerLimitx;
    float upperLimitx;
    float lowerLimity;
    float upperLimity;
    int binsx;
    int binsy;
    TH2D *ahisto2;
    std::vector<myParticle*> inputParticles;

public:
    HistoNode2D( std::string id,std::string desc,int nx, float xmin, float xmax, int ny, float ymin, float ymax, Node* l, Node* r){
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
        left=l;
        right=r;
    }
virtual void Reset() override{ left->Reset(); } 

virtual void getParticles(std::vector<myParticle *>* particles) override{
         left->getParticles(particles);
    }
virtual void getParticlesAt(std::vector<myParticle *>* particles, int index) override{}
double evaluate(AnalysisObjects* ao) override;
virtual ~HistoNode2D(){
  if (left!=NULL) delete left;
	if (right!=NULL) delete right;
}

};

#endif
