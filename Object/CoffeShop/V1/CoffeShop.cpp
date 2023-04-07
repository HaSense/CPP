#include <iostream>
#include <string>

class Coffee {
public:
    explicit Coffee(const std::string& name) : name_(name) {}

    std::string getName() const {
        return name_;
    }

private:
    std::string name_;
};

class Customer {
public:
    explicit Customer(const std::string& name) : name_(name) {}

    void order(const std::string& coffeeName) {
        std::cout << name_ << "이(가) " << coffeeName << "를 주문합니다." << std::endl;
    }

    void receiveCoffee(const Coffee& coffee) {
        std::cout << name_ << "이(가) " << coffee.getName() << "를 받았습니다." << std::endl;
    }

private:
    std::string name_;
};

class Barista {
public:
    explicit Barista(const std::string& name) : name_(name) {}

    Coffee makeCoffee(const std::string& coffeeName) {
        std::cout << name_ << "이(가) " << coffeeName << "를 만듭니다." << std::endl;
        return Coffee(coffeeName);
    }

private:
    std::string name_;
};

int main() {
    Customer customer("손님");
    Barista barista("바리스타");

    // 손님은 커피를 주문한다.
    customer.order("아메리카노");

    // 바리스타는 커피를 만든다.
    Coffee coffee = barista.makeCoffee("아메리카노");

    // 손님은 커피를 받는다.
    customer.receiveCoffee(coffee);

    return 0;
}
