#ifndef DBX_ELECTRON_H
#define DBX_ELECTRON_H

#include "dbxParticle.h"

class dbxElectron : public dbxParticle {
 public:
        dbxElectron( ): dbxParticle( ){};
        dbxElectron( TLorentzVector lv): dbxParticle(lv){};

        int setElTriggerDR   (double v)       { p_eltriggerdr=v;    return 0;}
        int setElTriggerMatch(int v)          { p_eltriggermatch=v; return 0;}
        int setTrkTheta      (double v)       { p_trktheta=v;       return 0;}
        int setTrkEta        (double v)       { p_trketa=v;         return 0;}
        int setTrkPhi        (double v)       { p_trkphi=v;         return 0;}
        int setBestEt        (double v)       { p_bestet=v;         return 0;}
        int setPtCone30      (unsigned int v) { p_ptcone=v;         return 0;}
        int setEtCone20      (unsigned int v) { p_etcone=v;         return 0;}
        int setEp_elE_up     (double v)       { p_elE_up=v;         return 0;}
        int setEp_elE_down   (double v)       { p_elE_down=v;       return 0;}
        int setClusterE      (double v)       { p_clE=v;            return 0;}
        int setClusterEta    (double v)       { p_clEta=v;          return 0;}
//S.I
       void  setd0sig(const float&v){ m_d0sig=v;}
       void setdelta_z0_sintheta(const float&v){m_delta_z0_sintheta=v;}
       void settrue_type(const int&v){m_true_type=v;}
       void settrue_origin(const int&v){ m_true_origin=v;}
       void settrue_typebkg(const int&v){m_true_typebkg=v;}
       void settrue_originbkg(const int&v){m_true_originbkg=v;}
       void settrigMatch_HLT_e60_lhmedium_nod0(const char&v){m_trigMatch_HLT_e60_lhmedium_nod0=v;}
       void settrigMatch_HLT_e26_lhtight_nod0_ivarloose(const char&v){m_trigMatch_HLT_e26_lhtight_nod0_ivarloose=v;}
       void settrigMatch_HLT_e140_lhloose_nod0(const char&v){m_trigMatch_HLT_e140_lhloose_nod0=v;}
       void settrigMatch_HLT_e60_lhmedium(const char&v){m_trigMatch_HLT_e60_lhmedium=v;}
       void settrigMatch_HLT_e24_lhmedium_L1EM20VH(const char&v){m_trigMatch_HLT_e24_lhmedium_L1EM20VH=v;}
       void settrigMatch_HLT_e120_lhloose(const char&v){ m_trigMatch_HLT_e120_lhloose=v;}
       void setisZCand(const int&v){m_isZCand=v;}
//E S.I
        

        int          ElTriggerMatch() { return p_eltriggermatch; }
        double       ElTriggerDR()    { return p_eltriggerdr; }
        double       TrkTheta()       { return p_trktheta; }
        double       TrkEta()         { return p_trketa; }
        double       TrkPhi()         { return p_trkphi; }
        double       BestEt()         { return p_bestet; }
        unsigned int PtCone30()       { return p_ptcone; }
        unsigned int EtCone20()       { return p_etcone; }
        double       Ep_elE_up()      { return p_elE_up; }
        double       Ep_elE_down()    { return p_elE_down; }
        double       clusterE()       { return p_clE; }
        double       clusterEta()     { return p_clEta; }
//S.I
        float d0sig()const{return m_d0sig;}
        float delta_z0_sintheta()const{return m_delta_z0_sintheta;}
        int   true_type()const{return m_true_type;}
        int   true_origin()const{return m_true_origin;}
        int   true_typebkg()const{return m_true_typebkg;}
        int   true_originbkg()const{return m_true_originbkg;}
        char  trigMatch_HLT_e60_lhmedium_nod0()const{return m_trigMatch_HLT_e60_lhmedium_nod0;}
        char  trigMatch_HLT_e26_lhtight_nod0_ivarloose()const{return m_trigMatch_HLT_e26_lhtight_nod0_ivarloose;}
        char  trigMatch_HLT_e140_lhloose_nod0()const{return m_trigMatch_HLT_e140_lhloose_nod0;}
        char  trigMatch_HLT_e60_lhmedium()const{return m_trigMatch_HLT_e60_lhmedium;}
        char  trigMatch_HLT_e24_lhmedium_L1EM20VH()const{return m_trigMatch_HLT_e24_lhmedium_L1EM20VH;}
        char  trigMatch_HLT_e120_lhloose()const{return m_trigMatch_HLT_e120_lhloose;}
        int   isZCand()const{return m_isZCand;}
//E S.I
        
        

private:
          int p_eltriggermatch;
       double p_eltriggerdr;
       double p_trktheta;
       double p_trketa;
       double p_trkphi;
       double p_bestet;
       double p_clE;
       double p_clEta;
       unsigned int p_ptcone;
       unsigned int p_etcone;
       double p_elE_up;
       double p_elE_down;
       
//S.I
       float m_d0sig;
       float m_delta_z0_sintheta;
       int m_true_type;
       int m_true_origin;
       int m_true_typebkg;
       int m_true_originbkg;
       char m_trigMatch_HLT_e60_lhmedium_nod0;
       char m_trigMatch_HLT_e26_lhtight_nod0_ivarloose;
       char m_trigMatch_HLT_e140_lhloose_nod0;
       char m_trigMatch_HLT_e60_lhmedium;
       char m_trigMatch_HLT_e24_lhmedium_L1EM20VH;
       char m_trigMatch_HLT_e120_lhloose;
       int m_isZCand;
//E S.I       

       ClassDef(dbxElectron,1);
};

#endif
