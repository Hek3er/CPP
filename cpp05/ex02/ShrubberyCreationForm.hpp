#pragma once

# include <iostream>
# include "AForm.hpp"

class ShrubberyCreationForm : public AForm {

public:

	ShrubberyCreationForm();
	ShrubberyCreationForm( ShrubberyCreationForm& obj );
	ShrubberyCreationForm& operator=( const ShrubberyCreationForm& obj );
	~ShrubberyCreationForm();

private:

};