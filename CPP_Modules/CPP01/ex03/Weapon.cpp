/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naadam <naadam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 17:28:11 by naadam            #+#    #+#             */
/*   Updated: 2024/06/24 18:16:22 by naadam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type): type(type){}

std::string const& Weapon::getType()
{
    return (type);
}

void    Weapon::setType(std::string type)
{
    this->type = type; 
}