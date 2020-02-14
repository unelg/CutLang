//
//  LoopNode.h
//
//

#ifndef LoopNode_h
#define LoopNode_h
#include "Node.h"

#define _CLV_
#ifdef _CLV_
#define DEBUG(a) std::cout<<a
#else
#define DEBUG(a)
#endif

//Looping over variables
class LoopNode : public Node{
private:
    double (*f)(std::vector<double>);

protected:
    std::vector<myParticle*> inputParticles;

public:
    LoopNode(double (*func)(std::vector<double>), Node* l, std::string s){
        f=func;
        symbol=s;
        left=l;
        right=NULL;
    }
    
    virtual void getParticles(std::vector<myParticle *>* particles) override{
         left->getParticles(particles);
    }

    virtual void getParticlesAt(std::vector<myParticle *>* particles, int index) override{
        left->getParticlesAt(particles,index);
    }

    virtual void Reset() override{
        left->Reset();
    }

    virtual double evaluate(AnalysisObjects* ao) override {
      // here we need to loop over all functions
       std::vector <double> result_list;
       DEBUG("\nWe are in "<<this->getStr()<<"\n");
       this->getParticles(&inputParticles);       

       for (int ii=0; ii<inputParticles.size(); ii++){
        DEBUG("Loop:"<<ii<<" Type:"<<inputParticles[ii]->type<<" collection:"
                     << inputParticles[ii]->collection << " index:"<<inputParticles[ii]->index<<"\n");
       }
       int ipart2_max=0; // loop counter
       if (inputParticles[0]->index == 6213) {
        std::string base_collection2=inputParticles[0]->collection;
        int base_type2=inputParticles[0]->type;
        try {
                switch(inputParticles[0]->type){
                    case 0: ipart2_max=(ao->muos).at(base_collection2).size(); break;
                    case 10: ipart2_max=(ao->truth).at(base_collection2).size(); break;
                    case 1: ipart2_max=(ao->eles).at(base_collection2).size(); break;
                    case 2: ipart2_max=(ao->jets).at(base_collection2).size(); break;
                    case 7: ipart2_max=1; break;
                    case 8: ipart2_max=(ao->gams).at(base_collection2).size(); break;
                    case 9: ipart2_max=(ao->ljets).at(base_collection2).size(); break;
                   case 11: ipart2_max=(ao->taus).at(base_collection2).size(); break;
                   case 20: ipart2_max=(ao->combos)[base_collection2].size(); break;

                   default:
                       std::cerr << "WRONG PARTICLE TYPE:"<<inputParticles[0]->type << std::endl; break;
                }
        } catch(...) {
                            std::cerr << "YOU WANT TO LOOP A PARTICLE TYPE YOU DIDN'T CREATE:"<<base_collection2 <<" !\n";
                            _Exit(-1);
        }
       }
       // now we know how many we want
       DEBUG ("loop over "<< ipart2_max<<" particles\t");
       for (int ii=0;ii<ipart2_max; ii++){
        ((FuncNode*)left)->setParticleIndex(0, ii);
        double retval=left->evaluate(ao);
        DEBUG("retval:"<<retval<<"\n");
        result_list.push_back(retval); 
       }
       ((FuncNode*)left)->setParticleIndex(0, 6213);
       return (*f)(result_list);
    }
    
    virtual ~LoopNode() {
        if (left!=NULL) delete left;
    }
    
};

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


#endif /* LoopNode_h */
