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
    HistoNode1D( std::string id,std::string desc, vector<float> ls, Node* l){
        this->id=id;
        Desciption=desc;
        lowerLimitx=ls[0];
        upperLimitx=ls[0];
        binsx=ls.size();
        double *xvals=(double *)malloc(binsx*sizeof(double) );
//      cout <<"~~~~~~~~~~~~~~~VARIABLE BINS~~~~~~~~~~~~\n";
        for (int jj=0; jj<binsx; jj++) {xvals[jj]=(double)ls[jj]; //cout << xvals[jj] << "\n"; 
                                       }
        symbol="histo "+id+","+Desciption+",variable bins";
        ahisto1 = new TH1D(id.data(), Desciption.data(), binsx-1, xvals);
        left=l;
        right=NULL;
        free(xvals);
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

    HistoNode2D( std::string id,std::string desc, vector<float> vx , int ny, float ymin, float ymax, Node* l, Node* r){
        this->id=id;
        Desciption=desc;
        lowerLimitx=vx[0];
        upperLimitx=vx[0];
	lowerLimity=ymin;
	upperLimity=ymax;
        binsx=vx.size();
        double *xvals=(double *)malloc(binsx*sizeof(double) );
        for (int jj=0; jj<binsx; jj++) {xvals[jj]=(double)vx[jj]; //cout << xvals[jj] << "\n"; 
                                       }
	binsy=ny;
        symbol="histo "+id+","+Desciption+",variable,"+std::to_string(ymin)+","+std::to_string(ymax)+","+std::to_string(ny);
        ahisto2 = new TH2D(id.data(), Desciption.data(), binsx-1, xvals, binsy, lowerLimity, upperLimity);
        left=l;
        right=r;
        free(xvals);
    }
    HistoNode2D( std::string id,std::string desc, int nx, float xmin, float xmax,  vector<float> vy, Node* l, Node* r){
        this->id=id;
        Desciption=desc;
        lowerLimity=vy[0];
        upperLimity=vy[0];
	lowerLimitx=xmin;
	upperLimitx=xmax;
        binsy=vy.size();
        double *yvals=(double *)malloc(binsy*sizeof(double) );
        for (int jj=0; jj<binsy; jj++) {yvals[jj]=(double)vy[jj]; //cout << yvals[jj] << "\n"; 
                                       }
	binsx=nx;
        symbol="histo "+id+","+Desciption+","+std::to_string(xmin)+","+std::to_string(xmax)+","+std::to_string(nx)+",variable";
        ahisto2 = new TH2D(id.data(), Desciption.data(), binsx, lowerLimitx, upperLimitx, binsy-1, yvals );
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
