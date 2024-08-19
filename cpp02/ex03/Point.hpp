#pragma once

#include "Fixed.hpp"

class Point {
public:
	Point( void );
	~Point( void );
	Point( const float a, const float b );
	Point( const Point& pt );
	Point& operator=(const Point& pt);
	const Fixed	GetX( void ) const;
	const Fixed	GetY( void ) const;

private:
	const Fixed _x;
	const Fixed _y;
};

bool bsp( Point const a, Point const b, Point const c, Point const point);
std::ostream& operator<<(std::ostream& o, const Point& pt);