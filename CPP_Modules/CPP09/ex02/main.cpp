#include "PmergeMe.hpp"

// int main(int ac, char **av)
// {
// 	try
// 	{
// 		if (ac < 2)
// 			throw std::runtime_error("Error: No input provided.");
// 		if (ac == 2)
// 			PmergeMe::meVec(av[1]);
// 		else {
// 			for (int i = 1; i < ac; ++i) {
// 				PmergeMe::meVec(av[i]);
// 			}
// 		}
// 	} catch (const std::exception& e) {
// 		std::cerr << e.what() << std::endl;  // Catch and print the exception message
// 		return 1;  // Return with an error code
// 	}

// 	return 0;  // Success
// }


int main(int ac, char **av)
{
    try
    {
		if (ac < 2)
			throw std::runtime_error("Error: No input provided.");
		std::string input; // To hold concatenated input
		for (int i = 1; i < ac; ++i)
		{
			input += av[i]; // Concatenate arguments
			if (i < ac - 1)
				input += " "; // Add space between numbers
        }
		PmergeMe::meVec(input); // Process the concatenated input
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;  // Catch and print the exception message
		return 1;  // Return with an error code
    }
	return 0;  // Success
}