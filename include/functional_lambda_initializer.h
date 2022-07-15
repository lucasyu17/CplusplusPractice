/**
 * @file functional_lambda_initializer.h
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

#include <functional>
#include <iostream>

using Function1 = std::function<double(const double&)>;
using namespace std;

template <typename Function>
class A {
    public:
        A(const Function& func_, const double& b_): 
        _b{b_}, 
        _f{func_},
        _f1{[this](const double &x){return _f(x, _b);}}
        {}

        Function _f;
        double _b;

        Function1 _f1;

        void call_f1(const double& x){
            cout << "calling f1" << endl << _f1(x) << endl;
        }

        void set_b(const double& b){
            _b = b;
        }
};