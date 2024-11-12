#pragma once

# include <iostream>
# include "Brain.hpp"

class Animal {

public:

	Animal();
	Animal( Animal& obj );
	Animal& operator=( const Animal& obj );
	virtual void	makeSound( void ) const = 0;
	std::string	getType( void ) const;
	virtual ~Animal();

protected:
	std::string	type;
};