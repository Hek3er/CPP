#ifndef HUMAN_B_HPP
# define HUMAN_B_HPP

#include "Weapon.hpp"

class HumanB {
public:
	HumanB();
	void	attack();
	~HumanB();
private:
	Weapon		w;
	std::string name;
};

#endif