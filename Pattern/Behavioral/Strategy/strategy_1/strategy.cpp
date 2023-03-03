#include <iostream>
#include "Strategy.h"
#include "WallFollowerStrategy.hpp"
using namespace std;

class Strategy {
public:
    virtual void drive() = 0;
};

class WallFollowerStrategy : public Strategy {
public:
    void drive() override {
        // 오른쪽 벽을 따라서 주행하는 로직을 구현
        cout << "오른쪽 벽을 따라서 주행" << endl;
    }
};

class AvoidanceStrategy : public Strategy {
public:
    void drive() override {
        // 장애물을 피해 주행하는 로직을 구현
        cout << "장애물을 피하는 로직 수행" << endl;
    }
};

class Context {
private:
    Strategy* strategy_;
public:
    Context(Strategy* strategy) : strategy_(strategy) {}
    void set_strategy(Strategy* strategy) {
        strategy_ = strategy;
    }
    void execute_strategy() {
        strategy_->drive();
    }
};

int main() {
    // WallFollowerStrategy 객체 생성
    Strategy* my_strategy = new WallFollowerStrategy();
    // Context 객체 생성
    Context* context = new Context(my_strategy);
    // Wall
    context->set_strategy(my_strategy);
    context->execute_strategy();

    // AvoidanceStrategy 객체 생성
    my_strategy = new AvoidanceStrategy();
    // 로봇 자동차의 주행 전략을 변경하여 AvoidanceStrategy를 실행
    context->set_strategy(my_strategy);
    context->execute_strategy();

    return 0;
}
