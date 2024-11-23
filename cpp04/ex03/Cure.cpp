#include "Cure.hpp"

Cure::Cure() {
	// std::cout << "Default Constructor Called" << std::endl;
	this->_Type = "cure";
}

Cure::Cure(const Cure& obj )  {
	// std::cout << "Copy Constructor Called" << std::endl;
	// this->_Type = "cure";
	*this = obj;
}

Cure& Cure::operator=( const Cure& obj) {
	this->_Type = obj._Type;
	return (*this);
}

AMateria* 	Cure::clone() const {
	AMateria* ptr = new Cure(*this);
	return (ptr);
}

void		Cure::use(ICharacter& target) {
	std::cout << "* heals "<< target.getName() <<"'s wounds *" << std::endl;
}

Cure::~Cure() {
	// std::cout << "Deconstructor Called" << std::endl;
}

