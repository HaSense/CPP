#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    
    std::vector<int> vec = {97, 91, 84, 84, 65};
    
    // 벡터 정렬
    std::sort(vec.begin(), vec.end(), std::greater<int>());

    // 각 요소에 대한 순위 계산
    std::vector<int> rank(5);
    for (int i = 0; i < 5; i++) {
        int r = i;
        while (r > 0 && vec[r] == vec[r-1]) {
            r--;
        }
        rank[i] = r+1;
    }

    // 결과 출력
    for (int i = 0; i < 5; i++) {
        std::cout << vec[i] << " " << rank[i] << std::endl;
    }

    return 0;
}
