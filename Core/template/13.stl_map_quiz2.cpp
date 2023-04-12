#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
    map<string, string> phone_book;

    phone_book["Alice"] = "010-1234-5678";
    phone_book["Bob"] = "010-9876-5432";
    phone_book["Charlie"] = "010-5555-5555";

    cout << "Alice's phone number: " << phone_book["Alice"] << endl;
    cout << "Bob's phone number: " << phone_book["Bob"] << endl;
    cout << "Charlie's phone number: " << phone_book["Charlie"] << endl;

    return 0;
}
