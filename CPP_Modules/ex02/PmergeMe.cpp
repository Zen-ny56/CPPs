#include "PmergeMe.hpp"

void PmergeMe::meVec(const std::string& literal)
{
	std::stringstream ss(literal);
	std::vector<int> integerList;
	std::string token;
	while (ss >> token)
	{
		if (!isValidPositiveInteger(token))
			throw std::runtime_error("Error: Invalid input");
		int number = std::atoi(token.c_str());
		if (number < 0) {
			throw std::runtime_error("Error: Invalid input");
		}
		integerList.push_back(number);
	}
	// Step 4: Display the "Before" sequence
	for (size_t i = 0; i < integerList.size(); ++i)
	{
		for (size_t j = i + 1; j < integerList.size(); ++j)
		{
			if (integerList[i] == integerList[j])
				throw std::runtime_error("Error: Duplicate value found");
        }
    }
	if (integerList.size() <= 1)
		throw std::runtime_error("Error: Only one element is present");
	std::cout << "Before (std::vector): ";
	for (size_t i = 0; i < integerList.size(); ++i)
	{
		std::cout << integerList[i];
		if (i < integerList.size() - 1) {
			std::cout << " ";  // Add space between numbers
        }
    }
    std::cout << std::endl; // Move to the next line
	std::vector<int> S = processInput(integerList);
	std::cout << "After (std::vector): ";
    for (size_t i = 0; i < S.size(); ++i) {
        std::cout << S[i] << " ";
    }
	std::cout << std::endl;
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


std::vector<int> PmergeMe::fordJohnsonSort(std::vector<int>& S, const std::vector<int>& validIndices, const std::vector<int>& pend)
{
    // Create a vector to hold the extracted elements from arr based on validIndices
    std::vector<int> extractedElements;
    // Extract elements from arr based on validIndices
    for (size_t i = 0; i < validIndices.size(); ++i)
	{
		if (static_cast<size_t>(validIndices[i]) < pend.size()){
			extractedElements.push_back(pend[validIndices[i]]);
		}
	}
    // std::cout << "Extracted Elements: ";
    // for (size_t i = 0; i < extractedElements.size(); ++i) {
    //     std::cout << extractedElements[i] << " ";
    // }
    // std::cout << std::endl;
    for (size_t i = 0; i < extractedElements.size(); ++i)
	{
		int currentElement = extractedElements[i];
		std::vector<int>::iterator pos = std::lower_bound(S.begin(), S.end(), currentElement);
		S.insert(pos, currentElement);
	}
	for (size_t i = 0; i < pend.size(); ++i)
	{
		// Check if the current element is already in S by checking the last inserted position
		if (std::find(extractedElements.begin(), extractedElements.end(), pend[i]) == extractedElements.end())
		{
			// If not found, use lower_bound to find the correct position
			std::vector<int>::iterator pos = std::lower_bound(S.begin(), S.end(), pend[i]);
			S.insert(pos, pend[i]); // Insert remaining element
		}
	}
    // Output the modified S after insertion
    // std::cout << "Greater Elements after insertion: ";
    // for (size_t i = 0; i < S.size(); ++i) {
    //     std::cout << S[i] << " ";
    // }
    // std::cout << std::endl;
	return S;
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
	std::vector<int> leftArr(n1), rightArr(n2);
	for (int i = 0; i < n1; ++i)
		leftArr[i] = arr[left + i];
	for (int i = 0; i < n2; ++i)
		rightArr[i] = arr[mid + 1 + i];
	int i = 0;    // Initial index of leftArr
	int j = 0;    // Initial index of rightArr
	int k = left; // Initial index of merged subarray
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
	while (i < n1)
	{
		arr[k] = leftArr[i];
		i++;
		k++;
	}
    while (j < n2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

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

std::vector<int> PmergeMe::processInput(const std::vector<int>& integerList)
{
	clock_t start = clock();
	std::vector<std::pair<int, int> > pairs;
	std::vector<int> straggler;
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
			straggler.push_back(integerList[i]);
		}
    }
    // Display pairs (optional for debugging)
	 // std::cout << "Pairs (less, greater): ";
    // for (size_t i = 0; i < pairs.size(); ++i)
    // {
    //     std::cout << "(" << pairs[i].first << ", " << pairs[i].second << ") ";
    // }
    // std::cout << std::endl;
	// std::cout << "Straggler: ";
    // for (size_t i = 0; i < straggler.size(); ++i)
    // {
    //     std::cout << straggler[i] << std::endl;
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
	// std::cout << "Pend: ";
	// for (size_t i = 0; i < pend.size(); ++i)
	// {
    // 	std::cout << pend[i] << " ";
	// }
	// std::cout << std::endl;
	std::vector<int> jacobsthalSequence = generateJacobsthal(pend.size());
	// std::cout << "Sequence: ";
	// for (size_t i = 0; i < jacobsthalSequence.size(); ++i)
	// {
	// 	std::cout << jacobsthalSequence[i] << " ";
	// }
	// std::cout << std::endl;
	std::vector<int> validIndices = getValidIndices(jacobsthalSequence, pend.size());
	// std::cout << "Valid Indices: ";
	// for (size_t i = 0; i < validIndices.size(); ++i)
	// {
	// 	std::cout << validIndices[i] << " ";
	// }
	// std::cout << std::endl;
	std::vector<int> modifiedValidIndices;
    for (size_t i = 2; i < validIndices.size(); ++i)
	{
		modifiedValidIndices.push_back(validIndices[i]);
	}
	S = fordJohnsonSort(greaterElements, modifiedValidIndices, pend);
	if (!straggler.empty())
	{
		std::vector<int>::iterator pos = std::lower_bound(S.begin(), S.end(), straggler[0]);
		S.insert(pos, straggler[0]);
	}
	// std::cout << "Greater Elements after insertion: ";
    // for (size_t i = 0; i < S.size(); ++i) {
    //     std::cout << S[i] << " ";
    // }
	// std::cout << std::endl;
	clock_t end = clock();
	double duration = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1e6; // Convert to microseconds
	std::cout << "Time to process a range of " << integerList.size() << " elements with std::vector : " << duration << " us" << std::endl;
	return (S);
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

//LIST IMPLEMENTATION

std::list<int> PmergeMe::fordJohnsonSort(std::list<int>& S, const std::list<int>& validIndices, const std::list<int>& pend)
{
	std::list<int>::const_iterator pendIt = pend.begin();
	for (std::list<int>::const_iterator idxIt = validIndices.begin(); idxIt != validIndices.end(); ++idxIt)
	{
		int value = *pendIt;

		std::list<int>::iterator pos = S.begin();
		for (; pos != S.end(); ++pos)
		{
			if (*pos > value)
				break;
		}
		S.insert(pos, value);
		++pendIt;
	}
	pendIt = pend.begin();
	while (pendIt != pend.end())
	{
		int currentElement = *pendIt;
		if (std::find(S.begin(), S.end(), currentElement) == S.end())
		{
			std::list<int>::iterator pos = S.begin();
			for (; pos != S.end(); ++pos)
			{
				if (*pos > currentElement)
					break;
			}
			S.insert(pos, currentElement);
		}
		++pendIt;
	}
	return S;
}

std::list<int> PmergeMe::getValidIndices(const std::list<int>& jacobsthal, int arraySize)
{
    std::list<int> validIndices;
    for (std::list<int>::const_iterator it = jacobsthal.begin(); it != jacobsthal.end(); ++it)
    {
        int index = *it;
        if (index < arraySize)
            validIndices.push_back(index);
    }

    return validIndices;
}

std::list<int> PmergeMe::generateJacobsthal(int n, int f)
{
	(void) f;
    std::list<int> jacobsthal;
    jacobsthal.push_back(0); // J(0)
    if (n > 1)
        jacobsthal.push_back(1); // J(1)

    int prev1 = 1, prev2 = 0;
    for (int i = 2; i < n; ++i)
    {
        int current = prev1 + 2 * prev2;
        jacobsthal.push_back(current);
        prev2 = prev1;
        prev1 = current;
    }
    return jacobsthal;
}

void PmergeMe::mergeSort(std::list<int>& lst)
{
    if (lst.size() <= 1)
		return;
    std::list<int>::iterator mid = lst.begin();
    std::advance(mid, lst.size() / 2);
    std::list<int> left(lst.begin(), mid);
    std::list<int> right(mid, lst.end());

    mergeSort(left);
    mergeSort(right);
    lst.clear();
    // Manual merging instead of using std::back_inserter
    std::list<int>::iterator it_left = left.begin();
    std::list<int>::iterator it_right = right.begin();

    while (it_left != left.end() && it_right != right.end())
    {
        if (*it_left < *it_right)
        {
            lst.push_back(*it_left);
            ++it_left;
        }
        else
        {
            lst.push_back(*it_right);
            ++it_right;
        }
    }
    // Insert any remaining elements from the left list
    while (it_left != left.end())
    {
        lst.push_back(*it_left);
        ++it_left;
    }

    // Insert any remaining elements from the right list
    while (it_right != right.end())
    {
        lst.push_back(*it_right);
        ++it_right;
    }
}

std::list<int> PmergeMe::processInput(const std::list<int>& integerList)
{
	clock_t start = clock();
	std::list<std::pair<int, int> > pairs;
    std::list<int> straggler;
    std::list<int>::const_iterator it = integerList.begin();
    while (it != integerList.end())
    {
		int first = *it;
		++it;
		if (it != integerList.end()) // Ensure we don't go out of bounds
        {
			int second = *it;
			if (first > second)
				pairs.push_back(std::make_pair(second, first));
			else
				pairs.push_back(std::make_pair(first, second));
			++it;
		}
		else
			straggler.push_back(first);
    }
	std::list<int> greaterElements;
	for (std::list<std::pair<int, int> >::iterator it = pairs.begin(); it != pairs.end(); ++it)
        greaterElements.push_back(it->second);
	//Merge
    mergeSort(greaterElements);
    std::list<int> S = greaterElements;
	std::list<int> pend;
    for (std::list<std::pair<int, int> >::iterator it = pairs.begin(); it != pairs.end(); ++it)
        pend.push_back(it->first);
    std::list<int> jacobsthalSequence = generateJacobsthal(pend.size(), 0);
    std::list<int> validIndices = getValidIndices(jacobsthalSequence, pend.size());
    // Modified valid indices for the Ford-Johnson sort
    std::list<int>::iterator idxStart = validIndices.begin();
    ++idxStart;
    ++idxStart; // Equivalent to std::next(validIndices.begin(), 2)
    std::list<int> modifiedValidIndices(idxStart, validIndices.end());
    S = fordJohnsonSort(S, modifiedValidIndices, pend);
    // Handling straggler if it exists
    if (!straggler.empty())
    {
        std::list<int>::iterator pos = S.begin();
        for (; pos != S.end(); ++pos)
        {
            if (*pos > straggler.front())
                break;
        }
        S.insert(pos, straggler.front());
    }
    clock_t end = clock();
    double duration = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1e6; // Convert to microseconds
    std::cout << "Time to process a range of " << integerList.size() << " elements using std::list: " << duration << " us" << std::endl;
	return (S);
}

void PmergeMe::meList(const std::string& literal)
{
	// (void)literal;
	 std::stringstream ss(literal);
    std::list<int> integerList;
    std::string token;
    while (ss >> token)
    {
        if (!isValidPositiveInteger(token))
            throw std::runtime_error("Error: Invalid input");
        int number = std::atoi(token.c_str());
        if (number < 0) {
            throw std::runtime_error("Error: Invalid input");
        }
        integerList.push_back(number);
    }
    // Check for duplicates manually without using std::next
    for (std::list<int>::iterator it1 = integerList.begin(); it1 != integerList.end(); ++it1)
    {
        std::list<int>::iterator it2 = it1;
        ++it2;
        for (; it2 != integerList.end(); ++it2)
        {
            if (*it1 == *it2)
                throw std::runtime_error("Error: Duplicate value found");
        }
    }
	if (integerList.size() <= 1)
        throw std::runtime_error("Error: Only one element is present");
	std::cout << "Before (std::list): ";
	for (std::list<int>::iterator it = integerList.begin(); it != integerList.end(); ++it)
	{
		std::cout << *it;
		// Create a temporary iterator to check if the current element is the last one
		std::list<int>::iterator temp = it;
		if (++temp != integerList.end())
			std::cout << " ";  // Print space only if it's not the last element
	}
    std::cout << std::endl;
	std::list<int> S = processInput(integerList);  // Just for demonstration; you might want to adjust this
	std::cout << "After (std::list): ";
	for (std::list<int>::iterator it = S.begin(); it != S.end(); ++it)
	{
		std::cout << *it;
		// Create a temporary iterator to check if the current element is the last one
		std::list<int>::iterator temp = it;
		if (++temp != S.end())
			std::cout << " ";  // Print space only if it's not the last element
	}
	std::cout << std::endl;
}