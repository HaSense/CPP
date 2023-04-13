/* 가장 이상적인 방법은 각 범위의 합을 async(비동기) 계산하고 계산이 완료되면 결과를 가져와 
총합을 계산한다. 이렇게 하면 작업을 병렬로 실행하여 계산 속도를 높일 수 있다. */

#include <iostream>
#include <future>
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
    std::vector<std::future<int>> partialSumsFutures;

    partialSumsFutures.push_back(std::async(std::launch::async, sumRange, 1, 1000));
    partialSumsFutures.push_back(std::async(std::launch::async, sumRange, 1001, 2000));
    partialSumsFutures.push_back(std::async(std::launch::async, sumRange, 2001, 3000));

    int totalSum = 0;
    for (auto &partialSumFuture : partialSumsFutures) {
        totalSum += partialSumFuture.get();
    }

    std::cout << "Total sum: " << totalSum << std::endl;

    return 0;
}
