#pragma once

#include <string>
#include <iostream>
#include <vector>
#include <deque>
#include <sstream>
#include <stdexcept>
#include <cstdlib>
#include <algorithm>

class PmergeMe
{
	private:
  		PmergeMe();
		PmergeMe(const PmergeMe& other);
		PmergeMe& operator=(const PmergeMe& other);
		~PmergeMe();
		static bool isValidPositiveInteger(const std::string& str);
		static  void merge(std::vector<int>& arr, int left, int mid, int right);
		static  void mergeSort(std::vector<int>& arr, int left, int right);
		static  void processInput(const std::string& input);
		static  std::vector<int> generateJacobsthal( int n);
		static	std::vector<int> getValidIndices(const std::vector<int>& jacobsthal, int arraySize);
		static	void fordJohnsonSort(const std::vector<int>& arr, const std::vector<int>& validIndices, const std::vector<int>& pend);
	public:
		static void meVec(const std::string& literal);
		static void meDeq(const std::string& literal);
};