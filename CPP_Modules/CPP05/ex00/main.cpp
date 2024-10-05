#include "Bureaucrat.hpp"

int main() {
    try {
        Bureaucrat b1("Alice", -2147483648);
        std::cout << b1 << std::endl;

        b1.increment();
        std::cout << b1 << std::endl;
        b1.increment();
    }
    catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    try {
        Bureaucrat b2("Bob", 123);
        std::cout << b2 << std::endl;
        b2.decrement();
        std::cout << b2 << std::endl;
        b2.decrement();
    }
    catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    try {
        Bureaucrat b3("Charlie", 0);
    }
    catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}