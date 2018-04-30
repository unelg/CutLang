#ifndef DBX_CUT_CPP
#define DBX_CUT_CPP

#include "dbxCut.h"
#include "ex1.h"
#include <math.h>

//#define _CLV_
#ifdef _CLV_
#define DEBUG(a) std::cout<<a
#else
#define DEBUG(a) 
#endif

ClassImp(dbxCut)

dbxCut::dbxCut( std::string name){p_name=name; p_searchable=false; p_Npart=0;}
dbxCut::dbxCut( std::string name, int i){p_name=name; p_cuti=i; p_searchable=false; p_Npart=0;}
dbxCut::dbxCut( std::string name, std::vector<int> mytypes, std::vector<int> myids,  int myparam)
{
                p_name=name; p_part_type=mytypes; p_part_index=myids; p_Npart=0;
                p_params.clear(); p_params.push_back(myparam);                 
                bool sresult=false;
                for (size_t it=0; it<p_part_index.size(); it++)
                        if (p_part_index.at(it) < 0) {sresult=true; p_searchable_types.push_back( p_part_type.at(it) );
                }
                DEBUG("searchable?:"<<sresult<<" w/"); for (size_t it=0; it<p_searchable_types.size(); it++) DEBUG(p_searchable_types[it]<<",");
                p_searchable=sresult;
                aparticle=new dbxParticle[16];
}  
void dbxCut::addTypesIndexes(std::vector<int> newtypes, std::vector<int> newids){
              bool sresult=false;
              for (size_t i=0; i<newtypes.size(); i++) if (newids[i] < 0) { 
                     sresult=true; // some intelligence is needed after here.
                     bool itisNew=true;
                     for (size_t ii=0; ii<p_part_type.size(); ii++){
                        if (p_part_type[ii] == newtypes[i]) 
                         if (p_part_index[ii] == newids[i])
                             itisNew=false; // we have this ID before.
                     }
                     if (itisNew)  p_searchable_types.push_back( newtypes[i] );
              }//first loop is only for negative ids

// now we add the new guys 
              for (size_t i=0; i<newtypes.size(); i++){
                  DEBUG("Adding:"<<newtypes[i]<<"@"<<newids[i]<<" ");
                  p_part_type.push_back(newtypes[i]);
                  p_part_index.push_back(newids[i]);
              }//new types and ids 

              if (!p_searchable) p_searchable=sresult;
}
//-----------------tagJets
std::vector<dbxJet> dbxCut::tagJets(AnalysisObjects *ao, int jtype)
{
                    std::vector<dbxJet>      rjets;
                    for (size_t jj=0; jj<ao->jets.size(); jj++) if (ao->jets.at(jj).isbtagged_77() == jtype) {rjets.push_back(ao->jets.at(jj)); }    
                    return rjets;
}
//-----------------partConstruct
dbxParticle dbxCut::partConstruct(AnalysisObjects *ao, int order)
{
                   // return (myPart); // returning here results in 3.35s for 25k events
                    myPart.Reset();
                    size_t kk=0, kstart=0, pcount=0;
                    DEBUG("O:"<<order<< " #p:"<<p_part_type.size()<<" ");
                    if (order>1) {
                     for (kk=0; kk<p_part_type.size(); kk++){
                      if (p_part_type.at(kk)==-1) pcount++;           
                      if ((order-1) == pcount) break;
                     } // count until you find -1 which is the comma separating the two particles
                    kstart=kk+1; // this is my new start value
                    } // end of if
// now I start constructing my particles.
                    DEBUG("Start@"<<kstart<<" ");
                    if (kstart >= p_part_type.size()) {std::cout << "countint ERROR, STOP\n"; exit (-11);}
                    float v_eta; 
//                  return myPart; //----------------------------> 3.35s
                    for (kk=kstart; kk<p_part_type.size(); kk++){ 
                                  if (p_part_index.at(kk) < 0)  { 
                                   DEBUG(" "<<p_part_index.at(kk)<<"@"<<kk<<"\t");
                                  } else {
                                         switch (p_part_type.at(kk)) { // unused cases don't cost any time.
                                            case -1: DEBUG("MPS ");
                                                     break;
                                            case 0: myPart.setTlv(myPart.lv()+ao->muos[ p_part_index.at(kk) ].lv() ); // 0 is muon
                                                    myPart.setCharge(myPart.q()+ao->muos[ p_part_index.at(kk) ].q() );
                                                    DEBUG("muon:"<<p_part_index.at(kk)<<" ");
                                                    break;
                                            case 1: myPart.setTlv(myPart.lv()+ao->eles[ p_part_index.at(kk) ].lv() ); // 1 is electron
                                                    myPart.setCharge(myPart.q()+ao->eles[ p_part_index.at(kk) ].q() );
                                                    DEBUG("electron:"<<p_part_index.at(kk)<<"  ");
                                                    break;
                                           case 2: myPart.setTlv(myPart.lv()+ao->jets[ p_part_index.at(kk)].lv() ); // 2 is any jet
//                                                  DEBUG("jet:"<<p_part_index.at(kk)<<" ");
                                                  break;
//                                            case 2: myPart.addTlv(  &(ao->jets[ p_part_index.at(kk)].lv()) ); // 2 is any jet
//                                                    break;
                                            case 3: myPart.setTlv(myPart.lv()+tagJets(ao, 1)[ p_part_index.at(kk) ].lv() ); // 3 is a b jet
                                                    DEBUG("b-jet:"<<p_part_index.at(kk)<<"  ");
                                                    break;
                                            case 4: myPart.setTlv(myPart.lv()+tagJets(ao,0)[ p_part_index.at(kk) ].lv()); // 4 is light jet
                                                    DEBUG("qgjet:"<<p_part_index.at(kk)<<" ");
                                                    break;
                                            case 5: v_eta=ao->muos[p_part_index.at(kk)].lv().Eta();
                                                    ametlv.SetPtEtaPhiM(ao->met.Mod(), v_eta,ao->met.Phi(),0);
                                                    myPart.setTlv(myPart.lv()+ametlv); // met4v is v from MET using same eta approx.
                                                    DEBUG("muMET ");
                                                    break;
                                            case 6: v_eta=ao->eles[p_part_index.at(kk)].lv().Eta();
                                                    ametlv.SetPtEtaPhiM(ao->met.Mod(), v_eta,ao->met.Phi(),0);
                                                    myPart.setTlv(myPart.lv()+ametlv); // v from MET using same eta approx.
                                                    DEBUG("eleMET ");
                                                    break;
                                            case 7: ametlv.SetPxPyPzE(ao->met.Px(), ao->met.Py(), 0, ao->met.Mod());
                                                    myPart.setTlv(myPart.lv()+ametlv); // v from MET using same eta approx.
                                                    DEBUG("MET PV ");
                                                    break;
                                            case 8: if (p_part_index.at(kk)==6213) {
                                                      myPart.setCharge( ao->gams.size() );
                                                      DEBUG("#gams:"<< ao->gams.size()<<" ");
                                                    } else {
                                                      myPart.setTlv(myPart.lv()+ao->gams[ p_part_index.at(kk) ].lv()); // 8 is gammas
                                                      DEBUG("gamma:"<<p_part_index.at(kk)<<" ");
                                                    }
                                                    break;

                                           default: std::cout<<"No such object! ERROR\n";
                                                    break;
                                           } // end of case

                                       } // end of regular particle addition
                                       if (p_part_type.at(kk)==-1) break;
                        } 
                        return myPart;
}

//-----------------getSearchableType
int dbxCut::getSearchableType(int idx)
{
                       if (idx<0) {return p_searchable_types.size();
                       } else {return p_searchable_types.at(idx); }
}
//-----------------getParticleIndex
int dbxCut::getParticleIndex(int idx)
{
                       if (idx<0) {return p_part_index.size();
                       } else {return p_part_index.at(idx); }
}
//-----------------clear Found Results
void dbxCut::clearFoundResults()
{
                       for (size_t ikp=0; ikp<p_keep_idx.size(); ikp++) setParticleIndex( p_keep_idx[ikp], p_keep_vals[ikp]);
                       p_keep_idx.clear();
                       p_keep_vals.clear();
}
//-----------------use Found Results
void dbxCut::useFoundResults()
{
             std::vector<int> found_list=getFoundVector();
#ifdef _CLV_
             DEBUG("  will use previous results, #p:"<<getParticleIndex()<<"\t");
             DEBUG("particle_list:"); for (int ppp=0; ppp<getParticleIndex(); ppp++) DEBUG(getParticleIndex(ppp)<<" ");DEBUG(std::endl);
             DEBUG(" found_list:"); for (size_t ppp=0; ppp<found_list.size(); ppp++) DEBUG(found_list[ppp]<<" ");DEBUG("\t");
             DEBUG(" found_Oi_list:"); for (size_t ppp=0; ppp<p_found_orig_idxs.size(); ppp++) DEBUG(p_found_orig_idxs[ppp]<<" ");DEBUG("\t");
             DEBUG(" found_Ot_list:"); for (size_t ppp=0; ppp<p_found_types.size(); ppp++) DEBUG(p_found_types[ppp]<<",");DEBUG(std::endl);
#endif
             int tpp=0; // we have a match already, to be optimized later.

             for (int pp=0; pp<getParticleIndex(); pp++ ){
              if (tpp == found_list.size()) break;
              DEBUG("@:"<<pp<<"  idx:"<<getParticleIndex(pp)<<"\t");
              if  ( (getParticleIndex(pp)==p_found_orig_idxs[tpp] )
                 || ((getParticleIndex(pp)<0) && ( p_found_orig_idxs.size() >found_list.size()) ) // preselected. 
                  ){
                       p_keep_idx.push_back(pp); p_keep_vals.push_back(getParticleIndex(pp) );
                       DEBUG("replacing @"<<pp<<" with:"<<found_list.at(tpp)<<"\n");
                       setParticleIndex(pp, found_list[tpp] ) ; // which particle index to replace
                       tpp++;
              }
             }//end of loop over all particles

// anything left?-----------------------
         std::vector<int> secondary_idx;
         std::vector<int> secondary_pos;
         int prev_idx=0;
         for (int pp=0; pp<getParticleIndex(); pp++ ) {
           int api=getParticleIndex(pp);
           if (api<0){ //loop over all particle indexes
              DEBUG (api<<"@"<<pp<<"~>");
              for (int ov=0; ov<found_list.size(); ov++){ // previously found guys
                 if ( (p_found_orig_idxs[ov] == api) && ( p_part_type[pp] == p_found_types[ov] ) )
                  { // previous found index does it match the current one?
                       if (prev_idx == api) { prev_idx=0; continue;} // skip this match take next one
 ////////                      DEBUG ("<"<<p_part_type[pp]<<"?"<<p_found_types[ov]<<">"); // I know previous type.
                       DEBUG (found_list[ov]<<" |");
//set the index here. also save the previous values
                       secondary_idx.push_back(api);
                       secondary_pos.push_back(pp);
                       setParticleIndex( pp, found_list[ov] ); // same as we looped over.
                       prev_idx=api;
                       break; // should break the first loop
                  }
              }// loop pre-existing ones
           }// found unused neg.
         }// loop over all particles
//add to ....
        for (size_t pp=0; pp<secondary_idx.size(); pp++) { p_keep_idx.push_back(secondary_pos[pp]); p_keep_vals.push_back(secondary_idx[pp]);}

}
//-----------------getSearchableType
bool dbxCut::Ccompare(float v)
{
                       if (p_oper=="~=" || p_oper=="~!") { return (true);} // these are combi selections, always pass.
                       if (p_oper=="EQ" || p_oper=="==") { return (v==p_cutf);}
                       if (p_oper=="NE" || p_oper=="!=") { return (v!=p_cutf);}
                       if (p_oper=="LE" || p_oper=="<=") { return (v<=p_cutf);}
                       if (p_oper=="LT" || p_oper=="<")  { return (v< p_cutf);}
                       if (p_oper=="GE" || p_oper==">=") { return (v>=p_cutf);}
                       if (p_oper=="GT" || p_oper==">")  { return (v> p_cutf);}
                       if (p_oper=="[]") { return ((v>=p_min) && (v<=p_max));} 
                       if (p_oper=="][") { return ((v<=p_min) && (v>=p_max));}
                       return false;
}

//-------------------------------------arithmetic ops
bool dbxCut::isSpecial(int order)
{
   bool rv=false;
   int op_start=0, op_stop=-1;
   for (size_t iop=0; iop< p_arith_ops.size(); iop++){
       op_stop++;
       if ( p_arith_vals[iop]==0 ) {break;}
   }
/*
   if (order>=1) {
     op_start=op_stop; 
     for (size_t iop=op_start; iop< p_arith_ops.size(); iop++){
       if ( p_arith_vals[iop]==0 ) {break;}
       op_stop++;
     }
   } 
*/
   if (order>=2) {
     op_stop++;
     op_start=op_stop; 
     for (size_t iop=op_start; iop< p_arith_ops.size(); iop++){
       op_stop++;
       if ( p_arith_vals[iop]==0 ) {break;}
     }
   } 
   if (order>=3) {
     op_stop++;
     op_start=op_stop; 
     for (size_t iop=op_start; iop< p_arith_ops.size(); iop++){
       op_stop++;
       if ( p_arith_vals[iop]==0 ) {break;}
     }
   } 

   if (op_start==op_stop) rv=true;
   DEBUG("[SO"<<order<<":"<<rv<<"] ");
   return rv;

}
//-------------------------------------arithmetic ops
float dbxCut::doArithOps(float v, int order, float vt)
{
   int op_start=0, op_stop=-1;
// for (size_t iop=0; iop< p_arith_ops.size(); iop++){
//     DEBUG("[@"<<iop<<p_arith_ops[iop]<<p_arith_vals[iop]<<"] ");
// }

   for (size_t iop=0; iop< p_arith_ops.size(); iop++){
       op_stop++;
       if ( p_arith_vals[iop]==0 ) {break;}
   }

   if (order>=2) {
     op_stop++;
     op_start=op_stop; 
     for (size_t iop=op_start; iop< p_arith_ops.size(); iop++){
       if ( p_arith_vals[iop]==0 ) {break;}
       op_stop++;
   }
   } 
   if (order>=3) {
     op_stop++;
     op_start=op_stop; 
     for (size_t iop=op_start; iop< p_arith_ops.size(); iop++){
       if ( p_arith_vals[iop]==0 ) {break;}
       op_stop++;
   }
   } 
   if (order>=4) {
     op_stop++;
     op_start=op_stop; 
     for (size_t iop=op_start; iop< p_arith_ops.size(); iop++){
       if ( p_arith_vals[iop]==0 ) {break;}
       op_stop++;
   }
   } 

   DEBUG(" @"<<order<<" From:"<<op_start<<" To:"<<op_stop<<" ");

   if (vt == 0 ) {
     for (int iop=op_start; iop<op_stop; iop++){
     if (p_arith_ops[iop]=='+') { v+=p_arith_vals[iop];        continue;}
     if (p_arith_ops[iop]=='-') { v-=p_arith_vals[iop];        continue;}
     if (p_arith_ops[iop]=='*') { v*=p_arith_vals[iop];        continue;}
     if (p_arith_ops[iop]=='/') { v/=p_arith_vals[iop];        continue;}
     if (p_arith_ops[iop]=='^') { v=pow(v, p_arith_vals[iop]); continue;}

//   if (p_arith_ops[iop]=='+') { v+=p_arith_vals[iop]; DEBUG(" +"<<p_arith_vals[iop]); continue;}
//   if (p_arith_ops[iop]=='-') { v-=p_arith_vals[iop]; DEBUG(" -"<<p_arith_vals[iop]); continue;}
//   if (p_arith_ops[iop]=='*') { v*=p_arith_vals[iop]; DEBUG(" *"<<p_arith_vals[iop]); continue;}
//   if (p_arith_ops[iop]=='/') { v/=p_arith_vals[iop]; DEBUG(" /"<<p_arith_vals[iop]); continue;}
//   if (p_arith_ops[iop]=='^') { v=pow(v, p_arith_vals[iop]); DEBUG(" ^"<<p_arith_vals[iop]); continue;}
      
     }
   } else {
     int iop=op_stop;
          if (p_arith_ops[iop]=='+') { vt+=v;  }
    else  if (p_arith_ops[iop]=='-') { vt-=v;  }
    else  if (p_arith_ops[iop]=='*') { vt*=v;  }
    else  if (p_arith_ops[iop]=='/') { vt/=v;  }
     v=vt;
   } //end of else
   return v;
}

//-------------------------------------forbidden list

bool dbxCut::isForbidden(int idx, int type )
{
     bool retval=false;
     int flistsize= getForbiddenPair().first ;
        for (int kk=0; kk<flistsize; kk++){
//           DEBUG(idx<<":i?"<<getForbiddenPair(kk).first<<" "<<type<<":t?"<<getForbiddenPair(kk).second<<"\n");
           if (idx==getForbiddenPair(kk).first && type== getForbiddenPair(kk).second) {
           retval=true; break;
           }
        }
        return retval;
}

bool dbxCut::find(AnalysisObjects *ao)
{
          float abig=999999999999.9; float asmall=0.0; float adelta, aresult;
          const int unk_MAX=6;
          int found_idx[unk_MAX], ip_N[unk_MAX]={0,0,0,0,0,0}; int pp_target[unk_MAX]={-1, -1, -1, -1, -1, -1}; // assume max variables
          int search_types[unk_MAX]={-1, -1, -1, -1, -1, -1}, oldvals[unk_MAX]={0,0,0,0,0,0}; 
          if (getSearchableType() >unk_MAX) { 
                     std::cerr<< "Can NOT optimize "<< getSearchableType() <<" variables. ERROR.\n"; //TODO
                     return 0;}
          int ip2_min=0, ip3_min=0, ip4_min=0, ip5_min=0, ip6_min=0;
//        for (int kik=0; kik<getSearchableType(); kik++){ DEBUG(kik<<":"<<getSearchableType(kik)<<"  ");} DEBUG("\n"); 
//        for (int kik=0; kik<getParticleIndex(); kik++){ DEBUG(kik<<":"<<getParticleIndex(kik)<<"  ");} DEBUG("\n");

         
// p_part_index example: 0 0 -4 -4
          int tpp=0; 
          bool multiparticleset=false;
          for (int pp=0; pp<getParticleIndex() && tpp<unk_MAX; pp++ ){ //loop over all particle indexes
           int aParticleIndex=getParticleIndex(pp);
           DEBUG("Scan:"<<aParticleIndex<<" ");
// NGU---TODO
           bool idx_used_before=false;
           if (aParticleIndex == 999) multiparticleset=true;
           if (aParticleIndex <0){
             
      //   if (multiparticleset) for (int ipp=0; ipp<= tpp; ipp++) {
      //      if (oldvals[ipp]==aParticleIndex) { DEBUG(" *index seen before* ");
      //       idx_used_before=true;
      //      }
      //   }


           if ( !idx_used_before) {
             pp_target[tpp]=pp;                       // now I know which particle index to replace
             oldvals[tpp] = aParticleIndex;
             DEBUG("Type:"<<p_part_type[pp] << " to be optimized. ");
             search_types[tpp]=p_part_type[pp];
             switch (search_types[tpp]) {
                  case 0: ip_N[tpp]=ao->muos.size(); // 0 is muon
                          break;
                  case 1: ip_N[tpp]=ao->eles.size(); // 1 is electron
                          break;
                  case 2: ip_N[tpp]=ao->jets.size(); // 2 is any jet
                          break;
                  case 3: ip_N[tpp]=tagJets(ao, 1).size(); // 3 is a b jet
                          break;
                  case 4: ip_N[tpp]=tagJets(ao,0).size(); // 4 is light jet
             }
             tpp++;
           } // not used before
           }// for a negative index particle
          }
          DEBUG("\n Optimizing total "<<tpp<< " particle idxes, #old founds:"<< getFoundVector().size()<<"\n");

          if (tpp < 1) {std::cerr << "No particles to optimize! \n"; exit (35);}
          normal_op=false;
          std::vector<int> secondary_idx;
          std::vector<int> secondary_pos;

// loops start ~~~~~~~~~~~
          for (int ip1=0; ip1<=ip_N[0]; ip1++) {
           if (ip1> 0 ) if (ip1==ip_N[0]) continue; // upper limit
           if (isForbidden(ip1, search_types[0])) continue;
           
// sz           ip2_min=ip1+1;
           for (int ip2=ip2_min; ip2<=ip_N[1]; ip2++) {
            if (ip_N[1]>0 && (ip2==ip1)) continue;
            if (ip_N[1]>0 ) {
                   if ( (ip1>ip2) && (oldvals[0] == oldvals[1]) && (search_types[0]==search_types[1]) ) continue;
            }
            if (ip2> 0 ) if (ip2==ip_N[1]) continue; // upper limit
            if (isForbidden(ip2, search_types[1])) continue;
            
            for (int ip3=ip3_min; ip3<=ip_N[2]; ip3++) {
              if (ip_N[2]>0 && (ip3==ip1 || ip3==ip2)) continue;
              if (ip3> 0 ) if (ip3==ip_N[2]) continue; // upper limit
              if (isForbidden(ip3, search_types[2])) continue;
              
// sz              ip4_min=ip1+1;
              for (int ip4=ip4_min; ip4<=ip_N[3]; ip4++) {
                if (ip_N[3]>0 && (ip4==ip1 || ip4==ip2 || ip4==ip3)) continue;
                if (ip4> 0 ) if (ip4==ip_N[3]) continue; // upper limit
                if ((oldvals[3] == (oldvals[0]-10)) && (ip4 < ip1)) continue; // NGU---->
                if (isForbidden(ip4, search_types[3])) continue;
                  
// sz              ip5_min=ip4+1;
               for (int ip5=ip5_min; ip5<=ip_N[4]; ip5++) {
                if (ip_N[4]>0 && (ip5==ip1 || ip5==ip2 || ip5==ip3 || ip5==ip4)) continue;
                if (ip5>0 )  if (ip5==ip_N[4]) continue; // upper limit
                if ((search_types[4] == search_types[3]) && (ip5 < ip4)) continue; // NGU---->
                if (isForbidden(ip5, search_types[4])) continue;

               for (int ip6=ip6_min; ip6<=ip_N[5]; ip6++) {
                 if (ip_N[5]>0 &&(ip6==ip1 || ip6==ip2 || ip6==ip3 || ip6==ip4 || ip6==ip5)) continue;
                 if (ip6> 0 ) if (ip6==ip_N[5]) continue; // upper limit
                 if (isForbidden(ip6, search_types[5])) continue;

                DEBUG(ip1 <<","<<ip2<<","<<ip3<<","<<ip4<<","<<ip5<<","<<ip6<<" \t");
                if (ip_N[0]>0) setParticleIndex( pp_target[0], ip1); // I replaced 1st dummy particle index (which was -)
                if (ip_N[1]>0) setParticleIndex( pp_target[1], ip2); // I replaced 2nd dummy particle index (which was -)
                if (ip_N[2]>0) setParticleIndex( pp_target[2], ip3); // I replaced 3rd dummy particle index (which was -)
                if (ip_N[3]>0) setParticleIndex( pp_target[3], ip4); // I replaced 4th dummy particle index (which was -)
                if (ip_N[4]>0) setParticleIndex( pp_target[4], ip5); // I replaced 5th dummy particle index (which was -)
                if (ip_N[5]>0) setParticleIndex( pp_target[5], ip6); // I replaced 6th dummy particle index (which was -)

// Check here if there are any unfilled - index values              
         int prev_idx=0;
         for (int pp=0; pp<getParticleIndex(); pp++ ) {
           int api=getParticleIndex(pp);
           if (api<0){ //loop over all particle indexes
              DEBUG (api<<"@"<<pp<<"~>");
              for (int ov=0; ov<unk_MAX; ov++){
                  if (oldvals[ov] == api) { // old value is recognized.
                    if (prev_idx == api) { prev_idx=0; continue;} // skip this match take next one
                    DEBUG (getParticleIndex(pp_target[ov])<<"| ");
//set the index here. also save the previous values
                    secondary_idx.push_back(api);
                    secondary_pos.push_back(pp);
                    setParticleIndex( pp, getParticleIndex(pp_target[ov]) ); // same as we looped over. 
                    prev_idx=api;
                    break; // should break the first loop
                  }
              }// loop existing ones
           }// found unused neg.
         }// loop over all particles

         aresult=calc(ao); // calling calc multiple times...
         adelta=fabs(aresult - getLi() );
         DEBUG(" Res: "<< aresult<<" Exp:"<<getLi()<<std::endl);
         if ( getOp()=="~=" ) {  // we use ~= 
            if (adelta < abig) {
                   abig=adelta;
                   setPrecalc(aresult);
                   found_idx[0]=ip1;
                   found_idx[1]=ip2;
                   found_idx[2]=ip3;
                   found_idx[3]=ip4;
                   found_idx[4]=ip5;
                   found_idx[5]=ip6;
            }
         } else {              //or !=
            if (adelta > asmall) {
                   asmall=adelta;
                   setPrecalc(aresult);
                   found_idx[0]=ip1;
                   found_idx[1]=ip2;
                   found_idx[2]=ip3;
                   found_idx[3]=ip4;
                   found_idx[4]=ip5;
                   found_idx[5]=ip6;
            }
         }

// need to clean the secondary indices
                for (size_t as=0; as<secondary_idx.size(); as++){
                   setParticleIndex( secondary_pos[as], secondary_idx[as] ); // same as we looped over. 
                }
                if (secondary_idx.size() > 0) { secondary_pos.clear(); secondary_idx.clear(); } // clear 
               }}}}}} //all iN loops end

          normal_op=true;
// put back the best values
          clearFoundVector();
          clearOrigFoundVector();
          for (int ik=0; ik<getSearchableType(); ik++) {
            if (ip_N[ik]>0) {
                             DEBUG("Best@"<<  pp_target[ik] <<" :"<<found_idx[ik] << ",Oi"<<oldvals[ik]<<" ,Ty:"<<search_types[ik]<<"  ");
                             addFoundIndex(   found_idx[ik] ); // I store
                             addFoundType (search_types[ik] );
                             setParticleIndex(pp_target[ik] , oldvals[ik] ); // I replaced dummy particle index with VALUE
                             addOrigFoundVector(              oldvals[ik] );
            }
          } 
      DEBUG(" best value found:"<< getPrecalc()<< " "<< p_found_types.size()  <<std::endl);
      return 1;
}
/////////////// complex calc ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
float dbxCut::cxcalc(AnalysisObjects *ao, std::vector<int> * param)
{ // should be aware of not using prev results.
            DEBUG("#Parts:"<<getNpart()<<" Param:"<<param->size() <<" ");
            int extraParticleSet=getNpart();
            for (int ii=0; ii<param->size(); ii++){
             if (param->at(ii)>30 ) extraParticleSet=extraParticleSet+1; // special case for R function which has 2 parameters.
            }
            DEBUG("#ExParts:"<< extraParticleSet <<" ");
//@ 2.5s return(rand() % 10000); 
            if (normal_op && (getFoundVector()).size() > 0){
              useFoundResults();
              DEBUG(" #searchables:"<<getSearchableType()<<std::endl);
              if ( (getFoundVector()).size() < getSearchableType() ) find(ao);
              for (int ipart=0; ipart<=extraParticleSet; ipart++) aparticle[ipart]=dbxCut::partConstruct(ao,ipart+1) ;
              clearFoundResults();
            } else {
              DEBUG(" NNO #PT:"<<p_part_type.size()<< "  #PI:"<<p_part_index.size()<<"\n" );
              for (int ipart=0; ipart<=extraParticleSet; ipart++) aparticle[ipart]=partConstruct(ao,ipart+1); //3.4s
//              for (int ipart=0; ipart<=extraParticleSet; ipart++) aparticle[ipart]=myPart; // 2.8s
// pushing a dummy particle costs 1.1s in 25k events (2.6 --> 3.7 s)
            }
//@ 4.5s return(rand() % 10000); 
//************************************************
// 2.5s  -->4.5s --> 6.2
// the cost of above lines is 4.5-2.5 = 2.0s
// the cost of below lines is 6.2-4.5 = 1.7s
//************************************************
            float retval, totretval=0; 
            int iporder=-1;
            for (int ipart=0; ipart<=extraParticleSet; ipart++){
             bool special_op=false;
             bool twoParam=false;

             iporder++;         

             switch (param->at(iporder) ){
              case 1: retval=aparticle[ipart].lv().M();
                      break;
              case 2: retval=aparticle[ipart].lv().Pt();
                      break;
              case 3: retval=aparticle[ipart].lv().Eta();
                      break;
              case 4: retval=aparticle[ipart].lv().Phi();
                      break;
              case 5: retval=aparticle[ipart].q();
                      break;
              case 6: retval=aparticle[ipart].lv().Pz();
                      break;
              case 7: retval=aparticle[ipart].lv().P();
                      break;
              case 8: retval=aparticle[ipart].lv().E();
                      break;
              case 9: retval=aparticle[ipart].q(); // I used Q to carry number of particles in this set.
                      break;
             case 31: retval=aparticle[ipart].lv().DeltaR(aparticle[ipart+1].lv() );
                      twoParam=true;
                      break;
             case 32: retval=aparticle[ipart].lv().DeltaR(aparticle[ipart+1].lv() );
                      twoParam=true;
                      break;
             case 33: retval=fabs(aparticle[ipart].lv().Eta() - aparticle[ipart+1].lv().Eta() );
                      twoParam=true;
                      break;
              default: std::cout<<"No such Parameter "<< param->at(ipart) << " to use! ERROR\n";
                      break;
             }
             DEBUG("\n Xp:"<<ipart<<" ipo:"<<iporder<<" Op:"<<param->at(iporder)<<" RetVal:"<<retval<<" ");
//-----------------------------------ok

             special_op=isSpecial(iporder);

             if (special_op) { retval=doArithOps(retval, iporder,totretval); // ~ totretval+=retval;
                               DEBUG ("Toti:"<<retval);
             }
             if (getArithVals() >0 ) {retval=doArithOps(retval,iporder+1); DEBUG(" aRetVal:"<<retval<<" "); }

             if (ipart==0) { totretval=retval;
             } else {
              if (!special_op) { 
                DEBUG(" T:"<<totretval<<" aRv:"<<retval);
                totretval=doArithOps(retval, (iporder),totretval); // ~ totretval+=retval; 
              } else { totretval=retval; }
             }
             DEBUG ("GTot:"<<totretval);
             if (twoParam) { ipart++; }
            }
             DEBUG ("-> FinalGTot:"<<totretval);
            return (totretval);
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Nof
ClassImp(dbxCutNof)
bool dbxCutNof::select(AnalysisObjects *ao){
              float result;
              result=calc(ao);
              DEBUG("  res:"<< result << "\n");
              return (Ccompare( result ) );
}


float dbxCutNof::calc(AnalysisObjects *ao)
{
            return ( cxcalc(ao, getParams() )); 
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Mof
ClassImp(dbxCutMof)
bool dbxCutMof::select(AnalysisObjects *ao){
              float result;
              if (getOp()=="~=" || getOp()=="~!") {
                   DEBUG(" OPTIMIZING #searchables:"<<getSearchableType()<<std::endl);
                   if ( (getFoundVector()).size() > 0 ){
                        useFoundResults();
                   }
                   if ( !find(ao) ) {std::cerr<<"Find ERROR\n"; exit(213);}
                   clearFoundResults();
                   return (true);
              }
              result=calc(ao);
              DEBUG("  res:"<< result << "\n");
              return (Ccompare( result ) );
}


float dbxCutMof::calc(AnalysisObjects *ao)
{
            return ( cxcalc(ao, getParams() )); 
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Qof
ClassImp(dbxCutQof)
bool dbxCutQof::select(AnalysisObjects *ao){
              float result;
              if (getOp()=="~=" || getOp()=="~!") {
                   DEBUG(" OPTIMIZING #searchables:"<<getSearchableType()<<std::endl);
                   if ( (getFoundVector()).size() > 0 ){
                        useFoundResults();
                   }
                   if ( !find(ao) ) {std::cerr<<"Find ERROR\n"; exit(213);}
                   clearFoundResults();
                   return (true);
              }
              result=calc(ao);
              DEBUG("  res:"<< result << "\n");
              return (Ccompare( result ) );
}

float dbxCutQof::calc(AnalysisObjects *ao)
{
            return ( cxcalc(ao, getParams() )); 
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Ptof
ClassImp(dbxCutPtof)
bool dbxCutPtof::select(AnalysisObjects *ao){
              float result;
              if (getOp()=="~=" || getOp()=="~!") {
                   DEBUG(" OPTIMIZING #searchables:"<<getSearchableType()<<std::endl);
                   if ( (getFoundVector()).size() > 0 ){
                        useFoundResults();
                   }
                   if ( !find(ao) ) {std::cerr<<"Find ERROR\n"; exit(213);}
                   clearFoundResults();
                   return (true);
              }
              if ( getParticleIndex(0) != 6213 ) {
                 result=calc(ao);
                 DEBUG("  res:"<< result << "\n");
                 return (Ccompare( result ) );
              } else {
               DEBUG(getParticleIndex(0)<< "i  t"<< getParticleType(0)<<"\n");
               DEBUG("DEFINING NEW OBJECT: #i:"<< getParticleIndex(-1) <<"  #t:"<<getParticleType(-1) <<"\n");
               int ipart_max;
// 0 is muon
// 1 is electron
// 2 is any jet // 3 is a b jet // 4 is light jet
// 8 is gammas
                switch (getParticleType(0)){
                 case 0: ipart_max=ao->muos.size(); break;
                 case 1: ipart_max=ao->eles.size(); break;
                 case 2: ipart_max=ao->jets.size(); break;
                 case 8: ipart_max=ao->gams.size(); break;
                }

               for (int ipart=ipart_max-1; ipart>=0; ipart--){
                 setParticleIndex(0, ipart);
                 result=calc(ao);
                 bool ppassed=Ccompare(result);
                 DEBUG("\n tested:"<<ipart<< " res:"<< result << " =>"<< ppassed <<"\n");
                 if (!ppassed) {
                   switch (getParticleType(0)){
                     case 0: ao->muos.erase(ao->muos.begin()+ipart); break;
                     case 1: ao->eles.erase(ao->eles.begin()+ipart); break;
                     case 2: ao->jets.erase(ao->jets.begin()+ipart); break;
                     case 8: ao->gams.erase(ao->gams.begin()+ipart); break;
                   }
                 }
               }

               DEBUG("FINAL "<<ao->jets.size()<<" "<<ao->eles.size()<<" \n");

               setParticleIndex(0,6213);
               return true;
              }//end of object selection
              
}

float dbxCutPtof::calc(AnalysisObjects *ao)
{ 
            return ( cxcalc(ao, getParams() )); 
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Pzof
ClassImp(dbxCutPzof)
bool dbxCutPzof::select(AnalysisObjects *ao){
              float result;
              if (getOp()=="~=" || getOp()=="~!") {
                   DEBUG(" OPTIMIZING #searchables:"<<getSearchableType()<<std::endl);
                   if ( (getFoundVector()).size() > 0 ){
                        useFoundResults();
                   }
                   if ( !find(ao) ) {std::cerr<<"Find ERROR\n"; exit(213);}
                   clearFoundResults();
                   return (true);
              }
              result=calc(ao);
              DEBUG("  res:"<< result << "\n");
              return (Ccompare( result ) );
}

float dbxCutPzof::calc(AnalysisObjects *ao)
{ 
            return ( cxcalc(ao, getParams() )); 
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Pof
ClassImp(dbxCutPof)
bool dbxCutPof::select(AnalysisObjects *ao){
              float result;
              if (getOp()=="~=" || getOp()=="~!") {
                   DEBUG(" OPTIMIZING #searchables:"<<getSearchableType()<<std::endl);
                   if ( (getFoundVector()).size() > 0 ){
                        useFoundResults();
                   }
                   if ( !find(ao) ) {std::cerr<<"Find ERROR\n"; exit(213);}
                   clearFoundResults();
                   return (true);
              }
              result=calc(ao);
              DEBUG("  res:"<< result << "\n");
              return (Ccompare( result ) );
}

float dbxCutPof::calc(AnalysisObjects *ao)
{ 
            return ( cxcalc(ao, getParams() ));
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Eof
ClassImp(dbxCutEof)
bool dbxCutEof::select(AnalysisObjects *ao){
              float result;
              if (getOp()=="~=" || getOp()=="~!") {
                   DEBUG(" OPTIMIZING #searchables:"<<getSearchableType()<<std::endl);
                   if ( (getFoundVector()).size() > 0 ){
                        useFoundResults();
                   }
                   if ( !find(ao) ) {std::cerr<<"Find ERROR\n"; exit(213);}
                   clearFoundResults();
                   return (true);
              }
              result=calc(ao);
              DEBUG("  res:"<< result << "\n");
              return (Ccompare( result ) );
}

float dbxCutEof::calc(AnalysisObjects *ao)
{ 
            return ( cxcalc(ao, getParams() )); 
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Etaof
ClassImp(dbxCutEtaof)
bool dbxCutEtaof::select(AnalysisObjects *ao){
              float result;
              if (getOp()=="~=" || getOp()=="~!") {
                   DEBUG(" OPTIMIZING #searchables:"<<getSearchableType()<<std::endl);
                   if ( (getFoundVector()).size() > 0 ){
                        useFoundResults();
                   }
                   if ( !find(ao) ) {std::cerr<<"Find ERROR\n"; exit(213);}
                   clearFoundResults();
                   return (true);
              }
              result=calc(ao);
              DEBUG("  res:"<< result << "\n");
              return (Ccompare( result ) );
}

float dbxCutEtaof::calc(AnalysisObjects *ao)
{ 
            return ( cxcalc(ao, getParams() )); 
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Phiof
ClassImp(dbxCutPhiof)
bool dbxCutPhiof::select(AnalysisObjects *ao){
              float result;
              if (getOp()=="~=" || getOp()=="~!") {
                   DEBUG(" OPTIMIZING #searchables:"<<getSearchableType()<<std::endl);
                   if ( (getFoundVector()).size() > 0 ){
                        useFoundResults();
                   }
                   if ( !find(ao) ) {std::cerr<<"Find ERROR\n"; exit(213);}
                   clearFoundResults();
                   return (true);
              }
              result=calc(ao);
              DEBUG("  res:"<< result << "\n");
              return (Ccompare( result ) );
}

float dbxCutPhiof::calc(AnalysisObjects *ao)
{ 
            return ( cxcalc(ao, getParams() )); 
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~dRof
ClassImp(dbxCutdRof)
bool dbxCutdRof::select(AnalysisObjects *ao){
              float result;
              if (getOp()=="~=" || getOp()=="~!") {
                   DEBUG(" OPTIMIZING #searchables:"<<getSearchableType()<<std::endl);
                   if ( (getFoundVector()).size() > 0 ){
                        useFoundResults();
                   }
                   if ( !find(ao) ) {std::cerr<<"Find ERROR\n"; exit(213);}
                   clearFoundResults();
                   return (true);
              }
              if ( getParticleIndex(0) != 6213 ) {
               result=calc(ao);
               DEBUG(" res:"<< result << "\n");
               return (Ccompare( result ) );
              } else {
               DEBUG(getParticleIndex(0)<<"  "<< getParticleIndex(1)<< "  "<< getParticleIndex(2)   <<"\n");
               DEBUG(" DEFINING NEW OBJECT: #i:"<< getParticleIndex(-1) <<"  #t:"<<getParticleType(-1) <<"\n");
               DEBUG(getParticleType(0)<<"  "<< getParticleType(1)<<"  " << getParticleType(2)  <<"\n");
               int ipart_max[2]; 
// 0 is muon
// 1 is electron
// 2 is any jet // 3 is a b jet // 4 is light jet
// 8 is gammas
               for (int jj=0; jj<2; jj++)
                switch (getParticleType(jj*2)){
                 case 0: ipart_max[jj]=ao->muos.size(); break;
                 case 1: ipart_max[jj]=ao->eles.size(); break;
                 case 2: ipart_max[jj]=ao->jets.size(); break;
                 case 8: ipart_max[jj]=ao->gams.size(); break;
                }
               DEBUG(ipart_max[0]<<" "<<ipart_max[1]<<" \n");

               for (int ipart=ipart_max[0]-1; ipart>=0; ipart--)
                for (int jpart=0; jpart<ipart_max[1]; jpart++) {
                 setParticleIndex(0, ipart);
                 setParticleIndex(2, jpart);
                 result=calc(ao);
                 bool ppassed=Ccompare(result);
                 DEBUG("\n tested:"<<ipart<< ","<< jpart<< " res:"<< result << " =>"<< ppassed <<"\n");
                 if (!ppassed) {
                   switch (getParticleType(0)){
                     case 0: ao->muos.erase(ao->muos.begin()+ipart); break;
                     case 1: ao->eles.erase(ao->eles.begin()+ipart); break;
                     case 2: ao->jets.erase(ao->jets.begin()+ipart); break;
                     case 8: ao->gams.erase(ao->gams.begin()+ipart); break;
                   }
                   break;
                 }
               }

               DEBUG("FINAL "<<ao->jets.size()<<" "<<ao->eles.size()<<" \n");

               setParticleIndex(0,6213);
               setParticleIndex(2,6213);
               return true;
              }//end of object selection
}//end of dRof

float dbxCutdRof::calc(AnalysisObjects *ao)
{ 
            return ( cxcalc(ao, getParams() )); 
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~dPhiof
ClassImp(dbxCutdPhiof)
bool dbxCutdPhiof::select(AnalysisObjects *ao){
              float result;
              if (getOp()=="~=" || getOp()=="~!") {
                   DEBUG(" OPTIMIZING #searchables:"<<getSearchableType()<<std::endl);
                   if ( (getFoundVector()).size() > 0 ){
                        useFoundResults();
                   }
                   if ( !find(ao) ) {std::cerr<<"Find ERROR\n"; exit(213);}
                   clearFoundResults();
                   return (true);
              }
              result=calc(ao);
              DEBUG(" res:"<< result << "\n");
// put back the originals
              return (Ccompare( result ) );
}

float dbxCutdPhiof::calc(AnalysisObjects *ao)
{ 
            return ( cxcalc(ao, getParams() )); 
}

//-------------------------------------------------------dbxCutList
//-------------------------------------------------------dbxCutList
ClassImp(dbxCutList)
     std::vector<std::string> dbxCutList::cutTokenizer(std::string s, std::vector<dbxCut*> *mycut) {
        std::vector<std::string> qret;
        std::string delimiter = " ";
        std::string subdelimiter = "_"; //0&+number index, -number search, nonumber: ALL 
        std::string token0, token1, token2;
        size_t pos = 0;
        size_t apos = 0;
        bool foundcut=false;
        unsigned int cutid;
        float previous_v=0;
        bool found_first_v=false;
        bool need_one_arg=true;
        std::vector<int> my_typelist;
        std::vector<int> my_indexlist;
        std::string myEvalString;

//        std::cout << s << std::endl;
        while ((pos = s.find(delimiter)) < std::string::npos) {
//remove extra white spaces
            if (pos==0) {
                        s.erase(0, pos + delimiter.length());
                        continue;
            }
            token0 = s.substr(0, pos);
            if (token0.length()==0) break; // the last junk

//          std::cout<<" "<<pos << "\t T:"<<token0 << " " <<token0.length() <<std::endl;
// token is the space separated string
// if it doesn't have any paranthesis, just evaluate
            if ( (token0.find('(') == std::string::npos)
              && (token0.find(')') == std::string::npos)
              && (token0.find('{') == std::string::npos)
               ){ // alone token, else would be with parantheses.
//              std::cout << "Have:"<<token0 << "  Found?:"<< foundcut<<std::endl;
                if (token0=="AND" || token0=="&&") {qret.push_back("*"); }
                else if (token0=="OR" || token0=="||")  {qret.push_back("+"); }
                else if (token0=="," )  { DEBUG("Adding new particle set. "); 
                                          my_typelist.push_back(-1); my_indexlist.push_back(999); // for R function 
                                        } // comma  means I have 2 particles, distinguished by -1
                else if ((apos=token0.find(subdelimiter)) != std::string::npos )  {
                         std::string subtoken0, subtoken1;
                         subtoken0 = token0.substr(0, apos); //
                         subtoken1 = token0.substr(apos+subdelimiter.length(),std::string::npos); // 0&+number index, -number search, nonumber: ALL
//                       std::cout <<"found PList0:"<<subtoken0<<" and PList1:"<<subtoken1.length()<< ".  idxlist:"<<my_indexlist.size()<<std::endl;
// -------------depending on subtoken0, fill the particle type.
                         if        (subtoken0=="LEP"){
                                               DEBUG(" Lepton at:"<< std::stoi(subtoken1) << "\t");
                                               if (TrigType<4) { my_typelist.push_back(0);       // muon is 0
                                               } else { my_typelist.push_back(1);                // electron is 1
                                               }
                         } else if (subtoken0.find("ELE") != std::string::npos ){
                                               DEBUG(" ELE at:"<< subtoken1 << "\t");
                                               my_typelist.push_back(1);                        // explicit ele is 1
                         } else if (subtoken0.find("MUO") != std::string::npos ){
                                               DEBUG(" MUO at:"<< subtoken1 << "\t");
                                               my_typelist.push_back(0);                        // explicit muo is 0
                         } else if (subtoken0.find("BJET") != std::string::npos){
                                               DEBUG(" BJET at:"<< subtoken1 << "\t");
                                               my_typelist.push_back(3);                        // bjet is 3
                         } else if (subtoken0.find("QGJET") != std::string::npos){
                                               DEBUG(" QGJET at:"<< subtoken1 << "\t");
                                               my_typelist.push_back(4);                        // qgjet is 4
                         } else if (subtoken0.find("JET") != std::string::npos ){   //----------------------this should be AFTER BJET and QGJET
                                               DEBUG(" JET at:"<< subtoken1 << "\t");
                                               my_typelist.push_back(2);                        // jet is 2
                         } else if (subtoken0=="NUMET"){
                                               if (TrigType<4) { my_typelist.push_back(5);       // MET4V muon is 5
                                               } else {my_typelist.push_back(6);}                // MET4V electron is 6
                         } else if (subtoken0=="METLV"){
                                               DEBUG(" METLV at:"<< std::stoi(subtoken1) << "\t");
                                               my_typelist.push_back(7);                        // MET psedovector is 7
                         } else if (subtoken0.find("PHO") != std::string::npos ){               //found = str.find(str2);
                                               DEBUG(" PHO at:"<< subtoken1 << "\t");
                                               my_typelist.push_back(8);                        // photon is 8
                         } else {
                           std::cout <<subtoken0<<" is a UFO particle! STOP!!\n"; exit (2);
                         }
                         if (subtoken1.length() == 0) { DEBUG("all ");  my_indexlist.push_back(6213);} //magic number
                           else my_indexlist.push_back(std::atoi(subtoken1.data() ));
                     }
                else {
                if (!foundcut) {
// search the cut in the list
                   for ( unsigned int i=0; i<cutlist.size(); i++) {
                     if (token0.find(cutlist[i]->getName()) != std::string::npos){ // WHY needed??????????
                        DEBUG(token0<<" is valid.\t");
                        foundcut=true;
                        cutid=i;
                        qret.push_back("x");
                        myEvalString+="x";   
                         if    (token0.find("nELE")  != std::string::npos )    {mycut->push_back(new dbxCutNEle()           );}
                        else if(token0.find("nMUO")  != std::string::npos )    {mycut->push_back(new dbxCutNMu()            );}
                        else if(token0.find("nPHO")  != std::string::npos )    {mycut->push_back(new dbxCutNPho()           );}
                        else if(token0.find("nJET")  != std::string::npos )    {mycut->push_back(new dbxCutNJet()           );}
                        else if(token0.find("nBJET") != std::string::npos )    {mycut->push_back(new dbxCutnBJet()          );}
                        else if(token0.find("nQGJET")!= std::string::npos )    {mycut->push_back(new dbxCutnQGJet()         );}
                        else if(token0=="nLEP")      {mycut->push_back(new dbxCutNLEP(TrigType)   );}
                        else if(token0=="qLEP.qLEP") {mycut->push_back(new dbxCutQQLEP(TrigType)  );}
                        else if(token0=="m2LEP")     {mycut->push_back(new dbxCutm2LEP(TrigType)  );}
                        else if(token0=="pt2LEP")    {mycut->push_back(new dbxCutpt2LEP(TrigType) );}
                        else if(token0=="ALL")       {mycut->push_back(new dbxCutALL()            );}
                        else if(token0=="FillHistos"){mycut->push_back(new dbxCutFillHistos()     );}
                        else if(token0=="Trig")      {mycut->push_back(new dbxCutTrig(TrigType)   );}
                        else if(token0=="VtxTrks")   {mycut->push_back(new dbxCutVtxTrks()        );}
                        else if(token0=="LEPsf")     {mycut->push_back(new dbxCutLEPsf()          );}
                        else if(token0=="MET")       {mycut->push_back(new dbxCutMET()            );}
                        else if(token0=="MWT")       {mycut->push_back(new dbxCutMWT(TrigType)    );}
                        else if(token0=="R2LEPJ0")   {mycut->push_back(new dbxCutR_Z_J0(TrigType) );}
                        else if(token0=="METMWT")    {mycut->push_back(new dbxCutMETMWT(TrigType) );}
                        else if(token0=="SumHTJET")  {mycut->push_back(new dbxCutSumHTJET()       );} // remove sum, add HTALL
                        else if(token0=="TrigMatch") {mycut->push_back(new dbxCutTrigMatch(TrigType) );}
                        else if(token0=="}m")        {mycut->push_back(new dbxCutMof(my_typelist,   my_indexlist,1) ); my_typelist.clear(); my_indexlist.clear();}
                        else if(token0=="}Pt")       {mycut->push_back(new dbxCutPtof(my_typelist,  my_indexlist,2) ); my_typelist.clear(); my_indexlist.clear();}
                        else if(token0=="}Eta")      {mycut->push_back(new dbxCutEtaof(my_typelist, my_indexlist,3) ); my_typelist.clear(); my_indexlist.clear();}
                        else if(token0=="}Phi")      {mycut->push_back(new dbxCutPhiof(my_typelist, my_indexlist,4) ); my_typelist.clear(); my_indexlist.clear();}
                        else if(token0=="}q")        {mycut->push_back(new dbxCutQof(my_typelist,   my_indexlist,5) ); my_typelist.clear(); my_indexlist.clear();}
                        else if(token0=="}Pz")       {mycut->push_back(new dbxCutPzof(my_typelist,  my_indexlist,6) ); my_typelist.clear(); my_indexlist.clear();}
                        else if(token0=="}P")        {mycut->push_back(new dbxCutPof(my_typelist,   my_indexlist,7) ); my_typelist.clear(); my_indexlist.clear();}
                        else if(token0=="}E")        {mycut->push_back(new dbxCutEof(my_typelist,   my_indexlist,8) ); my_typelist.clear(); my_indexlist.clear();}
                        else if(token0=="}N")        {mycut->push_back(new dbxCutNof(my_typelist,   my_indexlist,9) ); my_typelist.clear(); my_indexlist.clear();}
                        else if(token0=="}dR")       {mycut->push_back(new dbxCutdRof(my_typelist,  my_indexlist,31)); my_typelist.clear(); my_indexlist.clear();}
                        else if(token0=="}dPhi")     {mycut->push_back(new dbxCutdPhiof(my_typelist,my_indexlist,32)); my_typelist.clear(); my_indexlist.clear();}
                        else {std::cout << "This Cut IS NOT defined. MAJOR ERROR. STOP!\n"; exit(32);}
                        i=cutlist.size();
                     }
                   }
//if we didn't find a match by now, this cut is f*cked up.
                   if (!foundcut) { std::cout << token0<< " is a UFO!\n"; exit (1);}
                } else { // foundcut
                 if (atoi(token0.c_str())!=0 || isdigit(token0.c_str()[0]) ){ //this is the digit
                    myEvalString+=token0;
                    DEBUG(token0 << " is a value ");
                    if ( (mycut->back()->getOp()=="")) {
                     DEBUG("for arithmetic Ops  ");
                     mycut->back()->addArithVal(atof(token0.data()));
                     
                    } else { // limit value(s)
                             if (need_one_arg) {
                               mycut->back()->setLi(atof(token0.data()));
                               foundcut=false; //reset the search
                               DEBUG("Limit set.\n");
                             } else {
                               if (!found_first_v) {
                                  previous_v=atof(token0.data() ); // one more is expected.
                                  found_first_v=true;
                               } else {
                                  mycut->back()->setRa(previous_v, atof(token0.data()));
                                  foundcut=false; //reset the search
                                  found_first_v=false;
                                  DEBUG("Range set.\n");
                               }
                             } //end of two args
                    }
                 } else {        //this must be the cut operator OR artihmetic operator
                     if (  token0=="}m" || token0=="}dR" || token0=="}Pt" || token0=="}Phi" || token0=="}q"    || token0=="}N"
                        || token0=="}E" || token0=="}Pz" || token0=="}P"  || token0=="}Eta" || token0=="}dPhi"
                        ) { DEBUG("Another Op found:"<<token0<<"\n");
                                 if(token0=="}m")   {mycut->back()->addParam(1) ; }
                            else if(token0=="}Pt")  {mycut->back()->addParam(2) ; }
                            else if(token0=="}Eta") {mycut->back()->addParam(3) ; }
                            else if(token0=="}Phi") {mycut->back()->addParam(4) ; }
                            else if(token0=="}q")   {mycut->back()->addParam(5) ; }
                            else if(token0=="}Pz")  {mycut->back()->addParam(6) ; }
                            else if(token0=="}P")   {mycut->back()->addParam(7) ; }
                            else if(token0=="}E")   {mycut->back()->addParam(8) ; }
                            else if(token0=="}N")   {mycut->back()->addParam(9) ; }
                            else if(token0=="}dR")  {mycut->back()->addParam(31); }
                            else if(token0=="}dPhi"){mycut->back()->addParam(32); }
                   
                            myEvalString+="x";

                            mycut->back()->addTypesIndexes(my_typelist,my_indexlist); 
                            my_typelist.clear(); my_indexlist.clear();
                       
                     } else if ( token0=="+" || token0=="-" || token0=="/" || token0=="*" || token0=="^" ) {        //is it a math operation like + - ...
                          myEvalString+=token0;  
                          DEBUG(token0 <<" is an arithmetic Op ");
                          mycut->back()->addArithOp(*token0.c_str() );
                     } else { //is this is cut operator like < > ==
                             myEvalString+=".";
                             if (token0.find_first_of("=<>![") !=std::string::npos ) {  //is it an op?  
                                 if ((token0.find('[') != std::string::npos) && (token0.find(']') != std::string::npos )) {
                                     DEBUG(token0<< " is an OP with two arguments.\n");
                                     mycut->back()->setOp(token0);
                                     need_one_arg=false;
                                 } else {
                                     DEBUG(token0<< " is an OP with one argument.\n");
                                     need_one_arg=true;
                                     mycut->back()->setOp(token0);
                                 }
                             }//is it an op?
                     }//end of checking arithmetic or cut operator
                 }
                }//else foundcut close
               }
            } else { // about paranthesis
// handling the paranthesis
              size_t found0 = token0.find_last_of('(');
              size_t found1 = token0.find_first_of(')');
              size_t found4 = token0.find_last_of('{');
              size_t found5 = token0.find_first_of('}');
              if (found4!=std::string::npos) { //found a curly 
               DEBUG(":NP:");
               if (mycut->size() >0) if (mycut->back()->getOp() == "") {
                  DEBUG(" Reset4ExtraParts:"<<mycut->back()->getOp()<<" ");
                  mycut->back()->addApart();
//                  foundcut=false; //reset the search
                  my_typelist.push_back(-1); my_indexlist.push_back(999);
                  mycut->back()->addArithVal(0.0); // zero is special in this case.
               }
              }
              if (found0!=std::string::npos) { //found at the beginning of a keyword
                      myEvalString+="(";
                      token1 = token0.substr(0, found0+1);
                      qret.push_back(token1);
                      token2 = token0.substr(found0+1, std::string::npos );
                      for (unsigned int i=0; i<cutlist.size(); i++)
                      {
                        if (cutlist[i]->getName()==token2){ DEBUG("found ( cut:\n");
                                                            foundcut=true;
                                                            qret.push_back("x");
                                                          }
                      }
                      DEBUG("  l:"<<found0<<"  b:"<<token1<<  "   e:"<<token2<<std::endl);
               }
               if (found1!=std::string::npos) { //found at the end of a keyword
                      myEvalString+=")";
                      token1 = token0.substr(0, found1);
                      token2 = token0.substr(found1, std::string::npos );
                      qret.push_back(token2);
                      DEBUG("  f:"<<found1<<"  b:"<<token1<< "   e:"<<token2<<std::endl);
               }

            }
            s.erase(0, pos + delimiter.length());
            if (pos == std::string::npos) break;
        }


        std::vector<std::string> qret_reduced;
        bool use_reduced=true;
        DEBUG ("~~~>qret: ");
        for (size_t qq=0; qq<qret.size(); qq++) {
          DEBUG(qret[qq]);
          if ( qret[qq] != "+" && qret[qq] != "*" && qret[qq] != "(" && qret[qq] != ")" ) qret_reduced.push_back(qret[qq] );
          if ( qret[qq] == "+" || qret[qq] == "*" ) use_reduced=false; 
        } 

        DEBUG("\n"<<myEvalString<<"\n");
        if (use_reduced) {
         DEBUG (" ~>qret reduced: ");
         for (size_t qq=0; qq<qret_reduced.size(); qq++) DEBUG(qret_reduced[qq]);
         DEBUG("\n\n");
         return qret_reduced;
        } else {  DEBUG("\n"); }

        return qret;
    }
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ListClass constructor
dbxCutList::dbxCutList(){
                    TrigType=0; // no trigger
                    cutlist.push_back(new dbxCutALL());
                    cutlist.push_back(new dbxCutFillHistos());
                    cutlist.push_back(new dbxCutNEle());
                    cutlist.push_back(new dbxCutNMu());
                    cutlist.push_back(new dbxCutNJet());
                    cutlist.push_back(new dbxCutNPho());
                    cutlist.push_back(new dbxCutNLEP());
                    cutlist.push_back(new dbxCutQQLEP());
                    cutlist.push_back(new dbxCutm2LEP());
                    cutlist.push_back(new dbxCutpt2LEP());
                    cutlist.push_back(new dbxCutTrig());
                    cutlist.push_back(new dbxCutVtxTrks());
                    cutlist.push_back(new dbxCutTrigMatch());
                    cutlist.push_back(new dbxCutLEPsf());
                    cutlist.push_back(new dbxCutR_Z_J0());
                    cutlist.push_back(new dbxCutMET());
                    cutlist.push_back(new dbxCutMWT());
                    cutlist.push_back(new dbxCutMETMWT());
                    cutlist.push_back(new dbxCutnBJet());
                    cutlist.push_back(new dbxCutnQGJet());
                    cutlist.push_back(new dbxCutSumHTJET());
                    cutlist.push_back(new dbxCutQof());
                    cutlist.push_back(new dbxCutPtof());
                    cutlist.push_back(new dbxCutEtaof());
                    cutlist.push_back(new dbxCutPhiof());
                    cutlist.push_back(new dbxCutNof());
                    cutlist.push_back(new dbxCutMof());
                    cutlist.push_back(new dbxCutEof());
                    cutlist.push_back(new dbxCutPof());
                    cutlist.push_back(new dbxCutPzof());
                    cutlist.push_back(new dbxCutdRof());
                    cutlist.push_back(new dbxCutdPhiof());
                    cutlist.push_back(new dbxCutEx1of());
        }


#endif
