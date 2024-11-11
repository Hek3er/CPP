#pragma once

# include <iostream>

class Brain {

public:

	Brain();
	Brain( Brain& obj );
	Brain& operator=( const Brain& obj );
	~Brain();

private:
	std::string ideas[100];
};