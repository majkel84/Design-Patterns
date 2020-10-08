#pragma once

#include "Cook.hpp"

class FunghiPizza : public Cook {
    void setDough() { pizza_->setDough(Dough::FLUFFY); }
    void setSauce() { pizza_->setSauce(Sauce::GARLIC); }
    void setToppings() {
        pizza_->setToppings(Toppings::FUNGHI);
        pizza_->setToppings(Toppings::ONNION);
    }
    void setPrice() { pizza_->calculatePrice(); }
};