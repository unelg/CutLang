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
#include <algorithm>  
#include <cassert>
#include <cstddef>
#include <cstdint>
#include <sstream>
#include <string>
#include <vector>
#include <onnxruntime_cxx_api.h>

template <typename T>
Ort::Value vec_to_tensor(std::vector<T>& data, const std::vector<std::int64_t>& shape) {
  Ort::MemoryInfo mem_info =
      Ort::MemoryInfo::CreateCpu(OrtAllocatorType::OrtArenaAllocator, OrtMemType::OrtMemTypeDefault);
  auto tensor = Ort::Value::CreateTensor<T>(mem_info, data.data(), data.size(), shape.data(), shape.size());
  return tensor;
}

class OMENode : public Node{
private:
      vector<Node*> variableList;
      vector<float> OME_input;
      short int selector;
public:
	OMENode(std::string s, short int sele, vector<Node*> VariableList){
        path_of_model=s;
        selector=sele;
		left = NULL;
		right = NULL;
        variableList = VariableList;
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
    
    virtual std::string print_shape(const std::vector<std::int64_t>& v) {
        std::stringstream ss("");
        for (std::size_t i = 0; i < v.size() - 1; i++) ss << v[i] << "x";
        ss << v[v.size() - 1];
        return ss.str();
    }

    virtual float OnnxModelEvaluator(std::basic_string<ORTCHAR_T> model_file, std::vector<float> input_data){
        Ort::Env env(ORT_LOGGING_LEVEL_WARNING, "OME_TEST");
        Ort::SessionOptions session_options;
        Ort::Session session = Ort::Session(env, model_file.c_str(), session_options);

        // print name/shape of inputs
        Ort::AllocatorWithDefaultOptions allocator;

        std::vector<std::string> input_names;
        std::vector<std::int64_t> input_shapes;
        std::cout << "Input Node Name/Shape (" << input_names.size() << "):" << std::endl;
        for (std::size_t i = 0; i < session.GetInputCount(); i++) {
            input_names.emplace_back(session.GetInputNameAllocated(i, allocator).get());
            input_shapes = session.GetInputTypeInfo(i).GetTensorTypeAndShapeInfo().GetShape();
            std::cout << "\t" << input_names.at(i) << " : " << print_shape(input_shapes) << std::endl;
            std::cout << "\t" << "Input name size: " << input_names.size() << std::endl;

        }
        // some models might have negative shape values to indicate dynamic shape, e.g., for variable batch size.
        for (auto& s : input_shapes) {
            if (s < 0) {
            s = 1;
            }
        }

        // print name/shape of outputs
        std::vector<std::string> output_names;
        std::cout << "Output Node Name/Shape (" << output_names.size() << "):" << std::endl;
        for (std::size_t i = 0; i < session.GetOutputCount(); i++) {
            output_names.emplace_back(session.GetOutputNameAllocated(i, allocator).get());
            auto output_shapes = session.GetOutputTypeInfo(i).GetTensorTypeAndShapeInfo().GetShape();
            std::cout << "\t" << output_names.at(i) << " : " << print_shape(output_shapes) << std::endl;
            std::cout << "\t" << "Output name size: " << output_names.size() << std::endl;
        }


        std::vector<Ort::Value> input_tensors;
        for(int i = 0; i < input_tensor_values.size(); i++){
            std::cout << input_data[i] << " , "; // modified this part! prints the input data.
        }

        input_tensors.emplace_back(vec_to_tensor<float>(input_data, input_shape));

        // double-check the dimensions of the input tensor
        assert(input_tensors[0].IsTensor() && input_tensors[0].GetTensorTypeAndShapeInfo().GetShape() == input_shape);
        std::cout << "\ninput_tensor shape: " << print_shape(input_tensors[0].GetTensorTypeAndShapeInfo().GetShape()) << std::endl;

        // pass data through model
        std::vector<const char*> input_names_char(input_names.size(), nullptr);
        std::transform(std::begin(input_names), std::end(input_names), std::begin(input_names_char),
                        [&](const std::string& str) { return str.c_str(); });

        std::vector<const char*> output_names_char(output_names.size(), nullptr);
        std::transform(std::begin(output_names), std::end(output_names), std::begin(output_names_char),
                        [&](const std::string& str) { return str.c_str(); });

        try {
            auto output_tensors = session.Run(Ort::RunOptions{nullptr}, input_names_char.data(), input_tensors.data(),
                                            input_names_char.size(), output_names_char.data(), output_names_char.size());
            //float* floatarr = output_tensors[0].GetTensorMutableData<float>();
            //std::cout << *floatarr << std::endl;
            

            float* output_data;

            for (size_t i = 0; i < output_tensors.size(); ++i) {
                Ort::Value& output_tensor = output_tensors[i];

                // Get the output tensor data pointer and shape
                output_data = output_tensor.GetTensorMutableData<float>();
                Ort::TensorTypeAndShapeInfo output_info = output_tensor.GetTensorTypeAndShapeInfo();
                std::vector<int64_t> output_shape = output_info.GetShape();

                // Print the output values
                std::cout << "Output " << i << ": \t" << *output_data << std::endl;
            }

            return output_data[0];

            
        } catch (const Ort::Exception& exception) {
            std::cout << "ERROR running model inference: " << exception.what() << std::endl;
            exit(-1);
        }
    };

    virtual void Reset() override{}


    virtual double evaluate(AnalysisObjects* ao) override {
           std::vector<myParticle *>  bparticles;
           std::vector<myParticle *> *aparticles=&bparticles;
            for (int i = 0; i < (int)variableList.size(); i++)
            {
                variableList[i]->getParticlesAt(aparticles,0);
                std::cout<< variableList[i]->evaluate(ao) << " , ";
                OME_input[i] = variableList[i]->evaluate(ao);
            }
            std::cout << "\n";
            OnnxModelEvaluator(path_of_model, OME_input);

            return 1;
        
    }
    virtual ~OMENode() {}
};

#endif // OMENode_h
