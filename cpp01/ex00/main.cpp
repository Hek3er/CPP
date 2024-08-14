#include "Zombie.hpp"

void f() {
	system("leaks zombie");
}

int main()
{
	atexit(f);

	Zombie* zombieptr = newZombie("1337");
	if (zombieptr == NULL) {
		return (1);
	}
	zombieptr->announce();
	delete zombieptr;
	randomChump("aymen");
}