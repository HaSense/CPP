#include <iostream>
#include <thread>

void threadFunction() {
    std::thread::id threadId = std::this_thread::get_id();
    std::cout << "Thread ID: " << threadId << std::endl;
}

int main() {

    std::thread::id threadId = std::this_thread::get_id();
    std::cout << "Thread ID: " << threadId << std::endl;

    std::thread t1(threadFunction);
    std::thread t2(threadFunction);

    t1.join();
    t2.join();

    return 0;
}

/*

Thread ID: 139634982897472
Thread ID: 139634956355328
Thread ID: 139634964748032

*/
