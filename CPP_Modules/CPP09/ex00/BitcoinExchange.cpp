#include "BitcoinExchange.hpp"

bool BitcoinExchange::isInteger(const std::string& literal)
{
    char* endPtr;
    errno = 0;

    if (literal.find('.') != std::string::npos)
        return false;
    long intVal = std::strtol(literal.c_str(), &endPtr, 10);
    if (*endPtr == '\0' && errno != ERANGE && (intVal >= std::numeric_limits<int>::min() &&
        intVal <= std::numeric_limits<int>::max()))
        return true;
    return (false);
}

bool BitcoinExchange::isFloat(const std::string& literal)
{
    char* endPtr;
    errno = 0;
    if (literal.find('.') == std::string::npos)
		return false;
	double floatVal = std::strtof(literal.c_str(), &endPtr);
	(void)floatVal;
   if (errno == ERANGE || *endPtr != '\0')
	{
		return (false);
	}
    return true;
}

int BitcoinExchange::isValidPrice(const std::string& price)
{
	if (isInteger(price) == false && isFloat(price) == false)
		return (0);
	return (1);
}

int	BitcoinExchange::isValidDate(const std::string& date)
{
	if (date.length() != 10 || date[4] != '-' || date[7] != '-')
        return 0;
    std::string yearStr = date.substr(0, 4);
    std::string monthStr = date.substr(5, 2);
    std::string dayStr = date.substr(8, 2);
    // Check if all parts are digits
	for (std::string::size_type i = 0; i < yearStr.size(); ++i)
	{
    	char c = yearStr[i];
		if (!isdigit(c))
			return 0;
	}
 	for (std::string::size_type i = 0; i < monthStr.size(); ++i)
	{
    	char c = monthStr[i];
		if (!isdigit(c))
			return 0;
	}
 	for (std::string::size_type i = 0; i < dayStr.size(); ++i)
	{
    	char c = dayStr[i];
		if (!isdigit(c))
			return 0;
	}
	//Convert to 10
    int year = atoi(yearStr.c_str());
    int month = atoi(monthStr.c_str());
    int day = atoi(dayStr.c_str());
    // Check for valid year, month, and day ranges
    if (year < 0 || month < 1 || month > 12 || day < 1 || day > 31)
        return 0;
    // Check for valid days in the month
    if (month == 2)
	{ // February
		if (day > 29)
			return 0; // February can't have more than 29 days
        // Check for leap year
        if (day == 29 && !(year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)))
			return 0;
    } 
	else if (month == 4 || month == 6 || month == 9 || month == 11)
	{
		if (day > 30)
			return 0;
	}
	return 1; // Valid date
}

void BitcoinExchange::takedata(const std::string &csvFilePath, std::multimap<std::string, float> &rates, int a)
{
	(void)a;
	std::ifstream csvFile(csvFilePath.c_str());
	if (!csvFile.is_open())
		throw std::runtime_error("Error: could not open CSV file.");
	std::string line;
	if (!std::getline(csvFile, line)) 
	{
		csvFile.close();
		throw std::runtime_error("Error: CSV file is empty or could not read the header.");
	}
	while (std::getline(csvFile, line))
	{
		std::stringstream ss(line);
		std::string date;
		std::string priceStr;
		if (std::getline(ss, date, ',') && std::getline(ss, priceStr))
		{
			char *end;
			float f = std::strtof(priceStr.c_str(), &end);
			rates.insert(std::make_pair(date, f));  // Insert into multimap
		}
	}
	csvFile.close();
	if (rates.empty())
	{
		throw std::runtime_error("Invalid data found in the data file.csv file");
	}
}

void BitcoinExchange::takedata(const std::string &inputFilePath, std::multimap<std::string, float> &bitcoinPrices)
{
	std::ifstream inputFile(inputFilePath.c_str());
	if (!inputFile.is_open())
		throw std::runtime_error("Error: could not open CSV file.");
	std::string line;
	if (!std::getline(inputFile, line)) 
	{
		inputFile.close();
		throw std::runtime_error("Error: CSV file is empty or could not read the header.");
	}
	while (std::getline(inputFile, line))
	{
		std::stringstream ss(line);
		std::string date;
		std::string priceStr;
		if (std::getline(ss, date, '|') && std::getline(ss, priceStr))
		{
			date = date.substr(0, date.find_last_not_of(" \t") + 1);
			priceStr = priceStr.substr(priceStr.find_first_not_of(" \t"));
			char *end;
			float f;
			if (isInteger(priceStr))
			{
				long i = std::strtol(priceStr.c_str(), &end, 10);
				f = static_cast<float>(i);
				if (*end != '\0' || i > 1000 || i < 0)
					f = -1;
			}
			else
			{
				f = std::strtof(priceStr.c_str(), &end);
				if (*end != '\0' || f < 0 || f > 1000)
					f = -1;
			}
			bitcoinPrices.insert(std::make_pair(date, f));
		}
	}
	inputFile.close();
	if (bitcoinPrices.empty())
	{
		throw std::runtime_error("Invalid data found in the input file, or no data at all");
	}
}

void    BitcoinExchange::bitByBit(const std::string &csvFilePath, const std::string &inputFilePath)
{
	// (void)inputFilePath;
	std::multimap<std::string, float> exchangeRates;
	takedata(csvFilePath, exchangeRates, 0);
	std::multimap<std::string, float> bitcoinPrices;
	takedata(inputFilePath, bitcoinPrices);
	// testParsing(bitcoinPrices);
	execute(exchangeRates, bitcoinPrices);
}

void BitcoinExchange::execute(const std::multimap<std::string, float>& exchangeRates, const std::multimap<std::string, float>& bitcoinPrices)
{
	for (std::multimap<std::string, float>::const_iterator it = bitcoinPrices.begin(); it != bitcoinPrices.end(); ++it)
	{
		const std::string& date = it->first;
		std::string bitcoinValueStr;
		std::stringstream ss;
		ss << it->second;
		ss >> bitcoinValueStr;
		if (!isValidDate(date))
		{
			std::cout << "Error: Invalid date format for date " << date << std::endl;
			continue;
		}
		float bitcoinValue = it->second;
		if (bitcoinValue < 0 || bitcoinValue > 1000)
		{
			std::cout << "Error: Invalid bitcoin value " << date << std::endl;
			continue;
		}
		std::multimap<std::string, float>::const_iterator rateIt = exchangeRates.lower_bound(date);
		if (rateIt == exchangeRates.begin() && rateIt->first != date)
		{
			std::cout << "Error: No valid exchange rate found for or before date " << date << std::endl;
			continue;
		}
		if (rateIt == exchangeRates.end() || rateIt->first != date)
		{
			if (rateIt != exchangeRates.begin())
				--rateIt;
		}
		float exchangeRate = rateIt->second;
		float result = bitcoinValue * exchangeRate;
		std::cout << date << " => " << bitcoinValue << " = " << result << std::endl;
    }
}