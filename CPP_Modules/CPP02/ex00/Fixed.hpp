#pragma once
#include <iostream>

class Fixed
{
	private:
		int	fixed_point;
		static const int fractional;
	public:
		Fixed();
		Fixed(const Fixed& copy);
		Fixed& operator=(const Fixed& copy);
		~Fixed();
		int	getRawBits(void) const;
		void setRawBit(int const raw);
};