/* Clion 사용하신다면 리눅스에서는 pthread 라이브러리를 추가해야 합니다.

CmakeLists.txt target_link에 pthread 라이브러리 아래처럼 추가해 주시면 잘 동작합니다. (현재 리눅스에서 테스트)
예) target_link_libraries(프로그램제목 pthread) 
*/
#include <iostream>
#include <mutex>
#include <thread>

class Singleton
{

private:
    static Singleton * pinstance_;
    static std::mutex mutex_;

protected:
    Singleton(const std::string value): value_(value)
    {
    }
    ~Singleton() {}
    std::string value_;

public:

    Singleton(Singleton &other) = delete;

    void operator=(const Singleton &) = delete;

    static Singleton *GetInstance(const std::string& value);

    void SomeBusinessLogic()
    {
        // ...
    }
    
    std::string value() const{
        return value_;
    } 
};


Singleton* Singleton::pinstance_{nullptr};
std::mutex Singleton::mutex_;

Singleton *Singleton::GetInstance(const std::string& value)
{
    std::lock_guard<std::mutex> lock(mutex_);
    if (pinstance_ == nullptr)
    {
        pinstance_ = new Singleton(value);
    }
    return pinstance_;
}

void ThreadFoo(){

    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    Singleton* singleton = Singleton::GetInstance("FOO");
    std::cout << singleton->value() << "\n";
}

void ThreadBar(){

    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    Singleton* singleton = Singleton::GetInstance("BAR");
    std::cout << singleton->value() << "\n";
}

int main()
{   
    std::cout <<"If you see the same value, then singleton was reused (yay!\n" <<
                "If you see different values, then 2 singletons were created (booo!!)\n\n" <<
                "RESULT:\n";

    std::thread t1(ThreadFoo);
    std::thread t2(ThreadBar);
    t1.join();
    t2.join();
    
    return 0;
}
