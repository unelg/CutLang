//  
//  OMENode.cpp
//  Created by 8/7/23.
//

#ifndef OMENode_cpp
#define OMENode_cpp
#include "OMENode.h"

#include <iostream>
#include <fstream>
#include <ios>
#include <stdio.h>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <sstream>


//#define _CLV_
#ifdef _CLV_
#define DEBUG(a) std::cout<<a
#else
#define DEBUG(a)
#endif

double OMENode::evaluate(AnalysisObjects* ao) {
           std::vector<myParticle *>  bparticles;
           std::vector<myParticle *> *aparticles=&bparticles;
           std::vector<double> NNvalues;
           input_tensor_values.clear();
           for (int i = 0; i < (int)variableList.size(); i++)
            {
//               std::cout<<i<<"\t";
                variableList[i]->getParticlesAt(aparticles,0); double pval=variableList[i]->evaluate(ao);
                    meanList[i]->getParticlesAt(aparticles,0); double aval=    meanList[i]->evaluate(ao);
                   sigmaList[i]->getParticlesAt(aparticles,0); double sval=   sigmaList[i]->evaluate(ao);
                   aparticles->clear();

//                  std::cout<<pval<<" - "<< aval<< " / "<<sval<<"\n";

                double outval=(pval-aval)/sval;

                input_tensor_values.push_back(outval);
//                std::cout<<i<<" val:"<< outval << "\n ";
            }
  auto input_shape = input_shapes;
  std::vector<Ort::Value> input_tensors;
  input_tensors.emplace_back(vec_to_tensor<float>(input_tensor_values, input_shape));
  // double-check the dimensions of the input tensor
  assert(input_tensors[0].IsTensor() && input_tensors[0].GetTensorTypeAndShapeInfo().GetShape() == input_shape);
  
  // pass data through model
  std::vector<const char*> input_names_char(input_names.size(), nullptr);
  std::transform(std::begin(input_names), std::end(input_names), std::begin(input_names_char),
                 [&](const std::string& str) { return str.c_str(); });

  std::vector<const char*> output_names_char(output_names.size(), nullptr);
  std::transform(std::begin(output_names), std::end(output_names), std::begin(output_names_char),
                 [&](const std::string& str) { return str.c_str(); });

  //std::cout << "Running model...\t" ;
  try {
    auto output_tensors = session->Run(Ort::RunOptions{nullptr}, input_names_char.data(), input_tensors.data(),
                                      input_names_char.size(), output_names_char.data(), output_names_char.size());
    float* floatarr = output_tensors.front().GetTensorMutableData<float>();
  //std::cout<<"Score:"<<floatarr[selector]<<"\n";
    return (double)floatarr[selector];
    // double-check the dimensions of the output tensors
    // NOTE: the number of output tensors is equal to the number of output nodes specifed in the Run() call
    assert(output_tensors.size() == output_names.size() && output_tensors[0].IsTensor());
  } catch (const Ort::Exception& exception) {
      std::cout << "ERROR running model inference: " << exception.what() << std::endl;
    exit(-1);
  }

    return 0;
    
};

#endif // OMENode_cpp
