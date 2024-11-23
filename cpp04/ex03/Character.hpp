#pragma once

# include <iostream>
# include "ICharacter.hpp"

class Character : public ICharacter {

public:

	Character();
	Character( std::string name );
	Character( Character& obj );
	Character& operator=( const Character& obj );
	std::string const & getName() const;
	void equip(AMateria* m);
	void unequip(int idx);
	void use(int idx, ICharacter& target);
	~Character();

private:
	AMateria* arr[4];
	AMateria* gc[4];
	std::string _name;
};