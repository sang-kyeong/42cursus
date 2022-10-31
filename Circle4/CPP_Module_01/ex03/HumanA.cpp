#include <string>
#include <iostream>
#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : _name(name), _weapon(weapon)
{
	std::cout << this->_name << " created and a " << this->_weapon.getType() << " is on his hand" << std::endl;
}

HumanA::~HumanA( void )
{
	std::cout << this->_name << " destroyed" << std::endl;
}

void	HumanA::attack( void )
{
	std::cout << this->_name << " attacks with their " << this->_weapon.getType() << std::endl;
}
