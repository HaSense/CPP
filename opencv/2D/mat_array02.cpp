#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
   //Stack에 배열선언
   int arr[3][3];
   
   int cnt = 1;
   for(int i=0; i<3; i++){
    for(int j=0; j<3; j++){
        arr[j][i] = cnt++; 
    }
   }
   for(int i=0; i<3; i++){
    for(int j=0; j<3; j++){
        cout << arr[i][j] << " ";
    }
    cout<<endl;
   }
   //동적할당 Heap
   int **arr2 = new int*[3]; //*[row] 동적할당 선언
   for(int i=0; i<3; i++) //각각의 행에 길이가 4인 배열을 할당
   arr2[i] = new int[3];

   cnt = 1;
   for(int i=0; i<3; i++){
    for(int j=0; j<3; j++){
        arr2[j][i] = cnt++; 
    }
   }
   for(int i=0; i<3; i++){
    for(int j=0; j<3; j++){
        cout << arr2[i][j] << " ";
    }
    cout<<endl;
   } 
   delete[] arr2; //heap에 객체 메모리 해제
   
   //Mat 표현
   Mat m2 = (Mat_<int>(3,3) << 1, 4, 7, 2, 5, 8, 3, 6, 9);
   cout << "m2 : " << endl << m2 << endl;; 

    return 0;
}
