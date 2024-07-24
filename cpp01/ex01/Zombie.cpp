#include "Zombie.hpp"

Zombie::Zombie() {}

void Zombie::SetName(std::string str) {
	name = str;
}

void Zombie::announce( void ) {
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::~Zombie() {
	std::cout << name << " is dead" << std::endl;
}