#include <iostream>
#include <list>
#include "easyfind.hpp"

int main()
{
	std::list<int> numbers;
	numbers.push_back(10);
	numbers.push_back(20);
	numbers.push_back(30);
	// numbers.push_back(40);
	// numbers.push_back(50);
	try
	{
		std::list<int>::iterator it = easyfind(numbers, 30);
		std::cout << "Found: " << *it << std::endl;
		it = easyfind(numbers, 100);
		std::cout << "Found: " << *it << std::endl;
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return 0;
}