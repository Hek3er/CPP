#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed {

public:
	Fixed( void );
	Fixed( const int val );
	Fixed( const float val );
	Fixed( const Fixed& fix );
	int getRawBits( void ) const;
	void setRawBits( int const raw );
	float toFloat( void ) const;
	int toInt( void ) const;
	Fixed& operator=(const Fixed& fix);

	bool operator>(const Fixed& fix) const;
	bool operator<(const Fixed& fix) const;
	bool operator>=(const Fixed& fix) const;
	bool operator<=(const Fixed& fix) const;
	bool operator==(const Fixed& fix) const;
	bool operator!=(const Fixed& fix) const;
	Fixed operator+(const Fixed& fix) const;
	Fixed operator-(const Fixed& fix) const;
	Fixed operator*(const Fixed& fix) const;
	Fixed operator/(const Fixed& fix) const;
	Fixed operator++( void ) ;
	Fixed operator++( int ) ;
	Fixed operator--( void ) ;
	Fixed operator--( int ) ;
	static Fixed& max(Fixed& a, Fixed& b);
	static const Fixed& max(const Fixed& a, const Fixed& b);
	static Fixed& min(Fixed& a, Fixed& b);
	static const Fixed& min(const Fixed& a, const Fixed& b);

	~Fixed();

private:
	int	_FixedVal;
	static const int	_FractionVal = 8;
};

std::ostream& operator<<(std::ostream& o, const Fixed& fix);

#endif