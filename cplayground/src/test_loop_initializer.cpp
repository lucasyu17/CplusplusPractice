/**
 * @file test_loop_initializer.cpp
 * @author Hongzhe Yu (hyu419@gatech.edu)
 * @brief 
 * @version 0.1
 * @date 2022-07-14
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/// Decription: Initializing a vector of a specific class A in a for loop, The class constructor
/// accepts a temporary object B, b, and a function f. 
/// This test wants to see whether the b will maintained outside the for loop.

#include "../include/lambda_class_function.h"

/// example function
double function1(const double& b, Object obj){
    obj.printKeys();
    return b + obj.a_;
}

using Func1 = std::function<double(const double&, const Object&)>;
using A1 = A<Object>;
using namespace std;

/// The collection class
class A1Collection{
    public:
        A1Collection(const vector<std::shared_ptr<A1>>& vec_a1):_vec_a1{vec_a1}{

        }

        vector<std::shared_ptr<A1>> _vec_a1;

        void interative_call(){
            for (int k=0; k< _vec_a1.size(); k++){

            std::shared_ptr<A1> a1_k = _vec_a1[k];
            a1_k->call_gh_function(2.0);
            }
        }
};

int main(){ 

    vector<std::shared_ptr<A1>> vec_as;

    for (int i=0; i<10; i++){
        double a = i*2.0;

        Object o1{gtsam::symbol('x', i), a};

        /// try with unique pointer
        std::shared_ptr<A1> pA1(new A1{function1, o1});

        vec_as.emplace_back(pA1);

    }

    A1Collection a1_collection{vec_as};

    a1_collection.interative_call();

    return 0;
}