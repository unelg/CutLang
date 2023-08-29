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
#include "CLTTReader.h"

using namespace std;




//takes care of functions with arguments
class FuncNode : public Node{
private:
        double (*f)(dbxParticle* apart);
        float v_eta;
        bool special_function;
        TLorentzVector ametlv;
        Node* userObjectA;
        Node* userObjectB;
        Node* userObjectC;
        Node* userObjectD;

        TTreeReader *m_ttreader;

        myTTreader *ttrdr;
        myTTreaderF *ttrdrF;
        myTTreaderD *ttrdrD;
        myTTreaderB *ttrdrB;
        myTTreaderI *ttrdrI;
	myTTreaderC *ttrdrC;

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

    void setTTRaddr( TTreeReader *ttr, string s);
    virtual void Reset() override;
    virtual void getParticles(std::vector<myParticle *>* particles) override;
    virtual void getParticlesAt(std::vector<myParticle *>* particles, int index) override;
    virtual void setUserObjects(Node *objectNodea = NULL, Node *objectNodeb = NULL, Node *objectNodec = NULL, Node *objectNoded = NULL) override;
    virtual double evaluate(AnalysisObjects* ao) override;
    virtual ~FuncNode();
};


double      specialf( dbxParticle* apart);
double      Qof( dbxParticle* apart);
double      Mof( dbxParticle* apart);
double      Eof( dbxParticle* apart);
double      Pof( dbxParticle* apart);
double     Pzof( dbxParticle* apart);
double     Ptof( dbxParticle* apart);
double PtConeof( dbxParticle* apart);
double EtConeof( dbxParticle* apart);
double AbsEtaof( dbxParticle* apart);
double    Etaof( dbxParticle* apart);
double    Rapof( dbxParticle* apart);
double    Phiof( dbxParticle* apart);
double 	pdgIDof( dbxParticle* apart);
double flavorof( dbxParticle* apart);
double   isBTag( dbxParticle* apart);
double isTauTag( dbxParticle* apart);
double isTight ( dbxParticle* apart);
double isMedium( dbxParticle* apart);
double isLoose ( dbxParticle* apart);
double genpartidxof( dbxParticle* apart);

double    dxyof( dbxParticle* apart);
double   edxyof( dbxParticle* apart);
double     dzof( dbxParticle* apart);
double    edzof( dbxParticle* apart);
double     vxof( dbxParticle* apart);
double     vyof( dbxParticle* apart);
double     vzof( dbxParticle* apart);
double     vtof( dbxParticle* apart);
double    vtrof( dbxParticle* apart);

double CCountof( dbxParticle* apart);
double    nbfof( dbxParticle* apart);
double MiniIsoVarof( dbxParticle* apart);
double AbsIsoVarof( dbxParticle* apart);
double IDXof( dbxParticle* apart);

//other functions to be added
#endif /* FuncNode_h */
