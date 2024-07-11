/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naadam <naadam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 17:33:35 by naadam            #+#    #+#             */
/*   Updated: 2024/06/24 17:37:35 by naadam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int main()
{
    Weapon ak("AK-47");
    HumanA zeni("Zeni", ak);
    zeni.attack();
    HumanB jim("Jim");
    //jim.set_Weapon(ak);
    jim.attack();  // Jim has no weapon
    return (0);
}
