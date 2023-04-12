#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> numbers = { 4, 2, 7, 1, 8, 3, 5, 9, 6 };
    
    std::sort(numbers.begin(), numbers.end());
    
    for (const auto& number : numbers) {
        std::cout << number << " ";
    }
    
    std::cout << std::endl;
    
    return 0;
}
