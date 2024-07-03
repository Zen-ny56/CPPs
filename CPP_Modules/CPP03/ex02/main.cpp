#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
	std::string forty = "enemy";
	ClapTrap claptrap("CL4P-TP");
	claptrap.attack(forty);
	claptrap.takeDamage(5);
	claptrap.beRepaired(3);

	ScavTrap scavtrap ("SC4V-TP");
	scavtrap.attack(forty);
	scavtrap.takeDamage(20);
	scavtrap.beRepaired(10);
	scavtrap.guardGate();

	FragTrap fragtrap ("SC4V-TP");
	fragtrap.attack(forty);
	fragtrap.takeDamage(20);
	fragtrap.beRepaired(10);
	fragtrap.highFiveGuys();
	return 0;
}