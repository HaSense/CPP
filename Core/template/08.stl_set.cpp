//set을 이용한 중복제거

#include <iostream>
#include <set>
#include <vector>

int main() {
    std::vector<int> numbers = { 1, 2, 3, 4, 5, 3, 2, 1, 4, 5 };
    
    std::set<int> unique_numbers;
    
    for (const auto& number : numbers) {
        unique_numbers.insert(number);
    }
    
    for (const auto& number : unique_numbers) {
        std::cout << number << " ";
    }
    
    std::cout << std::endl;
    
    return 0;
}
