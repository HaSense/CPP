#include <iostream>
#include <thread>

void Add(int a, int b, int& result) {
    result = a + b;
}

int main() {
    int sum = 0;
    std::thread t1(Add, 10, 20, std::ref(sum));
    t1.join();
    std::cout << "Sum: " << sum << std::endl;
    return 0;
}
