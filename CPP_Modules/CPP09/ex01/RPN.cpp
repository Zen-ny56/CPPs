#include "RPN.hpp"

bool RPN::isOperator(char c) {
	return c == '+' || c == '-' || c == '*' || c == '/';
}

bool RPN::isNumber(char c) {
	return c >= '0' && c <= '9';
}

int RPN::performOperation(int a, int b, char op) {
	switch (op) {
		case '+': return a + b;
		case '-': return a - b;
		case '*': return a * b;
		case '/': 
			if (b == 0)
				throw std::runtime_error("Error: Division by zero");
			return a / b;
		default:
			throw std::runtime_error("Error: Unknown operator");
	}
}

int RPN::evaluate(const std::string &expression)
{
	std::stack<int> stack;
	std::stringstream ss(expression);
	std::string token;

	while (ss >> token)
	{
		if (token.length() == 1 && isOperator(token[0]))
		{
			if (stack.size() < 2)
				throw std::runtime_error("Error: Too few operands for operation");
			int b = stack.top(); stack.pop();
			int a = stack.top(); stack.pop();
			int result = performOperation(a, b, token[0]);
			stack.push(result);
		}
		else if (token.length() == 1 && isNumber(token[0])) {
			stack.push(token[0] - '0');
		}
		else {
			throw std::runtime_error("Error: Invalid token in input");
		}
	}
	if (stack.size() != 1)
		throw std::runtime_error("Error: Invalid expression");

	return stack.top();  // Final result
}
