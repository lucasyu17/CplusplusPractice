/**
 * @file test_changable_lambda.cpp
 * @author Hongzhe Yu (hyu419@gatech.edu)
 * @brief Test if lambda function will change with member variable.
 * @version 0.1
 * @date 2022-07-14
 * 
 * @copyright Copyright (c) 2022
 * 
 */


/// Function f2 is defined using f1 and a class member a, want to see if a will change 
/// with the class: Yes.

#include "../include/functional_lambda_initializer.h"

/// example functions 
double function1(const double& a){
    return 2*a;
}

double f(const double& a, const double& b){
    return a+b;
}


using Function = std::function<double(const double&, const double&)>;

int main(){
    A<Function> a{f, 2.5};

    /// expected: 12
    a.call_f1(9.5);

    /// change one variable _b
    a.set_b(4.5);

    /// expected: 14
    a.call_f1(9.5);

    return 0;
}