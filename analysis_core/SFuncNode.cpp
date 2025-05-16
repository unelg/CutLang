//
//  SFuncNode.cpp
//  mm
//
//  Created by Anna-Monica  on 8/2/18.
//  Copyright © 2018 Anna-Monica. All rights reserved.
//  Copyright © 2020 Gokhan Unel. All rights reserved.
//
#include <cmath>
#include "SFuncNode.h"
#include "ValueNode.h"
#include "ObjectNode.hpp"

//#define _CLV_
#ifdef _CLV_
#define DEBUG(a) std::cout<<a
#else
#define DEBUG(a)
#endif

void SFuncNode::setTTRaddr( TTreeReader *ttr, string s){
         int maxTTRdist =6;
         m_ttreader=ttr;

         cout << "** sf:"<< s<<"\t"; //this is special function
         special_function=true;
         TTree *at = m_ttreader->GetTree();
         TObjArray *lbranches = at->GetListOfBranches();
         if (lbranches == 0) {
            cerr<<"No branches found in this ntuple!\n";
            exit(-2);
         }
         std::vector<int> distances;
         for (int i = 0; i < lbranches->GetEntries(); ++i) {
          TBranch *abranch = (TBranch*)lbranches->At(i);
          int dist = levenshtein(s, abranch->GetName());
          distances.push_back(dist);
         }

         int minDist = *std::min_element(distances.begin(), distances.end());
         int minIndex = std::distance(distances.begin(), std::min_element(distances.begin(), distances.end()));
         TBranch *ab = (TBranch*)lbranches->At(minIndex);
         std::string bc_name=ab->GetClassName();
         std::string realstr=ab->GetName();
         TLeaf *aleaf = ab->GetLeaf(realstr.c_str());
         std::string type_name = aleaf->GetTypeName();
//         s=realstr; // should I keep the orig?
         cout << " Real Str:"<<realstr<< "\t type:"<<type_name<< " \t dist:"<<minDist << " TTR addr:"<<m_ttreader<<"\n";
         if (minDist > maxTTRdist) {
           cerr <<"ERROR !!!"<< s << " is not a branch in this NTUPLE\n";
           exit(-123);
         }

         if (  type_name.find("loat") != std::string::npos ) {
             ttrdrF = new SFTTreaderF( m_ttreader, realstr);
             ttrdr=ttrdrF;
         } else if (type_name.find("ouble") != std::string::npos ) {
             ttrdrD = new SFTTreaderD( m_ttreader, realstr);
             ttrdr=ttrdrD;
         } else if (type_name.find("nt") != std::string::npos ) {
             ttrdrI= new SFTTreaderI ( m_ttreader, realstr);
             ttrdr=ttrdrI;
         } else if (type_name.find("ool") != std::string::npos ) {
             ttrdrB= new SFTTreaderB ( m_ttreader, realstr);
             ttrdr=ttrdrB;
         } else if (type_name.find("har") != std::string::npos ) {
             ttrdrC= new SFTTreaderC ( m_ttreader, realstr);
             ttrdr=ttrdrC;
	 } else {
             cerr<<"Assuming Float for: "<< s<<"\n";
             ttrdrF = new SFTTreaderF( m_ttreader, realstr);
             ttrdr=ttrdrF;
         }
}

double SFuncNode::evaluate(AnalysisObjects* ao) {

        DEBUG("*******In SF,"<<symbol<<" Extern True/False:"<< ext <<"\n"); 
        if(userObjectA && !ext) {
           DEBUG("\t start user obj A type:"<< ((ObjectNode*)userObjectA)->type<<"\n"); 

           userObjectA->evaluate(ao); // returns 1, hardcoded. see ObjectNode.cpp
           value=((ObjectNode*)userObjectA)->type; //ngu added this as a temporary solution as he uses 2nd creator
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
		  case 10:  aPart->setTlv( aPart->lv()+ao->truth[ac].at(ai).lv()  );   break;
                  case 12:  aPart->setTlv( aPart->lv()+ao->muos[ac].at(ai).lv()   );   break;
                  case  1:  aPart->setTlv( aPart->lv()+ao->eles[ac].at(ai).lv()   );   break;
                  case 11:  aPart->setTlv( aPart->lv()+ao->taus[ac].at(ai).lv()   );   break;
                  case  2:  aPart->setTlv( aPart->lv()+ao->jets[ac].at(ai).lv()   );   break;
                  case 19:  aPart->setTlv( aPart->lv()+ao->track[ac].at(ai).lv() );   break;
                  case 20:  aPart->setTlv( aPart->lv()+ao->combos[ac].at(ai).lv() );   break;
                   case 9:  aPart->setTlv( aPart->lv()+ao->ljets[ac].at(ai).lv()  );   break;
                   case 8:  aPart->setTlv( aPart->lv()+ao->gams[ac].at(ai).lv()   );   break;
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
                   case 20:  bPart->setTlv(  bPart->lv()+ao->combos[ac].at(ai).lv() ); break;
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
        DEBUG ("Before Eval:"<<symbol<<" Value:"<<value<< " Type:"<<type<<"\n");
        if (left != NULL && !userObjectA ) { // there is a child node to evalute, like a weight function. there must be no userObjA.
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
              double retval;
              if (g1 != NULL) {retval=(*g1)(ao, symbol, type, h1 ); // A
                              }
           else if (g2 != NULL) {retval=(*g2)(ao, symbol, type, h2 ); // B
                              }
           else if (g3 != NULL) {retval=(*g3)(ao, symbol, type, h3 ); // C
                              }
           else if (g4 != NULL) {retval=(*g4)(ao, symbol, type, aPart->lv(), h4); // D
                              }
           else if (g5 != NULL) { // E
                if ( BUFFERED_VALUES.find(extkey.Data()) !=BUFFERED_VALUES.end() ){
                   DEBUG("Returning buffered value:"<<(BUFFERED_VALUES[extkey.Data()]) << "\n");
                   delete aPart;
                   delete bPart;
                   delete cPart;
                   return (BUFFERED_VALUES[extkey.Data()]);
                } else { 
                   retval=(*g5)(ao, symbol, type, aPart->lv(), bPart->lv(), cPart->lv(), h5);
                   BUFFERED_VALUES.insert(std::pair<string, double >(extkey.Data(), retval));
                }
              }
           else if (g6 != NULL) { // F
            retval=(*g6)(ao, symbol, type, pv1, pv2, pv3, pv4,  h6);
           }

           delete aPart;
           delete bPart;
           delete cPart;
           return retval;
        }
        delete aPart;
        delete bPart;
        delete cPart;

        if (special_function) {
                  double avalue=ttrdr->readvalue();
                  DEBUG(symbol<<" SF read new attrib:"<< avalue << "\n");
                  return avalue;
        }
        double arv=(*f)(ao, symbol, value);              
        DEBUG("ARV="<<arv<<"\n");
        return arv;
}

void SFuncNode::Reset() {
      DEBUG (" SF Resetting cache \n");
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
      DEBUG("#ComboA typename:"<<itp->first<<"    size:"<<itp->second.tableA.size() <<"\n");
    }

    ValueNode abc=ValueNode();
    switch (pid) {
     case truth_t:    return (ao->truth.at(s).size()); break;
     case track_t:    return (ao->track.at(s).size()); break;
     case muon_t:     return (ao->muos.at(s).size()); break;
     case electron_t: return (ao->eles.at(s).size()); break;
     case tau_t:      return (ao->taus.at(s).size()); break;
     case jet_t:      return (ao->jets.at(s).size()); break;
     case bjet_t:     return ( (abc.tagJets(ao, 1, s) ).size()); break;
     case lightjet_t: return ( (abc.tagJets(ao, 0, s) ).size()); break;
     case fjet_t:     return (ao->ljets.at(s).size()); break;
     case photon_t:   return (ao->gams.at(s).size()); break;
     case consti_t:   return (ao->constits.at(s).size()); break;
     case combo_t:    if (ao->combosA.find(s)!=ao->combosA.end() ){
                           DEBUG(s<<" tableA max r,c:"<<ao->combosA.at(s).max_row <<" "<< ao->combosA.at(s).max_col<<"\n");
                           return (ao->combosA.at(s).max_row);
                      } else { 
                           DEBUG(s<<" Normal\n");    // to be continued     
                           return (ao->combos.at(s).size() );
                      }
                      break;
     default:        std::cerr<<"count No such Particle Type:"<<pid<<" for collection:"<<s<<"\n"; return (-1); break;
    }
    return (-1);
}

double met(AnalysisObjects* ao, string s, float id){
     DEBUG("MET:" << ao->met["MET"].Mod() <<"\n");
    return ( ao->met["MET"].Mod() );
}

//MetSig
//double resopt(double pt) {return sqrt((pt * pt) * pow((5.6 / pt), 2) + pow((1.25 / sqrt(pt)), 2) + 0.0332);} existing coefficients

double resopt(double pt) {return 1.05729 - 0.452141*log(pt) + 0.067873*pow(log(pt),2) - 0.00343522*pow(log(pt),3);} // checkmate's coefficients

//double resophi(double pt) {return sqrt((pt * pt) * pow((4.75 / pt), 2) + pow((0.426 / sqrt(pt)), 2) + 0.0232);} // existing coefficients

double resophi(double pt) {return pt < 100 ? 1.23*pow(pt, -0.95) : 0.017;} // checkmate's coefficients
// these are only for jets, need to find coefficients for other analysis objects

void rotateXY(TMatrix &mat, TMatrix &mat_new, double phi) {
     double c = cos(phi);
     double s = sin(phi);
     double cc = c*c;
     double ss = s*s;
     double cs = c*s;

     mat_new(0,0) = mat(0,0)*cc + mat(1,1)*ss - cs*(mat(1,0) + mat(0,1));
     mat_new(0,1) = mat(0,1)*cc - mat(1,0)*ss + cs*(mat(0,0) - mat(1,1));
     mat_new(1,0) = mat(1,0)*cc - mat(0,1)*ss + cs*(mat(0,0) - mat(1,1));
     mat_new(1,1) = mat(0,0)*ss + mat(1,1)*cc + cs*(mat(1,0) + mat(0,1));
}

double metsig(AnalysisObjects* ao, string s, float id){  
  double npt, nphi;
  TVector2 softVec = ao->met["MET"];
  TMatrix cov_sum(2,2);
  TMatrix particle_u(2,2),particle_u_rot(2,2);
  for (int nj=0; nj< ao->jets.at("JET").size(); nj++){
    nphi = ao->jets["JET"].at(nj).lv().Phi();
    npt  = ao->jets["JET"].at(nj).lv().Pt();
    double dphi = TVector2::Phi_mpi_pi(ao->met["MET"].Phi() - nphi);
    particle_u(0,0) = pow(resopt(npt)*npt,2);
    particle_u(1,1) = pow(resophi(npt)*npt,2);
    rotateXY(particle_u, particle_u_rot, dphi);
    cov_sum += particle_u_rot;
	  
  }  
  for (int nj=0; nj<ao->muos.at("MUO").size(); nj++){
    nphi = ao->muos["MUO"].at(nj).lv().Phi();
    npt  = ao->muos["MUO"].at(nj).lv().Pt();
    double dphi = TVector2::Phi_mpi_pi(ao->met["MET"].Phi() - nphi);
    particle_u(0,0) = pow(resopt(npt)*npt,2);
    particle_u(1,1) = pow(resophi(npt)*npt,2);
    rotateXY(particle_u, particle_u_rot, dphi);
    cov_sum += particle_u_rot;
  }
  for (int nj=0; nj<ao->eles.at("ELE").size(); nj++){
    nphi = ao->eles["ELE"].at(nj).lv().Phi();
    npt  = ao->eles["ELE"].at(nj).lv().Pt();
    double dphi = TVector2::Phi_mpi_pi(ao->met["MET"].Phi() - nphi);
    particle_u(0,0) = pow(resopt(npt)*npt,2);
    particle_u(1,1) = pow(resophi(npt)*npt,2);
    rotateXY(particle_u, particle_u_rot, dphi);
    cov_sum += particle_u_rot;
  }
  for (int nj=0; nj<ao->gams.at("PHO").size(); nj++){
    nphi = ao->gams["PHO"].at(nj).lv().Phi();
    npt  = ao->gams["PHO"].at(nj).lv().Pt();
    double dphi = TVector2::Phi_mpi_pi(ao->met["MET"].Phi() - nphi);
    particle_u(0,0) = pow(resopt(npt)*npt,2);
    particle_u(1,1) = pow(resophi(npt)*npt,2);
    rotateXY(particle_u, particle_u_rot, dphi);
    cov_sum += particle_u_rot;
  }
  // soft term
  particle_u(0,0) = 10*10;
  particle_u(1,1) = 10*10;
  double dphi2 = TVector2::Phi_mpi_pi(ao->met["MET"].Phi() - softVec.Phi());
  rotateXY(particle_u, particle_u_rot, dphi2);
  cov_sum+=particle_u_rot;

  double varL = cov_sum(0,0);
  double varT = cov_sum(1,1);
  double covLT = cov_sum(0,1);

  double significance = 0;
  double rho = 0;

  double met = ao->met["MET"].Mod();
  if( varL != 0 ){
    rho = covLT / sqrt( varL * varT ) ;
    if (fabs( rho ) >= 0.9 ) rho = 0; //too large - ignore it
    significance = met/sqrt((varL*(1-pow(rho,2))));
  }
 
  return significance;
}

//MetSig end

double hlt_iso_mu(AnalysisObjects* ao, string s, float id){
     bool retval=ao->evt.HLT_IsoMu17_eta2p1_LooseIsoPFTau20;
     DEBUG("HLT_ISO_MU:" << retval <<"\n");
    return ( (double)retval );
}
double hlt_trg(AnalysisObjects* ao, string s, float id){
     bool retval=1;
     DEBUG("HLT_TRG "<< s <<":" << retval <<"\n");
     if (ao->evt.hlt_map.find(s)!=ao->evt.hlt_map.end()) retval=ao->evt.hlt_map[s];
     return ( (double)retval );
}


double ht(AnalysisObjects* ao, string s, float id){
    double sum_htjet=0;
    particleType pid = (particleType)id;
    switch (pid){
     case truth_t:    for (UInt_t i=0; i<ao->truth.at(s).size(); i++) sum_htjet+=ao->truth.at(s).at(i).lv().Pt(); break;
     case muon_t:     for (UInt_t i=0; i<ao->muos.at(s).size(); i++) sum_htjet+=ao->muos.at(s).at(i).lv().Pt(); break;
     case electron_t: for (UInt_t i=0; i<ao->eles.at(s).size(); i++) sum_htjet+=ao->eles.at(s).at(i).lv().Pt(); break;
     case tau_t:      for (UInt_t i=0; i<ao->taus.at(s).size(); i++) sum_htjet+=ao->taus.at(s).at(i).lv().Pt(); break;
     case jet_t:      for (UInt_t i=0; i<ao->jets.at(s).size(); i++) sum_htjet+=ao->jets.at(s).at(i).lv().Pt();   break;
     case fjet_t:     for (UInt_t i=0; i<ao->ljets.at(s).size(); i++) sum_htjet+=ao->ljets.at(s).at(i).lv().Pt(); break;
     case photon_t:   for (UInt_t i=0; i<ao->gams.at(s).size(); i++) sum_htjet+=ao->gams.at(s).at(i).lv().Pt(); break;
     case combo_t:    for (UInt_t i=0; i<ao->combos.at(s).size(); i++) sum_htjet+=ao->combos.at(s).at(i).lv().Pt(); break;

     default:        std::cerr<<"ht No such Particle Type:"<<pid <<"\n"; return (-1); break;
    }
    return (sum_htjet);
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
         ao->jets.at(s).erase( ao->jets.at(s).begin()+ipart );
     } else {
          ao->jets.at(s).at(ipart).setTlv( retjets[ipart] );
     }
   }

//   cout <<s<<"\n";
//   if (retjets.size() < ao->jets.at(s).size()) 
//       ao->jets.at(s).erase(ao->jets.at(s).begin(), ao->jets.at(s).begin()+ao->jets.at(s).size()-retjets.size()); 
//   ao->jets.at(s).resize(retjets.size());
//   ao->jets.at(s).shrink_to_fit(); 
//   for (int ipart=0; ipart<retjets.size(); ipart++){
//          ao->jets.at(s).at(ipart).setTlv( retjets[ipart] );
//   }
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

double userfuncF(AnalysisObjects* ao, string s, int id, double l1, double l2,  double m1, double l3,
          double (*func)(double la, double lb, double amet, double lab ) ){
// string contains what to send
// id contains the particle type ASSUME ID=JET TYPE,

   DEBUG("UserfunctionF :"<<s<<"\n");
   DEBUG("evaluating external function :"<<s<<"\n");
   double retvalue= (*func)(l1, l2, m1, l3);
   return (retvalue);
}




std::vector<TLorentzVector> negsumobj(std::vector<TLorentzVector> myjets, int p1) {
 TLorentzVector h1;
 for (int i=0; i<myjets.size(); i++) {
  h1+=myjets[i];
 }
 
 std::vector<TLorentzVector> retval;
 retval.push_back(-h1);
 return (retval);
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
    std::vector<TLorentzVector> myhemispheres;
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

double none(AnalysisObjects* ao, string s, float id){
    return 0;
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
double specialsf(AnalysisObjects* ao, string s, float value){
        return 1;
}

int levenshtein(const std::string &s1_input, const std::string &s2_input) {

    std::string s1 = s1_input, s2 = s2_input;
    std::transform(s1.begin(), s1.end(), s1.begin(), [](unsigned char c){ return std::tolower(c); });
    std::transform(s2.begin(), s2.end(), s2.begin(), [](unsigned char c){ return std::tolower(c); });

    if (s1[0] != s2[0]) return 1000;

    const size_t len1 = s1.size(), len2 = s2.size();
    std::vector<std::vector<int>> d(len1 + 1, std::vector<int>(len2 + 1));

    d[0][0] = 0;
    for(unsigned int i = 1; i <= len1; ++i) d[i][0] = i;
    for(unsigned int i = 1; i <= len2; ++i) d[0][i] = i;

    for(unsigned int i = 1; i <= len1; ++i)
        for(unsigned int j = 1; j <= len2; ++j)
            d[i][j] = std::min({ d[i - 1][j] + 1, d[i][j - 1] + 1, d[i - 1][j - 1] + (s1[i - 1] == s2[j - 1] ? 0 : 1) });

    return d[len1][len2];
};

TMatrixDSym TLVecToTensor(TLorentzVector obj){
  TMatrixDSym retTensor(3); 
  retTensor.Zero();
  retTensor[0][0] += obj.Px() * obj.Px();
  retTensor[1][1] += obj.Py() * obj.Py();
  retTensor[2][2] += obj.Pz() * obj.Pz();
  retTensor[0][1] += obj.Px() * obj.Py();
  retTensor[1][0] += obj.Py() * obj.Px();
  retTensor[0][2] += obj.Px() * obj.Pz();
  retTensor[2][0] += obj.Pz() * obj.Px();
  retTensor[1][2] += obj.Py() * obj.Pz();
  retTensor[2][1] += obj.Pz() * obj.Py();
  return retTensor;
}

TMatrixDSym getMomentumTensor(AnalysisObjects* ao, string s, float id){
  TMatrixDSym retTensor(3);
  particleType pid = (particleType)id;
  retTensor.Zero();
  switch (pid){
  case truth_t:    for (UInt_t i=0; i<ao->truth.at(s).size(); i++) retTensor+=TLVecToTensor(ao->truth.at(s).at(i).lv()); break;
  case muon_t:     for (UInt_t i=0; i<ao->muos.at(s).size(); i++) retTensor+=TLVecToTensor(ao->muos.at(s).at(i).lv()); break;
  case electron_t: for (UInt_t i=0; i<ao->eles.at(s).size(); i++) retTensor+=TLVecToTensor(ao->eles.at(s).at(i).lv()); break;
  case tau_t:      for (UInt_t i=0; i<ao->taus.at(s).size(); i++) retTensor+=TLVecToTensor(ao->taus.at(s).at(i).lv()); break;
  case jet_t:      for (UInt_t i=0; i<ao->jets.at(s).size(); i++) retTensor+=TLVecToTensor(ao->jets.at(s).at(i).lv());   break;
  case fjet_t:     for (UInt_t i=0; i<ao->ljets.at(s).size(); i++) retTensor+=TLVecToTensor(ao->ljets.at(s).at(i).lv()); break;
  case photon_t:   for (UInt_t i=0; i<ao->gams.at(s).size(); i++) retTensor+=TLVecToTensor(ao->gams.at(s).at(i).lv()); break;
  case combo_t:    for (UInt_t i=0; i<ao->combos.at(s).size(); i++) retTensor+=TLVecToTensor(ao->combos.at(s).at(i).lv()); break;
  }
  retTensor *= 1./(retTensor[0][0]+retTensor[1][1]+retTensor[2][2]);
  return retTensor;
}

double fAplanarity(AnalysisObjects* ao, string s, float id){
  double retval;
  int ao_size = count(ao,s,id);
  if( ao_size > 2 ){
    TMatrixDSym momentumTensor(3);
    TVectorD eigenValues(3);
    momentumTensor = getMomentumTensor(ao,s,id);
    TMatrixDSymEigen eigenSystem(momentumTensor);
    eigenValues = eigenSystem.GetEigenValues();
    retval = 1.5 * eigenValues(2);
    return retval;
  } 
  else { 
    retval = 0.;
  }
  return retval;
}

double fSphericity(AnalysisObjects* ao, string s, float id){
  double retval;
  int ao_size = count(ao,s,id);
  if( ao_size > 2 ){
    TMatrixDSym momentumTensor(3);
    TVectorD eigenValues(3);
    momentumTensor = getMomentumTensor(ao,s,id);
    TMatrixDSymEigen eigenSystem(momentumTensor);
    eigenValues = eigenSystem.GetEigenValues();
    retval = 1.5 * (eigenValues(1)+eigenValues(2));
    return retval;
  } 
  else { 
    retval = 0.;
  }
  return retval;
}
