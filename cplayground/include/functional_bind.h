/**
 * @file functional_bind.h
 * @author Hongzhe Yu (hyu419@gatech.edu)
 * @brief 
 * @version 0.1
 * @date 2022-07-14
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/// Test the initiation problem in "functional_lambda_initializer.h".
/// std::bind seems not working.
 

#include <functional>

/// simulation of GH class
template <typename FunctionB, typename... Args>
class B{
    public:
    B(const FunctionB& func_, const double& b): _func{func_}, _b{b}{}

    FunctionB _func;
    double _b;

    void call_function(Args... args){
        _func(args...);
    }

    void update_function(const FunctionB& func){
        _func = func;
    } 
};


/// simulation of the optimizer class
template <typename FunctionA, typename... Args>
class A{
    public:
        A(const FunctionA& func_, const double& a, const double& b): 
        _funcb{func_},
        _b{b}, 
        _a{a},
        _func_b_bind{std::bind(&func_, _b, std::placeholders::_1)},
        _class_b{_func_b_bind, _a}
        {}

        FunctionA _funcb;
        double _b;
        double _a;

        B<std::function<double(const double&)>, const double&> _class_b;

        std::function<double(const double&)> _func_b_bind;

        void call_function(Args... args){
            _funcb(args...);
        }

        void call_func_b(const double& input){
            _class_b.call_function(input);
        }

        void update_b_func(){
            _class_b.update_function(_func_b_bind);
        }

};