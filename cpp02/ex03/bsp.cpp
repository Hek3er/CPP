#include "Point.hpp"

static Fixed abs(const Fixed& p) {
	if (p.toFloat() < 0)
		return (Fixed(p.toFloat() * -1));
	return (Fixed(p));
}

static Fixed area(Point const a, Point const b, Point const c) {
	Fixed _area = abs(((a.GetX() * b.GetY()) - (a.GetY() * b.GetX()) + 
						(b.GetX() * c.GetY()) - (b.GetY() * c.GetX()) +
						(c.GetX() * a.GetY()) - (c.GetY() * a.GetX())) / 2.0f);
	return (_area);
}

bool bsp( Point const a, Point const b, Point const c, Point const point) {

	Fixed TriangleArea = area(a, b, c);
	Fixed TriangleABP = area(a, b, point);
	Fixed TriangleAPC = area(a, point, c);
	Fixed TriangleBPC = area(b, point, c);
	
	if (!TriangleABP.toFloat() || !TriangleAPC.toFloat() || !TriangleBPC.toFloat())
		return false;
	if (TriangleArea < (TriangleABP + TriangleAPC + TriangleBPC))
		return (false);
	return (true);
}