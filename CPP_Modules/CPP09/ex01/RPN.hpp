#pragma once

#include <iostream>
#include <stack>
#include <string>
#include <stdexcept>
#include <sstream>

class RPN
{
	private:
		RPN();
		RPN(const RPN& other);
		RPN& operator=(const RPN& other);
		~RPN();
        static int  performOperation(int a, int b, char op);
        static bool isOperator(char c);
        static bool isNumber(char c);
    public:
        static int  evaluate(const std::string& literal);
};