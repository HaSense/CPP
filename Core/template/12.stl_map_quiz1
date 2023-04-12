#include <iostream>
#include <map>
#include <string>

int main() {
    std::map<std::string, double> scores = {
        { "Alice", 85.0 },
        { "Bob", 75.0 },
        { "Charlie", 90.0 },
        { "David", 80.0 },
        { "Emily", 95.0 }
    };
    
    double total = 0.0;
    for (auto& kv : scores) {
        total += kv.second;
    }
    
    double avg = total / scores.size();
    
    std::cout << "Average score: " << avg << std::endl;
    
    return 0;
}
