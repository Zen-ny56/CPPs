#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
    std::string target = "enemy";

    // Mixed operations for ClapTrap
    ClapTrap claptrap("CL4P-TP");
    claptrap.attack(target);
    claptrap.takeDamage(5);
    claptrap.beRepaired(4);
    claptrap.attack(target);
    claptrap.takeDamage(10);
    claptrap.beRepaired(5);

    // Mixed operations for ScavTrap
    // ScavTrap scavtrap("SC4V-TP");
    // scavtrap.attack(target);
    // scavtrap.takeDamage(10);
    // scavtrap.beRepaired(5);
    // scavtrap.attack(target);
    // scavtrap.takeDamage(15);
    // scavtrap.beRepaired(10);
    // scavtrap.guardGate();

    // // Mixed operations for FragTrap
    // FragTrap fragtrap("BB-TP");
    // fragtrap.attack(target);
    // fragtrap.takeDamage(10);
    // fragtrap.beRepaired(5);
    // fragtrap.attack(target);
    // fragtrap.takeDamage(20);
    // fragtrap.beRepaired(15);
    // fragtrap.highFiveGuys();

    // return 0;
}