#include "Brain.hpp"

Brain::Brain() {
	std::cout << "Brain Constructor Called" << std::endl;

}

Brain::Brain( Brain& obj ) {
	std::cout << "Brain Copy Constructor Called" << std::endl;

	*this = obj;
}

Brain& Brain::operator=( const Brain& obj) {
	
	return (*this);
}

Brain::~Brain() {
	std::cout << "Brain Deconstructor Called" << std::endl;
}

