#include <iostream>
using namespace std;

void greet(); //함수 헤더 

static int a = 100;
int main() {
    
    greet();

    return 0;
}
void greet() {
    cout << "Hello there!";
    cout << a <<endl;
}
