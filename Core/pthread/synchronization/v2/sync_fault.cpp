/* 실전성 없는 스레드 코드, 교과서에만 존재하는 코드 */

#include <iostream>
#include <thread>
#include <vector>
#include <numeric>

int sumRange(int start, int end) {
    int sum = 0;
    for (int i = start; i <= end; ++i) {
        sum += i;
    }
    return sum;
}

int main() {
    std::vector<int> partialSums(3);

    std::thread t1([&partialSums] { partialSums[0] = sumRange(1, 1000); });
    t1.join();

    std::thread t2([&partialSums] { partialSums[1] = sumRange(1001, 2000); });
    t2.join();

    std::thread t3([&partialSums] { partialSums[2] = sumRange(2001, 3000); });
    t3.join();

    int totalSum = std::accumulate(partialSums.begin(), partialSums.end(), 0);

    std::cout << "Total sum: " << totalSum << std::endl;

    return 0;
}
