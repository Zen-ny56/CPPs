#include "MutantStack.hpp"

template<typename T>
MutantStack<T>::MutantStack() : std::stack<T>()
{
	std::cout << "Constructor has been called" << std::endl;
}

template<typename T>
MutantStack<T>::MutantStack(const MutantStack<T>& other) : std::stack<T>(other)
{
	std::cout << "Copy constructor has been called" << std::endl;
}

template<typename T>
MutantStack<T>& MutantStack<T>::operator=(const MutantStack<T>& other)
{
	if (this != &other)
		std::stack<T>::operator=(other);
	std::cout << "Copy assignment operator has been called" << std::endl;
    return *this;
}

// Destructor
template<typename T>
MutantStack<T>::~MutantStack()
{
	std::cout << "Deconstructor has been called" << std::endl;
}

// Iterator begin function
template<typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin()
{
	return std::stack<T>::c.begin();
}

template<typename T>
typename MutantStack<T>::iterator MutantStack<T>::end()
{
	return std::stack<T>::c.end();
}

template<typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::begin() const
{
    return std::stack<T>::c.begin();
}

// Const iterator end function
template<typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::end() const
{
    return std::stack<T>::c.end();
}