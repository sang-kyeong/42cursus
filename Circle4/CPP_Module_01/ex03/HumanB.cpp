#include <string>
#include <iostream>
#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name), _weapon(NULL)
{
	std::cout << this->_name << " created and nothing is on his hand" << std::endl;
}

HumanB::~HumanB( void )
{
	if (this->_weapon != NULL)
		delete (this->_weapon);
	std::cout << this->_name << " destroyed" << std::endl;
}

void	HumanB::setWeapon(Weapon weapon)
{
	if (this->_weapon == NULL)
		this->_weapon = new Weapon();
	this->_weapon->setType(weapon.getType());
}

void	HumanB::attack( void )
{
	std::cout << this->_name << " attacks with their " << this->_weapon->getType() << std::endl;
}
