#include <iostream>
#include <memory> //smart pointer 
using namespace std;

class Car {
public:
    //멤버함수
    Car(){
        this->speed_ = 0;
    }
    Car(int speed):speed_(speed){
    }
    int Speed(){
        return speed_;
    }
    //멤버변수
private:
        int speed_;
};

int main()
{
    //Stack 생성
    Car myCar(), myCar2(100);
    cout << myCar2.Speed() << endl;

    //Heap 생성
    Car *myCar3 = new Car(200);
    cout << myCar3->Speed() << endl;
    delete myCar3;

    //Heap 생성 C++11 smart_pointer
    std::unique_ptr<Car> myCar4 = std::make_unique<Car>(300);
    cout << myCar4->Speed() << endl;
    //delete가 없어도 객체를 메모리에서 알아서 해제해줌
    return 0;
}
