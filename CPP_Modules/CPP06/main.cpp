#include "ScalarConverter.hpp"
#include <iostream>

int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		std::cerr << "Usage: ./convert <literal>" << std::endl;
		return 1;
	}
	try 
	{
		ScalarConverter::convert(argv[1]);
	} catch (const ScalarConverter::UnknownTypeException& e)
	{
		std::cerr << e.what() << std::endl; // Output the error message
		return 1; // Return error code
	} catch (const ScalarConverter::OutOfRangeException &e)
	{
		std::cerr << e.what() << std::endl;
		return 1;
	}
	catch (const ScalarConverter::EmptyStringException &e)
	{
		std::cerr << e.what() << std::endl;
		return 1;
	}
	catch (const ScalarConverter::WhiteSpaceException &e)
	{
		std::cerr << e.what() << std::endl;
		return 1;
	}
	return 0;
}
