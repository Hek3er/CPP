#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("anon"), _grade(1) {
}

Bureaucrat::Bureaucrat( const std::string name, const short grade ) : _name(name), _grade(grade) {
	if (grade < 1) {
		throw Bureaucrat::GradeTooHighException();
		return ;
	}
	if (grade > 150) {
		throw Bureaucrat::GradeTooLowException();
		return ;
	}
}

Bureaucrat::Bureaucrat( Bureaucrat& obj ) {
	*this = obj;
}

Bureaucrat& Bureaucrat::operator=( const Bureaucrat& obj) {
	if (this != &obj) {
		this->_grade = obj._grade;
	}
	return (*this);
}

const std::string& Bureaucrat::getName( void ) const {
	return (this->_name);
}

short Bureaucrat::getGrade( void ) const {
	return (this->_grade);
}

void	Bureaucrat::bump( void ) {
	if (this->_grade == 1) {
		throw Bureaucrat::GradeTooHighException();
		return ;
	}
	this->_grade--;
}

void	Bureaucrat::dump( void ) {
	if (this->_grade == 150) {
		throw Bureaucrat::GradeTooLowException();
		return ;
	}
	this->_grade++;
}

std::ostream& operator<<(std::ostream& o, const Bureaucrat& obj) {
	o << obj.getName() << ", " << "bureaucrat grade " << obj.getGrade() << ".";
	return o;
}

const char * Bureaucrat::GradeTooHighException::what() const throw() {
	return ("Grade is too high");
}

const char * Bureaucrat::GradeTooLowException::what() const throw() {
	return ("Grade is too Low");
}

Bureaucrat::~Bureaucrat() {
}

