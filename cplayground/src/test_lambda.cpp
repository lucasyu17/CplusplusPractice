/**
 * @file test_lambda.cpp
 * @author Hongzhe Yu (hyu419@gatech.edu)
 * @brief 
 * @version 0.1
 * @date 2022-07-14
 * 
 * @copyright Copyright (c) 2022
 * 
 */


/// Test initiating a class member function using an input function and lambda expression.

/// f1<c(a,b)> -> f2<c(a)>
/// We can fix the argument b using another class member variable in the constructor.

/// https://stackoverflow.com/questions/72974425/how-to-initialize-a-stdfunction-using-stdbind

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

    a.call_f1(9.5);

    return 0;
}