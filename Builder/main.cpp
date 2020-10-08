#include <iostream>
#include <typeinfo>
#include "FunghiPizza.hpp"
#include "MargheritaPizza.hpp"
#include "Waiter.hpp"

int main() {
    std::cout << "Welcom in Tratoria CODERS!\n";
    Waiter waiter;
    MargheritaPizza  margherita;
    FunghiPizza funghi;

    waiter.prepareOrder(&margherita);
    std::cout << typeid(margherita).name() << " " << waiter.getPrice() << "PLN\n";
    waiter.prepareOrder(&funghi);
    std::cout << typeid(funghi).name() << " " << waiter.getPrice() << "PLN\n";
    
    return 0;
}