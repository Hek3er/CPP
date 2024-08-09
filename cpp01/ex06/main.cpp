#include "Harl.hpp"


int main(int ac, char **av){
	if (ac != 2) {
		std::cerr << "[ Probably complaining about insignificant problems ]" << std::endl;
		return (0);
	}
	
	Harl h;

	h.complain(av[1]);
}