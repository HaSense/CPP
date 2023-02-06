#include <iostream>
#include <memory> //smart pointer 사용 시 
using namespace std;

class Cat
{
    public:
        Cat() { }
        Cat(string name) { }
        Cat(string name, string color):name_(name), color_(color){}
        //Getter
        string Name(){
            return name_;
        }
        string Color(){
            return color_;
        }
        //virtual
        virtual string Speak() {}; 
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

int main()
{
    //Stack에 객체생성
    Persian kitti("키티", "하얀색");
    cout << kitti.Name() << ":" << kitti.Color() << endl;
    cout << kitti.Speak() << endl;
    //Heap에 객체생성
    Persian *bbomi = new Persian("뽀미", "회색");
    cout << bbomi->Name() << ":" <<bbomi->Color() << endl;
    delete bbomi;
    //Heap에 객체생성, smart pointer를 이용하여 자동 메모리 해제, 메모리 누수방지
    std::unique_ptr<Cat> tom = std::make_unique<Cat>("톰", "노란색");
    cout << tom->Name() << ":" << tom->Color() << endl; 
    return 0;
}
