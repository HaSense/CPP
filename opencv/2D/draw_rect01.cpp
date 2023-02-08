#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
    Mat image(1000, 600, CV_8UC3, Scalar(255,255,255));
    //Mat image(1000, 600, CV_8UC1, Scalar(255));
    Point2f center(300, 500);
    Size2f size(400, 200);
    RotatedRect rot_rect(center, size, 20);

    Rect bound_rect = rot_rect.boundingRect();
    
    rectangle(image, bound_rect, Scalar(0,0,0), 2);
    //rectangle(image, bound_rect, Scalar(0), 1);
    rectangle(image, Point(50,50), Point(200, 200), Scalar(0,0,255), 3, 4, 0);

    imshow("사각형", image);
    waitKey(0);

    return 0;
}




