#include "Fixed.hpp"

int main( void )
{
	Fixed a;
	//Copy constructor
	Fixed b(a);
	//Copy assignment contructor
	Fixed c;
	c = b;
	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;
	return 0;
}