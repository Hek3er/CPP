#ifndef HUMAN_B_HPP
# define HUMAN_B_HPP

#include "Weapon.hpp"

class HumanB {
public:
	HumanB(std::string str);
	void	attack();
	void	setWeapon(Weapon &weapon);
	~HumanB();
private:
	Weapon		*w;
	std::string name;
};

#endif