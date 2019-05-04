#ifndef DBX_TAU_H
#define DBX_TAU_H

#include "dbxParticle.h"

class dbxTau: public dbxParticle {
 public:
        dbxTau( ): dbxParticle(){};
        dbxTau( TLorentzVector lv): dbxParticle(lv){};

        void setIsolation          (double v) {p_isolation=v;            }

private:
       double p_isolation;

     ClassDef(dbxTau,1);
};

#endif
