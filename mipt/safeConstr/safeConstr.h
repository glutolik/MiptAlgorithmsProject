#include <iostream>
#include <memory>

class B {
private:
    int b;
public:
    B(int x) : b(x) {
        std::cout << "B constructed" << std::endl;
    }
    ~B() {
        std::cout << "B destructed" << std::endl;
    }
};

class C{
private:
    int c;
public:
    C(int y) : c(y) {
        std::cout << "C constructed" << std::endl;
    }
    ~C() {
        std::cout << "C destructed" << std::endl;
    }
};

class A{
private:
    std::shared_ptr<B> b;
    std::shared_ptr<C> c;
public:
    A(B l, C m) : b(new B(l)), c(new C(m)) {
        std::cout << "Constructor" << std::endl;
    }
    ~A() {
        std::cout << "Destructor" << std::endl;
    }

};
