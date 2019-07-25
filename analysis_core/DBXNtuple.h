#ifndef DBX_NT_H
#define DBX_NT_H

#include <vector>
#include <cmath>
#include "TObject.h"
#include "TLorentzVector.h"
#include "TVector2.h"
#include "TFile.h"
#include "TNtuple.h"
#include "TH1F.h"
#include "TH2F.h"
#include "TCanvas.h"

#include "dbx_electron.h"
#include "dbx_muon.h"
#include "dbx_jet.h"
#include "dbx_tau.h"
#include "dbx_photon.h"
#include "dbx_truth.h"
#include "dbxParticle.h"


using namespace std;

class DBXNtuple: public TObject {
    public:
        DBXNtuple() ;
       ~DBXNtuple() ;

        int nEle;
        int nMuo;
        int nJet;
	int nLJet;
	int nPhoton;
	int nTau;
	int nTruth;
	int nCombo;
        void  Clean( );

        vector<dbxElectron> nt_eles;
        vector<dbxMuon>     nt_muos;
        vector<dbxJet>      nt_jets;
	vector<dbxTau>	    nt_taus;
	vector<dbxJet>      nt_ljets;
	vector<dbxPhoton>   nt_photons;
        vector<dbxParticle> nt_combos;
	vector<dbxTruth>    nt_truth;
        vector<double>      nt_uncs;
        vector<TVector2>    nt_sys_met;
        TVector2            nt_met;
        evt_data            nt_evt;
// http://root.cern.ch/root/Using.html

        ClassDef(DBXNtuple,4);
};

#endif
