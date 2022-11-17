#include <cmath>
#include "Point.hpp"

Point::Point ( void )
{
	this->x = Fixed();
	this->y = Fixed();
}

Point::Point ( const Fixed x, const Fixed y )
{
	this->x = x;
	this->y = y;
}

Point::Point ( const Point & other )
{
	*this = other;
}

Point & Point::operator= (const Point & other )
{
	this->x = other.x;
	this->y = other.y;
	return (*this);
}

std::ostream & operator<< ( std::ostream &output_stream, const Point & point )
{
	output_stream << "[" << point.getX() << ", " << point.getY() << "]";
	return (output_stream);
}

Point operator+ ( Point left, const Point & right )
{
	left.setX(left.getX() + right.getX());
	left.setY(left.getY() + right.getY());
	return (left);
}

Point operator- ( Point left, const Point & right )
{
	left.setX(left.getX() - right.getX());
	left.setY(left.getY() - right.getY());
	return (left);
}

Point::~Point()
{

}

void	Point::setX ( const Fixed x )
{
	this->x = x;
}

void	Point::setY ( const Fixed y )
{
	this->y = y;
}

Fixed	Point::getX ( void ) const
{
	return (this->x);
}

Fixed	Point::getY ( void ) const
{
	return (this->y);
}
