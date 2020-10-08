#pragma once

#include <vector>

enum class Dough {
    FLAT = 10,
    FLUFFY = 15
};

enum class Sauce {
    TOMATO = 1,
    GARLIC = 1
};

enum class Toppings {
    BASIL = 1,
    ONNION = 1,
    MOZARELLA = 2,
    FUNGHI = 2
};

class Pizza {
public:
    void setDough(const Dough dough) { dough_ = dough; }
    void setSauce(const Sauce sauce) { sauce_ = sauce; }
    void setToppings(const Toppings toppings) { toppings_.emplace_back(toppings); }
    void calculatePrice() {
        price_ += static_cast<size_t>(dough_);
        price_ += static_cast<size_t>(sauce_);
        for (const auto& it: toppings_) {
            price_ += static_cast<size_t>(it);
        }
    }
    size_t getPrice() { 
        return price_; }
private:
    Dough dough_;
    Sauce sauce_;
    std::vector<Toppings> toppings_;
    size_t price_ {};
};