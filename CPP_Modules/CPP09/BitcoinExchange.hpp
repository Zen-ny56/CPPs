#pragma once 

#include <string>
#include <iostream>
#include <map>
#include <sstream>
#include <fstream>

class BitcoinExchange
{
	private:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& other);
		BitcoinExchange& operator=(const BitcoinExchange& other);
		~BitcoinExchange();
		static void parseCSV(const std::string& csvFilePath, std::map<std::string, float> &exchangeRates);
		static void parseInputFile(const std::string& inputFilePath, const std::map<std::string, float> &bitcoinPrices);
		static void isValidDate(const std::string& date);
		static void	isValidPrice(const std::string& price);
	public:
		static void bitByBit(const std::string& csvFilePath, const std::string& inputFilePath);
};