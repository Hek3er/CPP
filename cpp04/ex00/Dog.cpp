#include "Dog.hpp"

Dog::Dog() {
	std::cout << "Dog Default Constructor Called" << std::endl;
	this->type = "Dog";
}

Dog::Dog( Dog& obj ) {
	std::cout << "Dog Copy Constructor Called" << std::endl;
	this->type = obj.type;
	*this = obj;
}

Dog& Dog::operator=( const Dog& obj) {
	this->type = obj.type;
	return (*this);
}

Dog::~Dog() {
	std::cout << "Dog Deconstructor Called" << std::endl;
}

void	Dog::makeSound( void ) const {
	std::cout << "** HAW HAW **" << std::endl;
}
