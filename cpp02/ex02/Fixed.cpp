#include "Fixed.hpp"

#include <cmath> // remove

//	Int				 Fraction
// 	xxxxxxxxxxxxxxxx.xxxxxxxxxxxxxxxx
//  0000000000000011.1000000000000000

Fixed::Fixed( void ) : _FixedVal(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( const int val ) {
	std::cout << "Int constructor called" << std::endl;
	this->_FixedVal = (val << this->_FractionVal);
}

Fixed::Fixed( const float val ) {
	std::cout << "Float constructor called" << std::endl;
	this->_FixedVal = (int)(roundf(val * 256.0f));
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
	float	frac_part = frac_fix_part / (256);
	return (int_part + frac_part);
}

int Fixed::toInt( void ) const {
	return (this->_FixedVal >> this->_FractionVal);
}

bool Fixed::operator>(const Fixed& fix) const {
	if (this->toFloat() > fix.toFloat()) {
		return true;
	}
	return false;
}

bool Fixed::operator<(const Fixed& fix) const {
	if (this->toFloat() < fix.toFloat()) {
		return true;
	}
	return false;
}

bool Fixed::operator>=(const Fixed& fix) const {
	if (this->toFloat() >= fix.toFloat()) {
		return true;
	}
	return false;
}

bool Fixed::operator<=(const Fixed& fix) const {
	if (this->toFloat() <= fix.toFloat()) {
		return true;
	}
	return false;
}

bool Fixed::operator==(const Fixed& fix) const {
	if (this->toFloat() == fix.toFloat()) {
		return true;
	}
	return false;
}

bool Fixed::operator!=(const Fixed& fix) const {
	if (this->toFloat() == fix.toFloat()) {
		return true;
	}
	return false;
}

Fixed Fixed::operator+(const Fixed& fix) const {
	return (Fixed(this->toFloat() + fix.toFloat()));
}

Fixed Fixed::operator-(const Fixed& fix) const {
	return (Fixed(this->toFloat() - fix.toFloat()));
}

Fixed Fixed::operator*(const Fixed& fix) const {
	return (Fixed(this->toFloat() * fix.toFloat()));
}

Fixed Fixed::operator/(const Fixed& fix) const {
	return (Fixed(this->toFloat() / fix.toFloat()));
}

Fixed& Fixed::operator++( void )  {
	this->_FixedVal++;
	return (*this);
}

Fixed Fixed::operator++( int )  {
	Fixed fix(*this);
	this->_FixedVal++;
	return (fix);
}

Fixed& Fixed::operator--( void )  {
	this->_FixedVal--;
	return (*this);
}

Fixed Fixed::operator--( int )  {
	Fixed fix(*this);
	this->_FixedVal--;
	return (fix);
}

Fixed& Fixed::max(Fixed& a, Fixed& b) {
	return (a > b) ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
	return (a > b) ? a : b;
}
Fixed& Fixed::min(Fixed& a, Fixed& b) {
	return (a < b) ? a : b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
	return (a < b) ? a : b;
}

