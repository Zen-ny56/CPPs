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

//For data.csv file
void BitcoinExchange::parseFile(const std::string &csvFilePath, std::map<std::string, float> &exchangeRates, int a)
{
	(void)a;
	std::ifstream csvFile(csvFilePath.c_str());
	if (!csvFile.is_open())
		throw std::runtime_error("Error: could not open CSV file.");
	std::string line;
	std::getline(csvFile, line); // Skip first line
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
			if (isValidDate(date) && isValidPrice(priceStr))
			{
				char *end;
				float f = std::strtof(priceStr.c_str(), &end);
				if (*end != '\0')
				{
					csvFile.close();
					throw std::runtime_error("Conversion to float failed");
				}
				if (f < 0 || std::isinf(f))
				{
					csvFile.close();
					throw std::runtime_error("Float passed float max");
				}
				exchangeRates[date] = f;
			} 
			else
			{
				csvFile.close();
				throw std::runtime_error("Error in dates or data type on exchange rates entered");
			}
		}
		csvFile.close();
	}
	if (exchangeRates.empty())
	{
		throw std::runtime_error("Invalid data found in the data file.csv file");
	}
}

//Our File
void BitcoinExchange::parseFile(const std::string &inputFilePath, std::map<std::string, float> &bitcoinPrices)
{   
	std::ifstream inputFile(inputFilePath.c_str());
	if (!inputFile.is_open())
		throw std::runtime_error("Error: could not open CSV file.");
	std::string line;
	while (std::getline(inputFile, line))
	{
		std::stringstream ss(line);
		std::string date;
		std::string priceStr;
		if (std::getline(ss, date, ',') && std::getline(ss, priceStr))
		{
			if (isValidDate(date) && isValidPrice(priceStr))
			{
				char *end;
				float f = std::strtof(priceStr.c_str(), &end);
				if (*end != '\0')
				{
					inputFile.close();
					throw std::runtime_error("Conversion to float failed");
				}
				if (f < 0 || f > 1000)
				{
					inputFile.close();
					throw std::runtime_error("Number for user file was way too large");
				}
				bitcoinPrices[date] = f;
			} 
			else
			{
				inputFile.close();
				throw std::runtime_error("Error in dates or data type on bitcoin prices entered");
			}
		}
		inputFile.close();
	}
	if (bitcoinPrices.empty())
	{
		throw std::runtime_error("Invalid data found in the input file, or no data at all");
	}
}

void BitcoinExchange::testParsing(const std::map<std::string, float>& rates)
{
    for (std::map<std::string, float>::const_iterator it = rates.begin(); it != rates.end(); ++it)
    {
        const std::string &key = it->first;
        float value = it->second;
        std::cout << key << " -> " << value << std::endl;
    }
}

void    BitcoinExchange::bitByBit(const std::string &csvFilePath, const std::string &inputFilePath)
{
	(void)inputFilePath;
	std::map<std::string, float> exchangeRates;
	parseFile(csvFilePath, exchangeRates, 0);
	testParsing(exchangeRates);
	// std::map<std::string, float> bitcoinPrices;
	// parseFile(inputFilePath, bitcoinPrices);
}
