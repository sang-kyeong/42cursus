#include <string>
#include <iostream>
#include "Weapon.hpp"

Weapon::Weapon ( void )
{
	std::cout << "unknown weapon is constructed" << std::endl;
}

Weapon::Weapon ( std::string type )
: _type(type)
{
	std::cout << this->_type << " is constructed" << std::endl;
}

Weapon::~Weapon (void )
{
	if (this->_type.empty())
		std::cout << "unknown weapon is destructed" << std::endl;
	else
		std::cout << this->_type << " is destructed" << std::endl;
}

const std::string	Weapon::getType ( void )
{
	return (this->_type);
}

void	Weapon::setType(std::string type)
{
	std::cout << "weapon type is " << type << std::endl;
	this->_type = type;
}
