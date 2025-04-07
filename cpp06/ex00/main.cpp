#include "ScalarConverter.hpp"

int main( int ac, char **av ) {
	if (ac != 2) {
		std::cout << "Usage:\n\t./convert <arg>" << std::endl;
		return 1;
	}
	
	// std::string in[] = {"12", "12f", "0", "100", "c", "p", "21.", "32.f", "3.14f", "3.14", "crazy", "+inf", "-inf", "nan", "nanf", "nand", "+inff", "-inff", " ", " +inf"};

	// std::cout << "\n-----------tests------------\n";

	// for (size_t i = 0; i < (sizeof(in) / sizeof(in[0])); i++) {
	// 	std::cout << "TEST : \033[31;1;4m'" << in[i] << "'\033[0m" << std::endl;
	// 	ScalarConverter::convert(in[i]);
	// 	std::cout << "\n---------------------------\n";
	// }
	// std::cout << "\n\n" ;


	ScalarConverter::convert(av[1]);
	return (0);
}
