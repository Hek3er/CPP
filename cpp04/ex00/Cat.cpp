#include "Cat.hpp"

Cat::Cat() {
	std::cout << "Default Constructor Called" << std::endl;

}

Cat::Cat( Cat& obj ) {
	std::cout << "Copy Constructor Called" << std::endl;

	*this = obj;
}

Cat& Cat::operator=( const Cat& obj) {

	return (*this);
}

Cat::~Cat() {
	std::cout << "Deconstructor Called" << std::endl;
}

