#include <iostream>
#include <string>
using namespace std;

class Animal{
    //생성자, 멤버메소드
    public: 
        Animal(){
            name = "동물";
        }

        //Getter, Setter
        void setName(string name_){
            name = name_;
        }
        string getName(){
            return name;
        }
        void setAge(int age_){
            age = age_;
        }
        int getAge(){
            return age;
        }
    //멤버변수
    private:
        int age;
        string name;

};
class Dog : public Animal{

};

int main()
{
    Animal ani;
    //cout << ani.name << endl;     //Error , 직접접근 
    cout << ani.getName() << endl; //성공, 간접접근
    ani.setAge(10);
    cout << ani.getAge() << endl;
    ani.setName("동물2");
    cout << ani.getName() << endl;
    return 0;
}







