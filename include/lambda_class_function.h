/**
 * @file lambda_class_function.h
 * @author Hongzhe Yu (hyu419@gatech.edu)
 * @brief 
 * @version 0.1
 * @date 2022-07-13
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/// Test the lambda expression in initiating std::function, and a nested class
/// We have a class A, class B, and class Object. Class A is initialized using function
/// f1=<double(double, Object)> and Object o1. B is nested inside A, having itself a function
/// f2=<double(double)>. We want to partially fix the parameter Object using that of A
/// to initialize the f2, and B.

#include <functional>
#include <gtsam/inference/Symbol.h>
#include <iostream>
using namespace std;

/// class Object, whic is needed in constructing the input function
class Object{
    public:
        Object(const gtsam::Key& key, double a):
        key_{key}, a_{a}{}

    public:
        gtsam::Key key_;
        double a_;

        double a(){
            return a_;
        }

        void printKeys(){
            cout << key_ << endl;
        }
        
};

/// nested class B
template <typename FunctionB>
class B{
    public:
        B(const FunctionB& _func, const double& other_param):
        func_{_func}, 
        param_{other_param}{}

    public:
        FunctionB func_;
        double param_;

        double cost_function(const double& x){
            cout << "finished function call in B..." << endl;
            return func_(x);
        }

        void update_function(const FunctionB& func){
            func_ = func;
        }

};

/// class A
template <typename CostClass>
class A{
    using FunctionA = std::function<double(const double&, const CostClass&)>;
    using FunctionB = std::function<double(const double&)>;
    public:
        A(FunctionA _function, CostClass _cost_class):
            cost_class_{_cost_class}, 
            func_{_function},
            func_b{[this](const double& x){return func_(x, cost_class_);}},
            _class_b{func_b, 1.0}{}

    public:
        CostClass cost_class_;
        FunctionA func_;
        FunctionB func_b;
        B<std::function<double(const double&)>> _class_b;

        double cost_function(double x){
            
            cout << "calling A cost function ..." << endl;
            double res{func_(x, cost_class_)};
            cout << res << endl;

            return func_(x, cost_class_);
        }

    /// Calling the cost function inside the nested class B, 
    /// with partially fixed argument cost_class_ 
    double call_gh_function(const double& x){
        cout << "calling gh cost function ..." << endl;
        double res{_class_b.cost_function(x)};
        cout << res << endl;
        return _class_b.cost_function(x);
    }
    
};

