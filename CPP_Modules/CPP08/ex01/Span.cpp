#include "Span.hpp"

Span::Span(unsigned int N) : maxSize(N)
{
	std::cout << "Span constructor has been called" << std::endl;
}

Span::~Span()
{
	std::cout << "Span deconstructor has been called" << std::endl;
}

Span::Span(const Span& other) : container(other.container), maxSize(other.maxSize)\
{
	std::cout << "Copy constructor has been called" << std::endl;
}

Span& Span::operator=(const Span& other)
{
	if (this != &other)
	{
		container = other.container;
		maxSize = other.maxSize;
	}
	std::cout << "Copy assignment operator has been called" << std::endl;
	return *this;
}

void Span::addNumber(int number)
{
	if (container.size() >= maxSize)
	{
		throw FullSpanException();
	}
	container.push_back(number);
}

int Span::shortestSpan() const
{
	if (container.size() < 2)
	{
		throw NotEnoughElementsException();
	}
	std::vector<int> temp = container;
	std::sort(temp.begin(), temp.end());
	int shortest = std::numeric_limits<int>::max();
	for (unsigned int i = 0; i < temp.size() - 1; ++i)
	{
		int span = temp[i + 1] - temp[i];
		if (span < shortest)
			shortest = span;
	}
	return shortest;
}

int Span::longestSpan() const
{
	if (container.size() < 2)
	{
		throw NotEnoughElementsException();
	}
	int min = *std::min_element(container.begin(), container.end());
	int max = *std::max_element(container.begin(), container.end());
	return max - min;
}

const char* Span::FullSpanException::what() const throw()
{
	return "Span is full. Cannot add more numbers.";
}

const char* Span::NotEnoughElementsException::what() const throw()
{
	return "Not enough elements to calculate a span.";
}
