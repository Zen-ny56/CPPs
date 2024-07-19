#include "FragTrap.hpp"

FragTrap::FragTrap(): ClapTrap("Default")
{
    this->hit_points = 100;
    this->energy_points = 100;
    this->attack_damage = 30;
    std::cout << "FragTrap default constructor has been called" << std::endl;
}

FragTrap::FragTrap(std::string name) :ClapTrap(name)
{
    this->hit_points = 100;
    this->energy_points = 100;
    this->attack_damage = 30;
    std::cout << "FragTrap parameterized constructor has been called" << std::endl;
}

FragTrap::FragTrap(const FragTrap& copy) : ClapTrap(copy)
{
    this->hit_points = 100;
    this->energy_points = 100;
    this->attack_damage = 30;
    std::cout << "FragTrap copy constructor has been called" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& copy)
{
    if (this != &copy)
        ClapTrap::operator=(copy);
    std::cout << "FragTrap copy assignment operator has been called" << std::endl;
    return (*this);
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap deconstructor has been called" << std::endl;
}

void    FragTrap::highFiveGuys()
{
    std::cout << "Can I have a high five" << std::endl;
}