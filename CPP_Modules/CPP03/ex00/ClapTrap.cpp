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

void	ClapTrap::reduce(){this->hit_points -= 1;}

void	ClapTrap::set_energypoints(){this->energy_points -= 1;}

void	ClapTrap::increase(){this->hit_points += 1;}

void ClapTrap::attack(const std::string &target)
{
	// std::cout << hit_points << std::endl;
	// std::cout << energy_points << std::endl;
	// std::cout << attack_damage << std::endl;
	if (energy_points > 0)
	{
		std::cout << "ClapTrap " << name << " attacks " << target << " losing 1 energy point" << std::endl;
		set_energypoints();
		std::cout << this->get_energypoints() << std::endl;
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (hit_points > 0 && (hit_points >= amount))
	{
		std::cout << "ClapTrap " << name << " has taken this damage from it's opponent: " << amount << std::endl;
		while (amount > 0)
		{
			reduce();
			amount--;
		}
		std::cout << "ClapTrap " << name << " has " << hit_points << " left" << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	while (amount > 0)
	{
		increase();
		amount--;
	}
	std::cout << "ClapTrap " << name << " has been repaired , it's new health is: " << hit_points << std::endl;
} 