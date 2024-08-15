#include "Fixed.hpp"

int main() {
	Fixed const f(3.1f);
	Fixed const g(2.1f);
	Fixed const b( Fixed( 5.0547f ) * Fixed( 2 ) );

	// bool flag = g < f;

	std::cout << b << std::endl;
}