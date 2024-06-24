/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naadam <naadam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 19:44:40 by naadam            #+#    #+#             */
/*   Updated: 2024/06/24 18:16:25 by naadam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string.h>

class Weapon
{
    private:
        std::string type;
    public:
        Weapon(std::string type);
        std::string const& getType();
        void setType(std::string type);
};