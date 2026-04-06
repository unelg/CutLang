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
#include <unordered_map>

//#define _CLV_
#ifdef _CLV_
#define DEBUG(a) std::cout<<a
#else
#define DEBUG(a)
#endif
  
extern void _fsig_handler (int) ;
extern bool fctrlc;

extern map<string, TTreeReader*> ttr_map;

void AtlMin::GetPhysicsObjects( Long64_t j, AnalysisObjects *a0 )
{
   AnalysisObjects &ao = *a0;

   fChain->GetEntry(j);

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

   unordered_map<string, vector<dbxMuon> > muos_map;
   unordered_map<string, vector<dbxElectron> > eles_map;
   unordered_map<string, vector<dbxTau> > taus_map;
   unordered_map<string, vector<dbxPhoton> > gams_map;
   unordered_map<string, vector<dbxJet> > jets_map;
   unordered_map<string, vector<dbxJet> >ljets_map;
   unordered_map<string, vector<dbxTruth> >truth_map;
   unordered_map<string, vector<dbxTrack> >track_map;
   unordered_map<string, vector<dbxParticle> >combo_map;
   unordered_map<string, vector<dbxParticle> >constits_map;
   unordered_map<string, TVector2 >  met_map;

   evt_data anevt;

//temporary variables
       TLorentzVector  alv;
       TLorentzVector dummyTlv(0.,0.,0.,0.);
       TVector2 met;

 DEBUG("Begin Filling MUONS\n");

/*
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


*/
//MUONS
              for (unsigned int i=0; i<mu_e->size(); i++) {
                alv.SetPtEtaPhiE( mu_pt->at(i)*0.001, mu_eta->at(i), mu_phi->at(i), mu_e->at(i)*0.001 ); // all in GeV
//                if (i==1) cout <<"********* mu Z:"<<mu_isZCand->at(i)<<"\n";
                muons.emplace_back(alv);
                muons.back().setCharge(mu_charge->at(i) );
		muons.back().setPdgID(-13*mu_charge->at(i) );
                muons.back().setParticleIndx(i);
        }

DEBUG("Muons OK:"<< mu_pt->size()<<std::endl);


//ELECTRONS
        for (unsigned int i=0; i<el_e->size(); i++) {
                alv.SetPtEtaPhiE( el_pt->at(i)*0.001, el_eta->at(i), el_phi->at(i), el_e->at(i)*0.001 ); // all in GeV
                electrons.emplace_back(alv);
                electrons.back().setCharge(el_charge->at(i) );
		electrons.back().setPdgID(-11*el_charge->at(i) );
                electrons.back().setPtCone(el_ptvarcone20->at(i));// 30 has 20 !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
                electrons.back().setEtCone20(el_ptvarcone20->at(i) );
                if (b_el_true_origin) electrons.back().settrue_origin(el_true_origin->at(i));
                if (b_el_true_type) electrons.back().settrue_type(el_true_type->at(i));
                electrons.back().setParticleIndx(i);
                electrons.back().setClusterEta(el_cl_eta->at(i) );
                electrons.back().setd0sig(el_d0sig->at(i) );
                electrons.back().setdelta_z0_sintheta(el_delta_z0_sintheta->at(i) );
                electrons.back().setisZCand(el_isZCand->at(i) );
                electrons.back().settrigMatch_HLT_e60_lhmedium_nod0(el_trigMatch_HLT_e60_lhmedium_nod0->at(i));
                electrons.back().settrigMatch_HLT_e26_lhtight_nod0_ivarloose(el_trigMatch_HLT_e26_lhtight_nod0_ivarloose->at(i));
                electrons.back().settrigMatch_HLT_e140_lhloose_nod0(el_trigMatch_HLT_e140_lhloose_nod0->at(i));
                electrons.back().settrigMatch_HLT_e60_lhmedium(el_trigMatch_HLT_e60_lhmedium->at(i));
                electrons.back().settrigMatch_HLT_e24_lhmedium_L1EM20VH(el_trigMatch_HLT_e24_lhmedium_L1EM20VH->at(i));
                electrons.back().settrigMatch_HLT_e120_lhloose(el_trigMatch_HLT_e120_lhloose->at(i));
        }



DEBUG("Electrons OK:"<< el_e->size() <<std::endl);

//JETS
        for (unsigned int i=0; i<jet_pt->size(); i++) {
                alv.SetPtEtaPhiE( jet_pt->at(i)*0.001, jet_eta->at(i), jet_phi->at(i), jet_e->at(i)*0.001 ); // all in GeV
                jets.emplace_back(alv);
                jets.back().setCharge(-99);
                jets.back().setjvt(jet_jvt->at(i));
                jets.back().setParticleIndx(i);
                if (b_jet_truthflav != NULL) jets.back().setFlavor(jet_truthflav->at(i) );
                jets.back().set_isbtagged_77(bool(jet_isbtagged_DL1r_77->at(i)));
        }
 DEBUG("Jets OK:"<< jet_pt->size() <<std::endl);
//MET
        met.SetMagPhi( met_met*0.001,  met_phi); //mev-->gev
 DEBUG("MET OK"<<std::endl );

    
    //LJETS
         
         for (unsigned int i=0; i<vrcjet_2m_t_pt->size(); i++) {
             alv.SetPtEtaPhiE( vrcjet_2m_t_pt->at(i)*0.001, vrcjet_2m_t_eta->at(i), vrcjet_2m_t_phi->at(i), vrcjet_2m_t_e->at(i)*0.001 ); // all in GeV
             ljets.emplace_back(alv);
             
             bool is_bljet = false;
             for (unsigned int j=0; j<vrcjetsub_2m_t_pt->at(i).size(); j++) { // this is loop over subjets
               alv.SetPtEtaPhiE( vrcjetsub_2m_t_pt->at(i).at(j)*0.001, vrcjetsub_2m_t_eta->at(i).at(j), vrcjetsub_2m_t_phi->at(i).at(j), vrcjetsub_2m_t_e->at(i).at(j)*0.001);
               constis.emplace_back(alv);
               if (vrcjetsub_2m_t_mv2c10->at(i).at(j) > 0.77 ) is_bljet = true;
             }
             DEBUG("FJET:"<<i<< "  #childen:"<< vrcjetsub_2m_t_mv2c10->at(i).size()<<"\n");
             ljets.back().setParticleIndx(i);
             ljets.back().set_isbtagged_77(is_bljet);
             ljets.back().addAttribute( 0);   // 0
             ljets.back().addAttribute( 0);  // 1 
             ljets.back().addAttribute( 0); // this is dummy, as we dont have isolation variable for GEN particles(unlike e,m,photon)
             ljets.back().addAttribute( 0); // 3
             ljets.back().addAttribute( 0);  //4
             ljets.back().addAttribute( 0);  //5
             ljets.back().addAttribute( 0);  //6
             ljets.back().addAttribute( 0);  //7
             ljets.back().addAttribute( 1);  //8
             ljets.back().addAttribute( vrcjetsub_2m_t_mv2c10->at(i).size() );  //9

             if (constis.size() > 0){
               TString cname ="FJET_";
               cname+=i;    // ljet index
               cname+="c"; //  c for constituents
               constits_map.insert( pair <string,vector<dbxParticle> > (cname.Data(), constis) );
               DEBUG("Inserting "<<cname<<" :"<<constis.size()<<"\n");
               constis.clear();
             }
           }// end of loop over ljets
           DEBUG("LJets OK:"<< ljets.size() <<std::endl);

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
  anevt.weight_bTagSF_77=weight_bTagSF_DL1r_77; // was weight_bTagSF_MV2c10_77;
  anevt.weight_jvt=weight_jvt;
  DEBUG("Filling finished."<<std::endl);

        muos_map["MUO"].swap(muons);
        eles_map["ELE"].swap(electrons);
        taus_map["TAU"].swap(taus);
        gams_map["PHO"].swap(photons);
        jets_map["JET"].swap(jets);
        ljets_map["FJET"].swap(ljets);
        truth_map["Truth"].swap(truth);
        track_map["Track"].swap(track);
        combo_map["Combo"].swap(combos);
        constits_map["Constits"].swap(constis);
        met_map["MET"] = met;
  DEBUG("MAP finished."<<std::endl);

        ao.muos=muos_map;
        ao.eles=eles_map;
        ao.taus=taus_map;
        ao.gams=gams_map;
        ao.jets=jets_map;
        ao.ljets=ljets_map;
        ao.truth=truth_map;
        ao.track=track_map;
        ao.combos=combo_map;
        ao.constits=constits_map;
        ao.met=met_map;
        ao.evt = anevt;
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
   map < string, AtlMin*> syst_objects;

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
                  freaders.push_back(TTreeReaderArray<Float_t>( *(ttr_map["nominal"]), resultstr[ri].c_str() ) ); //push only the generic name
             //     cout <<"XXXXXXXXXXXXXXXXX:"<<ri<<" "<< resultstr[ri]<< " @:"<< ttr_map["nominal"] <<" finished\n";
                 }//2 3 counting
               } else { // tree
                    string xxx="XXX";
                    syst_names[resultstr[2]] = resultstr[4] ; // with []
                    syst_names[resultstr[3]] = resultstr[4] ; // with []
                    
             //       cout << "B r2:"<< resultstr[2]<<" r3:"<<resultstr[3]<<" r4:"<<resultstr[4]<<"\n";                   

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
                    cout << "A r2:"<< resultstr[2]<<" r3:"<<resultstr[3]<<" r4:"<<resultstr[4]<<"\n";                   

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
       ttr_map["nominal"]->SetEntry(j);
       evt_data oldevt=a0.evt;
       double wvalue=0;
       


       for (map<string,syst_struct>::iterator it = systematics.begin(); it != systematics.end(); it++) {

 //        cout << "it nam:"<<it->first<<"\t"<<it->second.vartype<<"\t" ;
         int jsyst=it->second.index;
         int jid=it->second.varid;
 //        cout <<" jsyst:"<<jsyst <<" jid:"<< jid<<"\n";
         if (jid >=0){
           wvalue = freaders.at(jsyst)[jid]; //may not be zero?
 //          cout <<"Wv:"<<wvalue<<"\n";
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
		AnalysisObjects ad;
   //             cout<<"NAme D:"<<it->first<<"\n";
             	syst_objects[it->first]->GetPhysicsObjects(j, &ad);
        	analysis_objs_map[it->first] = ad;
  	      it++;
		AnalysisObjects au;
     //           cout<<"NAme U:"<<it->first<<"\n";
                syst_objects[it->first]->GetPhysicsObjects(j, &au);
        	analysis_objs_map[it->first] = au;

             for ( map<string, TTreeReader*>::iterator itr=ttr_map.begin(); itr!= ttr_map.end(); itr++){
                     (itr->second)->SetEntry(j);
             }


         } else {
	        cout << "problem with: "<<it->second.vartype<< ", no such systematics type.\n";
         }
       } // end of loop over syst subsyst name

       a0.evt=oldevt;
       aCtrl.RunTasks(a0, analysis_objs_map);

  }// event loop ends.
  aCtrl.Finalize();

}
