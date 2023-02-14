#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

void onMouse(int event, int x, int y, int flags, void* param);

int main()
{
    Mat image(200, 300, CV_8U);
    image.setTo(255); //Scalar() 함수와 결과가 같다.
    imshow("퀴즈", image);
    
    setMouseCallback("퀴즈", onMouse, 0);
    waitKey(0); // 0는 무한대기
    return 0;
}

void onMouse(int event, int x, int y, int flags, void* param)
{
    static vector<int> vec(5);
    static int flag = 0; //0 일때 1 - 5   1일때 5 - 1
    
    switch(event) 
    {
        case EVENT_LBUTTONDOWN:
            cout << "마우스 왼쪽 버튼이 클릭 되었습니다." << endl;
            if(flag == 0) {
                for(int i=0; i<5; i++)
                    vec[i] = (i+1);
                flag = 1;
            }
            else {
                int j = 5;
                for(int i=0; i<5; i++)
                    vec[i] = j--;
                flag = 0;
            }
            break;
        case EVENT_RBUTTONDOWN:
            cout << "마우스 오른쪽 버튼이 클릭 되었습니다." << endl;
            for(int i : vec)
                cout << i << " ";
            cout << endl;
            break;
    }
}




