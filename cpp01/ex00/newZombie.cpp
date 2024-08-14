#include "Zombie.hpp"

Zombie* newZombie( std::string name ) {
	Zombie	*ptr;
	
	try {
		ptr = new Zombie(name);
	} catch(std::bad_alloc& e) {
		std::cerr << "New Failed with " << e.what() << std::endl;
		return (NULL);
	}
	return (ptr);
}