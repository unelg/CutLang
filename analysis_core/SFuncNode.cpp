//
//  SFuncNode.cpp
//  mm
//
//  Created by Anna-Monica  on 8/2/18.
//  Copyright © 2018 Anna-Monica. All rights reserved.
//  Copyright © 2020 Gokhan Unel. All rights reserved.
//
#include "SFuncNode.h"
#include "ValueNode.h"

//#define _CLV_
#ifdef _CLV_
#define DEBUG(a) std::cout<<a
#else
#define DEBUG(a)
#endif
    
double SFuncNode::evaluate(AnalysisObjects* ao) {

        DEBUG("*******In SF, Extern True/False:"<< ext <<"\n"); 
        if(userObjectA && !ext) {
           DEBUG("\t start user obj A\n"); 
           userObjectA->evaluate(ao); // returns 1, hardcoded. see ObjectNode.cpp
           DEBUG("user obj A done.\n"); 
        }
        if(userObjectB && !ext) {
           DEBUG("\t B user obj\n"); 
           userObjectB->evaluate(ao); // returns 1, hardcoded. see ObjectNode.cpp
           DEBUG("user obj B done.\n"); 
        }
        dbxParticle *aPart= new dbxParticle;
        dbxParticle *bPart= new dbxParticle;
        dbxParticle *cPart= new dbxParticle;

          TString unikID="_";

        if ( inputParticlesA.size()>0 ){
           aPart->Reset();
           TLorentzVector ametlv;
           DEBUG("\n input particles A "); 
           for(vector<myParticle*>::iterator i=inputParticlesA.begin();i!=inputParticlesA.end();i++){
               DEBUG("type:"<<(*i)->type<<" index:"<< (*i)->index<< " addr:"<<*i<<  "\t name:"<< (*i)->collection<<"\n");
              int atype=(*i)->type;
                int ai=(*i)->index;
             string ac=(*i)->collection;

             if (atype==7) ac="MET";
               unikID+=ac;             
               unikID+=ai;             

               switch (atype) { 
		  case 10:  aPart->setTlv(  aPart->lv()+ao->truth[ac].at(ai).lv() );   break;
                  case 12:  aPart->setTlv(  aPart->lv()+ao->muos[ac].at(ai).lv() );   break;
                  case  1:  aPart->setTlv(  aPart->lv()+ao->eles[ac].at(ai).lv() );   break;
                  case 11:  aPart->setTlv(  aPart->lv()+ao->taus[ac].at(ai).lv() );   break;
                  case  2:  aPart->setTlv(  aPart->lv()+ao->jets[ac].at(ai).lv() );   break;
                  case 20:  aPart->setTlv(  aPart->lv()+ao->combos[ac].at(ai).lv() ); break;
                   case 9:  aPart->setTlv(  aPart->lv()+ao->ljets[ac].at(ai).lv() );  break;
                   case 8:  aPart->setTlv(  aPart->lv()+ao->gams[ac].at(ai).lv() );   break;
                   case 7: DEBUG("MET LV\n ");
                            ametlv.SetPxPyPzE(ao->met[ac].Px(), ao->met[ac].Py(), 0, ao->met[ac].Mod());
                            aPart->setTlv(aPart->lv()+ametlv); // v from MET using same eta approx.
                            break;
                   default: std::cout<<"SFN No such object! ERROR\n";
                            break;

               } // end of switch
           }// end of for

           DEBUG("aPart constructed \t");
        }
        if ( inputParticlesB.size()>0 ){
           bPart->Reset();
           TLorentzVector ametlv;
           DEBUG("\n input particles B "); 
           for(vector<myParticle*>::iterator i=inputParticlesB.begin();i!=inputParticlesB.end();i++){
               DEBUG("type:"<<(*i)->type<<" index:"<< (*i)->index<< " addr:"<<*i<<  "\t name:"<< (*i)->collection<<"\n");
              int atype=(*i)->type;
                int ai=(*i)->index;
             string ac=(*i)->collection;
             if (atype==7) ac="MET";
               unikID+=ac;             
               unikID+=ai;             

               switch (atype) { 
		   case 10:  bPart->setTlv(  bPart->lv()+ao->truth[ac].at(ai).lv() );  break;
                   case 12:  bPart->setTlv(  bPart->lv()+ao->muos[ac].at(ai).lv() );   break;
                   case  1:  bPart->setTlv(  bPart->lv()+ao->eles[ac].at(ai).lv() );   break;
                   case 11:  bPart->setTlv(  bPart->lv()+ao->taus[ac].at(ai).lv() );   break;
                   case  2:  bPart->setTlv(  bPart->lv()+ao->jets[ac].at(ai).lv() );   break;
                   case 20:  aPart->setTlv(  bPart->lv()+ao->combos[ac].at(ai).lv() ); break;
                   case  9:  bPart->setTlv(  bPart->lv()+ao->ljets[ac].at(ai).lv() );  break;
                   case  8:  bPart->setTlv(  bPart->lv()+ao->gams[ac].at(ai).lv() );   break;
                   case  7: DEBUG("MET LV\n ");
                            ametlv.SetPxPyPzE(ao->met[ac].Px(), ao->met[ac].Py(), 0, ao->met[ac].Mod());
                            bPart->setTlv(bPart->lv()+ametlv); // v from MET using same eta approx.
                            break;
                   default: std::cout<<"SFN No such object! ERROR\n";
                            break;

               } // end of switch
           }// end of for

           DEBUG("bPart constructed \t");
        }
        if ( inputParticlesC.size()>0 ){
           cPart->Reset();
           TLorentzVector ametlv;
           DEBUG("\n input particles C "); 
           for(vector<myParticle*>::iterator i=inputParticlesC.begin();i!=inputParticlesC.end();i++){
               DEBUG("type:"<<(*i)->type<<" index:"<< (*i)->index<< " addr:"<<*i<<  "\t name:"<< (*i)->collection<<"\n");
              int atype=(*i)->type;
                int ai=(*i)->index;
             string ac=(*i)->collection;
             if (atype==7) ac="MET";
               unikID+=ac;             
               unikID+=ai;             

             switch (atype) { 
		   case 10:  cPart->setTlv(  cPart->lv()+ao->truth[ac].at(ai).lv() );   break;
                   case 12:  cPart->setTlv(  cPart->lv()+ao->muos[ac].at(ai).lv() );   break;
                   case  1:  cPart->setTlv(  cPart->lv()+ao->eles[ac].at(ai).lv() );   break;
                   case 11:  cPart->setTlv(  cPart->lv()+ao->taus[ac].at(ai).lv() );   break;
                   case  2:  cPart->setTlv(  cPart->lv()+ao->jets[ac].at(ai).lv() );   break;
                   case 20:  cPart->setTlv(  cPart->lv()+ao->combos[ac].at(ai).lv() ); break;
                   case  9:  cPart->setTlv(  cPart->lv()+ao->ljets[ac].at(ai).lv() );  break;
                   case  8:  cPart->setTlv(  cPart->lv()+ao->gams[ac].at(ai).lv() );   break;
                   case  7: DEBUG("MET LV\n ");
                            ametlv.SetPxPyPzE(ao->met[ac].Px(), ao->met[ac].Py(), 0, ao->met[ac].Mod());
                            cPart->setTlv(cPart->lv()+ametlv); // v from MET using same eta approx.
                            break;
                   default: std::cout<<"SFN No such object! ERROR\n";
                            break;

               } // end of switch
           }// end of for

           DEBUG("cPart constructed \t");
        }
        if (left != NULL) {
          value =left->evaluate(ao);
        }

        DEBUG ("Before Symbol:"<<symbol<<" Value:"<<value<< " Type:"<<type<<"\n");
        if(ext) {
             TString extkey =symbol;
                     extkey+="_";
                     extkey+=value;
                     extkey+="_";
                     extkey+=type;
                     extkey+=unikID;

             std::map< std::string, double >::iterator keyit; 

              DEBUG("external user function evaluation. initial Key:"<< extkey<<"\n");
              if (g1 != NULL) return (*g1)(ao, symbol, type, h1 ); // A
              if (g2 != NULL) return (*g2)(ao, symbol, type, h2 ); // B
              if (g3 != NULL) return (*g3)(ao, symbol, type, h3 ); // C
              if (g4 != NULL) return (*g4)(ao, symbol, type, aPart->lv(), h4); // D
              if (g5 != NULL) { // E
                if ( BUFFERED_VALUES.find(extkey.Data()) !=BUFFERED_VALUES.end() ){
                   DEBUG("Returning buffered value:"<<(BUFFERED_VALUES[extkey.Data()]) << "\n");
                   return (BUFFERED_VALUES[extkey.Data()]);
                } else { 
                 double g5retval=(*g5)(ao, symbol, type, aPart->lv(), bPart->lv(), cPart->lv(), h5);
                 BUFFERED_VALUES.insert(std::pair<string, double >(extkey.Data(), g5retval));
                 return g5retval;
                }
              }
        }
        double arv=(*f)(ao, symbol, value);              
        DEBUG("ARV="<<arv<<"\n");
        return arv;
//        return (*f)(ao, symbol, value);
}

void SFuncNode::Reset() {
      DEBUG (" Resetting cache \n");
      BUFFERED_VALUES.clear();
    }

double getIndex(AnalysisObjects* ao, string s, float id){ // new internal function
    particleType pid = (particleType)id;
    DEBUG("GETINDEX function\n");
    DEBUG("STR:"<<s<<" Type:"<<pid<<" #Combos types:"<<ao->combos.size() << " #Table types:"<<ao->combosA.size()<<"\n");
    map <string,  indicesA  >::iterator itp;
    for (itp=ao->combosA.begin();itp!=ao->combosA.end();itp++){
      DEBUG("#Combo typename:"<<itp->first<<"  Table  size:"<<itp->second.tableA.size() <<" maxRow:" 
                              <<itp->second.max_row<< " maxCol:"<< itp->second.max_col <<"\n");
      std::vector< std::vector <int> > mytable= itp->second.tableA;
      for (int anidx=0; anidx < mytable.size(); anidx++) {
         DEBUG(mytable[anidx][0] <<" "<< mytable[anidx][1]); // asume 2 cols
         DEBUG("\n");
         if (pid==muon_t) return mytable[anidx][0];
         if (pid==tau_t ) return mytable[anidx][1];
      }
    }
    return (123); // never here
}

double count(AnalysisObjects* ao, string s, float id) {
    particleType pid = (particleType)id;

    DEBUG("STR:"<<s<<" Type:"<<pid<<" #J types:"<<ao->jets.size() << " #M types:"<<ao->muos.size()<<"\n");
    map <string, std::vector<dbxJet>  >::iterator it;
    for (it=ao->jets.begin();it!=ao->jets.end();it++){
      DEBUG("\t #Jtypename:"<<it->first<<"    size:"<<it->second.size() <<"\n");
    }

    DEBUG("\n");
    map <string,  indicesA  >::iterator itp;
    for (itp=ao->combosA.begin();itp!=ao->combosA.end();itp++){
      DEBUG("#C typename:"<<itp->first<<"    size:"<<itp->second.tableA.size() <<"\n");
    }

    ValueNode abc=ValueNode();
    switch (pid) {
//   case consti_t:   return (ao->truth.at(s).size()); break;
     case truth_t:    return (ao->truth.at(s).size()); break;
     case muon_t:     return (ao->muos.at(s).size()); break;
     case electron_t: return (ao->eles.at(s).size()); break;
     case tau_t:      return (ao->taus.at(s).size()); break;
     case jet_t:      return (ao->jets.at(s).size()); break;
     case bjet_t:     return ( (abc.tagJets(ao, 1, s) ).size()); break;
     case lightjet_t: return ( (abc.tagJets(ao, 0, s) ).size()); break;
     case fjet_t:     return (ao->ljets.at(s).size()); break;
     case photon_t:   return (ao->gams.at(s).size()); break;
     case combo_t:    if (ao->combosA.find(s)!=ao->combosA.end() ){
                           DEBUG(s<<" tableA max r,c:"<<ao->combosA.at(s).max_row <<" "<< ao->combosA.at(s).max_col<<"\n");
                           return (ao->combosA.at(s).max_row);
                      } else { 
                           DEBUG(s<<" Normal\n");    // to be continued     
                           return (ao->combos.at(s).size() );
                      }
                      break;
     default:        std::cerr<<"No such Particle Type:\n"; return (-1); break;
    }
    return (-1);
}

double met(AnalysisObjects* ao, string s, float id){
     DEBUG("MET:" << ao->met["MET"].Mod() <<"\n");
    return ( ao->met["MET"].Mod() );
}

double hlt_iso_mu(AnalysisObjects* ao, string s, float id){
     bool retval=ao->evt.HLT_IsoMu17_eta2p1_LooseIsoPFTau20;
     DEBUG("HLT_ISO_MU:" << retval <<"\n");
    return ( (double)retval );
}


double ht(AnalysisObjects* ao, string s, float id){
    double sum_htjet=0;
    for (UInt_t i=0; i<ao->jets.at(s).size(); i++) sum_htjet+=ao->jets.at(s).at(i).lv().Pt();
    return (sum_htjet  );
}

double userfuncA(AnalysisObjects* ao, string s, int id, std::vector<TLorentzVector> (*func)(std::vector<TLorentzVector> jets, int p1) ){
// string contains what to send
// id contains the particle type ASSUME ID=JET TYPE,

   DEBUG("UserfunctionA, s:"<<s<<" id: "<<id<<"\n");

   std::vector<TLorentzVector> myjets;
   for (UInt_t i=0; i<ao->jets.at(s).size(); i++) myjets.push_back(ao->jets.at(s).at(i).lv() );

   DEBUG("evaluating external function on jets: :"<<s<<"\n");
   std::vector<TLorentzVector> retjets= (*func)(myjets, id);
   DEBUG("external function Done. size:"<<retjets.size()<<"\n");
   for (int ipart=ao->jets.at(s).size()-1; ipart>=0; ipart--){ // I have all particles, jets, in an event.
     if (ipart > (retjets.size()-1) ) {
         (ao->jets).find(s)->second.erase( (ao->jets).find(s)->second.begin()+ipart);
     } else {
          ao->jets.at(s).at(ipart).setTlv( retjets[ipart] );
     }
   }
    return (1);
}

double userfuncB(AnalysisObjects* ao, string s, int id, double (*func)(std::vector<TLorentzVector> jets ) ){
// string contains what to send
// id contains the particle type ASSUME ID=JET TYPE,

   DEBUG("UserfunctionB :"<<s<<"\n");

   std::vector<TLorentzVector> myjets;
   for (UInt_t i=0; i<ao->jets.at(s).size(); i++) myjets.push_back(ao->jets.at(s).at(i).lv() );
   DEBUG("evaluating external function :"<<s<<"\n");
   double retvalue= (*func)(myjets);
   return (retvalue);
}

double userfuncC(AnalysisObjects* ao, string s, int id, double (*func)(std::vector<TLorentzVector> jets, TVector2 amet ) ){
// string contains what to send
// id contains the particle type ASSUME ID=JET TYPE,

   DEBUG("UserfunctionC :"<<s<<"\n");

   std::vector<TLorentzVector> myjets;
        TVector2 mymet=ao->met["MET"];
   for (UInt_t i=0; i<ao->jets.at(s).size(); i++) myjets.push_back(ao->jets.at(s).at(i).lv() );
   DEBUG("evaluating external function :"<<s<<"\n");
   double retvalue= (*func)(myjets, mymet);
   return (retvalue);
}

double userfuncD(AnalysisObjects* ao, string s, int id, TLorentzVector alv, double (*func)(std::vector<TLorentzVector> jets, TLorentzVector amet ) ){
// string contains what to send
// id contains the particle type ASSUME ID=JET TYPE,

   DEBUG("UserfunctionD :"<<s<<"\n");

   std::vector<TLorentzVector> myjets;
   for (UInt_t i=0; i<ao->jets.at(s).size(); i++) myjets.push_back(ao->jets.at(s).at(i).lv() );
   DEBUG("evaluating external function :"<<s<<"\n");
   double retvalue= (*func)(myjets, alv);
   return (retvalue);
}

double userfuncE(AnalysisObjects* ao, string s, int id, TLorentzVector l1, TLorentzVector l2,  TLorentzVector m1,
         double (*func)(TLorentzVector la, TLorentzVector lb, TLorentzVector amet ) ){
// string contains what to send
// id contains the particle type ASSUME ID=JET TYPE,

   DEBUG("UserfunctionE :"<<s<<"\n");
   DEBUG("evaluating external function :"<<s<<"\n");
   double retvalue= (*func)(l1, l2, m1);
   return (retvalue);
}

std::vector<TLorentzVector> sumobj(std::vector<TLorentzVector> myjets, int p1) {
 TLorentzVector h1;
 for (int i=0; i<myjets.size(); i++) {
  h1+=myjets[i];
 }
 std::vector<TLorentzVector> retval;
 retval.push_back(h1);
 return (retval);
}

std::vector<TLorentzVector> fhemisphere(std::vector<TLorentzVector> myjets, int p1) {
//                                               int p1=100*seed+assoc;
    int seed=int(p1/100);
    int assoc=int(p1%10);
    // Convert
    std::vector<float> px;
    std::vector<float> py;
    std::vector<float> pz;
    std::vector<float> E;
    for (int i=0; i<myjets.size(); i++) {
      px.push_back(myjets[i].Px());
      py.push_back(myjets[i].Py());
      pz.push_back(myjets[i].Pz());
      E.push_back(myjets[i].E());
    }
    // Run the hemisphere algorithm
    Hemisphere hemis(px, py, pz, E, seed, assoc);
    // Get the vector that gives int values for group number assigned to each jet
    std::vector<int> hemisgroup = hemis.getGrouping();
    // Combine jets in each group into one object
    std::vector<TLorentzVector> myhemispheres;
    TLorentzVector h1, h2;
    for (int i=0; i<myjets.size(); i++) {
      int hg = hemisgroup[i];
      if (hg == 1) h1 += myjets[i];
      if (hg == 2) h2 += myjets[i];
    }
    myhemispheres.push_back(h1);
    myhemispheres.push_back(h2);
    return myhemispheres;

}

double fMT2(TLorentzVector lep1, TLorentzVector lep2, TLorentzVector amet){
  double retval;
  DEBUG("MT2 function wrapper\n");
  mt2_bisect::mt2 mt2_event;
// Set momenta and the mass of the invisible particle, mn:
// where array pa[0..2], pb[0..2], pmiss[0..2] contains (mass,px,py)
  double pa[3], pb[3], pmiss[3];
  pa[0]=lep1.M();  pb[0]=lep2.M();  pmiss[0]=amet.M();
  pa[1]=lep1.Px(); pb[1]=lep2.Px(); pmiss[1]=amet.Px();
  pa[2]=lep1.Py(); pb[2]=lep2.Py(); pmiss[2]=amet.Py();
  double mn=0.0;

  mt2_event.set_momenta( pa, pb, pmiss );
  mt2_event.set_mn( mn );
  retval=mt2_event.get_mt2();
  return (retval);
}

double all(AnalysisObjects* ao, string s, float id){
    return 1;
}

double uweight(AnalysisObjects* ao, string s, float value){
        ao->evt.user_evt_weight *= value;
        return 1;
}

double lepsf(AnalysisObjects* ao, string s, float value){
        ao->evt.user_evt_weight *= ao->evt.weight_leptonSF;
        return 1;
}

double btagsf(AnalysisObjects* ao, string s, float value){
        ao->evt.user_evt_weight *= ao->evt.weight_bTagSF_77;
        return 1;
}

double xslumicorrsf(AnalysisObjects* ao, string s, float value){
	ao->evt.user_evt_weight *= ao->evt.correction_weight;
	ao->evt.user_evt_weight *= ao->evt.luminosity_weight;
	ao->evt.user_evt_weight *= ao->evt.weight_xsec;
	return 1;
}
