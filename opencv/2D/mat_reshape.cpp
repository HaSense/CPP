#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

class CVInfo
{
public :
    void print_matInfo(string m_name, Mat m)
    {
        cout << "[" << m_name << " 행렬]" << endl;
        cout << "   채널 수 = " << m.channels() << endl;
        cout << "   행 X 열 = " << m.rows << " x " << m.cols << endl << endl;
        cout << "행렬 : " << endl << m << endl << endl;
    }
};
int main()
{
    Mat m1(2, 6, CV_8U);
    Mat m2 = m1.reshape(2, m2.rows * m2.cols);
    Mat m3 = m1.reshape(3, 2);

    CVInfo cvinfo;
    cvinfo.print_matInfo("m1(2, 6)", m1);
    cvinfo.print_matInfo("m2 = m1_reshape(2)", m2);
    cvinfo.print_matInfo("m3 = m1_reshape(3, 2)", m3);
    
    m1.create(3, 5, CV_16S);
    cvinfo.print_matInfo("m1.create(3, 5)", m1);

    return 0;
}











