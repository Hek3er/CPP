#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() {
	std::cout << "Default Constructor Called" << std::endl;

}

ShrubberyCreationForm::ShrubberyCreationForm( ShrubberyCreationForm& obj ) {
	std::cout << "Copy Constructor Called" << std::endl;

	*this = obj;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=( const ShrubberyCreationForm& obj) {

	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	std::cout << "Deconstructor Called" << std::endl;
}

