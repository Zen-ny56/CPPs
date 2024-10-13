#pragma once 

#include <string>
#include <iostream>
#include <map>
#include <sstream>
#include <fstream>
#include <limits>
#include <cmath>
#include <cstdio>
#include <stdexcept>
#include <cstdlib> 

typedef enum e_type
{
	EMPTY_LINE,
	BIT_HIGH,
	FLOAT_OVERFLOW,
	DATE,
}		t_type;

class BitcoinExchange
{
	private:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& other);
		BitcoinExchange& operator=(const BitcoinExchange& other);
		~BitcoinExchange();
		static void takedata(const std::string& csvFilePath, std::map<std::string, float> &exchangeRates, int a);
		static void takedata(const std::string& inputFilePath, std::map<std::string, float> &bitcoinPrices);
		static int isValidDate(const std::string& date);
		static int	isValidPrice(const std::string& price);
		static bool	isInteger(const std::string& literal);
		static void testParsing(const std::map<std::string, float> &rates);
		static bool	isFloat(const std::string& literal);
		static void	execute(const std::map<std::string, float>& exchangeRates, const std::map<std::string, float>& bitcoinPrices);
	public:
		static void bitByBit(const std::string& csvFilePath, const std::string& inputFilePath);
};