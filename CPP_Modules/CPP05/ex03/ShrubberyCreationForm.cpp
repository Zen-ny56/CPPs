#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): AForm("ShrubberyCreationForm", 145, 137), target(target)
{
    std::cout << "Parametized constructor has been called\n" << std::endl;
};

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& copy) : AForm(copy)
{
    std::cout << "ShrubberyCreationForm Copy constructor has been called" << std::endl;
};

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& copy) 
{
    if (this != &copy)
        AForm::operator=(copy);
    std::cout << "ShrubberyCreationForm Copy assignment operator has been called" << std::endl;
    return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << "ShrubberyCreationForm deconstructor has been called\n" << std::endl;
}


void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
    if (AForm::getIsSigned() == false)
        throw AForm::FormNotSignedException();
     if (executor.getGrade() > AForm::getExecuteGrade())
        throw AForm::GradeTooLowException();
    //Creating a new file
    std::ofstream file((target + "_shrubbery").c_str());
    if (file.is_open())
    {
        file << "  ###\n #####\n#######\n  |||\n  |||\n";
        file.close();
        std::cout << "Shrubbery has been created at " << target << std::endl;
    } else {
        std::cerr << "Error: Could not open file." << std::endl;
    }
}