#pragma once

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {

public:
	ScavTrap();
	ScavTrap( std::string Name );
	ScavTrap( ScavTrap& scav ); // fill later
	void attack(const std::string& target);
	void guardGate();
	~ScavTrap();
};