#include "ScalarConverter.hpp"

//Detect Input
bool ScalarConverter::isInteger(const std::string& literal)
{
    char* endPtr;
    errno = 0;

    if (literal.find('.') != std::string::npos)
        return false;
    long intVal = std::strtol(literal.c_str(), &endPtr, 10);
    if (*endPtr == '\0' && errno != ERANGE && (intVal >= std::numeric_limits<int>::min() &&
        intVal <= std::numeric_limits<int>::max()))
        return true;
    throw OutOfRangeException();  // Throw if out of range
}

bool ScalarConverter::isFloat(const std::string& literal)
{
	char* endPtr;
	errno = 0;

	if (literal.find('.') == std::string::npos)
		return false;
	float floatVal = std::strtof(literal.c_str(), &endPtr);
	(void)floatVal;
	if (*endPtr == '\0' && *(endPtr - 1) != 'f')
		return (true);
	if (*endPtr != 'f' || *(endPtr + 1) != '\0')
	{
		throw OutOfRangeException();
	}
	return true;
}

bool ScalarConverter::isDouble(const std::string& literal)
{
    char* endPtr;
    errno = 0;
    if (literal.find('.') == std::string::npos)
		return false;
	double doubleVal = std::strtod(literal.c_str(), &endPtr);
   if (errno == ERANGE || *endPtr != '\0' ||
   		doubleVal > std::numeric_limits<double>::max() || doubleVal < std::numeric_limits<double>::min())
	{
		throw OutOfRangeException();
	}
    return true;  // Valid double
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

void ScalarConverter::printConversions(char c, int i, float f, double d, const std::string &literal)
{
	const char* intMinStr = "-2147483648";
	const char* intMaxStr = "2147483647";
	if (std::isprint(c) && (i >= 0 && i <= 127))
        std::cout << "char  : '" << c << "'" << std::endl;
	else if (i < 0 || i > 127)
		std::cout << "char  : Impossible" << std::endl;
	else
        std::cout << "char  : Non displayable" << std::endl;
	if (literal.length() > 11 || (literal.length() == 11 && literal > intMaxStr) || 
        (literal.length() == 11 && literal < intMinStr))
        std::cout << "int   : Impossible" << std::endl;
	else if (std::isinf(f) || std::isnan(f) || std::isinf(d) || std::isnan(d))
		std::cout << "int   : Impossible" << std::endl;
    else if (i >= std::numeric_limits<int>::min() && i <= std::numeric_limits<int>::max())
		std::cout << "int   : " << i << std::endl;
	else
        std::cout << "int   : Impossible" << std::endl;
	 // Handle float conversion
    if (std::isinf(f)) {
        std::cout << "float  : " << (f > 0 ? "+inff" : "-inff") << std::endl;
    } else if (std::isnan(f)) {
        std::cout << "float  : nanf" << std::endl;
    } else {
        std::cout << "float  : " << f;
        if (f == static_cast<int>(f)) {
            std::cout << ".0f" << std::endl;  // Add ".0f" for whole numbers
        } else {
            std::cout << "f" << std::endl;
        }
    }
    // Handle double conversion
    if (std::isinf(d)) {
        std::cout << "double : " << (d > 0 ? "+inf" : "-inf") << std::endl;
    } else if (std::isnan(d)) {
        std::cout << "double : nan" << std::endl;
    } else {
        std::cout << "double : " << d;
        if (d == static_cast<int>(d)) {
            std::cout << ".0" << std::endl;  // Add ".0" for whole numbers
        } else {
            std::cout << std::endl;
        }
    }
}

void	ScalarConverter::convertChar(const std::string& literal)
{ 
	char c = literal[0];
    int i = static_cast<int>(c);
    float f = static_cast<float>(c);
    double d = static_cast<double>(c);
    printConversions(c, i, f, d, literal);
}

void	ScalarConverter::convertInt(const std::string& literal)
{
	char* end;
	errno = 0;
    long i = std::strtol(literal.c_str(), &end, 10);
    char c = static_cast<char>(i);
    float f = static_cast<float>(i);
    double d = static_cast<double>(i);
    printConversions(c, static_cast<int>(i), f, d, literal);
}

void	ScalarConverter::convertDouble(const std::string& literal)
{
	char* end;
	float f = std::strtof(literal.c_str(), &end);
	int i = static_cast<int>(f);
	char c = static_cast<char>(i);
	double d = static_cast<double>(f);
	printConversions(c, i, f, d, literal);
}

void	ScalarConverter::convertFloat(const std::string& literal)
{
	char* end;
	double d = std::strtod(literal.c_str(), &end);
	int i = static_cast<int>(d);
	char c = static_cast<char>(i);
	float f = static_cast<float>(d);
	printConversions(c, i, f, d, literal);
}

void ScalarConverter::convert(const std::string& literal)
{
	t_type type = detect_type(literal);
	switch (type)
	{
		case UNKNOWN:
			throw UnknownTypeException();
		case CHAR:
			convertChar(literal);
			break;
		case INT:
			convertInt(literal);
			break;
		case FLOAT:
			convertFloat(literal);
			break;
		case DOUBLE:
			convertDouble(literal);
			break;
		case PINFF:
			convertFloat(literal);
			break;
		case NINFF:
			convertFloat(literal);
			break;
		case NANNF:
			convertFloat(literal);
			break;
		case PINF:
			convertDouble(literal);
			break;
		case NINF:
			convertDouble(literal);
			break;
		case NANN:
			convertDouble(literal);
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
	return "Invalid Input";
}