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

class Cat
{
public:
    std::size_t getHashCoe() const {
        return std::hash<const Cat*>()(this);
    }
};

int main() {

    Singleton& s1 = Singleton::GetInstance();
    Singleton& s2 = Singleton::GetInstance();
    Singleton& s3 = Singleton::GetInstance();

    std::cout << "s1 : " << s1.getHashCoe() << std::endl;
    std::cout << "s2 : " << s2.getHashCoe() << std::endl;
    std::cout << "s3 : " << s3.getHashCoe() << std::endl;

    Cat cat1, cat2, cat3;
    std::cout << "cat1 : " << cat1.getHashCoe() << std::endl;
    std::cout << "cat2 : " << cat2.getHashCoe() << std::endl;
    std::cout << "cat3 : " << cat3.getHashCoe() << std::endl;

    return 0;
}

/*
s1 : 94837060084018
s2 : 94837060084018
s3 : 94837060084018
cat1 : 140723780945005
cat2 : 140723780945006
cat3 : 140723780945007
*/


