#include "Cure.hpp"

Cure::Cure() {
	std::cout << "Default Constructor Called" << std::endl;
	this->_Type = "cure";
}

Cure::Cure( Cure& obj ) {
	std::cout << "Copy Constructor Called" << std::endl;

	*this = obj;
}

Cure& Cure::operator=( const Cure& obj) {
	this->_Type = obj._Type;
	return (*this);
}

AMateria* 	Cure::clone() const {
	return (new Cure);
}

void		use(ICharacter& target) {
	std::cout << "* heals "<< target.getName() <<"’s wounds *" << std::endl;
}

Cure::~Cure() {
	std::cout << "Deconstructor Called" << std::endl;
}

