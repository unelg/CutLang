//  
//  OMENode.h
//  Created by 8/7/23.
//

#ifndef OMENode_h
#define OMENode_h
#include "Node.h"

#include <iostream>
#include <fstream>
#include <ios>
#include <stdio.h>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <sstream>

#include <algorithm>  
#include <cassert>
#include <cstddef>
#include <cstdint>
#include <onnxruntime_cxx_api.h>
#include <coreml_provider_factory.h>

template <typename T>
Ort::Value vec_to_tensor(std::vector<T>& data, const std::vector<std::int64_t>& shape) {
  Ort::MemoryInfo mem_info =
      Ort::MemoryInfo::CreateCpu(OrtAllocatorType::OrtArenaAllocator, OrtMemType::OrtMemTypeDefault);
  auto tensor = Ort::Value::CreateTensor<T>(mem_info, data.data(), data.size(), shape.data(), shape.size());
  return tensor;
}


class OMENode : public Node{
private:
      std::vector<Node*> variableList;
      std::vector<Node*>     meanList;
      std::vector<Node*>    sigmaList;
      short int selector;
      std::vector<float> input_tensor_values;
      std::vector<std::string> input_names;
      std::vector<std::int64_t> input_shapes;
      std::vector<std::string> output_names;
//
      Ort::Session *session;
public:
	OMENode(std::string s, short int sele, std::vector<Node*> VariableList, std::vector<Node*> aVariableList, std::vector<Node*> sVariableList){
        symbol=s;
        selector=sele;
	left = NULL;
	right = NULL;
        variableList = VariableList;
          meanList=aVariableList;
         sigmaList=sVariableList;

//-------------------------------ONNX
        std::vector<float> uservals;
        symbol.erase(remove( symbol.begin(), symbol.end(), '\"' ), symbol.end());
        std::basic_string<ORTCHAR_T> model_file = symbol;
        Ort::Env env(ORT_LOGGING_LEVEL_ERROR, "onnx-model-executer");
        Ort::SessionOptions session_options;
        uint32_t coreml_flags = 0;
//           coreml_flags |= COREML_FLAG_ONLY_ENABLE_DEVICE_WITH_ANE;
//           coreml_flags |= COREML_FLAG_ENABLE_ON_SUBGRAPH;
             coreml_flags |= COREML_FLAG_USE_CPU_ONLY;

        Ort::ThrowOnError(OrtSessionOptionsAppendExecutionProvider_CoreML(session_options, coreml_flags));
        session = new Ort::Session(env, model_file.c_str(), session_options);

        Ort::AllocatorWithDefaultOptions allocator;

        for (std::size_t i = 0; i < session->GetInputCount(); i++) {
          input_names.emplace_back(session->GetInputNameAllocated(i, allocator).get());
          input_shapes = session->GetInputTypeInfo(i).GetTensorTypeAndShapeInfo().GetShape();
        }
// some models might have negative shape values to indicate dynamic shape, e.g., for variable batch size.
        for (auto& s : input_shapes) {
          if (s < 0) {
            s = 1;
          }
        }
//output
        for (std::size_t i = 0; i < session->GetOutputCount(); i++) {
          output_names.emplace_back(session->GetOutputNameAllocated(i, allocator).get());
          auto output_shapes = session->GetOutputTypeInfo(i).GetTensorTypeAndShapeInfo().GetShape();
         std::cout << "\t" << output_names.at(i) <<"\n";
// verbose    std::cout << "\t" << output_names.at(i) << " : " << print_shape(output_shapes) << std::endl;
        }


        // Assume model has 1 input node and 1 output node.
         assert(input_names.size() == 1 && output_names.size() == 1);
}
    virtual void getParticles(std::vector<myParticle *>* particles) override{
                 std::vector<myParticle *>  bparticles;
                 std::vector<myParticle *> *aparticles=&bparticles;
                 variableList[0]->getParticlesAt(aparticles,0);
                  particles->push_back(bparticles[0]);
                 }
    virtual void getParticlesAt(std::vector<myParticle *>* particles,int index) override{
                 std::vector<myParticle *>  bparticles;
                 std::vector<myParticle *> *aparticles=&bparticles;
                 variableList[0]->getParticlesAt(aparticles,0);
                  particles->push_back(bparticles[index]);
                 }
    
    virtual void Reset() override{}


    virtual double evaluate(AnalysisObjects* ao) override ;

    virtual ~OMENode() {}
};

#endif // OMENode_h
