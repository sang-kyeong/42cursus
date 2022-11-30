#include <string>
#include <iostream>
#include "Weapon.hpp"

Weapon::Weapon ( void )
{
	std::cout << "정체모를 무기가 나타났다." << std::endl;
}

Weapon::Weapon ( std::string type )
: _type(type)
{
	std::cout << this->_type << " (이)가 나타났다." << std::endl;
}

Weapon::~Weapon (void )
{
	if (this->_type.empty())
		std::cout << "정체모를 무기가 사라졌다." << std::endl;
	else
		std::cout << this->_type << " (이)가 사라졌다." << std::endl;
}

const std::string	Weapon::getType ( void )
{
	return (this->_type);
}

void	Weapon::setType(std::string type)
{
	this->_type = type;
}
