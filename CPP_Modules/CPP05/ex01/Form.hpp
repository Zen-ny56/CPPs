#pragma once

#include "Bureaucrat.hpp"

class Bureaucrat; // Forward declaration to inform the compiler the existence without fully defining it 

class Form
{
	private:
		const std::string name; // Name of the Bu....
		bool isSigned; // Whether the form is sign
		const int signGrade;
		const int executeGrade;
	public:
		Form();
		Form(const std::string name, const int signGrade, const int executeGrade);
		Form(const Form &copy);
		Form& operator=(const Form &other);
		~Form();

		std::string getName() const;
		bool getIsSigned() const;
		int getSignGrade() const;
		int getExecuteGrade() const;

   		 // Method to sign the form
    	void beSigned(const Bureaucrat& b);

   		 // Exception classes
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
};

std::ostream& operator<<(std::ostream& os, const Form& form);