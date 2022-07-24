/**
 * @file virtual_overload.h
 * @author Hongzhe Yu (hyu419@gatech.edu)
 * @brief Test the virtual functions in class inheritance
 * @version 0.1
 * @date 2022-07-15
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>

using namespace std;

class Base{
    public:
        Base(double a):_a{a}{}

        double _a;

        inline void base_func(){
            cout << "base a" << endl << _a << endl;
        }
};

class Derived: public Base{
    public:
        Derived(double a, double b):Base(a),_b{b}{
            _a = b;
            _b = _a;
        }

        double _b;

        void b(){
            cout << "child b" << endl << _b << endl;
        }
};