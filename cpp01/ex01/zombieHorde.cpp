#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name ) {
	
	if (N < 0) {
		std::cerr << "You can't allocate Negative Values" << std::endl;
		exit(1);
	}

	Zombie* ptr = new Zombie[N];
	
	if (!ptr) {
		std::cerr << "New Failed" << std::endl;
		exit(1);
	
	}
	for (int i = 0; i < N ; i++) {
		ptr[i].SetName(name);
	
	}
	return (ptr);
}