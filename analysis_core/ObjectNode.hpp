//
//  ObjectNode.hpp
//  mm
//
//  Created by Anna-Monica  on 8/16/18.
//  Copyright © 2018 Anna-Monica. All rights reserved.
//

#ifndef ObjectNode_hpp
#define ObjectNode_hpp
#include <vector>
#include <stdio.h>
#include "Node.h"
using namespace std;
//takes care of user defined objects
class ObjectNode : public Node{
    private:
        //not sure if we need to use it---------ObjectNode* previous;
        vector<Node*> criteria;
        //still need to add something to save the modifed AO
        std::vector<myParticle *> particles;//used to collect particle pointers to be changed
    protected:
        void (* createNewSet) (AnalysisObjects* ao,vector<Node*> *criteria,std::vector<myParticle *>* particles);
    public:
        string name;
        ObjectNode(string id,Node* previous, 
        void (* func) (AnalysisObjects* ao,vector<Node*>* criteria,
        std::vector<myParticle *>* particles ), vector<Node*> criteria,  
        std::string s );
        
        virtual void Reset() override;
        
        virtual void getParticles(std::vector<myParticle *>* particles) override;
        virtual void getParticlesAt(std::vector<myParticle *>* particles, int index) override;
        virtual double evaluate(AnalysisObjects* ao) override;
        
        virtual ~ObjectNode();
};

void createNewJet (AnalysisObjects* ao,vector<Node*> *criteria,std::vector<myParticle *>* particles);
void createNewEle (AnalysisObjects* ao,vector<Node*> *criteria,std::vector<myParticle *>* particles);
void createNewMuo (AnalysisObjects* ao,vector<Node*> *criteria,std::vector<myParticle *>* particles);
void createNewPho (AnalysisObjects* ao,vector<Node*> *criteria,std::vector<myParticle *>* particles);
#endif /* ObjectNode_hpp */
