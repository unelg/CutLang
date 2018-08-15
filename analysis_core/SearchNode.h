#ifndef SearchNode_h
#define SearchNode_h

#include <stdio.h>
#include <math.h>
#include <list>
#include <unordered_set>
#include "Node.h"

//#define _CLV_

#ifdef _CLV_
#define DEBUG(a) std::cout<<a
#else
#define DEBUG(a)
#endif


//takes care of Minimizing/Maximizing
class SearchNode : public Node{
private:
    static unordered_set<int> FORBIDDEN_INDICES;
    double (*f)(double, double);
    vector<int> bestIndices;
    std::vector<myParticle *> particles;//pointers to particles in all nodes that have to be changed

    void performInnerOperation(vector<int> *v,vector<int> *indices, double *current_difference,AnalysisObjects* ao){
          
        for(int i=0;i<v->size();i++){
            DEBUG(v[i]<<" ");
            particles.at(indices->at(i))->index=v->at(i);
        }

//-------~1min in 25k events
      double tmpval=left->evaluate(ao); // enabling this makes total 1min6s, without it 12s
      double diff=right->evaluate(ao)-tmpval;

            
        if ( (*f)(diff,*current_difference) ) {
            DEBUG("diff:"<<diff<<" c_diff:"<<*current_difference<<"\n");
            *current_difference = fabs(diff);
            bestIndices=*v;
        } else { DEBUG("\n");}
      }

    void runNestedLoopBarb( int start, int N, int level, int maxDepth, vector<int> *v,vector<int> *indices,double *curr_diff,AnalysisObjects* ao) 
      {
      // loops start ~~~~~~~~~~~
          const int unk_MAX=6;
          int ip_N[unk_MAX]={N,N,N,N,N,N}; 
          int ip2_min=0, ip3_min=0, ip4_min=0, ip5_min=0, ip6_min=0;

          for (int ip1=0; ip1< ip_N[0]; ip1++) {
           if (ip1> 0 ) if (ip1==ip_N[0]) continue; // upper limit
//           if (isForbidden(ip1, search_types[0])) continue;

           for (int ip2=ip2_min; ip2<=ip_N[1]; ip2++) {
            if (ip_N[1]>0 && (ip2==ip1)) continue;
            if (ip2> 0 ) if (ip2==ip_N[1]) continue; // upper limit
//            if (isForbidden(ip2, search_types[1])) continue;

            for (int ip3=ip3_min; ip3< ip_N[2]; ip3++) {
              if (ip_N[2]>0 && (ip3==ip1 || ip3==ip2)) continue;
              if (ip3> 0 ) if (ip3==ip_N[2]) continue; // upper limit
//              if (isForbidden(ip3, search_types[2])) continue;

              for (int ip4=ip4_min; ip4< ip_N[3]; ip4++) {
                if (ip_N[3]>0 && (ip4==ip1 || ip4==ip2 || ip4==ip3)) continue;
                if (ip4> 0 ) if (ip4==ip_N[3]) continue; // upper limit
//                if (isForbidden(ip4, search_types[3])) continue;

               for (int ip5=ip5_min; ip5< ip_N[4]; ip5++) {
                if (ip_N[4]>0 && (ip5==ip1 || ip5==ip2 || ip5==ip3 || ip5==ip4)) continue;
                if (ip5>0 )  if (ip5==ip_N[4]) continue; // upper limit
//                if (isForbidden(ip5, search_types[4])) continue;

               for (int ip6=ip6_min; ip6< ip_N[5]; ip6++) {
                 if (ip_N[5]>0 &&(ip6==ip1 || ip6==ip2 || ip6==ip3 || ip6==ip4 || ip6==ip5)) continue;
                 if (ip6> 0 ) if (ip6==ip_N[5]) continue; // upper limit
//                 if (isForbidden(ip6, search_types[5])) continue;

                  ;//1.3s

                  v->push_back(ip1);
                  v->push_back(ip2);
                  v->push_back(ip3);
                  v->push_back(ip4);
                  v->push_back(ip5);
                  v->push_back(ip6);
                  //performInnerOperation (v,indices,curr_diff,ao); //2.3s without this call

        for(int i=0;i<v->size();i++){
            DEBUG(v[i]<<" ");
            particles.at(indices->at(i))->index=v->at(i);
        }

//-------~1min in 25k events
      double tmpval=left->evaluate(ao); // enabling this makes total 1min6s, without it 12s
      double diff=right->evaluate(ao)-tmpval;


        if ( (*f)(diff,*curr_diff) ) {
            DEBUG("diff:"<<diff<<" c_diff:"<<*curr_diff<<"\n");
            *curr_diff = fabs(diff);
            bestIndices=*v;
        } else { DEBUG("\n");}

              
                  v->clear();
                }}}}}} //all iN loops end

    }
    void runNestedLoopRec( int start, int N, int level, int maxDepth, vector<int> v,vector<int> indices,double *curr_diff,AnalysisObjects* ao) {
    if(level==maxDepth)  performInnerOperation (&v,&indices,curr_diff,ao); //18 without this function call
    else{
        bool skip=false;
        for (int x = start; x < N; x++ ) {

            skip=false;
            for (int kk=0; kk<v.size(); kk++){
             if (v[kk]==x) {
                 skip=true; break;}
             //check if particle x is forbidden
             if ( FORBIDDEN_INDICES.find(x)!=FORBIDDEN_INDICES.end() )//true if element is present
                    {skip=true; break;}
            }
            if (skip) continue;

            v.push_back(x); //add the current value
            runNestedLoopRec( start, N, level + 1, maxDepth, v,indices, curr_diff, ao );
            v.pop_back();//remove the value
        }
    }
}


public:

    SearchNode(double (*func)(double, double), Node* l, Node* r, std::string s){
        f=func;
        symbol=s;
        left=l;
        right=r;
    }

    virtual double evaluate(AnalysisObjects* ao) override{
            
            DEBUG("Evaluate\n");
            particles.clear();
            left->getParticles(&particles);//should fill with particles pointers no more cast needed

            vector<int> indices;
            for(int i=0;i<particles.size();i++){
                DEBUG("Part:"<<i<<"  idx:"<<particles.at(i)->index<<"\n");
                if(particles.at(i)->index<0) indices.push_back(i);
                else FORBIDDEN_INDICES.insert(particles.at(i)->index);
            }

            int MaxDepth=indices.size();//number of nested loops needed
            DEBUG("Depth:"<<MaxDepth<<"\n");
            if(indices.size()>0){

                    int type=particles.at(indices[0])->type;
                    int Max;
                    switch(type){//assuming all particles have the same type
                        case 0: Max=ao->muos.size();break;
                        case 1: Max=ao->eles.size();break;
                        case 2: Max=ao->jets.size();break;
                        case 3: Max=left->tagJets(ao,1).size();break;
                        case 4: Max=left->tagJets(ao,0).size();break;
                    }
                    vector<int> v;//--------------------why not pass it by reference?!
                    double current_difference =9999999999.9;
                    runNestedLoopBarb( 0, Max, 0, MaxDepth, &v,&indices, &current_difference,ao);

                    for(int i=0;i<bestIndices.size();i++){
                        particles.at(indices[i])->index=bestIndices[i];//directly changing the concerned particle
                        //-------------------add found indices to FORBIDDEN
                        FORBIDDEN_INDICES.insert(bestIndices[i]);
                        DEBUG("BEST"<<particles.at(indices[i])->index<<" : "<<bestIndices[i]<<" ");
                    }
            }
            else{
                DEBUG("No negative index found... Returning\n");
            }
            DEBUG("\n");
            return 1;
   
    }
    virtual void Reset() override{
            FORBIDDEN_INDICES.clear();
            left->Reset();//assuming right doesnt need a Reset because it's a value Node
    }

    virtual void getParticles(std::vector<myParticle *>* particles) override{
    }

    virtual ~SearchNode() {
//        if (left!=NULL) delete left;
//        if (right!=NULL) delete right;
    }

};

double maxim( double difference, double current_difference){
    return (fabs(difference) > current_difference );
}

double minim( double difference, double current_difference){
    return fabs(difference) < current_difference ;
}

#endif
