#include "PmergeMe.hpp"

void PmergeMe::meVec(const std::string& literal)
{
	processInput(literal);
}

void PmergeMe::meDeq(const std::string& literal)
{
	// You can implement similar logic here for deque if needed
	processInput(literal);  // Just for demonstration; you might want to adjust this
}

void PmergeMe::processInput(const std::string& input)
{
	std::stringstream ss(input);
	std::vector<int> integerList;
	std::string token;
	// Step 2: Tokenize the input and validate each token
	while (ss >> token)
	{
		// Step 3: Validate the argument
		if (!isValidPositiveInteger(token))
			throw std::runtime_error("Error: Invalid input");  // Exit on error
		int number = std::atoi(token.c_str());
		if (number <= 0) {
			throw std::runtime_error("Error: Invalid input");  // Exit on error
		}
		integerList.push_back(number);
	}
	// Step 4: Display the "Before" sequence
	std::cout << "Before: ";
	for (size_t i = 0; i < integerList.size(); ++i)
	{
		std::cout << integerList[i];
		if (i < integerList.size() - 1) {
			std::cout << " ";  // Add space between numbers
        }
    }
    std::cout << std::endl; // Move to the next line
	std::cout << "Contents of integerList: ";
	for (size_t i = 0; i < integerList.size(); ++i) {
		std::cout << integerList[i] << " "; // Print each integer
	}
	std::cout << std::endl; // Move to the next line	
}

bool PmergeMe::isValidPositiveInteger(const std::string& str)
{
	// Check if the string is empty or contains any non-digit characters
	if (str.empty()) return false;
	for (size_t i = 0; i < str.length(); ++i) {
		if (!std::isdigit(str[i])) return false;
	}
	return true;
}