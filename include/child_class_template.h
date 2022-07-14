/**
 * @file child_class_template.h
 * @author Hongzhe Yu (hyu419@gatech.edu)
 * @brief 
 * @version 0.1
 * @date 2022-07-12
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/// Extending a parent class with a new template in the child class,
/// without instantiating the parent templates.


#include "base_class.h"
#include "functional"

using namespace std;
    
typedef std::function<double(const double&, const double&)> Func1;
typedef std::function<int(const double&, const double&)> Func2;

template <typename Func1, typename Class1, typename ... Args>
class ChildCostTemplate1 : public Base<Func1, double, double>
{

public:
    ChildCostTemplate1(const Func1& _func, const Class1& _class1):
    Base<Func1, double, double>{_func},
    class1_{_class1}{}
    
    void child_func(const double& a, const double& b, Args... args){
        Base<Func1, double, double>::base_func(a, b);

    };

    Class1 class1_;
};
