#include <iostream>
using namespace std;

template<typename T, int size>
T sum(T arr[]) {
    T total = 0;
    for (int i = 0; i < size; i++) {
        total += arr[i];
    }
    return total;
}

int main() {
    int arr1[] = {1, 2, 3};
    float arr2[] = {1.5, 2.5, 3.5};

    cout << sum<int, 3>(arr1) << endl; // 6
    cout << sum<float, 3>(arr2) << endl; // 7.5
    return 0;
}
