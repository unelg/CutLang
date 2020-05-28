#include "LFuncNode.h"

//#define _CLV_
#ifdef _CLV_
#define DEBUG(a) std::cout<<a
#else
#define DEBUG(a)
#endif

void LFuncNode::ResetParticles() {
          for(int i=0;i<originalParticles.size();i++){
                *(inputParticles[i])=originalParticles[i];

          }
          for(int i=0;i<originalParticles2.size();i++){
              *(inputParticles2[i])=originalParticles2[i];

          }
    }

void LFuncNode::setParticleIndex(int order, int newIndex) {
        if(order<inputParticles.size()){
            inputParticles.at(order)->index=newIndex;
        }
        else{
            inputParticles2.at(order-inputParticles.size())->index=newIndex;
        }
    }
    

LFuncNode::LFuncNode(double (*func)(dbxParticle* part1,dbxParticle* part2),std::vector<myParticle*> input1,std::vector<myParticle*> input2,std::string s,  Node *objectNodea, Node *objectNodeb, Node *objectNodec, Node *objectNoded ) : FuncNode(NULL,input1,s, objectNodea,"", objectNodeb, objectNodec, objectNoded) {
//after objnodea the correct string needs to be put, NGU-----
        f2=func;
        inputParticles2=input2;
        myParticle apart2;
        userObjectA=objectNodea;
        userObjectB=objectNodeb;
        userObjectC=objectNodec;
        userObjectD=objectNoded;

        for (int i=0; i<input2.size(); i++){
           apart2.index=input2[i]->index;
           apart2.type=input2[i]->type;
           apart2.collection=input2[i]->collection;
         originalParticles2.push_back(apart2);
        }
    }
    

void LFuncNode::getParticles(std::vector<myParticle *>* particles) {
//        cout<<"MODIFY TO CHECK FOR EXISTING INDICES in ListFuncNode------\n";
        int size=particles->size();
        for (int i=0; i<inputParticles.size(); i++){
            bool found=false;
            for(int j=0;j<size;j++){
                if (inputParticles[i]->index==particles->at(j)->index)
                { found=true;break; }
            }
            if(!found){ particles->push_back(inputParticles[i]); }

        }   
        for (int i=0; i<inputParticles2.size(); i++){
            bool found=false;
            for(int j=0;j<size;j++){
                if (inputParticles2[i]->index==particles->at(j)->index)
                {   found=true;break; }
            }
            if(!found){ particles->push_back(inputParticles2[i]); }
        } 
    }

void LFuncNode::getParticlesAt(std::vector<myParticle *>* particles, int index){
        particles->push_back(inputParticles[index]);
        particles->push_back(inputParticles2[index]);
}

void LFuncNode::setUserObjects(Node *objectNodea, Node *objectNodeb, Node *objectNodec, Node *objectNoded){
        userObjectA=objectNodea;
        userObjectB=objectNodeb;
        userObjectC=objectNodec;
        userObjectD=objectNoded;
}

   
double LFuncNode::evaluate(AnalysisObjects* ao)  {
        DEBUG("In L function Node evaluate: "<< inputParticles.size() << ","<< inputParticles2.size()<<"\n");

        if(userObjectA)  userObjectA->evaluate(ao); // returns 1, hardcoded. see ObjectNode.cpp
        if(userObjectB)  userObjectB->evaluate(ao); // returns 1, hardcoded. see ObjectNode.cpp
        if(userObjectC)  userObjectC->evaluate(ao); // returns 1, hardcoded. see ObjectNode.cpp
        if(userObjectD)  userObjectD->evaluate(ao); // returns 1, hardcoded. see ObjectNode.cpp

        for (int jj=0; jj< inputParticles.size(); jj++){
         DEBUG("P0_"<<jj<<" Type:"<<inputParticles[jj]->type<< " index:"<<inputParticles[jj]->index<<"\n");
        }
        DEBUG("P1_0 Type:"<<inputParticles2[0]->type<<" collection:"<< inputParticles2[0]->collection << " index:"<<inputParticles2[0]->index<<"\n");
        if ( inputParticles2[0]->index == 6213) {
           string base_collection2=inputParticles2[0]->collection;
              int base_type2=inputParticles2[0]->type;
           int ipart2_max=-1;
           try {
                switch(abs(inputParticles2[0]->type)){
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
                       std::cerr << "WRONG PARTICLE TYPE:"<<inputParticles2[0]->type << std::endl; break;
                }
                } catch(...) {
                            std::cerr << "YOU WANT A PARTICLE TYPE YOU DIDN'T CREATE:"<<base_collection2 <<" !\n";
                            _Exit(-1);
                }
            // now we know how many we want
            DEBUG ("Sum "<< ipart2_max<<" particles\t");
            std::vector<myParticle*>  inputParticles1;
            std::vector<myParticle>  inputParticles0;
            for (int ip2=0; ip2 < ipart2_max; ip2++){
            myParticle * aparticle = new myParticle;
                         aparticle->type= base_type2;
                         aparticle->collection= base_collection2;
                         aparticle->index=ip2;
                       DEBUG( "index="<<ip2<<" ");
              inputParticles0.push_back(*aparticle);
              delete aparticle;
            }
            DEBUG("\n");
        for (int ji=0; ji<inputParticles0.size(); ji++){
         inputParticles1.push_back( &inputParticles0[ji]);
        }
        partConstruct(ao, &inputParticles1,&myPart2);
        inputParticles0.clear();
        inputParticles1.clear();
        } else {
        partConstruct(ao, &inputParticles2,&myPart2);
        }
  
        partConstruct(ao, &inputParticles,&myPart);
        return (*f2)(&myPart,&myPart2);
}

LFuncNode::~LFuncNode() {}
    


double dR(dbxParticle* apart,dbxParticle* apart2){
    double deltaR=apart->lv().DeltaR(apart2->lv() );
    DEBUG(" dR:"<<deltaR<<"\t");
    return deltaR;
}

double dPhi(dbxParticle* apart,dbxParticle* apart2){
    double deltaPhi=fabs(apart->lv().DeltaPhi(apart2->lv() ) );
    DEBUG(" dPhi:"<<deltaPhi<<"\t");
    return deltaPhi;
}

double dEta(dbxParticle* apart,dbxParticle* apart2){
    double deltaEta=fabs(apart->lv().Eta() - apart2->lv().Eta() );
    DEBUG(" dEta:"<<deltaEta<<"\t");
    return deltaEta;
}
