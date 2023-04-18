#include <iostream>
#include <memory>
#include <string>

class Beverage {
public:
    virtual ~Beverage() = default;

    virtual std::string getDescription() const {
        return description;
    }

    virtual double cost() const = 0;

protected:
    std::string description = "Unknown Beverage";
};

class CondimentDecorator : public Beverage {
public:
    virtual ~CondimentDecorator() = default;

    std::string getDescription() const override {
        return beverage->getDescription();
    }

protected:
    std::shared_ptr<Beverage> beverage;
};

class DarkRoast : public Beverage {
public:
    DarkRoast() {
        description = "Dark Roast Coffee";
    }

    double cost() const override {
        return 0.99;
    }
};

class Espresso : public Beverage {
public:
    Espresso() {
        description = "Espresso";
    }

    double cost() const override {
        return 1.99;
    }
};

class Mocha : public CondimentDecorator {
public:
    explicit Mocha(std::shared_ptr<Beverage> beverage) : CondimentDecorator() { // 변경된 부분
        this->beverage = beverage;
    }

    std::string getDescription() const override {
        return beverage->getDescription() + ", Mocha";
    }

    double cost() const override {
        return 0.20 + beverage->cost();
    }
};

class Whip : public CondimentDecorator {
public:
    explicit Whip(std::shared_ptr<Beverage> beverage) : CondimentDecorator() { // 변경된 부분
        this->beverage = beverage;
    }

    std::string getDescription() const override {
        return beverage->getDescription() + ", Whip";
    }

    double cost() const override {
        return 0.10 + beverage->cost();
    }
};
int main() {

    std::shared_ptr<Beverage> beverage = std::make_shared<Espresso>();
    std::cout << beverage->getDescription() << " $" << beverage->cost() << std::endl;

    std::shared_ptr<Beverage> beverage2 = std::make_shared<DarkRoast>();
    beverage2 = std::make_shared<Mocha>(beverage2);
    beverage2 = std::make_shared<Mocha>(beverage2);
    beverage2 = std::make_shared<Whip>(beverage2);
    std::cout << beverage2->getDescription() << " $" << beverage2->cost() << std::endl;

//    std::unique_ptr<Beverage> beverage3 = std::make_unique<HouseBlend>();
//    beverage3 = std::make_unique<Soy>(beverage3.get());
//    beverage3 = std::make_unique<Mocha>(beverage3.get());
//    beverage3 = std::make_unique<Whip>(beverage3.get());
//    std::cout << beverage3->getDescription() << " $" << beverage3->cost() << std::endl;

    return 0;
}
