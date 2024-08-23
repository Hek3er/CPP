#include "ClapTrap.hpp"

ClapTrap::ClapTrap() {

	std::cout <<"Constructor Called" << std::endl;

	_Name = "robot";
	_HitPoints = 10;
	_EnergyPoints = 10;
	_AttackDamage = 0;
}

ClapTrap::ClapTrap( std::string Name ) {

	std::cout << Name << ": Constructor Called" << std::endl;

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
	return (*this);
}

ClapTrap::~ClapTrap( ) {
	std::cout << this->_Name << ": Deconstructor Called" << std::endl;
}

void ClapTrap::attack(const std::string& target) {
	if (this->_HitPoints && this->_EnergyPoints) {
		std::cout << "ClapTrap "<< this->_Name <<" attacks " << target << " , causing "<< this->_AttackDamage  <<" points of damage!" << std::endl;
		this->_EnergyPoints--;
	} else {
		std::cout << "ClapTrap " << this->_Name << " is dead!" << std::endl;
	}
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (amount > 10) {
		std::cout << "Damage amount should not exceed 10" << std::endl;
		return ;
	}
	if (this->_HitPoints) {
		std::cout << "ClapTrap " <<this->_Name << " took " << amount << " of damage!" << std::endl;
		if (this->_HitPoints < static_cast<int>(amount))
			this->_HitPoints = amount;
		this->_HitPoints -= amount;
	} else {
		std::cout << "ClapTrap " << this->_Name << " is dead!" << std::endl;
	}
}


void ClapTrap::beRepaired(unsigned int amount) {
	if (this->_HitPoints && this->_EnergyPoints) {
		if (this->_HitPoints == 10) {
			std::cout << "ClapTrap " << this->_Name << " has full health!" << std::endl;
			return ;
		}
		if (this->_HitPoints + amount > 10) {
 			std::cout << "Amount of repair is too big, this is the max value "<< (this->_HitPoints + amount) - 10 <<std::endl;
			return ;
		}
		std::cout << "ClapTrap " << this->_Name << " is being repaired by " << amount << std::endl;
		this->_EnergyPoints--;
		this->_HitPoints += amount;
	} else {
		std::cout << "ClapTrap " << this->_Name << " is dead!" << std::endl;
	}
}