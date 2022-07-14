// #include "../include/child_class.h"
// #include "../include/child_class_extended.h"
#include "../include/child_class_template.h"
#include <functional>

using namespace std;

double func1(const double& a, const double&b){
    return a+b;
}

int func2(const double & a, const double & b){
    return int(a-b);
}

double func3(const double & a, const double & b){
    return a*b;
}

class CostClass{
    public:
    CostClass(int a):a_{a}{}
    int a_;
};


int main()
{
    double a_0=1.5, b_0=2.5;
    typedef std::function<double(const double&, const double&)> Func1;
    typedef std::function<int(const double&, const double&)> Func2;

    // ChildCost2<Func2, double, double> childcost2(func1, func2, func3);
    // childcost2.child_func(a_0, b_0, a_0, b_0);

    /// Test the inheritance without instantiate the parent templates, but adding a new template directly.
    CostClass cost_class(1);
    ChildCostTemplate1<Func1, CostClass, double, double> childcosttemplate{func1, cost_class};
    return 0;
}
