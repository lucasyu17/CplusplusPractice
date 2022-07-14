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

/// Test the lambda expression in initiating the std::function with a class member variable.
#include <functional>
#include <gtsam/inference/Symbol.h>
#include <iostream>
using namespace std;

/// simulation of the cost class
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

/// simulation of class Gauss-Hermite
template <typename FunctionGH, typename ... Args>
class GH{
    public:
        GH(const FunctionGH& _func, const double& other_param):
        func_{_func}, 
        param_{other_param}{}

    public:
        FunctionGH func_;
        double param_;

        void cost_function(Args... args){
            func_(args...);
            cout << "finished function call..." << endl;
        }

        void update_function(const FunctionGH& func){
            func_ = func;
        }

};

/// simulation of the optimizer class
template <typename Function, typename CostClass, typename ... Args>
class A{
  public:
    
    A(Function _function, CostClass _cost_class):
    cost_class_{_cost_class}, 
    func_{_function},
    // func_phi{_function},
    gh_{_function, 1.0}{}

    Function func_;
    CostClass cost_class_;
    // std::function<double(const double&, const CostClass&)> func_phi;
    GH<std::function<double(const double&, const CostClass&)>, CostClass> gh_;

    double cost_function(double bb){
        func_(bb, cost_class_);
    }
    
};

