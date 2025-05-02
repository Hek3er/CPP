#include "RPN.hpp"

int main( int ac, char **av ) {
	if (ac < 2) {
		std::cout << "Error: No input" << std::endl;
		return 1;
	}

	RPN rpn(av);

	rpn.Run();

	return (0);
}
