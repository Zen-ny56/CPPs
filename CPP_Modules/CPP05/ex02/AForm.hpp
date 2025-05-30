#pragma once

#include "Bureaucrat.hpp"
#include <cstdio>
class Bureaucrat; // Forward declaration to inform the compiler the existence without fully defining it 

class AForm
{
	protected:
		const std::string name; // Name of the Bu....
		bool isSigned; // Whether the AForm is sign
		const int signGrade; // Grade needed to sign AForm
		const int executeGrade; // Grade needed to execute AForm
	public:
		AForm();
		AForm(const std::string name, const int signGrade, const int executeGrade);
		AForm(const AForm &copy);
		AForm& operator=(const AForm &other);
		virtual ~AForm();

		std::string getName() const; // Getter 
		bool getIsSigned() const; // Check if the form has been signed
		int getSignGrade() const;
		int getExecuteGrade() const;
	
   		 // Method to sign the form
    	void beSigned(const Bureaucrat& b); 
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