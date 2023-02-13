#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

//노트북 기준
int main()
{
    Mat image(200, 300, CV_8U, Scalar(255));
    namedWindow("키보드 이벤트", WINDOW_AUTOSIZE);
    imshow("키보드 이벤트", image);

    while(true)
    {
        int key = waitKey(200);
        if(key == 27) 
            break; //'ESC'키를 눌르면 프로그램 빠짐
        
        switch(key){

            case 'a' : 
                cout << "a키 입력 " << endl; 
                break;
            case 'b' : 
                cout << "b키 입력 " << endl; 
                break;
            case 0x41 : 
                cout << "A키 입력 " << endl; 
                break;
            case 66 : 
                cout << "B키 입력 " << endl; 
                break;

            case 81: 
                cout << "왼쪽 화살표 키 입력" << endl; 
                break;
            case 82: 
                cout << "위쪽 화살표 키 입력" << endl; 
                break;
            case 83: 
                cout << "오른쪽 화살표 키 입력" << endl; 
                break;
            case 84: 
                cout << "아래쪽 화살표 키 입력" << endl; 
                break;

            // default :
            //     cout << key << endl;
        }
    }
    
    return 0;
}






