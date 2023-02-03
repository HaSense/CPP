#include <iostream>
using namespace std;

class Animal
{
public:
    //Animal(){}; //Default Constructor
    Animal(string name):name_(name){    //초기화 변수
        //name_ = name; //동일효과 발생
    }
    //간접접근 Getter
    string Name() const {
        return name_;
    }

    virtual void Speak() const {
        cout << "동물이 말하다." << endl;
    }

private:
    string name_;
};

class Dog : public Animal 
{
    public:
        Dog(string name): Animal(name){}
        void Speak() const override{
            cout << "멍멍~!!!" << endl;
        }
};
int main()
{
    Animal animal("동물");
    cout << animal.Name() << endl;

    Dog bbobbi("뽀삐");
    bbobbi.Speak();

}



