//
//  LFuncNode.h
//  mm
//
//  Created by Anna-Monica  on 8/2/18.
//  Copyright © 2018 Anna-Monica. All rights reserved.
//

#ifndef LFuncNode_h
#define LFuncNode_h
#include <vector>
#include "myParticle.h"
#include "FuncNode.h"
using namespace std;
//takes care of functions with two arguments
class LFuncNode : public FuncNode{
private:
    double (*f2)(dbxParticle* part1,dbxParticle* part2);
    Node* userObjectA;
    Node* userObjectB;
    Node* userObjectC;
    Node* userObjectD;

    std::vector<myParticle*> inputParticles2;
    std::vector<myParticle> originalParticles2;
    dbxParticle myPart2;

    friend class LoopNode;

protected:
    virtual void ResetParticles() override;
    virtual void setParticleIndex(int order, int newIndex) override;

public:
    LFuncNode(double (*func)(dbxParticle* part1,dbxParticle* part2),std::vector<myParticle*> input1,std::vector<myParticle*> input2,std::string s,
              Node *objectNodea = NULL, Node *objectNodeb = NULL, Node *objectNodec = NULL, Node *objectNoded = NULL);
    virtual void getParticles(std::vector<myParticle *>* particles) override;
    virtual void getParticlesAt(std::vector<myParticle *>* particles, int index) override;
    virtual double evaluate(AnalysisObjects* ao)  override;
    virtual void setUserObjects(Node *objectNodea = NULL, Node *objectNodeb = NULL, Node *objectNodec = NULL, Node *objectNoded = NULL);
    virtual ~LFuncNode() ;
};

double dR  (dbxParticle* apart,dbxParticle* apart2);
double dPhi(dbxParticle* apart,dbxParticle* apart2);
double dEta(dbxParticle* apart,dbxParticle* apart2);
#endif /* LFuncNode_h */
