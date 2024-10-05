#include "Form.hpp"
#include "Bureaucrat.hpp"

int main() {
    try {
        // Create a Bureaucrat with a low grade
        Bureaucrat john("John", 100);  // Grade is too low for contract

        // Create a form that requires a high grade to sign
        Form contract("Contract", 50, 5);

        // Try signing the form (this should throw)
        john.signForm(contract);
    } catch (const std::exception& e) {
        std::cerr << "Exception caught in main: " << e.what() << std::endl;
    }

    // After catching the exception, program continues to run
    std::cout << "Program continues running after exception.\n";

    // Create another Bureaucrat and Form to show the program hasn't terminated
    Bureaucrat alice("Alice", 10);  // High grade
    Form report("Report", 20, 52);

    // Try signing a form where Alice's grade is sufficient
    alice.signForm(report);

    return 0;
}