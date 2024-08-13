#include "Fixed.hpp"

Fixed::Fixed( void ) : _FixedVal(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( const Fixed& fix ) {
	std::cout << "Copy constructor called" << std::endl;
	*this = fix;
}

Fixed& Fixed::operator=(const Fixed& fix) {
	std::cout << "Copy assignment operator called" << std::endl;
	this->_FixedVal = fix.getRawBits();
	return (*this);
}

int	Fixed::getRawBits( void ) const {
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_FixedVal);
}

void	Fixed::setRawBits( int const raw) {
	std::cout << "setRawBits member function called" << std::endl;
	this->_FixedVal = raw;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}