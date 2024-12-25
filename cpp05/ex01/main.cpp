#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {

	Bureaucrat b("Aymen", 25);
	// fail
	try {
		Form form("constitution", -1);
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	try {
		Form form("constitution", 255);
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	try {
		Form form("constitution", 1);
		b.signForm(form);
	} catch(std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	// 
	try {
		Form form("constitution", 25);
		b.signForm(form);
		std::cout << form << std::endl;
	} catch(std::exception& e) {
		std::cout << e.what() << std::endl;
	}


	return (0);
}
