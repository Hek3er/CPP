#include "ScavTrap.hpp"

ScavTrap::ScavTrap() {
	std::cout << "ScavTrap Default Constructor Called" << std::endl;
	this->_Name = "scavbot";
	this->_HitPoints = 100;
	this->_EnergyPoints = 50;
	this->_AttackDamage = 20;
	this->_MaxPoints = 100;
	this->_Type = "ScavTrap";
}

ScavTrap::ScavTrap( std::string name ) {
	std::cout << "ScavTrap "<< name <<" Constructor Called" << std::endl;
	this->_Name = name;
	this->_HitPoints = 100;
	this->_EnergyPoints = 50;
	this->_AttackDamage = 20;
	this->_MaxPoints = 100;
}

ScavTrap::ScavTrap( ScavTrap& obj ) {
	std::cout << "ScavTrap Copy Constructor Called" << std::endl;
	*this = obj;
}

ScavTrap& ScavTrap::operator=( const ScavTrap& obj) {
	this->_Name = obj._Name;
	this->_HitPoints = obj._HitPoints;
	this->_AttackDamage = obj._AttackDamage;
	this->_EnergyPoints = obj._EnergyPoints;
	this->_MaxPoints = obj._MaxPoints;
	return (*this);
}

void ScavTrap::attack( const std::string& target ) {
	if (this->_EnergyPoints <= 0) {
		std::cout << this->_Type << " " << this->_Name << " has insufficient Energy Points" << std::endl;
		return;
	}
	if (this->_HitPoints <= 0) {
		std::cout << "ScavTrap " << this->_Name << " is dead 💀" << std::endl;
		return;
	}
	this->_EnergyPoints--;
	std::cout << "ScavTrap " << this->_Name << " attacks " << target << ", causing " << this->_AttackDamage << " points of damage" << std::endl;
}

void ScavTrap::guardGate() {
	std::cout << "ScavTrap is now in Gate keeper mode" << std::endl;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap Deconstructor Called" << std::endl;
}

