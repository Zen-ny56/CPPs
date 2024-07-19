#include "ClapTrap.hpp"

int main()
{
    ClapTrap clap1("Clap1");

    // Hit points cannot go below 0
	clap1.attack("S");
    clap1.takeDamage(8); // Should show hit points as 0

    // Repair should still work correctly when at 0 hit points
    clap1.beRepaired(12); // Should increase hit points to 10

    // Hit points should not be negative
    clap1.takeDamage(3); // Should show hit points as 0

    return 0;
}