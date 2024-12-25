#pragma once

# include <iostream>
# include "AForm.hpp"

class RobotomyRequestForm : public AForm {

public:

	RobotomyRequestForm();
	RobotomyRequestForm( RobotomyRequestForm& obj );
	RobotomyRequestForm& operator=( const RobotomyRequestForm& obj );
	~RobotomyRequestForm();

private:

};