#include "Brain.hpp"

Brain::Brain() {
	std::cout << "Brain Constructor Called" << std::endl;

}

Brain::Brain( Brain& obj ) {
	std::cout << "Brain Copy Constructor Called" << std::endl;

	*this = obj;
}

Brain& Brain::operator=( const Brain& obj) {
	for (size_t i = 0; i < this->ideas->size(); i++) {
		this->ideas[i] = obj.ideas[i];
	}
	return (*this);
}

Brain::~Brain() {
	std::cout << "Brain Deconstructor Called" << std::endl;
}

