#include <iostream>

class Singleton
{
private:
    Singleton(){}
    Singleton(const Singleton&);
    Singleton& operator=(const Singleton&);

public:
    // 유일한 Instance를 반환하는 static method
    static Singleton& GetInstance() {
        static Singleton instance;
        return instance;
    }
    void DoSomething() {
        std::cout << "Hello, Singleton!" << std::endl;
    }
    std::size_t getHashCoe() const {
        return std::hash<const Singleton*>()(this);
    }
};

int main() {

    Singleton& s1 = Singleton::GetInstance();
    Singleton& s2 = Singleton::GetInstance();

    s1.DoSomething();
    s2.DoSomething();

    std::cout << s1.getHashCoe() << std::endl;
    std::cout << s2.getHashCoe() << std::endl;

    return 0;
}

/*

Hello, Singleton!
Hello, Singleton!
94879569248562
94879569248562

*/


