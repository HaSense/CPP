#include <iostream>
#include <memory>
#include <vector>

// Abstract Product A
class Chair {
public:
    virtual ~Chair() {}
    virtual std::string getName() = 0;
};

// Concrete Product A
class VictorianChair : public Chair {
public:
    std::string getName() override {
        return "빅토리안 스타일 의자";
    }
};

// Concrete Product A
class ModernChair : public Chair {
public:
    std::string getName() override {
        return "현대식 스타일 의자";
    }
};

// Abstract Product B
class Sofa {
public:
    virtual ~Sofa() {}
    virtual std::string getName() = 0;
};

// Concrete Product B
class VictorianSofa : public Sofa {
public:
    std::string getName() override {
        return "빅토리안 소파";
    }
};

// Concrete Product B
class ModernSofa : public Sofa {
public:
    std::string getName() override {
        return "현대식 소파";
    }
};

// Abstract Product C
class CoffeeTable {
public:
    virtual ~CoffeeTable() {}
    virtual std::string getName() = 0;
};

// Concrete Product C
class VictorianCoffeeTable : public CoffeeTable {
public:
    std::string getName() override {
        return "빅토리안 커피 테이블";
    }
};

// Concrete Product C
class ModernCoffeeTable : public CoffeeTable {
public:
    std::string getName() override {
        return "모던 커피 테이블 ";
    }
};

// Abstract Factory
class FurnitureFactory {
public:
    virtual ~FurnitureFactory() {}
    virtual std::shared_ptr<Chair> createChair() = 0;
    virtual std::shared_ptr<Sofa> createSofa() = 0;
    virtual std::shared_ptr<CoffeeTable> createCoffeeTable() = 0;
};

// Concrete Factory - Victorian
class VictorianFurnitureFactory : public FurnitureFactory {
public:
    std::shared_ptr<Chair> createChair() override {
        return std::make_shared<VictorianChair>();
    }

    std::shared_ptr<Sofa> createSofa() override {
        return std::make_shared<VictorianSofa>();
    }

    std::shared_ptr<CoffeeTable> createCoffeeTable() override {
        return std::make_shared<VictorianCoffeeTable>();
    }
};

// Concrete Factory - Modern
class ModernFurnitureFactory : public FurnitureFactory {
public:
    std::shared_ptr<Chair> createChair() override {
        return std::make_shared<ModernChair>();
    }

    std::shared_ptr<Sofa> createSofa() override {
        return std::make_shared<ModernSofa>();
    }

    std::shared_ptr<CoffeeTable> createCoffeeTable() override {
        return std::make_shared<ModernCoffeeTable>();
    }
};

/*
 * createFurniture 함수를 클래스 내부에 정의하는 것도 가능하지만, 
 * 그럴 경우 FurnitureFactory 클래스가 선언되기 전에 createFurniture 함수가 정의되어야 한다. 
 * 따라서 함수를 외부로 빼는 것이 더 간단하고 직관적입니다. 
 * 
 * 추상 팩토리 패턴에서는 추상 팩토리 클래스와 구체적인 팩토리 클래스를 분리하는 것이 중요한데, 
 * 
 * 이를 위해서도 함수를 외부로 빼는 것이 좋다.
 */
void createFurniture(FurnitureFactory* factory) {
    std::shared_ptr<Chair> chair = factory->createChair();
    std::shared_ptr<Sofa> sofa = factory->createSofa();
    std::shared_ptr<CoffeeTable> coffeeTable = factory->createCoffeeTable();

    std::cout << chair->getName() << std::endl;
    std::cout << sofa->getName() << std::endl;
    std::cout << coffeeTable->getName() << std::endl;
}

int main()
{
    // Victorian style furniture
    std::unique_ptr<FurnitureFactory> victorianFactory = std::make_unique<VictorianFurnitureFactory>();
    std::cout << "빅토리안 스타일 가구 :" << std::endl;
    createFurniture(victorianFactory.get());
    std::cout << std::endl;

    // Modern style furniture
    std::unique_ptr<FurnitureFactory> modernFactory = std::make_unique<ModernFurnitureFactory>();
    std::cout << "현대 스타일 가구 :" << std::endl;
    createFurniture(modernFactory.get());

    return 0;
}
