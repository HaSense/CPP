#include <iostream>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <ctime>
using namespace std;

class Car
{
    public: //지시자
    //1.멤버 변수
    int speed;
    string brand;
    string color;
    //2.생성자(디폴트 생성자 생략가능)
    Car() {     
    }
    Car(int _speed){
        speed = _speed;  
    }
    Car(string brand){
        this->brand = brand;
    }
    Car(string _brand, int _speed, string _color) {
        brand = _brand;
        speed = _speed;
        color = _color;
    }
    //3.멤버 메소드
};

int main() 
{
    Car myCar; //Stack에 생성
    Car *myCar2 = new Car(); //Heap에 객체 생성, 첫번째 생성자로 객체생성
    Car *myCar3 = new Car(180); //Heap에 생성, 두번째 생성자로 객체 생성
    Car *myCar4 = new Car("현대"); //Heap에 생성, 세번째 생성자로 객체 생성
    Car *myCar5 = new Car("기아", 240, "빨간색");

    cout << "myCar : " << myCar.speed << endl;
    cout << "myCar2 : " << myCar2->speed << endl;
    cout << "myCar3 : " << myCar3->speed << endl;
    cout << "myCar4 : " << myCar4->brand << endl;
    cout << "myCar5 : " << myCar5->color << ":" 
        << myCar5->speed << ":" 
        << myCar5->brand << endl;

    delete myCar2;
    delete myCar3;
    delete myCar4;
    delete myCar5;
  return 0;
}






