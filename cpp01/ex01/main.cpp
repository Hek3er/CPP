#include "Zombie.hpp"

int main()
{
	Zombie* ptr = zombieHorde(10, "aymen");
	for (int i = 0; i < 10; i++) {
		ptr[i].announce();
	}
	delete[] ptr;
}