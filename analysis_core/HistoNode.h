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
    };

#endif

