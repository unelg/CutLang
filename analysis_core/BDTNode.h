#ifndef BDTNode_h
#define BDTNode_h

#include <string>
#include <vector>

#include "Node.h"
#include "TMVA/Reader.h"


// BDT score from given tmva weight files
// if single file given then used for every event
// if two file are given then even event numbers use first, odd event numbers second 
// The event number is taken from ao->evt.event_no.
class BDTNode : public Node {
private:
    std::string              methodName;     // TMVA method label BDTG
    std::vector<Node*>       variableList;   // input variables, in the order in xml file
    std::vector<std::string> input_names;    // variable names read in xml file 
    std::vector<float>       input_values;   // filled for each event read by tmva readers
    TMVA::Reader*            model1 = nullptr;   // first file, even events (all events if only single file)
    TMVA::Reader*            model2 = nullptr;   // second file, odd events

public:
    BDTNode(const std::string& name,
            const std::string& xml1, const std::string& xml2,
            const std::string& method, const std::vector<Node*>& VariableList);
    ~BDTNode();

    void   getParticles(std::vector<myParticle*>* particles) override;
    void   getParticlesAt(std::vector<myParticle*>* particles, int index) override;
    void   Reset() override {}
    double evaluate(AnalysisObjects* ao) override;
};

#endif