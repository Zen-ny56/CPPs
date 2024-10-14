#pragma once

#include <string>
#include <iostream>
#include <vector>
#include <deque>
#include <sstream>
#include <stdexcept>
#include <cstdlib>

class PmergeMe
{
    private:
  	    PmergeMe();
	    PmergeMe(const PmergeMe& other);
	    PmergeMe& operator=(const PmergeMe& other);
	    ~PmergeMe();
        static bool isValidPositiveInteger(const std::string& str);
        static void processInput(const std::string& input);
    public:
        static void meVec(const std::string& literal);
        static void meDeq(const std::string& literal);
};