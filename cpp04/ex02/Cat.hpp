#pragma once

# include <iostream>
# include "Animal.hpp"

class Cat : public Animal {

public:

	Cat();
	Cat( Cat& obj );
	Cat& operator=( const Cat& obj );
	void	makeSound( void ) const;
	~Cat();

private:
	Brain	*brain;
};