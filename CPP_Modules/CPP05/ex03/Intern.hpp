#pragma once

#include "Intern.hpp"
#include "AForm.hpp"
#include <string>
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
	public:
    	Intern();
    	Intern(const Intern& other);
    	Intern& operator=(const Intern& other);
    	~Intern();
    	AForm* makeForm(const std::string& formName, const std::string& target) const;

		class ForNotException: public std::exception
		{
			public:
				const char* what() const throw();
		};
};
