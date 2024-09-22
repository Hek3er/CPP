#include "ScavTrap.hpp"

ScavTrap::ScavTrap() {

	std::cout << "ScavTrap " << " Constructor called!" << std::endl;
	
	this->_HitPoints = 100;
	this->_EnergyPoints = 100;
	this->_AttackDamage = 30;
}

ScavTrap::ScavTrap( std::string Name ) : ClapTrap( Name ) {

	std::cout << "ScavTrap " << Name << " Constructor called!" << std::endl;

	this->_HitPoints = 100;
	this->_EnergyPoints = 100;
	this->_AttackDamage = 30;
}

ScavTrap::ScavTrap( ScavTrap& scav ) {
	std::cout << "ScavTrap " << this->_Name << " Copy Constructor called" << std::endl;
	*this = scav;
}

void ScavTrap::attack(const std::string& target) {
	if (this->_HitPoints && this->_EnergyPoints) {
		std::cout << "ScavTrap "<< this->_Name <<" attacks " << target << " , causing "<< this->_AttackDamage  <<" points of damage!" << std::endl;
		this->_EnergyPoints--;
	} else {
		std::cout << "ScavTrap " << this->_Name << " is dead!" << std::endl;
	}
}

void ScavTrap::guardGate() {
	std::cout << "ScavTrap is now in Gate keeper mode!" << std::endl;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap: " << _Name << " destructed!" <<std::endl;
}