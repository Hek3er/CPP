#include "Fixed.hpp"

int main( void ) {
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;

	std::cout << std::endl << "Arithmeric operators" << std::endl;
	Fixed	x(1.0f);
	Fixed	y(3.5f);

	std::cout << x << " + " << y << " " << x + y << std::endl;
	std::cout << x << " - " << y << " " << x - y << std::endl;
	std::cout << x << " * " << y << " " << x * y << std::endl;
	std::cout << x << " / " << y << " " << x / y << std::endl << std::endl;

	std::cout << "Comparison operators" << std::endl;
	std::cout << "is " << x << " < " << y << " => " << (x < y) << std::endl;
	std::cout << "is " << x << " <= " << y << " => " << (x <= y) << std::endl;
	std::cout << "is " << x << " > " << y << " => " << (x > y) << std::endl;
	std::cout << "is " << x << " >= " << y << " => " << (x >= y) << std::endl;
	std::cout << "is " << x << " == " << y << " => " << (x == y) << std::endl;
	std::cout << "is " << x << " != " << y << " => " << (x != y) << std::endl;
return 0;
}