/**
 * @file child_class.h
 * @author HONGZHE YU (hyu419@gatech.edu)
 * @brief 
 * @version 0.1
 * @date 2022-07-12
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/// Description: Add a tempate function to the base class in inheritance. 
/// The Function2 and Function use different types of input arguments. 
/// The way of extention is to instantiate the template related to the parent.


#include "base_class.h"
#include "functional"
// https://dengking.github.io/programming-language/C%2B%2B/STL/Utility-library/General-purpose/Common-vocabulary-types/std-tuple/TODO-murrayc-Modern-C%2B%2BVariadic-template-parameters-and-tuples/

using namespace std;
    
typedef std::function<double(const double&, const double&)> Func1;
typedef std::function<int(const double&, const double&)> Func2;

template <typename Function2, typename ... Args>
class ChildCost1 : public Base<Func1, const double&, const double&>
{

public:
    ChildCost1(const Func1& _func, const Function2& _func2):
    Base<Func1, const double&, const double&>{_func},
    func2_{_func2}{}
    
    void child_func(const double& a, const double& b, Args... args){
        base_func(a, b);

        cout << func2_(args ...) << endl;
    };

    Function2 func2_;
};


