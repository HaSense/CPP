#include <iostream>

namespace my {
    class Point {
    public:
        Point(int x = 0, int y = 0) : x(x), y(y) {}

        // Copy constructor(복사 생성자)
        Point(const Point& other) : x(other.x), y(other.y) {}

        int x, y;
    };

    std::ostream& operator<<(std::ostream& os, const Point& p) {
        os << "(" << p.x << ", " << p.y << ")";
        return os;
    }
}

int main() {
    my::Point p1(1, 2);
    my::Point p2 = p1; //복사 생성자를 이용한 복사

    std::cout << "p1: " << p1 << "\n";
    std::cout << "p2: " << p2 << "\n";

    return 0;
}
