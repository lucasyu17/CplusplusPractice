/**
 * @file child_class_extended.h
 * @author HONGZHE YU (hyu419@gatech.edu)
 * @brief 
 * @version 0.1
 * @date 2022-07-12
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/// Extend the child class ChildCost1 with another cost, Function3. The way of extention is to instantiate the template related to the parent.


#include "child_class.h"

using namespace std;
    
typedef std::function<double(const double&, const double&)> Func1;
typedef std::function<int(const double&, const double&)> Func2;

template <typename Function3, typename ... Args>
class ChildCost2 : public ChildCost1<Func2, const double&, const double&>
{

public:
    ChildCost2(const Func1& _func, const Func2& _func2, const Function3& _func3):
    ChildCost1<Func2, const double&, const double&>{_func, _func2},
    func3_{_func3}{}
    
    void child_func(const double& a, const double& b, Args... args){
        base_func(a, b);
        cout << func2_(a, b) << endl;
        cout << func3_(args ...) << endl;
    };

private:
    Function3 func3_;
};


