#include <string>
#include <iostream>
#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon)
: _name(name), _weapon(weapon)
{
	std::cout << this->_name << " is constructed with " << this->_weapon.getType() << std::endl;
}

HumanA::~HumanA( void )
{
	std::cout << this->_name << " is destructed" << std::endl;
}

void	HumanA::attack( void )
{
	std::cout << this->_name << " attacks with their " << this->_weapon.getType() << std::endl;
}
