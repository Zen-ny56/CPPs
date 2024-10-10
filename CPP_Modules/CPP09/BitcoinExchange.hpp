#pragma once 

#include <string>
#include <iostream>
#include <map>
#include <sstream>
#include <fstream>
#include <limits>

class BitcoinExchange
{
	private:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& other);
		BitcoinExchange& operator=(const BitcoinExchange& other);
		~BitcoinExchange();
		static void parseCSV(const std::string& csvFilePath, std::map<std::string, float> &exchangeRates);
		static void parseInputFile(const std::string& inputFilePath, const std::map<std::string, float> &bitcoinPrices);
		static int isValidDate(const std::string& date);
		static int	isValidPrice(const std::string& price);
		static bool	isInteger(const std::string& literal);
		static bool	isFloat(const std::string& literal);
	public:
		static void bitByBit(const std::string& csvFilePath, const std::string& inputFilePath);
		class OutOfRangeException : public std::exception
		{
			public:
				const char* what(void) const throw();
		};
};