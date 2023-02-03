#include <iostream>
using namespace std;

class Animal{
public:
    //Animal(){}; //Default Constructor
    Animal(string name):name_(name){    //초기화 변수
        //name_ = name; //동일효과 발생
    }
    //간접접근 Getter
    string Name() const {
        return name_;
    }
private:
    string name_;
};

int main()
{
    Animal animal("동물");
    cout << animal.Name() << endl;
}

