#include <iostream>
#include <opencv2/opencv.hpp>
//#include <ctime>

using namespace std;
using namespace cv;

int main()
{
    vector<double> v1, v2;
    v1.reserve(10000000);

    double start_time = clock();
    cout << "v1.capacity() : " << v1.capacity() << endl;
    for(int i=0; i<v1.capacity(); i++){
        v1.push_back(i);
    }
    printf("reserve 사용 %5.2f ms\n", clock() - start_time);

    start_time = clock();
    cout << "v1.capacity() : " << v1.capacity() << endl;
    for(int i=0; i<v1.capacity(); i++){
        v2.push_back(i);
    }
    printf("reserve 미사용 %5.2f ms\n", clock() - start_time);
    return 0;
}













