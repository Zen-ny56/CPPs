/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naadam <naadam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 15:20:51 by naadam            #+#    #+#             */
/*   Updated: 2024/06/22 16:08:46 by naadam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

Phonebook::Phonebook()
{
	ccount = 0;
	std::cout << "Phonebook default constructor has been called" << std::endl;
}

Phonebook::~Phonebook()
{
	std::cout << "Phonebook deconstructor has been called" << std::endl;
};

void   Phonebook::welcome()
{
	std::cout << "User is allowed only three prompts:" << std::endl;
	std::cout << std::endl;
	std::cout << "1.ADD: to add a contact" << std::endl;
	std::cout << std::endl;
	std::cout << "2.SEARCH: to search for one" << std::endl;
	std::cout << std::endl;
	std::cout << "3.EXIT: to delete all contacts and exit the phonebook" << std::endl;
	std::cout << std::endl;
}


int	  Phonebook::ver(std::string& uinput)
{
	if (std::cin.eof()){return (42);}
	if (verification(uinput) == 1)
	{
		// std::cout << "Enter any character apart from a whitespace" << std::endl;
		return (-1);		
	}
	if (uinput.compare("EXIT") == 0){return (1);}
	return (0);
}

int   Phonebook::add_contact(int *index)
{
	//Creating single object and filling values of that object
	Contact new_contact;
	int i = 0;
	std::string uinput;
	while (i < 5)
	{
		//Add First Name
		if (i == 0)
		{
			std::cout << "First Name: ";
			std::getline(std::cin, uinput);
			if (ver(uinput) > 0)
				return (ver(uinput));
			else if (ver(uinput) == -1)
				continue;
			new_contact.set_firstname(uinput);
			i++;
			std::cout << std::endl;
			continue;
		}
		//Add Last Name
		else if (i == 1)
		{
			std::cout << "Last Name: ";
			std::getline(std::cin, uinput);
			if (ver(uinput) > 0)
				return (ver(uinput));
			else if (ver(uinput) == -1)
				continue;
			new_contact.set_lastname(uinput);
			i++;
			std::cout << std::endl;
			continue;
		}
		//Add Nickname
		else if (i == 2)
		{
			std::cout << "Nick Name: ";
			std::getline(std::cin, uinput);
			if (ver(uinput) > 0)
				return (ver(uinput));
			else if (ver(uinput) == -1)
				continue;
			new_contact.set_nickname(uinput);
			i++;
			std::cout << std::endl;
			continue;
		}
		//Add Phonenumber
		else if (i == 3)
		{
			std::cout << "Phone Number: ";
			std::getline(std::cin, uinput);
			if (ver(uinput) > 0)
				return (ver(uinput));
			if (is_digit(uinput) == false || ver(uinput) == -1)
			{
				std::cout << "Only enter digits" << std::endl;
				continue;
			}
			new_contact.set_phone_number(uinput);
			i++;
			std::cout << std::endl;
			continue;
		}
		//Add Darkest Secret
		else if (i == 4)
		{
			std::cout << "Darkest Secret: ";
			std::getline(std::cin, uinput);
			if (ver(uinput) > 0)
				return (ver(uinput));
			else if (ver(uinput) == -1)
				continue;
			new_contact.set_darkest_secret(uinput);
			i++;
			std::cout << std::endl;
			continue;
		}
	}
	//Adding object created to the array of objects & keeping
	contacts[*index] = new_contact;
	*index = (*index + 1) % 8;
	increment_ccount(&ccount);
	return (0);
}


//Keeping count of contacts
void	Phonebook::increment_ccount(int *ccount)
{
	if ((*ccount) < 8)
		(*ccount)++;
}

int		Phonebook::get_ccount()
{
	return (ccount);
}

int	Phonebook::verification(std::string uinput)
{
	if (uinput.find_first_not_of("\t\n\v\f\r") == std::string::npos)
		return (1);
	return (0);
}

bool Phonebook::is_digit(const std::string& str) 
{
	size_t i = 0;
	while (i < str.length())
	{
		if (!std::isdigit(static_cast<unsigned char>(str[i])))
			return (false);
		++i;
	}
	return (true);
}

std::string format_string(const std::string& str, size_t width)
{
	if (str.length() > width)
		return (str.substr(0, width - 1) + ".");
	return (str);
}

void Phonebook::display()
{
	int temp = get_ccount();
	int i = -1;
	if (temp == 0)
	{
		std::cout << "Ain't nothing there yet" << std::endl;
		return ;
	}
	std::cout << std::setw(10) << "Index" << "|" << std::setw(10) << "First Name" << "|" << std::setw(10) << "Last Name" << "|" << std::setw(10) << "Nickname" << std::endl;
	while (++i < temp)
		std::cout << std::setw(10) << i << "|" << std::setw(10) <<	format_string(contacts[i].get_firstname(), 10) << "|" << std::setw(10) << format_string(contacts[i].get_lastname(), 10) << "|" << std::setw(10) << format_string(contacts[i].get_nickname(), 10) << std::endl;
}

int Phonebook::search_contact()
{
	int num;
	int i = get_ccount() - 1;
	std::string uinput;
	if (get_ccount() == 0)
		return (0);
	while (1)
	{
		std::cout << "Enter a valid index:  " << std::endl;
		std::getline(std::cin, uinput);
		if (ver(uinput) > 0)
			return (ver(uinput));
		if (is_digit(uinput) == false || ver(uinput) == -1)
		{
			// std::cout << std::endl;
			continue;
		}
		std::istringstream iss(uinput);
		iss >> num;
		if (num > i || num < 0)
			continue ;
		std::cout << std::endl;
		std::cout << "First Name: " << contacts[num].get_firstname() << std::endl;
		std::cout << std::endl;
		std::cout << "Last Name: " << contacts[num].get_lastname() << std::endl;
		std::cout << std::endl;
		std::cout << "Nickname: " << contacts[num].get_nickname() << std::endl;
		std::cout << std::endl;
		std::cout << "Phone Number: " << contacts[num].get_phone_number() << std::endl;
		std::cout << std::endl;
		std::cout << "Darkest Secret: " << contacts[num].get_darkest_secret() << std::endl;
		std::cout << std::endl;
		break;
	}
	return (0);
}