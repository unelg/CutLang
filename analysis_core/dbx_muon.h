#ifndef DBX_MUON_H
#define DBX_MUON_H

#include "dbxParticle.h"

class dbxMuon : public dbxParticle {
 public:
        dbxMuon( ): dbxParticle(){};
        dbxMuon( TLorentzVector lv): dbxParticle(lv){};
        ~dbxMuon(){};
        void setd0( double v)             { mu_trackd0beam=v;   }
        
        double d0()                      { return mu_trackd0beam; }
        
private:
       double mu_trackd0beam;
       
       ClassDef(dbxMuon,1);
};

#endif
