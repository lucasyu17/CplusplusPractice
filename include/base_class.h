#include <iostream>

template <typename Function, typename ...Args>
class Base
{
public:
    /* data */
    Function function_;
    
public:
    Base(const Function& _func):function_{_func}{}

    void base_func(Args... args){
        auto result = function_(args...);
        std::cout << result << std::endl;
    }
};
