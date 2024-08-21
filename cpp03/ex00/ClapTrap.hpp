#pragma once

#include <iostream>

class ClapTrap {

public:

	ClapTrap( std::string Name );
	ClapTrap( ClapTrap& clap );
	void attack(const std::string& target);
	ClapTrap& operator=( const ClapTrap& clap );
	~ClapTrap();

private:

	std::string _Name;
	int			_HitPoints;
	int			_EnergyPoints;
	int			_AttackDamage;
};