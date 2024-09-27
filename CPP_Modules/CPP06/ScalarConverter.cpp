#include "ScalarConverter.hpp"

bool ScalarConverter::isInteger(const std::string& literal)
{
	char* endPtr;
	errno = 0;
	if (literal.find('.') != std::string::npos) 
		return (false);
	long intVal = std::strtol(literal.c_str(), &endPtr, 10);
	if (*endPtr == '\0' && errno != ERANGE && intVal >= std::numeric_limits<int>::min() &&
        intVal <= std::numeric_limits<int>::max())
        return true;
    throw OutOfRangeException(); // Handle out of range case
}

// Check if the literal is a float
bool ScalarConverter::isFloat(const std::string& literal)
{
	char* endPtr;
	errno = 0;
	if (literal.find('.') == std::string::npos)
		return (false);
	float floatVal = std::strtof(literal.c_str(), &endPtr);
	(void)floatVal;
	return (*endPtr == 'f' && *(endPtr + 1) == '\0' && errno != ERANGE);
}

// Check if the literal is a double
bool ScalarConverter::isDouble(const std::string& literal)
{
	char* endPtr;
	errno = 0;
	if (literal.find('.') == std::string::npos)
		return (false);
	double doubleVal = std::strtod(literal.c_str(), &endPtr);
	(void)doubleVal;
	return (*endPtr == '\0' && errno != ERANGE);
}

t_type ScalarConverter::detect_type(const std::string& literal)
{
	if (literal.empty())
        throw EmptyStringException();
	if (literal.find_first_not_of(' ') == std::string::npos)
        throw WhiteSpaceException();
	if (literal == "+inff")
		return PINFF;
	else if (literal == "-inff")
		return NINFF;
	else if (literal == "nanf")
		return NANNF;
	else if (literal == "+inf")
		return PINF;
	else if (literal == "-inf")
		return NINF;
	else if (literal == "nan")
		return NANN;
	if (literal.length() == 1 && std::isprint(literal[0]) && !std::isdigit(literal[0]))
		return CHAR;
	if (isInteger(literal))
		return INT;
	if (isFloat(literal))
		return FLOAT;
	if (isDouble(literal))
		return DOUBLE;
	return UNKNOWN;
}

void ScalarConverter::convert(const std::string& literal)
{
	t_type type = detect_type(literal);
	switch (type)
	{
		case UNKNOWN:
			throw UnknownTypeException();
		case CHAR:
			std::cout << "Type: CHAR" << std::endl;
			break;
		case INT:
			std::cout << "Type: INT" << std::endl;
			break;
		case FLOAT:
			std::cout << "Type: FLOAT" << std::endl;
			break;
		case DOUBLE:
			std::cout << "Type: DOUBLE" << std::endl;
			break;
		case PINFF:
			std::cout << "Type: +inff (FLOAT)" << std::endl;
			break;
		case NINFF:
			std::cout << "Type: -inff (FLOAT)" << std::endl;
			break;
		case NANNF:
			std::cout << "Type: nanf (FLOAT)" << std::endl;
			break;
		case PINF:
			std::cout << "Type: +inf (DOUBLE)" << std::endl;
			break;
		case NINF:
			std::cout << "Type: -inf (DOUBLE)" << std::endl;
			break;
		case NANN:
			std::cout << "Type: nan (DOUBLE)" << std::endl;
			break;
	}
}

const char* ScalarConverter::UnknownTypeException::what(void) const throw()
{
    return "Unknown Type";
}

const char* ScalarConverter::EmptyStringException::what(void) const throw()
{
	return "Empty String";
}

const char* ScalarConverter::WhiteSpaceException::what(void) const throw()
{
	return "White Spaces Only";
}


const char* ScalarConverter::OutOfRangeException::what(void) const throw()
{
	return "Out of Range";
}