#include "Bureaucrat.hpp"

int main() {
    try {
        // Creating a valid bureaucrat
        Bureaucrat b1("Alice", 1);
        std::cout << b1 << std::endl;

        // Incrementing grade (grade goes from 2 to 1)
        b1.increment();
        std::cout << b1 << std::endl;
        // Trying to increment past the upper limit
        b1.increment(); // This should throw GradeTooHighException
    }
    catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    try {
        Bureaucrat b2("Bob", 123);
        std::cout << b2 << std::endl;

        // Decrementing grade (grade goes from 149 to 150)
        b2.decrement();
        std::cout << b2 << std::endl;

        // Trying to decrement past the lower limit
        b2.decrement(); // This should throw GradeTooLowException
    }
    catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    // Attempt to create a bureaucrat with invalid grade
    try {
        Bureaucrat b3("Charlie", 0); // Should throw GradeTooHighException
    }
    catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}