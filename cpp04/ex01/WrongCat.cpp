#include "WrongCat.hpp"

WrongCat::WrongCat() {
	std::cout << "WrongCat Default Constructor Called" << std::endl;
	this->type = "WrongCat";
}

WrongCat::WrongCat( WrongCat& obj ) {
	std::cout << "WrongCat Copy Constructor Called" << std::endl;

	*this = obj;
}

WrongCat& WrongCat::operator=( const WrongCat& obj) {
	this->type = obj.type;
	return (*this);
}

WrongCat::~WrongCat() {
	std::cout << "WrongCat Deconstructor Called" << std::endl;
}

void	WrongCat::makeSound( void ) const {
	std::cout << "** Wrong MEAW **" << std::endl;
}

