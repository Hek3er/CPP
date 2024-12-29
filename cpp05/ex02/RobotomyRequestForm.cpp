#include "RobotomyRequestForm.hpp"
#include <ctime>
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), _target("default") {

}

RobotomyRequestForm::RobotomyRequestForm( std::string target ) : AForm("RobotomyRequestForm", 72, 45), _target(target) {

}

RobotomyRequestForm::RobotomyRequestForm( RobotomyRequestForm& obj ) : AForm(obj.getName(), 72, 45), _target(obj._target) {

}

RobotomyRequestForm& RobotomyRequestForm::operator=( const RobotomyRequestForm& obj) {
	this->_target = obj._target;
	return (*this);
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const {
	if (executor.getGrade() > this->getSignGrade() || executor.getGrade() > this->getSignExecute()) {
		throw AForm::GradeTooLowException();
	}

	std::cout << "** Drilling Noise **" << std::endl;

	std::srand(std::time(NULL));
	int r = std::rand();
	if (r % 2 == 0) {
		std::cout << this->getName() << ": " << this->_target <<" has been rotomized successfully" << std::endl;
	} else {
		std::cerr << this->getName() << ": " << this->_target <<" has not been rotomized successfully" << std::endl;
	}
}

RobotomyRequestForm::~RobotomyRequestForm() {
}

