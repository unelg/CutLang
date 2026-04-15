//
//  myParticle.h
//  mm
//
//  Created by Anna-Monica  on 8/2/18.
//  Copyright © 2018 Anna-Monica. All rights reserved.
//
#include <string>
#include <vector>

#ifndef myParticle_h
#define myParticle_h
struct myParticle{
    int type;
    int index;
    std::string collection;
    int reduce_mode = 0; // 0:none, 1:anyof, 2:allof
};

struct cntHisto {
 std::string cH_name;
 std::string cH_title;
 std::vector<float> cH_means;
 std::vector<float> cH_StatErr_p;
 std::vector<float> cH_StatErr_n;
 std::vector<float> cH_SystErr_p;
 std::vector<float> cH_SystErr_n;
 bool cH_StatErr;
 bool cH_SystErr;
};

#endif /* myParticle_h */
