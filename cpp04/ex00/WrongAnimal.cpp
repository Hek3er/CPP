#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() {
	std::cout << "WrongAnimal Default Constructor Called" << std::endl;
	this->type = "Undefined WrongAnimal";
}

WrongAnimal::WrongAnimal( WrongAnimal& obj ) {
	std::cout << "WrongAnimal Copy Constructor Called" << std::endl;

	*this = obj;
}

WrongAnimal& WrongAnimal::operator=( const WrongAnimal& obj) {
	this->type = obj.type;
	return (*this);
}

WrongAnimal::~WrongAnimal() {
	std::cout << "WrongAnimal Deconstructor Called" << std::endl;
}

void WrongAnimal::makeSound( void ) const {
	std::cout << "*WrongAnimal Sound Undefined*" << std::endl;
}

std::string	WrongAnimal::getType( void ) const {
	return (this->type);
}