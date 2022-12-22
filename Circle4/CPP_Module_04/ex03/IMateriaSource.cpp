#include <iostream>
#include "IMateriaSource.hpp"
#include "Color.hpp"

IMateriaSource::IMateriaSource ( void )
{
	std::cout << BLACK << "[IMateriaSource] default constructor" << NORMAL << std::endl;
}

IMateriaSource::IMateriaSource ( const IMateriaSource & other )
{
	(void)other;
	std::cout << BLACK << "[IMateriaSource] copy constructor" << NORMAL << std::endl;
}

IMateriaSource::~IMateriaSource ( void )
{
	std::cout << BLACK << "[IMateriaSource] destructor" << NORMAL << std::endl;
}

IMateriaSource &	IMateriaSource::operator= ( const IMateriaSource & other )
{
	(void)other;
	return *this;
}
