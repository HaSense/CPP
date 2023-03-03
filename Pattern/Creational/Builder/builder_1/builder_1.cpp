#include <iostream>
#include <string>
#include <memory>

using namespace std;

// Car 클래스
class Car {
protected:
    string m_brand;     // 브랜드
    string m_model;     // 모델명
    int m_year;         // 연식
    string m_engine;    // 엔진 타입

public:
    void set_brand(const string& brand) {
        m_brand = brand;
    }

    void set_model(const string& model) {
        m_model = model;
    }

    void set_year(int year) {
        m_year = year;
    }

    void set_engine(const string& engine) {
        m_engine = engine;
    }

    string to_string() const {
        return m_brand + " " + m_model + " (" + to_string(m_year) + "), " + m_engine;
    }
};

// Builder 인터페이스
class Builder {
protected:
    unique_ptr<Car> m_car;

public:
    Car* get_car() {
        return m_car.release();
    }

    void create_new_car() {
        m_car = make_unique<Car>();
    }

    virtual void set_brand() = 0;
    virtual void set_model() = 0;
    virtual void set_year() = 0;
    virtual void set_engine() = 0;
};

// SportsCarBuilder 클래스
class SportsCarBuilder : public Builder {
public:
    virtual void set_brand() override {
        m_car->set_brand("Ferrari");
    }

    virtual void set_model() override {
        m_car->set_model("488 Spider");
    }

    virtual void set_year() override {
        m_car->set_year(2022);
    }

    virtual void set_engine() override {
        m_car->set_engine("3.9L V8 Twin-Turbo");
    }
};

// SUVBuilder 클래스
class SUVBuilder : public Builder {
public:
    virtual void set_brand() override {
        m_car->set_brand("BMW");
    }

    virtual void set_model() override {
        m_car->set_model("X7");
    }

    virtual void set_year() override {
        m_car->set_year(2022);
    }

    virtual void set_engine() override {
        m_car->set_engine("4.4L V8 Twin-Turbo");
    }
};

// Director 클래스
class Director {
private:
    Builder* m_builder;

public:
    void set_builder(Builder* builder) {
        m_builder = builder;
    }

    Car* get_car() {
        return m_builder->get_car();
    }

    void construct_car() {
        m_builder->create_new_car();
        m_builder->set_brand();
        m_builder->set_model();
        m_builder->set_year();
        m_builder->set_engine();
    }
};

// 메인 함수
int main() {
    Director director;
    SportsCarBuilder sports_car_builder;
    SUVBuilder suv_builder;

    // 스포츠카 만들기
    director.set_builder(&sports_car_builder);
    director.construct_car();
    Car* sports_car = director.get_car();

    // SUV 만들기
    director.set_builder(&suv_builder);
    director.construct_car();
    Car* suv = director.get_car();

    // 결과 출력
    cout << "Sports car: " << sports_car->to_string() << endl;
    cout << "SUV: " << suv->to_string() << endl;

    delete sports_car;
    delete suv;

    return 0;
}
