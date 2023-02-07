#include <iostream>

class Complex {
public:
    Complex(double real = 0, double imag = 0) : real(real), imag(imag) {}

    double real, imag;

    // Overloading the + operator
    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imag + other.imag);
    }
};

int main() {
    Complex c1(1, 2), c2(3, 4);
    Complex c3 = c1 + c2;

    std::cout << "c1: " << c1.real << " + " << c1.imag << "i\n";
    std::cout << "c2: " << c2.real << " + " << c2.imag << "i\n";
    std::cout << "c3: " << c3.real << " + " << c3.imag << "i\n";

    return 0;
}
