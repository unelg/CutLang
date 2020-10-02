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
#include "ObjectNode.hpp"

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

        friend class HistoNode1D;
        friend class HistoNode2D;
        friend class LoopNode;
        friend class TableNode;
protected:
    std::vector<myParticle*> inputParticles;
    std::vector<myParticle> originalParticles;
    dbxParticle myPart;

    virtual void ResetParticles();
    void partConstruct(AnalysisObjects *ao, std::vector<myParticle*> *input, dbxParticle* inputPart);
    virtual void setParticleIndex(int order, int newIndex);
    virtual void setParticleType(int order, int newType);
    virtual void setParticleCollection(int order, string newName);

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


double      Qof( dbxParticle* apart);
double      Mof( dbxParticle* apart);
double      Eof( dbxParticle* apart);
double      Pof( dbxParticle* apart);
double     Pzof( dbxParticle* apart);
double     Ptof( dbxParticle* apart);
double AbsEtaof( dbxParticle* apart);
double    Etaof( dbxParticle* apart);
double    Rapof( dbxParticle* apart);
double    Phiof( dbxParticle* apart);
double 	pdgIDof( dbxParticle* apart);
double MsoftDof( dbxParticle* apart);
double  DeepBof( dbxParticle* apart);
double   isBTag( dbxParticle* apart);
double isTauTag( dbxParticle* apart);
double   tau1of( dbxParticle* apart);
double   tau2of( dbxParticle* apart);
double   tau3of( dbxParticle* apart);
double    dxyof( dbxParticle* apart);
double     dzof( dbxParticle* apart);
double     vxof( dbxParticle* apart);
double     vyof( dbxParticle* apart);
double     vzof( dbxParticle* apart);
double     vtof( dbxParticle* apart);
double    vtrof( dbxParticle* apart);
double relisoof( dbxParticle* apart);
double relisoallof( dbxParticle* apart);
double pfreliso03allof( dbxParticle* apart);
double iddecaymodeof( dbxParticle* apart);
double idisotightof( dbxParticle* apart);
double idantieletightof( dbxParticle* apart);
double idantimutightof( dbxParticle* apart);
double tightidof( dbxParticle* apart);
double    puidof( dbxParticle* apart);
double genpartidxof( dbxParticle* apart);
double decaymodeof( dbxParticle* apart);
double tauisoof( dbxParticle* apart);
double softIdof( dbxParticle* apart);
double CCountof( dbxParticle* apart);
double    nbfof( dbxParticle* apart);

//other functions to be added
#endif /* FuncNode_h */
