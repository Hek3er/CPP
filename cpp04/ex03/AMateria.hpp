#pragma once

# include <iostream>
# include "Character.hpp"

class AMateria {

public:

	AMateria();
	AMateria( std::string const &type );
	AMateria( AMateria& obj );
	AMateria& operator=( const AMateria& obj );
	std::string	const 	&getType() const;
	virtual AMateria* 	clone() const = 0;
	virtual	void		use(ICharacter& target); 
	~AMateria();

protected:
	std::string	_Type;
};