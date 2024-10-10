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
    for (char c : yearStr)
	{
		if (!isdigit(c))
			return 0;
	}
    for (char c : monthStr)
	{
		if (!isdigit(c))
			return 0;
	}
    for (char c : dayStr)
	{
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
				char *end;
				float f = std::strtof(priceStr.c_str(), &end);
				if (*end != '\0')
				{
					csvFile.close();
					throw OutOfRangeException();
				}
				if (f > 1000 || f < 0)
				{
					csvFile.close();
					throw OutOfRangeException();
				}
				exchangeRates[date] = f;
			} 
			else
			{
				csvFile.close();
				throw	OutOfRangeException();
			}
		}
		csvFile.close();
	}
}

void    BitcoinExchange::bitByBit(const std::string &csvFilePath, const std::string &inputFilePath)
{
	std::map<std::string, float> exchangeRates;
	parseCSV(csvFilePath, exchangeRates);
	std::map<std::string, float> bitcoinPrices;
	parseInputFile(inputFilePath, bitcoinPrices);
}

const char* BitcoinExchange::OutOfRangeException::what(void) const throw()
{
	return "Error with file";
}