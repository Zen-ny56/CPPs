/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naadam <naadam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 18:57:59 by naadam            #+#    #+#             */
/*   Updated: 2024/06/23 19:25:39 by naadam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
    int n = -3;
    Zombie* horde = zombieHorde(n, "LargeHorde");
    if (horde)
	{
		for (int i = 0; i < n; ++i)
            horde[i].announce();
        delete[] horde;
    }
    return (0);
}