#pragma once

# include <iostream>
# include "Form.hpp"

class Form;

class Bureaucrat {

public:

	Bureaucrat();
	Bureaucrat( const std::string name, const short grade );
	Bureaucrat( Bureaucrat& obj );
	Bureaucrat& operator=( const Bureaucrat& obj );

	const std::string& getName( void ) const;
	short getGrade( void ) const;
	void	bump( void );
	void	dump( void );

	void	signForm( Form& obj );

	class GradeTooHighException : public std::exception {
	public:
		const char *what() const throw();
	};

	class GradeTooLowException : public std::exception {
	public:
		const char *what() const throw();
	};

	~Bureaucrat();

private:
	const std::string _name;
	short _grade;
};

std::ostream& operator<<(std::ostream& o, const Bureaucrat& obj);