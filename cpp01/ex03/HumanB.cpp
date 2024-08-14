#include "HumanB.hpp"

HumanB::HumanB(std::string str) {
	name = str;
	w = NULL;
}

HumanB::~HumanB() {}

void HumanB::attack() {
	if (w == NULL) {
		std::cerr << "Weapon is not set" << std::endl;
		return ;
	}
	std::cout << name << " attacks with their " << w->getType() << std::endl;
}

void	HumanB::setWeapon(Weapon &weapon) {
	w = &weapon;
}