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
std::vector<int> PmergeMe::generateJacobsthal(int n)
{
    std::vector<int> jacobsthal(n);
    jacobsthal[0] = 0; // J(0)
    jacobsthal[1] = 1; // J(1)

    // Generate the Jacobsthal numbers
    for (int i = 2; i < n; ++i) {
        jacobsthal[i] = jacobsthal[i - 1] + 2 * jacobsthal[i - 2];
    }
    return jacobsthal;
}


void PmergeMe::fordJohnsonSort(const std::vector<int>& S, const std::vector<int>& validIndices, const std::vector<int>& pend)
{
	(void)S;
    // Create a vector to hold the extracted elements from arr based on validIndices
    std::vector<int> extractedElements;

    // Extract elements from arr based on validIndices
    for (size_t i = 0; i < validIndices.size(); ++i)
	{
		if (static_cast<size_t>(validIndices[i]) < pend.size()){
			extractedElements.push_back(pend[validIndices[i]]);
		}
	}
    // At this point, extractedElements contains the elements from arr indexed by validIndices
    // You can output or further process extractedElements as needed
    std::cout << "Extracted Elements: ";
    for (size_t i = 0; i < extractedElements.size(); ++i) {
        std::cout << extractedElements[i] << " ";
    }
    std::cout << std::endl;
}

std::vector<int> PmergeMe::getValidIndices(const std::vector<int>& jacobsthal, int arraySize)
{
    std::vector<int> validIndices;
    
    // Use a traditional for loop with indexing
    for (size_t i = 0; i < jacobsthal.size(); ++i)
    {
        int index = jacobsthal[i];
        if (index < arraySize)
            validIndices.push_back(index);
    }
    
    return validIndices;
}
// Merge two halves of the array into a sorted array
void PmergeMe::merge(std::vector<int>& arr, int left, int mid, int right)
{
	// Find sizes of two subarrays to merge
	int n1 = mid - left + 1; // Size of left subarray
	int n2 = right - mid;     // Size of right subarray
	// Create temporary arrays
	std::vector<int> leftArr(n1), rightArr(n2);
	// Copy data to temp arrays leftArr[] and rightArr[]
	for (int i = 0; i < n1; ++i)
		leftArr[i] = arr[left + i];
	for (int i = 0; i < n2; ++i)
		rightArr[i] = arr[mid + 1 + i];
	// Merge the temporary arrays back into arr[left...right]
	int i = 0;    // Initial index of leftArr
	int j = 0;    // Initial index of rightArr
	int k = left; // Initial index of merged subarray
	// Pick the smaller of the elements in leftArr and rightArr
	while (i < n1 && j < n2)
	{
		if (leftArr[i] <= rightArr[j])
		{
			arr[k] = leftArr[i];
			i++;
		} else {
			arr[k] = rightArr[j];
			j++;
		}
		k++;
	}
    // Copy any remaining elements of leftArr[], if any
	while (i < n1)
	{
		arr[k] = leftArr[i];
		i++;
		k++;
	}
    // Copy any remaining elements of rightArr[], if any
    while (j < n2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

// Main merge sort function
void PmergeMe::mergeSort(std::vector<int>& arr, int left, int right)
{
	// Base case: if there's only one element, it's already sorted
	if (left < right)
	{
		int mid = left + (right - left) / 2;
		mergeSort(arr, left, mid);
		mergeSort(arr, mid + 1, right);
		merge(arr, left, mid, right);
	}
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
    // std::cout << "Pairs (less, greater): ";
    // for (size_t i = 0; i < pairs.size(); ++i)
    // {
    //     std::cout << "(" << pairs[i].first << ", " << pairs[i].second << ") ";
    // }
    // std::cout << std::endl;
	std::vector<int> greaterElements;
	for (size_t i = 0; i < pairs.size(); ++i)
	{
    	greaterElements.push_back(pairs[i].second);
	}// Sort the greater elements using std::sort
	mergeSort(greaterElements, 0, greaterElements.size() - 1);
	// Display sorted greater elements (optional for debugging)
	std::vector<int> S = greaterElements;  // Sequence 'S'
	// Display the sequence S (optional for debugging)
	// std::cout << "Sequence S: ";
	// for (size_t i = 0; i < S.size(); ++i)
	// {
	// 	std::cout << S[i] << " ";
	// }
	// std::cout << std::endl;
	std::vector<int> pend;
	for (size_t i = 0; i < pairs.size(); ++i)
	{
    	pend.push_back(pairs[i].first);
	}
	// // Display the pend array (optional for debugging)
	std::cout << "Pend: ";
	for (size_t i = 0; i < pend.size(); ++i)
	{
    	std::cout << pend[i] << " ";
	}
	std::cout << std::endl;
	std::vector<int> jacobsthalSequence = generateJacobsthal(pend.size());
	// std::cout << "Sequence: ";
	// for (size_t i = 0; i < jacobsthalSequence.size(); ++i)
	// {
	// 	std::cout << jacobsthalSequence[i] << " ";
	// }
	// std::cout << std::endl;
	std::vector<int> validIndices = getValidIndices(jacobsthalSequence, pend.size());
	std::cout << "Valid Indices: ";
	for (size_t i = 0; i < validIndices.size(); ++i)
	{
		std::cout << validIndices[i] << " ";
	}
	std::cout << std::endl;
	std::vector<int> modifiedValidIndices;
    for (size_t i = 2; i < validIndices.size(); ++i)
	{
		modifiedValidIndices.push_back(validIndices[i]);
	}
	fordJohnsonSort(greaterElements, modifiedValidIndices, pend);
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