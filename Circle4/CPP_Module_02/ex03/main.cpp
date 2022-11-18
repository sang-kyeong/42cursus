#include <iostream>
#include "Point.hpp"

bool	bsp ( Point const a, Point const b, Point const c, Point const point );

Point	getPointFromUser ( void )
{
	Point	point;
	float	x, y;

	std::cout << "format is : \'x y\'" << std::endl;
	while (true)
	{
		std::cin >> x >> y;
		if (std::cin.fail())
		{
			std::cout << "Wrong format please type again" << std::endl;
			std::cin.clear();
			std::cin.ignore(1024, '\n');
		}
		else
			break ;
	}
	std::cin.ignore(1024, '\n');
	point = Point(Fixed(x), Fixed(y));
	std::cout << std::endl;
	return (point);
}

int main ( void ) {

	Point	a, b, c, point;

	std::cout << "type x, y coordinates of point A on the triangle" << std::endl;
	a = getPointFromUser();
	std::cout << "type x, y coordinates of point B on the triangle" << std::endl;
	b = getPointFromUser();
	std::cout << "type x, y coordinates of point C on the triangle" << std::endl;
	c = getPointFromUser();

	std::cout << "And then, type x, y coordinates of point which you want to test" << std::endl;
	point = getPointFromUser();

	std::cout << "Triangle" << std::endl;
	std::cout << "\t" << a << std::endl;
	std::cout << "\t" << b << std::endl;
	std::cout << "\t" << c << std::endl;
	std::cout << "Point to test" << std::endl;
	std::cout << "\t" << point << std::endl << std::endl;

	if (bsp(a, b, c, point))
		std::cout << "Point is inside of triangle" << std::endl;
	else
		std::cout << "Point is out of triangle" << std::endl;

	return 0;
}
