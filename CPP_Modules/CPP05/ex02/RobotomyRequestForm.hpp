#pragma once

#include "AForm.hpp"

class RobotomyRequestForm: public AForm
{
    private:
        std::string target;
    public:
        RobotomyRequestForm();
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(const RobotomyRequestForm &copy);
		RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
		~RobotomyRequestForm();
		void execute(Bureaucrat const &executor) const;
};