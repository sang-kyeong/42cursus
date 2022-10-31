#include <string>
#include <iostream>
#include "Weapon.hpp"

Weapon::Weapon ( void )
{
	std::cout << "a unknown weapons is created" << std::endl;
}

Weapon::Weapon ( std::string type ) : _type(type)
{
	std::cout << this->_type << " is created" << std::endl;
}

Weapon::~Weapon (void )
{
	if (this->_type.empty())
		std::cout << "A unknown weapon is destroyed" << std::endl;
	else
		std::cout << this->_type << " is destroyed" << std::endl;
}

const std::string	Weapon::getType ( void )
{
	return (this->_type);
}

void	Weapon::setType(std::string type)
{
	this->_type = type;
}
