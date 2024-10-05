#include "Intern.hpp"

Intern::Intern()
{
	std::cout << "Intern Default constructor has been called" << std::endl;
}

Intern::Intern(const Intern& other)
{
	(void)other;
	std::cout << "Intern copy constructor has been called" << std::endl;
}

Intern& Intern::operator=(const Intern& other)
{
	(void)other;
	std::cout << "Intern copy assignment operator has been called" << std::endl;
	return (*this);
}

Intern::~Intern()
{
	std::cout << "Intern deconstructor has been called" << std::endl;
}

int getFormIndex(const std::string& formName)
{
	std::string formTypes[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	for (int i = 0; i < 3; i++) {
		if (formName == formTypes[i])
			return (i);
	}
	return (-1);  // Invalid form name
}

AForm* Intern::makeForm(const std::string& formName, const std::string& target) const
{
	switch (getFormIndex(formName))
	{
		case 0: 
			std::cout << "Intern creates ShrubberyCreationForm" << std::endl;
			return (new ShrubberyCreationForm(target));
		case 1:  // RobotomyRequestForm
			std::cout << "Intern creates RobotomyRequestForm" << std::endl;
			return new RobotomyRequestForm(target);
		case 2:  // PresidentialPardonForm
			std::cout << "Intern creates PresidentialPardonForm" << std::endl;
			return new PresidentialPardonForm(target);
		default:
			throw ForNotException();
			return (NULL);
	}
}

const char* Intern::ForNotException::what(void) const throw(){
    return "Form does not exist cannot be created";
}