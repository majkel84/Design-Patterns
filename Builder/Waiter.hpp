#pragma once

#include <iostream>
#include "Cook.hpp"
#include "Pizza.hpp"

class Waiter {
public:
    void prepareOrder(Cook* cook)
    {
        cook_ = cook;
        cook_->createNewPizza();
        cook_->setDough();
        cook_->setSauce();
        cook_->setToppings();
        cook_->setPrice();
    }
    size_t getPrice() { return cook_->getPizza()->getPrice(); }
private:
    Cook* cook_;
};