/**
 * @file test_bind.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-13
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/// Test std::bind

#include "../include/functional_bind.h"
#include <iostream>

using namespace std;

double functionb(const double& a){
    cout << "function 1" << endl << 2*a << endl;
    return 2*a;
}

double functiona(const double& a, const double& b){
    cout << "function 2" << endl << a+b << endl;
    return a+b;
}

using FunctionB = std::function<double(const double&)>;
using FunctionA = std::function<double(const double&, const double&)>;


int main(){

    FunctionB func1 = std::bind(&functiona, 1.5, std::placeholders::_1);
    func1(2.5);

    /// Bind dose not work.
    // B<FunctionB, double> b1(functionb, 1.0);
    // A<FunctionA, double, double> a1 = A<FunctionA, double, double>{functiona, 15, 2.5};

    // b1.update_a_func();

    // b1.call_func_a(2.5);

    

    return 0;
}

