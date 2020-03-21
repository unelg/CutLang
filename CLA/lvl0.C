#define lvl0_cxx
#include "lvl0.h"
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

//#define __DEBUG__
//using namespace Root;

// header and lines to handle ctrl+C gracefully
extern void _fsig_handler (int) ;
extern bool fctrlc;

void lvl0::Loop(analy_struct aselect, char *extname)
{

// Signal HANDLER
   signal (SIGINT, _fsig_handler); // signal handler has issues with CINT

   if (fChain == 0) {
          cout <<"Error opening the data file"<<endl; return;
   }

   int verboseFreq(aselect.verbfreq);
   int extra_analysis_count=1;
   int prev_RunNumber=-1;

   map < string, int > syst_names;
   syst_names["01_pileup"]                  = 2;
   syst_names["02_elTRG"]                   = 2;
   syst_names["03_elRECO"]                  = 2;
   syst_names["04_elID"]                    = 2;
   syst_names["05_elISOL"]                  = 2;
   syst_names["06_muTRGStat"]               = 2;
   syst_names["07_muTRGSys"]                = 2;
   syst_names["08_muIDStat"]                = 2;
   syst_names["09_muIDSys"]                 = 2;
   syst_names["10_muIDStatLowPT"]           = 2;
   syst_names["11_muIDSysLowPT"]            = 2;
   syst_names["12_muISOLStat"]              = 2;
   syst_names["13_muISOLSys"]               = 2;
   syst_names["14_muTTVAStat"]              = 2;
   syst_names["15_muTTVASys"]               = 2;
   syst_names["16_btagSF77extraP"]          = 2;
   syst_names["17_btagSF77extraPfromC"]     = 2;
   syst_names["18_btagSF77eigenvarsB"]      = 2;
   syst_names["19_btagSF77eigenvarsC"]      = 2;
   syst_names["20_btagSF77eigenvarsLight"]  = 2;
   syst_names["21_jvt"]                     = 2;



   AnalysisController aCtrl(&aselect, syst_names);
   aCtrl.Initialize(extname);
   cout << "End of analysis initialization"<<endl;

   Long64_t nentries = fChain->GetEntriesFast();
   if (aselect.maxEvents>0 ) nentries=aselect.maxEvents;
   cout << "number of entries " << nentries << endl;
   Long64_t startevent = 0;
   if (aselect.startpt>0 ) startevent=aselect.startpt;
   cout << "starting entry " << startevent << endl;
   Long64_t lastevent = startevent + nentries;
   if (lastevent > fChain->GetEntriesFast() ) { lastevent=fChain->GetEntriesFast();
       cout << "Interval exceeds tree. Analysis is done on max available events starting from event : " << startevent << endl;
   }

   Long64_t nbytes = 0, nb = 0;
   for (Long64_t j=startevent; j<lastevent; ++j) {

       if ( fctrlc ) { cout << "Processed " << j << " events\n"; break; }
       if (0 > LoadTree (j)) break;
       if ( j%verboseFreq == 0 ) cout << "Processing event " << j << endl;

//--------variables-------
       vector<dbxMuon> muons_sf_pos, muons_sf_neg, muons_ms_pos,muons_ms_neg,muons_id_pos,muons_id_neg;
       vector<dbxElectron> eles_sf_pos, eles_sf_neg;
       vector<dbxJet> jets_goodjee ;
       vector<dbxJet> jetBtaggedUp, jetBtaggedDown;
       vector<dbxJet> jets_jes_pos, jets_jes_neg, jets_jespileup_pos, jets_jesbjetescale_pos;
       vector<dbxJet> jets_jer_pos, jets_jer_neg, jets_jespileup_neg, jets_jesbjetescale_neg;
       vector<dbxJet> jesu_jets_Down [16];
       vector<dbxJet> jesu_jets_Up   [16];

       vector<dbxMuon>     muons;
       vector<dbxElectron> electrons;
       vector<dbxTau>      taus;
       vector<dbxPhoton>   photons;
       vector<dbxJet>      jets;
       vector<dbxJet>     ljets;
       vector<dbxTruth>   truth;
       vector<dbxParticle> combos;
       vector<dbxParticle> constis;


       map<string, vector<dbxMuon>     > muos_map;
       map<string, vector<dbxElectron> > eles_map;
       map<string, vector<dbxTau>      > taus_map;
       map<string, vector<dbxPhoton>   > gams_map;
       map<string, vector<dbxJet>      > jets_map;
       map<string, vector<dbxJet>      >ljets_map;
       map<string, vector<dbxTruth>    >truth_map;
       map<string, vector<dbxParticle> >combo_map;
       map<string, vector<dbxParticle> >constits_map;
       map<string, TVector2            >  met_map;

       std::vector<double> scale_mus_msup, scale_mus_mslow, scale_mus_idup, scale_mus_idlow;
       std::vector<double> scale_mus_sfup, scale_mus_sflow, scale_ele_rescaleup, scale_ele_rescalelow;
       std::vector<double> scale_ele_sfup, scale_ele_sflow;
       bool is_mc=true;
       TVector2 met;
       TVector2 met_jesp, met_jesn, met_jerp, met_jern, met_jespileupp, met_jespileupn, met_jesbjetp, met_jesbjetn;//Jets
       TVector2 met_escalerp, met_escalern, met_esfp, met_esfn;//Electrons
       TVector2 met_msfp, met_msfn, met_mmsp, met_mmsn, met_midp, met_midn; //Muons

//---get an event--------
       fChain->GetEntry(j);
//       cout << "Got an event\n";
       int RunNumber=137;
       if (int(RunNumber)!=prev_RunNumber) {
               cout << "Working on Run #:"<<RunNumber<<endl;
               prev_RunNumber=RunNumber;
       }


    if (j<2) {
     std::cout << "Main says hello @evt:"<< event->nt_evt.run_no<<endl;
     cout << "------------- event #:"<<j<< endl;
     cout << "#E:"<< event->nEle <<endl;
     cout << "#M:"<< event->nMuo <<endl;
     cout << "#J:"<< event->nJet << " ==?" << " #J:"<< event->nt_jets.size() <<endl;
     cout << "#Run:"<< event->nt_evt.run_no<<endl;
     cout << "#Evt:"<< event->nt_evt.event_no<<endl;
     cout << "#Evt W:"<< event->nt_evt.user_evt_weight<<endl;
     cout << "METsize:"<<event->nt_sys_met.size() << endl;
     for (unsigned int jk=0; jk<event->nt_sys_met.size(); jk++) {
        cout << (event->nt_sys_met.at(jk)).Mod() << "  " << (event->nt_sys_met.at(jk)).Phi() << endl;
     }
    }

// analysis using info from lvl0 file
    evt_data ev0;
    muons=event->nt_muos;
    electrons=event->nt_eles;
    jets=event->nt_jets;
    met=event->nt_met;

// take a copy of the event info
   ev0=event->nt_evt;
/*
   cout << "Ev0 UW:"<<ev0.user_evt_weight<< endl;
   cout << "Ev0:"<<ev0.weight_mc<< " "<<ev0.weight_pileup<<" "<<ev0.weight_jvt<< endl;
   cout << event->nt_evt.weight_bTagSF_77_eigenvars_B_up.size();
   cout << "~~~~~~~~~~~\n";
   for (int iii=0; iii<event->nt_evt.weight_bTagSF_77_eigenvars_B_up.size(); iii++){ cout<< event->nt_evt.weight_bTagSF_77_eigenvars_B_up.at(iii)<<" ";}
   cout <<"\n";
*/
   int km=0; // this is to count number of systematics
   map < string,   AnalysisObjects > analysis_objs_map;
/*
  if (aselect.dosystematics) {
#ifdef __DEBUG__
   cout << "Running with systematics.\n";
#endif
   ev0.weight_pileup=ev0.weight_pileup_UP;
                                                        analysis_objs_map["01_pileup_0"]   =(AnalysisObjects){event->nt_muos,event->nt_eles,     ga0,  event->nt_jets,  event->nt_met, ev0}; km++;
   ev0.weight_pileup=ev0.weight_pileup_DOWN;
                                                        analysis_objs_map["01_pileup_1"]   =(AnalysisObjects){event->nt_muos,event->nt_eles,     ga0,  event->nt_jets,  event->nt_met, ev0}; km++;
   ev0.weight_leptonSF=ev0.weight_leptonSF_EL_SF_Trigger_UP;
                                                        analysis_objs_map["02_elTRG_0"]   =(AnalysisObjects){event->nt_muos,event->nt_eles,     ga0,  event->nt_jets,  event->nt_met, ev0}; km++;
   ev0.weight_leptonSF=ev0.weight_leptonSF_EL_SF_Trigger_DOWN;
                                                        analysis_objs_map["02_elTRG_1"]   =(AnalysisObjects){event->nt_muos,event->nt_eles,     ga0,  event->nt_jets,  event->nt_met, ev0}; km++;
   ev0.weight_leptonSF=ev0.weight_leptonSF_EL_SF_Reco_UP;
                                                        analysis_objs_map["03_elRECO_0"]  =(AnalysisObjects){event->nt_muos,event->nt_eles,     ga0,  event->nt_jets,  event->nt_met, ev0}; km++;
   ev0.weight_leptonSF=ev0.weight_leptonSF_EL_SF_Reco_DOWN;
                                                        analysis_objs_map["03_elRECO_1"]  =(AnalysisObjects){event->nt_muos,event->nt_eles,     ga0,  event->nt_jets,  event->nt_met, ev0}; km++;
   ev0.weight_leptonSF=ev0.weight_leptonSF_EL_SF_ID_UP;
                                                        analysis_objs_map["04_elID_0"]    =(AnalysisObjects){event->nt_muos,event->nt_eles,     ga0,  event->nt_jets,  event->nt_met, ev0}; km++;
   ev0.weight_leptonSF=ev0.weight_leptonSF_EL_SF_ID_DOWN;
                                                        analysis_objs_map["04_elID_1"]    =(AnalysisObjects){event->nt_muos,event->nt_eles,     ga0,  event->nt_jets,  event->nt_met, ev0}; km++;
   ev0.weight_leptonSF=ev0.weight_leptonSF_EL_SF_Isol_UP;
                                                        analysis_objs_map["05_elISOL_0"]  =(AnalysisObjects){event->nt_muos,event->nt_eles,     ga0,  event->nt_jets,  event->nt_met, ev0}; km++;
   ev0.weight_leptonSF=ev0.weight_leptonSF_EL_SF_Isol_DOWN;
                                                        analysis_objs_map["05_elISOL_1"]  =(AnalysisObjects){event->nt_muos,event->nt_eles,     ga0,  event->nt_jets,  event->nt_met, ev0}; km++;
   ev0.weight_leptonSF=ev0.weight_leptonSF_MU_SF_Trigger_STAT_UP;
                                                       analysis_objs_map["06_muTRGStat_0"]=(AnalysisObjects){event->nt_muos,event->nt_eles,     ga0,  event->nt_jets,  event->nt_met, ev0}; km++;
   ev0.weight_leptonSF=ev0.weight_leptonSF_MU_SF_Trigger_STAT_DOWN;
                                                       analysis_objs_map["06_muTRGStat_1"]=(AnalysisObjects){event->nt_muos,event->nt_eles,     ga0,  event->nt_jets,  event->nt_met, ev0}; km++;
   ev0.weight_leptonSF=ev0.weight_leptonSF_MU_SF_Trigger_SYST_UP;
                                                       analysis_objs_map["07_muTRGSys_0"] =(AnalysisObjects){event->nt_muos,event->nt_eles,     ga0,  event->nt_jets,  event->nt_met, ev0}; km++;
   ev0.weight_leptonSF=ev0.weight_leptonSF_MU_SF_Trigger_SYST_DOWN;
                                                       analysis_objs_map["07_muTRGSys_1"] =(AnalysisObjects){event->nt_muos,event->nt_eles,     ga0,  event->nt_jets,  event->nt_met, ev0}; km++;
   ev0.weight_leptonSF=ev0.weight_leptonSF_MU_SF_ID_STAT_UP;
                                                       analysis_objs_map["08_muIDStat_0"] =(AnalysisObjects){event->nt_muos,event->nt_eles,     ga0,  event->nt_jets,  event->nt_met, ev0}; km++;
   ev0.weight_leptonSF=ev0.weight_leptonSF_MU_SF_ID_STAT_DOWN;
                                                       analysis_objs_map["08_muIDStat_1"] =(AnalysisObjects){event->nt_muos,event->nt_eles,     ga0,  event->nt_jets,  event->nt_met, ev0}; km++;
   ev0.weight_leptonSF=ev0.weight_leptonSF_MU_SF_ID_SYST_UP;
                                                       analysis_objs_map["09_muIDSys_0"]  =(AnalysisObjects){event->nt_muos,event->nt_eles,     ga0,  event->nt_jets,  event->nt_met, ev0}; km++;
   ev0.weight_leptonSF=ev0.weight_leptonSF_MU_SF_ID_SYST_DOWN;
                                                       analysis_objs_map["09_muIDSys_1"]  =(AnalysisObjects){event->nt_muos,event->nt_eles,     ga0,  event->nt_jets,  event->nt_met, ev0}; km++;
   ev0.weight_leptonSF=ev0.weight_leptonSF_MU_SF_ID_STAT_LOWPT_UP;
                                                       analysis_objs_map["10_muIDStatLowPT_0"]=(AnalysisObjects){event->nt_muos,event->nt_eles, ga0,  event->nt_jets,  event->nt_met, ev0}; km++;
   ev0.weight_leptonSF=ev0.weight_leptonSF_MU_SF_ID_STAT_LOWPT_DOWN;
                                                       analysis_objs_map["10_muIDStatLowPT_1"]=(AnalysisObjects){event->nt_muos,event->nt_eles, ga0,  event->nt_jets,  event->nt_met, ev0}; km++;
   ev0.weight_leptonSF=ev0.weight_leptonSF_MU_SF_ID_SYST_LOWPT_UP;
                                                       analysis_objs_map["11_muIDSysLowPT_0"] =(AnalysisObjects){event->nt_muos,event->nt_eles, ga0,  event->nt_jets,  event->nt_met, ev0}; km++;
   ev0.weight_leptonSF=ev0.weight_leptonSF_MU_SF_ID_SYST_LOWPT_DOWN;
                                                       analysis_objs_map["11_muIDSysLowPT_1"] =(AnalysisObjects){event->nt_muos,event->nt_eles, ga0,  event->nt_jets,  event->nt_met, ev0}; km++;
   ev0.weight_leptonSF=ev0.weight_leptonSF_MU_SF_Isol_STAT_UP;
                                                       analysis_objs_map["12_muISOLStat_0"]   =(AnalysisObjects){event->nt_muos,event->nt_eles, ga0,  event->nt_jets,  event->nt_met, ev0}; km++;
   ev0.weight_leptonSF=ev0.weight_leptonSF_MU_SF_Isol_STAT_DOWN;
                                                       analysis_objs_map["12_muISOLStat_1"]   =(AnalysisObjects){event->nt_muos,event->nt_eles, ga0,  event->nt_jets,  event->nt_met, ev0}; km++;
   ev0.weight_leptonSF=ev0.weight_leptonSF_MU_SF_Isol_SYST_UP;
                                                       analysis_objs_map["13_muISOLSys_0"]    =(AnalysisObjects){event->nt_muos,event->nt_eles, ga0,  event->nt_jets,  event->nt_met, ev0}; km++;
   ev0.weight_leptonSF=ev0.weight_leptonSF_MU_SF_Isol_SYST_DOWN;
                                                       analysis_objs_map["13_muISOLSys_1"]    =(AnalysisObjects){event->nt_muos,event->nt_eles, ga0,  event->nt_jets,  event->nt_met, ev0}; km++;
   ev0.weight_leptonSF=ev0.weight_leptonSF_MU_SF_TTVA_STAT_UP;
                                                       analysis_objs_map["14_muTTVAStat_0"]   =(AnalysisObjects){event->nt_muos,event->nt_eles, ga0,  event->nt_jets,  event->nt_met, ev0}; km++;
   ev0.weight_leptonSF=ev0.weight_leptonSF_MU_SF_TTVA_STAT_DOWN;
                                                       analysis_objs_map["14_muTTVAStat_1"]   =(AnalysisObjects){event->nt_muos,event->nt_eles, ga0,  event->nt_jets,  event->nt_met, ev0}; km++;
   ev0.weight_leptonSF=ev0.weight_leptonSF_MU_SF_TTVA_SYST_UP;
                                                       analysis_objs_map["15_muTTVASys_0"]    =(AnalysisObjects){event->nt_muos,event->nt_eles, ga0,  event->nt_jets,  event->nt_met, ev0}; km++;
   ev0.weight_leptonSF=ev0.weight_leptonSF_MU_SF_TTVA_SYST_DOWN;
                                                        analysis_objs_map["15_muTTVASys_1"]   =(AnalysisObjects){event->nt_muos,event->nt_eles, ga0,  event->nt_jets,  event->nt_met, ev0}; km++;
   ev0.weight_bTagSF_77=ev0.weight_bTagSF_77_extrapolation_up;
                                                        analysis_objs_map["16_btagSF77extraP_0"] =(AnalysisObjects){event->nt_muos,event->nt_eles, ga0,  event->nt_jets,  event->nt_met, ev0}; km++;
   ev0.weight_bTagSF_77=ev0.weight_bTagSF_77_extrapolation_down;
                                                        analysis_objs_map["16_btagSF77extraP_1"] =(AnalysisObjects){event->nt_muos,event->nt_eles, ga0,  event->nt_jets,  event->nt_met, ev0}; km++;
   ev0.weight_bTagSF_77=ev0.weight_bTagSF_77_extrapolation_from_charm_up;
                                                        analysis_objs_map["17_btagSF77extraPfromC_0"] =(AnalysisObjects){event->nt_muos,event->nt_eles, ga0,  event->nt_jets,  event->nt_met, ev0}; km++;
   ev0.weight_bTagSF_77=ev0.weight_bTagSF_77_extrapolation_from_charm_down;
                                                        analysis_objs_map["17_btagSF77extraPfromC_1"]   =(AnalysisObjects){event->nt_muos,event->nt_eles, ga0,  event->nt_jets,  event->nt_met, ev0}; km++;
   ev0.weight_bTagSF_77=ev0.weight_bTagSF_77_eigenvars_B_up.size();
                                                        analysis_objs_map["18_btagSF77eigenvarsB_0"]   =(AnalysisObjects){event->nt_muos,event->nt_eles, ga0,  event->nt_jets,  event->nt_met, ev0}; km++;
   ev0.weight_bTagSF_77=ev0.weight_bTagSF_77_eigenvars_B_down.size();
                                                        analysis_objs_map["18_btagSF77eigenvarsB_1"]   =(AnalysisObjects){event->nt_muos,event->nt_eles, ga0,  event->nt_jets,  event->nt_met, ev0}; km++;
   ev0.weight_bTagSF_77=ev0.weight_bTagSF_77_eigenvars_C_up.size();
                                                        analysis_objs_map["19_btagSF77eigenvarsC_0"]   =(AnalysisObjects){event->nt_muos,event->nt_eles, ga0,  event->nt_jets,  event->nt_met, ev0}; km++;
   ev0.weight_bTagSF_77=ev0.weight_bTagSF_77_eigenvars_C_down.size();
                                                        analysis_objs_map["19_btagSF77eigenvarsC_1"]   =(AnalysisObjects){event->nt_muos,event->nt_eles, ga0,  event->nt_jets,  event->nt_met, ev0}; km++;
   ev0.weight_bTagSF_77=ev0.weight_bTagSF_77_eigenvars_Light_up.size();
                                                        analysis_objs_map["20_btagSF77eigenvarsLight_0"]   =(AnalysisObjects){event->nt_muos,event->nt_eles, ga0,  event->nt_jets,  event->nt_met, ev0}; km++;
   ev0.weight_bTagSF_77=ev0.weight_bTagSF_77_eigenvars_Light_down.size();
                                                        analysis_objs_map["20_btagSF77eigenvarsLight_1"]   =(AnalysisObjects){event->nt_muos,event->nt_eles, ga0,  event->nt_jets,  event->nt_met, ev0}; km++;
   ev0.weight_jvt=ev0.weight_jvt_UP;
                                                        analysis_objs_map["21_jvt_0"]   =(AnalysisObjects){event->nt_muos,event->nt_eles, ga0,  event->nt_jets,  event->nt_met, ev0}; km++;
   ev0.weight_jvt=ev0.weight_jvt_DOWN;
                                                        analysis_objs_map["21_jvt_1"]   =(AnalysisObjects){event->nt_muos,event->nt_eles, ga0,  event->nt_jets,  event->nt_met, ev0}; km++;


  }
  aCtrl.RunTasks(a0, analysis_objs_map);
// ---------no systematics for now
*/

// now run

        muos_map.insert( pair <string,vector<dbxMuon>     > ("MUO",         muons) );
        eles_map.insert( pair <string,vector<dbxElectron> > ("ELE",     electrons) );
        taus_map.insert( pair <string,vector<dbxTau>      > ("TAU",          taus) );
        gams_map.insert( pair <string,vector<dbxPhoton>   > ("PHO",       photons) );
        jets_map.insert( pair <string,vector<dbxJet>      > ("JET",          jets) );
       ljets_map.insert( pair <string,vector<dbxJet>      > ("FJET",        ljets) );
       truth_map.insert( pair <string,vector<dbxTruth>    > ("Truth",       truth) );
       combo_map.insert( pair <string,vector<dbxParticle> > ("Combo",      combos) );
    constits_map.insert( pair <string,vector<dbxParticle> > ("Constits",  constis) );
         met_map.insert( pair <string,TVector2>             ("MET",           met) );

        AnalysisObjects a0={muos_map, eles_map, taus_map, gams_map, jets_map, ljets_map, truth_map, combo_map, constits_map, met_map,  ev0};
        aCtrl.RunTasks(a0);

   } // end of event loop
   aCtrl.Finalize();

}
