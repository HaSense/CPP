//동적할당
#include <iostream>
using namespace std;

int main() 
{
    int *arr = new int[3];
    
    for(int i=0; i<3; i++) {
        arr[i] = i+1;
        cout << arr[i]<< endl;
    }

    delete[] arr; // 매우 중요~!!!
    return 0;
}
