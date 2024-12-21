#include "Bureaucrat.hpp"

int main() {

	Bureaucrat	b1;

	std::cout << b1 << std::endl;

	Bureaucrat	b2("aymen", 12);

	std::cout << b2 << std::endl;
	std::cout << "name : " << b2.getName() << " grade : " << b2.getGrade() <<std::endl;
	
	std::cout << "----------------------------" << std::endl;
	
	try {
		Bureaucrat b3("aymen", -1);
	}
	catch (std::exception& e) {
		std::cout << "Exception : " << e.what() << std::endl;
	}

	std::cout << "----------------------------" << std::endl;

	try {
		Bureaucrat b3("aymen", 151);
	}
	catch (std::exception& e) {
		std::cout << "Exception : " << e.what() << std::endl;
	}

	std::cout << "----------------------------" << std::endl;

	try {
		Bureaucrat b3("aymen", 1);
		b3.bump();
	}
	catch (std::exception& e) {
		std::cout << "Exception : " << e.what() << std::endl;
	}

	std::cout << "----------------------------" << std::endl;

	try {
		Bureaucrat b3("aymen", 2);
		b3.bump();
		std::cout << b3 << std::endl;
		b3.dump();
		std::cout << b3 << std::endl;
	}
	catch (std::exception& e) {
		std::cout << "Exception : " << e.what() << std::endl;
	}

	return (0);
}
