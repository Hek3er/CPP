#include "FragTrap.hpp"

int main() {

	// FragTrap	c;
	FragTrap	c("aymen");
	std::cout << "\n /**** FragTrap Info ****/\n" << std::endl;
	c.PrintName();
	c.PrintAttackDamage();
	c.PrintEnergyPoints();
	c.PrintHitPoints();
	std::cout << "\n /********************/\n" << std::endl;

	// **** damage test ****************************************
	// c.attack("bob");
	// c.beRepaired(1);
	// c.takeDamage(100);

	// std::cout << "\n /**** FragTrap Info ****/\n" << std::endl;
	// c.PrintName();
	// c.PrintAttackDamage();
	// c.PrintEnergyPoints();
	// c.PrintHitPoints();
	// std::cout << "\n /********************/\n" << std::endl;
	// ********************************************************

	// **** Repaire test ****************************************
	// c.takeDamage(9);
	// c.beRepaired(1);
	// std::cout << "\n /**** FragTrap Info ****/\n" << std::endl;
	// c.PrintName();
	// c.PrintAttackDamage();
	// c.PrintEnergyPoints();
	// c.PrintHitPoints();
	// std::cout << "\n /********************/\n" << std::endl;
	// ********************************************************

	// **** No points test ****************************************
	for (int i = 0; i < 100; i++) {
		c.attack("bob");
	}
	//no points
	c.PrintEnergyPoints();
	c.attack("bob");
	c.beRepaired(1);

	//special ability
	c.highFivesGuys();

	// ********************************************************

	std::cout << std::endl;
	return (0);

	return (0);
}
