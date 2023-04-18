#include <algorithm>
#include <iostream>
#include <memory>
#include <string>

using namespace std;

// Interface for the legacy system
class LegacyInterface {
public:
    virtual ~LegacyInterface() = default;

    virtual string LegacyOperation() const {
        return "기존(레거시) 동작";
    }
};

// Interface for the new system
class NewInterface {
public:
    virtual ~NewInterface() = default;

    virtual string NewOperation() const {
        return "새 시스템 동작 방식";
    }
};

// Adapter class for bridging the legacy system to the new system
class Adapter : public NewInterface {
private:
    shared_ptr<LegacyInterface> legacy_;

public:
    Adapter(shared_ptr<LegacyInterface> legacy) : legacy_(legacy) {}

    string NewOperation() const override {
        return "어답터: 새 시스템에서 동작하는 레거시(기존의) 방식 : " + legacy_->LegacyOperation();
    }
};

void ClientFunction(const shared_ptr<NewInterface> &new_interface) {
    cout << new_interface->NewOperation() << endl;
}

int main() {
    // Legacy system
    shared_ptr<LegacyInterface> legacy = make_shared<LegacyInterface>();

    // Adapter for the legacy system
    shared_ptr<Adapter> adapter = make_shared<Adapter>(legacy);

    // New system
    shared_ptr<NewInterface> new_interface = make_shared<NewInterface>();

    cout << "클라이언트: 새로운 시스템 방식으로 동작:" << endl;
    ClientFunction(new_interface);

    cout << endl;
    cout << "클라이언트: 어답터를 통해 기존의 방식으로 동작:" << endl;
    ClientFunction(adapter);

    return 0;
}
/*
클라이언트: 새로운 시스템 방식으로 동작:
새 시스템 동작 방식

클라이언트: 어답터를 통해 기존의 방식으로 동작:
어답터: 새 시스템에서 동작하는 레거시(기존의) 방식 : 기존(레거시) 동작
*/
