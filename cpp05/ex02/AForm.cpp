#include "AForm.hpp"

AForm::AForm() : _name("default AForm"), _signed(false), _required_grade_sign(1), _required_grade_execute(50) {

}

AForm::AForm( const std::string name, const short signGrade ) : _name(name), _required_grade_sign(signGrade), _required_grade_execute(1) {
	if (signGrade > 150) {
		throw AForm::GradeTooLowException();
	}
	if (signGrade < 1) {
		throw AForm::GradeTooHighException();
	}
}

AForm::AForm( const AForm& obj ) : _name(obj._name), _signed(obj._signed), _required_grade_sign(obj._required_grade_sign), _required_grade_execute(obj._required_grade_execute) {

}

AForm& AForm::operator=( const AForm& obj) {
	if (this != &obj) {
		this->_signed = obj._signed;
	}
	return (*this);
}

bool AForm::getSigned( void ) const {
	return this->_signed;
}

const std::string AForm::getName( void ) const {
	return this->_name;
}

short AForm::getSignGrade( void ) const {
	return this->_required_grade_sign;
}

short AForm::getSignExecute( void ) const {
	return this->_required_grade_execute;
}

const char * AForm::GradeTooHighException::what() const throw() {
	return ("Grade is too high");
}

const char * AForm::GradeTooLowException::what() const throw() {
	return ("Grade is too low");
}

void	AForm::beSigned( const Bureaucrat& obj) {
	if (obj.getGrade() <= this->_required_grade_sign) {
		this->_signed = true;
		return ;
	}
	throw AForm::GradeTooLowException();
}

std::ostream& operator<<( std::ostream& o, const AForm& AForm ) {
	o << "AForm " << AForm.getName() << " requires " << AForm.getSignGrade() << " grades to sign and " << AForm.getSignExecute() << " grades to excecute it, right now it's signed value is " << AForm.getSigned() ;
	return o;
}

AForm::~AForm() {
}

