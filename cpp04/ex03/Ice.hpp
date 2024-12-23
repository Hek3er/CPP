#pragma once

# include <iostream>
# include "AMateria.hpp"

class Ice : public AMateria {

public:

	Ice();
	Ice( const Ice& obj );
	Ice& operator=( const Ice& obj );
	AMateria* 	clone() const;
	void		use(ICharacter& target);
	~Ice();

};