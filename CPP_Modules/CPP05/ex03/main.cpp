#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
    try {
        Intern someRandomIntern;
        Bureaucrat bureaucrat("John", 2);
        AForm* form1 = someRandomIntern.makeForm("shrubbery", "Home");
        // AForm* form2 = someRandomIntern.makeForm("robotomy request", "Bender");
        // AForm* form3 = someRandomIntern.makeForm("presidential pardon", "Arthur Dent");
        // AForm* form4 = someRandomIntern.makeForm("invalid form", "Nobody");

        bureaucrat.signForm(*form1);
        bureaucrat.executeForm(*form1);
        delete form1;
        // No need to delete form4, since it will be nullptr
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}