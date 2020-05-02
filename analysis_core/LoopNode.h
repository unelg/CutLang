//
//  LoopNode.h
//
//

#ifndef LoopNode_h
#define LoopNode_h
#include "Node.h"
#include <TRandom3.h>

//Looping over variables
class LoopNode : public Node{
private:
    double (*f)(std::vector<double>);
    std::vector<bool> (*g)(std::vector<double>);
    std::vector <Node*> lefs;
    TRandom3 rand3; 

protected:
    std::vector<myParticle*> inputParticles;

public:
    LoopNode(std::vector<bool> (*func)(std::vector<double>), Node* l, std::string s){
        g=func;
        f=NULL;
        symbol=s;
        left=l;
        lefs.push_back(l);
        right=NULL;
     //   rand3=new TRandom3();
    }
    LoopNode(double (*func)(std::vector<double>), Node* l, std::string s){
        f=func;
        g=NULL;
        symbol=s;
        left=l;
        lefs.push_back(l);
        right=NULL;
   //     rand3=new TRandom3();
    }
    LoopNode(double (*func)(std::vector<double>), std::vector<Node*> ls, std::string s){
        f=func;
        g=NULL;
        symbol=s;
        left=ls[0]; // just in case if someone asks the list of particles for example
        lefs=ls;
        right=NULL;
 //       rand3=new TRandom3();
    }
    
    static double getRand(); //{return (rand3.Uniform(0,1) );}
    virtual void getParticles(std::vector<myParticle *>* particles) override{
         left->getParticles(particles);
    }

    virtual void getParticlesAt(std::vector<myParticle *>* particles, int index) override{
        left->getParticlesAt(particles,index);
    }

    virtual void Reset() override{
        left->Reset();
    }

    virtual double evaluate(AnalysisObjects* ao) override;
    
    virtual ~LoopNode() {
        if (left!=NULL) delete left;
    }
    
};

double sumof(std::vector<double> xlist);
double minof(std::vector<double> xlist);
double maxof(std::vector<double> xlist);
std::vector<bool> hitmissA(std::vector<double> xlist);
std::vector<bool> hitmissR(std::vector<double> xlist);


#endif /* LoopNode_h */
