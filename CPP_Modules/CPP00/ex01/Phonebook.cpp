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


int	  Phonebook::ver(std::string uinput)
{
	if (std::cin.eof()){return (42);}
	if (!verification(uinput))
	{
		std::cout << "Enter any character apart from a whitespace" << std::endl;
		return (-1);		
	}
	if (uinput.compare("EXIT")){return (1);}
	return (0);
}

int   Phonebook::add_contact(int *index)
{
	//Creating single object and filling values of that object
	Contact new_contact;
	int i = 0;
	std::string uinput;
	//Add First Name
	std::cout << "First Name: ";
	std::getline(std::cin, uinput);
	if (ver(uinput) != 0)
		return (ver(uinput));
	new_contact.set_firstname(uinput);
	std::cout << std::endl;
	//Add Last Name
	std::cout << "Last Name: ";
	std::getline(std::cin, uinput);
	if (ver(uinput) != 0)
		return (ver(uinput));
	new_contact.set_lastname(uinput);
	std::cout << std::endl;
	//Add Nickname
	std::cout << "Nick Name: ";
	std::getline(std::cin, uinput);
	if (ver(uinput) != 0)
		return (ver(uinput));
	new_contact.set_nickname(uinput);
	std::cout << std::endl;
	//Add Phonenumber
	std::cout << "Phone Number: ";
	std::getline(std::cin, uinput);
	if (ver(uinput) != 0)
		return (ver(uinput));
	if (is_digit(uinput) == false)
		return (1);
	new_contact.set_phone_number(uinput);
	std::cout << std::endl;
	//Add Darkest Secret
	std::cout << "Darkest Secret: ";
	std::getline(std::cin, uinput);
	if (ver(uinput) != 0)
		return (ver(uinput));
	new_contact.set_darkest_secret(uinput);
	std::cout << std::endl;
	//Adding object created to the array of objects & keeping
	contacts[*index] = new_contact;
	*index = (*index + 1) % 8;
	increment_ccount(ccount);
	return (0);
}


//Keeping count of contacts
void	increment_ccount(int ccount)
{
	if (ccount < 8)
		ccount++;
}

int	Phonebook::verification(std::string uinput)
{

	if (uinput.find_first_not_of("\t\n\v\f\r") == std::string::npos)
	{
		std::cout << "Enter Something meaningful" << std::endl;
		return (1);
	}
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
	else
		return (std::string(width - str.length(), ' ') + str);
}

void Phonebook::display(int *index, int overflow)
{
	int temp = 0;
	while (temp < *index)
	{
		if (temp == 0)
			std::cout << "|   Index  | First Name | Last Name  | Nickname   |\n";
		std::cout << "-----------------------------------------------------\n";
		std::cout << "|     " << *index << "    | ";
		std::cout << format_string(contacts[*index].get_firstname(), 10) << " | ";
		std::cout << format_string(contacts[*index].get_lastname(), 10) << " | ";
		std::cout << format_string(contacts[*index].get_nickname(), 10) << " |\n";
		(*index)++;
	}
}

int	Phonebook::search_contact(int *overflow)
{
	int num;
	if (overflow == 0)
		return (0);
	std::string uinput;
	while (1)
	{
		std::cout << "Input Index: ";
		std::getline(std::cin, uinput);
		if (std::cin.eof()) {return (42);}
		if (uinput.compare("EXIT") == 0)
			break ;
		if (verification(uinput) != 0){
			std::cout << "Enter something meaningful" << std::endl;
			continue;
		};
		if (Phonebook::is_digit(uinput) == false)
			break ;
		std::istringstream iss(uinput);
		iss >> num;
		std::cout << *overflow << std::endl;
		if ((num >= 0 && num <= 8) && (num < *overflow))
		{
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
			break ;
		}
		else
		{
			std::cout << "Enter a valid index" << std::endl;
			continue ;
		}
	}
	return (0);
	//std::cout << "Put Something Meaningful: " << std::endl;
}