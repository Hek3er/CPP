#pragma once

# include <iostream>
# include "AForm.hpp"

class PresidentialPardonForm : public AForm {

public:

	PresidentialPardonForm();
	PresidentialPardonForm( std::string target );
	PresidentialPardonForm( PresidentialPardonForm& obj );
	void execute(Bureaucrat const & executor) const;
	PresidentialPardonForm& operator=( const PresidentialPardonForm& obj );
	~PresidentialPardonForm();

private:
	std::string _target;
};