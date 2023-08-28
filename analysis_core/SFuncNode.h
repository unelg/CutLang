//
//  SFuncNode.h
//  mm
//
//  Created by Anna-Monica  on 8/2/18.
//  Copyright © 2018 Anna-Monica. All rights reserved.
//

#ifndef SFuncNode_h
#define SFuncNode_h
#include "Node.h"
#include "Hemisphere.h"
#include "mt2_bisect.h"
#include "TTreeReader.h"

//#define _CLV_
#ifdef _CLV_
#define DEBUG(a) std::cout<<a
#else
#define DEBUG(a)
#endif

using namespace std;
//takes care of functions with arguments


class SFTTreader {
  public:
        virtual double readvalue( ){ return 0; }
};

class SFTTreaderI : public SFTTreader{
private:
     double avalue;
     string sin;
public:
       TTreeReaderValue<Int_t> *my_reader;
       SFTTreaderI(TTreeReader *ttreader, string s) {
           my_reader = new TTreeReaderValue<Int_t>(*ttreader, s.c_str() );
           sin=s;
       }
       double readvalue( ) {
        avalue=*(my_reader->Get() );
        return avalue;
      }
};

class SFTTreaderD : public SFTTreader{
private:
     double avalue;
     string sin;
public:
       TTreeReaderValue<Double_t> *my_reader;
       SFTTreaderD(TTreeReader *ttreader, string s) {
           my_reader = new TTreeReaderValue<Double_t>(*ttreader, s.c_str() );
           sin=s;
       }
      double readvalue() {
        avalue=*(my_reader->Get() );
        return avalue;
      }
};

class SFTTreaderF : public SFTTreader{
private:
     double avalue;
     string sin;
public:
       TTreeReaderValue<Float_t> *my_reader;
       SFTTreaderF(TTreeReader *ttreader, string s) {
           my_reader = new TTreeReaderValue<Float_t>(*ttreader, s.c_str() );
           sin=s;
       }
      double readvalue() {
        avalue=*(my_reader->Get() );
        return avalue;
      }
};

class SFTTreaderB : public SFTTreader{
private:
     double avalue;
     string sin;
public:
       TTreeReaderValue<Bool_t> *my_reader;
       SFTTreaderB(TTreeReader *ttreader, string s) {
           my_reader = new TTreeReaderValue<Bool_t>(*ttreader, s.c_str() );
           sin=s;
       }
      double readvalue() {
        avalue=*(my_reader->Get() );
        return avalue;
      }
};



class SFuncNode : public Node {
private:
    bool special_function;
      TTreeReader *m_ttreader;

      SFTTreader *ttrdr;
      SFTTreaderF *ttrdrF;
      SFTTreaderD *ttrdrD;
      SFTTreaderB *ttrdrB;
      SFTTreaderI *ttrdrI;
    static std::map< std::string, double > BUFFERED_VALUES;
    //should add something related to trigger types
    Node* userObjectA;
    Node* userObjectB;
    double (*f )(AnalysisObjects*, string, float); // the regular
    double (*g1)(AnalysisObjects*, string, int, std::vector<TLorentzVector> (*func)(std::vector<TLorentzVector>, int));
    double (*g2)(AnalysisObjects*, string, int,                      double (*func)(std::vector<TLorentzVector>));
    double (*g3)(AnalysisObjects*, string, int,                      double (*func)(std::vector<TLorentzVector>, TVector2 ));
    double (*g4)(AnalysisObjects*, string, int, TLorentzVector,      double (*func)(std::vector<TLorentzVector>, TLorentzVector ));
    double (*g5)(AnalysisObjects*, string, int, TLorentzVector, TLorentzVector, TLorentzVector,   double (*func)(TLorentzVector, TLorentzVector, TLorentzVector ));
    double (*g6)(AnalysisObjects*, string, int, double, double, double, double, double (*func)(double, double, double, double));//fTTbarNNLORec

    std::vector<TLorentzVector> (*h1)(std::vector<TLorentzVector>, int);
                         double (*h2)(std::vector<TLorentzVector>);
                         double (*h3)(std::vector<TLorentzVector>, TVector2 );
                         double (*h4)(std::vector<TLorentzVector>, TLorentzVector );
                         double (*h5)(TLorentzVector, TLorentzVector, TLorentzVector );
                         double (*h6)(double, double, double, double);
    bool ext;
    int type = 1;
    float value = -1.0;
    std::vector<myParticle*> inputParticlesA;
    std::vector<myParticle*> inputParticlesB;
    std::vector<myParticle*> inputParticlesC;
    double pv1, pv2, pv3, pv4;


public:
    SFuncNode(double (*func)(AnalysisObjects* ao, string s, float val), 
              float val, 
              std::string s, 
              Node *objectNodeA = NULL, Node *objectNodeB = NULL){
        f=func;
        g1=NULL;
        g2=NULL;
        g3=NULL;
        g4=NULL;
        g5=NULL;
        g6=NULL;
        ext=false;
        value=val;
        symbol=s;
        left=NULL;
        right=NULL;
        userObjectA = objectNodeA;
        userObjectB = objectNodeB;
        DEBUG("** regular simple SF node.\n");
        special_function=false;
}

    SFuncNode(double (*func)(AnalysisObjects* ao, string s, float val),
              Node *child, std::string s, 
              Node *objectNodeA = NULL, Node *objectNodeB = NULL){
        f=func;
        g1=NULL;
        g2=NULL;
        g3=NULL;
        g4=NULL;
        g5=NULL;
        g6=NULL;
        ext=false;
        symbol=s;
        left=child;
        right=NULL;
        userObjectA = objectNodeA;
        userObjectB = objectNodeB;
        DEBUG("** SF node with child node as left.\n");
}

//------------------------- g1 with userfuncA
    SFuncNode(double (*func)(AnalysisObjects* ao, string s, int id, std::vector<TLorentzVector> (*gunc) (std::vector<TLorentzVector> jets, int p1)),
              std::vector<TLorentzVector> (*tunc) (std::vector<TLorentzVector> jets, int p1),
                      int id, 
               std::string s, 
               Node *objectNodeA = NULL, Node *objectNodeB = NULL){
        DEBUG("*****************************************EXTERN SF :"<<s <<"\n");
        f=NULL;
        g3=NULL;
        g2=NULL;
        g4=NULL;
        g5=NULL;
        g6=NULL;
        g1=func;
        h1=tunc;
        ext=true;
        type=id;
        symbol=s;
        left=NULL;
        right=NULL;
        userObjectA = objectNodeA;
        userObjectB = objectNodeB;
}
SFuncNode(double (*func)(AnalysisObjects* ao, string s, int id, double (*gunc) (std::vector<TLorentzVector> jets)),
              double (*tunc) (std::vector<TLorentzVector> jets),
                      int id, 
               std::string s, 
               Node *objectNodeA = NULL, Node *objectNodeB = NULL){
        DEBUG("*****************************************EXTERN SF :"<<s <<"\n");
        f=NULL;
        g6=NULL;
        g5=NULL;
        g4=NULL;
        g3=NULL;
        g1=NULL;
        g2=func;
        h2=tunc;
        ext=true;
        type=id;
        symbol=s;
        left=NULL;
        right=NULL;
        userObjectA = objectNodeA;
        userObjectB = objectNodeB;

}
SFuncNode(double (*func)(AnalysisObjects* ao, string s, int id, double (*gunc) (std::vector<TLorentzVector> jets, TVector2 amet)),
              double (*tunc) (std::vector<TLorentzVector> jets, TVector2 amet),
                      int id, 
               std::string s, 
               Node *objectNodeA = NULL, Node *objectNodeB = NULL){
       DEBUG("*****************************************EXTERN SF :"<<s <<"\n");
        f=NULL;
        g1=NULL;
        g2=NULL;
        g4=NULL;
        g5=NULL;
        g6=NULL;
        g3=func;
        h3=tunc;
        ext=true;
        type=id;
        symbol=s;
        left=NULL;
        right=NULL;
        userObjectA = objectNodeA;
        userObjectB = objectNodeB;

}
SFuncNode(double (*func)(AnalysisObjects* ao, string s, int id, TLorentzVector alv, double (*gunc) (std::vector<TLorentzVector> jets, TLorentzVector amet)),
              double (*tunc) (std::vector<TLorentzVector> jets, TLorentzVector amet),
                      int id, 
               std::string s,
               std::vector<myParticle*> input, 
               Node *objectNodeA = NULL, Node *objectNodeB = NULL){
        DEBUG("*****************************************EXTERN SF :"<<s <<"\n");
        f=NULL;
        g1=NULL;
        g2=NULL;
        g3=NULL;
        g5=NULL;
        g6=NULL;
        g4=func;
        h4=tunc;
        ext=true;
        type=id;
        symbol=s;
        left=NULL;
        right=NULL;
        inputParticlesA=input;
        userObjectA = objectNodeA;
        userObjectB = objectNodeB;
}
SFuncNode(double (*func)(AnalysisObjects* ao, string s, int id, TLorentzVector a1, TLorentzVector a2, TLorentzVector b1, double (*gunc) (TLorentzVector lep1, TLorentzVector lep2, TLorentzVector amet)),
              double (*tunc) (TLorentzVector lep1, TLorentzVector lep2, TLorentzVector amet),
                      int id, 
               std::string s,
               std::vector<myParticle*> input1, 
               std::vector<myParticle*> input2, 
               std::vector<myParticle*> input3, 
               Node *objectNodeA = NULL, Node *objectNodeB = NULL){
        DEBUG("*****************************************EXTERN SF T5:"<<s <<"\n");
        f=NULL;
        g1=NULL;
        g2=NULL;
        g3=NULL;
        g4=NULL;
        g6=NULL;
        g5=func;
        h5=tunc;
        ext=true;
        type=id;
        symbol=s;
        left=NULL;
        right=NULL;
        inputParticlesA=input1;
        inputParticlesB=input2;
        inputParticlesC=input3;
        userObjectA = objectNodeA;
        userObjectB = objectNodeB;
}
//--------------------------------g6
SFuncNode(double (*func)(AnalysisObjects* ao, string s, int id, double pt1, double pt2, double m1, double pt3, double (*gunc)(double a1, double a2, double a3, double a4)),
              double (*tunc) (double a1, double a2, double a3, double a4),
                      int id,
               std::string s,
                  double apt1, double apt2, double apt3, double apt4,
               Node *objectNodeA = NULL, Node *objectNodeB = NULL){
        DEBUG("*****************************************EXTERN SF T5:"<<s <<"\n");
        f=NULL;
        g1=NULL;
        g2=NULL;
        g3=NULL;
        g4=NULL;
        g5=NULL;
        g6=func;
        h6=tunc;
        ext=true;
        type=id;
        symbol=s;
        left=NULL;
        right=NULL;
        pv1=apt1; 
        pv2=apt2; 
        pv3=apt3; 
        pv4=apt4; 
 //      inputParticlesA=input1;
 //      inputParticlesB=input2;
 //      inputParticlesC=input3;
        userObjectA = objectNodeA;
        userObjectB = objectNodeB;
}



//---------------------------end of extern function types
    void setTTRaddr( TTreeReader *ttr, string s);   
    virtual double evaluate(AnalysisObjects* ao) override ;
    virtual void Reset() override;
    virtual void getParticles(std::vector<myParticle *>* particles) override{}
    virtual void getParticlesAt(std::vector<myParticle *>* particles, int index) override{}
    virtual void setSymbol(string s) { symbol=s; }
    virtual ~SFuncNode() {}
};

double none(AnalysisObjects* ao, string s, float id);
double all(AnalysisObjects* ao, string s, float id);
double uweight(AnalysisObjects* ao, string s, float value);
double lepsf(AnalysisObjects* ao, string s, float value);
double btagsf(AnalysisObjects* ao, string s, float value);
double xslumicorrsf(AnalysisObjects* ao, string s, float value);
double count(AnalysisObjects* ao, string s, float id);
double getIndex(AnalysisObjects* ao, string s, float id); // new internal function
double met   (AnalysisObjects* ao, string s, float id);
double metsig(AnalysisObjects* ao, string s, float id);
double hlt_iso_mu(AnalysisObjects* ao, string s, float id);
double hlt_trg(AnalysisObjects* ao, string s, float id);
double ht(AnalysisObjects* ao, string s, float id);
double userfuncA(AnalysisObjects* ao, string s, int id, std::vector<TLorentzVector> (*func)(std::vector<TLorentzVector> jets, int p1) );
double userfuncB(AnalysisObjects* ao, string s, int id, double (*func)(std::vector<TLorentzVector> jets ) );
double userfuncC(AnalysisObjects* ao, string s, int id, double (*func)(std::vector<TLorentzVector> jets, TVector2 amet ) );
double userfuncD(AnalysisObjects* ao, string s, int id, TLorentzVector alv, double (*func)(std::vector<TLorentzVector> jets, TLorentzVector amet ));
double userfuncE(AnalysisObjects* ao, string s, int id, TLorentzVector l1, TLorentzVector l2,  TLorentzVector m1,
                                                            double (*func)(TLorentzVector la, TLorentzVector lb, TLorentzVector amet ) );
double userfuncF(AnalysisObjects* ao, string s, int id, double l1, double l2,  double m1, double l3,
                                                            double (*func)(double la, double lb, double amet, double lab ) );

std::vector<TLorentzVector> negsumobj(std::vector<TLorentzVector> myjets, int p1);
std::vector<TLorentzVector> sumobj(std::vector<TLorentzVector> myjets, int p1);
std::vector<TLorentzVector> fhemisphere(std::vector<TLorentzVector> myjets, int p1);
double fMT2(TLorentzVector lep1, TLorentzVector lep2, TLorentzVector amet);
double fTTbarNNLORec(double lep1, double lep2, double amet, double lab);
double specialsf(AnalysisObjects* ao, string s, float value);


/*
double nbjets(AnalysisObjects* ao){
    ValueNode abc=ValueNode();
//    return (abc.tagJets(ao, 1).size() );
    return (1);
}

double nljets(AnalysisObjects* ao){
    ValueNode abc=ValueNode();
//    return (abc.tagJets(ao, 0).size() );
    return (1);
}


double emwt(AnalysisObjects* ao){
    double theLeptonTrkPhi = ao->eles.at(0).lv().Phi();
    double           leppt = ao->eles.at(0).lv().Pt();
    double dphi_e_et = fabs(theLeptonTrkPhi - ao->met.Phi());
    if (dphi_e_et>M_PI) dphi_e_et=2*M_PI-dphi_e_et;
    float mwt=sqrt(2*leppt*ao->met.Mod()*(1-cos(dphi_e_et)));
    return (mwt);
} 

double mmwt(AnalysisObjects* ao){
    double theLeptonTrkPhi = ao->muos.at(0).lv().Phi();
    double           leppt = ao->muos.at(0).lv().Pt();
    double dphi_e_et = fabs(theLeptonTrkPhi - ao->met.Phi());
    if (dphi_e_et>M_PI) dphi_e_et=2*M_PI-dphi_e_et;
    float mwt=sqrt(2*leppt*ao->met.Mod()*(1-cos(dphi_e_et)));
    return (mwt);
} 

double mmetmwt(AnalysisObjects* ao){
    double theLeptonTrkPhi = ao->muos.at(0).lv().Phi();
    double           leppt = ao->muos.at(0).lv().Pt();
    double dphi_e_et = fabs(theLeptonTrkPhi - ao->met.Phi());
    if (dphi_e_et>M_PI) dphi_e_et=2*M_PI-dphi_e_et;
    float mwt=sqrt(2*leppt*ao->met.Mod()*(1-cos(dphi_e_et)));
    return (mwt+ao->met.Mod() );
}

double emetmwt(AnalysisObjects* ao){
    double theLeptonTrkPhi = ao->eles.at(0).lv().Phi();
    double           leppt = ao->eles.at(0).lv().Pt();
    double dphi_e_et = fabs(theLeptonTrkPhi - ao->met.Phi());
    if (dphi_e_et>M_PI) dphi_e_et=2*M_PI-dphi_e_et;
    float mwt=sqrt(2*leppt*ao->met.Mod()*(1-cos(dphi_e_et)));
    return (mwt+ao->met.Mod() );
}
*/

#endif /* SFuncNode_h */
