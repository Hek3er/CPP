#include "Form.hpp"

Form::Form() : _name("default form"), _signed(false), _required_grade_execute(1), _required_grade_sign(50) {

}

Form::Form( const std::string name, const short signGrade ) : _name(name), _required_grade_sign(signGrade), _required_grade_execute(1) {
	if (signGrade > 150) {
		throw Form::GradeTooLowException();
	}
	if (signGrade < 1) {
		throw Form::GradeTooHighException();
	}
}

Form::Form( const Form& obj ) : _name(obj._name), _signed(obj._signed), _required_grade_execute(obj._required_grade_execute), _required_grade_sign(obj._required_grade_sign) {

}

Form& Form::operator=( const Form& obj) {
	if (this != &obj) {
		this->_signed = obj._signed;
	}
	return (*this);
}

bool Form::getSigned( void ) const {
	return this->_signed;
}

const std::string Form::getName( void ) const {
	return this->_name;
}

const short Form::getSignGrade( void ) const {
	return this->_required_grade_sign;
}

const short Form::getSignExecute( void ) const {
	return this->_required_grade_execute;
}

const char * Form::GradeTooHighException::what() const throw() {
	return ("Grade is too high");
}

const char * Form::GradeTooLowException::what() const throw() {
	return ("Grade is too low");
}

void	Form::beSigned( const Bureaucrat& obj) {
	if (obj.getGrade() <= this->_required_grade_sign) {
		this->_signed = true;
		return ;
	}
	throw Form::GradeTooLowException();
}

Form::~Form() {
}

