//
//  ValueNode.h
//  mm
//
//  Created by Anna-Monica  on 7/31/18.
//  Copyright © 2018 Anna-Monica. All rights reserved.
//

#ifndef ValueNode_h
#define ValueNode_h
#include "Node.h"
//takes care of integers and real values
class ValueNode :public Node{
private:
    double value;
public:
    ValueNode(double v=0){
                value=v;
                left=NULL;
                right=NULL;
                symbol=std::to_string(v);
            }
    
     virtual double evaluate() {
        return value;
    }
    
    virtual ~ValueNode() {}
};

#endif /* ValueNode_h */
