#include "TParameter.h"
#include <TRandom.h>
#include "TText.h"

#include "bp_a.h"
#include "analysis_core.h"
#include "dbx_a.h"

//#define __VERBOSE3__
//#define _CLV_

#ifdef _CLV_
#define DEBUG(a) std::cout<<a
#else
#define DEBUG(a)
#endif

extern int yyparse(list<string> *parts,map<string,Node*>* NodeVars,map<string,vector<myParticle*> >* ListParts,map<int,Node*>* NodeCuts, map<string,Node*>* ObjectCuts, vector<double>* PtEtaInitializations , vector<double>* btagValues);

extern FILE* yyin;
extern int cutcount;


int BPdbxA::plotVariables(int sel) {
 return 0;  
}

//--------------------------
int BPdbxA:: readAnalysisParams() {
  int retval=0;

/* --- we should do this whenever we can't find the txt file but if the ini file is around
  string i2tconverter="./ini2txt.sh ";
         i2tconverter+=cname;
  retval=system(i2tconverter.data());
  if (retval==0) cout<<"ini to txt convestion OK for:"<< cname <<"\n";

*/

  dbxA::ChangeDir(cname);
  TString CardName=cname;
          CardName+="-card.txt";


// ---------------------------DBX style defs
    int kk=1;
    map < string, string > def_names;

/*
     TText info(0,0,DefList2file.Data());
           info.SetName("CLA2defs");
           info.Write();
*/

// ****************************************
//---------------------------DBX style analysis object definitions
// ****************************************
     kk=1;

   TString CutList2file="\n";

// ****************************************
// ---------------------------DBX style cuts
       CutList2file="\n";
       //BPcutlist.setTrigType( TRGm+(TRGe<<2) );//bitwise left shift by 2 for TRGe
       eff->GetXaxis()->SetBinLabel(1,"all Events"); // this is hard coded.
       int kFillHistos=0;
       kk=1;
    
       std::vector<double> PtEtaInitializations(11);
       PtEtaInitializations={15., 15., 15., 15., 15., 2.5, 2.5, 2.5, 2.5, 30, 1, 0};
       vector<double> btagValues=vector<double>(6);

       yyin=fopen(CardName,"r");
       if (yyin==NULL) { cout << "Cardfile "<<CardName<<" has problems, please check\n";}
       cutcount=0;
       retval=yyparse(&parts,&NodeVars,&ListParts,&NodeCuts, &ObjectCuts, &PtEtaInitializations, &btagValues);
       if (retval){
         cout << "\nSYNTAX error check the input file\n";
         exit (99); 
       }
       cout << "\nWe have "<<NodeCuts.size() << " CutLang Cuts and "<<ObjectCuts.size()  <<" CutLang objects cuts\n";

   minpte  = PtEtaInitializations[0];
   minptm  = PtEtaInitializations[1];
   minptj  = PtEtaInitializations[2];
   minptg  = PtEtaInitializations[3];
   maxetae = PtEtaInitializations[4];
   maxetam = PtEtaInitializations[5];
   maxetaj = PtEtaInitializations[6];
   maxetag = PtEtaInitializations[7];
   maxmet  = PtEtaInitializations[8];
   TRGe    = PtEtaInitializations[9];
   TRGm    = PtEtaInitializations[10];

    eff->GetXaxis()->SetBinLabel(1,"all Events"); // this is hard coded.

    DEBUG("CL CUTS: \n");
    std::map<int, Node*>::iterator iter = NodeCuts.begin();
    while(iter != NodeCuts.end())
    {
            DEBUG(" CUT "<<iter->first<<" ");
  //          iter->second->display();
            DEBUG("--->"<<iter->second->getStr()<<"\n");

           TString newLabels=iter->second->getStr();
/*
            TString newLabels="CUT";
                    newLabels+=iter->first;
 */
           eff->GetXaxis()->SetBinLabel(iter->first+1,newLabels); // labels

            DEBUG(std::endl);
            iter++;
    }

#ifdef _CLV__
     cout<<"\n Particle Lists: \n";

     for (map<string,vector<myParticle*> >::iterator it1 = ListParts.begin(); it1 != ListParts.end(); it1++)
         {
         cout << (*it1)->first << ": ";
         for (vector<myParticle*>::iterator lit = it1->second.begin(); lit  != it1->second.end(); lit++)
         cout << (*lit)->type << "_" << (*lit)->index << " ";
         cout << "\n";
         }

    cout<<"\n Particles defintions as given by user: \n";

    std::list<std::string>::iterator it = parts.begin();
    while(it != parts.end())
    {
            std::cout<<(*it)<<std::endl;
            it++;
    }

    cout<<"\n Variables results: \n";
    map<string,Node* >::iterator itv = NodeVars.begin();
    while(itv != NodeVars.end())
    {
            std::cout<<"**************************** "<<itv->first<<endl;
            itv->second->display();
            std::cout<<std::endl;
            itv++;
    }

#endif

//----------put into output file as text

         TText cinfo(0,0,CutList2file.Data());
               cinfo.SetName("CLA2cuts");
               cinfo.Write();

// PUT ANALYSIS PARAMETERS INTO .ROOT //////////////
	
    TParameter<double> *minpte_tmp=new TParameter<double> ("minpte", minpte);
    TParameter<double> *maxetae_tmp=new TParameter<double> ("maxetae", maxetae);
    TParameter<double> *minptm_tmp=new TParameter<double> ("minptm", minptm);
    TParameter<double> *maxetam_tmp=new TParameter<double> ("maxetam", maxetam);
    TParameter<double> *minptj_tmp=new TParameter<double> ("minptj", minptj);
    TParameter<double> *maxetaj_tmp=new TParameter<double> ("maxetaj", maxetaj);
    TParameter<double> *TRGe_tmp=new TParameter<double> ("TRGe", TRGe);
    TParameter<double> *TRGm_tmp=new TParameter<double> ("TRGm", TRGm);

    minpte_tmp->Write("minpte");
    maxetae_tmp->Write("maxetae");
    minptm_tmp->Write("minptm");
    maxetam_tmp->Write("maxetam");
    minptj_tmp->Write("minptj");
    maxetaj_tmp->Write("maxetaj");
    TRGe_tmp->Write("TRGe");
    TRGm_tmp->Write("TRGm");

  return retval;
}

int BPdbxA:: printEfficiencies() {
  int retval=0;
  PrintEfficiencies(eff);
  return retval;
}

int BPdbxA:: initGRL() {
  int retval=0;
  grl_cut=true;
  return retval;
}

int BPdbxA:: bookAdditionalHistos() {
        int retval=0;
        dbxA::ChangeDir(cname);
        int kk=1;
        std::string Hsubdelimiter = ",";
        char HCardName[64];

// read histo defitions from file
        sprintf(HCardName,"%s-histos.txt",cname);

#ifdef __VERBOSE3__
	// Sezen's handmade histograms
	mWHh1 = new TH1D("mWHh1", "Hadronic W best combi (GeV)", 50, 50, 150);
	mWHh2 = new TH1D("mHWh2", "Hadronic W best combi (GeV)", 50, 50, 150);
	mTopHh1 = new TH1D("mTopHh1", "Hadronic top combi (GeV)", 70, 0, 700);
	mTopHh2 = new TH1D("mTopHh2", "Hadronic top combi (GeV)", 70, 0, 700);
	WHbRh1 = new TH1D("WHbRh1", "Angular distance between W1 and bjet", 70, 0, 7);
	WHbRh2 = new TH1D("WHbRh2", "Angular distance between W2 and bjet", 70, 0, 7);
	xWHbRh1 = new TH1D("xWHbRh1", "Hadronic top combi (GeV) after angular cut", 70, 0, 700);
	xWHbRh2 = new TH1D("xWHbRh2", "Hadronic top combi (GeV) after angular cut", 70, 0, 700);
#endif

// ---------------------------DBX style defs from the main file
 TString CardName=cname;
         CardName+="-card.txt";
         map < string, string > def_names;

  return retval;
}

/////////////////////////
int BPdbxA::makeAnalysis(vector<dbxMuon> muons, vector<dbxElectron> electrons, vector <dbxPhoton> photons,
                               vector<dbxJet> jets, TVector2 met, evt_data anevt) {
  int retval=0;

  vector<dbxElectron>  goodElectrons;
  vector<dbxMuon>      goodMuons;
  vector<dbxJet>       goodJets;
  vector<dbxPhoton>    goodPhotons;

  DEBUG("-------------------------------------------------------------------- "<<cname<<"\n");
//----------------------selection of good gams-----------------
        for (UInt_t i=0; i<photons.size(); i++) {
               TLorentzVector gam4p = photons.at(i).lv();
               if (    (gam4p.Pt()  > minptg)
                    && (fabs(gam4p.Eta()) < maxetag)
                  )
                  goodPhotons.push_back(photons.at(i));
        }
//----------------------selection of good electrons-----------------
        for (UInt_t i=0; i<electrons.size(); i++) {
               if ( (electrons.at(i).lv().Pt()  > minpte)    // the electrons should have a minimum PT
                  &&(electrons.at(i).lv().Eta() < maxetae )  // and maximum eta.
                  )
                  goodElectrons.push_back( electrons.at(i) );
        }

//----------------------selection of good muons-----------------
        for (UInt_t i=0; i<muons.size(); i++) {
               TLorentzVector mu4p = muons.at(i).lv();
               if (    (mu4p.Pt()  > minptm)
                    && (fabs(mu4p.Eta()) < maxetam)
                  )
                  goodMuons.push_back(muons.at(i));
        }

//------------selection of good jets----------------------------------
        for (UInt_t i=0; i<jets.size(); i++) {
               TLorentzVector jet4p = jets.at(i).lv();
               if (   (fabs(jet4p.Pt())  > minptj ) // this corresponds to min PT cut
                    && (jet4p.E() >= 0)
                    && (fabs(jet4p.Eta())<= maxetaj) 
                   )
                   goodJets.push_back(jets.at(i) );
        }

///////
        double theLeptonWeight = 1;
        double theFourJetWeight = 1;
        unsigned int njets;
        double evt_weight = 1;

        if(TRGe==2 || TRGm== 2) evt_weight = anevt.weight_mc*anevt.weight_pileup*anevt.weight_jvt;//                                                                                                                                                                 
// --------- INITIAL  # events  ====> C0
        eff->Fill(1, 1);

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    AnalysisObjects a0={goodMuons, goodElectrons, goodPhotons, goodJets, met, anevt};
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~cutLang style preselection
         map < string, vector<dbxElectron> > ele_sets;
         map < string, vector<dbxMuon>     > muo_sets;
         map < string, vector<dbxJet>      > jet_sets;
         map < string, vector<dbxPhoton>   > pho_sets;

// basic analysis objects---- are they needed?
         ele_sets["ELE"]=goodElectrons;
         muo_sets["MUO"]=goodMuons;
         pho_sets["PHO"]=goodPhotons;
         jet_sets["JET"]=goodJets;

         map <string, vector<dbxJet> >::iterator tmpjet;
         map <string, vector<dbxElectron> >::iterator tmpele;
         map <string, vector<dbxMuon> >::iterator tmpmuo;
         map <string, vector<dbxPhoton> >::iterator tmpgam;

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// do we have other objects?
/*
         if ( obj_names.size() > 0) { // remove the if and check...
            for( map<string, vector<string> >::iterator newdef=obj_names.begin(); newdef!=obj_names.end(); ++newdef) {
              DEBUG("-----will now define:"<<newdef->first <<" using "<< newdef->second[0] <<endl);
              map < string,  pair< vector< std::vector<dbxCut*> >, vector< vector<string> > > >::iterator acutset;
              acutset=obj_defs.find(newdef->first);
              if (acutset != obj_defs.end()){
               for (unsigned int k=0; k<(acutset->second).first.size(); k++){
                 switch ( newdef->second[1+k][0] ){
                     case 'J': tmpjet=jet_sets.find(newdef->second[1+k]); 
                            DEBUG("~~~Will use "<< newdef->second[1+k] <<"~~~~\n");
	           	    if (tmpjet != jet_sets.end()){ a0.jets=tmpjet->second; }
	           	    break;
                     case 'E': tmpele=ele_sets.find(newdef->second[1+k]); 
	           	    if (tmpele != ele_sets.end()){ a0.eles=tmpele->second; }
	           	    break;
                     case 'M': tmpmuo=muo_sets.find(newdef->second[1+k]); 
	           	    if (tmpmuo != muo_sets.end()){ a0.muos=tmpmuo->second; }
	           	    break;
                     case 'G': tmpgam=pho_sets.find(newdef->second[1+k]); 
	           	    if (tmpgam != pho_sets.end()){ a0.gams=tmpgam->second; }
	           	    break;
                 }
                 DEBUG(newdef->second[1+k]<<" a0  #J:"<<a0.jets.size()<<" #E:"<<a0.eles.size()<<" #M:"<<a0.muos.size()<<"  #G:"<<a0.gams.size()<<"\n");
                 unsigned int j=0; // j=0 is the first cut in that line, if we have more, like ANDs and ORs, j will increase
                 DEBUG("Obj def sel:"<<((acutset->second).first)[k][j]->getName() <<"    \n");
                 ((acutset->second).first)[k][j]->select(&a0); // execute the selection cut
                 DEBUG("b0  #J:"<<a0.jets.size()<<" #E:"<<a0.eles.size()<<" #M:"<<a0.muos.size()<<"  #G:"<<a0.gams.size()<<"\n");
               }//loop over definition cuts
               switch ( newdef->second[0][0] ){
                     case 'J': jet_sets.insert (pair<string, vector<dbxJet>      >(newdef->first, a0.jets) ); break;
                     case 'E': ele_sets.insert (pair<string, vector<dbxElectron> >(newdef->first, a0.eles) ); break;
                     case 'M': muo_sets.insert (pair<string, vector<dbxMuon>     >(newdef->first, a0.muos) ); break;
                     case 'G': pho_sets.insert (pair<string, vector<dbxPhoton>   >(newdef->first, a0.gams) ); break;
               }

              }//valid cutset for current object
            }//end of object definition loop
         }// any obj def?
*/
/*
#ifdef _CLV_
         for( map<string, vector<dbxJet> >::iterator apart=jet_sets.begin(); apart!=jet_sets.end(); ++apart) 
          cout << apart->first<<" is defined with " << (apart->second).size()<< " elements\n";
         for( map<string, vector<dbxElectron> >::iterator apart=ele_sets.begin(); apart!=ele_sets.end(); ++apart) 
          cout << apart->first<<" is defined with " << (apart->second).size()<< " elements\n";
         for( map<string, vector<dbxMuon> >::iterator apart=muo_sets.begin(); apart!=muo_sets.end(); ++apart) 
          cout << apart->first<<" is defined with " << (apart->second).size()<< " elements\n";
         for( map<string, vector<dbxPhoton> >::iterator apart=pho_sets.begin(); apart!=pho_sets.end(); ++apart) 
          cout << apart->first<<" is defined with " << (apart->second).size()<< " elements\n";
#endif
*/
    unsigned int btagSF_counter=0;
    unsigned int FillHistos_counter=0;
             int ahistid;
           float ahistval;
DEBUG("------------------------------------------------- Event ID:"<<anevt.event_no<<" \n");

//    std::cout<<"\n--------------Starting New Event: "<<anevt.event_no<<"  ";

/*
    found_type_vecs.clear(); found_idx_vecs.clear(); found_idx_origs.clear();
    for (unsigned int k=0; k<mycutlist.size(); k++){
           if (mycutlist[k][0]->getOp()=="~=" || mycutlist[k][0]->getOp()=="!=")  // closest to or far away from
              mycutlist[k][0]->clearFoundVector(); //---- clear previous events findings.
    }
*/


// *************************************
/// CutLang execution starts-------here*
// *************************************

    unsigned int ternaryCount=0;
    std::map<int, Node*>::iterator iter = NodeCuts.begin();
    DEBUG("Start resetting cuts:"<< NodeCuts.size() <<"\n");
//----------------------reset 

    while(iter != NodeCuts.end())
    {   
        iter->second->Reset();
        iter++;
     }

     DEBUG("RESet ALL cuts\n");
    iter = NodeCuts.begin();

//----------------------execute
    while(iter != NodeCuts.end())
    {   
        a0={goodMuons, goodElectrons, goodPhotons, goodJets, met, anevt}; // we start from good ones.

/*
        if ( levelObjectMap.size() > 0) {
              map <int, vector<std::pair<string,string> > >::iterator it;
              it=levelObjectMap.find(k+1); 
              if (it != levelObjectMap.end()){
                  DEBUG("cut predef:"<< it->first << "  ");
                  for (int iobj=0; iobj<it->second.size(); iobj++){
                     DEBUG( it->second.at(iobj).first << " will be used as "<< it->second.at(iobj).second );
//--------here we must replace      e.g.                JETclean will be used as JET
                     switch ( it->second.at(iobj).second[0] ){
                     case 'J': tmpjet=jet_sets.find(it->second.at(iobj).first); 
                            DEBUG("~~~Will use "<< it->second.at(iobj).first <<"~~~~\t");
                            if (tmpjet != jet_sets.end()){ a0.jets=tmpjet->second; }
                            break;
                     case 'E': tmpele=ele_sets.find(it->second.at(iobj).first); 
                            if (tmpele != ele_sets.end()){ a0.eles=tmpele->second; }
                            break;
                     case 'M': tmpmuo=muo_sets.find(it->second.at(iobj).first); 
                            if (tmpmuo != muo_sets.end()){ a0.muos=tmpmuo->second; }
                            break;
                     case 'G': tmpgam=pho_sets.find(it->second.at(iobj).first); 
                            if (tmpgam != pho_sets.end()){ a0.gams=tmpgam->second; }
                            break;
                     }
                  }
                  DEBUG("\n" );
              }
        } 
*/
        unsigned int j=0; // j=0 is the first cut in that line, if we have more, like ANDs and ORs, j will increase 
        double d;

        DEBUG("Selecting: "<<iter->first<<" |");
        d=iter->second->evaluate(&a0); // execute the selection cut

        DEBUG(" Result : " << d << std::endl);
        if (d==0) return iter->first; // quit the event.
        eff->Fill(iter->first+1, evt_weight); // filling starts from 1 which is already filled.
        iter++;
    } // loop over all cutlang cuts
    DEBUG("   EOE\n     ");
return 1;
}
