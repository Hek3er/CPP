#pragma once

# include <iostream>

class Dog {

public:

	Dog();
	Dog( Dog& obj );
	Dog& operator=( const Dog& obj );
	~Dog();

private:

};