/**
 * @file test_functional.cpp
 * @author Hongzhe Yu (hyu419@gatech.edu)
 * @brief 
 * @version 0.1
 * @date 2022-07-13
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "../include/lambda_class_function.h"

/// Test funcitonal with class members

/// example function
double function1(const double& b, Object obj){
    obj.printKeys();
    return b + obj.a_;
}

using Func1 = std::function<double(const double&, const Object&)>;
using A1 = A<Object>;

/// main function
int main()
{
    double a = 1.5;
    Object o1{gtsam::symbol('x', 5.5), a};

    A1 a1{function1, o1};

    a1.cost_function(2.5);

    a1.call_gh_function(3.5);
    return 0;

}