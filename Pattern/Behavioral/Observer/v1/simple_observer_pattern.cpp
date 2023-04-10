#include <iostream>
#include <list>
#include <string>

using namespace std;

class IObserver {
 public:
  virtual ~IObserver(){};   // 소멸자: 리소스 반
  virtual void Update(const string &message_from_subject) = 0;  // 업데이트
};

class ISubject {
 public:
  virtual ~ISubject(){};
  virtual void Attach(IObserver *observer) = 0;         // 등록
  virtual void Detach(IObserver *observer) = 0;         // 제거
  virtual void Notify() = 0;                            // 통지
};

class Subject : public ISubject {       // 출판 구독 모델에서 Publisher에 해당
 public:
  virtual ~Subject() {
    cout << "안녕 내가 Subject 였어요." << endl;
  }
  // 구독 등록
  void Attach(IObserver *observer) override {
    list_observer_.push_back(observer);
  }
  // 구독 취소
  void Detach(IObserver *observer) override {
    list_observer_.remove(observer);
  }
  // 통지, 메시지 전달
  void Notify() override {
    list<IObserver *>::iterator iterator = list_observer_.begin();
    HowManyObserver();
    while (iterator != list_observer_.end()) {      //list_observer에 등록되어 있는 observer들에 메시지 업데이트
      (*iterator)->Update(message_);
      ++iterator;
    }
  }

  void CreateMessage(string message = "Empty") {
    this->message_ = message;
    Notify();
  }
  void HowManyObserver() {
    cout << "There are " << list_observer_.size() << " observers in the list.\n";
  }

  // 구독 서비스를 풍부하게 만들기 우해 비즈니스 로직추가
  void SomeBusinessLogic() {
    this->message_ = "메시지를 변경합니다.";
    Notify();
    cout << "나는 중요한 일을 하려고 합니다." << endl;
  }

 private:
  list<IObserver *> list_observer_;
  string message_;
};

class Observer : public IObserver {
 public:
  Observer(Subject &subject) : subject_(subject) {
    this->subject_.Attach(this);
    cout << "안녕, 난 옵저버야!" << ++Observer::static_number_ << endl;
    this->number_ = Observer::static_number_;
  }
  virtual ~Observer() {
    cout << "안녕히, 난 옵저버였어." << this->number_ << endl;
  }

  void Update(const string &message_from_subject) override {
    message_from_subject_ = message_from_subject;
    PrintInfo();
  }
  void RemoveMeFromTheList() {
    subject_.Detach(this);
    cout << "Observer \"" << number_ << "\" 번을 리스트에서 제거하였습니다." << endl;
  }
  void PrintInfo() {
    cout << "Observer \"" << this->number_ << "\": 새로운 메시지가 있습니다. --> " << this->message_from_subject_ << "\n";
  }

 private:
  string message_from_subject_;
  Subject &subject_;
  static int static_number_;
  int number_;
};

int Observer::static_number_ = 0;

void ClientCode() {
  Subject *subject = new Subject;
  Observer *observer1 = new Observer(*subject);
  Observer *observer2 = new Observer(*subject);
  Observer *observer3 = new Observer(*subject);
  Observer *observer4;
  Observer *observer5;

  subject->CreateMessage("안녕하세요~~!! ^^ ");
  observer3->RemoveMeFromTheList();

  subject->CreateMessage("오늘은 날씨가 무척 무덥습니다.");
  observer4 = new Observer(*subject);

  observer2->RemoveMeFromTheList();
  observer5 = new Observer(*subject);

  subject->CreateMessage("제 차는 너무 멋져요.");
  observer5->RemoveMeFromTheList();

  observer4->RemoveMeFromTheList();
  observer1->RemoveMeFromTheList();

  delete observer5;
  delete observer4;
  delete observer3;
  delete observer2;
  delete observer1;
  delete subject;
}

int main() {
  ClientCode();
  return 0;
}

/*
안녕, 난 옵저버야!1
안녕, 난 옵저버야!2
안녕, 난 옵저버야!3
There are 3 observers in the list.
Observer "1": 새로운 메시지가 있습니다. --> 안녕하세요~~!! ^^ 
Observer "2": 새로운 메시지가 있습니다. --> 안녕하세요~~!! ^^ 
Observer "3": 새로운 메시지가 있습니다. --> 안녕하세요~~!! ^^ 
Observer "3" 번을 리스트에서 제거하였습니다.
There are 2 observers in the list.
Observer "1": 새로운 메시지가 있습니다. --> 오늘은 날씨가 무척 무덥습니다.
Observer "2": 새로운 메시지가 있습니다. --> 오늘은 날씨가 무척 무덥습니다.
안녕, 난 옵저버야!4
Observer "2" 번을 리스트에서 제거하였습니다.
안녕, 난 옵저버야!5
There are 3 observers in the list.
Observer "1": 새로운 메시지가 있습니다. --> 제 차는 너무 멋져요.
Observer "4": 새로운 메시지가 있습니다. --> 제 차는 너무 멋져요.
Observer "5": 새로운 메시지가 있습니다. --> 제 차는 너무 멋져요.
Observer "5" 번을 리스트에서 제거하였습니다.
Observer "4" 번을 리스트에서 제거하였습니다.
Observer "1" 번을 리스트에서 제거하였습니다.
안녕히, 난 옵저버였어.5
안녕히, 난 옵저버였어.4
안녕히, 난 옵저버였어.3
안녕히, 난 옵저버였어.2
안녕히, 난 옵저버였어.1
안녕 내가 Subject 였어요.
*/
