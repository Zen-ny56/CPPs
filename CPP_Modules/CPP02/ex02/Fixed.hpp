#pragma once 

#include <iostream>
#include <cmath>

class Fixed
{
   	private:
		int	fixed_point;
		static const int fractional;
	public:
		Fixed();
		Fixed(const int num);
		Fixed(const float f);
		Fixed& operator=(const Fixed& copy);
		~Fixed();
		int	getRawBits(void) const;
		void setRawBit(int const raw);
		float toFloat(void) const;
		int toInt(void) const;
		bool operator>(const Fixed &other) const;
 		bool operator<(const Fixed &other) const;
		bool operator>=(const Fixed &other) const;
		bool operator<=(const Fixed &other) const;
		bool operator==(const Fixed &other) const;
		bool operator!=(const Fixed &other) const;
		Fixed operator+(const Fixed &other) const;
		Fixed operator-(const Fixed &other) const;
		Fixed operator*(const Fixed &other) const;
		Fixed operator/(const Fixed &other) const;
		Fixed& operator--();
		Fixed operator--(int);
		Fixed& operator++();
		Fixed operator++(int);
		const static Fixed& min(const Fixed& a, const Fixed& b); 
		static Fixed& min(Fixed& a, Fixed& b);
		const static Fixed& max(const Fixed& a, const Fixed& b);
		static Fixed& max(Fixed& a, Fixed& b);
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);