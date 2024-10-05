#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(): AForm()
{
    std::cout << "Robotomy... Default constructor has been called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target): AForm("RobotomyRequestForm", 72, 45), target(target)
{
    std::cout << "Parametized constructor has been called\n" << std::endl;
};

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& copy) : AForm(copy)
{
    std::cout << "RobotomyRequestForm Copy constructor has been called" << std::endl;
};

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& copy) 
{
    if (this != &copy)
        AForm::operator=(copy);
    std::cout << "RobotomyRequestForm Copy assignment operator has been called" << std::endl;
    return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << "RobotomyRequestForm deconstructor has been called\n" << std::endl;
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
    if (AForm::getIsSigned() == false)
        throw AForm::FormNotSignedException();
    if (executor.getGrade() > AForm::getExecuteGrade())
        throw AForm::GradeTooLowException();
    std::cout << "* drilling noises *" << std::endl;
    srand(time(0));
    if (rand() % 2)
        std::cout << target << " has been successfully robotomized." << std::endl;
    else
        std::cout << "Robotomy failed on " << target << std::endl;
}