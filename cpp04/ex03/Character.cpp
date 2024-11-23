#include "Character.hpp"

Character::Character() {
	// std::cout << "Default Constructor Called" << std::endl;
	for (int i = 0; i < 4; i++) {
		arr[i] = NULL;
		gc[i] = NULL;
	}
	_name = "default name";
}

Character::Character( std::string name ) {
	// std::cout << "Default Constructor Called" << std::endl;
	for (int i = 0; i < 4; i++) {
		arr[i] = NULL;
		gc[i] = NULL;
	}
	_name = name;
}

Character::Character( Character& obj ) {
	// std::cout << "Copy Constructor Called" << std::endl;
	*this = obj;
}

Character& Character::operator=( const Character& obj) {
	if (this != &obj) {
		this->_name = obj._name;
		for (int i = 0; i < 4; i++) {
			if (this->arr[i]) {
				delete this->arr[i];
			}
			this->arr[i] = obj.arr[i]->clone();
		}
	}
	return (*this);
}

std::string const & Character::getName() const {
	return (this->_name);
}

void Character::equip(AMateria* m) {
	if (!m){
		std::cout << "NULL" << std::endl;
		return ;
	}
	for (int i = 0; i < 4; i++) {
		if (this->arr[i] == NULL) {
			this->arr[i] = m;
			return ;
		}
	}
	std::cerr << "Can't equip inventory full" << std::endl;
}

void Character::unequip(int idx) {
	if (idx >= 4 || idx < 0) {
		std::cerr << "Idx is incorrect" << std::endl;
		return ;
	}
	for (int i = 0; i < 4; i++) {
		if (this->gc[i] == NULL) {
			this->gc[i] = this->arr[idx]; 
			this->arr[idx] = NULL;
		}
	}
}

void Character::use(int idx, ICharacter& target) {
	if (idx >= 0 && idx < 4) {
		if (this->arr[idx]) {
			this->arr[idx]->use(target);
			delete this->arr[idx];
			this->arr[idx] = NULL;
		}
	}
}

Character::~Character() {
	// std::cout << "Deconstructor Called" << std::endl;
	for (int i = 0; i < 4; i++) {
		if (this->arr[i]) {
			delete this->arr[i];
			this->arr[i] = NULL;
		}
		if (this->gc[i]) {
			delete this->gc[i];
			this->gc[i] = NULL;
		}
	}
}
