#include <cmath>
#include "Point.hpp"


#include <iostream>
Fixed	crossProduct( Point const a, Point const b ) {
	return (a.getX() * b.getY()) - (a.getY() * b.getX());
}

bool	bsp ( Point const a, Point const b, Point const c, Point const point ) {
	Fixed	zero = Fixed(0);
	Point	AB, AP, BC, BP, CA, CP;

	if (crossProduct(b - a, point - a) > zero)
	{
		if (crossProduct(c - b, point - b) <= zero)
			return (false);
		if (crossProduct(a - c, point - c) <= zero)
			return (false);
	}
	else if (crossProduct(b - a, point - a) < zero)
	{
		if (crossProduct(c - b, point - b) >= zero)
			return (false);
		if (crossProduct(a - c, point - c) >= zero)
			return (false);
	}
	else
		return (false);

	return (true);
}
