#include <iostream>

#include "Zombie.hpp"

Zombie::Zombie( void )
{
	
}

Zombie::~Zombie( void )
{
	std::cout << this->name << "oh no..." << std::endl;
}

void	Zombie::set_name(std::string name)
{
	this->name  = name;
}

void	Zombie::announce( void )
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}