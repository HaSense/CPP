#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

class Target {
public:
    virtual ~Target() = default;

    virtual string Request() const {
        return "Target: 기본 대상의 동작.";
    }
};

class Adaptee {
public:
    string SpecificRequest() const {
        return ".eetpadA eht fo roivaheb laicepS";
    }
};

class Adapter : public Target {
private:
    Adaptee *adaptee_;

public:
    Adapter(Adaptee *adaptee) : adaptee_(adaptee) {}

    string Request() const override {
        string to_reverse = this->adaptee_->SpecificRequest();
        reverse(to_reverse.begin(), to_reverse.end());
        return "어답터: (번역) " + to_reverse;
    }
};

void ClientCode(const Target *target) {
    cout << target->Request();
}

int main() {
    cout << "클라이언트: Target 개체를 사용하여 작업할 수 있습니다:" << endl;
    Target *target = new Target;
    ClientCode(target);
    cout << "\n\n";

    Adaptee *adaptee = new Adaptee;
    cout << "클라이언트: Adaptee 클래스의 인터페이스가 이상합니다. 이해가 안됩니다.\n";
    cout << "Adaptee: " << adaptee->SpecificRequest();
    cout << "\n\n";

    cout << "클라이언트: 하지만 어댑터를 통해 작업할 수 있습니다:\n";
    Adapter *adapter = new Adapter(adaptee);
    ClientCode(adapter);
    cout << "\n";

    delete target;
    delete adaptee;
    delete adapter;

    return 0;
}

/*
클라이언트: Target 개체를 사용하여 작업할 수 있습니다:
Target: 기본 대상의 동작.

클라이언트: Adaptee 클래스의 인터페이스가 이상합니다. 이해가 안됩니다.
Adaptee: .eetpadA eht fo roivaheb laicepS

클라이언트: 하지만 어댑터를 통해 작업할 수 있습니다:
어답터: (번역) Special behavior of the Adaptee.
*/
