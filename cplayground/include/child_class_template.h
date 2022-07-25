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

/// Extending a parent class by a new template in the child class.


#include "functional"
#include <iostream>

using namespace std;

template <typename Function, typename CostClass>
class Base
{
public:
    /* data */
    Function _function;
    CostClass _cost_class;
    double _db;
    
public:
    Base(const Function& _func, const CostClass& cost_class, const double& db):
    _function{_func},
    _cost_class{cost_class},
    _db{db}{}

    void base_function(){
        cout << "base function" << endl << _db << endl;
    }

};
    
using Function2 = std::function<double(const double&)>;
template <typename CostClass, typename Class1, typename ... Args>
/// making the cost function type explicit
class ChildCostTemplate1 : public Base<std::function<double(const double&, const CostClass&, const Class1&)>, CostClass>
{
    /// Alias
using Function = std::function<double(const double&, const CostClass&, const Class1&)>;
using Basealias = Base<Function, CostClass>;
public:
    ChildCostTemplate1(const Function& func, const CostClass& cost_class, const Class1& class1, const double& db):
    Basealias(func, cost_class, db), // base class constructor
    _class1{class1}, // new cost class
    _dc{Basealias::_db},
    _func2{[this](const double& x){return Basealias::_function(x-Basealias::_db, Basealias::_cost_class, _class1);}} // new function
    {}
    
    void child_func(const double& x){
        double res = _func2(x); 
        cout << "res in child template" << endl << res << endl;
    }


protected:
    Class1 _class1;
    double _dc;
    Function2 _func2;

};
