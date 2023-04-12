#include <iostream>
using namespace std;

template<typename T>
T add(T a, T b) {
    return a + b;
}

int main() {
    int x = 1, y = 2;
    float f1 = 1.5, f2 = 2.5;

    cout << add(x, y) << endl; // 3
    cout << add(f1, f2) << endl; // 4
    return 0;
}
