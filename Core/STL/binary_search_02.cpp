#include <iostream>
#include <vector> 
#include <algorithm> 
#include <string>
using namespace std;
int main()
{
    vector<string> vec = {"사과", "배", "수박", "바나나", "딸기", "메론"};
    //이진탐색(binary_search)의 순서
    //1. 정렬
    sort(vec.begin(), vec.end());
    //2. 탐색
    int ret_v1 = binary_search(vec.begin(), vec.end(), "바나나");
    int ret_v2 = binary_search(vec.begin(), vec.end(), "체리");

    //출력
    cout << "자료가 존재할 때 리턴값 : " << ret_v1 << endl;
    cout << "자료가 존재하지 않을 때 리턴값 : " << ret_v2 << endl;
        
    return 0;
}

