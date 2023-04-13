#include <iostream>
#include <string>

// Product 클래스
class Beverage {
public:
    virtual ~Beverage() {}
    virtual std::string getName() = 0;
    virtual double getPrice() = 0;
};

// Concrete Product 클래스
class Cola : public Beverage {
public:
    std::string getName() override {
        return "Coca-Cola";
    }

    double getPrice() override {
        return 2.0;
    }
};

// Concrete Product 클래스
class Fanta : public Beverage {
public:
    std::string getName() override {
        return "Fanta Orange";
    }

    double getPrice() override {
        return 2.5;
    }
};

// Creator 클래스
class BeverageFactory {
public:
    virtual ~BeverageFactory() {}
    virtual Beverage* createBeverage() = 0;
};

// Concrete Creator 클래스
class ColaFactory : public BeverageFactory {
public:
    Beverage* createBeverage() override {
        return new Cola();
    }
};

// Concrete Creator 클래스
class FantaFactory : public BeverageFactory {
public:
    Beverage* createBeverage() override {
        return new Fanta();
    }
};

int main() {
    // Creator 객체를 생성하고 Concrete Product 객체를 생성하는 메소드 호출
    BeverageFactory* factory = new ColaFactory();
    Beverage* beverage = factory->createBeverage();
    std::cout << "We have a " << beverage->getName() << " for " << beverage->getPrice() << " dollars" << std::endl;

    // 메모리 해제
    delete factory;
    delete beverage;

    factory = new FantaFactory();
    beverage = factory->createBeverage();
    std::cout << "We have a " << beverage->getName() << " for " << beverage->getPrice() << " dollars" << std::endl;

    // 메모리 해제
    delete factory;
    delete beverage;


    return 0;
}
