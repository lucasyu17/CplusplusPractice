/**
 * @file test_inheritance_template.cpp
 * @author your name (you@domain.com)
 * @brief Extending a parent class by a new template in the child class.
 * @version 0.1
 * @date 2022-07-15
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "../include/child_class_template.h"

class CostClass{
    public:
        CostClass(double a):a_{a}{}
        double a_;
};

class CostClass1{
    public:
        CostClass1(double b):b_{b}{}
        double b_;
};

double func1(const double& a, const double&b){
    return a+b;
}

double func2( const double& c, const CostClass & a, const CostClass1 & b){
    return a.a_ + b.b_ + c;
}


int main(){

    double a = 1.5, b = 2.5, c = 3.5;
    CostClass cl_a{a};
    CostClass1 cl_b{b};
    
    ChildCostTemplate1<CostClass, CostClass1> child_template{func2, cl_a, cl_b, 10.0};
    child_template.child_func(c);

    child_template.base_function();
    return 0;
}
