/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naadam <naadam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 18:52:10 by naadam            #+#    #+#             */
/*   Updated: 2024/06/23 19:23:35 by naadam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/*Constrtuctors and deconstructor*/
Zombie::Zombie()
{
	std::cout << "Zombie default constructor has been called" << std::endl;
}

Zombie::Zombie(std::string name) : name(name)
{
	std::cout << name <<  ": Zombie has been created" << std::endl;
}

Zombie::~Zombie()
{
	std::cout << "Zombie has been destroyed" << std::endl;
}

void    Zombie::announce()
{
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void    Zombie::set_name(std::string name){this->name = name;}


Zombie* zombieHorde(int N, std::string name)
{
	if (N <= 0)
	{
		std::cerr << "Invalid number of zombies: " << N << std::endl;
		return (NULL);
	}
	try
	{
		Zombie* horde = new Zombie[N];
		for (int i = 0; i < N; ++i)
		{
			horde[i].set_name(name);
		}
		return (horde);	
	}
	catch (const std::bad_alloc& e)
	{
		std::cerr << "Memory allocation failed: " << e.what() << std::endl;
		return (NULL);
	}
}