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
//takes care of functions with arguments
class FuncNode : public Node{
private:
        double (*f)(dbxParticle* apart);
        float v_eta;
        TLorentzVector ametlv;
        Node* userObjectA;
        Node* userObjectB;
        Node* userObjectC;
        Node* userObjectD;


protected:
    std::vector<myParticle*> inputParticles;
    std::vector<myParticle> originalParticles;
    dbxParticle myPart;

    virtual void ResetParticles();
    void partConstruct(AnalysisObjects *ao, std::vector<myParticle*> *input, dbxParticle* inputPart);
    virtual void setParticleIndex(int order, int newIndex);

public:
    FuncNode(double (*func)(dbxParticle* apart ),std::vector<myParticle*> input,  std::string s,  
             Node *objectNodea = NULL, std::string as="", Node *objectNodeb = NULL, Node *objectNodec = NULL, Node *objectNoded = NULL);
    virtual void Reset() override;
    virtual void getParticles(std::vector<myParticle *>* particles) override;
    virtual void getParticlesAt(std::vector<myParticle *>* particles, int index) override;
    virtual void setUserObjects(Node *objectNodea = NULL, Node *objectNodeb = NULL, Node *objectNodec = NULL, Node *objectNoded = NULL);
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
