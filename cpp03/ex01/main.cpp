#include "ScavTrap.hpp"

int main() {

	// ScavTrap	c;
	ScavTrap	c("aymen");
	std::cout << "\n /**** ScavTrap Info ****/\n" << std::endl;
	c.PrintName();
	c.PrintAttackDamage();
	c.PrintEnergyPoints();
	c.PrintHitPoints();
	std::cout << "\n /********************/\n" << std::endl;

	// **** damage test ****************************************
	c.attack("bob");
	c.beRepaired(1);
	c.takeDamage(100);

	std::cout << "\n /**** ScavTrap Info ****/\n" << std::endl;
	c.PrintName();
	c.PrintAttackDamage();
	c.PrintEnergyPoints();
	c.PrintHitPoints();
	std::cout << "\n /********************/\n" << std::endl;
	// ********************************************************

	// **** Repaire test ****************************************
	// c.takeDamage(9);
	// c.beRepaired(1);
	// std::cout << "\n /**** ScavTrap Info ****/\n" << std::endl;
	// c.PrintName();
	// c.PrintAttackDamage();
	// c.PrintEnergyPoints();
	// c.PrintHitPoints();
	// std::cout << "\n /********************/\n" << std::endl;
	// ********************************************************

	// **** No points test ****************************************
	// for (int i = 0; i < 50; i++) {
	// 	c.attack("bob");
	// }
	// //no points
	// c.PrintEnergyPoints();
	// c.attack("bob");
	// c.beRepaired(1);

	// //special ability
	// c.guardGate();

	// ********************************************************

	std::cout << std::endl;
	return (0);
}
