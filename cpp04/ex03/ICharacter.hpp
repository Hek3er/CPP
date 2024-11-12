#pragma once

# include <iostream>

class ICharacter {

public:

	ICharacter();
	ICharacter( ICharacter& obj );
	ICharacter& operator=( const ICharacter& obj );
	~ICharacter();

private:

};