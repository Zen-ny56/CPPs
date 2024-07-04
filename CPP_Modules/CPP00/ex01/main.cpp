/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naadam <naadam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 14:39:53 by naadam            #+#    #+#             */
/*   Updated: 2024/06/22 16:01:33 by naadam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "Phonebook.hpp"
int main(void)
{
	Phonebook negus;
	int     index = 0;
	int		overflow = 0;
	std::string uinput;
	negus.welcome();
	while (1)
	{
		std::cout << "Enter Something: ";
		std::getline(std::cin, uinput);
		if (std::cin.eof())
			break ;
		if (uinput.find_first_not_of("\t\n\v\f\r") == std::string::npos)
			std::cout << "Enter Something meaningful" << std::endl;
		else
		{
			// std::cout << overflow << std::endl;
			if (uinput.compare("ADD") == 0 && overflow < 9)
			{
				std::cout << std::endl;
				overflow = negus.add_contact(&index);
				if (overflow == 42)
					break;
				negus.display(&index, overflow);
			}
			if (uinput.compare("SEARCH") == 0 && (overflow > 0))
			{
				negus.display(&index, overflow);
				if (negus.search_contact(&overflow) == 42)
					break ;
			}
			if (uinput.compare("EXIT") == 0)
				break;
		}
	}
	std::cout << "User has exited" << std::endl;
}