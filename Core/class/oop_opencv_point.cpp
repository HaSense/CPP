#include <iostream>
#include <opencv2/highgui.hpp>

// using namespace std;
// using namespace cv;
class Point{
public:
    Point(){ }
    Point(int x, int y):x(x), y(y){}

    //복사생성자
    Point(Point& other) : x(other.x), y(other.y) {}

    int x, y;
};
int main() 
{
   cv::Point_<int> pt1(100, 100);
   std::cout << pt1 << std::endl;

    Point pt2(200, 200);
    std::cout << pt2.x << ":" << pt2.y << std::endl;

    return 0;
}
