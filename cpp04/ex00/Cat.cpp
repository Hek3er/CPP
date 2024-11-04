#include "Cat.hpp"

Cat::Cat() {
	std::cout << "Cat Default Constructor Called" << std::endl;
	this->type = "Cat";
}

Cat::Cat( Cat& obj ) {
	std::cout << "Cat Copy Constructor Called" << std::endl;

	*this = obj;
}

Cat& Cat::operator=( const Cat& obj) {
	this->type = obj.type;
	return (*this);
}

Cat::~Cat() {
	std::cout << "Cat Deconstructor Called" << std::endl;
}

void	Cat::makeSound( void ) const {
	std::cout << "** MEAW **" << std::endl;
}

