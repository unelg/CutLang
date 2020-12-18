#include "TParameter.h"
#include <TRandom.h>
#include "TText.h"
#include <iostream>
#include <sstream>      // std::istringstream
#include <string>
#include <map>
#include <iterator>
#include <vector>
#include "SearchNode.h"

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

extern int yyparse(list<string> *parts,map<string,Node*>* NodeVars,map<string,vector<myParticle*> >* ListParts,map<int,Node*>* NodeCuts,
                                       map<int,Node*>* BinCuts, map<string,Node*>* ObjectCuts, vector<string>* Initializations, 
                                       vector<double>* TRGValues, map<string,pair<vector<float>, bool> >* ListTables,
                                       map<string, vector<cntHisto> >*cntHistos);

extern FILE* yyin;
extern int cutcount;
extern int bincount;

bool is_number(const std::string& s)
{
    return( strspn( s.c_str(), "-.0123456789" ) == s.size() );
}

int BPdbxA::getInputs(std::string aname) {
        int retval=0;
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
    string hashdelimiter = "#";
    size_t found, foundp, foundr, foundw, founds, foundsave;
    TString DefList2file="\n";
    TString CutList2file="\n";
    TString ObjList2file="\n";

    bool algorithmnow=false;

    while ( ! cardfile.eof() ) {
       getline( cardfile, tempLine );
       if ( tempLine[0] == '#' ) continue; // skip comment lines starting with #
       if (tempLine.find_first_of("#") != std::string::npos ){ // skip anything after #
         tempLine.erase(tempLine.find_first_of("#"));
       }
//     cout << tempLine<<"\n";
       if (tempLine.size() < 3) continue; // remove the junk

//-------------tokenize with space or tab 
       std::istringstream iss(tempLine);
       std::vector<std::string> resultstr((std::istream_iterator<std::string>(iss)), std::istream_iterator<std::string>());
       if (resultstr.size() < 1) continue;
       string firstword=resultstr[0];
       for(auto& c : firstword) { c = tolower(c); } // convert to lowercase
       string toplam;
       if (resultstr.size() >1) for(int ic=1; ic<resultstr.size(); ic++) {
//                cout << resultstr[ic] <<".\n";
                  toplam+=resultstr[ic];
                  if (ic<resultstr.size()-1) toplam+=" ";
       }              

//---------obj
       if ((firstword == "obj") || (firstword == "object") ) {
           ObjList2file+=tempLine;
           ObjList2file+="\n";
           continue;
       }

//---------algo / region etc.
       if ((firstword == "algo") || (firstword=="region"))  {
           cout <<"\t REGION/ALGO:"<< resultstr[1] <<"\n";
           algorithmnow=true;
           sprintf (algoname,"%s",resultstr[1].c_str());
           continue;
       }
//---------defs
       if ((firstword == "def") || (firstword=="define"))  {
           DefList2file+=tempLine;
           DefList2file+="\n";
           continue;
       }
//---------bins
       if (firstword == "bin")  {
//            cout << toplam <<"\n";
           if (is_number(resultstr[2]) ){   // MHT 0 300 400, do magic
//            cout <<"magic needed \n";    //  1   2  3   4
            TString con1 =resultstr[1];
                    con1+=" <= ";
                    con1+=resultstr[2];
            binCL.push_back(con1.Data());
            for(int ic=3; ic<resultstr.size(); ic++) {
                con1 =resultstr[1];
                con1+=" [] ";
                con1+=resultstr[ic-1];
                con1+=" ";
                con1+=resultstr[ic];
                binCL.push_back(con1.Data());
            }
            con1 =resultstr[1];
            con1+=" >= ";
            con1+=resultstr[resultstr.size()-1];
            binCL.push_back(con1.Data());
            
           } else binCL.push_back(toplam); // no magic
           continue;
       }

//---------other cmds
       if (  (firstword=="cmd")  || (firstword=="sort")   || (firstword=="reject")
          || (firstword=="save") || (firstword=="weight") || (firstword=="select")
          ) {
           if (algorithmnow) {
              CutList2file+=tempLine;
              CutList2file+="\n";
              if (firstword=="save"){
               tempS2 = "[Save] ";
               tempS2 += toplam;
               effCL.push_back(tempS2);
              } else effCL.push_back(toplam);
//            cout <<toplam<<"\n";
           } else {
              ObjList2file+=tempLine;
              ObjList2file+="\n";
           }
           continue;
       }
//---------histos
       if (firstword=="histo") {
           CutList2file+=tempLine;
           CutList2file+="\n";
           size_t apos=toplam.find_first_of('"');
           size_t bpos=toplam.find_last_of('"');
           tempS1 = toplam.substr(apos+1, bpos-apos-1); // without the quotation marks
           tempS2 = "[Histo] ";
           tempS2 += tempS1;
//           cout <<tempS2<<"\n";
           if (algorithmnow) {
            effCL.push_back(tempS2);
            CutList2file+=tempLine;
            CutList2file+="\n";
           } else {
              ObjList2file+=tempLine;
              ObjList2file+="\n";
           }

           continue;
       }

    } // end of first look over ADL file

//-----create the relevant output directory
    if (!algorithmnow) {
       int r=dbxA::setDir(cname);  // make the relevant root directory
       if (r)  std::cout <<"Root Directory Set Failure in:"<<cname<<std::endl;
       dbxA::ChangeDir(cname);
    } else {
       int r=dbxA::setDir(algoname);  // make the relevant root directory
       if (r)  std::cout <<"Root Directory Set Failure in:"<<cname<<std::endl;
       dbxA::ChangeDir(algoname);
    }



// ---------------------------read CutLang style cuts using lex/yacc
       NameInitializations={" "," "};
       TRGValues={1,0,0,0,0};
       yyin=fopen(CardName,"r");
       if (yyin==NULL) { cout << "Cardfile "<<CardName<<" has problems, please check\n";}
       cutcount=0;
       bincount=0;
       cout <<"==Parsing started:\t";
       retval=yyparse(&parts,&NodeVars,&ListParts,&NodeCuts, &BinCuts, &ObjectCuts, &NameInitializations, &TRGValues, &ListTables, &cntHistos);
       cout <<"\t Parsing finished.==\n";
       if (retval){
         cout << "\nyyParse returns SYNTAX error. Check the input file\n";
         exit (99); 
       }
       cout << "We have "<<NodeCuts.size() << " CutLang Cuts, "<<ObjectCuts.size()  <<" CutLang objects and ";
       cout << BinCuts.size() << " Bins\n";
       TRGe    = TRGValues[0];
       TRGm    = TRGValues[1];
       skip_effs    = (bool) TRGValues[2];
       skip_histos  = (bool) TRGValues[3];
// ------------------------------------4 is reserved for future use.

//---------save in the dir.
    unsigned int effsize=NodeCuts.size()+1; // all is always there 
 
//-----create the eff histograms
       int r=dbxA::defHistos( effsize);  // enough room

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


       std::map<int, Node*>::iterator iter = NodeCuts.begin();
       while(iter != NodeCuts.end()) {
//               cout << "**-- BP sees:"<<iter->second->getStr().Data()<<".\n";
                if (iter->second->getStr().CompareTo(" save") == 0 ) {
		      save.push_back(iter->first);
//                    cout <<"Saving at "<<iter->first<<"\n";
		      iter->second->createFile();
		}
                if (iter->second->getStr().Contains("~=") ) {
	            optimize.insert(iter->first);
//                    cout <<"Optimize at "<<iter->first<<"\n";
		}
                iter++;
       }
#ifdef _CLV_
// check if the user injects cuts or not.
     for (int jt=0; jt<TRGValues.size(); jt++){
      cout <<"Cut @:"<<jt<<" value:"<<TRGValues.at(jt)<<"\n";
     }
     for (int jt=0; jt<effCL.size(); jt++){
      cout << "Eff @:"<<jt<<" val:"<<effCL.at(jt)<<"\n";
     }
#endif
 
    unsigned int binsize=BinCuts.size(); // bins 
    if (binsize>0) hbincounts= new TH1D("bincounts","event counts in bins ",binsize,0.5,binsize+0.5);
    if (binsize==binCL.size() ) {
     for (int jbin=0; jbin<binsize; jbin++){
       DEBUG("Bin from User C++:"<<binCL[jbin]<<"\n");
       hbincounts->GetXaxis()->SetBinLabel(1+jbin,binCL[jbin].c_str() );
     }
    } else {
     std::map<int, Node*>::iterator biter = BinCuts.begin();
     while(biter != BinCuts.end()) {    
       DEBUG("Bin from Auto yacc:"<<biter->second->getStr()<<"\n");
       hbincounts->GetXaxis()->SetBinLabel(biter->first, biter->second->getStr().Data() );
       biter++;
     }
    }
//--------effciency names and debugs     
       eff->GetXaxis()->SetBinLabel(1,"all Events"); // this is hard coded.
       cout << "TRGe:"<<TRGe<<"  TRGm:"<<TRGm<<"\n";
       DEBUG("CL CUTS:"<< NodeCuts.size()<< " eff:"<<effCL.size() <<"\n");
       iter = NodeCuts.begin();
       int labelSkip=0;
       bool usecpp=true;
       int inserted=TRGValues.size()-5;
       if (inserted>0) {
              std::cout<<"Auto inserted cuts:"<< inserted<<"\n";
       }
       bool nextcpp=false;
       while(iter != NodeCuts.end())
       {  
          DEBUG(" CUT "<<iter->first<<" LabelSkip:"<<labelSkip<< " inserted:"<<inserted << " ");
          DEBUG(" :"<<iter->second->getStr()<<"\t");
          string newNLabels=iter->second->getStr().Data();
          DEBUG("-->"<<effCL[ iter->first -1-labelSkip]<<"\t");
          TString ELabels=effCL[ iter->first -1-labelSkip];
          if (inserted>0 && !nextcpp) { //5-0 yacc, 6-1: c++,
            if ( iter->first == TRGValues.at(labelSkip+5)  ) { usecpp=false; inserted-=1;  } 
          } else usecpp=true;
         
          if (usecpp) {
                DEBUG("From C++:"<<ELabels<<"\n");
                eff->GetXaxis()->SetBinLabel(iter->first+1,ELabels.Data()); // labels
                nextcpp=false;
          } else {
                DEBUG("from yacc:"<<newNLabels<<"\n");
                string newlabels="Size "+newNLabels; 
                eff->GetXaxis()->SetBinLabel(iter->first+1,newlabels.c_str()); // labels
                labelSkip++;
                nextcpp=true;
          } 
           
           iter++; 
       }
 DEBUG("BIN CUTS: \n");
       iter = BinCuts.begin();
       while(iter != BinCuts.end())
       { bincounts.push_back(0);
         DEBUG("+++++ Binning: "<<iter->first<<" |"<< iter->second->getStr()<<"\n");
         iter++;
       }
//---------------------- count histos
for (map<string,vector<cntHisto> >::iterator ichi = cntHistos.begin(); ichi != cntHistos.end(); ichi++){
 // cout << ichi->first << " \n ------- \n ";
         for (vector<cntHisto>::iterator ih=ichi->second.begin(); ih!=ichi->second.end(); ih++){
   //        cout<< ih->cH_name<< " "<< ih->cH_title<<":"<< ih->cH_means.size()<<"\n";
           TH1D* chistoM= new TH1D(ih->cH_name.c_str(), ih->cH_title.c_str(), ih->cH_means.size(), 0.5, 0.5+ih->cH_means.size());
           string upname=ih->cH_name; upname+="_up";
           string downname=ih->cH_name; downname+="_down";
           TH1D* chistoU= new TH1D(  upname.c_str(), ih->cH_title.c_str(), ih->cH_means.size(), 0.5, 0.5+ih->cH_means.size());
           TH1D* chistoD= new TH1D(downname.c_str(), ih->cH_title.c_str(), ih->cH_means.size(), 0.5, 0.5+ih->cH_means.size());
           for (int iv=0; iv<ih->cH_means.size(); iv++){
     //        cout<< ih->cH_means[iv] << " stat +" << ih->cH_StatErr_p[iv] << " -"<<ih->cH_StatErr_n[iv] 
      //                               << "  sys +" << ih->cH_SystErr_p[iv] << " -"<<ih->cH_SystErr_n[iv] <<"\n";  
             chistoM->SetBinContent(1+iv, ih->cH_means[iv]);
             chistoU->SetBinContent(1+iv, sqrt(ih->cH_StatErr_p[iv]*ih->cH_StatErr_p[iv] + ih->cH_SystErr_p[iv]*ih->cH_SystErr_p[iv]));
             chistoD->SetBinContent(1+iv, sqrt(ih->cH_StatErr_n[iv]*ih->cH_StatErr_n[iv] + ih->cH_SystErr_n[iv]*ih->cH_SystErr_n[iv]));
           }
         }
}

#ifdef _CLV__
     cout<<"\n Parsed Particle Lists: \n";

     for (map<string,vector<myParticle*> >::iterator it1 = ListParts.begin(); it1 != ListParts.end(); it1++)
         {
         cout << it1->first << ": ";
         for (vector<myParticle*>::iterator lit = it1->second.begin(); lit  != it1->second.end(); lit++)
         cout << (*lit)->type << "_" << (*lit)->index << " ";
         cout << "\n";
      }

    cout<<"\n UNParsed Particles Lists: \n";

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

  return retval;
}

int BPdbxA::printEfficiencies() {
  if (skip_effs) return 0;
  cout <<"Efficiencies for analysis : "<< cname <<endl;
  cout <<"\t\t\t\t\t\t"<<algoname<<"\t";
  PrintEfficiencies(eff, skip_histos);
  cout <<"Bins for analysis : "<< cname <<endl;
  cout <<setprecision(6);
  for (int ii=0; ii<bincounts.size(); ii++) std::cout<<"\t\t\t\t\t\tBin:"<<ii<<" has:"<<bincounts[ii]<<" events\n";
  return 0;
}

int BPdbxA:: initGRL() {
  int retval=0;
  grl_cut=true;
  return retval;
}

int BPdbxA::bookAdditionalHistos() {
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
//------------------------
int BPdbxA::Finalize(){       
  std::cout <<"finalize.\n";
  return 1;
}

/////////////////////////
int BPdbxA::makeAnalysis( AnalysisObjects *ao, int controlword, int lastCutPass){

  evt_data anevt = ao->evt; // event information

  DEBUG("-----------------------------------------------"<<cname<<" ctrl:"<< controlword<< " lastC:"<<lastCutPass<< "\n");
  double evt_weight = ao->evt.user_evt_weight; // FROM file or previous calculation  
  if (controlword == 0){
    if(TRGe>1 || TRGm> 1) evt_weight = anevt.weight_mc*anevt.weight_pileup*anevt.weight_jvt;
    ao->evt.user_evt_weight*=evt_weight;
  }else { // this is a dependent region, with pre-selection that failed at some point
// no need to calculate something that we know will fail.
   if (!lastCutPass) return 0;
  } 

// --------- INITIAL  # events  ====> C0
        eff->Fill(1, 1);
DEBUG("------------------------------------------------- Event ID:"<<anevt.event_no<<" \n");

// *************************************
/// CutLang execution starts-------here*
// *************************************

    std::map<int, Node*>::iterator iter = NodeCuts.begin();
//----------------------reset 

  if (controlword == 0){
    DEBUG("Start resetting cuts:"<< NodeCuts.size() <<"\n");
    while(iter != NodeCuts.end())
    {   
        iter->second->Reset();
        iter++;
    }
    particleBank.clear();
    DEBUG("Done resetting cuts.\n");
    iter = NodeCuts.begin();
   } else {
     for (int in:optimize){
      DEBUG("Get Optimals from:"<< in<<"\t");
      DEBUG("names:"<<  NodeCuts[ in ]->getStr()<<"\n");
      for (int ip=0; ip<particleBank[in].size(); ip++){
          DEBUG("Bank-> Coll:"<<particleBank[in].at(ip)->collection<<" type:"<< particleBank[in].at(ip)->type
                             <<" index:"<<particleBank[in].at(ip)->index<<"\n");
      }
      ((SearchNode *)NodeCuts[in])->setParticles(&particleBank[in]);
     }
     for (int aa=0; aa<controlword; aa++) iter++;

  }

//----------------------execute
    while(iter != NodeCuts.end())
    {   
        double d;
        DEBUG("**********Selecting: "<<iter->first<<" | ");
        if ( iter->first < controlword ) {
// controlword 5 means 1 1 1 1 0, first 4 cuts passed.
         DEBUG ("preset");
         d=1;
// if only 5cuts were there, and all 5 passed, we get a  10000+4
         } else if (iter->first == controlword ){
         DEBUG ("preset");
         d=lastCutPass;
         }
         else d=iter->second->evaluate(ao); // execute the selection cut
         
        DEBUG("\t***Result : " << d << std::endl);
        evt_weight = ao->evt.user_evt_weight;
        if (d==0) {
		if (ao->evt.event_no == (ao->evt.maxEvents - 1)) {	// to close
			std::map<int, Node*>::iterator jter = NodeCuts.begin();
	                for (std::vector<int>::iterator it = save.begin() ; it != save.end(); ++it) {
                	        int diff = *it - jter->first;
                                for(int i = 0; i < diff; i++) jter++;
                               	jter->second->saveFile();
        	        }
		}
                DEBUG("Return:"<<iter->first<<"\n");
		return iter->first;         // quits the event.
	}
        DEBUG("W:"<<evt_weight<<"\n");
        eff->Fill(iter->first+1, evt_weight); // filling starts from 1 which is already filled.
        if ((controlword == 0) && (optimize.size()>0)) {
           if (optimize.find(iter->first) != optimize.end()){
             DEBUG("This optimized results are to be saved.\n");
             vector<myParticle *> theseParticles;
             iter->second->getParticles(&theseParticles);
             DEBUG("#particles:"<< theseParticles.size()<<".\n");
             for (int ip=0; ip<theseParticles.size(); ip++){
               DEBUG("Bank] Coll:"<<theseParticles[ip]->collection<<" type:"<< theseParticles[ip]->type<<" index:"<<theseParticles[ip]->index<<"\n");
             }
               particleBank.insert(make_pair(iter->first, theseParticles) );
           }
        }
        iter++; //moves on to the next cut
    } // loop over all cutlang cuts
    DEBUG("   EOE\n     ");

    iter = BinCuts.begin();
    DEBUG("Binning now ..\n");
    while(iter != BinCuts.end())
    {
        DEBUG("+++++ Binning: "<<iter->first<<" |"<<"\t");
        double d=iter->second->evaluate(ao); // execute the selection cut
        DEBUG("\t****Result : " << d << std::endl);
        evt_weight = ao->evt.user_evt_weight;
        if (d==1) { // inside a bin
           DEBUG(iter->first<<" Passed\n"); // do something
           bincounts[iter->first -1]++;
           hbincounts->Fill(iter->first , evt_weight);
           break;
        }
        iter++; //moves on to the next cut
    }// loop over all binnings   

// les cuts sont finis ici.
    return 10000+NodeCuts.size();
}

