#include <iostream>

using namespace std;

template <typename T>
T Max(T a, T b) {
    return (a > b) ? a : b;
}

int main()
{
    cout << Max(100, 200) << endl;
    cout << Max(200.45, 100.37) << endl;
    cout << Max('C', 'F') << endl;
    
    return 0;
}
