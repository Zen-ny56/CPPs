#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap("Default")
{
	hit_points = 100;
	energy_points = 50;
	attack_damage = 20;
	std::cout << "ScavTrap default onstructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) :ClapTrap(name)
{
	hit_points = 100;
	energy_points = 50;
	attack_damage = 20;
	std::cout << "ScavTrap parameter constructor has been called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& copy) : ClapTrap(copy)
{
	hit_points = 100;
	energy_points = 50;
	attack_damage = 20;
	std::cout << "ScavTrap copy constructor has been called" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& copy)
{
	if (this != &copy)
		ClapTrap::operator=(copy);
	std::cout << "ScavTrap copy assigment operator has been called" << std::endl;
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap Deconstructor called" << std::endl;
}


void	ScavTrap::guardGate()
{
	std::cout  << this->get_name() << " is now in Gatekeeper mode." << std::endl;
}
