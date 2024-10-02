#pragma once

#include <iostream>
#include <stdexcept>
#include <string>

template <typename T>
class Array
{
	private:
		T* data;
		unsigned int _size;
	public:
		Array();
		Array(unsigned int n);
		Array(const Array& copy);
		Array& operator=(const Array& copy);
		~Array();
		unsigned int size() const;
		class OutOfBounds : public std::exception
		{
			public:
				const char* what(void) const throw();
		};
		T& operator[](unsigned int i) const;
};
#include "Array.tpp"
