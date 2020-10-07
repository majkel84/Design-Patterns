## BUILDER DESIGN PATERN
---


#### Basic assumptions
---
On of the creative patterns.
Separate the construction of complex object from it's representation.
The process of creating an objects is divided into several smaller stages and each of these stages can be implemented in many ways.
Such a solutions helps to create different representations of objects in the same construction process.


#### Overview
---
Problems solved by builder design patern:
* How can a class of the same construction process crate diffrent representations,
* How can a complex object creation be simplified,
* It's impossible to change object representation without changing the class,
* Encapsulate creating and assembly of complex object in separate Builder class,
* Base class delegates object creation to builder class instead of creating object directly.


#### Class diagram
---
Pattern consists of basis classes as:
* Client - use patern to create director, order an object,
* Director - refers to Builder interface for building part of complex object,
* Builder - abstract interface for creating objects,
* Concrete Builder - provides implementation for Builder, it's an object able to construct other objects. 
![Builder UML](Builder_UML.png)


#### Advantages
---
* Allow to vary a product's internal representation,
* Encapsulate code for construction and representation,
* Provides control over steps of construction process.


#### Disadvantages
---
* Require create separate Concrete Builder for each type of object,
* Requires the builder classes to be mutable,
* Dependancy injection may be less support.


#### Sample implementation
---
We'll try to explain on simple example pizzeria.

##### Customer (ordering pizza)
```
class PizzaCustomer {
    Waiter waiter;
    MargheritaPizza  margherita;
    FunghiPizza funghi;

    waiter.prepareOrder(&margherita);
    waiter.prepareOrder(&funghi);
}
```

##### Director (takes an order)
```
class Waiter {
public:
    void makePizza(pizzaBuilder* cook)
    :cook_(cook) {
        cook_->createNewPizza();
        cook_->buildDough();
        cook_->buildSauce();
        cook_->buildToppings();
    }
    Pizza getPizza() { return cook_->getPizza(); }
private:
    Cook* cook_;
}
```

##### Abstract builder (prepar product for order)
```
class Cook {
public:
    virtual ~Cook() {}
    Pizza* getPizza() { return pizza_.release(); }
    void createNewPizza() { pizza_ = make_unique<Pizza>(); }
    virtual void buildDough() = 0;
    virtual void buildSauce() = 0;
    virtual void buildTop()   = 0;
protected:
    std::unique_ptr<Pizza> pizza_;
}
```

##### Product (Pizza)
```
class Pizza {
public:
    void setDough(const Dough dough) { dough_ = dough; }
    void setSauce(const Sauce sauce) { sauce_ = sauce; }
    void setToppings(const Toppings toppings) { toppings_.emplace_back(toppings); }
    void setPrice() { /* to be continue */ }
private:
    Dough dough_; // Dough might be enum class
    Sauce sauce_; //Sauce might be enum class
    std::vector<Toppings> toppings_; //Toppings might be enum class
}
```

##### ConcreteBuilder (Margherita Pizza)
```
class MargheritaPizza : public Cook {
    virtual void setDough() { pizza_->setDough(Dough::FLAT); }
    virtual void setSauce() { pizza_->setSauce(Sauce::TOMATO); }
    virtual void setToppings() { pizza_->setTopping(Toppings::MOZARELLA); }
    virtual void setToppings() { pizza_->setTopping(Toppings::BASIL } 
}
```

##### ConcreteBuilder (Funghi Pizza)
```
class FunghiPizza : public Cook {
    virtual void setDough() { pizza_->setDough(Dough::FLUFFY); }
    virtual void setSauce() { pizza_->setSauce(Sauce::GARLIC); }
    virtual void setToppings() { pizza_->setTopping(Toppings::FUNGHI); }
    virtual void setToppings() { pizza_->setTopping(Toppings::ONNION } 
}
```

