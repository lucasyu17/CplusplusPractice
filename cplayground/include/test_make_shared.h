/**
 * @file test_make_shared.h
 * @author Hongzhe Yu (hyu419@gatech.edu)
 * @brief Test initialize shared_ptr member using a const reference, even within vector.
 * @version 0.1
 * @date 2022-07-24
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <boost/make_shared.hpp>
#include <boost/shared_ptr.hpp>


class A{
    public:
        A(const double& x):_x{x}{}

        double _x;

        double print_x(){
            return _x;
        }

};

class B{
    public:
        B(const A& a):_pa{boost::make_shared<A>(a)}{}
        boost::shared_ptr<A> _pa;

        double fb(){
            return _pa->print_x();
        }
};