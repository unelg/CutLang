#ifndef DBX_TRUTH_H
#define DBX_TRUTH_H

#include "dbxParticle.h"

class dbxTruth: public dbxParticle {
 public:
        dbxTruth( ): dbxParticle(){};
        dbxTruth( TLorentzVector lv): dbxParticle(lv){};

     ClassDef(dbxTruth,1);
};

#endif
