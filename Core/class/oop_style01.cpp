#include <iostream>
using namespace std;

class Cat
{
    public:
        Cat(string name, string color):name_(name), color_(color){}
        //Getter
        string Name(){
            return name_;
        }
        string Color(){
            return color_;
        }
        //virtual
        virtual string Speak() = 0; //순수가상함수
    private:
        string name_;
        string color_;

};
class Persian : public Cat
{
    public:
        Persian(string name, string color):Cat(name, color){}
        string Speak() override {
            return "야옹~~!";
        }
    private:
};

class Dog
{
    public:
        Dog(string name, string color):name_(name), color_(color){}
        //Getter
        string Name(){
            return name_;
        }
        string Color(){
            return color_;
        }
        //virtual
        virtual string Speak() = 0; //순수가상함수
    private:
        string name_;
        string color_;

};
class Bulldog : public Dog
{
    public:
        Bulldog(string name, string color):Dog(name, color){}
        string Speak() override {
            return "멍멍~~!";
        }
    private:
};

int main()
{
    Persian kitti("키티", "하얀색"), bbomi("뽀미", "회색");
    cout << kitti.Name() << ":" << kitti.Color() << endl;
    cout << kitti.Speak() << endl;

    Bulldog tomy("토미", "검은색"), kaltok("칼톡", "회백색");
    cout << tomy.Name() << ":" << tomy.Color() << endl;
    cout << tomy.Speak() << endl;

    return 0;
}

/* 출력
키티:하얀색
야옹~~!
토미:검은색
멍멍~~!

*/
