#ifndef DBX_TRUTH_H
#define DBX_TRUTH_H

#ifdef VLQLIGHT
#include "VLQLight/dbxParticle.h"
#else
#include "dbxParticle.h"
#endif

class dbxTruth: public dbxParticle {
 public:
        dbxTruth( ): dbxParticle(){};
        dbxTruth( TLorentzVector lv): dbxParticle(lv){};

     ClassDef(dbxTruth,1);
};

#endif
