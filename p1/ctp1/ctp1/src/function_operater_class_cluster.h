//
//  function_operater_class_cluster.h
//  kqueueBasic
//
//  Created by Albert Tian on 13-4-25.
//  Copyright (c) 2013年 twk. All rights reserved.
//

#ifndef kqueueBasic_function_operater_class_cluster_h
#define kqueueBasic_function_operater_class_cluster_h

#include <cmath>

struct CalculatorFunctionor {
    virtual int operator()(int a, int b) {
        return a + b;
    }
};

struct MutilCalculator : public CalculatorFunctionor {
    int operator()(int a, int b) {
        return a * b;
    }
};

struct FactorialCalculator : public CalculatorFunctionor {
    int operator()(int a, int b) {
        return sqrt(a*a + b*b);
    }
};

template <typename TY1>
struct TempCalculator {
public:
    TY1 operator()(TY1 left, TY1 right) {
        return left + right;
    }
};


#endif
