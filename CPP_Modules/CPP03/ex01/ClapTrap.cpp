#include "ClapTrap.hpp"

//Constructors and co
ClapTrap::ClapTrap()
{
	std::cout << "Default Constructor called" << std::endl;
	return ;
}

ClapTrap::ClapTrap(std::string name) :name(name), hit_points(10), energy_points(10), attack_damage(0), max(hit_points)
{
	std::cout << "Constructor has been called" << std::endl;
	return ;
}

ClapTrap::ClapTrap(const ClapTrap& copy) :name(copy.name), hit_points(copy.hit_points), energy_points(copy.energy_points), attack_damage(copy.attack_damage), max(copy.hit_points)
{
	std::cout << "Copy Constructor has been called" << std::endl;
	*this = copy;
}

ClapTrap& ClapTrap::operator=(const ClapTrap &copy)
{
	if (this != &copy)
	{
		this->name = copy.get_name();
		this->hit_points = copy.get_hitpoints();
		this->energy_points = copy.get_energypoints();
		this->attack_damage = copy.get_attackdamage();
		this->max = copy.get_hitpoints();
	}
	std::cout << "Copy assignment operator has been called" << std::endl;
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << "Deconstructor has been called" << std::endl;
	return ;
}

void ClapTrap::attack(std::string &target)
{
    if (energy_points == 0)
	{
		std::cout << this->get_name() << " has no energy to attack!" << std::endl;
		return;
    }
    if (hit_points == 0)
	{
		std::cout << this->get_name() << " is out of hit points and cannot attack!" << std::endl;
		return;
    }
	std::cout << this->get_name() << " attacks " << target << ", causing " << this->get_attackdamage() << " points of damage!" << std::endl;
    reduce_energy();
    std::cout << this->get_name() << " now has " << this->get_energypoints() << " energy points left." << std::endl;
}
   
void ClapTrap::takeDamage(unsigned int amount)
{
	if (hit_points == 0)
		std::cout  << this->get_name() << " has not hitpoints left" << std::endl;
	if (amount > 0)
	{
		std::cout << this->get_name() << " has taken this damage from it's opponent: " << amount << std::endl;
		while (amount > 0 && this->get_hitpoints() > 0)
		{
			reduce_health();
			amount--;
		}
		std::cout <<  this->get_name() << " has " << this->get_hitpoints() << " hit_points left" << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (energy_points == 0)
	{
		std::cout  << this->get_name() << " has no energy to repair!" << std::endl;
		return;
    }
	int temp = amount;
	unsigned int i = 0;
	while (amount > 0 && this->get_energypoints() > 0 && (i < this->get_max()))
	{
		if (this->get_hitpoints() == this->get_max())
			break;
		increase_health();
		reduce_energy();
		amount--;
		i++;
	}
	std::cout <<  this->get_name() << " is repaired by " << temp << " points, now has " << this->get_hitpoints() << " hit points and " << this->get_energypoints() << " energy points left." << std::endl;
}

//Getter functions
std::string ClapTrap::get_name() const
{
	return (this->name);
}

unsigned int ClapTrap::get_hitpoints() const
{
	if (this->hit_points > this->max)
		return (this->max);
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

unsigned int ClapTrap::get_max() const
{
	return (this->max);
}

//Helping functions & setters
void	ClapTrap::reduce_health(){this->hit_points -= 1;}

void	ClapTrap::reduce_energy(){this->energy_points -= 1;}

void	ClapTrap::increase_health(){this->hit_points += 1;}

void	ClapTrap::set_attackdamage(unsigned int amount)
{
	this->attack_damage = amount;
}