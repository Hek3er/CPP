#pragma once

# include <iostream>
# include <vector>
# include <algorithm>
# include <limits.h>
class Span {

public:

	Span( const size_t size );
	Span( const Span& obj );
	Span& operator=( const Span& obj );
	void	addNumber( const int val );
	int		shortestSpan( void ) const;
	int		longestSpan( void ) const;
	~Span();

private:
	std::vector<int> _arr;
	size_t _size;
};