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

	friend std::ostream & operator<< ( std::ostream &output_stream, const Point & point );

	friend Point operator+ ( Point left, const Point & right );
	friend Point operator- ( Point left, const Point & right );

	~Point();

	void	setX ( Fixed x );
	void	setY ( Fixed y );
	Fixed	getX ( void ) const;
	Fixed	getY ( void ) const;

};

#endif //__POINT_H__
