//
//  TableNode.cpp
//  takes care of Table Operations
//
//  Created by ngu  on Oct19.
//  Copyright © 2019 . All rights reserved.
//

#ifndef TableNode_cpp
#define TableNode_cpp

#include <stdio.h>
#include <math.h>
#include "TableNode.h"
#include "FuncNode.h"
#include <TF1.h>
//#define _CLV_
#ifdef _CLV_
#define DEBUG(a) std::cout<<a
#else
#define DEBUG(a)
#endif


//---------EVALUATE---------
double TableNode::evaluate(AnalysisObjects* ao) {
            DEBUG("Table Node\n");
            double aval=left->evaluate(ao);
            double bval, cval, dval, tval; 
            bool range_found=false;
            int it;

            if (left2==NULL){ // 1D
              DEBUG("aval:"<<aval<<"\t");
              for (it=0; it<atable.size(); it+=3){ // 3 is for 1D only. value, min, max.
               if ( aval>=atable[it+1] && aval<=atable[it+2]){
                range_found=true;
                tval=atable[it];
                DEBUG(" tval:"<<tval<<"\n");
                it=(it/3);
                break;
               } 
              }
            if (!range_found) {std::cerr << "Specified 1st value "<< aval <<" is out of table range! Setting coeff to ZERO.\n"; 
                               tval=0;}
            }else{ //2D
                if (left3==NULL) {
                DEBUG("\nTABLE evaluating second function\n");
                std::vector<myParticle*> inputParts1;
                std::vector<myParticle*> inputParts2;
                 left->getParticles(&inputParts1);
                left2->getParticles(&inputParts2);
                DEBUG("1 Size:"<<inputParts1.size()<<" 0th:"<<inputParts1[0]->index<<"\n");
                DEBUG("2 Size:"<<inputParts2.size()<<" 0th:"<<inputParts2[0]->index<<"\n");
                FuncNode *pippo;
                if ( inputParts2.size()>0 && inputParts2[0]->index == 6213) {
                    if ((pippo=dynamic_cast< FuncNode*>(left2)) ) {
                      DEBUG("TABLE 2nd func downcast OK\n");
                      pippo->setParticleIndex(0,   inputParts1[0]->index);
                      pippo->setParticleCollection(0, inputParts1[0]->collection);
                      DEBUG("TABLE 2nd func param set OK\n");
                     } else {
                     std::cerr<<"TABLE 2nd function parmeters can not be set. ERROR\n"; exit (15);
                     }
                     bval=left2->evaluate(ao);
                     pippo->setParticleIndex(0,   6213);
                } else bval=left2->evaluate(ao);
                      
                DEBUG("\naval:"<<aval<< " bval:"<<bval<<"\t");
                for (it=0; it<atable.size(); it+=5){ // 5 is for 2D only. value, min, max, min2, max2.
                  if (aval>=atable[it+1] && aval<=atable[it+2] && bval>=atable[it+3] && bval<=atable[it+4]){
                   range_found=true;
                   tval=atable[it];
                   DEBUG(" tval:"<<tval<<"\n");
                   it=(it/5);
                   break;
                  } 
                 }
                
               if (!range_found) {std::cerr << "Specified 1st:"<< aval << " or 2nd:"<< bval
                                            <<" value is out of table range! Setting coeff to ZERO.\n";
                                  tval=0;}
            } // 2D ends
            else { // 4D
                    DEBUG("\nTABLE evaluating second function\n");
                  std::vector<myParticle*> inputParts1;
                  std::vector<myParticle*> inputParts2;
                  std::vector<myParticle*> inputParts3;
                  std::vector<myParticle*> inputParts4;
                   left->getParticles(&inputParts1);
                  left2->getParticles(&inputParts2);
                  left3->getParticles(&inputParts3);
                  left4->getParticles(&inputParts4);
                  DEBUG("1 Size:"<<inputParts1.size()<<" 0th:"<<inputParts1[0]->index<<"\n");
                  DEBUG("2 Size:"<<inputParts2.size()<<" 0th:"<<inputParts2[0]->index<<"\n");
                  DEBUG("3 Size:"<<inputParts3.size()<<" 0th:"<<inputParts3[0]->index<<"\n");
                  DEBUG("4 Size:"<<inputParts4.size()<<" 0th:"<<inputParts4[0]->index<<"\n");
                  FuncNode *pippo;
                  if ( inputParts2.size()>0 && inputParts2[0]->index == 6213) {
                      if ((pippo=dynamic_cast< FuncNode*>(left2)) ) {
                        DEBUG("TABLE 2nd func downcast OK\n");
                        pippo->setParticleIndex(0,   inputParts1[0]->index);
                        pippo->setParticleCollection(0, inputParts1[0]->collection);
                        DEBUG("TABLE 2nd func param set OK\n");
                       } else {
                       std::cerr<<"TABLE 2nd function parmeters can not be set. ERROR\n"; exit (15);
                       }
                      bval=left2->evaluate(ao);
                      pippo->setParticleIndex(0,   6213);
                      if ((pippo=dynamic_cast< FuncNode*>(left3)) ) {
                        DEBUG("TABLE 3nd func downcast OK\n");
                        pippo->setParticleIndex(0,   inputParts1[0]->index);
                        pippo->setParticleCollection(0, inputParts1[0]->collection);
                        DEBUG("TABLE 3nd func param set OK\n");
                       } else {
                       std::cerr<<"TABLE 3nd function parmeters can not be set. ERROR\n"; exit (15);
                       }
                      cval=left3->evaluate(ao);
                      pippo->setParticleIndex(0,   6213);
                      if ((pippo=dynamic_cast< FuncNode*>(left4)) ) {
                        DEBUG("TABLE 4nd func downcast OK\n");
                        pippo->setParticleIndex(0,   inputParts1[0]->index);
                        pippo->setParticleCollection(0, inputParts1[0]->collection);
                        DEBUG("TABLE 4nd func param set OK\n");
                       } else {
                       std::cerr<<"TABLE 4nd function parmeters can not be set. ERROR\n"; exit (15);
                       }
                      dval=left4->evaluate(ao);
                      pippo->setParticleIndex(0,   6213);
                  } 
                  
                  DEBUG("\naval:"<<aval<< " bval:"<<bval<< " cval:"<<cval<< " dval:"<<dval<<"\t");
                  for (it=0; it<atable.size(); it+=9){ // 9 is for 2D only. value, min, max, min2, max2. min3 max3 min4 max4
                    if(  aval>=atable[it+1] && aval<=atable[it+2] 
                      && bval>=atable[it+3] && bval<=atable[it+4]
                      && cval>=atable[it+5] && cval<=atable[it+6]
                      && dval>=atable[it+7] && bval<=atable[it+8]
                      ) {
                     range_found=true;
                     tval=atable[it];
                     DEBUG(" tval:"<<tval<<"\n");
                     it=(it/9);
                     break;
                    }
                   }
                  
                 if (!range_found) {std::cerr << "Specified 1st:"<< aval << " or 2nd:"<< bval
                                              <<" value is out of table range! Setting coeff to ZERO.\n";
                                    tval=0;}
             } // 4D ends
           
            }// not 1D ends.
            DEBUG(" Error condition:"<<errors<< " it:"<<it<<"\n");
            if (errors && it<errtable.size() ){
             double sigleft=errtable[it];
             double sigright=errtable[it+1];
             double Area=sqrt(2/3.14159265)/(sigright+sigleft);
             TString hesap="x>";
                     hesap+=tval;
                     hesap+="?gaus(0):gaus(3)";
             TF1 *f4 = new TF1("f4",hesap,0,1);
             f4->SetParameters(Area,tval,sigleft,Area,tval,sigright);
             DEBUG("err range:"<<sigleft<<","<< sigright<<" modified tval:"<<f4->GetRandom()<<"\n"); 
            }

    return (*f)(tval, ao);
    }


double tweight(double value, AnalysisObjects* ao ) {
    ao->evt.user_evt_weight *= value;
    return 1;
}
double thitmiss(double value, AnalysisObjects* ao ) {
    DEBUG( "table hitmiss retval:"<<value<<"\n");
    return value;
}

#endif /* TableNode */
