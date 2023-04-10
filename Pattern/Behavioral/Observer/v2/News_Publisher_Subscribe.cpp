#include <iostream>
#include <list>
#include <string>

using namespace std;

// 구독자가 구현해야 하는 인터페이스
class ISubscriber {
public:
    virtual ~ISubscriber() {};
    virtual void Update(const string& message) = 0;
};

// 발행자가 구현해야 하는 인터페이스
class IPublisher {
public:
    virtual ~IPublisher() {};
    virtual void Attach(ISubscriber* subscriber) = 0;
    virtual void Detach(ISubscriber* subscriber) = 0;
    virtual void Notify(const string& message) = 0;
};

// 발행자 클래스
class Publisher : public IPublisher {
public:
    virtual ~Publisher() {
        cout << "안녕 내가 Publisher 였어요." << endl;
    }

    // 구독자 등록
    void Attach(ISubscriber* subscriber) override {
        list_subscriber_.push_back(subscriber);
    }

    // 구독자 해제
    void Detach(ISubscriber* subscriber) override {
        list_subscriber_.remove(subscriber);
    }

    // 메시지 전파
    void Notify(const string& message) override {
        list<ISubscriber*>::iterator iterator = list_subscriber_.begin();
        while (iterator != list_subscriber_.end()) {
            (*iterator)->Update(message);
            ++iterator;
        }
    }

    // 발행자에서 메시지 생성 및 전파
    void CreateMessage(string message = "Empty") {
        this->message_ = message;
        Notify(message_);
    }

    // 비즈니스 로직
    void SomeBusinessLogic() {
        this->message_ = "메시지를 변경합니다.";
        Notify(message_);
        cout << "나는 중요한 일을 하려고 합니다." << endl;
    }

private:
    list<ISubscriber*> list_subscriber_;
    string message_;
};

// 구독자 클래스
class Subscriber : public ISubscriber {
public:
    Subscriber(const string& name, Publisher& publisher)
        : name_(name), publisher_(publisher) {
        this->publisher_.Attach(this);
        cout << "안녕, 난 구독자 " << this->name_ << "야!" << endl;
    }

    virtual ~Subscriber() {
        cout << "안녕히, 난 구독자 " << this->name_ << "였어." << endl;
        this->publisher_.Detach(this);
    }

    // 발행자로부터 메시지 수신 및 출력
    void Update(const string& message) override {
        cout << "구독자 \"" << this->name_ << "\": 새로운 메시지가 있습니다. --> " << message << "\n";
    }

private:
    string name_;
    Publisher& publisher_;
};

int main() {
    Publisher* publisher = new Publisher();
    Subscriber* subscriber1 = new Subscriber("철수", *publisher);
    Subscriber* subscriber2 = new Subscriber("영희", *publisher);
    Subscriber* subscriber3 = new Subscriber("민수", *publisher);

    publisher->CreateMessage("안녕하세요!");
    publisher->SomeBusinessLogic();
    cout << endl;
    
    publisher->CreateMessage("2번째 메시지 입니다.");
    publisher->Detach(subscriber1);

    cout << endl;
    publisher->CreateMessage("3번째 메시지 입니다.");

    delete subscriber3;
    delete subscriber2;
    delete subscriber1;
    delete publisher;

    return 0;
}

/*
/home/iot/CLionProjects/Observer_Pattern_v2/cmake-build-debug/Observer_Pattern_v2
안녕, 난 구독자 철수야!
안녕, 난 구독자 영희야!
안녕, 난 구독자 민수야!
구독자 "철수": 새로운 메시지가 있습니다. --> 안녕하세요!
구독자 "영희": 새로운 메시지가 있습니다. --> 안녕하세요!
구독자 "민수": 새로운 메시지가 있습니다. --> 안녕하세요!
구독자 "철수": 새로운 메시지가 있습니다. --> 메시지를 변경합니다.
구독자 "영희": 새로운 메시지가 있습니다. --> 메시지를 변경합니다.
구독자 "민수": 새로운 메시지가 있습니다. --> 메시지를 변경합니다.
나는 중요한 일을 하려고 합니다.

구독자 "철수": 새로운 메시지가 있습니다. --> 2번째 메시지 입니다.
구독자 "영희": 새로운 메시지가 있습니다. --> 2번째 메시지 입니다.
구독자 "민수": 새로운 메시지가 있습니다. --> 2번째 메시지 입니다.

구독자 "영희": 새로운 메시지가 있습니다. --> 3번째 메시지 입니다.
구독자 "민수": 새로운 메시지가 있습니다. --> 3번째 메시지 입니다.
안녕히, 난 구독자 민수였어.
안녕히, 난 구독자 영희였어.
안녕히, 난 구독자 철수였어.
안녕 내가 Publisher 였어요.

종료 코드 0(으)로 완료된 프로세스
*/
