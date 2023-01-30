#include <iostream>

using namespace std;

int main() {
    int arr[3]; // 3개의 요소를 가진 int 타입 배열 arr 선언
    // int arr[3] = {1, 2, 3}; //가능

    // 배열의 각 요소에 값을 입력
    for (int i = 0; i < 3; i++) {
        arr[i] = i + 1;
    }

    // 배열의 각 요소 출력
    for (int i = 0; i < 3; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
