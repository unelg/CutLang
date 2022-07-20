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
#include "TTreeReader.h"
#include "TTreeReaderArray.h"

class myTTreader {

public:
        virtual double readvalue(int nix){ return 0; }
};

class myTTreaderF : public myTTreader{

private:
     double avalue;

public:
       TTreeReaderArray<Float_t>  *my_reader;
       myTTreaderF(TTreeReader *ttreader, string s) {
           my_reader = new TTreeReaderArray<Float_t>(*ttreader, s.c_str() );
       }
      double readvalue(int nix) {
        avalue=my_reader->At(nix) ; //->At(nix)
        return avalue;
      }
};

class myTTreaderD : public myTTreader{
private:
     double avalue;
public:
      TTreeReaderArray<Double_t> *my_reader;
      myTTreaderD( TTreeReader *ttreader, string s) {
           my_reader = new TTreeReaderArray<Double_t>(*ttreader, s.c_str() );
      }
      double readvalue(int nix) {
        avalue=my_reader->At(nix) ; //->At(nix)
        return avalue;
      }
};

class myTTreaderB : public myTTreader{
private:
     double avalue;
public:
      TTreeReaderArray<Bool_t> *my_reader;
      myTTreaderB( TTreeReader *ttreader, string s) {
           my_reader = new TTreeReaderArray<Bool_t>(*ttreader, s.c_str() );
      }
      double readvalue(int nix) {
        avalue=my_reader->At(nix) ; //->At(nix)
        return avalue;
      }
};
class myTTreaderI : public myTTreader{
private:
     double avalue;
public:
      TTreeReaderArray<Int_t> *my_reader;
      myTTreaderI( TTreeReader *ttreader, string s) {
           my_reader = new TTreeReaderArray<Int_t>(*ttreader, s.c_str() );
      }
      double readvalue(int nix) {
        avalue=my_reader->At(nix) ; //->At(nix)
        return avalue;
      }
};

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

        myTTreader *ttrdr;
        myTTreaderF *ttrdrF;
        myTTreaderD *ttrdrD;
        myTTreaderB *ttrdrB;
        myTTreaderI *ttrdrI;

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
double MsoftDof( dbxParticle* apart);
double  DeepBof( dbxParticle* apart);
double   isBTag( dbxParticle* apart);
double isTauTag( dbxParticle* apart);
double isTight ( dbxParticle* apart);
double isMedium( dbxParticle* apart);
double isLoose ( dbxParticle* apart);
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
double  sieieof( dbxParticle* apart);
double sub1btagof( dbxParticle* apart);
double sub2btagof( dbxParticle* apart);
double mvalooseof( dbxParticle* apart);
double mvatightof( dbxParticle* apart);
double relisoof( dbxParticle* apart);
double isZcandid ( dbxParticle* apart);
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
double IsoVarof( dbxParticle* apart);
double averageMuof( dbxParticle* apart);
double truthMatchProbof( dbxParticle* apart);
double truthIDof( dbxParticle* apart);
double truthParentIDof( dbxParticle* apart);
double IDXof( dbxParticle* apart);

//other functions to be added
#endif /* FuncNode_h */
