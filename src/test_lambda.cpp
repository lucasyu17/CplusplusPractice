#include "../include/functional_lambda_initializer.h"


double function1(const double& a){
    return 2*a;
}

double f(const double& a, const double& b){
    return a+b;
}
using Function = std::function<double(const double&, const double&)>;

int main(){
    A<Function> a{f, 2.5};

    a.call_f1(9.5);

    return 0;
}