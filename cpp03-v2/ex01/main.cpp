#include "ScavTrap.hpp"

int main() {

	ScavTrap	bot("aymen");
	ScavTrap	copy(bot);
	
	//[no energy points]

	// bot.beRepaired(1); // bot is max health
	// bot.attack("Bob1");
	// bot.attack("Bob2");
	// bot.attack("Bob3");
	// bot.attack("Bob4");
	// bot.attack("Bob5");
	// bot.attack("Bob6");
	// bot.attack("Bob7");
	// bot.attack("Bob8");
	// bot.attack("Bob9");
	// bot.attack("Bob10");
	// bot.attack("Bob11"); // no energy points
	// ClapTrap	t;
	// t = bot;
	// t.attack("from t");

	// [bot dies]
	
	// bot.takeDamage(120);
	// bot.beRepaired(10);

	bot.takeDamage(9);
	bot.beRepaired(4);
	bot.attack("smoke");
	bot.guardGate();


	return (0);
}
