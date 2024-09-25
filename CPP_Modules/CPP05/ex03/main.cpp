#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
    try {
        Intern someRandomIntern;
        Bureaucrat bureaucrat("John", 2);

        AForm* form1 = someRandomIntern.makeForm("shrubbery creation", "Home");
        AForm* form2 = someRandomIntern.makeForm("robotomy request", "Bender");
        AForm* form3 = someRandomIntern.makeForm("presidential pardon", "Arthur Dent");
        // AForm* form4 = someRandomIntern.makeForm("invalid form", "Nobody");

        if (form1) {
            bureaucrat.signForm(*form1);
            bureaucrat.executeForm(*form1);
            delete form1;
        }

        if (form2) {
            bureaucrat.signForm(*form2);
            bureaucrat.executeForm(*form2);
            delete form2;
        }

        if (form3) {
            bureaucrat.signForm(*form3);
            bureaucrat.executeForm(*form3);
            delete form3;
        }

        // No need to delete form4, since it will be nullptr
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}