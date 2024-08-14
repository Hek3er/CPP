#include "Zombie.hpp"

int main()
{
	int x = 4;
	Zombie* ptr = zombieHorde(x, "aymen");
	if (ptr == NULL) {
		return (1);
	}
	for (int i = 0; i < x; i++) {
		ptr[i].announce();
	}
	delete[] ptr;
	// int *ptr;
	// try {
	// 	ptr = new int[7979797999447979];
	// }
	// catch (std::bad_alloc& e) {
	// 	std::cout << "failed with " << e.what() << std::endl;
	// }
	// std::cout << "***** Hello ****" << std::endl;
}