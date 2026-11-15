// BDTNode.cpp

#include <algorithm>
#include <fstream>        
#include <iostream>
#include <set>       
#include <stdexcept>       

#include "TMVA/Tools.h"

#include "BDTNode.h"    



//#define _CLV_
#ifdef _CLV_
#define DEBUG(a) std::cout << a
#else
#define DEBUG(a)
#endif

namespace {

std::string stripQuotes(std::string s) {
    s.erase(std::remove(s.begin(), s.end(), '"'), s.end());
    return s;
}

// variable names in the order of Expression="..." entries in xml files
std::vector<std::string> readInputNames(const std::string& path) {
    std::ifstream in(path);
    if (!in) throw std::runtime_error("BDT: cannot open " + path);

    std::vector<std::string> names;
    const std::string key = "Expression=\"";
    for (std::string line; std::getline(in, line);) {
        auto start = line.find(key);
        if (start == std::string::npos) continue;
        start += key.size();
        names.push_back(line.substr(start, line.find('"', start) - start));
    }
    return names;
}

TMVA::Reader* loadReader(const std::string& path, const std::string& method,
                         const std::vector<std::string>& names,
                         std::vector<float>& values) {
    auto* reader = new TMVA::Reader("!Color:Silent");
    for (size_t i = 0; i < names.size(); ++i)
        reader->AddVariable(names[i], &values[i]);
    reader->BookMVA(method, path);
    return reader;
}

}  // namespace

BDTNode::BDTNode(const std::string& name,
                 const std::string& xml1, const std::string& xml2,
                 const std::string& method, const std::vector<Node*>& VariableList)
    : methodName(method), variableList(VariableList) {
    symbol = name;     // score name in adl
    left  = NULL;
    right = NULL;

    const std::string path1 = stripQuotes(xml1);
    const std::string path2 = stripQuotes(xml2);

    TMVA::Tools::Instance();

    input_names = readInputNames(path1);
    if (input_names.size() != variableList.size())
        throw std::runtime_error("BDT: model expects " + std::to_string(input_names.size()) +
                                 " inputs, got " + std::to_string(variableList.size()));

    input_values.assign(input_names.size(), 0.0f);
    model1 = loadReader(path1, methodName, input_names, input_values);
    if (!path2.empty())
        model2 = loadReader(path2, methodName, input_names, input_values);

    // adl is parsed once per region print the model and its inputs only first time
    static std::set<std::string> announced;
    if (announced.insert(name + "|" + path1 + "|" + path2).second) {
        std::cout << "BDTNode " << name << ": loaded " << path1;
        if (model2) std::cout << " (even) and " << path2 << " (odd)";
        else           std::cout << " (all events)";
        std::cout << "\n  inputs (index, xml name):\n";
        for (size_t i = 0; i < input_names.size(); ++i)
            std::cout << "    " << i << " " << input_names[i] << "\n";
        std::cout << std::flush;
    }
}

BDTNode::~BDTNode() {
    delete model1;
    delete model2;
}

void BDTNode::getParticles(std::vector<myParticle*>* particles) {
    std::vector<myParticle*> found;
    variableList[0]->getParticlesAt(&found, 0);
    particles->push_back(found[0]);
}

void BDTNode::getParticlesAt(std::vector<myParticle*>* particles, int index) {
    std::vector<myParticle*> found;
    variableList[0]->getParticlesAt(&found, 0);
    particles->push_back(found[index]);
}

double BDTNode::evaluate(AnalysisObjects* ao) {
    std::vector<myParticle*> found;
    for (size_t i = 0; i < variableList.size(); ++i) {
        variableList[i]->getParticlesAt(&found, 0);
        input_values[i] = static_cast<float>(variableList[i]->evaluate(ao));
        found.clear();
    }

    const bool useModel2 = model2 && (ao->evt.event_no % 2 == 1);
    TMVA::Reader* model = useModel2 ? model2 : model1;
    const double score = model->EvaluateMVA(methodName);

    DEBUG("BDT event " << ao->evt.event_no << " model="
          << (model2 ? (useModel2 ? "odd" : "even") : "single")
          << " score=" << score << " inputs:");
    for (size_t i = 0; i < input_values.size(); ++i) DEBUG(" " << input_values[i]);
    DEBUG("\n");
    return score;
}