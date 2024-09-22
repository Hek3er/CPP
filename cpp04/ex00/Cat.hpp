#pragma once

# include <iostream>

class Cat {

public:

	Cat();
	Cat( Cat& obj );
	Cat& operator=( const Cat& obj );
	~Cat();

private:

};