#include <iostream>
#include <memory>

class Car {
public:
    Car() {}
    virtual ~Car() {}

    virtual std::string get_brand() const = 0;
    virtual std::string get_model() const = 0;
    virtual int get_year() const = 0;
};

class CarBuilder {
public:
    CarBuilder() {}
    virtual ~CarBuilder() {}

    virtual void set_brand() = 0;
    virtual void set_model() = 0;
    virtual void set_year() = 0;
    virtual std::unique_ptr<Car> get_car() = 0;
};

class SportsCarBuilder : public CarBuilder {
private:
    std::unique_ptr<Car> m_car;

public:
    SportsCarBuilder() {}
    virtual ~SportsCarBuilder() {}

    virtual void set_brand() override {
        m_car->m_brand = "Ferrari";
    }

    virtual void set_model() override {
        m_car->m_model = "458 Spider";
    }

    virtual void set_year() override {
        m_car->m_year = 2012;
    }

    virtual std::unique_ptr<Car> get_car() override {
        return std::move(m_car);
    }
};

class CarManufacturingDirector {
public:
    CarManufacturingDirector() {}
    virtual ~CarManufacturingDirector() {}

    std::unique_ptr<Car> make_car(CarBuilder* builder) {
        builder->m_car = std::make_unique<Car>();
        builder->set_brand();
        builder->set_model();
        builder->set_year();
        return builder->get_car();
    }
};

int main() {
    CarManufacturingDirector car_manufacturing_director;

    std::unique_ptr<CarBuilder> sports_car_builder = std::make_unique<SportsCarBuilder>();
    std::unique_ptr<Car> sports_car = car_manufacturing_director.make_car(std::move(sports_car_builder));

    std::cout << "Sports car:" << std::endl;
    std::cout << "Brand: " << sports_car->get_brand() << std::endl;
    std::cout << "Model: " << sports_car->get_model() << std::endl;
    std::cout << "Year: " << sports_car->get_year() << std::endl;

    return 0;
}
