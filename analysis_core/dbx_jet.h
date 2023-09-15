#ifndef DBX_JET_H
#define DBX_JET_H

#include "dbxParticle.h"

class dbxJet: public dbxParticle {
 public:
        dbxJet( ): dbxParticle(){};
        dbxJet( TLorentzVector lv): dbxParticle(lv){};

        void set_isbtagged_77(const char& flag){jet_isbtagged_77=flag;}
        void set_isTautagged(const char& flag){jet_isTautagged=flag;}
        void settruthflav(const int&v){m_truthflav=v;}
        void setisTrueHS(const char&v){ m_isTrueHS=v;}
        
        bool  isbtagged_77() { return jet_isbtagged_77;}
        int   truthflav() const{return m_truthflav;}
        char isTrueHS()const{return m_isTrueHS;}
        
        TLorentzVector Nocalibjet() {return p_Nocalibjet;} 
private:
       int m_truthflav;
       char m_isTrueHS;
       bool jet_isbtagged_77;
       bool jet_isTautagged;
       double p_btag_eventW;
       TLorentzVector p_Nocalibjet;
     ClassDef(dbxJet,1);
};

#endif
