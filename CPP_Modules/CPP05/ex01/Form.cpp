#include "Form.hpp"

Form::Form(const std::string name, int signGrade, int executeGrade): name(name), isSigned(false), signGrade(signGrade), executeGrade(executeGrade)
{
	if (signGrade < 1 || executeGrade < 1)
		throw GradeTooHighException();
	if (signGrade > 150 || executeGrade > 150)
		throw GradeTooLowException();
	std::cout << "Form constructor has been called" << std::endl;
	return ;
}

Form::Form(const Form& copy) :name(copy.name), isSigned(copy.isSigned), signGrade(copy.signGrade), executeGrade(copy.executeGrade)
{
	std::cout << "Copy Constructor has been called" << std::endl;
	*this = copy;
}

Form& Form::operator=(const Form &copy)
{
	std::cout << "Copy assignment operator has been called" << std::endl;
	if (this != &copy)
	{
		this->isSigned = copy.getIsSigned();
		this->signGrade = copy.getSignGrade();
		this->executeGrade = copy.getExecuteGrade();
	}
	return (*this);
}

Form::~Form()
{
	std::cout << "Form destructor called" << std::endl;
}

std::string Form::getName() const
{
	return (this->name);
}

bool Form::getIsSigned() const
{
	return (this->isSigned);
}

int Form::getSignGrade() const
{
	return (this->signGrade);
}

int Form::getExecuteGrade() const
{
	return (this->executeGrade);
}

// beSigned method: checks if the form has a high enough grade to sign 
void Form::beSigned(const Bureaucrat& b)
{
	if (b.getGrade() > this->signGrade)
		throw GradeTooLowException();
	this->isSigned = true;
}

// Exception definitions
const char* Form::GradeTooHighException::what() const throw()
{
	return ("Form grade is too high!");
}

const char* Form::GradeTooLowException::what() const throw()
{
	return ("Form grade is too low!");
}

std::ostream& operator<<(std::ostream& os, const Form& form)
{
	os	<< "Form: " << form.getName() 
		<< ", Signed: " << (form.getIsSigned() ? "Yes" : "No") 
		<< ", Sign Grade: " << form.getSignGrade() 
		<< ", Execute Grade: " << form.getExecuteGrade();
	return (os);
}