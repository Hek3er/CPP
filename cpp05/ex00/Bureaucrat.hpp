#pragma once

# include <iostream>

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