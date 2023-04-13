#include <iostream>
#include <memory>

// 상품 추상 클래스
class Product {
public:
    virtual void info() const = 0;
};

class Laptop : public Product {
public:
    virtual void info() const override {
        std::cout << "노트북: ";
    }
};

class Phone : public Product {
public:
    virtual void info() const override {
        std::cout << "핸드폰: ";
    }
};

// 공장 추상 클래스
class Factory {
public:
    virtual std::unique_ptr<Laptop> createLaptop() = 0;
    virtual std::unique_ptr<Phone> createPhone() = 0;
};

class SamsungLaptop : public Laptop {
public:
    void info() const override {
        Laptop::info();
        std::cout << "삼성 노트북" << std::endl;
    }
};

class SamsungPhone : public Phone {
public:
    void info() const override {
        Phone::info();
        std::cout << "삼성 핸드폰" << std::endl;
    }
};

class SamsungFactory : public Factory {
public:
    std::unique_ptr<Laptop> createLaptop() override {
        return std::make_unique<SamsungLaptop>();
    }

    std::unique_ptr<Phone> createPhone() override {
        return std::make_unique<SamsungPhone>();
    }
};

class AppleLaptop : public Laptop {
public:
    void info() const override {
        Laptop::info();
        std::cout << "애플 노트북" << std::endl;
    }
};

class ApplePhone : public Phone {
public:
    void info() const override {
        Phone::info();
        std::cout << "애플 핸드폰" << std::endl;
    }
};

class AppleFactory : public Factory {
public:
    std::unique_ptr<Laptop> createLaptop() override {
        return std::make_unique<AppleLaptop>();
    }

    std::unique_ptr<Phone> createPhone() override {
        return std::make_unique<ApplePhone>();
    }
};

void testFactory(Factory& factory) {
    auto laptop = factory.createLaptop();
    auto phone = factory.createPhone();

    laptop->info();
    phone->info();
}

int main() 
{
    SamsungFactory samsungFactory;
    AppleFactory appleFactory;

    testFactory(samsungFactory);
    testFactory(appleFactory);
    
    
 /*  아래는 함수를 따로 만들지 않고 main에서만 테스트 할때 코드 */ 
//     SamsungFactory samsungFactory;
//     AppleFactory appleFactory;

//     auto samsungLaptop = samsungFactory.createLaptop();
//     auto samsungPhone = samsungFactory.createPhone();

//     auto appleLaptop = appleFactory.createLaptop();
//     auto applePhone = appleFactory.createPhone();

//     samsungLaptop->info();
//     samsungPhone->info();
//     appleLaptop->info();
//     applePhone->info();

    return 0;
}
