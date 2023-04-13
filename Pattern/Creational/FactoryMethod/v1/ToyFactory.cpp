#include <iostream>
#include <string>
#include <vector>

// Product 클래스
class Toy {
public:
    virtual ~Toy() {}
    virtual std::string getName() = 0;
};

// Concrete Product 클래스
class TeddyBear : public Toy {
public:
    std::string getName() override {
        return "Teddy Bear";
    }
};

// Concrete Product 클래스
class Lego : public Toy {
public:
    std::string getName() override {
        return "Lego";
    }
};

// Creator 클래스
class ToyFactory {
public:
    virtual ~ToyFactory() {}
    virtual Toy* createToy() = 0;
};

// Concrete Creator 클래스
class TeddyBearFactory : public ToyFactory {
public:
    Toy* createToy() override {
        return new TeddyBear();
    }
};

// Concrete Creator 클래스
class LegoFactory : public ToyFactory {
public:
    Toy* createToy() override {
        return new Lego();
    }
};

int main() {
    // Creator 객체를 생성하고 Concrete Product 객체를 생성하는 메소드 호출
    std::vector<Toy*> toys;
    ToyFactory* teddyBearFactory = new TeddyBearFactory();
    Toy* teddyBear = teddyBearFactory->createToy();
    toys.push_back(teddyBear);

    ToyFactory* legoFactory = new LegoFactory();
    Toy* lego = legoFactory->createToy();
    toys.push_back(lego);

    // 생성된 객체 출력
    for (auto toy : toys) {
        std::cout << "We have a " << toy->getName() << std::endl;
    }

    // 메모리 해제
    delete teddyBearFactory;
    delete teddyBear;
    delete legoFactory;
    delete lego;

    return 0;
}
