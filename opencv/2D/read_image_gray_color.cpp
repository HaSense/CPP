#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

void print_matInfo(string name, Mat img)
{
    string mat_type;
    if(img.depth() == CV_8U) 
        mat_type = "CV_8U";
    else if (img.depth() == CV_8S)
        mat_type = "CV_8S";
    else if (img.depth() == CV_16U)
        mat_type = "CV_16U";
    else if (img.depth() == CV_16S)
        mat_type = "CV_16S";
    else if (img.depth() == CV_32S)
        mat_type = "CV_32S";
    else if (img.depth() == CV_32F)
        mat_type = "CV_32F";
    else if (img.depth() == CV_64F)
        mat_type = "CV_64F";

    cout << name;
    cout << format(": depth(%d) channel(%d) --> 자료형 : ", img.depth(), img.channels());
    cout << mat_type << "C" << img.channels() << endl;
}

int main()
{
    string filename = "../image/read_gray.jpg";
    string path = "../image/read_color.jpg";
    Mat gray2gray = imread(filename, IMREAD_GRAYSCALE);
    Mat color = imread(path, IMREAD_COLOR);

    print_matInfo("gray2gray", gray2gray);
    print_matInfo("color", color);

    imshow("gray2gray", gray2gray);
    imshow("color", color);

    waitKey(0); // 0는 무한대기
    return 0;
}

