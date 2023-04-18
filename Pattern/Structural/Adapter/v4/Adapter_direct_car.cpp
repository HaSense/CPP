#include <iostream>
#include <memory>

using namespace std;

// Car interface
class Car {
public:
    virtual ~Car() = default;
    virtual void start() const = 0;
    virtual void drive() const = 0;
};

// ElectricCar concrete implementation
class ElectricCar : public Car {
public:
    void start() const override {
        cout << "전기 모터 시작" << endl;
    }

    void drive() const override {
        cout << "전기차 운전" << endl;
    }
};

// InternalCombustionCar interface
class InternalCombustionCar {
public:
    virtual ~InternalCombustionCar() = default;
    virtual void igniteEngine() const = 0;
    virtual void accelerate() const = 0;
};

// InternalCombustionCar concrete implementation
class GasolineCar : public InternalCombustionCar {
public:
    void igniteEngine() const override {
        cout << "가솔린 엔진 점화" << endl;
    }

    void accelerate() const override {
        cout << "가솔린 차 가속" << endl;
    }
};

// Adapter class to adapt InternalCombustionCar interface to Car interface
class InternalCombustionCarAdapter : public Car {
private:
    shared_ptr<InternalCombustionCar> icCar_;

public:
    InternalCombustionCarAdapter(shared_ptr<InternalCombustionCar> icCar) : icCar_(icCar) {}

    void start() const override {
        icCar_->igniteEngine();
    }

    void drive() const override {
        icCar_->accelerate();
    }
};

void testCar(const shared_ptr<Car> &car) {
    car->start();
    car->drive();
}

int main() {
    shared_ptr<ElectricCar> electricCar = make_shared<ElectricCar>();
    shared_ptr<GasolineCar> gasolineCar = make_shared<GasolineCar>();
    shared_ptr<Car> icCarAdapter = make_shared<InternalCombustionCarAdapter>(gasolineCar);

    cout << "전기차가 동작 시작..." << endl;
    testCar(electricCar);

    cout << "\n가솔린차 동작 시작..." << endl;
    testCar(icCarAdapter);

    return 0;
}

/*
전기차가 동작 시작...
전기 모터 시작
전기차 운전

가솔린차 동작 시작...
가솔린 엔진 점화
가솔린 차 가속
*/
