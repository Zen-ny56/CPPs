#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

int main()
{
	Bureaucrat john("John", 1);
	ShrubberyCreationForm shrubbery("home");
	RobotomyRequestForm robotomy("John");
	PresidentialPardonForm pardon("Alice");

	// Signing forms
	john.signForm(shrubbery);
	john.signForm(robotomy);

	// Executing forms
	john.executeForm(shrubbery);   // should create a shrubbery file
	john.executeForm(robotomy);    // 50% chance of success
	john.executeForm(pardon);      // fails due to low grade
}