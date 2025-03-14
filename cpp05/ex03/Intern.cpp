#include "Intern.hpp"

Intern::Intern() {

}

Intern::Intern( const Intern& obj ) {
	(void)obj;
	*this = obj;
}

Intern& Intern::operator=( const Intern& obj) {
	(void)obj;
	return (*this);
}

AForm* Intern::makeForm( const std::string name, const std::string target ) {
	int id = (name == "robotomy request") * 1 + (name == "shrubery request") * 2 + (name == "presedential pardon request") * 3;

	switch (id)
	{
	case 1:
		return new RobotomyRequestForm(target);
		break;
	case 2:
		return new ShrubberyCreationForm(target);
		break;
	case 3:
		return new PresidentialPardonForm(target);
		break;
	}
	std::cerr << "invalid form name" << std::endl;
	return NULL;
}

Intern::~Intern() {

}

