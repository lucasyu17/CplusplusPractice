#include "../include/virtual_overload.h"

int main(){

    Base a{1.5};

    Derived b{1.5, 5.5};

    b.base_func();

    b.b();
    
    return 0;
}