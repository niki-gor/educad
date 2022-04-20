#include "iostream"

int main(){
    int foo = 5;
    int bar = 5;
    int* toFoo = &foo;
    int* toBar = &bar;
    int* toFoo2 = &foo;
    std::cout << (toFoo == toBar) << std::endl;
    std::cout << (toFoo == toFoo2) << std::endl;
    std::cout << (*toFoo == *toBar) << std::endl;
}