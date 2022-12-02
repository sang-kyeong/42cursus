#include <iostream>
#include <string>
#include "Zombie.hpp"

Zombie::Zombie(std::string name)
: _name(name)
{
	std::cout << "A zombie is created. His name is " << this->_name << std::endl;
}

Zombie::~Zombie ( void )
{
	std::cout << this->_name << " is destroyed" << std::endl;
}

void	Zombie::announce ( void )
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
