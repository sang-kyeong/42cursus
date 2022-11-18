#ifndef __POINT_H__
# define __POINT_H__

# include "Fixed.hpp"

class Point
{

private:

	Fixed		x;
	Fixed		y;

public:

	Point ( void );
	Point ( const Fixed x, const Fixed y );
	Point ( const Point & other );

	Point & operator= (const Point & other );

	~Point();

	void	setX ( Fixed x );
	void	setY ( Fixed y );
	Fixed	getX ( void ) const;
	Fixed	getY ( void ) const;

};

std::ostream & operator<< ( std::ostream &output_stream, const Point & point );

Point operator+ ( Point left, const Point & right );
Point operator- ( Point left, const Point & right );

#endif //__POINT_H__
