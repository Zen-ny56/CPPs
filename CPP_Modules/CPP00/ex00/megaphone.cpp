/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naadam <naadam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 12:20:38 by naadam            #+#    #+#             */
/*   Updated: 2024/06/19 12:31:16 by naadam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

int main(int ac, char **av)
{

	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
	{
		int i = 1;
		while (i < ac)
		{
			int j = 0;
			while (av[i][j])
			{
				if (std::isalpha(av[i][j]))
					std::cout << (char)std::toupper(av[i][j]);
				else
					std::cout << av[i][j];
				j++;
			}
			if (i < (ac - 1))
				std::cout << ' ';
			i++;
		}
	}
	std::cout << std::endl;
}