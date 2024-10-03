#include "Form.hpp"
#include "Bureaucrat.hpp"

int main()
{
    try {
        // Creating Bureaucrats with different grades
        Bureaucrat john("John", 4); // High grade
        Bureaucrat alice("Alice", 140); // Low grade

        // Creating Forms with different grade requirements
        Form contract("Contract", 5, 10);
        Form report("Report", 130, 135);

        // Attempting to sign forms
        std::cout << john << std::endl;
        std::cout << contract << std::endl;
        john.signForm(contract);  // Should succeed
        std::cout << contract << std::endl;

        std::cout << alice << std::endl;
        std::cout << report << std::endl;
        alice.signForm(report);  // Should succeed
        std::cout << report << std::endl;

        std::cout << std::endl;

        // Attempt to sign a form where the Bureaucrat's grade is too low
        std::cout << alice << std::endl;
        std::cout << contract << std::endl;
        alice.signForm(contract); // Should fail due to low grade

    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        // Creating Bureaucrat with invalid grade
        Bureaucrat invalidBureaucrat("Invalid", 0);  // Should throw exception

    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}