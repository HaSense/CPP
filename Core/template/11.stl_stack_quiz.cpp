#include <iostream>
#include <stack>
#include <string>

int main() {
    std::string str = "Hello, world!";
    std::stack<char> st;

    // 문자열을 스택에 삽입
    for (char c : str) {
        st.push(c);
    }

    // 스택에서 문자열 뒤집어 출력
    while (!st.empty()) {
        std::cout << st.top();
        st.pop();
    }
    std::cout << std::endl;

    return 0;
}
