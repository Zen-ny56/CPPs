#pragma once

#include <iostream>
#include <string.h>

class ClapTrap
{
	protected:
		std::string name;
		unsigned int hit_points;//Health
		unsigned int energy_points;//Stamina
		unsigned int attack_damage;//Damage taken
	public:
		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap& copy);
		ClapTrap& operator=(const ClapTrap& copy);
		virtual ~ClapTrap();
		void	attack(std::string &target);
		void	takeDamage(unsigned int amount);
		void 	beRepaired(unsigned int amount);
		std::string get_name() const;
		unsigned int get_hitpoints() const;
		unsigned int get_energypoints() const;
		unsigned int get_attackdamage() const;
		void	reduce_health();
		void	increase_health();
		void	reduce_energy();
		void	set_attackdamage(unsigned int attack_damage);
};

