#pragma once

# include <iostream>

class ClapTrap {

public:

	ClapTrap();
	ClapTrap( std::string name );
	ClapTrap( ClapTrap& obj );
	void attack( const std::string& target );
	void takeDamage( unsigned int amount );
	void beRepaired( unsigned int amount );
	ClapTrap& operator=( const ClapTrap& obj );
	void	PrintHitPoints() const;
	void	PrintEnergyPoints() const;
	void	PrintAttackDamage() const;
	void	PrintName() const;
	~ClapTrap();

protected:
	std::string _Name;
	int			_HitPoints;
	int			_EnergyPoints;
	int			_AttackDamage;
	int			_MaxPoints;
	std::string	_Type;
};