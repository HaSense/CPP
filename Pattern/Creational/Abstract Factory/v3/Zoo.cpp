#include <iostream>
#include <memory>

class Animal {
public:
    virtual void speak() = 0;
};

class Lion : public Animal {
public:
    void speak() override {
        std::cout << "크앙~ 울부짓다." << std::endl;
    }
};

class Elephant : public Animal {
public:
    void speak() override {
        std::cout << "뿌우우~~ 소리치다" << std::endl;
    }
};

class Zookeeper {
public:
    virtual void manage() = 0;
};

class LionKeeper : public Zookeeper {
public:
    void manage() override {
        std::cout << "사자들을 관리합니다." << std::endl;
    }
};

class ElephantKeeper : public Zookeeper {
public:
    void manage() override {
        std::cout << "코끼리들을 관리합니다." << std::endl;
    }
};

class AbstractZooFactory {
public:
    virtual std::unique_ptr<Animal> createAnimal() = 0;
    virtual std::unique_ptr<Zookeeper> createZookeeper() = 0;
};

class LionFactory : public AbstractZooFactory {
public:
    std::unique_ptr<Animal> createAnimal() override {
        return std::make_unique<Lion>();
    }

    std::unique_ptr<Zookeeper> createZookeeper() override {
        return std::make_unique<LionKeeper>();
    }
};

class ElephantFactory : public AbstractZooFactory {
public:
    std::unique_ptr<Animal> createAnimal() override {
        return std::make_unique<Elephant>();
    }

    std::unique_ptr<Zookeeper> createZookeeper() override {
        return std::make_unique<ElephantKeeper>();
    }
};

int main() {
    std::unique_ptr<AbstractZooFactory> lionFactory = std::make_unique<LionFactory>();
    std::unique_ptr<Animal> lion = lionFactory->createAnimal();
    std::unique_ptr<Zookeeper> lionKeeper = lionFactory->createZookeeper();

    lion->speak();
    lionKeeper->manage();

    std::unique_ptr<AbstractZooFactory> elephantFactory = std::make_unique<ElephantFactory>();
    std::unique_ptr<Animal> elephant = elephantFactory->createAnimal();
    std::unique_ptr<Zookeeper> elephantKeeper = elephantFactory->createZookeeper();

    elephant->speak();
    elephantKeeper->manage();

    return 0;
}
