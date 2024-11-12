#include "AMateria.hpp"

AMateria::AMateria() {
	std::cout << "Default Constructor Called" << std::endl;

}

AMateria::AMateria( AMateria& obj ) {
	std::cout << "Copy Constructor Called" << std::endl;

	*this = obj;
}

AMateria& AMateria::operator=( const AMateria& obj) {

	return (*this);
}

AMateria::~AMateria() {
	std::cout << "Deconstructor Called" << std::endl;
}

