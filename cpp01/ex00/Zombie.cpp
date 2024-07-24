#include "Zombie.hpp"

Zombie::Zombie(std::string str) {
	name = str;
}

void Zombie::announce( void ) {
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::~Zombie() {
	std::cout << name << " is destructed" << std::endl;
}