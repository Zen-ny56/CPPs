/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naadam <naadam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 17:54:22 by naadam            #+#    #+#             */
/*   Updated: 2024/06/24 18:06:46 by naadam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : name(name)
{
	std::cout << "HumanB constructor has been called" << std::endl;
}

HumanB::~HumanB()
{
	std::cout << "HumanB deconstructor has been called" << std::endl;
}

void    HumanB::set_Weapon(Weapon &weapon)
{
	this->weapon = &weapon;
}

void    HumanB::attack()
{
	if (weapon)
	{
		std::cout << name << " attacks with their " << weapon->getType() << std::endl;
	}
	else
		std::cout << name << " does not have a weapon yet" << std::endl;
}