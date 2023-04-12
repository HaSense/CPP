#include <iostream>
#include <list>

template <typename T>
class Stack {
public:
    void push(const T& item) {
        data_.push_front(item);
    }
    
    void pop() {
        data_.pop_front();
    }
    
    T top() const {
        return data_.front();
    }
    
    bool empty() const {
        return data_.empty();
    }
    
private:
    std::list<T> data_;
};

int main() {
    Stack<int> stack;
    
    stack.push(1);
    stack.push(2);
    stack.push(3);
    
    while (!stack.empty()) {
        std::cout << stack.top() << " ";
        stack.pop();
    }
    
    std::cout << std::endl;
    
    return 0;
}
