#ifndef ZOMBIE_H
# define ZOMBIE_H

#include <iostream>

class Zombie {
public:
	Zombie();
	void	SetName(std::string str);
	void	announce( void );
	~Zombie();

private:
	std::string name;
};

Zombie* zombieHorde( int N, std::string name );

# endif