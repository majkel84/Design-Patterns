#pragma once

#include "Cook.hpp"

class MargheritaPizza : public Cook {
    void setDough() { pizza_->setDough(Dough::FLAT); }
    void setSauce() { pizza_->setSauce(Sauce::TOMATO); }
    void setToppings() {
        pizza_->setToppings(Toppings::MOZARELLA);
        pizza_->setToppings(Toppings::BASIL);
    }
    void setPrice() { pizza_->calculatePrice(); }
};