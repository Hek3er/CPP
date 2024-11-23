#pragma once

# include <iostream>
# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {

public:

	MateriaSource();
	MateriaSource( const MateriaSource& obj );
	MateriaSource& operator=( const MateriaSource& obj );
	void learnMateria(AMateria*);
	AMateria* createMateria(std::string const & type);
	~MateriaSource();

private:
	AMateria *arr[4];
};