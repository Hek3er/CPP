#pragma once

# include <iostream>
# include "Animal.hpp"

class Dog : public Animal {

public:

	Dog();
	Dog( Dog& obj );
	Dog& operator=( const Dog& obj );
	~Dog();
	void	makeSound( void ) const;

private:
	Brain	*brain;

};