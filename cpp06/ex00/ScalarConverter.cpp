#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {
	std::cout << "Default Constructor Called" << std::endl;

}

ScalarConverter::ScalarConverter( const ScalarConverter& obj ) {
	std::cout << "Copy Constructor Called" << std::endl;
	if (this != &obj)
		*this = obj;
}

ScalarConverter& ScalarConverter::operator=( const ScalarConverter& obj) {

	return (*this);
}


void ScalarConverter::convert( const std::string& msg ) {
	
}


ScalarConverter::~ScalarConverter() {
	std::cout << "Deconstructor Called" << std::endl;
}

