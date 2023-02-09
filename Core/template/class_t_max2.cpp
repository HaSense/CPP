//

#include <iostream>

using namespace std;

class Calculate {
public:
    template <typename T>
    T Max(T a, T b) {
        return a > b ? a : b;;
    }
};

int main()
{   
    Calculate cal;
    cout << cal.Max(100, 200) << endl;
    cout << cal.Max(200.45, 100.37) << endl;
    cout << cal.Max('C', 'F') << endl;
    return 0;
}
