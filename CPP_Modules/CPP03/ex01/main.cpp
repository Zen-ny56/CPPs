#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
    std::string forty = "enemy";
    ClapTrap claptrap("CL4P-TP");
    claptrap.attack(forty);
    claptrap.takeDamage(5);
    claptrap.beRepaired(3);

    ScavTrap scavtrap("SC4V-TP");
    scavtrap.attack(forty);
    scavtrap.takeDamage(20);
    scavtrap.beRepaired(10);
    scavtrap.guardGate();

    return 0;
}