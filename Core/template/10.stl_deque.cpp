#include <iostream>
#include <deque>

template <typename T>
class Queue {
public:
    void push(const T& item) {
        data_.push_back(item);
    }
    
    void pop() {
        data_.pop_front();
    }
    
    T front() const {
        return data_.front();
    }
    
    bool empty() const {
        return data_.empty();
    }
    
private:
    std::deque<T> data_;
};

int main() {
    Queue<int> queue;
    
    queue.push(1);
    queue.push(2);
    queue.push(3);
    
    while (!queue.empty()) {
        std::cout << queue.front() << " ";
        queue.pop();
    }
    
    std::cout << std::endl;
    
    return 0;
}
