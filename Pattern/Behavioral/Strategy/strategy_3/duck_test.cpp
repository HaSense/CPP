#include <iostream>

#include <iostream>

// Strategy Interface
class FlyBehavior {
public:
    virtual void fly() = 0;
};

// Concrete Strategies
class FlyWithWings : public FlyBehavior {
public:
    void fly() override {
        std::cout << "I'm flying with wings!\n";
    }
};

class FlyNoWay : public FlyBehavior {
public:
    void fly() override {
        std::cout << "I can't fly!\n";
    }
};

// Strategy Interface
class QuackBehavior {
public:
    virtual void quack() = 0;
};

// Concrete Strategies
class Quack : public QuackBehavior {
public:
    void quack() override {
        std::cout << "Quack! Quack!\n";
    }
};

class Squeak : public QuackBehavior {
public:
    void quack() override {
        std::cout << "Squeak! Squeak!\n";
    }
};

class MuteQuack : public QuackBehavior {
public:
    void quack() override {
        std::cout << "<< Silence >>\n";
    }
};

// Context
class Duck {
public:
    Duck(FlyBehavior* flyBehavior, QuackBehavior* quackBehavior)
        : m_flyBehavior(flyBehavior), m_quackBehavior(quackBehavior) {}

    void performFly() {
        m_flyBehavior->fly();
    }

    void performQuack() {
        m_quackBehavior->quack();
    }

    void swim() {
        std::cout << "All ducks float, even decoys!\n";
    }

    virtual void display() = 0;

    virtual ~Duck() {
        delete m_flyBehavior;
        delete m_quackBehavior;
    }

private:
    FlyBehavior* m_flyBehavior;
    QuackBehavior* m_quackBehavior;
};

// Concrete Contexts
class MallardDuck : public Duck {
public:
    MallardDuck()
        : Duck(new FlyWithWings(), new Quack()) {}

    void display() override {
        std::cout << "I'm a real Mallard duck!\n";
    }
};

class RubberDuck : public Duck {
public:
    RubberDuck()
        : Duck(new FlyNoWay(), new Squeak()) {}

    void display() override {
        std::cout << "I'm a rubber duck!\n";
    }
};

// Client
int main() {
    Duck* mallard = new MallardDuck();
    Duck* rubberDuckie = new RubberDuck();

    mallard->display();
    mallard->performQuack();
    mallard->performFly();

    rubberDuckie->display();
    rubberDuckie->performQuack();
    rubberDuckie->performFly();

    delete mallard;
    delete rubberDuckie;

    return 0;
}
