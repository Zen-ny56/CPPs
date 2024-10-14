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
	std::vector<std::pair<int, int> > pairs;
	for (size_t i = 0; i < integerList.size(); i += 2)
	{
		if (i + 1 < integerList.size()) // Ensure we don't go out of bounds
		{
			if (integerList[i] > integerList[i + 1])
				pairs.push_back(std::make_pair(integerList[i + 1], integerList[i]));
			else
				pairs.push_back(std::make_pair(integerList[i], integerList[i + 1]));
		}
		else
		{
			// Handle odd length by adding the last element as a pair with itself
			pairs.push_back(std::make_pair(integerList[i], integerList[i]));
		}
    }
    // Display pairs (optional for debugging)
    std::cout << "Pairs (less, greater): ";
    for (size_t i = 0; i < pairs.size(); ++i)
    {
        std::cout << "(" << pairs[i].first << ", " << pairs[i].second << ") ";
    }
    std::cout << std::endl;
	std::vector<int> greaterElements;
	for (size_t i = 0; i < pairs.size(); ++i)
	{
    	greaterElements.push_back(pairs[i].second);
	}// Sort the greater elements using std::sort
	std::sort(greaterElements.begin(), greaterElements.end());
	// Display sorted greater elements (optional for debugging)
	std::cout << "Sorted Greater Elements: ";
	for (size_t i = 0; i < greaterElements.size(); ++i)
	{
    	std::cout << greaterElements[i] << " ";
	}
	std::cout << std::endl;
	std::vector<int> S = greaterElements;  // Sequence 'S'
	// Display the sequence S (optional for debugging)
	std::cout << "Sequence S: ";
	for (size_t i = 0; i < S.size(); ++i)
	{
    	std::cout << S[i] << " ";
	}
	std::cout << std::endl;
	std::vector<int> pend;
	for (size_t i = 0; i < pairs.size(); ++i)
	{
    	pend.push_back(pairs[i].first);
	}
	// Display the pend array (optional for debugging)
	std::cout << "Pend: ";
	for (size_t i = 0; i < pend.size(); ++i)
	{
    	std::cout << pend[i] << " ";
	}
	std::cout << std::endl;	
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