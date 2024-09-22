#include "Animal.hpp"

Animal::Animal() {
	std::cout << "Default Constructor Called" << std::endl;

}

Animal::Animal( Animal& obj ) {
	std::cout << "Copy Constructor Called" << std::endl;

	*this = obj;
}

Animal& Animal::operator=( const Animal& obj) {

	return (*this);
}

Animal::~Animal() {
	std::cout << "Deconstructor Called" << std::endl;
}

