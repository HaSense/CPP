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
    BeverageFactory* colaFactory = new ColaFactory();
    Beverage* cola = colaFactory->createBeverage();
    std::cout << "We have a " << cola->getName() << " for " << cola->getPrice() << " dollars" << std::endl;

    BeverageFactory* fantaFactory = new FantaFactory();
    Beverage* fanta = fantaFactory->createBeverage();
    std::cout << "We have a " << fanta->getName() << " for " << fanta->getPrice() << " dollars" << std::endl;

    // 메모리 해제
    delete colaFactory;
    delete cola;
    delete fantaFactory;
    delete fanta;

    return 0;
}
