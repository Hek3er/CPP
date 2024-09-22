#pragma once

# include <iostream>
# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap{

public:

	ScavTrap();
	ScavTrap( std::string name );
	ScavTrap( ScavTrap& obj );
	ScavTrap& operator=( const ScavTrap& obj );
	void attack( const std::string& target );
	void guardGate();
	~ScavTrap();
};