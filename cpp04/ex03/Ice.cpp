#include "Ice.hpp"

Ice::Ice() {
	// std::cout << "Default Constructor Called" << std::endl;
	this->_Type = "ice";
}

Ice::Ice( const Ice& obj ) {
	// std::cout << "Copy Constructor Called" << std::endl;

	*this = obj;
}

Ice& Ice::operator=( const Ice& obj) {
	this->_Type = obj._Type;
	return (*this);
}

AMateria* 	Ice::clone() const {
	AMateria* ptr = new Ice(*this);
	return (ptr);
}

void		Ice::use(ICharacter& target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

Ice::~Ice() {
	// std::cout << "Deconstructor Called" << std::endl;
}

