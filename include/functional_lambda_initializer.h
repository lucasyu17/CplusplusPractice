#include <functional>
#include <iostream>

using Function1 = std::function<double(const double&)>;
using namespace std;

template <typename Function>
class A {
    public:
        A(const Function& func_, const double& b_): 
        _b{b_}, 
        _f{func_},
        _f1{[this](const double &x){return _f(x, _b);}}
        {}

        Function _f;
        double _b;

        Function1 _f1;

        void call_f1(const double& x){
            cout << "calling f1" << endl << _f1(x) << endl;
        }
};