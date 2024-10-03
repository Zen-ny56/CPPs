#pragma once
#include <stack>
#include <iterator>
#include <iostream>

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		typedef typename std::stack<T>::container_type::iterator iterator;
		typedef typename std::stack<T>::container_type::const_iterator const_iterator;

	MutantStack();
	MutantStack(const MutantStack& other);
	~MutantStack();
	MutantStack& operator=(const MutantStack& other);
	
	iterator begin();
	iterator end();
	const_iterator begin() const;
	const_iterator end() const;
};

#include "MutantStack.tpp"
