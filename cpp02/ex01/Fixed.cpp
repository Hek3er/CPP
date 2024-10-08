#include "Fixed.hpp"

#include <cmath>

Fixed::Fixed( void ) : _FixedVal(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( const int val ) {
	std::cout << "Int constructor called" << std::endl;
	this->_FixedVal = (val << this->_FractionVal);
}

Fixed::Fixed( const float val ) {
	std::cout << "Float constructor called" << std::endl;
	this->_FixedVal = static_cast<int>(roundf(val * 256.0f));
}

Fixed::Fixed( const Fixed& fix ) {
	std::cout << "Copy constructor called" << std::endl;
	*this = fix;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& fix) {
	std::cout << "Copy assignment operator called" << std::endl;
	this->_FixedVal = fix.getRawBits();
	return (*this);
}

std::ostream& operator<<(std::ostream& o,const Fixed& fix) {
	o << fix.toFloat();
	return (o);
}

int	Fixed::getRawBits( void ) const {
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_FixedVal);
}

void	Fixed::setRawBits( int const raw) {
	std::cout << "setRawBits member function called" << std::endl;
	this->_FixedVal = raw;
}

float Fixed::toFloat( void ) const {
	float	int_part = this->_FixedVal >> this->_FractionVal;
	float	frac_fix_part = this->_FixedVal & ((1 << this->_FractionVal) - 1);
	float	frac_part = frac_fix_part / (256.0f);
	return (int_part + frac_part);
}

int Fixed::toInt( void ) const {
	return (this->_FixedVal >> this->_FractionVal);
}