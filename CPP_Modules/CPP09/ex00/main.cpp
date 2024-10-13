#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
	(void)av;
	if (ac != 2)
	{
		std::cout << "Wrong Number of arguments" << std::endl;
		return (1);
	}
	std::string InputFileName = av[1];
	std::string csvFileName = "data.csv";
	try
	{
		BitcoinExchange::bitByBit(csvFileName, InputFileName);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}