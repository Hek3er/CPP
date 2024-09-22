#pragma once

# include <iostream>

class Animal {

public:

	Animal();
	Animal( Animal& obj );
	Animal& operator=( const Animal& obj );
	~Animal();

private:

};