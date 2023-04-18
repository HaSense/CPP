#include <iostream>

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
    Component* component_;

public:
    BaseDecorator(Component* component) : component_(component) {
    }
    std::string Execute() const override {
        return this->component_->Execute();
    }
};
class ConcreateDecoratorA : public BaseDecorator {
public:
    ConcreateDecoratorA(Component* component) : BaseDecorator(component) {
    }
    std::string Execute() const override {
        return "데코레이터A로 꾸미기(" + BaseDecorator::Execute() + ")";
    }
};
class ConcreateDecoratorB : public BaseDecorator {
public:
    ConcreateDecoratorB(Component* component) : BaseDecorator(component) {
    }
    std::string Execute() const override {
        return "데코레이터B로 꾸미기(" + BaseDecorator::Execute() + ")";
    }
};
void ClientCode(Component* component) {
    std::cout << "결과 : " << component->Execute();
}


int main()
{
    Component* simple = new ConcreteComponent;
    std::cout << "클라이언트: 기본 데코레이터 " << std::endl;
    ClientCode(simple);
    std::cout << std::endl << std::endl;

    //decorator
    Component* deco1 = new ConcreateDecoratorA(simple);
    Component* deco2 = new ConcreateDecoratorB(deco1);
    std::cout << "클라이언트: 데코레이터 처리된 버전" << std::endl;
    ClientCode(deco2);
    std::cout << std::endl;

    delete simple;
    delete deco1;
    delete deco2;

    return 0;
}

/*
클라이언트: 기본 데코레이터 
결과 : 기본 컴포넌트

클라이언트: 데코레이터 처리된 버전
결과 : 데코레이터B로 꾸미기(데코레이터A로 꾸미기(기본 컴포넌트))
*/




