/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naadam <naadam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 17:27:22 by naadam            #+#    #+#             */
/*   Updated: 2024/06/23 18:49:34 by naadam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name) : name(name)

{std::cout << name <<  ":Zombie has been created" << std::endl;}
Zombie::~Zombie(){std::cout << "Zombie has been destroyed" << std::endl;}
void    Zombie::announce(){std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;}