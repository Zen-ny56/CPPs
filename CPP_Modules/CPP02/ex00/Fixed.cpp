#include "Fixed.hpp"

const int Fixed::fractional = 8;

Fixed::Fixed() : fixed_point(0)
{
    std::cout << "Default constructor called" << std::endl;
    return ;
};

Fixed::~Fixed()
{
    std::cout << "Deconstructor called" << std::endl;
    return ;
};

Fixed::Fixed(const Fixed& copy)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = copy;
    return ;
}

Fixed& Fixed::operator=(const Fixed& copy)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &copy)
        this->fixed_point = copy.getRawBits();
    return (*this);
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return (this->fixed_point);
}

void Fixed::setRawBit(int const raw)
{
    this->fixed_point = raw;
    return ;
}