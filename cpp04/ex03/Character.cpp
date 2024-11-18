#include "Character.hpp"

Character::Character() {
	std::cout << "Default Constructor Called" << std::endl;
	for (int i = 0; i < 4; i++) {
		arr[i] = NULL;
	}
	_name = "default name";
}

Character::Character( std::string name ) {
	std::cout << "Default Constructor Called" << std::endl;
	for (int i = 0; i < 4; i++) {
		arr[i] = NULL;
		gc[i] = NULL;
	}
	_name = name;
}

Character::Character( Character& obj ) {
	std::cout << "Copy Constructor Called" << std::endl;
	for (int i = 0; i < 4; i++) {
		arr[i] = obj.arr[i];
		gc[i] = obj.gc[i];
	}
	*this = obj;
}

Character& Character::operator=( const Character& obj) {
	if (this != &obj) {
		for (int i = 0; i < 4; i++) {
			if (arr[i]) {
				delete arr[i];
			}
			arr[i] = obj.arr[i];
		}
	}
	return (*this);
}

std::string const & Character::getName() const {
	return (this->_name);
}

void Character::equip(AMateria* m) {
	for (int i = 0; i < 4; i++) {
		if (this->arr[i] == NULL) {
			this->arr[i] = m;
			break;
		}
	}
}

void Character::unequip(int idx) {
	for (int i = 0; i < 4; i++) {
		if (this->gc[i] == NULL) {

		}
	}
}

Character::~Character() {
	std::cout << "Deconstructor Called" << std::endl;
}
