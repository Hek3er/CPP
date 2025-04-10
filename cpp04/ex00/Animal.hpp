#pragma once

# include <iostream>

class Animal {

public:

	Animal();
	Animal( Animal& obj );
	Animal& operator=( const Animal& obj );
	virtual void	makeSound( void ) const;
	std::string	getType( void ) const;
	virtual ~Animal();

protected:
	std::string	type;
};