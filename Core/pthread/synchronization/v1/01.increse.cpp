#include <iostream>
#include <memory>

class SharedData {
public:
    int value;

    SharedData() : value(0) {}
};

void increment(std::shared_ptr<SharedData> data, int times) {
    for (int i = 0; i < times; ++i) {
        ++(data->value);
    }
}

int main() {
    std::shared_ptr<SharedData> data = std::make_shared<SharedData>();

    const int times = 100;
    increment(data, times);
    increment(data, times);

    std::cout << "Final value: " << data->value << std::endl;

    return 0;
}
