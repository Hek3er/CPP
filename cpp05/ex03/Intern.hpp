#pragma once

# include <iostream>
# include "AForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "ShrubberyCreationForm.hpp"

class Intern {

public:

	Intern();
	Intern( const Intern& obj );
	Intern& operator=( const Intern& obj );
	AForm* makeForm( const std::string name, const std::string target );
	~Intern();

private:

};