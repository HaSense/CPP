#include <iostream>
#include <map>
#include <string>

int main() {
    std::string text = "hello world";
    
    std::map<char, int> freq;
    
    for (const auto& ch : text) {
        freq[ch]++;
    }
    
    for (const auto& pair : freq) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }
    
    return 0;
}
