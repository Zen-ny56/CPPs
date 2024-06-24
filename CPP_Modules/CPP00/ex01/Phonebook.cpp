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

Phonebook::Phonebook(){};
Phonebook::~Phonebook(){};

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

int   Phonebook::add_contact(int *index)
{
	int d_index = 0;
	std::string uinput;
	if (*index < 8)
	{
		while (d_index < 5)
		{
			d_index = add_details(uinput, index, &d_index);
			std::cout << std::endl;
		}
		d_index = 0;
	}
	(*index)++;
	return (*index);
}

int Phonebook::add_details(std::string uinput, int *index, int *d_index)
{
	if (*d_index == 0)
	{
		std::cout << "First Name: ";
		std::getline(std::cin, uinput);
		if (std::cin.eof()){return (42);}
		if (verification(uinput) == 0)
		{
			contacts[*index].set_firstname(uinput);
			(*d_index)++;
		}
		return (*d_index);
	}
	else if (*d_index == 1)
	{
		std::cout << "Last Name: ";
		std::getline(std::cin, uinput);
		if (std::cin.eof()){return (42);}
		if (verification(uinput) == 0)
		{
			contacts[*index].set_lastname(uinput);
			(*d_index)++;
		}
		return (*d_index);
	}
	else if  (*d_index == 2)
	{
		std::cout <<  "Nickname: ";
		std::getline(std::cin, uinput);
		if (std::cin.eof()){return (42);}
		if (verification(uinput) == 0)
		{
			contacts[*index].set_nickname(uinput);
			(*d_index)++;
		}
		return (*d_index);
	}
	else if (*d_index == 3)
	{
		while (1)
		{
			std::cout << "Phone Number: ";
			std::getline(std::cin, uinput);
			if (std::cin.eof()){return (42);}
			if (verification(uinput) == 0)
			{
				if (is_digit(uinput) == false)
				{
					std::cout << "Enter something meaningful";
					std::cout << std::endl;
					continue;
				}
				contacts[*index].set_phone_number(uinput);
				(*d_index)++;
				break ;
			}
		}
		return (*d_index);
	}
	else if (*d_index == 4)
	{
		std::cout << "Darkest Secret: ";
		std::getline(std::cin, uinput);
		if (std::cin.eof()) {return (42);}
		if (verification(uinput) == 0)
		{
			contacts[*index].set_darkest_secret(uinput);
			(*d_index)++;
		}
		return (*d_index);
	}
	return (0);
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
	(*index) = 0;
	if (overflow == 42)
		return ;
	std::cout << "|   Index  | First Name | Last Name  | Nickname   |\n";
	while (*index < overflow)
	{
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
	*overflow = (*overflow) - 1;
	std::string uinput;
	while (1)
	{
		std::cout << "Input Index: ";
		std::getline(std::cin, uinput);
		if (std::cin.eof()) {return (42);}
		if (verification(uinput) != 0){
			std::cout << "Enter something meaningful" << std::endl;
			continue;
		} ;
		std::istringstream iss(uinput);
		iss >> num;
		if ((num >= 0 && num <= 8) && (num <= *overflow))
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
			std::cout << "Darkest Secret " << contacts[num].get_darkest_secret() << std::endl;
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