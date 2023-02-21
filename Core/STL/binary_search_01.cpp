#include <iostream>
#include <vector> 
#include <algorithm> 
using namespace std;
int main()
{
    vector<int> vec = {1, 6, 7, 5, 2, 3, 4};
    //이진탐색(binary_search)의 순서
    //1. 정렬
    sort(vec.begin(), vec.end());
    //2. 탐색
    int ret_v1 = binary_search(vec.begin(), vec.end(), 5);
    int ret_v2 = binary_search(vec.begin(), vec.end(), 99);

    //출력
    cout << "자료가 존재할 때 리턴값 : " << ret_v1 << endl;
    cout << "자료가 존재하지 않을 때 리턴값 : " << ret_v2 << endl;
        
    return 0;
}

