#include <iostream>

class Singleton {
private:
    // 생성자, 복사 생성자, 대입 연산자 모두 private으로 선언하여 외부에서의 객체 생성을 방지
    Singleton() {}
    Singleton(const Singleton&);
    Singleton& operator=(const Singleton&);

public:
    // 유일한 인스턴스를 반환하는 정적 메소드 GetInstance()
    static Singleton& GetInstance() {
        static Singleton instance; // 정적 지역 변수로 인스턴스를 유지
        return instance;
    }

    // 기능을 제공하는 메소드
    void DoSomething() {
        std::cout << "Hello, Singleton!" << std::endl;
    }
};

int main() {
    Singleton& s1 = Singleton::GetInstance();
    Singleton& s2 = Singleton::GetInstance();

    s1.DoSomething();
    s2.DoSomething();

    return 0;
}
