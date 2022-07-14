#include <functional>

/// simulation of GH class
template <typename FunctionA, typename... Args>
class A{
    public:
    A(const FunctionA& func_, const double& a): _func{func_}, _a{a}{}

    FunctionA _func;
    double _a;

    void call_function(Args... args){
        _func(args...);
    }

    void update_function(const FunctionA& func){
        _func = func;
    } 
};


/// simulation of the optimizer class
template <typename FunctionB, typename... Args>
class B{
    public:
        B(const FunctionB& func_, const double& a, const double& b): 
        _funcb{func_},
        _b{b}, 
        _a{a},
        _func_a_bind{std::bind(&func_, _b, std::placeholders::_1)},
        _class_a{_func_a_bind, a}
        {}

        FunctionB _funcb;
        double _b;
        double _a;

        A<std::function<double(const double&)>, const double&> _class_a;

        std::function<double(const double&)> _func_a_bind;

        void call_function(Args... args){
            _funcb(args...);
        }

        void call_func_a(const double& input){
            _class_a.call_function(input);
        }

        void update_a_func(){
            _class_a.update_function(_func_a_bind);
        }

};