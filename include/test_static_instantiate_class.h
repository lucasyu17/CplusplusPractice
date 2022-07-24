/**
 * @file test_static_instantiate_class.h
 * @author Hongzhe Yu (hyu419@gatech.edu)
 * @brief Test using a static function to initialize a functor 
 * declared in the parent class.
 * @version 0.1
 * @date 2022-07-24
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <functional>

template <typename Function>
class A{
    public:
        A(Function f): _f{f}{}

        Function _f;

        double f_A(const double & x){
            return _f(x);
        }
};

typedef std::function<double(const double&)> Fun;
typedef A<Fun> AFunc;

class B: public AFunc{
    public:
        B(const double& b):AFunc{function}, _b{b}{}

        double _b;

        static double function(const double & x){
            return x;
        }
};