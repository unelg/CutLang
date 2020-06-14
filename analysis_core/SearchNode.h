#ifndef SearchNode_h
#define SearchNode_h

#include <stdio.h>
#include <math.h>
#include <list>
#include <unordered_set>
#include "myParticle.h"
#include "Node.h"


using namespace std;

//takes care of Minimizing/Maximizing
class SearchNode : public Node{
private:
    static std::map< std::string, unordered_set<int> > FORBIDDEN_INDEX_LIST;
    double (*f)(double, double);
    vector<int> bestIndices;
    std::vector<myParticle *> particles;//pointers to particles in all nodes that have to be changed
    void performInnerOperation(vector<int> *v,vector<int> *indices, double *current_difference,AnalysisObjects* ao);
    void runNestedLoopBarb( int start, int N, int level, int maxDepth, vector<int> *v,vector<int> *indices,double *curr_diff,AnalysisObjects* ao, int type, string ac);
    void runNestedLoopRec ( int start, int N, int level, int maxDepth, vector<int> *v,vector<int> *indices,double *curr_diff,AnalysisObjects* ao, int type, string ac);


public:
    SearchNode(double (*func)(double, double), Node* l, Node* r, std::string s);
    virtual double evaluate(AnalysisObjects* ao) override;
    virtual void Reset() override;
    virtual void setParticles(std::vector<myParticle *>* particles);
    virtual void getParticles(std::vector<myParticle *>* particles) override;
    virtual void getParticlesAt(std::vector<myParticle *>* particles, int index) override;
    virtual ~SearchNode() ;

};

double maxim( double difference, double current_difference);
double minim( double difference, double current_difference);

#endif
