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

void SearchNode::runNestedLoopBarb( int start, int N, int level, int maxDepth, vector<int> *v,
                                    vector<int> *indices,double *curr_diff,AnalysisObjects* ao, int type, string ac) {
      const int unk_MAX=6;
      bool found_at_least_one=false;
      int ip_N[unk_MAX]={N,N,N,N,N,N}; 
      int kN=particles.size();
//      int ip_N[unk_MAX]={kN,kN,kN,kN,kN,kN}; 
      int ip[unk_MAX]; 
      int  oi[unk_MAX]={N,N,N,N,N,N}; 
      int ip2_min=0, ip3_min=0, ip4_min=0, ip5_min=0, ip1_min=0;


//------------if less than 6, no other loops
      for (int i=maxDepth; i<6; i++) ip_N[i]=1;

      for(int i=0;i<particles.size();i++){
                    oi[i]=particles.at(i)->index;
                    DEBUG(" oi:"<<oi[i]<<" ");
      }
      int forbidit_size;
      std::map<string,unordered_set<int> >::iterator forbidit;
//-----TODO: put a check mechanism
       if ( FORBIDDEN_INDEX_LIST.find(ac) !=FORBIDDEN_INDEX_LIST.end() ){
        DEBUG("FORBIDDEN_INDEX_LIST is NOT Empty.\n");
        forbidit=FORBIDDEN_INDEX_LIST.find(ac);
        forbidit_size=forbidit->second.size();
       } else {
        DEBUG("FORBIDDEN_INDEX_LIST is Empty.\n");
        forbidit_size=0;
       }

      string s=particles.at(0)->collection;
      DEBUG(" -|:"<<maxDepth<<" N:"<<N<< " #ForbiddenIndexSize:"<<forbidit_size
                  << " Type:"<<type<<" Collection:"<<s<<" ac:"<<ac<<"\n");

      if ((type==20) && (ao->combosA[s].tableA.size() > 0)){
       DEBUG("-------------combo-------------------\n");
        for (int k1=0; k1<ao->combosA.at(s).tableA.size(); k1++) {
         if (ao->combosA.at(s).tableA[k1].size()==maxDepth) {
         for (int k2=0; k2<ao->combosA.at(s).tableA[k1].size(); k2++) {
          DEBUG(ao->combosA.at(s).tableA[k1][k2] << " ");
// the indice @ k1,k2 should be used
          if (k2 < maxDepth) v->push_back( ao->combosA.at(s).tableA[k1][k2] );
         }
         for(int i=0;i<v->size();i++){
                      particles.at(indices->at(i))->index=v->at(i);
         }   
         double tmpval=left->evaluate(ao); // enabling this makes total 1min6s, without it 12s
         double diff=right->evaluate(ao)-tmpval;

         if ( (*f)(diff,*curr_diff) ) {
                       DEBUG("diff:"<<diff<<" c_diff:"<<*curr_diff<<"\n");
                       *curr_diff = fabs(diff);
                       bestIndices.clear();
                       for(int i=0;i<v->size();i++){ bestIndices.push_back(v->at(i) ); }
                 } else { DEBUG("\n");}
          v->clear();
         }
        }
      return;
      }
      DEBUG("NON COMBO\n");
      // loops start ~~~~~~~~~~~
      DEBUG("MAX ips:"<< ip_N[0]<< " "<<ip_N[1]<<" "<<ip_N[2]<<" "<< ip_N[3]<<" "<<ip_N[4]<<" "<<ip_N[5]<<"\n");
      unordered_set<int> Forbidden_Indices;
      if (forbidit_size > 0) Forbidden_Indices=forbidit->second;
          DEBUG("Before LOOP\n");
          for (ip[0]=0; ip[0]<ip_N[0]; ip[0]++) {
           DEBUG("0:"<<ip[0]<<"\n");
           if ( Forbidden_Indices.find( ip[0] )!=Forbidden_Indices.end() ) continue;        
           for (ip[1]=ip1_min; ip[1]<ip_N[1]; ip[1]++) {
           DEBUG("1:"<<ip[1]<<"\n");
            if (Forbidden_Indices.find( ip[1] )!=Forbidden_Indices.end() ) { DEBUG("FORBIDDEN\n"); continue; }        
            if (particles.size()>1 && (ip[1]==ip[0])) { DEBUG("Repeated \n"); continue; }
            if ( (oi[0] == oi[1] ) && (ip[0]>ip[1]) ) { DEBUG("Same OI, repated\n"); continue; }

              for (ip[2]=ip2_min; ip[2]<ip_N[2]; ip[2]++) {
                DEBUG("2:"<< ip[2]<<"\n");
                if ( maxDepth>2 ){ 
                   if ( particles.size()>2 && (ip[2]==ip[0] || ip[2]==ip[1])) continue;
                   if ( Forbidden_Indices.find( ip[2] )!=Forbidden_Indices.end() ) continue;        
                }
                for (ip[3]=ip3_min; ip[3]<ip_N[3]; ip[3]++) {
                  DEBUG("3:"<< ip[3]<<"\n" );
                  if ( maxDepth>3){ 
                     if ( particles.size()>3 && (ip[3]==ip[0] || ip[3]==ip[1] || ip[3]==ip[2])) continue;
                     if ( Forbidden_Indices.find( ip[3] )!=Forbidden_Indices.end() ) continue;        
                     if ( (oi[2]==oi[3]) && (ip[2]>ip[3]) ) continue;
                  }
                  for (ip[4]=ip4_min; ip[4]<ip_N[4]; ip[4]++) {
                    DEBUG("4:"<<ip[4] <<"\n");
                    //if (ip_N[5]>1)
                    if ( maxDepth>4)  {
                     if ( particles.size()>4 && (ip[4]==ip[0] || ip[4]==ip[1] || ip[4]==ip[2] || ip[4]==ip[3])) continue;
                     if ( Forbidden_Indices.find( ip[4] )!=Forbidden_Indices.end() ) continue;        
                     if ( ( oi[3] == oi[4]) &&(ip[3]>ip[4]) )  continue;
                    }
                     for (ip[5]=ip5_min; ip[5]<ip_N[5]; ip[5]++) {
                      DEBUG("5:"<<ip[5] <<"\n");
                      //if (ip_N[5]>1)
                      if (maxDepth>5) {
                       if ( particles.size()>5 &&(ip[5]==ip[0] || ip[5]==ip[1] || ip[5]==ip[2] || ip[5]==ip[3] || ip[5]==ip[4])) continue;
                       if ( Forbidden_Indices.find( ip[5] )!=Forbidden_Indices.end() ) continue;        
                       if ( ( oi[4] == oi[5]) &&(ip[4]>ip[5]) )  continue;
                      }

                      if ( (oi[3]== (-10+oi[0]) ) && (ip[0]>ip[3]) ) continue;
          
                 DEBUG("testing:"<<ip[0]<<" "<<ip[1]<<" "<<ip[2]<<" "<<ip[3]<<" "<<ip[4]<<" "<<ip[5]<<"\n");
                 for (int i=0; i<maxDepth; i++) v->push_back(ip[i]);
                  DEBUG("Keeping: ");
                  for(int i=0;i<v->size();i++){
                      DEBUG(v->at(i)<<" --> "<<indices->at(i)<<"  was:"<<particles.at(indices->at(i))->index <<" " );
                      particles.at(indices->at(i))->index=v->at(i);
                  }
                  DEBUG("now left evaluate\n");

//-------~1min in 25k events
                 double tmpval=left->evaluate(ao); // enabling this makes total 1min6s, without it 12s
                 DEBUG("left ok: \n");
                 double diff=right->evaluate(ao)-tmpval;

                  DEBUG("compare: \n");
                 if ( (*f)(diff,*curr_diff) ) {
                       DEBUG("diff:"<<diff<<" c_diff:"<<*curr_diff<<"\n");
                       *curr_diff = fabs(diff);
                       bestIndices.clear();
                       for(int i=0;i<v->size();i++){ bestIndices.push_back( v->at(i) ); }
                       found_at_least_one=true;
                 } else { DEBUG("Comparison failed...\n");}

                 v->clear();
                }}
             }}}} //all iN loops end

     DEBUG("Search Ended.\n");
    }

   void SearchNode::runNestedLoopRec( int start, int N, int level, int maxDepth, vector<int> *v,
                                     vector<int> *indices,double *curr_diff,AnalysisObjects* ao, int type, string ac) {
    if(level==maxDepth)  performInnerOperation (v,indices,curr_diff,ao); //18 without this function call
    else{
        bool skip=false;
        for (int x = start; x < N; x++ ) {

            skip=false;
            for (int kk=0; kk<v->size(); kk++){
             if (v->at(kk)==x) {
                 skip=true; break;}
             //check if particle x is forbidden
              std::cout<<"FIXME\n";
                    {skip=true; break;}
            }
            if (skip) continue;

            v->push_back(x); //add the current value
            runNestedLoopRec( start, N, level + 1, maxDepth, v,indices, curr_diff, ao, type, ac);
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
        DEBUG("\nSearchN ---------------"<<getStr()<<"\n"); 
        particles.clear();
        left->getParticles(&particles);//should fill with particles pointers no more cast needed

        std::map<string,unordered_set<int> >::iterator forbidit;
        vector<int> indices;
        for(int i=0;i<particles.size();i++){
                DEBUG("SearchN Part:"<<i<<" idx:"<<particles.at(i)->index<< " addr:"<<particles.at(i)<<" name:"<< particles.at(i)->collection<<"\n");
                if(particles.at(i)->index<0) indices.push_back(i);
                else {
                     forbidit=FORBIDDEN_INDEX_LIST.find( particles.at(i)->collection  );
                     if (forbidit == FORBIDDEN_INDEX_LIST.end() ){
                       DEBUG("was NOT blacklisted, now adding. \n");
                       unordered_set<int> pippo;
                                          pippo.insert(particles.at(i)->index);
                       FORBIDDEN_INDEX_LIST.insert(std::pair<string, unordered_set<int> >(particles.at(i)->collection, pippo));
                      } else forbidit->second.insert(particles.at(i)->index);
                     }
        }

        int MaxDepth=indices.size();//number of nested loops needed
        DEBUG("SearchN Depth:"<<MaxDepth<<"\n");
        if(MaxDepth>0){
                    int type=particles.at(indices[0])->type;
                    string ac=particles.at(indices[0])->collection;
                    int Max;
                    switch(type){//assuming all particles have the same type
                       case 12: Max=ao->muos[ac].size();break;
                        case 1: Max=ao->eles[ac].size();break;
                        case 2: Max=ao->jets[ac].size();break;
                        case 3: Max=left->tagJets(ao,1,ac).size();break;
                        case 4: Max=left->tagJets(ao,0,ac).size();break;
			case 8: Max=ao->gams[ac].size();break;
			case 11: Max=ao->taus[ac].size();break;
			case 20: Max=ao->combos[ac].size();break;
                    }
                    DEBUG("Before find, Max:"<<Max<<" collection:"<< ac<< " Best index vector size:"<<bestIndices.size()<<"\n");
                    vector<int> v;//--------------------why not pass it by reference?!
                    double current_difference =9999999999.9;
                    runNestedLoopBarb( 0, Max, 0, MaxDepth, &v,&indices, &current_difference,ao, type, ac);
                   // runNestedLoopRec( 0, Max, 0, MaxDepth, &v,&indices, &current_difference,ao, type, ac);

                    DEBUG("After find, Best index vector size:"<<bestIndices.size()<<" MaxDepth"<<MaxDepth<<"\n");
                    if (bestIndices.size() < 1) return 0;
                    int maxFound = bestIndices.size();
//                    if (MaxDepth < bestIndices.size()) maxFound = MaxDepth;
                    for(int i=0;i<maxFound;i++){
                        particles.at(indices[i])->index=bestIndices[i]; //directly changing the concerned particle -i-->bestIndices[i]
                        //-------------------add found indices to FORBIDDEN 
                        forbidit=FORBIDDEN_INDEX_LIST.find( ac );
                        DEBUG("forbidding:"<<bestIndices[i]<<" for "<<ac<<"\n");
                        if (forbidit == FORBIDDEN_INDEX_LIST.end() ){
                         DEBUG(ac<<" was NOT there, now adding. \n");
                         unordered_set<int> pippo;
                                            pippo.insert(bestIndices[i]);
                         FORBIDDEN_INDEX_LIST.insert( std::pair<string, unordered_set<int> >(ac, pippo) );
                        } else {
                         forbidit->second.insert(bestIndices[i]);
                        }
                        DEBUG("BEST"<<particles.at(indices[i])->index<<" : "<<bestIndices[i]<<"@"<<indices[i] <<" type:"<<particles.at(indices[i])->type<<"  addr:"<<particles.at(indices[i]) <<" \n");
                    }
        } else{
                DEBUG("SearchN No negative index found... Returning evaluation as is.\n");
                double  leftval=left->evaluate(ao); // enabling this makes total 1min6s, without it 12s
                DEBUG("SearchN left:"<<leftval<<"\t");
                double rightval=right->evaluate(ao);
                DEBUG(" right:"<<rightval<<"\n");
                if (leftval == rightval) { return 1; }
                else { return 0;} // NGU TODO we should improve.
        }
        DEBUG("\n");
        return 1;
    }

    void SearchNode::Reset() {
            DEBUG("Clearing ForbiddenIndices on all names\t");
            for (std::map<string, unordered_set<int> >::iterator it=FORBIDDEN_INDEX_LIST.begin(); it!=FORBIDDEN_INDEX_LIST.end(); ++it){
             DEBUG( it->first << " clearing \n"); 
             it->second.clear();
            }
            bestIndices.clear();
            DEBUG("done.\n");
            left->Reset();//assuming right doesnt need a Reset because it's a value Node
    }

    void SearchNode::getParticles(std::vector<myParticle *>* particles) {
     left->getParticles(particles);
    }
    void SearchNode::getParticlesAt(std::vector<myParticle *>* particles, int index) {
        
    }

    SearchNode::~SearchNode() {
//        if (left!=NULL) delete left;
//        if (right!=NULL) delete right;
    }
//-------set particles
   void SearchNode::setParticles(std::vector<myParticle *>* bankParticles) {
     particles.clear();
     left->getParticles(&particles);//should fill with particles pointers no more cast needed
     int frombank=0;
     for(int i=0;i<particles.size();i++){
         DEBUG("Fill Part:"<<i<<"  idx:"<<particles.at(i)->index<< "  addr:"<<particles.at(i)<<" name:"<< particles.at(i)->collection<<"\n");
         if(particles.at(i)->index<0) {
                 particles.at(i)->index=bankParticles->at(frombank)->index;
                 frombank++;
                 DEBUG("Filled.\n");
         }
     }
   }

//---------------------------------------------------------------------general functions
double maxim( double difference, double current_difference){
    return (fabs(difference) > current_difference );
}

double minim( double difference, double current_difference){
    DEBUG("dif:"<<difference <<"  cur_diff:"<<current_difference<<"\n");
    return fabs(difference) < current_difference ;
}
