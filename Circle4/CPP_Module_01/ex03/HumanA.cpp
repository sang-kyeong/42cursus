#include <string>
#include <iostream>
#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon)
: _name(name), _weapon(weapon)
{
	std::cout << this->_name << " (이)가 나타났다. 그는 " << this->_weapon.getType() << "(을) 를 들고있다." << std::endl;
}

HumanA::~HumanA( void )
{
	std::cout << this->_name << " (이)가 사라졌다." << std::endl;
}

void	HumanA::attack( void )
{
	std::cout << this->_name << " attacks with their " << this->_weapon.getType() << std::endl;
}
