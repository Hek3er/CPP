#include "Animal.hpp"

Animal::Animal() {
	std::cout << "Animal Default Constructor Called" << std::endl;
	this->type = "Undefined Animal";
}

Animal::Animal( Animal& obj ) {
	std::cout << "Animal Copy Constructor Called" << std::endl;

	*this = obj;
}

Animal& Animal::operator=( const Animal& obj) {
	this->type = obj.type;
	return (*this);
}

Animal::~Animal() {
	std::cout << "Animal Deconstructor Called" << std::endl;
}

std::string	Animal::getType( void ) const {
	return (this->type);
}