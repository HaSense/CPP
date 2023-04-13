#include <iostream>
#include <memory>

class Shape {
public:
    virtual void draw() const = 0;
};

class Circle : public Shape {
public:
    void draw() const override {
        std::cout << "Drawing a circle." << std::endl;
    }
};

class Rectangle : public Shape {
public:
    void draw() const override {
        std::cout << "Drawing a rectangle." << std::endl;
    }
};

int main() {
    // Using unique_ptr
    std::unique_ptr<Shape> circle = std::make_unique<Circle>();
    std::unique_ptr<Shape> rectangle = std::make_unique<Rectangle>();

    circle->draw();
    rectangle->draw();

    // Using shared_ptr
    std::shared_ptr<Shape> sharedCircle = std::make_shared<Circle>();
    std::shared_ptr<Shape> sharedRectangle = std::make_shared<Rectangle>();

    sharedCircle->draw();
    sharedRectangle->draw();

    return 0;
}
