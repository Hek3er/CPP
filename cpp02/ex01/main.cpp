#include "Fixed.hpp"

int main() {
	Fixed const f(3.5f);

	std::cout << f << std::endl;
	// std::cout << f.getRawBits() << " |---> " << f.toFloat() << " --- " << f.toInt() << std::endl;
}