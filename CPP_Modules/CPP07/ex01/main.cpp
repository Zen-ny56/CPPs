#include "iter.hpp"

void printInt(int x)
{
	std::cout << x << " ";
}

void printString(const std::string& str)
{
	std::cout << str << " ";
}

template <typename T>
void increment(T& x)
{
	x++;
}

// int square(int x)
// {
//     return x * x;
// }

// std::string toUpperCase(const std::string& str)
// {
// 	std::string result;
// 	for (char c : str)
//         result += std::toupper(c);
//     return result;
// }

int main()
{
	int intArray[] = {1, 2, 3, 4, 5};
	size_t intArrayLength = sizeof(intArray) / sizeof(intArray[0]);

	std::cout << "Original integer array: ";
	iter(intArray, intArrayLength, printInt);
	std::cout << std::endl;

	// Increment each element in the integer array
	iter(intArray, intArrayLength, increment<int>);

	std::cout << "After incrementing: ";
	iter(intArray, intArrayLength, printInt);
	std::cout << std::endl;

	// Test with an array of strings
	std::string strArray[] = {"Hello", "World", "C++", "Templates"};
	size_t strArrayLength = sizeof(strArray) / sizeof(strArray[0]);

	std::cout << "String array: ";
	iter(strArray, strArrayLength, printString);
	std::cout << std::endl;

	return 0;
}