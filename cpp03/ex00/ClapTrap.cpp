#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _Name("Robot"), _HitPoints(10), _EnergyPoints(10), _AttackDamage(0), _MaxPoints(10), _Type("ClapTrap") {
	std::cout << "ClapTrap Default Constructor Called" << std::endl;
}

ClapTrap::ClapTrap( std::string name ) {
	std::cout << "ClapTrap " << name <<": Default Constructor Called" << std::endl;
	this->_Name = name;
	this->_HitPoints = 10;
	this->_EnergyPoints = 10;
	this->_AttackDamage = 0;
	this->_MaxPoints = 10;
	this->_Type = "ClapTrap";
}

ClapTrap::ClapTrap( ClapTrap& obj ) {
	std::cout << "ClapTrap Copy Constructor Called" << std::endl;
	*this = obj;
}

ClapTrap& ClapTrap::operator=( const ClapTrap& obj) {
	std::cout << "ClapTrap Copy Assigment operator called" << std::endl;
	this->_Name = obj._Name;
	this->_HitPoints = obj._HitPoints;
	this->_AttackDamage = obj._AttackDamage;
	this->_EnergyPoints = obj._EnergyPoints;
	this->_MaxPoints = obj._MaxPoints;
	this->_Type = obj._Type;
	return (*this);
}

void ClapTrap::attack( const std::string& target ) {
	if (this->_EnergyPoints <= 0) {
		std::cout << this->_Type << " " << this->_Name << " has insufficient Energy Points" << std::endl;
		return;
	}
	if (this->_HitPoints <= 0) {
		std::cout << this->_Type << " " << this->_Name << " is dead 💀" << std::endl;
		return;
	}
	this->_EnergyPoints--;
	std::cout << this->_Type << " " << this->_Name << " attacks " << target << ", causing " << this->_AttackDamage << " points of damage" << std::endl;
}

void ClapTrap::takeDamage( unsigned int amount ) {
	if (this->_HitPoints <= 0) {
		std::cout << this->_Type << " " << this->_Name << " is dead 💀" << std::endl;
		return;
	}
	if (static_cast<int>(amount) > this->_HitPoints) {
		amount = this->_HitPoints;
	}
	this->_HitPoints -= amount;
	std::cout << this->_Type << " " << this->_Name << " took " << amount << " of damage" << std::endl;
	if (this->_HitPoints == 0) {
		std::cout << this->_Type << " " << this->_Name << " is dead 💀" << std::endl;
	}
}

void ClapTrap::beRepaired( unsigned int amount ) {
	if (this->_HitPoints <= 0) {
		std::cout << this->_Type << " " << this->_Name << " is dead 💀" << std::endl;
		return;
	}
	if (this->_EnergyPoints <= 0) {
		std::cout << this->_Type << " " << this->_Name << " has insufficient Energy Points" << std::endl;
		return;
	}
	if (static_cast<int>(amount) > this->_MaxPoints - this->_HitPoints) {
		std::cout << this->_Type << " " << this->_Name << " currenly have " << this->_HitPoints << " points and can hold up to maximum " << this->_MaxPoints << " points, the amout will be converted to " << this->_MaxPoints - this->_HitPoints << " points" << std::endl;
		amount = this->_MaxPoints - this->_HitPoints;
	}
	this->_HitPoints += amount;
	if (amount > 0) {
		std::cout << this->_Type << " " << this->_Name << " is being repaired by " << amount << std::endl;
		this->_EnergyPoints--;
	}
}

void	ClapTrap::PrintHitPoints() const {
	std::cout << "HitPoints : " << this->_HitPoints << std::endl;
}
void	ClapTrap::PrintEnergyPoints() const {
	std::cout << "EnergyPoints : " << this->_EnergyPoints << std::endl;
}
void	ClapTrap::PrintAttackDamage() const {
	std::cout << "AttackDamage : " << this->_AttackDamage << std::endl;
}
void	ClapTrap::PrintName() const {
	std::cout << "Name : " << this->_Name << std::endl;
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap Deconstructor Called" << std::endl;
}

