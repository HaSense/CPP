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

// Customer 인터페이스
class Customer {
public:
    virtual ~Customer() = default;
    virtual void order(const std::string& coffeeName) = 0;
    virtual void receiveCoffee(const Coffee& coffee) = 0;
};

// GeneralCustomer 클래스: Customer 인터페이스를 구현
class GeneralCustomer : public Customer {
public:
    explicit GeneralCustomer(const std::string& name) : name_(name) {}

    void order(const std::string& coffeeName) override {
        std::cout << name_ << "이(가) " << coffeeName << "를 주문합니다." << std::endl;
    }

    void receiveCoffee(const Coffee& coffee) override {
        std::cout << name_ << "이(가) " << coffee.getName() << "를 받았습니다." << std::endl;
    }

private:
    std::string name_;
};

// Barista 인터페이스
class Barista {
public:
    virtual ~Barista() = default;
    virtual Coffee makeCoffee(const std::string& coffeeName) = 0;
};

// ProfessionalBarista 클래스: Barista 인터페이스를 구현
class ProfessionalBarista : public Barista {
public:
    explicit ProfessionalBarista(const std::string& name) : name_(name) {}

    Coffee makeCoffee(const std::string& coffeeName) override {
        std::cout << name_ << "이(가) " << coffeeName << "를 만듭니다." << std::endl;
        return Coffee(coffeeName);
    }

private:
    std::string name_;
};

int main() {
    Customer* customer = new GeneralCustomer("손님");
    Barista* barista = new ProfessionalBarista("바리스타");

    // 손님은 커피를 주문한다.
    customer->order("아메리카노");

    // 바리스타는 커피를 만든다.
    Coffee coffee = barista->makeCoffee("아메리카노");

    // 손님은 커피를 받는다.
    customer->receiveCoffee(coffee);

    delete customer;
    delete barista;

    return 0;
}
