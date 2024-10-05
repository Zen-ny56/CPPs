#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

int main()
{
	try
	{
		Bureaucrat john("Jog", 134);
		// ShrubberyCreationForm shrubbery("home");
		// RobotomyRequestForm robotomy("John");
		PresidentialPardonForm pardon("Alice");

		// Signing forms
		// john.signForm(shrubbery);
		// john.signForm(robotomy);
		john.signForm(pardon);
		john.printsomethin();
	// Executing forms
	// john.executeForm(shrubbery);   // should create a shrubbery file
	// john.executeForm(robotomy);    // 50% chance of success
	john.executeForm(pardon);      // fails due to low grade
	}
	catch (const std::exception& e){
		std::cerr << e.what() << std::endl;
	}
}