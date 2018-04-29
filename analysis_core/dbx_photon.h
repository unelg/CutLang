#ifndef DBX_PHOTON_H
#define DBX_PHOTON_H

#include "dbxParticle.h"

class dbxPhoton : public dbxParticle {
 public:
        dbxPhoton( ): dbxParticle( ){};
        dbxPhoton( TLorentzVector lv): dbxParticle(lv){};

        int setElTriggerDR   (double v)       { p_eltriggerdr=v;    return 0;}
        int setElTriggerMatch(int v)          { p_eltriggermatch=v; return 0;}
        int setTrkTheta      (double v)       { p_trktheta=v;       return 0;}
        int setTrkEta        (double v)       { p_trketa=v;         return 0;}
        int setTrkPhi        (double v)       { p_trkphi=v;         return 0;}
        int setBestEt        (double v)       { p_bestet=v;         return 0;}
        int setPtCone30      (unsigned int v) { p_ptcone=v;         return 0;}
        int setEtCone20      (unsigned int v) { p_etcone=v;         return 0;}
        int setEp_elE_up     (double v)       { p_elE_up=v;         return 0;}
        int setEp_elE_down   (double v)       { p_elE_down=v;       return 0;}
        int setClusterE      (double v)       { p_clE=v;            return 0;}
        int setClusterEta    (double v)       { p_clEta=v;          return 0;}


        int         ElTriggerMatch()  { return p_eltriggermatch; }
        double       ElTriggerDR()    { return p_eltriggerdr; }
        double       TrkTheta()       { return p_trktheta; }
        double       TrkEta()         { return p_trketa; }
        double       TrkPhi()         { return p_trkphi; }
        double       BestEt()         { return p_bestet; }
        unsigned int PtCone30()       { return p_ptcone; }
        unsigned int EtCone20()       { return p_etcone; }
        double       Ep_elE_up()      { return p_elE_up; }
        double       Ep_elE_down()    { return p_elE_down; }
        double       clusterE()       { return p_clE; }
        double       clusterEta()     { return p_clEta; }


private:
       int p_eltriggermatch;
       double p_eltriggerdr;
       double p_trktheta;
       double p_trketa;
       double p_trkphi;
       double p_bestet;
       double p_clE;
       double p_clEta;
       unsigned int p_ptcone;
       unsigned int p_etcone;
       double p_elE_up;
       double p_elE_down;

       ClassDef(dbxPhoton,1);
};

#endif
