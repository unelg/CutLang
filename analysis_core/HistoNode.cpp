#include "HistoNode.h"

//#define _CLV_

#ifdef _CLV_
#define DEBUG(a) std::cout<<a
#else
#define DEBUG(a)
#endif

using namespace std;

  void   HistoNode( std::string id,std::string desc,int n, float l1, float l2,Node* l){
        this->id=id;
        Desciption=desc;
        lowerLimitx=l1;
        upperLimitx=l2;
        binsx=n;
        symbol="histo "+id+","+Desciption+","+std::to_string(l1)+","+std::to_string(l2)+","+std::to_string(n);
        ahisto1 = new TH1D(id.data(), Desciption.data(), binsx, lowerLimitx, upperLimitx);
	ahisto2 = NULL;
        left=l;
        right=NULL;
    }

    virtual void Reset() override{ left->Reset(); } // reset right as well 
    virtual void getParticles(std::vector<myParticle *>* particles) override{
         left->getParticles(particles);
    }
    virtual void getParticlesAt(std::vector<myParticle *>* particles, int index) override{}
    virtual double evaluate(AnalysisObjects* ao) override {
        if (dim == 1) // this if has to go. we can make 2 independent and similar classes
		{

                  this->getParticles(&inputParticles);
                  for (int ii=0; ii<inputParticles.size(); ii++){
                      DEBUG("Histo particle ID:"<<ii<<" Type:"<<inputParticles[ii]->type<<" collection:"
                        << inputParticles[ii]->collection << " index:"<<inputParticles[ii]->index<<"\n");
                  }
                  if (inputParticles[0]->index == 6213){
                      std::string bcol2=inputParticles[0]->collection;
                      bool constiloop=false;
                      std::string consname;
                      int ipartMax=0;
                      try {
                                   switch(inputParticles[0]->type){
                                   case muon_t: ipartMax=(ao->muos).at(bcol2).size(); break;
                                  case truth_t: ipartMax=(ao->truth).at(bcol2).size(); break;
                               case electron_t: ipartMax=(ao->eles).at(bcol2).size(); break;
                                    case jet_t: ipartMax=(ao->jets).at(bcol2).size(); break;
                                  case pureV_t: ipartMax=1; break;
                                 case photon_t: ipartMax=(ao->gams).at(bcol2).size(); break;
                                   case fjet_t: ipartMax=(ao->ljets).at(bcol2).size(); break;
                                    case tau_t: ipartMax=(ao->taus).at(bcol2).size(); break;
                                  case combo_t: ipartMax=(ao->combos)[bcol2].size(); break;
                                 case consti_t: {constiloop=true;
                                               TString konsname=bcol2;
                                                      konsname+="_";
                                                      konsname+=inputParticles[0]->index;
                                                      konsname+="c";
                                                      consname=(std::string)konsname;
                                                      ipartMax =(ao->constits).find(consname)->second.size();
                                                      DEBUG(consname<<" has "<<ipartMax<<" constituents\n");
                                               break;}
                           
                           
                                      default:
                                          std::cerr << "WRONG PARTICLE TYPE:"<<inputParticles[0]->type << std::endl; break;
                                   }
                           } catch(...) {
                                               std::cerr << "YOU WANT TO histo A PARTICLE TYPE YOU DIDN'T CREATE:"<<bcol2 <<" !\n";
                                               _Exit(-1);
                           }
                           DEBUG ("loop over "<< ipartMax<<" particles\n");
                           FuncNode *pippo;
                           DEBUG("it will do: "<<left->getStr()<<"\n");
                           if (pippo=dynamic_cast< FuncNode*>(left) ) {
                            DEBUG("downcast OK\n");
                           } else {
                            DEBUG("downcast FAILS\n");
                             if (pippo=dynamic_cast< FuncNode*>(left->left) ) {
                               DEBUG("down-downcast OK\n");
                             }
                           }
                           for (int ii=0; ii<ipartMax; ii++) {
                             DEBUG("now for particle "<<ii<<"\n");
                             pippo->setParticleIndex(0, ii);
                             double value = left->evaluate(ao);
                             DEBUG("Histo Loop retval:"<<value<<"\n");
		             ahisto1->Fill(value, ao->evt.user_evt_weight);
                           }
                           pippo->setParticleIndex(0, 6213);
                  } else 
                  {
                           double value = left->evaluate(ao);
		           ahisto1->Fill(value, ao->evt.user_evt_weight);
                  }
		  return 1;
		}
	else
		{
		      double value1=left->evaluate(ao);
		      double value2=right->evaluate(ao);
        	      ahisto2->Fill(value1, value2, ao->evt.user_evt_weight);
        	      return 1;
		}
    }
    virtual ~HistoNode() {
        if (left!=NULL) delete left;
	if (right!=NULL) delete right;
    }
    
}
