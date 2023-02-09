#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
    vector<Point> v1; //객체생성
    Point p1(10, 20);
    Point p3;
    p3.x = 50, p3.y = 60;

    v1.push_back(p1);
    v1.push_back(Point(20, 30));
    v1.push_back(p3);

    vector<float> v2(3, 9.25);
    Size arr_size[3] = { Size(2, 2), Size(3, 3), Size(4, 4) };
    int arr_int[5] = { 10, 20, 30, 40, 50 };

    //배열 원소로 벡터 초기화
    vector<Size> v3(arr_size, arr_size + (sizeof(arr_size) / sizeof(Size)) ); //Size형 벡터선언
    vector<int> v4(arr_int + 2, arr_int + sizeof(arr_int) / sizeof(int) );
    cout << "v1 : " << endl << (Mat)v1 << endl;
    cout << "v2 : " << endl << (Mat)v2 << endl;
    cout << "v2 reshape(1,1) : " << ((Mat)v2).reshape(1, 1) <<  endl;
    cout << "v3 : " << endl << (Mat)v3 << endl;
    cout << "v3 reshape(1,1): " << endl << ((Mat)v3).reshape(1, 1) << endl;
    cout << "v4 : " << endl << (Mat)v4 << endl;
    cout << "v4 reshape(1,1): " << endl << ((Mat)v4).reshape(1, 1) << endl;

    return 0;
}

