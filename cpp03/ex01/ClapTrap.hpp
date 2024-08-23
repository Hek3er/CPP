#pragma once

#include <iostream>

class ClapTrap {

public:

	ClapTrap();
	ClapTrap( std::string Name );
	ClapTrap( ClapTrap& clap );
	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	ClapTrap& operator=( const ClapTrap& clap );
	~ClapTrap();

protected:

	std::string _Name;
	int			_HitPoints;
	int			_EnergyPoints;
	int			_AttackDamage;
};