#include <iostream>

using namespace std;

template <typename T>
T Max(T a, T b) {
    return a > b ? a : b;
}

class Calculate {
public:
    template <typename T>
    T Maximum(T a, T b) {
        return Max(a, b);
    }
};

int main()
{   
    Calculate cal;
    cout << cal.Maximum(100, 200) << endl;
    cout << cal.Maximum(200.45, 100.37) << endl;
    cout << cal.Maximum('C', 'F') << endl;
    return 0;
}
