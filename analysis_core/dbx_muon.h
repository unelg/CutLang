#ifndef DBX_MUON_H
#define DBX_MUON_H

#include "dbxParticle.h"

class dbxMuon : public dbxParticle {
 public:
        dbxMuon( ): dbxParticle(){};
        dbxMuon( TLorentzVector lv): dbxParticle(lv){};
        ~dbxMuon(){};
        void setMuTriggerMatch(int v)    { p_mutriggermatch=v; }
        void setMuIdTheta(double v)       { p_muidtheta=v;      }
        void setMuIdPhi(double v)         { p_muidphi=v;        }
        void setTopMuInTrigger(bool v)    { p_topmutrigdec=v;   }
        void setPtMsup(     double v )    { p_msup=v;           }
        void setPtMsdown(   double v )    { p_msdown=v;         }
        void setPtIdup(     double v )    { p_idup=v;           }
        void setPtIddown(   double v )    { p_iddown=v;         }
        void setPtScup(     double v )    { p_scup=v;           }
        void setPtScdown(   double v )    { p_scdown=v;         }
        void setd0( double v)             { mu_trackd0beam=v;   }
//S.I
        void setdelta_z0_sintheta(const float&v) {m_delta_z0_sintheta=v;}
        void settrue_type(const int&v) { m_true_type=v;}
        void settrue_origin(const int&v) { m_true_origin=v;}
        void settrigMatch_HLT_mu26_ivarmedium(const char&v){ m_trigMatch_HLT_mu26_ivarmedium=v;}
        void settrigMatch_HLT_mu50(const char&v){ m_trigMatch_HLT_mu50=v;}
        void settrigMatch_HLT_mu20_iloose_L1MU15(const char&v){ m_trigMatch_HLT_mu20_iloose_L1MU15=v;}
        void setisZCand(const int&v){ m_isZCand=v;}

//E S.I
        
        
        int    MuTriggerMatch()          { return p_mutriggermatch; }
        bool   TopMuInTrigger()          { return p_topmutrigdec; }
        double MuIdTheta()               { return p_muidtheta; }
        double MuIdPhi()                 { return p_muidphi; }
        double PtMsup()                  { return p_msup;  }
        double PtMsdown()                { return p_msdown;}
        double PtIdup()                  { return p_idup;  }
        double PtIddown()                { return p_iddown;}
        double PtScup()                  { return p_scup;  }
        double PtScdown()                { return p_scdown;}
        double d0()                      { return mu_trackd0beam; }
//S.I
        float delta_z0_sintheta()const {return m_delta_z0_sintheta;}
        int   true_type()const  {return m_true_type;}
        int   true_origin()const {return m_true_origin;}
        char  trigMatch_HLT_mu26_ivarmedium()const{return m_trigMatch_HLT_mu26_ivarmedium;}
        char  trigMatch_HLT_mu50()const{return m_trigMatch_HLT_mu50;}
        char  trigMatch_HLT_mu20_iloose_L1MU15()const{return m_trigMatch_HLT_mu20_iloose_L1MU15;}
        int   isZCand()const{return m_isZCand;}
//E S.I
        
        
private:
       int   p_mutriggermatch;
       bool   p_topmutrigdec;
       double p_muidtheta;
       double p_muidphi;
       double p_msup;
       double p_msdown;
       double p_idup;
       double p_iddown;
       double p_scup;
       double p_scdown;
       double mu_trackd0beam;
//S.I
       float m_delta_z0_sintheta;
       int m_true_type;
       int m_true_origin;
       char m_trigMatch_HLT_mu26_ivarmedium;
       char m_trigMatch_HLT_mu50;
       char m_trigMatch_HLT_mu20_iloose_L1MU15;
       int m_isZCand;
//E S.I       
       
       
       ClassDef(dbxMuon,1);
};

#endif
