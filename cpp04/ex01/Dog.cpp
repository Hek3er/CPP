#include "Dog.hpp"

Dog::Dog() {
	std::cout << "Dog Default Constructor Called" << std::endl;
	this->type = "Dog";
	this->brain = new Brain;
}

Dog::Dog( Dog& obj ) {
	std::cout << "Dog Copy Constructor Called" << std::endl;
	this->type = obj.type;
	this->brain = new Brain;
	*(this->brain) = *(obj.brain);
}

Dog& Dog::operator=( const Dog& obj) {
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

Dog::~Dog() {
	std::cout << "Dog Deconstructor Called" << std::endl;
	delete this->brain;
}

void	Dog::makeSound( void ) const {
	std::cout << "** HAW HAW **" << std::endl;
}
