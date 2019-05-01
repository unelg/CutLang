#ifndef DBX_LJET_H
#define DBX_LJET_H

#include "dbxParticle.h"

class dbxLJet: public dbxParticle {
 public:
        dbxLJet( ): dbxParticle(){};
        dbxLJet( TLorentzVector lv): dbxParticle(lv){};

        /*void setSv0mass          (double v) {p_sv0mass=v;            }
        void setEmEta            (double v) {p_emeta=v;              }
        void setEmEta            (double v) {p_emeta=v;              }*/

     ClassDef(dbxLJet,1);
};

#endif
