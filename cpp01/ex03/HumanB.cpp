#include "HumanB.hpp"

HumanB::HumanB() {}

HumanB::~HumanB() {}

void HumanB::attack() {
	std::cout << name << " attacks with their " << w.getType() << std::endl;
}