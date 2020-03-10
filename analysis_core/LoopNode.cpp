//
//  LoopNode.cpp
//
//

#ifndef LoopNode_cpp
#define LoopNode_cpp
#include "LoopNode.h"
#include "FuncNode.h"
#include "LFuncNode.h"

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
       DEBUG("\nWe are in LoopNode, "<<this->getStr()<<"\n");

      for (int in=0; in<lefs.size(); in++){ // loop over all possible left branches.
       left=lefs[in];

       this->getParticles(&inputParticles);       
 
       bool oneParticleAtATime=false;
       for (int ii=0; ii<inputParticles.size(); ii++){
        DEBUG("Loop particle ID:"<<ii<<" Type:"<<inputParticles[ii]->type<<" collection:"
                     << inputParticles[ii]->collection << " index:"<<inputParticles[ii]->index<<"\n");
        if (inputParticles[ii]->index > 9999) oneParticleAtATime=true; 
       }
       int ipart2_max=0; // loop counter
       bool constiloop=false;
//       if (inputParticles[0]->index == 6213 && inputParticles.size()==1) 
       if (inputParticles.size()==1) 
       {
        std::string base_collection2=inputParticles[0]->collection;
        std::string consname;
        int base_type2=inputParticles[0]->type;
        try {
                switch(inputParticles[0]->type){
                case muon_t: ipart2_max=(ao->muos).at(base_collection2).size(); break;
               case truth_t: ipart2_max=(ao->truth).at(base_collection2).size(); break;
            case electron_t: ipart2_max=(ao->eles).at(base_collection2).size(); break;
                 case jet_t: ipart2_max=(ao->jets).at(base_collection2).size(); break;
               case pureV_t: ipart2_max=1; break;
              case photon_t: ipart2_max=(ao->gams).at(base_collection2).size(); break;
                case fjet_t: ipart2_max=(ao->ljets).at(base_collection2).size(); break;
                 case tau_t: ipart2_max=(ao->taus).at(base_collection2).size(); break;
               case combo_t: ipart2_max=(ao->combos)[base_collection2].size(); break;
              case consti_t: {constiloop=true;
                            TString konsname=base_collection2;
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
                            std::cerr << "YOU WANT TO LOOP A PARTICLE TYPE YOU DIDN'T CREATE:"<<base_collection2 <<" !\n";
                            _Exit(-1);
        }
       // now we know how many we want
       DEBUG ("loop over "<< ipart2_max<<" particles\t");
       for (int ii=0;ii<ipart2_max; ii++){
        ((FuncNode*)left)->setParticleIndex(0, ii);
        if (inputParticles[0]->index != 6213){
          ((FuncNode*)left)->setParticleType(0, base_type2);
          ((FuncNode*)left)->setParticleCollection(0, consname);
        }
        retval=left->evaluate(ao);
        DEBUG("retval:"<<retval<<"\n");
        result_list.push_back(retval); 
       }
       ((FuncNode*)left)->setParticleIndex(0, 6213);
       } else if(oneParticleAtATime){
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

       return (*f)(result_list);
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
    
#endif /* LoopNode_cpp */
