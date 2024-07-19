#include "ClapTrap.hpp"
#include "ScavTrap.hpp"


int main()
{
    std::string target = "enemy";

    // // Mixed operations for ClapTrap
    // ClapTrap claptrap("Player 1");
    // claptrap.attack(target);
    // claptrap.takeDamage(3);
    // claptrap.beRepaired(2);
    // claptrap.attack(target);
    // claptrap.takeDamage(5);
    // claptrap.beRepaired(3);

    // Mixed operations for ScavTrap
    ScavTrap scavtrap("Player 2");
    scavtrap.attack(target);
    scavtrap.takeDamage(10);
    scavtrap.beRepaired(5);
    for (int i = 0; i < 33; ++i)
    scavtrap.attack(target);
    scavtrap.takeDamage(15);
    scavtrap.beRepaired(400);
    scavtrap.guardGate();

    return 0;
}