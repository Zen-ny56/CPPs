#pragma once

#include <vector>
#include <algorithm>
#include <exception>
#include <iostream>
#include <limits>
class Span
{
	private:
		std::vector<int> container;
		unsigned int maxSize;
	public:
		Span(unsigned int N);
		Span(const Span& other);
		Span& operator=(const Span& other);
		~Span();

		void addNumber(int number);
		int shortestSpan() const;
		int longestSpan() const;

		class FullSpanException : public std::exception
		{
			public:
				const char* what() const throw();
		};

		class NotEnoughElementsException : public std::exception
		{
			public:
				const char* what() const throw();
		};
};
