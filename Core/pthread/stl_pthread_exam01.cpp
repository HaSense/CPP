#include <iostream>
#include <thread>

void PrintNumbers()
{
    for(int i=1; i<=100; i++)
        std::cout << i << std::endl;
}

void ShowAlpabet()
{

    for(int i='A'; i<='Z'; i++){
        std::cout << (char)i << std::endl;
    }
}
int main() {

    std::thread t1(PrintNumbers);
    std::thread t2(ShowAlpabet);
    t1.join();
    t2.join();

    return 0;
}
