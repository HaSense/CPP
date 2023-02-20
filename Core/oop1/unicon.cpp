#include <iostream>
using namespace std;

class Angel{
public:
    void Fly(){
        cout << "날다" << endl;
    }
};
class Horse{
public:
    void Run(){
        cout << "달리다" << endl;
    }
};
class Unicon : public Angel, public Horse{

};

int main()
{
    Unicon unicon;
    unicon.Fly();
    unicon.Run();
}
