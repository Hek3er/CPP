#include "FragTrap.hpp"

FragTrap::FragTrap() {
	std::cout << "FragTrap Default Constructor Called" << std::endl;
	this->_Name = "Fragbot";
	this->_HitPoints = 100;
	this->_EnergyPoints = 100;
	this->_AttackDamage = 30;
	this->_MaxPoints = 100;
	this->_Type = "FragTrap";
}

FragTrap::FragTrap( std::string name ) {
	std::cout << "FragTrap "<< name <<" Constructor Called" << std::endl;
	this->_Name = name;
	this->_HitPoints = 100;
	this->_EnergyPoints = 100;
	this->_AttackDamage = 30;
	this->_MaxPoints = 100;
	this->_Type = "FragTrap";
}

FragTrap::FragTrap( FragTrap& obj ) {
	std::cout << "FragTrap Copy Constructor Called" << std::endl;
	*this = obj;
}

FragTrap& FragTrap::operator=( const FragTrap& obj) {
	this->_Name = obj._Name;
	this->_HitPoints = obj._HitPoints;
	this->_AttackDamage = obj._AttackDamage;
	this->_EnergyPoints = obj._EnergyPoints;
	this->_MaxPoints = obj._MaxPoints;
	this->_Type = obj._Type;
	return (*this);
}

void FragTrap::highFivesGuys(void) {
	std::cout << "positive high fives request" << std::endl;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap Deconstructor Called" << std::endl;
}

