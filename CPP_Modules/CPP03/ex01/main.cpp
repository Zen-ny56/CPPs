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
    ScavTrap fragtrap("BB-TP");
    fragtrap.attack(target);    // Should display attack message
    fragtrap.takeDamage(20);    // Should reduce hit points by 20
    fragtrap.beRepaired(42);    // Should increase hit points by 10
    // Should ask for high five


    return 0;
}