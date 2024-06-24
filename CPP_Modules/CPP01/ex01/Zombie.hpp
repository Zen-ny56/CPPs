/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naadam <naadam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 18:52:17 by naadam            #+#    #+#             */
/*   Updated: 2024/06/23 19:20:00 by naadam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Zombie
{
	private:
		std::string name;
	public:
		Zombie(std::string name);
        Zombie();
		~Zombie();
		void	announce(void);
		void 	set_name(std::string name);
		void	get_name(std::string name);
};
Zombie* zombieHorde(int N, std::string name);