#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target): AForm("PresidentialPardonForm", 25, 5), target(target)
{
    std::cout << "Parametized constructor has been called\n" << std::endl;
};

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& copy) : AForm(copy)
{
    std::cout << "PresidentialPardonForm Copy constructor has been called" << std::endl;
};

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& copy) 
{
    if (this != &copy)
        AForm::operator=(copy);
    std::cout << "PresidentialPardonForm Copy assignment operator has been called" << std::endl;
    return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout << "PresidentialPardonForm deconstructor has been called\n" << std::endl;
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
    if (AForm::getIsSigned() == false)
        throw AForm::FormNotSignedException();
    if (executor.getGrade() > AForm::getExecuteGrade())
        throw AForm::GradeTooLowException();
    std::cout << target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
