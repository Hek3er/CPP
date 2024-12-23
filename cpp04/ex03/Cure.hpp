#pragma once

# include <iostream>
# include "AMateria.hpp"

class Cure : public AMateria {

public:

	Cure();
	Cure( const Cure& obj );
	Cure& 		operator=( const Cure& obj );
	AMateria* 	clone() const;
	void		use(ICharacter& target);
	~Cure();

};