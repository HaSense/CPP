/* 일을 잘 구분하여 동시에 실행 시킨다. */

#include <iostream>
#include <thread>
#include <vector>
#include <mutex>

std::mutex mtx;

void addValues(std::vector<int> &vec, int start, int end) {
    for (int i = start; i <= end; ++i) {
        std::unique_lock<std::mutex> lock(mtx);
        vec.push_back(i);
        lock.unlock();
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
    }
}

int main() {
    std::vector<int> sharedVec;

    std::thread t1(addValues, std::ref(sharedVec), 1, 10);
    std::thread t2(addValues, std::ref(sharedVec), 11, 20);

    t1.join();
    t2.join();

    for (const auto &val : sharedVec) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    return 0;
}
