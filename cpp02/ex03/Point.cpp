#include "Point.hpp"

Point::Point(): _x(0), _y(0) {

}

Point::~Point() {

}

Point::Point( const float a, const float b ): _x(Fixed(a)), _y(Fixed(b)) {

}

Point::Point( const Point& pt ) : _x(Fixed((pt.GetX()).toFloat())), _y(Fixed((pt.GetY()).toFloat())) {

}

Point& Point::operator=(const Point& pt) {
	static_cast<Fixed>(_x) = pt.GetX();
	static_cast<Fixed>(_y) = pt.GetX();
	return (*this);
}

const Fixed	Point::GetX( void ) const {
	return (_x);
}

const Fixed	Point::GetY( void ) const {
	return (_y);
}

std::ostream& operator<<(std::ostream& o, const Point& pt) {
	o << "( " << pt.GetX() << ", " << pt.GetY() << " )";
	return (o);
}