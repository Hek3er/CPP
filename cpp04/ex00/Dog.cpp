#include "Dog.hpp"

Dog::Dog() {
	std::cout << "Default Constructor Called" << std::endl;

}

Dog::Dog( Dog& obj ) {
	std::cout << "Copy Constructor Called" << std::endl;

	*this = obj;
}

Dog& Dog::operator=( const Dog& obj) {

	return (*this);
}

Dog::~Dog() {
	std::cout << "Deconstructor Called" << std::endl;
}

