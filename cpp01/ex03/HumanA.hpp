#ifndef HUMAN_A_H
# define HUMAN_A_H

#include "Weapon.hpp"

class HumanA {
public:
	// HumanA();
	HumanA(std::string str, Weapon& weapon);
	void	attack();
	~HumanA();
private:
	Weapon		*w;
	std::string name;
};

#endif