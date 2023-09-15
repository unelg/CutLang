#ifndef DBX_PHOTON_H
#define DBX_PHOTON_H

#include "dbxParticle.h"

class dbxPhoton : public dbxParticle {
 public:
        dbxPhoton( ): dbxParticle( ){};
        dbxPhoton( TLorentzVector lv): dbxParticle(lv){};


private:

       ClassDef(dbxPhoton,1);
};

#endif
