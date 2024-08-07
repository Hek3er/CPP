#include "HumanB.hpp"

HumanB::HumanB(std::string str) : name(str) {}

HumanB::~HumanB() {}

void HumanB::attack() {
	std::cout << name << " attacks with their " << w->getType() << std::endl;
}

void	HumanB::setWeapon(Weapon &weapon) {
	w = &weapon;
}