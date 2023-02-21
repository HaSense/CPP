#include <iostream>
#include <vector> //벡터 사용 시 꼭!!! 사용해 주세요.
#include <algorithm> //알고리즘 문제 풀이 시 꼭 사용!!!

using namespace std;

bool compare(int i, int j){
    return i > j;
}

int main()
{
    //1.입력부
    vector<int> vec;
    int N = 0;
    int score;
    
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> score;
        vec.push_back(score);
    }

    std::sort(vec.begin(), vec.end(), compare);  //정렬완료

    //out
    cout << endl;
    int rank = 0;
    int flag = 0;
    int cnt = 0;

    for(int i=0; i<vec.size(); i++){
         if(i>0 && vec[i] == vec[i-1]){
            rank = rank;
            cnt++;
            flag = 1;
         }else{
            rank++;
            cnt++;
            flag = 0;
         }
        if(flag == 0)
            rank = cnt;
        cout << vec[i] << " " << rank << endl;
    }

    return 0;
}
