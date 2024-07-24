#include "Zombie.hpp"

int main()
{
	int x = -1;
	Zombie* ptr = zombieHorde(x, "aymen");
	for (int i = 0; i < x; i++) {
		ptr[i].announce();
	}
	delete[] ptr;
}