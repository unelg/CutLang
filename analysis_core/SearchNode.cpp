#include "SearchNode.h"

//#define _CLV_

#ifdef _CLV_
#define DEBUG(a) std::cout<<a
#else
#define DEBUG(a)
#endif

using namespace std;
    void SearchNode::performInnerOperation(vector<int> *v,vector<int> *indices, double *current_difference,AnalysisObjects* ao){
          
        for(int i=0;i<v->size();i++){
            DEBUG(v->at(i)<<" ");
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

    void SearchNode::runNestedLoopBarb( int start, int N, int level, int maxDepth, vector<int> *v,vector<int> *indices,double *curr_diff,AnalysisObjects* ao) 
      {
      const int unk_MAX=6;
      int ip_N[unk_MAX]={N,N,N,N,N,N}; 
      int ip[unk_MAX]; 
      int  oi[unk_MAX]={N,N,N,N,N,N}; 
      int ip2_min=0, ip3_min=0, ip4_min=0, ip5_min=0, ip1_min=0;


//------------if less than 6, no other loops
       for (int i=maxDepth; i<6; i++) ip_N[i]=1;


      for(int i=0;i<particles.size();i++){
                    oi[i]=particles.at(i)->index;
                      DEBUG(" oi:"<<oi[i]<<" ");
      }
      DEBUG(" -|:"<<maxDepth<<"\n");
      // loops start ~~~~~~~~~~~

       DEBUG("MAX ips:"<< ip_N[0]<< " "<<ip_N[1]<<" "<<ip_N[2]<<" "<< ip_N[3]<<" "<<ip_N[4]<<" "<<ip_N[5]<<"\n ");

          for (ip[0]=0; ip[0]<ip_N[0]; ip[0]++) {
           DEBUG("0:"<<ip[0]<<"\n");
           if ( FORBIDDEN_INDICES.find( ip[0] )!=FORBIDDEN_INDICES.end() ) continue;        
           for (ip[1]=ip1_min; ip[1]<ip_N[1]; ip[1]++) {
           DEBUG("1:"<<ip[1]<<"\n");
            if ( FORBIDDEN_INDICES.find( ip[1] )!=FORBIDDEN_INDICES.end() ) continue;        
            if (ip_N[1]>0 && (ip[1]==ip[0])) continue;
            if ( (oi[0] == oi[1]) && (ip[0]>ip[1]) ) continue;

              for (ip[2]=ip2_min; ip[2]<ip_N[2]; ip[2]++) {
                DEBUG("2:"<< ip[2]<<"\n");
                if ( maxDepth>2 ){ 
                   if ( ip_N[2]>0 && (ip[2]==ip[0] || ip[2]==ip[1])) continue;
                   if ( FORBIDDEN_INDICES.find( ip[2] )!=FORBIDDEN_INDICES.end() ) continue;        
                }
                for (ip[3]=ip3_min; ip[3]<ip_N[3]; ip[3]++) {
                  DEBUG("3: "<< ip[0] << " " << ip[1] << " " <<ip[2] <<" "<<ip[3]<<"\n" );
                  if ( maxDepth>3){ 
                     if ( ip_N[3]>0 && (ip[3]==ip[0] || ip[3]==ip[1] || ip[3]==ip[2])) continue;
                     if ( FORBIDDEN_INDICES.find( ip[3] )!=FORBIDDEN_INDICES.end() ) continue;        
                     if ( (oi[2]==oi[3]) && (ip[2]>ip[3]) ) continue;
                  }
                  for (ip[4]=ip4_min; ip[4]<ip_N[4]; ip[4]++) {
                    DEBUG("4\n");
                    //if (ip_N[5]>1)
                    if ( maxDepth>4)  {
                     if ( ip_N[4]>0 && (ip[4]==ip[0] || ip[4]==ip[1] || ip[4]==ip[2] || ip[4]==ip[3])) continue;
                     if ( FORBIDDEN_INDICES.find( ip[4] )!=FORBIDDEN_INDICES.end() ) continue;        
                     if ( ( oi[3] == oi[4]) &&(ip[3]>ip[4]) )  continue;
                    }
                     for (ip[5]=ip5_min; ip[5]<ip_N[5]; ip[5]++) {
                      DEBUG("5\n");
                      //if (ip_N[5]>1)
                      if (maxDepth>5) {
                       if ( ip_N[5]>0 &&(ip[5]==ip[0] || ip[5]==ip[1] || ip[5]==ip[2] || ip[5]==ip[3] || ip[5]==ip[4])) continue;
                       if ( FORBIDDEN_INDICES.find( ip[5] )!=FORBIDDEN_INDICES.end() ) continue;        
                       if ( ( oi[4] == oi[5]) &&(ip[4]>ip[5]) )  continue;
                      }

                      if ( (oi[3]== (-10+oi[0]) ) && (ip[0]>ip[3]) ) continue;
          
                 DEBUG("test:"<<ip[0]<<" "<<ip[1]<<" "<<ip[2]<<" "<<ip[3]<<" "<<ip[4]<<" "<<ip[5]<<"\n");
                 for (int i=0; i<maxDepth; i++) v->push_back(ip[i]);

                  for(int i=0;i<v->size();i++){
                      DEBUG(v->at(i)<<" ");
                      particles.at(indices->at(i))->index=v->at(i);
                  }

//-------~1min in 25k events
                 double tmpval=left->evaluate(ao); // enabling this makes total 1min6s, without it 12s
                 double diff=right->evaluate(ao)-tmpval;
                 //cout << tmpval<<"\n";
                 if ( (*f)(diff,*curr_diff) ) {
                       DEBUG("diff:"<<diff<<" c_diff:"<<*curr_diff<<"\n");
                       *curr_diff = fabs(diff);
                       bestIndices=*v;
                 } else { DEBUG("\n");}
                 v->clear();
                }}
             }}}} //all iN loops end

    }
    void SearchNode::runNestedLoopRec( int start, int N, int level, int maxDepth, vector<int> *v,vector<int> *indices,double *curr_diff,AnalysisObjects* ao) {
    if(level==maxDepth)  performInnerOperation (v,indices,curr_diff,ao); //18 without this function call
    else{
        bool skip=false;
        for (int x = start; x < N; x++ ) {

            skip=false;
            for (int kk=0; kk<v->size(); kk++){
             if (v->at(kk)==x) {
                 skip=true; break;}
             //check if particle x is forbidden
             if ( FORBIDDEN_INDICES.find(x)!=FORBIDDEN_INDICES.end() )//true if element is present
                    {skip=true; break;}
            }
            if (skip) continue;

            v->push_back(x); //add the current value
            runNestedLoopRec( start, N, level + 1, maxDepth, v,indices, curr_diff, ao );
            v->pop_back();//remove the value
        }
    }
}


    SearchNode::SearchNode(double (*func)(double, double), Node* l, Node* r, std::string s){
        f=func;
        symbol=s;
        left=l;
        right=r;
    }

    double SearchNode::evaluate(AnalysisObjects* ao) {
            
           
            particles.clear();
            left->getParticles(&particles);//should fill with particles pointers no more cast needed

            vector<int> indices;
            DEBUG("\n");
            for(int i=0;i<particles.size();i++){
                DEBUG("Part:"<<i<<"  idx:"<<particles.at(i)->index<< "  addr:"<<particles.at(i)<<"\n");
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
                   // runNestedLoopRec( 0, Max, 0, MaxDepth, &v,&indices, &current_difference,ao);

                    for(int i=0;i<bestIndices.size();i++){
                        particles.at(indices[i])->index=bestIndices[i];//directly changing the concerned particle
                        //-------------------add found indices to FORBIDDEN
                        FORBIDDEN_INDICES.insert(bestIndices[i]);
                        DEBUG("BEST"<<particles.at(indices[i])->index<<" : "<<bestIndices[i]<<"@"<<indices[i] <<" type:"<<particles.at(indices[i])->type<<"  addr:"<<particles.at(indices[i]) <<" \n");
                    }
            }
            else{
                DEBUG("No negative index found... Returning\n");
            }
            DEBUG("\n");
            return 1;
    }

    void SearchNode::Reset() {
            FORBIDDEN_INDICES.clear();
            left->Reset();//assuming right doesnt need a Reset because it's a value Node
    }

    void SearchNode::getParticles(std::vector<myParticle *>* particles) {
    }
    void SearchNode::getParticlesAt(std::vector<myParticle *>* particles, int index) {
        
    }

    SearchNode::~SearchNode() {
//        if (left!=NULL) delete left;
//        if (right!=NULL) delete right;
    }



double maxim( double difference, double current_difference){
    return (fabs(difference) > current_difference );
}

double minim( double difference, double current_difference){
    return fabs(difference) < current_difference ;
}
