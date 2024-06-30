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

Fixed::Fixed(const int num) : fixed_point(num << fractional)
{
	std::cout << "Int constructor called" << std::endl;
	return ;
}

Fixed::Fixed(const float f) : fixed_point(roundf(f * (1 << fractional)))
{
	std::cout << "Float constructor called" << std::endl;
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

float    Fixed::toFloat(void) const
{
	return  (static_cast<float>(fixed_point) / (1 << fractional));
}

int    Fixed::toInt(void) const
{
	return (fixed_point >> fractional);
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

bool Fixed::operator>(const Fixed &other) const
{
	if (fixed_point > other.fixed_point)
		return (true);
	return (false);
}

bool Fixed::operator<(const Fixed &other) const
{
	if (fixed_point < other.fixed_point)
		return (true);
	return (false);
}

bool Fixed::operator>=(const Fixed &other) const
{
	if (fixed_point >= other.fixed_point)
		return (true);
	return (false);
}

bool Fixed::operator<=(const Fixed &other) const
{
	if (fixed_point <= other.fixed_point)
		return (true);
	return (false);
}

bool Fixed::operator==(const Fixed &other)const
{
	if (fixed_point == other.fixed_point)
		return (true);
	return (false);
}

bool Fixed::operator!=(const Fixed &other)const
{
	if (fixed_point != other.fixed_point)
		return (true);
	return (false);
}

Fixed Fixed::operator+(const Fixed &other) const
{
	Fixed result;
	result = this->fixed_point + other.fixed_point;
	return (result);
}

Fixed Fixed::operator-(const Fixed &other) const
{
	Fixed result;
	result = this->fixed_point - other.fixed_point;
	return (result);
}

Fixed Fixed::operator*(const Fixed &other) const
{
	Fixed result;
	result = this->fixed_point * other.fixed_point;
	return (result);
}

Fixed Fixed::operator/(const Fixed &other) const
{
	Fixed result;
	result = this->fixed_point / other.fixed_point;
	return (result);
}

Fixed& Fixed::operator++()
{
	this->fixed_point++;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed temp = *this;
	this->fixed_point++;
	return (temp);
}

Fixed& Fixed::operator--()
{
	this->fixed_point--;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed temp = *this;
	this->fixed_point--;
	return (temp);
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
    if (a > b)
		return (a);
	else
        return (b);
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
    if (a > b)
		return (a);
	else
		return (b);
}

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
    if (a < b)
        return (a);
	else
        return (b);
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
	os << fixed.toInt();
	return (os);
}