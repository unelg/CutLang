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

void find_idxtype_tobeused( dbxCut *acut, vector <int> *found_idx_vecs, vector <int> *found_type_vecs, vector <int> *found_idx_origs,  vector <int> *ret_i, vector <int> *ret_t ){

#ifdef _CLV_
     DEBUG( "--previous finder:  ");
     DEBUG( acut->getName()<<" Found idx: "); for (int qq=0; qq<found_idx_vecs->size(); qq++) DEBUG(found_idx_vecs->at(qq)<<" "); DEBUG("\t");
     DEBUG("found type<>origs:"); for (int qq=0; qq<found_type_vecs->size(); qq++) DEBUG(found_type_vecs->at(qq)<<"<>"<< found_idx_origs->at(qq)<<" "); DEBUG("\n");
     DEBUG(" searchable types in this cut: "); 
     for (int qq=0; qq<acut->getSearchableType(); qq++) DEBUG( acut->getSearchableType(qq)<<" "); DEBUG("  ");
     DEBUG("ALL idxs in this cut: "); for (int qq=0; qq<acut->getParticleIndex(); qq++) DEBUG(acut->getParticleIndex(qq)<<" "); DEBUG("\t");
#endif

     if (found_idx_vecs->size() == 0) {cerr << "Found idx vector empty!!\n"; exit (23);}
     vector <int> alreadyused; // store already used found idx
     vector<int>::iterator it;
     vector<int> local_part_idxs;

     for (int ipd=0; ipd< acut->getParticleIndex(); ipd++)  // this cut needs // loop over indices remove 999
          if ( acut->getParticleIndex(ipd) < 0) local_part_idxs.push_back(acut->getParticleIndex(ipd));
              
     for (int ipd=0; ipd< acut->getSearchableType(); ipd++)  // this cut needs // loop over indices MUST
        for (unsigned int itk=0; itk<found_idx_vecs->size(); itk++){ // read from found list.
             DEBUG (local_part_idxs[ipd]<<" -vs- "<< found_idx_vecs->at(itk) << "\n");
             if ( found_type_vecs->at(itk) == acut->getSearchableType(ipd)  // types match
               && ( local_part_idxs[ipd]  < 0 )                             // searchable type.
               && found_idx_origs->at(itk) == local_part_idxs[ipd]          // idx match 
               ) {
               DEBUG(" useI:"<<found_idx_vecs->at(itk)<<"\n");
               it=find(alreadyused.begin(), alreadyused.end(), itk);
               if ( it == alreadyused.end() ) { // not previously used
                  ret_i->push_back(found_idx_vecs->at(itk));
                  ret_t->push_back(found_type_vecs->at(itk));
                  alreadyused.push_back(itk);
               }
             }
     }// loop over all previously found idx
     for (int ipd=0; ipd< ret_i->size(); ipd++){
      DEBUG(" ridx:"<<ret_i->at(ipd)<< "  rtyp:"<<ret_t->at(ipd)<<"\n");
     }
     DEBUG(": previous finder--\n");
     return ;
}   


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

   minptm     = ReadCard(CardName,"minptm",15.);
   maxetam    = ReadCard(CardName,"maxetam",2.5);
   minpte     = ReadCard(CardName,"minpte",15.);
   maxetae    = ReadCard(CardName,"maxetae",2.5);
   minptg     = ReadCard(CardName,"minptg",15.);
   maxetag    = ReadCard(CardName,"maxetag",2.5);
   minptj     = ReadCard(CardName,"minptj", 15.);
   maxetaj    = ReadCard(CardName,"maxetaj",2.5);
   maxmet     = ReadCard(CardName,"maxmet", 30.);

   TRGe = ReadCard(CardName,"TRGe",1);
   TRGm = ReadCard(CardName,"TRGm",1);

// ---------------------------DBX style defs
    int kk=1;
    map < string, string > def_names;
    size_t apos = 0;
    size_t bpos = 0;
    size_t cpos = 0;
    size_t dpos = 0;
    string subdelimiter = ":";
    string seldelimiter = ",";
    string  opdelimiter = "_";
    TString DefList2file="\n";
    while (1){
                  TString basedef="def";
                          basedef+=kk++;
                  string def0 = ReadCardString(CardName,basedef,"XXX");
                  if (def0=="XXX") break;
//                  cout << "==========-> def id:"<<kk-1<<") "<<def0<<endl;
                  if ((apos=def0.find(subdelimiter)) != std::string::npos )  {
                         std::string subtoken0, subtoken1;
                         subtoken0 = def0.substr(0, apos); //
                         subtoken1 = def0.substr(apos+subdelimiter.length(),std::string::npos); //
                         subtoken1+=" ";
//                       std::cout <<"DEFINE  "<<subtoken0<<" as "<<subtoken1<<std::endl;
                         DefList2file+=subtoken0;
                         DefList2file+=":";
                         DefList2file+=subtoken1;
                         DefList2file+="\n";
                         TNamed *astr_tmp=new TNamed (subtoken0.data(), subtoken1.data());
//                       TParameter<std::string> *astr_tmp=new TParameter<std::string> (subtoken0.data(), subtoken1,'f');
//                                             astr_tmp->Write(); // can we overload merge on TName? or similar.
//TParameter<std::string> is Foobar because of line 142 on TParameter.h :   fVal *= c->GetVal(); // can't be done with strings
                         def_names[subtoken0]=subtoken1;
                  } else{
                  cout << "This def is problematic. STOP\n"; exit (3);
                  }
     }
     TText info(0,0,DefList2file.Data());
           info.SetName("CLA2defs");
           info.Write();

// ****************************************
//---------------------------DBX style analysis object definitions
// ****************************************
     kk=1;
     TString CutList2file="\n";
     while (1){
               TString basecut="obj";
                       basecut+=kk++; 
               string cut0 = ReadCardString(CardName,basecut,"XXX");
               if (cut0=="XXX") break;
               string subtoken0, subtoken1;
               vector <string> nametokens;
               if ((apos=cut0.find(subdelimiter)) != std::string::npos )  {
                         subtoken0 = cut0.substr(0, apos); //
                         std::string::iterator end_pos = std::remove(subtoken0.begin(), subtoken0.end(), ' ');
                         subtoken0.erase(end_pos, subtoken0.end());
                         subtoken1 = cut0.substr(apos+subdelimiter.length(),std::string::npos); //
                                               end_pos = std::remove(subtoken1.begin(), subtoken1.end(), ' ');
                         subtoken1.erase(end_pos, subtoken1.end());
                         std::cout <<"Object "<<subtoken0<<" is "<<subtoken1<<". ";
                         nametokens.push_back( subtoken1 ); // we keep what the new object will be
               } else { std::cout <<"WRONG object definition!\n"; exit (1);}

               CutList2file+=basecut;
               CutList2file+=" : ";
               CutList2file+=cut0;
               CutList2file+="\n";
               cout << "\n~******----> obj id:"<<kk-1<<") "<<cut0<<"\t";
               int kj=1;
               vector< vector<dbxCut*> > objSelList;
               vector< vector<string>  > objOpeList;
               while (1){
                      basecut="cmd";
                      basecut+=kk-1; 
                      basecut+="-";
                      basecut+=kj++; 
                      string cut1 = ReadCardString(CardName,basecut,"XXX", false);
                      if (cut1=="XXX") break;

                      std::vector<dbxCut*> acutlist;
                      acutlist.reserve(10);
                      std::vector<std::string> q;
                      q=BPcutlist.cutTokenizer(cut1, &acutlist); //BPcutlist is not a real list, name change and also just a local variable TODO
                      objSelList.push_back(acutlist);
                      objOpeList.push_back(q);


                      if ((apos=cut1.find(seldelimiter)) != std::string::npos )  {  // take between , and close curly
                        string pippo=cut1.substr(apos+subdelimiter.length(),std::string::npos);
                        apos=pippo.find(opdelimiter);
                        pippo=pippo.substr(0, apos);
                        std::string::iterator jnk_pos = std::remove(pippo.begin(), pippo.end(), ' ');// delete whites and insert.
                        pippo.erase(jnk_pos, pippo.end());
                        nametokens.push_back(pippo);
                      } else {
// this is a single variable cut
                        nametokens.push_back("XXX");
                      }


                      CutList2file+=basecut;
                      CutList2file+=" : ";
                      CutList2file+=cut1;
                      CutList2file+="\n";
                      cout << "\n~~~~~~~~~~->obj cmd id:"<<kj-1<<") "<<cut1<<"\t";
               }// end of while 1 over cmds
               pair< vector< vector<dbxCut*> >, vector< vector<string> > > anObjdef(objSelList, objOpeList);
               obj_defs.insert(pair< string, pair< vector< vector<dbxCut*> >, vector< vector<string> > > >(subtoken0, anObjdef ) );
               obj_names.insert ( pair<string,vector<string> >(subtoken0,nametokens) );
     } // end of while 1 over objs

// ****************************************
// ---------------------------DBX style cuts
         CutList2file="\n";
         BPcutlist.setTrigType( TRGm+(TRGe<<2) );//bitwise left shift by 2 for TRGe
         eff->GetXaxis()->SetBinLabel(1,"all Events"); // this is hard coded.
         int kFillHistos=0;
         kk=1;

         while (1){
                  std::vector< std::pair<string,string> > obj2use;
                  TString basecut="cmd";
                          basecut+=kk++; 
                  string cut0 = ReadCardString(CardName,basecut,"XXX");
                  if (cut0=="XXX") break;

                  for( map<string, vector<string> >::reverse_iterator it=obj_names.rbegin(); it!=obj_names.rend(); ++it) {
                   std::size_t objfound =cut0.find(it->first);
                   if (objfound !=std::string::npos) {
                     DEBUG("using derived object "<< it->first<< " as "<<it->second[0] );
                     obj2use.push_back(std::pair<string,string>(it->first, it->second[0]) );
                   }
                  }
                  if (obj2use.size() > 0 ) levelObjectMap.insert( std::pair<int, vector<std::pair<string,string> > > (kk-1,obj2use)  );

                  CutList2file+=basecut;
                  CutList2file+=" : ";
                  CutList2file+=cut0;
                  CutList2file+="\n";

//                cout << "\n~~~~~~~~~~-> cut id:"<<kk-1<<") "<<cut0<<"\t";
                  TString newLabels = cut0.data();
                  eff->GetXaxis()->SetBinLabel(kk,newLabels); // labels
                  string cut1;
// loop over all chars. Put a space before and after each operator.
                  for (int ic=0; ic<cut0.size(); ic++){
                   if (cut0[ic] == '(' || cut0[ic] == ')' || cut0[ic] == '+' 
                    || cut0[ic] == '-' || cut0[ic] == '^' || cut0[ic] == '/' 
                    || cut0[ic] == '*' ) 
                   {
                    if (ic>0 && cut0[ic-1] != '_'){
                       cut1.append(" ");
                       cut1.append(cut0,ic,1);
                       cut1.append(" ");
                    }else { cut1.append(cut0,ic,1); }
                   } else { cut1.append(cut0,ic,1); }
                  }

                  DEBUG("====>>>"<<cut1<<".\n");
                  if (cut1.find("FillHistos")!=std::string::npos){ newLabels = "FillHistos-"+TString::Format("%d",++kFillHistos); }

// do we have a definition?
                 for( map<string,string>::reverse_iterator it=def_names.rbegin(); it!=def_names.rend(); ++it) {
//                  cout << "\ndef:"<<it->first<<endl;
                  std::size_t found =cut1.find(it->first);
                  while ( found !=std::string::npos){
//                  cout << "Replace with:"<<it->second<<"  ";
                    cut1.replace(found,it->first.length(),it->second);
//                    cout << "\n~~~~~~~~~~-> cut id:"<<kk-1<<" becomes ) "<<cut1<<"\t";
                    found =cut1.find(it->first);
                  }
                 } 
//----------------------TERNARIES-----------------------------
                 if ((apos=cut1.find('?'))!=std::string::npos){ 
                    std::vector<std::string> q;
                    std::string subtok0, subtokT, subtokF, subtokTMP;
                    std::string subtok0T, subtok0F;
                    std::string subtokTT, subtokTF, subtokFT, subtokFF;
                    subtok0 = cut1.substr(0, apos); // test condition
                    subtokTMP = cut1.substr(apos+subdelimiter.length(), std::string::npos); // the rest...
                    bpos=subtokTMP.find(':');
                    cpos=subtokTMP.find('?'); // another, nested, ternary?
                    DEBUG("****>>>We have a ternary operator @"<< apos <<"\n");

                    std::vector<dbxCut*> acutlist; 
                    acutlist.reserve(10);     // including logics we can have max 10 operations in a line
                    q=BPcutlist.cutTokenizer(subtok0, &acutlist); //BPcutlist is not a real list, name change and also just a local variable TODO
                    mycutlist.push_back(acutlist); myopelist.push_back(q);

//do we have another nested ternary?
                    if ( cpos!=std::string::npos){
                     int terval=0;
                     DEBUG("~~~~~~>We have a nested ternary operator @"<< cpos <<"\n");
                     if ( cpos < bpos ) {// another ternary in true
                         terval+=10;
                         subtok0T = subtokTMP.substr(0, cpos); // test condition
                         subtokTMP = subtokTMP.substr(cpos+subdelimiter.length(), std::string::npos); // the rest...
                         bpos=subtokTMP.find(':');
                         subtokTT = subtokTMP.substr(0, bpos); // test condition
                         subtokTMP = subtokTMP.substr(bpos+subdelimiter.length(), std::string::npos); // the rest...
                         bpos=subtokTMP.find(':');
                         subtokTF = subtokTMP.substr(0, bpos); // test condition
                         subtokTMP = subtokTMP.substr(bpos+subdelimiter.length(), std::string::npos); // the rest...
                         DEBUG("****>>>true test:"<< subtok0T <<"\n");
                         DEBUG("****>>>true true:"<< subtokTT <<"\n");
                         DEBUG("****>>>true false:"<<subtokTF <<"\n");
                         DEBUG("****>>>remaining: "<< subtokTMP <<"\n");
//-----------------------
                         std::vector<dbxCut*> acutlist, bcutlist, ccutlist; 
                         acutlist.reserve(10);     // including logics we can have max 10 operations in a line
                         bcutlist.reserve(10);     // including logics we can have max 10 operations in a line
                         ccutlist.reserve(10);     // including logics we can have max 10 operations in a line
                         q=BPcutlist.cutTokenizer(subtok0T, &acutlist); //BPcutlist is not a real list, name change and also just a local variable TODO
                         terCutlistT.push_back(acutlist); terOpelistT.push_back(q); // to keep track of IDs
                         q=BPcutlist.cutTokenizer(subtokTT, &bcutlist); //BPcutlist is not a real list, name change and also just a local variable TODO
                         terCutlistT.push_back(bcutlist); terOpelistT.push_back(q);
                         q=BPcutlist.cutTokenizer(subtokTF, &ccutlist); //BPcutlist is not a real list, name change and also just a local variable TODO
                         terCutlistF.push_back(ccutlist); terOpelistF.push_back(q);

                     } else {
                         subtokTT = subtokTMP.substr(0, bpos); // test condition
                         subtokTMP = subtokTMP.substr(bpos+subdelimiter.length(), std::string::npos); // the rest...
                         DEBUG("****>>>true "<< subtokTT <<"\n");
                         std::vector<dbxCut*> bcutlist; 
                         bcutlist.reserve(10);     // including logics we can have max 10 operations in a line
                         q=BPcutlist.cutTokenizer(subtokTT, &bcutlist); //BPcutlist is not a real list, name change and also just a local variable TODO
                         terCutlistT.push_back(bcutlist); terOpelistT.push_back(q);
                     } 
                     cpos=subtokTMP.find('?'); // another nested ternary
                     if ( cpos!=std::string::npos){
                      terval+=11;               // another ternary in false
                      subtok0F = subtokTMP.substr(0, cpos); // test condition
                      subtokTMP = subtokTMP.substr(cpos+subdelimiter.length(), std::string::npos); // the rest...
                      bpos=subtokTMP.find(':');
                      subtokFT = subtokTMP.substr(0, bpos); // test condition
                      subtokFF = subtokTMP.substr(bpos+subdelimiter.length(), std::string::npos); // the rest...
                      DEBUG("****>>>false test :"<< subtok0F <<"\n");
                      DEBUG("****>>>false true :"<< subtokFT <<"\n");
                      DEBUG("****>>>false false:"<<subtokFF <<"\n");
//-----------------------
                         std::vector<dbxCut*> acutlist, bcutlist, ccutlist; 
                         acutlist.reserve(10);     // including logics we can have max 10 operations in a line
                         bcutlist.reserve(10);     // including logics we can have max 10 operations in a line
                         ccutlist.reserve(10);     // including logics we can have max 10 operations in a line
                         q=BPcutlist.cutTokenizer(subtok0F, &acutlist); //BPcutlist is not a real list, name change and also just a local variable TODO
                         terCutlistF.push_back(acutlist); terOpelistF.push_back(q); // to keep track of IDs
                         q=BPcutlist.cutTokenizer(subtokFT, &bcutlist); //BPcutlist is not a real list, name change and also just a local variable TODO
                         terCutlistT.push_back(bcutlist); terOpelistT.push_back(q);
                         q=BPcutlist.cutTokenizer(subtokFF, &ccutlist); //BPcutlist is not a real list, name change and also just a local variable TODO
                         terCutlistF.push_back(ccutlist); terOpelistF.push_back(q);
                     } else {
                       subtokFT = subtokTMP; // test condition
                     }
                     isTernary.push_back(terval);
                    } else { // simple ternary
                            isTernary.push_back(1);
                            subtokT = subtokTMP.substr(0,bpos); //
                            subtokT+=" ";
                            subtokF = subtokTMP.substr(bpos+subdelimiter.length(),std::string::npos); //
                            subtokF+=" ";
                            DEBUG("Test  "<<subtok0<<" |T:"<<subtokT<< "\n|F:"<<subtokF <<std::endl);
                            std::vector<dbxCut*> bcutlist, ccutlist; 
                            bcutlist.reserve(10);     // including logics we can have max 10 operations in a line
                            ccutlist.reserve(10);     // including logics we can have max 10 operations in a line
                            q=BPcutlist.cutTokenizer(subtokT, &bcutlist); //BPcutlist is not a real list, name change and also just a local variable TODO
                            terCutlistT.push_back(bcutlist); terOpelistT.push_back(q);
                            q=BPcutlist.cutTokenizer(subtokF, &ccutlist); //BPcutlist is not a real list, name change and also just a local variable TODO
                            terCutlistF.push_back(ccutlist); terOpelistF.push_back(q);
                    }

                 } else { // normally we dont have ternaries
                    isTernary.push_back(0);
                    std::vector<dbxCut*> acutlist; 
                    acutlist.reserve(10);     // including logics we can have max 10 operations in a line
                    std::vector<std::string> q;
                    q=BPcutlist.cutTokenizer(cut1, &acutlist); //BPcutlist is not a real list, name change and also just a local variable TODO
                    mycutlist.push_back(acutlist);
                    myopelist.push_back(q);
                 }
/////////DEBUG
/*
                  for ( unsigned int ic=0; ic<acutlist.size(); ic++) {
                      cout<<" name:"<<acutlist[ic]->getName()<<"\t";
                  }
                  cout<<endl;

                  unsigned int jc=0;
                  for ( unsigned int ic=0; ic<q.size(); ic++) {
                    if (q[ic]=="x"){
                      cout<<acutlist[jc++]->getName();
                      cout<<q[ic];
                    } else {
                      cout<<q[ic];
                    }
                  }
                  cout<<endl;
*/
         } // end of while 1
         cout << "\nWe have "<<mycutlist.size() << " CutLang Cuts\n";
         if ( levelObjectMap.size() > 0) {
              map <int, vector<std::pair<string,string> > >::iterator it;
              for (it=levelObjectMap.begin(); it!=levelObjectMap.end(); ++it) {
                  std::cout <<"Cut:"<< it->first << "  ";
                  for (int iobj=0; iobj<it->second.size(); iobj++){
                     std::cout << it->second.at(iobj).first << " will be used as "<< it->second.at(iobj).second;
                  }
                  std::cout <<"\n";
              }
         }
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
        size_t apos = 0;

// read histo defitions from file
        sprintf(HCardName,"%s-histos.txt",cname);
        vector <pair <int, std::vector<dbxCut*> > > aa; 
        std::vector<dbxCut*> aajunk;

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
         std::string subdelimiter = ":";
         while (1){
                  TString basedef="def";
                          basedef+=kk++;
                  string def0 = ReadCardString(CardName,basedef,"XXX");
                  if (def0=="XXX") break;
//                  cout << "==========-> def id:"<<kk-1<<") "<<def0<<endl;
                  if ((apos=def0.find(subdelimiter)) != std::string::npos )  {
                         std::string subtoken0, subtoken1;
                         subtoken0 = def0.substr(0, apos); //
                         subtoken1 = def0.substr(apos+subdelimiter.length(),std::string::npos); //
                         subtoken1+=" ";
//                       std::cout <<"DEFINE  "<<subtoken0<<" as "<<subtoken1<<std::endl;
                         TNamed *astr_tmp=new TNamed (subtoken0.data(), subtoken1.data());
//                       TParameter<std::string> *astr_tmp=new TParameter<std::string> (subtoken0.data(), subtoken1,'f');
//                                             astr_tmp->Write(); // can we overload merge on TName? or similar.
//TParameter<std::string> is Foobar because of line 142 on TParameter.h :   fVal *= c->GetVal(); // can't be done with strings
                         def_names[subtoken0]=subtoken1;
                  } else{
                  cout << "This def is problematic. STOP\n"; exit (3);
                  }
        }

        aa.push_back( make_pair(-1, aajunk) );
        for (int dummy=0; dummy<9; dummy++) { histos_order.push_back( aa ); b_histos[dummy]=-1;}
        kk=1;
        while (1){
                  TString basedef="histo";
                          basedef+=kk++;
                  string def0 = ReadCardString(HCardName,basedef,"XXX");
                  if (def0=="XXX") break;
                  string def1;
// loop over all chars. Put a space before and after each operator.
                  for (int ic=0; ic<def0.size(); ic++){
                   if (def0[ic] == '(' 
                    || def0[ic] == ')' 
                    || def0[ic] == '+' 
                    || def0[ic] == '-' 
                    || def0[ic] == '^' 
                    || def0[ic] == '/' 
                    || def0[ic] == '*' ) 
                   {
                    if (ic>0 && def0[ic-1] != '_'){
                       def1.append(" ");
                       def1.append(def0,ic,1);
                       def1.append(" ");
                    }else { def1.append(def0,ic,1); }
                   } else { def1.append(def0,ic,1); }
                  }
                  DEBUG("====>>>"<<def1<<".\n");

// do we have a definition?
                 for( map<string,string>::reverse_iterator it=def_names.rbegin(); it!=def_names.rend(); ++it) {
                  std::size_t found =def1.find(it->first); 
                  while ( found !=std::string::npos){
//                    cout << "Replace with:"<<it->second<<"  ";
                    def1.replace(found,it->first.length(),it->second);
//                    cout << "\n+++=> histo id:"<<kk-1<<" becomes ) "<<def1<<"\t";
                    found =def1.find(it->first);
                  }
                 }

// ------- the rest of the histo definitions
                  if ((apos=def1.find(Hsubdelimiter)) != std::string::npos )  {
                         std::string subtoken0, subtoken1;
                         int hnbin, horder;
                         float hxmin, hxmax;
                         string hargument;

                         subtoken0 = def1.substr(0, apos); // histo name
                         def1.erase(0, apos + Hsubdelimiter.length());
                         apos=def1.find(Hsubdelimiter);     // histo title
                         subtoken1 = def1.substr(0, apos); // histo title
                         def1.erase(0, apos + Hsubdelimiter.length());
                         apos=def1.find(Hsubdelimiter);     // histo nbins
                         hnbin=atoi(def1.substr(0, apos).data());

                         if (subtoken0.find("Basics") != std::string::npos  ) {
                          cout << "\nBasics Histos @:"<<hnbin<<" using id:"<< atoi(subtoken1.data() ) << "  ";
                          b_histos[hnbin]=atoi(subtoken1.data() );
                         } else {

                            def1.erase(0, apos + Hsubdelimiter.length());
                            apos=def1.find(Hsubdelimiter);            //histo xmin
                            hxmin=atof(def1.substr(0, apos).data()); //histo xmin
                            def1.erase(0, apos + Hsubdelimiter.length());
                            apos=def1.find(Hsubdelimiter);            //histo xmax
                            hxmax=atof(def1.substr(0, apos).data()); //histo xmax
                            def1.erase(0, apos + Hsubdelimiter.length());
                            apos=def1.find(Hsubdelimiter);            //histo order
                            horder=atoi(def1.substr(0, apos).data());//histo order
                            def1.erase(0, apos + Hsubdelimiter.length());
                            apos=def1.find(subdelimiter);     // histo argument
                            hargument = def1.substr(0, apos); // histo argument

          //                  std::cout <<"\nHISTO ---:  "<<subtoken0<<" name:"<<subtoken1<< "."<< " nbin:"<<hnbin<<" ["<<hxmin<<","<<hxmax<<"]" << " @:"<<horder<<" w/"<<hargument << " ";
                            a_histos[kk-1]=new TH1F(subtoken0.data(), subtoken1.data(), hnbin, hxmin, hxmax);

                            std::vector<dbxCut*> acutlist;
                            acutlist.reserve(10);
                            BPcutlist.cutTokenizer(hargument, &acutlist); //BPcutlist is not a real list, name change and also just a local variable TODO

                            histos_order.at(horder-1).push_back( make_pair (kk-1, acutlist) );
                         }

                  } else{
                  cout << "This histo is problematic. STOP\n"; exit (3);
                  }
        }
  return retval;
}

/////////////////////////
int BPdbxA::makeAnalysis(vector<dbxMuon> muons, vector<dbxElectron> electrons, vector <dbxPhoton> photons,
                               vector<dbxJet> jets, TVector2 met, evt_data anevt) {
  int retval=0;
  int cur_cut=1;

  vector<dbxElectron>  goodElectrons;
  vector<dbxMuon>      goodMuons;
  vector<dbxJet>       goodJets;
  vector<dbxPhoton>    goodPhotons;

  DEBUG("--------------------------------------------------------------------\n");
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
               if(electrons.at(i).isZCand()==0) continue;//This varible has just added in tree. //TODO
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
        eff->Fill(cur_cut, 1);
        cur_cut++;

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

    unsigned int btagSF_counter=0;
    unsigned int FillHistos_counter=0;
             int ahistid;
           float ahistval;
DEBUG("------------------------------------------------- Event ID:"<<anevt.event_no<<" \n");

//    std::cout<<"\n--------------Starting New Event: "<<anevt.event_no<<"  ";

    found_type_vecs.clear(); found_idx_vecs.clear(); found_idx_origs.clear();
    for (unsigned int k=0; k<mycutlist.size(); k++){
           if (mycutlist[k][0]->getOp()=="~=" || mycutlist[k][0]->getOp()=="!=")  // closest to or far away from
              mycutlist[k][0]->clearFoundVector(); //---- clear previous events findings.
    }

// *************************************
/// CutLang execution starts-------here*
// *************************************

    unsigned int ternaryCount=0;
    for (unsigned int k=0; k<mycutlist.size(); k++){
        a0={goodMuons, goodElectrons, goodPhotons, goodJets, met, anevt}; // we start from good ones.

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
        unsigned int j=0; // j=0 is the first cut in that line, if we have more, like ANDs and ORs, j will increase 
        double d, dt=-1;
        if ( isTernary[k]>0 ) {  
            DEBUG(" isTernarySize:"<<isTernary.size()<<"\t tc:" <<ternaryCount << "\t k:" << k <<" maxTC:"<<terCutlistT.size()<<"\n" );
            DEBUG(" BEFORE CUT, solve TERNARY @Degree:"<< isTernary[k] <<"---------"); 
            dt=mycutlist[k][j]->select(&a0); // execute the selection cut
            DEBUG("L0 dt:"<<dt<<"\n"); 

            if (isTernary[k]==10){ // ONE more ternary in T, F is a normal cut
               if (dt > 0) { DEBUG("@L1, True\t");
                 dt=terCutlistT[ternaryCount][j]->select(&a0); // execute the selection cut
               }  else  {    DEBUG("@L1, False\t");
                 ternaryCount++;
               }
            }
            if (isTernary[k]==11){ // ONE more ternary in F, T is a normal cut
               if (dt > 0) { DEBUG("@L1, True\t");
                 ternaryCount++;
               }  else  {    DEBUG("@L1, False\t");
                 dt=terCutlistF[ternaryCount][j]->select(&a0); // execute the selection cut
                 ternaryCount++;
               }
            }

            if (isTernary[k]==21){ // TWO ternaries both in T and F
               if (dt > 0) { DEBUG("@L1, True\t");
                 dt=terCutlistT[ternaryCount][j]->select(&a0); // execute the selection cut
                 ternaryCount++;
               }  else  {    DEBUG("@L1, False\t");
                  ternaryCount++;
                  DEBUG(" cutName:"<<terCutlistF[ternaryCount][j]->getName()<< " cutOp:"<<terCutlistF[ternaryCount][j]->getOp()<<" #cutParts:"<<terCutlistF[ternaryCount][j]->getParticleType() );
                  dt=terCutlistF[ternaryCount][j]->select(&a0); // execute the selection cut
               }
               DEBUG("L1 dt:"<<dt<<"\n");
               ternaryCount++;// ternary skips true; moves to false
            }

            if (dt > 0) { DEBUG("Final True  @"<< ternaryCount <<"\t");
                          DEBUG(" name of this cut:"<<terCutlistT[ternaryCount][j]->getName() );
                          mycutlist[k].swap( terCutlistT[ternaryCount] );
                          myopelist[k].swap( terOpelistT[ternaryCount] ); 
            }  else  {    
                          DEBUG("Final False @"<< ternaryCount <<"\t");
                          DEBUG(" name of this cut:"<<terCutlistF[ternaryCount][j]->getName() );
                          myopelist[k].swap(terOpelistF[ternaryCount] );
                          mycutlist[k].swap(terCutlistF[ternaryCount] );
            }
            DEBUG(" Swapped.\n");
        }


        DEBUG("CUT:"<<k+1<< " "<<" # operations in this cut:"<<myopelist[k].size());
        DEBUG(" name of this cut:"<<mycutlist[k][j]->getName() <<"    ");
//--------- we apply scale factors
        if (TRGe==2 || TRGm== 2) {
         if (mycutlist[k][j]->getName() == "LEPsf" ) evt_weight*=anevt.weight_leptonSF;
         if (mycutlist[k][j]->getName() == "nBJET" || mycutlist[k][j]->getName()=="}nbj" ) {
                evt_weight*=anevt.weight_bTagSF_77;
                anevt.mcevt_weight = evt_weight;
                btagSF_counter++;
         } //TO BE IMPROVED
        }

//----------------histogram filling
        if (mycutlist[k][j]->getName() == "FillHistos") {
           FillHistos_counter++;

           switch ( FillHistos_counter ) {
           case 1:
                 anevt.mcevt_weight = evt_weight;//BG
                 break;
           case 2:
                 anevt.mcevt_weight = evt_weight;//BG
                 break;
           case 3:
                 break;

// if it is not defined---------------
          default:
                //cout << "This PLOT section is NOT defined!!!!!!!!\n";
                break;
         }

        // no need to calculate cut value, since this is only plotting facility
        // continue; ---------TODO


//---------fill cutlang type histos
//      DEBUG("FillSet "<<FillHistos_counter<<endl);
        for (int ij=1; ij<histos_order.at(FillHistos_counter-1).size(); ij++){
           ahistid=histos_order.at(FillHistos_counter-1)[ij].first;
           if (histos_order.at(FillHistos_counter-1)[ij].second.at(0)->isSearchable() ){
//                  DEBUG("searchable histo.\t");
                    dbxCut *histocut= histos_order.at(FillHistos_counter-1)[ij].second.at(0);
                    ret_i.clear(); 
                    ret_t.clear(); 
                    find_idxtype_tobeused( histocut,  &found_idx_vecs, &found_type_vecs, &found_idx_origs, &ret_i, &ret_t );
//                  DEBUG("#idxs to be used:"<< ret_i.size()<<endl);
                    histos_order.at(FillHistos_counter-1)[ij].second.at(0)->setFoundVectors ( &ret_i, &ret_t, &found_idx_origs ); 
           }
//         DEBUG("calculating..\t");
           ahistval=histos_order.at(FillHistos_counter-1)[ij].second.at(0)->calc(&a0); // calculate as before
//         DEBUG("Histo ID:"<<ahistid<<" to be filled with:"<<ahistval<< " title:"<<   histos_order.at(FillHistos_counter-1)[ij].second.at(0)->getName()<<endl);
           a_histos[ahistid]->Fill(ahistval, evt_weight);
        }

        if (b_histos[FillHistos_counter] != -1 ) { //was set at the initialization also we start @1.
           dbxA::makeAnalysis (goodMuons, goodElectrons, goodJets, met, anevt, b_histos[FillHistos_counter]);
        }

        }// end of histogram filling command

        if (myopelist[k].size()>1) { //more than one operator
           std::ostringstream oss;
           for ( unsigned int i=0; i<myopelist[k].size(); i++) { //loop over operations
           if (myopelist[k][i]=="x"){   //something to be evaluated
//             DEBUG("op:"<<mycutlist[k][j]->getOp()   <<"  "); // this operator
               if (mycutlist[k][j]->isSearchable() ) {
//                  DEBUG(mycutlist[k][j]->getName()<<" is searchable.\n");
                    int found_res_size=found_idx_vecs.size();
                    if (found_idx_vecs.size() >0) {// do we have any previous results we can use?
                        ret_i.clear(); 
                        ret_t.clear(); 
                        find_idxtype_tobeused( mycutlist[k][j], &found_idx_vecs, &found_type_vecs, &found_idx_origs, &ret_i, &ret_t );
//                      DEBUG("To be used idx_vec size:"<< ret_i.size()<<endl);
                        if (ret_i.size() >0) { mycutlist[k][j]->setFoundVectors( &ret_i, &ret_t, &found_idx_origs); }
                        forbidthese.clear();
                        for (int ikk=0; ikk<found_res_size; ikk++){ 
                             forbidthese.push_back( make_pair(found_idx_vecs[ikk],found_type_vecs[ikk]) );
                        }
                        mycutlist[k][j]->setForbiddenVector(&forbidthese);
                    }
               }// end searchable

              oss<<mycutlist[k][j++]->select(&a0);
           } else {
              oss<<myopelist[k][i];
           }
           } // end of operations
//           oss << "  "; // very very important to finish with space.
           DEBUG("\n Total oper is:"<< oss.str()<<endl);

//--------------we now have a logic operation to perform
           basic_parser pars;
           std::vector<std::string> rpn;
           std::vector<std::string> tokens = pars.getExpressionTokens( oss.str() );
           pars.infixToRPN( tokens, tokens.size(), &rpn );
           d = pars.RPNtoDouble( rpn );
	} else { //single operation
           if (mycutlist[k][j]->isSearchable() ) {
               DEBUG(mycutlist[k][j]->getName()<<" is searchable.\n");
                int found_res_size=found_idx_vecs.size();
                if (found_res_size >0) {// do we have any previous results we can use?
                  ret_i.clear(); 
                  ret_t.clear(); 
                  find_idxtype_tobeused( mycutlist[k][j], &found_idx_vecs, &found_type_vecs, &found_idx_origs, &ret_i, &ret_t );
                  DEBUG("To be used idx_vec size:"<< ret_i.size()<<endl);
                  if (ret_i.size() >0) { mycutlist[k][j]->setFoundVectors( &ret_i, &ret_t, &found_idx_origs); }
                  forbidthese.clear();
                  for (int ikk=0; ikk<found_res_size; ikk++){ 
                     forbidthese.push_back( make_pair(found_idx_vecs[ikk],found_type_vecs[ikk]) );
                  }
                  mycutlist[k][j]->setForbiddenVector(&forbidthese);
                }
           }// end searchable
           DEBUG("Selecting: ");
           d=mycutlist[k][j]->select(&a0); // execute the selection cut
//---------if this was a defining cut, we will store the results;
           if (mycutlist[k][j]->getOp()=="~=" || mycutlist[k][j]->getOp()=="!=") {
                DEBUG("storing found vecs. Tot="<<(mycutlist[k][j]->getFoundVector()).size()); 
                for (int iti=0; iti<(mycutlist[k][j]->getFoundVector()).size(); iti++) {
                      found_idx_vecs.push_back ( mycutlist[k][j]->getFoundVector()[iti]  );
                      found_type_vecs.push_back( mycutlist[k][j]->getFoundType(iti) );
                      found_idx_origs.push_back( mycutlist[k][j]->getOrigFoundIndexes(iti) );
                }
           //   DEBUG(" TOT#found:"<<found_idx_vecs.size()<<" tot#Oi:"<<found_idx_origs.size() <<" \n ");
           //   for (int iti=0; iti<found_idx_origs.size(); iti++) {DEBUG(" Oi:"<<found_idx_origs[iti]);}  DEBUG("\n");
           }
           j++;
        }
        if ( isTernary[k] > 0){
            if (dt > 0) { 
                          mycutlist[k].swap( terCutlistT[ternaryCount] );
                          myopelist[k].swap( terOpelistT[ternaryCount] ); 
            }  else  {    
                          myopelist[k].swap(terOpelistF[ternaryCount] );
                          mycutlist[k].swap(terCutlistF[ternaryCount] );
            }
         ternaryCount++; // ternary skips 1 here, nested or not doesn't matter.
        }
        DEBUG("             Result = " << d << std::endl);
        if (d==0) return k; // quit the event.
        eff->Fill(k+2, evt_weight); // filling starts from 1 which is already filled.
    } // loop over all cutlang cuts
    cur_cut+=mycutlist.size(); // we continue
return 1;
}
