#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

class MatManager
{
public:
    void ShowInfo(string name, Mat m)
    {
        //1.if mat_type설정
        string mat_type = findType(m);
        //2.정보 보여주기
        cout << name << " 크기 " << m.size() << ",";
        cout << " 자료형 " << mat_type << "C" << m.channels() << endl;
        cout << m << endl << endl;
    }
private:
    string findType(Mat m)
    {
        string mat_type;
        if(m.depth() == CV_8U) mat_type = "CV_8U";
        else if(m.depth() == CV_8S) mat_type = "CV_8S";
        else if(m.depth() == CV_16U) mat_type = "CV_16U";
        else if(m.depth() == CV_32S) mat_type = "CV_32S";
        else if(m.depth() == CV_32F) mat_type = "CV_32F";
        else if(m.depth() == CV_64F) mat_type = "CV_64F";
        
        return mat_type;
    }
    
};

int main()
{
    Mat         m1, m2, m3, m4(2, 6, CV_8UC1), m5;
    Mat         add1(2, 3, CV_8UC1, Scalar(100));
    Mat         add2 = (Mat)Mat::eye(4, 3, CV_8UC1);
    
    m1.push_back(100);
    m1.push_back(200);
    m2.push_back(100.5);
    m2.push_back(200.6);
    
    //m3.push_back(add1);
    //m3.push_back(add2);

    //m4.push_back(add1)
    //m4.push_back(100);
    m4.push_back(add1.reshape(1, 1));
    m4.push_back(add2.reshape(1, 2));
    
    MatManager matManager;  //객체 생성(Stack) // MatManager matManager = new MatManager();
    matManager.ShowInfo("m1", m1);
    matManager.ShowInfo("m2", m2);
    //matManager.ShowInfo("m3", m3);
    matManager.ShowInfo("m4", m4);
    // matManager.ShowInfo("m5", m5);
    // cout << "m1 : " << endl << m1 << endl;

    // m1.pop_back(2);

    // cout << "m1 : " << endl << m1 << endl;

    return 0;
}




