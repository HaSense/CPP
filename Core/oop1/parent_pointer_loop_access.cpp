#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Shape
{
public:
    virtual void Draw(){
        cout << "도형을 그리다." << endl;
    }
};
class Triangle : public Shape
{
public:
    void Draw() override {
        cout << "삼각형을 그리다." << endl;
    }
};
class Rectangle : public Shape
{
public:
    void Draw() override {
        cout << "사각형을 그리다." << endl;
    }    
};
class Circle : public Shape
{
public:
    void Draw() override {
        cout << "원을 그리다." << endl;
    }    
};

int main()
{
    
    vector<Shape*> shapes;
    shapes.push_back(new Triangle());
    shapes.push_back(new Rectangle());
    shapes.push_back(new Circle());

    for (auto shape : shapes) {
        shape->Draw();
    }

    // 메모리 해제
    for (auto shape : shapes) {
        delete shape;
    }
    shapes.clear();
    return 0;
}




