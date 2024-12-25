#pragma once

# include <iostream>
# include "AForm.hpp"

class PresidentialPardonForm : public AForm {

public:

	PresidentialPardonForm();
	PresidentialPardonForm( PresidentialPardonForm& obj );
	PresidentialPardonForm& operator=( const PresidentialPardonForm& obj );
	~PresidentialPardonForm();

private:

};