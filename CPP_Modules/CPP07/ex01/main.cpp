#include "iter.hpp"

template <typename T>
void print(T& x)
{
	std::cout << x << " ";
}

template <typename T>
void increment(T& x)
{
	x++;
}

template <typename T>
void square(T& x)
{
    x = x * x;
}

int main()
{
	int intArray[] = {1, 2, 3, 4, 5};
	size_t intArrayLength = sizeof(intArray) / sizeof(intArray[0]);

	std::cout << "Original integer array: ";
	iter(intArray, intArrayLength, print);
	std::cout << std::endl;

	// Increment each element in the integer array
	iter(intArray, intArrayLength, square<int>);

	std::cout << "After incrementing: ";
	iter(intArray, intArrayLength, print);
	std::cout << std::endl;

	// Test with an array of strings
	double dubArray[] = {3.5, 8.2, 21.2};
	size_t dubArrayLength = sizeof(dubArray) / sizeof(dubArray[0]);

	std::cout << "Double array: ";
	iter(dubArray, dubArrayLength, print);
	iter(dubArray, dubArrayLength, square<double>);
	std::cout << std::endl;
	iter(dubArray, dubArrayLength, print);
	std::cout << std::endl;

	const std::string strArray[] = {"C++", "Is", "Awesome"};
	size_t strArrayLength= sizeof(strArray) / sizeof(strArray[0]);
	std::cout << "String array: ";
	iter(strArray, strArrayLength, print);
	std::cout << std::endl;
	return 0;
}