#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
    std::string target = "enemy";

    // // Test ClapTrap
    // ClapTrap claptrap("CL4P-TP");
    // claptrap.attack(target);    // Should display attack message
    // claptrap.takeDamage(5);     // Should reduce hit points by 5
    // claptrap.beRepaired(3);     // Should increase hit points by 3

    // // Test ScavTrap
    // ScavTrap scavtrap("SC4V-TP");
    // scavtrap.attack(target);    // Should display attack message
    // scavtrap.takeDamage(20);    // Should reduce hit points by 20
    // scavtrap.beRepaired(10);    // Should increase hit points by 10
    // scavtrap.guardGate();       // Should activate Gatekeeper mode

    // Test FragTrap
    FragTrap fragtrap("BB-TP");
    fragtrap.attack(target);    // Should display attack message
    fragtrap.takeDamage(20);    // Should reduce hit points by 20
    fragtrap.beRepaired(82);    // Should increase hit points by 10
    fragtrap.highFiveGuys();    // Should ask for high five

    return 0;
}