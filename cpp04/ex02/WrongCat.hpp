#pragma once

# include <iostream>
# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {

public:

	WrongCat();
	WrongCat( WrongCat& obj );
	WrongCat& operator=( const WrongCat& obj );
	void	makeSound( void ) const;
	~WrongCat();

};