#include "../include/test_static_instantiate_class.h"
#include <iostream>
#include <memory>

int main(){

    B b{1.5};
    std::cout << "b.function(2.5)" << std::endl << b.function(2.5) << std::endl;
    std::cout << "b._b" << std::endl << b._b << std::endl;
    

    /// shared pointer
    std::shared_ptr<B> pb{new B{2.1}};
    std::cout << "pb->function(3.5)" << std::endl << pb->function(3.5) << std::endl;
    std::cout << "pb->_b" << std::endl << pb->_b << std::endl;
    
    return 0;

}