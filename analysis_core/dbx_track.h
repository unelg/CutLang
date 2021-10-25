#ifndef DBX_TRACK_H
#define DBX_TRACK_H

#include "dbxParticle.h"

class dbxTrack: public dbxParticle {
 public:
        dbxTrack( ): dbxParticle(){};
        dbxTrack( TLorentzVector lv): dbxParticle(lv){};

     ClassDef(dbxTrack,1);
};

#endif
