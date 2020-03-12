#ifndef DBX_JET_H
#define DBX_JET_H

#include "dbxParticle.h"

class dbxJet: public dbxParticle {
 public:
        dbxJet( ): dbxParticle(){};
        dbxJet( TLorentzVector lv): dbxParticle(lv){};

        void setSv0mass          (double v) {p_sv0mass=v;            }
        void setSv0nt2           (double v) {p_sv0nt2 =v;            }
        void setSv0svok          (double v) {p_sv0svok=v;            }
        void setSv0ntrk          (double v) {p_sv0ntrk=v;            }
        void setSv0ntrkv         (double v) {p_sv0ntrkv=v;           }
        void setSv0ntrkj         (double v) {p_sv0ntrkj=v;           }
        void setSv0efrc          (double v) {p_sv0efrc=v;            }
        void setJVtxf            (double v) {p_jetvtxf=v;            }
        void setEmEta            (double v) {p_emeta=v;              }
        void setEmPhi            (double v) {p_emphi=v;              }
        void setEtaCorr          (double v) {p_etacorr=v;            }
        void setJesuRelativePos  (double v) {p_jesu_relative_pos=v;  }
        void setJesuRelativeNeg  (double v) {p_jesu_relative_neg=v;  }
        void setJerUncert        (double v) {p_jer_uncert=v;         }
        void setJetFrac          (double v) {p_jetfrac=v;            }
        void setJLabel           (int    v) {p_jlabel=v;             }
        void setJee_status       (unsigned int v) {p_jee_status=v;         }
        void setCalibjetscale    (double v) {p_btag_eventW=v;        }  
        void setBJetEscalePos    (double v) {p_bjetescale_pos=v;     }
        void setBJetEscaleNeg    (double v) {p_bjetescale_neg=v;     }
        void setNocalibjet       (TLorentzVector lv){p_Nocalibjet=lv; }
        void set_isbtagged_77(const char& flag){jet_isbtagged_77=flag;}
        void set_isTautagged(const char& flag){jet_isTautagged=flag;}
        void setmv2c00(const float&v){m_mv2c00=v;}
        void setmv2c10(const float&v){m_mv2c10=v;}
        void setmv2c20(const float&v){m_mv2c20=v;}
        void setip3dsv1(const float&v){m_ip3dsv1=v;}
        void setjvt(const float&v){m_jvt=v;}
        void settruthflav(const int&v){m_truthflav=v;}
        void setisTrueHS(const char&v){ m_isTrueHS=v;}
        
        unsigned int Jee_status(){return p_jee_status;}
        double btag_eventW()     {return p_btag_eventW;}
        int    JLabel()          {return p_jlabel;}
        double JesuRelativePos() {return p_jesu_relative_pos;}
        double JesuRelativeNeg() {return p_jesu_relative_neg;}
        double JerUncert()       {return p_jer_uncert;}
        double Sv0mass()         {return p_sv0mass;}
        double Sv0nt2()          {return p_sv0nt2; }
        double Sv0svok()         {return p_sv0svok; }
        double Sv0ntrk()         {return p_sv0ntrk; }
        double Sv0ntrkv()        {return p_sv0ntrkv; }
        double Sv0ntrkj()        {return p_sv0ntrkj; }
        double Sv0efrc()         {return p_sv0efrc; }
        double JetVtxF()         {return p_jetvtxf; }
        double EmEta()           {return p_emeta; }
        double EmPhi()           {return p_emphi; }
        double EtaCorr()         {return p_etacorr; }
        double JetFrac()         {return p_jetfrac; }
        double BJetEscalePos()   {return p_bjetescale_pos;}
        double BJetEscaleNeg()   {return p_bjetescale_neg;}
        
        bool  isbtagged_77() { return jet_isbtagged_77;}
        bool  isTautagged() { return jet_isTautagged;}
        float mv2c00()    const{return m_mv2c00;}
        float mv2c10()const{return m_mv2c10;}
        float mv2c20()const{return m_mv2c20;}
        float ip3dsv1()const{return m_ip3dsv1;}
        float jvt() const{return m_jvt;}
        int   truthflav() const{return m_truthflav;}
        char isTrueHS()const{return m_isTrueHS;}
        
        TLorentzVector Nocalibjet() {return p_Nocalibjet;} 
private:
 unsigned int p_jee_status;
       int    p_jlabel;
       double p_jesu_relative_pos;
       double p_jesu_relative_neg;
       double p_jer_uncert;
       double p_bjetescale_pos;
       double p_bjetescale_neg;
       double p_sv0mass;
       double p_sv0nt2;
       double p_sv0svok;
       double p_sv0ntrk;
       double p_sv0ntrkv;
       double p_sv0ntrkj;
       double p_sv0efrc;
       double p_jetvtxf;
       double p_emeta;
       double p_emphi;
       double p_etacorr;
       double p_jetfrac;
       float m_mv2c00;
       float m_mv2c10;
       float m_mv2c20;
       float m_ip3dsv1;
       float m_jvt;
       int m_truthflav;
       char m_isTrueHS;
       bool jet_isbtagged_77;
       bool jet_isTautagged;
       double p_btag_eventW;
       TLorentzVector p_Nocalibjet;
     ClassDef(dbxJet,1);
};

#endif
