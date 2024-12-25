#pragma once

# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {

public:

	AForm();
	AForm( const std::string name, const short signGrade );
	AForm( const Form& obj );
	AForm& operator=( const AForm& obj );

	bool getSigned( void ) const;
	const std::string getName( void ) const;
	short getSignGrade( void ) const;
	short getSignExecute( void ) const;

	void	beSigned( const Bureaucrat& obj );

	virtual void execute(Bureaucrat const & executor) const = 0;

	class GradeTooHighException : public std::exception {
	public:
		const char *what() const throw();
	};

	class GradeTooLowException : public std::exception {
	public:
		const char *what() const throw();
	};

	~AForm();

private:
	const std::string _name;
	bool		_signed;
	const short	_required_grade_sign;
	const short _required_grade_execute;
};

std::ostream& operator<<(std::ostream& o, const AForm& form);