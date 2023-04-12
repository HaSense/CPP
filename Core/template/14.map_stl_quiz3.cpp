#include <iostream>
#include <map>
#include <sstream>
#include <string>

using namespace std;

int main() {
    string str = "the quick brown fox jumps over the lazy dog";
    map<string, int> freq;
    istringstream iss(str);

    string word;
    while (iss >> word) {
        freq[word]++;
    }

    for (auto it : freq) {
        cout << "'" << it.first << "' appears " << it.second << " times." << endl;
    }

    return 0;
}
