#pragma once

#include <memory>
#include "Pizza.hpp"

class Cook {
public:
    virtual ~Cook() {}
    void createNewPizza() { pizza_ = std::make_unique<Pizza>(); }
    virtual void setDough() = 0;
    virtual void setSauce() = 0;
    virtual void setToppings() = 0;
    virtual void setPrice() = 0;
    Pizza* getPizza(){ return pizza_.release(); }
protected:
    std::unique_ptr<Pizza> pizza_;
};