#include <iostream>
#include <sstream>
#include "Point.hpp"

bool	bsp ( Point const a, Point const b, Point const c, Point const point );

Point	getPointFromString ( std::string arg )
{
	std::stringstream	ss;
	float				x, y;
	Point				p;
	
	ss = std::stringstream(arg);
	ss >> x >> y;
	if (ss.fail())
	{
		std::cout << "Wrong format" << std::endl;
		exit(1);
	}
	return (Point(x, y));
}

int main ( int argc, char *argv[] ) {
	Point				vertex[3], point;

	if (argc != 5)
		return (1);
	vertex[0] = getPointFromString(argv[1]);
	vertex[1] = getPointFromString(argv[2]);
	vertex[2] = getPointFromString(argv[3]);
	point = getPointFromString(argv[4]);

	std::cout << "Triangle" << std::endl;
	std::cout << "\t" << vertex[0] << std::endl;
	std::cout << "\t" << vertex[1] << std::endl;
	std::cout << "\t" << vertex[2] << std::endl;
	std::cout << "Point to test" << std::endl;
	std::cout << "\t" << point << std::endl << std::endl;

	if (bsp(vertex[0], vertex[1], vertex[2], point))
		std::cout << "The point is inside of triangle" << std::endl;
	else
		std::cout << "The point is out of triangle" << std::endl;

	return 0;
}
