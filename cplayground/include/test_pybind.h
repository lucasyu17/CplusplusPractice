/**
 * @file test_pybind.h
 * @author Hongzhe Yu (hyu419@gatech.edu)
 * @brief Test pybind for stl containers of custom class
 * @version 0.1
 * @date 2022-07-24
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>

namespace cplayground{
    class PybindTest{
        public:
            PybindTest(){};
            PybindTest(const double & a):_a{a}{}

            double _a; 

            void sayHello(){
                std::cout << "Hello " << std::endl;
            }
    };
}
