#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
	// std::cout << "Default Constructor Called" << std::endl;
	for (int i = 0; i < 4; i++) {
		this->arr[i] = NULL;
	}
}

MateriaSource::MateriaSource( const MateriaSource& obj ) {
	// std::cout << "Copy Constructor Called" << std::endl;
	// for (int i = 0 ; i < 4; i++) {
	// 	this->arr[i] = NULL;
	// }
	*this = obj;
}

MateriaSource& MateriaSource::operator=( const MateriaSource& obj) {
	if (this != &obj) {
		for (int i = 0; i < 4; i++) {
			if (this->arr[i]) {
				delete this->arr[i];
				this->arr[i] = obj.arr[i]->clone();
			}
		}
	}
	return (*this);
}

void MateriaSource::learnMateria(AMateria* m) {
	if (!m) return;
	for (int i = 0; i < 4; i++) {
		if (this->arr[i] == NULL) {
			this->arr[i] = m;
			break;
		}
	}
}

AMateria*	MateriaSource::createMateria(std::string const& type) {
	for (int i = 0; i < 4; i++) {
		if (this->arr[i] && this->arr[i]->getType() == type) {
			return (this->arr[i]->clone());
		}
	}
	return 0;
}

MateriaSource::~MateriaSource() {
	// std::cout << "Deconstructor Called" << std::endl;
	for (int i = 0; i < 4; i++) {
		if (this->arr[i]) {
			delete this->arr[i];
			this->arr[i] = NULL;
		}
	}
}

