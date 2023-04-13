//잘못된 동기화 문제가 발생할 수 있는 스레드 코드

#include <iostream>
#include <memory>
#include <thread>

class SharedData {
public:
    int value;

    SharedData() : value(0) {}
};

void increment(std::shared_ptr<SharedData> data, int times) {
    for (int i = 0; i < times; ++i) {
        ++(data->value);
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
    }
}

int main() {
    std::shared_ptr<SharedData> data = std::make_shared<SharedData>();

    const int times = 1000;
    std::thread t1(increment, data, times);
    std::thread t2(increment, data, times);

    t1.join();
    t2.join();

    std::cout << "Final value: " << data->value << std::endl;

    return 0;
}
