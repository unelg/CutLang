#ifndef SearchNode_h
#define SearchNode_h

#include <stdio.h>
#include <math.h>
#include <list>
#include <unordered_set>
#include "Node.h"

#define _CLV_

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


    void performInnerOperation(vector<int> v,vector<int> indices, double *current_difference,AnalysisObjects* ao){
          
        for(int i=0;i<v.size();i++){
            DEBUG(v[i]<<" ");
            particles.at(indices[i])->index=v[i];
        }
        double tmpval=left->evaluate(ao);
        double diff=right->evaluate(ao)-tmpval;
            
        if ( (*f)(diff,*current_difference) ) {
            DEBUG("diff:"<<diff<<" c_diff:"<<*current_difference<<"\n");
            *current_difference = fabs(diff);
            bestIndices=v;
        } else { DEBUG("\n");}
      }

    void runNestedLoop( int start, int N, int level, int maxDepth, vector<int> v,vector<int> indices,double *curr_diff,AnalysisObjects* ao) {
    if(level==maxDepth) performInnerOperation (v,indices,curr_diff,ao);
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
            
            v.push_back(x); 
            runNestedLoop( start, N, level + 1, maxDepth, v,indices, curr_diff, ao );
            v.pop_back();
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
                    vector<int> v;
                    double current_difference =1000;
                    runNestedLoop( 0, Max, 0, MaxDepth, v,indices, &current_difference,ao);

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
        cout<<"Calling getParticles on an SearchNode------doing nothing to input";    
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
