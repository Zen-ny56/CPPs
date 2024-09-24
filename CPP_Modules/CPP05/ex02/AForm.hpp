#pragma once

#include "Bureaucrat.hpp"

class Bureaucrat; // Forward declaration to inform the compiler the existence without fully defining it 

class AForm
{
	private:
		const std::string name; // Name of the Bu....
		bool isSigned; // Whether the AForm is sign
		unsigned int signGrade; // Grade needed to sign AForm
		unsigned int executeGrade; // Grade needed to execute AForm
	public:
		AForm(const std::string name, int signGrade, int executeGrade);
		AForm(const AForm &copy);
		AForm& operator=(const AForm &other);
		virtual ~AForm();
		virtual void execute(Bureaucrat const & executor) const = 0;
		class GradeTooHighException : public std::exception
		{
			public:
				const char* what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				const char* what() const throw();
		};
		class FormNotSignedException : public std::exception
		{
			public:
        		const char* what() const throw();
    	};

};

std::ostream& operator<<(std::ostream& os, const AForm& aform);