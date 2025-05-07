#include "PmergeMe.hpp"

int main( int ac, char **av ) {
	if (ac < 2) {
		std::cout << "Error: No input" << std::endl;
		return 1;
	}

	PmergeMe pmerge(av);

	pmerge.Run();

	return (0);
}
