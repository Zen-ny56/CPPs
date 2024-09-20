#pragma once

#include "Bureaucrat.hpp"

class Form
{
	private:
		const std::string name;
		bool isSigned;
		unsigned int signGrade;
		unsigned int executeGrade;
	public:
		Form(const std::string name, int signGrade, int executeGrade);
		Form(const Form &copy);
		Form& operator=(const Form &other);
		~Form();
	//Getter methods
	std::string getName() const;
	bool getIsSigned() const;
	int getSignGrade() const;
	int getExecuteGrade() const;
    // Method to sign the form
    void beSigned(const Bureaucrat& bureaucrat);
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