#include <iostream>
#include <memory>

using namespace std;
class Dog
{
public:
    Dog();

    void info(){
        cout << "info() " << endl;
    }
};

int main() {

    Dog d1;
    Dog* d2 = new Dog();
    unique_ptr<Dog> d3 = make_unique<Dog>();

    d1.info();
    d2->info();
    delete d2;
    d3->info();

    return 0;
}
