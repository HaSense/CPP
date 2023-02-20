#include <iostream>
using namespace std;

#define interface struct
interface IFlyable{
    virtual void Fly() = 0; //순수가상함수
};
class Horse{
public:
    void Run(){
        cout << "달리다" << endl;
    }
};
class Unicon : public Horse, public IFlyable{
public:    
    virtual void Fly(){
        cout << "(interface) 날다" << endl;
    }
};
int main()
{
    Unicon unicon;
    unicon.Fly();
    unicon.Run();
}
