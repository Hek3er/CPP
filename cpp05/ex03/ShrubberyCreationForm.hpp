#pragma once

# include <iostream>
# include "AForm.hpp"

class ShrubberyCreationForm : public AForm {

public:

	ShrubberyCreationForm();
	ShrubberyCreationForm( std::string target );
	ShrubberyCreationForm( ShrubberyCreationForm& obj );
	void execute(Bureaucrat const & executor) const;
	ShrubberyCreationForm& operator=( const ShrubberyCreationForm& obj );
	~ShrubberyCreationForm();

private:
	std::string _target;
};