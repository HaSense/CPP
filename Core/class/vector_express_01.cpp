#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
    //vector를 이용한 동적할당 배열표현
    vector <vector<int>> arr(3,vector<int>(3,0)); // n행 2열을 가지는 벡터 선언
    int cnt=1;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            arr[j][i] = cnt++;
        }
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}

