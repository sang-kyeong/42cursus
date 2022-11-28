#include <string>
#include <iostream>
#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name), _weapon(NULL) { std::cout << this->_name << " (이)가 나타났다. 그는 아무것도 들고있지 않다." << std::endl; }

HumanB::~HumanB( void ) { std::cout << this->_name << " (이)가 사라졌다." << std::endl; }

void	HumanB::setWeapon(Weapon &weapon) { this->_weapon = &weapon; }

void	HumanB::attack( void ) {
	if (this->_weapon != NULL)
		std::cout << this->_name << " attacks with their " << this->_weapon->getType() << std::endl;
	else
		std::cout << this->_name << " attacks with their Hand" << std::endl;
}
