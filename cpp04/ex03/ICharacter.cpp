#include "ICharacter.hpp"

ICharacter::ICharacter() {
	std::cout << "Default Constructor Called" << std::endl;

}

ICharacter::ICharacter( ICharacter& obj ) {
	std::cout << "Copy Constructor Called" << std::endl;

	*this = obj;
}

ICharacter& ICharacter::operator=( const ICharacter& obj) {

	return (*this);
}

ICharacter::~ICharacter() {
	std::cout << "Deconstructor Called" << std::endl;
}

