#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() {
	std::cout << "Default Constructor Called" << std::endl;

}

RobotomyRequestForm::RobotomyRequestForm( RobotomyRequestForm& obj ) {
	std::cout << "Copy Constructor Called" << std::endl;

	*this = obj;
}

RobotomyRequestForm& RobotomyRequestForm::operator=( const RobotomyRequestForm& obj) {

	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm() {
	std::cout << "Deconstructor Called" << std::endl;
}

