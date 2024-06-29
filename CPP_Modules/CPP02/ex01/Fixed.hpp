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
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);