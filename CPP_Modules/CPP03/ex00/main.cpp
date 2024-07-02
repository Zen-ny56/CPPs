#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap claptrap1("CT-01");
	ClapTrap claptrap2("CT-02");

	claptrap1.attack("target1");
	claptrap1.takeDamage(5);
	claptrap1.beRepaired(3);

	claptrap2.attack("target2");
	claptrap2.takeDamage(8);
	claptrap2.beRepaired(2);

	return (0);
}
