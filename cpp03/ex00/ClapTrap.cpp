#include "ClapTrap.hpp"

ClapTrap::ClapTrap( std::string Name ) {

	std::cout << "Constructor Called" << std::endl;

	_Name = Name;
	_HitPoints = 10;
	_EnergyPoints = 10;
	_AttackDamage = 0;

}

ClapTrap::ClapTrap( ClapTrap& clap ) {

	std::cout << "Copy Constructor Called" << std::endl;

	*this = clap;
}

ClapTrap& ClapTrap::operator=( const ClapTrap& clap ) {
	this->_Name = clap._Name;
	this->_AttackDamage = clap._AttackDamage;
	this->_EnergyPoints = clap._EnergyPoints;
	this->_HitPoints = clap._HitPoints;
}

ClapTrap::~ClapTrap( ) {

	std::cout << "Deconstructor Called" << std::endl;

}

void ClapTrap::attack(const std::string& target) {

	if (this->_EnergyPoints == 0) {
		std::cout << "ClapTrap " << this->_Name << " there is " << this->_EnergyPoints << " Energy points left" << std::endl;
		return ;
	}
	if (this->_HitPoints == 0) {
		std::cout << "ClapTrap " << this->_Name << " there is " << this->_HitPoints << " Hit points left" << std::endl;
	}
	
}

