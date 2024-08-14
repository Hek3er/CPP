#include "HumanA.hpp"

HumanA::HumanA(std::string str, Weapon& weapon) : w(weapon), name(str) {
}

HumanA::~HumanA() {}

void HumanA::attack() {
	std::cout << name << " attacks with their " << w.getType() << std::endl;
}