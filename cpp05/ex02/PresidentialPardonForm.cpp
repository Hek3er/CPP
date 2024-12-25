#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() {
	std::cout << "Default Constructor Called" << std::endl;

}

PresidentialPardonForm::PresidentialPardonForm( PresidentialPardonForm& obj ) {
	std::cout << "Copy Constructor Called" << std::endl;

	*this = obj;
}

PresidentialPardonForm& PresidentialPardonForm::operator=( const PresidentialPardonForm& obj) {

	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm() {
	std::cout << "Deconstructor Called" << std::endl;
}

