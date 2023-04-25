#include <iostream>
#include <map>
#include <memory>
#include <string>

//FlyWeight 클래스
class Car {         
public:
    virtual ~Car() = default;
    virtual void printDetails() const = 0;
};
//ConCrete FlyWeight
class ConcreteCar : public Car {
    std::string color_;
    std::string brand_;

public:
    ConcreteCar(const std::string& color, const std::string& brand) : color_(color), brand_(brand) {}
    void printDetails() const override {
        std::cout << "Car: Color: " << color_ << ", Brand: " << brand_ << std::endl;
    }
};

//FlyWeight Factory 클래스
class CarFactory {
    std::map<std::pair<std::string, std::string>, std::shared_ptr<Car>> cars_;

public:
    std::shared_ptr<Car> getCar(const std::string& color, const std::string& brand) {
        auto key = std::make_pair(color, brand);
        auto car = cars_.find(key);
        if (car == cars_.end()) {
            std::shared_ptr<Car> newCar = std::make_shared<ConcreteCar>(color, brand);
            cars_[key] = newCar;
            return newCar;
        }
        return car->second;
    }
};

//Context 클래스
class CarOwnerContext {
    std::shared_ptr<Car> car_;
    std::string owner_;

public:
    CarOwnerContext(const std::string& owner, std::shared_ptr<Car> car) : owner_(owner), car_(car) {}
    void printDetails() const {
        std::cout << "Owner: " << owner_ << ", ";
        car_->printDetails();
    }
};

//테스트를 위한 메인함수
int main() {
    CarFactory carFactory;

    auto car1 = carFactory.getCar("Red", "Toyota");
    auto car2 = carFactory.getCar("Blue", "Honda");
    auto car3 = carFactory.getCar("Red", "Toyota");

    CarOwnerContext owner1("Alice", car1);
    CarOwnerContext owner2("Bob", car2);
    CarOwnerContext owner3("Charlie", car3);

    owner1.printDetails();
    owner2.printDetails();
    owner3.printDetails();

    return 0;
}

/*
Instance: 부분은 일부러 적은 것 코드결과랑은 상관이 없다.ㅑ

1. 패턴을 사용하지 않은 경우
Owner: Alice, Car: Color: Red, Brand: Toyota                  Instance: 1
Owner: Bob, Car: Color: Blue, Brand: Honda                    Instance: 2
Owner: Charlie, Car: Color: Red, Brand: Toyota                Instance: 3

2. 패턴을 적용한 경우
Owner: Alice, Car: Color: Red, Brand: Toyota                  Instance: 1
Owner: Bob, Car: Color: Blue, Brand: Honda                    Instance: 2
Owner: Charlie, Car: Color: Red, Brand: Toyota                Instance: 1


*/
