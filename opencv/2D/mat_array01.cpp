#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
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
   
   Mat m2 = (Mat_<int>(3,3) << 1, 4, 7, 2, 5, 8, 3, 6, 9);
   cout << "m2 : " << endl << m2 << endl;; 

    return 0;
}
