#include <iostream>
#include <memory>
#include <mutex>
#include <thread>

class SharedData {
public:
    int value;

    SharedData() : value(0) {}
};

void increment(std::shared_ptr<SharedData> data, std::mutex &mtx, int times) {
    for (int i = 0; i < times; ++i) {
        std::unique_lock<std::mutex> lock(mtx);
        ++(data->value);
        lock.unlock();
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
    }
}

int main() {
    std::shared_ptr<SharedData> data = std::make_shared<SharedData>();
    std::mutex mtx;

    const int times = 1000;
    std::thread t1(increment, data, std::ref(mtx), times);
    std::thread t2(increment, data, std::ref(mtx), times);

    t1.join();
    t2.join();

    std::cout << "Final value: " << data->value << std::endl;

    return 0;
}
