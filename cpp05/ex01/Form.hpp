#pragma once

# include <iostream>
# include "Bureaucrat.hpp"

class Form {

public:

	Form();
	Form( const std::string name, const short signGrade );
	Form( const Form& obj );
	Form& operator=( const Form& obj );

	bool getSigned( void ) const;
	const std::string getName( void ) const;
	const short getSignGrade( void ) const;
	const short getSignExecute( void ) const;

	void	beSigned( const Bureaucrat& obj );

	class GradeTooHighException : public std::exception {
	public:
		const char *what() const throw();
	};

	class GradeTooLowException : public std::exception {
	public:
		const char *what() const throw();
	};

	~Form();

private:
	const std::string _name;
	bool	_signed;
	const short	_required_grade_sign;
	const short _required_grade_execute;
};

std::ostream& operator<<(std::ostream& o, const Form& form);