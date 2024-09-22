#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() {
	std::cout << "Default Constructor Called" << std::endl;

}

DiamondTrap::DiamondTrap( DiamondTrap& obj ) {
	std::cout << "Copy Constructor Called" << std::endl;

	*this = obj;
}

DiamondTrap& DiamondTrap::operator=( const DiamondTrap& obj) {

	return (*this);
}

DiamondTrap::~DiamondTrap() {
	std::cout << "Deconstructor Called" << std::endl;
}

