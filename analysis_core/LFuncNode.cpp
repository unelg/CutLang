#include "LFuncNode.h"

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
         originalParticles2.push_back(apart2);
        }
    }
    

void LFuncNode::getParticles(std::vector<myParticle *>* particles) {
        cout<<"MODIFY TO CHECK FOR EXISTING INDICES in ListFuncNode------\n";
        for (int i=0; i<inputParticles.size(); i++){
            particles->push_back(inputParticles[i]);
            }   
        for (int i=0; i<inputParticles2.size(); i++){
            particles->push_back(inputParticles2[i]);
            } 
    }

void LFuncNode::getParticlesAt(std::vector<myParticle *>* particles, int index){
        particles->push_back(inputParticles[index]);
        particles->push_back(inputParticles2[index]);
}

void LFuncNode::setUserObjects(Node *objectNodea, Node *objectNodeb, Node *objectNodec, Node *objectNoded){
       cout <<"Adding UOs 2 LF\n";
        userObjectA=objectNodea;
        userObjectB=objectNodeb;
        userObjectC=objectNodec;
        userObjectD=objectNoded;
}

   
double LFuncNode::evaluate(AnalysisObjects* ao)  {
     cout <<"In L function Node evaluate\n";

        if(userObjectA)  userObjectA->evaluate(ao); // returns 1, hardcoded. see ObjectNode.cpp
        if(userObjectB)  userObjectB->evaluate(ao); // returns 1, hardcoded. see ObjectNode.cpp
        if(userObjectC)  userObjectC->evaluate(ao); // returns 1, hardcoded. see ObjectNode.cpp
        if(userObjectD)  userObjectD->evaluate(ao); // returns 1, hardcoded. see ObjectNode.cpp

        partConstruct(ao, &inputParticles,&myPart);
        partConstruct(ao, &inputParticles2,&myPart2);
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
