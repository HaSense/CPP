#include <iostream>
#include <memory>

class Strategy {
public:
    virtual ~Strategy() {}
    virtual double execute(int a, int b) = 0;
};

class Addition : public Strategy {
public:
    double execute(int a, int b) override {
        return a + b;
    }
};

class Subtraction : public Strategy {
public:
    double execute(int a, int b) override {
        return a - b;
    }
};

class Multiplication : public Strategy {
public:
    double execute(int a, int b) override {
        return a * b;
    }
};

class Division : public Strategy {
public:
    double execute(int a, int b) override {
        if (b == 0) {
            throw std::invalid_argument("division by zero");
        }
        return (double)a / (double)b;
    }
};

class Calculator {
public:
    Calculator() : strategy(nullptr) {}

    void set_strategy(std::unique_ptr<Strategy> s) {
        strategy = std::move(s);
    }

    double execute(int a, int b) {
        if (!strategy) {
            throw std::runtime_error("strategy not set");
        }
        return strategy->execute(a, b);
    }

private:
    std::unique_ptr<Strategy> strategy;
};


int main() {
    Calculator calculator;
    calculator.set_strategy(std::make_unique<Addition>());

    int a = 10;
    int b = 3;

    std::cout << "a + b = " << calculator.execute(a, b) << std::endl;

    calculator.set_strategy(std::make_unique<Subtraction>());
    std::cout << "a - b = " << calculator.execute(a, b) << std::endl;

    calculator.set_strategy(std::make_unique<Multiplication>());
    std::cout << "a * b = " << calculator.execute(a, b) << std::endl;

    calculator.set_strategy(std::make_unique<Division>());
    std::cout << "a / b = " << calculator.execute(a, b) << std::endl;

    return 0;
}
