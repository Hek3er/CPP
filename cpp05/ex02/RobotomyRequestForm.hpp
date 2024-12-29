#pragma once

# include <iostream>
# include "AForm.hpp"

class RobotomyRequestForm : public AForm {

public:

	RobotomyRequestForm();
	RobotomyRequestForm( std::string target );
	RobotomyRequestForm( RobotomyRequestForm& obj );
	void execute(Bureaucrat const & executor) const;
	RobotomyRequestForm& operator=( const RobotomyRequestForm& obj );
	~RobotomyRequestForm();

private:
	std::string _target;
};