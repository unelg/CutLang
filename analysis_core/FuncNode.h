//
//  FuncNode.h
//  mm -=-=-=-=
//
//  Created by Anna-Monica  on 8/2/18.
//  Copyright © 2018 Anna-Monica. All rights reserved.
//

#ifndef FuncNode_h
#define FuncNode_h
#include <vector>
#include "myParticle.h"
#include "Node.h"

using namespace std;
//#define _CLV_

#ifdef _CLV_
#define DEBUG(a) std::cout<<a
#else
#define DEBUG(a)
#endif
using namespace std;
//takes care of functions with arguments
class FuncNode : public Node{
private:
        double (*f)(dbxParticle* apart);
        float v_eta;
        TLorentzVector ametlv;

protected:
    
    std::vector<myParticle*> inputParticles;
    std::vector<myParticle> originalParticles;
    dbxParticle myPart;

    virtual void ResetParticles();
    
    void partConstruct(AnalysisObjects *ao, std::vector<myParticle*> *input, dbxParticle* inputPart);

    virtual void setParticleIndex(int order, int newIndex);

    virtual int getParticleIndex(int order);

public:
    FuncNode(double (*func)(dbxParticle* apart ),std::vector<myParticle*> input,  std::string s );
    
    virtual void Reset() override;

    virtual void getParticles(std::vector<myParticle *>* particles) override;

    virtual double evaluate(AnalysisObjects* ao) override;

    virtual ~FuncNode();
};


double Qof( dbxParticle* apart);

double Mof( dbxParticle* apart);

double Eof( dbxParticle* apart);

double Pof( dbxParticle* apart);

double Pzof( dbxParticle* apart);
double Ptof( dbxParticle* apart);

double AbsEtaof( dbxParticle* apart);

double Etaof( dbxParticle* apart);

double Phiof( dbxParticle* apart);

double nbfof( dbxParticle* apart);
//other functions to be added
#endif /* FuncNode_h */
