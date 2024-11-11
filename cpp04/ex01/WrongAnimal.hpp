#pragma once

# include <iostream>

class WrongAnimal {

public:

	WrongAnimal();
	WrongAnimal( WrongAnimal& obj );
	WrongAnimal& operator=( const WrongAnimal& obj );
	void	makeSound( void ) const;
	std::string	getType( void ) const;
	~WrongAnimal();

protected:
	std::string	type;
};