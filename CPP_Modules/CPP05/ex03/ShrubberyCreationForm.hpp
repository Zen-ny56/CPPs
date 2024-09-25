#pragma once

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

class ShrubberyCreationForm: public AForm
{
    private:
        std::string target;
    public:
        ShrubberyCreationForm();
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm &copy);
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
		~ShrubberyCreationForm();
		void execute(Bureaucrat const &executor) const;
};