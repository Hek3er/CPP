#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed {

public:
	Fixed( void );
	Fixed( const Fixed& fix );
	int getRawBits( void ) const;
	void setRawBits( int const raw );
	Fixed& operator=(const Fixed& fix);
	~Fixed();

private:
	int	_FixedVal;
	static const int	_FractionVal = 8;
};

#endif