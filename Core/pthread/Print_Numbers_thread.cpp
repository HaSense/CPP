#include <iostream>
#include <pthread>

void* PrintNumbers(void* arg) {
    int* max_number = static_cast<int*>(arg);
    for (int i = 0; i < *max_number; ++i) {
        std::cout << "Thread " << pthread_self() << ": " << i << std::endl;
    }
    pthread_exit(NULL);
}

int main() {
    pthread_t thread1, thread2;
    int max_number1 = 5, max_number2 = 8;

    pthread_create(&thread1, NULL, PrintNumbers, &max_number1);
    pthread_create(&thread2, NULL, PrintNumbers, &max_number2);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    std::cout << "Threads finished." << std::endl;

    return 0;
}
