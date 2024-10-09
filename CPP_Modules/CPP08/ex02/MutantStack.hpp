#pragma once
#include <stack>
#include <iterator>
#include <iostream>

template <typename T>
class MutantStack : public std::stack<T> // Not a true container but an adapter that wraps around internal constainers such as <std::deque> , or <std::vector>
{
	public:
		typedef typename std::stack<T>::container_type::iterator iterator; //Basically grabbing the iterator that belongs to the hidden container 
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
