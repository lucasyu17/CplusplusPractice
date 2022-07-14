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

double function1(const double& a){
    cout << "function 1" << endl << 2*a << endl;
    return 2*a;
}

double function2(const double& a, const double& b){
    cout << "function 2" << endl << a+b << endl;
    return a+b;
}

using FunctionA = std::function<double(const double&)>;
using FunctionB = std::function<double(const double&, const double&)>;


int main(){

    FunctionA func1 = std::bind(&function2, 1.5, std::placeholders::_1);
    func1(2.5);

    A<FunctionA, double> a1(function1, 1.0);
    B<FunctionB, double, double> b1 = B<FunctionB, double, double>{function2, 15, 2.5};

    // b1.update_a_func();

    // b1.call_func_a(2.5);

    

    return 0;
}

