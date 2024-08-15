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
	~Fixed();

private:
	int	_FixedVal;
	static const int	_FractionVal = 8;
};

std::ostream& operator<<(std::ostream& o, const Fixed& fix);

#endif