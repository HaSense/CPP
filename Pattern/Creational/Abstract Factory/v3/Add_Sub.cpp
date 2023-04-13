#include <iostream>
#include <memory>

// Abstract Product A
class Operation {
public:
    virtual ~Operation() {}

    virtual int getResult(int a, int b) = 0;
};

// Concrete Product A
class Addition : public Operation {
public:
    int getResult(int a, int b) override {
        return a + b;
    }
};

// Concrete Product A
class Subtraction : public Operation {
public:
    int getResult(int a, int b) override {
        return a - b;
    }
};

// Abstract Factory
class CalculatorFactory {
public:
    virtual ~CalculatorFactory() {}

    virtual std::unique_ptr<Operation> createOperation() = 0;
};

// Concrete Factory
class AdditionFactory : public CalculatorFactory {
public:
    std::unique_ptr<Operation> createOperation() override {
        return std::make_unique<Addition>();
    }
};

// Concrete Factory
class SubtractionFactory : public CalculatorFactory {
public:
    std::unique_ptr<Operation> createOperation() override {
        return std::make_unique<Subtraction>();
    }
};

int main() {
    // Create Addition Calculator
    std::unique_ptr<CalculatorFactory> additionFactory = std::make_unique<AdditionFactory>();
    std::unique_ptr<Operation> addition = additionFactory->createOperation();
    std::cout << "1 + 2 = " << addition->getResult(1, 2) << std::endl;
    // Create Subtraction Calculator
    std::unique_ptr<CalculatorFactory> subtractionFactory = std::make_unique<SubtractionFactory>();
    std::unique_ptr<Operation> subtraction = subtractionFactory->createOperation();
    std::cout << "5 - 3 = " << subtraction->getResult(5, 3) << std::endl;

    return 0;
}
