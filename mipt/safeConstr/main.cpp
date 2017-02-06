#include <iostream>
#include "safeConstr.h"


int main()
{
    B b1;
    try{
        B b(1);
        b1 = b;
    }catch(...){
        std::cout << "An error occured" << std::endl;
        return 1;
    }

    try{
        C c(2);
    }catch(...){
        b.~B();
        std::cout << "An error occured" << std::endl;
        return 1;
    }
    C c(2);
    try{
        A a(b, c);
    }catch(...){
        std::cout << "An error occured" << std::endl;
        return 1;
    }
    return 0;
}
