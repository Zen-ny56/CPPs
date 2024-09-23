#pragma once

#include "Bureaucrat.hpp"

class Bureaucrat; // Forward declaration to inform the compiler the existence without fully defining it 

class Form
{
	private:
		const std::string name; // Name of the Bu....
		bool isSigned; // Whether the form is sign
		unsigned int signGrade; // Grade needed to sign form
		unsigned int executeGrade; // Grade needed to execute form
	public:
		Form(const std::string name, int signGrade, int executeGrade); // Takes name of Bureaucra and the signing grade and execution grade of the bureaucrat
		Form(const Form &copy); // Copy constructor
		Form& operator=(const Form &other); //
		~Form();
		//Getter methods
		std::string getName() const; // Getter 
		bool getIsSigned() const; // 
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