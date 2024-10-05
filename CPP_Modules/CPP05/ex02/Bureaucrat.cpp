#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
{
	std::cout << "Default Constructor called" << std::endl;
	return ;
}

Bureaucrat::Bureaucrat(const std::string name, int grade) :name(name)
{
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
	this->grade = grade;
	std::cout << "Constructor has been called" << std::endl;
	return ;
}

Bureaucrat::Bureaucrat(const Bureaucrat& copy) :name(copy.name), grade(copy.grade)
{
	std::cout << "Copy Constructor has been called" << std::endl;
	*this = copy;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &copy)
{
	std::cout << "Copy assignment operator has been called" << std::endl;
	if (this != &copy)
	{
		this->grade = copy.getGrade();
	}
	return (*this);
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat Deconstructor has been called" << std::endl;
	return ;
}

std::string Bureaucrat::getName(void) const
{
	return (name);
}

int Bureaucrat::getGrade(void) const
{
	return (grade);
}

void    Bureaucrat::increment(void)
{
	if (grade - 1 < 1)
		throw GradeTooHighException();
	--grade;
}

void	Bureaucrat::decrement(void)
{
	if (grade + 1 > 150)
		throw GradeTooLowException();
	++grade;
}

void Bureaucrat::signForm(AForm& form) const
{
    try {
        form.beSigned(*this);
        std::cout << name << " signed " << form.getName() << std::endl;
    } catch (std::exception& e) {
        std::cout << name << " couldn’t sign " << form.getName() << " because " << e.what() << std::endl;
    }
}

void Bureaucrat::executeForm(const AForm& form) const
{
    try {
        form.execute(*this);
        std::cout << this->getName() << " executed " << form.getName() << std::endl;
    } catch (std::exception &e) {
        std::cerr << this->getName() << " couldn't execute form: " << e.what() << std::endl;
    }
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat)
{
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	return (os);
}

const char* Bureaucrat::GradeTooHighException::what(void) const throw() {
    return "Bureaucrat's Grade is too High!";
}

const char* Bureaucrat::GradeTooLowException::what(void) const throw(){
    return "Bureaucrat's Grade is too Low!";
}