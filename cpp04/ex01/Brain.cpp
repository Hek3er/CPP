#include "Brain.hpp"

Brain::Brain() {
	std::cout << "Brain Constructor Called" << std::endl;

}

Brain::Brain( Brain& obj ) {
	std::cout << "Brain Copy Constructor Called" << std::endl;
	for (int i = 0; i < 100; i++) {
		this->ideas[i] = obj.ideas[i];
	}
}

Brain& Brain::operator=( const Brain& obj) {
	for (int i = 0; i < 100; i++) {
		this->ideas[i] = obj.ideas[i];
	}
	return (*this);
}

Brain::~Brain() {
	std::cout << "Brain Deconstructor Called" << std::endl;
}

