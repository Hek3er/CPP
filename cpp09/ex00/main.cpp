#include "BitcoinExchange.hpp"

int main( int ac, char **av ) {
	if (ac != 2) {
		std::cout << "Input DB is required" << std::endl;
		return 1;
	}
	
	BitcoinExchange btc( (std::string(av[1])) );

	try {
		btc.run();
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	return (0);
}
