#include <iostream>

using namespace std;

/*
  객체를 이용하여 배열을 만드는 방법을 설명합니다.
  주의하실 점은 스택에 배열을 만들면 요소 객체를 만들 필요가 없지만
  
  힙메모리에 동적할당으로 만들면 만들어진 배열의 각요소에 객체공간을 만들어 주셔야 합니다.
  또, c++ 이기 때문에 메모리 해제도 해주셔야 합니다.
*/

class Point
{
public:
    int x, y;
    Point():x(0),y(0){}
    void Print(){
        cout << x << " " << y << endl;
    }
};
int main()
{
    Point point_arr[3]; //stack생성

    cout << "Stack에 객체를 만들어 출력" << endl;
    for(int i=0; i<3; i++){
        cout << point_arr[i].x << " " << point_arr[i].y << endl;
    }
    cout << "for-each 구문"<< endl;
    for(Point pt : point_arr){
        cout << pt.x << " " << pt.y << endl;
    }
    cout << "Heap에 객체생성된 배열" << endl;
    Point *point_arr2 = new Point[3];
    for(int i=0; i<3; i++){
        point_arr2[i] = Point();    //현재 요소에 객체를 만들어주어야 함!!!
        cout << point_arr2[i].x << " " << point_arr2[i].y << endl;    
    }
    delete[] point_arr2;
    return 0;
}









