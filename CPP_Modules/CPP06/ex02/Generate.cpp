#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base* generate()
{
	std::srand(std::time(0));
	int randomNum = std::rand() % 3;

	if (randomNum == 0)
		return new A();
	else if (randomNum == 1)
		return new B();
	else
		return new C();
}

void identify(Base* p)
{
	if (p == NULL)
		std::cout << "It;s null" << std::endl;
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
}

void identify(Base& p)
{
	try
	{
		(void)dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
		return ;
	} 
	catch (...){}
	try
	{
		// Try casting to B directly without assigning to a variable
		(void)dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
		return ;
	} 
	catch (...) {}
	try
	{
		// Try casting to C directly without assigning to a variable
		(void)dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
		return ;
	}
	catch (...) {}
}
