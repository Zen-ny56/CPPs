#include "MutantStack.hpp"

int main()
{
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << " Top of the stack" << std::endl;
	mstack.pop();
	std::cout << mstack.top() << " Top after popping" << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(4);
	mstack.push(0);
	std::cout << mstack.size() << " Size" << std::endl;
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	// ++it;
	// --it;
	while (it != ite)
	{
		std::cout << *it << " Element in stack" << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
	return(0);
}