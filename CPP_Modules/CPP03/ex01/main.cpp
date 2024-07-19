#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
    std::string forty = "enemy";
    ClapTrap claptrap("Player 1");
    claptrap.attack(forty);
    claptrap.takeDamage(5);
    claptrap.beRepaired(3);

    ScavTrap scavtrap("Player 2");
    scavtrap.attack(forty);
    scavtrap.takeDamage(20);
    scavtrap.beRepaired(10);
    scavtrap.guardGate();

    return 0;
}