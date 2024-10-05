#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() :signGrade(0), executeGrade(0)
{
	std::cout << "Default constructor has been called" << std::endl;
}

AForm::AForm(const std::string name, int signGrade, int executeGrade): name(name), isSigned(false), signGrade(signGrade), executeGrade(executeGrade)
{
	if (signGrade < 1 || executeGrade < 1)
		throw GradeTooHighException();
	if (signGrade > 150 || executeGrade > 150)
		throw GradeTooLowException();
	std::cout << "AForm constructor has been called" << std::endl;
	return ;
}

AForm::AForm(const AForm& copy) :name(copy.name), isSigned(copy.isSigned), signGrade(copy.signGrade), executeGrade(copy.executeGrade)
{
	std::cout << "Copy Constructor has been called" << std::endl;
	*this = copy;
}

AForm& AForm::operator=(const AForm &copy)
{
	std::cout << "Copy assignment operator has been called" << std::endl;
	if (this != &copy)
	{
		this->isSigned = copy.getIsSigned();
	}
	return (*this);
}

AForm::~AForm()
{
	std::cout << "AForm destructor called" << std::endl;
}

// Getters
std::string AForm::getName() const
{
	return (this->name);
}

bool AForm::getIsSigned() const
{
	return (this->isSigned);
}

int AForm::getSignGrade() const
{
	return (this->signGrade);
}

int AForm::getExecuteGrade() const
{
	return (this->executeGrade);
}

// beSigned method: checks if the AForm has a high enough grade to sign 
void AForm::beSigned(const Bureaucrat& b)
{
	if (b.getGrade() > this->signGrade)
		throw GradeTooLowException();
	this->isSigned = true;
}

// Exception definitions
const char* AForm::GradeTooHighException::what() const throw()
{
	return ("AForm grade is too high!");
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return ("AForm grade is too low!");
}

const char* AForm::FormNotSignedException::what() const throw()
{
	return ("Form has not been signed");
}
std::ostream& operator<<(std::ostream& os, const AForm& aform)
{
	os	<< "AForm: " << aform.getName() 
		<< ", Signed: " << (aform.getIsSigned() ? "Yes" : "No") 
		<< ", Sign Grade: " << aform.getSignGrade() 
		<< ", Execute Grade: " << aform.getExecuteGrade();
	return (os);
}