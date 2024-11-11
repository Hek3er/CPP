#include "Cat.hpp"

Cat::Cat() {
	std::cout << "Cat Default Constructor Called" << std::endl;
	this->type = "Cat";
	this->brain = new Brain;
}

Cat::Cat( Cat& obj ) {
	std::cout << "Cat Copy Constructor Called" << std::endl;
	this->type = obj.type;
	this->brain = new Brain;
	*(this->brain) = *(obj.brain);
}

Cat& Cat::operator=( const Cat& obj) {
	if (this != &obj) {
		this->type = obj.type;
		if (this->brain) {
			delete this->brain;
		}
		this->brain = new Brain;
		*(this->brain) = *(obj.brain);
	}
	return (*this);
}

Cat::~Cat() {
	std::cout << "Cat Deconstructor Called" << std::endl;
	delete this->brain;
}

void	Cat::makeSound( void ) const {
	std::cout << "** MEAW **" << std::endl;
}

