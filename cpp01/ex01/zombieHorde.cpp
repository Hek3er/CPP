#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name ) {
	
	if (N < 0) {
		std::cerr << "You can't allocate Negative Values" << std::endl;
		return (NULL);
	}

	Zombie* ptr;

	try {
		ptr = new Zombie[N];
	} catch (std::bad_alloc& e) {
		std::cerr << "New Failed with " << e.what() << std::endl;
		return (NULL);
	}
	

	for (int i = 0; i < N ; i++) {
		ptr[i].SetName(name);
	}
	return (ptr);
}