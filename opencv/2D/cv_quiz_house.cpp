#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
    Mat image(600, 800, CV_8UC3, Scalar(255, 255, 255));
    vector<Point> pts;
    Point pt1(100, 500), pt2(400, 150), pt3(700, 500);
    pts.push_back(pt1);
    pts.push_back(pt2);
    pts.push_back(pt3);
    fillPoly(image, pts, Scalar(0, 0, 255), LINE_AA, 1);
    
    Point pt4(100, 500), pt5(400, 150), pt6(700, 500);
    Point tri_point[1][3];
    tri_point[0][0] = pt4;
    tri_point[0][1] = pt5;
    tri_point[0][2] = pt6;
    const Point *ppt[1] = {tri_point[0]};
    int npt[] = {3};    
    fillPoly(image, ppt, npt, 1, Scalar(255,0,0), 8);
    
    //2번째 매개변수를 vector로 넣었을 대 에러가 발생
    vector<Point> ppts;
    ppts.push_back(pt4);
    ppts.push_back(pt5);
    ppts.push_back(pt6);
    //fillPoly(image, ppts, npt, 1, Scalar(255,0,0), 8); //type Error
    
    imshow("삼각형 그리기", image);
    waitKey(0); // 0는 무한대기
    return 0;
}

