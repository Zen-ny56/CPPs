#pragma once

#include <iostream>
#include <string>
#include <stdexcept>
#include <sstream>
#include "Form.hpp"

class Form;

class   Bureaucrat 
{
	private:
	 	const std::string name;
		int grade;
	public:
		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat& copy);
		Bureaucrat& operator=(const Bureaucrat& copy);
		~Bureaucrat();
		void	increment();
		void	decrement();
		int 	getGrade(void) const;
		std::string		getName(void) const;
		void signForm(Form& form) const;
		class GradeTooHighException: public std::exception
		{
			public:
        		const char* what() const throw();
		};
		class GradeTooLowException: public std::exception
		{
			public:
				const char* what() const throw();
		};

};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);