#include "Brain.hpp"

Brain::Brain() {
	std::cout << "Brain Constructor Called" << std::endl;

}

Brain::Brain( Brain& obj ) {
	std::cout << "Brain Copy Constructor Called" << std::endl;
	std::copy(obj.ideas, obj.ideas + 100, this->ideas);
}

Brain& Brain::operator=( const Brain& obj) {
	std::copy(obj.ideas, obj.ideas + 100, this->ideas);
	return (*this);
}

Brain::~Brain() {
	std::cout << "Brain Deconstructor Called" << std::endl;
}

