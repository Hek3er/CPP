#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5), _target("default") {

}

PresidentialPardonForm::PresidentialPardonForm( std::string target ) : AForm("PresidentialPardonForm", 25, 5), _target(target) {}

PresidentialPardonForm::PresidentialPardonForm( PresidentialPardonForm& obj ) : AForm(obj.getName(), 25, 5), _target(obj._target) {

}

PresidentialPardonForm& PresidentialPardonForm::operator=( const PresidentialPardonForm& obj) {
	if (this != &obj) {
		this->_target = obj._target;
	}
	return (*this);
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const {
	if ( !this->getSigned() || executor.getGrade() > this->getSignGrade() || executor.getGrade() > this->getSignExecute()) {
		throw AForm::GradeTooLowException();
	}
	std::cout << this->getName() << ": " << this->_target << " has been pardoned by Zaphod Beeblerox" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm() {
}

