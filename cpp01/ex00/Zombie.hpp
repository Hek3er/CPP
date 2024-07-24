#ifndef ZOMBIE_H
# define ZOMBIE_H

#include <iostream>

class Zombie {
public:
	Zombie(std::string str);
	void announce( void );
	~Zombie();
private:
	std::string name;
};

Zombie* newZombie( std::string name );
void randomChump( std::string name );

#endif