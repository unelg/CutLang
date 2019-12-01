#include "TParameter.h"
#include <TRandom.h>
#include "TText.h"

#include "bp_a.h"
#include "analysis_core.h"
#include "dbx_a.h"

//#define __SEZEN__
//#define _CLV_

#ifdef _CLV_
#define DEBUG(a) std::cout<<a
#else
#define DEBUG(a)
#endif

extern int yyparse(list<string> *parts,map<string,Node*>* NodeVars,map<string,vector<myParticle*> >* ListParts,map<int,Node*>* NodeCuts, map<string,Node*>* ObjectCuts, vector<string>* Initializations, vector<double>* TRGValues, map<string,vector<float> >* ListTables);

extern FILE* yyin;
extern int cutcount;

int BPdbxA::getInputs(std::string aname) {
        int retval=0;
        ntsave = new DBXNtuple();
        std::string fname="lvl0_";
                    fname+=aname;
                    fname+=".root";
        ftsave = new TFile (fname.c_str(),"RECREATE"); // il faut changer le nom du fichier
        ttsave = new TTree ("nt_tree", "saving data on the grid");
        ttsave->Branch("dbxAsave", ntsave);
        return retval;
}

int BPdbxA::plotVariables(int sel) {
 return 0;  
}

//--------------------------
int BPdbxA:: readAnalysisParams() {
  int retval=0;

//  dbxA::ChangeDir(cname);
  TString CardName=cname;
          CardName+="-card.ini";

  ifstream cardfile(CardName);
  if ( ! cardfile.good()) {
    cerr << "The cardfile " << CardName << " file has problems... " << endl;
    return -1;
  }

// ---------------------------DBX style defs, objects and cuts
    string tempLine;
    string tempS1, tempS2;
    string subdelimiter = " ";
    string hashdelimiter = "#";
    size_t found, foundp, foundr, foundw, founds;
    TString DefList2file="\n";
    TString CutList2file="\n";
    TString ObjList2file="\n";

    bool algorithmnow=false;

    while ( ! cardfile.eof() ) {
       getline( cardfile, tempLine );
       if ( tempLine[0] == '#' ) continue; // skip comment lines
       if (tempLine.find_first_of("#") != std::string::npos ){
         tempLine.erase(tempLine.find_first_of("#"));
       }
//---------obj
       found = tempLine.find("obj ");
       if (found!=std::string::npos) {
           ObjList2file+=tempLine;
           ObjList2file+="\n";
           continue;
       }
       found = tempLine.find("object ");
       if (found!=std::string::npos) {
           ObjList2file+=tempLine;
           ObjList2file+="\n";
           continue;
       }

//---------algo
       found =tempLine.find("algo ") ;
       if (found!=std::string::npos) {
           tempS1 = tempLine.substr(found+5, std::string::npos );
           tempS1.erase(tempS1.find_last_not_of(" \n\r\t")+1);
           if (tempS1[0]==' ') tempS1 = tempS1.substr(tempS1.find_first_not_of(" \n\r\t"), std::string::npos );
           cout <<"\t ALGO:"<< tempS1 <<"\n";
           algorithmnow=true;
           sprintf (algoname,"%s",tempS1.c_str());
           continue;
       }
       found =tempLine.find("region ") ;
       if (found!=std::string::npos) {
           tempS1 = tempLine.substr(found+7, std::string::npos );
           tempS1.erase(tempS1.find_last_not_of(" \n\r\t")+1);
           if (tempS1[0]==' ') tempS1 = tempS1.substr(tempS1.find_first_not_of(" "), std::string::npos );
           cout <<"\t REGION:"<< tempS1 <<"\n";
           algorithmnow=true;
           sprintf (algoname,"%s",tempS1.c_str());
           continue;
       }
//---------defs
       found = tempLine.find("def ");
       if (found!=std::string::npos) {
           DefList2file+=tempLine;
           DefList2file+="\n";
           continue;
       }
       found = tempLine.find("define ");
       if (found!=std::string::npos) {
           DefList2file+=tempLine;
           DefList2file+="\n";
           continue;
       }

//---------cmds
        found=tempLine.find("cmd ")  ;
       founds=tempLine.find("Sort ")  ;
       foundw=tempLine.find("weight ")  ;
       foundp=tempLine.find("select ")  ;
       foundr=tempLine.find("reject ")  ;
       if ((found!=std::string::npos) ||(foundp!=std::string::npos) || (foundr!=std::string::npos) || (foundw!=std::string::npos) || (founds!=std::string::npos) ) {
           if (algorithmnow) {
              CutList2file+=tempLine;
              CutList2file+="\n";
              size_t apos=tempLine.find(hashdelimiter);
              if       (found!=std::string::npos) { tempS1 = tempLine.substr(found +4, apos); }
              else if (foundw!=std::string::npos) { tempS1 = tempLine.substr(foundw+7, apos); }
              else if (foundp!=std::string::npos) { tempS1 = tempLine.substr(foundp+7, apos); }
              else if (founds!=std::string::npos) { tempS1 = tempLine.substr(founds  , apos); }
              else                                { tempS1 = tempLine.substr(foundr+7, apos); tempS1="reject "+tempS1; }
              tempS1.erase(tempS1.find_last_not_of(" \n\r\t")+1);
              effCL.push_back(tempS1);
//              cout <<tempS1<<"\n";
           } else {
              ObjList2file+=tempLine;
              ObjList2file+="\n";
           }
           continue;
       }
//---------histos
       found=tempLine.find("histo ");
       if (found!=std::string::npos) {
           CutList2file+=tempLine;
           CutList2file+="\n";
           size_t apos=tempLine.find(hashdelimiter);
           tempS1 = tempLine.substr(found+5, apos); // without the comments
           apos=tempS1.find_first_of('"');
           size_t bpos=tempS1.find_last_of('"');
           tempS1 = tempS1.substr(apos+1, bpos-apos-1); // without the comments
           tempS2 = "[Histo] ";
           tempS2 += tempS1;
//           cout <<tempS2<<"\n";
           effCL.push_back(tempS2);
           continue;
       }

    }
    unsigned int bsize=effCL.size()+1; // all is always there 
//-----create the relevant output directory
    if (!algorithmnow) {
       int r=dbxA::setDir(cname, bsize);  // make the relevant root directory
       if (r)  std::cout <<"Root Directory Set Failure in:"<<cname<<std::endl;
       dbxA::ChangeDir(cname);
    } else {
       int r=dbxA::setDir(algoname, bsize);  // make the relevant root directory
       if (r)  std::cout <<"Root Directory Set Failure in:"<<cname<<std::endl;
       dbxA::ChangeDir(algoname);
    }

//----------put into output file as text
    TText cinfo(0,0,CutList2file.Data());
          cinfo.SetName("CLA2cuts");
          cinfo.Write();

    TText info(0,0,DefList2file.Data());
          info.SetName("CLA2defs");
          info.Write();

    TText oinfo(0,0,ObjList2file.Data());
          oinfo.SetName("CLA2Objs");
          oinfo.Write();

// ****************************************
// ---------------------------DBX style cuts
       eff->GetXaxis()->SetBinLabel(1,"all Events"); // this is hard coded.
    
       std::vector<std::string> NameInitializations(2);
       NameInitializations={" "," "};
       vector<double> TRGValues(5);
       TRGValues={1,0,0,0,0};

       yyin=fopen(CardName,"r");
       if (yyin==NULL) { cout << "Cardfile "<<CardName<<" has problems, please check\n";}
       cutcount=0;
       cout <<"==parsing started==\t";
       retval=yyparse(&parts,&NodeVars,&ListParts,&NodeCuts, &ObjectCuts, &NameInitializations, &TRGValues, &ListTables);
       cout <<" parsing finished.  ";
       if (retval){
         cout << "\nyyParse returns SYNTAX error. Check the input file\n";
         exit (99); 
       }
       cout << "We have "<<NodeCuts.size() << " CutLang Cuts and "<<ObjectCuts.size()  <<" CutLang objects cuts\n";
       TRGe    = TRGValues[0];
       TRGm    = TRGValues[1];
       skip_histos    = (bool) TRGValues[3];
      
        eff->GetXaxis()->SetBinLabel(1,"all Events"); // this is hard coded.
      
        cout << "TRGe:"<<TRGe<<"  TRGm:"<<TRGm<<"\n";
        DEBUG("CL CUTS: \n");
        std::map<int, Node*>::iterator iter = NodeCuts.begin();
        while(iter != NodeCuts.end())
        {
            DEBUG(" CUT "<<iter->first<<" ");
            DEBUG("--->"<<iter->second->getStr()<<"\n");
//           TString newLabels=iter->second->getStr();
            TString newLabels=effCL[ iter->first -1];
            eff->GetXaxis()->SetBinLabel(iter->first+1,newLabels); // labels
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

// check if the user wants to save or NOT.
     if (TRGValues.at(4)>0) {
       getInputs( NameInitializations[0] ); // verifier si la commande est bon ou pas
       savebool = true;
     }
  return retval;
}

int BPdbxA:: printEfficiencies() {
  cout <<"\t\t\t\t\t\t"<<algoname<<"\t";
  PrintEfficiencies(eff, skip_histos);
  return 0;
}

int BPdbxA:: initGRL() {
  int retval=0;
  grl_cut=true;
  return retval;
}

int BPdbxA:: bookAdditionalHistos() {
        int retval=0;
//        dbxA::ChangeDir(cname);

#ifdef __SEZEN__
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

  return retval;
}

/////////////////////////
int BPdbxA::makeAnalysis( AnalysisObjects ao ){

  evt_data anevt = ao.evt;

  DEBUG("-------------------------------------------------------------------- "<<cname<<"\n");
  double evt_weight = ao.evt.user_evt_weight;  
  if(TRGe>1 || TRGm> 1) evt_weight = anevt.weight_mc*anevt.weight_pileup*anevt.weight_jvt;
  ao.evt.user_evt_weight*=evt_weight;

// --------- INITIAL  # events  ====> C0
        eff->Fill(1, 1);
DEBUG("------------------------------------------------- Event ID:"<<anevt.event_no<<" \n");
//cout<<"------------------------------------------------- Event ID:"<<anevt.event_no<<" \n";

// *************************************
/// CutLang execution starts-------here*
// *************************************

    std::map<int, Node*>::iterator iter = NodeCuts.begin();
    DEBUG("Start resetting cuts:"<< NodeCuts.size() <<"\n");
//----------------------reset 

    while(iter != NodeCuts.end())
    {   
        iter->second->Reset();
        iter++;
    }

    DEBUG("RESET ALL cuts\n");
    iter = NodeCuts.begin();

//----------------------execute
    while(iter != NodeCuts.end())
    {   
        DEBUG("**********Selecting: "<<iter->first<<" |"<<"\t");
        double d=iter->second->evaluate(&ao); // execute the selection cut
        DEBUG("\t****Result : " << d << std::endl);
        evt_weight = ao.evt.user_evt_weight;
        if (d==0) return iter->first;         // quits the event.
        eff->Fill(iter->first+1, evt_weight); // filling starts from 1 which is already filled.
        iter++; //moves on to the next cut
    } // loop over all cutlang cuts
    DEBUG("   EOE\n     ");

// les cuts sont finis ici.
    if(savebool){
      
      vector<dbxMuon>        muons = ao.muos.begin()->second;
      vector<dbxElectron> electrons= ao.eles.begin()->second;
      vector <dbxPhoton>    photons= ao.gams.begin()->second;
      vector<dbxJet>           jets= ao.jets.begin()->second;
      vector<dbxJet>          ljets= ao.ljets.begin()->second;
      vector<dbxTau>           taus= ao.taus.begin()->second;
      vector<dbxTruth>        truth= ao.truth.begin()->second;
      vector<dbxParticle>    combos= ao.combos.begin()->second;
      //-----------------------------------------
      
      
      TVector2 met = ao.met.begin()->second;
      evt_data anevt = ao.evt;
      
      //      here we save the DBXNTuple
      ntsave->Clean();
      ntsave->nEle=electrons.size();
      for ( int i=0; i<(int)electrons.size(); i++) {
	ntsave->nt_eles.push_back(electrons.at(i) );
      }
      ntsave->nMuo=muons.size();
      for ( int i=0; i<(int)muons.size(); i++) {
	ntsave->nt_muos.push_back(muons.at(i) );
      }
      ntsave->nJet=jets.size();
      for ( int i=0; i<(int)jets.size(); i++) {
	ntsave->nt_jets.push_back(jets.at(i) );
      }
      ntsave->nPhoton=photons.size();
      for ( int i=0; i<(int)photons.size(); i++) {
	ntsave->nt_photons.push_back(photons.at(i) );
      }
      ntsave->nLJet=ljets.size();
      for ( int i=0; i<(int)ljets.size(); i++) {
	ntsave->nt_ljets.push_back(ljets.at(i) );
      }
      ntsave->nTau=taus.size();
      for ( int i=0; i<(int)taus.size(); i++) {
	ntsave->nt_taus.push_back(taus.at(i) );
      }
      ntsave->nTruth=truth.size();
      for ( int i=0; i<(int)truth.size(); i++) {
	ntsave->nt_truth.push_back(truth.at(i) );
      }
      ntsave->nCombo=combos.size();
      for ( int i=0; i<(int)combos.size(); i++) {
	ntsave->nt_combos.push_back(combos.at(i) );
      }
      
      ntsave->nt_met=met;
      ntsave->nt_evt=anevt;
      ntsave->nt_muos.resize    ( muons.size()             );
      ntsave->nt_eles.resize    ( electrons.size()         );
      ntsave->nt_taus.resize    ( taus.size()              );
      ntsave->nt_jets.resize    ( jets.size()              );
      ntsave->nt_ljets.resize   ( ljets.size()             );
      ntsave->nt_photons.resize ( photons.size()           );
      ntsave->nt_combos.resize  ( combos.size()            );
      ntsave->nt_truth.resize   ( truth.size()             );
      
      ttsave->Fill();
      
      }
    return 1;
}

int BPdbxA::Finalize(){       
  ftsave->Write();
  ftsave->Close();
  return 1;
}
