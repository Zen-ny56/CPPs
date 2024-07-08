#include "ClapTrap.hpp"

//Constructors
ClapTrap::ClapTrap()
{
	std::cout << "Default Constructor called" << std::endl;
	return ;
}

ClapTrap::ClapTrap(const std::string name) :name(name), hit_points(10), energy_points(10), attack_damage(0)
{
	std::cout << "Constructor has been called" << std::endl;
	return ;
}

ClapTrap::ClapTrap(const ClapTrap& copy) :name(copy.name), hit_points(copy.hit_points), energy_points(copy.energy_points), attack_damage(copy.attack_damage)
{
	std::cout << "Copy Constructor has been called" << std::endl;
	*this = copy;
}

//Getter functions
std::string ClapTrap::get_name() const
{
	return (this->name);
}

unsigned int ClapTrap::get_hitpoints() const
{
	return (this->hit_points);
}

unsigned int ClapTrap::get_energypoints() const
{
	return (this->energy_points);
}

unsigned int ClapTrap::get_attackdamage() const
{
	return (this->attack_damage);
}

//Assignment operator
ClapTrap& ClapTrap::operator=(const ClapTrap &copy)
{
	if (this != &copy)
	{
		//this->name = copy.get_name();
		this->hit_points = copy.get_hitpoints();
		this->energy_points = copy.get_energypoints();
		this->attack_damage = copy.get_attackdamage();
	}
	std::cout << "Copy assignment operator has been called" << std::endl;
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << "Deconstructor has been called" << std::endl;
	return ;
}

//Helping functions
void	ClapTrap::reduce_health(){this->hit_points -= 1;}

void	ClapTrap::reduce_energy(){this->energy_points -= 1;}

void	ClapTrap::increase_health(){this->hit_points += 1;}

void ClapTrap::attack(const std::string &target)
{
    if (energy_points == 0)
	{
		std::cout << "ClapTrap " << name << " has no energy to attack!" << std::endl;
		return;
    }
    if (hit_points == 0)
	{
		std::cout << "ClapTrap " << name << " is out of hit points and cannot attack!" << std::endl;
		return;
    }
	std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << attack_damage << " points of damage!" << std::endl;
    reduce_energy();
    std::cout << name << " now has " << energy_points << " energy points left." << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (hit_points == 0)
		std::cout << "ClapTrap " << name << " has not hitpoints left" << std::endl;
	if (hit_points >= amount)
	{
		std::cout << "ClapTrap " << name << " has taken this damage from it's opponent: " << amount << std::endl;
		while (amount > 0)
		{
			reduce_health();
			amount--;
		}
		std::cout << "ClapTrap " << name << " has " << hit_points << " left" << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (energy_points == 0)
	{
		std::cout << "ClapTrap " << name << " has no energy to repair!" << std::endl;
		return;
    }
	if (hit_points == 0)
	{
		std::cout << "ClapTrap " << name << " is out of hit points and cannot be repaired!" << std::endl;
		return;
	}
	while (amount > 0)
	{
		increase_health();
		reduce_energy();
		amount--;
	}
	std::cout << "ClapTrap " << name << " is repaired by " << amount << " points, now has " << hit_points << " hit points and " << energy_points << " energy points left." << std::endl;
}
