#include <iostream>
#include <memory>

class Component {
public:
    virtual ~Component() {}
    virtual std::string Execute() const = 0;
};

class ConcreteComponent : public Component {
public:
    std::string Execute() const override {
        return "기본 컴포넌트";
    }
};

class BaseDecorator : public Component {
protected:
    std::shared_ptr<Component> component_;

public:
    BaseDecorator(std::shared_ptr<Component> component) : component_(component) {
    }
    std::string Execute() const override {
        return this->component_->Execute();
    }
};

class ConcreateDecoratorA : public BaseDecorator {
public:
    ConcreateDecoratorA(std::shared_ptr<Component> component) : BaseDecorator(component) {
    }
    std::string Execute() const override {
        return "데코레이터A(" + BaseDecorator::Execute() + ")";
    }
};

class ConcreateDecoratorB : public BaseDecorator {
public:
    ConcreateDecoratorB(std::shared_ptr<Component> component) : BaseDecorator(component) {
    }
    std::string Execute() const override {
        return "데코레이터B(" + BaseDecorator::Execute() + ")";
    }
};

void ClientCode(const std::shared_ptr<Component>& component) {
    std::cout << "결과 : " << component->Execute();
}

int main()
{
    std::shared_ptr<Component> simple = std::make_shared<ConcreteComponent>();
    std::cout << "클라이언트: 기본 데코레이터 " << std::endl;
    ClientCode(simple);
    std::cout << std::endl << std::endl;

    //decorator
    std::shared_ptr<Component> deco1 = std::make_shared<ConcreateDecoratorA>(simple);
    std::shared_ptr<Component> deco2 = std::make_shared<ConcreateDecoratorB>(deco1);
    std::cout << "클라이언트: 데코레이터 사용된 컴포넌트 \n";
    ClientCode(deco2);
    std::cout << std::endl;

    return 0;
}

/*
클라이언트: 기본 데코레이터 
결과 : 기본 컴포넌트

클라이언트: 데코레이터 사용된 컴포넌트 
결과 : 데코레이터B(데코레이터A(기본 컴포넌트))

*/
