#pragma once 

#include <string>
#include <iostream>
#include <cstdlib> 
#include <limits>
#include <cstring> 
#include <stdexcept>
#include <cerrno>
#include <sstream>
#include <cstdio>
#include <cmath>

typedef enum e_type {
	UNKNOWN,  // unknown datatype 
	CHAR,     // char datatype 
	INT,      // int datatype
	FLOAT,    // float datatype
	DOUBLE,   // double datatype
	PINFF,    // positive infinity FLOAT
	NINFF,    // Negative infinity FLOAT
	NANNF,    // Non-Displayable FLOAT
	PINF,     // positive infinity DOUBLE
	NINF,     // Negative infinity DOUBLE
	NANN      // Non-Displayable DOUBLE
} t_type;

class ScalarConverter
{
	private:
		ScalarConverter(); 
		ScalarConverter(const ScalarConverter&); 
		ScalarConverter& operator=(const ScalarConverter&);
		static bool isInteger(const std::string& literal);
		static bool isFloat(const std::string& literal);
		static bool isDouble(const std::string& literal);
		static bool isSpecialFloat(const std::string& literal);
		static bool isSpecialDouble(const std::string& literal);
		static void	convertChar(const std::string& literal);
		static void	convertFloat(const std::string& literal);
		static void	convertDouble(const std::string& literal);
		static void	convertInt(const std::string& literal);
	public:
		~ScalarConverter();
		static void convert(const std::string& literal);
		static void	printConversions(char c, int i, float f, double d, const std::string& literal);
		static t_type detect_type(const std::string& literal);
		class UnknownTypeException: public std::exception
		{
			public:
				const char* what() const throw();
		};
		class EmptyStringException : public std::exception
		{
			public:
				const char* what(void) const throw();
		};
		class WhiteSpaceException : public std::exception
		{
			public:
				const char* what(void) const throw();
		};
		class OutOfRangeException : public std::exception
		{
			public:
				const char* what(void) const throw();
		};
};