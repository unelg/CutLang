#define ${name}_cxx
#include "${name}.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <signal.h>

#include "dbx_electron.h"
#include "dbx_muon.h"
#include "dbx_jet.h"
#include "dbx_tau.h"
#include "dbx_a.h"
#include "DBXNtuple.h"
#include "analysis_core.h"
#include "AnalysisController.h"

//#define _CLV_
#ifdef _CLV_
#define DEBUG(a) std::cout<<a
#else
#define DEBUG(a)
#endif

void ${name}
::GetPhysicsObjects(Long64_t j, AnalysisObjects *a0)
{
   fChain->GetEntry(j);
   vector<dbxMuon>     muons;
   vector<dbxElectron> electrons;
   vector<dbxPhoton>   photons;
   vector<dbxJet>      jets;
   vector<dbxTau>      taus;
   vector<dbxJet>     ljets;
   vector<dbxTruth>    truth;
   vector<dbxParticle> combos;
   vector<dbxParticle> constis;

   map<string, vector<dbxMuon>     > muos_map;
   map<string, vector<dbxElectron> > eles_map;
   map<string, vector<dbxTau>      > taus_map;
   map<string, vector<dbxPhoton>   > gams_map;
   map<string, vector<dbxJet>      > jets_map;
   map<string, vector<dbxJet>     >ljets_map;
   map<string, vector<dbxTruth>    >truth_map;
   map<string, vector<dbxParticle> >combo_map;
   map<string, vector<dbxParticle> >constits_map;
   map<string, TVector2            >  met_map;

   ---GET_PHYS_TEMP_VAR---

   DEBUG("Begin Filling")

   // PHOTONS -------- // now tau info
   for (unsigned int i=0; i<tau_pt->size(); i++) {
      ---PHOTONS---
   }

   DEBUG("PHOTONS OK")

   //MUONS
   for (unsigned int i=0; i<muon_pt->size(); i++) {
      ---MUONS---
   }

   DEBUG("MUONS OK")

   //ELECTRONS
   for (unsigned int i=0; i<el_pt->size(); i++) {
      ---ELECTRONS---
   }

   DEBUG("ELECTRONS OK")

   //JETS
   for (unsigned int i=0; i<jet_pt->size(); i++) {
      ---JETS---
   }

   DEBUG("JETS OK")

   //MET
   ---MET---

   DEBUG("MET OK")

}

void ${name}
::Loop()
{
   //   In a ROOT session, you can do:
   //      root> .L ${name}.C
   //      root> ${name} t
   //      root> t.GetEntry(12); // Fill t data members with entry number 12
   //      root> t.Show();       // Show values of entry 12
   //      root> t.Show(16);     // Read and show values of entry 16
   //      root> t.Loop();       // Loop on all entries
   //

   //     This is the loop skeleton where:
   //    jentry is the global entry number in the chain
   //    ientry is the entry number in the current Tree
   //  Note that the argument to GetEntry must be:
   //    jentry for TChain::GetEntry
   //    ientry for TTree::GetEntry and TBranch::GetEntry
   //
   //       To read only selected branches, Insert statements like:
   // METHOD1:
   //    fChain->SetBranchStatus("*",0);  // disable all branches
   //    fChain->SetBranchStatus("branchname",1);  // activate branchname
   // METHOD2: replace line
   //    fChain->GetEntry(jentry);       //read all branches
   //by  b_branchname->GetEntry(ientry); //read only this branch
   if (fChain == 0)
      return;

   Long64_t nentries = fChain->GetEntriesFast();

   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry = 0; jentry < nentries; jentry++)
   {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0)
         break;
      nb = fChain->GetEntry(jentry);
      nbytes += nb;
      // if (Cut(ientry) < 0) continue;
   }
}
