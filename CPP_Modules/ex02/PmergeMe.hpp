#pragma once

#include <string>
#include <iostream>
#include <vector>
#include <list>
#include <sstream>
#include <stdexcept>
#include <cstdlib>
#include <algorithm>
#include <ctime>     // For clock()

class PmergeMe
{
	private:
  		PmergeMe();
		PmergeMe(const PmergeMe& other);
		PmergeMe& operator=(const PmergeMe& other);
		~PmergeMe();
		static bool isValidPositiveInteger(const std::string& str);
		static  void merge(std::vector<int>& arr, int left, int mid, int right);
		static  void merge(std::list<int>& arr, int left, int mid, int right, int f);
		static  void mergeSort(std::vector<int>& arr, int left, int right);
		static  void mergeSort(std::list<int>& lst);
		static  std::vector<int> processInput(const std::vector<int>& integerList);
		static	std::list<int> processInput(const std::list<int>& integerList);
		static  std::vector<int> generateJacobsthal(int n);
		static	std::list<int> generateJacobsthal(int n, int f);
		static	std::vector<int> getValidIndices(const std::vector<int>& jacobsthal, int arraySize);
		static	std::list<int> getValidIndices(const std::list<int>& jacobsthal, int arraySize);
		static	std::vector<int> fordJohnsonSort(std::vector<int>& S, const std::vector<int>& validIndices, const std::vector<int>& pend);
		static	std::list<int> fordJohnsonSort(std::list<int>& S, const std::list<int>& validIndices, const std::list<int>& pend);
	public:
		static void meVec(const std::string& literal);
		static void meList(const std::string& literal);
};