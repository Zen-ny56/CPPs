#include "BitcoinExchange.hpp"

static void	isValidPrice(const std::string& price)
{
	
}

void BitcoinExchange::parseCSV(const std::string &csvFilePath, std::map<std::string, float> &exchangeRates)
{   
	std::ifstream csvFile(csvFilePath.c_str());
	if (!csvFile.is_open())
		throw std::runtime_error("Error: could not open CSV file.");
	std::string line;
	while (std::getline(csvFile, line))
	{
		std::stringstream ss(line);
		std::string date;
		std::string priceStr;
		if (std::getline(ss, date, ',') && std::getline(ss, priceStr))
		{
			if (isValidDate(date) && isValidPrice(priceStr))
			{
				// bitcoinPrices[date] = std::stof(priceStr);
			} else
			{
					std::cerr << "Error: Invalid data in CSV file => " << line << std::endl;
			}
		}
		csvFile.close();
	}
}

void    BitcoinExchange::bitByBit(const std::string &csvFilePath, const std::string &InputFilePath)
{
	std::map<std::string, float> exchangeRates;
	parseCSV(csvFilePath, exchangeRates);
	std::map<std::string, float> bitcoinPrices;
}