#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

class VectorInfo
{
public:
    void showInfo(string v_name, vector<int> v){
        cout << v_name << " : " << endl;
        if(v.empty())
            cout << "벡터가 비었습니다." << endl;
        else
            cout << ((Mat)v).reshape(1, 1) << endl;

        cout <<".size() " << v.size() << endl;
    }
};

int main()
{
    int arr[5] = { 10, 20, 30, 40, 50 };
    int arr2[1] = {10};
    vector<int> v1(arr, arr + sizeof(arr) / sizeof(int)); //v1(배열, 5)
    vector<int> v2(arr2, arr2 + sizeof(arr2) / sizeof(int));
    cout << "arr : " << arr << "*arr:" << *arr << endl;
    cout << "sizeof(arr) : " << sizeof(arr) << endl;
    cout << "sizeof(int) : " << sizeof(int) << endl;
    cout << "sizeof(arr) / sizeof(int) : " << sizeof(arr) / sizeof(int) << endl;
    cout << "arr + sizeof(arr) / sizeof(int) : " << arr + (sizeof(arr) / sizeof(arr)) << endl;

    VectorInfo vinfo;
    vinfo.showInfo("v1", v1);
    cout << ".capacity() " << v1.capacity() << endl << endl;

    v1.insert(v1.begin() + 2, 100);
    vinfo.showInfo("v1, insert(2) ", v1);
    cout << ".capacity() " << v1.capacity() << endl << endl;

    v1.erase(v1.begin() + 3);
    vinfo.showInfo("v1, erase(3)", v1);
    cout << ".capacity() " << v1.capacity() << endl << endl;

    v1.clear();
    vinfo.showInfo("v1, clear : ", v1);
    cout << ".capacity() " << v1.capacity() << endl << endl;

    vinfo.showInfo("v2 : ", v2);
    cout << ".capacity() " << v2.capacity() << endl << endl;

    return 0;
}



/*
iot@iot:~/work/opencv/basic04$ ./run
arr : 0x7ffc0f2ff640*arr:10
sizeof(arr) : 20
sizeof(int) : 4
sizeof(arr) / sizeof(int) : 5
arr + sizeof(arr) / sizeof(int) : 0x7ffc0f2ff644
v1 : 
[10, 20, 30, 40, 50]
.size() 5
.capacity() 5

v1, insert(2)  : 
[10, 20, 100, 30, 40, 50]
.size() 6
.capacity() 10

v1, erase(3) : 
[10, 20, 100, 40, 50]
.size() 5
.capacity() 10

v1, clear :  : 
벡터가 비었습니다.
.size() 0
.capacity() 10

v2 :  : 
[10]
.size() 1
.capacity() 1



*/
