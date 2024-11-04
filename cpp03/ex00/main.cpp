#include "ClapTrap.hpp"

int main() {

	// ClapTrap	c;
	ClapTrap	c("aymen");
	std::cout << "\n /**** ClapTrap Info ****/\n" << std::endl;
	c.PrintName();
	c.PrintAttackDamage();
	c.PrintEnergyPoints();
	c.PrintHitPoints();
	std::cout << "\n /********************/\n" << std::endl;

	// **** damage test ****************************************
	// c.attack("bob");
	// c.beRepaired(1);
	// c.takeDamage(100);

	// std::cout << "\n /**** ClapTrap Info ****/\n" << std::endl;
	// c.PrintName();
	// c.PrintAttackDamage();
	// c.PrintEnergyPoints();
	// c.PrintHitPoints();
	// std::cout << "\n /********************/\n" << std::endl;
	// ********************************************************

	// **** Repaire test ****************************************
	// c.takeDamage(9);
	// c.beRepaired(1);
	// std::cout << "\n /**** ClapTrap Info ****/\n" << std::endl;
	// c.PrintName();
	// c.PrintAttackDamage();
	// c.PrintEnergyPoints();
	// c.PrintHitPoints();
	// std::cout << "\n /********************/\n" << std::endl;
	// ********************************************************

	// **** No points test ****************************************
	c.attack("bob");
	c.attack("bob");
	c.attack("bob");
	c.attack("bob");
	c.attack("bob");
	c.attack("bob");
	c.attack("bob");
	c.attack("bob");
	c.attack("bob");
	c.attack("bob");
	//no points
	c.PrintEnergyPoints();
	c.attack("bob");
	c.beRepaired(1);

	// ********************************************************

	std::cout << std::endl;
	return (0);
}
