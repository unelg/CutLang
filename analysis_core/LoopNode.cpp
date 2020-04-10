//
//  LoopNode.cpp
//
//

#ifndef LoopNode_cpp
#define LoopNode_cpp
#include "LoopNode.h"
#include "FuncNode.h"
#include "LFuncNode.h"
#include <TF1.h>

//#define _CLV_
#ifdef _CLV_
#define DEBUG(a) std::cout<<a
#else
#define DEBUG(a)
#endif

double LoopNode::evaluate(AnalysisObjects* ao) {
      // here we need to loop over all functions
       std::vector <double> result_list;
       double retval;
       std::string bcol2;
       int ipart2_max;

       DEBUG("\nWe are in LoopNode, "<<this->getStr()<<"\n");
       DEBUG("Left size:"<<lefs.size()<<"\n");
      for (int in=0; in<lefs.size(); in++){ // loop over all possible left branches.
       left=lefs[in];
       this->getParticles(&inputParticles);       
 
       bool oneParticleAtATime=false;
       for (int ii=0; ii<inputParticles.size(); ii++){
        DEBUG("Loop particle ID:"<<ii<<" Type:"<<inputParticles[ii]->type<<" collection:"
                     << inputParticles[ii]->collection << " index:"<<inputParticles[ii]->index<<"\n");
        if (inputParticles[ii]->index > 9999) oneParticleAtATime=true; 
       }
       ipart2_max=0; // loop counter
       bool constiloop=false;
       std::string consname;
       if (inputParticles.size()==1) // here we loop over all particles in the collection
       {
        DEBUG("Looping one by one\n");
        bcol2=inputParticles[0]->collection;
        consname=bcol2;
        int base_type2=inputParticles[0]->type;
        try {
                switch(inputParticles[0]->type){
                case muon_t: ipart2_max=(ao->muos).at(bcol2).size(); break;
               case truth_t: ipart2_max=(ao->truth).at(bcol2).size(); break;
            case electron_t: ipart2_max=(ao->eles).at(bcol2).size(); break;
                 case jet_t: ipart2_max=(ao->jets).at(bcol2).size(); break;
               case pureV_t: ipart2_max=1; break;
              case photon_t: ipart2_max=(ao->gams).at(bcol2).size(); break;
                case fjet_t: ipart2_max=(ao->ljets).at(bcol2).size(); break;
                 case tau_t: ipart2_max=(ao->taus).at(bcol2).size(); break;
               case combo_t: ipart2_max=(ao->combos)[bcol2].size(); break;
              case consti_t: {constiloop=true;
                            TString konsname=bcol2;
                                   konsname+="_";
                                   konsname+=inputParticles[0]->index;
                                   konsname+="c";
                                   consname=(std::string)konsname;
                                   ipart2_max =(ao->constits).find(consname)->second.size();
                                   DEBUG(consname<<" has "<<ipart2_max<<" constituents\n");
                                   base_type2=consti_t;
                            break;}


                   default:
                       std::cerr << "WRONG PARTICLE TYPE:"<<inputParticles[0]->type << std::endl; break;
                }
        } catch(...) {
                            std::cerr << "YOU WANT TO LOOP A PARTICLE TYPE YOU DIDN'T CREATE:"<<bcol2 <<" !\n";
                            _Exit(-1);
        }
       // now we know how many we want
       DEBUG ("loop over "<< ipart2_max<<" particles\t");
       FuncNode *pippo;
       for (int ii=0;ii<ipart2_max; ii++){
        DEBUG("now for particle "<<ii<<"\n");
        DEBUG("0 will do: "<<left->getStr()<<"\n");
        if (pippo=dynamic_cast< FuncNode*>(left) ) {
         DEBUG("downcast OK\n");
        } else {
         DEBUG("downcast FAILS\n");
          if (pippo=dynamic_cast< FuncNode*>(left->left) ) {
            DEBUG("down-downcast OK\n");
          }
        }
        
        pippo->setParticleIndex(0, ii);
        DEBUG("I will do: "<<left->getStr()<<"\t");
        DEBUG("over: "<<right<<"\n");
        if (inputParticles[0]->index != 6213){
         pippo->setParticleType(0, base_type2);
         pippo->setParticleCollection(0, consname);
        }
        retval=left->evaluate(ao);
        DEBUG("Loop retval:"<<retval<<"\n");
        result_list.push_back(retval); 
       }
        pippo->setParticleIndex(0, 6213);
       } else if(oneParticleAtATime){   // here we give an explicit list, like 1,3,4,6..
        for (int ii=0;ii<inputParticles.size(); ii++){
           int anindex=inputParticles[ii]->index;
           if (anindex > 9999) { // Indices around 10000 are to be looped over
            ((LFuncNode*)left)->setParticleIndex(ii, anindex-10000 );
            retval=left->evaluate(ao);
            DEBUG("retval:"<<retval<<"\n");
            result_list.push_back(retval); 
            ((LFuncNode*)left)->setParticleIndex(ii, anindex );
           }
        }// endof over loop over particles
       } else {
//--------- here we will simply evaluate the left node and push the result
         retval=left->evaluate(ao);
         DEBUG("retval:"<<retval<<"\n");
         result_list.push_back(retval); 
       }
     }// end of loop over multiple lefts

       if (g==NULL) { return (*f)(result_list);} 
       else {
        std::vector<bool> retvals=(*g)(result_list);
        if (inputParticles.size()==1) { // here we loop over all particles in the collection
        if (retvals.size() != ipart2_max) {std::cerr <<"HitMiss LoopObj has a problem\n"; exit(12);}
        for (int ii=ipart2_max-1; ii>=0; ii--){
         if (!retvals[ii]) { // we will kill this guy
          DEBUG("Killing "<<ii<<" of "<<bcol2<<"\n");
          switch(inputParticles[0]->type){
                case muon_t:  ( ao->muos)[bcol2].erase((ao->muos  ).find(bcol2)->second.begin()+ii); break;
               case truth_t:  (ao->truth)[bcol2].erase((ao->truth ).find(bcol2)->second.begin()+ii); break;
            case electron_t:  ( ao->eles)[bcol2].erase((ao->eles  ).find(bcol2)->second.begin()+ii); break;
                 case jet_t:  ( ao->jets)[bcol2].erase((ao->jets  ).find(bcol2)->second.begin()+ii); break;
              case photon_t:  ( ao->gams)[bcol2].erase((ao->gams  ).find(bcol2)->second.begin()+ii); break;
                case fjet_t:  (ao->ljets)[bcol2].erase((ao->ljets ).find(bcol2)->second.begin()+ii); break;
                 case tau_t:  ( ao->taus)[bcol2].erase((ao->taus  ).find(bcol2)->second.begin()+ii); break;
               case combo_t: (ao->combos)[bcol2].erase((ao->combos).find(bcol2)->second.begin()+ii); break;
               case pureV_t: break;
          }//loop over switch 
         }// loop over kill 
        } // loop over particles and results
        } // loop over all particles or not
       return 1;
       }
}


double sumof(std::vector<double> xlist){
 double retval=0;
 for (unsigned int ii=0; ii<xlist.size(); ii++) retval+=xlist[ii];
 DEBUG("Sum:"<<retval<<"\n");
 return retval;
}

double minof(std::vector<double> xlist){
 double retval=999999999999.9;
 for (unsigned int ii=0; ii<xlist.size(); ii++) {
  if (xlist[ii]< retval) retval=xlist[ii];
 }
 DEBUG("min:"<<retval<<"\n");
 return retval;
}

double maxof(std::vector<double> xlist){
 double retval=-999999999999.9;
 for (unsigned int ii=0; ii<xlist.size(); ii++) {
  if (xlist[ii]> retval) retval=xlist[ii];
 }
 DEBUG("max:"<<retval<<"\n");
 return retval;
}
 
std::vector<bool> hitmissA(std::vector<double> xlist){
// random number setup is here
 std::vector<bool> retvals;
 TF1 *fRandom ;
 fRandom=new TF1("fRandom","x",0,1);

 for (unsigned int ii=0; ii<xlist.size(); ii++) {
 double r = fRandom->GetRandom();
 DEBUG("hit/miss to Accept:"<<xlist[ii]<< " vs " << r << "\t");
 if (xlist[ii]< r ) { retvals.push_back(false); DEBUG("Missed.\n");} 
 else { retvals.push_back(true); DEBUG("Hit.\n"); }
 }
 return retvals;
}

std::vector<bool> hitmissR(std::vector<double> xlist){
// random number setup is here
 std::vector<bool> retvals;
 TF1 *fRandom ;
 fRandom=new TF1("fRandom","x",0,1);

 for (unsigned int ii=0; ii<xlist.size(); ii++) {
 double r = fRandom->GetRandom();
 DEBUG("hit/miss to Reject:"<<xlist[ii]<< " vs " << r << "\t");
 if (xlist[ii]> r ) { retvals.push_back(false); DEBUG("Missed.\n");} 
 else { retvals.push_back(true); DEBUG("Hit.\n"); }
 }
 return retvals;
}

   
#endif /* LoopNode_cpp */
