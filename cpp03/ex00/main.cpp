#include "ClapTrap.hpp"

int main() {
	ClapTrap	clap("aymen");

	clap.attack("zainabi");
	clap.takeDamage(-5);
	clap.beRepaired(1);
	clap.takeDamage(4);
	clap.beRepaired(5);
}