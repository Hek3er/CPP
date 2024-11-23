#include "AMateria.hpp"

AMateria::AMateria() {
	// std::cout << "Default Constructor Called" << std::endl;
	this->_Type = "Default AMateria";
}

AMateria::AMateria( std::string const &type ) {
	this->_Type = type;
}

AMateria::AMateria( const AMateria& obj ) {
	// std::cout << "Copy Constructor Called" << std::endl;
	*this = obj;
}

AMateria& AMateria::operator=( const AMateria& obj) {
	this->_Type = obj._Type;
	return (*this);
}

std::string	const& 	AMateria::getType() const {
	return (this->_Type);
}

void	AMateria::use(ICharacter& target) {
	std::cout << "* X AMateria used at " << target.getName() << std::endl;
}

AMateria::~AMateria() {}

