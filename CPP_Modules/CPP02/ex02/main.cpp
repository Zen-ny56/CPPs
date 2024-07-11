#include "Fixed.hpp"

int main() {
    Fixed a(3.5f);
    Fixed b(2.5f);

    std::cout << "Testing arithmetic operators:" << std::endl;
    std::cout << a << " + " << b << " = " << (a + b) << std::endl;
    std::cout << a << " - " << b << " = " << (a - b) << std::endl;
    std::cout << a << " * " << b << " = " << (a * b) << std::endl;
    std::cout << a << " / " << b << " = " << (a / b) << std::endl;

    return 0;
}