#include <iostream>
using namespace std;

template<typename T>
T max(T a, T b) {
    return a > b ? a : b;
}

int main() {
    int x = 1, y = 2;
    float f1 = 1.5, f2 = 2.5;

    cout << max(x, y) << endl; // 2
    cout << max(f1, f2) << endl; // 2.5
    return 0;
}
