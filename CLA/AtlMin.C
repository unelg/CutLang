#define AtlMin_cxx
#include "AtlMin.h"
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
#include <iostream>
#include <sstream>      // std::istringstream
#include <string>

//#define _CLV_
#ifdef _CLV_
#define DEBUG(a) std::cout<<a
#else
#define DEBUG(a)
#endif

extern void _fsig_handler (int) ;
extern bool fctrlc;

extern TTreeReader *ttreader;

void AtlMin::GetPhysicsObjects( Long64_t j, AnalysisObjects *a0 )
{

   fChain->GetEntry(j);
   ttreader->Next();

   vector<dbxMuon>     muons;
   vector<dbxElectron> electrons;
   vector<dbxTau>      taus;
   vector<dbxPhoton>   photons;
   vector<dbxJet>      jets;
   vector<dbxJet>    ljets;
   vector<dbxTruth>   truth;
   vector<dbxTrack>    track;
   vector<dbxParticle> combos;
   vector<dbxParticle> constis;

   map<string, vector<dbxMuon>     > muos_map;
   map<string, vector<dbxElectron> > eles_map;
   map<string, vector<dbxTau>      > taus_map;
   map<string, vector<dbxPhoton>   > gams_map;
   map<string, vector<dbxJet>      > jets_map;
   map<string, vector<dbxJet>     >ljets_map;
   map<string, vector<dbxTruth>    >truth_map;
   map<string, vector<dbxTrack>    >track_map;
   map<string, vector<dbxParticle> >combo_map;
   map<string, vector<dbxParticle> >constits_map;
   map<string, TVector2            >  met_map;

   evt_data anevt;

//temporary variables
       TLorentzVector  alv;
       TLorentzVector dummyTlv(0.,0.,0.,0.);
       TVector2 met;
       dbxJet      *adbxj;
       dbxJet      *adbxlj;
       dbxElectron *adbxe;
       dbxMuon     *adbxm;
       //dbxTau      *adbxt;
       dbxPhoton   *adbxp;
       dbxParticle *adbxparticle;

#ifdef __DEBUG__
std::cout << "Begin Filling"<<std::endl;
#endif

// PHOTONS -------- // now truth info
        for (unsigned int i=0; i<truth_pt->size(); i++) {
                alv.SetPtEtaPhiE( truth_pt->at(i)*0.001, truth_eta->at(i), truth_phi->at(i), truth_e->at(i)*0.001 ); // all in GeV
                adbxp= new dbxPhoton(alv);
                adbxp->setCharge(truth_charge->at(i) );
                adbxp->setParticleIndx( truth_pdgID->at(i)    );
                adbxp->setElTriggerMatch( truth_parentIndex->at(i)    );
                photons.push_back(*adbxp);
                delete adbxp;
        }
#ifdef __DEBUG__
std::cout << "Photons OK:"<< truth_pt->size()<<std::endl;
#endif

//MUONS
        for (unsigned int i=0; i<mu_pt->size(); i++) {
                alv.SetPtEtaPhiE( mu_pt->at(i)*0.001, mu_eta->at(i), mu_phi->at(i), mu_e->at(i)*0.001 ); // all in GeV
//                if (i==1) cout <<"********* mu pt:"<<mu_pt->at(i)*0.001<<"\n";
                adbxm= new dbxMuon(alv);
                adbxm->setCharge(mu_charge->at(i) );
		adbxm->setPdgID(-13*mu_charge->at(i) );
                adbxm->setEtCone(mu_topoetcone20->at(i) );
                adbxm->setPtCone(mu_ptvarcone30->at(i)  );
                adbxm->setParticleIndx(i);
                adbxm->setisZCand(mu_isZCand->at(i) );
                adbxm->settrigMatch_HLT_mu26_ivarmedium(mu_trigMatch_HLT_mu26_ivarmedium->at(i));
                adbxm->settrigMatch_HLT_mu50(mu_trigMatch_HLT_mu50->at(i));
                adbxm->settrigMatch_HLT_mu20_iloose_L1MU15(mu_trigMatch_HLT_mu20_iloose_L1MU15->at(i));
                muons.push_back(*adbxm);
                delete adbxm;
        }
#ifdef __DEBUG__
std::cout << "Muons OK:"<< mu_pt->size()<<std::endl;
#endif

//ELECTRONS
        for (unsigned int i=0; i<el_e->size(); i++) {
                alv.SetPtEtaPhiE( el_pt->at(i)*0.001, el_eta->at(i), el_phi->at(i), el_e->at(i)*0.001 ); // all in GeV
                adbxe= new dbxElectron(alv);
                adbxe->setCharge(el_charge->at(i) );
		adbxe->setPdgID(-11*el_charge->at(i) );
                adbxe->setPtCone(el_ptvarcone20->at(i));// 30 has 20 !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
                adbxe->setEtCone20(el_ptvarcone20->at(i) );
                adbxe->settrue_origin(el_true_origin->at(i));
                adbxe->settrue_type(el_true_type->at(i));
                adbxe->setParticleIndx(i);
                adbxe->setClusterEta(el_cl_eta->at(i) );
                adbxe->setd0sig(el_d0sig->at(i) );
                adbxe->setdelta_z0_sintheta(el_delta_z0_sintheta->at(i) );
                adbxe->setisZCand(el_isZCand->at(i) );
                adbxe->settrigMatch_HLT_e60_lhmedium_nod0(el_trigMatch_HLT_e60_lhmedium_nod0->at(i));
                adbxe->settrigMatch_HLT_e26_lhtight_nod0_ivarloose(el_trigMatch_HLT_e26_lhtight_nod0_ivarloose->at(i));
                adbxe->settrigMatch_HLT_e140_lhloose_nod0(el_trigMatch_HLT_e140_lhloose_nod0->at(i));
                adbxe->settrigMatch_HLT_e60_lhmedium(el_trigMatch_HLT_e60_lhmedium->at(i));
                adbxe->settrigMatch_HLT_e24_lhmedium_L1EM20VH(el_trigMatch_HLT_e24_lhmedium_L1EM20VH->at(i));
                adbxe->settrigMatch_HLT_e120_lhloose(el_trigMatch_HLT_e120_lhloose->at(i));

                electrons.push_back(*adbxe);
                delete adbxe;
        }

#ifdef __DEBUG__
std::cout << "Electrons OK:"<< el_e->size() <<std::endl;
#endif

//JETS
        for (unsigned int i=0; i<jet_pt->size(); i++) {
                alv.SetPtEtaPhiE( jet_pt->at(i)*0.001, jet_eta->at(i), jet_phi->at(i), jet_e->at(i)*0.001 ); // all in GeV
                adbxj= new dbxJet(alv);
                adbxj->setCharge(-99);
                adbxj->setjvt(jet_jvt->at(i));
                adbxj->setParticleIndx(i);
                adbxj->setFlavor(jet_truthflav->at(i) );
                adbxj->set_isbtagged_77(bool(jet_isbtagged_MV2c10_77->at(i)));
//                            if  (jet_isbtagged_MV2c10_77->at(i)>0)  std::cout << bool(jet_isbtagged_MV2c10_77->at(i)) <<"\n";
                adbxj->setmv2c00(jet_mv2c00->at(i));
                adbxj->setmv2c10(jet_mv2c10->at(i));
                adbxj->setmv2c20(jet_mv2c20->at(i));
                adbxj->setip3dsv1(jet_ip3dsv1->at(i));

                jets.push_back(*adbxj);
                delete adbxj;
        }
#ifdef __DEBUG__
std::cout << "Jets OK:"<< jet_pt->size() <<std::endl;
#endif
//MET
        met.SetMagPhi( met_met*0.001,  met_phi); //mev-->gev
#ifdef __DEBUG__
std::cout << "MET OK"<<std::endl;
#endif
    
    //LJETS
         
         for (unsigned int i=0; i<rcjet_pt->size(); i++) {
             alv.SetPtEtaPhiE( rcjet_pt->at(i)*0.001, rcjet_eta->at(i), rcjet_phi->at(i), rcjet_e->at(i)*0.001 ); // all in GeV
             adbxlj= new dbxJet(alv);
             //adbxlj->set_rcjetsub_mv2c10_isbtagged(rcjetsub_mv2c10->at(i));
             /*for (unsigned int i=0; i<rcjetsub_mv2c10->size(); i++) {
                 adbxlj->rcjetsub_mv2c10_isbtagged(rcjetsub_mv2c10->at(i));
             }*/
             
             bool is_bljet = false;
             for (unsigned int j=0; j<rcjetsub_mv2c10->at(i).size(); j++) { // this is loop over subjets
               alv.SetPtEtaPhiE( rcjetsub_pt->at(i).at(j)*0.001, rcjetsub_eta->at(i).at(j), rcjetsub_phi->at(i).at(j), rcjetsub_e->at(i).at(j)*0.001);
               adbxparticle = new dbxParticle(alv);
               constis.push_back(*adbxparticle);
               delete adbxparticle;              
               if (rcjetsub_mv2c10->at(i).at(j) > 0.77 ) is_bljet = true;
             }
             DEBUG("FJET:"<<i<< "  #childen:"<< rcjetsub_mv2c10->at(i).size()<<"\n");
             adbxlj->setParticleIndx(i);
             adbxlj->set_isbtagged_77(is_bljet);
             adbxlj->addAttribute( 0);   // 0
             adbxlj->addAttribute( 0);  // 1 
             adbxlj->addAttribute( 0); // this is dummy, as we dont have isolation variable for GEN particles(unlike e,m,photon)
             adbxlj->addAttribute( 0); // 3
             adbxlj->addAttribute( 0);  //4
             adbxlj->addAttribute( 0);  //5
             adbxlj->addAttribute( 0);  //6
             adbxlj->addAttribute( 0);  //7
             adbxlj->addAttribute( 1);  //8
             adbxlj->addAttribute( rcjetsub_mv2c10->at(i).size() );  //9
             
             ljets.push_back(*adbxlj);
             delete adbxlj;

             if (constis.size() > 0){
               TString cname ="FJET_";
               cname+=i;    // ljet index
               cname+="c"; //  c for constituents
               constits_map.insert( pair <string,vector<dbxParticle> > (cname.Data(), constis) );
               DEBUG("Inserting "<<cname<<" :"<<constis.size()<<"\n");
               constis.clear();
             }
           }// end of loop over ljets
           DEBUG("LJets OK:"<< rcjet_pt->size() <<std::endl);

//        cout<<"Evt:"<<eventNumber<<"\n";

        anevt.run_no=runNumber;
        anevt.user_evt_weight=1;
        anevt.event_no=eventNumber;
        anevt.lumiblk_no=1;
        anevt.top_hfor_type=0;
        anevt.TRG_e= 1;
        anevt.TRG_m= 0;
        anevt.TRG_j= 0;
        anevt.vxp_maxtrk_no= 1;
        anevt.badjet=0;

  anevt.weight_mc=weight_mc;
  anevt.weight_pileup=weight_pileup;
  anevt.weight_leptonSF=weight_leptonSF;
  anevt.weight_bTagSF_77=weight_bTagSF_MV2c10_77;
  anevt.weight_jvt=weight_jvt;
  DEBUG("Filling finished."<<std::endl);

        muos_map.insert( pair <string,vector<dbxMuon>     > ("MUO",         muons) );
        eles_map.insert( pair <string,vector<dbxElectron> > ("ELE",     electrons) );
        taus_map.insert( pair <string,vector<dbxTau>      > ("TAU",          taus) );
        gams_map.insert( pair <string,vector<dbxPhoton>   > ("PHO",       photons) );
        jets_map.insert( pair <string,vector<dbxJet>      > ("JET",          jets) );
       ljets_map.insert( pair <string,vector<dbxJet>     > ("FJET",        ljets) );
       truth_map.insert( pair <string,vector<dbxTruth>    > ("Truth",       truth) );
       track_map.insert( pair <string,vector<dbxTrack>    > ("Track",       track) );
       combo_map.insert( pair <string,vector<dbxParticle> > ("Combo",      combos) );
    constits_map.insert( pair <string,vector<dbxParticle> > ("Constits",  constis) );
         met_map.insert( pair <string,TVector2>             ("MET",           met) );
  DEBUG("MAP finished."<<std::endl);

        *a0={muos_map, eles_map, taus_map, gams_map, jets_map, ljets_map, truth_map,track_map, combo_map, constits_map, met_map, anevt};
  DEBUG("retuning"<<std::endl);
}

//--------------------------------------------------------LOOP
void AtlMin::Loop( analy_struct aselect, char *extname)
{
// Signal HANDLER
  signal (SIGINT, _fsig_handler); // signal handler has issues with CINT
   TFile *afile= ((TChain *)fChain)->GetFile();

   if (fChain == 0) {
          cout <<"Error opening the data file"<<endl; return;
   }
   int verboseFreq(aselect.verbfreq);
   bool  doSystematics(aselect.dosystematics);
   map < string, syst_struct > systematics; // contains all
   map < string, string > syst_names; // contains all
   map < string, AtlMin *> syst_objects;

   if (doSystematics) {
       string tempLine;
       cout << "Reading available systematics from ini file...\n";
       TString CardName="BP_1-card.ini";
       ifstream cardfile(CardName);
       if ( ! cardfile.good()) {
         cerr << "The cardfile " << CardName << " file has problems... " << endl;
       }
       int systindex=0;
       while ( ! cardfile.eof() ) {
          getline( cardfile, tempLine );
          if ( tempLine[0] == '#' ) continue; // skip comment lines starting with #
          if (tempLine.find_first_of("#") != std::string::npos ){ // skip anything after #
            tempLine.erase(tempLine.find_first_of("#"));
          }
          if (tempLine.size() < 3) continue; // skip the junk

          std::istringstream iss(tempLine);
          std::vector<std::string> resultstr((std::istream_iterator<std::string>(iss)), std::istream_iterator<std::string>());
          if (resultstr.size() < 1) continue;
          string firstword=resultstr[0];
          for(auto& c : firstword) { c = tolower(c); } // convert to lowercase

//---------do we have a systematic or NOT ?
         if (firstword == "systematic" ) {
              string ison=resultstr[1];
              for(auto& c : ison) { c = tolower(c); } // convert to lowercase
              if (ison == "on") {
                resultstr[2].erase(remove( resultstr[2].begin(), resultstr[2].end(), '\"' ),resultstr[2].end());
                resultstr[3].erase(remove( resultstr[3].begin(), resultstr[3].end(), '\"' ),resultstr[3].end());
                DEBUG("--> Syst  "<< resultstr[2] << " &&  " << resultstr[3]<<" "<<resultstr[4] <<"\n");
                if ( resultstr[4] != "ttree" ) { // maybe sshould contain weight
		 for (int ri=2; ri<4; ri++){
                  size_t findex = resultstr[ri].find_first_of("[");
                  syst_struct asyst;
                  if (findex == std::string::npos ){ // without any []
                      asyst.index=systindex;
                      asyst.vartype=resultstr[4];
                      asyst.varname=resultstr[ri];
                      asyst.varid=0;
                      asyst.systname=resultstr[ri];// I am double counting
                      systematics[ resultstr[ri] ] = asyst;  // add a simple variable
                      syst_names[ resultstr[ri] ] = resultstr[4];  // add a simple variable
                  } else { // here we have [] lets find the numbers
                      size_t lindex = resultstr[ri].find_first_of("]");
                      string numsection=resultstr[ri].substr(findex+1, lindex-findex-1);
                      string delimiters=",";
                      resultstr[ri].erase(findex);
                      stringstream jss(numsection);
                      string intermediate;
                      while(getline(jss, intermediate, ',')) {
                            cout <<" select subset @" << intermediate << " of "<< resultstr[ri] <<"\n";
                            string asysname=resultstr[ri]+"["+intermediate+"]";
                            //cout <<"==========>"<< asysname <<"\n";
                            asyst.vartype=resultstr[4];
                            asyst.varname=resultstr[ri];
                            asyst.systname=asysname;
                            asyst.varid=stoi(intermediate);
                            asyst.index=systindex;
                            systematics[asysname] = asyst ; // with []
                            syst_names[asysname] = resultstr[4] ; // with []
                      }
                  }
                  systindex++;
                  freaders.push_back(TTreeReaderArray<Float_t>(*ttreader, resultstr[ri].c_str() ) ); //push only the generic name
                  cout <<ri<<" finished\n";
                 }//2 3 counting
               } else { // tree
                    string xxx="XXX";
                    syst_names[resultstr[2]] = resultstr[4] ; // with []
                    syst_names[resultstr[3]] = resultstr[4] ; // with []
                    syst_struct asyst;
                    asyst.vartype=resultstr[4];
                    asyst.varname=resultstr[2];
                    asyst.systname=resultstr[2];
                    asyst.varid=-1;
                    asyst.index=systindex;
                    syst_names[resultstr[2]] = resultstr[4] ; // with []
                    systematics[resultstr[2]] = asyst ; // with []
                    syst_objects[resultstr[2]] = new AtlMin((char*)xxx.c_str() ,(TChain *)afile->Get(resultstr[2].c_str()) );
                    systindex++;
                    syst_struct bsyst;
                    bsyst.vartype=resultstr[4];
                    bsyst.varname=resultstr[3];
                    bsyst.systname=resultstr[3];
                    bsyst.varid=-1;
                    bsyst.index=systindex;
                    syst_names[resultstr[3]] = resultstr[4] ; // with []
                    syst_objects[resultstr[3]]=new AtlMin((char*)xxx.c_str(),(TChain *)afile->Get(resultstr[3].c_str()) );
                    systematics[resultstr[3]] = bsyst ; // with []
                    systindex++;

                    // TFile * _afile = TFile::Open(fileList[0].c_str());
                    // ttreader =  new TTreeReader(leafname.c_str(), _afile);
               }
              }// end of systematics on
             continue;
          }
          
       }// end of while reading the file
   }// end of do systematics


//--------------start stop event ids etc
   map < string,   AnalysisObjects > analysis_objs_map;

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

// ******************************************************************
   for (Long64_t j=startevent; j<lastevent; ++j) { // event loop here

     //  if ( fctrlc ) { cout << "Processed " << j << " events\n"; break; }
       if (0 > LoadTree (j)) break;
       if ( j%verboseFreq == 0 ) cout << "Processing event " << j << endl;

       AnalysisObjects a0;
       GetPhysicsObjects(j, &a0);
       evt_data oldevt=a0.evt;
       double wvalue;

       for (map<string,syst_struct>::iterator it = systematics.begin(); it != systematics.end(); it++) {

         int jsyst=it->second.index;
         int jid=it->second.varid;
         if (jid >=0){
           wvalue = freaders.at(jsyst)[jid]; //may not be zero?
//           cout <<"Wv:"<<wvalue<<"\n";
           if (jsyst>0) a0.evt=oldevt;
         }
         if (it->second.vartype ==  "weight_jvt" ) {
                a0.evt.weight_jvt=wvalue; // cout <<  "jvt\n";
         	analysis_objs_map[it->first] = a0;
         } else if (it->second.vartype == "weight_pileup" ) {
                a0.evt.weight_pileup=wvalue; // cout <<  "pileup\n";
         	analysis_objs_map[it->first] = a0;
         } else if (it->second.vartype == "weight_leptonSF" ) {
                a0.evt.weight_leptonSF=wvalue; //  cout <<  "SF\n";
         	analysis_objs_map[it->first] = a0;
         } else if (it->second.vartype == "weight_BTagSF" ) {
                a0.evt.weight_bTagSF_77=wvalue; //  cout <<  "w BTAG:" << wvalue <<"\n";
         	analysis_objs_map[it->first] = a0;
         } else if (it->second.vartype == "ttree" ) {
		AnalysisObjects au;
//            	Init(it->second.chain,0); 
//                 atlmin_sau->GetPhysicsObjects(j, &au);
//        	GetPhysicsObjects(j, &au);
             	syst_objects[it->first]->GetPhysicsObjects(j, &au);
        	analysis_objs_map[it->first] = au;
  	      it++;
		AnalysisObjects ad;
//              	Init(it->second.chain,0); 
// 	       		GetPhysicsObjects(j, &ad);
                syst_objects[it->first]->GetPhysicsObjects(j, &ad);
        	analysis_objs_map[it->first] = ad;

         } else {
	        cout << "problem with: "<<it->second.vartype<< ", no such systematics type.\n";
         }
       } // end of loop over syst subsyst name

       a0.evt=oldevt;
       aCtrl.RunTasks(a0, analysis_objs_map);

  }// event loop ends.
  aCtrl.Finalize();

}
